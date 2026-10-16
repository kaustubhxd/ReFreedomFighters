// batch218003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_473a70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_473a70
  u8 F[0x4220] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x4120);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4120 + 8, &a0, 4);
  edi = ecx;  // @0_473a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_473a70
  ecx = (u32)(EBP - 16596);  // @2_473a70
  eax = ext_4d2280_thiscall1(ecx);  // @3_473a70
  ecx = edx = 0;  // @4_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_473a70
  PV[0] = (u32)(esi);  // @6_473a70
  reg.state = (s32)((u32)(0));  // @7_473a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_473a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @10_473a70
  ecx = edx = 0;  // @11_473a70
  PV[1] = (u32)(eax);  // @12_473a70
  ecx = (u32)(EBP - 16596);  // @13_473a70
  eax = ext_4d3ab0_stdcall2((u32)(6851120), PV[1]);  // @14_473a70
  ecx = edx = 0;  // @15_473a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_473a70
  eax = (u32)(EBP - 16596);  // @17_473a70
  PV[2] = (u32)(eax);  // @18_473a70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338404), sizeof v); (u32)v; });  // @19_473a70
  ecx = edi;  // @20_473a70
  PV[3] = (u32)(eax);  // @21_473a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, PV[3], PV[2]);  // @22_473a70
  ecx = edx = 0;  // @23_473a70
  ecx = (u32)(EBP - 16596);  // @24_473a70
  eax = ext_4d2330_thiscall1(ecx);  // @25_473a70
  ecx = edx = 0;  // @26_473a70
  SEH_LEAVE();  // @27_473a70
  ext_633654(G(u32, 0x6f5630));  // @28_473a70
  return eax;  // @29_473a70
}
PCREG(473a70, lifted_473a70);

extern "C" u32 THISCALL lifted_474f60(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_474f60
  u8 F[0x4220] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x4120);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4120 + 8, &a0, 4);
  edi = ecx;  // @0_474f60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_474f60
  ecx = (u32)(EBP - 16596);  // @2_474f60
  eax = ext_4d2280_thiscall1(ecx);  // @3_474f60
  ecx = edx = 0;  // @4_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474f60
  PV[0] = (u32)(esi);  // @6_474f60
  reg.state = (s32)((u32)(0));  // @7_474f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_474f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @10_474f60
  ecx = edx = 0;  // @11_474f60
  PV[1] = (u32)(eax);  // @12_474f60
  ecx = (u32)(EBP - 16596);  // @13_474f60
  eax = ext_4d3ab0_stdcall2((u32)(6851120), PV[1]);  // @14_474f60
  ecx = edx = 0;  // @15_474f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_474f60
  eax = (u32)(EBP - 16596);  // @17_474f60
  PV[2] = (u32)(eax);  // @18_474f60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338400), sizeof v); (u32)v; });  // @19_474f60
  ecx = edi;  // @20_474f60
  PV[3] = (u32)(eax);  // @21_474f60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, PV[3], PV[2]);  // @22_474f60
  ecx = edx = 0;  // @23_474f60
  ecx = (u32)(EBP - 16596);  // @24_474f60
  eax = ext_4d2330_thiscall1(ecx);  // @25_474f60
  ecx = edx = 0;  // @26_474f60
  SEH_LEAVE();  // @27_474f60
  ext_633654(G(u32, 0x6f5630));  // @28_474f60
  return eax;  // @29_474f60
}
PCREG(474f60, lifted_474f60);

extern "C" u32 THISCALL lifted_4353b0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4353b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(edx);  // @9_4353b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4353b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[0], (u32)(6792636), (u32)(8));  // @11_4353b0
  ecx = edx = 0;  // @12_4353b0
  eax = (u32)(EBP - 144);  // @13_4353b0
  PV[1] = (u32)(eax);  // @14_4353b0
  ecx = (u32)(EBP - 272);  // @15_4353b0
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @16_4353b0
  ecx = edx = 0;  // @17_4353b0
  eax = (u32)(EBP - 272);  // @18_4353b0
  reg.state = (s32)((u32)(0));  // @19_4353b0
  PV[2] = (u32)(eax);  // @20_4353b0
  ecx = (u32)(esi + 12);  // @21_4353b0
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @22_4353b0
  ecx = edx = 0;  // @23_4353b0
  ecx = (u32)(EBP - 272);  // @24_4353b0
  eax = ext_4cbec0_thiscall1(ecx);  // @25_4353b0
  ecx = edx = 0;  // @26_4353b0
  SEH_LEAVE();  // @27_4353b0
  ext_633654(G(u32, 0x6f5630));  // @28_4353b0
  return eax;  // @29_4353b0
  L43545d:;
  eax = ext_634047_cdecl0();  // @31_4353b0
  ecx = edx = 0;  // @32_4353b0
}
PCREG(4353b0, lifted_4353b0);

extern "C" u32 THISCALL lifted_4cb150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66906b);  // @h_4cb150
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(eax);  // @19_4cb150
  ecx = edi;  // @20_4cb150
  eax = ext_4e6330_thiscall2(ecx, PV[0]);  // @21_4cb150
  ecx = edx = 0;  // @22_4cb150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4cb150
  ecx = (u32)(EBP - 188);  // @24_4cb150
  PV[1] = (u32)(ecx);  // @25_4cb150
  ecx = esi;  // @26_4cb150
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[1]);  // @27_4cb150
  ecx = edx = 0;  // @28_4cb150
  ecx = (u32)(EBP - 188);  // @29_4cb150
  eax = ext_4ccf60_thiscall1(ecx);  // @30_4cb150
  ecx = edx = 0;  // @31_4cb150
  SEH_LEAVE();  // @32_4cb150
  ext_633654(G(u32, 0x6f5630));  // @33_4cb150
  return eax;  // @34_4cb150
}
PCREG(4cb150, lifted_4cb150);






