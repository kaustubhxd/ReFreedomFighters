// batch218023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42ae00_fastcall3(u32, u32, u32) __asm__("ext_42ae00");
extern "C" u32 FASTCALL ext_42aee0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42aee0");
extern "C" u32 FASTCALL ext_42b1e0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42b1e0");
extern "C" u32 FASTCALL ext_430620_fastcall4(u32, u32, u32, u32) __asm__("ext_430620");
extern "C" u32 FASTCALL ext_49f9b0_fastcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_49f9b0");
extern "C" u32 FASTCALL ext_4cc780_fastcall2(u32, u32) __asm__("ext_4cc780");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4cd9b0_fastcall4(u32, u32, u32, u32) __asm__("ext_4cd9b0");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_5fed20_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5fed20");
extern "C" u32 STDCALL ext_4309b0_stdcall1(u32) __asm__("ext_4309b0");
extern "C" u32 STDCALL ext_4c4f10_stdcall3(u32, u32, u32) __asm__("ext_4c4f10");
extern "C" u32 STDCALL ext_4d06a0_stdcall1(u32) __asm__("ext_4d06a0");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_5c6370_stdcall2(u32, u32) __asm__("ext_5c6370");
extern "C" u32 STDCALL ext_5ff140_stdcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5ff140");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 STDCALL ext_634123_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_634123");
extern "C" u32 THISCALL ext_42b390_thiscall3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_4301c0_thiscall3(u32, u32, u32) __asm__("ext_4301c0");
extern "C" u32 THISCALL ext_4302d0_thiscall3(u32, u32, u32) __asm__("ext_4302d0");
extern "C" u32 THISCALL ext_430c70_thiscall3(u32, u32, u32) __asm__("ext_430c70");
extern "C" u32 THISCALL ext_430d10_thiscall4(u32, u32, u32, u32) __asm__("ext_430d10");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_4367b0_thiscall3(u32, u32, u32) __asm__("ext_4367b0");
extern "C" u32 THISCALL ext_4369a0_thiscall3(u32, u32, u32) __asm__("ext_4369a0");
extern "C" u32 THISCALL ext_436b30_thiscall3(u32, u32, u32) __asm__("ext_436b30");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_441c00_thiscall1(u32) __asm__("ext_441c00");
extern "C" u32 THISCALL ext_444530_thiscall1(u32) __asm__("ext_444530");
extern "C" u32 THISCALL ext_456b70_thiscall3(u32, u32, u32) __asm__("ext_456b70");
extern "C" u32 THISCALL ext_45c560_thiscall2(u32, u32) __asm__("ext_45c560");
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_45f420_thiscall1(u32) __asm__("ext_45f420");
extern "C" u32 THISCALL ext_4634f0_thiscall2(u32, u32) __asm__("ext_4634f0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_472fd0_thiscall1(u32) __asm__("ext_472fd0");
extern "C" u32 THISCALL ext_48b530_thiscall3(u32, u32, u32) __asm__("ext_48b530");
extern "C" u32 THISCALL ext_4957f0_thiscall3(u32, u32, u32) __asm__("ext_4957f0");
extern "C" u32 THISCALL ext_496a40_thiscall1(u32) __asm__("ext_496a40");
extern "C" u32 THISCALL ext_497750_thiscall2(u32, u32) __asm__("ext_497750");
extern "C" u32 THISCALL ext_497930_thiscall1(u32) __asm__("ext_497930");
extern "C" u32 THISCALL ext_49d220_thiscall4(u32, u32, u32, u32) __asm__("ext_49d220");
extern "C" u32 THISCALL ext_4a85a0_thiscall2(u32, u32) __asm__("ext_4a85a0");
extern "C" u32 THISCALL ext_4c3e80_thiscall1(u32) __asm__("ext_4c3e80");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cc930_thiscall3(u32, u32, u32) __asm__("ext_4cc930");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4cda40_thiscall3(u32, u32, u32) __asm__("ext_4cda40");
extern "C" u32 THISCALL ext_4cdd40_thiscall1(u32) __asm__("ext_4cdd40");
extern "C" u32 THISCALL ext_4ce5b0_thiscall2(u32, u32) __asm__("ext_4ce5b0");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d8ce0_thiscall2(u32, u32) __asm__("ext_4d8ce0");
extern "C" u32 THISCALL ext_4d9350_thiscall3(u32, u32, u32) __asm__("ext_4d9350");
extern "C" u32 THISCALL ext_4d93e0_thiscall1(u32) __asm__("ext_4d93e0");
extern "C" u32 THISCALL ext_4d9430_thiscall1(u32) __asm__("ext_4d9430");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4da6d0_thiscall1(u32) __asm__("ext_4da6d0");
extern "C" u32 THISCALL ext_4db2c0_thiscall3(u32, u32, u32) __asm__("ext_4db2c0");
extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4db7e0_thiscall1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4dcdf0_thiscall2(u32, u32) __asm__("ext_4dcdf0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0f60_thiscall2(u32, u32) __asm__("ext_4e0f60");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e3f00_thiscall1(u32) __asm__("ext_4e3f00");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_4e8450_thiscall2(u32, u32) __asm__("ext_4e8450");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_523650_thiscall2(u32, u32) __asm__("ext_523650");
extern "C" u32 THISCALL ext_52cb60_thiscall3(u32, u32, u32) __asm__("ext_52cb60");
extern "C" u32 THISCALL ext_530fd0_thiscall2(u32, u32) __asm__("ext_530fd0");
extern "C" u32 THISCALL ext_57c500_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_57c500");
extern "C" u32 THISCALL ext_57c910_thiscall2(u32, u32) __asm__("ext_57c910");
extern "C" u32 THISCALL ext_57d780_thiscall1(u32) __asm__("ext_57d780");
extern "C" u32 THISCALL ext_57d950_thiscall2(u32, u32) __asm__("ext_57d950");
extern "C" u32 THISCALL ext_57ee90_thiscall1(u32) __asm__("ext_57ee90");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5acad0_thiscall3(u32, u32, u32) __asm__("ext_5acad0");
extern "C" u32 THISCALL ext_5b6ab0_thiscall2(u32, u32) __asm__("ext_5b6ab0");
extern "C" u32 THISCALL ext_5eaab0_thiscall3(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL ext_5ebae0_thiscall2(u32, u32) __asm__("ext_5ebae0");
extern "C" u32 THISCALL ext_5ec720_thiscall2(u32, u32) __asm__("ext_5ec720");
extern "C" u32 THISCALL ext_5ed460_thiscall1(u32) __asm__("ext_5ed460");
extern "C" u32 THISCALL ext_5edd80_thiscall2(u32, u32) __asm__("ext_5edd80");
extern "C" u32 THISCALL ext_5eec40_thiscall1(u32) __asm__("ext_5eec40");
extern "C" u32 THISCALL ext_5ef080_thiscall1(u32) __asm__("ext_5ef080");
extern "C" u32 THISCALL ext_5efd10_thiscall1(u32) __asm__("ext_5efd10");
extern "C" u32 THISCALL ext_5f0020_thiscall1(u32) __asm__("ext_5f0020");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_5f5520_thiscall3(u32, u32, u32) __asm__("ext_5f5520");
extern "C" u32 THISCALL ext_5f55e0_thiscall1(u32) __asm__("ext_5f55e0");
extern "C" u32 THISCALL ext_5fa380_thiscall3(u32, u32, u32) __asm__("ext_5fa380");
extern "C" u32 THISCALL ext_5fb110_thiscall2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 THISCALL ext_5fb980_thiscall3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 THISCALL ext_5fe920_thiscall3(u32, u32, u32) __asm__("ext_5fe920");
extern "C" u32 THISCALL ext_5fef70_thiscall2(u32, u32) __asm__("ext_5fef70");
extern "C" u32 THISCALL ext_5ff0a0_thiscall1(u32) __asm__("ext_5ff0a0");
extern "C" u32 THISCALL ext_600260_thiscall3(u32, u32, u32) __asm__("ext_600260");
extern "C" u32 THISCALL ext_600e40_thiscall3(u32, u32, u32) __asm__("ext_600e40");
extern "C" u32 THISCALL ext_602290_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_639c50_thiscall2(u32, u32) __asm__("ext_639c50");
extern "C" u32 THISCALL ext_639df0_thiscall3(u32, u32, u32) __asm__("ext_639df0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_42ab0d_cdecl6(...) __asm__("ext_42ab0d");
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" u32 ext_46bca0_cdecl0(void) __asm__("ext_46bca0");
extern "C" u32 ext_4a2f90_cdecl0(void) __asm__("ext_4a2f90");
extern "C" u32 ext_4d9590_cdecl1(...) __asm__("ext_4d9590");
extern "C" u32 ext_5fa630_cdecl0(void) __asm__("ext_5fa630");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_430a20(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66534c);  // @h_430a20
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_430a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_430a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_430a20
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5), sizeof v); (u32)v; });  // @4_430a20
  if (FL[0] != FL[1]) goto L430a98;  // @5_430a20
  FL[0] = esi; FL[1] = edx;  // @6_430a20
  if (FL[0] != FL[1]) goto L430a98;  // @7_430a20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_430a20
  if (FL[0] == FL[1]) goto L430b52;  // @9_430a20
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @10_430a20
  eax = ext_430010_thiscall2(ecx, PV[0]);  // @11_430a20
  ecx = edx = 0;  // @12_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @14_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_430a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @16_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @18_430a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @19_430a20
  SEH_LEAVE();  // @20_430a20
  return eax;  // @21_430a20
  L430a98:;
  FL[0] = eax; FL[1] = esi;  // @23_430a20
  if (FL[0] == FL[1]) goto L430b52;  // @24_430a20
  L430aa0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; });  // @26_430a20
  esi = eax;  // @27_430a20
  FL[2] = (ecx & ecx);  // @28_430a20
  if (FL[2] == 0) goto L430abf;  // @29_430a20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @30_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; });  // @31_430a20
  FL[2] = (eax & eax);  // @32_430a20
  if (FL[2] == 0) goto L430add;  // @33_430a20
  L430ab3:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @35_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5), sizeof v); (u32)v; });  // @36_430a20
  FL[2] = (eax & eax);  // @37_430a20
  if (FL[2] != 0) goto L430ab3;  // @38_430a20
  goto L430add;  // @39_430a20
  L430abf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @41_430a20
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; });  // @42_430a20
  if (FL[0] != FL[1]) goto L430ad4;  // @43_430a20
  L430ac7:;
  eax = ecx;  // @45_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @46_430a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @47_430a20
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; });  // @48_430a20
  if (FL[0] == FL[1]) goto L430ac7;  // @49_430a20
  L430ad4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; }); FL[1] = ecx;  // @51_430a20
  if (FL[0] != FL[1]) eax = ecx;  // @52_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @53_430a20
  L430add:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @55_430a20
  ecx = esi;  // @56_430a20
  eax = (u32)(edx + 9);  // @57_430a20
  PV[1] = (u32)(eax);  // @58_430a20
  eax = (u32)(edx + 5);  // @59_430a20
  edx = (edx + 1);  // @60_430a20
  FL[3] = edx;  // @61_430a20
  PV[2] = (u32)(eax);  // @62_430a20
  eax = ext_430620_fastcall4(ecx, edx, PV[2], PV[1]);  // @63_430a20
  ecx = edx = 0;  // @64_430a20
  ebx = eax;  // @65_430a20
  ecx = (u32)(ebx + 25);  // @66_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_430a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @68_430a20
  edx = (edx - eax);  // @69_430a20
  FL[3] = edx;  // @70_430a20
  reg.state = (s32)((u32)(0));  // @71_430a20
  FL[2] = (eax & eax);  // @72_430a20
  if (FL[2] == 0) goto L430b11;  // @73_430a20
  FL[2] = (edx & edx);  // @74_430a20
  if (FL[2] == 0) goto L430b11;  // @75_430a20
  PV[3] = (u32)(edx);  // @76_430a20
  PV[4] = (u32)(eax);  // @77_430a20
  eax = ext_54f870_stdcall2(PV[4], PV[3]);  // @78_430a20
  ecx = edx = 0;  // @79_430a20
  L430b11:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 13), sizeof v); (u32)v; });  // @81_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21), sizeof v); (u32)v; });  // @82_430a20
  eax = (eax - edx);  // @83_430a20
  FL[3] = eax;  // @84_430a20
  reg.state = (s32)((u32)(1));  // @85_430a20
  FL[2] = (edx & edx);  // @86_430a20
  if (FL[2] == 0) goto L430b32;  // @87_430a20
  FL[2] = (eax & eax);  // @88_430a20
  if (FL[2] == 0) goto L430b32;  // @89_430a20
  PV[5] = (u32)(eax);  // @90_430a20
  PV[6] = (u32)(edx);  // @91_430a20
  ecx = (u32)(ebx + 13);  // @92_430a20
  eax = ext_54f870_stdcall2(PV[6], PV[5]);  // @93_430a20
  ecx = edx = 0;  // @94_430a20
  L430b32:;
  PV[7] = (u32)(ebx);  // @96_430a20
  ecx = edi;  // @97_430a20
  reg.state = (s32)((u32)(4294967295));  // @98_430a20
  eax = ext_54f870_stdcall2(PV[7], (u32)(37));  // @99_430a20
  ecx = edx = 0;  // @100_430a20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @101_430a20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @102_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @103_430a20
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @104_430a20
  if (FL[0] != FL[1]) goto L430aa0;  // @105_430a20
  L430b52:;
  SEH_LEAVE();  // @107_430a20
  return eax;  // @108_430a20
}
PCREG(430a20, lifted_430a20);
