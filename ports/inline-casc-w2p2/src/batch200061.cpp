// batch200061.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4528f0_fastcall4(u32, u32, u32, u32) __asm__("ext_4528f0");
extern "C" u32 FASTCALL ext_4697d0_fastcall4(u32, u32, u32, u32) __asm__("ext_4697d0");
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_4d8db0_stdcall2(u32, u32) __asm__("ext_4d8db0");
extern "C" u32 STDCALL ext_4d8ef0_stdcall3(u32, u32, u32) __asm__("ext_4d8ef0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_41cfd0_thiscall1(u32) __asm__("ext_41cfd0");
extern "C" u32 THISCALL ext_423e60_thiscall1(u32) __asm__("ext_423e60");
extern "C" u32 THISCALL ext_423ff0_thiscall2(u32, u32) __asm__("ext_423ff0");
extern "C" u32 THISCALL ext_42be20_thiscall2(u32, u32) __asm__("ext_42be20");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_43a900_thiscall1(u32) __asm__("ext_43a900");
extern "C" u32 THISCALL ext_43de40_thiscall4(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43e990_thiscall4(u32, u32, u32, u32) __asm__("ext_43e990");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_447640_thiscall4(u32, u32, u32, u32) __asm__("ext_447640");
extern "C" u32 THISCALL ext_44b610_thiscall1(u32) __asm__("ext_44b610");
extern "C" u32 THISCALL ext_45c3e0_thiscall1(u32) __asm__("ext_45c3e0");
extern "C" u32 THISCALL ext_45e660_thiscall1(u32) __asm__("ext_45e660");
extern "C" u32 THISCALL ext_45e710_thiscall1(u32) __asm__("ext_45e710");
extern "C" u32 THISCALL ext_460f90_thiscall1(u32) __asm__("ext_460f90");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_469980_thiscall4(u32, u32, u32, u32) __asm__("ext_469980");
extern "C" u32 THISCALL ext_46a4f0_thiscall1(u32) __asm__("ext_46a4f0");
extern "C" u32 THISCALL ext_480a40_thiscall4(u32, u32, u32, u32) __asm__("ext_480a40");
extern "C" u32 THISCALL ext_48a470_thiscall2(u32, u32) __asm__("ext_48a470");
extern "C" u32 THISCALL ext_49b5c0_thiscall2(u32, u32) __asm__("ext_49b5c0");
extern "C" u32 THISCALL ext_49b680_thiscall1(u32) __asm__("ext_49b680");
extern "C" u32 THISCALL ext_49f670_thiscall1(u32) __asm__("ext_49f670");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbf30_thiscall2(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cc690_thiscall1(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccc30_thiscall3(u32, u32, u32) __asm__("ext_4ccc30");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccee0_thiscall1(u32) __asm__("ext_4ccee0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4d9430_thiscall1(u32) __asm__("ext_4d9430");
extern "C" u32 THISCALL ext_4da720_thiscall2(u32, u32) __asm__("ext_4da720");
extern "C" u32 THISCALL ext_4dae60_thiscall1(u32) __asm__("ext_4dae60");
extern "C" u32 THISCALL ext_4dbb00_thiscall2(u32, u32) __asm__("ext_4dbb00");
extern "C" u32 THISCALL ext_4dc130_thiscall1(u32) __asm__("ext_4dc130");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4dcdf0_thiscall2(u32, u32) __asm__("ext_4dcdf0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e5e40_thiscall1(u32) __asm__("ext_4e5e40");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_4e66a0_thiscall1(u32) __asm__("ext_4e66a0");
extern "C" u32 THISCALL ext_4f2be0_thiscall1(u32) __asm__("ext_4f2be0");
extern "C" u32 THISCALL ext_4f6b20_thiscall1(u32) __asm__("ext_4f6b20");
extern "C" u32 THISCALL ext_4ff7b0_thiscall1(u32) __asm__("ext_4ff7b0");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_500150_thiscall1(u32) __asm__("ext_500150");
extern "C" u32 THISCALL ext_500190_thiscall2(u32, u32) __asm__("ext_500190");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_53b600_thiscall1(u32) __asm__("ext_53b600");
extern "C" u32 THISCALL ext_53c590_thiscall3(u32, u32, u32) __asm__("ext_53c590");
extern "C" u32 THISCALL ext_549350_thiscall1(u32) __asm__("ext_549350");
extern "C" u32 THISCALL ext_54e100_thiscall1(u32) __asm__("ext_54e100");
extern "C" u32 THISCALL ext_54f890_thiscall1(u32) __asm__("ext_54f890");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5aede0_thiscall1(u32) __asm__("ext_5aede0");
extern "C" u32 THISCALL ext_5ec720_thiscall2(u32, u32) __asm__("ext_5ec720");
extern "C" u32 THISCALL ext_5ed460_thiscall1(u32) __asm__("ext_5ed460");
extern "C" u32 THISCALL ext_5f0370_thiscall1(u32) __asm__("ext_5f0370");
extern "C" u32 THISCALL ext_5f0490_thiscall1(u32) __asm__("ext_5f0490");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f12d0_thiscall1(u32) __asm__("ext_5f12d0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_5f5490_thiscall3(u32, u32, u32) __asm__("ext_5f5490");
extern "C" u32 THISCALL ext_5f9700_thiscall3(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 THISCALL ext_5fb000_thiscall1(u32) __asm__("ext_5fb000");
extern "C" u32 THISCALL ext_5fb600_thiscall1(u32) __asm__("ext_5fb600");
extern "C" u32 THISCALL ext_5fd7c0_thiscall2(u32, u32) __asm__("ext_5fd7c0");
extern "C" u32 THISCALL ext_600c70_thiscall3(u32, u32, u32) __asm__("ext_600c70");
extern "C" u32 THISCALL ext_600d70_thiscall3(u32, u32, u32) __asm__("ext_600d70");
extern "C" u32 THISCALL ext_601380_thiscall1(u32) __asm__("ext_601380");
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_602260_thiscall2(u32, u32) __asm__("ext_602260");
extern "C" u32 THISCALL ext_603110_thiscall1(u32) __asm__("ext_603110");
extern "C" u32 THISCALL ext_6031e0_thiscall2(u32, u32) __asm__("ext_6031e0");
extern "C" u32 THISCALL ext_6033c0_thiscall2(u32, u32) __asm__("ext_6033c0");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_603850_thiscall1(u32) __asm__("ext_603850");
extern "C" u32 THISCALL ext_6042f0_thiscall1(u32) __asm__("ext_6042f0");
extern "C" u32 THISCALL ext_604650_thiscall1(u32) __asm__("ext_604650");
extern "C" u32 THISCALL ext_604ca0_thiscall1(u32) __asm__("ext_604ca0");
extern "C" u32 THISCALL ext_6052f0_thiscall3(u32, u32, u32) __asm__("ext_6052f0");
extern "C" u32 THISCALL ext_606ee0_thiscall4(u32, u32, u32, u32) __asm__("ext_606ee0");
extern "C" u32 THISCALL ext_6071c0_thiscall1(u32) __asm__("ext_6071c0");
extern "C" u32 THISCALL ext_607f60_thiscall4(u32, u32, u32, u32) __asm__("ext_607f60");
extern "C" u32 THISCALL ext_608e80_thiscall1(u32) __asm__("ext_608e80");
extern "C" u32 THISCALL ext_63ed10_thiscall1(u32) __asm__("ext_63ed10");
extern "C" u32 THISCALL ext_651880_thiscall1(u32) __asm__("ext_651880");
extern "C" u32 THISCALL ext_6590a0_thiscall2(u32, u32) __asm__("ext_6590a0");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 THISCALL ext_65c7f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_65c7f0");
extern "C" u32 THISCALL ext_65e090_thiscall1(u32) __asm__("ext_65e090");
extern "C" u32 ext_41c750_cdecl0(void) __asm__("ext_41c750");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_45c4b0_cdecl1(...) __asm__("ext_45c4b0");
extern "C" u32 ext_45c4f0_cdecl2(...) __asm__("ext_45c4f0");
extern "C" u32 ext_45c510_cdecl1(...) __asm__("ext_45c510");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4d9590_cdecl1(...) __asm__("ext_4d9590");
extern "C" u32 ext_50b4b0_cdecl0(void) __asm__("ext_50b4b0");
extern "C" u32 ext_50d750_cdecl0(void) __asm__("ext_50d750");
extern "C" u32 ext_510b70_cdecl0(void) __asm__("ext_510b70");
extern "C" u32 ext_511700_cdecl0(void) __asm__("ext_511700");
extern "C" u32 ext_560580_cdecl0(void) __asm__("ext_560580");
extern "C" u32 ext_580000_cdecl0(void) __asm__("ext_580000");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

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

extern "C" u32 THISCALL lifted_602bc0(u32 ecx_in) {
  SEH_ENTER(0x66dbd8);  // @h_602bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_602bc0
  eax = ext_603110_thiscall1(ecx);  // @1_602bc0
  ecx = edx = 0;  // @2_602bc0
  { u32 v = (u32)((u32)(7046408)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @3_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @4_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @5_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_602bc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_602bc0
  ecx = (u32)(EBP - 36);  // @8_602bc0
  reg.state = (s32)((u32)(0));  // @9_602bc0
  eax = ext_602260_thiscall2(ecx, (u32)(eax));  // @10_602bc0
  ecx = edx = 0;  // @11_602bc0
  eax = (u32)(EBP - 36);  // @12_602bc0
  ecx = esi;  // @13_602bc0
  eax = ext_6031e0_thiscall2(ecx, (u32)(eax));  // @14_602bc0
  ecx = edx = 0;  // @15_602bc0
  ecx = (u32)(EBP - 36);  // @16_602bc0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @17_602bc0
  eax = ext_602240_thiscall1(ecx);  // @18_602bc0
  ecx = edx = 0;  // @19_602bc0
  SEH_LEAVE();  // @20_602bc0
  return eax;  // @21_602bc0
}
PCREG(602bc0, lifted_602bc0);

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

extern "C" u32 STDCALL lifted_5f3050(u32 a0, u32 a1) {
  SEH_ENTER(0x66d04f);  // @h_5f3050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
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

extern "C" u32 THISCALL lifted_603500(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66dc73);  // @h_603500
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_603500
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_603500
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @2_603500
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @3_603500
  ecx = (u32)(ebx + 12);  // @4_603500
  reg.state = (s32)((u32)(0));  // @5_603500
  { u32 v = (u32)((u32)(7051812)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_603500
  eax = ext_6033c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @7_603500
  ecx = edx = 0;  // @8_603500
  eax = (u32)(EBP - 24);  // @9_603500
  reg.state = (s32)((u32)(1));  // @10_603500
  ecx = (u32)(ebx + 12);  // @11_603500
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @12_603500
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_603500
  eax = ext_5f5490_thiscall3(ecx, (u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @14_603500
  ecx = edx = 0;  // @15_603500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489176), sizeof v); (u32)v; }) != (u32)(0)) goto L603580;  // @16_603500
  ecx = ebx;  // @17_603500
  eax = ext_603850_thiscall1(ecx);  // @18_603500
  ecx = edx = 0;  // @19_603500
  L603580:;
  eax = ebx;  // @21_603500
  SEH_LEAVE();  // @22_603500
  return eax;  // @23_603500
}
PCREG(603500, lifted_603500);

extern "C" u32 THISCALL lifted_549df0(u32 ecx_in) {
  SEH_ENTER(0x66ac42);  // @h_549df0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_549df0
  eax = ext_41e290_cdecl1((u32)(750));  // @1_549df0
  ecx = edx = 0;  // @2_549df0
  esi = eax;  // @3_549df0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_549df0
  reg.state = (s32)((u32)(0));  // @5_549df0
  if ((esi & esi) == 0) goto L549e43;  // @6_549df0
  ecx = esi;  // @7_549df0
  eax = ext_54e100_thiscall1(ecx);  // @8_549df0
  ecx = edx = 0;  // @9_549df0
  { u32 v = (u32)((u32)(6960108)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_549df0
  goto L549e45;  // @11_549df0
  L549e43:;
  esi = 0;  // @13_549df0
  L549e45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41582), sizeof v); (u32)v; });  // @15_549df0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 32865), &v, sizeof v); }  // @16_549df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 453), &v, sizeof v); }  // @17_549df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32865), sizeof v); (u32)v; });  // @18_549df0
  reg.state = (s32)((u32)(4294967295));  // @19_549df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_549df0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @21_549df0
  ecx = edx = 0;  // @22_549df0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @23_549df0
  SEH_LEAVE();  // @24_549df0
  return eax;  // @25_549df0
}
PCREG(549df0, lifted_549df0);

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

extern "C" u32 FASTCALL lifted_42b160(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6649b1);  // @h_42b160
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = edx;  // @0_42b160
  esi = ecx;  // @1_42b160
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42b160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @3_42b160
  if (esi == ebx) goto L42b1be;  // @4_42b160
  L42b194:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_42b160
  reg.state = (s32)((u32)(0));  // @7_42b160
  if ((edi & edi) == 0) goto L42b1aa;  // @8_42b160
  ecx = edi;  // @9_42b160
  eax = ext_5f10c0_thiscall2(ecx, (u32)(esi));  // @10_42b160
  ecx = edx = 0;  // @11_42b160
  L42b1aa:;
  esi = (esi + (u32)(12));  // @13_42b160
  reg.state = (s32)((u32)(4294967295));  // @14_42b160
  edi = (edi + (u32)(12));  // @15_42b160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @16_42b160
  if (esi != ebx) goto L42b194;  // @17_42b160
  L42b1be:;
  eax = edi;  // @19_42b160
  SEH_LEAVE();  // @20_42b160
  return eax;  // @21_42b160
}
PCREG(42b160, lifted_42b160);

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

extern "C" u32 THISCALL lifted_616620(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66e628);  // @h_616620
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edi = ecx;  // @0_616620
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_616620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_616620
  ecx = (u32)(edi + 8);  // @5_616620
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_616620
  { u32 v = (u32)((u32)(7068760)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_616620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @8_616620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @9_616620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @10_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @11_616620
  reg.state = (s32)((u32)(0));  // @12_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @13_616620
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 14), sizeof v); (u32)v; });  // @14_616620
  eax = ext_659330_thiscall3(ecx, (u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 47528), sizeof v); (u32)v; }));  // @15_616620
  ecx = edx = 0;  // @16_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @17_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @18_616620
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) | (u32)(16777216))); __builtin_memcpy((void *)(u32)(eax + 60), &v, sizeof v); }  // @19_616620
  eax = edi;  // @20_616620
  { u32 v = (u32)((u32)(7068812)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @21_616620
  SEH_LEAVE();  // @22_616620
  return eax;  // @23_616620
}
PCREG(616620, lifted_616620);

extern "C" u32 THISCALL lifted_5a3dc0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5a3dc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5a3dc0
  { u32 v = (u32)((u32)(7008280)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @1_5a3dc0
  esi = (u32)(ebx + 233);  // @2_5a3dc0
  edi = (u32)(4);  // @3_5a3dc0
  L5a3df8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_5a3dc0
  if ((ecx & ecx) == 0) goto L5a3e04;  // @6_5a3dc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_5a3dc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @8_5a3dc0
  ecx = edx = 0;  // @9_5a3dc0
  L5a3e04:;
  esi = (esi + (u32)(4));  // @11_5a3dc0
  edi = (edi - (u32)(1));  // @12_5a3dc0
  if (edi != 0) goto L5a3df8;  // @13_5a3dc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @14_5a3dc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @15_5a3dc0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @16_5a3dc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_5a3dc0
  reg.state = (s32)(edi);  // @18_5a3dc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5a3dc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5a3dc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(ebx));  // @21_5a3dc0
  ecx = edx = 0;  // @22_5a3dc0
  SEH_LEAVE();  // @23_5a3dc0
  return eax;  // @24_5a3dc0
}
PCREG(5a3dc0, lifted_5a3dc0);

extern "C" u32 THISCALL lifted_449fa0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66825f);  // @h_449fa0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_449fa0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L449ffd;  // @1_449fa0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_449fa0
  ecx = edx = 0;  // @3_449fa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_449fa0
  reg.state = (s32)((u32)(0));  // @5_449fa0
  if ((eax & eax) == 0) goto L449ff1;  // @6_449fa0
  ecx = eax;  // @7_449fa0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(1));  // @8_449fa0
  ecx = edx = 0;  // @9_449fa0
  goto L449ff3;  // @10_449fa0
  L449ff1:;
  eax = 0;  // @12_449fa0
  L449ff3:;
  reg.state = (s32)((u32)(4294967295));  // @14_449fa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @15_449fa0
  L449ffd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @17_449fa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_449fa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @19_449fa0
  ecx = edx = 0;  // @20_449fa0
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; })) & 0xffff);  // @21_449fa0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @22_449fa0
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) & 0xffff);  // @23_449fa0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 2), &v, sizeof v); }  // @24_449fa0
  SEH_LEAVE();  // @25_449fa0
  return eax;  // @26_449fa0
}
PCREG(449fa0, lifted_449fa0);

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

extern "C" u32 THISCALL lifted_606a70(u32 ecx_in) {
  SEH_ENTER(0x66df2b);  // @h_606a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_606a70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_606a70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @2_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 3), &v, sizeof v); }  // @3_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 7), &v, sizeof v); }  // @4_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 11), &v, sizeof v); }  // @5_606a70
  ecx = (u32)(100);  // @6_606a70
  reg.state = (s32)((u32)(0));  // @7_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 15), &v, sizeof v); }  // @8_606a70
  eax = ext_6071c0_thiscall1(ecx);  // @9_606a70
  ecx = edx = 0;  // @10_606a70
  esi = eax;  // @11_606a70
  ecx = (u32)(ebx + 3);  // @12_606a70
  eax = ext_59a9b0_thiscall2(ecx, (u32)(esi));  // @13_606a70
  ecx = edx = 0;  // @14_606a70
  eax = (u32)(EBP - 16);  // @15_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @16_606a70
  ecx = (u32)(ebx + 3);  // @17_606a70
  eax = ext_606ee0_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7), sizeof v); (u32)v; }), (u32)(esi), (u32)(eax));  // @18_606a70
  ecx = edx = 0;  // @19_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 15), &v, sizeof v); }  // @20_606a70
  eax = ebx;  // @21_606a70
  SEH_LEAVE();  // @22_606a70
  return eax;  // @23_606a70
}
PCREG(606a70, lifted_606a70);

extern "C" u32 THISCALL lifted_601ee0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d93f);  // @h_601ee0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_601ee0
  eax = ext_41e290_cdecl1((u32)(4));  // @1_601ee0
  ecx = edx = 0;  // @2_601ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601ee0
  reg.state = (s32)((u32)(0));  // @4_601ee0
  if ((eax & eax) == 0) goto L601f30;  // @5_601ee0
  ecx = eax;  // @6_601ee0
  eax = ext_600c70_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_601ee0
  ecx = edx = 0;  // @8_601ee0
  edi = eax;  // @9_601ee0
  goto L601f32;  // @10_601ee0
  L601f30:;
  edi = 0;  // @12_601ee0
  L601f32:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @14_601ee0
  reg.state = (s32)((u32)(4294967295));  // @15_601ee0
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L601f49;  // @16_601ee0
  ecx = (u32)(esi + 4);  // @17_601ee0
  eax = ext_5f4630_thiscall1(ecx);  // @18_601ee0
  ecx = edx = 0;  // @19_601ee0
  L601f49:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @21_601ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @22_601ee0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @23_601ee0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @24_601ee0
  SEH_LEAVE();  // @25_601ee0
  return eax;  // @26_601ee0
}
PCREG(601ee0, lifted_601ee0);

extern "C" u32 THISCALL lifted_601f70(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d93f);  // @h_601f70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_601f70
  eax = ext_41e290_cdecl1((u32)(4));  // @1_601f70
  ecx = edx = 0;  // @2_601f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601f70
  reg.state = (s32)((u32)(0));  // @4_601f70
  if ((eax & eax) == 0) goto L601fc0;  // @5_601f70
  ecx = eax;  // @6_601f70
  eax = ext_600d70_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_601f70
  ecx = edx = 0;  // @8_601f70
  edi = eax;  // @9_601f70
  goto L601fc2;  // @10_601f70
  L601fc0:;
  edi = 0;  // @12_601f70
  L601fc2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @14_601f70
  reg.state = (s32)((u32)(4294967295));  // @15_601f70
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L601fd9;  // @16_601f70
  ecx = (u32)(esi + 4);  // @17_601f70
  eax = ext_5f4630_thiscall1(ecx);  // @18_601f70
  ecx = edx = 0;  // @19_601f70
  L601fd9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @21_601f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @22_601f70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @23_601f70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @24_601f70
  SEH_LEAVE();  // @25_601f70
  return eax;  // @26_601f70
}
PCREG(601f70, lifted_601f70);

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

extern "C" u32 STDCALL lifted_601d80(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ext_41e290_cdecl1((u32)(42));  // @0_601d80
  ecx = edx = 0;  // @1_601d80
  esi = eax;  // @2_601d80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601d80
  reg.state = (s32)((u32)(0));  // @4_601d80
  if ((esi & esi) == 0) goto L601df0;  // @5_601d80
  ecx = esi;  // @6_601d80
  eax = ext_603500_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_601d80
  ecx = edx = 0;  // @8_601d80
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_601d80
  eax = (u32)(esi + 12);  // @10_601d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @11_601d80
  eax = 0;  // @12_601d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @13_601d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @14_601d80
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @15_601d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_601d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @17_601d80
  goto L601df2;  // @18_601d80
  L601df0:;
  esi = 0;  // @20_601d80
  L601df2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_601d80
  ecx = esi;  // @23_601d80
  reg.state = (s32)((u32)(4294967295));  // @24_601d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @25_601d80
  ecx = edx = 0;  // @26_601d80
  eax = esi;  // @27_601d80
  SEH_LEAVE();  // @28_601d80
  return eax;  // @29_601d80
}
PCREG(601d80, lifted_601d80);

extern "C" u32 STDCALL lifted_601e20(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ext_41e290_cdecl1((u32)(42));  // @0_601e20
  ecx = edx = 0;  // @1_601e20
  esi = eax;  // @2_601e20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601e20
  reg.state = (s32)((u32)(0));  // @4_601e20
  if ((esi & esi) == 0) goto L601e90;  // @5_601e20
  ecx = esi;  // @6_601e20
  eax = ext_603500_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_601e20
  ecx = edx = 0;  // @8_601e20
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_601e20
  eax = (u32)(esi + 12);  // @10_601e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @11_601e20
  eax = 0;  // @12_601e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @13_601e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @14_601e20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @15_601e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_601e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @17_601e20
  goto L601e92;  // @18_601e20
  L601e90:;
  esi = 0;  // @20_601e20
  L601e92:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_601e20
  ecx = esi;  // @23_601e20
  reg.state = (s32)((u32)(4294967295));  // @24_601e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @25_601e20
  ecx = edx = 0;  // @26_601e20
  eax = esi;  // @27_601e20
  SEH_LEAVE();  // @28_601e20
  return eax;  // @29_601e20
}
PCREG(601e20, lifted_601e20);

