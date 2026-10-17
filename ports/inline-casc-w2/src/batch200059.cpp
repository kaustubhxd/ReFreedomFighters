// batch200059.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_436bd0(u32, u32);
extern "C" u32 STDCALL ext_54f870(u32, u32);
extern "C" u32 STDCALL ext_6014a0(u32);
extern "C" u32 THISCALL ext_431630(u32);
extern "C" u32 THISCALL ext_43de70(u32);
extern "C" u32 THISCALL ext_469870(u32);
extern "C" u32 THISCALL ext_47fb10(u32, u32);
extern "C" u32 THISCALL ext_480a20(u32);
extern "C" u32 THISCALL ext_4876a0(u32, u32, u32);
extern "C" u32 THISCALL ext_4cbe80(u32, u32);
extern "C" u32 THISCALL ext_4cbec0(u32);
extern "C" u32 THISCALL ext_4cbee0(u32, u32);
extern "C" u32 THISCALL ext_4ccba0(u32);
extern "C" u32 THISCALL ext_4ccbe0(u32, u32, u32);
extern "C" u32 THISCALL ext_4ccf60(u32);
extern "C" u32 THISCALL ext_4de7a0(u32);
extern "C" u32 THISCALL ext_4e6330(u32, u32);
extern "C" u32 THISCALL ext_4e6680(u32);
extern "C" u32 THISCALL ext_4f0c10(u32);
extern "C" u32 THISCALL ext_4f97f0(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_5047c0(u32, u32);
extern "C" u32 THISCALL ext_564460(u32);
extern "C" u32 THISCALL ext_5e0e10(u32, u32, u32);
extern "C" u32 THISCALL ext_5e1040(u32, u32, u32);
extern "C" u32 THISCALL ext_5ebae0(u32, u32);
extern "C" u32 THISCALL ext_5f10c0(u32, u32);
extern "C" u32 THISCALL ext_5f1180(u32);
extern "C" u32 THISCALL ext_5f95e0(u32, u32);
extern "C" u32 THISCALL ext_5fb370(u32, u32);
extern "C" u32 THISCALL ext_602240(u32);
extern "C" u32 THISCALL ext_602260(u32, u32);
extern "C" u32 THISCALL ext_6024a0(u32);
extern "C" u32 THISCALL ext_603110(u32);
extern "C" u32 THISCALL ext_6031e0(u32, u32);
extern "C" u32 THISCALL ext_604650(u32);
extern "C" u32 THISCALL ext_615390(u32, u32, u32, u32, u32);
extern "C" u32 ext_41e290(u32);
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5f1850(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_5f1850
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5f1850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5f1850
  ecx = (u32)(EBP - 144);  // @2_5f1850
  eax = ext_4cbe80(ecx, (u32)(eax));  // @3_5f1850
  ecx = edx = 0;  // @4_5f1850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @5_5f1850
  eax = (u32)(EBP - 144);  // @6_5f1850
  reg.state = (s32)((u32)(0));  // @7_5f1850
  eax = ext_4cbee0(ecx, (u32)(eax));  // @8_5f1850
  ecx = edx = 0;  // @9_5f1850
  ecx = (u32)(EBP - 144);  // @10_5f1850
  eax = ext_4cbec0(ecx);  // @11_5f1850
  ecx = edx = 0;  // @12_5f1850
  SEH_LEAVE();  // @13_5f1850
  ext_633654(G(u32, 0x6f5630));  // @14_5f1850
  return eax;  // @15_5f1850
}
PCREG(5f1850, lifted_5f1850);

extern "C" u32 THISCALL lifted_423ff0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_423ff0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_423ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_423ff0
  ecx = (u32)(EBP - 144);  // @2_423ff0
  eax = ext_4cbe80(ecx, (u32)(eax));  // @3_423ff0
  ecx = edx = 0;  // @4_423ff0
  eax = (u32)(EBP - 144);  // @5_423ff0
  reg.state = (s32)((u32)(0));  // @6_423ff0
  ecx = (u32)(esi + 9179);  // @7_423ff0
  eax = ext_4cbee0(ecx, (u32)(eax));  // @8_423ff0
  ecx = edx = 0;  // @9_423ff0
  ecx = (u32)(EBP - 144);  // @10_423ff0
  eax = ext_4cbec0(ecx);  // @11_423ff0
  ecx = edx = 0;  // @12_423ff0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6975), &v, sizeof v); }  // @13_423ff0
  SEH_LEAVE();  // @14_423ff0
  ext_633654(G(u32, 0x6f5630));  // @15_423ff0
  return eax;  // @16_423ff0
}
PCREG(423ff0, lifted_423ff0);

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
  eax = ext_603110(ecx);  // @1_602bc0
  ecx = edx = 0;  // @2_602bc0
  { u32 v = (u32)((u32)(7046408)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @3_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @4_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @5_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_602bc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_602bc0
  ecx = (u32)(EBP - 36);  // @8_602bc0
  reg.state = (s32)((u32)(0));  // @9_602bc0
  eax = ext_602260(ecx, (u32)(eax));  // @10_602bc0
  ecx = edx = 0;  // @11_602bc0
  eax = (u32)(EBP - 36);  // @12_602bc0
  ecx = esi;  // @13_602bc0
  eax = ext_6031e0(ecx, (u32)(eax));  // @14_602bc0
  ecx = edx = 0;  // @15_602bc0
  ecx = (u32)(EBP - 36);  // @16_602bc0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @17_602bc0
  eax = ext_602240(ecx);  // @18_602bc0
  ecx = edx = 0;  // @19_602bc0
  SEH_LEAVE();  // @20_602bc0
  return eax;  // @21_602bc0
}
PCREG(602bc0, lifted_602bc0);

extern "C" u32 THISCALL lifted_5fad10(u32 ecx_in) {
  SEH_ENTER(0x66d9ec);  // @h_5fad10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5fad10
  reg.state = (s32)((u32)(0));  // @1_5fad10
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L5fad66;  // @2_5fad10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_5fad10
  eax = ext_5fb370(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }));  // @4_5fad10
  ecx = edx = 0;  // @5_5fad10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_5fad10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @7_5fad10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_5fad10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @9_5fad10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_5fad10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @11_5fad10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @12_5fad10
  L5fad66:;
  ecx = esi;  // @14_5fad10
  reg.state = (s32)((u32)(1));  // @15_5fad10
  eax = ext_54f870(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(29));  // @16_5fad10
  ecx = edx = 0;  // @17_5fad10
  SEH_LEAVE();  // @18_5fad10
  return eax;  // @19_5fad10
}
PCREG(5fad10, lifted_5fad10);

