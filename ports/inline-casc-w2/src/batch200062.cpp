// batch200062.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_423ff0_thiscall2(u32, u32) __asm__("ext_423ff0");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_44b610_thiscall1(u32) __asm__("ext_44b610");
extern "C" u32 THISCALL ext_460f90_thiscall1(u32) __asm__("ext_460f90");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4d6980_thiscall2(u32, u32) __asm__("ext_4d6980");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_50a380_thiscall1(u32) __asm__("ext_50a380");
extern "C" u32 THISCALL ext_53b600_thiscall1(u32) __asm__("ext_53b600");
extern "C" u32 THISCALL ext_53c590_thiscall3(u32, u32, u32) __asm__("ext_53c590");
extern "C" u32 THISCALL ext_54e100_thiscall1(u32) __asm__("ext_54e100");
extern "C" u32 THISCALL ext_5ebae0_thiscall2(u32, u32) __asm__("ext_5ebae0");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_5fd7c0_thiscall2(u32, u32) __asm__("ext_5fd7c0");
extern "C" u32 THISCALL ext_600c70_thiscall3(u32, u32, u32) __asm__("ext_600c70");
extern "C" u32 THISCALL ext_600d70_thiscall3(u32, u32, u32) __asm__("ext_600d70");
extern "C" u32 THISCALL ext_601380_thiscall1(u32) __asm__("ext_601380");
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_602260_thiscall2(u32, u32) __asm__("ext_602260");
extern "C" u32 THISCALL ext_603110_thiscall1(u32) __asm__("ext_603110");
extern "C" u32 THISCALL ext_6031e0_thiscall2(u32, u32) __asm__("ext_6031e0");
extern "C" u32 THISCALL ext_608e80_thiscall1(u32) __asm__("ext_608e80");
extern "C" u32 THISCALL ext_63ed10_thiscall1(u32) __asm__("ext_63ed10");
extern "C" u32 THISCALL ext_651880_thiscall1(u32) __asm__("ext_651880");
extern "C" u32 THISCALL ext_6590a0_thiscall2(u32, u32) __asm__("ext_6590a0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_45c510_cdecl1(...) __asm__("ext_45c510");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
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

extern "C" u32 THISCALL lifted_549df0(u32 ecx_in) {
  SEH_ENTER(0x66ac42);  // @h_549df0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_449fa0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66825f);  // @h_449fa0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_601ee0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d93f);  // @h_601ee0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_4373a0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x665a8f);  // @h_4373a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_449ed0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_449ed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_6012e0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_6012e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_435920(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66588e);  // @h_435920
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_441d90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_441d90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_5f97e0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_5f97e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_5379b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a892);  // @h_5379b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_4d5440(u32 ecx_in) {
  SEH_ENTER(0x669519);  // @h_4d5440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4d5440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4d5440
  { u32 v = (u32)((u32)(6907860)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4d5440
  reg.state = (s32)((u32)(0));  // @3_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 70), &v, sizeof v); }  // @4_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @5_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 78), &v, sizeof v); }  // @6_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @7_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @8_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @9_4d5440
  ecx = (u32)(esi + 94);  // @10_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @11_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @12_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @13_4d5440
  reg.state = (s32)((u32)(3));  // @14_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 106), &v, sizeof v); }  // @15_4d5440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @16_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @17_4d5440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @18_4d5440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @19_4d5440
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @20_4d5440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @21_4d5440
  eax = ext_4d6980_thiscall2(ecx, (u32)(256));  // @22_4d5440
  ecx = edx = 0;  // @23_4d5440
  { u32 v = (u32)((u32)(7240600)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @24_4d5440
  eax = esi;  // @25_4d5440
  SEH_LEAVE();  // @26_4d5440
  return eax;  // @27_4d5440
}
PCREG(4d5440, lifted_4d5440);

extern "C" u32 THISCALL lifted_421560(u32 ecx_in) {
  SEH_ENTER(0x66428b);  // @h_421560
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_421560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_421560
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8769), &v, sizeof v); }  // @2_421560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(0));  // @3_421560
  ecx = edx = 0;  // @4_421560
  ecx = (u32)(EBP - 144);  // @5_421560
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 9706), &v, sizeof v); }  // @6_421560
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782860));  // @7_421560
  ecx = edx = 0;  // @8_421560
  eax = (u32)(EBP - 144);  // @9_421560
  reg.state = (s32)((u32)(0));  // @10_421560
  ecx = (u32)(esi + 9030);  // @11_421560
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @12_421560
  ecx = edx = 0;  // @13_421560
  ecx = (u32)(EBP - 144);  // @14_421560
  eax = ext_4cbec0_thiscall1(ecx);  // @15_421560
  ecx = edx = 0;  // @16_421560
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 9706), &v, sizeof v); }  // @17_421560
  SEH_LEAVE();  // @18_421560
  ext_633654(G(u32, 0x6f5630));  // @19_421560
  return eax;  // @20_421560
}
PCREG(421560, lifted_421560);