extern "C" u32 THISCALL lifted_607b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e0b2);  // @h_607b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
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

extern "C" u32 THISCALL lifted_608080(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_608080
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_608080
  { u32 v = (u32)((u32)(7063740)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_608080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; }) == (u32)(0)) goto L6080b6;  // @2_608080
  eax = ext_608e80_thiscall1(ecx);  // @3_608080
  ecx = edx = 0;  // @4_608080
  L6080b6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @6_608080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_608080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 196), sizeof v); (u32)v; });  // @8_608080
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489600), sizeof v); (u32)v; }));  // @9_608080
  ecx = edx = 0;  // @10_608080
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6080f8;  // @11_608080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489600), sizeof v); (u32)v; });  // @12_608080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_608080
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @14_608080
  ecx = edx = 0;  // @15_608080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489600), sizeof v); (u32)v; });  // @16_608080
  if ((ecx & ecx) == 0) goto L6080ec;  // @17_608080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_608080
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(1));  // @19_608080
  ecx = edx = 0;  // @20_608080
  L6080ec:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489600), &v, sizeof v); }  // @22_608080
  goto L60810c;  // @23_608080
  L6080f8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @25_608080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_608080
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 192)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489600), sizeof v); (u32)v; }));  // @27_608080
  ecx = edx = 0;  // @28_608080
  L60810c:;
  ecx = esi;  // @30_608080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 189), &v, sizeof v); }  // @31_608080
  eax = ext_651880_thiscall1(ecx);  // @32_608080
  ecx = edx = 0;  // @33_608080
  SEH_LEAVE();  // @34_608080
  return eax;  // @35_608080
}
PCREG(608080, lifted_608080);

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

extern "C" u32 THISCALL lifted_473a70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_473a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_473a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_473a70
  ecx = (u32)(EBP - 16596);  // @2_473a70
  eax = ext_4d2280_thiscall1(ecx);  // @3_473a70
  ecx = edx = 0;  // @4_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_473a70
  reg.state = (s32)((u32)(0));  // @6_473a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_473a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @9_473a70
  ecx = edx = 0;  // @10_473a70
  ecx = (u32)(EBP - 16596);  // @11_473a70
  eax = ext_4d3ab0_stdcall2((u32)(6851120), (u32)(eax));  // @12_473a70
  ecx = edx = 0;  // @13_473a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_473a70
  eax = (u32)(EBP - 16596);  // @15_473a70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338404), sizeof v); (u32)v; });  // @16_473a70
  ecx = edi;  // @17_473a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(eax), (u32)(eax));  // @18_473a70
  ecx = edx = 0;  // @19_473a70
  ecx = (u32)(EBP - 16596);  // @20_473a70
  eax = ext_4d2330_thiscall1(ecx);  // @21_473a70
  ecx = edx = 0;  // @22_473a70
  SEH_LEAVE();  // @23_473a70
  ext_633654(G(u32, 0x6f5630));  // @24_473a70
  return eax;  // @25_473a70
}
PCREG(473a70, lifted_473a70);

extern "C" u32 THISCALL lifted_474e00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_474e00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_474e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_474e00
  ecx = (u32)(EBP - 16596);  // @2_474e00
  eax = ext_4d2280_thiscall1(ecx);  // @3_474e00
  ecx = edx = 0;  // @4_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474e00
  reg.state = (s32)((u32)(0));  // @6_474e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_474e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @9_474e00
  ecx = edx = 0;  // @10_474e00
  ecx = (u32)(EBP - 16596);  // @11_474e00
  eax = ext_4d3ab0_stdcall2((u32)(6851120), (u32)(eax));  // @12_474e00
  ecx = edx = 0;  // @13_474e00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_474e00
  eax = (u32)(EBP - 16596);  // @15_474e00
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338412), sizeof v); (u32)v; });  // @16_474e00
  ecx = edi;  // @17_474e00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(eax), (u32)(eax));  // @18_474e00
  ecx = edx = 0;  // @19_474e00
  ecx = (u32)(EBP - 16596);  // @20_474e00
  eax = ext_4d2330_thiscall1(ecx);  // @21_474e00
  ecx = edx = 0;  // @22_474e00
  SEH_LEAVE();  // @23_474e00
  ext_633654(G(u32, 0x6f5630));  // @24_474e00
  return eax;  // @25_474e00
}
PCREG(474e00, lifted_474e00);

extern "C" u32 THISCALL lifted_474f60(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_474f60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_474f60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_474f60
  ecx = (u32)(EBP - 16596);  // @2_474f60
  eax = ext_4d2280_thiscall1(ecx);  // @3_474f60
  ecx = edx = 0;  // @4_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474f60
  reg.state = (s32)((u32)(0));  // @6_474f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_474f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @9_474f60
  ecx = edx = 0;  // @10_474f60
  ecx = (u32)(EBP - 16596);  // @11_474f60
  eax = ext_4d3ab0_stdcall2((u32)(6851120), (u32)(eax));  // @12_474f60
  ecx = edx = 0;  // @13_474f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_474f60
  eax = (u32)(EBP - 16596);  // @15_474f60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338400), sizeof v); (u32)v; });  // @16_474f60
  ecx = edi;  // @17_474f60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(eax), (u32)(eax));  // @18_474f60
  ecx = edx = 0;  // @19_474f60
  ecx = (u32)(EBP - 16596);  // @20_474f60
  eax = ext_4d2330_thiscall1(ecx);  // @21_474f60
  ecx = edx = 0;  // @22_474f60
  SEH_LEAVE();  // @23_474f60
  ext_633654(G(u32, 0x6f5630));  // @24_474f60
  return eax;  // @25_474f60
}
PCREG(474f60, lifted_474f60);

extern "C" u32 THISCALL lifted_46a5e0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_46a5e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_46a5e0
  { u32 v = (u32)((u32)(6845100)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_46a5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_46a5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_46a5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_46a5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 237), sizeof v); (u32)v; }));  // @5_46a5e0
  ecx = edx = 0;  // @6_46a5e0
  if ((eax & eax) == 0) goto L46a631;  // @7_46a5e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_46a5e0
  ecx = eax;  // @9_46a5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @10_46a5e0
  ecx = edx = 0;  // @11_46a5e0
  L46a631:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 217), sizeof v); (u32)v; });  // @13_46a5e0
  if ((ecx & ecx) == 0) goto L46a641;  // @14_46a5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_46a5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @16_46a5e0
  ecx = edx = 0;  // @17_46a5e0
  L46a641:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_46a5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_46a5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 158), sizeof v); (u32)v; }));  // @21_46a5e0
  ecx = edx = 0;  // @22_46a5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 158), sizeof v); (u32)v; });  // @23_46a5e0
  if ((ecx & ecx) == 0) goto L46a665;  // @24_46a5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_46a5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @26_46a5e0
  ecx = edx = 0;  // @27_46a5e0
  L46a665:;
  ecx = esi;  // @29_46a5e0
  eax = ext_46a4f0_thiscall1(ecx);  // @30_46a5e0
  ecx = edx = 0;  // @31_46a5e0
  SEH_LEAVE();  // @32_46a5e0
  return eax;  // @33_46a5e0
}
PCREG(46a5e0, lifted_46a5e0);

extern "C" u32 THISCALL lifted_4352f0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4352f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4352f0
  eax = 0;  // @1_4352f0
  L435325:;
  if (eax >= (u32)(128)) goto L4353a0;  // @3_4352f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + eax - 144), &v, sizeof v); }  // @4_4352f0
  eax = (eax + 1);  // @5_4352f0
  if ((s32)eax < (s32)(u32)(128)) goto L435325;  // @6_4352f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @7_4352f0
  edx = (u32)(EBP - 144);  // @8_4352f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4352f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(edx), (u32)(6792648), (u32)(8));  // @10_4352f0
  ecx = edx = 0;  // @11_4352f0
  eax = (u32)(EBP - 144);  // @12_4352f0
  ecx = (u32)(EBP - 272);  // @13_4352f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @14_4352f0
  ecx = edx = 0;  // @15_4352f0
  eax = (u32)(EBP - 272);  // @16_4352f0
  reg.state = (s32)((u32)(0));  // @17_4352f0
  ecx = (u32)(esi + 140);  // @18_4352f0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @19_4352f0
  ecx = edx = 0;  // @20_4352f0
  ecx = (u32)(EBP - 272);  // @21_4352f0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_4352f0
  ecx = edx = 0;  // @23_4352f0
  SEH_LEAVE();  // @24_4352f0
  ext_633654(G(u32, 0x6f5630));  // @25_4352f0
  return eax;  // @26_4352f0
  L4353a0:;
  eax = ext_634047_cdecl0();  // @28_4352f0
  ecx = edx = 0;  // @29_4352f0
}
PCREG(4352f0, lifted_4352f0);

extern "C" u32 THISCALL lifted_4353b0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4353b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4353b0
  eax = 0;  // @1_4353b0
  L4353e5:;
  if (eax >= (u32)(128)) goto L43545d;  // @3_4353b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + eax - 144), &v, sizeof v); }  // @4_4353b0
  eax = (eax + 1);  // @5_4353b0
  if ((s32)eax < (s32)(u32)(128)) goto L4353e5;  // @6_4353b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @7_4353b0
  edx = (u32)(EBP - 144);  // @8_4353b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4353b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(edx), (u32)(6792636), (u32)(8));  // @10_4353b0
  ecx = edx = 0;  // @11_4353b0
  eax = (u32)(EBP - 144);  // @12_4353b0
  ecx = (u32)(EBP - 272);  // @13_4353b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @14_4353b0
  ecx = edx = 0;  // @15_4353b0
  eax = (u32)(EBP - 272);  // @16_4353b0
  reg.state = (s32)((u32)(0));  // @17_4353b0
  ecx = (u32)(esi + 12);  // @18_4353b0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @19_4353b0
  ecx = edx = 0;  // @20_4353b0
  ecx = (u32)(EBP - 272);  // @21_4353b0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_4353b0
  ecx = edx = 0;  // @23_4353b0
  SEH_LEAVE();  // @24_4353b0
  ext_633654(G(u32, 0x6f5630));  // @25_4353b0
  return eax;  // @26_4353b0
  L43545d:;
  eax = ext_634047_cdecl0();  // @28_4353b0
  ecx = edx = 0;  // @29_4353b0
}
PCREG(4353b0, lifted_4353b0);

extern "C" u32 THISCALL lifted_4c6360(u32 ecx_in) {
  SEH_ENTER(0x668f1a);  // @h_4c6360
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c6360
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c6360
  eax = ext_469870_thiscall1(ecx);  // @2_4c6360
  ecx = edx = 0;  // @3_4c6360
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c6360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c6360
  reg.state = (s32)((u32)(0));  // @6_4c6360
  { u32 v = (u32)((u32)(6900508)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4c6360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @8_4c6360
  eax = ext_41e290_cdecl1((u32)(264));  // @9_4c6360
  ecx = edx = 0;  // @10_4c6360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @11_4c6360
  reg.state = (s32)((u32)(1));  // @12_4c6360
  if ((eax & eax) == 0) goto L4c63e0;  // @13_4c6360
  ecx = (u32)(esi + 72);  // @14_4c6360
  ecx = eax;  // @15_4c6360
  eax = ext_4d8330_thiscall4(ecx, (u32)(6900780), (u32)(6900640), (u32)(ecx));  // @16_4c6360
  ecx = edx = 0;  // @17_4c6360
  edx = eax;  // @18_4c6360
  goto L4c63e2;  // @19_4c6360
  L4c63e0:;
  edx = 0;  // @21_4c6360
  L4c63e2:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @23_4c6360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_4c6360
  reg.state = (s32)((u32)(0));  // @25_4c6360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4c6360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @27_4c6360
  ecx = edx = 0;  // @28_4c6360
  eax = esi;  // @29_4c6360
  SEH_LEAVE();  // @30_4c6360
  return eax;  // @31_4c6360
}
PCREG(4c6360, lifted_4c6360);

extern "C" u32 THISCALL lifted_4998c0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664c7f);  // @h_4998c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ext_4ccdd0_thiscall4(ecx, (u32)(edi), (u32)(eax), (u32)(256));  // @15_4998c0
  ecx = edx = 0;  // @16_4998c0
  goto L499946;  // @17_4998c0
  L499944:;
  eax = 0;  // @19_4998c0
  L499946:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @21_4998c0
  eax = esi;  // @22_4998c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @23_4998c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 308), &v, sizeof v); }  // @24_4998c0
  SEH_LEAVE();  // @25_4998c0
  return eax;  // @26_4998c0
}
PCREG(4998c0, lifted_4998c0);

extern "C" u32 THISCALL lifted_4f1a10(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4f1a10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4f1a10
  { u32 v = (u32)((u32)(6917104)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4f1a10
  eax = ext_4f2be0_thiscall1(ecx);  // @2_4f1a10
  ecx = edx = 0;  // @3_4f1a10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4f1a10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_4f1a10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_4f1a10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @7_4f1a10
  ecx = edx = 0;  // @8_4f1a10
  ecx = eax;  // @9_4f1a10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_4f1a10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 160)))(ecx, (u32)(6918004), (u32)(0));  // @11_4f1a10
  ecx = edx = 0;  // @12_4f1a10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_4f1a10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4f1a10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @15_4f1a10
  ecx = edx = 0;  // @16_4f1a10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @17_4f1a10
  if ((ecx & ecx) == 0) goto L4f1a82;  // @18_4f1a10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4f1a10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @20_4f1a10
  ecx = edx = 0;  // @21_4f1a10
  L4f1a82:;
  ecx = (u32)(esi + 423);  // @23_4f1a10
  eax = ext_4ccee0_thiscall1(ecx);  // @24_4f1a10
  ecx = edx = 0;  // @25_4f1a10
  ecx = (u32)(esi + 243);  // @26_4f1a10
  eax = ext_4ccf60_thiscall1(ecx);  // @27_4f1a10
  ecx = edx = 0;  // @28_4f1a10
  ecx = (u32)(esi + 203);  // @29_4f1a10
  eax = ext_4cce40_thiscall1(ecx);  // @30_4f1a10
  ecx = edx = 0;  // @31_4f1a10
  ecx = (u32)(esi + 159);  // @32_4f1a10
  eax = ext_4ccee0_thiscall1(ecx);  // @33_4f1a10
  ecx = edx = 0;  // @34_4f1a10
  ecx = esi;  // @35_4f1a10
  eax = ext_43ea20_thiscall1(ecx);  // @36_4f1a10
  ecx = edx = 0;  // @37_4f1a10
  SEH_LEAVE();  // @38_4f1a10
  return eax;  // @39_4f1a10
}
PCREG(4f1a10, lifted_4f1a10);

extern "C" u32 THISCALL lifted_6040d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66de50);  // @h_6040d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_6040d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_6040d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(0));  // @2_6040d0
  ecx = edx = 0;  // @3_6040d0
  esi = eax;  // @4_6040d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @5_6040d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_6040d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @7_6040d0
  ecx = (u32)(EBP - 28);  // @8_6040d0
  reg.state = (s32)((u32)(0));  // @9_6040d0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @10_6040d0
  eax = ext_59a9b0_thiscall2(ecx, (u32)(50));  // @11_6040d0
  ecx = edx = 0;  // @12_6040d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_6040d0
  ecx = (u32)(EBP - 28);  // @14_6040d0
  ecx = esi;  // @15_6040d0
  reg.state = (s32)((u32)(1));  // @16_6040d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(ecx));  // @17_6040d0
  ecx = edx = 0;  // @18_6040d0
  ecx = (u32)(EBP - 28);  // @19_6040d0
  eax = ext_500190_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @20_6040d0
  ecx = edx = 0;  // @21_6040d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_6040d0
  ecx = edi;  // @23_6040d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(esi));  // @24_6040d0
  ecx = edx = 0;  // @25_6040d0
  ecx = (u32)(EBP - 28);  // @26_6040d0
  eax = ext_4ff9d0_thiscall1(ecx);  // @27_6040d0
  ecx = edx = 0;  // @28_6040d0
  SEH_LEAVE();  // @29_6040d0
  return eax;  // @30_6040d0
}
PCREG(6040d0, lifted_6040d0);

extern "C" u32 THISCALL lifted_4cb150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66906b);  // @h_4cb150
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4cb150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1_4cb150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4cb150
  if ((eax & eax) == 0) goto L4cb18f;  // @3_4cb150
  eax = ((u32(STDCALL *)(void))(eax))();  // @4_4cb150
  ecx = edx = 0;  // @5_4cb150
  goto L4cb190;  // @6_4cb150
  L4cb18f:;
  __builtin_trap();  // @8_4cb150
  L4cb190:;
  ecx = edi;  // @10_4cb150
  eax = ext_4e5e60_thiscall1(ecx);  // @11_4cb150
  ecx = edx = 0;  // @12_4cb150
  ecx = (u32)(EBP - 188);  // @13_4cb150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @14_4cb150
  eax = ext_4ccba0_thiscall1(ecx);  // @15_4cb150
  ecx = edx = 0;  // @16_4cb150
  eax = (u32)(EBP - 188);  // @17_4cb150
  reg.state = (s32)((u32)(0));  // @18_4cb150
  ecx = edi;  // @19_4cb150
  eax = ext_4e6330_thiscall2(ecx, (u32)(eax));  // @20_4cb150
  ecx = edx = 0;  // @21_4cb150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_4cb150
  ecx = (u32)(EBP - 188);  // @23_4cb150
  ecx = esi;  // @24_4cb150
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(ecx));  // @25_4cb150
  ecx = edx = 0;  // @26_4cb150
  ecx = (u32)(EBP - 188);  // @27_4cb150
  eax = ext_4ccf60_thiscall1(ecx);  // @28_4cb150
  ecx = edx = 0;  // @29_4cb150
  SEH_LEAVE();  // @30_4cb150
  ext_633654(G(u32, 0x6f5630));  // @31_4cb150
  return eax;  // @32_4cb150
}
PCREG(4cb150, lifted_4cb150);

extern "C" u32 STDCALL lifted_43a720(u32 a0) {
  SEH_ENTER(0x665c56);  // @h_43a720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_43a720
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @1_43a720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }) != 0) goto L43a7ab;  // @2_43a720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4628), sizeof v); (u32)v; });  // @3_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_43a720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(esi));  // @5_43a720
  ecx = edx = 0;  // @6_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @7_43a720
  reg.state = (s32)((u32)(0));  // @8_43a720
  { u32 v = (u32)((u32)(6793124)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_43a720
  if ((eax & eax) == 0) goto L43a777;  // @10_43a720
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @11_43a720
  ecx = edx = 0;  // @12_43a720
  L43a777:;
  ecx = esi;  // @14_43a720
  eax = ext_43a900_thiscall1(ecx);  // @15_43a720
  ecx = edx = 0;  // @16_43a720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @17_43a720
  if ((ecx & ecx) == 0) goto L43a78b;  // @18_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_43a720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @20_43a720
  ecx = edx = 0;  // @21_43a720
  L43a78b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @23_43a720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4916), sizeof v); (u32)v; }) != esi) goto L43a7a0;  // @24_43a720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4916), &v, sizeof v); }  // @25_43a720
  L43a7a0:;
  eax = ext_634273_cdecl2((u32)(esi), (u32)(35));  // @27_43a720
  ecx = edx = 0;  // @28_43a720
  L43a7ab:;
  SEH_LEAVE();  // @30_43a720
  return eax;  // @31_43a720
}
PCREG(43a720, lifted_43a720);

extern "C" u32 THISCALL lifted_435580(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_435580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435580
  ecx = (u32)(EBP - 144);  // @2_435580
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @3_435580
  ecx = edx = 0;  // @4_435580
  eax = (u32)(EBP - 144);  // @5_435580
  reg.state = (s32)((u32)(0));  // @6_435580
  edi = (edi + (u32)(140));  // @7_435580
  ecx = edi;  // @8_435580
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @9_435580
  ecx = edx = 0;  // @10_435580
  ecx = (u32)(EBP - 144);  // @11_435580
  reg.state = (s32)((u32)(4294967295));  // @12_435580
  eax = ext_4cbec0_thiscall1(ecx);  // @13_435580
  ecx = edx = 0;  // @14_435580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @15_435580
  ecx = edi;  // @16_435580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_435580
  eax = ext_4cc5f0_thiscall1(ecx);  // @18_435580
  ecx = edx = 0;  // @19_435580
  ecx = edi;  // @20_435580
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @21_435580
  ecx = edx = 0;  // @22_435580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @23_435580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 20)))(ecx, (u32)(6792648), (u32)(8), (u32)(eax));  // @24_435580
  ecx = edx = 0;  // @25_435580
  SEH_LEAVE();  // @26_435580
  ext_633654(G(u32, 0x6f5630));  // @27_435580
  return eax;  // @28_435580
}
PCREG(435580, lifted_435580);

extern "C" u32 THISCALL lifted_435630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_435630
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435630
  ecx = (u32)(EBP - 144);  // @2_435630
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @3_435630
  ecx = edx = 0;  // @4_435630
  eax = (u32)(EBP - 144);  // @5_435630
  reg.state = (s32)((u32)(0));  // @6_435630
  edi = (edi + (u32)(12));  // @7_435630
  ecx = edi;  // @8_435630
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @9_435630
  ecx = edx = 0;  // @10_435630
  ecx = (u32)(EBP - 144);  // @11_435630
  reg.state = (s32)((u32)(4294967295));  // @12_435630
  eax = ext_4cbec0_thiscall1(ecx);  // @13_435630
  ecx = edx = 0;  // @14_435630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @15_435630
  ecx = edi;  // @16_435630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_435630
  eax = ext_4cc5f0_thiscall1(ecx);  // @18_435630
  ecx = edx = 0;  // @19_435630
  ecx = edi;  // @20_435630
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @21_435630
  ecx = edx = 0;  // @22_435630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @23_435630
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 20)))(ecx, (u32)(6792636), (u32)(8), (u32)(eax));  // @24_435630
  ecx = edx = 0;  // @25_435630
  SEH_LEAVE();  // @26_435630
  ext_633654(G(u32, 0x6f5630));  // @27_435630
  return eax;  // @28_435630
}
PCREG(435630, lifted_435630);