extern "C" u32 THISCALL lifted_4f7960(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x669a18);  // @h_4f7960
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_4f7960
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4f7960
  eax = ext_4f97f0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_4f7960
  ecx = edx = 0;  // @3_4f7960
  ecx = (u32)(esi + 179);  // @4_4f7960
  reg.state = (s32)((u32)(0));  // @5_4f7960
  { u32 v = (u32)((u32)(6925972)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4f7960
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 143), &v, sizeof v); }  // @7_4f7960
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 147), &v, sizeof v); }  // @8_4f7960
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 159), &v, sizeof v); }  // @9_4f7960
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 171), &v, sizeof v); }  // @10_4f7960
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 175), &v, sizeof v); }  // @11_4f7960
  eax = ext_4ccbe0(ecx, (u32)(4), (u32)(0));  // @12_4f7960
  ecx = edx = 0;  // @13_4f7960
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 211), &v, sizeof v); }  // @14_4f7960
  eax = esi;  // @15_4f7960
  SEH_LEAVE();  // @16_4f7960
  return eax;  // @17_4f7960
}
PCREG(4f7960, lifted_4f7960);

extern "C" u32 THISCALL lifted_5060f0(u32 ecx_in) {
  SEH_ENTER(0x669d2f);  // @h_5060f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5060f0
  eax = ext_41e290((u32)(24));  // @1_5060f0
  ecx = edx = 0;  // @2_5060f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_5060f0
  reg.state = (s32)((u32)(0));  // @4_5060f0
  if ((eax & eax) == 0) goto L506146;  // @5_5060f0
  ecx = eax;  // @6_5060f0
  eax = ext_5047c0(ecx, (u32)(esi));  // @7_5060f0
  ecx = edx = 0;  // @8_5060f0
  SEH_LEAVE();  // @9_5060f0
  return eax;  // @10_5060f0
  L506146:;
  eax = 0;  // @12_5060f0
  SEH_LEAVE();  // @13_5060f0
  return eax;  // @14_5060f0
}
PCREG(5060f0, lifted_5060f0);