extern "C" u32 THISCALL lifted_4c38e0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_4c38e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c38e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c38e0
  eax = ext_469870_thiscall1(ecx);  // @2_4c38e0
  ecx = edx = 0;  // @3_4c38e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c38e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c38e0
  eax = (u32)(esi + 138);  // @6_4c38e0
  { u32 v = (u32)((u32)(6897608)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4c38e0
  ecx = (u32)(EBP - 20);  // @8_4c38e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 126), &v, sizeof v); }  // @9_4c38e0
  reg.state = (s32)((u32)(0));  // @10_4c38e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @11_4c38e0
  if (eax == ecx) goto L4c3948;  // @12_4c38e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @13_4c38e0
  L4c3948:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4c38e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_4c38e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4c38e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6881000), (u32)(0), (u32)(6897740), (u32)(88));  // @18_4c38e0
  ecx = edx = 0;  // @19_4c38e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340872), &v, sizeof v); }  // @20_4c38e0
  eax = esi;  // @21_4c38e0
  SEH_LEAVE();  // @22_4c38e0
  return eax;  // @23_4c38e0
}
PCREG(4c38e0, lifted_4c38e0);

extern "C" u32 THISCALL lifted_5ec720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cb06);  // @h_5ec720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_5ec720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5ec720
  eax = ext_5ebae0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @2_5ec720
  ecx = edx = 0;  // @3_5ec720
  { u32 v = (u32)((u32)(7045396)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5ec720
  reg.state = (s32)((u32)(0));  // @5_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 203), &v, sizeof v); }  // @6_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 207), &v, sizeof v); }  // @7_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 211), &v, sizeof v); }  // @8_5ec720
  ecx = (u32)(esi + 118);  // @9_5ec720
  reg.state = (s32)((u32)(1));  // @10_5ec720
  eax = ext_4de7a0_thiscall1(ecx);  // @11_5ec720
  ecx = edx = 0;  // @12_5ec720
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 191), &v, sizeof v); }  // @13_5ec720
  eax = esi;  // @14_5ec720
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @15_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 195), &v, sizeof v); }  // @16_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 199), &v, sizeof v); }  // @17_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 175), &v, sizeof v); }  // @18_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 171), &v, sizeof v); }  // @19_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 167), &v, sizeof v); }  // @20_5ec720
  SEH_LEAVE();  // @21_5ec720
  return eax;  // @22_5ec720
}
PCREG(5ec720, lifted_5ec720);

extern "C" u32 THISCALL lifted_50a4a0(u32 ecx_in) {
  SEH_ENTER(0x669e17);  // @h_50a4a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_50a4a0
  eax = ext_41e290_cdecl1((u32)(16));  // @1_50a4a0
  ecx = edx = 0;  // @2_50a4a0
  esi = eax;  // @3_50a4a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_50a4a0
  reg.state = (s32)((u32)(0));  // @5_50a4a0
  if ((esi & esi) == 0) goto L50a51f;  // @6_50a4a0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @7_50a4a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_50a4a0
  reg.state = (s32)((u32)(1));  // @9_50a4a0
  { u32 v = (u32)((u32)(6934980)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_50a4a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @11_50a4a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344424), sizeof v); (u32)v; }) != (u32)(0)) goto L50a50c;  // @12_50a4a0
  ecx = esi;  // @13_50a4a0
  eax = ext_50a380_thiscall1(ecx);  // @14_50a4a0
  ecx = edx = 0;  // @15_50a4a0
  L50a50c:;
  eax = esi;  // @17_50a4a0
  SEH_LEAVE();  // @18_50a4a0
  return eax;  // @19_50a4a0
  L50a51f:;
  eax = 0;  // @21_50a4a0
  SEH_LEAVE();  // @22_50a4a0
  return eax;  // @23_50a4a0
}
PCREG(50a4a0, lifted_50a4a0);

extern "C" u32 THISCALL lifted_444120(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665f32);  // @h_444120
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_444120
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; }) != (u32)(0)) goto L444182;  // @1_444120
  eax = ext_41e290_cdecl1((u32)(172));  // @2_444120
  ecx = edx = 0;  // @3_444120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_444120
  reg.state = (s32)((u32)(0));  // @5_444120
  if ((eax & eax) == 0) goto L444173;  // @6_444120
  ecx = eax;  // @7_444120
  eax = ext_4ccba0_thiscall1(ecx);  // @8_444120
  ecx = edx = 0;  // @9_444120
  goto L444175;  // @10_444120
  L444173:;
  eax = 0;  // @12_444120
  L444175:;
  reg.state = (s32)((u32)(4294967295));  // @14_444120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @15_444120
  L444182:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; });  // @17_444120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_444120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @19_444120
  ecx = edx = 0;  // @20_444120
  if ((eax & eax) != 0) goto L4441a2;  // @21_444120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; });  // @22_444120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_444120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @24_444120
  ecx = edx = 0;  // @25_444120
  L4441a2:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @27_444120
  SEH_LEAVE();  // @28_444120
  return eax;  // @29_444120
}
PCREG(444120, lifted_444120);

