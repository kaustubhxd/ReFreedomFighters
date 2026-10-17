// batch218016.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cd9b0_fastcall4(u32, u32, u32, u32) __asm__("ext_4cd9b0");
extern "C" u32 STDCALL ext_4d06a0_stdcall1(u32) __asm__("ext_4d06a0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_4367b0_thiscall3(u32, u32, u32) __asm__("ext_4367b0");
extern "C" u32 THISCALL ext_4369a0_thiscall3(u32, u32, u32) __asm__("ext_4369a0");
extern "C" u32 THISCALL ext_436b30_thiscall3(u32, u32, u32) __asm__("ext_436b30");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_496a40_thiscall1(u32) __asm__("ext_496a40");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d9350_thiscall3(u32, u32, u32) __asm__("ext_4d9350");
extern "C" u32 THISCALL ext_4d93e0_thiscall1(u32) __asm__("ext_4d93e0");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_606a70_thiscall1(u32) __asm__("ext_606a70");
extern "C" u32 THISCALL ext_607310_thiscall2(u32, u32) __asm__("ext_607310");
extern "C" u32 THISCALL ext_639c50_thiscall2(u32, u32) __asm__("ext_639c50");
extern "C" u32 THISCALL ext_639df0_thiscall3(u32, u32, u32) __asm__("ext_639df0");
extern "C" u32 THISCALL ext_659220_thiscall3(u32, u32, u32) __asm__("ext_659220");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_4d4c20(u32 a0) {
  SEH_ENTER(0x66adf6);  // @h_4d4c20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d4c20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4d4c20
  PV[0] = (u32)(esi);  // @2_4d4c20
  eax = ((u32(*)(u32))(*(u32 *)0x6763dc))(PV[0]);  // @3_4d4c20
  ecx = edx = 0;  // @4_4d4c20
  edi = eax;  // @5_4d4c20
  PV[1] = (u32)(esi);  // @6_4d4c20
  reg.state = (s32)((u32)(0));  // @7_4d4c20
  eax = ((u32(*)(u32))(*(u32 *)0x6763d8))(PV[1]);  // @8_4d4c20
  ecx = edx = 0;  // @9_4d4c20
  if ((eax & eax) == 0) goto L4d4c75;  // @10_4d4c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @11_4d4c20
  if ((eax & eax) == 0) goto L4d4c74;  // @12_4d4c20
  eax = ((u32(STDCALL *)(void))(eax))();  // @13_4d4c20
  ecx = edx = 0;  // @14_4d4c20
  goto L4d4c75;  // @15_4d4c20
  L4d4c74:;
  __builtin_trap();  // @17_4d4c20
  L4d4c75:;
  eax = edi;  // @19_4d4c20
  SEH_LEAVE();  // @20_4d4c20
  return eax;  // @21_4d4c20
}
PCREG(4d4c20, lifted_4d4c20);

extern "C" u32 STDCALL lifted_4d4ab0(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66adf6);  // @h_4d4ab0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4d4ab0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d4ab0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4d4ab0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_4d4ab0
  PV[2] = (u32)(esi);  // @4_4d4ab0
  eax = ((u32(*)(u32, u32, u32))(*(u32 *)0x6763e8))(PV[2], PV[1], PV[0]);  // @5_4d4ab0
  ecx = edx = 0;  // @6_4d4ab0
  edi = eax;  // @7_4d4ab0
  PV[3] = (u32)(esi);  // @8_4d4ab0
  reg.state = (s32)((u32)(0));  // @9_4d4ab0
  eax = ((u32(*)(u32))(*(u32 *)0x6763d8))(PV[3]);  // @10_4d4ab0
  ecx = edx = 0;  // @11_4d4ab0
  if ((eax & eax) == 0) goto L4d4b0b;  // @12_4d4ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_4d4ab0
  if ((eax & eax) == 0) goto L4d4b0a;  // @14_4d4ab0
  eax = ((u32(STDCALL *)(void))(eax))();  // @15_4d4ab0
  ecx = edx = 0;  // @16_4d4ab0
  goto L4d4b0b;  // @17_4d4ab0
  L4d4b0a:;
  __builtin_trap();  // @19_4d4ab0
  L4d4b0b:;
  eax = edi;  // @21_4d4ab0
  SEH_LEAVE();  // @22_4d4ab0
  return eax;  // @23_4d4ab0
}
PCREG(4d4ab0, lifted_4d4ab0);