extern "C" u32 lifted_603090(void) {
  SEH_ENTER(0x66dc0f);  // @h_603090
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489172), sizeof v); (u32)v; });  // @0_603090
  if ((eax & eax) != 0) goto L6030f6;  // @1_603090
  eax = ext_41e290((u32)(26));  // @2_603090
  ecx = edx = 0;  // @3_603090
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_603090
  reg.state = (s32)((u32)(0));  // @5_603090
  if ((eax & eax) == 0) goto L6030ef;  // @6_603090
  ecx = eax;  // @7_603090
  eax = ext_6024a0(ecx);  // @8_603090
  ecx = edx = 0;  // @9_603090
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7489172), &v, sizeof v); }  // @10_603090
  SEH_LEAVE();  // @11_603090
  return eax;  // @12_603090
  L6030ef:;
  eax = 0;  // @14_603090
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7489172), &v, sizeof v); }  // @15_603090
  L6030f6:;
  SEH_LEAVE();  // @17_603090
  return eax;  // @18_603090
}
PCREG(603090, lifted_603090);

extern "C" u32 THISCALL lifted_590d40(u32 ecx_in) {
  SEH_ENTER(0x66b912);  // @h_590d40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_590d40
  eax = ext_41e290((u32)(1533));  // @1_590d40
  ecx = edx = 0;  // @2_590d40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_590d40
  reg.state = (s32)((u32)(0));  // @4_590d40
  if ((eax & eax) == 0) goto L590d9b;  // @5_590d40
  ecx = eax;  // @6_590d40
  eax = ext_5e1040(ecx, (u32)(esi), (u32)(5));  // @7_590d40
  ecx = edx = 0;  // @8_590d40
  SEH_LEAVE();  // @9_590d40
  return eax;  // @10_590d40
  L590d9b:;
  eax = 0;  // @12_590d40
  SEH_LEAVE();  // @13_590d40
  return eax;  // @14_590d40
}
PCREG(590d40, lifted_590d40);