extern "C" u32 THISCALL lifted_4f8b60(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_4f8b60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4f8b60
  ecx = (u32)(EBP - 144);  // @1_4f8b60
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @2_4f8b60
  ecx = edx = 0;  // @3_4f8b60
  eax = (u32)(EBP - 144);  // @4_4f8b60
  reg.state = (s32)((u32)(0));  // @5_4f8b60
  ecx = (u32)(ebx + 143);  // @6_4f8b60
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @7_4f8b60
  ecx = edx = 0;  // @8_4f8b60
  ecx = (u32)(EBP - 144);  // @9_4f8b60
  reg.state = (s32)((u32)(4294967295));  // @10_4f8b60
  eax = ext_4cbec0_thiscall1(ecx);  // @11_4f8b60
  ecx = edx = 0;  // @12_4f8b60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_4f8b60
  ecx = (u32)(ebx + 143);  // @14_4f8b60
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_4f8b60
  ecx = edx = 0;  // @16_4f8b60
  ecx = ebx;  // @17_4f8b60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, (u32)(eax));  // @18_4f8b60
  ecx = edx = 0;  // @19_4f8b60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 447), sizeof v); (u32)v; }) == (u32)(0)) goto L4f8bf6;  // @20_4f8b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @21_4f8b60
  ecx = ebx;  // @22_4f8b60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 868)))(ecx, (u32)(0));  // @23_4f8b60
  ecx = edx = 0;  // @24_4f8b60
  L4f8bf6:;
  SEH_LEAVE();  // @26_4f8b60
  ext_633654(G(u32, 0x6f5630));  // @27_4f8b60
  return eax;  // @28_4f8b60
}
PCREG(4f8b60, lifted_4f8b60);

extern "C" u32 THISCALL lifted_495230(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667fff);  // @h_495230
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_495230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 23861), sizeof v); (u32)v; });  // @1_495230
  if ((esi & esi) == 0) goto L495273;  // @2_495230
  ecx = esi;  // @3_495230
  eax = ext_49b680_thiscall1(ecx);  // @4_495230
  ecx = edx = 0;  // @5_495230
  eax = ext_634273_cdecl2((u32)(esi), (u32)(65));  // @6_495230
  ecx = edx = 0;  // @7_495230
  L495273:;
  eax = ext_41e290_cdecl1((u32)(97));  // @9_495230
  ecx = edx = 0;  // @10_495230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @11_495230
  reg.state = (s32)((u32)(0));  // @12_495230
  if ((eax & eax) == 0) goto L4952ae;  // @13_495230
  ecx = eax;  // @14_495230
  eax = ext_49b5c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @15_495230
  ecx = edx = 0;  // @16_495230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 23861), &v, sizeof v); }  // @17_495230
  SEH_LEAVE();  // @18_495230
  return eax;  // @19_495230
  L4952ae:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23861), &v, sizeof v); }  // @21_495230
  SEH_LEAVE();  // @22_495230
  return eax;  // @23_495230
}
PCREG(495230, lifted_495230);

extern "C" u32 THISCALL lifted_567720(u32 ecx_in) {
  SEH_ENTER(0x66c468);  // @h_567720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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

extern "C" u32 lifted_48a390(void) {
  SEH_ENTER(0x6676b2);  // @h_48a390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = eax;  // @21_48a390
  eax = ext_48a470_thiscall2(ecx, (u32)(esi));  // @22_48a390
  ecx = edx = 0;  // @23_48a390
  edx = eax;  // @24_48a390
  goto L48a418;  // @25_48a390
  L48a416:;
  edx = 0;  // @27_48a390
  L48a418:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_48a390
  reg.state = (s32)((u32)(4294967295));  // @30_48a390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_48a390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 260)))(ecx, (u32)(edx));  // @32_48a390
  ecx = edx = 0;  // @33_48a390
  SEH_LEAVE();  // @34_48a390
  return eax;  // @35_48a390
}
PCREG(48a390, lifted_48a390);

extern "C" u32 THISCALL lifted_5c9530(u32 ecx_in) {
  SEH_ENTER(0x66c588);  // @h_5c9530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5c9530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5c9530
  eax = ext_469870_thiscall1(ecx);  // @2_5c9530
  ecx = edx = 0;  // @3_5c9530
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5c9530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5c9530
  reg.state = (s32)((u32)(0));  // @6_5c9530
  edi = (u32)(esi + 108);  // @7_5c9530
  { u32 v = (u32)((u32)(7031552)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5c9530
  ebx = (u32)(5);  // @9_5c9530
  L5c9580:;
  ecx = edi;  // @11_5c9530
  eax = ext_4e1b60_thiscall1(ecx);  // @12_5c9530
  ecx = edx = 0;  // @13_5c9530
  edi = (edi + (u32)(130));  // @14_5c9530
  ebx = (ebx - (u32)(1));  // @15_5c9530
  if (ebx != 0) goto L5c9580;  // @16_5c9530
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 778), &v, sizeof v); }  // @17_5c9530
  eax = esi;  // @18_5c9530
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @19_5c9530
  { u32 v = (u32)((u32)(1203982336)); __builtin_memcpy((void *)(u32)(esi + 758), &v, sizeof v); }  // @20_5c9530
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 216), &v, sizeof v); }  // @21_5c9530
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 346), &v, sizeof v); }  // @22_5c9530
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 476), &v, sizeof v); }  // @23_5c9530
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 606), &v, sizeof v); }  // @24_5c9530
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 736), &v, sizeof v); }  // @25_5c9530
  { u32 v = (u32)((u32)(1203982336)); __builtin_memcpy((void *)(u32)(esi + 347), &v, sizeof v); }  // @26_5c9530
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @27_5c9530
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1092), &v, sizeof v); }  // @28_5c9530
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1096), &v, sizeof v); }  // @29_5c9530
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1100), &v, sizeof v); }  // @30_5c9530
  SEH_LEAVE();  // @31_5c9530
  return eax;  // @32_5c9530
}
PCREG(5c9530, lifted_5c9530);

extern "C" u32 lifted_605400(void) {
  SEH_ENTER(0x66dda7);  // @h_605400
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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

extern "C" u32 FASTCALL lifted_4697d0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665e21);  // @h_4697d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_4697d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4697d0
  eax = ext_45c4f0_cdecl2((u32)(148), (u32)(ecx));  // @2_4697d0
  ecx = edx = 0;  // @3_4697d0
  esi = eax;  // @4_4697d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_4697d0
  reg.state = (s32)((u32)(0));  // @6_4697d0
  if ((esi & esi) == 0) goto L469856;  // @7_4697d0
  ecx = esi;  // @8_4697d0
  eax = ext_469980_thiscall4(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @9_4697d0
  ecx = edx = 0;  // @10_4697d0
  eax = 0;  // @11_4697d0
  { u32 v = (u32)((u32)(6846024)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_4697d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 146), &v, sizeof v); }  // @13_4697d0
  eax = esi;  // @14_4697d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 142), &v, sizeof v); }  // @15_4697d0
  SEH_LEAVE();  // @16_4697d0
  return eax;  // @17_4697d0
  L469856:;
  eax = 0;  // @19_4697d0
  SEH_LEAVE();  // @20_4697d0
  return eax;  // @21_4697d0
}
PCREG(4697d0, lifted_4697d0);

extern "C" u32 THISCALL lifted_4e7dd0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6697df);  // @h_4e7dd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = eax;  // @15_4e7dd0
  eax = ext_4ccc30_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(5));  // @16_4e7dd0
  ecx = edx = 0;  // @17_4e7dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @18_4e7dd0
  eax = esi;  // @19_4e7dd0
  SEH_LEAVE();  // @20_4e7dd0
  return eax;  // @21_4e7dd0
  L4e7e5f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @23_4e7dd0
  eax = esi;  // @24_4e7dd0
  SEH_LEAVE();  // @25_4e7dd0
  return eax;  // @26_4e7dd0
}
PCREG(4e7dd0, lifted_4e7dd0);

extern "C" u32 THISCALL lifted_46a680(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_46a680
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_46a680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_46a680
  reg.state = (s32)((u32)(0));  // @3_46a680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_46a680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @6_46a680
  ecx = edx = 0;  // @7_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_46a680
  reg.state = (s32)((u32)(4294967295));  // @9_46a680
  if (((eax & 0xff) & (u32)(1)) == 0) goto L46a71b;  // @10_46a680
  if (((eax & 0xff) & (u32)(4)) != 0) goto L46a710;  // @11_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @12_46a680
  reg.state = (s32)((u32)(1));  // @13_46a680
  if ((eax & eax) == 0) goto L46a6fb;  // @14_46a680
  eax = ((u32(STDCALL *)(void))(eax))();  // @15_46a680
  ecx = edx = 0;  // @16_46a680
  eax = esi;  // @17_46a680
  SEH_LEAVE();  // @18_46a680
  return eax;  // @19_46a680
  L46a6fb:;
  __builtin_trap();  // @21_46a680
  L46a710:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(64));  // @23_46a680
  ecx = edx = 0;  // @24_46a680
  L46a71b:;
  eax = esi;  // @26_46a680
  SEH_LEAVE();  // @27_46a680
  return eax;  // @28_46a680
}
PCREG(46a680, lifted_46a680);

extern "C" u32 THISCALL lifted_5eae20(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66ca98);  // @h_5eae20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ecx;  // @0_5eae20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5eae20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_5eae20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @5_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @6_5eae20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @7_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @8_5eae20
  { u32 v = (u32)((u32)(7045224)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_5eae20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @10_5eae20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @11_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_5eae20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_5eae20
  reg.state = (s32)((u32)(0));  // @14_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_5eae20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6997996), (u32)(0), (u32)(7045300), (u32)(20));  // @16_5eae20
  ecx = edx = 0;  // @17_5eae20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422884), &v, sizeof v); }  // @18_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_5eae20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_5eae20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_5eae20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6941356), (u32)(0), (u32)(7045300), (u32)(21));  // @22_5eae20
  ecx = edx = 0;  // @23_5eae20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422888), &v, sizeof v); }  // @24_5eae20
  eax = esi;  // @25_5eae20
  SEH_LEAVE();  // @26_5eae20
  return eax;  // @27_5eae20
}
PCREG(5eae20, lifted_5eae20);

extern "C" u32 THISCALL lifted_431410(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664d1b);  // @h_431410
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_431410
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_431410
  ecx = (u32)(EBP - 144);  // @2_431410
  eax = ext_4cbeb0_thiscall1(ecx);  // @3_431410
  ecx = edx = 0;  // @4_431410
  ecx = (u32)(EBP - 144);  // @5_431410
  reg.state = (s32)((u32)(0));  // @6_431410
  eax = ext_4cbf30_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_431410
  ecx = edx = 0;  // @8_431410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @9_431410
  ecx = (u32)(EBP - 144);  // @10_431410
  eax = ext_4cc1d0_thiscall1(ecx);  // @11_431410
  ecx = edx = 0;  // @12_431410
  ecx = edi;  // @13_431410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 104)))(ecx, (u32)(ebx), (u32)(eax));  // @14_431410
  ecx = edx = 0;  // @15_431410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_431410
  ecx = (u32)(EBP - 144);  // @17_431410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_431410
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_431410
  ecx = edx = 0;  // @20_431410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_431410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, (u32)(ebx), (u32)(eax));  // @22_431410
  ecx = edx = 0;  // @23_431410
  ecx = (u32)(EBP - 144);  // @24_431410
  eax = ext_4cbec0_thiscall1(ecx);  // @25_431410
  ecx = edx = 0;  // @26_431410
  SEH_LEAVE();  // @27_431410
  ext_633654(G(u32, 0x6f5630));  // @28_431410
  return eax;  // @29_431410
}
PCREG(431410, lifted_431410);

extern "C" u32 THISCALL lifted_469b40(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666b37);  // @h_469b40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_469b40
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_469b40
  eax = ext_469980_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_469b40
  ecx = edx = 0;  // @3_469b40
  reg.state = (s32)((u32)(0));  // @4_469b40
  { u32 v = (u32)((u32)(6849288)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_469b40
  eax = ext_41e290_cdecl1((u32)(28));  // @6_469b40
  ecx = edx = 0;  // @7_469b40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @8_469b40
  reg.state = (s32)((u32)(1));  // @9_469b40
  if ((eax & eax) == 0) goto L469ba6;  // @10_469b40
  ecx = eax;  // @11_469b40
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(8), (u32)(0));  // @12_469b40
  ecx = edx = 0;  // @13_469b40
  goto L469ba8;  // @14_469b40
  L469ba6:;
  eax = 0;  // @16_469b40
  L469ba8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @18_469b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_469b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_469b40
  reg.state = (s32)((u32)(0));  // @21_469b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_469b40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6850920), (u32)(0), (u32)(6850500), (u32)(3750));  // @23_469b40
  ecx = edx = 0;  // @24_469b40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 146), &v, sizeof v); }  // @25_469b40
  eax = esi;  // @26_469b40
  SEH_LEAVE();  // @27_469b40
  return eax;  // @28_469b40
}
PCREG(469b40, lifted_469b40);

extern "C" u32 THISCALL lifted_4a4fb0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_4a4fb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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

extern "C" u32 THISCALL lifted_45fdf0(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45fdf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @14_45fdf0
  ecx = edx = 0;  // @15_45fdf0
  L45fe50:;
  eax = ext_634273_cdecl2((u32)(ebx), (u32)(16));  // @17_45fdf0
  ecx = edx = 0;  // @18_45fdf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @19_45fdf0
  L45fe62:;
  eax = ext_634273_cdecl2((u32)(edi), (u32)(8));  // @21_45fdf0
  ecx = edx = 0;  // @22_45fdf0
  L45fe6d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @24_45fdf0
  SEH_LEAVE();  // @25_45fdf0
  return eax;  // @26_45fdf0
}
PCREG(45fdf0, lifted_45fdf0);

extern "C" u32 THISCALL lifted_4b1130(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_4b1130
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = (u32)(EBP - 144);  // @22_4b1130
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @23_4b1130
  ecx = edx = 0;  // @24_4b1130
  eax = (u32)(EBP - 144);  // @25_4b1130
  reg.state = (s32)((u32)(0));  // @26_4b1130
  ecx = (u32)(edi + 86);  // @27_4b1130
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @28_4b1130
  ecx = edx = 0;  // @29_4b1130
  ecx = (u32)(EBP - 144);  // @30_4b1130
  eax = ext_4cbec0_thiscall1(ecx);  // @31_4b1130
  ecx = edx = 0;  // @32_4b1130
  L4b11c6:;
  SEH_LEAVE();  // @34_4b1130
  ext_633654(G(u32, 0x6f5630));  // @35_4b1130
  return eax;  // @36_4b1130
}
PCREG(4b1130, lifted_4b1130);

extern "C" u32 THISCALL lifted_431580(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664d1b);  // @h_431580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  reg.state = (s32)((u32)(0));  // @7_431580
  eax = ext_4cbf30_thiscall2(ecx, (u32)(eax));  // @8_431580
  ecx = edx = 0;  // @9_431580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_431580
  ecx = (u32)(EBP - 144);  // @11_431580
  eax = ext_4cc1d0_thiscall1(ecx);  // @12_431580
  ecx = edx = 0;  // @13_431580
  ecx = edi;  // @14_431580
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 104)))(ecx, (u32)(ebx), (u32)(eax));  // @15_431580
  ecx = edx = 0;  // @16_431580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_431580
  ecx = (u32)(EBP - 144);  // @18_431580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_431580
  eax = ext_4cc1d0_thiscall1(ecx);  // @20_431580
  ecx = edx = 0;  // @21_431580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_431580
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, (u32)(ebx), (u32)(eax));  // @23_431580
  ecx = edx = 0;  // @24_431580
  ecx = (u32)(EBP - 144);  // @25_431580
  eax = ext_4cbec0_thiscall1(ecx);  // @26_431580
  ecx = edx = 0;  // @27_431580
  SEH_LEAVE();  // @28_431580
  ext_633654(G(u32, 0x6f5630));  // @29_431580
  return eax;  // @30_431580
}
PCREG(431580, lifted_431580);

extern "C" u32 THISCALL lifted_566bc0(u32 ecx_in) {
  SEH_ENTER(0x66c3da);  // @h_566bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = eax;  // @16_566bc0
  eax = ext_4d8330_thiscall4(ecx, (u32)(6791420), (u32)(6975376), (u32)(edi));  // @17_566bc0
  ecx = edx = 0;  // @18_566bc0
  edx = eax;  // @19_566bc0
  goto L566c58;  // @20_566bc0
  L566c56:;
  edx = 0;  // @22_566bc0
  L566c58:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @24_566bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_566bc0
  reg.state = (s32)((u32)(0));  // @26_566bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_566bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @28_566bc0
  ecx = edx = 0;  // @29_566bc0
  eax = esi;  // @30_566bc0
  SEH_LEAVE();  // @31_566bc0
  return eax;  // @32_566bc0
}
PCREG(566bc0, lifted_566bc0);

extern "C" u32 THISCALL lifted_500220(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66ae60);  // @h_500220
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_500220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_500220
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(0));  // @2_500220
  ecx = edx = 0;  // @3_500220
  edi = eax;  // @4_500220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @5_500220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_500220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @7_500220
  ecx = (u32)(EBP - 28);  // @8_500220
  reg.state = (s32)((u32)(0));  // @9_500220
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @10_500220
  eax = ext_59a9b0_thiscall2(ecx, (u32)(50));  // @11_500220
  ecx = edx = 0;  // @12_500220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_500220
  ecx = (u32)(EBP - 28);  // @14_500220
  ecx = edi;  // @15_500220
  reg.state = (s32)((u32)(1));  // @16_500220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(ecx));  // @17_500220
  ecx = edx = 0;  // @18_500220
  ecx = (u32)(EBP - 28);  // @19_500220
  eax = ext_500150_thiscall1(ecx);  // @20_500220
  ecx = edx = 0;  // @21_500220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @22_500220
  ecx = ebx;  // @23_500220
  esi = eax;  // @24_500220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, (u32)(edi));  // @25_500220
  ecx = edx = 0;  // @26_500220
  ecx = (u32)(EBP - 28);  // @27_500220
  eax = ext_4ff9d0_thiscall1(ecx);  // @28_500220
  ecx = edx = 0;  // @29_500220
  eax = (u32)(esi + 4);  // @30_500220
  SEH_LEAVE();  // @31_500220
  return eax;  // @32_500220
}
PCREG(500220, lifted_500220);

extern "C" u32 THISCALL lifted_54acc0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_54acc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_54acc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25580), sizeof v); (u32)v; });  // @1_54acc0
  { u32 v = (u32)((u32)(6961080)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_54acc0
  if ((ecx & ecx) == 0) goto L54ad0b;  // @3_54acc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_54acc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(ecx));  // @5_54acc0
  ecx = edx = 0;  // @6_54acc0
  if ((eax & eax) == 0) goto L54ad0b;  // @7_54acc0
  edx = (u32)(6962064);  // @8_54acc0
  ecx = eax;  // @9_54acc0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @10_54acc0
  ecx = edx = 0;  // @11_54acc0
  L54ad0b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25584), sizeof v); (u32)v; });  // @13_54acc0
  if ((ecx & ecx) == 0) goto L54ad1b;  // @14_54acc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_54acc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @16_54acc0
  ecx = edx = 0;  // @17_54acc0
  L54ad1b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25588), sizeof v); (u32)v; });  // @19_54acc0
  if ((ecx & ecx) == 0) goto L54ad2b;  // @20_54acc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_54acc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @22_54acc0
  ecx = edx = 0;  // @23_54acc0
  L54ad2b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25580), sizeof v); (u32)v; });  // @25_54acc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25584), &v, sizeof v); }  // @26_54acc0
  if ((ecx & ecx) == 0) goto L54ad4f;  // @27_54acc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_54acc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @29_54acc0
  ecx = edx = 0;  // @30_54acc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25580), &v, sizeof v); }  // @31_54acc0
  L54ad4f:;
  ecx = esi;  // @33_54acc0
  eax = ext_549350_thiscall1(ecx);  // @34_54acc0
  ecx = edx = 0;  // @35_54acc0
  SEH_LEAVE();  // @36_54acc0
  return eax;  // @37_54acc0
}
PCREG(54acc0, lifted_54acc0);

extern "C" u32 THISCALL lifted_5dc5f0(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_5dc5f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5dc5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 101), sizeof v); (u32)v; });  // @1_5dc5f0
  { u32 v = (u32)((u32)(7039908)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5dc5f0
  if ((eax & eax) == 0) goto L5dc62b;  // @3_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @4_5dc5f0
  ecx = edx = 0;  // @5_5dc5f0
  L5dc62b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 105), sizeof v); (u32)v; });  // @7_5dc5f0
  if ((eax & eax) == 0) goto L5dc63b;  // @8_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @9_5dc5f0
  ecx = edx = 0;  // @10_5dc5f0
  L5dc63b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 109), sizeof v); (u32)v; });  // @12_5dc5f0
  if ((eax & eax) == 0) goto L5dc64b;  // @13_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @14_5dc5f0
  ecx = edx = 0;  // @15_5dc5f0
  L5dc64b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @17_5dc5f0
  if ((eax & eax) == 0) goto L5dc65b;  // @18_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @19_5dc5f0
  ecx = edx = 0;  // @20_5dc5f0
  L5dc65b:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @22_5dc5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @23_5dc5f0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @24_5dc5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_5dc5f0
  reg.state = (s32)((u32)(0));  // @26_5dc5f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @27_5dc5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5dc5f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @29_5dc5f0
  ecx = edx = 0;  // @30_5dc5f0
  SEH_LEAVE();  // @31_5dc5f0
  return eax;  // @32_5dc5f0
}
PCREG(5dc5f0, lifted_5dc5f0);

extern "C" u32 THISCALL lifted_4c4a70(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_4c4a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c4a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @1_4c4a70
  { u32 v = (u32)((u32)(6897948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4c4a70
  if ((ecx & ecx) == 0) goto L4c4aa8;  // @3_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4c4a70
  ecx = edx = 0;  // @6_4c4a70
  L4c4aa8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @8_4c4a70
  if ((ecx & ecx) == 0) goto L4c4ab5;  // @9_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_4c4a70
  ecx = edx = 0;  // @12_4c4a70
  L4c4ab5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @14_4c4a70
  if ((ecx & ecx) == 0) goto L4c4ac2;  // @15_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_4c4a70
  ecx = edx = 0;  // @18_4c4a70
  L4c4ac2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @20_4c4a70
  if ((ecx & ecx) == 0) goto L4c4acf;  // @21_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_4c4a70
  ecx = edx = 0;  // @24_4c4a70
  L4c4acf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @26_4c4a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @27_4c4a70
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @28_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4c4a70
  reg.state = (s32)((u32)(0));  // @30_4c4a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @33_4c4a70
  ecx = edx = 0;  // @34_4c4a70
  SEH_LEAVE();  // @35_4c4a70
  return eax;  // @36_4c4a70
}
PCREG(4c4a70, lifted_4c4a70);

extern "C" u32 THISCALL lifted_4373a0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x665a8f);  // @h_4373a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_4373a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4373a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @2_4373a0
  ecx = edx = 0;  // @3_4373a0
  if ((eax & eax) == 0) goto L4373e7;  // @4_4373a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @5_4373a0
  SEH_LEAVE();  // @6_4373a0
  return eax;  // @7_4373a0
  L4373e7:;
  eax = ext_41e290_cdecl1((u32)(35));  // @9_4373a0
  ecx = edx = 0;  // @10_4373a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @11_4373a0
  reg.state = (s32)((u32)(0));  // @12_4373a0
  if ((eax & eax) == 0) goto L437413;  // @13_4373a0
  ecx = eax;  // @14_4373a0
  eax = ext_4364e0_thiscall5(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(0));  // @15_4373a0
  ecx = edx = 0;  // @16_4373a0
  edx = eax;  // @17_4373a0
  goto L437415;  // @18_4373a0
  L437413:;
  edx = 0;  // @20_4373a0
  L437415:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4628), sizeof v); (u32)v; });  // @22_4373a0
  reg.state = (s32)((u32)(4294967295));  // @23_4373a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4373a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edx));  // @25_4373a0
  ecx = edx = 0;  // @26_4373a0
  SEH_LEAVE();  // @27_4373a0
  return eax;  // @28_4373a0
}
PCREG(4373a0, lifted_4373a0);