extern "C" u32 STDCALL lifted_4d4ba0(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66adf6);  // @h_4d4ba0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4d4ba0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4d4ba0
  PV[0] = (u32)(esi);  // @2_4d4ba0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4d4ba0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4d4ba0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)0x6763d4))(PV[2], (u32)(1), PV[1], PV[0]);  // @5_4d4ba0
  ecx = edx = 0;  // @6_4d4ba0
  edi = eax;  // @7_4d4ba0
  PV[3] = (u32)(esi);  // @8_4d4ba0
  reg.state = (s32)((u32)(0));  // @9_4d4ba0
  eax = ((u32(*)(u32))(*(u32 *)0x6763d8))(PV[3]);  // @10_4d4ba0
  ecx = edx = 0;  // @11_4d4ba0
  if ((eax & eax) == 0) goto L4d4bfd;  // @12_4d4ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_4d4ba0
  if ((eax & eax) == 0) goto L4d4bfc;  // @14_4d4ba0
  eax = ((u32(STDCALL *)(void))(eax))();  // @15_4d4ba0
  ecx = edx = 0;  // @16_4d4ba0
  goto L4d4bfd;  // @17_4d4ba0
  L4d4bfc:;
  __builtin_trap();  // @19_4d4ba0
  L4d4bfd:;
  eax = edi;  // @21_4d4ba0
  SEH_LEAVE();  // @22_4d4ba0
  return eax;  // @23_4d4ba0
}
PCREG(4d4ba0, lifted_4d4ba0);

extern "C" u32 THISCALL lifted_4d1640(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66930f);  // @h_4d1640
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4d1640
  eax = ext_41e290_cdecl1((u32)(20));  // @1_4d1640
  ecx = edx = 0;  // @2_4d1640
  edi = eax;  // @3_4d1640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4d1640
  reg.state = (s32)((u32)(0));  // @5_4d1640
  if ((edi & edi) == 0) goto L4d16bf;  // @6_4d1640
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_4d1640
  PV[0] = (u32)(esi);  // @8_4d1640
  eax = ext_41e290_cdecl1(PV[0]);  // @9_4d1640
  ecx = edx = 0;  // @10_4d1640
  PV[1] = (u32)(esi);  // @11_4d1640
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_4d1640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @13_4d1640
  PV[3] = (u32)(eax);  // @14_4d1640
  eax = ext_634d22_cdecl3(PV[3], PV[2], PV[1]);  // @15_4d1640
  ecx = edx = 0;  // @16_4d1640
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @17_4d1640
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @18_4d1640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @19_4d1640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @20_4d1640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @21_4d1640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @22_4d1640
  if ((eax & eax) == 0) goto L4d16b9;  // @23_4d1640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @24_4d1640
  goto L4d16bc;  // @25_4d1640
  L4d16b9:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @27_4d1640
  L4d16bc:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @29_4d1640
  L4d16bf:;
  SEH_LEAVE();  // @31_4d1640
  return eax;  // @32_4d1640
}
PCREG(4d1640, lifted_4d1640);

