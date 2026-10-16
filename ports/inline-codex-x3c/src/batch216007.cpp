// batch216007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_43a900_thiscall1(u32) __asm__("ext_43a900");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_469980_thiscall4(u32, u32, u32, u32) __asm__("ext_469980");
extern "C" u32 THISCALL ext_49b5c0_thiscall2(u32, u32) __asm__("ext_49b5c0");
extern "C" u32 THISCALL ext_49b680_thiscall1(u32) __asm__("ext_49b680");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbf30_thiscall2(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_500190_thiscall2(u32, u32) __asm__("ext_500190");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_43a720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665c56);  // @h_43a720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_43a720
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @1_43a720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }) != 0) goto L43a7ab;  // @2_43a720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4628), sizeof v); (u32)v; });  // @3_43a720
  PS[0] = esi;  // @4_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_43a720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(PS[0]));  // @6_43a720
  ecx = edx = 0;  // @7_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @8_43a720
  reg.state = (s32)((u32)(0));  // @9_43a720
  { u32 v = (u32)((u32)(6793124)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_43a720
  if ((eax & eax) == 0) goto L43a777;  // @11_43a720
  PS[1] = eax;  // @12_43a720
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @13_43a720
  ecx = edx = 0;  // @14_43a720
  L43a777:;
  ecx = esi;  // @16_43a720
  eax = ext_43a900_thiscall1(ecx);  // @17_43a720
  ecx = edx = 0;  // @18_43a720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @19_43a720
  if ((ecx & ecx) == 0) goto L43a78b;  // @20_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_43a720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @22_43a720
  ecx = edx = 0;  // @23_43a720
  L43a78b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @25_43a720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4916), sizeof v); (u32)v; }) != esi) goto L43a7a0;  // @26_43a720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4916), &v, sizeof v); }  // @27_43a720
  L43a7a0:;
  PS[1] = esi;  // @29_43a720
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(35));  // @30_43a720
  ecx = edx = 0;  // @31_43a720
  L43a7ab:;
  SEH_LEAVE();  // @33_43a720
  return eax;  // @34_43a720
}
PCREG(43a720, lifted_43a720);

extern "C" u32 THISCALL lifted_4c6360(u32 ecx_in) {
  SEH_ENTER(0x668f1a);  // @h_4c6360
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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
  PS[0] = ecx;  // @15_4c6360
  ecx = eax;  // @16_4c6360
  eax = ext_4d8330_thiscall4(ecx, (u32)(6900780), (u32)(6900640), (u32)(PS[0]));  // @17_4c6360
  ecx = edx = 0;  // @18_4c6360
  edx = eax;  // @19_4c6360
  goto L4c63e2;  // @20_4c6360
  L4c63e0:;
  edx = 0;  // @22_4c6360
  L4c63e2:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @24_4c6360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4c6360
  PS[0] = edx;  // @26_4c6360
  reg.state = (s32)((u32)(0));  // @27_4c6360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4c6360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @29_4c6360
  ecx = edx = 0;  // @30_4c6360
  eax = esi;  // @31_4c6360
  SEH_LEAVE();  // @32_4c6360
  return eax;  // @33_4c6360
}
PCREG(4c6360, lifted_4c6360);

extern "C" u32 THISCALL lifted_6040d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66de50);  // @h_6040d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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
  PS[0] = ecx;  // @15_6040d0
  ecx = esi;  // @16_6040d0
  reg.state = (s32)((u32)(1));  // @17_6040d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(PS[0]));  // @18_6040d0
  ecx = edx = 0;  // @19_6040d0
  ecx = (u32)(EBP - 28);  // @20_6040d0
  eax = ext_500190_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @21_6040d0
  ecx = edx = 0;  // @22_6040d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_6040d0
  ecx = edi;  // @24_6040d0
  PS[0] = esi;  // @25_6040d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @26_6040d0
  ecx = edx = 0;  // @27_6040d0
  ecx = (u32)(EBP - 28);  // @28_6040d0
  eax = ext_4ff9d0_thiscall1(ecx);  // @29_6040d0
  ecx = edx = 0;  // @30_6040d0
  SEH_LEAVE();  // @31_6040d0
  return eax;  // @32_6040d0
}
PCREG(6040d0, lifted_6040d0);