extern "C" u32 THISCALL lifted_49a240(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66825f);  // @h_49a240
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_49a240
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; }) != (u32)(0)) goto L49a2a6;  // @1_49a240
  eax = ext_41e290_cdecl1((u32)(28));  // @2_49a240
  ecx = edx = 0;  // @3_49a240
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_49a240
  reg.state = (s32)((u32)(0));  // @5_49a240
  if ((eax & eax) == 0) goto L49a297;  // @6_49a240
  ecx = eax;  // @7_49a240
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(2));  // @8_49a240
  ecx = edx = 0;  // @9_49a240
  goto L49a299;  // @10_49a240
  L49a297:;
  eax = 0;  // @12_49a240
  L49a299:;
  reg.state = (s32)((u32)(4294967295));  // @14_49a240
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 312), &v, sizeof v); }  // @15_49a240
  L49a2a6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @17_49a240
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_49a240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @19_49a240
  ecx = edx = 0;  // @20_49a240
  ecx = eax;  // @21_49a240
  if ((ecx & ecx) != 0) goto L49a2d8;  // @22_49a240
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @23_49a240
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_49a240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @25_49a240
  ecx = edx = 0;  // @26_49a240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @27_49a240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @28_49a240
  ecx = (u32)(eax - 4);  // @29_49a240
  L49a2d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_49a240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @32_49a240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @33_49a240
  SEH_LEAVE();  // @34_49a240
  return eax;  // @35_49a240
}
PCREG(49a240, lifted_49a240);

extern "C" u32 THISCALL lifted_46a870(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_46a870
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_46a870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @1_46a870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @2_46a870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @3_46a870
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_46a870
  reg.state = (s32)((u32)(0));  // @6_46a870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_46a870
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @9_46a870
  ecx = edx = 0;  // @10_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_46a870
  reg.state = (s32)((u32)(4294967295));  // @12_46a870
  if (((eax & 0xff) & (u32)(1)) == 0) goto L46a920;  // @13_46a870
  if (((eax & 0xff) & (u32)(4)) != 0) goto L46a915;  // @14_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_46a870
  reg.state = (s32)((u32)(1));  // @16_46a870
  if ((eax & eax) == 0) goto L46a900;  // @17_46a870
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_46a870
  ecx = edx = 0;  // @19_46a870
  eax = esi;  // @20_46a870
  SEH_LEAVE();  // @21_46a870
  return eax;  // @22_46a870
  L46a900:;
  __builtin_trap();  // @24_46a870
  L46a915:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(94));  // @26_46a870
  ecx = edx = 0;  // @27_46a870
  L46a920:;
  eax = esi;  // @29_46a870
  SEH_LEAVE();  // @30_46a870
  return eax;  // @31_46a870
}
PCREG(46a870, lifted_46a870);

extern "C" u32 THISCALL lifted_5658e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_5658e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5658e0
  { u32 v = (u32)((u32)(6974476)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @1_5658e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @2_5658e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @3_5658e0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5658e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5658e0
  reg.state = (s32)((u32)(0));  // @6_5658e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_5658e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5658e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @9_5658e0
  ecx = edx = 0;  // @10_5658e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_5658e0
  reg.state = (s32)((u32)(4294967295));  // @12_5658e0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L565996;  // @13_5658e0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L565988;  // @14_5658e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_5658e0
  reg.state = (s32)((u32)(1));  // @16_5658e0
  if ((eax & eax) == 0) goto L565973;  // @17_5658e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_5658e0
  ecx = edx = 0;  // @19_5658e0
  eax = esi;  // @20_5658e0
  SEH_LEAVE();  // @21_5658e0
  return eax;  // @22_5658e0
  L565973:;
  __builtin_trap();  // @24_5658e0
  L565988:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(3250));  // @26_5658e0
  ecx = edx = 0;  // @27_5658e0
  L565996:;
  eax = esi;  // @29_5658e0
  SEH_LEAVE();  // @30_5658e0
  return eax;  // @31_5658e0
}
PCREG(5658e0, lifted_5658e0);

extern "C" u32 THISCALL lifted_5c6050(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_5c6050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5c6050
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @1_5c6050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @2_5c6050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @3_5c6050
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5c6050
  reg.state = (s32)((u32)(0));  // @6_5c6050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5c6050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @9_5c6050
  ecx = edx = 0;  // @10_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_5c6050
  reg.state = (s32)((u32)(4294967295));  // @12_5c6050
  if (((eax & 0xff) & (u32)(1)) == 0) goto L5c60fd;  // @13_5c6050
  if (((eax & 0xff) & (u32)(4)) != 0) goto L5c60f2;  // @14_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_5c6050
  reg.state = (s32)((u32)(1));  // @16_5c6050
  if ((eax & eax) == 0) goto L5c60dd;  // @17_5c6050
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_5c6050
  ecx = edx = 0;  // @19_5c6050
  eax = esi;  // @20_5c6050
  SEH_LEAVE();  // @21_5c6050
  return eax;  // @22_5c6050
  L5c60dd:;
  __builtin_trap();  // @24_5c6050
  L5c60f2:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(85));  // @26_5c6050
  ecx = edx = 0;  // @27_5c6050
  L5c60fd:;
  eax = esi;  // @29_5c6050
  SEH_LEAVE();  // @30_5c6050
  return eax;  // @31_5c6050
}
PCREG(5c6050, lifted_5c6050);

extern "C" u32 THISCALL lifted_5dae30(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_5dae30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5dae30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5dae30
  eax = ext_469870_thiscall1(ecx);  // @2_5dae30
  ecx = edx = 0;  // @3_5dae30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5dae30
  reg.state = (s32)((u32)(0));  // @6_5dae30
  { u32 v = (u32)((u32)(7038804)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @8_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @9_5dae30
  { u32 v = (u32)((u32)(1045220557)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @10_5dae30
  eax = ext_41e290_cdecl1((u32)(28));  // @11_5dae30
  ecx = edx = 0;  // @12_5dae30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_5dae30
  reg.state = (s32)((u32)(1));  // @14_5dae30
  if ((eax & eax) == 0) goto L5daeaf;  // @15_5dae30
  ecx = eax;  // @16_5dae30
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @17_5dae30
  ecx = edx = 0;  // @18_5dae30
  goto L5daeb1;  // @19_5dae30
  L5daeaf:;
  eax = 0;  // @21_5dae30
  L5daeb1:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @23_5dae30
  eax = esi;  // @24_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @25_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @26_5dae30
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @27_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @28_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @29_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @30_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @31_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @32_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @33_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @34_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @35_5dae30
  SEH_LEAVE();  // @36_5dae30
  return eax;  // @37_5dae30
}
PCREG(5dae30, lifted_5dae30);

extern "C" u32 THISCALL lifted_5db5b0(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_5db5b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5db5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5db5b0
  eax = ext_469870_thiscall1(ecx);  // @2_5db5b0
  ecx = edx = 0;  // @3_5db5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5db5b0
  reg.state = (s32)((u32)(0));  // @6_5db5b0
  { u32 v = (u32)((u32)(7039056)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5db5b0
  eax = ext_41e290_cdecl1((u32)(28));  // @8_5db5b0
  ecx = edx = 0;  // @9_5db5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_5db5b0
  reg.state = (s32)((u32)(1));  // @11_5db5b0
  if ((eax & eax) == 0) goto L5db61a;  // @12_5db5b0
  ecx = eax;  // @13_5db5b0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @14_5db5b0
  ecx = edx = 0;  // @15_5db5b0
  goto L5db61c;  // @16_5db5b0
  L5db61a:;
  eax = 0;  // @18_5db5b0
  L5db61c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @20_5db5b0
  eax = esi;  // @21_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 139), &v, sizeof v); }  // @22_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 143), &v, sizeof v); }  // @23_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @24_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 91), &v, sizeof v); }  // @25_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 95), &v, sizeof v); }  // @26_5db5b0
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)(esi + 127), &v, sizeof v); }  // @27_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 131), &v, sizeof v); }  // @28_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @29_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @30_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @31_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 87), &v, sizeof v); }  // @32_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @33_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 107), &v, sizeof v); }  // @34_5db5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 103), &v, sizeof v); }  // @35_5db5b0
  SEH_LEAVE();  // @36_5db5b0
  return eax;  // @37_5db5b0
}
PCREG(5db5b0, lifted_5db5b0);

extern "C" u32 THISCALL lifted_449ed0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_449ed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_449ed0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L449f2e;  // @1_449ed0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_449ed0
  ecx = edx = 0;  // @3_449ed0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_449ed0
  reg.state = (s32)((u32)(0));  // @5_449ed0
  if ((eax & eax) == 0) goto L449f22;  // @6_449ed0
  ecx = eax;  // @7_449ed0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @8_449ed0
  ecx = edx = 0;  // @9_449ed0
  goto L449f24;  // @10_449ed0
  L449f22:;
  eax = 0;  // @12_449ed0
  L449f24:;
  reg.state = (s32)((u32)(4294967295));  // @14_449ed0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @15_449ed0
  L449f2e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @17_449ed0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(edi));  // @20_449ed0
  ecx = edx = 0;  // @21_449ed0
  if ((eax & eax) != 0) goto L449f47;  // @22_449ed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @23_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edi));  // @25_449ed0
  ecx = edx = 0;  // @26_449ed0
  L449f47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_449ed0
  ecx = esi;  // @29_449ed0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 560)))(ecx, (u32)(edi), (u32)(1));  // @30_449ed0
  ecx = edx = 0;  // @31_449ed0
  SEH_LEAVE();  // @32_449ed0
  return eax;  // @33_449ed0
}
PCREG(449ed0, lifted_449ed0);

extern "C" u32 THISCALL lifted_453b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_453b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_453b50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; }) != (u32)(0)) goto L453bae;  // @1_453b50
  eax = ext_41e290_cdecl1((u32)(28));  // @2_453b50
  ecx = edx = 0;  // @3_453b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_453b50
  reg.state = (s32)((u32)(0));  // @5_453b50
  if ((eax & eax) == 0) goto L453ba2;  // @6_453b50
  ecx = eax;  // @7_453b50
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(0));  // @8_453b50
  ecx = edx = 0;  // @9_453b50
  goto L453ba4;  // @10_453b50
  L453ba2:;
  eax = 0;  // @12_453b50
  L453ba4:;
  reg.state = (s32)((u32)(4294967295));  // @14_453b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @15_453b50
  L453bae:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; });  // @17_453b50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(edi));  // @20_453b50
  ecx = edx = 0;  // @21_453b50
  if ((eax & eax) != 0) goto L453bd8;  // @22_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; });  // @23_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edi));  // @25_453b50
  ecx = edx = 0;  // @26_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edi));  // @30_453b50
  ecx = edx = 0;  // @31_453b50
  L453bd8:;
  SEH_LEAVE();  // @33_453b50
  return eax;  // @34_453b50
}
PCREG(453b50, lifted_453b50);

extern "C" u32 FASTCALL lifted_45ace0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666539);  // @h_45ace0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_45ace0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_45ace0
  eax = ext_45c4f0_cdecl2((u32)(36), (u32)(ecx));  // @2_45ace0
  ecx = edx = 0;  // @3_45ace0
  esi = eax;  // @4_45ace0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_45ace0
  reg.state = (s32)((u32)(0));  // @6_45ace0
  if ((esi & esi) == 0) goto L45ad73;  // @7_45ace0
  ecx = esi;  // @8_45ace0
  eax = ext_43de40_thiscall4(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @9_45ace0
  ecx = edx = 0;  // @10_45ace0
  { u32 v = (u32)((u32)(6831696)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_45ace0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @12_45ace0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @13_45ace0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @14_45ace0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @15_45ace0
  reg.state = (s32)((u32)(1));  // @16_45ace0
  eax = ext_4dcdf0_thiscall2(ecx, (u32)(0));  // @17_45ace0
  ecx = edx = 0;  // @18_45ace0
  eax = esi;  // @19_45ace0
  SEH_LEAVE();  // @20_45ace0
  return eax;  // @21_45ace0
  L45ad73:;
  eax = 0;  // @23_45ace0
  SEH_LEAVE();  // @24_45ace0
  return eax;  // @25_45ace0
}
PCREG(45ace0, lifted_45ace0);

extern "C" u32 THISCALL lifted_5ebbd0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5ebbd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5ebbd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @1_5ebbd0
  { u32 v = (u32)((u32)(7045364)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5ebbd0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; })) goto L5ebc19;  // @3_5ebbd0
  L5ebc05:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(44));  // @5_5ebbd0
  ecx = edx = 0;  // @6_5ebbd0
  esi = (esi + (u32)(4));  // @7_5ebbd0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; })) goto L5ebc05;  // @8_5ebbd0
  L5ebc19:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @10_5ebbd0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }), (u32)(40));  // @11_5ebbd0
  ecx = edx = 0;  // @12_5ebbd0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; }), (u32)(8));  // @13_5ebbd0
  ecx = edx = 0;  // @14_5ebbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @15_5ebbd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @16_5ebbd0
  eax = (eax - ecx);  // @17_5ebbd0
  eax = (u32)((s32)eax >> (u32)(2));  // @18_5ebbd0
  reg.state = (s32)((u32)(0));  // @19_5ebbd0
  if ((eax & eax) == 0) goto L5ebc56;  // @20_5ebbd0
  eax = (eax << (u32)(2));  // @21_5ebbd0
  ecx = (u32)(edi + 98);  // @22_5ebbd0
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @23_5ebbd0
  ecx = edx = 0;  // @24_5ebbd0
  L5ebc56:;
  { u32 v = (u32)((u32)(7012828)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @26_5ebbd0
  SEH_LEAVE();  // @27_5ebbd0
  return eax;  // @28_5ebbd0
}
PCREG(5ebbd0, lifted_5ebbd0);

extern "C" u32 lifted_4244a0(void) {
  SEH_ENTER(0x6644b6);  // @h_4244a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4244a0
  ecx = esi;  // @1_4244a0
  eax = ext_423e60_thiscall1(ecx);  // @2_4244a0
  ecx = edx = 0;  // @3_4244a0
  ecx = (u32)(EBP - 144);  // @4_4244a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @5_4244a0
  ecx = edx = 0;  // @6_4244a0
  eax = (u32)(EBP - 144);  // @7_4244a0
  reg.state = (s32)((u32)(0));  // @8_4244a0
  ecx = (u32)(esi + 9179);  // @9_4244a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @10_4244a0
  ecx = edx = 0;  // @11_4244a0
  ecx = (u32)(EBP - 144);  // @12_4244a0
  reg.state = (s32)((u32)(4294967295));  // @13_4244a0
  eax = ext_4cbec0_thiscall1(ecx);  // @14_4244a0
  ecx = edx = 0;  // @15_4244a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_4244a0
  ecx = (u32)(EBP - 272);  // @17_4244a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @18_4244a0
  ecx = edx = 0;  // @19_4244a0
  eax = (u32)(EBP - 272);  // @20_4244a0
  reg.state = (s32)((u32)(1));  // @21_4244a0
  ecx = (u32)(esi + 9563);  // @22_4244a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @23_4244a0
  ecx = edx = 0;  // @24_4244a0
  ecx = (u32)(EBP - 272);  // @25_4244a0
  eax = ext_4cbec0_thiscall1(ecx);  // @26_4244a0
  ecx = edx = 0;  // @27_4244a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9692), sizeof v); (u32)v; });  // @28_4244a0
  if ((eax & eax) == 0) goto L42456d;  // @29_4244a0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @30_4244a0
  ecx = edx = 0;  // @31_4244a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 9692), &v, sizeof v); }  // @32_4244a0
  L42456d:;
  SEH_LEAVE();  // @34_4244a0
  ext_633654(G(u32, 0x6f5630));  // @35_4244a0
  return eax;  // @36_4244a0
}
PCREG(4244a0, lifted_4244a0);

extern "C" u32 THISCALL lifted_5f1370(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_5f1370
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5f1370
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; }), (u32)(8));  // @1_5f1370
  ecx = edx = 0;  // @2_5f1370
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @3_5f1370
  if ((edi & edi) == 0) goto L5f13bf;  // @4_5f1370
  ecx = edi;  // @5_5f1370
  eax = ext_5fb000_thiscall1(ecx);  // @6_5f1370
  ecx = edx = 0;  // @7_5f1370
  eax = ext_634273_cdecl2((u32)(edi), (u32)(77));  // @8_5f1370
  ecx = edx = 0;  // @9_5f1370
  L5f13bf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_5f1370
  if ((ecx & ecx) == 0) goto L5f13cb;  // @12_5f1370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_5f1370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @14_5f1370
  ecx = edx = 0;  // @15_5f1370
  L5f13cb:;
  ecx = (u32)(esi + 172);  // @17_5f1370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @18_5f1370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5f1370
  eax = (eax - edx);  // @20_5f1370
  eax = (u32)((s32)eax >> (u32)(2));  // @21_5f1370
  reg.state = (s32)((u32)(0));  // @22_5f1370
  if ((eax & eax) == 0) goto L5f13f0;  // @23_5f1370
  eax = (eax << (u32)(2));  // @24_5f1370
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @25_5f1370
  ecx = edx = 0;  // @26_5f1370
  L5f13f0:;
  ecx = (u32)(esi + 20);  // @28_5f1370
  eax = ext_4cbec0_thiscall1(ecx);  // @29_5f1370
  ecx = edx = 0;  // @30_5f1370
  ecx = (u32)(esi + 8);  // @31_5f1370
  eax = ext_6042f0_thiscall1(ecx);  // @32_5f1370
  ecx = edx = 0;  // @33_5f1370
  SEH_LEAVE();  // @34_5f1370
  return eax;  // @35_5f1370
}
PCREG(5f1370, lifted_5f1370);

extern "C" u32 THISCALL lifted_5379b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a892);  // @h_5379b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_5379b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L537a11;  // @1_5379b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_5379b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5379b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6954540), (u32)(1442));  // @4_5379b0
  ecx = edx = 0;  // @5_5379b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_5379b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6955384));  // @7_5379b0
  ecx = edx = 0;  // @8_5379b0
  SEH_LEAVE();  // @9_5379b0
  return eax;  // @10_5379b0
  L537a11:;
  eax = ext_41e290_cdecl1((u32)(4618));  // @12_5379b0
  ecx = edx = 0;  // @13_5379b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @14_5379b0
  reg.state = (s32)((u32)(0));  // @15_5379b0
  if ((eax & eax) == 0) goto L537a35;  // @16_5379b0
  ecx = eax;  // @17_5379b0
  eax = ext_53b600_thiscall1(ecx);  // @18_5379b0
  ecx = edx = 0;  // @19_5379b0
  goto L537a37;  // @20_5379b0
  L537a35:;
  eax = 0;  // @22_5379b0
  L537a37:;
  ecx = eax;  // @24_5379b0
  reg.state = (s32)((u32)(4294967295));  // @25_5379b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 21246), &v, sizeof v); }  // @26_5379b0
  eax = ext_53c590_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @27_5379b0
  ecx = edx = 0;  // @28_5379b0
  SEH_LEAVE();  // @29_5379b0
  return eax;  // @30_5379b0
}
PCREG(5379b0, lifted_5379b0);

