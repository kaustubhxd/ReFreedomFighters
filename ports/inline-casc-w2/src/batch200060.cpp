// batch200060.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4d3ab0(u32, u32);
extern "C" u32 STDCALL ext_54f870(u32, u32);
extern "C" u32 STDCALL ext_6014a0(u32);
extern "C" u32 STDCALL ext_63418c(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_423ff0(u32, u32);
extern "C" u32 THISCALL ext_4302d0(u32, u32, u32);
extern "C" u32 THISCALL ext_43de40(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_43e990(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_44b610(u32);
extern "C" u32 THISCALL ext_45c3e0(u32);
extern "C" u32 THISCALL ext_469870(u32);
extern "C" u32 THISCALL ext_46a4f0(u32);
extern "C" u32 THISCALL ext_480980(u32);
extern "C" u32 THISCALL ext_4876e0(u32, u32, u32);
extern "C" u32 THISCALL ext_4cbe80(u32, u32);
extern "C" u32 THISCALL ext_4cbeb0(u32);
extern "C" u32 THISCALL ext_4cbec0(u32);
extern "C" u32 THISCALL ext_4cbee0(u32, u32);
extern "C" u32 THISCALL ext_4cca60(u32, u32, u32);
extern "C" u32 THISCALL ext_4ccba0(u32);
extern "C" u32 THISCALL ext_4ccbe0(u32, u32, u32);
extern "C" u32 THISCALL ext_4d2280(u32);
extern "C" u32 THISCALL ext_4d2330(u32);
extern "C" u32 THISCALL ext_4d6980(u32, u32);
extern "C" u32 THISCALL ext_4d7540(u32);
extern "C" u32 THISCALL ext_4dc630(u32, u32, u32);
extern "C" u32 THISCALL ext_4e6b30(u32);
extern "C" u32 THISCALL ext_4e6bc0(u32);
extern "C" u32 THISCALL ext_4e6c10(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_50a380(u32);
extern "C" u32 THISCALL ext_5167d0(u32);
extern "C" u32 THISCALL ext_534be0(u32);
extern "C" u32 THISCALL ext_5421b0(u32);
extern "C" u32 THISCALL ext_549280(u32, u32);
extern "C" u32 THISCALL ext_54ccf0(u32);
extern "C" u32 THISCALL ext_54e100(u32);
extern "C" u32 THISCALL ext_59a9b0(u32, u32);
extern "C" u32 THISCALL ext_5f10c0(u32, u32);
extern "C" u32 THISCALL ext_5f4630(u32);
extern "C" u32 THISCALL ext_5f5490(u32, u32, u32);
extern "C" u32 THISCALL ext_600c70(u32, u32, u32);
extern "C" u32 THISCALL ext_600d70(u32, u32, u32);
extern "C" u32 THISCALL ext_6033c0(u32, u32);
extern "C" u32 THISCALL ext_603500(u32, u32);
extern "C" u32 THISCALL ext_603850(u32);
extern "C" u32 THISCALL ext_606220(u32);
extern "C" u32 THISCALL ext_606ee0(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_6071c0(u32);
extern "C" u32 THISCALL ext_607f60(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_608e80(u32);
extern "C" u32 THISCALL ext_61ba30(u32, u32);
extern "C" u32 THISCALL ext_635490(u32);
extern "C" u32 THISCALL ext_651880(u32);
extern "C" u32 THISCALL ext_659330(u32, u32, u32);
extern "C" u32 ext_41e290(u32);
extern "C" u32 ext_41e2c0(u32);
extern "C" u32 ext_4690b0(u32, u32);
extern "C" u32 ext_634273(u32, u32);
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4311f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665381);  // @h_4311f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4311f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_4311f0
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L431251;  // @2_4311f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_4311f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_4311f0
  reg.state = (s32)((u32)(0));  // @5_4311f0
  if ((eax & eax) == 0) goto L43123b;  // @6_4311f0
  ecx = eax;  // @7_4311f0
  eax = ext_5f10c0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @8_4311f0
  ecx = edx = 0;  // @9_4311f0
  L43123b:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @11_4311f0
  SEH_LEAVE();  // @12_4311f0
  return eax;  // @13_4311f0
  L431251:;
  eax = ext_4302d0(ecx, (u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @15_4311f0
  ecx = edx = 0;  // @16_4311f0
  SEH_LEAVE();  // @17_4311f0
  return eax;  // @18_4311f0
}
PCREG(4311f0, lifted_4311f0);

extern "C" u32 THISCALL lifted_5329f0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_5329f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5329f0
  { u32 v = (u32)((u32)(6952336)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_5329f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_5329f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5329f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21618), sizeof v); (u32)v; }));  // @4_5329f0
  ecx = edx = 0;  // @5_5329f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21618), sizeof v); (u32)v; });  // @6_5329f0
  if ((ecx & ecx) == 0) goto L532a3f;  // @7_5329f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5329f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @9_5329f0
  ecx = edx = 0;  // @10_5329f0
  L532a3f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_5329f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_5329f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21622), sizeof v); (u32)v; }));  // @14_5329f0
  ecx = edx = 0;  // @15_5329f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21622), sizeof v); (u32)v; });  // @16_5329f0
  if ((ecx & ecx) == 0) goto L532a63;  // @17_5329f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5329f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @19_5329f0
  ecx = edx = 0;  // @20_5329f0
  L532a63:;
  ecx = esi;  // @22_5329f0
  eax = ext_534be0(ecx);  // @23_5329f0
  ecx = edx = 0;  // @24_5329f0
  SEH_LEAVE();  // @25_5329f0
  return eax;  // @26_5329f0
}
PCREG(5329f0, lifted_5329f0);