extern "C" u32 THISCALL lifted_5f12d0(u32 ecx_in) {
  SEH_ENTER(0x66ce4a);  // @h_5f12d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5f12d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f12d0
  eax = ext_4e6680(ecx);  // @2_5f12d0
  ecx = edx = 0;  // @3_5f12d0
  { u32 v = (u32)((u32)(7046076)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5f12d0
  reg.state = (s32)((u32)(0));  // @5_5f12d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489172), &v, sizeof v); }  // @6_5f12d0
  eax = ext_41e290((u32)(184));  // @7_5f12d0
  ecx = edx = 0;  // @8_5f12d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @9_5f12d0
  reg.state = (s32)((u32)(1));  // @10_5f12d0
  if ((eax & eax) == 0) goto L5f1338;  // @11_5f12d0
  ecx = eax;  // @12_5f12d0
  eax = ext_5f1180(ecx);  // @13_5f12d0
  ecx = edx = 0;  // @14_5f12d0
  goto L5f133a;  // @15_5f12d0
  L5f1338:;
  eax = 0;  // @17_5f12d0
  L5f133a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @19_5f12d0
  eax = esi;  // @20_5f12d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4112), &v, sizeof v); }  // @21_5f12d0
  SEH_LEAVE();  // @22_5f12d0
  return eax;  // @23_5f12d0
}
PCREG(5f12d0, lifted_5f12d0);

extern "C" u32 THISCALL lifted_466380(u32 ecx_in) {
  SEH_ENTER(0x666a9f);  // @h_466380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_466380
  eax = ext_41e290((u32)(12));  // @1_466380
  ecx = edx = 0;  // @2_466380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_466380
  reg.state = (s32)((u32)(0));  // @4_466380
  if ((eax & eax) == 0) goto L4663dc;  // @5_466380
  ecx = eax;  // @6_466380
  eax = ext_47fb10(ecx, (u32)(esi));  // @7_466380
  ecx = edx = 0;  // @8_466380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 462), &v, sizeof v); }  // @9_466380
  SEH_LEAVE();  // @10_466380
  return eax;  // @11_466380
  L4663dc:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 462), &v, sizeof v); }  // @13_466380
  SEH_LEAVE();  // @14_466380
  return eax;  // @15_466380
}
PCREG(466380, lifted_466380);

extern "C" u32 THISCALL lifted_590cd0(u32 ecx_in) {
  SEH_ENTER(0x66b8e2);  // @h_590cd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_590cd0
  eax = ext_41e290((u32)(1356));  // @1_590cd0
  ecx = edx = 0;  // @2_590cd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_590cd0
  reg.state = (s32)((u32)(0));  // @4_590cd0
  if ((eax & eax) == 0) goto L590d2b;  // @5_590cd0
  ecx = eax;  // @6_590cd0
  eax = ext_5e0e10(ecx, (u32)(esi), (u32)(3));  // @7_590cd0
  ecx = edx = 0;  // @8_590cd0
  SEH_LEAVE();  // @9_590cd0
  return eax;  // @10_590cd0
  L590d2b:;
  eax = 0;  // @12_590cd0
  SEH_LEAVE();  // @13_590cd0
  return eax;  // @14_590cd0
}
PCREG(590cd0, lifted_590cd0);