extern "C" u32 THISCALL lifted_6012e0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_6012e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_6012e0
  { u32 v = (u32)((u32)(7046360)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_6012e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L601358;  // @2_6012e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @3_6012e0
  L601317:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @5_6012e0
  if ((ecx & ecx) == 0) goto L60132a;  // @6_6012e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @7_6012e0
  ecx = (ecx - 1);  // @8_6012e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @9_6012e0
  ebx = (u32)(eax + ecx*4);  // @10_6012e0
  goto L60133a;  // @11_6012e0
  L60132a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_6012e0
  if ((eax & eax) == 0) goto L601337;  // @14_6012e0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @15_6012e0
  ecx = edx = 0;  // @16_6012e0
  goto L60133a;  // @17_6012e0
  L601337:;
  __builtin_trap();  // @19_6012e0
  L60133a:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @21_6012e0
  if ((edi & edi) == 0) goto L601352;  // @22_6012e0
  ecx = edi;  // @23_6012e0
  eax = ext_601380_thiscall1(ecx);  // @24_6012e0
  ecx = edx = 0;  // @25_6012e0
  eax = ext_634273_cdecl2((u32)(edi), (u32)(4));  // @26_6012e0
  ecx = edx = 0;  // @27_6012e0
  L601352:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L601317;  // @29_6012e0
  L601358:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @31_6012e0
  ecx = edx = 0;  // @32_6012e0
  { u32 v = (u32)((u32)(7046312)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @33_6012e0
  SEH_LEAVE();  // @34_6012e0
  return eax;  // @35_6012e0
}
PCREG(6012e0, lifted_6012e0);

extern "C" u32 THISCALL lifted_45a5a0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_45a5a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @1_45a5a0
  { u32 v = (u32)((u32)(6831020)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_45a5a0
  if ((ecx & ecx) == 0) goto L45a61e;  // @3_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45a5a0
  edx = (u32)(EBP - 24);  // @5_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @6_45a5a0
  ecx = edx = 0;  // @7_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @8_45a5a0
  edx = (u32)(EBP - 24);  // @9_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @11_45a5a0
  ecx = edx = 0;  // @12_45a5a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L45a611;  // @13_45a5a0
  L45a5f0:;
  if ((eax & eax) == 0) goto L45a5ff;  // @15_45a5a0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @16_45a5a0
  ecx = edx = 0;  // @17_45a5a0
  L45a5ff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @19_45a5a0
  edx = (u32)(EBP - 24);  // @20_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @22_45a5a0
  ecx = edx = 0;  // @23_45a5a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L45a5f0;  // @24_45a5a0
  L45a611:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @26_45a5a0
  if ((ecx & ecx) == 0) goto L45a61e;  // @27_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @29_45a5a0
  ecx = edx = 0;  // @30_45a5a0
  L45a61e:;
  ecx = esi;  // @32_45a5a0
  eax = ext_43de70_thiscall1(ecx);  // @33_45a5a0
  ecx = edx = 0;  // @34_45a5a0
  SEH_LEAVE();  // @35_45a5a0
  return eax;  // @36_45a5a0
}
PCREG(45a5a0, lifted_45a5a0);

extern "C" u32 THISCALL lifted_435920(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66588e);  // @h_435920
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_435920
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L43597d;  // @1_435920
  eax = ext_41e290_cdecl1((u32)(40));  // @2_435920
  ecx = edx = 0;  // @3_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_435920
  reg.state = (s32)((u32)(0));  // @5_435920
  if ((eax & eax) == 0) goto L435971;  // @6_435920
  ecx = eax;  // @7_435920
  eax = ext_4cca60_thiscall3(ecx, (u32)(4), (u32)(1));  // @8_435920
  ecx = edx = 0;  // @9_435920
  goto L435973;  // @10_435920
  L435971:;
  eax = 0;  // @12_435920
  L435973:;
  reg.state = (s32)((u32)(4294967295));  // @14_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @15_435920
  L43597d:;
  eax = ext_41e290_cdecl1((u32)(21));  // @17_435920
  ecx = edx = 0;  // @18_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_435920
  reg.state = (s32)((u32)(1));  // @20_435920
  if ((eax & eax) == 0) goto L4359a6;  // @21_435920
  ecx = eax;  // @22_435920
  eax = ext_4d4c90_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @23_435920
  ecx = edx = 0;  // @24_435920
  edx = eax;  // @25_435920
  goto L4359a8;  // @26_435920
  L4359a6:;
  edx = 0;  // @28_435920
  L4359a8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @30_435920
  reg.state = (s32)((u32)(4294967295));  // @31_435920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_435920
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(edx));  // @33_435920
  ecx = edx = 0;  // @34_435920
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @35_435920
  SEH_LEAVE();  // @36_435920
  return eax;  // @37_435920
}
PCREG(435920, lifted_435920);

extern "C" u32 THISCALL lifted_5898c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_5898c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_5898c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5898c0
  if (eax != (u32)(12)) goto L58994d;  // @2_5898c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @3_5898c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5898c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6995856), (u32)(392));  // @5_5898c0
  ecx = edx = 0;  // @6_5898c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_5898c0
  edi = eax;  // @8_5898c0
  eax = (u32)(EBP - 144);  // @9_5898c0
  ecx = esi;  // @10_5898c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @11_5898c0
  ecx = edx = 0;  // @12_5898c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_5898c0
  ecx = eax;  // @14_5898c0
  reg.state = (s32)((u32)(0));  // @15_5898c0
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_5898c0
  ecx = edx = 0;  // @17_5898c0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6995992), (u32)(eax));  // @18_5898c0
  ecx = edx = 0;  // @19_5898c0
  ecx = (u32)(EBP - 144);  // @20_5898c0
  eax = ext_4cbec0_thiscall1(ecx);  // @21_5898c0
  ecx = edx = 0;  // @22_5898c0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @23_5898c0
  goto L589955;  // @24_5898c0
  L58994d:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 4), &v, sizeof v); }  // @26_5898c0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @27_5898c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @28_5898c0
  L589955:;
  SEH_LEAVE();  // @30_5898c0
  ext_633654(G(u32, 0x6f5630));  // @31_5898c0
  return eax;  // @32_5898c0
}
PCREG(5898c0, lifted_5898c0);

extern "C" u32 THISCALL lifted_5faf50(u32 ecx_in) {
  SEH_ENTER(0x66d3c8);  // @h_5faf50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5faf50
  ecx = (u32)(esi + 35);  // @1_5faf50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @2_5faf50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5faf50
  eax = (eax - edx);  // @4_5faf50
  eax = (u32)((s32)eax >> (u32)(1));  // @5_5faf50
  reg.state = (s32)((u32)(0));  // @6_5faf50
  if (eax == 0) goto L5faf93;  // @7_5faf50
  eax = (eax + eax);  // @8_5faf50
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @9_5faf50
  ecx = edx = 0;  // @10_5faf50
  L5faf93:;
  ecx = (u32)(esi + 23);  // @12_5faf50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @13_5faf50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5faf50
  eax = (eax - edx);  // @15_5faf50
  eax = (u32)((s32)eax >> (u32)(2));  // @16_5faf50
  reg.state = (s32)((u32)(1));  // @17_5faf50
  if ((eax & eax) == 0) goto L5fafb5;  // @18_5faf50
  eax = (eax << (u32)(2));  // @19_5faf50
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @20_5faf50
  ecx = edx = 0;  // @21_5faf50
  L5fafb5:;
  ecx = (u32)(esi + 4);  // @23_5faf50
  reg.state = (s32)((u32)(2));  // @24_5faf50
  eax = ext_5fb600_thiscall1(ecx);  // @25_5faf50
  ecx = edx = 0;  // @26_5faf50
  ecx = (u32)(esi + 7);  // @27_5faf50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @28_5faf50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_5faf50
  eax = (eax - edx);  // @30_5faf50
  eax = (u32)((s32)eax >> (u32)(2));  // @31_5faf50
  reg.state = (s32)((u32)(3));  // @32_5faf50
  if ((eax & eax) == 0) goto L5fafe3;  // @33_5faf50
  eax = (eax << (u32)(2));  // @34_5faf50
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @35_5faf50
  ecx = edx = 0;  // @36_5faf50
  L5fafe3:;
  SEH_LEAVE();  // @38_5faf50
  return eax;  // @39_5faf50
}
PCREG(5faf50, lifted_5faf50);

extern "C" u32 THISCALL lifted_5c4600(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_5c4600
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5c4600
  { u32 v = (u32)((u32)(7028872)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_5c4600
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }));  // @2_5c4600
  ecx = edx = 0;  // @3_5c4600
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @4_5c4600
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @5_5c4600
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5c4600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_5c4600
  reg.state = (s32)((u32)(0));  // @8_5c4600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_5c4600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5c4600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @11_5c4600
  ecx = edx = 0;  // @12_5c4600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @13_5c4600
  reg.state = (s32)((u32)(4294967295));  // @14_5c4600
  if (((eax & 0xff) & (u32)(1)) == 0) goto L5c46ba;  // @15_5c4600
  if (((eax & 0xff) & (u32)(4)) != 0) goto L5c46af;  // @16_5c4600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @17_5c4600
  reg.state = (s32)((u32)(1));  // @18_5c4600
  if ((eax & eax) == 0) goto L5c469a;  // @19_5c4600
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_5c4600
  ecx = edx = 0;  // @21_5c4600
  eax = esi;  // @22_5c4600
  SEH_LEAVE();  // @23_5c4600
  return eax;  // @24_5c4600
  L5c469a:;
  __builtin_trap();  // @26_5c4600
  L5c46af:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(124));  // @28_5c4600
  ecx = edx = 0;  // @29_5c4600
  L5c46ba:;
  eax = esi;  // @31_5c4600
  SEH_LEAVE();  // @32_5c4600
  return eax;  // @33_5c4600
}
PCREG(5c4600, lifted_5c4600);

extern "C" u32 FASTCALL lifted_6054b0(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x66dde7);  // @h_6054b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  edi = edx;  // @0_6054b0
  ebx = ecx;  // @1_6054b0
  eax = ext_41e290_cdecl1((u32)(18));  // @2_6054b0
  ecx = edx = 0;  // @3_6054b0
  esi = eax;  // @4_6054b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_6054b0
  reg.state = (s32)((u32)(0));  // @6_6054b0
  if ((esi & esi) == 0) goto L605534;  // @7_6054b0
  ecx = esi;  // @8_6054b0
  eax = ext_5f9700_thiscall3(ecx, (u32)(ebx), (u32)(edi));  // @9_6054b0
  ecx = edx = 0;  // @10_6054b0
  reg.state = (s32)((u32)(1));  // @11_6054b0
  { u32 v = (u32)((u32)(7052156)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_6054b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489384), sizeof v); (u32)v; }) != (u32)(0)) goto L605517;  // @13_6054b0
  ecx = esi;  // @14_6054b0
  eax = ext_604ca0_thiscall1(ecx);  // @15_6054b0
  ecx = edx = 0;  // @16_6054b0
  L605517:;
  ecx = esi;  // @18_6054b0
  eax = ext_6052f0_thiscall3(ecx, (u32)(ebx), (u32)(edi));  // @19_6054b0
  ecx = edx = 0;  // @20_6054b0
  eax = esi;  // @21_6054b0
  SEH_LEAVE();  // @22_6054b0
  return eax;  // @23_6054b0
  L605534:;
  eax = 0;  // @25_6054b0
  SEH_LEAVE();  // @26_6054b0
  return eax;  // @27_6054b0
}
PCREG(6054b0, lifted_6054b0);

extern "C" u32 THISCALL lifted_615390(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66e55a);  // @h_615390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edi = ecx;  // @0_615390
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_615390
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_615390
  eax = ext_65c7f0_thiscall5(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @3_615390
  ecx = edx = 0;  // @4_615390
  ebx = (u32)(edi + 98985);  // @5_615390
  reg.state = (s32)((u32)(0));  // @6_615390
  { u32 v = (u32)((u32)(7068356)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_615390
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @8_615390
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 98981), &v, sizeof v); }  // @9_615390
  eax = ext_41e290_cdecl1((u32)(264));  // @10_615390
  ecx = edx = 0;  // @11_615390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @12_615390
  reg.state = (s32)((u32)(1));  // @13_615390
  if ((eax & eax) == 0) goto L615417;  // @14_615390
  ecx = eax;  // @15_615390
  eax = ext_4d83b0_thiscall4(ecx, (u32)(7068548), (u32)(7068496), (u32)(ebx));  // @16_615390
  ecx = edx = 0;  // @17_615390
  edx = eax;  // @18_615390
  goto L615419;  // @19_615390
  L615417:;
  edx = 0;  // @21_615390
  L615419:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 98986), &v, sizeof v); }  // @23_615390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_615390
  reg.state = (s32)((u32)(0));  // @25_615390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_615390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @27_615390
  ecx = edx = 0;  // @28_615390
  eax = edi;  // @29_615390
  SEH_LEAVE();  // @30_615390
  return eax;  // @31_615390
}
PCREG(615390, lifted_615390);

extern "C" u32 THISCALL lifted_42d600(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664e7e);  // @h_42d600
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_42d600
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_42d600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @2_42d600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_42d600
  if (edx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d63e;  // @4_42d600
  eax = (u32)(edx + 12);  // @5_42d600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_42d600
  L42d63e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @8_42d600
  eax = ext_42be20_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @9_42d600
  ecx = edx = 0;  // @10_42d600
  ecx = (u32)(EBP - 24);  // @11_42d600
  eax = ext_5f10c0_thiscall2(ecx, (u32)(eax));  // @12_42d600
  ecx = edx = 0;  // @13_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_42d600
  reg.state = (s32)((u32)(0));  // @15_42d600
  eax = ext_5f2c60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @16_42d600
  ecx = edx = 0;  // @17_42d600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @18_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_42d600
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d67b;  // @20_42d600
  eax = (u32)(ecx + 12);  // @21_42d600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @22_42d600
  L42d67b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @24_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @25_42d600
  eax = (eax - ecx);  // @26_42d600
  reg.state = (s32)((u32)(1));  // @27_42d600
  if ((ecx & ecx) == 0) goto L42d69c;  // @28_42d600
  if ((eax & eax) == 0) goto L42d69c;  // @29_42d600
  ecx = (u32)(EBP - 24);  // @30_42d600
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @31_42d600
  ecx = edx = 0;  // @32_42d600
  L42d69c:;
  SEH_LEAVE();  // @34_42d600
  return eax;  // @35_42d600
}
PCREG(42d600, lifted_42d600);

extern "C" u32 THISCALL lifted_4554c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_4554c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4554c0
  { u32 v = (u32)((u32)(6826716)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4554c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_4554c0
  reg.state = (s32)((u32)(0));  // @3_4554c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4554c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }));  // @5_4554c0
  ecx = edx = 0;  // @6_4554c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @7_4554c0
  if ((ecx & ecx) == 0) goto L455510;  // @8_4554c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4554c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @10_4554c0
  ecx = edx = 0;  // @11_4554c0
  L455510:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2077), sizeof v); (u32)v; }), (u32)(152580));  // @13_4554c0
  ecx = edx = 0;  // @14_4554c0
  ecx = esi;  // @15_4554c0
  eax = ext_43de70_thiscall1(ecx);  // @16_4554c0
  ecx = edx = 0;  // @17_4554c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_4554c0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L455560;  // @19_4554c0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L455552;  // @20_4554c0
  eax = ext_45c510_cdecl1((u32)(esi));  // @21_4554c0
  ecx = edx = 0;  // @22_4554c0
  eax = esi;  // @23_4554c0
  SEH_LEAVE();  // @24_4554c0
  return eax;  // @25_4554c0
  L455552:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(2087));  // @27_4554c0
  ecx = edx = 0;  // @28_4554c0
  L455560:;
  eax = esi;  // @30_4554c0
  SEH_LEAVE();  // @31_4554c0
  return eax;  // @32_4554c0
}
PCREG(4554c0, lifted_4554c0);

extern "C" u32 THISCALL lifted_465660(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_465660
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_465660
  { u32 v = (u32)((u32)(6838980)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @4_465660
  if ((ecx & ecx) == 0) goto L4656df;  // @5_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_465660
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @7_465660
  ecx = edx = 0;  // @8_465660
  ebx = eax;  // @9_465660
  if ((ebx & ebx) == 0) goto L4656df;  // @10_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @12_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(edi));  // @14_465660
  ecx = edx = 0;  // @15_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_465660
  esi = eax;  // @17_465660
  ecx = ebx;  // @18_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 556)))(ecx, (u32)(esi));  // @19_465660
  ecx = edx = 0;  // @20_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @21_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(esi));  // @23_465660
  ecx = edx = 0;  // @24_465660
  L4656df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 462), sizeof v); (u32)v; });  // @26_465660
  if ((ecx & ecx) == 0) goto L4656ef;  // @27_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @29_465660
  ecx = edx = 0;  // @30_465660
  L4656ef:;
  ecx = edi;  // @32_465660
  eax = ext_460f90_thiscall1(ecx);  // @33_465660
  ecx = edx = 0;  // @34_465660
  SEH_LEAVE();  // @35_465660
  return eax;  // @36_465660
}
PCREG(465660, lifted_465660);

extern "C" u32 THISCALL lifted_47f760(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_47f760
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_47f760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @1_47f760
  reg.state = (s32)((u32)(0));  // @2_47f760
  { u32 v = (u32)((u32)(6860620)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_47f760
  if ((edx & edx) == 0) goto L47f7ba;  // @4_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_47f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_47f760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @8_47f760
  ecx = edx = 0;  // @9_47f760
  if ((eax & eax) == 0) goto L47f7ba;  // @10_47f760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @11_47f760
  ecx = eax;  // @12_47f760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @13_47f760
  ecx = edx = 0;  // @14_47f760
  L47f7ba:;
  ecx = esi;  // @16_47f760
  eax = ext_43de70_thiscall1(ecx);  // @17_47f760
  ecx = edx = 0;  // @18_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_47f760
  if (((eax & 0xff) & (u32)(1)) == 0) goto L47f7f4;  // @20_47f760
  if (((eax & 0xff) & (u32)(4)) != 0) goto L47f7e9;  // @21_47f760
  eax = ext_45c510_cdecl1((u32)(esi));  // @22_47f760
  ecx = edx = 0;  // @23_47f760
  eax = esi;  // @24_47f760
  SEH_LEAVE();  // @25_47f760
  return eax;  // @26_47f760
  L47f7e9:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(28));  // @28_47f760
  ecx = edx = 0;  // @29_47f760
  L47f7f4:;
  eax = esi;  // @31_47f760
  SEH_LEAVE();  // @32_47f760
  return eax;  // @33_47f760
}
PCREG(47f760, lifted_47f760);

extern "C" u32 FASTCALL lifted_4808d0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x667359);  // @h_4808d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_4808d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4808d0
  eax = ext_45c4f0_cdecl2((u32)(1611), (u32)(ecx));  // @2_4808d0
  ecx = edx = 0;  // @3_4808d0
  esi = eax;  // @4_4808d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_4808d0
  reg.state = (s32)((u32)(0));  // @6_4808d0
  if ((esi & esi) == 0) goto L480967;  // @7_4808d0
  ecx = esi;  // @8_4808d0
  eax = ext_480a40_thiscall4(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @9_4808d0
  ecx = edx = 0;  // @10_4808d0
  { u32 v = (u32)((u32)(6865084)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_4808d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_4808d0
  reg.state = (s32)((u32)(1));  // @13_4808d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @14_4808d0
  if ((ecx & ecx) == 0) goto L480952;  // @15_4808d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4808d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 12)))(ecx, (u32)(7233608), (u32)(6866696), (u32)(0));  // @17_4808d0
  ecx = edx = 0;  // @18_4808d0
  L480952:;
  eax = esi;  // @20_4808d0
  SEH_LEAVE();  // @21_4808d0
  return eax;  // @22_4808d0
  L480967:;
  eax = 0;  // @24_4808d0
  SEH_LEAVE();  // @25_4808d0
  return eax;  // @26_4808d0
}
PCREG(4808d0, lifted_4808d0);

extern "C" u32 THISCALL lifted_5cac20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_5cac20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5cac20
  { u32 v = (u32)((u32)(7031784)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_5cac20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_5cac20
  reg.state = (s32)((u32)(0));  // @3_5cac20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5cac20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1448), sizeof v); (u32)v; }));  // @5_5cac20
  ecx = edx = 0;  // @6_5cac20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1448), sizeof v); (u32)v; });  // @7_5cac20
  if ((ecx & ecx) == 0) goto L5cac76;  // @8_5cac20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_5cac20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @10_5cac20
  ecx = edx = 0;  // @11_5cac20
  L5cac76:;
  ecx = esi;  // @13_5cac20
  eax = ext_4f6b20_thiscall1(ecx);  // @14_5cac20
  ecx = edx = 0;  // @15_5cac20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_5cac20
  reg.state = (s32)((u32)(4294967295));  // @17_5cac20
  if (((eax & 0xff) & (u32)(1)) == 0) goto L5cacd8;  // @18_5cac20
  if (((eax & 0xff) & (u32)(4)) != 0) goto L5cacca;  // @19_5cac20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5cac20
  reg.state = (s32)((u32)(1));  // @21_5cac20
  if ((eax & eax) == 0) goto L5cacb5;  // @22_5cac20
  eax = ((u32(STDCALL *)(void))(eax))();  // @23_5cac20
  ecx = edx = 0;  // @24_5cac20
  eax = esi;  // @25_5cac20
  SEH_LEAVE();  // @26_5cac20
  return eax;  // @27_5cac20
  L5cacb5:;
  __builtin_trap();  // @29_5cac20
  L5cacca:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(1978));  // @31_5cac20
  ecx = edx = 0;  // @32_5cac20
  L5cacd8:;
  eax = esi;  // @34_5cac20
  SEH_LEAVE();  // @35_5cac20
  return eax;  // @36_5cac20
}
PCREG(5cac20, lifted_5cac20);

extern "C" u32 THISCALL lifted_4a33e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_4a33e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4a33e0
  { u32 v = (u32)((u32)(6879964)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4a33e0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }), (u32)(10));  // @2_4a33e0
  ecx = edx = 0;  // @3_4a33e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @4_4a33e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @5_4a33e0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4a33e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_4a33e0
  reg.state = (s32)((u32)(0));  // @8_4a33e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_4a33e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4a33e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @11_4a33e0
  ecx = edx = 0;  // @12_4a33e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @13_4a33e0
  reg.state = (s32)((u32)(4294967295));  // @14_4a33e0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4a349f;  // @15_4a33e0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L4a3491;  // @16_4a33e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @17_4a33e0
  reg.state = (s32)((u32)(1));  // @18_4a33e0
  if ((eax & eax) == 0) goto L4a347c;  // @19_4a33e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_4a33e0
  ecx = edx = 0;  // @21_4a33e0
  eax = esi;  // @22_4a33e0
  SEH_LEAVE();  // @23_4a33e0
  return eax;  // @24_4a33e0
  L4a347c:;
  __builtin_trap();  // @26_4a33e0
  L4a3491:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(344));  // @28_4a33e0
  ecx = edx = 0;  // @29_4a33e0
  L4a349f:;
  eax = esi;  // @31_4a33e0
  SEH_LEAVE();  // @32_4a33e0
  return eax;  // @33_4a33e0
}
PCREG(4a33e0, lifted_4a33e0);

extern "C" u32 STDCALL lifted_4266a0(u32 a0, u32 a1) {
  SEH_ENTER(0x664638);  // @h_4266a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4266a0
  ecx = edi;  // @1_4266a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4266a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3_4266a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4266a0
  eax = (eax + (u32)(291));  // @5_4266a0
  reg.state = (s32)((u32)(0));  // @6_4266a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @7_4266a0
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @8_4266a0
  ecx = edx = 0;  // @9_4266a0
  ecx = (u32)(EBP - 144);  // @10_4266a0
  reg.state = (s32)((u32)(0));  // @11_4266a0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @12_4266a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @13_4266a0
  ecx = edx = 0;  // @14_4266a0
  eax = (u32)(EBP - 144);  // @15_4266a0
  reg.state = (s32)((u32)(1));  // @16_4266a0
  ecx = edi;  // @17_4266a0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @18_4266a0
  ecx = edx = 0;  // @19_4266a0
  ecx = (u32)(EBP - 144);  // @20_4266a0
  reg.state = (s32)((u32)(0));  // @21_4266a0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_4266a0
  ecx = edx = 0;  // @23_4266a0
  ecx = (u32)(EBP - 144);  // @24_4266a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(esi));  // @25_4266a0
  ecx = edx = 0;  // @26_4266a0
  eax = (u32)(EBP - 144);  // @27_4266a0
  reg.state = (s32)((u32)(2));  // @28_4266a0
  ecx = edi;  // @29_4266a0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @30_4266a0
  ecx = edx = 0;  // @31_4266a0
  ecx = (u32)(EBP - 144);  // @32_4266a0
  eax = ext_4cbec0_thiscall1(ecx);  // @33_4266a0
  ecx = edx = 0;  // @34_4266a0
  eax = edi;  // @35_4266a0
  SEH_LEAVE();  // @36_4266a0
  ext_633654(G(u32, 0x6f5630));  // @37_4266a0
  return eax;  // @38_4266a0
}
PCREG(4266a0, lifted_4266a0);