extern "C" u32 THISCALL lifted_43b710(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665d0f);  // @h_43b710
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_43b710
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_43b710
  eax = ext_61ba30(ecx, (u32)(1));  // @2_43b710
  ecx = edx = 0;  // @3_43b710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_43b710
  ecx = (u32)(esi + 16);  // @5_43b710
  reg.state = (s32)((u32)(0));  // @6_43b710
  { u32 v = (u32)((u32)(6798668)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_43b710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_43b710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @9_43b710
  eax = ext_4cbeb0(ecx);  // @10_43b710
  ecx = edx = 0;  // @11_43b710
  ecx = (u32)(esi + 195);  // @12_43b710
  reg.state = (s32)((u32)(1));  // @13_43b710
  eax = ext_4cbeb0(ecx);  // @14_43b710
  ecx = edx = 0;  // @15_43b710
  ecx = (u32)(esi + 323);  // @16_43b710
  reg.state = (s32)((u32)(2));  // @17_43b710
  eax = ext_4cbe80(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @18_43b710
  ecx = edx = 0;  // @19_43b710
  ecx = (u32)(esi + 451);  // @20_43b710
  reg.state = (s32)((u32)(3));  // @21_43b710
  eax = ext_4cbeb0(ecx);  // @22_43b710
  ecx = edx = 0;  // @23_43b710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 583), &v, sizeof v); }  // @24_43b710
  eax = esi;  // @25_43b710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 579), &v, sizeof v); }  // @26_43b710
  SEH_LEAVE();  // @27_43b710
  return eax;  // @28_43b710
}
PCREG(43b710, lifted_43b710);

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
  eax = ext_6033c0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @7_603500
  ecx = edx = 0;  // @8_603500
  eax = (u32)(EBP - 24);  // @9_603500
  reg.state = (s32)((u32)(1));  // @10_603500
  ecx = (u32)(ebx + 12);  // @11_603500
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @12_603500
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_603500
  eax = ext_5f5490(ecx, (u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @14_603500
  ecx = edx = 0;  // @15_603500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489176), sizeof v); (u32)v; }) != (u32)(0)) goto L603580;  // @16_603500
  ecx = ebx;  // @17_603500
  eax = ext_603850(ecx);  // @18_603500
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
  eax = ext_41e290((u32)(750));  // @1_549df0
  ecx = edx = 0;  // @2_549df0
  esi = eax;  // @3_549df0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_549df0
  reg.state = (s32)((u32)(0));  // @5_549df0
  if ((esi & esi) == 0) goto L549e43;  // @6_549df0
  ecx = esi;  // @7_549df0
  eax = ext_54e100(ecx);  // @8_549df0
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

extern "C" u32 THISCALL lifted_6024a0(u32 ecx_in) {
  SEH_ENTER(0x66d9bb);  // @h_6024a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_6024a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6024a0
  esi = (u32)(edi + 1);  // @2_6024a0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @3_6024a0
  ecx = esi;  // @4_6024a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_6024a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_6024a0
  eax = ext_6014a0((u32)(29));  // @7_6024a0
  ecx = edx = 0;  // @8_6024a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_6024a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @10_6024a0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @11_6024a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_6024a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @13_6024a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_6024a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @15_6024a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_6024a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @17_6024a0
  ecx = (u32)(edi + 10);  // @18_6024a0
  reg.state = (s32)((u32)(0));  // @19_6024a0
  eax = ext_606220(ecx);  // @20_6024a0
  ecx = edx = 0;  // @21_6024a0
  eax = edi;  // @22_6024a0
  SEH_LEAVE();  // @23_6024a0
  return eax;  // @24_6024a0
}
PCREG(6024a0, lifted_6024a0);

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
  eax = ext_54f870((u32)(edx), (u32)(eax));  // @8_42ba60
  ecx = edx = 0;  // @9_42ba60
  L42baa5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_42ba60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @12_42ba60
  eax = (eax - ecx);  // @13_42ba60
  reg.state = (s32)((u32)(1));  // @14_42ba60
  if ((ecx & ecx) == 0) goto L42bac4;  // @15_42ba60
  if ((eax & eax) == 0) goto L42bac4;  // @16_42ba60
  ecx = esi;  // @17_42ba60
  eax = ext_54f870((u32)(ecx), (u32)(eax));  // @18_42ba60
  ecx = edx = 0;  // @19_42ba60
  L42bac4:;
  SEH_LEAVE();  // @21_42ba60
  return eax;  // @22_42ba60
}
PCREG(42ba60, lifted_42ba60);

extern "C" u32 THISCALL lifted_43e190(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666568);  // @h_43e190
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_43e190
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_43e190
  eax = ext_43de40(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_43e190
  ecx = edx = 0;  // @3_43e190
  { u32 v = (u32)((u32)(6800836)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_43e190
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_43e190
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @6_43e190
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @7_43e190
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @8_43e190
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @9_43e190
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @10_43e190
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @11_43e190
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @12_43e190
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @13_43e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @14_43e190
  reg.state = (s32)((u32)(0));  // @15_43e190
  { u32 v = (u32)((u32)(15020851)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @16_43e190
  { u32 v = (u32)((u32)(15066597)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @17_43e190
  eax = ext_4dc630(ecx, (u32)(262144), (u32)(0));  // @18_43e190
  ecx = edx = 0;  // @19_43e190
  eax = esi;  // @20_43e190
  SEH_LEAVE();  // @21_43e190
  return eax;  // @22_43e190
}
PCREG(43e190, lifted_43e190);

extern "C" u32 THISCALL lifted_4c38e0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_4c38e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c38e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c38e0
  eax = ext_469870(ecx);  // @2_4c38e0
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

extern "C" u32 THISCALL lifted_5c4490(u32 ecx_in) {
  SEH_ENTER(0x66c831);  // @h_5c4490
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5c4490
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5c4490
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @2_5c4490
  reg.state = (s32)((u32)(0));  // @3_5c4490
  if ((esi & esi) == 0) goto L5c4514;  // @4_5c4490
  eax = ext_469870(ecx);  // @5_5c4490
  ecx = edx = 0;  // @6_5c4490
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @7_5c4490
  eax = esi;  // @8_5c4490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @9_5c4490
  { u32 v = (u32)((u32)(7028872)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_5c4490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @11_5c4490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @12_5c4490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @13_5c4490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @14_5c4490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @15_5c4490
  SEH_LEAVE();  // @16_5c4490
  return eax;  // @17_5c4490
  L5c4514:;
  eax = 0;  // @19_5c4490
  SEH_LEAVE();  // @20_5c4490
  return eax;  // @21_5c4490
}
PCREG(5c4490, lifted_5c4490);

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
  eax = ext_5f10c0(ecx, (u32)(esi));  // @10_42b160
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
  eax = ext_634273((u32)(esi), (u32)(36));  // @17_4cd240
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
  eax = ext_659330(ecx, (u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 47528), sizeof v); (u32)v; }));  // @15_616620
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

extern "C" u32 THISCALL lifted_4e3e70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6697ab);  // @h_4e3e70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4e3e70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4e3e70
  ecx = (u32)(edi + 4);  // @2_4e3e70
  eax = ext_4e6b30(ecx);  // @3_4e3e70
  ecx = edx = 0;  // @4_4e3e70
  ecx = (u32)(edi + 4);  // @5_4e3e70
  reg.state = (s32)((u32)(0));  // @6_4e3e70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 25), &v, sizeof v); }  // @7_4e3e70
  eax = ext_4e6c10(ecx, (u32)(16), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(1));  // @8_4e3e70
  ecx = edx = 0;  // @9_4e3e70
  ecx = (u32)(edi + 4);  // @10_4e3e70
  eax = ext_4e6bc0(ecx);  // @11_4e3e70
  ecx = edx = 0;  // @12_4e3e70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @13_4e3e70
  ecx = 0;  // @14_4e3e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @15_4e3e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @16_4e3e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @17_4e3e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @18_4e3e70
  eax = edi;  // @19_4e3e70
  { u32 v = (u32)((u32)(1040187392)); __builtin_memcpy((void *)(u32)(edi + 29), &v, sizeof v); }  // @20_4e3e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 33), &v, sizeof v); }  // @21_4e3e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 37), &v, sizeof v); }  // @22_4e3e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 41), &v, sizeof v); }  // @23_4e3e70
  SEH_LEAVE();  // @24_4e3e70
  return eax;  // @25_4e3e70
}
PCREG(4e3e70, lifted_4e3e70);

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
  eax = ext_41e290((u32)(28));  // @2_449fa0
  ecx = edx = 0;  // @3_449fa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_449fa0
  reg.state = (s32)((u32)(0));  // @5_449fa0
  if ((eax & eax) == 0) goto L449ff1;  // @6_449fa0
  ecx = eax;  // @7_449fa0
  eax = ext_4ccbe0(ecx, (u32)(2), (u32)(1));  // @8_449fa0
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
  eax = ext_44b610(ecx);  // @14_44c060
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

extern "C" u32 THISCALL lifted_4d5440(u32 ecx_in) {
  SEH_ENTER(0x669519);  // @h_4d5440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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
  eax = ext_4d6980(ecx, (u32)(256));  // @22_4d5440
  ecx = edx = 0;  // @23_4d5440
  { u32 v = (u32)((u32)(7240600)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @24_4d5440
  eax = esi;  // @25_4d5440
  SEH_LEAVE();  // @26_4d5440
  return eax;  // @27_4d5440
}
PCREG(4d5440, lifted_4d5440);

extern "C" u32 THISCALL lifted_45c5f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_45c5f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_45c5f0
  eax = ext_45c3e0(ecx);  // @1_45c5f0
  ecx = edx = 0;  // @2_45c5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_45c5f0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L45c65f;  // @4_45c5f0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L45c654;  // @5_45c5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_45c5f0
  reg.state = (s32)((u32)(0));  // @7_45c5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_45c5f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @9_45c5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_45c5f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(esi));  // @11_45c5f0
  ecx = edx = 0;  // @12_45c5f0
  eax = esi;  // @13_45c5f0
  SEH_LEAVE();  // @14_45c5f0
  return eax;  // @15_45c5f0
  L45c654:;
  eax = ext_4690b0((u32)(esi), (u32)(24));  // @17_45c5f0
  ecx = edx = 0;  // @18_45c5f0
  L45c65f:;
  eax = esi;  // @20_45c5f0
  SEH_LEAVE();  // @21_45c5f0
  return eax;  // @22_45c5f0
}
PCREG(45c5f0, lifted_45c5f0);

extern "C" u32 THISCALL lifted_4c32a0(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_4c32a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c32a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c32a0
  eax = ext_469870(ecx);  // @2_4c32a0
  ecx = edx = 0;  // @3_4c32a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c32a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c32a0
  reg.state = (s32)((u32)(0));  // @6_4c32a0
  { u32 v = (u32)((u32)(6897212)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4c32a0
  eax = ext_41e290((u32)(28));  // @8_4c32a0
  ecx = edx = 0;  // @9_4c32a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_4c32a0
  reg.state = (s32)((u32)(1));  // @11_4c32a0
  if ((eax & eax) == 0) goto L4c330a;  // @12_4c32a0
  ecx = eax;  // @13_4c32a0
  eax = ext_4ccbe0(ecx, (u32)(32), (u32)(0));  // @14_4c32a0
  ecx = edx = 0;  // @15_4c32a0
  goto L4c330c;  // @16_4c32a0
  L4c330a:;
  eax = 0;  // @18_4c32a0
  L4c330c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @20_4c32a0
  eax = esi;  // @21_4c32a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @22_4c32a0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @23_4c32a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @24_4c32a0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @25_4c32a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @26_4c32a0
  SEH_LEAVE();  // @27_4c32a0
  return eax;  // @28_4c32a0
}
PCREG(4c32a0, lifted_4c32a0);

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
  eax = ext_6071c0(ecx);  // @9_606a70
  ecx = edx = 0;  // @10_606a70
  esi = eax;  // @11_606a70
  ecx = (u32)(ebx + 3);  // @12_606a70
  eax = ext_59a9b0(ecx, (u32)(esi));  // @13_606a70
  ecx = edx = 0;  // @14_606a70
  eax = (u32)(EBP - 16);  // @15_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @16_606a70
  ecx = (u32)(ebx + 3);  // @17_606a70
  eax = ext_606ee0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7), sizeof v); (u32)v; }), (u32)(esi), (u32)(eax));  // @18_606a70
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
  eax = ext_41e290((u32)(4));  // @1_601ee0
  ecx = edx = 0;  // @2_601ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601ee0
  reg.state = (s32)((u32)(0));  // @4_601ee0
  if ((eax & eax) == 0) goto L601f30;  // @5_601ee0
  ecx = eax;  // @6_601ee0
  eax = ext_600c70(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_601ee0
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
  eax = ext_5f4630(ecx);  // @18_601ee0
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
  eax = ext_41e290((u32)(4));  // @1_601f70
  ecx = edx = 0;  // @2_601f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601f70
  reg.state = (s32)((u32)(0));  // @4_601f70
  if ((eax & eax) == 0) goto L601fc0;  // @5_601f70
  ecx = eax;  // @6_601f70
  eax = ext_600d70(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_601f70
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
  eax = ext_5f4630(ecx);  // @18_601f70
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

extern "C" u32 THISCALL lifted_444120(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665f32);  // @h_444120
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_444120
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; }) != (u32)(0)) goto L444182;  // @1_444120
  eax = ext_41e290((u32)(172));  // @2_444120
  ecx = edx = 0;  // @3_444120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_444120
  reg.state = (s32)((u32)(0));  // @5_444120
  if ((eax & eax) == 0) goto L444173;  // @6_444120
  ecx = eax;  // @7_444120
  eax = ext_4ccba0(ecx);  // @8_444120
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

extern "C" u32 THISCALL lifted_529800(u32 ecx_in) {
  SEH_ENTER(0x66a53b);  // @h_529800
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_529800
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_529800
  esi = (u32)(edi + 48);  // @2_529800
  { u32 v = (u32)((u32)(6949860)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @3_529800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_529800
  ecx = (u32)(esi + 61);  // @5_529800
  { u32 v = (u32)((u32)(6949848)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_529800
  eax = ext_5167d0(ecx);  // @7_529800
  ecx = edx = 0;  // @8_529800
  ecx = (u32)(esi + 182);  // @9_529800
  reg.state = (s32)((u32)(0));  // @10_529800
  eax = ext_5167d0(ecx);  // @11_529800
  ecx = edx = 0;  // @12_529800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @13_529800
  eax = edi;  // @14_529800
  { u32 v = (u32)((u32)(3287941120)); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @15_529800
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 57), &v, sizeof v); }  // @16_529800
  { u32 v = (u32)((u32)(1128792064)); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @17_529800
  { u32 v = (u32)((u32)(3284664320)); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @18_529800
  { u32 v = (u32)((u32)(3229614080)); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @19_529800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @20_529800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @21_529800
  { u32 v = (u32)((u32)(3287941120)); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @22_529800
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @23_529800
  { u32 v = (u32)((u32)(1128792064)); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @24_529800
  { u32 v = (u32)((u32)(3284664320)); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @25_529800
  { u32 v = (u32)((u32)(3229614080)); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @26_529800
  SEH_LEAVE();  // @27_529800
  return eax;  // @28_529800
}
PCREG(529800, lifted_529800);

extern "C" u32 THISCALL lifted_45c560(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669286);  // @h_45c560
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_45c560
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_45c560
  if ((edi & edi) == 0) goto L45c5bd;  // @2_45c560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @3_45c560
  reg.state = (s32)((u32)(0));  // @4_45c560
  if ((ecx & ecx) == 0) goto L45c5ab;  // @5_45c560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @6_45c560
  if ((edx & edx) == 0) goto L45c5ab;  // @7_45c560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_45c560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @9_45c560
  ecx = edx = 0;  // @10_45c560
  L45c5ab:;
  eax = ext_634273((u32)(edi), (u32)(16));  // @12_45c560
  ecx = edx = 0;  // @13_45c560
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_45c560
  L45c5bd:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L45c5ce;  // @16_45c560
  eax = ext_634273((u32)(esi), (u32)(8));  // @17_45c560
  ecx = edx = 0;  // @18_45c560
  L45c5ce:;
  eax = esi;  // @20_45c560
  SEH_LEAVE();  // @21_45c560
  return eax;  // @22_45c560
}
PCREG(45c560, lifted_45c560);

extern "C" u32 THISCALL lifted_480980(u32 ecx_in) {
  SEH_ENTER(0x66825f);  // @h_480980
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_480980
  { u32 v = (u32)((u32)(6862340)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_480980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @2_480980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @3_480980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @4_480980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @5_480980
  eax = ext_41e290((u32)(28));  // @6_480980
  ecx = edx = 0;  // @7_480980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @8_480980
  reg.state = (s32)((u32)(0));  // @9_480980
  if ((eax & eax) == 0) goto L480a00;  // @10_480980
  ecx = eax;  // @11_480980
  eax = ext_4ccbe0(ecx, (u32)(8), (u32)(2));  // @12_480980
  ecx = edx = 0;  // @13_480980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @14_480980
  eax = esi;  // @15_480980
  SEH_LEAVE();  // @16_480980
  return eax;  // @17_480980
  L480a00:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @19_480980
  eax = esi;  // @20_480980
  SEH_LEAVE();  // @21_480980
  return eax;  // @22_480980
}
PCREG(480980, lifted_480980);

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
  eax = ext_41e290((u32)(40));  // @12_4b6d70
  ecx = edx = 0;  // @13_4b6d70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_4b6d70
  reg.state = (s32)((u32)(0));  // @15_4b6d70
  if ((eax & eax) == 0) goto L4b6dd8;  // @16_4b6d70
  ecx = eax;  // @17_4b6d70
  eax = ext_4cca60(ecx, (u32)(4), (u32)(2));  // @18_4b6d70
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

extern "C" u32 THISCALL lifted_4acde0(u32 ecx_in) {
  SEH_ENTER(0x668742);  // @h_4acde0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4acde0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4acde0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @2_4acde0
  reg.state = (s32)((u32)(0));  // @3_4acde0
  if ((esi & esi) == 0) goto L4ace6b;  // @4_4acde0
  eax = ext_469870(ecx);  // @5_4acde0
  ecx = edx = 0;  // @6_4acde0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @7_4acde0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @8_4acde0
  ecx = (u32)(esi + 110);  // @9_4acde0
  reg.state = (s32)((u32)(1));  // @10_4acde0
  { u32 v = (u32)((u32)(6877600)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_4acde0
  eax = ext_4ccba0(ecx);  // @12_4acde0
  ecx = edx = 0;  // @13_4acde0
  ecx = (u32)(esi + 282);  // @14_4acde0
  reg.state = (s32)((u32)(2));  // @15_4acde0
  eax = ext_4ccba0(ecx);  // @16_4acde0
  ecx = edx = 0;  // @17_4acde0
  ecx = (u32)(esi + 454);  // @18_4acde0
  reg.state = (s32)((u32)(3));  // @19_4acde0
  eax = ext_4ccba0(ecx);  // @20_4acde0
  ecx = edx = 0;  // @21_4acde0
  eax = esi;  // @22_4acde0
  SEH_LEAVE();  // @23_4acde0
  return eax;  // @24_4acde0
  L4ace6b:;
  eax = 0;  // @26_4acde0
  SEH_LEAVE();  // @27_4acde0
  return eax;  // @28_4acde0
}
PCREG(4acde0, lifted_4acde0);

extern "C" u32 THISCALL lifted_53cfa0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_53cfa0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_53cfa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @1_53cfa0
  { u32 v = (u32)((u32)(6958104)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_53cfa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @3_53cfa0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) == 0) goto L53cff7;  // @4_53cfa0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 98), sizeof v); (u32)v; });  // @5_53cfa0
  if ((edi & edi) == 0) goto L53cff7;  // @6_53cfa0
  ecx = edi;  // @7_53cfa0
  eax = ext_635490(ecx);  // @8_53cfa0
  ecx = edx = 0;  // @9_53cfa0
  eax = ext_634273((u32)(edi), (u32)(147));  // @10_53cfa0
  ecx = edx = 0;  // @11_53cfa0
  L53cff7:;
  ecx = (u32)(esi + 106);  // @13_53cfa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 207), &v, sizeof v); }  // @14_53cfa0
  eax = ext_5421b0(ecx);  // @15_53cfa0
  ecx = edx = 0;  // @16_53cfa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @17_53cfa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @18_53cfa0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_53cfa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_53cfa0
  reg.state = (s32)((u32)(0));  // @21_53cfa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @22_53cfa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_53cfa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @24_53cfa0
  ecx = edx = 0;  // @25_53cfa0
  SEH_LEAVE();  // @26_53cfa0
  return eax;  // @27_53cfa0
}
PCREG(53cfa0, lifted_53cfa0);

extern "C" u32 STDCALL lifted_601d80(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ext_41e290((u32)(42));  // @0_601d80
  ecx = edx = 0;  // @1_601d80
  esi = eax;  // @2_601d80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601d80
  reg.state = (s32)((u32)(0));  // @4_601d80
  if ((esi & esi) == 0) goto L601df0;  // @5_601d80
  ecx = esi;  // @6_601d80
  eax = ext_603500(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_601d80
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
  eax = ext_41e290((u32)(42));  // @0_601e20
  ecx = edx = 0;  // @1_601e20
  esi = eax;  // @2_601e20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601e20
  reg.state = (s32)((u32)(0));  // @4_601e20
  if ((esi & esi) == 0) goto L601e90;  // @5_601e20
  ecx = esi;  // @6_601e20
  eax = ext_603500(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_601e20
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

extern "C" u32 THISCALL lifted_4b8610(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_4b8610
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4b8610
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4b8610
  eax = ext_469870(ecx);  // @2_4b8610
  ecx = edx = 0;  // @3_4b8610
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b8610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4b8610
  reg.state = (s32)((u32)(0));  // @6_4b8610
  { u32 v = (u32)((u32)(6891676)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4b8610
  eax = ext_41e290((u32)(28));  // @8_4b8610
  ecx = edx = 0;  // @9_4b8610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_4b8610
  reg.state = (s32)((u32)(1));  // @11_4b8610
  if ((eax & eax) == 0) goto L4b868d;  // @12_4b8610
  ecx = eax;  // @13_4b8610
  eax = ext_4ccbe0(ecx, (u32)(8), (u32)(0));  // @14_4b8610
  ecx = edx = 0;  // @15_4b8610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @16_4b8610
  eax = esi;  // @17_4b8610
  SEH_LEAVE();  // @18_4b8610
  return eax;  // @19_4b8610
  L4b868d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @21_4b8610
  eax = esi;  // @22_4b8610
  SEH_LEAVE();  // @23_4b8610
  return eax;  // @24_4b8610
}
PCREG(4b8610, lifted_4b8610);

extern "C" u32 THISCALL lifted_4c52f0(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_4c52f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c52f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c52f0
  eax = ext_469870(ecx);  // @2_4c52f0
  ecx = edx = 0;  // @3_4c52f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c52f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c52f0
  reg.state = (s32)((u32)(0));  // @6_4c52f0
  { u32 v = (u32)((u32)(6898192)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4c52f0
  eax = ext_41e290((u32)(28));  // @8_4c52f0
  ecx = edx = 0;  // @9_4c52f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_4c52f0
  reg.state = (s32)((u32)(1));  // @11_4c52f0
  if ((eax & eax) == 0) goto L4c536d;  // @12_4c52f0
  ecx = eax;  // @13_4c52f0
  eax = ext_4ccbe0(ecx, (u32)(2), (u32)(0));  // @14_4c52f0
  ecx = edx = 0;  // @15_4c52f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @16_4c52f0
  eax = esi;  // @17_4c52f0
  SEH_LEAVE();  // @18_4c52f0
  return eax;  // @19_4c52f0
  L4c536d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @21_4c52f0
  eax = esi;  // @22_4c52f0
  SEH_LEAVE();  // @23_4c52f0
  return eax;  // @24_4c52f0
}
PCREG(4c52f0, lifted_4c52f0);

extern "C" u32 THISCALL lifted_5c3e70(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_5c3e70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5c3e70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5c3e70
  eax = ext_469870(ecx);  // @2_5c3e70
  ecx = edx = 0;  // @3_5c3e70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5c3e70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5c3e70
  reg.state = (s32)((u32)(0));  // @6_5c3e70
  { u32 v = (u32)((u32)(7028572)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5c3e70
  eax = ext_41e290((u32)(28));  // @8_5c3e70
  ecx = edx = 0;  // @9_5c3e70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_5c3e70
  reg.state = (s32)((u32)(1));  // @11_5c3e70
  if ((eax & eax) == 0) goto L5c3eed;  // @12_5c3e70
  ecx = eax;  // @13_5c3e70
  eax = ext_4ccbe0(ecx, (u32)(1), (u32)(0));  // @14_5c3e70
  ecx = edx = 0;  // @15_5c3e70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @16_5c3e70
  eax = esi;  // @17_5c3e70
  SEH_LEAVE();  // @18_5c3e70
  return eax;  // @19_5c3e70
  L5c3eed:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @21_5c3e70
  eax = esi;  // @22_5c3e70
  SEH_LEAVE();  // @23_5c3e70
  return eax;  // @24_5c3e70
}
PCREG(5c3e70, lifted_5c3e70);

extern "C" u32 THISCALL lifted_54ae00(u32 ecx_in) {
  SEH_ENTER(0x66ac72);  // @h_54ae00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_54ae00
  eax = ext_41e290((u32)(25592));  // @1_54ae00
  ecx = edx = 0;  // @2_54ae00
  esi = eax;  // @3_54ae00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_54ae00
  reg.state = (s32)((u32)(0));  // @5_54ae00
  if ((esi & esi) == 0) goto L54ae8d;  // @6_54ae00
  ecx = esi;  // @7_54ae00
  eax = ext_549280(ecx, (u32)(edi));  // @8_54ae00
  ecx = edx = 0;  // @9_54ae00
  { u32 v = (u32)((u32)(6961080)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_54ae00
  eax = esi;  // @11_54ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25580), &v, sizeof v); }  // @12_54ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25584), &v, sizeof v); }  // @13_54ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25588), &v, sizeof v); }  // @14_54ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25576), &v, sizeof v); }  // @15_54ae00
  SEH_LEAVE();  // @16_54ae00
  return eax;  // @17_54ae00
  L54ae8d:;
  eax = 0;  // @19_54ae00
  SEH_LEAVE();  // @20_54ae00
  return eax;  // @21_54ae00
}
PCREG(54ae00, lifted_54ae00);

extern "C" u32 THISCALL lifted_54ac30(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_54ac30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_54ac30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @1_54ac30
  { u32 v = (u32)((u32)(6961212)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_54ac30
  if ((ecx & ecx) == 0) goto L54ac7c;  // @3_54ac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_54ac30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @5_54ac30
  ecx = edx = 0;  // @6_54ac30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @7_54ac30
  if ((ecx & ecx) == 0) goto L54ac75;  // @8_54ac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_54ac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @10_54ac30
  ecx = edx = 0;  // @11_54ac30
  L54ac75:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @13_54ac30
  L54ac7c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @15_54ac30
  if ((ecx & ecx) == 0) goto L54ac89;  // @16_54ac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_54ac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_54ac30
  ecx = edx = 0;  // @19_54ac30
  L54ac89:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @21_54ac30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @22_54ac30
  if ((ecx & ecx) == 0) goto L54ac9d;  // @23_54ac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_54ac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @25_54ac30
  ecx = edx = 0;  // @26_54ac30
  L54ac9d:;
  ecx = esi;  // @28_54ac30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @29_54ac30
  eax = ext_54ccf0(ecx);  // @30_54ac30
  ecx = edx = 0;  // @31_54ac30
  SEH_LEAVE();  // @32_54ac30
  return eax;  // @33_54ac30
}
PCREG(54ac30, lifted_54ac30);

extern "C" u32 THISCALL lifted_5dd6b0(u32 ecx_in) {
  SEH_ENTER(0x668a89);  // @h_5dd6b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5dd6b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5dd6b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @2_5dd6b0
  reg.state = (s32)((u32)(0));  // @3_5dd6b0
  if ((esi & esi) == 0) goto L5dd73a;  // @4_5dd6b0
  eax = ext_469870(ecx);  // @5_5dd6b0
  ecx = edx = 0;  // @6_5dd6b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @7_5dd6b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @8_5dd6b0
  { u32 v = (u32)((u32)(7040736)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_5dd6b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_5dd6b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @11_5dd6b0
  reg.state = (s32)((u32)(1));  // @12_5dd6b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_5dd6b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 276)))(ecx, (u32)(7040920), (u32)(0), (u32)(7040868), (u32)(21));  // @14_5dd6b0
  ecx = edx = 0;  // @15_5dd6b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @16_5dd6b0
  eax = esi;  // @17_5dd6b0
  SEH_LEAVE();  // @18_5dd6b0
  return eax;  // @19_5dd6b0
  L5dd73a:;
  eax = 0;  // @21_5dd6b0
  SEH_LEAVE();  // @22_5dd6b0
  return eax;  // @23_5dd6b0
}
PCREG(5dd6b0, lifted_5dd6b0);

extern "C" u32 THISCALL lifted_5e0e10(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66c922);  // @h_5e0e10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_5e0e10
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5e0e10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5e0e10
  eax = ext_4876e0(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @3_5e0e10
  ecx = edx = 0;  // @4_5e0e10
  ecx = (u32)(edi + 979);  // @5_5e0e10
  reg.state = (s32)((u32)(0));  // @6_5e0e10
  { u32 v = (u32)((u32)(7042464)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_5e0e10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 877), &v, sizeof v); }  // @8_5e0e10
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 881), &v, sizeof v); }  // @9_5e0e10
  eax = ext_480980(ecx);  // @10_5e0e10
  ecx = edx = 0;  // @11_5e0e10
  ecx = (u32)(edi + 1003);  // @12_5e0e10
  reg.state = (s32)((u32)(1));  // @13_5e0e10
  eax = ext_480980(ecx);  // @14_5e0e10
  ecx = edx = 0;  // @15_5e0e10
  ecx = (u32)(edi + 1195);  // @16_5e0e10
  reg.state = (s32)((u32)(2));  // @17_5e0e10
  eax = ext_480980(ecx);  // @18_5e0e10
  ecx = edx = 0;  // @19_5e0e10
  ecx = (u32)(edi + 1315);  // @20_5e0e10
  reg.state = (s32)((u32)(3));  // @21_5e0e10
  eax = ext_480980(ecx);  // @22_5e0e10
  ecx = edx = 0;  // @23_5e0e10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1339), &v, sizeof v); }  // @24_5e0e10
  eax = edi;  // @25_5e0e10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1355), &v, sizeof v); }  // @26_5e0e10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1343), &v, sizeof v); }  // @27_5e0e10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1347), &v, sizeof v); }  // @28_5e0e10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1351), &v, sizeof v); }  // @29_5e0e10
  SEH_LEAVE();  // @30_5e0e10
  return eax;  // @31_5e0e10
}
PCREG(5e0e10, lifted_5e0e10);

extern "C" u32 THISCALL lifted_607b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e0b2);  // @h_607b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_607b50
  eax = ext_41e290((u32)(5366));  // @1_607b50
  ecx = edx = 0;  // @2_607b50
  ecx = eax;  // @3_607b50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_607b50
  reg.state = (s32)((u32)(0));  // @5_607b50
  if ((ecx & ecx) == 0) goto L607bae;  // @6_607b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_607b50
  eax = ext_607f60(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2511), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }));  // @8_607b50
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
  eax = ext_608e80(ecx);  // @3_608080
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
  eax = ext_651880(ecx);  // @32_608080
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
  eax = ext_4cbe80(ecx, (u32)(ecx));  // @6_424080
  ecx = edx = 0;  // @7_424080
  eax = (u32)(EBP - 144);  // @8_424080
  reg.state = (s32)((u32)(0));  // @9_424080
  ecx = (u32)(esi + 9563);  // @10_424080
  eax = ext_4cbee0(ecx, (u32)(eax));  // @11_424080
  ecx = edx = 0;  // @12_424080
  ecx = (u32)(EBP - 144);  // @13_424080
  eax = ext_4cbec0(ecx);  // @14_424080
  ecx = edx = 0;  // @15_424080
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6975), &v, sizeof v); }  // @16_424080
  goto L42410f;  // @17_424080
  L4240fa:;
  if ((eax & eax) == 0) goto L42410f;  // @19_424080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L42410f;  // @20_424080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_424080
  eax = ext_423ff0(ecx, (u32)(eax));  // @22_424080
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
  eax = ext_4d2280(ecx);  // @3_473a70
  ecx = edx = 0;  // @4_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_473a70
  reg.state = (s32)((u32)(0));  // @6_473a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_473a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @9_473a70
  ecx = edx = 0;  // @10_473a70
  ecx = (u32)(EBP - 16596);  // @11_473a70
  eax = ext_4d3ab0((u32)(6851120), (u32)(eax));  // @12_473a70
  ecx = edx = 0;  // @13_473a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_473a70
  eax = (u32)(EBP - 16596);  // @15_473a70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338404), sizeof v); (u32)v; });  // @16_473a70
  ecx = edi;  // @17_473a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(eax), (u32)(eax));  // @18_473a70
  ecx = edx = 0;  // @19_473a70
  ecx = (u32)(EBP - 16596);  // @20_473a70
  eax = ext_4d2330(ecx);  // @21_473a70
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
  eax = ext_4d2280(ecx);  // @3_474e00
  ecx = edx = 0;  // @4_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474e00
  reg.state = (s32)((u32)(0));  // @6_474e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_474e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @9_474e00
  ecx = edx = 0;  // @10_474e00
  ecx = (u32)(EBP - 16596);  // @11_474e00
  eax = ext_4d3ab0((u32)(6851120), (u32)(eax));  // @12_474e00
  ecx = edx = 0;  // @13_474e00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_474e00
  eax = (u32)(EBP - 16596);  // @15_474e00
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338412), sizeof v); (u32)v; });  // @16_474e00
  ecx = edi;  // @17_474e00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(eax), (u32)(eax));  // @18_474e00
  ecx = edx = 0;  // @19_474e00
  ecx = (u32)(EBP - 16596);  // @20_474e00
  eax = ext_4d2330(ecx);  // @21_474e00
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
  eax = ext_4d2280(ecx);  // @3_474f60
  ecx = edx = 0;  // @4_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474f60
  reg.state = (s32)((u32)(0));  // @6_474f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_474f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @9_474f60
  ecx = edx = 0;  // @10_474f60
  ecx = (u32)(EBP - 16596);  // @11_474f60
  eax = ext_4d3ab0((u32)(6851120), (u32)(eax));  // @12_474f60
  ecx = edx = 0;  // @13_474f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_474f60
  eax = (u32)(EBP - 16596);  // @15_474f60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338400), sizeof v); (u32)v; });  // @16_474f60
  ecx = edi;  // @17_474f60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(eax), (u32)(eax));  // @18_474f60
  ecx = edx = 0;  // @19_474f60
  ecx = (u32)(EBP - 16596);  // @20_474f60
  eax = ext_4d2330(ecx);  // @21_474f60
  ecx = edx = 0;  // @22_474f60
  SEH_LEAVE();  // @23_474f60
  ext_633654(G(u32, 0x6f5630));  // @24_474f60
  return eax;  // @25_474f60
}
PCREG(474f60, lifted_474f60);

extern "C" u32 THISCALL lifted_454a10(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666ba7);  // @h_454a10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_454a10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_454a10
  eax = ext_43e990(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_454a10
  ecx = edx = 0;  // @3_454a10
  reg.state = (s32)((u32)(0));  // @4_454a10
  { u32 v = (u32)((u32)(6825408)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_454a10
  eax = ext_41e290((u32)(28));  // @6_454a10
  ecx = edx = 0;  // @7_454a10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @8_454a10
  reg.state = (s32)((u32)(1));  // @9_454a10
  if ((eax & eax) == 0) goto L454a8b;  // @10_454a10
  ecx = eax;  // @11_454a10
  eax = ext_4ccbe0(ecx, (u32)(32), (u32)(0));  // @12_454a10
  ecx = edx = 0;  // @13_454a10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @14_454a10
  eax = esi;  // @15_454a10
  SEH_LEAVE();  // @16_454a10
  return eax;  // @17_454a10
  L454a8b:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @19_454a10
  eax = esi;  // @20_454a10
  SEH_LEAVE();  // @21_454a10
  return eax;  // @22_454a10
}
PCREG(454a10, lifted_454a10);

extern "C" u32 THISCALL lifted_4d5580(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4d5580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4d5580
  { u32 v = (u32)((u32)(6907860)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4d5580
  eax = ext_4d7540(ecx);  // @2_4d5580
  ecx = edx = 0;  // @3_4d5580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 102), sizeof v); (u32)v; });  // @4_4d5580
  if ((eax & eax) == 0) goto L4d55d5;  // @5_4d5580
  eax = ext_41e2c0((u32)(eax));  // @6_4d5580
  ecx = edx = 0;  // @7_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 102), &v, sizeof v); }  // @8_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 98), &v, sizeof v); }  // @9_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @10_4d5580
  L4d55d5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 90), sizeof v); (u32)v; });  // @12_4d5580
  if ((eax & eax) == 0) goto L4d55fa;  // @13_4d5580
  eax = ext_41e2c0((u32)(eax));  // @14_4d5580
  ecx = edx = 0;  // @15_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @16_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @17_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @18_4d5580
  L4d55fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 78), sizeof v); (u32)v; });  // @20_4d5580
  if ((eax & eax) == 0) goto L4d561f;  // @21_4d5580
  eax = ext_41e2c0((u32)(eax));  // @22_4d5580
  ecx = edx = 0;  // @23_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 78), &v, sizeof v); }  // @24_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @25_4d5580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 70), &v, sizeof v); }  // @26_4d5580
  L4d561f:;
  { u32 v = (u32)((u32)(6907444)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @28_4d5580
  SEH_LEAVE();  // @29_4d5580
  return eax;  // @30_4d5580
}
PCREG(4d5580, lifted_4d5580);

extern "C" u32 THISCALL lifted_50a4a0(u32 ecx_in) {
  SEH_ENTER(0x669e17);  // @h_50a4a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_50a4a0
  eax = ext_41e290((u32)(16));  // @1_50a4a0
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
  eax = ext_50a380(ecx);  // @14_50a4a0
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
  eax = ext_46a4f0(ecx);  // @30_46a5e0
  ecx = edx = 0;  // @31_46a5e0
  SEH_LEAVE();  // @32_46a5e0
  return eax;  // @33_46a5e0
}
PCREG(46a5e0, lifted_46a5e0);

extern "C" u32 THISCALL lifted_4af390(u32 ecx_in) {
  SEH_ENTER(0x668a89);  // @h_4af390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4af390
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4af390
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @2_4af390
  reg.state = (s32)((u32)(0));  // @3_4af390
  if ((esi & esi) == 0) goto L4af420;  // @4_4af390
  eax = ext_469870(ecx);  // @5_4af390
  ecx = edx = 0;  // @6_4af390
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @7_4af390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @8_4af390
  { u32 v = (u32)((u32)(6884880)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_4af390
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @10_4af390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4af390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_4af390
  reg.state = (s32)((u32)(1));  // @13_4af390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4af390
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 276)))(ecx, (u32)(6885064), (u32)(0), (u32)(6885016), (u32)(17));  // @15_4af390
  ecx = edx = 0;  // @16_4af390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @17_4af390
  eax = esi;  // @18_4af390
  SEH_LEAVE();  // @19_4af390
  return eax;  // @20_4af390
  L4af420:;
  eax = 0;  // @22_4af390
  SEH_LEAVE();  // @23_4af390
  return eax;  // @24_4af390
}
PCREG(4af390, lifted_4af390);

extern "C" u32 THISCALL lifted_511950(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_511950
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_511950
  eax = (u32)(esi + 4613);  // @1_511950
  eax = ext_63418c((u32)(eax), (u32)(121), (u32)(2), (u32)(4624560));  // @2_511950
  ecx = edx = 0;  // @3_511950
  eax = (u32)(esi + 3385);  // @4_511950
  eax = ext_63418c((u32)(eax), (u32)(307), (u32)(4), (u32)(5315248));  // @5_511950
  ecx = edx = 0;  // @6_511950
  eax = (u32)(esi + 1965);  // @7_511950
  eax = ext_63418c((u32)(eax), (u32)(355), (u32)(4), (u32)(5314864));  // @8_511950
  ecx = edx = 0;  // @9_511950
  eax = (u32)(esi + 1077);  // @10_511950
  eax = ext_63418c((u32)(eax), (u32)(222), (u32)(4), (u32)(5332736));  // @11_511950
  ecx = edx = 0;  // @12_511950
  eax = (u32)(esi + 189);  // @13_511950
  eax = ext_63418c((u32)(eax), (u32)(222), (u32)(4), (u32)(5332736));  // @14_511950
  ecx = edx = 0;  // @15_511950
  SEH_LEAVE();  // @16_511950
  return eax;  // @17_511950
}
PCREG(511950, lifted_511950);

extern "C" u32 THISCALL lifted_511a00(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_511a00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_511a00
  eax = (u32)(esi + 8654);  // @1_511a00
  eax = ext_63418c((u32)(eax), (u32)(121), (u32)(2), (u32)(4624560));  // @2_511a00
  ecx = edx = 0;  // @3_511a00
  eax = (u32)(esi + 6157);  // @4_511a00
  eax = ext_63418c((u32)(eax), (u32)(307), (u32)(8), (u32)(5315248));  // @5_511a00
  ecx = edx = 0;  // @6_511a00
  eax = (u32)(esi + 3701);  // @7_511a00
  eax = ext_63418c((u32)(eax), (u32)(307), (u32)(8), (u32)(5315248));  // @8_511a00
  ecx = edx = 0;  // @9_511a00
  eax = (u32)(esi + 1925);  // @10_511a00
  eax = ext_63418c((u32)(eax), (u32)(222), (u32)(8), (u32)(5332736));  // @11_511a00
  ecx = edx = 0;  // @12_511a00
  eax = (u32)(esi + 149);  // @13_511a00
  eax = ext_63418c((u32)(eax), (u32)(222), (u32)(8), (u32)(5332736));  // @14_511a00
  ecx = edx = 0;  // @15_511a00
  SEH_LEAVE();  // @16_511a00
  return eax;  // @17_511a00
}
PCREG(511a00, lifted_511a00);

