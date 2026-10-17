// batch218022.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
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
extern "C" u32 THISCALL ext_4d6400_thiscall1(u32) __asm__("ext_4d6400");
extern "C" u32 THISCALL ext_4d6a10_thiscall2(u32, u32) __asm__("ext_4d6a10");
extern "C" u32 THISCALL ext_4d6c60_thiscall1(u32) __asm__("ext_4d6c60");
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





extern "C" u32 THISCALL lifted_49a240(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66825f);  // @h_49a240
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_49a240
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_49a240
  if (FL[0] != FL[1]) goto L49a2a6;  // @2_49a240
  eax = ext_41e290_cdecl1((u32)(28));  // @3_49a240
  ecx = edx = 0;  // @4_49a240
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_49a240
  reg.state = (s32)((u32)(0));  // @6_49a240
  FL[2] = (eax & eax);  // @7_49a240
  if (FL[2] == 0) goto L49a297;  // @8_49a240
  ecx = eax;  // @9_49a240
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(2));  // @10_49a240
  ecx = edx = 0;  // @11_49a240
  goto L49a299;  // @12_49a240
  L49a297:;
  eax = 0;  // @14_49a240
  FL[3] = eax;  // @15_49a240
  L49a299:;
  reg.state = (s32)((u32)(4294967295));  // @17_49a240
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 312), &v, sizeof v); }  // @18_49a240
  L49a2a6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @20_49a240
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_49a240
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_49a240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[0]);  // @23_49a240
  ecx = edx = 0;  // @24_49a240
  ecx = eax;  // @25_49a240
  FL[2] = (ecx & ecx);  // @26_49a240
  if (FL[2] != 0) goto L49a2d8;  // @27_49a240
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @28_49a240
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @29_49a240
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_49a240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[1]);  // @31_49a240
  ecx = edx = 0;  // @32_49a240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @33_49a240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @34_49a240
  ecx = (u32)(eax - 4);  // @35_49a240
  L49a2d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @37_49a240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @38_49a240
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @39_49a240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @40_49a240
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @41_49a240
  SEH_LEAVE();  // @42_49a240
  return eax;  // @43_49a240
}
PCREG(49a240, lifted_49a240);
























































extern "C" u32 THISCALL lifted_431e40(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x6654f6);  // @h_431e40
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0};
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  edi = ecx;  // @0_431e40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_431e40
  ecx = (u32)(EBP - 324);  // @2_431e40
  eax = ext_4cbeb0_thiscall1(ecx);  // @3_431e40
  ecx = edx = 0;  // @4_431e40
  PV[0] = (u32)(esi);  // @5_431e40
  ecx = (u32)(EBP - 144);  // @6_431e40
  reg.state = (s32)((u32)(0));  // @7_431e40
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @8_431e40
  ecx = edx = 0;  // @9_431e40
  eax = (u32)(EBP - 144);  // @10_431e40
  reg.state = (s32)((u32)(1));  // @11_431e40
  PV[1] = (u32)(eax);  // @12_431e40
  ecx = (u32)(EBP - 324);  // @13_431e40
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @14_431e40
  ecx = edx = 0;  // @15_431e40
  ecx = (u32)(EBP - 144);  // @16_431e40
  reg.state = (s32)((u32)(0));  // @17_431e40
  eax = ext_4cbec0_thiscall1(ecx);  // @18_431e40
  ecx = edx = 0;  // @19_431e40
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; })) & 0xff);  // @20_431e40
  ecx = (u32)(EBP - 324);  // @21_431e40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 0), 4); v; });  // @22_431e40
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 4), 4); v; });  // @23_431e40
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 8), 4); v; });  // @24_431e40
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 12), 4); v; });  // @25_431e40
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @26_431e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @27_431e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @28_431e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @29_431e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @30_431e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @31_431e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @32_431e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @33_431e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @34_431e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @35_431e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @36_431e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_431e40
  PV[2] = (u32)(ecx);  // @38_431e40
  ecx = edi;  // @39_431e40
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 159), &v, sizeof v); }  // @40_431e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 149), &v, sizeof v); }  // @41_431e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 157), &v, sizeof v); }  // @42_431e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @43_431e40
  __builtin_memcpy((void *)((u32)(EBP - 180) + 0), &X0[0], 4);  // @44_431e40
  __builtin_memcpy((void *)((u32)(EBP - 180) + 4), &X0[1], 4);  // @45_431e40
  __builtin_memcpy((void *)((u32)(EBP - 180) + 8), &X0[2], 4);  // @46_431e40
  __builtin_memcpy((void *)((u32)(EBP - 180) + 12), &X0[3], 4);  // @47_431e40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[2]);  // @48_431e40
  ecx = edx = 0;  // @49_431e40
  ecx = (u32)(EBP - 324);  // @50_431e40
  esi = eax;  // @51_431e40
  eax = ext_4cbec0_thiscall1(ecx);  // @52_431e40
  ecx = edx = 0;  // @53_431e40
  eax = esi;  // @54_431e40
  SEH_LEAVE();  // @55_431e40
  ext_633654(G(u32, 0x6f5630));  // @56_431e40
  return eax;  // @57_431e40
}
PCREG(431e40, lifted_431e40);