extern "C" u32 THISCALL lifted_5f9720(u32 ecx_in) {
  SEH_ENTER(0x66d198);  // @h_5f9720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5f9720
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f9720
  ecx = 0;  // @2_5f9720
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_5f9720
  eax = (u32)(10);  // @4_5f9720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @5_5f9720
  edx = (u32)(4);  // @6_5f9720
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @7_5f9720
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @8_5f9720
  ecx = (0u - ecx);  // @9_5f9720
  ecx = (ecx | eax);  // @10_5f9720
  PV[0] = (u32)(ecx);  // @11_5f9720
  eax = ext_41e290_cdecl1(PV[0]);  // @12_5f9720
  ecx = edx = 0;  // @13_5f9720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @14_5f9720
  esi = (u32)(edi + 12);  // @15_5f9720
  reg.state = (s32)((u32)(0));  // @16_5f9720
  ecx = esi;  // @17_5f9720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @18_5f9720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_5f9720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @20_5f9720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @21_5f9720
  eax = ext_6014a0_stdcall1((u32)(8));  // @22_5f9720
  ecx = edx = 0;  // @23_5f9720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @24_5f9720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @25_5f9720
  ecx = (u32)(eax + 8);  // @26_5f9720
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @27_5f9720
  if ((eax & eax) == 0) goto L5f97b6;  // @28_5f9720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @29_5f9720
  L5f97b6:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @31_5f9720
  eax = edi;  // @32_5f9720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @33_5f9720
  SEH_LEAVE();  // @34_5f9720
  return eax;  // @35_5f9720
}
PCREG(5f9720, lifted_5f9720);

extern "C" u32 THISCALL lifted_4ccc30(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x669258);  // @h_4ccc30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4ccc30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4ccc30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4ccc30
  edi = (u32)(1);  // @3_4ccc30
  edx = edi;  // @4_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @5_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @6_4ccc30
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) >= (s32)edx) edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_4ccc30
  ecx = (ecx + (u32)(2));  // @8_4ccc30
  eax = edx;  // @9_4ccc30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @10_4ccc30
  eax = (u32)((s32)eax * (s32)ecx);  // @11_4ccc30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @12_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @13_4ccc30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @14_4ccc30
  reg.state = (s32)((u32)(0));  // @15_4ccc30
  { u32 v = (u32)((u32)(6903876)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @16_4ccc30
  eax = ext_41e290_cdecl1((u32)(28));  // @17_4ccc30
  ecx = edx = 0;  // @18_4ccc30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @19_4ccc30
  if ((eax & eax) == 0) goto L4ccce6;  // @20_4ccc30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @21_4ccc30
  ecx = (ecx & (u32)(2147483647));  // @22_4ccc30
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @23_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @24_4ccc30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @25_4ccc30
  if (ecx < edi) ecx = edi;  // @26_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @27_4ccc30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @28_4ccc30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @29_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @30_4ccc30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @31_4ccc30
  goto L4ccced;  // @32_4ccc30
  L4ccce6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @34_4ccc30
  L4ccced:;
  eax = esi;  // @36_4ccc30
  SEH_LEAVE();  // @37_4ccc30
  return eax;  // @38_4ccc30
}
PCREG(4ccc30, lifted_4ccc30);

extern "C" u32 THISCALL lifted_585620(u32 ecx_in) {
  SEH_ENTER(0x66b5ec);  // @h_585620
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_585620
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @1_585620
  { u32 v = (u32)((u32)(6993944)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_585620
  eax = ext_634273_cdecl2(PV[0], (u32)(10));  // @3_585620
  ecx = edx = 0;  // @4_585620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_585620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_585620
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; });  // @7_585620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, PV[1]);  // @8_585620
  ecx = edx = 0;  // @9_585620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; });  // @10_585620
  if ((ecx & ecx) == 0) goto L585677;  // @11_585620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_585620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @13_585620
  ecx = edx = 0;  // @14_585620
  L585677:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 103), sizeof v); (u32)v; });  // @16_585620
  eax = (u32)(954437177);  // @17_585620
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; }));  // @18_585620
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @19_585620
  reg.state = (s32)((u32)(0));  // @20_585620
  edx = (u32)((s32)edx >> (u32)(4));  // @21_585620
  eax = edx;  // @22_585620
  eax = (eax >> (u32)(31));  // @23_585620
  eax = (eax + edx);  // @24_585620
  if (eax == 0) goto L5856a9;  // @25_585620
  eax = (u32)(eax + eax*8);  // @26_585620
  eax = (eax << (u32)(3));  // @27_585620
  ecx = (u32)(esi + 95);  // @28_585620
  PV[2] = (u32)(eax);  // @29_585620
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @30_585620
  eax = ext_54f870_stdcall2(PV[3], PV[2]);  // @31_585620
  ecx = edx = 0;  // @32_585620
  L5856a9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @34_585620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @35_585620
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @36_585620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @37_585620
  PV[4] = (u32)(esi);  // @38_585620
  reg.state = (s32)((u32)(1));  // @39_585620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @40_585620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_585620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[4]);  // @42_585620
  ecx = edx = 0;  // @43_585620
  SEH_LEAVE();  // @44_585620
  return eax;  // @45_585620
}
PCREG(585620, lifted_585620);