extern "C" u32 THISCALL lifted_5b2a00(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_5b2a00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5b2a00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 596), sizeof v); (u32)v; });  // @1_5b2a00
  { u32 v = (u32)((u32)(7020252)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5b2a00
  if ((edi & edi) == 0) goto L5b2a48;  // @3_5b2a00
  ecx = edi;  // @4_5b2a00
  eax = ext_5f0370_thiscall1(ecx);  // @5_5b2a00
  ecx = edx = 0;  // @6_5b2a00
  eax = ext_634273_cdecl2((u32)(edi), (u32)(16));  // @7_5b2a00
  ecx = edx = 0;  // @8_5b2a00
  L5b2a48:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 600), sizeof v); (u32)v; });  // @10_5b2a00
  if ((edi & edi) == 0) goto L5b2a64;  // @11_5b2a00
  ecx = edi;  // @12_5b2a00
  eax = ext_5f0490_thiscall1(ecx);  // @13_5b2a00
  ecx = edx = 0;  // @14_5b2a00
  eax = ext_634273_cdecl2((u32)(edi), (u32)(20));  // @15_5b2a00
  ecx = edx = 0;  // @16_5b2a00
  L5b2a64:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_5b2a00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5b2a00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }));  // @20_5b2a00
  ecx = edx = 0;  // @21_5b2a00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @22_5b2a00
  if ((ecx & ecx) == 0) goto L5b2a82;  // @23_5b2a00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_5b2a00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @25_5b2a00
  ecx = edx = 0;  // @26_5b2a00
  L5b2a82:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @28_5b2a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @29_5b2a00
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @30_5b2a00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_5b2a00
  reg.state = (s32)((u32)(0));  // @32_5b2a00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_5b2a00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_5b2a00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @35_5b2a00
  ecx = edx = 0;  // @36_5b2a00
  SEH_LEAVE();  // @37_5b2a00
  return eax;  // @38_5b2a00
}
PCREG(5b2a00, lifted_5b2a00);

extern "C" u32 THISCALL lifted_49e2e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_49e2e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_49e2e0
  ecx = (u32)(esi + 454);  // @1_49e2e0
  eax = ext_4ccf60_thiscall1(ecx);  // @2_49e2e0
  ecx = edx = 0;  // @3_49e2e0
  ecx = (u32)(esi + 282);  // @4_49e2e0
  eax = ext_4ccf60_thiscall1(ecx);  // @5_49e2e0
  ecx = edx = 0;  // @6_49e2e0
  ecx = (u32)(esi + 110);  // @7_49e2e0
  eax = ext_4ccf60_thiscall1(ecx);  // @8_49e2e0
  ecx = edx = 0;  // @9_49e2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @10_49e2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @11_49e2e0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_49e2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_49e2e0
  reg.state = (s32)((u32)(0));  // @14_49e2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_49e2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_49e2e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @17_49e2e0
  ecx = edx = 0;  // @18_49e2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_49e2e0
  reg.state = (s32)((u32)(4294967295));  // @20_49e2e0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L49e3aa;  // @21_49e2e0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L49e39c;  // @22_49e2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @23_49e2e0
  reg.state = (s32)((u32)(1));  // @24_49e2e0
  if ((eax & eax) == 0) goto L49e387;  // @25_49e2e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @26_49e2e0
  ecx = edx = 0;  // @27_49e2e0
  eax = esi;  // @28_49e2e0
  SEH_LEAVE();  // @29_49e2e0
  return eax;  // @30_49e2e0
  L49e387:;
  __builtin_trap();  // @32_49e2e0
  L49e39c:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(626));  // @34_49e2e0
  ecx = edx = 0;  // @35_49e2e0
  L49e3aa:;
  eax = esi;  // @37_49e2e0
  SEH_LEAVE();  // @38_49e2e0
  return eax;  // @39_49e2e0
}
PCREG(49e2e0, lifted_49e2e0);

extern "C" u32 THISCALL lifted_578710(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_578710
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_578710
  { u32 v = (u32)((u32)(6986028)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_578710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_578710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 412), sizeof v); (u32)v; }));  // @4_578710
  ecx = edx = 0;  // @5_578710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 412), sizeof v); (u32)v; });  // @6_578710
  if ((ecx & ecx) == 0) goto L57875f;  // @7_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_578710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @9_578710
  ecx = edx = 0;  // @10_578710
  L57875f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_578710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 416), sizeof v); (u32)v; }));  // @14_578710
  ecx = edx = 0;  // @15_578710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 416), sizeof v); (u32)v; });  // @16_578710
  if ((ecx & ecx) == 0) goto L578783;  // @17_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_578710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @19_578710
  ecx = edx = 0;  // @20_578710
  L578783:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_578710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 420), sizeof v); (u32)v; }));  // @24_578710
  ecx = edx = 0;  // @25_578710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 420), sizeof v); (u32)v; });  // @26_578710
  if ((ecx & ecx) == 0) goto L5787a7;  // @27_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_578710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @29_578710
  ecx = edx = 0;  // @30_578710
  L5787a7:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @32_578710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @33_578710
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @34_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_578710
  reg.state = (s32)((u32)(0));  // @36_578710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @37_578710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_578710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @39_578710
  ecx = edx = 0;  // @40_578710
  SEH_LEAVE();  // @41_578710
  return eax;  // @42_578710
}
PCREG(578710, lifted_578710);

extern "C" u32 THISCALL lifted_57c9e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_57c9e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_57c9e0
  ecx = (u32)(esi + 612);  // @1_57c9e0
  eax = ext_4ccf60_thiscall1(ecx);  // @2_57c9e0
  ecx = edx = 0;  // @3_57c9e0
  ecx = (u32)(esi + 572);  // @4_57c9e0
  eax = ext_4cce40_thiscall1(ecx);  // @5_57c9e0
  ecx = edx = 0;  // @6_57c9e0
  ecx = (u32)(esi + 400);  // @7_57c9e0
  eax = ext_4ccf60_thiscall1(ecx);  // @8_57c9e0
  ecx = edx = 0;  // @9_57c9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @10_57c9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @11_57c9e0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_57c9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_57c9e0
  reg.state = (s32)((u32)(0));  // @14_57c9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_57c9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_57c9e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @17_57c9e0
  ecx = edx = 0;  // @18_57c9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_57c9e0
  reg.state = (s32)((u32)(4294967295));  // @20_57c9e0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L57caad;  // @21_57c9e0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L57ca9f;  // @22_57c9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @23_57c9e0
  reg.state = (s32)((u32)(1));  // @24_57c9e0
  if ((eax & eax) == 0) goto L57ca8a;  // @25_57c9e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @26_57c9e0
  ecx = edx = 0;  // @27_57c9e0
  eax = esi;  // @28_57c9e0
  SEH_LEAVE();  // @29_57c9e0
  return eax;  // @30_57c9e0
  L57ca8a:;
  __builtin_trap();  // @32_57c9e0
  L57ca9f:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(855));  // @34_57c9e0
  ecx = edx = 0;  // @35_57c9e0
  L57caad:;
  eax = esi;  // @37_57c9e0
  SEH_LEAVE();  // @38_57c9e0
  return eax;  // @39_57c9e0
}
PCREG(57c9e0, lifted_57c9e0);

extern "C" u32 lifted_4216f0(void) {
  SEH_ENTER(0x664311);  // @h_4216f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
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

extern "C" u32 FASTCALL lifted_452a20(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66609b);  // @h_452a20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_452a20
  ebx = ecx;  // @1_452a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_452a20
  if ((ecx & ecx) == 0) goto L452a6e;  // @3_452a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_452a20
  eax = ext_4528f0_fastcall4(ecx, edx, (u32)(ebx), (u32)(edi));  // @5_452a20
  ecx = edx = 0;  // @6_452a20
  SEH_LEAVE();  // @7_452a20
  return eax;  // @8_452a20
  L452a6e:;
  eax = ext_45c4b0_cdecl1((u32)(36));  // @10_452a20
  ecx = edx = 0;  // @11_452a20
  esi = eax;  // @12_452a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @13_452a20
  reg.state = (s32)((u32)(0));  // @14_452a20
  if ((esi & esi) == 0) goto L452aa9;  // @15_452a20
  ecx = esi;  // @16_452a20
  eax = ext_447640_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(ebx), (u32)(edi));  // @17_452a20
  ecx = edx = 0;  // @18_452a20
  { u32 v = (u32)((u32)(6821984)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_452a20
  { u32 v = (u32)((u32)(12288)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @20_452a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @21_452a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @22_452a20
  goto L452aab;  // @23_452a20
  L452aa9:;
  esi = 0;  // @25_452a20
  L452aab:;
  eax = esi;  // @27_452a20
  SEH_LEAVE();  // @28_452a20
  return eax;  // @29_452a20
}
PCREG(452a20, lifted_452a20);

extern "C" u32 THISCALL lifted_46e800(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_46e800
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_46e800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_46e800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_46e800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_46e800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @4_46e800
  ecx = edx = 0;  // @5_46e800
  ebx = eax;  // @6_46e800
  if ((ebx & ebx) != 0) goto L46e899;  // @7_46e800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @8_46e800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_46e800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6850500), (u32)(1247));  // @10_46e800
  ecx = edx = 0;  // @11_46e800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_46e800
  edi = eax;  // @13_46e800
  eax = (u32)(EBP - 144);  // @14_46e800
  ecx = esi;  // @15_46e800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @16_46e800
  ecx = edx = 0;  // @17_46e800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_46e800
  ecx = eax;  // @19_46e800
  reg.state = (s32)(ebx);  // @20_46e800
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_46e800
  ecx = edx = 0;  // @22_46e800
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6851060), (u32)(eax));  // @23_46e800
  ecx = edx = 0;  // @24_46e800
  ecx = (u32)(EBP - 144);  // @25_46e800
  eax = ext_4cbec0_thiscall1(ecx);  // @26_46e800
  ecx = edx = 0;  // @27_46e800
  eax = ebx;  // @28_46e800
  L46e899:;
  SEH_LEAVE();  // @30_46e800
  ext_633654(G(u32, 0x6f5630));  // @31_46e800
  return eax;  // @32_46e800
}
PCREG(46e800, lifted_46e800);

extern "C" u32 THISCALL lifted_4cb410(u32 ecx_in) {
  SEH_ENTER(0x6691af);  // @h_4cb410
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4cb410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4cb410
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4cb410
  ecx = edx = 0;  // @5_4cb410
  ecx = (u32)(EBP - 16);  // @6_4cb410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_4cb410
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_4cb410
  ecx = eax;  // @9_4cb410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6903412), (u32)(ecx));  // @10_4cb410
  ecx = edx = 0;  // @11_4cb410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @12_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4cb410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @14_4cb410
  ecx = edx = 0;  // @15_4cb410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @16_4cb410
  edi = eax;  // @17_4cb410
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) != (u32)(0)) goto L4cb4b3;  // @18_4cb410
  eax = ext_41e290_cdecl1((u32)(28));  // @19_4cb410
  ecx = edx = 0;  // @20_4cb410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @21_4cb410
  reg.state = (s32)((u32)(0));  // @22_4cb410
  if ((eax & eax) == 0) goto L4cb4a7;  // @23_4cb410
  ecx = eax;  // @24_4cb410
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(0));  // @25_4cb410
  ecx = edx = 0;  // @26_4cb410
  goto L4cb4a9;  // @27_4cb410
  L4cb4a7:;
  eax = 0;  // @29_4cb410
  L4cb4a9:;
  reg.state = (s32)((u32)(4294967295));  // @31_4cb410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @32_4cb410
  L4cb4b3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @34_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4cb410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(esi));  // @36_4cb410
  ecx = edx = 0;  // @37_4cb410
  SEH_LEAVE();  // @38_4cb410
  return eax;  // @39_4cb410
}
PCREG(4cb410, lifted_4cb410);

extern "C" u32 THISCALL lifted_5edea0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5edea0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5edea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @1_5edea0
  { u32 v = (u32)((u32)(7045476)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5edea0
  if ((ecx & ecx) == 0) goto L5ededa;  // @3_5edea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5edea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_5edea0
  ecx = edx = 0;  // @6_5edea0
  L5ededa:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; });  // @8_5edea0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; })) goto L5edf04;  // @9_5edea0
  L5edee2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_5edea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_5edea0
  if ((ecx & ecx) == 0) goto L5edef0;  // @13_5edea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5edea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @15_5edea0
  ecx = edx = 0;  // @16_5edea0
  L5edef0:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(8));  // @18_5edea0
  ecx = edx = 0;  // @19_5edea0
  esi = (esi + (u32)(4));  // @20_5edea0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; })) goto L5edee2;  // @21_5edea0
  L5edf04:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 13), sizeof v); (u32)v; });  // @23_5edea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; });  // @24_5edea0
  eax = (eax - ecx);  // @25_5edea0
  eax = (u32)((s32)eax >> (u32)(2));  // @26_5edea0
  reg.state = (s32)((u32)(0));  // @27_5edea0
  if ((eax & eax) == 0) goto L5edf27;  // @28_5edea0
  eax = (eax << (u32)(2));  // @29_5edea0
  ecx = (u32)(edi + 5);  // @30_5edea0
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @31_5edea0
  ecx = edx = 0;  // @32_5edea0
  L5edf27:;
  { u32 v = (u32)((u32)(7012828)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @34_5edea0
  SEH_LEAVE();  // @35_5edea0
  return eax;  // @36_5edea0
}
PCREG(5edea0, lifted_5edea0);

extern "C" u32 FASTCALL lifted_46ad90(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66609b);  // @h_46ad90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_46ad90
  ebx = ecx;  // @1_46ad90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_46ad90
  if ((ecx & ecx) == 0) goto L46adde;  // @3_46ad90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_46ad90
  eax = ext_4697d0_fastcall4(ecx, edx, (u32)(ebx), (u32)(edi));  // @5_46ad90
  ecx = edx = 0;  // @6_46ad90
  SEH_LEAVE();  // @7_46ad90
  return eax;  // @8_46ad90
  L46adde:;
  eax = ext_45c4b0_cdecl1((u32)(148));  // @10_46ad90
  ecx = edx = 0;  // @11_46ad90
  esi = eax;  // @12_46ad90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @13_46ad90
  reg.state = (s32)((u32)(0));  // @14_46ad90
  if ((esi & esi) == 0) goto L46ae22;  // @15_46ad90
  ecx = esi;  // @16_46ad90
  eax = ext_469980_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(ebx), (u32)(edi));  // @17_46ad90
  ecx = edx = 0;  // @18_46ad90
  eax = 0;  // @19_46ad90
  { u32 v = (u32)((u32)(6846024)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @20_46ad90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 142), &v, sizeof v); }  // @21_46ad90
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 146), &v, sizeof v); }  // @22_46ad90
  goto L46ae24;  // @23_46ad90
  L46ae22:;
  esi = 0;  // @25_46ad90
  L46ae24:;
  eax = esi;  // @27_46ad90
  SEH_LEAVE();  // @28_46ad90
  return eax;  // @29_46ad90
}
PCREG(46ad90, lifted_46ad90);

extern "C" u32 THISCALL lifted_4b8730(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_4b8730
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4b8730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @1_4b8730
  { u32 v = (u32)((u32)(6891676)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4b8730
  if ((ecx & ecx) == 0) goto L4b8768;  // @3_4b8730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4b8730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4b8730
  ecx = edx = 0;  // @6_4b8730
  L4b8768:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @8_4b8730
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @9_4b8730
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_4b8730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4b8730
  reg.state = (s32)((u32)(0));  // @12_4b8730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_4b8730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4b8730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @15_4b8730
  ecx = edx = 0;  // @16_4b8730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_4b8730
  reg.state = (s32)((u32)(4294967295));  // @18_4b8730
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4b87ec;  // @19_4b8730
  if (((eax & 0xff) & (u32)(4)) != 0) goto L4b87e1;  // @20_4b8730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @21_4b8730
  reg.state = (s32)((u32)(1));  // @22_4b8730
  if ((eax & eax) == 0) goto L4b87cc;  // @23_4b8730
  eax = ((u32(STDCALL *)(void))(eax))();  // @24_4b8730
  ecx = edx = 0;  // @25_4b8730
  eax = esi;  // @26_4b8730
  SEH_LEAVE();  // @27_4b8730
  return eax;  // @28_4b8730
  L4b87cc:;
  __builtin_trap();  // @30_4b8730
  L4b87e1:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(88));  // @32_4b8730
  ecx = edx = 0;  // @33_4b8730
  L4b87ec:;
  eax = esi;  // @35_4b8730
  SEH_LEAVE();  // @36_4b8730
  return eax;  // @37_4b8730
}
PCREG(4b8730, lifted_4b8730);

extern "C" u32 THISCALL lifted_4c5390(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_4c5390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4c5390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @1_4c5390
  { u32 v = (u32)((u32)(6898192)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4c5390
  if ((ecx & ecx) == 0) goto L4c53c8;  // @3_4c5390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4c5390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4c5390
  ecx = edx = 0;  // @6_4c5390
  L4c53c8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @8_4c5390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @9_4c5390
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_4c5390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4c5390
  reg.state = (s32)((u32)(0));  // @12_4c5390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_4c5390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4c5390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @15_4c5390
  ecx = edx = 0;  // @16_4c5390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_4c5390
  reg.state = (s32)((u32)(4294967295));  // @18_4c5390
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4c544c;  // @19_4c5390
  if (((eax & 0xff) & (u32)(4)) != 0) goto L4c5441;  // @20_4c5390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @21_4c5390
  reg.state = (s32)((u32)(1));  // @22_4c5390
  if ((eax & eax) == 0) goto L4c542c;  // @23_4c5390
  eax = ((u32(STDCALL *)(void))(eax))();  // @24_4c5390
  ecx = edx = 0;  // @25_4c5390
  eax = esi;  // @26_4c5390
  SEH_LEAVE();  // @27_4c5390
  return eax;  // @28_4c5390
  L4c542c:;
  __builtin_trap();  // @30_4c5390
  L4c5441:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(87));  // @32_4c5390
  ecx = edx = 0;  // @33_4c5390
  L4c544c:;
  eax = esi;  // @35_4c5390
  SEH_LEAVE();  // @36_4c5390
  return eax;  // @37_4c5390
}
PCREG(4c5390, lifted_4c5390);

extern "C" u32 THISCALL lifted_4ff920(u32 ecx_in) {
  SEH_ENTER(0x66b6d2);  // @h_4ff920
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ff920
  ecx = (u32)(esi + 56);  // @1_4ff920
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4ff920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @3_4ff920
  eax = (eax - edx);  // @4_4ff920
  reg.state = (s32)((u32)(0));  // @5_4ff920
  if ((edx & edx) == 0) goto L4ff965;  // @6_4ff920
  if ((eax & eax) == 0) goto L4ff965;  // @7_4ff920
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @8_4ff920
  ecx = edx = 0;  // @9_4ff920
  L4ff965:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }));  // @11_4ff920
  ecx = edx = 0;  // @12_4ff920
  ecx = (u32)(esi + 28);  // @13_4ff920
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4ff920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @15_4ff920
  eax = (eax - edx);  // @16_4ff920
  reg.state = (s32)((u32)(1));  // @17_4ff920
  if ((edx & edx) == 0) goto L4ff990;  // @18_4ff920
  if ((eax & eax) == 0) goto L4ff990;  // @19_4ff920
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @20_4ff920
  ecx = edx = 0;  // @21_4ff920
  L4ff990:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @23_4ff920
  ecx = edx = 0;  // @24_4ff920
  ecx = (u32)(esi + 4);  // @25_4ff920
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4ff920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @27_4ff920
  eax = (eax - edx);  // @28_4ff920
  reg.state = (s32)((u32)(2));  // @29_4ff920
  if ((edx & edx) == 0) goto L4ff9bb;  // @30_4ff920
  if ((eax & eax) == 0) goto L4ff9bb;  // @31_4ff920
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @32_4ff920
  ecx = edx = 0;  // @33_4ff920
  L4ff9bb:;
  SEH_LEAVE();  // @35_4ff920
  return eax;  // @36_4ff920
}
PCREG(4ff920, lifted_4ff920);

extern "C" u32 THISCALL lifted_5f2910(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d018);  // @h_5f2910
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5f2910
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5f2910
  ecx = edi;  // @2_5f2910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(18));  // @4_5f2910
  ecx = edx = 0;  // @5_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @6_5f2910
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_5f2910
  ecx = (ecx + (u32)(20));  // @8_5f2910
  eax = ext_4cc1d0_thiscall1(ecx);  // @9_5f2910
  ecx = edx = 0;  // @10_5f2910
  ecx = edi;  // @11_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 92)))(ecx, (u32)(eax));  // @12_5f2910
  ecx = edx = 0;  // @13_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @14_5f2910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_5f2910
  ecx = eax;  // @16_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 152), sizeof v); (u32)v; }));  // @17_5f2910
  ecx = edx = 0;  // @18_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @19_5f2910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_5f2910
  ecx = eax;  // @21_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 156), sizeof v); (u32)v; }));  // @22_5f2910
  ecx = edx = 0;  // @23_5f2910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @24_5f2910
  { u32 v = (u32)((u32)(7046532)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @25_5f2910
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 19), &v, sizeof v); }  // @26_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @27_5f2910
  eax = (u32)(EBP - 40);  // @28_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @29_5f2910
  { u32 v = (u32)((u32)(1000000)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @30_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @31_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @32_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @33_5f2910
  reg.state = (s32)((u32)(0));  // @34_5f2910
  eax = ext_5fd7c0_thiscall2(ecx, (u32)(eax));  // @35_5f2910
  ecx = edx = 0;  // @36_5f2910
  ecx = (u32)(EBP - 40);  // @37_5f2910
  eax = ext_602240_thiscall1(ecx);  // @38_5f2910
  ecx = edx = 0;  // @39_5f2910
  SEH_LEAVE();  // @40_5f2910
  return eax;  // @41_5f2910
}
PCREG(5f2910, lifted_5f2910);

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

extern "C" u32 THISCALL lifted_5697c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_5697c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5697c0
  { u32 v = (u32)((u32)(6977024)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_5697c0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 445), sizeof v); (u32)v; }), (u32)(1));  // @2_5697c0
  ecx = edx = 0;  // @3_5697c0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 449), sizeof v); (u32)v; }), (u32)(1));  // @4_5697c0
  ecx = edx = 0;  // @5_5697c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @6_5697c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @7_5697c0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5697c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_5697c0
  reg.state = (s32)((u32)(0));  // @10_5697c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @11_5697c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_5697c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @13_5697c0
  ecx = edx = 0;  // @14_5697c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_5697c0
  reg.state = (s32)((u32)(4294967295));  // @16_5697c0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L56988f;  // @17_5697c0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L569881;  // @18_5697c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @19_5697c0
  reg.state = (s32)((u32)(1));  // @20_5697c0
  if ((eax & eax) == 0) goto L56986c;  // @21_5697c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5697c0
  ecx = edx = 0;  // @23_5697c0
  eax = esi;  // @24_5697c0
  SEH_LEAVE();  // @25_5697c0
  return eax;  // @26_5697c0
  L56986c:;
  __builtin_trap();  // @28_5697c0
  L569881:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(461));  // @30_5697c0
  ecx = edx = 0;  // @31_5697c0
  L56988f:;
  eax = esi;  // @33_5697c0
  SEH_LEAVE();  // @34_5697c0
  return eax;  // @35_5697c0
}
PCREG(5697c0, lifted_5697c0);