extern "C" u32 THISCALL lifted_46a680(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_46a680
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_46a680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_46a680
  PS[0] = esi;  // @3_46a680
  reg.state = (s32)((u32)(0));  // @4_46a680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_46a680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @7_46a680
  ecx = edx = 0;  // @8_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_46a680
  reg.state = (s32)((u32)(4294967295));  // @10_46a680
  if (((eax & 0xff) & (u32)(1)) == 0) goto L46a71b;  // @11_46a680
  if (((eax & 0xff) & (u32)(4)) != 0) goto L46a710;  // @12_46a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_46a680
  reg.state = (s32)((u32)(1));  // @14_46a680
  if ((eax & eax) == 0) goto L46a6fb;  // @15_46a680
  eax = ((u32(STDCALL *)(void))(eax))();  // @16_46a680
  ecx = edx = 0;  // @17_46a680
  eax = esi;  // @18_46a680
  SEH_LEAVE();  // @19_46a680
  return eax;  // @20_46a680
  L46a6fb:;
  __builtin_trap();  // @22_46a680
  L46a710:;
  PS[1] = esi;  // @24_46a680
  eax = ext_4690b0_cdecl2((u32)(PS[1]), (u32)(64));  // @25_46a680
  ecx = edx = 0;  // @26_46a680
  L46a71b:;
  eax = esi;  // @28_46a680
  SEH_LEAVE();  // @29_46a680
  return eax;  // @30_46a680
}
PCREG(46a680, lifted_46a680);

extern "C" u32 THISCALL lifted_495230(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667fff);  // @h_495230
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_495230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 23861), sizeof v); (u32)v; });  // @1_495230
  if ((esi & esi) == 0) goto L495273;  // @2_495230
  ecx = esi;  // @3_495230
  eax = ext_49b680_thiscall1(ecx);  // @4_495230
  ecx = edx = 0;  // @5_495230
  PS[1] = esi;  // @6_495230
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(65));  // @7_495230
  ecx = edx = 0;  // @8_495230
  L495273:;
  eax = ext_41e290_cdecl1((u32)(97));  // @10_495230
  ecx = edx = 0;  // @11_495230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_495230
  reg.state = (s32)((u32)(0));  // @13_495230
  if ((eax & eax) == 0) goto L4952ae;  // @14_495230
  ecx = eax;  // @15_495230
  eax = ext_49b5c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @16_495230
  ecx = edx = 0;  // @17_495230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 23861), &v, sizeof v); }  // @18_495230
  SEH_LEAVE();  // @19_495230
  return eax;  // @20_495230
  L4952ae:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23861), &v, sizeof v); }  // @22_495230
  SEH_LEAVE();  // @23_495230
  return eax;  // @24_495230
}
PCREG(495230, lifted_495230);

extern "C" u32 THISCALL lifted_5c9530(u32 ecx_in) {
  SEH_ENTER(0x66c588);  // @h_5c9530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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

extern "C" u32 THISCALL lifted_5eae20(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66ca98);  // @h_5eae20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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
  PS[0] = eax;  // @13_431410
  PS[1] = ebx;  // @14_431410
  ecx = edi;  // @15_431410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 104)))(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @16_431410
  ecx = edx = 0;  // @17_431410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_431410
  ecx = (u32)(EBP - 144);  // @19_431410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_431410
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_431410
  ecx = edx = 0;  // @22_431410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_431410
  PS[0] = eax;  // @24_431410
  PS[1] = ebx;  // @25_431410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @26_431410
  ecx = edx = 0;  // @27_431410
  ecx = (u32)(EBP - 144);  // @28_431410
  eax = ext_4cbec0_thiscall1(ecx);  // @29_431410
  ecx = edx = 0;  // @30_431410
  SEH_LEAVE();  // @31_431410
  ext_633654(G(u32, 0x6f5630));  // @32_431410
  return eax;  // @33_431410
}
PCREG(431410, lifted_431410);

extern "C" u32 THISCALL lifted_469b40(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666b37);  // @h_469b40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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