extern "C" u32 THISCALL lifted_5ec720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cb06);  // @h_5ec720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5ec720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5ec720
  eax = ext_5ebae0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @2_5ec720
  ecx = edx = 0;  // @3_5ec720
  { u32 v = (u32)((u32)(7045396)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5ec720
  reg.state = (s32)((u32)(0));  // @5_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 203), &v, sizeof v); }  // @6_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 207), &v, sizeof v); }  // @7_5ec720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 211), &v, sizeof v); }  // @8_5ec720
  ecx = (u32)(esi + 118);  // @9_5ec720
  reg.state = (s32)((u32)(1));  // @10_5ec720
  eax = ext_4de7a0(ecx);  // @11_5ec720
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

extern "C" u32 STDCALL lifted_5fb2c0(u32 a0) {
  SEH_ENTER(0x66dac1);  // @h_5fb2c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ext_6014a0((u32)(29));  // @0_5fb2c0
  ecx = edx = 0;  // @1_5fb2c0
  ebx = eax;  // @2_5fb2c0
  edi = (u32)(ebx + 13);  // @3_5fb2c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_5fb2c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_5fb2c0
  reg.state = (s32)((u32)(0));  // @6_5fb2c0
  if ((edi & edi) == 0) goto L5fb316;  // @7_5fb2c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_5fb2c0
  ecx = edi;  // @9_5fb2c0
  eax = ext_5f10c0(ecx, (u32)(esi));  // @10_5fb2c0
  ecx = edx = 0;  // @11_5fb2c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @12_5fb2c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @13_5fb2c0
  L5fb316:;
  eax = ebx;  // @15_5fb2c0
  SEH_LEAVE();  // @16_5fb2c0
  return eax;  // @17_5fb2c0
}
PCREG(5fb2c0, lifted_5fb2c0);

extern "C" u32 THISCALL lifted_4c7aa0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66906b);  // @h_4c7aa0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_4c7aa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4c7aa0
  ecx = (u32)(EBP - 188);  // @2_4c7aa0
  eax = ext_4ccba0(ecx);  // @3_4c7aa0
  ecx = edx = 0;  // @4_4c7aa0
  eax = (u32)(EBP - 188);  // @5_4c7aa0
  reg.state = (s32)((u32)(0));  // @6_4c7aa0
  ecx = esi;  // @7_4c7aa0
  eax = ext_4e6330(ecx, (u32)(eax));  // @8_4c7aa0
  ecx = edx = 0;  // @9_4c7aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_4c7aa0
  ecx = edi;  // @11_4c7aa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @12_4c7aa0
  ecx = edx = 0;  // @13_4c7aa0
  ecx = (u32)(EBP - 188);  // @14_4c7aa0
  eax = ext_4ccf60(ecx);  // @15_4c7aa0
  ecx = edx = 0;  // @16_4c7aa0
  SEH_LEAVE();  // @17_4c7aa0
  ext_633654(G(u32, 0x6f5630));  // @18_4c7aa0
  return eax;  // @19_4c7aa0
}
PCREG(4c7aa0, lifted_4c7aa0);

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
  eax = ext_4cbe80(ecx, (u32)(6782860));  // @7_421560
  ecx = edx = 0;  // @8_421560
  eax = (u32)(EBP - 144);  // @9_421560
  reg.state = (s32)((u32)(0));  // @10_421560
  ecx = (u32)(esi + 9030);  // @11_421560
  eax = ext_4cbee0(ecx, (u32)(eax));  // @12_421560
  ecx = edx = 0;  // @13_421560
  ecx = (u32)(EBP - 144);  // @14_421560
  eax = ext_4cbec0(ecx);  // @15_421560
  ecx = edx = 0;  // @16_421560
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 9706), &v, sizeof v); }  // @17_421560
  SEH_LEAVE();  // @18_421560
  ext_633654(G(u32, 0x6f5630));  // @19_421560
  return eax;  // @20_421560
}
PCREG(421560, lifted_421560);

extern "C" u32 THISCALL lifted_433d20(u32 ecx_in) {
  SEH_ENTER(0x665646);  // @h_433d20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_433d20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_433d20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @2_433d20
  eax = ext_431630(ecx);  // @3_433d20
  ecx = edx = 0;  // @4_433d20
  ecx = (u32)(EBP - 144);  // @5_433d20
  reg.state = (s32)((u32)(0));  // @6_433d20
  { u32 v = (u32)((u32)(6791844)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_433d20
  eax = ext_4cbe80(ecx, (u32)(6792080));  // @8_433d20
  ecx = edx = 0;  // @9_433d20
  eax = (u32)(EBP - 144);  // @10_433d20
  reg.state = (s32)((u32)(1));  // @11_433d20
  ecx = (u32)(esi + 4);  // @12_433d20
  eax = ext_4cbee0(ecx, (u32)(eax));  // @13_433d20
  ecx = edx = 0;  // @14_433d20
  ecx = (u32)(EBP - 144);  // @15_433d20
  eax = ext_4cbec0(ecx);  // @16_433d20
  ecx = edx = 0;  // @17_433d20
  eax = esi;  // @18_433d20
  SEH_LEAVE();  // @19_433d20
  ext_633654(G(u32, 0x6f5630));  // @20_433d20
  return eax;  // @21_433d20
}
PCREG(433d20, lifted_433d20);

extern "C" u32 THISCALL lifted_42d6b0(u32 ecx_in) {
  SEH_ENTER(0x664eb2);  // @h_42d6b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_42d6b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_42d6b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 200)))(ecx);  // @2_42d6b0
  ecx = edx = 0;  // @3_42d6b0
  eax = ext_41e290((u32)(4940));  // @4_42d6b0
  ecx = edx = 0;  // @5_42d6b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_42d6b0
  reg.state = (s32)((u32)(0));  // @7_42d6b0
  if ((eax & eax) == 0) goto L42d716;  // @8_42d6b0
  ecx = eax;  // @9_42d6b0
  eax = ext_436bd0(ecx, edx);  // @10_42d6b0
  ecx = edx = 0;  // @11_42d6b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 6407), &v, sizeof v); }  // @12_42d6b0
  SEH_LEAVE();  // @13_42d6b0
  return eax;  // @14_42d6b0
  L42d716:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6407), &v, sizeof v); }  // @16_42d6b0
  SEH_LEAVE();  // @17_42d6b0
  return eax;  // @18_42d6b0
}
PCREG(42d6b0, lifted_42d6b0);