extern "C" u32 THISCALL lifted_5c3f90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_5c3f90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5c3f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @1_5c3f90
  { u32 v = (u32)((u32)(7028572)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5c3f90
  if ((ecx & ecx) == 0) goto L5c3fcf;  // @3_5c3f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5c3f90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_5c3f90
  ecx = edx = 0;  // @6_5c3f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @7_5c3f90
  L5c3fcf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @9_5c3f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @10_5c3f90
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_5c3f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_5c3f90
  reg.state = (s32)((u32)(0));  // @13_5c3f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @14_5c3f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_5c3f90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @16_5c3f90
  ecx = edx = 0;  // @17_5c3f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_5c3f90
  reg.state = (s32)((u32)(4294967295));  // @19_5c3f90
  if (((eax & 0xff) & (u32)(1)) == 0) goto L5c4053;  // @20_5c3f90
  if (((eax & 0xff) & (u32)(4)) != 0) goto L5c4048;  // @21_5c3f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @22_5c3f90
  reg.state = (s32)((u32)(1));  // @23_5c3f90
  if ((eax & eax) == 0) goto L5c4033;  // @24_5c3f90
  eax = ((u32(STDCALL *)(void))(eax))();  // @25_5c3f90
  ecx = edx = 0;  // @26_5c3f90
  eax = esi;  // @27_5c3f90
  SEH_LEAVE();  // @28_5c3f90
  return eax;  // @29_5c3f90
  L5c4033:;
  __builtin_trap();  // @31_5c3f90
  L5c4048:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(84));  // @33_5c3f90
  ecx = edx = 0;  // @34_5c3f90
  L5c4053:;
  eax = esi;  // @36_5c3f90
  SEH_LEAVE();  // @37_5c3f90
  return eax;  // @38_5c3f90
}
PCREG(5c3f90, lifted_5c3f90);

extern "C" u32 THISCALL lifted_45c3e0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_45c3e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45c3e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_45c3e0
  { u32 v = (u32)((u32)(6835748)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_45c3e0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(262144)) == 0) goto L45c426;  // @3_45c3e0
  eax = ext_4da720_thiscall2(ecx, (u32)(0));  // @4_45c3e0
  ecx = edx = 0;  // @5_45c3e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @6_45c3e0
  eax = ext_4dae60_thiscall1(ecx);  // @7_45c3e0
  ecx = edx = 0;  // @8_45c3e0
  L45c426:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @10_45c3e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L45c447;  // @11_45c3e0
  eax = ext_4dc130_thiscall1(ecx);  // @12_45c3e0
  ecx = edx = 0;  // @13_45c3e0
  if ((eax & eax) == 0) goto L45c447;  // @14_45c3e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_45c3e0
  ecx = eax;  // @16_45c3e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 656)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }), (u32)(1));  // @17_45c3e0
  ecx = edx = 0;  // @18_45c3e0
  L45c447:;
  ecx = esi;  // @20_45c3e0
  eax = ext_45e660_thiscall1(ecx);  // @21_45c3e0
  ecx = edx = 0;  // @22_45c3e0
  ecx = esi;  // @23_45c3e0
  eax = ext_45e710_thiscall1(ecx);  // @24_45c3e0
  ecx = edx = 0;  // @25_45c3e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_45c3e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @27_45c3e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_45c3e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 304)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @29_45c3e0
  ecx = edx = 0;  // @30_45c3e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @31_45c3e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @32_45c3e0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) < (s32)(u32)(0)) goto L45c49e;  // @33_45c3e0
  eax = ext_4dc630_thiscall3(ecx, (u32)(2147483648), (u32)(0));  // @34_45c3e0
  ecx = edx = 0;  // @35_45c3e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @36_45c3e0
  if ((esi & esi) == 0) goto L45c49e;  // @37_45c3e0
  ecx = esi;  // @38_45c3e0
  eax = ext_4d9430_thiscall1(ecx);  // @39_45c3e0
  ecx = edx = 0;  // @40_45c3e0
  eax = ext_4d9590_cdecl1((u32)(esi));  // @41_45c3e0
  ecx = edx = 0;  // @42_45c3e0
  L45c49e:;
  SEH_LEAVE();  // @44_45c3e0
  return eax;  // @45_45c3e0
}
PCREG(45c3e0, lifted_45c3e0);

extern "C" u32 lifted_41cfd0(void) {
  SEH_ENTER(0x663f7f);  // @h_41cfd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ext_41e290_cdecl1((u32)(13));  // @0_41cfd0
  ecx = edx = 0;  // @1_41cfd0
  edx = eax;  // @2_41cfd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_41cfd0
  if ((edx & edx) == 0) goto L41d019;  // @4_41cfd0
  { u32 v = (u32)((u32)(6777852)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @5_41cfd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @6_41cfd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @7_41cfd0
  goto L41d01b;  // @8_41cfd0
  L41d019:;
  edx = 0;  // @10_41cfd0
  L41d01b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @12_41cfd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7327044), &v, sizeof v); }  // @13_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_41cfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @15_41cfd0
  ecx = edx = 0;  // @16_41cfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @17_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_41cfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(9));  // @19_41cfd0
  ecx = edx = 0;  // @20_41cfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327048), sizeof v); (u32)v; }) != (u32)(0)) goto L41d07a;  // @21_41cfd0
  eax = ext_41e290_cdecl1((u32)(109));  // @22_41cfd0
  ecx = edx = 0;  // @23_41cfd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @24_41cfd0
  reg.state = (s32)((u32)(0));  // @25_41cfd0
  if ((eax & eax) == 0) goto L41d066;  // @26_41cfd0
  ecx = eax;  // @27_41cfd0
  eax = ext_54f890_thiscall1(ecx);  // @28_41cfd0
  ecx = edx = 0;  // @29_41cfd0
  ecx = eax;  // @30_41cfd0
  goto L41d068;  // @31_41cfd0
  L41d066:;
  ecx = 0;  // @33_41cfd0
  L41d068:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7327048), &v, sizeof v); }  // @35_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_41cfd0
  reg.state = (s32)((u32)(4294967295));  // @37_41cfd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @38_41cfd0
  ecx = edx = 0;  // @39_41cfd0
  L41d07a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @41_41cfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) == (u32)(0)) goto L41d096;  // @42_41cfd0
  eax = ext_580000_cdecl0();  // @43_41cfd0
  ecx = edx = 0;  // @44_41cfd0
  eax = ext_560580_cdecl0();  // @45_41cfd0
  ecx = edx = 0;  // @46_41cfd0
  eax = ext_41c750_cdecl0();  // @47_41cfd0
  ecx = edx = 0;  // @48_41cfd0
  L41d096:;
  SEH_LEAVE();  // @50_41cfd0
  return eax;  // @51_41cfd0
}
PCREG(41cfd0, lifted_41cfd0);

extern "C" u32 THISCALL lifted_441d90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_441d90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_441d90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; }) != (u32)(0)) goto L441dee;  // @1_441d90
  eax = ext_41e290_cdecl1((u32)(28));  // @2_441d90
  ecx = edx = 0;  // @3_441d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_441d90
  reg.state = (s32)((u32)(0));  // @5_441d90
  if ((eax & eax) == 0) goto L441de2;  // @6_441d90
  ecx = eax;  // @7_441d90
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(0));  // @8_441d90
  ecx = edx = 0;  // @9_441d90
  goto L441de4;  // @10_441d90
  L441de2:;
  eax = 0;  // @12_441d90
  L441de4:;
  reg.state = (s32)((u32)(4294967295));  // @14_441d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @15_441d90
  L441dee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; });  // @17_441d90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_441d90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edi));  // @20_441d90
  ecx = edx = 0;  // @21_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_441d90
  ecx = edi;  // @23_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 776), sizeof v); (u32)v; });  // @24_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @25_441d90
  ecx = edx = 0;  // @26_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e12;  // @27_441d90
  ecx = esi;  // @28_441d90
  eax = ext_442050_thiscall2(ecx, (u32)(edi));  // @29_441d90
  ecx = edx = 0;  // @30_441d90
  L441e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_441d90
  ecx = edi;  // @33_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @34_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @35_441d90
  ecx = edx = 0;  // @36_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e2a;  // @37_441d90
  ecx = esi;  // @38_441d90
  eax = ext_441e40_thiscall2(ecx, (u32)(edi));  // @39_441d90
  ecx = edx = 0;  // @40_441d90
  L441e2a:;
  SEH_LEAVE();  // @42_441d90
  return eax;  // @43_441d90
}
PCREG(441d90, lifted_441d90);

extern "C" u32 THISCALL lifted_4b0840(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_4b0840
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4b0840
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b0840
  ecx = esi;  // @2_4b0840
  eax = ext_4e5e60_thiscall1(ecx);  // @3_4b0840
  ecx = edx = 0;  // @4_4b0840
  ecx = esi;  // @5_4b0840
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @6_4b0840
  eax = ext_4e5e60_thiscall1(ecx);  // @7_4b0840
  ecx = edx = 0;  // @8_4b0840
  ecx = esi;  // @9_4b0840
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @10_4b0840
  eax = ext_4e5e60_thiscall1(ecx);  // @11_4b0840
  ecx = edx = 0;  // @12_4b0840
  ecx = esi;  // @13_4b0840
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @14_4b0840
  eax = ext_4e5e60_thiscall1(ecx);  // @15_4b0840
  ecx = edx = 0;  // @16_4b0840
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 88), &v, sizeof v); }  // @17_4b0840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4b0840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_4b0840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4b0840
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840116), (u32)(0), (u32)(6889180), (u32)(2620));  // @21_4b0840
  ecx = edx = 0;  // @22_4b0840
  ecx = esi;  // @23_4b0840
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 220), &v, sizeof v); }  // @24_4b0840
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 222), &v, sizeof v); }  // @25_4b0840
  eax = ext_4e5ea0_thiscall1(ecx);  // @26_4b0840
  ecx = edx = 0;  // @27_4b0840
  if ((eax & eax) == 0) goto L4b0907;  // @28_4b0840
  ecx = (u32)(EBP - 144);  // @29_4b0840
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @30_4b0840
  ecx = edx = 0;  // @31_4b0840
  eax = (u32)(EBP - 144);  // @32_4b0840
  reg.state = (s32)((u32)(0));  // @33_4b0840
  ecx = (u32)(edi + 92);  // @34_4b0840
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @35_4b0840
  ecx = edx = 0;  // @36_4b0840
  ecx = (u32)(EBP - 144);  // @37_4b0840
  eax = ext_4cbec0_thiscall1(ecx);  // @38_4b0840
  ecx = edx = 0;  // @39_4b0840
  L4b0907:;
  SEH_LEAVE();  // @41_4b0840
  ext_633654(G(u32, 0x6f5630));  // @42_4b0840
  return eax;  // @43_4b0840
}
PCREG(4b0840, lifted_4b0840);

extern "C" u32 FASTCALL lifted_44c450(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66626c);  // @h_44c450
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_44c450
  ebx = ecx;  // @1_44c450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_44c450
  if ((eax & eax) == 0) goto L44c4b4;  // @3_44c450
  eax = ext_45c4f0_cdecl2((u32)(25), (u32)(eax));  // @4_44c450
  ecx = edx = 0;  // @5_44c450
  esi = eax;  // @6_44c450
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_44c450
  reg.state = (s32)((u32)(0));  // @8_44c450
  if ((esi & esi) == 0) goto L44c4e6;  // @9_44c450
  ecx = esi;  // @10_44c450
  eax = ext_43de40_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(ebx), (u32)(edi));  // @11_44c450
  ecx = edx = 0;  // @12_44c450
  { u32 v = (u32)((u32)(6815532)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @13_44c450
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @14_44c450
  goto L44c4e8;  // @15_44c450
  L44c4b4:;
  eax = ext_45c4b0_cdecl1((u32)(25));  // @17_44c450
  ecx = edx = 0;  // @18_44c450
  esi = eax;  // @19_44c450
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @20_44c450
  reg.state = (s32)((u32)(1));  // @21_44c450
  if ((esi & esi) == 0) goto L44c4e6;  // @22_44c450
  ecx = esi;  // @23_44c450
  eax = ext_43de40_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(ebx), (u32)(edi));  // @24_44c450
  ecx = edx = 0;  // @25_44c450
  { u32 v = (u32)((u32)(6815532)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_44c450
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @27_44c450
  goto L44c4e8;  // @28_44c450
  L44c4e6:;
  esi = 0;  // @30_44c450
  L44c4e8:;
  eax = esi;  // @32_44c450
  SEH_LEAVE();  // @33_44c450
  return eax;  // @34_44c450
}
PCREG(44c450, lifted_44c450);

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

extern "C" u32 THISCALL lifted_53a810(u32 ecx_in) {
  SEH_ENTER(0x66a9be);  // @h_53a810
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_53a810
  eax = ext_41e290_cdecl1((u32)(28));  // @1_53a810
  ecx = edx = 0;  // @2_53a810
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_53a810
  reg.state = (s32)((u32)(0));  // @4_53a810
  if ((eax & eax) == 0) goto L53a85b;  // @5_53a810
  ecx = eax;  // @6_53a810
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(8));  // @7_53a810
  ecx = edx = 0;  // @8_53a810
  goto L53a85d;  // @9_53a810
  L53a85b:;
  eax = 0;  // @11_53a810
  L53a85d:;
  reg.state = (s32)((u32)(4294967295));  // @13_53a810
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_53a810
  eax = ext_41e290_cdecl1((u32)(40));  // @15_53a810
  ecx = edx = 0;  // @16_53a810
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @17_53a810
  reg.state = (s32)((u32)(1));  // @18_53a810
  if ((eax & eax) == 0) goto L53a88b;  // @19_53a810
  ecx = eax;  // @20_53a810
  eax = ext_4cca60_thiscall3(ecx, (u32)(32), (u32)(4));  // @21_53a810
  ecx = edx = 0;  // @22_53a810
  goto L53a88d;  // @23_53a810
  L53a88b:;
  eax = 0;  // @25_53a810
  L53a88d:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @27_53a810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_53a810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_53a810
  reg.state = (s32)((u32)(4294967295));  // @30_53a810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_53a810
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6957884), (u32)(0), (u32)(6957828), (u32)(13));  // @32_53a810
  ecx = edx = 0;  // @33_53a810
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @34_53a810
  eax = esi;  // @35_53a810
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 10), &v, sizeof v); }  // @36_53a810
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 14), &v, sizeof v); }  // @37_53a810
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @38_53a810
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @39_53a810
  SEH_LEAVE();  // @40_53a810
  return eax;  // @41_53a810
}
PCREG(53a810, lifted_53a810);

extern "C" u32 THISCALL lifted_5edd80(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cb55);  // @h_5edd80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5edd80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5edd80
  { u32 v = (u32)((u32)(7045476)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5edd80
  reg.state = (s32)((u32)(0));  // @3_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5), &v, sizeof v); }  // @4_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @5_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @6_5edd80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_5edd80
  reg.state = (s32)((u32)(1));  // @8_5edd80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @9_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @10_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65), &v, sizeof v); }  // @11_5edd80
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @12_5edd80
  { u32 v = (u32)((u32)(256)); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @13_5edd80
  { u32 v = (u32)((u32)(256)); __builtin_memcpy((void *)(u32)(esi + 73), &v, sizeof v); }  // @14_5edd80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 77), &v, sizeof v); }  // @15_5edd80
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(esi + 78), &v, sizeof v); }  // @16_5edd80
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @17_5edd80
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @18_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @19_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @20_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 98), &v, sizeof v); }  // @21_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 102), &v, sizeof v); }  // @22_5edd80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @23_5edd80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 106), &v, sizeof v); }  // @24_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @25_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @26_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @27_5edd80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @28_5edd80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @29_5edd80
  eax = ext_41e290_cdecl1((u32)(247));  // @30_5edd80
  ecx = edx = 0;  // @31_5edd80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @32_5edd80
  reg.state = (s32)((u32)(2));  // @33_5edd80
  if ((eax & eax) == 0) goto L5ede79;  // @34_5edd80
  ecx = eax;  // @35_5edd80
  eax = ext_5ed460_thiscall1(ecx);  // @36_5edd80
  ecx = edx = 0;  // @37_5edd80
  goto L5ede7b;  // @38_5edd80
  L5ede79:;
  eax = 0;  // @40_5edd80
  L5ede7b:;
  ecx = (u32)(esi + 29);  // @42_5edd80
  reg.state = (s32)((u32)(1));  // @43_5edd80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @44_5edd80
  eax = ext_4de7a0_thiscall1(ecx);  // @45_5edd80
  ecx = edx = 0;  // @46_5edd80
  eax = esi;  // @47_5edd80
  SEH_LEAVE();  // @48_5edd80
  return eax;  // @49_5edd80
}
PCREG(5edd80, lifted_5edd80);

extern "C" u32 lifted_545260(void) {
  SEH_ENTER(0x66abd4);  // @h_545260
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7412620), sizeof v); (u32)v; });  // @0_545260
  ecx = eax;  // @1_545260
  eax = (eax + 1);  // @2_545260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7412620), &v, sizeof v); }  // @3_545260
  if ((ecx & ecx) != 0) goto L545338;  // @4_545260
  eax = ext_41e290_cdecl1((u32)(264));  // @5_545260
  ecx = edx = 0;  // @6_545260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_545260
  reg.state = (s32)((u32)(0));  // @8_545260
  if ((eax & eax) == 0) goto L5452ca;  // @9_545260
  ecx = eax;  // @10_545260
  eax = ext_4d8330_thiscall4(ecx, (u32)(6959384), (u32)(0), (u32)(7412608));  // @11_545260
  ecx = edx = 0;  // @12_545260
  edx = eax;  // @13_545260
  goto L5452cc;  // @14_545260
  L5452ca:;
  edx = 0;  // @16_545260
  L5452cc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_545260
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7412612), &v, sizeof v); }  // @19_545260
  reg.state = (s32)((u32)(4294967295));  // @20_545260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_545260
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @22_545260
  ecx = edx = 0;  // @23_545260
  eax = ext_41e290_cdecl1((u32)(264));  // @24_545260
  ecx = edx = 0;  // @25_545260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_545260
  reg.state = (s32)((u32)(1));  // @27_545260
  if ((eax & eax) == 0) goto L54531a;  // @28_545260
  ecx = eax;  // @29_545260
  eax = ext_4d8330_thiscall4(ecx, (u32)(6959396), (u32)(0), (u32)(7259084));  // @30_545260
  ecx = edx = 0;  // @31_545260
  edx = eax;  // @32_545260
  goto L54531c;  // @33_545260
  L54531a:;
  edx = 0;  // @35_545260
  L54531c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @37_545260
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7412616), &v, sizeof v); }  // @38_545260
  reg.state = (s32)((u32)(4294967295));  // @39_545260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_545260
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @41_545260
  ecx = edx = 0;  // @42_545260
  L545338:;
  SEH_LEAVE();  // @44_545260
  return eax;  // @45_545260
}
PCREG(545260, lifted_545260);

extern "C" u32 THISCALL lifted_430010(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66528c);  // @h_430010
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ecx;  // @0_430010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_430010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_430010
  if ((esi & esi) == 0) goto L4300ab;  // @3_430010
  L430042:;
  ecx = eax;  // @5_430010
  eax = ext_430010_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }));  // @6_430010
  ecx = edx = 0;  // @7_430010
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @8_430010
  ecx = (u32)(esi + 25);  // @9_430010
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @11_430010
  eax = (eax - edx);  // @12_430010
  reg.state = (s32)((u32)(0));  // @13_430010
  if ((edx & edx) == 0) goto L43006f;  // @14_430010
  if ((eax & eax) == 0) goto L43006f;  // @15_430010
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @16_430010
  ecx = edx = 0;  // @17_430010
  L43006f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @19_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @20_430010
  eax = (eax - edx);  // @21_430010
  reg.state = (s32)((u32)(1));  // @22_430010
  if ((edx & edx) == 0) goto L430090;  // @23_430010
  if ((eax & eax) == 0) goto L430090;  // @24_430010
  ecx = (u32)(esi + 13);  // @25_430010
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @26_430010
  ecx = edx = 0;  // @27_430010
  L430090:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @29_430010
  reg.state = (s32)((u32)(4294967295));  // @30_430010
  eax = ext_54f870_stdcall2((u32)(esi), (u32)(37));  // @31_430010
  ecx = edx = 0;  // @32_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @33_430010
  esi = ebx;  // @34_430010
  if ((ebx & ebx) != 0) goto L430042;  // @35_430010
  L4300ab:;
  SEH_LEAVE();  // @37_430010
  return eax;  // @38_430010
}
PCREG(430010, lifted_430010);

extern "C" u32 THISCALL lifted_4a9880(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_4a9880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4a9880
  { u32 v = (u32)((u32)(6882628)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4a9880
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }), (u32)(10));  // @2_4a9880
  ecx = edx = 0;  // @3_4a9880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4a9880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89724), sizeof v); (u32)v; }));  // @6_4a9880
  ecx = edx = 0;  // @7_4a9880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89724), sizeof v); (u32)v; });  // @8_4a9880
  if ((ecx & ecx) == 0) goto L4a98dc;  // @9_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4a9880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_4a9880
  ecx = edx = 0;  // @12_4a9880
  L4a98dc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4a9880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89728), sizeof v); (u32)v; }));  // @16_4a9880
  ecx = edx = 0;  // @17_4a9880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89728), sizeof v); (u32)v; });  // @18_4a9880
  if ((ecx & ecx) == 0) goto L4a9900;  // @19_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4a9880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @21_4a9880
  ecx = edx = 0;  // @22_4a9880
  L4a9900:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4a9880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89732), sizeof v); (u32)v; }));  // @26_4a9880
  ecx = edx = 0;  // @27_4a9880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89732), sizeof v); (u32)v; });  // @28_4a9880
  if ((ecx & ecx) == 0) goto L4a9924;  // @29_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4a9880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @31_4a9880
  ecx = edx = 0;  // @32_4a9880
  L4a9924:;
  ecx = (u32)(esi + 89692);  // @34_4a9880
  eax = ext_4ccfe0_thiscall1(ecx);  // @35_4a9880
  ecx = edx = 0;  // @36_4a9880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @37_4a9880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @38_4a9880
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @39_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4a9880
  reg.state = (s32)((u32)(0));  // @41_4a9880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @42_4a9880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_4a9880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @44_4a9880
  ecx = edx = 0;  // @45_4a9880
  SEH_LEAVE();  // @46_4a9880
  return eax;  // @47_4a9880
}
PCREG(4a9880, lifted_4a9880);