extern "C" u32 THISCALL lifted_606b80(u32 ecx_in) {
  SEH_ENTER(0x66df71);  // @h_606b80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_606b80
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_606b80
  ecx = (u32)(ebx + 4);  // @2_606b80
  { u32 v = (u32)((u32)(7053004)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @3_606b80
  eax = ext_606a70_thiscall1(ecx);  // @4_606b80
  ecx = edx = 0;  // @5_606b80
  ecx = (u32)(ebx + 23);  // @6_606b80
  reg.state = (s32)((u32)(0));  // @7_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @8_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @9_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @10_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 35), &v, sizeof v); }  // @11_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 39), &v, sizeof v); }  // @12_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 43), &v, sizeof v); }  // @13_606b80
  reg.state = (s32)((u32)(2));  // @14_606b80
  eax = ext_607310_thiscall2(ecx, (u32)(200));  // @15_606b80
  ecx = edx = 0;  // @16_606b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 35), sizeof v); (u32)v; });  // @17_606b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 43), sizeof v); (u32)v; });  // @18_606b80
  eax = (eax - ecx);  // @19_606b80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @20_606b80
  eax = (u32)((s32)eax >> (u32)(1));  // @21_606b80
  if (eax >= (u32)(200)) goto L606c70;  // @22_606b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 39), sizeof v); (u32)v; });  // @23_606b80
  eax = esi;  // @24_606b80
  eax = (eax - ecx);  // @25_606b80
  ecx = (u32)(ebx + 35);  // @26_606b80
  eax = (u32)((s32)eax >> (u32)(1));  // @27_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @28_606b80
  eax = ext_6014a0_stdcall1((u32)(400));  // @29_606b80
  ecx = edx = 0;  // @30_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @31_606b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @32_606b80
  esi = (esi - eax);  // @33_606b80
  esi = (esi & (u32)(4294967294));  // @34_606b80
  PV[0] = (u32)(esi);  // @35_606b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @36_606b80
  PV[1] = (u32)(eax);  // @37_606b80
  PV[2] = (u32)(esi);  // @38_606b80
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676278))(PV[2], PV[1], PV[0]);  // @39_606b80
  ecx = edx = 0;  // @40_606b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 43), sizeof v); (u32)v; });  // @41_606b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 35), sizeof v); (u32)v; });  // @42_606b80
  eax = (eax - ecx);  // @43_606b80
  eax = (u32)((s32)eax >> (u32)(1));  // @44_606b80
  if (eax == 0) goto L606c5b;  // @45_606b80
  eax = (eax + eax);  // @46_606b80
  PV[3] = (u32)(eax);  // @47_606b80
  PV[4] = (u32)(ecx);  // @48_606b80
  ecx = (u32)(ebx + 35);  // @49_606b80
  eax = ext_54f870_stdcall2(PV[4], PV[3]);  // @50_606b80
  ecx = edx = 0;  // @51_606b80
  L606c5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @53_606b80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 35), &v, sizeof v); }  // @54_606b80
  eax = (u32)(esi + eax*2);  // @55_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 39), &v, sizeof v); }  // @56_606b80
  eax = (u32)(esi + 400);  // @57_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 43), &v, sizeof v); }  // @58_606b80
  L606c70:;
  eax = ebx;  // @60_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 47), &v, sizeof v); }  // @61_606b80
  SEH_LEAVE();  // @62_606b80
  return eax;  // @63_606b80
}
PCREG(606b80, lifted_606b80);