extern "C" u32 THISCALL lifted_5d6040(u32 ecx_in) {
  SEH_ENTER(0x66c8ce);  // @h_5d6040
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5d6040
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5d6040
  eax = ext_469870(ecx);  // @2_5d6040
  ecx = edx = 0;  // @3_5d6040
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5d6040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5d6040
  ecx = (u32)(EBP - 88);  // @6_5d6040
  reg.state = (s32)((u32)(0));  // @7_5d6040
  { u32 v = (u32)((u32)(7035332)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5d6040
  eax = ext_469870(ecx);  // @9_5d6040
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

extern "C" u32 THISCALL lifted_5fd0a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d631);  // @h_5fd0a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_5fd0a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_5fd0a0
  eax = ext_6014a0((u32)(20));  // @2_5fd0a0
  ecx = edx = 0;  // @3_5fd0a0
  edi = eax;  // @4_5fd0a0
  ecx = (u32)(edi + 8);  // @5_5fd0a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_5fd0a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @7_5fd0a0
  reg.state = (s32)((u32)(0));  // @8_5fd0a0
  if ((ecx & ecx) == 0) goto L5fd0f0;  // @9_5fd0a0
  eax = ext_5f10c0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @10_5fd0a0
  ecx = edx = 0;  // @11_5fd0a0
  L5fd0f0:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @13_5fd0a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @14_5fd0a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @15_5fd0a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @16_5fd0a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @17_5fd0a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @18_5fd0a0
  SEH_LEAVE();  // @19_5fd0a0
  return eax;  // @20_5fd0a0
}
PCREG(5fd0a0, lifted_5fd0a0);

extern "C" u32 THISCALL lifted_487820(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x667684);  // @h_487820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_487820
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_487820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_487820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @3_487820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_487820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @5_487820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @6_487820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @7_487820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @8_487820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @9_487820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @10_487820
  ecx = (u32)(esi + 221);  // @11_487820
  reg.state = (s32)((u32)(0));  // @12_487820
  { u32 v = (u32)((u32)(6868916)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @13_487820
  eax = ext_480a20(ecx);  // @14_487820
  ecx = edx = 0;  // @15_487820
  ecx = (u32)(esi + 245);  // @16_487820
  reg.state = (s32)((u32)(1));  // @17_487820
  eax = ext_480a20(ecx);  // @18_487820
  ecx = edx = 0;  // @19_487820
  ecx = (u32)(esi + 269);  // @20_487820
  reg.state = (s32)((u32)(2));  // @21_487820
  eax = ext_480a20(ecx);  // @22_487820
  ecx = edx = 0;  // @23_487820
  eax = esi;  // @24_487820
  SEH_LEAVE();  // @25_487820
  return eax;  // @26_487820
}
PCREG(487820, lifted_487820);

extern "C" u32 THISCALL lifted_4ee440(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_4ee440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ee440
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 151), sizeof v); (u32)v; });  // @1_4ee440
  { u32 v = (u32)((u32)(6914328)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4ee440
  if ((edx & edx) == 0) goto L4ee484;  // @3_4ee440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4ee440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4ee440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, (u32)(edx));  // @6_4ee440
  ecx = edx = 0;  // @7_4ee440
  L4ee484:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 155), sizeof v); (u32)v; });  // @9_4ee440
  if ((edx & edx) == 0) goto L4ee49d;  // @10_4ee440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4ee440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4ee440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, (u32)(edx));  // @13_4ee440
  ecx = edx = 0;  // @14_4ee440
  L4ee49d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @16_4ee440
  ecx = esi;  // @17_4ee440
  reg.state = (s32)((u32)(0));  // @18_4ee440
  { u32 v = (u32)((u32)(6913692)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_4ee440
  eax = ext_4f0c10(ecx);  // @20_4ee440
  ecx = edx = 0;  // @21_4ee440
  ecx = esi;  // @22_4ee440
  eax = ext_43de70(ecx);  // @23_4ee440
  ecx = edx = 0;  // @24_4ee440
  SEH_LEAVE();  // @25_4ee440
  return eax;  // @26_4ee440
}
PCREG(4ee440, lifted_4ee440);

extern "C" u32 THISCALL lifted_615010(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66e4a2);  // @h_615010
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_615010
  eax = ext_41e290((u32)(98990));  // @1_615010
  ecx = edx = 0;  // @2_615010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_615010
  reg.state = (s32)((u32)(0));  // @4_615010
  if ((eax & eax) == 0) goto L615074;  // @5_615010
  ecx = eax;  // @6_615010
  eax = ext_615390(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_615010
  ecx = edx = 0;  // @8_615010
  SEH_LEAVE();  // @9_615010
  return eax;  // @10_615010
  L615074:;
  eax = 0;  // @12_615010
  SEH_LEAVE();  // @13_615010
  return eax;  // @14_615010
}
PCREG(615010, lifted_615010);

extern "C" u32 THISCALL lifted_56b230(u32 ecx_in) {
  SEH_ENTER(0x66c831);  // @h_56b230
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_56b230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_56b230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @2_56b230
  reg.state = (s32)((u32)(0));  // @3_56b230
  if ((esi & esi) == 0) goto L56b2b8;  // @4_56b230
  eax = ext_564460(ecx);  // @5_56b230
  ecx = edx = 0;  // @6_56b230
  { u32 v = (u32)((u32)(6977840)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_56b230
  eax = esi;  // @8_56b230
  { u32 v = (u32)((u32)(6978108)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @9_56b230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3298), &v, sizeof v); }  // @10_56b230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3302), &v, sizeof v); }  // @11_56b230
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3230), &v, sizeof v); }  // @12_56b230
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3310), &v, sizeof v); }  // @13_56b230
  SEH_LEAVE();  // @14_56b230
  return eax;  // @15_56b230
  L56b2b8:;
  eax = 0;  // @17_56b230
  SEH_LEAVE();  // @18_56b230
  return eax;  // @19_56b230
}
PCREG(56b230, lifted_56b230);