extern "C" u32 THISCALL lifted_4d6aa0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6695a5);  // @h_4d6aa0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0};
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_4d6aa0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 13), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4d6aa0
  if (FL[0] == FL[1]) goto L4d6ad2;  // @2_4d6aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_4d6aa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 56)))(ecx);  // @4_4d6aa0
  ecx = edx = 0;  // @5_4d6aa0
  L4d6ad2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_4d6aa0
  FL[0] = esi; FL[1] = (u32)(5);  // @8_4d6aa0
  if (FL[0] != FL[1]) goto L4d6b0d;  // @9_4d6aa0
  eax = ext_41e290_cdecl1((u32)(16));  // @10_4d6aa0
  ecx = edx = 0;  // @11_4d6aa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_4d6aa0
  FL[2] = (eax & eax);  // @13_4d6aa0
  if (FL[2] == 0) goto L4d6b08;  // @14_4d6aa0
  { u32 v = (u32)((u32)(6907724)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @15_4d6aa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @16_4d6aa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @17_4d6aa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @18_4d6aa0
  goto L4d6b0a;  // @19_4d6aa0
  L4d6b08:;
  eax = 0;  // @21_4d6aa0
  FL[3] = eax;  // @22_4d6aa0
  L4d6b0a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 21), &v, sizeof v); }  // @24_4d6aa0
  L4d6b0d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @26_4d6aa0
  FL[0] = esi; FL[1] = (u32)(1);  // @27_4d6aa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @28_4d6aa0
  eax = (u32)(6908624);  // @29_4d6aa0
  { u32 v = (u32)((u32)(6786252)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_4d6aa0
  if (FL[0] != FL[1]) eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @31_4d6aa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4d6aa0
  PV[0] = (u32)(eax);  // @33_4d6aa0
  PV[1] = (u32)(esi);  // @34_4d6aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @35_4d6aa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[1], PV[0]);  // @36_4d6aa0
  ecx = edx = 0;  // @37_4d6aa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 17), &v, sizeof v); }  // @38_4d6aa0
  FL[2] = (eax & eax);  // @39_4d6aa0
  if (FL[2] == 0) goto L4d6c18;  // @40_4d6aa0
  ecx = esi;  // @41_4d6aa0
  edx = (u32)(ecx + 1);  // @42_4d6aa0
  L4d6b40:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @44_4d6aa0
  ecx = (ecx + 1);  // @45_4d6aa0
  FL[3] = ecx;  // @46_4d6aa0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @47_4d6aa0
  if (FL[2] != 0) goto L4d6b40;  // @48_4d6aa0
  ecx = (ecx - edx);  // @49_4d6aa0
  FL[3] = ecx;  // @50_4d6aa0
  eax = (u32)(ecx + 1);  // @51_4d6aa0
  PV[2] = (u32)(eax);  // @52_4d6aa0
  eax = ext_41e290_cdecl1(PV[2]);  // @53_4d6aa0
  ecx = edx = 0;  // @54_4d6aa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 13), &v, sizeof v); }  // @55_4d6aa0
  eax = (eax - esi);  // @56_4d6aa0
  FL[3] = eax;  // @57_4d6aa0
  L4d6b60:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @59_4d6aa0
  esi = (u32)(esi + 1);  // @60_4d6aa0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + esi - 1), &v, sizeof v); }  // @61_4d6aa0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @62_4d6aa0
  if (FL[2] != 0) goto L4d6b60;  // @63_4d6aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @64_4d6aa0
  ecx = (u32)(edi + 70);  // @65_4d6aa0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @66_4d6aa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 9), &v, sizeof v); }  // @67_4d6aa0
  eax = ext_4d6a10_thiscall2(ecx, (u32)(256));  // @68_4d6aa0
  ecx = edx = 0;  // @69_4d6aa0
  ecx = (u32)(edi + 82);  // @70_4d6aa0
  eax = ext_4d6a10_thiscall2(ecx, (u32)(8));  // @71_4d6aa0
  ecx = edx = 0;  // @72_4d6aa0
  X0[0] = 0;  // @73_4d6aa0
  X0[1] = 0;  // @74_4d6aa0
  X0[2] = 0;  // @75_4d6aa0
  X0[3] = 0;  // @76_4d6aa0
  ecx = edi;  // @77_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 34) + 0), &X0[0], 4);  // @78_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 34) + 4), &X0[1], 4);  // @79_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 34) + 8), &X0[2], 4);  // @80_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 34) + 12), &X0[3], 4);  // @81_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 50) + 0), &X0[0], 4);  // @82_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 50) + 4), &X0[1], 4);  // @83_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 50) + 8), &X0[2], 4);  // @84_4d6aa0
  __builtin_memcpy((void *)((u32)(edi + 50) + 12), &X0[3], 4);  // @85_4d6aa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 66), &v, sizeof v); }  // @86_4d6aa0
  eax = ext_4d6400_thiscall1(ecx);  // @87_4d6aa0
  ecx = edx = 0;  // @88_4d6aa0
  eax = ext_41e290_cdecl1((u32)(182));  // @89_4d6aa0
  ecx = edx = 0;  // @90_4d6aa0
  esi = eax;  // @91_4d6aa0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @92_4d6aa0
  reg.state = (s32)((u32)(0));  // @93_4d6aa0
  FL[2] = (esi & esi);  // @94_4d6aa0
  if (FL[2] == 0) goto L4d6be6;  // @95_4d6aa0
  ecx = (u32)(esi + 4);  // @96_4d6aa0
  reg.state = (s32)((u32)(1));  // @97_4d6aa0
  { u32 v = (u32)((u32)(6907972)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @98_4d6aa0
  eax = ext_4d8ce0_thiscall2(ecx, (u32)(32));  // @99_4d6aa0
  ecx = edx = 0;  // @100_4d6aa0
  ecx = (u32)(esi + 10);  // @101_4d6aa0
  reg.state = (s32)((u32)(2));  // @102_4d6aa0
  eax = ext_4ccba0_thiscall1(ecx);  // @103_4d6aa0
  ecx = edx = 0;  // @104_4d6aa0
  goto L4d6be8;  // @105_4d6aa0
  L4d6be6:;
  esi = 0;  // @107_4d6aa0
  FL[3] = esi;  // @108_4d6aa0
  L4d6be8:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @110_4d6aa0
  reg.state = (s32)((u32)(4294967295));  // @111_4d6aa0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 106), &v, sizeof v); }  // @112_4d6aa0
  if (FL[0] == FL[1]) goto L4d6bff;  // @113_4d6aa0
  ecx = edi;  // @114_4d6aa0
  eax = ext_4d6c60_thiscall1(ecx);  // @115_4d6aa0
  ecx = edx = 0;  // @116_4d6aa0
  L4d6bff:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 110), &v, sizeof v); }  // @118_4d6aa0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @119_4d6aa0
  SEH_LEAVE();  // @120_4d6aa0
  return eax;  // @121_4d6aa0
  L4d6c18:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @123_4d6aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_4d6aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @125_4d6aa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6908196), (u32)(1188));  // @126_4d6aa0
  ecx = edx = 0;  // @127_4d6aa0
  PV[3] = (u32)(esi);  // @128_4d6aa0
  PV[4] = (u32)(eax);  // @129_4d6aa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @130_4d6aa0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[4], (u32)(6908628), PV[3]);  // @131_4d6aa0
  ecx = edx = 0;  // @132_4d6aa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9), &v, sizeof v); }  // @133_4d6aa0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @134_4d6aa0
  FL[3] = (eax & 0xff);  // @135_4d6aa0
  SEH_LEAVE();  // @136_4d6aa0
  return eax;  // @137_4d6aa0
}
PCREG(4d6aa0, lifted_4d6aa0);