extern "C" u32 THISCALL lifted_431630(u32 ecx_in) {
  SEH_ENTER(0x6653ec);  // @h_431630
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_431630
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_431630
  ecx = (u32)(edi + 4);  // @2_431630
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @3_431630
  { u32 v = (u32)((u32)(6790804)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @4_431630
  eax = ext_4cbeb0_thiscall1(ecx);  // @5_431630
  ecx = edx = 0;  // @6_431630
  ecx = (u32)(edi + 132);  // @7_431630
  reg.state = (s32)((u32)(0));  // @8_431630
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(44));  // @9_431630
  ecx = edx = 0;  // @10_431630
  ecx = (u32)(edi + 172);  // @11_431630
  reg.state = (s32)((u32)(1));  // @12_431630
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(1));  // @13_431630
  ecx = edx = 0;  // @14_431630
  ecx = (u32)(edi + 200);  // @15_431630
  reg.state = (s32)((u32)(2));  // @16_431630
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @17_431630
  ecx = edx = 0;  // @18_431630
  ecx = (u32)(EBP - 144);  // @19_431630
  reg.state = (s32)((u32)(3));  // @20_431630
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(edi + 228), &v, sizeof v); }  // @21_431630
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 253), &v, sizeof v); }  // @22_431630
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6777860));  // @23_431630
  ecx = edx = 0;  // @24_431630
  eax = (u32)(EBP - 144);  // @25_431630
  reg.state = (s32)((u32)(4));  // @26_431630
  ecx = (u32)(edi + 4);  // @27_431630
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @28_431630
  ecx = edx = 0;  // @29_431630
  ecx = (u32)(EBP - 144);  // @30_431630
  eax = ext_4cbec0_thiscall1(ecx);  // @31_431630
  ecx = edx = 0;  // @32_431630
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(edi + 232), &v, sizeof v); }  // @33_431630
  eax = edi;  // @34_431630
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(edi + 236), &v, sizeof v); }  // @35_431630
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(edi + 240), &v, sizeof v); }  // @36_431630
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(edi + 244), &v, sizeof v); }  // @37_431630
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(edi + 248), &v, sizeof v); }  // @38_431630
  { u16 v = (u16)((u32)(257)); __builtin_memcpy((void *)(u32)(edi + 256), &v, sizeof v); }  // @39_431630
  SEH_LEAVE();  // @40_431630
  ext_633654(G(u32, 0x6f5630));  // @41_431630
  return eax;  // @42_431630
}
PCREG(431630, lifted_431630);

extern "C" u32 THISCALL lifted_5eecd0(u32 ecx_in) {
  SEH_ENTER(0x66cc46);  // @h_5eecd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5eecd0
  eax = ext_41e290_cdecl1((u32)(215));  // @1_5eecd0
  ecx = edx = 0;  // @2_5eecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_5eecd0
  reg.state = (s32)((u32)(0));  // @4_5eecd0
  if ((eax & eax) == 0) goto L5eed1c;  // @5_5eecd0
  ecx = eax;  // @6_5eecd0
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @7_5eecd0
  ecx = edx = 0;  // @8_5eecd0
  goto L5eed1e;  // @9_5eecd0
  L5eed1c:;
  eax = 0;  // @11_5eecd0
  L5eed1e:;
  reg.state = (s32)((u32)(4294967295));  // @13_5eecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_5eecd0
  eax = ext_41e290_cdecl1((u32)(247));  // @15_5eecd0
  ecx = edx = 0;  // @16_5eecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @17_5eecd0
  reg.state = (s32)((u32)(1));  // @18_5eecd0
  if ((eax & eax) == 0) goto L5eed4c;  // @19_5eecd0
  ecx = eax;  // @20_5eecd0
  eax = ext_5ed460_thiscall1(ecx);  // @21_5eecd0
  ecx = edx = 0;  // @22_5eecd0
  goto L5eed4e;  // @23_5eecd0
  L5eed4c:;
  eax = 0;  // @25_5eecd0
  L5eed4e:;
  reg.state = (s32)((u32)(4294967295));  // @27_5eecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @28_5eecd0
  eax = ext_41e290_cdecl1((u32)(168));  // @29_5eecd0
  ecx = edx = 0;  // @30_5eecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_5eecd0
  reg.state = (s32)((u32)(2));  // @32_5eecd0
  if ((eax & eax) == 0) goto L5eed8f;  // @33_5eecd0
  ecx = eax;  // @34_5eecd0
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(3));  // @35_5eecd0
  ecx = edx = 0;  // @36_5eecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @37_5eecd0
  SEH_LEAVE();  // @38_5eecd0
  return eax;  // @39_5eecd0
  L5eed8f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @41_5eecd0
  SEH_LEAVE();  // @42_5eecd0
  return eax;  // @43_5eecd0
}
PCREG(5eecd0, lifted_5eecd0);

extern "C" u32 THISCALL lifted_614f10(u32 ecx_in) {
  SEH_ENTER(0x66e46d);  // @h_614f10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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

extern "C" u32 THISCALL lifted_447690(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447690
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447690
  { u32 v = (u32)((u32)(6811248)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447690
  if ((ecx & ecx) == 0) goto L447714;  // @3_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447690
  edx = (u32)(EBP - 24);  // @5_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @6_447690
  ecx = edx = 0;  // @7_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @8_447690
  edx = (u32)(EBP - 24);  // @9_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @11_447690
  ecx = edx = 0;  // @12_447690
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L447714;  // @13_447690
  L4476e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @16_447690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @18_447690
  ecx = edx = 0;  // @19_447690
  if ((eax & eax) == 0) goto L447702;  // @20_447690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_447690
  ecx = eax;  // @22_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @23_447690
  ecx = edx = 0;  // @24_447690
  L447702:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @26_447690
  edx = (u32)(EBP - 24);  // @27_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @29_447690
  ecx = edx = 0;  // @30_447690
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4476e0;  // @31_447690
  L447714:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @33_447690
  if ((ecx & ecx) == 0) goto L447721;  // @34_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @36_447690
  ecx = edx = 0;  // @37_447690
  L447721:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @39_447690
  reg.state = (s32)((u32)(0));  // @40_447690
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @41_447690
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @42_447690
  ecx = edx = 0;  // @43_447690
  ecx = esi;  // @44_447690
  eax = ext_45c3e0_thiscall1(ecx);  // @45_447690
  ecx = edx = 0;  // @46_447690
  SEH_LEAVE();  // @47_447690
  return eax;  // @48_447690
}
PCREG(447690, lifted_447690);

extern "C" u32 THISCALL lifted_447750(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447750
  { u32 v = (u32)((u32)(6811840)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447750
  if ((ecx & ecx) == 0) goto L4477d4;  // @3_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447750
  edx = (u32)(EBP - 24);  // @5_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @6_447750
  ecx = edx = 0;  // @7_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @8_447750
  edx = (u32)(EBP - 24);  // @9_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @11_447750
  ecx = edx = 0;  // @12_447750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4477d4;  // @13_447750
  L4477a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @16_447750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @18_447750
  ecx = edx = 0;  // @19_447750
  if ((eax & eax) == 0) goto L4477c2;  // @20_447750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_447750
  ecx = eax;  // @22_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @23_447750
  ecx = edx = 0;  // @24_447750
  L4477c2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @26_447750
  edx = (u32)(EBP - 24);  // @27_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @29_447750
  ecx = edx = 0;  // @30_447750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4477a0;  // @31_447750
  L4477d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @33_447750
  if ((ecx & ecx) == 0) goto L4477e1;  // @34_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @36_447750
  ecx = edx = 0;  // @37_447750
  L4477e1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @39_447750
  reg.state = (s32)((u32)(0));  // @40_447750
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @41_447750
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @42_447750
  ecx = edx = 0;  // @43_447750
  ecx = esi;  // @44_447750
  eax = ext_45c3e0_thiscall1(ecx);  // @45_447750
  ecx = edx = 0;  // @46_447750
  SEH_LEAVE();  // @47_447750
  return eax;  // @48_447750
}
PCREG(447750, lifted_447750);

extern "C" u32 THISCALL lifted_447810(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447810
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447810
  { u32 v = (u32)((u32)(6812432)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447810
  if ((ecx & ecx) == 0) goto L447894;  // @3_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447810
  edx = (u32)(EBP - 24);  // @5_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @6_447810
  ecx = edx = 0;  // @7_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @8_447810
  edx = (u32)(EBP - 24);  // @9_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @11_447810
  ecx = edx = 0;  // @12_447810
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L447894;  // @13_447810
  L447860:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @16_447810
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @18_447810
  ecx = edx = 0;  // @19_447810
  if ((eax & eax) == 0) goto L447882;  // @20_447810
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_447810
  ecx = eax;  // @22_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @23_447810
  ecx = edx = 0;  // @24_447810
  L447882:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @26_447810
  edx = (u32)(EBP - 24);  // @27_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @29_447810
  ecx = edx = 0;  // @30_447810
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L447860;  // @31_447810
  L447894:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @33_447810
  if ((ecx & ecx) == 0) goto L4478a1;  // @34_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @36_447810
  ecx = edx = 0;  // @37_447810
  L4478a1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @39_447810
  reg.state = (s32)((u32)(0));  // @40_447810
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @41_447810
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @42_447810
  ecx = edx = 0;  // @43_447810
  ecx = esi;  // @44_447810
  eax = ext_45c3e0_thiscall1(ecx);  // @45_447810
  ecx = edx = 0;  // @46_447810
  SEH_LEAVE();  // @47_447810
  return eax;  // @48_447810
}
PCREG(447810, lifted_447810);

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

extern "C" u32 THISCALL lifted_5082c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_5082c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @2_5082c0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_5082c0
  ecx = edx = 0;  // @4_5082c0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @5_5082c0
  edx = (edx - (u32)(3));  // @6_5082c0
  if (edx == 0) goto L50834e;  // @7_5082c0
  edx = (edx - (u32)(1));  // @8_5082c0
  if (edx == 0) goto L508345;  // @9_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(273));  // @12_5082c0
  ecx = edx = 0;  // @13_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6932144), (u32)(6932912));  // @15_5082c0
  ecx = edx = 0;  // @16_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @17_5082c0
  if ((eax & eax) == 0) goto L508340;  // @18_5082c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @19_5082c0
  ecx = edx = 0;  // @20_5082c0
  eax = 0;  // @21_5082c0
  goto L508350;  // @22_5082c0
  L508340:;
  __builtin_trap();  // @24_5082c0
  L508345:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_5082c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @28_5082c0
  ecx = edx = 0;  // @29_5082c0
  goto L508350;  // @30_5082c0
  L50834e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_5082c0
  L508350:;
  ecx = (u32)(EBP - 144);  // @34_5082c0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @35_5082c0
  ecx = edx = 0;  // @36_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @37_5082c0
  eax = (u32)(EBP - 144);  // @38_5082c0
  ecx = (ecx + (u32)(1042));  // @39_5082c0
  reg.state = (s32)((u32)(0));  // @40_5082c0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @41_5082c0
  ecx = edx = 0;  // @42_5082c0
  ecx = (u32)(EBP - 144);  // @43_5082c0
  eax = ext_4cbec0_thiscall1(ecx);  // @44_5082c0
  ecx = edx = 0;  // @45_5082c0
  SEH_LEAVE();  // @46_5082c0
  ext_633654(G(u32, 0x6f5630));  // @47_5082c0
  return eax;  // @48_5082c0
}
PCREG(5082c0, lifted_5082c0);

extern "C" u32 THISCALL lifted_469da0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666ba7);  // @h_469da0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_469da0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_469da0
  eax = ext_43e990_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_469da0
  ecx = edx = 0;  // @3_469da0
  reg.state = (s32)((u32)(0));  // @4_469da0
  { u32 v = (u32)((u32)(6842600)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_469da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @6_469da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @7_469da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @8_469da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @9_469da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @10_469da0
  eax = ext_41e290_cdecl1((u32)(28));  // @11_469da0
  ecx = edx = 0;  // @12_469da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @13_469da0
  reg.state = (s32)((u32)(1));  // @14_469da0
  if ((eax & eax) == 0) goto L469e29;  // @15_469da0
  ecx = eax;  // @16_469da0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(1));  // @17_469da0
  ecx = edx = 0;  // @18_469da0
  goto L469e2b;  // @19_469da0
  L469e29:;
  eax = 0;  // @21_469da0
  L469e2b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @23_469da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_469da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_469da0
  reg.state = (s32)((u32)(0));  // @26_469da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_469da0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6850540), (u32)(0), (u32)(6850500), (u32)(360));  // @28_469da0
  ecx = edx = 0;  // @29_469da0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @30_469da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_469da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_469da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_469da0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6850560), (u32)(0), (u32)(6850500), (u32)(361));  // @34_469da0
  ecx = edx = 0;  // @35_469da0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @36_469da0
  eax = esi;  // @37_469da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @38_469da0
  SEH_LEAVE();  // @39_469da0
  return eax;  // @40_469da0
}
PCREG(469da0, lifted_469da0);

extern "C" u32 THISCALL lifted_5f97e0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_5f97e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5f97e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L5f9871;  // @1_5f97e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @2_5f97e0
  L5f9811:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @4_5f97e0
  if ((ecx & ecx) == 0) goto L5f9824;  // @5_5f97e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @6_5f97e0
  ecx = (ecx - 1);  // @7_5f97e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @8_5f97e0
  ebx = (u32)(eax + ecx*4);  // @9_5f97e0
  goto L5f9834;  // @10_5f97e0
  L5f9824:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @12_5f97e0
  if ((eax & eax) == 0) goto L5f9831;  // @13_5f97e0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @14_5f97e0
  ecx = edx = 0;  // @15_5f97e0
  goto L5f9834;  // @16_5f97e0
  L5f9831:;
  __builtin_trap();  // @18_5f97e0
  L5f9834:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_5f97e0
  if ((esi & esi) == 0) goto L5f986b;  // @21_5f97e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_5f97e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @23_5f97e0
  eax = (eax - ecx);  // @24_5f97e0
  reg.state = (s32)((u32)(0));  // @25_5f97e0
  if ((ecx & ecx) == 0) goto L5f9859;  // @26_5f97e0
  if ((eax & eax) == 0) goto L5f9859;  // @27_5f97e0
  ecx = esi;  // @28_5f97e0
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @29_5f97e0
  ecx = edx = 0;  // @30_5f97e0
  L5f9859:;
  reg.state = (s32)((u32)(4294967295));  // @32_5f97e0
  eax = ext_634273_cdecl2((u32)(esi), (u32)(12));  // @33_5f97e0
  ecx = edx = 0;  // @34_5f97e0
  L5f986b:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }) != (u32)(0)) goto L5f9811;  // @36_5f97e0
  L5f9871:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }));  // @38_5f97e0
  ecx = edx = 0;  // @39_5f97e0
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @40_5f97e0
  ecx = edx = 0;  // @41_5f97e0
  SEH_LEAVE();  // @42_5f97e0
  return eax;  // @43_5f97e0
}
PCREG(5f97e0, lifted_5f97e0);

extern "C" u32 THISCALL lifted_57c6f0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66b1bb);  // @h_57c6f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
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

extern "C" u32 THISCALL lifted_4d8fc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d1b);  // @h_4d8fc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4d8fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d8fc0
  ecx = (u32)(EBP - 144);  // @2_4d8fc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @3_4d8fc0
  ecx = edx = 0;  // @4_4d8fc0
  ecx = (u32)(EBP - 144);  // @5_4d8fc0
  reg.state = (s32)((u32)(0));  // @6_4d8fc0
  eax = ext_4cc690_thiscall1(ecx);  // @7_4d8fc0
  ecx = edx = 0;  // @8_4d8fc0
  ecx = (u32)(EBP - 144);  // @9_4d8fc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @10_4d8fc0
  ecx = edx = 0;  // @11_4d8fc0
  edi = eax;  // @12_4d8fc0
  esi = edi;  // @13_4d8fc0
  eax = (u32)(esi + 1);  // @14_4d8fc0
  L4d9023:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @16_4d8fc0
  esi = (esi + 1);  // @17_4d8fc0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L4d9023;  // @18_4d8fc0
  esi = (esi - eax);  // @19_4d8fc0
  ecx = ebx;  // @20_4d8fc0
  eax = ext_4d8db0_stdcall2((u32)(edi), (u32)(esi));  // @21_4d8fc0
  ecx = edx = 0;  // @22_4d8fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @23_4d8fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4d8fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, (u32)(eax));  // @25_4d8fc0
  ecx = edx = 0;  // @26_4d8fc0
  if ((eax & eax) == 0) goto L4d9054;  // @27_4d8fc0
  ecx = ebx;  // @28_4d8fc0
  eax = ext_4d8ef0_stdcall3((u32)(eax), (u32)(edi), (u32)(esi));  // @29_4d8fc0
  ecx = edx = 0;  // @30_4d8fc0
  if ((eax & eax) == 0) goto L4d9054;  // @31_4d8fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @32_4d8fc0
  goto L4d9056;  // @33_4d8fc0
  L4d9054:;
  esi = 0;  // @35_4d8fc0
  L4d9056:;
  ecx = (u32)(EBP - 144);  // @37_4d8fc0
  eax = ext_4cbec0_thiscall1(ecx);  // @38_4d8fc0
  ecx = edx = 0;  // @39_4d8fc0
  eax = esi;  // @40_4d8fc0
  SEH_LEAVE();  // @41_4d8fc0
  ext_633654(G(u32, 0x6f5630));  // @42_4d8fc0
  return eax;  // @43_4d8fc0
}
PCREG(4d8fc0, lifted_4d8fc0);

extern "C" u32 THISCALL lifted_4ffab0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4ffab0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ffab0
  { u32 v = (u32)((u32)(6932168)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4ffab0
  eax = ext_50b4b0_cdecl0();  // @2_4ffab0
  ecx = edx = 0;  // @3_4ffab0
  eax = ext_50d750_cdecl0();  // @4_4ffab0
  ecx = edx = 0;  // @5_4ffab0
  eax = ext_510b70_cdecl0();  // @6_4ffab0
  ecx = edx = 0;  // @7_4ffab0
  eax = ext_511700_cdecl0();  // @8_4ffab0
  ecx = edx = 0;  // @9_4ffab0
  eax = ext_4690b0_cdecl0();  // @10_4ffab0
  ecx = edx = 0;  // @11_4ffab0
  eax = ext_4690b0_cdecl0();  // @12_4ffab0
  ecx = edx = 0;  // @13_4ffab0
  eax = ext_4690b0_cdecl0();  // @14_4ffab0
  ecx = edx = 0;  // @15_4ffab0
  eax = ext_4690b0_cdecl0();  // @16_4ffab0
  ecx = edx = 0;  // @17_4ffab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @18_4ffab0
  if ((ecx & ecx) == 0) goto L4ffb17;  // @19_4ffab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4ffab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 200)))(ecx, (u32)(0));  // @21_4ffab0
  ecx = edx = 0;  // @22_4ffab0
  L4ffb17:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(4));  // @24_4ffab0
  ecx = edx = 0;  // @25_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }), (u32)(4));  // @26_4ffab0
  ecx = edx = 0;  // @27_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }), (u32)(4));  // @28_4ffab0
  ecx = edx = 0;  // @29_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }), (u32)(4));  // @30_4ffab0
  ecx = edx = 0;  // @31_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }), (u32)(4));  // @32_4ffab0
  ecx = edx = 0;  // @33_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }), (u32)(4));  // @34_4ffab0
  ecx = edx = 0;  // @35_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }), (u32)(4));  // @36_4ffab0
  ecx = edx = 0;  // @37_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }), (u32)(4));  // @38_4ffab0
  ecx = edx = 0;  // @39_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }), (u32)(4));  // @40_4ffab0
  ecx = edx = 0;  // @41_4ffab0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }), (u32)(4));  // @42_4ffab0
  ecx = edx = 0;  // @43_4ffab0
  ecx = esi;  // @44_4ffab0
  eax = ext_4e66a0_thiscall1(ecx);  // @45_4ffab0
  ecx = edx = 0;  // @46_4ffab0
  SEH_LEAVE();  // @47_4ffab0
  return eax;  // @48_4ffab0
}
PCREG(4ffab0, lifted_4ffab0);

extern "C" u32 THISCALL lifted_49f5a0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_49f5a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_49f5a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_49f5a0
  eax = ext_469870_thiscall1(ecx);  // @2_49f5a0
  ecx = edx = 0;  // @3_49f5a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_49f5a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_49f5a0
  ecx = (u32)(esi + 108);  // @6_49f5a0
  reg.state = (s32)((u32)(0));  // @7_49f5a0
  { u32 v = (u32)((u32)(6878560)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_49f5a0
  eax = ext_49f670_thiscall1(ecx);  // @9_49f5a0
  ecx = edx = 0;  // @10_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_49f5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_49f5a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @14_49f5a0
  ecx = edx = 0;  // @15_49f5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @16_49f5a0
  edi = eax;  // @17_49f5a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_49f5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(esi));  // @19_49f5a0
  ecx = edx = 0;  // @20_49f5a0
  if ((eax & eax) == 0) goto L49f618;  // @21_49f5a0
  ecx = 0;  // @22_49f5a0
  goto L49f649;  // @23_49f5a0
  L49f618:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @25_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @26_49f5a0
  if ((eax & eax) == 0) goto L49f637;  // @27_49f5a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L49f637;  // @28_49f5a0
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L49f637;  // @29_49f5a0
  ecx = esi;  // @30_49f5a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @31_49f5a0
  ecx = edx = 0;  // @32_49f5a0
  ecx = eax;  // @33_49f5a0
  goto L49f649;  // @34_49f5a0
  L49f637:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L49f646;  // @36_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_49f5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(esi));  // @38_49f5a0
  ecx = edx = 0;  // @39_49f5a0
  L49f646:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @41_49f5a0
  L49f649:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_49f5a0
  ecx = edi;  // @44_49f5a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6879012), (u32)(ecx), (u32)(4));  // @45_49f5a0
  ecx = edx = 0;  // @46_49f5a0
  eax = esi;  // @47_49f5a0
  SEH_LEAVE();  // @48_49f5a0
  return eax;  // @49_49f5a0
}
PCREG(49f5a0, lifted_49f5a0);