extern "C" u32 THISCALL lifted_5e1240(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66c9c0);  // @h_5e1240
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_5e1240
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5e1240
  eax = ext_4876a0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @2_5e1240
  ecx = edx = 0;  // @3_5e1240
  ecx = (u32)(esi + 269);  // @4_5e1240
  reg.state = (s32)((u32)(0));  // @5_5e1240
  { u32 v = (u32)((u32)(7042364)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5e1240
  eax = ext_480a20(ecx);  // @7_5e1240
  ecx = edx = 0;  // @8_5e1240
  ecx = (u32)(esi + 293);  // @9_5e1240
  reg.state = (s32)((u32)(1));  // @10_5e1240
  eax = ext_480a20(ecx);  // @11_5e1240
  ecx = edx = 0;  // @12_5e1240
  ecx = (u32)(esi + 317);  // @13_5e1240
  reg.state = (s32)((u32)(2));  // @14_5e1240
  eax = ext_480a20(ecx);  // @15_5e1240
  ecx = edx = 0;  // @16_5e1240
  ecx = (u32)(esi + 341);  // @17_5e1240
  reg.state = (s32)((u32)(3));  // @18_5e1240
  eax = ext_480a20(ecx);  // @19_5e1240
  ecx = edx = 0;  // @20_5e1240
  ecx = (u32)(esi + 365);  // @21_5e1240
  reg.state = (s32)((u32)(4));  // @22_5e1240
  eax = ext_480a20(ecx);  // @23_5e1240
  ecx = edx = 0;  // @24_5e1240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 389), &v, sizeof v); }  // @25_5e1240
  eax = esi;  // @26_5e1240
  SEH_LEAVE();  // @27_5e1240
  return eax;  // @28_5e1240
}
PCREG(5e1240, lifted_5e1240);

extern "C" u32 STDCALL lifted_5f3050(u32 a0, u32 a1) {
  SEH_ENTER(0x66d04f);  // @h_5f3050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ext_41e290((u32)(18));  // @0_5f3050
  ecx = edx = 0;  // @1_5f3050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_5f3050
  reg.state = (s32)((u32)(0));  // @3_5f3050
  if ((eax & eax) == 0) goto L5f3097;  // @4_5f3050
  ecx = eax;  // @5_5f3050
  eax = ext_604650(ecx);  // @6_5f3050
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

extern "C" u32 STDCALL lifted_42ff40(u32 a0) {
  SEH_ENTER(0x665259);  // @h_42ff40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ext_6014a0((u32)(37));  // @0_42ff40
  ecx = edx = 0;  // @1_42ff40
  ebx = eax;  // @2_42ff40
  edi = (u32)(ebx + 13);  // @3_42ff40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_42ff40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_42ff40
  reg.state = (s32)((u32)(0));  // @6_42ff40
  if ((edi & edi) == 0) goto L42ffa0;  // @7_42ff40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_42ff40
  ecx = edi;  // @9_42ff40
  eax = ext_5f10c0(ecx, (u32)(esi));  // @10_42ff40
  ecx = edx = 0;  // @11_42ff40
  eax = (u32)(esi + 12);  // @12_42ff40
  reg.state = (s32)((u32)(1));  // @13_42ff40
  ecx = (u32)(edi + 12);  // @14_42ff40
  eax = ext_5f10c0(ecx, (u32)(eax));  // @15_42ff40
  ecx = edx = 0;  // @16_42ff40
  L42ffa0:;
  eax = ebx;  // @18_42ff40
  SEH_LEAVE();  // @19_42ff40
  return eax;  // @20_42ff40
}
PCREG(42ff40, lifted_42ff40);

extern "C" u32 THISCALL lifted_5f9680(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669d2f);  // @h_5f9680
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5f9680
  { u32 v = (u32)((u32)(7049368)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_5f9680
  eax = ext_41e290((u32)(24));  // @2_5f9680
  ecx = edx = 0;  // @3_5f9680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_5f9680
  reg.state = (s32)((u32)(0));  // @5_5f9680
  if ((eax & eax) == 0) goto L5f96e5;  // @6_5f9680
  ecx = eax;  // @7_5f9680
  eax = ext_5f95e0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @8_5f9680
  ecx = edx = 0;  // @9_5f9680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @10_5f9680
  eax = esi;  // @11_5f9680
  SEH_LEAVE();  // @12_5f9680
  return eax;  // @13_5f9680
  L5f96e5:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @15_5f9680
  eax = esi;  // @16_5f9680
  SEH_LEAVE();  // @17_5f9680
  return eax;  // @18_5f9680
}
PCREG(5f9680, lifted_5f9680);