extern "C" u32 THISCALL lifted_6162f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e5c8);  // @h_6162f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_6162f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6162f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6162f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @3_6162f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @4_6162f0
  { u32 v = (u32)((u32)(7068968)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @5_6162f0
  eax = (u32)(ecx + 12);  // @6_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @7_6162f0
  edi = (u32)(ecx + 36);  // @8_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @9_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @11_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @12_6162f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47536), sizeof v); (u32)v; });  // @13_6162f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47524), sizeof v); (u32)v; });  // @14_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @15_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_6162f0
  reg.state = (s32)((u32)(0));  // @17_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @18_6162f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @19_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @20_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @21_6162f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @22_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @23_6162f0
  eax = (eax + ecx);  // @24_6162f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @25_6162f0
  PV[1] = (u32)(eax);  // @26_6162f0
  eax = ext_659220_thiscall3(ecx, PV[1], PV[0]);  // @27_6162f0
  ecx = edx = 0;  // @28_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @29_6162f0
  ecx = edi;  // @30_6162f0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47532), sizeof v); (u32)v; });  // @31_6162f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 14), sizeof v); (u32)v; });  // @32_6162f0
  PV[3] = (u32)(eax);  // @33_6162f0
  eax = ext_659330_thiscall3(ecx, PV[3], PV[2]);  // @34_6162f0
  ecx = edx = 0;  // @35_6162f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5122), sizeof v); (u32)v; });  // @36_6162f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5130), sizeof v); (u32)v; });  // @37_6162f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @38_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) == (u32)(0)) goto L6163f0;  // @39_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L6163ce;  // @40_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @41_6162f0
  ecx = ebx;  // @42_6162f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @43_6162f0
  ecx = edx = 0;  // @44_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @45_6162f0
  L6163ce:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_6162f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @48_6162f0
  eax = (u32)((s32)eax * (s32)(u32)(52));  // @49_6162f0
  PV[4] = (u32)(eax);  // @50_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @51_6162f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @52_6162f0
  PV[5] = (u32)(eax);  // @53_6162f0
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) * (s32)(u32)(52));  // @54_6162f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; }));  // @55_6162f0
  PV[6] = (u32)(eax);  // @56_6162f0
  eax = ext_634d22_cdecl3(PV[6], PV[5], PV[4]);  // @57_6162f0
  ecx = edx = 0;  // @58_6162f0
  L6163f0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L616472;  // @60_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L61640a;  // @61_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_6162f0
  ecx = edi;  // @63_6162f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @64_6162f0
  ecx = edx = 0;  // @65_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @66_6162f0
  L61640a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @68_6162f0
  ebx = 0;  // @69_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @70_6162f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @71_6162f0
  edi = (edi + (u32)(2));  // @72_6162f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @73_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @74_6162f0
  edi = (edi + eax);  // @75_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= ebx) goto L616472;  // @76_6162f0
  L616425:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @78_6162f0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_6162f0
  edi = (edi + (u32)(2));  // @80_6162f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @81_6162f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*8 + 4), sizeof v); (u32)v; }) & (u32)(2147483647))); __builtin_memcpy((void *)(u32)(eax + ebx*8 + 4), &v, sizeof v); }  // @82_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*8 + 4), sizeof v); (u32)v; });  // @83_6162f0
  eax = (u32)(edx + eax*2);  // @84_6162f0
  if ((ecx & ecx) == 0) goto L616469;  // @85_6162f0
  esi = edi;  // @86_6162f0
  edx = ecx;  // @87_6162f0
  esi = (esi - eax);  // @88_6162f0
  L616450:;
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; })) & 0xffff);  // @90_6162f0
  eax = (u32)(eax + 2);  // @91_6162f0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax - 2), &v, sizeof v); }  // @92_6162f0
  edx = (edx - (u32)(1));  // @93_6162f0
  if (edx != 0) goto L616450;  // @94_6162f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @95_6162f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @96_6162f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @97_6162f0
  L616469:;
  ebx = (ebx + 1);  // @99_6162f0
  edi = (u32)(edi + ecx*2);  // @100_6162f0
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L616425;  // @101_6162f0
  L616472:;
  eax = esi;  // @103_6162f0
  SEH_LEAVE();  // @104_6162f0
  return eax;  // @105_6162f0
}
PCREG(6162f0, lifted_6162f0);





