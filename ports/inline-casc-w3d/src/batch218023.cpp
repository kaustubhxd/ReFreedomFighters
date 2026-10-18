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

extern "C" u32 THISCALL lifted_444020(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_444020
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_444020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @1_444020
  { u32 v = (u32)((u32)(6803920)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_444020
  FL[2] = (ecx & ecx);  // @3_444020
  if (FL[2] == 0) goto L444066;  // @4_444020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_444020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @6_444020
  ecx = edx = 0;  // @7_444020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @8_444020
  L444066:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @10_444020
  if (FL[0] == FL[1]) goto L44408d;  // @11_444020
  L444070:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @13_444020
  FL[2] = (edi & edi);  // @14_444020
  if (FL[2] == 0) goto L444087;  // @15_444020
  ecx = edi;  // @16_444020
  eax = ext_4d9430_thiscall1(ecx);  // @17_444020
  ecx = edx = 0;  // @18_444020
  PV[0] = (u32)(edi);  // @19_444020
  eax = ext_4d9590_cdecl1(PV[0]);  // @20_444020
  ecx = edx = 0;  // @21_444020
  L444087:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_444020
  if (FL[0] != FL[1]) goto L444070;  // @24_444020
  L44408d:;
  ecx = esi;  // @26_444020
  eax = ext_444530_thiscall1(ecx);  // @27_444020
  ecx = edx = 0;  // @28_444020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 144), sizeof v); (u32)v; });  // @29_444020
  FL[2] = (eax & eax);  // @30_444020
  if (FL[2] == 0) goto L4440bd;  // @31_444020
  PV[1] = (u32)(eax);  // @32_444020
  eax = ext_634273_cdecl2(PV[1], (u32)(52));  // @33_444020
  ecx = edx = 0;  // @34_444020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @35_444020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @36_444020
  L4440bd:;
  ecx = esi;  // @38_444020
  eax = ext_441c00_thiscall1(ecx);  // @39_444020
  ecx = edx = 0;  // @40_444020
  SEH_LEAVE();  // @41_444020
  return eax;  // @42_444020
}
PCREG(444020, lifted_444020);

extern "C" u32 THISCALL lifted_45a5a0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_45a5a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @1_45a5a0
  { u32 v = (u32)((u32)(6831020)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_45a5a0
  FL[2] = (ecx & ecx);  // @3_45a5a0
  if (FL[2] == 0) goto L45a61e;  // @4_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_45a5a0
  edx = (u32)(EBP - 24);  // @6_45a5a0
  PV[0] = (u32)(edx);  // @7_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @8_45a5a0
  ecx = edx = 0;  // @9_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @10_45a5a0
  edx = (u32)(EBP - 24);  // @11_45a5a0
  PV[1] = (u32)(edx);  // @12_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @14_45a5a0
  ecx = edx = 0;  // @15_45a5a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @16_45a5a0
  if (FL[0] == FL[1]) goto L45a611;  // @17_45a5a0
  L45a5f0:;
  FL[2] = (eax & eax);  // @19_45a5a0
  if (FL[2] == 0) goto L45a5ff;  // @20_45a5a0
  PV[2] = (u32)(eax);  // @21_45a5a0
  eax = ext_634273_cdecl2(PV[2], (u32)(1));  // @22_45a5a0
  ecx = edx = 0;  // @23_45a5a0
  L45a5ff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @25_45a5a0
  edx = (u32)(EBP - 24);  // @26_45a5a0
  PV[3] = (u32)(edx);  // @27_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @29_45a5a0
  ecx = edx = 0;  // @30_45a5a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @31_45a5a0
  if (FL[0] != FL[1]) goto L45a5f0;  // @32_45a5a0
  L45a611:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @34_45a5a0
  FL[2] = (ecx & ecx);  // @35_45a5a0
  if (FL[2] == 0) goto L45a61e;  // @36_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @38_45a5a0
  ecx = edx = 0;  // @39_45a5a0
  L45a61e:;
  ecx = esi;  // @41_45a5a0
  eax = ext_43de70_thiscall1(ecx);  // @42_45a5a0
  ecx = edx = 0;  // @43_45a5a0
  SEH_LEAVE();  // @44_45a5a0
  return eax;  // @45_45a5a0
}
PCREG(45a5a0, lifted_45a5a0);

extern "C" u32 THISCALL lifted_436ec0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_436ec0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_436ec0
  FL[2] = (eax & eax);  // @2_436ec0
  if (FL[2] == 0) goto L436efa;  // @3_436ec0
  PV[0] = (u32)(eax);  // @4_436ec0
  eax = ext_634273_cdecl2(PV[0], (u32)(1));  // @5_436ec0
  ecx = edx = 0;  // @6_436ec0
  L436efa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @8_436ec0
  FL[2] = (ecx & ecx);  // @9_436ec0
  if (FL[2] == 0) goto L436f4e;  // @10_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_436ec0
  edx = (u32)(EBP - 24);  // @12_436ec0
  PV[1] = (u32)(edx);  // @13_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @14_436ec0
  ecx = edx = 0;  // @15_436ec0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @16_436ec0
  edx = (u32)(EBP - 24);  // @17_436ec0
  PV[2] = (u32)(edx);  // @18_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @20_436ec0
  ecx = edx = 0;  // @21_436ec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @22_436ec0
  if (FL[0] == FL[1]) goto L436f41;  // @23_436ec0
  L436f20:;
  FL[2] = (eax & eax);  // @25_436ec0
  if (FL[2] == 0) goto L436f2f;  // @26_436ec0
  PV[3] = (u32)(eax);  // @27_436ec0
  eax = ext_634273_cdecl2(PV[3], (u32)(1));  // @28_436ec0
  ecx = edx = 0;  // @29_436ec0
  L436f2f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @31_436ec0
  edx = (u32)(EBP - 24);  // @32_436ec0
  PV[4] = (u32)(edx);  // @33_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @35_436ec0
  ecx = edx = 0;  // @36_436ec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @37_436ec0
  if (FL[0] != FL[1]) goto L436f20;  // @38_436ec0
  L436f41:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @40_436ec0
  FL[2] = (ecx & ecx);  // @41_436ec0
  if (FL[2] == 0) goto L436f4e;  // @42_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @44_436ec0
  ecx = edx = 0;  // @45_436ec0
  L436f4e:;
  SEH_LEAVE();  // @47_436ec0
  return eax;  // @48_436ec0
}
PCREG(436ec0, lifted_436ec0);

extern "C" u32 THISCALL lifted_5082c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_5082c0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @2_5082c0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_5082c0
  ecx = edx = 0;  // @4_5082c0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @5_5082c0
  edx = (edx - (u32)(3));  // @6_5082c0
  FL[3] = edx;  // @7_5082c0
  if (FL[3] == 0) goto L50834e;  // @8_5082c0
  edx = (edx - (u32)(1));  // @9_5082c0
  FL[3] = edx;  // @10_5082c0
  if (FL[3] == 0) goto L508345;  // @11_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @12_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(273));  // @14_5082c0
  ecx = edx = 0;  // @15_5082c0
  PV[0] = (u32)(eax);  // @16_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_5082c0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932912));  // @18_5082c0
  ecx = edx = 0;  // @19_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5082c0
  FL[2] = (eax & eax);  // @21_5082c0
  if (FL[2] == 0) goto L508340;  // @22_5082c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @23_5082c0
  ecx = edx = 0;  // @24_5082c0
  eax = 0;  // @25_5082c0
  FL[3] = eax;  // @26_5082c0
  goto L508350;  // @27_5082c0
  L508340:;
  __builtin_trap();  // @29_5082c0
  L508345:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_5082c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @33_5082c0
  ecx = edx = 0;  // @34_5082c0
  goto L508350;  // @35_5082c0
  L50834e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @37_5082c0
  L508350:;
  PV[1] = (u32)(eax);  // @39_5082c0
  ecx = (u32)(EBP - 144);  // @40_5082c0
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @41_5082c0
  ecx = edx = 0;  // @42_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @43_5082c0
  eax = (u32)(EBP - 144);  // @44_5082c0
  PV[2] = (u32)(eax);  // @45_5082c0
  ecx = (ecx + (u32)(1042));  // @46_5082c0
  FL[3] = ecx;  // @47_5082c0
  reg.state = (s32)((u32)(0));  // @48_5082c0
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @49_5082c0
  ecx = edx = 0;  // @50_5082c0
  ecx = (u32)(EBP - 144);  // @51_5082c0
  eax = ext_4cbec0_thiscall1(ecx);  // @52_5082c0
  ecx = edx = 0;  // @53_5082c0
  SEH_LEAVE();  // @54_5082c0
  ext_633654(G(u32, 0x6f5630));  // @55_5082c0
  return eax;  // @56_5082c0
}
PCREG(5082c0, lifted_5082c0);

extern "C" u32 FASTCALL lifted_42b080(u32 ecx_in, u32 edx_in, u32 a0) {
  SEH_ENTER(0x66adf6);  // @h_42b080
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = edx;  // @0_42b080
  esi = ecx;  // @1_42b080
  FL[0] = esi; FL[1] = edi;  // @2_42b080
  if (FL[0] == FL[1]) goto L42b0dd;  // @3_42b080
  L42b0b0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_42b080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @6_42b080
  eax = (eax - ecx);  // @7_42b080
  FL[3] = eax;  // @8_42b080
  reg.state = (s32)((u32)(0));  // @9_42b080
  FL[2] = (ecx & ecx);  // @10_42b080
  if (FL[2] == 0) goto L42b0cf;  // @11_42b080
  FL[2] = (eax & eax);  // @12_42b080
  if (FL[2] == 0) goto L42b0cf;  // @13_42b080
  PV[0] = (u32)(eax);  // @14_42b080
  PV[1] = (u32)(ecx);  // @15_42b080
  ecx = esi;  // @16_42b080
  eax = ext_54f870_stdcall2(PV[1], PV[0]);  // @17_42b080
  ecx = edx = 0;  // @18_42b080
  L42b0cf:;
  esi = (esi + (u32)(12));  // @20_42b080
  FL[3] = esi;  // @21_42b080
  reg.state = (s32)((u32)(4294967295));  // @22_42b080
  FL[0] = esi; FL[1] = edi;  // @23_42b080
  if (FL[0] != FL[1]) goto L42b0b0;  // @24_42b080
  L42b0dd:;
  SEH_LEAVE();  // @26_42b080
  return eax;  // @27_42b080
}
PCREG(42b080, lifted_42b080);

extern "C" u32 THISCALL lifted_5f3b00(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_5f3b00
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_5f3b00
  ecx = (u32)(esi + 52);  // @1_5f3b00
  { u32 v = (u32)((u32)(7047724)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5f3b00
  eax = ext_5f55e0_thiscall1(ecx);  // @3_5f3b00
  ecx = edx = 0;  // @4_5f3b00
  edi = (u32)(esi + 40);  // @5_5f3b00
  ecx = edi;  // @6_5f3b00
  eax = ext_5f55e0_thiscall1(ecx);  // @7_5f3b00
  ecx = edx = 0;  // @8_5f3b00
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @9_5f3b00
  if (FL[0] == FL[1]) goto L5f3b83;  // @10_5f3b00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @11_5f3b00
  L5f3b50:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @13_5f3b00
  FL[2] = (ecx & ecx);  // @14_5f3b00
  if (FL[2] == 0) goto L5f3b63;  // @15_5f3b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @16_5f3b00
  ecx = (ecx - 1);  // @17_5f3b00
  FL[3] = ecx;  // @18_5f3b00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @19_5f3b00
  edi = (u32)(eax + ecx*4);  // @20_5f3b00
  goto L5f3b73;  // @21_5f3b00
  L5f3b63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @23_5f3b00
  FL[2] = (eax & eax);  // @24_5f3b00
  if (FL[2] == 0) goto L5f3b70;  // @25_5f3b00
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @26_5f3b00
  ecx = edx = 0;  // @27_5f3b00
  goto L5f3b73;  // @28_5f3b00
  L5f3b70:;
  __builtin_trap();  // @30_5f3b00
  L5f3b73:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_5f3b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_5f3b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @34_5f3b00
  ecx = edx = 0;  // @35_5f3b00
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @36_5f3b00
  if (FL[0] != FL[1]) goto L5f3b50;  // @37_5f3b00
  edi = (u32)(esi + 40);  // @38_5f3b00
  L5f3b83:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @40_5f3b00
  if (FL[0] != FL[1]) goto L5f3b97;  // @41_5f3b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 150), sizeof v); (u32)v; });  // @42_5f3b00
  PV[0] = (u32)(esi);  // @43_5f3b00
  eax = ext_5fef70_thiscall2(ecx, PV[0]);  // @44_5f3b00
  ecx = edx = 0;  // @45_5f3b00
  goto L5f3ba6;  // @46_5f3b00
  L5f3b97:;
  ecx = (u32)(esi + 154);  // @48_5f3b00
  eax = ext_600260_thiscall3(ecx, (u32)(0), (u32)(0));  // @49_5f3b00
  ecx = edx = 0;  // @50_5f3b00
  L5f3ba6:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @52_5f3b00
  eax = ext_41e2c0_cdecl1(PV[1]);  // @53_5f3b00
  ecx = edx = 0;  // @54_5f3b00
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @55_5f3b00
  eax = ext_41e2c0_cdecl1(PV[2]);  // @56_5f3b00
  ecx = edx = 0;  // @57_5f3b00
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @58_5f3b00
  eax = ext_41e2c0_cdecl1(PV[3]);  // @59_5f3b00
  ecx = edx = 0;  // @60_5f3b00
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @61_5f3b00
  eax = ext_41e2c0_cdecl1(PV[4]);  // @62_5f3b00
  ecx = edx = 0;  // @63_5f3b00
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_5f3b00
  eax = ext_41e2c0_cdecl1(PV[5]);  // @65_5f3b00
  ecx = edx = 0;  // @66_5f3b00
  SEH_LEAVE();  // @67_5f3b00
  return eax;  // @68_5f3b00
}
PCREG(5f3b00, lifted_5f3b00);

extern "C" u32 THISCALL lifted_441c00(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_441c00
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_441c00
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_441c00
  { u32 v = (u32)((u32)(6802876)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_441c00
  if (FL[0] == FL[1]) goto L441c50;  // @3_441c00
  L441c33:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @5_441c00
  FL[2] = (edi & edi);  // @6_441c00
  if (FL[2] == 0) goto L441c4a;  // @7_441c00
  ecx = edi;  // @8_441c00
  eax = ext_4d9430_thiscall1(ecx);  // @9_441c00
  ecx = edx = 0;  // @10_441c00
  PV[0] = (u32)(edi);  // @11_441c00
  eax = ext_4d9590_cdecl1(PV[0]);  // @12_441c00
  ecx = edx = 0;  // @13_441c00
  L441c4a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @15_441c00
  if (FL[0] != FL[1]) goto L441c33;  // @16_441c00
  L441c50:;
  ecx = esi;  // @18_441c00
  eax = ext_45f420_thiscall1(ecx);  // @19_441c00
  ecx = edx = 0;  // @20_441c00
  FL[2] = (eax & eax);  // @21_441c00
  if (FL[2] == 0) goto L441c8a;  // @22_441c00
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_441c00
  if (FL[0] != FL[1]) goto L441c8a;  // @24_441c00
  ecx = esi;  // @25_441c00
  eax = ext_45f420_thiscall1(ecx);  // @26_441c00
  ecx = edx = 0;  // @27_441c00
  FL[2] = (eax & eax);  // @28_441c00
  if (FL[2] == 0) goto L441c8a;  // @29_441c00
  ecx = esi;  // @30_441c00
  eax = ext_45f420_thiscall1(ecx);  // @31_441c00
  ecx = edx = 0;  // @32_441c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @33_441c00
  eax = ext_4db7e0_thiscall1(ecx);  // @34_441c00
  ecx = edx = 0;  // @35_441c00
  FL[2] = (eax & eax);  // @36_441c00
  if (FL[2] == 0) goto L441c8a;  // @37_441c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_441c00
  ecx = eax;  // @39_441c00
  PV[1] = (u32)(esi);  // @40_441c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 716)))(ecx, PV[1]);  // @41_441c00
  ecx = edx = 0;  // @42_441c00
  L441c8a:;
  edi = (u32)(esi + 93);  // @44_441c00
  ebx = (u32)(5);  // @45_441c00
  L441c92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_441c00
  FL[2] = (ecx & ecx);  // @48_441c00
  if (FL[2] == 0) goto L441ca5;  // @49_441c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_441c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(1));  // @51_441c00
  ecx = edx = 0;  // @52_441c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @53_441c00
  L441ca5:;
  edi = (edi + (u32)(4));  // @55_441c00
  FL[3] = edi;  // @56_441c00
  ebx = (ebx - (u32)(1));  // @57_441c00
  FL[3] = ebx;  // @58_441c00
  if (FL[3] != 0) goto L441c92;  // @59_441c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @60_441c00
  FL[2] = (edi & edi);  // @61_441c00
  if (FL[2] == 0) goto L441cc9;  // @62_441c00
  ecx = edi;  // @63_441c00
  eax = ext_4e3f00_thiscall1(ecx);  // @64_441c00
  ecx = edx = 0;  // @65_441c00
  PV[2] = (u32)(edi);  // @66_441c00
  eax = ext_634273_cdecl2(PV[2], (u32)(45));  // @67_441c00
  ecx = edx = 0;  // @68_441c00
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @69_441c00
  L441cc9:;
  ecx = esi;  // @71_441c00
  eax = ext_43ea20_thiscall1(ecx);  // @72_441c00
  ecx = edx = 0;  // @73_441c00
  SEH_LEAVE();  // @74_441c00
  return eax;  // @75_441c00
}
PCREG(441c00, lifted_441c00);

extern "C" u32 THISCALL lifted_435470(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6657fd);  // @h_435470
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_435470
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_435470
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_435470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_435470
  if (FL[0] != FL[1]) goto L4354e3;  // @4_435470
  eax = ext_41e290_cdecl1((u32)(28));  // @5_435470
  ecx = edx = 0;  // @6_435470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @7_435470
  reg.state = (s32)((u32)(0));  // @8_435470
  FL[2] = (eax & eax);  // @9_435470
  if (FL[2] == 0) goto L4354d7;  // @10_435470
  ecx = eax;  // @11_435470
  eax = ext_4ccd10_thiscall3(ecx, (u32)(8), (u32)(0));  // @12_435470
  ecx = edx = 0;  // @13_435470
  goto L4354d9;  // @14_435470
  L4354d7:;
  eax = 0;  // @16_435470
  FL[3] = eax;  // @17_435470
  L4354d9:;
  reg.state = (s32)((u32)(4294967295));  // @19_435470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @20_435470
  L4354e3:;
  PV[0] = (u32)(esi);  // @22_435470
  ecx = (u32)(EBP - 144);  // @23_435470
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @24_435470
  ecx = edx = 0;  // @25_435470
  ecx = (u32)(EBP - 144);  // @26_435470
  reg.state = (s32)((u32)(1));  // @27_435470
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_435470
  ecx = edx = 0;  // @29_435470
  edi = eax;  // @30_435470
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @31_435470
  if (FL[0] == FL[1]) goto L43554d;  // @32_435470
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775380), sizeof v); (u32)v; });  // @33_435470
  L435510:;
  PV[1] = (u32)(edi);  // @35_435470
  eax = ((u32( *)(u32, u32))(ebx))(PV[1], (u32)(59));  // @36_435470
  ecx = edx = 0;  // @37_435470
  esi = eax;  // @38_435470
  FL[2] = (esi & esi);  // @39_435470
  if (FL[2] != 0) goto L43552f;  // @40_435470
  eax = edi;  // @41_435470
  edx = (u32)(eax + 1);  // @42_435470
  L435523:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @44_435470
  eax = (eax + 1);  // @45_435470
  FL[3] = eax;  // @46_435470
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @47_435470
  if (FL[2] != 0) goto L435523;  // @48_435470
  eax = (eax - edx);  // @49_435470
  FL[3] = eax;  // @50_435470
  esi = (u32)(eax + edi);  // @51_435470
  L43552f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @53_435470
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @54_435470
  PV[2] = (u32)(edi);  // @55_435470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @56_435470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_435470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[2]);  // @58_435470
  ecx = edx = 0;  // @59_435470
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @60_435470
  edi = (u32)(esi + 1);  // @61_435470
  if (FL[0] != FL[1]) goto L435510;  // @62_435470
  L43554d:;
  ecx = (u32)(EBP - 144);  // @64_435470
  eax = ext_4cbec0_thiscall1(ecx);  // @65_435470
  ecx = edx = 0;  // @66_435470
  SEH_LEAVE();  // @67_435470
  ext_633654(G(u32, 0x6f5630));  // @68_435470
  return eax;  // @69_435470
}
PCREG(435470, lifted_435470);

extern "C" u32 THISCALL lifted_6028b0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9) {
  SEH_ENTER(0x66db5c);  // @h_6028b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  __builtin_memcpy(F + 0x300 + 40, &a8, 4);
  __builtin_memcpy(F + 0x300 + 44, &a9, 4);
  eax = ecx;  // @0_6028b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_6028b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; }); FL[1] = (u32)(5);  // @2_6028b0
  reg.state = (s32)((u32)(0));  // @3_6028b0
  if (FL[0] == FL[1]) goto L6029ea;  // @4_6028b0
  ebx = (u32)(eax + 1);  // @5_6028b0
  eax = (u32)(EBP + 8);  // @6_6028b0
  ecx = ebx;  // @7_6028b0
  PV[0] = (u32)(eax);  // @8_6028b0
  eax = (u32)(EBP - 16);  // @9_6028b0
  PV[1] = (u32)(eax);  // @10_6028b0
  eax = ext_5fb980_thiscall3(ecx, PV[1], PV[0]);  // @11_6028b0
  ecx = edx = 0;  // @12_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_6028b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = eax;  // @14_6028b0
  if (FL[0] != FL[1]) goto L6029b5;  // @15_6028b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @16_6028b0
  edi = 0;  // @17_6028b0
  FL[3] = edi;  // @18_6028b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }); FL[1] = edi;  // @19_6028b0
  if (FL[0] != FL[1]) goto L60291e;  // @20_6028b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }); FL[1] = edi;  // @21_6028b0
  if (FL[0] != FL[1]) goto L60291e;  // @22_6028b0
  FL[2] = (esi & esi);  // @23_6028b0
  if (FL[2] == 0) goto L60294d;  // @24_6028b0
  L60291e:;
  eax = ext_41e290_cdecl1((u32)(48));  // @26_6028b0
  ecx = edx = 0;  // @27_6028b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 28), &v, sizeof v); }  // @28_6028b0
  reg.state = (s32)((u32)(1));  // @29_6028b0
  FL[2] = (eax & eax);  // @30_6028b0
  if (FL[2] == 0) goto L602947;  // @31_6028b0
  PV[2] = (u32)(esi);  // @32_6028b0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @33_6028b0
  ecx = eax;  // @34_6028b0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @35_6028b0
  eax = ext_602290_thiscall5(ecx, (u32)(0), PV[4], PV[3], PV[2]);  // @36_6028b0
  ecx = edx = 0;  // @37_6028b0
  edi = eax;  // @38_6028b0
  goto L602949;  // @39_6028b0
  L602947:;
  edi = 0;  // @41_6028b0
  FL[3] = edi;  // @42_6028b0
  L602949:;
  reg.state = (s32)((u32)(0));  // @44_6028b0
  L60294d:;
  eax = ext_41e290_cdecl1((u32)(40));  // @46_6028b0
  ecx = edx = 0;  // @47_6028b0
  esi = eax;  // @48_6028b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @49_6028b0
  reg.state = (s32)((u32)(2));  // @50_6028b0
  FL[2] = (esi & esi);  // @51_6028b0
  if (FL[2] == 0) goto L60299a;  // @52_6028b0
  eax = (u32)(EBP + 8);  // @53_6028b0
  { u32 v = (u32)((u32)(7051460)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @54_6028b0
  PV[5] = (u32)(eax);  // @55_6028b0
  ecx = (u32)(esi + 4);  // @56_6028b0
  eax = ext_5f10c0_thiscall2(ecx, PV[5]);  // @57_6028b0
  ecx = edx = 0;  // @58_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @59_6028b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @60_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @61_6028b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @62_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 44), sizeof v); (u32)v; });  // @63_6028b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @64_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 40), sizeof v); (u32)v; });  // @65_6028b0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @66_6028b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @67_6028b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @68_6028b0
  goto L60299c;  // @69_6028b0
  L60299a:;
  esi = 0;  // @71_6028b0
  FL[3] = esi;  // @72_6028b0
  L60299c:;
  eax = (u32)(EBP + 8);  // @74_6028b0
  reg.state = (s32)((u32)(0));  // @75_6028b0
  PV[6] = (u32)(eax);  // @76_6028b0
  ecx = ebx;  // @77_6028b0
  eax = ext_5fb110_thiscall2(ecx, PV[6]);  // @78_6028b0
  ecx = edx = 0;  // @79_6028b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @80_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @81_6028b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @82_6028b0
  goto L602a1d;  // @83_6028b0
  L6029b5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @85_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_6028b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051464), (u32)(59));  // @87_6028b0
  ecx = edx = 0;  // @88_6028b0
  PV[7] = (u32)(eax);  // @89_6028b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @90_6028b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[7], (u32)(6932144), (u32)(7051600));  // @91_6028b0
  ecx = edx = 0;  // @92_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @93_6028b0
  FL[2] = (eax & eax);  // @94_6028b0
  if (FL[2] == 0) goto L6029e7;  // @95_6028b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @96_6028b0
  ecx = edx = 0;  // @97_6028b0
  goto L602a1d;  // @98_6028b0
  L6029e7:;
  __builtin_trap();  // @100_6028b0
  L6029ea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @102_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_6028b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051464), (u32)(46));  // @104_6028b0
  ecx = edx = 0;  // @105_6028b0
  PV[8] = (u32)(eax);  // @106_6028b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @107_6028b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[8], (u32)(6932144), (u32)(7051548));  // @108_6028b0
  ecx = edx = 0;  // @109_6028b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @110_6028b0
  FL[2] = (eax & eax);  // @111_6028b0
  if (FL[2] == 0) goto L602a1c;  // @112_6028b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @113_6028b0
  ecx = edx = 0;  // @114_6028b0
  goto L602a1d;  // @115_6028b0
  L602a1c:;
  __builtin_trap();  // @117_6028b0
  L602a1d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @119_6028b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @120_6028b0
  eax = (eax - ecx);  // @121_6028b0
  FL[3] = eax;  // @122_6028b0
  reg.state = (s32)((u32)(3));  // @123_6028b0
  FL[2] = (ecx & ecx);  // @124_6028b0
  if (FL[2] == 0) goto L602a3e;  // @125_6028b0
  FL[2] = (eax & eax);  // @126_6028b0
  if (FL[2] == 0) goto L602a3e;  // @127_6028b0
  PV[9] = (u32)(eax);  // @128_6028b0
  PV[10] = (u32)(ecx);  // @129_6028b0
  ecx = (u32)(EBP + 8);  // @130_6028b0
  eax = ext_54f870_stdcall2(PV[10], PV[9]);  // @131_6028b0
  ecx = edx = 0;  // @132_6028b0
  L602a3e:;
  SEH_LEAVE();  // @134_6028b0
  return eax;  // @135_6028b0
}
PCREG(6028b0, lifted_6028b0);

extern "C" u32 THISCALL lifted_598eb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66bbbf);  // @h_598eb0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 S2 = 0; u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_598eb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_598eb0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 7435), &v, sizeof v); }  // @2_598eb0
  FL[2] = (esi & esi);  // @3_598eb0
  if (FL[2] == 0) goto L599021;  // @4_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_598eb0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1654), sizeof v); (u32)v; });  // @6_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @9_598eb0
  ecx = edx = 0;  // @10_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7431), &v, sizeof v); }  // @11_598eb0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @12_598eb0
  if (FL[0] != FL[1]) goto L598f22;  // @13_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_598eb0
  ecx = esi;  // @15_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6975112));  // @16_598eb0
  ecx = edx = 0;  // @17_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2138), &v, sizeof v); }  // @18_598eb0
  L598f22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; });  // @20_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7427), &v, sizeof v); }  // @21_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7435), sizeof v); (u32)v; });  // @22_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1668), sizeof v); (u32)v; });  // @23_598eb0
  eax = (eax - (u32)(2));  // @24_598eb0
  FL[3] = eax;  // @25_598eb0
  if (FL[3] == 0) goto L598faa;  // @26_598eb0
  eax = (eax - (u32)(1));  // @27_598eb0
  FL[3] = eax;  // @28_598eb0
  if (FL[3] == 0) goto L598f8c;  // @29_598eb0
  eax = (eax - (u32)(1));  // @30_598eb0
  FL[3] = eax;  // @31_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_598eb0
  if (FL[3] == 0) goto L598f7b;  // @35_598eb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @36_598eb0
  ecx = edx = 0;  // @37_598eb0
  ecx = (u32)(EBP + 8);  // @38_598eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @39_598eb0
  PV[1] = (u32)(ecx);  // @40_598eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_598eb0
  ecx = eax;  // @42_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973184), PV[1]);  // @43_598eb0
  ecx = edx = 0;  // @44_598eb0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @45_598eb0
  goto L598fda;  // @46_598eb0
  L598f7b:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx); S2 = 6973232;  // @48_598eb0
  ecx = edx = 0;  // @49_598eb0
  ecx = (u32)(EBP - 16);  // @50_598eb0
  PV[3] = (u32)(ecx);  // @51_598eb0
  goto L598fc6;  // @52_598eb0
  L598f8c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_598eb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx); S2 = 6973216;  // @57_598eb0
  ecx = edx = 0;  // @58_598eb0
  ecx = (u32)(EBP - 16);  // @59_598eb0
  PV[4] = (u32)(ecx);  // @60_598eb0
  goto L598fc6;  // @61_598eb0
  L598faa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_598eb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx); S2 = 6973200;  // @66_598eb0
  ecx = edx = 0;  // @67_598eb0
  ecx = (u32)(EBP - 16);  // @68_598eb0
  PV[5] = (u32)(ecx);  // @69_598eb0
  L598fc6:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @71_598eb0
  ecx = eax;  // @72_598eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @73_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, S2, (u32)(EBP - 16));  // @74_598eb0
  ecx = edx = 0;  // @75_598eb0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @76_598eb0
  L598fda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[6]);  // @81_598eb0
  ecx = edx = 0;  // @82_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7439), &v, sizeof v); }  // @83_598eb0
  eax = ext_41e290_cdecl1((u32)(76));  // @84_598eb0
  ecx = edx = 0;  // @85_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @86_598eb0
  reg.state = (s32)((u32)(0));  // @87_598eb0
  FL[2] = (eax & eax);  // @88_598eb0
  if (FL[2] == 0) goto L599019;  // @89_598eb0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7439), sizeof v); (u32)v; });  // @90_598eb0
  ecx = eax;  // @91_598eb0
  eax = ext_5eaab0_thiscall3(ecx, PV[7], (u32)(16));  // @92_598eb0
  ecx = edx = 0;  // @93_598eb0
  goto L59901b;  // @94_598eb0
  L599019:;
  eax = 0;  // @96_598eb0
  FL[3] = eax;  // @97_598eb0
  L59901b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8919), &v, sizeof v); }  // @99_598eb0
  L599021:;
  SEH_LEAVE();  // @101_598eb0
  return eax;  // @102_598eb0
}
PCREG(598eb0, lifted_598eb0);

extern "C" u32 THISCALL lifted_602750(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x66db0c);  // @h_602750
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  eax = ecx;  // @0_602750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_602750
  edi = (u32)(eax + 1);  // @2_602750
  reg.state = (s32)((u32)(0));  // @3_602750
  eax = (u32)(EBP + 8);  // @4_602750
  ecx = edi;  // @5_602750
  PV[0] = (u32)(eax);  // @6_602750
  eax = (u32)(EBP - 16);  // @7_602750
  PV[1] = (u32)(eax);  // @8_602750
  eax = ext_5fb980_thiscall3(ecx, PV[1], PV[0]);  // @9_602750
  ecx = edx = 0;  // @10_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_602750
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = eax;  // @12_602750
  if (FL[0] != FL[1]) goto L60283f;  // @13_602750
  eax = ext_41e290_cdecl1((u32)(48));  // @14_602750
  ecx = edx = 0;  // @15_602750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @16_602750
  reg.state = (s32)((u32)(1));  // @17_602750
  FL[2] = (eax & eax);  // @18_602750
  if (FL[2] == 0) goto L6027cd;  // @19_602750
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @20_602750
  ecx = eax;  // @21_602750
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @22_602750
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @23_602750
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @24_602750
  eax = ext_602290_thiscall5(ecx, PV[5], PV[4], PV[3], PV[2]);  // @25_602750
  ecx = edx = 0;  // @26_602750
  ebx = eax;  // @27_602750
  goto L6027cf;  // @28_602750
  L6027cd:;
  ebx = 0;  // @30_602750
  FL[3] = ebx;  // @31_602750
  L6027cf:;
  reg.state = (s32)((u32)(0));  // @33_602750
  eax = ext_41e290_cdecl1((u32)(40));  // @34_602750
  ecx = edx = 0;  // @35_602750
  esi = eax;  // @36_602750
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 32), &v, sizeof v); }  // @37_602750
  reg.state = (s32)((u32)(2));  // @38_602750
  FL[2] = (esi & esi);  // @39_602750
  if (FL[2] == 0) goto L602824;  // @40_602750
  eax = (u32)(EBP + 8);  // @41_602750
  { u32 v = (u32)((u32)(7051460)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @42_602750
  PV[6] = (u32)(eax);  // @43_602750
  ecx = (u32)(esi + 4);  // @44_602750
  eax = ext_5f10c0_thiscall2(ecx, PV[6]);  // @45_602750
  ecx = edx = 0;  // @46_602750
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @47_602750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @48_602750
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @49_602750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @50_602750
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @51_602750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @52_602750
  goto L602826;  // @53_602750
  L602824:;
  esi = 0;  // @55_602750
  FL[3] = esi;  // @56_602750
  L602826:;
  eax = (u32)(EBP + 8);  // @58_602750
  reg.state = (s32)((u32)(0));  // @59_602750
  PV[7] = (u32)(eax);  // @60_602750
  ecx = edi;  // @61_602750
  eax = ext_5fb110_thiscall2(ecx, PV[7]);  // @62_602750
  ecx = edx = 0;  // @63_602750
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @64_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @65_602750
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @66_602750
  goto L602872;  // @67_602750
  L60283f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @69_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_602750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051464), (u32)(90));  // @71_602750
  ecx = edx = 0;  // @72_602750
  PV[8] = (u32)(eax);  // @73_602750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @74_602750
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[8], (u32)(6932144), (u32)(7051644));  // @75_602750
  ecx = edx = 0;  // @76_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @77_602750
  FL[2] = (eax & eax);  // @78_602750
  if (FL[2] == 0) goto L602871;  // @79_602750
  eax = ((u32(STDCALL *)(void))(eax))();  // @80_602750
  ecx = edx = 0;  // @81_602750
  goto L602872;  // @82_602750
  L602871:;
  __builtin_trap();  // @84_602750
  L602872:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @86_602750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @87_602750
  eax = (eax - ecx);  // @88_602750
  FL[3] = eax;  // @89_602750
  reg.state = (s32)((u32)(3));  // @90_602750
  FL[2] = (ecx & ecx);  // @91_602750
  if (FL[2] == 0) goto L602893;  // @92_602750
  FL[2] = (eax & eax);  // @93_602750
  if (FL[2] == 0) goto L602893;  // @94_602750
  PV[9] = (u32)(eax);  // @95_602750
  PV[10] = (u32)(ecx);  // @96_602750
  ecx = (u32)(EBP + 8);  // @97_602750
  eax = ext_54f870_stdcall2(PV[10], PV[9]);  // @98_602750
  ecx = edx = 0;  // @99_602750
  L602893:;
  SEH_LEAVE();  // @101_602750
  return eax;  // @102_602750
}
PCREG(602750, lifted_602750);

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

extern "C" u32 THISCALL lifted_4e7e80(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_4e7e80
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_4e7e80
  { u32 v = (u32)((u32)(6911508)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_4e7e80
  L4e7eb0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @4_4e7e80
  FL[0] = ebx; FL[1] = eax;  // @5_4e7e80
  if (FL[0] == FL[1]) goto L4e7f46;  // @6_4e7e80
  FL[2] = (ebx & ebx);  // @7_4e7e80
  if (FL[2] == 0) goto L4e7f46;  // @8_4e7e80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }); FL[1] = eax;  // @9_4e7e80
  if (FL[0] == FL[1]) goto L4e7edc;  // @10_4e7e80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }); FL[1] = eax;  // @11_4e7e80
  if (FL[0] == FL[1]) goto L4e7edc;  // @12_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_4e7e80
  ecx = edi;  // @14_4e7e80
  PV[0] = (u32)(ebx);  // @15_4e7e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[0]);  // @16_4e7e80
  ecx = edx = 0;  // @17_4e7e80
  esi = eax;  // @18_4e7e80
  goto L4e7ede;  // @19_4e7e80
  L4e7edc:;
  esi = ebx;  // @21_4e7e80
  L4e7ede:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @23_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @24_4e7e80
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @25_4e7e80
  if (FL[0] != FL[1]) goto L4e7eef;  // @26_4e7e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @27_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @28_4e7e80
  L4e7eef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_4e7e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @31_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_4e7e80
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @33_4e7e80
  if (FL[0] != FL[1]) goto L4e7eff;  // @34_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @35_4e7e80
  goto L4e7f0c;  // @36_4e7e80
  L4e7eff:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @38_4e7e80
  if (FL[0] != FL[1]) goto L4e7f09;  // @39_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @40_4e7e80
  goto L4e7f0c;  // @41_4e7e80
  L4e7f09:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @43_4e7e80
  L4e7f0c:;
  FL[0] = esi; FL[1] = ebx;  // @45_4e7e80
  if (FL[0] == FL[1]) goto L4e7f22;  // @46_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @47_4e7e80
  ecx = edi;  // @48_4e7e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @49_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @50_4e7e80
  PV[1] = (u32)(esi);  // @51_4e7e80
  PV[2] = (u32)(ebx);  // @52_4e7e80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[2], PV[1]);  // @53_4e7e80
  ecx = edx = 0;  // @54_4e7e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @55_4e7e80
  L4e7f22:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @57_4e7e80
  if (FL[0] != FL[1]) goto L4e7f30;  // @58_4e7e80
  PV[3] = (u32)(ecx);  // @59_4e7e80
  ecx = edi;  // @60_4e7e80
  eax = ext_4e8450_thiscall2(ecx, PV[3]);  // @61_4e7e80
  ecx = edx = 0;  // @62_4e7e80
  L4e7f30:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 29), sizeof v); (u32)v; });  // @64_4e7e80
  eax = 0;  // @65_4e7e80
  FL[3] = eax;  // @66_4e7e80
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @67_4e7e80
  if (FL[0] == FL[1]) esi = eax;  // @68_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_4e7e80
  PV[4] = (u32)(esi);  // @70_4e7e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[4]);  // @71_4e7e80
  ecx = edx = 0;  // @72_4e7e80
  goto L4e7eb0;  // @73_4e7e80
  L4e7f46:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 29), sizeof v); (u32)v; });  // @75_4e7e80
  FL[2] = (ecx & ecx);  // @76_4e7e80
  if (FL[2] == 0) goto L4e7f53;  // @77_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_4e7e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @79_4e7e80
  ecx = edx = 0;  // @80_4e7e80
  L4e7f53:;
  SEH_LEAVE();  // @82_4e7e80
  return eax;  // @83_4e7e80
}
PCREG(4e7e80, lifted_4e7e80);

extern "C" u32 THISCALL lifted_45d3a0(u32 ecx_in) {
  SEH_ENTER(0x66583b);  // @h_45d3a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_45d3a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_45d3a0
  if (FL[0] == FL[1]) goto L45d58b;  // @2_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @3_45d3a0
  FL[2] = (eax & eax);  // @4_45d3a0
  if (FL[2] == 0) goto L45d58b;  // @5_45d3a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @6_45d3a0
  if (FL[0] == FL[1]) goto L45d58b;  // @7_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @8_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(9375743));  // @10_45d3a0
  ecx = edx = 0;  // @11_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @12_45d3a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @13_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @14_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340968), sizeof v); (u32)v; });  // @15_45d3a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @16_45d3a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @17_45d3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_45d3a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @20_45d3a0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @21_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @22_45d3a0
  PV[1] = (u32)(ebx);  // @23_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @25_45d3a0
  ecx = edx = 0;  // @26_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340968), sizeof v); (u32)v; });  // @27_45d3a0
  PV[2] = (u32)(eax);  // @28_45d3a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 64)))(ecx, PV[2], (u32)(6836784), (u32)(6836768), PV[0]);  // @29_45d3a0
  ecx = edx = 0;  // @30_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @31_45d3a0
  PV[3] = (u32)(ebx);  // @32_45d3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @37_45d3a0
  ecx = edx = 0;  // @38_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @39_45d3a0
  PV[4] = (u32)(eax);  // @40_45d3a0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @41_45d3a0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @42_45d3a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 60)))(ecx, PV[6], PV[5], PV[4]);  // @43_45d3a0
  ecx = edx = 0;  // @44_45d3a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @45_45d3a0
  FL[2] = (eax & eax);  // @46_45d3a0
  if (FL[2] == 0) goto L45d491;  // @47_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @48_45d3a0
  PV[7] = (u32)(eax);  // @49_45d3a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, PV[7]);  // @51_45d3a0
  ecx = edx = 0;  // @52_45d3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @53_45d3a0
  goto L45d4fd;  // @54_45d3a0
  L45d491:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @56_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_45d3a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1809));  // @58_45d3a0
  ecx = edx = 0;  // @59_45d3a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @60_45d3a0
  edi = eax;  // @61_45d3a0
  eax = (u32)(EBP - 144);  // @62_45d3a0
  ecx = ebx;  // @63_45d3a0
  PV[8] = (u32)(eax);  // @64_45d3a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[8], (u32)(1));  // @65_45d3a0
  ecx = edx = 0;  // @66_45d3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_45d3a0
  ecx = eax;  // @68_45d3a0
  reg.state = (s32)((u32)(0));  // @69_45d3a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @70_45d3a0
  ecx = edx = 0;  // @71_45d3a0
  PV[9] = (u32)(eax);  // @72_45d3a0
  PV[10] = (u32)(edi);  // @73_45d3a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[10], (u32)(6836792), PV[9]);  // @74_45d3a0
  ecx = edx = 0;  // @75_45d3a0
  reg.state = (s32)((u32)(4294967295));  // @76_45d3a0
  ecx = (u32)(EBP - 144);  // @77_45d3a0
  eax = ext_4cbec0_thiscall1(ecx);  // @78_45d3a0
  ecx = edx = 0;  // @79_45d3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @80_45d3a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @81_45d3a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @82_45d3a0
  L45d4fd:;
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @84_45d3a0
  eax = ext_634273_cdecl2(PV[11], (u32)(1));  // @85_45d3a0
  ecx = edx = 0;  // @86_45d3a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @87_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @88_45d3a0
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @89_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[12]);  // @91_45d3a0
  ecx = edx = 0;  // @92_45d3a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @93_45d3a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @94_45d3a0
  if (FL[0] != FL[1]) goto L45d57a;  // @95_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_45d3a0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6971), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @97_45d3a0
  if (FL[0] == FL[1]) goto L45d57a;  // @98_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @99_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @100_45d3a0
  FL[2] = (ecx & ecx);  // @101_45d3a0
  if (FL[2] == 0) goto L45d54b;  // @102_45d3a0
  eax = ext_45c560_thiscall2(ecx, (u32)(1));  // @103_45d3a0
  ecx = edx = 0;  // @104_45d3a0
  L45d54b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @106_45d3a0
  PV[13] = (u32)(ebx);  // @107_45d3a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @108_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @109_45d3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @111_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @112_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @114_45d3a0
  ecx = edx = 0;  // @115_45d3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @116_45d3a0
  PV[14] = (u32)(eax);  // @117_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 132)))(ecx, PV[14]);  // @118_45d3a0
  ecx = edx = 0;  // @119_45d3a0
  L45d57a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @121_45d3a0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @122_45d3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_45d3a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[15]);  // @124_45d3a0
  ecx = edx = 0;  // @125_45d3a0
  L45d58b:;
  SEH_LEAVE();  // @127_45d3a0
  ext_633654(G(u32, 0x6f5630));  // @128_45d3a0
  return eax;  // @129_45d3a0
}
PCREG(45d3a0, lifted_45d3a0);

extern "C" u32 THISCALL lifted_4ad770(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6688a1);  // @h_4ad770
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4ad770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ad770
  PV[0] = (u32)(edi);  // @3_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @6_4ad770
  ecx = edx = 0;  // @7_4ad770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 416), &v, sizeof v); }  // @8_4ad770
  FL[2] = (eax & eax);  // @9_4ad770
  if (FL[2] != 0) goto L4ad816;  // @10_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(656));  // @13_4ad770
  ecx = edx = 0;  // @14_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @15_4ad770
  edi = eax;  // @16_4ad770
  eax = (u32)(EBP - 144);  // @17_4ad770
  PV[1] = (u32)(eax);  // @18_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[1], (u32)(1));  // @20_4ad770
  ecx = edx = 0;  // @21_4ad770
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_4ad770
  ecx = eax;  // @23_4ad770
  reg.state = (s32)((u32)(0));  // @24_4ad770
  eax = ext_4cc1d0_thiscall1(ecx);  // @25_4ad770
  ecx = edx = 0;  // @26_4ad770
  PV[2] = (u32)(eax);  // @27_4ad770
  PV[3] = (u32)(edi);  // @28_4ad770
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[3], (u32)(6884388), PV[2]);  // @29_4ad770
  ecx = edx = 0;  // @30_4ad770
  ecx = (u32)(EBP - 144);  // @31_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @32_4ad770
  ecx = edx = 0;  // @33_4ad770
  goto L4ad97a;  // @34_4ad770
  L4ad816:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @36_4ad770
  ecx = (u32)(esi + 282);  // @37_4ad770
  PV[4] = (u32)(edi);  // @38_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[4]);  // @39_4ad770
  ecx = edx = 0;  // @40_4ad770
  FL[2] = (eax & eax);  // @41_4ad770
  if (FL[2] != 0) goto L4ad8c3;  // @42_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(661));  // @45_4ad770
  ecx = edx = 0;  // @46_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @47_4ad770
  edi = eax;  // @48_4ad770
  eax = (u32)(EBP - 400);  // @49_4ad770
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @50_4ad770
  PV[5] = (u32)(eax);  // @51_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[5], (u32)(1));  // @53_4ad770
  ecx = edx = 0;  // @54_4ad770
  ebx = eax;  // @55_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; });  // @56_4ad770
  eax = (u32)(EBP - 272);  // @57_4ad770
  PV[6] = (u32)(eax);  // @58_4ad770
  reg.state = (s32)((u32)(1));  // @59_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[6], (u32)(1));  // @61_4ad770
  ecx = edx = 0;  // @62_4ad770
  esi = eax;  // @63_4ad770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_4ad770
  ecx = ebx;  // @65_4ad770
  reg.state = (s32)((u32)(2));  // @66_4ad770
  eax = ext_4cc1d0_thiscall1(ecx);  // @67_4ad770
  ecx = edx = 0;  // @68_4ad770
  PV[7] = (u32)(eax);  // @69_4ad770
  ecx = esi;  // @70_4ad770
  eax = ext_4cc1d0_thiscall1(ecx);  // @71_4ad770
  ecx = edx = 0;  // @72_4ad770
  PV[8] = (u32)(eax);  // @73_4ad770
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; });  // @74_4ad770
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[9], (u32)(6884448), PV[8], PV[7]);  // @75_4ad770
  ecx = edx = 0;  // @76_4ad770
  ecx = (u32)(EBP - 272);  // @77_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @78_4ad770
  ecx = edx = 0;  // @79_4ad770
  ecx = (u32)(EBP - 400);  // @80_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @81_4ad770
  ecx = edx = 0;  // @82_4ad770
  goto L4ad97a;  // @83_4ad770
  L4ad8c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @85_4ad770
  ecx = (u32)(esi + 282);  // @86_4ad770
  PV[10] = (u32)(edi);  // @87_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[10]);  // @88_4ad770
  ecx = edx = 0;  // @89_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @90_4ad770
  FL[2] = (edx & edx);  // @91_4ad770
  if (FL[2] == 0) goto L4ad8fd;  // @92_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_4ad770
  PV[11] = (u32)(edx);  // @94_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @95_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[11]);  // @97_4ad770
  ecx = edx = 0;  // @98_4ad770
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; });  // @99_4ad770
  PV[12] = (u32)(edi);  // @100_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @101_4ad770
  PV[13] = (u32)(ecx);  // @102_4ad770
  ecx = eax;  // @103_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[13], PV[12], (u32)(0));  // @104_4ad770
  ecx = edx = 0;  // @105_4ad770
  L4ad8fd:;
  esi = (esi + (u32)(454));  // @107_4ad770
  FL[3] = esi;  // @108_4ad770
  if (FL[3] == 0) goto L4ad97a;  // @109_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @110_4ad770
  ecx = (u32)(EBP - 412);  // @111_4ad770
  PV[14] = (u32)(ecx);  // @112_4ad770
  ecx = esi;  // @113_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @114_4ad770
  ecx = edx = 0;  // @115_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_4ad770
  ecx = (u32)(EBP - 412);  // @117_4ad770
  PV[15] = (u32)(ecx);  // @118_4ad770
  ecx = esi;  // @119_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @120_4ad770
  ecx = edx = 0;  // @121_4ad770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @122_4ad770
  if (FL[0] == FL[1]) goto L4ad97a;  // @123_4ad770
  L4ad930:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @125_4ad770
  PV[16] = (u32)(eax);  // @126_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[16]);  // @128_4ad770
  ecx = edx = 0;  // @129_4ad770
  ecx = eax;  // @130_4ad770
  FL[2] = (ecx & ecx);  // @131_4ad770
  if (FL[2] == 0) goto L4ad955;  // @132_4ad770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 262), sizeof v); (u32)v; }); FL[1] = edi;  // @133_4ad770
  if (FL[0] != FL[1]) goto L4ad963;  // @134_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_4ad770
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 172)))(ecx);  // @136_4ad770
  ecx = edx = 0;  // @137_4ad770
  L4ad955:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @139_4ad770
  ecx = (u32)(EBP - 412);  // @140_4ad770
  PV[17] = (u32)(ecx);  // @141_4ad770
  ecx = esi;  // @142_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[17]);  // @143_4ad770
  ecx = edx = 0;  // @144_4ad770
  L4ad963:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_4ad770
  ecx = (u32)(EBP - 412);  // @147_4ad770
  PV[18] = (u32)(ecx);  // @148_4ad770
  ecx = esi;  // @149_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[18]);  // @150_4ad770
  ecx = edx = 0;  // @151_4ad770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @152_4ad770
  if (FL[0] != FL[1]) goto L4ad930;  // @153_4ad770
  L4ad97a:;
  SEH_LEAVE();  // @155_4ad770
  ext_633654(G(u32, 0x6f5630));  // @156_4ad770
  return eax;  // @157_4ad770
}
PCREG(4ad770, lifted_4ad770);

extern "C" u32 THISCALL lifted_46bf20(u32 ecx_in) {
  SEH_ENTER(0x666d98);  // @h_46bf20
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_46bf20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @1_46bf20
  eax = ext_46bca0_cdecl0();  // @2_46bf20
  ecx = edx = 0;  // @3_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @6_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6851000), (u32)(6852056));  // @8_46bf20
  ecx = edx = 0;  // @9_46bf20
  PV[0] = (u32)(eax);  // @10_46bf20
  edx = eax;  // @11_46bf20
  ecx = edi;  // @12_46bf20
  eax = ext_49f9b0_fastcall8(ecx, edx, PV[0], (u32)(7), (u32)(0), (u32)(0), (u32)(150), (u32)(0));  // @13_46bf20
  ecx = edx = 0;  // @14_46bf20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @15_46bf20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 142), &v, sizeof v); }  // @16_46bf20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @17_46bf20
  eax = ext_41e290_cdecl1((u32)(28));  // @18_46bf20
  ecx = edx = 0;  // @19_46bf20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @20_46bf20
  reg.state = (s32)((u32)(0));  // @21_46bf20
  FL[2] = (eax & eax);  // @22_46bf20
  if (FL[2] == 0) goto L46bfcb;  // @23_46bf20
  ecx = eax;  // @24_46bf20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @25_46bf20
  ecx = edx = 0;  // @26_46bf20
  goto L46bfcd;  // @27_46bf20
  L46bfcb:;
  eax = 0;  // @29_46bf20
  FL[3] = eax;  // @30_46bf20
  L46bfcd:;
  reg.state = (s32)((u32)(4294967295));  // @32_46bf20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 148), &v, sizeof v); }  // @33_46bf20
  FL[2] = (ebx & ebx);  // @34_46bf20
  if (FL[2] == 0) goto L46c0a0;  // @35_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_46bf20
  ecx = (u32)(EBP - 296);  // @37_46bf20
  PV[1] = (u32)(ecx);  // @38_46bf20
  ecx = ebx;  // @39_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @40_46bf20
  ecx = edx = 0;  // @41_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_46bf20
  ecx = (u32)(EBP - 296);  // @43_46bf20
  PV[2] = (u32)(ecx);  // @44_46bf20
  ecx = ebx;  // @45_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @46_46bf20
  ecx = edx = 0;  // @47_46bf20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @48_46bf20
  if (FL[0] == FL[1]) goto L46c0a0;  // @49_46bf20
  L46c010:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_46bf20
  PV[3] = (u32)(eax);  // @52_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @53_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[3]);  // @55_46bf20
  ecx = edx = 0;  // @56_46bf20
  esi = eax;  // @57_46bf20
  FL[2] = (esi & esi);  // @58_46bf20
  if (FL[2] == 0) goto L46c085;  // @59_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_46bf20
  ecx = esi;  // @61_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @62_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050579));  // @63_46bf20
  ecx = edx = 0;  // @64_46bf20
  ecx = esi;  // @65_46bf20
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @66_46bf20
  if (FL[2] == 0) goto L46c0bc;  // @67_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @70_46bf20
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @71_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 708)))(ecx, PV[4], (u32)(1230259533));  // @72_46bf20
  ecx = edx = 0;  // @73_46bf20
  esi = eax;  // @74_46bf20
  L46c05f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_46bf20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @77_46bf20
  PV[5] = (u32)(esi);  // @78_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @81_46bf20
  ecx = edx = 0;  // @82_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @83_46bf20
  PV[6] = (u32)(eax);  // @84_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 800)))(ecx, PV[6]);  // @85_46bf20
  ecx = edx = 0;  // @86_46bf20
  L46c07f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @88_46bf20
  L46c085:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_46bf20
  ecx = (u32)(EBP - 296);  // @91_46bf20
  PV[7] = (u32)(ecx);  // @92_46bf20
  ecx = ebx;  // @93_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @94_46bf20
  ecx = edx = 0;  // @95_46bf20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_46bf20
  if (FL[0] != FL[1]) goto L46c010;  // @97_46bf20
  L46c0a0:;
  SEH_LEAVE();  // @99_46bf20
  ext_633654(G(u32, 0x6f5630));  // @100_46bf20
  return eax;  // @101_46bf20
  L46c0bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @103_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @104_46bf20
  eax = ((u32(STDCALL *)(u32))(eax))((u32)(1050577));  // @105_46bf20
  ecx = edx = 0;  // @106_46bf20
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @107_46bf20
  if (FL[2] != 0) goto L46c05f;  // @108_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @109_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3792));  // @111_46bf20
  ecx = edx = 0;  // @112_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @113_46bf20
  edi = eax;  // @114_46bf20
  eax = (u32)(EBP - 272);  // @115_46bf20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @116_46bf20
  PV[8] = (u32)(eax);  // @117_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[8], (u32)(1));  // @119_46bf20
  ecx = edx = 0;  // @120_46bf20
  ebx = eax;  // @121_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_46bf20
  eax = (u32)(EBP - 144);  // @123_46bf20
  PV[9] = (u32)(eax);  // @124_46bf20
  ecx = esi;  // @125_46bf20
  reg.state = (s32)((u32)(1));  // @126_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[9], (u32)(1));  // @127_46bf20
  ecx = edx = 0;  // @128_46bf20
  esi = eax;  // @129_46bf20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @130_46bf20
  ecx = ebx;  // @131_46bf20
  reg.state = (s32)((u32)(2));  // @132_46bf20
  eax = ext_4cc1d0_thiscall1(ecx);  // @133_46bf20
  ecx = edx = 0;  // @134_46bf20
  PV[10] = (u32)(eax);  // @135_46bf20
  ecx = esi;  // @136_46bf20
  eax = ext_4cc1d0_thiscall1(ecx);  // @137_46bf20
  ecx = edx = 0;  // @138_46bf20
  PV[11] = (u32)(eax);  // @139_46bf20
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @140_46bf20
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[12], (u32)(6852072), PV[11], PV[10]);  // @141_46bf20
  ecx = edx = 0;  // @142_46bf20
  ecx = (u32)(EBP - 144);  // @143_46bf20
  eax = ext_4cbec0_thiscall1(ecx);  // @144_46bf20
  ecx = edx = 0;  // @145_46bf20
  ecx = (u32)(EBP - 272);  // @146_46bf20
  reg.state = (s32)((u32)(4294967295));  // @147_46bf20
  eax = ext_4cbec0_thiscall1(ecx);  // @148_46bf20
  ecx = edx = 0;  // @149_46bf20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @150_46bf20
  goto L46c07f;  // @151_46bf20
}
PCREG(46bf20, lifted_46bf20);

extern "C" u32 THISCALL lifted_46f2d0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666e76);  // @h_46f2d0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_46f2d0
  PV[0] = (u32)(edx);  // @3_46f2d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @4_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @7_46f2d0
  ecx = edx = 0;  // @8_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_46f2d0
  edi = eax;  // @10_46f2d0
  ecx = ebx;  // @11_46f2d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 324), &v, sizeof v); }  // @12_46f2d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @13_46f2d0
  ecx = edx = 0;  // @14_46f2d0
  PV[1] = (u32)(edi);  // @15_46f2d0
  ecx = eax;  // @16_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 796), sizeof v); (u32)v; });  // @18_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[1]);  // @19_46f2d0
  ecx = edx = 0;  // @20_46f2d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @21_46f2d0
  if (FL[2] != 0) goto L46f3d7;  // @22_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @23_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3888));  // @25_46f2d0
  ecx = edx = 0;  // @26_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_46f2d0
  edi = eax;  // @28_46f2d0
  eax = (u32)(EBP - 320);  // @29_46f2d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @30_46f2d0
  PV[2] = (u32)(eax);  // @31_46f2d0
  ecx = ebx;  // @32_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[2], (u32)(1));  // @33_46f2d0
  ecx = edx = 0;  // @34_46f2d0
  ebx = eax;  // @35_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; });  // @36_46f2d0
  ecx = (u32)(EBP - 192);  // @37_46f2d0
  PV[3] = (u32)(ecx);  // @38_46f2d0
  ecx = eax;  // @39_46f2d0
  reg.state = (s32)((u32)(0));  // @40_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[3], (u32)(1));  // @42_46f2d0
  ecx = edx = 0;  // @43_46f2d0
  esi = eax;  // @44_46f2d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_46f2d0
  ecx = ebx;  // @46_46f2d0
  reg.state = (s32)((u32)(1));  // @47_46f2d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @48_46f2d0
  ecx = edx = 0;  // @49_46f2d0
  PV[4] = (u32)(eax);  // @50_46f2d0
  ecx = esi;  // @51_46f2d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @52_46f2d0
  ecx = edx = 0;  // @53_46f2d0
  PV[5] = (u32)(eax);  // @54_46f2d0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @55_46f2d0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[6], (u32)(6852148), PV[5], PV[4]);  // @56_46f2d0
  ecx = edx = 0;  // @57_46f2d0
  ecx = (u32)(EBP - 192);  // @58_46f2d0
  eax = ext_4cbec0_thiscall1(ecx);  // @59_46f2d0
  ecx = edx = 0;  // @60_46f2d0
  ecx = (u32)(EBP - 320);  // @61_46f2d0
  eax = ext_4cbec0_thiscall1(ecx);  // @62_46f2d0
  ecx = edx = 0;  // @63_46f2d0
  goto L46f4e0;  // @64_46f2d0
  L46f3d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_46f2d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_46f2d0
  PV[7] = (u32)(ebx);  // @68_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @69_46f2d0
  PV[8] = (u32)(ebx);  // @70_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @72_46f2d0
  ecx = edx = 0;  // @73_46f2d0
  PV[9] = (u32)(eax);  // @74_46f2d0
  ecx = edi;  // @75_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 752)))(ecx, PV[9], PV[7], (u32)(1));  // @76_46f2d0
  ecx = edx = 0;  // @77_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_46f2d0
  ecx = edi;  // @79_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 768)))(ecx, (u32)(1));  // @80_46f2d0
  ecx = edx = 0;  // @81_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @82_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3895));  // @84_46f2d0
  ecx = edx = 0;  // @85_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @86_46f2d0
  esi = (u32)(6801640);  // @87_46f2d0
  FL[2] = (ecx & ecx);  // @88_46f2d0
  edx = esi;  // @89_46f2d0
  edi = eax;  // @90_46f2d0
  if (FL[2] != 0) edx = ecx;  // @91_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; });  // @92_46f2d0
  PV[10] = (u32)(edx);  // @93_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @94_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @95_46f2d0
  FL[2] = (ecx & ecx);  // @96_46f2d0
  if (FL[2] != 0) esi = ecx;  // @97_46f2d0
  PV[11] = (u32)(esi);  // @98_46f2d0
  PV[12] = (u32)(edi);  // @99_46f2d0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(PV[12], (u32)(6852196), PV[11], PV[10]);  // @100_46f2d0
  ecx = edx = 0;  // @101_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_46f2d0
  ecx = ebx;  // @103_46f2d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @104_46f2d0
  ecx = edx = 0;  // @105_46f2d0
  ecx = eax;  // @106_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @107_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 604)))(ecx, (u32)(6852232), (u32)(0));  // @108_46f2d0
  ecx = edx = 0;  // @109_46f2d0
  FL[2] = (eax & eax);  // @110_46f2d0
  if (FL[2] == 0) goto L46f477;  // @111_46f2d0
  ecx = (u32)(EBP - 28);  // @112_46f2d0
  PV[13] = (u32)(ecx);  // @113_46f2d0
  ecx = (u32)(EBP - 64);  // @114_46f2d0
  PV[14] = (u32)(ecx);  // @115_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @116_46f2d0
  eax = ext_4db2c0_thiscall3(ecx, PV[14], PV[13]);  // @117_46f2d0
  ecx = edx = 0;  // @118_46f2d0
  goto L46f494;  // @119_46f2d0
  L46f477:;
  ecx = (u32)(EBP - 64);  // @121_46f2d0
  eax = ext_4de7a0_thiscall1(ecx);  // @122_46f2d0
  ecx = edx = 0;  // @123_46f2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @124_46f2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @125_46f2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @126_46f2d0
  L46f494:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; });  // @128_46f2d0
  edx = (u32)(EBP - 28);  // @129_46f2d0
  PV[15] = (u32)(edx);  // @130_46f2d0
  edx = (u32)(EBP - 64);  // @131_46f2d0
  PV[16] = (u32)(edx);  // @132_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 724)))(ecx, PV[16], PV[15]);  // @134_46f2d0
  ecx = edx = 0;  // @135_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @136_46f2d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @137_46f2d0
  PV[17] = (u32)(esi);  // @138_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[17]);  // @140_46f2d0
  ecx = edx = 0;  // @141_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @142_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3913));  // @144_46f2d0
  ecx = edx = 0;  // @145_46f2d0
  PV[18] = (u32)(esi);  // @146_46f2d0
  PV[19] = (u32)(eax);  // @147_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @148_46f2d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[19], (u32)(6852252), PV[18]);  // @149_46f2d0
  ecx = edx = 0;  // @150_46f2d0
  L46f4e0:;
  SEH_LEAVE();  // @152_46f2d0
  ext_633654(G(u32, 0x6f5630));  // @153_46f2d0
  return eax;  // @154_46f2d0
}
PCREG(46f2d0, lifted_46f2d0);

extern "C" u32 THISCALL lifted_4627d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66693b);  // @h_4627d0
  u8 F[0x4230] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x4130);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4130 + 8, &a0, 4);
  __builtin_memcpy(F + 0x4130 + 12, &a1, 4);
  esi = ecx;  // @0_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @2_4627d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16604), &v, sizeof v); }  // @3_4627d0
  ecx = (u32)(edi + edi*2);  // @4_4627d0
  ecx = (u32)(eax + ecx*8);  // @5_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @6_4627d0
  FL[2] = ((eax & 0xff) & (u32)(1));  // @7_4627d0
  if (FL[2] == 0) goto L4629f7;  // @8_4627d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @9_4627d0
  eax = (eax & (u32)(4294967292));  // @10_4627d0
  FL[3] = eax;  // @11_4627d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @12_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @13_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @14_4627d0
  ecx = esi;  // @15_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_4627d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16612), &v, sizeof v); }  // @17_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @18_4627d0
  ecx = edx = 0;  // @19_4627d0
  edi = (u32)(edi + edi*2);  // @20_4627d0
  edi = (edi + edi);  // @21_4627d0
  FL[3] = edi;  // @22_4627d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 47), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @23_4627d0
  if (FL[0] == FL[1]) goto L462909;  // @24_4627d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @25_4627d0
  if (FL[0] == FL[1]) goto L462909;  // @26_4627d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_4627d0
  if (FL[0] != FL[1]) goto L462909;  // @28_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_4627d0
  ecx = esi;  // @30_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @31_4627d0
  ecx = edx = 0;  // @32_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 12), sizeof v); (u32)v; });  // @33_4627d0
  FL[2] = (edi & edi);  // @34_4627d0
  if ((s32)FL[2] < 0) goto L462909;  // @35_4627d0
  L462880:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @37_4627d0
  ecx = (u32)(edi + edi*2);  // @38_4627d0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 4), sizeof v); (u32)v; }) & (u32)(1));  // @39_4627d0
  ebx = (u32)(eax + ecx*8);  // @40_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @41_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16608), &v, sizeof v); }  // @42_4627d0
  if (FL[2] == 0) goto L4628a1;  // @43_4627d0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @44_4627d0
  if (FL[0] != FL[1]) goto L4628ba;  // @45_4627d0
  L4628a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_4627d0
  ecx = esi;  // @48_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @49_4627d0
  ecx = edx = 0;  // @50_4627d0
  ecx = (u32)(edi + edi*2);  // @51_4627d0
  ecx = (ecx + ecx);  // @52_4627d0
  FL[3] = ecx;  // @53_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 12), sizeof v); (u32)v; });  // @54_4627d0
  FL[2] = (edi & edi);  // @55_4627d0
  if ((s32)FL[2] >= 0) goto L462880;  // @56_4627d0
  goto L462903;  // @57_4627d0
  L4628ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_4627d0
  ecx = esi;  // @60_4627d0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; });  // @61_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 700)))(ecx, PV[0]);  // @62_4627d0
  ecx = edx = 0;  // @63_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @64_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16608), sizeof v); (u32)v; });  // @65_4627d0
  PV[1] = (u32)(eax);  // @66_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_4627d0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; });  // @68_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 48)))(ecx, PV[2], PV[1]);  // @69_4627d0
  ecx = edx = 0;  // @70_4627d0
  ecx = eax;  // @71_4627d0
  FL[2] = (ecx & ecx);  // @72_4627d0
  if (FL[2] == 0) goto L462903;  // @73_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_4627d0
  PV[3] = (u32)(edi);  // @75_4627d0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; });  // @76_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 848), sizeof v); (u32)v; });  // @77_4627d0
  PV[5] = (u32)(ecx);  // @78_4627d0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; });  // @79_4627d0
  ecx = esi;  // @80_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[6], PV[5], PV[4], PV[3]);  // @81_4627d0
  ecx = edx = 0;  // @82_4627d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @83_4627d0
  if (FL[2] == 0) goto L462903;  // @84_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @85_4627d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 68), &v, sizeof v); }  // @86_4627d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @87_4627d0
  L462903:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @89_4627d0
  L462909:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @91_4627d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @92_4627d0
  if (FL[3] != 0) goto L4629f7;  // @93_4627d0
  ecx = (u32)(EBP - 16596);  // @94_4627d0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @95_4627d0
  eax = ext_4d2280_thiscall1(ecx);  // @96_4627d0
  ecx = edx = 0;  // @97_4627d0
  edi = (u32)(ebx + 76);  // @98_4627d0
  reg.state = (s32)((u32)(0));  // @99_4627d0
  PV[7] = (u32)(edi);  // @100_4627d0
  ecx = (u32)(EBP - 16596);  // @101_4627d0
  eax = ext_4d39a0_stdcall2((u32)(6838552), PV[7]);  // @102_4627d0
  ecx = edx = 0;  // @103_4627d0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @104_4627d0
  ecx = (u32)(EBP - 16596);  // @105_4627d0
  eax = ext_4d3ab0_stdcall2((u32)(6838564), PV[8]);  // @106_4627d0
  ecx = edx = 0;  // @107_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @108_4627d0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608));  // @109_4627d0
  if (FL[2] == 0) goto L462979;  // @110_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_4627d0
  eax = (u32)(EBP - 16596);  // @112_4627d0
  PV[9] = (u32)(eax);  // @113_4627d0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 296), sizeof v); (u32)v; });  // @114_4627d0
  ecx = esi;  // @115_4627d0
  PV[10] = (u32)(eax);  // @116_4627d0
  PV[11] = (u32)(esi);  // @117_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[11], PV[10], PV[9]);  // @118_4627d0
  ecx = edx = 0;  // @119_4627d0
  L462979:;
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16612), sizeof v); (u32)v; });  // @121_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_4627d0
  ecx = esi;  // @123_4627d0
  PV[13] = (u32)(edi);  // @124_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 836)))(ecx, PV[13], PV[12]);  // @125_4627d0
  ecx = edx = 0;  // @126_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @127_4627d0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @128_4627d0
  FL[3] = (ebx & 0xff);  // @129_4627d0
  FL[2] = (ecx & ecx);  // @130_4627d0
  if (FL[2] == 0) goto L4629ec;  // @131_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_4627d0
  edx = (u32)(EBP - 16624);  // @133_4627d0
  PV[14] = (u32)(edx);  // @134_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @135_4627d0
  ecx = edx = 0;  // @136_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @137_4627d0
  edx = (u32)(EBP - 16624);  // @138_4627d0
  PV[15] = (u32)(edx);  // @139_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[15]);  // @141_4627d0
  ecx = edx = 0;  // @142_4627d0
  edx = eax;  // @143_4627d0
  FL[2] = (edx & edx);  // @144_4627d0
  if (FL[2] == 0) goto L4629ec;  // @145_4627d0
  L4629b4:;
  ecx = (u32)(edx + 4);  // @147_4627d0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @148_4627d0
  if (FL[2] != 0) goto L4629d7;  // @149_4627d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; }); FL[1] = (u32)(-2);  // @150_4627d0
  if (FL[0] != FL[1]) goto L4629d7;  // @151_4627d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 68), &v, sizeof v); }  // @152_4627d0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @153_4627d0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @154_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @155_4627d0
  PV[17] = (u32)(ecx);  // @156_4627d0
  ecx = esi;  // @157_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 844)))(ecx, PV[17], PV[16]);  // @158_4627d0
  ecx = edx = 0;  // @159_4627d0
  L4629d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @161_4627d0
  edx = (u32)(EBP - 16624);  // @162_4627d0
  PV[18] = (u32)(edx);  // @163_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[18]);  // @165_4627d0
  ecx = edx = 0;  // @166_4627d0
  edx = eax;  // @167_4627d0
  FL[2] = (edx & edx);  // @168_4627d0
  if (FL[2] != 0) goto L4629b4;  // @169_4627d0
  L4629ec:;
  ecx = (u32)(EBP - 16596);  // @171_4627d0
  eax = ext_4d2330_thiscall1(ecx);  // @172_4627d0
  ecx = edx = 0;  // @173_4627d0
  L4629f7:;
  SEH_LEAVE();  // @175_4627d0
  ext_633654(G(u32, 0x6f5630));  // @176_4627d0
  return eax;  // @177_4627d0
}
PCREG(4627d0, lifted_4627d0);

extern "C" u32 THISCALL lifted_603a50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66dc9f);  // @h_603a50
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_603a50
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @2_603a50
  eax = ext_41e290_cdecl1((u32)(24));  // @3_603a50
  ecx = edx = 0;  // @4_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_603a50
  reg.state = (s32)((u32)(0));  // @6_603a50
  FL[2] = (eax & eax);  // @7_603a50
  if (FL[2] == 0) goto L603aa7;  // @8_603a50
  PV[0] = (u32)(esi);  // @9_603a50
  ecx = eax;  // @10_603a50
  eax = ext_603500_thiscall2(ecx, PV[0]);  // @11_603a50
  ecx = edx = 0;  // @12_603a50
  edi = eax;  // @13_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @14_603a50
  goto L603aac;  // @15_603a50
  L603aa7:;
  edi = 0;  // @17_603a50
  FL[3] = edi;  // @18_603a50
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_603a50
  L603aac:;
  esi = 0;  // @21_603a50
  FL[3] = esi;  // @22_603a50
  reg.state = (s32)((u32)(4294967295));  // @23_603a50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }); FL[1] = esi;  // @24_603a50
  if (FL[0] <= FL[1]) goto L603b6f;  // @25_603a50
  L603ac0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @27_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @28_603a50
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @29_603a50
  if (FL[0] >= FL[1]) goto L603af1;  // @30_603a50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @31_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_603a50
  ebx = (ebx + esi);  // @33_603a50
  FL[3] = ebx;  // @34_603a50
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @35_603a50
  if (FL[0] < FL[1]) goto L603aea;  // @36_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @37_603a50
  FL[2] = (eax & eax);  // @38_603a50
  if (FL[2] == 0) goto L603ae9;  // @39_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @40_603a50
  ecx = edx = 0;  // @41_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_603a50
  ebx = (u32)(eax + ebx*8);  // @43_603a50
  goto L603b19;  // @44_603a50
  L603ae9:;
  __builtin_trap();  // @46_603a50
  L603aea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_603a50
  ebx = (u32)(eax + ebx*8);  // @49_603a50
  goto L603b19;  // @50_603a50
  L603af1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @52_603a50
  FL[2] = (eax & eax);  // @53_603a50
  if (FL[2] == 0) goto L603afe;  // @54_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @55_603a50
  ecx = edx = 0;  // @56_603a50
  goto L603aff;  // @57_603a50
  L603afe:;
  __builtin_trap();  // @59_603a50
  L603aff:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @61_603a50
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @62_603a50
  if (FL[0] < FL[1]) goto L603b14;  // @63_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @64_603a50
  FL[2] = (eax & eax);  // @65_603a50
  if (FL[2] == 0) goto L603b13;  // @66_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @67_603a50
  ecx = edx = 0;  // @68_603a50
  goto L603b14;  // @69_603a50
  L603b13:;
  __builtin_trap();  // @71_603a50
  L603b14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @73_603a50
  ebx = (u32)(eax + esi*8);  // @74_603a50
  L603b19:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @76_603a50
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @77_603a50
  if (FL[0] < FL[1]) goto L603b2f;  // @78_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @79_603a50
  FL[2] = (eax & eax);  // @80_603a50
  if (FL[2] == 0) goto L603b2e;  // @81_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @82_603a50
  ecx = edx = 0;  // @83_603a50
  goto L603b2f;  // @84_603a50
  L603b2e:;
  __builtin_trap();  // @86_603a50
  L603b2f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @88_603a50
  edi = (u32)(eax + esi*8);  // @89_603a50
  FL[0] = ebx; FL[1] = edi;  // @90_603a50
  if (FL[0] == FL[1]) goto L603b5f;  // @91_603a50
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @92_603a50
  if (FL[0] != FL[1]) goto L603b46;  // @93_603a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @94_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @96_603a50
  ecx = edx = 0;  // @97_603a50
  L603b46:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @99_603a50
  if (FL[0] == FL[1]) goto L603b50;  // @100_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @101_603a50
  goto L603b57;  // @102_603a50
  L603b50:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @104_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @106_603a50
  ecx = edx = 0;  // @107_603a50
  L603b57:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @109_603a50
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @110_603a50
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @111_603a50
  L603b5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @113_603a50
  esi = (esi + 1);  // @114_603a50
  FL[3] = esi;  // @115_603a50
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @116_603a50
  if (FL[0] < FL[1]) goto L603ac0;  // @117_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @118_603a50
  L603b6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @120_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @121_603a50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @122_603a50
  if (FL[0] <= FL[1]) goto L603b9f;  // @123_603a50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @124_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @125_603a50
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @126_603a50
  if (FL[0] < FL[1]) goto L603b98;  // @127_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @128_603a50
  FL[2] = (eax & eax);  // @129_603a50
  if (FL[2] == 0) goto L603b97;  // @130_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @131_603a50
  ecx = edx = 0;  // @132_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @133_603a50
  esi = (u32)(eax + ebx*8);  // @134_603a50
  goto L603bc5;  // @135_603a50
  L603b97:;
  __builtin_trap();  // @137_603a50
  L603b98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @139_603a50
  esi = (u32)(eax + ebx*8);  // @140_603a50
  goto L603bc5;  // @141_603a50
  L603b9f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @143_603a50
  FL[2] = (eax & eax);  // @144_603a50
  if (FL[2] == 0) goto L603bac;  // @145_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @146_603a50
  ecx = edx = 0;  // @147_603a50
  goto L603bad;  // @148_603a50
  L603bac:;
  __builtin_trap();  // @150_603a50
  L603bad:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @152_603a50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @153_603a50
  if (FL[0] > FL[1]) goto L603bc3;  // @154_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @155_603a50
  FL[2] = (eax & eax);  // @156_603a50
  if (FL[2] == 0) goto L603bc2;  // @157_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @158_603a50
  ecx = edx = 0;  // @159_603a50
  goto L603bc3;  // @160_603a50
  L603bc2:;
  __builtin_trap();  // @162_603a50
  L603bc3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_603a50
  L603bc5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @166_603a50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @167_603a50
  if (FL[2] == 0) goto L603bd7;  // @168_603a50
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @169_603a50
  if (FL[0] != FL[1]) goto L603be4;  // @170_603a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @171_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @172_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @173_603a50
  ecx = edx = 0;  // @174_603a50
  L603bd7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @176_603a50
  ecx = edi;  // @177_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @178_603a50
  ecx = edx = 0;  // @179_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @180_603a50
  { u8 v = (u8)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @181_603a50
  L603be4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @183_603a50
  ecx = edi;  // @184_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @185_603a50
  ecx = edx = 0;  // @186_603a50
  SEH_LEAVE();  // @187_603a50
  return eax;  // @188_603a50
}
PCREG(603a50, lifted_603a50);

extern "C" u32 THISCALL lifted_437440(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665ac2);  // @h_437440
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_437440
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @2_437440
  FL[3] = (eax & 0xff);  // @3_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @4_437440
  eax = ext_41e290_cdecl1((u32)(28));  // @5_437440
  ecx = edx = 0;  // @6_437440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @7_437440
  reg.state = (s32)((u32)(0));  // @8_437440
  FL[2] = (eax & eax);  // @9_437440
  if (FL[2] == 0) goto L4374a3;  // @10_437440
  ecx = eax;  // @11_437440
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @12_437440
  ecx = edx = 0;  // @13_437440
  goto L4374a5;  // @14_437440
  L4374a3:;
  eax = 0;  // @16_437440
  FL[3] = eax;  // @17_437440
  L4374a5:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @19_437440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @20_437440
  reg.state = (s32)((u32)(4294967295));  // @21_437440
  if (FL[0] == FL[1]) goto L437632;  // @22_437440
  L4374c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @24_437440
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @25_437440
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[1], PV[0]);  // @28_437440
  ecx = edx = 0;  // @29_437440
  edi = eax;  // @30_437440
  FL[2] = (edi & edi);  // @31_437440
  if (FL[2] == 0) goto L437538;  // @32_437440
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 160), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @33_437440
  if (FL[0] == FL[1]) goto L4374e5;  // @34_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @35_437440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 161), &v, sizeof v); }  // @36_437440
  L4374e5:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) & (u32)(2));  // @38_437440
  if (FL[2] == 0) goto L43752e;  // @39_437440
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @40_437440
  if (FL[0] != FL[1]) goto L43752e;  // @41_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @42_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2574));  // @44_437440
  ecx = edx = 0;  // @45_437440
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_437440
  PV[3] = (u32)(eax);  // @48_437440
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6793848), PV[2]);  // @49_437440
  ecx = edx = 0;  // @50_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @51_437440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @52_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_437440
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @54_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[4]);  // @55_437440
  ecx = edx = 0;  // @56_437440
  L43752e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @58_437440
  ecx = ebx;  // @59_437440
  PV[5] = (u32)(edi);  // @60_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[5]);  // @61_437440
  ecx = edx = 0;  // @62_437440
  goto L437540;  // @63_437440
  L437538:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @65_437440
  ecx = ebx;  // @66_437440
  PV[6] = (u32)(esi);  // @67_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[6]);  // @68_437440
  ecx = edx = 0;  // @69_437440
  L437540:;
  esi = (esi + (u32)(28));  // @71_437440
  FL[3] = esi;  // @72_437440
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @73_437440
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @74_437440
  if (FL[3] != 0) goto L4374c0;  // @75_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 145), sizeof v); (u32)v; })) & 0xff);  // @76_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @77_437440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @78_437440
  if (FL[2] == 0) goto L437638;  // @79_437440
  FL[2] = (esi & esi);  // @80_437440
  if (FL[2] == 0) goto L437644;  // @81_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_437440
  ecx = (u32)(EBP - 164);  // @83_437440
  PV[7] = (u32)(ecx);  // @84_437440
  ecx = esi;  // @85_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @86_437440
  ecx = edx = 0;  // @87_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_437440
  ecx = (u32)(EBP - 164);  // @89_437440
  PV[8] = (u32)(ecx);  // @90_437440
  ecx = esi;  // @91_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @92_437440
  ecx = edx = 0;  // @93_437440
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @94_437440
  ecx = eax;  // @95_437440
  if (FL[0] == FL[1]) goto L437638;  // @96_437440
  L437594:;
  edx = (u32)(EBP - 144);  // @98_437440
  edx = (edx - ecx);  // @99_437440
  FL[3] = edx;  // @100_437440
  L4375a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @102_437440
  ecx = (u32)(ecx + 1);  // @103_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @104_437440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @105_437440
  if (FL[2] != 0) goto L4375a0;  // @106_437440
  esi = (u32)(EBP - 144);  // @107_437440
  L4375b3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @109_437440
  edi = esi;  // @110_437440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @111_437440
  if (FL[2] == 0) goto L43760d;  // @112_437440
  FL[0] = (eax & 0xff); FL[1] = (u32)(48);  // @113_437440
  if (FL[0] == FL[1]) goto L43760d;  // @114_437440
  L4375c0:;
  FL[0] = (eax & 0xff); FL[1] = (u32)(43);  // @116_437440
  if (FL[0] == FL[1]) goto L4375d0;  // @117_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @118_437440
  esi = (esi + 1);  // @119_437440
  FL[3] = esi;  // @120_437440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @121_437440
  if (FL[2] != 0) goto L4375c0;  // @122_437440
  FL[0] = (eax & 0xff); FL[1] = (u32)(43);  // @123_437440
  if (FL[0] != FL[1]) goto L4375d4;  // @124_437440
  L4375d0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @126_437440
  esi = (esi + 1);  // @127_437440
  FL[3] = esi;  // @128_437440
  L4375d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @130_437440
  PV[9] = (u32)(edi);  // @131_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @133_437440
  ecx = edx = 0;  // @134_437440
  FL[2] = (eax & eax);  // @135_437440
  if (FL[2] == 0) goto L4375e7;  // @136_437440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @137_437440
  goto L4375b3;  // @138_437440
  L4375e7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @140_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2603));  // @142_437440
  ecx = edx = 0;  // @143_437440
  PV[10] = (u32)(edi);  // @144_437440
  PV[11] = (u32)(eax);  // @145_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @146_437440
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[11], (u32)(6793964), PV[10]);  // @147_437440
  ecx = edx = 0;  // @148_437440
  goto L4375b3;  // @149_437440
  L43760d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @151_437440
  ecx = (u32)(EBP - 164);  // @152_437440
  PV[12] = (u32)(ecx);  // @153_437440
  ecx = esi;  // @154_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @155_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[12]);  // @156_437440
  ecx = edx = 0;  // @157_437440
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @158_437440
  ecx = eax;  // @159_437440
  if (FL[0] != FL[1]) goto L437594;  // @160_437440
  goto L437638;  // @161_437440
  L437632:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @163_437440
  L437638:;
  FL[2] = (esi & esi);  // @165_437440
  if (FL[2] == 0) goto L437644;  // @166_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @167_437440
  ecx = esi;  // @168_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @169_437440
  ecx = edx = 0;  // @170_437440
  L437644:;
  SEH_LEAVE();  // @172_437440
  ext_633654(G(u32, 0x6f5630));  // @173_437440
  return eax;  // @174_437440
}
PCREG(437440, lifted_437440);

extern "C" u32 THISCALL lifted_5c6cb0(u32 ecx_in) {
  SEH_ENTER(0x66c6f6);  // @h_5c6cb0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5c6cb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_5c6cb0
  ecx = edx = 0;  // @5_5c6cb0
  ecx = (u32)(EBP - 148);  // @6_5c6cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @7_5c6cb0
  PV[0] = (u32)(ecx);  // @8_5c6cb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_5c6cb0
  ecx = eax;  // @10_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6970440), PV[0]);  // @11_5c6cb0
  ecx = edx = 0;  // @12_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_5c6cb0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @14_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @17_5c6cb0
  ecx = edx = 0;  // @18_5c6cb0
  edi = eax;  // @19_5c6cb0
  FL[2] = (edi & edi);  // @20_5c6cb0
  if (FL[2] == 0) goto L5c6f23;  // @21_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @22_5c6cb0
  eax = (u32)(EBP - 160);  // @23_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_5c6cb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @25_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_5c6cb0
  PV[2] = (u32)(eax);  // @27_5c6cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @28_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @29_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6970472), (u32)(0), (u32)(7030208), (u32)(812));  // @31_5c6cb0
  ecx = edx = 0;  // @32_5c6cb0
  eax = (eax & 0xffff);  // @33_5c6cb0
  ecx = edi;  // @34_5c6cb0
  PV[3] = (u32)(eax);  // @35_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[3], PV[2], (u32)(0));  // @36_5c6cb0
  ecx = edx = 0;  // @37_5c6cb0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @38_5c6cb0
  if (FL[0] == FL[1]) goto L5c6f23;  // @39_5c6cb0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @40_5c6cb0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 84), &v, sizeof v); }  // @41_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @43_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @45_5c6cb0
  ecx = edx = 0;  // @46_5c6cb0
  esi = eax;  // @47_5c6cb0
  FL[2] = (esi & esi);  // @48_5c6cb0
  if (FL[2] == 0) goto L5c6e22;  // @49_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @50_5c6cb0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }); FL[1] = (u32)(134217754);  // @51_5c6cb0
  if (FL[0] == FL[1]) goto L5c6e13;  // @52_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @53_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7030208), (u32)(819));  // @55_5c6cb0
  ecx = edx = 0;  // @56_5c6cb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_5c6cb0
  edi = eax;  // @58_5c6cb0
  eax = (u32)(EBP - 144);  // @59_5c6cb0
  ecx = esi;  // @60_5c6cb0
  PV[5] = (u32)(eax);  // @61_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[5], (u32)(1));  // @62_5c6cb0
  ecx = edx = 0;  // @63_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_5c6cb0
  ecx = eax;  // @65_5c6cb0
  reg.state = (s32)((u32)(0));  // @66_5c6cb0
  eax = ext_4cc1d0_thiscall1(ecx);  // @67_5c6cb0
  ecx = edx = 0;  // @68_5c6cb0
  PV[6] = (u32)(eax);  // @69_5c6cb0
  PV[7] = (u32)(edi);  // @70_5c6cb0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[7], (u32)(7030636), PV[6]);  // @71_5c6cb0
  ecx = edx = 0;  // @72_5c6cb0
  reg.state = (s32)((u32)(4294967295));  // @73_5c6cb0
  ecx = (u32)(EBP - 144);  // @74_5c6cb0
  eax = ext_4cbec0_thiscall1(ecx);  // @75_5c6cb0
  ecx = edx = 0;  // @76_5c6cb0
  goto L5c6e22;  // @77_5c6cb0
  L5c6e13:;
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @79_5c6cb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @80_5c6cb0
  ecx = ebx;  // @81_5c6cb0
  PV[9] = (u32)(eax);  // @82_5c6cb0
  eax = ext_5c6370_stdcall2(PV[9], PV[8]);  // @83_5c6cb0
  ecx = edx = 0;  // @84_5c6cb0
  L5c6e22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @86_5c6cb0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; });  // @87_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @88_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[10]);  // @90_5c6cb0
  ecx = edx = 0;  // @91_5c6cb0
  esi = eax;  // @92_5c6cb0
  FL[2] = (esi & esi);  // @93_5c6cb0
  if (FL[2] == 0) goto L5c6eb7;  // @94_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @95_5c6cb0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }); FL[1] = (u32)(134217754);  // @96_5c6cb0
  if (FL[0] == FL[1]) goto L5c6ea2;  // @97_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @98_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7030208), (u32)(827));  // @100_5c6cb0
  ecx = edx = 0;  // @101_5c6cb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_5c6cb0
  edi = eax;  // @103_5c6cb0
  eax = (u32)(EBP - 144);  // @104_5c6cb0
  ecx = esi;  // @105_5c6cb0
  PV[11] = (u32)(eax);  // @106_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[11], (u32)(1));  // @107_5c6cb0
  ecx = edx = 0;  // @108_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @109_5c6cb0
  ecx = eax;  // @110_5c6cb0
  reg.state = (s32)((u32)(1));  // @111_5c6cb0
  eax = ext_4cc1d0_thiscall1(ecx);  // @112_5c6cb0
  ecx = edx = 0;  // @113_5c6cb0
  PV[12] = (u32)(eax);  // @114_5c6cb0
  PV[13] = (u32)(edi);  // @115_5c6cb0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[13], (u32)(7030636), PV[12]);  // @116_5c6cb0
  ecx = edx = 0;  // @117_5c6cb0
  reg.state = (s32)((u32)(4294967295));  // @118_5c6cb0
  ecx = (u32)(EBP - 144);  // @119_5c6cb0
  eax = ext_4cbec0_thiscall1(ecx);  // @120_5c6cb0
  ecx = edx = 0;  // @121_5c6cb0
  goto L5c6eb7;  // @122_5c6cb0
  L5c6ea2:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @124_5c6cb0
  ecx = ebx;  // @125_5c6cb0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @126_5c6cb0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @127_5c6cb0
  eax = (eax & 0xff);  // @128_5c6cb0
  PV[15] = (u32)(eax);  // @129_5c6cb0
  eax = ext_5c6370_stdcall2(PV[15], PV[14]);  // @130_5c6cb0
  ecx = edx = 0;  // @131_5c6cb0
  L5c6eb7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @133_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @134_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @135_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @137_5c6cb0
  ecx = edx = 0;  // @138_5c6cb0
  edi = eax;  // @139_5c6cb0
  FL[2] = (edi & edi);  // @140_5c6cb0
  if (FL[2] == 0) goto L5c6f23;  // @141_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @142_5c6cb0
  eax = (u32)(EBP - 152);  // @143_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @144_5c6cb0
  PV[16] = (u32)(eax);  // @145_5c6cb0
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @146_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @147_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6882516), (u32)(0), (u32)(7030208), (u32)(836));  // @149_5c6cb0
  ecx = edx = 0;  // @150_5c6cb0
  eax = (eax & 0xffff);  // @151_5c6cb0
  ecx = edi;  // @152_5c6cb0
  PV[17] = (u32)(eax);  // @153_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[17], PV[16], (u32)(0));  // @154_5c6cb0
  ecx = edx = 0;  // @155_5c6cb0
  L5c6f23:;
  SEH_LEAVE();  // @157_5c6cb0
  ext_633654(G(u32, 0x6f5630));  // @158_5c6cb0
  return eax;  // @159_5c6cb0
}
PCREG(5c6cb0, lifted_5c6cb0);

extern "C" u32 THISCALL lifted_4335e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665608);  // @h_4335e0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4335e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @1_4335e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4335e0
  esi = (esi + (u32)(200));  // @3_4335e0
  FL[3] = esi;  // @4_4335e0
  if (FL[3] == 0) goto L43370a;  // @5_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4335e0
  ecx = (u32)(EBP - 416);  // @7_4335e0
  PV[0] = (u32)(ecx);  // @8_4335e0
  ecx = esi;  // @9_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @10_4335e0
  ecx = edx = 0;  // @11_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_4335e0
  ecx = (u32)(EBP - 416);  // @13_4335e0
  PV[1] = (u32)(ecx);  // @14_4335e0
  ecx = esi;  // @15_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @16_4335e0
  ecx = edx = 0;  // @17_4335e0
  edi = eax;  // @18_4335e0
  FL[2] = (edi & edi);  // @19_4335e0
  if (FL[2] == 0) goto L43370a;  // @20_4335e0
  L433650:;
  ecx = (u32)(EBP - 144);  // @22_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791768));  // @23_4335e0
  ecx = edx = 0;  // @24_4335e0
  eax = (u32)(EBP - 144);  // @25_4335e0
  reg.state = (s32)((u32)(0));  // @26_4335e0
  PV[2] = (u32)(eax);  // @27_4335e0
  ecx = ebx;  // @28_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[2]);  // @29_4335e0
  ecx = edx = 0;  // @30_4335e0
  ecx = (u32)(EBP - 144);  // @31_4335e0
  reg.state = (s32)((u32)(4294967295));  // @32_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @33_4335e0
  ecx = edx = 0;  // @34_4335e0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_4335e0
  ecx = (u32)(EBP - 144);  // @36_4335e0
  eax = ext_4cbe80_thiscall2(ecx, PV[3]);  // @37_4335e0
  ecx = edx = 0;  // @38_4335e0
  eax = (u32)(EBP - 144);  // @39_4335e0
  reg.state = (s32)((u32)(1));  // @40_4335e0
  PV[4] = (u32)(eax);  // @41_4335e0
  ecx = ebx;  // @42_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[4]);  // @43_4335e0
  ecx = edx = 0;  // @44_4335e0
  ecx = (u32)(EBP - 144);  // @45_4335e0
  reg.state = (s32)((u32)(4294967295));  // @46_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_4335e0
  ecx = edx = 0;  // @48_4335e0
  ecx = (u32)(EBP - 144);  // @49_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6778092));  // @50_4335e0
  ecx = edx = 0;  // @51_4335e0
  eax = (u32)(EBP - 144);  // @52_4335e0
  reg.state = (s32)((u32)(2));  // @53_4335e0
  PV[5] = (u32)(eax);  // @54_4335e0
  ecx = ebx;  // @55_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[5]);  // @56_4335e0
  ecx = edx = 0;  // @57_4335e0
  ecx = (u32)(EBP - 144);  // @58_4335e0
  reg.state = (s32)((u32)(4294967295));  // @59_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @60_4335e0
  ecx = edx = 0;  // @61_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_4335e0
  ecx = (u32)(EBP - 416);  // @63_4335e0
  PV[6] = (u32)(ecx);  // @64_4335e0
  ecx = esi;  // @65_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[6]);  // @66_4335e0
  ecx = edx = 0;  // @67_4335e0
  edi = eax;  // @68_4335e0
  FL[2] = (edi & edi);  // @69_4335e0
  if (FL[2] != 0) goto L433650;  // @70_4335e0
  L43370a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @72_4335e0
  esi = (esi + (u32)(172));  // @73_4335e0
  FL[3] = esi;  // @74_4335e0
  if (FL[3] == 0) goto L43386c;  // @75_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_4335e0
  ecx = (u32)(EBP - 428);  // @77_4335e0
  PV[7] = (u32)(ecx);  // @78_4335e0
  ecx = esi;  // @79_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @80_4335e0
  ecx = edx = 0;  // @81_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_4335e0
  ecx = (u32)(EBP - 428);  // @83_4335e0
  PV[8] = (u32)(ecx);  // @84_4335e0
  ecx = esi;  // @85_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @86_4335e0
  ecx = edx = 0;  // @87_4335e0
  edi = eax;  // @88_4335e0
  FL[2] = (edi & edi);  // @89_4335e0
  if (FL[2] == 0) goto L43386c;  // @90_4335e0
  L433750:;
  ecx = (u32)(EBP - 144);  // @92_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791760));  // @93_4335e0
  ecx = edx = 0;  // @94_4335e0
  eax = (u32)(EBP - 144);  // @95_4335e0
  reg.state = (s32)((u32)(3));  // @96_4335e0
  PV[9] = (u32)(eax);  // @97_4335e0
  ecx = ebx;  // @98_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[9]);  // @99_4335e0
  ecx = edx = 0;  // @100_4335e0
  ecx = (u32)(EBP - 144);  // @101_4335e0
  reg.state = (s32)((u32)(4294967295));  // @102_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @103_4335e0
  ecx = edx = 0;  // @104_4335e0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @105_4335e0
  ecx = (u32)(EBP - 144);  // @106_4335e0
  eax = ext_4cbe80_thiscall2(ecx, PV[10]);  // @107_4335e0
  ecx = edx = 0;  // @108_4335e0
  eax = (u32)(EBP - 144);  // @109_4335e0
  reg.state = (s32)((u32)(4));  // @110_4335e0
  PV[11] = (u32)(eax);  // @111_4335e0
  ecx = ebx;  // @112_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[11]);  // @113_4335e0
  ecx = edx = 0;  // @114_4335e0
  ecx = (u32)(EBP - 144);  // @115_4335e0
  reg.state = (s32)((u32)(4294967295));  // @116_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @117_4335e0
  ecx = edx = 0;  // @118_4335e0
  ecx = (u32)(EBP - 144);  // @119_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791776));  // @120_4335e0
  ecx = edx = 0;  // @121_4335e0
  eax = (u32)(EBP - 144);  // @122_4335e0
  reg.state = (s32)((u32)(5));  // @123_4335e0
  PV[12] = (u32)(eax);  // @124_4335e0
  ecx = ebx;  // @125_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[12]);  // @126_4335e0
  ecx = edx = 0;  // @127_4335e0
  ecx = (u32)(EBP - 144);  // @128_4335e0
  reg.state = (s32)((u32)(4294967295));  // @129_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @130_4335e0
  ecx = edx = 0;  // @131_4335e0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @132_4335e0
  ecx = (u32)(EBP - 400);  // @133_4335e0
  eax = ext_4cbe50_thiscall2(ecx, PV[13]);  // @134_4335e0
  ecx = edx = 0;  // @135_4335e0
  eax = (u32)(EBP - 400);  // @136_4335e0
  reg.state = (s32)((u32)(6));  // @137_4335e0
  PV[14] = (u32)(eax);  // @138_4335e0
  ecx = ebx;  // @139_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[14]);  // @140_4335e0
  ecx = edx = 0;  // @141_4335e0
  ecx = (u32)(EBP - 272);  // @142_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6778092));  // @143_4335e0
  ecx = edx = 0;  // @144_4335e0
  eax = (u32)(EBP - 272);  // @145_4335e0
  reg.state = (s32)((u32)(7));  // @146_4335e0
  PV[15] = (u32)(eax);  // @147_4335e0
  ecx = ebx;  // @148_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[15]);  // @149_4335e0
  ecx = edx = 0;  // @150_4335e0
  ecx = (u32)(EBP - 272);  // @151_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @152_4335e0
  ecx = edx = 0;  // @153_4335e0
  ecx = (u32)(EBP - 400);  // @154_4335e0
  reg.state = (s32)((u32)(4294967295));  // @155_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @156_4335e0
  ecx = edx = 0;  // @157_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_4335e0
  ecx = (u32)(EBP - 428);  // @159_4335e0
  PV[16] = (u32)(ecx);  // @160_4335e0
  ecx = esi;  // @161_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[16]);  // @162_4335e0
  ecx = edx = 0;  // @163_4335e0
  edi = eax;  // @164_4335e0
  FL[2] = (edi & edi);  // @165_4335e0
  if (FL[2] != 0) goto L433750;  // @166_4335e0
  L43386c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @168_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @169_4335e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(1134));  // @170_4335e0
  ecx = edx = 0;  // @171_4335e0
  esi = eax;  // @172_4335e0
  ecx = ebx;  // @173_4335e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @174_4335e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @175_4335e0
  ecx = edx = 0;  // @176_4335e0
  PV[17] = (u32)(eax);  // @177_4335e0
  PV[18] = (u32)(esi);  // @178_4335e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[18], (u32)(6791780), PV[17]);  // @179_4335e0
  ecx = edx = 0;  // @180_4335e0
  SEH_LEAVE();  // @181_4335e0
  ext_633654(G(u32, 0x6f5630));  // @182_4335e0
  return eax;  // @183_4335e0
}
PCREG(4335e0, lifted_4335e0);

extern "C" u32 THISCALL lifted_5b8b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x663fdf);  // @h_5b8b50
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_5b8b50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5b8b50
  eax = (u32)(esi + 72);  // @2_5b8b50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_5b8b50
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @4_5b8b50
  ecx = edi;  // @5_5b8b50
  PV[0] = (u32)(eax);  // @6_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[0]);  // @8_5b8b50
  ecx = edx = 0;  // @9_5b8b50
  eax = ext_41e290_cdecl1((u32)(28));  // @10_5b8b50
  ecx = edx = 0;  // @11_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @12_5b8b50
  reg.state = (s32)((u32)(0));  // @13_5b8b50
  FL[2] = (eax & eax);  // @14_5b8b50
  if (FL[2] == 0) goto L5b8bb0;  // @15_5b8b50
  ecx = eax;  // @16_5b8b50
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @17_5b8b50
  ecx = edx = 0;  // @18_5b8b50
  ecx = eax;  // @19_5b8b50
  goto L5b8bb2;  // @20_5b8b50
  L5b8bb0:;
  ecx = 0;  // @22_5b8b50
  FL[3] = ecx;  // @23_5b8b50
  L5b8bb2:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @25_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_5b8b50
  PV[1] = (u32)(ecx);  // @27_5b8b50
  ecx = edi;  // @28_5b8b50
  reg.state = (s32)((u32)(4294967295));  // @29_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[1]);  // @30_5b8b50
  ecx = edx = 0;  // @31_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_5b8b50
  eax = (u32)(esi + 80);  // @33_5b8b50
  PV[2] = (u32)(eax);  // @34_5b8b50
  ecx = edi;  // @35_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[2]);  // @36_5b8b50
  ecx = edx = 0;  // @37_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_5b8b50
  eax = (u32)(esi + 84);  // @39_5b8b50
  PV[3] = (u32)(eax);  // @40_5b8b50
  ecx = edi;  // @41_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[3]);  // @42_5b8b50
  ecx = edx = 0;  // @43_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_5b8b50
  eax = (u32)(esi + 88);  // @45_5b8b50
  PV[4] = (u32)(eax);  // @46_5b8b50
  ecx = edi;  // @47_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[4]);  // @48_5b8b50
  ecx = edx = 0;  // @49_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @50_5b8b50
  eax = (u32)(esi + 92);  // @51_5b8b50
  PV[5] = (u32)(eax);  // @52_5b8b50
  ecx = edi;  // @53_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[5]);  // @54_5b8b50
  ecx = edx = 0;  // @55_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_5b8b50
  ecx = (u32)(EBP + 8);  // @57_5b8b50
  PV[6] = (u32)(ecx);  // @58_5b8b50
  ecx = edi;  // @59_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[6]);  // @60_5b8b50
  ecx = edx = 0;  // @61_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_5b8b50
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @63_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[7]);  // @66_5b8b50
  ecx = edx = 0;  // @67_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 126), &v, sizeof v); }  // @68_5b8b50
  ecx = (u32)(EBP + 8);  // @69_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_5b8b50
  PV[8] = (u32)(ecx);  // @71_5b8b50
  ecx = edi;  // @72_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[8]);  // @73_5b8b50
  ecx = edx = 0;  // @74_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_5b8b50
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @76_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @77_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @79_5b8b50
  ecx = edx = 0;  // @80_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 130), &v, sizeof v); }  // @81_5b8b50
  ecx = (u32)(EBP + 8);  // @82_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @83_5b8b50
  PV[10] = (u32)(ecx);  // @84_5b8b50
  ecx = edi;  // @85_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[10]);  // @86_5b8b50
  ecx = edx = 0;  // @87_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_5b8b50
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @89_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @90_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[11]);  // @92_5b8b50
  ecx = edx = 0;  // @93_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 134), &v, sizeof v); }  // @94_5b8b50
  ecx = edi;  // @95_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @96_5b8b50
  eax = (u32)(esi + 138);  // @97_5b8b50
  PV[12] = (u32)(eax);  // @98_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[12]);  // @99_5b8b50
  ecx = edx = 0;  // @100_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @101_5b8b50
  eax = (u32)(esi + 150);  // @102_5b8b50
  PV[13] = (u32)(eax);  // @103_5b8b50
  ecx = edi;  // @104_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[13]);  // @105_5b8b50
  ecx = edx = 0;  // @106_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @107_5b8b50
  eax = (u32)(esi + 162);  // @108_5b8b50
  PV[14] = (u32)(eax);  // @109_5b8b50
  ecx = edi;  // @110_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[14]);  // @111_5b8b50
  ecx = edx = 0;  // @112_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @113_5b8b50
  eax = (u32)(esi + 174);  // @114_5b8b50
  PV[15] = (u32)(eax);  // @115_5b8b50
  ecx = edi;  // @116_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[15]);  // @117_5b8b50
  ecx = edx = 0;  // @118_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @119_5b8b50
  eax = (u32)(esi + 178);  // @120_5b8b50
  PV[16] = (u32)(eax);  // @121_5b8b50
  ecx = edi;  // @122_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[16]);  // @123_5b8b50
  ecx = edx = 0;  // @124_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @125_5b8b50
  eax = (u32)(esi + 179);  // @126_5b8b50
  PV[17] = (u32)(eax);  // @127_5b8b50
  ecx = edi;  // @128_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[17]);  // @129_5b8b50
  ecx = edx = 0;  // @130_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @131_5b8b50
  eax = (u32)(esi + 183);  // @132_5b8b50
  PV[18] = (u32)(eax);  // @133_5b8b50
  ecx = edi;  // @134_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, PV[18]);  // @135_5b8b50
  ecx = edx = 0;  // @136_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @137_5b8b50
  ecx = (u32)(EBP + 8);  // @138_5b8b50
  PV[19] = (u32)(ecx);  // @139_5b8b50
  ecx = edi;  // @140_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[19]);  // @141_5b8b50
  ecx = edx = 0;  // @142_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_5b8b50
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @144_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @145_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[20]);  // @147_5b8b50
  ecx = edx = 0;  // @148_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 226), &v, sizeof v); }  // @149_5b8b50
  ecx = edi;  // @150_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @151_5b8b50
  eax = (u32)(esi + 222);  // @152_5b8b50
  PV[21] = (u32)(eax);  // @153_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[21]);  // @154_5b8b50
  ecx = edx = 0;  // @155_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @156_5b8b50
  ecx = (u32)(EBP + 8);  // @157_5b8b50
  PV[22] = (u32)(ecx);  // @158_5b8b50
  ecx = edi;  // @159_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[22]);  // @160_5b8b50
  ecx = edx = 0;  // @161_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @162_5b8b50
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @163_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @164_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[23]);  // @166_5b8b50
  ecx = edx = 0;  // @167_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 226), &v, sizeof v); }  // @168_5b8b50
  ecx = (u32)(EBP - 16);  // @169_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @170_5b8b50
  PV[24] = (u32)(ecx);  // @171_5b8b50
  ecx = edi;  // @172_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[24]);  // @173_5b8b50
  ecx = edx = 0;  // @174_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @175_5b8b50
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @176_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @177_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[25]);  // @179_5b8b50
  ecx = edx = 0;  // @180_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 230), &v, sizeof v); }  // @181_5b8b50
  ecx = edi;  // @182_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @183_5b8b50
  eax = (u32)(esi + 234);  // @184_5b8b50
  PV[26] = (u32)(eax);  // @185_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[26]);  // @186_5b8b50
  ecx = edx = 0;  // @187_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @188_5b8b50
  eax = (u32)(esi + 221);  // @189_5b8b50
  PV[27] = (u32)(eax);  // @190_5b8b50
  ecx = edi;  // @191_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[27]);  // @192_5b8b50
  ecx = edx = 0;  // @193_5b8b50
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @194_5b8b50
  SEH_LEAVE();  // @195_5b8b50
  return eax;  // @196_5b8b50
}
PCREG(5b8b50, lifted_5b8b50);

extern "C" u32 THISCALL lifted_5b59e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c34f);  // @h_5b59e0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5b59e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5b59e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @2_5b59e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_5b59e0
  if (FL[0] != FL[1]) goto L5b5ac0;  // @4_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5b59e0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @6_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5b59e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @9_5b59e0
  ecx = edx = 0;  // @10_5b59e0
  ecx = eax;  // @11_5b59e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_5b59e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @13_5b59e0
  ecx = edx = 0;  // @14_5b59e0
  ecx = eax;  // @15_5b59e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_5b59e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @17_5b59e0
  ecx = edx = 0;  // @18_5b59e0
  esi = eax;  // @19_5b59e0
  ecx = ebx;  // @20_5b59e0
  PV[1] = (u32)(esi);  // @21_5b59e0
  eax = ext_5b6ab0_thiscall2(ecx, PV[1]);  // @22_5b59e0
  ecx = edx = 0;  // @23_5b59e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @24_5b59e0
  FL[2] = (eax & eax);  // @25_5b59e0
  if (FL[2] != 0) goto L5b5ac0;  // @26_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @27_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @28_5b59e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @29_5b59e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @30_5b59e0
  FL[2] = (eax & eax);  // @31_5b59e0
  if (FL[2] == 0) goto L5b5c80;  // @32_5b59e0
  L5b5a70:;
  ecx = eax;  // @34_5b59e0
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2099193));  // @35_5b59e0
  ecx = edx = 0;  // @36_5b59e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @37_5b59e0
  if (FL[2] == 0) goto L5b5aa3;  // @38_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @39_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @40_5b59e0
  FL[2] = (ecx & ecx);  // @41_5b59e0
  if (FL[2] == 0) goto L5b5aa3;  // @42_5b59e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_5b59e0
  eax = (u32)(EBP - 152);  // @44_5b59e0
  PV[2] = (u32)(eax);  // @45_5b59e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 78), sizeof v); (u32)v; });  // @46_5b59e0
  PV[3] = (u32)(eax);  // @47_5b59e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[3], PV[2], (u32)(0));  // @48_5b59e0
  ecx = edx = 0;  // @49_5b59e0
  L5b5aa3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_5b59e0
  ecx = (u32)(EBP - 148);  // @52_5b59e0
  PV[4] = (u32)(ecx);  // @53_5b59e0
  ecx = esi;  // @54_5b59e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[4]);  // @55_5b59e0
  ecx = edx = 0;  // @56_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @57_5b59e0
  FL[2] = (eax & eax);  // @58_5b59e0
  if (FL[2] != 0) goto L5b5a70;  // @59_5b59e0
  goto L5b5c80;  // @60_5b59e0
  L5b5ac0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @62_5b59e0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @63_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_5b59e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[5]);  // @65_5b59e0
  ecx = edx = 0;  // @66_5b59e0
  FL[2] = (eax & eax);  // @67_5b59e0
  if (FL[2] != 0) goto L5b5bd6;  // @68_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_5b59e0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_5b59e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[6]);  // @73_5b59e0
  ecx = edx = 0;  // @74_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @75_5b59e0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @76_5b59e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @77_5b59e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_5b59e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[7]);  // @79_5b59e0
  ecx = edx = 0;  // @80_5b59e0
  ebx = eax;  // @81_5b59e0
  eax = ext_41e290_cdecl1((u32)(28));  // @82_5b59e0
  ecx = edx = 0;  // @83_5b59e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @84_5b59e0
  reg.state = (s32)((u32)(0));  // @85_5b59e0
  FL[2] = (eax & eax);  // @86_5b59e0
  if (FL[2] == 0) goto L5b5b1e;  // @87_5b59e0
  ecx = eax;  // @88_5b59e0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(29));  // @89_5b59e0
  ecx = edx = 0;  // @90_5b59e0
  goto L5b5b20;  // @91_5b59e0
  L5b5b1e:;
  eax = 0;  // @93_5b59e0
  FL[3] = eax;  // @94_5b59e0
  L5b5b20:;
  reg.state = (s32)((u32)(4294967295));  // @96_5b59e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @97_5b59e0
  eax = ext_41e290_cdecl1((u32)(28));  // @98_5b59e0
  ecx = edx = 0;  // @99_5b59e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @100_5b59e0
  reg.state = (s32)((u32)(1));  // @101_5b59e0
  FL[2] = (eax & eax);  // @102_5b59e0
  if (FL[2] == 0) goto L5b5b51;  // @103_5b59e0
  ecx = eax;  // @104_5b59e0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(32));  // @105_5b59e0
  ecx = edx = 0;  // @106_5b59e0
  goto L5b5b53;  // @107_5b59e0
  L5b5b51:;
  eax = 0;  // @109_5b59e0
  FL[3] = eax;  // @110_5b59e0
  L5b5b53:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @112_5b59e0
  edi = (u32)(ebx + 72);  // @113_5b59e0
  esi = (u32)(ebx + 96);  // @114_5b59e0
  reg.state = (s32)((u32)(4294967295));  // @115_5b59e0
  ecx = esi;  // @116_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @117_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @118_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @119_5b59e0
  eax = ext_4de7a0_thiscall1(ecx);  // @120_5b59e0
  ecx = edx = 0;  // @121_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @122_5b59e0
  PV[8] = (u32)(edi);  // @123_5b59e0
  PV[9] = (u32)(esi);  // @124_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_5b59e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[9], PV[8]);  // @126_5b59e0
  ecx = edx = 0;  // @127_5b59e0
  eax = (u32)(ebx + 8);  // @128_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 92), &v, sizeof v); }  // @129_5b59e0
  PV[10] = (u32)(eax);  // @130_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @131_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 84), &v, sizeof v); }  // @132_5b59e0
  eax = ext_634d10_cdecl3(PV[10], (u32)(0), (u32)(48));  // @133_5b59e0
  ecx = edx = 0;  // @134_5b59e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @135_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 56), &v, sizeof v); }  // @136_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 132), &v, sizeof v); }  // @137_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 136), &v, sizeof v); }  // @138_5b59e0
  goto L5b5bd9;  // @139_5b59e0
  L5b5bd6:;
  ebx = (u32)(eax + 4);  // @141_5b59e0
  L5b5bd9:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @143_5b59e0
  FL[2] = (esi & esi);  // @144_5b59e0
  if ((s32)FL[2] > 0) goto L5b5ca0;  // @145_5b59e0
  esi = 0;  // @146_5b59e0
  FL[3] = esi;  // @147_5b59e0
  eax = (u32)(ebx + 8);  // @148_5b59e0
  L5b5bf0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @150_5b59e0
  if (FL[0] == FL[1]) goto L5b5cac;  // @151_5b59e0
  esi = (esi + 1);  // @152_5b59e0
  FL[3] = esi;  // @153_5b59e0
  eax = (eax + (u32)(4));  // @154_5b59e0
  FL[3] = eax;  // @155_5b59e0
  FL[0] = esi; FL[1] = (u32)(12);  // @156_5b59e0
  if ((s32)FL[0] < (s32)FL[1]) goto L5b5bf0;  // @157_5b59e0
  L5b5c02:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @159_5b59e0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @160_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @161_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_5b59e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[11]);  // @163_5b59e0
  ecx = edx = 0;  // @164_5b59e0
  ecx = eax;  // @165_5b59e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @166_5b59e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @167_5b59e0
  ecx = edx = 0;  // @168_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @169_5b59e0
  esi = eax;  // @170_5b59e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_5b59e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(7021036), (u32)(556));  // @172_5b59e0
  ecx = edx = 0;  // @173_5b59e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @174_5b59e0
  edi = eax;  // @175_5b59e0
  eax = (u32)(EBP - 144);  // @176_5b59e0
  ecx = esi;  // @177_5b59e0
  PV[12] = (u32)(eax);  // @178_5b59e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[12], (u32)(1));  // @179_5b59e0
  ecx = edx = 0;  // @180_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @181_5b59e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @182_5b59e0
  reg.state = (s32)((u32)(2));  // @183_5b59e0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @184_5b59e0
  ecx = eax;  // @185_5b59e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @186_5b59e0
  ecx = edx = 0;  // @187_5b59e0
  PV[14] = (u32)(eax);  // @188_5b59e0
  PV[15] = (u32)(edi);  // @189_5b59e0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 48)))(PV[15], (u32)(7021092), PV[14], PV[13]);  // @190_5b59e0
  ecx = edx = 0;  // @191_5b59e0
  ecx = (u32)(EBP - 144);  // @192_5b59e0
  eax = ext_4cbec0_thiscall1(ecx);  // @193_5b59e0
  ecx = edx = 0;  // @194_5b59e0
  L5b5c79:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 140), &v, sizeof v); }  // @196_5b59e0
  L5b5c80:;
  eax = 0;  // @198_5b59e0
  FL[3] = eax;  // @199_5b59e0
  SEH_LEAVE();  // @200_5b59e0
  ext_633654(G(u32, 0x6f5630));  // @201_5b59e0
  return eax;  // @202_5b59e0
  L5b5ca0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi*4 + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @204_5b59e0
  if (FL[0] != FL[1]) goto L5b5c02;  // @205_5b59e0
  esi = (esi - 1);  // @206_5b59e0
  FL[3] = esi;  // @207_5b59e0
  L5b5cac:;
  FL[2] = (esi & esi);  // @209_5b59e0
  if ((s32)FL[2] < 0) goto L5b5c02;  // @210_5b59e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @211_5b59e0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @212_5b59e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @213_5b59e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[16]);  // @214_5b59e0
  ecx = edx = 0;  // @215_5b59e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @216_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @217_5b59e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @218_5b59e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @219_5b59e0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(eax + 13), &v, sizeof v); }  // @220_5b59e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + esi*4 + 8), &v, sizeof v); }  // @221_5b59e0
  goto L5b5c79;  // @222_5b59e0
}
PCREG(5b59e0, lifted_5b59e0);

extern "C" u32 THISCALL lifted_4c5090(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66997b);  // @h_4c5090
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4c5090
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @1_4c5090
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4c5090
  ecx = (u32)(EBP - 188);  // @3_4c5090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4c5090
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @5_4c5090
  eax = ext_4ccba0_thiscall1(ecx);  // @6_4c5090
  ecx = edx = 0;  // @7_4c5090
  PV[0] = (u32)(esi);  // @8_4c5090
  PV[1] = (u32)(edi);  // @9_4c5090
  eax = (u32)(EBP - 188);  // @10_4c5090
  reg.state = (s32)((u32)(0));  // @11_4c5090
  PV[2] = (u32)(eax);  // @12_4c5090
  ecx = ebx;  // @13_4c5090
  eax = ext_4c4f10_stdcall3(PV[2], PV[1], PV[0]);  // @14_4c5090
  ecx = edx = 0;  // @15_4c5090
  eax = (u32)(EBP - 200);  // @16_4c5090
  PV[3] = (u32)(eax);  // @17_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @18_4c5090
  ecx = (u32)(EBP - 188);  // @19_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @20_4c5090
  ecx = edx = 0;  // @21_4c5090
  eax = (u32)(EBP - 200);  // @22_4c5090
  PV[4] = (u32)(eax);  // @23_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @24_4c5090
  ecx = (u32)(EBP - 188);  // @25_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @26_4c5090
  ecx = edx = 0;  // @27_4c5090
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @28_4c5090
  if (FL[0] == FL[1]) goto L4c51c7;  // @29_4c5090
  L4c5130:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_4c5090
  PV[5] = (u32)(eax);  // @32_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @33_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[5]);  // @35_4c5090
  ecx = edx = 0;  // @36_4c5090
  esi = eax;  // @37_4c5090
  FL[2] = (esi & esi);  // @38_4c5090
  if (FL[2] == 0) goto L4c519e;  // @39_4c5090
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @40_4c5090
  if (FL[0] == FL[1]) goto L4c5197;  // @41_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_4c5090
  PV[6] = (u32)(esi);  // @43_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @44_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[6]);  // @46_4c5090
  ecx = edx = 0;  // @47_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @48_4c5090
  PV[7] = (u32)(eax);  // @49_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 44)))(ecx, PV[7]);  // @51_4c5090
  ecx = edx = 0;  // @52_4c5090
  FL[2] = (eax & eax);  // @53_4c5090
  if (FL[2] == 0) goto L4c5172;  // @54_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @55_4c5090
  goto L4c5174;  // @56_4c5090
  L4c5172:;
  edx = 0;  // @58_4c5090
  FL[3] = edx;  // @59_4c5090
  L4c5174:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_4c5090
  PV[8] = (u32)(edx);  // @62_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[8]);  // @65_4c5090
  ecx = edx = 0;  // @66_4c5090
  FL[2] = (eax & eax);  // @67_4c5090
  if (FL[2] == 0) goto L4c519e;  // @68_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @69_4c5090
  ecx = eax;  // @70_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @71_4c5090
  ecx = edx = 0;  // @72_4c5090
  goto L4c519e;  // @73_4c5090
  L4c5197:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_4c5090
  ecx = esi;  // @76_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @77_4c5090
  ecx = edx = 0;  // @78_4c5090
  L4c519e:;
  eax = (u32)(EBP - 200);  // @80_4c5090
  PV[9] = (u32)(eax);  // @81_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @82_4c5090
  ecx = (u32)(EBP - 188);  // @83_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[9]);  // @84_4c5090
  ecx = edx = 0;  // @85_4c5090
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @86_4c5090
  if (FL[0] != FL[1]) goto L4c5130;  // @87_4c5090
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @88_4c5090
  L4c51c7:;
  PV[10] = (u32)(edi);  // @90_4c5090
  PV[11] = (u32)(esi);  // @91_4c5090
  eax = (u32)(EBP - 188);  // @92_4c5090
  ecx = ebx;  // @93_4c5090
  PV[12] = (u32)(eax);  // @94_4c5090
  eax = ext_4c4f10_stdcall3(PV[12], PV[11], PV[10]);  // @95_4c5090
  ecx = edx = 0;  // @96_4c5090
  eax = (u32)(EBP - 200);  // @97_4c5090
  PV[13] = (u32)(eax);  // @98_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @99_4c5090
  ecx = (u32)(EBP - 188);  // @100_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @101_4c5090
  ecx = edx = 0;  // @102_4c5090
  eax = (u32)(EBP - 200);  // @103_4c5090
  PV[14] = (u32)(eax);  // @104_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @105_4c5090
  ecx = (u32)(EBP - 188);  // @106_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[14]);  // @107_4c5090
  ecx = edx = 0;  // @108_4c5090
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @109_4c5090
  if (FL[0] == FL[1]) goto L4c52be;  // @110_4c5090
  L4c5210:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @112_4c5090
  PV[15] = (u32)(eax);  // @113_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @114_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[15]);  // @116_4c5090
  ecx = edx = 0;  // @117_4c5090
  esi = eax;  // @118_4c5090
  FL[2] = (esi & esi);  // @119_4c5090
  if (FL[2] == 0) goto L4c529b;  // @120_4c5090
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @121_4c5090
  if (FL[0] == FL[1]) goto L4c528a;  // @122_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @123_4c5090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_4c5090
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(0), (u32)(0), (u32)(0), (u32)(1));  // @126_4c5090
  ecx = edx = 0;  // @127_4c5090
  PV[16] = (u32)(eax);  // @128_4c5090
  ecx = esi;  // @129_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 440)))(ecx, PV[16]);  // @130_4c5090
  ecx = edx = 0;  // @131_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @132_4c5090
  ebx = eax;  // @133_4c5090
  PV[17] = (u32)(ebx);  // @134_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @135_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[17]);  // @137_4c5090
  ecx = edx = 0;  // @138_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @139_4c5090
  edi = eax;  // @140_4c5090
  PV[18] = (u32)(esi);  // @141_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @142_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[18]);  // @144_4c5090
  ecx = edx = 0;  // @145_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @146_4c5090
  PV[19] = (u32)(eax);  // @147_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 106), sizeof v); (u32)v; });  // @148_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[19]);  // @150_4c5090
  ecx = edx = 0;  // @151_4c5090
  esi = ebx;  // @152_4c5090
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @153_4c5090
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @154_4c5090
  L4c528a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_4c5090
  ecx = esi;  // @157_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @158_4c5090
  ecx = edx = 0;  // @159_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_4c5090
  ecx = esi;  // @161_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 456)))(ecx);  // @162_4c5090
  ecx = edx = 0;  // @163_4c5090
  L4c529b:;
  eax = (u32)(EBP - 200);  // @165_4c5090
  PV[20] = (u32)(eax);  // @166_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @167_4c5090
  ecx = (u32)(EBP - 188);  // @168_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[20]);  // @169_4c5090
  ecx = edx = 0;  // @170_4c5090
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @171_4c5090
  if (FL[0] != FL[1]) goto L4c5210;  // @172_4c5090
  L4c52be:;
  ecx = (u32)(EBP - 188);  // @174_4c5090
  eax = ext_4ccf60_thiscall1(ecx);  // @175_4c5090
  ecx = edx = 0;  // @176_4c5090
  SEH_LEAVE();  // @177_4c5090
  ext_633654(G(u32, 0x6f5630));  // @178_4c5090
  return eax;  // @179_4c5090
}
PCREG(4c5090, lifted_4c5090);

extern "C" u32 THISCALL lifted_45e190(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665bff);  // @h_45e190
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_45e190
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_45e190
  ebx = (ebx & (u32)(280));  // @3_45e190
  FL[3] = ebx;  // @4_45e190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @5_45e190
  ecx = edx = 0;  // @6_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @7_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @8_45e190
  FL[2] = (ecx & ecx);  // @9_45e190
  if (FL[2] == 0) goto L45e25e;  // @10_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_45e190
  edx = (u32)(EBP - 24);  // @12_45e190
  PV[0] = (u32)(edx);  // @13_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @14_45e190
  ecx = edx = 0;  // @15_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @16_45e190
  edx = (u32)(EBP - 24);  // @17_45e190
  PV[1] = (u32)(edx);  // @18_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @19_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @21_45e190
  ecx = edx = 0;  // @22_45e190
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_45e190
  if (FL[0] == FL[1]) goto L45e294;  // @24_45e190
  L45e200:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @26_45e190
  PV[2] = (u32)(eax);  // @27_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[2]);  // @29_45e190
  ecx = edx = 0;  // @30_45e190
  esi = eax;  // @31_45e190
  FL[2] = (esi & esi);  // @32_45e190
  if (FL[2] != 0) goto L45e226;  // @33_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @34_45e190
  edx = (u32)(EBP - 24);  // @35_45e190
  PV[3] = (u32)(edx);  // @36_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @37_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[3]);  // @39_45e190
  ecx = edx = 0;  // @40_45e190
  goto L45e22c;  // @41_45e190
  L45e226:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @43_45e190
  if (FL[0] != FL[1]) goto L45e243;  // @44_45e190
  L45e22c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @46_45e190
  edx = (u32)(EBP - 24);  // @47_45e190
  PV[4] = (u32)(edx);  // @48_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @49_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @51_45e190
  ecx = edx = 0;  // @52_45e190
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @53_45e190
  if (FL[0] != FL[1]) goto L45e200;  // @54_45e190
  goto L45e294;  // @55_45e190
  L45e243:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_45e190
  ecx = (u32)(esi + 16);  // @58_45e190
  eax = (eax + (u32)(64));  // @59_45e190
  FL[3] = eax;  // @60_45e190
  FL[0] = ecx; FL[1] = eax;  // @61_45e190
  if (FL[0] == FL[1]) goto L45e256;  // @62_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @64_45e190
  L45e256:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) | ebx)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @66_45e190
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @67_45e190
  goto L45e2fe;  // @68_45e190
  L45e25e:;
  eax = ext_41e290_cdecl1((u32)(28));  // @70_45e190
  ecx = edx = 0;  // @71_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @72_45e190
  reg.state = (s32)((u32)(0));  // @73_45e190
  FL[2] = (eax & eax);  // @74_45e190
  if (FL[2] == 0) goto L45e285;  // @75_45e190
  ecx = eax;  // @76_45e190
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @77_45e190
  ecx = edx = 0;  // @78_45e190
  ecx = eax;  // @79_45e190
  goto L45e287;  // @80_45e190
  L45e285:;
  ecx = 0;  // @82_45e190
  FL[3] = ecx;  // @83_45e190
  L45e287:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @85_45e190
  reg.state = (s32)((u32)(4294967295));  // @86_45e190
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @87_45e190
  L45e294:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_45e190
  PV[5] = (u32)(edi);  // @90_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @91_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, PV[5]);  // @93_45e190
  ecx = edx = 0;  // @94_45e190
  esi = eax;  // @95_45e190
  PV[6] = (u32)(esi);  // @96_45e190
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @97_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @98_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, PV[6]);  // @100_45e190
  ecx = edx = 0;  // @101_45e190
  FL[2] = (eax & eax);  // @102_45e190
  if (FL[2] == 0) goto L45e2c1;  // @103_45e190
  edx = 0;  // @104_45e190
  FL[3] = edx;  // @105_45e190
  goto L45e2f2;  // @106_45e190
  L45e2c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @108_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @109_45e190
  FL[2] = (eax & eax);  // @110_45e190
  if (FL[2] == 0) goto L45e2e0;  // @111_45e190
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }); FL[1] = esi;  // @112_45e190
  if (FL[0] > FL[1]) goto L45e2e0;  // @113_45e190
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @114_45e190
  if (FL[0] >= FL[1]) goto L45e2e0;  // @115_45e190
  ecx = esi;  // @116_45e190
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @117_45e190
  ecx = edx = 0;  // @118_45e190
  edx = eax;  // @119_45e190
  goto L45e2f2;  // @120_45e190
  L45e2e0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @122_45e190
  if (FL[0] != FL[1]) goto L45e2ef;  // @123_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_45e190
  PV[7] = (u32)(esi);  // @125_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[7]);  // @126_45e190
  ecx = edx = 0;  // @127_45e190
  L45e2ef:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @129_45e190
  L45e2f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @131_45e190
  PV[8] = (u32)(edx);  // @132_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @133_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[8]);  // @135_45e190
  ecx = edx = 0;  // @136_45e190
  L45e2fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @138_45e190
  ecx = edi;  // @139_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @140_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @141_45e190
  PV[9] = (u32)(eax);  // @142_45e190
  PV[10] = (u32)(esi);  // @143_45e190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 284)))(ecx, PV[10], PV[9]);  // @144_45e190
  ecx = edx = 0;  // @145_45e190
  FL[2] = ((ebx & 0xff) & (u32)(8));  // @146_45e190
  if (FL[2] == 0) goto L45e36b;  // @147_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @148_45e190
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @149_45e190
  if (FL[0] == FL[1]) goto L45e36b;  // @150_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @151_45e190
  PV[11] = (u32)(esi);  // @152_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[11]);  // @154_45e190
  ecx = edx = 0;  // @155_45e190
  FL[2] = (eax & eax);  // @156_45e190
  if (FL[2] == 0) goto L45e332;  // @157_45e190
  ecx = 0;  // @158_45e190
  FL[3] = ecx;  // @159_45e190
  goto L45e363;  // @160_45e190
  L45e332:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @162_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @163_45e190
  FL[2] = (eax & eax);  // @164_45e190
  if (FL[2] == 0) goto L45e351;  // @165_45e190
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }); FL[1] = esi;  // @166_45e190
  if (FL[0] > FL[1]) goto L45e351;  // @167_45e190
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @168_45e190
  if (FL[0] >= FL[1]) goto L45e351;  // @169_45e190
  ecx = esi;  // @170_45e190
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @171_45e190
  ecx = edx = 0;  // @172_45e190
  ecx = eax;  // @173_45e190
  goto L45e363;  // @174_45e190
  L45e351:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @176_45e190
  if (FL[0] != FL[1]) goto L45e360;  // @177_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_45e190
  PV[12] = (u32)(esi);  // @179_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[12]);  // @180_45e190
  ecx = edx = 0;  // @181_45e190
  L45e360:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @183_45e190
  L45e363:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @185_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @186_45e190
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @187_45e190
  L45e36b:;
  eax = esi;  // @189_45e190
  SEH_LEAVE();  // @190_45e190
  return eax;  // @191_45e190
}
PCREG(45e190, lifted_45e190);

extern "C" u32 THISCALL lifted_5ee720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cbf2);  // @h_5ee720
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5ee720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5ee720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @2_5ee720
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_5ee720
  PV[0] = (u32)(ebx);  // @4_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[0]);  // @6_5ee720
  ecx = edx = 0;  // @7_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_5ee720
  eax = (u32)(EBP + 11);  // @9_5ee720
  PV[1] = (u32)(eax);  // @10_5ee720
  PV[2] = (u32)(eax);  // @11_5ee720
  PV[3] = (u32)(eax);  // @12_5ee720
  PV[4] = (u32)(eax);  // @13_5ee720
  PV[5] = (u32)(eax);  // @14_5ee720
  eax = (u32)(esi + 106);  // @15_5ee720
  ecx = ebx;  // @16_5ee720
  PV[6] = (u32)(eax);  // @17_5ee720
  eax = (u32)(esi + 77);  // @18_5ee720
  PV[7] = (u32)(eax);  // @19_5ee720
  eax = (u32)(esi + 4);  // @20_5ee720
  PV[8] = (u32)(eax);  // @21_5ee720
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, PV[8], PV[7], PV[6], PV[5], PV[4], PV[3], PV[2], PV[1]);  // @22_5ee720
  ecx = edx = 0;  // @23_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_5ee720
  ecx = (u32)(EBP - 16);  // @25_5ee720
  PV[9] = (u32)(ecx);  // @26_5ee720
  ecx = ebx;  // @27_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[9]);  // @28_5ee720
  ecx = edx = 0;  // @29_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @30_5ee720
  ecx = ebx;  // @31_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @32_5ee720
  eax = (u32)(esi + 25);  // @33_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @34_5ee720
  PV[10] = (u32)(eax);  // @35_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[10]);  // @36_5ee720
  ecx = edx = 0;  // @37_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_5ee720
  eax = (u32)(esi + 65);  // @39_5ee720
  PV[11] = (u32)(eax);  // @40_5ee720
  ecx = ebx;  // @41_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[11]);  // @42_5ee720
  ecx = edx = 0;  // @43_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @44_5ee720
  eax = (u32)(esi + 69);  // @45_5ee720
  PV[12] = (u32)(eax);  // @46_5ee720
  ecx = ebx;  // @47_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[12]);  // @48_5ee720
  ecx = edx = 0;  // @49_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_5ee720
  eax = (u32)(esi + 73);  // @51_5ee720
  PV[13] = (u32)(eax);  // @52_5ee720
  ecx = ebx;  // @53_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[13]);  // @54_5ee720
  ecx = edx = 0;  // @55_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_5ee720
  eax = (u32)(esi + 78);  // @57_5ee720
  PV[14] = (u32)(eax);  // @58_5ee720
  ecx = ebx;  // @59_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[14]);  // @60_5ee720
  ecx = edx = 0;  // @61_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_5ee720
  eax = (u32)(esi + 82);  // @63_5ee720
  PV[15] = (u32)(eax);  // @64_5ee720
  ecx = ebx;  // @65_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[15]);  // @66_5ee720
  ecx = edx = 0;  // @67_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_5ee720
  eax = (u32)(esi + 86);  // @69_5ee720
  PV[16] = (u32)(eax);  // @70_5ee720
  ecx = ebx;  // @71_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[16]);  // @72_5ee720
  ecx = edx = 0;  // @73_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_5ee720
  ecx = (u32)(EBP - 16);  // @75_5ee720
  PV[17] = (u32)(ecx);  // @76_5ee720
  ecx = ebx;  // @77_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[17]);  // @78_5ee720
  ecx = edx = 0;  // @79_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @80_5ee720
  ecx = (u32)(EBP - 16);  // @81_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @82_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @83_5ee720
  PV[18] = (u32)(ecx);  // @84_5ee720
  ecx = ebx;  // @85_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[18]);  // @86_5ee720
  ecx = edx = 0;  // @87_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @88_5ee720
  ecx = ebx;  // @89_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @90_5ee720
  eax = (u32)(esi + 98);  // @91_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @92_5ee720
  PV[19] = (u32)(eax);  // @93_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[19]);  // @94_5ee720
  ecx = edx = 0;  // @95_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_5ee720
  eax = (u32)(esi + 102);  // @97_5ee720
  PV[20] = (u32)(eax);  // @98_5ee720
  ecx = ebx;  // @99_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[20]);  // @100_5ee720
  ecx = edx = 0;  // @101_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_5ee720
  eax = (u32)(esi + 107);  // @103_5ee720
  PV[21] = (u32)(eax);  // @104_5ee720
  ecx = ebx;  // @105_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[21]);  // @106_5ee720
  ecx = edx = 0;  // @107_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @108_5ee720
  ecx = (u32)(EBP - 16);  // @109_5ee720
  PV[22] = (u32)(ecx);  // @110_5ee720
  ecx = ebx;  // @111_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[22]);  // @112_5ee720
  ecx = edx = 0;  // @113_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @114_5ee720
  ecx = (u32)(EBP - 16);  // @115_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @116_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @117_5ee720
  PV[23] = (u32)(ecx);  // @118_5ee720
  ecx = ebx;  // @119_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[23]);  // @120_5ee720
  ecx = edx = 0;  // @121_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @122_5ee720
  ecx = ebx;  // @123_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @124_5ee720
  eax = (u32)(esi + 120);  // @125_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @126_5ee720
  PV[24] = (u32)(eax);  // @127_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[24]);  // @128_5ee720
  ecx = edx = 0;  // @129_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @130_5ee720
  eax = (u32)(esi + 124);  // @131_5ee720
  PV[25] = (u32)(eax);  // @132_5ee720
  ecx = ebx;  // @133_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[25]);  // @134_5ee720
  ecx = edx = 0;  // @135_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @136_5ee720
  ecx = (u32)(esi + 128);  // @137_5ee720
  PV[26] = (u32)(ecx);  // @138_5ee720
  ecx = ebx;  // @139_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[26]);  // @140_5ee720
  ecx = edx = 0;  // @141_5ee720
  ecx = (u32)(esi + 29);  // @142_5ee720
  eax = ext_4de7a0_thiscall1(ecx);  // @143_5ee720
  ecx = edx = 0;  // @144_5ee720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @145_5ee720
  ecx = (u32)(EBP - 24);  // @146_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @147_5ee720
  PV[27] = (u32)(ecx);  // @148_5ee720
  ecx = ebx;  // @149_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[27]);  // @150_5ee720
  ecx = edx = 0;  // @151_5ee720
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @152_5ee720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @153_5ee720
  if (FL[0] <= FL[1]) goto L5ee90b;  // @154_5ee720
  L5ee883:;
  eax = ext_41e290_cdecl1((u32)(8));  // @156_5ee720
  ecx = edx = 0;  // @157_5ee720
  edi = eax;  // @158_5ee720
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @159_5ee720
  eax = ext_41e290_cdecl1((u32)(168));  // @160_5ee720
  ecx = edx = 0;  // @161_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @162_5ee720
  reg.state = (s32)((u32)(0));  // @163_5ee720
  FL[2] = (eax & eax);  // @164_5ee720
  if (FL[2] == 0) goto L5ee8be;  // @165_5ee720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @166_5ee720
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 128), sizeof v); (u32)v; });  // @167_5ee720
  ecx = eax;  // @168_5ee720
  eax = ext_5ab2e0_thiscall2(ecx, PV[28]);  // @169_5ee720
  ecx = edx = 0;  // @170_5ee720
  ecx = eax;  // @171_5ee720
  goto L5ee8c0;  // @172_5ee720
  L5ee8be:;
  ecx = 0;  // @174_5ee720
  FL[3] = ecx;  // @175_5ee720
  L5ee8c0:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @177_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_5ee720
  PV[29] = (u32)(ebx);  // @179_5ee720
  reg.state = (s32)((u32)(4294967295));  // @180_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[29]);  // @181_5ee720
  ecx = edx = 0;  // @182_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @183_5ee720
  eax = (u32)(edi + 4);  // @184_5ee720
  PV[30] = (u32)(eax);  // @185_5ee720
  ecx = ebx;  // @186_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[30]);  // @187_5ee720
  ecx = edx = 0;  // @188_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @189_5ee720
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @190_5ee720
  if (FL[0] == FL[1]) goto L5ee8ee;  // @191_5ee720
  FL[2] = (eax & eax);  // @192_5ee720
  if (FL[2] == 0) goto L5ee8e8;  // @193_5ee720
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @194_5ee720
  L5ee8e8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @196_5ee720
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @197_5ee720
  goto L5ee8fb;  // @198_5ee720
  L5ee8ee:;
  ecx = (u32)(EBP - 32);  // @200_5ee720
  PV[31] = (u32)(ecx);  // @201_5ee720
  PV[32] = (u32)(eax);  // @202_5ee720
  ecx = (u32)(esi + 5);  // @203_5ee720
  eax = ext_5fe3b0_thiscall3(ecx, PV[32], PV[31]);  // @204_5ee720
  ecx = edx = 0;  // @205_5ee720
  L5ee8fb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @207_5ee720
  eax = (eax + 1);  // @208_5ee720
  FL[3] = eax;  // @209_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @210_5ee720
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @211_5ee720
  if (FL[0] < FL[1]) goto L5ee883;  // @212_5ee720
  L5ee90b:;
  SEH_LEAVE();  // @214_5ee720
  return eax;  // @215_5ee720
}
PCREG(5ee720, lifted_5ee720);

extern "C" u32 THISCALL lifted_45f090(u32 ecx_in) {
  SEH_ENTER(0x66681b);  // @h_45f090
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_45f090
  PV[0] = (u32)(esi);  // @2_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @5_45f090
  ecx = edx = 0;  // @6_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @7_45f090
  edi = eax;  // @8_45f090
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }) & (u32)(1048576));  // @9_45f090
  if (FL[2] == 0) goto L45f28f;  // @10_45f090
  ecx = (u32)(EBP - 188);  // @11_45f090
  eax = ext_4ccba0_thiscall1(ecx);  // @12_45f090
  ecx = edx = 0;  // @13_45f090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @14_45f090
  reg.state = (s32)((u32)(0));  // @15_45f090
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @16_45f090
  FL[2] = (edx & edx);  // @17_45f090
  if (FL[2] == 0) goto L45f136;  // @18_45f090
  L45f101:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_45f090
  PV[1] = (u32)(edx);  // @21_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @22_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[1]);  // @24_45f090
  ecx = edx = 0;  // @25_45f090
  PV[2] = (u32)(eax);  // @26_45f090
  ecx = (u32)(EBP - 188);  // @27_45f090
  eax = ext_4cd540_thiscall2(ecx, PV[2]);  // @28_45f090
  ecx = edx = 0;  // @29_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_45f090
  ecx = (u32)(EBP - 192);  // @31_45f090
  PV[3] = (u32)(ecx);  // @32_45f090
  ecx = esi;  // @33_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[3]);  // @34_45f090
  ecx = edx = 0;  // @35_45f090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @36_45f090
  FL[2] = (edx & edx);  // @37_45f090
  if (FL[2] != 0) goto L45f101;  // @38_45f090
  L45f136:;
  eax = (u32)(EBP - 204);  // @40_45f090
  PV[4] = (u32)(eax);  // @41_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @42_45f090
  ecx = (u32)(EBP - 188);  // @43_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @44_45f090
  ecx = edx = 0;  // @45_45f090
  eax = (u32)(EBP - 204);  // @46_45f090
  PV[5] = (u32)(eax);  // @47_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @48_45f090
  ecx = (u32)(EBP - 188);  // @49_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @50_45f090
  ecx = edx = 0;  // @51_45f090
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @52_45f090
  esi = eax;  // @53_45f090
  if (FL[0] == FL[1]) goto L45f278;  // @54_45f090
  L45f171:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_45f090
  PV[6] = (u32)(esi);  // @57_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @58_45f090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[6]);  // @60_45f090
  ecx = edx = 0;  // @61_45f090
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @62_45f090
  FL[2] = (eax & eax);  // @63_45f090
  if (FL[2] == 0) goto L45f253;  // @64_45f090
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608));  // @65_45f090
  if (FL[2] != 0) goto L45f1a9;  // @66_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @67_45f090
  FL[2] = (ecx & ecx);  // @68_45f090
  if (FL[2] == 0) goto L45f1a9;  // @69_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @71_45f090
  ecx = edx = 0;  // @72_45f090
  L45f1a9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_45f090
  PV[7] = (u32)(esi);  // @75_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @76_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[7]);  // @78_45f090
  ecx = edx = 0;  // @79_45f090
  FL[2] = (eax & eax);  // @80_45f090
  if (FL[2] == 0) goto L45f253;  // @81_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @82_45f090
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @83_45f090
  ecx = edx = 0;  // @84_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_45f090
  PV[8] = (u32)(esi);  // @86_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @87_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[8]);  // @89_45f090
  ecx = edx = 0;  // @90_45f090
  FL[2] = (eax & eax);  // @91_45f090
  if (FL[2] == 0) goto L45f253;  // @92_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @93_45f090
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @94_45f090
  ecx = edx = 0;  // @95_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_45f090
  PV[9] = (u32)(esi);  // @97_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @98_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[9]);  // @100_45f090
  ecx = edx = 0;  // @101_45f090
  FL[2] = (eax & eax);  // @102_45f090
  if (FL[2] == 0) goto L45f253;  // @103_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @104_45f090
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(8388608));  // @105_45f090
  if (FL[2] != 0) goto L45f242;  // @106_45f090
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @107_45f090
  ecx = edx = 0;  // @108_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @109_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @110_45f090
  FL[2] = (ecx & ecx);  // @111_45f090
  if (FL[2] == 0) goto L45f242;  // @112_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @114_45f090
  ecx = edx = 0;  // @115_45f090
  L45f242:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @117_45f090
  PV[10] = (u32)(esi);  // @118_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @119_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[10]);  // @121_45f090
  ecx = edx = 0;  // @122_45f090
  L45f253:;
  eax = (u32)(EBP - 204);  // @124_45f090
  PV[11] = (u32)(eax);  // @125_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @126_45f090
  ecx = (u32)(EBP - 188);  // @127_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[11]);  // @128_45f090
  ecx = edx = 0;  // @129_45f090
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @130_45f090
  esi = eax;  // @131_45f090
  if (FL[0] != FL[1]) goto L45f171;  // @132_45f090
  L45f278:;
  ecx = (u32)(EBP - 188);  // @134_45f090
  reg.state = (s32)((u32)(4294967295));  // @135_45f090
  eax = ext_4ccf60_thiscall1(ecx);  // @136_45f090
  ecx = edx = 0;  // @137_45f090
  goto L45f331;  // @138_45f090
  L45f28f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @140_45f090
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608));  // @141_45f090
  if (FL[2] != 0) goto L45f2a5;  // @142_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @143_45f090
  ecx = esi;  // @144_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @145_45f090
  ecx = edx = 0;  // @146_45f090
  L45f2a5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @148_45f090
  PV[12] = (u32)(edi);  // @149_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @150_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[12]);  // @152_45f090
  ecx = edx = 0;  // @153_45f090
  FL[2] = (eax & eax);  // @154_45f090
  if (FL[2] != 0) goto L45f2c1;  // @155_45f090
  L45f2ba:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @157_45f090
  FL[3] = (eax & 0xff);  // @158_45f090
  goto L45f347;  // @159_45f090
  L45f2c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @161_45f090
  ecx = esi;  // @162_45f090
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @163_45f090
  ecx = edx = 0;  // @164_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @165_45f090
  PV[13] = (u32)(edi);  // @166_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @167_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @168_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[13]);  // @169_45f090
  ecx = edx = 0;  // @170_45f090
  FL[2] = (eax & eax);  // @171_45f090
  if (FL[2] == 0) goto L45f2ba;  // @172_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_45f090
  ecx = esi;  // @174_45f090
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @175_45f090
  ecx = edx = 0;  // @176_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @177_45f090
  PV[14] = (u32)(edi);  // @178_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @179_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @180_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[14]);  // @181_45f090
  ecx = edx = 0;  // @182_45f090
  FL[2] = (eax & eax);  // @183_45f090
  if (FL[2] == 0) goto L45f2ba;  // @184_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @185_45f090
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(8388608));  // @186_45f090
  if (FL[2] != 0) goto L45f331;  // @187_45f090
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @188_45f090
  ecx = edx = 0;  // @189_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @190_45f090
  ecx = esi;  // @191_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @192_45f090
  ecx = edx = 0;  // @193_45f090
  L45f331:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @195_45f090
  PV[15] = (u32)(edi);  // @196_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @197_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @198_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[15]);  // @199_45f090
  ecx = edx = 0;  // @200_45f090
  FL[2] = (eax & eax);  // @201_45f090
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @202_45f090
  L45f347:;
  SEH_LEAVE();  // @204_45f090
  ext_633654(G(u32, 0x6f5630));  // @205_45f090
  return eax;  // @206_45f090
}
PCREG(45f090, lifted_45f090);

extern "C" u32 THISCALL lifted_45cd90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x666733);  // @h_45cd90
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ecx;  // @0_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 448), &v, sizeof v); }  // @1_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_45cd90
  edi = 0;  // @3_45cd90
  FL[3] = edi;  // @4_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 480), &v, sizeof v); }  // @5_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @6_45cd90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @7_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @8_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 476), &v, sizeof v); }  // @9_45cd90
  eax = ext_4da3a0_thiscall1(ecx);  // @10_45cd90
  ecx = edx = 0;  // @11_45cd90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @12_45cd90
  if (FL[2] != 0) goto L45cdf4;  // @13_45cd90
  eax = (u32)(edi + 1);  // @14_45cd90
  goto L45d079;  // @15_45cd90
  L45cdf4:;
  ecx = (u32)(EBP - 444);  // @17_45cd90
  eax = ext_4ccba0_thiscall1(ecx);  // @18_45cd90
  ecx = edx = 0;  // @19_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @20_45cd90
  reg.state = (s32)((u32)(0));  // @21_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @22_45cd90
  FL[2] = (ecx & ecx);  // @23_45cd90
  if (FL[2] == 0) goto L45ce90;  // @24_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_45cd90
  edx = (u32)(EBP - 472);  // @26_45cd90
  PV[0] = (u32)(edx);  // @27_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @28_45cd90
  ecx = edx = 0;  // @29_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @30_45cd90
  edx = (u32)(EBP - 472);  // @31_45cd90
  PV[1] = (u32)(edx);  // @32_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @33_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @35_45cd90
  ecx = edx = 0;  // @36_45cd90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @37_45cd90
  esi = eax;  // @38_45cd90
  if (FL[0] == FL[1]) goto L45ce90;  // @39_45cd90
  L45ce40:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @41_45cd90
  PV[2] = (u32)(esi);  // @42_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[2]);  // @44_45cd90
  ecx = edx = 0;  // @45_45cd90
  FL[2] = (eax & eax);  // @46_45cd90
  if (FL[2] != 0) goto L45ce67;  // @47_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @48_45cd90
  edx = (u32)(EBP - 472);  // @49_45cd90
  PV[3] = (u32)(edx);  // @50_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @51_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[3]);  // @53_45cd90
  ecx = edx = 0;  // @54_45cd90
  goto L45ce73;  // @55_45cd90
  L45ce67:;
  PV[4] = (u32)(esi);  // @57_45cd90
  ecx = (u32)(EBP - 444);  // @58_45cd90
  eax = ext_4cd540_thiscall2(ecx, PV[4]);  // @59_45cd90
  ecx = edx = 0;  // @60_45cd90
  L45ce73:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @62_45cd90
  edx = (u32)(EBP - 472);  // @63_45cd90
  PV[5] = (u32)(edx);  // @64_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @65_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @67_45cd90
  ecx = edx = 0;  // @68_45cd90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @69_45cd90
  esi = eax;  // @70_45cd90
  if (FL[0] != FL[1]) goto L45ce40;  // @71_45cd90
  L45ce90:;
  eax = (u32)(EBP - 472);  // @73_45cd90
  PV[6] = (u32)(eax);  // @74_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @75_45cd90
  ecx = (u32)(EBP - 444);  // @76_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @77_45cd90
  ecx = edx = 0;  // @78_45cd90
  eax = (u32)(EBP - 472);  // @79_45cd90
  PV[7] = (u32)(eax);  // @80_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @81_45cd90
  ecx = (u32)(EBP - 444);  // @82_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @83_45cd90
  ecx = edx = 0;  // @84_45cd90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @85_45cd90
  edx = eax;  // @86_45cd90
  if (FL[0] == FL[1]) goto L45d052;  // @87_45cd90
  L45ced0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @89_45cd90
  PV[8] = (u32)(edx);  // @90_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[8]);  // @92_45cd90
  ecx = edx = 0;  // @93_45cd90
  esi = eax;  // @94_45cd90
  FL[2] = (esi & esi);  // @95_45cd90
  if (FL[2] == 0) goto L45d02d;  // @96_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @97_45cd90
  eax = ebx;  // @98_45cd90
  eax = (eax & (u32)(1));  // @99_45cd90
  FL[3] = eax;  // @100_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @101_45cd90
  if (FL[3] == 0) goto L45cf03;  // @102_45cd90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4));  // @103_45cd90
  if (FL[2] != 0) goto L45d027;  // @104_45cd90
  L45cf03:;
  eax = ebx;  // @106_45cd90
  eax = (eax & (u32)(2));  // @107_45cd90
  FL[3] = eax;  // @108_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @109_45cd90
  if (FL[3] == 0) goto L45cf1a;  // @110_45cd90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(8));  // @111_45cd90
  if (FL[2] != 0) goto L45d027;  // @112_45cd90
  L45cf1a:;
  FL[0] = ebx; FL[1] = (u32)(4);  // @114_45cd90
  if (FL[0] != FL[1]) goto L45cf28;  // @115_45cd90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (ebx & 0xff));  // @116_45cd90
  if (FL[2] == 0) goto L45d027;  // @117_45cd90
  L45cf28:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @119_45cd90
  eax = (eax & (u32)(4));  // @120_45cd90
  FL[3] = eax;  // @121_45cd90
  if (FL[3] != 0) goto L45d097;  // @122_45cd90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(1));  // @123_45cd90
  if (FL[2] == 0) goto L45d097;  // @124_45cd90
  FL[0] = ebx; FL[1] = (u32)(1);  // @125_45cd90
  if (FL[0] == FL[1]) goto L45d097;  // @126_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 476), sizeof v); (u32)v; });  // @127_45cd90
  FL[2] = (ecx & ecx);  // @128_45cd90
  if (FL[2] == 0) goto L45cf7e;  // @129_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_45cd90
  edx = (u32)(EBP - 144);  // @131_45cd90
  PV[9] = (u32)(edx);  // @132_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[9], (u32)(1));  // @133_45cd90
  ecx = edx = 0;  // @134_45cd90
  edi = (edi | (u32)(1));  // @135_45cd90
  FL[3] = edi;  // @136_45cd90
  reg.state = (s32)((u32)(1));  // @137_45cd90
  ecx = eax;  // @138_45cd90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @139_45cd90
  eax = ext_4cc1d0_thiscall1(ecx);  // @140_45cd90
  ecx = edx = 0;  // @141_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @142_45cd90
  goto L45cf88;  // @143_45cd90
  L45cf7e:;
  { u32 v = (u32)((u32)(6836600)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @145_45cd90
  L45cf88:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @147_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1620));  // @149_45cd90
  ecx = edx = 0;  // @150_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @151_45cd90
  ebx = eax;  // @152_45cd90
  eax = (u32)(EBP - 272);  // @153_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @154_45cd90
  PV[10] = (u32)(eax);  // @155_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @156_45cd90
  ecx = edi;  // @157_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[10], (u32)(1));  // @158_45cd90
  ecx = edx = 0;  // @159_45cd90
  edi = eax;  // @160_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @161_45cd90
  ecx = esi;  // @162_45cd90
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; });  // @163_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @164_45cd90
  reg.state = (s32)((u32)(2));  // @165_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[11]);  // @166_45cd90
  ecx = edx = 0;  // @167_45cd90
  PV[12] = (u32)(eax);  // @168_45cd90
  ecx = edi;  // @169_45cd90
  eax = ext_4cc1d0_thiscall1(ecx);  // @170_45cd90
  ecx = edx = 0;  // @171_45cd90
  PV[13] = (u32)(eax);  // @172_45cd90
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; });  // @173_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ebx + 44)))(ecx, PV[14], (u32)(6836608), PV[13], PV[12]);  // @174_45cd90
  ecx = edx = 0;  // @175_45cd90
  ecx = (u32)(EBP - 272);  // @176_45cd90
  eax = ext_4cbec0_thiscall1(ecx);  // @177_45cd90
  ecx = edx = 0;  // @178_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @179_45cd90
  reg.state = (s32)((u32)(0));  // @180_45cd90
  FL[2] = ((ebx & 0xff) & (u32)(1));  // @181_45cd90
  if (FL[2] == 0) goto L45d021;  // @182_45cd90
  ebx = (ebx & (u32)(4294967294));  // @183_45cd90
  FL[3] = ebx;  // @184_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @185_45cd90
  L45d016:;
  ecx = (u32)(EBP - 144);  // @187_45cd90
  eax = ext_4cbec0_thiscall1(ecx);  // @188_45cd90
  ecx = edx = 0;  // @189_45cd90
  L45d021:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @191_45cd90
  L45d027:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @193_45cd90
  L45d02d:;
  eax = (u32)(EBP - 472);  // @195_45cd90
  PV[15] = (u32)(eax);  // @196_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @197_45cd90
  ecx = (u32)(EBP - 444);  // @198_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @199_45cd90
  ecx = edx = 0;  // @200_45cd90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @201_45cd90
  edx = eax;  // @202_45cd90
  if (FL[0] != FL[1]) goto L45ced0;  // @203_45cd90
  L45d052:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @205_45cd90
  if (FL[0] != FL[1]) goto L45d067;  // @206_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @207_45cd90
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @208_45cd90
  ecx = edx = 0;  // @209_45cd90
  L45d067:;
  esi = (u32)(1);  // @211_45cd90
  L45d06c:;
  ecx = (u32)(EBP - 444);  // @213_45cd90
  eax = ext_4ccf60_thiscall1(ecx);  // @214_45cd90
  ecx = edx = 0;  // @215_45cd90
  eax = esi;  // @216_45cd90
  L45d079:;
  SEH_LEAVE();  // @218_45cd90
  ext_633654(G(u32, 0x6f5630));  // @219_45cd90
  return eax;  // @220_45cd90
  L45d097:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @222_45cd90
  if (FL[0] != FL[1]) goto L45d027;  // @223_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @224_45cd90
  FL[2] = (ebx & ecx);  // @225_45cd90
  if (FL[2] != 0) goto L45d0b2;  // @226_45cd90
  FL[0] = ebx; FL[1] = (u32)(4);  // @227_45cd90
  if (FL[0] == FL[1]) goto L45d0b2;  // @228_45cd90
  FL[0] = ebx; FL[1] = (u32)(32);  // @229_45cd90
  if (FL[0] != FL[1]) goto L45d027;  // @230_45cd90
  L45d0b2:;
  FL[2] = (eax & eax);  // @232_45cd90
  if (FL[2] != 0) goto L45d11b;  // @233_45cd90
  FL[2] = ((ecx & 0xff) & (u32)(1));  // @234_45cd90
  if (FL[2] == 0) goto L45d11b;  // @235_45cd90
  FL[0] = ebx; FL[1] = (u32)(1);  // @236_45cd90
  if (FL[0] == FL[1]) goto L45d11b;  // @237_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @238_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @239_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1634));  // @240_45cd90
  ecx = edx = 0;  // @241_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @242_45cd90
  ebx = eax;  // @243_45cd90
  eax = (u32)(EBP - 144);  // @244_45cd90
  ecx = edi;  // @245_45cd90
  PV[16] = (u32)(eax);  // @246_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @247_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[16], (u32)(1));  // @248_45cd90
  ecx = edx = 0;  // @249_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @250_45cd90
  ecx = eax;  // @251_45cd90
  reg.state = (s32)((u32)(3));  // @252_45cd90
  eax = ext_4cc1d0_thiscall1(ecx);  // @253_45cd90
  ecx = edx = 0;  // @254_45cd90
  PV[17] = (u32)(eax);  // @255_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @256_45cd90
  ecx = esi;  // @257_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[17]);  // @258_45cd90
  ecx = edx = 0;  // @259_45cd90
  PV[18] = (u32)(eax);  // @260_45cd90
  PV[19] = (u32)(ebx);  // @261_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, PV[19], (u32)(6836680), PV[18]);  // @262_45cd90
  ecx = edx = 0;  // @263_45cd90
  reg.state = (s32)((u32)(0));  // @264_45cd90
  goto L45d016;  // @265_45cd90
  L45d11b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @267_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @268_45cd90
  PV[20] = (u32)(edi);  // @269_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @270_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @271_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[20]);  // @272_45cd90
  ecx = edx = 0;  // @273_45cd90
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 480), sizeof v); (u32)v; });  // @274_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @275_45cd90
  ecx = esi;  // @276_45cd90
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @277_45cd90
  edi = eax;  // @278_45cd90
  PV[23] = (u32)(ebx);  // @279_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[23], PV[22], PV[21]);  // @280_45cd90
  ecx = edx = 0;  // @281_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @282_45cd90
  PV[24] = (u32)(edi);  // @283_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @284_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @285_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[24]);  // @286_45cd90
  ecx = edx = 0;  // @287_45cd90
  FL[2] = (eax & eax);  // @288_45cd90
  if (FL[2] == 0) goto L45d194;  // @289_45cd90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @290_45cd90
  if (FL[0] == FL[1]) goto L45d168;  // @291_45cd90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @292_45cd90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @293_45cd90
  L45d168:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @295_45cd90
  if (FL[0] == FL[1]) goto L45d175;  // @296_45cd90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @297_45cd90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @298_45cd90
  L45d175:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1));  // @300_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @301_45cd90
  if (FL[2] == 0) goto L45d189;  // @302_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @303_45cd90
  ecx = esi;  // @304_45cd90
  PV[25] = (u32)(ebx);  // @305_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[25]);  // @306_45cd90
  ecx = edx = 0;  // @307_45cd90
  L45d189:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @309_45cd90
  goto L45d02d;  // @310_45cd90
  L45d194:;
  esi = 0;  // @312_45cd90
  FL[3] = esi;  // @313_45cd90
  goto L45d06c;  // @314_45cd90
}
PCREG(45cd90, lifted_45cd90);

extern "C" u32 THISCALL lifted_52ac10(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66a630);  // @h_52ac10
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @1_52ac10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(65280));  // @4_52ac10
  ecx = edx = 0;  // @5_52ac10
  PV[0] = (u32)(edi);  // @6_52ac10
  ecx = esi;  // @7_52ac10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 376), &v, sizeof v); }  // @8_52ac10
  eax = ext_610100_stdcall1(PV[0]);  // @9_52ac10
  ecx = edx = 0;  // @10_52ac10
  eax = (u32)(EBP - 364);  // @11_52ac10
  ecx = edi;  // @12_52ac10
  PV[1] = (u32)(eax);  // @13_52ac10
  eax = ext_4e0f60_thiscall2(ecx, PV[1]);  // @14_52ac10
  ecx = edx = 0;  // @15_52ac10
  FL[2] = (eax & eax);  // @16_52ac10
  if ((s32)FL[2] <= 0) goto L52ac84;  // @17_52ac10
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; });  // @18_52ac10
  ecx = esi;  // @19_52ac10
  eax = ext_52cb60_thiscall3(ecx, PV[2], (u32)(1));  // @20_52ac10
  ecx = edx = 0;  // @21_52ac10
  goto L52acb5;  // @22_52ac10
  L52ac84:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @24_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_52ac10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9643));  // @26_52ac10
  ecx = edx = 0;  // @27_52ac10
  PV[3] = (u32)(eax);  // @28_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @29_52ac10
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6951444));  // @30_52ac10
  ecx = edx = 0;  // @31_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @32_52ac10
  FL[2] = (eax & eax);  // @33_52ac10
  if (FL[2] == 0) goto L52acb4;  // @34_52ac10
  eax = ((u32(STDCALL *)(void))(eax))();  // @35_52ac10
  ecx = edx = 0;  // @36_52ac10
  goto L52acb5;  // @37_52ac10
  L52acb4:;
  __builtin_trap();  // @39_52ac10
  L52acb5:;
  eax = ext_41e290_cdecl1((u32)(172));  // @41_52ac10
  ecx = edx = 0;  // @42_52ac10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @43_52ac10
  reg.state = (s32)((u32)(0));  // @44_52ac10
  FL[2] = (eax & eax);  // @45_52ac10
  if (FL[2] == 0) goto L52acdc;  // @46_52ac10
  ecx = eax;  // @47_52ac10
  eax = ext_4ccba0_thiscall1(ecx);  // @48_52ac10
  ecx = edx = 0;  // @49_52ac10
  goto L52acde;  // @50_52ac10
  L52acdc:;
  eax = 0;  // @52_52ac10
  FL[3] = eax;  // @53_52ac10
  L52acde:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @55_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_52ac10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @57_52ac10
  reg.state = (s32)((u32)(4294967295));  // @58_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @59_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @60_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @61_52ac10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @62_52ac10
  FL[2] = (eax & eax);  // @63_52ac10
  if (FL[2] == 0) goto L52ad78;  // @64_52ac10
  L52ad10:;
  ecx = eax;  // @66_52ac10
  eax = ext_4dc110_thiscall1(ecx);  // @67_52ac10
  ecx = edx = 0;  // @68_52ac10
  edx = (u32)(6951492);  // @69_52ac10
  ecx = eax;  // @70_52ac10
  eax = ext_4cc850_fastcall2(ecx, edx);  // @71_52ac10
  ecx = edx = 0;  // @72_52ac10
  FL[2] = (eax & eax);  // @73_52ac10
  if (FL[2] != 0) goto L52ad51;  // @74_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 368), sizeof v); (u32)v; });  // @75_52ac10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @76_52ac10
  FL[2] = (edx & edx);  // @77_52ac10
  if (FL[2] == 0) goto L52ad51;  // @78_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @79_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @80_52ac10
  FL[0] = eax; FL[1] = (u32)(2097154);  // @81_52ac10
  if (FL[0] == FL[1]) goto L52ad48;  // @82_52ac10
  FL[0] = eax; FL[1] = (u32)(1048577);  // @83_52ac10
  if (FL[0] != FL[1]) goto L52ad51;  // @84_52ac10
  L52ad48:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; });  // @86_52ac10
  PV[4] = (u32)(edx);  // @87_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[4]);  // @89_52ac10
  ecx = edx = 0;  // @90_52ac10
  L52ad51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_52ac10
  edx = (u32)(EBP - 368);  // @93_52ac10
  PV[5] = (u32)(edx);  // @94_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @95_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @96_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[5]);  // @98_52ac10
  ecx = edx = 0;  // @99_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 368), sizeof v); (u32)v; });  // @100_52ac10
  FL[2] = (eax & eax);  // @101_52ac10
  if (FL[2] != 0) goto L52ad10;  // @102_52ac10
  L52ad78:;
  ecx = edi;  // @104_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @105_52ac10
  ecx = edx = 0;  // @106_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(9);  // @107_52ac10
  if (FL[0] != FL[1]) goto L52ae30;  // @108_52ac10
  ecx = (u32)(EBP - 188);  // @109_52ac10
  eax = ext_4ccba0_thiscall1(ecx);  // @110_52ac10
  ecx = edx = 0;  // @111_52ac10
  eax = (u32)(EBP - 188);  // @112_52ac10
  reg.state = (s32)((u32)(1));  // @113_52ac10
  PV[6] = (u32)(eax);  // @114_52ac10
  ecx = edi;  // @115_52ac10
  eax = ext_4e0fd0_thiscall2(ecx, PV[6]);  // @116_52ac10
  ecx = edx = 0;  // @117_52ac10
  eax = (u32)(EBP - 388);  // @118_52ac10
  PV[7] = (u32)(eax);  // @119_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @120_52ac10
  ecx = (u32)(EBP - 188);  // @121_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @122_52ac10
  ecx = edx = 0;  // @123_52ac10
  eax = (u32)(EBP - 388);  // @124_52ac10
  PV[8] = (u32)(eax);  // @125_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @126_52ac10
  ecx = (u32)(EBP - 188);  // @127_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @128_52ac10
  ecx = edx = 0;  // @129_52ac10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 388), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @130_52ac10
  if (FL[0] == FL[1]) goto L52ae1e;  // @131_52ac10
  L52ade0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @133_52ac10
  PV[9] = (u32)(eax);  // @134_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @135_52ac10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[9]);  // @137_52ac10
  ecx = edx = 0;  // @138_52ac10
  FL[2] = (eax & eax);  // @139_52ac10
  if (FL[2] == 0) goto L52adff;  // @140_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; });  // @141_52ac10
  PV[10] = (u32)(eax);  // @142_52ac10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[10]);  // @144_52ac10
  ecx = edx = 0;  // @145_52ac10
  L52adff:;
  eax = (u32)(EBP - 388);  // @147_52ac10
  PV[11] = (u32)(eax);  // @148_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @149_52ac10
  ecx = (u32)(EBP - 188);  // @150_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[11]);  // @151_52ac10
  ecx = edx = 0;  // @152_52ac10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 388), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @153_52ac10
  if (FL[0] != FL[1]) goto L52ade0;  // @154_52ac10
  L52ae1e:;
  ecx = (u32)(EBP - 188);  // @156_52ac10
  reg.state = (s32)((u32)(4294967295));  // @157_52ac10
  eax = ext_4ccf60_thiscall1(ecx);  // @158_52ac10
  ecx = edx = 0;  // @159_52ac10
  L52ae30:;
  ecx = edi;  // @161_52ac10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 70), &v, sizeof v); }  // @162_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @163_52ac10
  ecx = edx = 0;  // @164_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @165_52ac10
  if (FL[0] != FL[1]) goto L52ae5c;  // @166_52ac10
  eax = (u32)(EBP - 364);  // @167_52ac10
  ecx = edi;  // @168_52ac10
  PV[12] = (u32)(eax);  // @169_52ac10
  eax = ext_4e11e0_thiscall3(ecx, PV[12], (u32)(1));  // @170_52ac10
  ecx = edx = 0;  // @171_52ac10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @172_52ac10
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @173_52ac10
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 70), &v, sizeof v); }  // @174_52ac10
  L52ae5c:;
  ebx = (u32)(esi + 37);  // @176_52ac10
  ecx = edi;  // @177_52ac10
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @178_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @179_52ac10
  ecx = edx = 0;  // @180_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @181_52ac10
  if (FL[0] != FL[1]) goto L52ae90;  // @182_52ac10
  PV[13] = (u32)(ebx);  // @183_52ac10
  ecx = edi;  // @184_52ac10
  eax = ext_4e11e0_thiscall3(ecx, PV[13], (u32)(1));  // @185_52ac10
  ecx = edx = 0;  // @186_52ac10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @187_52ac10
  if ((s32)FL[0] >= (s32)FL[1]) goto L52ae85;  // @188_52ac10
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @189_52ac10
  L52ae85:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @191_52ac10
  if ((s32)FL[0] <= (s32)FL[1]) goto L52ae90;  // @192_52ac10
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @193_52ac10
  L52ae90:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 49), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @195_52ac10
  if (FL[0] != FL[1]) goto L52ae9d;  // @196_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @197_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @198_52ac10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @199_52ac10
  L52ae9d:;
  ebx = (u32)(esi + 32);  // @201_52ac10
  ecx = edi;  // @202_52ac10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @203_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @204_52ac10
  ecx = edx = 0;  // @205_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @206_52ac10
  if (FL[0] != FL[1]) goto L52aebb;  // @207_52ac10
  PV[14] = (u32)(ebx);  // @208_52ac10
  ecx = edi;  // @209_52ac10
  eax = ext_4e12f0_thiscall3(ecx, PV[14], (u32)(1));  // @210_52ac10
  ecx = edx = 0;  // @211_52ac10
  L52aebb:;
  ecx = edi;  // @213_52ac10
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(7245756), &v, sizeof v); }  // @214_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @215_52ac10
  ecx = edx = 0;  // @216_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @217_52ac10
  if (FL[0] != FL[1]) goto L52aeee;  // @218_52ac10
  eax = (u32)(EBP - 364);  // @219_52ac10
  ecx = edi;  // @220_52ac10
  PV[15] = (u32)(eax);  // @221_52ac10
  eax = ext_4e11e0_thiscall3(ecx, PV[15], (u32)(1));  // @222_52ac10
  ecx = edx = 0;  // @223_52ac10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @224_52ac10
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @225_52ac10
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(7245756), &v, sizeof v); }  // @226_52ac10
  goto L52aef3;  // @227_52ac10
  L52aeee:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7245756), sizeof v); (u32)v; })) & 0xff);  // @229_52ac10
  L52aef3:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @231_52ac10
  if (FL[2] == 0) goto L52af1a;  // @232_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @233_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @234_52ac10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9729));  // @235_52ac10
  ecx = edx = 0;  // @236_52ac10
  PV[16] = (u32)(eax);  // @237_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @238_52ac10
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[16], (u32)(6951500));  // @239_52ac10
  ecx = edx = 0;  // @240_52ac10
  L52af1a:;
  ecx = edi;  // @242_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @243_52ac10
  ecx = edx = 0;  // @244_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(9);  // @245_52ac10
  if (FL[0] != FL[1]) goto L52af97;  // @246_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 50), sizeof v); (u32)v; });  // @247_52ac10
  FL[2] = (ecx & ecx);  // @248_52ac10
  if (FL[2] == 0) goto L52af32;  // @249_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @250_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @251_52ac10
  ecx = edx = 0;  // @252_52ac10
  L52af32:;
  eax = ext_41e290_cdecl1((u32)(172));  // @254_52ac10
  ecx = edx = 0;  // @255_52ac10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @256_52ac10
  reg.state = (s32)((u32)(2));  // @257_52ac10
  FL[2] = (eax & eax);  // @258_52ac10
  if (FL[2] == 0) goto L52af59;  // @259_52ac10
  ecx = eax;  // @260_52ac10
  eax = ext_4ccba0_thiscall1(ecx);  // @261_52ac10
  ecx = edx = 0;  // @262_52ac10
  goto L52af5b;  // @263_52ac10
  L52af59:;
  eax = 0;  // @265_52ac10
  FL[3] = eax;  // @266_52ac10
  L52af5b:;
  ecx = (u32)(EBP - 360);  // @268_52ac10
  reg.state = (s32)((u32)(4294967295));  // @269_52ac10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 50), &v, sizeof v); }  // @270_52ac10
  eax = ext_4ccba0_thiscall1(ecx);  // @271_52ac10
  ecx = edx = 0;  // @272_52ac10
  eax = (u32)(EBP - 360);  // @273_52ac10
  reg.state = (s32)((u32)(3));  // @274_52ac10
  PV[17] = (u32)(eax);  // @275_52ac10
  ecx = edi;  // @276_52ac10
  eax = ext_4e0fd0_thiscall2(ecx, PV[17]);  // @277_52ac10
  ecx = edx = 0;  // @278_52ac10
  ecx = (u32)(EBP - 360);  // @279_52ac10
  reg.state = (s32)((u32)(4294967295));  // @280_52ac10
  eax = ext_4ccf60_thiscall1(ecx);  // @281_52ac10
  ecx = edx = 0;  // @282_52ac10
  L52af97:;
  ecx = edi;  // @284_52ac10
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @285_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @286_52ac10
  ecx = edx = 0;  // @287_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @288_52ac10
  if (FL[0] != FL[1]) goto L52afc3;  // @289_52ac10
  eax = (u32)(EBP - 372);  // @290_52ac10
  ecx = edi;  // @291_52ac10
  PV[18] = (u32)(eax);  // @292_52ac10
  eax = ext_4e11e0_thiscall3(ecx, PV[18], (u32)(1));  // @293_52ac10
  ecx = edx = 0;  // @294_52ac10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @295_52ac10
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @296_52ac10
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @297_52ac10
  L52afc3:;
  ecx = edi;  // @299_52ac10
  eax = ext_4e1600_thiscall1(ecx);  // @300_52ac10
  ecx = edx = 0;  // @301_52ac10
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @302_52ac10
  if (FL[0] != FL[1]) goto L52afdb;  // @303_52ac10
  eax = (u32)(esi + 105);  // @304_52ac10
  ecx = edi;  // @305_52ac10
  PV[19] = (u32)(eax);  // @306_52ac10
  eax = ext_4e12e0_thiscall3(ecx, PV[19], (u32)(1));  // @307_52ac10
  ecx = edx = 0;  // @308_52ac10
  L52afdb:;
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 105), sizeof v); (u32)v; });  // @310_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 101), sizeof v); (u32)v; });  // @311_52ac10
  eax = ext_530fd0_thiscall2(ecx, PV[20]);  // @312_52ac10
  ecx = edx = 0;  // @313_52ac10
  ecx = edi;  // @314_52ac10
  eax = ext_4e1b30_thiscall1(ecx);  // @315_52ac10
  ecx = edx = 0;  // @316_52ac10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @317_52ac10
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 376), sizeof v); (u32)v; });  // @318_52ac10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @319_52ac10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[21]);  // @320_52ac10
  ecx = edx = 0;  // @321_52ac10
  SEH_LEAVE();  // @322_52ac10
  ext_633654(G(u32, 0x6f5630));  // @323_52ac10
  return eax;  // @324_52ac10
}
PCREG(52ac10, lifted_52ac10);

extern "C" u32 THISCALL lifted_463620(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6669ef);  // @h_463620
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_463620
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_463620
  PV[0] = (u32)(esi);  // @2_463620
  eax = ext_45f3c0_thiscall2(ecx, PV[0]);  // @3_463620
  ecx = edx = 0;  // @4_463620
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @5_463620
  if (FL[2] != 0) goto L46366b;  // @6_463620
  SEH_LEAVE();  // @7_463620
  return eax;  // @8_463620
  L46366b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_463620
  ecx = ebx;  // @11_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 532)))(ecx);  // @12_463620
  ecx = edx = 0;  // @13_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_463620
  eax = (u32)(ebx + 112);  // @15_463620
  PV[1] = (u32)(eax);  // @16_463620
  ecx = esi;  // @17_463620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[1], (u32)(1));  // @18_463620
  ecx = edx = 0;  // @19_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_463620
  eax = (u32)(ebx + 113);  // @21_463620
  PV[2] = (u32)(eax);  // @22_463620
  ecx = esi;  // @23_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[2]);  // @24_463620
  ecx = edx = 0;  // @25_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_463620
  ecx = esi;  // @27_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @28_463620
  ecx = edx = 0;  // @29_463620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @30_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @31_463620
  PV[3] = (u32)(esi);  // @32_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[3]);  // @34_463620
  ecx = edx = 0;  // @35_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @36_463620
  ecx = 0;  // @37_463620
  FL[3] = ecx;  // @38_463620
  edx = (u32)(24);  // @39_463620
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @40_463620
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @41_463620
  ecx = (0u - ecx);  // @42_463620
  ecx = (ecx | eax);  // @43_463620
  FL[3] = ecx;  // @44_463620
  PV[4] = (u32)(ecx);  // @45_463620
  eax = ext_41e290_cdecl1(PV[4]);  // @46_463620
  ecx = edx = 0;  // @47_463620
  edi = eax;  // @48_463620
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @49_463620
  eax = (u32)(EBP + 8);  // @50_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_463620
  ecx = esi;  // @52_463620
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @53_463620
  PV[5] = (u32)(eax);  // @54_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[5]);  // @55_463620
  ecx = edx = 0;  // @56_463620
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @57_463620
  if (FL[0] == FL[1]) goto L46373a;  // @58_463620
  eax = ext_41e290_cdecl1((u32)(40));  // @59_463620
  ecx = edx = 0;  // @60_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @61_463620
  reg.state = (s32)((u32)(0));  // @62_463620
  FL[2] = (eax & eax);  // @63_463620
  if (FL[2] == 0) goto L4636f9;  // @64_463620
  ecx = eax;  // @65_463620
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(30));  // @66_463620
  ecx = edx = 0;  // @67_463620
  goto L4636fb;  // @68_463620
  L4636f9:;
  eax = 0;  // @70_463620
  FL[3] = eax;  // @71_463620
  L4636fb:;
  edi = 0;  // @73_463620
  FL[3] = edi;  // @74_463620
  reg.state = (s32)((u32)(4294967295));  // @75_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @76_463620
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = edi;  // @77_463620
  if (FL[0] == FL[1]) goto L463737;  // @78_463620
  L463710:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_463620
  ecx = (u32)(EBP - 20);  // @81_463620
  PV[6] = (u32)(ecx);  // @82_463620
  ecx = esi;  // @83_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[6]);  // @84_463620
  ecx = edx = 0;  // @85_463620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @86_463620
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @87_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7]);  // @89_463620
  ecx = edx = 0;  // @90_463620
  PV[8] = (u32)(esi);  // @91_463620
  ecx = eax;  // @92_463620
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax + 116), &v, sizeof v); }  // @93_463620
  eax = ext_4634f0_thiscall2(ecx, PV[8]);  // @94_463620
  ecx = edx = 0;  // @95_463620
  edi = (edi + 1);  // @96_463620
  FL[3] = edi;  // @97_463620
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @98_463620
  if (FL[0] != FL[1]) goto L463710;  // @99_463620
  L463737:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @101_463620
  L46373a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @103_463620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @104_463620
  if (FL[0] == FL[1]) goto L4637a9;  // @105_463620
  edi = (edi + (u32)(20));  // @106_463620
  FL[3] = edi;  // @107_463620
  L463750:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @109_463620
  eax = (u32)(edi - 20);  // @110_463620
  PV[9] = (u32)(eax);  // @111_463620
  ecx = esi;  // @112_463620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[9], (u32)(16));  // @113_463620
  ecx = edx = 0;  // @114_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_463620
  ecx = esi;  // @116_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @117_463620
  ecx = edx = 0;  // @118_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @119_463620
  ecx = esi;  // @120_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @122_463620
  ecx = edx = 0;  // @123_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 8), &v, sizeof v); }  // @124_463620
  ecx = (u32)(EBP - 24);  // @125_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_463620
  PV[10] = (u32)(ecx);  // @127_463620
  ecx = esi;  // @128_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[10]);  // @129_463620
  ecx = edx = 0;  // @130_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @131_463620
  FL[2] = (eax & eax);  // @132_463620
  if (FL[2] == 0) goto L463794;  // @133_463620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @134_463620
  eax = (eax - 1);  // @135_463620
  FL[3] = eax;  // @136_463620
  PV[11] = (u32)(eax);  // @137_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, PV[11]);  // @139_463620
  ecx = edx = 0;  // @140_463620
  eax = (eax + (u32)(4));  // @141_463620
  FL[3] = eax;  // @142_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @143_463620
  goto L46379a;  // @144_463620
  L463794:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @146_463620
  L46379a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @148_463620
  edi = (edi + (u32)(24));  // @149_463620
  FL[3] = edi;  // @150_463620
  eax = (eax + 1);  // @151_463620
  FL[3] = eax;  // @152_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @153_463620
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @154_463620
  if (FL[0] != FL[1]) goto L463750;  // @155_463620
  L4637a9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @157_463620
  eax = (u32)(ebx + 130);  // @158_463620
  PV[12] = (u32)(eax);  // @159_463620
  ecx = esi;  // @160_463620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[12], (u32)(48));  // @161_463620
  ecx = edx = 0;  // @162_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @163_463620
  eax = (u32)(ebx + 278);  // @164_463620
  PV[13] = (u32)(eax);  // @165_463620
  ecx = esi;  // @166_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[13]);  // @167_463620
  ecx = edx = 0;  // @168_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @169_463620
  ecx = ebx;  // @170_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 608)))(ecx);  // @171_463620
  ecx = edx = 0;  // @172_463620
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @173_463620
  SEH_LEAVE();  // @174_463620
  return eax;  // @175_463620
}
PCREG(463620, lifted_463620);

extern "C" u32 THISCALL lifted_44f9c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6662b1);  // @h_44f9c0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_44f9c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_44f9c0
  PV[0] = (u32)(ebx);  // @2_44f9c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @3_44f9c0
  eax = ext_610100_stdcall1(PV[0]);  // @4_44f9c0
  ecx = edx = 0;  // @5_44f9c0
  ecx = (u32)(EBP - 532);  // @6_44f9c0
  eax = ext_4ccba0_thiscall1(ecx);  // @7_44f9c0
  ecx = edx = 0;  // @8_44f9c0
  ecx = (u32)(EBP - 360);  // @9_44f9c0
  reg.state = (s32)((u32)(0));  // @10_44f9c0
  eax = ext_4ccba0_thiscall1(ecx);  // @11_44f9c0
  ecx = edx = 0;  // @12_44f9c0
  ecx = (u32)(EBP - 188);  // @13_44f9c0
  reg.state = (s32)((u32)(1));  // @14_44f9c0
  eax = ext_4ccba0_thiscall1(ecx);  // @15_44f9c0
  ecx = edx = 0;  // @16_44f9c0
  esi = (u32)(edi + 28);  // @17_44f9c0
  reg.state = (s32)((u32)(2));  // @18_44f9c0
  PV[1] = (u32)(esi);  // @19_44f9c0
  ecx = ebx;  // @20_44f9c0
  eax = ext_4e12e0_thiscall3(ecx, PV[1], (u32)(1));  // @21_44f9c0
  ecx = edx = 0;  // @22_44f9c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @23_44f9c0
  if (FL[0] >= FL[1]) goto L44fa47;  // @24_44f9c0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @25_44f9c0
  L44fa47:;
  eax = (u32)(edi + 24);  // @27_44f9c0
  ecx = ebx;  // @28_44f9c0
  PV[2] = (u32)(eax);  // @29_44f9c0
  eax = ext_4e12e0_thiscall3(ecx, PV[2], (u32)(1));  // @30_44f9c0
  ecx = edx = 0;  // @31_44f9c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @32_44f9c0
  if (FL[0] >= FL[1]) goto L44fa61;  // @33_44f9c0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @34_44f9c0
  L44fa61:;
  eax = (u32)(edi + 36);  // @36_44f9c0
  ecx = ebx;  // @37_44f9c0
  PV[3] = (u32)(eax);  // @38_44f9c0
  eax = ext_4e11e0_thiscall3(ecx, PV[3], (u32)(1));  // @39_44f9c0
  ecx = edx = 0;  // @40_44f9c0
  eax = (u32)(edi + 40);  // @41_44f9c0
  ecx = ebx;  // @42_44f9c0
  PV[4] = (u32)(eax);  // @43_44f9c0
  eax = ext_4e12f0_thiscall3(ecx, PV[4], (u32)(1));  // @44_44f9c0
  ecx = edx = 0;  // @45_44f9c0
  eax = (u32)(edi + 44);  // @46_44f9c0
  ecx = ebx;  // @47_44f9c0
  PV[5] = (u32)(eax);  // @48_44f9c0
  eax = ext_4e12f0_thiscall3(ecx, PV[5], (u32)(1));  // @49_44f9c0
  ecx = edx = 0;  // @50_44f9c0
  eax = (u32)(edi + 48);  // @51_44f9c0
  ecx = ebx;  // @52_44f9c0
  PV[6] = (u32)(eax);  // @53_44f9c0
  eax = ext_4e12f0_thiscall3(ecx, PV[6], (u32)(1));  // @54_44f9c0
  ecx = edx = 0;  // @55_44f9c0
  eax = (u32)(edi + 32);  // @56_44f9c0
  ecx = ebx;  // @57_44f9c0
  PV[7] = (u32)(eax);  // @58_44f9c0
  eax = ext_4e11e0_thiscall3(ecx, PV[7], (u32)(1));  // @59_44f9c0
  ecx = edx = 0;  // @60_44f9c0
  eax = (u32)(EBP - 532);  // @61_44f9c0
  ecx = ebx;  // @62_44f9c0
  PV[8] = (u32)(eax);  // @63_44f9c0
  eax = ext_4e0fd0_thiscall2(ecx, PV[8]);  // @64_44f9c0
  ecx = edx = 0;  // @65_44f9c0
  eax = (u32)(EBP - 360);  // @66_44f9c0
  ecx = ebx;  // @67_44f9c0
  PV[9] = (u32)(eax);  // @68_44f9c0
  eax = ext_4e0fd0_thiscall2(ecx, PV[9]);  // @69_44f9c0
  ecx = edx = 0;  // @70_44f9c0
  eax = (u32)(EBP - 540);  // @71_44f9c0
  ecx = ebx;  // @72_44f9c0
  PV[10] = (u32)(eax);  // @73_44f9c0
  eax = ext_4e12e0_thiscall3(ecx, PV[10], (u32)(1));  // @74_44f9c0
  ecx = edx = 0;  // @75_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_44f9c0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @77_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @78_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_44f9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[11]);  // @80_44f9c0
  ecx = edx = 0;  // @81_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 144), &v, sizeof v); }  // @82_44f9c0
  ecx = ebx;  // @83_44f9c0
  eax = (u32)(EBP - 188);  // @84_44f9c0
  PV[12] = (u32)(eax);  // @85_44f9c0
  eax = ext_4e0fd0_thiscall2(ecx, PV[12]);  // @86_44f9c0
  ecx = edx = 0;  // @87_44f9c0
  eax = (u32)(edi + 52);  // @88_44f9c0
  ecx = ebx;  // @89_44f9c0
  PV[13] = (u32)(eax);  // @90_44f9c0
  eax = ext_4e12f0_thiscall3(ecx, PV[13], (u32)(1));  // @91_44f9c0
  ecx = edx = 0;  // @92_44f9c0
  ecx = ebx;  // @93_44f9c0
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @94_44f9c0
  eax = ext_4e1600_thiscall1(ecx);  // @95_44f9c0
  ecx = edx = 0;  // @96_44f9c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @97_44f9c0
  if (FL[0] != FL[1]) goto L44fb24;  // @98_44f9c0
  eax = (u32)(edi + 56);  // @99_44f9c0
  ecx = ebx;  // @100_44f9c0
  PV[14] = (u32)(eax);  // @101_44f9c0
  eax = ext_4e12f0_thiscall3(ecx, PV[14], (u32)(1));  // @102_44f9c0
  ecx = edx = 0;  // @103_44f9c0
  L44fb24:;
  ecx = ebx;  // @105_44f9c0
  { u32 v = (u32)((u32)(1008981770)); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @106_44f9c0
  eax = ext_4e1600_thiscall1(ecx);  // @107_44f9c0
  ecx = edx = 0;  // @108_44f9c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @109_44f9c0
  if (FL[0] != FL[1]) goto L44fb43;  // @110_44f9c0
  eax = (u32)(edi + 60);  // @111_44f9c0
  ecx = ebx;  // @112_44f9c0
  PV[15] = (u32)(eax);  // @113_44f9c0
  eax = ext_4e12f0_thiscall3(ecx, PV[15], (u32)(1));  // @114_44f9c0
  ecx = edx = 0;  // @115_44f9c0
  L44fb43:;
  eax = (u32)(EBP - 544);  // @117_44f9c0
  ecx = ebx;  // @118_44f9c0
  PV[16] = (u32)(eax);  // @119_44f9c0
  eax = ext_4e11e0_thiscall3(ecx, PV[16], (u32)(1));  // @120_44f9c0
  ecx = edx = 0;  // @121_44f9c0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; });  // @122_44f9c0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 208), &v, sizeof v); }  // @123_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @125_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @126_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_44f9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[17]);  // @128_44f9c0
  ecx = edx = 0;  // @129_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 196), &v, sizeof v); }  // @130_44f9c0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @131_44f9c0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 533), &v, sizeof v); }  // @132_44f9c0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @133_44f9c0
  if (FL[2] != 0) goto L44fb88;  // @134_44f9c0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @135_44f9c0
  L44fb88:;
  ecx = (u32)(eax + 4);  // @137_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 156), &v, sizeof v); }  // @138_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @139_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 64), &v, sizeof v); }  // @140_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @141_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @142_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @143_44f9c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @144_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @145_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @146_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @147_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @148_44f9c0
  ecx = (ecx + (u32)(24));  // @149_44f9c0
  FL[3] = ecx;  // @150_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @151_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @152_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 104), &v, sizeof v); }  // @153_44f9c0
  ecx = (u32)(ecx + eax*8);  // @154_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 88), &v, sizeof v); }  // @155_44f9c0
  eax = (u32)(edx + edx*2);  // @156_44f9c0
  ecx = (u32)(ecx + eax*4);  // @157_44f9c0
  edx = (edx << (u32)(2));  // @158_44f9c0
  FL[3] = edx;  // @159_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @160_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @161_44f9c0
  ecx = (ecx + edx);  // @162_44f9c0
  FL[3] = ecx;  // @163_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @164_44f9c0
  ecx = (ecx + edx);  // @165_44f9c0
  FL[3] = ecx;  // @166_44f9c0
  eax = (eax << (u32)(4));  // @167_44f9c0
  FL[3] = eax;  // @168_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @169_44f9c0
  ecx = (ecx + eax);  // @170_44f9c0
  FL[3] = ecx;  // @171_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @172_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @173_44f9c0
  ecx = (u32)(ecx + eax*2);  // @174_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; });  // @175_44f9c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 112), &v, sizeof v); }  // @176_44f9c0
  eax = (u32)(eax + eax*2);  // @177_44f9c0
  eax = (u32)(ecx + eax*2);  // @178_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_44f9c0
  ebx = ecx;  // @180_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 92), &v, sizeof v); }  // @181_44f9c0
  ebx = (ebx << (u32)(4));  // @182_44f9c0
  FL[3] = ebx;  // @183_44f9c0
  ebx = (ebx + eax);  // @184_44f9c0
  FL[3] = ebx;  // @185_44f9c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 533), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @186_44f9c0
  if (FL[0] != FL[1]) goto L44fc20;  // @187_44f9c0
  edx = 0;  // @188_44f9c0
  FL[3] = edx;  // @189_44f9c0
  FL[2] = (ecx & ecx);  // @190_44f9c0
  if (FL[2] == 0) goto L44fc20;  // @191_44f9c0
  ecx = 0;  // @192_44f9c0
  FL[3] = ecx;  // @193_44f9c0
  L44fc11:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @195_44f9c0
  ecx = (u32)(ecx + 16);  // @196_44f9c0
  edx = (edx + 1);  // @197_44f9c0
  FL[3] = edx;  // @198_44f9c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax - 16), sizeof v); (u32)v; }) + ebx)); __builtin_memcpy((void *)(u32)(ecx + eax - 16), &v, sizeof v); }  // @199_44f9c0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax - 16), sizeof v); (u32)v; });  // @200_44f9c0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @201_44f9c0
  if (FL[0] < FL[1]) goto L44fc11;  // @202_44f9c0
  L44fc20:;
  ecx = (u32)(EBP - 532);  // @204_44f9c0
  eax = ext_4cdd40_thiscall1(ecx);  // @205_44f9c0
  ecx = edx = 0;  // @206_44f9c0
  ecx = 0;  // @207_44f9c0
  FL[3] = ecx;  // @208_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 116), &v, sizeof v); }  // @209_44f9c0
  edx = (u32)(4);  // @210_44f9c0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @211_44f9c0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @212_44f9c0
  ecx = (0u - ecx);  // @213_44f9c0
  ecx = (ecx | eax);  // @214_44f9c0
  FL[3] = ecx;  // @215_44f9c0
  PV[18] = (u32)(ecx);  // @216_44f9c0
  eax = ext_41e290_cdecl1(PV[18]);  // @217_44f9c0
  ecx = edx = 0;  // @218_44f9c0
  ebx = 0;  // @219_44f9c0
  FL[3] = ebx;  // @220_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 120), &v, sizeof v); }  // @221_44f9c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; }); FL[1] = ebx;  // @222_44f9c0
  if (FL[0] <= FL[1]) goto L44fc86;  // @223_44f9c0
  L44fc51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @225_44f9c0
  ecx = (u32)(EBP - 532);  // @226_44f9c0
  PV[19] = (u32)(ebx);  // @227_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @228_44f9c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @229_44f9c0
  eax = ext_4ce5b0_thiscall2(ecx, PV[19]);  // @230_44f9c0
  ecx = edx = 0;  // @231_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @232_44f9c0
  PV[20] = (u32)(eax);  // @233_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @234_44f9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[20]);  // @235_44f9c0
  ecx = edx = 0;  // @236_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 120), sizeof v); (u32)v; });  // @237_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*4), &v, sizeof v); }  // @238_44f9c0
  ebx = (ebx + 1);  // @239_44f9c0
  FL[3] = ebx;  // @240_44f9c0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; });  // @241_44f9c0
  if (FL[0] < FL[1]) goto L44fc51;  // @242_44f9c0
  L44fc86:;
  ecx = (u32)(EBP - 360);  // @244_44f9c0
  eax = ext_4cdd40_thiscall1(ecx);  // @245_44f9c0
  ecx = edx = 0;  // @246_44f9c0
  ecx = 0;  // @247_44f9c0
  FL[3] = ecx;  // @248_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 128), &v, sizeof v); }  // @249_44f9c0
  edx = (u32)(4);  // @250_44f9c0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @251_44f9c0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @252_44f9c0
  ecx = (0u - ecx);  // @253_44f9c0
  ecx = (ecx | eax);  // @254_44f9c0
  FL[3] = ecx;  // @255_44f9c0
  PV[21] = (u32)(ecx);  // @256_44f9c0
  eax = ext_41e290_cdecl1(PV[21]);  // @257_44f9c0
  ecx = edx = 0;  // @258_44f9c0
  ebx = 0;  // @259_44f9c0
  FL[3] = ebx;  // @260_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @261_44f9c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 128), sizeof v); (u32)v; }); FL[1] = ebx;  // @262_44f9c0
  if (FL[0] <= FL[1]) goto L44fcfb;  // @263_44f9c0
  L44fcc0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @265_44f9c0
  ecx = (u32)(EBP - 360);  // @266_44f9c0
  PV[22] = (u32)(ebx);  // @267_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @268_44f9c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @269_44f9c0
  eax = ext_4ce5b0_thiscall2(ecx, PV[22]);  // @270_44f9c0
  ecx = edx = 0;  // @271_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @272_44f9c0
  PV[23] = (u32)(eax);  // @273_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @274_44f9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[23]);  // @275_44f9c0
  ecx = edx = 0;  // @276_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 132), sizeof v); (u32)v; });  // @277_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*4), &v, sizeof v); }  // @278_44f9c0
  ebx = (ebx + 1);  // @279_44f9c0
  FL[3] = ebx;  // @280_44f9c0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 128), sizeof v); (u32)v; });  // @281_44f9c0
  if (FL[0] < FL[1]) goto L44fcc0;  // @282_44f9c0
  L44fcfb:;
  ecx = (u32)(EBP - 188);  // @284_44f9c0
  eax = ext_4cdd40_thiscall1(ecx);  // @285_44f9c0
  ecx = edx = 0;  // @286_44f9c0
  ecx = 0;  // @287_44f9c0
  FL[3] = ecx;  // @288_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 164), &v, sizeof v); }  // @289_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 168), &v, sizeof v); }  // @290_44f9c0
  edx = (u32)(4);  // @291_44f9c0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @292_44f9c0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @293_44f9c0
  ecx = (0u - ecx);  // @294_44f9c0
  ecx = (ecx | eax);  // @295_44f9c0
  FL[3] = ecx;  // @296_44f9c0
  PV[24] = (u32)(ecx);  // @297_44f9c0
  eax = ext_41e290_cdecl1(PV[24]);  // @298_44f9c0
  ecx = edx = 0;  // @299_44f9c0
  ebx = 0;  // @300_44f9c0
  FL[3] = ebx;  // @301_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @302_44f9c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 164), sizeof v); (u32)v; }); FL[1] = ebx;  // @303_44f9c0
  if (FL[0] <= FL[1]) goto L44fd7b;  // @304_44f9c0
  L44fd40:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @306_44f9c0
  ecx = (u32)(EBP - 188);  // @307_44f9c0
  PV[25] = (u32)(ebx);  // @308_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @309_44f9c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @310_44f9c0
  eax = ext_4ce5b0_thiscall2(ecx, PV[25]);  // @311_44f9c0
  ecx = edx = 0;  // @312_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @313_44f9c0
  PV[26] = (u32)(eax);  // @314_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @315_44f9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 84)))(ecx, PV[26]);  // @316_44f9c0
  ecx = edx = 0;  // @317_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @318_44f9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*4), &v, sizeof v); }  // @319_44f9c0
  ebx = (ebx + 1);  // @320_44f9c0
  FL[3] = ebx;  // @321_44f9c0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 164), sizeof v); (u32)v; });  // @322_44f9c0
  if (FL[0] < FL[1]) goto L44fd40;  // @323_44f9c0
  L44fd7b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @325_44f9c0
  FL[2] = (eax & eax);  // @326_44f9c0
  if (FL[2] == 0) goto L44fd92;  // @327_44f9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @328_44f9c0
  FL[2] = (eax & eax);  // @329_44f9c0
  if (FL[2] == 0) goto L44fd92;  // @330_44f9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @331_44f9c0
  PV[27] = (u32)(eax);  // @332_44f9c0
  eax = ext_4dcdf0_thiscall2(ecx, PV[27]);  // @333_44f9c0
  ecx = edx = 0;  // @334_44f9c0
  L44fd92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 548), sizeof v); (u32)v; });  // @336_44f9c0
  eax = ext_4e1b30_thiscall1(ecx);  // @337_44f9c0
  ecx = edx = 0;  // @338_44f9c0
  ecx = (u32)(EBP - 188);  // @339_44f9c0
  eax = ext_4ccf60_thiscall1(ecx);  // @340_44f9c0
  ecx = edx = 0;  // @341_44f9c0
  ecx = (u32)(EBP - 360);  // @342_44f9c0
  eax = ext_4ccf60_thiscall1(ecx);  // @343_44f9c0
  ecx = edx = 0;  // @344_44f9c0
  ecx = (u32)(EBP - 532);  // @345_44f9c0
  eax = ext_4ccf60_thiscall1(ecx);  // @346_44f9c0
  ecx = edx = 0;  // @347_44f9c0
  SEH_LEAVE();  // @348_44f9c0
  ext_633654(G(u32, 0x6f5630));  // @349_44f9c0
  return eax;  // @350_44f9c0
}
PCREG(44f9c0, lifted_44f9c0);

extern "C" u32 THISCALL lifted_600940(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  SEH_ENTER(0x66d800);  // @h_600940
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_600940
  ecx = 0;  // @1_600940
  FL[3] = ecx;  // @2_600940
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @3_600940
  esi = 0;  // @4_600940
  FL[3] = esi;  // @5_600940
  eax = (u32)(10);  // @6_600940
  edx = (u32)(2);  // @7_600940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @8_600940
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @9_600940
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @10_600940
  ecx = (0u - ecx);  // @11_600940
  ecx = (ecx | eax);  // @12_600940
  FL[3] = ecx;  // @13_600940
  PV[0] = (u32)(ecx);  // @14_600940
  eax = ext_41e290_cdecl1(PV[0]);  // @15_600940
  ecx = edx = 0;  // @16_600940
  edi = eax;  // @17_600940
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @18_600940
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @19_600940
  reg.state = (s32)(esi);  // @20_600940
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @21_600940
  if (FL[0] != FL[1]) goto L600acf;  // @22_600940
  ecx = 0;  // @23_600940
  FL[3] = ecx;  // @24_600940
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @25_600940
  eax = (u32)(10);  // @26_600940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @27_600940
  edx = (u32)(2);  // @28_600940
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @29_600940
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @30_600940
  ecx = (0u - ecx);  // @31_600940
  ecx = (ecx | eax);  // @32_600940
  FL[3] = ecx;  // @33_600940
  PV[1] = (u32)(ecx);  // @34_600940
  eax = ext_41e290_cdecl1(PV[1]);  // @35_600940
  ecx = edx = 0;  // @36_600940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @37_600940
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @38_600940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @39_600940
  eax = (u32)(EBP - 36);  // @40_600940
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @41_600940
  reg.state = (s32)((u32)(1));  // @42_600940
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @43_600940
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @44_600940
  PV[6] = (u32)(ebx);  // @45_600940
  PV[7] = (u32)(eax);  // @46_600940
  eax = (u32)(EBP - 48);  // @47_600940
  PV[8] = (u32)(eax);  // @48_600940
  eax = ext_5ff140_stdcall7(PV[8], PV[7], PV[6], PV[5], PV[4], PV[3], PV[2]);  // @49_600940
  ecx = edx = 0;  // @50_600940
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @51_600940
  if (FL[2] == 0) goto L600a5f;  // @52_600940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @53_600940
  eax = 0;  // @54_600940
  FL[3] = eax;  // @55_600940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @56_600940
  FL[2] = (esi & esi);  // @57_600940
  if (FL[2] == 0) goto L600a67;  // @58_600940
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @59_600940
  L600a08:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @61_600940
  esi = (esi - 1);  // @62_600940
  FL[3] = esi;  // @63_600940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @64_600940
  edi = (u32)(ecx + esi*2);  // @65_600940
  goto L600a1a;  // @66_600940
  L600a1a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 244), sizeof v); (u32)v; });  // @68_600940
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_600940
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2), sizeof v); (u32)v; });  // @70_600940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 252), sizeof v); (u32)v; });  // @71_600940
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) + ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx), sizeof v); (u32)v; }))) & 0xffff);  // @72_600940
  FL[3] = (eax & 0xffff);  // @73_600940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @74_600940
  FL[2] = (esi & esi);  // @75_600940
  if (FL[2] != 0) goto L600a08;  // @76_600940
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @77_600940
  if (FL[2] == 0) goto L600a67;  // @78_600940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @79_600940
  ecx = (eax & 0xffff);  // @80_600940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @81_600940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @82_600940
  eax = (eax - ecx);  // @83_600940
  FL[3] = eax;  // @84_600940
  ecx = edx;  // @85_600940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 32), &v, sizeof v); }  // @86_600940
  eax = (u32)(EBP + 24);  // @87_600940
  PV[9] = (u32)(eax);  // @88_600940
  eax = (u32)(EBP + 32);  // @89_600940
  PV[10] = (u32)(eax);  // @90_600940
  eax = ext_5f5520_thiscall3(ecx, PV[10], PV[9]);  // @91_600940
  ecx = edx = 0;  // @92_600940
  goto L600a67;  // @93_600940
  L600a5f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @95_600940
  eax = ext_5f55e0_thiscall1(ecx);  // @96_600940
  ecx = edx = 0;  // @97_600940
  L600a67:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @99_600940
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @100_600940
  FL[2] = (esi & esi);  // @101_600940
  if (FL[2] == 0) goto L600abf;  // @102_600940
  L600a71:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 244), sizeof v); (u32)v; });  // @104_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*2 - 2), sizeof v); (u32)v; });  // @105_600940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 252), sizeof v); (u32)v; });  // @106_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*2), sizeof v); (u32)v; });  // @107_600940
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xffff);  // @108_600940
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @109_600940
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @110_600940
  if (FL[2] == 0) goto L600ab7;  // @111_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*2 - 2), sizeof v); (u32)v; });  // @112_600940
  edx = (edx + (u32)(2));  // @113_600940
  FL[3] = edx;  // @114_600940
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @115_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*2), sizeof v); (u32)v; });  // @116_600940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @117_600940
  eax = (eax + edx);  // @118_600940
  FL[3] = eax;  // @119_600940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 22), &v, sizeof v); }  // @120_600940
  eax = (u32)(EBP - 24);  // @121_600940
  PV[12] = (u32)(eax);  // @122_600940
  PV[13] = (u32)(ebx);  // @123_600940
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @124_600940
  eax = ext_5fed20_fastcall6(ecx, edx, PV[14], PV[13], PV[12], PV[11]);  // @125_600940
  ecx = edx = 0;  // @126_600940
  L600ab7:;
  esi = (esi - (u32)(1));  // @128_600940
  FL[3] = esi;  // @129_600940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @130_600940
  if (FL[3] != 0) goto L600a71;  // @131_600940
  L600abf:;
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @133_600940
  eax = ext_41e2c0_cdecl1(PV[15]);  // @134_600940
  ecx = edx = 0;  // @135_600940
  goto L600b81;  // @136_600940
  L600acf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @138_600940
  eax = ext_5f55e0_thiscall1(ecx);  // @139_600940
  ecx = edx = 0;  // @140_600940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @141_600940
  ecx = (u32)(65535);  // @142_600940
  ebx = (eax & 0xffff);  // @143_600940
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @144_600940
  if (FL[0] == FL[1]) goto L600b81;  // @145_600940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @146_600940
  L600af0:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @148_600940
  if (FL[0] < FL[1]) goto L600b06;  // @149_600940
  ecx = (u32)(EBP - 36);  // @150_600940
  eax = ext_5ff0a0_thiscall1(ecx);  // @151_600940
  ecx = edx = 0;  // @152_600940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @153_600940
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @154_600940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @155_600940
  L600b06:;
  { u16 v = (u16)((ebx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + esi*2), &v, sizeof v); }  // @157_600940
  esi = (esi + 1);  // @158_600940
  FL[3] = esi;  // @159_600940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 248), sizeof v); (u32)v; });  // @160_600940
  ecx = (ebx & 0xffff);  // @161_600940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @162_600940
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*2), sizeof v); (u32)v; });  // @163_600940
  eax = (u32)(65535);  // @164_600940
  FL[0] = (ebx & 0xffff); FL[1] = (eax & 0xffff);  // @165_600940
  if (FL[0] != FL[1]) goto L600af0;  // @166_600940
  FL[2] = (esi & esi);  // @167_600940
  if (FL[2] == 0) goto L600b81;  // @168_600940
  L600b30:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 244), sizeof v); (u32)v; });  // @170_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*2 - 2), sizeof v); (u32)v; });  // @171_600940
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 252), sizeof v); (u32)v; });  // @172_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*2), sizeof v); (u32)v; });  // @173_600940
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx), sizeof v); (u32)v; })) & 0xffff);  // @174_600940
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @175_600940
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @176_600940
  if (FL[2] == 0) goto L600b79;  // @177_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*2 - 2), sizeof v); (u32)v; });  // @178_600940
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @179_600940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*2), sizeof v); (u32)v; });  // @180_600940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @181_600940
  eax = (eax + (u32)(2));  // @182_600940
  FL[3] = eax;  // @183_600940
  eax = (eax + ebx);  // @184_600940
  FL[3] = eax;  // @185_600940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 22), &v, sizeof v); }  // @186_600940
  eax = (u32)(EBP - 24);  // @187_600940
  PV[17] = (u32)(eax);  // @188_600940
  PV[18] = (u32)(edx);  // @189_600940
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @190_600940
  eax = ext_5fed20_fastcall6(ecx, edx, PV[19], PV[18], PV[17], PV[16]);  // @191_600940
  ecx = edx = 0;  // @192_600940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @193_600940
  L600b79:;
  esi = (esi - (u32)(1));  // @195_600940
  FL[3] = esi;  // @196_600940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @197_600940
  if (FL[3] != 0) goto L600b30;  // @198_600940
  L600b81:;
  PV[20] = (u32)(edi);  // @200_600940
  eax = ext_41e2c0_cdecl1(PV[20]);  // @201_600940
  ecx = edx = 0;  // @202_600940
  SEH_LEAVE();  // @203_600940
  return eax;  // @204_600940
}
PCREG(600940, lifted_600940);

extern "C" u32 THISCALL lifted_5f9dd0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d23f);  // @h_5f9dd0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5f9dd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f9dd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5f9dd0
  ecx = (u32)(EBP - 20);  // @3_5f9dd0
  PV[0] = (u32)(ecx);  // @4_5f9dd0
  ecx = edi;  // @5_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @6_5f9dd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[0]);  // @7_5f9dd0
  ecx = edx = 0;  // @8_5f9dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @9_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @10_5f9dd0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @11_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @12_5f9dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @13_5f9dd0
  eax = ext_41e2c0_cdecl1(PV[1]);  // @14_5f9dd0
  ecx = edx = 0;  // @15_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @16_5f9dd0
  ecx = 0;  // @17_5f9dd0
  FL[3] = ecx;  // @18_5f9dd0
  edx = (u32)(4);  // @19_5f9dd0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @20_5f9dd0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @21_5f9dd0
  ecx = (0u - ecx);  // @22_5f9dd0
  ecx = (ecx | eax);  // @23_5f9dd0
  FL[3] = ecx;  // @24_5f9dd0
  PV[2] = (u32)(ecx);  // @25_5f9dd0
  eax = ext_41e290_cdecl1(PV[2]);  // @26_5f9dd0
  ecx = edx = 0;  // @27_5f9dd0
  ebx = 0;  // @28_5f9dd0
  FL[3] = ebx;  // @29_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @30_5f9dd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @31_5f9dd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = ebx;  // @32_5f9dd0
  if (FL[0] <= FL[1]) goto L5f9f2d;  // @33_5f9dd0
  L5f9e50:;
  eax = ext_41e290_cdecl1((u32)(12));  // @35_5f9dd0
  ecx = edx = 0;  // @36_5f9dd0
  edi = eax;  // @37_5f9dd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @38_5f9dd0
  reg.state = (s32)((u32)(0));  // @39_5f9dd0
  FL[2] = (edi & edi);  // @40_5f9dd0
  if (FL[2] == 0) goto L5f9e9e;  // @41_5f9dd0
  ecx = edi;  // @42_5f9dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_5f9dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @44_5f9dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @45_5f9dd0
  eax = ext_6014a0_stdcall1((u32)(8));  // @46_5f9dd0
  ecx = edx = 0;  // @47_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @48_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @49_5f9dd0
  ecx = (u32)(eax + 8);  // @50_5f9dd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @51_5f9dd0
  FL[2] = (eax & eax);  // @52_5f9dd0
  if (FL[2] == 0) goto L5f9e99;  // @53_5f9dd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @54_5f9dd0
  L5f9e99:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @56_5f9dd0
  goto L5f9ea0;  // @57_5f9dd0
  L5f9e9e:;
  edi = 0;  // @59_5f9dd0
  FL[3] = edi;  // @60_5f9dd0
  L5f9ea0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @62_5f9dd0
  PV[3] = (u32)(edi);  // @63_5f9dd0
  reg.state = (s32)((u32)(4294967295));  // @64_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_5f9dd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[3]);  // @66_5f9dd0
  ecx = edx = 0;  // @67_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @68_5f9dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @69_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @70_5f9dd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }); FL[1] = eax;  // @71_5f9dd0
  if (FL[0] < FL[1]) goto L5f9f11;  // @72_5f9dd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @73_5f9dd0
  eax = (eax + eax);  // @74_5f9dd0
  FL[3] = eax;  // @75_5f9dd0
  ecx = 0;  // @76_5f9dd0
  FL[3] = ecx;  // @77_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @78_5f9dd0
  edx = (u32)(4);  // @79_5f9dd0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @80_5f9dd0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @81_5f9dd0
  ecx = (0u - ecx);  // @82_5f9dd0
  ecx = (ecx | eax);  // @83_5f9dd0
  FL[3] = ecx;  // @84_5f9dd0
  PV[4] = (u32)(ecx);  // @85_5f9dd0
  eax = ext_41e290_cdecl1(PV[4]);  // @86_5f9dd0
  ecx = edx = 0;  // @87_5f9dd0
  edx = 0;  // @88_5f9dd0
  FL[3] = edx;  // @89_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @90_5f9dd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }); FL[1] = edx;  // @91_5f9dd0
  if (FL[0] <= FL[1]) goto L5f9eff;  // @92_5f9dd0
  L5f9ef0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @94_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx*4), sizeof v); (u32)v; });  // @95_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx*4), &v, sizeof v); }  // @96_5f9dd0
  edx = (edx + 1);  // @97_5f9dd0
  FL[3] = edx;  // @98_5f9dd0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @99_5f9dd0
  if (FL[0] < FL[1]) goto L5f9ef0;  // @100_5f9dd0
  L5f9eff:;
  PV[5] = (u32)(ebx);  // @102_5f9dd0
  eax = ext_41e2c0_cdecl1(PV[5]);  // @103_5f9dd0
  ecx = edx = 0;  // @104_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @105_5f9dd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @106_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @107_5f9dd0
  L5f9f11:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @109_5f9dd0
  ebx = (ebx + 1);  // @110_5f9dd0
  FL[3] = ebx;  // @111_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @112_5f9dd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @113_5f9dd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @114_5f9dd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @115_5f9dd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @116_5f9dd0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @117_5f9dd0
  if (FL[0] < FL[1]) goto L5f9e50;  // @118_5f9dd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @119_5f9dd0
  L5f9f2d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @121_5f9dd0
  ecx = (u32)(EBP - 24);  // @122_5f9dd0
  PV[6] = (u32)(ecx);  // @123_5f9dd0
  ecx = edi;  // @124_5f9dd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @125_5f9dd0
  ecx = edx = 0;  // @126_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @127_5f9dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @128_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @129_5f9dd0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @130_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @131_5f9dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @132_5f9dd0
  eax = ext_41e2c0_cdecl1(PV[7]);  // @133_5f9dd0
  ecx = edx = 0;  // @134_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @135_5f9dd0
  ecx = 0;  // @136_5f9dd0
  FL[3] = ecx;  // @137_5f9dd0
  edx = (u32)(4);  // @138_5f9dd0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @139_5f9dd0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @140_5f9dd0
  ecx = (0u - ecx);  // @141_5f9dd0
  ecx = (ecx | eax);  // @142_5f9dd0
  FL[3] = ecx;  // @143_5f9dd0
  PV[8] = (u32)(ecx);  // @144_5f9dd0
  eax = ext_41e290_cdecl1(PV[8]);  // @145_5f9dd0
  ecx = edx = 0;  // @146_5f9dd0
  ebx = 0;  // @147_5f9dd0
  FL[3] = ebx;  // @148_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @149_5f9dd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = ebx;  // @150_5f9dd0
  if (FL[0] <= FL[1]) goto L5fa02d;  // @151_5f9dd0
  L5f9f80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @153_5f9dd0
  ecx = (u32)(EBP - 36);  // @154_5f9dd0
  PV[9] = (u32)(ecx);  // @155_5f9dd0
  ecx = edi;  // @156_5f9dd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[9]);  // @157_5f9dd0
  ecx = edx = 0;  // @158_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @159_5f9dd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @160_5f9dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @161_5f9dd0
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @162_5f9dd0
  if (FL[0] < FL[1]) goto L5f9fa7;  // @163_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @164_5f9dd0
  FL[2] = (eax & eax);  // @165_5f9dd0
  if (FL[2] == 0) goto L5f9fa6;  // @166_5f9dd0
  eax = ((u32(STDCALL *)(void))(eax))();  // @167_5f9dd0
  ecx = edx = 0;  // @168_5f9dd0
  goto L5f9fa7;  // @169_5f9dd0
  L5f9fa6:;
  __builtin_trap();  // @171_5f9dd0
  L5f9fa7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @173_5f9dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @174_5f9dd0
  ecx = esi;  // @175_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @176_5f9dd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @177_5f9dd0
  PV[10] = (u32)(edi);  // @178_5f9dd0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @179_5f9dd0
  eax = ext_5fa380_thiscall3(ecx, PV[11], PV[10]);  // @180_5f9dd0
  ecx = edx = 0;  // @181_5f9dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @182_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @183_5f9dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @184_5f9dd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = ecx;  // @185_5f9dd0
  if (FL[0] < FL[1]) goto L5fa015;  // @186_5f9dd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @187_5f9dd0
  eax = (u32)(ecx + ecx);  // @188_5f9dd0
  ecx = 0;  // @189_5f9dd0
  FL[3] = ecx;  // @190_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @191_5f9dd0
  edx = (u32)(4);  // @192_5f9dd0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @193_5f9dd0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @194_5f9dd0
  ecx = (0u - ecx);  // @195_5f9dd0
  ecx = (ecx | eax);  // @196_5f9dd0
  FL[3] = ecx;  // @197_5f9dd0
  PV[12] = (u32)(ecx);  // @198_5f9dd0
  eax = ext_41e290_cdecl1(PV[12]);  // @199_5f9dd0
  ecx = edx = 0;  // @200_5f9dd0
  edx = 0;  // @201_5f9dd0
  FL[3] = edx;  // @202_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @203_5f9dd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = edx;  // @204_5f9dd0
  if (FL[0] <= FL[1]) goto L5fa003;  // @205_5f9dd0
  L5f9ff5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @207_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx*4), sizeof v); (u32)v; });  // @208_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx*4), &v, sizeof v); }  // @209_5f9dd0
  edx = (edx + 1);  // @210_5f9dd0
  FL[3] = edx;  // @211_5f9dd0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @212_5f9dd0
  if (FL[0] < FL[1]) goto L5f9ff5;  // @213_5f9dd0
  L5fa003:;
  PV[13] = (u32)(edi);  // @215_5f9dd0
  eax = ext_41e2c0_cdecl1(PV[13]);  // @216_5f9dd0
  ecx = edx = 0;  // @217_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @218_5f9dd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @219_5f9dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @220_5f9dd0
  L5fa015:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @222_5f9dd0
  ebx = (ebx + 1);  // @223_5f9dd0
  FL[3] = ebx;  // @224_5f9dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @225_5f9dd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @226_5f9dd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @227_5f9dd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @228_5f9dd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @229_5f9dd0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @230_5f9dd0
  if (FL[0] < FL[1]) goto L5f9f80;  // @231_5f9dd0
  L5fa02d:;
  SEH_LEAVE();  // @233_5f9dd0
  return eax;  // @234_5f9dd0
}
PCREG(5f9dd0, lifted_5f9dd0);

extern "C" u32 THISCALL lifted_4954f0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x668073);  // @h_4954f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_4954f0
  { u32 v = (u32)((u32)(6873828)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4954f0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_4954f0
  ecx = edx = 0;  // @3_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4954f0
  reg.state = (s32)((u32)(0));  // @5_4954f0
  FL[2] = (eax & eax);  // @6_4954f0
  if (FL[2] == 0) goto L495543;  // @7_4954f0
  ecx = eax;  // @8_4954f0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @9_4954f0
  ecx = edx = 0;  // @10_4954f0
  goto L495545;  // @11_4954f0
  L495543:;
  eax = 0;  // @13_4954f0
  FL[3] = eax;  // @14_4954f0
  L495545:;
  ecx = esi;  // @16_4954f0
  reg.state = (s32)((u32)(4294967295));  // @17_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @18_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @19_4954f0
  eax = ext_497930_thiscall1(ecx);  // @20_4954f0
  ecx = edx = 0;  // @21_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_4954f0
  eax = (u32)(613566757);  // @23_4954f0
  ecx = (ecx + (u32)(111));  // @24_4954f0
  FL[3] = ecx;  // @25_4954f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @26_4954f0
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @27_4954f0
  eax = (u32)(613566757);  // @28_4954f0
  ecx = (ecx - edx);  // @29_4954f0
  FL[3] = ecx;  // @30_4954f0
  ecx = (ecx >> (u32)(1));  // @31_4954f0
  FL[3] = ecx;  // @32_4954f0
  ecx = (ecx + edx);  // @33_4954f0
  FL[3] = ecx;  // @34_4954f0
  ecx = (ecx >> (u32)(6));  // @35_4954f0
  FL[3] = ecx;  // @36_4954f0
  edi = (u32)((s32)ecx * (s32)(u32)(112));  // @37_4954f0
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @38_4954f0
  eax = edi;  // @39_4954f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @40_4954f0
  eax = (eax - edx);  // @41_4954f0
  FL[3] = eax;  // @42_4954f0
  eax = (eax >> (u32)(1));  // @43_4954f0
  FL[3] = eax;  // @44_4954f0
  eax = (eax + edx);  // @45_4954f0
  FL[3] = eax;  // @46_4954f0
  eax = (eax >> (u32)(6));  // @47_4954f0
  FL[3] = eax;  // @48_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @49_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @50_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @51_4954f0
  eax = (eax + (u32)(15));  // @52_4954f0
  FL[3] = eax;  // @53_4954f0
  eax = (eax & (u32)(4294967280));  // @54_4954f0
  FL[3] = eax;  // @55_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @56_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @57_4954f0
  eax = (eax + (u32)(15));  // @58_4954f0
  FL[3] = eax;  // @59_4954f0
  eax = (eax & (u32)(4294967280));  // @60_4954f0
  FL[3] = eax;  // @61_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @62_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_4954f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(5177423));  // @64_4954f0
  ecx = edx = 0;  // @65_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @66_4954f0
  eax = ext_41e290_cdecl1((u32)(25));  // @67_4954f0
  ecx = edx = 0;  // @68_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @69_4954f0
  reg.state = (s32)((u32)(1));  // @70_4954f0
  FL[2] = (eax & eax);  // @71_4954f0
  if (FL[2] == 0) goto L4955e5;  // @72_4954f0
  ecx = eax;  // @73_4954f0
  eax = ext_4cc930_thiscall3(ecx, (u32)(13), (u32)(8192));  // @74_4954f0
  ecx = edx = 0;  // @75_4954f0
  goto L4955e7;  // @76_4954f0
  L4955e5:;
  eax = 0;  // @78_4954f0
  FL[3] = eax;  // @79_4954f0
  L4955e7:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @81_4954f0
  ecx = 0;  // @82_4954f0
  FL[3] = ecx;  // @83_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @84_4954f0
  edx = (u32)(4);  // @85_4954f0
  eax = (eax + 1);  // @86_4954f0
  FL[3] = eax;  // @87_4954f0
  reg.state = (s32)((u32)(4294967295));  // @88_4954f0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @89_4954f0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @90_4954f0
  ecx = (0u - ecx);  // @91_4954f0
  ecx = (ecx | eax);  // @92_4954f0
  FL[3] = ecx;  // @93_4954f0
  PV[0] = (u32)(ecx);  // @94_4954f0
  eax = ext_41e290_cdecl1(PV[0]);  // @95_4954f0
  ecx = edx = 0;  // @96_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @97_4954f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @98_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @99_4954f0
  ecx = (u32)(ecx*4 + 4);  // @100_4954f0
  PV[1] = (u32)(ecx);  // @101_4954f0
  PV[2] = (u32)(eax);  // @102_4954f0
  eax = ext_634d10_cdecl3(PV[2], (u32)(0), PV[1]);  // @103_4954f0
  ecx = edx = 0;  // @104_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @105_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_4954f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(8323199));  // @107_4954f0
  ecx = edx = 0;  // @108_4954f0
  eax = ext_41e290_cdecl1((u32)(20));  // @109_4954f0
  ecx = edx = 0;  // @110_4954f0
  ebx = eax;  // @111_4954f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @112_4954f0
  reg.state = (s32)((u32)(2));  // @113_4954f0
  FL[2] = (ebx & ebx);  // @114_4954f0
  if (FL[2] == 0) goto L49565d;  // @115_4954f0
  PV[3] = (u32)(edi);  // @116_4954f0
  ecx = ebx;  // @117_4954f0
  eax = ext_4957f0_thiscall3(ecx, PV[3], (u32)(0));  // @118_4954f0
  ecx = edx = 0;  // @119_4954f0
  goto L49565f;  // @120_4954f0
  L49565d:;
  ebx = 0;  // @122_4954f0
  FL[3] = ebx;  // @123_4954f0
  L49565f:;
  ecx = 0;  // @125_4954f0
  FL[3] = ecx;  // @126_4954f0
  reg.state = (s32)((u32)(4294967295));  // @127_4954f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @128_4954f0
  FL[2] = (edi & edi);  // @129_4954f0
  if (FL[2] == 0) goto L495685;  // @130_4954f0
  L495670:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @132_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @133_4954f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 60), sizeof v); (u32)v; }) | (u32)(67108864))); __builtin_memcpy((void *)(u32)(eax + ecx + 60), &v, sizeof v); }  // @134_4954f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 60), sizeof v); (u32)v; });  // @135_4954f0
  ecx = (ecx + (u32)(112));  // @136_4954f0
  FL[3] = ecx;  // @137_4954f0
  FL[0] = ecx; FL[1] = edi;  // @138_4954f0
  if (FL[0] != FL[1]) goto L495670;  // @139_4954f0
  L495685:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @141_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_4954f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(8323072));  // @143_4954f0
  ecx = edx = 0;  // @144_4954f0
  eax = ext_41e290_cdecl1((u32)(20));  // @145_4954f0
  ecx = edx = 0;  // @146_4954f0
  ebx = eax;  // @147_4954f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @148_4954f0
  reg.state = (s32)((u32)(3));  // @149_4954f0
  FL[2] = (ebx & ebx);  // @150_4954f0
  if (FL[2] == 0) goto L4956bd;  // @151_4954f0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @152_4954f0
  ecx = ebx;  // @153_4954f0
  eax = ext_4957f0_thiscall3(ecx, PV[4], (u32)(0));  // @154_4954f0
  ecx = edx = 0;  // @155_4954f0
  goto L4956bf;  // @156_4954f0
  L4956bd:;
  ebx = 0;  // @158_4954f0
  FL[3] = ebx;  // @159_4954f0
  L4956bf:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @161_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @162_4954f0
  reg.state = (s32)((u32)(4294967295));  // @163_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_4954f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(5177344));  // @165_4954f0
  ecx = edx = 0;  // @166_4954f0
  eax = ext_41e290_cdecl1((u32)(20));  // @167_4954f0
  ecx = edx = 0;  // @168_4954f0
  ebx = eax;  // @169_4954f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @170_4954f0
  reg.state = (s32)((u32)(4));  // @171_4954f0
  FL[2] = (ebx & ebx);  // @172_4954f0
  if (FL[2] == 0) goto L49571c;  // @173_4954f0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @174_4954f0
  ecx = ebx;  // @175_4954f0
  eax = ext_4957f0_thiscall3(ecx, PV[5], (u32)(0));  // @176_4954f0
  ecx = edx = 0;  // @177_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @178_4954f0
  reg.state = (s32)((u32)(5));  // @179_4954f0
  FL[2] = (ecx & ecx);  // @180_4954f0
  if (FL[2] == 0) goto L49571e;  // @181_4954f0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @182_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @183_4954f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6874312), PV[6]);  // @184_4954f0
  ecx = edx = 0;  // @185_4954f0
  goto L49571e;  // @186_4954f0
  L49571c:;
  ebx = 0;  // @188_4954f0
  FL[3] = ebx;  // @189_4954f0
  L49571e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @191_4954f0
  ecx = esi;  // @192_4954f0
  eax = (eax + (u32)(15));  // @193_4954f0
  FL[3] = eax;  // @194_4954f0
  reg.state = (s32)((u32)(4294967295));  // @195_4954f0
  eax = (eax & (u32)(4294967280));  // @196_4954f0
  FL[3] = eax;  // @197_4954f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @198_4954f0
  PV[7] = (u32)(eax);  // @199_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @200_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @201_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @202_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @203_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @204_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @205_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @206_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @207_4954f0
  eax = ext_497750_thiscall2(ecx, PV[7]);  // @208_4954f0
  ecx = edx = 0;  // @209_4954f0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @210_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @211_4954f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @212_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @213_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_4954f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[8]);  // @215_4954f0
  ecx = edx = 0;  // @216_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @217_4954f0
  FL[2] = (ecx & ecx);  // @218_4954f0
  if (FL[2] == 0) goto L4957d2;  // @219_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @220_4954f0
  PV[9] = (u32)(edi);  // @221_4954f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6873924), PV[9]);  // @222_4954f0
  ecx = edx = 0;  // @223_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @224_4954f0
  FL[2] = (ecx & ecx);  // @225_4954f0
  if (FL[2] == 0) goto L4957d2;  // @226_4954f0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @227_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @228_4954f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6873936), PV[10]);  // @229_4954f0
  ecx = edx = 0;  // @230_4954f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @231_4954f0
  FL[2] = (ecx & ecx);  // @232_4954f0
  if (FL[2] == 0) goto L4957d2;  // @233_4954f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @234_4954f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6873948), (u32)(32768));  // @235_4954f0
  ecx = edx = 0;  // @236_4954f0
  L4957d2:;
  eax = esi;  // @238_4954f0
  SEH_LEAVE();  // @239_4954f0
  return eax;  // @240_4954f0
}
PCREG(4954f0, lifted_4954f0);

extern "C" u32 THISCALL lifted_436bd0(u32 ecx_in) {
  SEH_ENTER(0x6659b9);  // @h_436bd0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_436bd0
  { u32 v = (u32)((u32)(6792928)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_436bd0
  ecx = 0;  // @2_436bd0
  FL[3] = ecx;  // @3_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7227584), sizeof v); (u32)v; });  // @4_436bd0
  edx = 0;  // @5_436bd0
  FL[3] = edx;  // @6_436bd0
  FL[2] = (eax & eax);  // @7_436bd0
  if (FL[2] == 0) goto L436c30;  // @8_436bd0
  eax = 0;  // @9_436bd0
  FL[3] = eax;  // @10_436bd0
  L436c10:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 7227576), &v, sizeof v); }  // @12_436bd0
  edx = (edx + 1);  // @13_436bd0
  FL[3] = edx;  // @14_436bd0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227588), sizeof v); (u32)v; }));  // @15_436bd0
  FL[3] = ecx;  // @16_436bd0
  eax = edx;  // @17_436bd0
  eax = (eax << (u32)(4));  // @18_436bd0
  FL[3] = eax;  // @19_436bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227584), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_436bd0
  if (FL[0] != FL[1]) goto L436c10;  // @21_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7227584), sizeof v); (u32)v; });  // @22_436bd0
  L436c30:;
  edx = 0;  // @24_436bd0
  FL[3] = edx;  // @25_436bd0
  ecx = 0;  // @26_436bd0
  FL[3] = ecx;  // @27_436bd0
  FL[2] = (eax & eax);  // @28_436bd0
  if (FL[2] == 0) goto L436c55;  // @29_436bd0
  eax = 0;  // @30_436bd0
  FL[3] = eax;  // @31_436bd0
  L436c40:;
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227588), sizeof v); (u32)v; }));  // @33_436bd0
  FL[3] = edx;  // @34_436bd0
  ecx = (ecx + 1);  // @35_436bd0
  FL[3] = ecx;  // @36_436bd0
  eax = ecx;  // @37_436bd0
  eax = (eax << (u32)(4));  // @38_436bd0
  FL[3] = eax;  // @39_436bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227584), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @40_436bd0
  if (FL[0] != FL[1]) goto L436c40;  // @41_436bd0
  L436c55:;
  PV[0] = (u32)(edx);  // @43_436bd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 4624), &v, sizeof v); }  // @44_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4616), &v, sizeof v); }  // @45_436bd0
  eax = ext_41e290_cdecl1(PV[0]);  // @46_436bd0
  ecx = edx = 0;  // @47_436bd0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; });  // @48_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4892), &v, sizeof v); }  // @49_436bd0
  PV[2] = (u32)(eax);  // @50_436bd0
  eax = ext_634d10_cdecl3(PV[2], (u32)(0), PV[1]);  // @51_436bd0
  ecx = edx = 0;  // @52_436bd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; });  // @53_436bd0
  ecx = 0;  // @54_436bd0
  FL[3] = ecx;  // @55_436bd0
  eax = ebx;  // @56_436bd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @57_436bd0
  edx = (u32)(10);  // @58_436bd0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @59_436bd0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @60_436bd0
  ecx = (0u - ecx);  // @61_436bd0
  ecx = (ecx | eax);  // @62_436bd0
  FL[3] = ecx;  // @63_436bd0
  eax = 0;  // @64_436bd0
  FL[3] = eax;  // @65_436bd0
  ecx = (ecx + (u32)(4));  // @66_436bd0
  FL[3] = ecx;  // @67_436bd0
  eax = (eax & 0xffffff00u) | ((((0 && FL[3]) ? 1 : 0)) & 0xff);  // @68_436bd0
  eax = (0u - eax);  // @69_436bd0
  eax = (eax | ecx);  // @70_436bd0
  FL[3] = eax;  // @71_436bd0
  PV[3] = (u32)(eax);  // @72_436bd0
  eax = ext_41e290_cdecl1(PV[3]);  // @73_436bd0
  ecx = edx = 0;  // @74_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @75_436bd0
  reg.state = (s32)((u32)(0));  // @76_436bd0
  FL[2] = (eax & eax);  // @77_436bd0
  if (FL[2] == 0) goto L436cd7;  // @78_436bd0
  PV[4] = (u32)(ebx);  // @79_436bd0
  edi = (u32)(eax + 4);  // @80_436bd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @81_436bd0
  PV[5] = (u32)(edi);  // @82_436bd0
  eax = ext_634123_stdcall5(PV[5], (u32)(10), PV[4], (u32)(4416720), (u32)(4624560));  // @83_436bd0
  ecx = edx = 0;  // @84_436bd0
  goto L436cd9;  // @85_436bd0
  L436cd7:;
  edi = 0;  // @87_436bd0
  FL[3] = edi;  // @88_436bd0
  L436cd9:;
  edx = 0;  // @90_436bd0
  FL[3] = edx;  // @91_436bd0
  reg.state = (s32)((u32)(4294967295));  // @92_436bd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 4932), &v, sizeof v); }  // @93_436bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; }); FL[1] = edx;  // @94_436bd0
  if (FL[0] == FL[1]) goto L436d13;  // @95_436bd0
  ecx = 0;  // @96_436bd0
  FL[3] = ecx;  // @97_436bd0
  L436cf2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4932), sizeof v); (u32)v; });  // @99_436bd0
  ecx = (u32)(ecx + 10);  // @100_436bd0
  edx = (edx + 1);  // @101_436bd0
  FL[3] = edx;  // @102_436bd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + eax - 10), &v, sizeof v); }  // @103_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4932), sizeof v); (u32)v; });  // @104_436bd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax - 1), &v, sizeof v); }  // @105_436bd0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; });  // @106_436bd0
  if (FL[0] != FL[1]) goto L436cf2;  // @107_436bd0
  L436d13:;
  eax = ext_41e290_cdecl1((u32)(28));  // @109_436bd0
  ecx = edx = 0;  // @110_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @111_436bd0
  reg.state = (s32)((u32)(1));  // @112_436bd0
  FL[2] = (eax & eax);  // @113_436bd0
  if (FL[2] == 0) goto L436d38;  // @114_436bd0
  ecx = eax;  // @115_436bd0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(0));  // @116_436bd0
  ecx = edx = 0;  // @117_436bd0
  goto L436d3a;  // @118_436bd0
  L436d38:;
  eax = 0;  // @120_436bd0
  FL[3] = eax;  // @121_436bd0
  L436d3a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4628), &v, sizeof v); }  // @123_436bd0
  ecx = (u32)(512);  // @124_436bd0
  reg.state = (s32)((u32)(4294967295));  // @125_436bd0
  eax = (u32)(esi + 13);  // @126_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4936), &v, sizeof v); }  // @127_436bd0
  L436d60:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 5), &v, sizeof v); }  // @129_436bd0
  eax = (u32)(eax + 9);  // @130_436bd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 10), &v, sizeof v); }  // @131_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 9), &v, sizeof v); }  // @132_436bd0
  ecx = (ecx - (u32)(1));  // @133_436bd0
  FL[3] = ecx;  // @134_436bd0
  if (FL[3] != 0) goto L436d60;  // @135_436bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4632), &v, sizeof v); }  // @136_436bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4904), &v, sizeof v); }  // @137_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @138_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2543), sizeof v); (u32)v; });  // @139_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4896), &v, sizeof v); }  // @140_436bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4900), &v, sizeof v); }  // @141_436bd0
  eax = ext_41e290_cdecl1((u32)(6));  // @142_436bd0
  ecx = edx = 0;  // @143_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @144_436bd0
  reg.state = (s32)((u32)(2));  // @145_436bd0
  FL[2] = (eax & eax);  // @146_436bd0
  if (FL[2] == 0) goto L436dc0;  // @147_436bd0
  ecx = eax;  // @148_436bd0
  eax = ext_4d8ce0_thiscall2(ecx, (u32)(32));  // @149_436bd0
  ecx = edx = 0;  // @150_436bd0
  goto L436dc2;  // @151_436bd0
  L436dc0:;
  eax = 0;  // @153_436bd0
  FL[3] = eax;  // @154_436bd0
  L436dc2:;
  reg.state = (s32)((u32)(4294967295));  // @156_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4912), &v, sizeof v); }  // @157_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4620), &v, sizeof v); }  // @158_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4916), &v, sizeof v); }  // @159_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4920), &v, sizeof v); }  // @160_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @161_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4908), &v, sizeof v); }  // @162_436bd0
  eax = ext_41e290_cdecl1((u32)(28));  // @163_436bd0
  ecx = edx = 0;  // @164_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @165_436bd0
  reg.state = (s32)((u32)(3));  // @166_436bd0
  FL[2] = (eax & eax);  // @167_436bd0
  if (FL[2] == 0) goto L436e23;  // @168_436bd0
  ecx = eax;  // @169_436bd0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(10), (u32)(0));  // @170_436bd0
  ecx = edx = 0;  // @171_436bd0
  goto L436e25;  // @172_436bd0
  L436e23:;
  eax = 0;  // @174_436bd0
  FL[3] = eax;  // @175_436bd0
  L436e25:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4924), &v, sizeof v); }  // @177_436bd0
  ecx = esi;  // @178_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_436bd0
  reg.state = (s32)((u32)(4294967295));  // @180_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4928), &v, sizeof v); }  // @181_436bd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(7225804));  // @182_436bd0
  ecx = edx = 0;  // @183_436bd0
  FL[2] = (eax & eax);  // @184_436bd0
  if (FL[2] == 0) goto L436e63;  // @185_436bd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @186_436bd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; });  // @187_436bd0
  eax = esi;  // @188_436bd0
  SEH_LEAVE();  // @189_436bd0
  return eax;  // @190_436bd0
  L436e63:;
  eax = ext_41e290_cdecl1((u32)(35));  // @192_436bd0
  ecx = edx = 0;  // @193_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @194_436bd0
  reg.state = (s32)((u32)(4));  // @195_436bd0
  FL[2] = (eax & eax);  // @196_436bd0
  if (FL[2] == 0) goto L436e93;  // @197_436bd0
  PV[6] = (u32)(esi);  // @198_436bd0
  ecx = eax;  // @199_436bd0
  eax = ext_4364e0_thiscall5(ecx, PV[6], (u32)(7225804), (u32)(6793340), (u32)(0));  // @200_436bd0
  ecx = edx = 0;  // @201_436bd0
  edx = eax;  // @202_436bd0
  goto L436e95;  // @203_436bd0
  L436e93:;
  edx = 0;  // @205_436bd0
  FL[3] = edx;  // @206_436bd0
  L436e95:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4628), sizeof v); (u32)v; });  // @208_436bd0
  PV[7] = (u32)(edx);  // @209_436bd0
  reg.state = (s32)((u32)(4294967295));  // @210_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @211_436bd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7]);  // @212_436bd0
  ecx = edx = 0;  // @213_436bd0
  eax = esi;  // @214_436bd0
  SEH_LEAVE();  // @215_436bd0
  return eax;  // @216_436bd0
}
PCREG(436bd0, lifted_436bd0);

extern "C" u32 THISCALL lifted_41e750(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x663fdf);  // @h_41e750
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_41e750
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 78), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_41e750
  if (FL[0] == FL[1]) goto L41e87f;  // @2_41e750
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_41e750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_41e750
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775536), sizeof v); (u32)v; });  // @5_41e750
  if (FL[0] != FL[1]) goto L41e7db;  // @6_41e750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @7_41e750
  FL[2] = (ecx & ecx);  // @8_41e750
  if (FL[2] == 0) goto L41e7a3;  // @9_41e750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_41e750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(28));  // @11_41e750
  ecx = edx = 0;  // @12_41e750
  goto L41e7a8;  // @13_41e750
  L41e7a3:;
  eax = ((u32(*)(u32))(ebx))((u32)(28));  // @15_41e750
  ecx = edx = 0;  // @16_41e750
  L41e7a8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @18_41e750
  reg.state = (s32)((u32)(0));  // @19_41e750
  FL[2] = (eax & eax);  // @20_41e750
  if (FL[2] == 0) goto L41e7cd;  // @21_41e750
  ecx = eax;  // @22_41e750
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(4));  // @23_41e750
  ecx = edx = 0;  // @24_41e750
  reg.state = (s32)((u32)(4294967295));  // @25_41e750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @26_41e750
  goto L41e7e1;  // @27_41e750
  L41e7cd:;
  eax = 0;  // @29_41e750
  FL[3] = eax;  // @30_41e750
  reg.state = (s32)((u32)(4294967295));  // @31_41e750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @32_41e750
  goto L41e7e1;  // @33_41e750
  L41e7db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_41e750
  PV[0] = (u32)(esi);  // @36_41e750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[0]);  // @37_41e750
  ecx = edx = 0;  // @38_41e750
  L41e7e1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @40_41e750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_41e750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @42_41e750
  ecx = edx = 0;  // @43_41e750
  edi = eax;  // @44_41e750
  ecx = esi;  // @45_41e750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @46_41e750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @47_41e750
  edx = (u32)(ecx + 1);  // @48_41e750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @49_41e750
  L41e800:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @51_41e750
  ecx = (ecx + 1);  // @52_41e750
  FL[3] = ecx;  // @53_41e750
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @54_41e750
  if (FL[2] != 0) goto L41e800;  // @55_41e750
  ecx = (ecx - edx);  // @56_41e750
  FL[3] = ecx;  // @57_41e750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @58_41e750
  ecx = (ecx + 1);  // @59_41e750
  FL[3] = ecx;  // @60_41e750
  FL[2] = (edx & edx);  // @61_41e750
  if (FL[2] == 0) goto L41e81e;  // @62_41e750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @63_41e750
  PV[1] = (u32)(ecx);  // @64_41e750
  ecx = edx;  // @65_41e750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[1]);  // @66_41e750
  ecx = edx = 0;  // @67_41e750
  goto L41e82a;  // @68_41e750
  L41e81e:;
  ecx = (ecx & (u32)(536870911));  // @70_41e750
  FL[3] = ecx;  // @71_41e750
  PV[2] = (u32)(ecx);  // @72_41e750
  eax = ((u32( *)(u32))(ebx))(PV[2]);  // @73_41e750
  ecx = edx = 0;  // @74_41e750
  L41e82a:;
  ecx = eax;  // @76_41e750
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @77_41e750
  ecx = (ecx - esi);  // @78_41e750
  FL[3] = ecx;  // @79_41e750
  L41e831:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @81_41e750
  esi = (u32)(esi + 1);  // @82_41e750
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @83_41e750
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @84_41e750
  if (FL[2] != 0) goto L41e831;  // @85_41e750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @86_41e750
  FL[2] = (ecx & ecx);  // @87_41e750
  if (FL[2] == 0) goto L41e854;  // @88_41e750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_41e750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(200));  // @90_41e750
  ecx = edx = 0;  // @91_41e750
  goto L41e859;  // @92_41e750
  L41e854:;
  eax = ((u32(*)(u32))(ebx))((u32)(200));  // @94_41e750
  ecx = edx = 0;  // @95_41e750
  L41e859:;
  PV[3] = (u32)(eax);  // @97_41e750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @98_41e750
  eax = ext_634d10_cdecl3(PV[3], (u32)(0), (u32)(200));  // @99_41e750
  ecx = edx = 0;  // @100_41e750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @101_41e750
  eax = (u32)(1374389535);  // @102_41e750
  ecx = (u32)(ecx + 49);  // @103_41e750
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @104_41e750
  edx = (edx >> (u32)(4));  // @105_41e750
  FL[3] = edx;  // @106_41e750
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @107_41e750
  L41e87f:;
  SEH_LEAVE();  // @109_41e750
  return eax;  // @110_41e750
}
PCREG(41e750, lifted_41e750);

extern "C" u32 THISCALL lifted_498430(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668201);  // @h_498430
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_498430
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_498430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_498430
  ecx = esi;  // @3_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_498430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(6));  // @5_498430
  ecx = edx = 0;  // @6_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @7_498430
  ecx = (u32)(EBP - 20);  // @8_498430
  PV[0] = (u32)(ecx);  // @9_498430
  ecx = esi;  // @10_498430
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @11_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_498430
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @13_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[0], (u32)(4));  // @14_498430
  ecx = edx = 0;  // @15_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @16_498430
  FL[0] = eax; FL[1] = (u32)(-1);  // @17_498430
  if (FL[0] == FL[1]) goto L498638;  // @18_498430
  L498490:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @20_498430
  edi = (u32)((s32)eax * (s32)(u32)(112));  // @21_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @22_498430
  ebx = (ebx + edi);  // @23_498430
  FL[3] = ebx;  // @24_498430
  PV[1] = (u32)(edi);  // @25_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_498430
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @27_498430
  eax = ext_4cda40_thiscall3(ecx, PV[1], (u32)(112));  // @28_498430
  ecx = edx = 0;  // @29_498430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @30_498430
  if (FL[2] != 0) goto L4984d2;  // @31_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @32_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(2316));  // @34_498430
  ecx = edx = 0;  // @35_498430
  PV[2] = (u32)(edi);  // @36_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @37_498430
  PV[3] = (u32)(eax);  // @38_498430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6874304), PV[2], (u32)(112));  // @39_498430
  ecx = edx = 0;  // @40_498430
  L4984d2:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @42_498430
  reg.state = (s32)((u32)(0));  // @43_498430
  FL[2] = (ebx & ebx);  // @44_498430
  if (FL[2] == 0) goto L4984e7;  // @45_498430
  ecx = ebx;  // @46_498430
  eax = ext_4d93e0_thiscall1(ecx);  // @47_498430
  ecx = edx = 0;  // @48_498430
  L4984e7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @50_498430
  reg.state = (s32)((u32)(4294967295));  // @51_498430
  FL[2] = (ecx & ecx);  // @52_498430
  if (FL[2] == 0) goto L49850b;  // @53_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_498430
  PV[4] = (u32)(edi);  // @55_498430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(6873924), PV[4], (u32)(112));  // @56_498430
  ecx = edx = 0;  // @57_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @58_498430
  L49850b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_498430
  PV[5] = (u32)(ebx);  // @61_498430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[5], (u32)(112), (u32)(11468975));  // @62_498430
  ecx = edx = 0;  // @63_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_498430
  ecx = (u32)(EBP - 28);  // @65_498430
  PV[6] = (u32)(ecx);  // @66_498430
  ecx = esi;  // @67_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[6], (u32)(4));  // @68_498430
  ecx = edx = 0;  // @69_498430
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 60), sizeof v); (u32)v; }) & (u32)(134217728));  // @70_498430
  if (FL[2] != 0) goto L49856f;  // @71_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @72_498430
  ecx = ebx;  // @73_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @74_498430
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @75_498430
  FL[3] = ecx;  // @76_498430
  eax = (u32)(2454267027);  // @77_498430
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @78_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @79_498430
  edx = (edx + ecx);  // @80_498430
  FL[3] = edx;  // @81_498430
  edx = (u32)((s32)edx >> (u32)(6));  // @82_498430
  FL[3] = edx;  // @83_498430
  edi = edx;  // @84_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @85_498430
  eax = (u32)(613566757);  // @86_498430
  edi = (edi >> (u32)(31));  // @87_498430
  FL[3] = edi;  // @88_498430
  edi = (edi + edx);  // @89_498430
  FL[3] = edi;  // @90_498430
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @91_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @92_498430
  ecx = (ecx - edx);  // @93_498430
  FL[3] = ecx;  // @94_498430
  ecx = (ecx >> (u32)(1));  // @95_498430
  FL[3] = ecx;  // @96_498430
  ecx = (ecx + edx);  // @97_498430
  FL[3] = ecx;  // @98_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 93), sizeof v); (u32)v; });  // @99_498430
  ecx = (ecx >> (u32)(6));  // @100_498430
  FL[3] = ecx;  // @101_498430
  edi = (edi - ecx);  // @102_498430
  FL[3] = edi;  // @103_498430
  ecx = (u32)(eax + edi*4);  // @104_498430
  goto L498571;  // @105_498430
  L49856f:;
  ecx = 0;  // @107_498430
  FL[3] = ecx;  // @108_498430
  L498571:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @110_498430
  edi = 0;  // @111_498430
  FL[3] = edi;  // @112_498430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @113_498430
  ecx = (u32)(EBP - 24);  // @114_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_498430
  PV[7] = (u32)(ecx);  // @116_498430
  ecx = esi;  // @117_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[7], (u32)(4));  // @118_498430
  ecx = edx = 0;  // @119_498430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(-1);  // @120_498430
  if (FL[0] == FL[1]) goto L4985a5;  // @121_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @122_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @123_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_498430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 380)))(ecx);  // @125_498430
  ecx = edx = 0;  // @126_498430
  edi = eax;  // @127_498430
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @128_498430
  FL[3] = edi;  // @129_498430
  goto L4985ca;  // @130_498430
  L4985a5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_498430
  ecx = (u32)(EBP + 8);  // @133_498430
  PV[8] = (u32)(ecx);  // @134_498430
  ecx = esi;  // @135_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[8], (u32)(2));  // @136_498430
  ecx = edx = 0;  // @137_498430
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @138_498430
  ecx = esi;  // @139_498430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_498430
  PV[9] = (u32)(eax);  // @141_498430
  eax = (u32)(EBP - 32);  // @142_498430
  PV[10] = (u32)(eax);  // @143_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[10], PV[9]);  // @144_498430
  ecx = edx = 0;  // @145_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @146_498430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = edi;  // @147_498430
  if (FL[0] != FL[1]) edi = eax;  // @148_498430
  L4985ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @150_498430
  ecx = (u32)(EBP - 36);  // @151_498430
  PV[11] = (u32)(ecx);  // @152_498430
  ecx = esi;  // @153_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[11], (u32)(4));  // @154_498430
  ecx = edx = 0;  // @155_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @156_498430
  PV[12] = (u32)(ebx);  // @157_498430
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @158_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_498430
  PV[14] = (u32)(edi);  // @160_498430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[14], PV[13], PV[12]);  // @161_498430
  ecx = edx = 0;  // @162_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @163_498430
  ecx = (u32)(EBP - 40);  // @164_498430
  PV[15] = (u32)(ecx);  // @165_498430
  ecx = esi;  // @166_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[15], (u32)(4));  // @167_498430
  ecx = edx = 0;  // @168_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @169_498430
  FL[0] = ecx; FL[1] = (u32)(-1);  // @170_498430
  if (FL[0] == FL[1]) goto L49861c;  // @171_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @172_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @173_498430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7261), sizeof v); (u32)v; });  // @174_498430
  edi = (edi + ecx);  // @175_498430
  FL[3] = edi;  // @176_498430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @177_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_498430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @179_498430
  ecx = edx = 0;  // @180_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @181_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @182_498430
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @183_498430
  L49861c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @185_498430
  ecx = (u32)(EBP - 20);  // @186_498430
  PV[16] = (u32)(ecx);  // @187_498430
  ecx = esi;  // @188_498430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[16], (u32)(4));  // @189_498430
  ecx = edx = 0;  // @190_498430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @191_498430
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @192_498430
  FL[0] = eax; FL[1] = (u32)(-1);  // @193_498430
  if (FL[0] != FL[1]) goto L498490;  // @194_498430
  L498638:;
  SEH_LEAVE();  // @196_498430
  return eax;  // @197_498430
}
PCREG(498430, lifted_498430);

extern "C" u32 THISCALL lifted_4a85a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4a85a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @1_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @2_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4a85a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @4_4a85a0
  ecx = edx = 0;  // @5_4a85a0
  FL[0] = eax; FL[1] = (u32)(1);  // @6_4a85a0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4a86a1;  // @7_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @8_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @9_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4a85a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @11_4a85a0
  ecx = edx = 0;  // @12_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @13_4a85a0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 78), sizeof v); (u32)v; }));  // @14_4a85a0
  FL[3] = eax;  // @15_4a85a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @17_4a85a0
  esi = (u32)(eax + ebx);  // @18_4a85a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4a85a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 20)))(ecx);  // @20_4a85a0
  ecx = edx = 0;  // @21_4a85a0
  ecx = eax;  // @22_4a85a0
  eax = esi;  // @23_4a85a0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @24_4a85a0
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @25_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @26_4a85a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 78), &v, sizeof v); }  // @27_4a85a0
  PV[0] = (u32)(edx);  // @28_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @29_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4a85a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[0]);  // @31_4a85a0
  ecx = edx = 0;  // @32_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4a85a0
  PV[1] = (u32)(eax);  // @34_4a85a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @35_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @36_4a85a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4a85a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[1]);  // @38_4a85a0
  ecx = edx = 0;  // @39_4a85a0
  esi = eax;  // @40_4a85a0
  FL[2] = (esi & esi);  // @41_4a85a0
  if (FL[2] != 0) goto L4a8652;  // @42_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @43_4a85a0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @44_4a85a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @45_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4a85a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[2]);  // @47_4a85a0
  ecx = edx = 0;  // @48_4a85a0
  PV[3] = (u32)(ebx);  // @49_4a85a0
  ecx = edi;  // @50_4a85a0
  eax = ext_4a85a0_thiscall2(ecx, PV[3]);  // @51_4a85a0
  ecx = edx = 0;  // @52_4a85a0
  goto L4a86a1;  // @53_4a85a0
  L4a8652:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @55_4a85a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4a85a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6881864), (u32)(85));  // @57_4a85a0
  ecx = edx = 0;  // @58_4a85a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_4a85a0
  edi = eax;  // @60_4a85a0
  eax = (u32)(EBP - 144);  // @61_4a85a0
  ecx = esi;  // @62_4a85a0
  PV[4] = (u32)(eax);  // @63_4a85a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[4], (u32)(1));  // @64_4a85a0
  ecx = edx = 0;  // @65_4a85a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_4a85a0
  ecx = eax;  // @67_4a85a0
  reg.state = (s32)((u32)(0));  // @68_4a85a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @69_4a85a0
  ecx = edx = 0;  // @70_4a85a0
  PV[5] = (u32)(eax);  // @71_4a85a0
  PV[6] = (u32)(edi);  // @72_4a85a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[6], (u32)(6881944), PV[5]);  // @73_4a85a0
  ecx = edx = 0;  // @74_4a85a0
  ecx = (u32)(EBP - 144);  // @75_4a85a0
  eax = ext_4cbec0_thiscall1(ecx);  // @76_4a85a0
  ecx = edx = 0;  // @77_4a85a0
  L4a86a1:;
  SEH_LEAVE();  // @79_4a85a0
  ext_633654(G(u32, 0x6f5630));  // @80_4a85a0
  return eax;  // @81_4a85a0
}
PCREG(4a85a0, lifted_4a85a0);

extern "C" u32 THISCALL lifted_42e6f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6650ba);  // @h_42e6f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7017), sizeof v); (u32)v; });  // @1_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3_42e6f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_42e6f0
  if (FL[0] == FL[1]) goto L42e788;  // @5_42e6f0
  L42e730:;
  edx = esi;  // @7_42e6f0
  ecx = (u32)(EBP - 76);  // @8_42e6f0
  eax = ext_42ae00_fastcall3(ecx, edx, (u32)(6777860));  // @9_42e6f0
  ecx = edx = 0;  // @10_42e6f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @11_42e6f0
  ecx = ebx;  // @12_42e6f0
  reg.state = (s32)((u32)(0));  // @13_42e6f0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_42e6f0
  eax = ext_5f2c60_thiscall3(ecx, PV[1], PV[0]);  // @15_42e6f0
  ecx = edx = 0;  // @16_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @17_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @18_42e6f0
  eax = (eax - ecx);  // @19_42e6f0
  FL[3] = eax;  // @20_42e6f0
  reg.state = (s32)((u32)(1));  // @21_42e6f0
  FL[2] = (ecx & ecx);  // @22_42e6f0
  if (FL[2] == 0) goto L42e773;  // @23_42e6f0
  FL[2] = (eax & eax);  // @24_42e6f0
  if (FL[2] == 0) goto L42e773;  // @25_42e6f0
  PV[2] = (u32)(eax);  // @26_42e6f0
  PV[3] = (u32)(ecx);  // @27_42e6f0
  ecx = (u32)(EBP - 76);  // @28_42e6f0
  eax = ext_54f870_stdcall2(PV[3], PV[2]);  // @29_42e6f0
  ecx = edx = 0;  // @30_42e6f0
  L42e773:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7017), sizeof v); (u32)v; });  // @32_42e6f0
  esi = (esi + (u32)(12));  // @33_42e6f0
  FL[3] = esi;  // @34_42e6f0
  reg.state = (s32)((u32)(4294967295));  // @35_42e6f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @36_42e6f0
  if (FL[0] != FL[1]) goto L42e730;  // @37_42e6f0
  L42e788:;
  ecx = (u32)(EBP - 52);  // @39_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @40_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @41_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @42_42e6f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @43_42e6f0
  ecx = edx = 0;  // @44_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @45_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @46_42e6f0
  ecx = (u32)(eax + 8);  // @47_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @48_42e6f0
  FL[2] = (eax & eax);  // @49_42e6f0
  if (FL[2] == 0) goto L42e7ba;  // @50_42e6f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @51_42e6f0
  L42e7ba:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @53_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @54_42e6f0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @55_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @56_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @57_42e6f0
  edx = ecx;  // @58_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @59_42e6f0
  PV[5] = (u32)(eax);  // @60_42e6f0
  reg.state = (s32)((u32)(2));  // @61_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @62_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @63_42e6f0
  eax = ext_42aee0_fastcall5(ecx, edx, PV[5], PV[4], (u32)(0));  // @64_42e6f0
  ecx = edx = 0;  // @65_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @66_42e6f0
  esi = eax;  // @67_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @68_42e6f0
  FL[0] = esi; FL[1] = eax;  // @69_42e6f0
  if (FL[0] == FL[1]) goto L42e820;  // @70_42e6f0
  ebx = eax;  // @71_42e6f0
  L42e7f3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @74_42e6f0
  eax = (eax - ecx);  // @75_42e6f0
  FL[3] = eax;  // @76_42e6f0
  reg.state = (s32)((u32)(3));  // @77_42e6f0
  FL[2] = (ecx & ecx);  // @78_42e6f0
  if (FL[2] == 0) goto L42e80f;  // @79_42e6f0
  FL[2] = (eax & eax);  // @80_42e6f0
  if (FL[2] == 0) goto L42e80f;  // @81_42e6f0
  PV[6] = (u32)(eax);  // @82_42e6f0
  PV[7] = (u32)(ecx);  // @83_42e6f0
  ecx = esi;  // @84_42e6f0
  eax = ext_54f870_stdcall2(PV[7], PV[6]);  // @85_42e6f0
  ecx = edx = 0;  // @86_42e6f0
  L42e80f:;
  esi = (esi + (u32)(12));  // @88_42e6f0
  FL[3] = esi;  // @89_42e6f0
  reg.state = (s32)((u32)(2));  // @90_42e6f0
  FL[0] = esi; FL[1] = ebx;  // @91_42e6f0
  if (FL[0] != FL[1]) goto L42e7f3;  // @92_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @93_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @94_42e6f0
  L42e820:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @96_42e6f0
  eax = (u32)(3579139413);  // @97_42e6f0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @98_42e6f0
  FL[3] = edx;  // @99_42e6f0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @100_42e6f0
  edx = (u32)((s32)edx >> (u32)(1));  // @101_42e6f0
  FL[3] = edx;  // @102_42e6f0
  eax = edx;  // @103_42e6f0
  eax = (eax >> (u32)(31));  // @104_42e6f0
  FL[3] = eax;  // @105_42e6f0
  eax = (eax + edx);  // @106_42e6f0
  FL[3] = eax;  // @107_42e6f0
  eax = (u32)(eax + eax*2);  // @108_42e6f0
  eax = (eax << (u32)(2));  // @109_42e6f0
  FL[3] = eax;  // @110_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @111_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @112_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @113_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @114_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @115_42e6f0
  if (FL[0] == FL[1]) goto L42e9c0;  // @116_42e6f0
  L42e850:;
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @118_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @119_42e6f0
  ecx = (u32)(EBP - 20);  // @120_42e6f0
  PV[9] = (u32)(ecx);  // @121_42e6f0
  ecx = (u32)(EBP - 52);  // @122_42e6f0
  PV[10] = (u32)(ecx);  // @123_42e6f0
  ecx = edi;  // @124_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[10], PV[9], PV[8]);  // @125_42e6f0
  ecx = edx = 0;  // @126_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @127_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @128_42e6f0
  FL[0] = ecx; FL[1] = edx;  // @129_42e6f0
  if (FL[0] == FL[1]) goto L42e9b4;  // @130_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @131_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @133_42e6f0
  if (FL[0] == FL[1]) goto L42e8b0;  // @134_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @135_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 12), sizeof v); (u32)v; });  // @136_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 8), sizeof v); (u32)v; });  // @137_42e6f0
  eax = (eax - ebx);  // @138_42e6f0
  FL[3] = eax;  // @139_42e6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @140_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @141_42e6f0
  FL[0] = eax; FL[1] = (u32)(1);  // @142_42e6f0
  if (FL[0] != FL[1]) goto L42e8b0;  // @143_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @144_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @145_42e6f0
  if (FL[0] != FL[1]) goto L42e8b0;  // @146_42e6f0
  eax = edx;  // @147_42e6f0
  eax = (eax - ecx);  // @148_42e6f0
  FL[3] = eax;  // @149_42e6f0
  FL[0] = eax; FL[1] = (u32)(1);  // @150_42e6f0
  if (FL[0] != FL[1]) goto L42e8b0;  // @151_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @152_42e6f0
  if (FL[0] == FL[1]) goto L42e9b4;  // @153_42e6f0
  L42e8b0:;
  edx = (edx - ecx);  // @155_42e6f0
  FL[3] = edx;  // @156_42e6f0
  FL[0] = edx; FL[1] = (u32)(1);  // @157_42e6f0
  if (FL[0] != FL[1]) goto L42e908;  // @158_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(36);  // @159_42e6f0
  if (FL[0] != FL[1]) goto L42e908;  // @160_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @161_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @162_42e6f0
  if (FL[0] == FL[1]) goto L42e8e7;  // @163_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @164_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @165_42e6f0
  reg.state = (s32)((u32)(4));  // @166_42e6f0
  FL[2] = (eax & eax);  // @167_42e6f0
  if (FL[2] == 0) goto L42e8dd;  // @168_42e6f0
  ecx = (u32)(EBP - 52);  // @169_42e6f0
  PV[11] = (u32)(ecx);  // @170_42e6f0
  ecx = eax;  // @171_42e6f0
  eax = ext_5f10c0_thiscall2(ecx, PV[11]);  // @172_42e6f0
  ecx = edx = 0;  // @173_42e6f0
  L42e8dd:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @175_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @176_42e6f0
  reg.state = (s32)((u32)(2));  // @177_42e6f0
  goto L42e8f3;  // @178_42e6f0
  L42e8e7:;
  ecx = (u32)(EBP - 52);  // @180_42e6f0
  PV[12] = (u32)(ecx);  // @181_42e6f0
  PV[13] = (u32)(eax);  // @182_42e6f0
  ecx = esi;  // @183_42e6f0
  eax = ext_4302d0_thiscall3(ecx, PV[13], PV[12]);  // @184_42e6f0
  ecx = edx = 0;  // @185_42e6f0
  L42e8f3:;
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @187_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @188_42e6f0
  ecx = (u32)(EBP - 20);  // @189_42e6f0
  PV[15] = (u32)(ecx);  // @190_42e6f0
  ecx = (u32)(EBP - 52);  // @191_42e6f0
  PV[16] = (u32)(ecx);  // @192_42e6f0
  ecx = edi;  // @193_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[16], PV[15], PV[14]);  // @194_42e6f0
  ecx = edx = 0;  // @195_42e6f0
  L42e908:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @197_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @198_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @199_42e6f0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @200_42e6f0
  if (FL[0] == FL[1]) goto L42e9a5;  // @201_42e6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @202_42e6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @203_42e6f0
  FL[2] = (ebx & ebx);  // @204_42e6f0
  if (FL[2] == 0) goto L42e99b;  // @205_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @206_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @207_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @208_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @209_42e6f0
  esi = edx;  // @210_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @211_42e6f0
  esi = (esi - ecx);  // @212_42e6f0
  FL[3] = esi;  // @213_42e6f0
  esi = (esi + 1);  // @214_42e6f0
  FL[3] = esi;  // @215_42e6f0
  reg.state = (s32)((u32)(6));  // @216_42e6f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @217_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @218_42e6f0
  FL[0] = esi; FL[1] = (u32)(-2);  // @219_42e6f0
  if (FL[0] > FL[1]) goto L42e975;  // @220_42e6f0
  FL[2] = (esi & esi);  // @221_42e6f0
  if (FL[2] != 0) goto L42e95d;  // @222_42e6f0
  eax = 0;  // @223_42e6f0
  FL[3] = eax;  // @224_42e6f0
  goto L42e96b;  // @225_42e6f0
  L42e95d:;
  PV[17] = (u32)(esi);  // @227_42e6f0
  ecx = ebx;  // @228_42e6f0
  eax = ext_6014a0_stdcall1(PV[17]);  // @229_42e6f0
  ecx = edx = 0;  // @230_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @231_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @232_42e6f0
  L42e96b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @234_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @235_42e6f0
  eax = (eax + esi);  // @236_42e6f0
  FL[3] = eax;  // @237_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @238_42e6f0
  L42e975:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @240_42e6f0
  edx = (edx - ecx);  // @241_42e6f0
  FL[3] = edx;  // @242_42e6f0
  PV[18] = (u32)(edx);  // @243_42e6f0
  PV[19] = (u32)(ecx);  // @244_42e6f0
  PV[20] = (u32)(esi);  // @245_42e6f0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))(PV[20], PV[19], PV[18]);  // @246_42e6f0
  ecx = edx = 0;  // @247_42e6f0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @248_42e6f0
  FL[3] = esi;  // @249_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @250_42e6f0
  eax = (eax + esi);  // @251_42e6f0
  FL[3] = eax;  // @252_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @253_42e6f0
  if (FL[3] == 0) goto L42e995;  // @254_42e6f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @255_42e6f0
  L42e995:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @257_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @258_42e6f0
  L42e99b:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @260_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @261_42e6f0
  reg.state = (s32)((u32)(2));  // @262_42e6f0
  goto L42e9b1;  // @263_42e6f0
  L42e9a5:;
  ecx = (u32)(EBP - 52);  // @265_42e6f0
  PV[21] = (u32)(ecx);  // @266_42e6f0
  PV[22] = (u32)(ebx);  // @267_42e6f0
  ecx = eax;  // @268_42e6f0
  eax = ext_4302d0_thiscall3(ecx, PV[22], PV[21]);  // @269_42e6f0
  ecx = edx = 0;  // @270_42e6f0
  L42e9b1:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @272_42e6f0
  L42e9b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @274_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = eax;  // @275_42e6f0
  if (FL[0] != FL[1]) goto L42e850;  // @276_42e6f0
  L42e9c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7009), sizeof v); (u32)v; });  // @278_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @279_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @280_42e6f0
  edx = esi;  // @281_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @282_42e6f0
  edx = (edx - esi);  // @283_42e6f0
  FL[3] = edx;  // @284_42e6f0
  edx = (u32)((s32)edx >> (u32)(2));  // @285_42e6f0
  FL[3] = edx;  // @286_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @287_42e6f0
  FL[2] = (edx & edx);  // @288_42e6f0
  if ((s32)FL[2] <= 0) goto L42e9f4;  // @289_42e6f0
  ebx = esi;  // @290_42e6f0
  ebx = (ebx - ecx);  // @291_42e6f0
  FL[3] = ebx;  // @292_42e6f0
  L42e9e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx), sizeof v); (u32)v; });  // @294_42e6f0
  ecx = (u32)(ecx + 4);  // @295_42e6f0
  edx = (edx - 1);  // @296_42e6f0
  FL[3] = edx;  // @297_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @298_42e6f0
  FL[2] = (edx & edx);  // @299_42e6f0
  if ((s32)FL[2] > 0) goto L42e9e0;  // @300_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @301_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @302_42e6f0
  L42e9f4:;
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @304_42e6f0
  FL[3] = esi;  // @305_42e6f0
  esi = (u32)((s32)esi >> (u32)(2));  // @306_42e6f0
  FL[3] = esi;  // @307_42e6f0
  esi = (0u - esi);  // @308_42e6f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @309_42e6f0
  esi = (esi << (u32)(2));  // @310_42e6f0
  FL[3] = esi;  // @311_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @312_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @313_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7009), sizeof v); (u32)v; });  // @314_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @315_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @316_42e6f0
  if (FL[0] == FL[1]) goto L42ea27;  // @317_42e6f0
  FL[2] = (eax & eax);  // @318_42e6f0
  if (FL[2] == 0) goto L42ea21;  // @319_42e6f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @320_42e6f0
  L42ea21:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @322_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @323_42e6f0
  goto L42ea31;  // @324_42e6f0
  L42ea27:;
  edx = (u32)(EBP - 36);  // @326_42e6f0
  PV[23] = (u32)(edx);  // @327_42e6f0
  PV[24] = (u32)(eax);  // @328_42e6f0
  eax = ext_4301c0_thiscall3(ecx, PV[24], PV[23]);  // @329_42e6f0
  ecx = edx = 0;  // @330_42e6f0
  L42ea31:;
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @332_42e6f0
  eax = ext_634d22_cdecl3(PV[25], (u32)(6781786), (u32)(0));  // @333_42e6f0
  ecx = edx = 0;  // @334_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @335_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @336_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @337_42e6f0
  FL[0] = ecx; FL[1] = esi;  // @338_42e6f0
  if (FL[0] == FL[1]) goto L42ea67;  // @339_42e6f0
  eax = esi;  // @340_42e6f0
  eax = (eax - esi);  // @341_42e6f0
  FL[3] = eax;  // @342_42e6f0
  eax = (eax + 1);  // @343_42e6f0
  FL[3] = eax;  // @344_42e6f0
  PV[26] = (u32)(eax);  // @345_42e6f0
  PV[27] = (u32)(esi);  // @346_42e6f0
  PV[28] = (u32)(ecx);  // @347_42e6f0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676278))(PV[28], PV[27], PV[26]);  // @348_42e6f0
  ecx = edx = 0;  // @349_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @350_42e6f0
  eax = (eax - esi);  // @351_42e6f0
  FL[3] = eax;  // @352_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @353_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @354_42e6f0
  L42ea67:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @356_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @357_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @358_42e6f0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @359_42e6f0
  if (FL[0] == FL[1]) goto L42ebe9;  // @360_42e6f0
  L42ea80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @362_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @363_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @364_42e6f0
  ebx = (ebx - esi);  // @365_42e6f0
  FL[3] = ebx;  // @366_42e6f0
  FL[0] = ebx; FL[1] = (u32)(6);  // @367_42e6f0
  if (FL[0] != FL[1]) goto L42eab2;  // @368_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1684433187);  // @369_42e6f0
  if (FL[0] != FL[1]) goto L42eab2;  // @370_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(26213);  // @371_42e6f0
  if (FL[0] != FL[1]) goto L42eab2;  // @372_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @373_42e6f0
  ecx = (u32)(EBP - 16);  // @374_42e6f0
  PV[29] = (u32)(ecx);  // @375_42e6f0
  ecx = edi;  // @376_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[29]);  // @377_42e6f0
  ecx = edx = 0;  // @378_42e6f0
  goto L42ebd4;  // @379_42e6f0
  L42eab2:;
  FL[0] = ebx; FL[1] = (u32)(7);  // @381_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @382_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1852205347);  // @383_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @384_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(25956);  // @385_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @386_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; }); FL[1] = (u32)(102);  // @387_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @388_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @389_42e6f0
  ecx = (u32)(EBP - 16);  // @390_42e6f0
  PV[30] = (u32)(ecx);  // @391_42e6f0
  ecx = edi;  // @392_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[30]);  // @393_42e6f0
  ecx = edx = 0;  // @394_42e6f0
  goto L42ebd4;  // @395_42e6f0
  L42eae0:;
  FL[0] = ebx; FL[1] = (u32)(5);  // @397_42e6f0
  if (FL[0] != FL[1]) goto L42eb06;  // @398_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1936483619);  // @399_42e6f0
  if (FL[0] != FL[1]) goto L42eb06;  // @400_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(101);  // @401_42e6f0
  if (FL[0] != FL[1]) goto L42eb06;  // @402_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @403_42e6f0
  ecx = (u32)(EBP - 16);  // @404_42e6f0
  PV[31] = (u32)(ecx);  // @405_42e6f0
  ecx = edi;  // @406_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[31]);  // @407_42e6f0
  ecx = edx = 0;  // @408_42e6f0
  goto L42ebd4;  // @409_42e6f0
  L42eb06:;
  FL[0] = ebx; FL[1] = (u32)(6);  // @411_42e6f0
  if (FL[0] != FL[1]) goto L42eb2e;  // @412_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1684956451);  // @413_42e6f0
  if (FL[0] != FL[1]) goto L42eb2e;  // @414_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(26217);  // @415_42e6f0
  if (FL[0] != FL[1]) goto L42eb2e;  // @416_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @417_42e6f0
  ecx = (u32)(EBP - 16);  // @418_42e6f0
  PV[32] = (u32)(ecx);  // @419_42e6f0
  ecx = edi;  // @420_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, PV[32]);  // @421_42e6f0
  ecx = edx = 0;  // @422_42e6f0
  goto L42ebd4;  // @423_42e6f0
  L42eb2e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7009), sizeof v); (u32)v; });  // @425_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @426_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @427_42e6f0
  if (FL[0] == FL[1]) goto L42ebd0;  // @428_42e6f0
  FL[0] = ebx; FL[1] = (u32)(7);  // @429_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @430_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1717920803);  // @431_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @432_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(28265);  // @433_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @434_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; }); FL[1] = (u32)(101);  // @435_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @436_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @437_42e6f0
  ecx = (u32)(EBP - 16);  // @438_42e6f0
  PV[33] = (u32)(ecx);  // @439_42e6f0
  ecx = edi;  // @440_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, PV[33]);  // @441_42e6f0
  ecx = edx = 0;  // @442_42e6f0
  goto L42ebd4;  // @443_42e6f0
  L42eb6c:;
  FL[0] = ebx; FL[1] = (u32)(6);  // @445_42e6f0
  if (FL[0] != FL[1]) goto L42eb92;  // @446_42e6f0
  PV[34] = (u32)(ebx);  // @447_42e6f0
  edx = (u32)(6790772);  // @448_42e6f0
  ecx = esi;  // @449_42e6f0
  eax = ext_4309b0_stdcall1(PV[34]);  // @450_42e6f0
  ecx = edx = 0;  // @451_42e6f0
  FL[2] = (eax & eax);  // @452_42e6f0
  if (FL[2] != 0) goto L42eb92;  // @453_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @454_42e6f0
  ecx = (u32)(EBP - 16);  // @455_42e6f0
  PV[35] = (u32)(ecx);  // @456_42e6f0
  ecx = edi;  // @457_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 164)))(ecx, PV[35]);  // @458_42e6f0
  ecx = edx = 0;  // @459_42e6f0
  goto L42ebd4;  // @460_42e6f0
  L42eb92:;
  FL[0] = ebx; FL[1] = (u32)(1);  // @462_42e6f0
  if (FL[0] != FL[1]) goto L42ebbc;  // @463_42e6f0
  PV[36] = (u32)(ebx);  // @464_42e6f0
  edx = (u32)(6790768);  // @465_42e6f0
  ecx = esi;  // @466_42e6f0
  eax = ext_4309b0_stdcall1(PV[36]);  // @467_42e6f0
  ecx = edx = 0;  // @468_42e6f0
  FL[2] = (eax & eax);  // @469_42e6f0
  if (FL[2] != 0) goto L42ebbc;  // @470_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @471_42e6f0
  ecx = (u32)(EBP - 16);  // @472_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @473_42e6f0
  PV[37] = (u32)(ecx);  // @474_42e6f0
  PV[38] = (u32)(ebx);  // @475_42e6f0
  ecx = edi;  // @476_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 168)))(ecx, PV[38], PV[37]);  // @477_42e6f0
  ecx = edx = 0;  // @478_42e6f0
  goto L42ebd7;  // @479_42e6f0
  L42ebbc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @481_42e6f0
  ecx = (u32)(EBP - 16);  // @482_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @483_42e6f0
  PV[39] = (u32)(ecx);  // @484_42e6f0
  PV[40] = (u32)(ebx);  // @485_42e6f0
  ecx = edi;  // @486_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[40], PV[39]);  // @487_42e6f0
  ecx = edx = 0;  // @488_42e6f0
  goto L42ebd7;  // @489_42e6f0
  L42ebd0:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @491_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @492_42e6f0
  L42ebd4:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @494_42e6f0
  L42ebd7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @496_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @497_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = eax;  // @498_42e6f0
  if (FL[0] != FL[1]) goto L42ea80;  // @499_42e6f0
  L42ebe9:;
  eax = (u32)(EBP + 11);  // @501_42e6f0
  PV[41] = (u32)(eax);  // @502_42e6f0
  ecx = (u32)(EBP - 64);  // @503_42e6f0
  eax = ext_42b390_thiscall3(ecx, (u32)(6781896), PV[41]);  // @504_42e6f0
  ecx = edx = 0;  // @505_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @506_42e6f0
  eax = edx;  // @507_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @508_42e6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @509_42e6f0
  ecx = (ecx - edi);  // @510_42e6f0
  FL[3] = ecx;  // @511_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @512_42e6f0
  eax = (eax - esi);  // @513_42e6f0
  FL[3] = eax;  // @514_42e6f0
  reg.state = (s32)((u32)(7));  // @515_42e6f0
  FL[0] = ecx; FL[1] = eax;  // @516_42e6f0
  if (FL[0] > FL[1]) goto L42ecda;  // @517_42e6f0
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @518_42e6f0
  eax = (u32)(ecx + edi);  // @519_42e6f0
  ecx = esi;  // @520_42e6f0
  PV[43] = (u32)(eax);  // @521_42e6f0
  PV[44] = (u32)(edi);  // @522_42e6f0
  eax = ext_42b1e0_fastcall5(ecx, edx, PV[44], PV[43], PV[42]);  // @523_42e6f0
  ecx = edx = 0;  // @524_42e6f0
  esi = eax;  // @525_42e6f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @526_42e6f0
  if (FL[0] == FL[1]) goto L42ec31;  // @527_42e6f0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @528_42e6f0
  FL[3] = esi;  // @529_42e6f0
  goto L42ec34;  // @530_42e6f0
  L42ec31:;
  esi = (esi | (u32)(4294967295));  // @532_42e6f0
  FL[3] = esi;  // @533_42e6f0
  L42ec34:;
  FL[0] = esi; FL[1] = (u32)(-1);  // @535_42e6f0
  if (FL[0] == FL[1]) goto L42ecda;  // @536_42e6f0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @537_42e6f0
  L42ec44:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @539_42e6f0
  edi = (u32)(EBP - 36);  // @540_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @541_42e6f0
  eax = (u32)(EBP + 8);  // @542_42e6f0
  ecx = (ecx - edx);  // @543_42e6f0
  FL[3] = ecx;  // @544_42e6f0
  ecx = (ecx - esi);  // @545_42e6f0
  FL[3] = ecx;  // @546_42e6f0
  FL[0] = ecx; FL[1] = (u32)(2);  // @547_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @548_42e6f0
  ecx = (u32)(edx + esi);  // @549_42e6f0
  if (FL[0] >= FL[1]) eax = edi;  // @550_42e6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @551_42e6f0
  edi = (edi + edx);  // @552_42e6f0
  FL[3] = edi;  // @553_42e6f0
  edi = (edi + esi);  // @554_42e6f0
  FL[3] = edi;  // @555_42e6f0
  eax = edi;  // @556_42e6f0
  eax = (eax - ecx);  // @557_42e6f0
  FL[3] = eax;  // @558_42e6f0
  FL[0] = eax; FL[1] = (u32)(1);  // @559_42e6f0
  if ((s32)FL[0] < (s32)FL[1]) goto L42ec95;  // @560_42e6f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6777860), sizeof v); (u32)v; })) & 0xff);  // @561_42e6f0
  esi = (u32)(ecx + 1);  // @562_42e6f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @563_42e6f0
  FL[0] = esi; FL[1] = edi;  // @564_42e6f0
  if (FL[0] == FL[1]) goto L42ecbf;  // @565_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @566_42e6f0
  eax = (eax - edi);  // @567_42e6f0
  FL[3] = eax;  // @568_42e6f0
  eax = (eax + 1);  // @569_42e6f0
  FL[3] = eax;  // @570_42e6f0
  PV[45] = (u32)(eax);  // @571_42e6f0
  PV[46] = (u32)(edi);  // @572_42e6f0
  PV[47] = (u32)(esi);  // @573_42e6f0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))(PV[47], PV[46], PV[45]);  // @574_42e6f0
  ecx = edx = 0;  // @575_42e6f0
  esi = (esi - edi);  // @576_42e6f0
  FL[3] = esi;  // @577_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @578_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @579_42e6f0
  goto L42ecbf;  // @580_42e6f0
  L42ec95:;
  esi = (u32)(eax + 6777860);  // @582_42e6f0
  eax = esi;  // @583_42e6f0
  eax = (eax - (u32)(6777860));  // @584_42e6f0
  FL[3] = eax;  // @585_42e6f0
  PV[48] = (u32)(eax);  // @586_42e6f0
  PV[49] = (u32)(ecx);  // @587_42e6f0
  eax = ext_634d22_cdecl3(PV[49], (u32)(6777860), PV[48]);  // @588_42e6f0
  ecx = edx = 0;  // @589_42e6f0
  ecx = ebx;  // @590_42e6f0
  PV[50] = (u32)(esi);  // @591_42e6f0
  PV[51] = (u32)(edi);  // @592_42e6f0
  eax = ext_430d10_thiscall4(ecx, PV[51], PV[50], (u32)(6777861));  // @593_42e6f0
  ecx = edx = 0;  // @594_42e6f0
  L42ecbf:;
  eax = (u32)(EBP - 64);  // @596_42e6f0
  ecx = ebx;  // @597_42e6f0
  PV[52] = (u32)(eax);  // @598_42e6f0
  eax = ext_430c70_thiscall3(ecx, PV[52], (u32)(0));  // @599_42e6f0
  ecx = edx = 0;  // @600_42e6f0
  esi = eax;  // @601_42e6f0
  FL[0] = esi; FL[1] = (u32)(-1);  // @602_42e6f0
  if (FL[0] != FL[1]) goto L42ec44;  // @603_42e6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @604_42e6f0
  L42ecda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @606_42e6f0
  eax = (eax - edi);  // @607_42e6f0
  FL[3] = eax;  // @608_42e6f0
  reg.state = (s32)((u32)(8));  // @609_42e6f0
  FL[2] = (edi & edi);  // @610_42e6f0
  if (FL[2] == 0) goto L42ecf5;  // @611_42e6f0
  FL[2] = (eax & eax);  // @612_42e6f0
  if (FL[2] == 0) goto L42ecf5;  // @613_42e6f0
  PV[53] = (u32)(eax);  // @614_42e6f0
  PV[54] = (u32)(edi);  // @615_42e6f0
  ecx = (u32)(EBP - 64);  // @616_42e6f0
  eax = ext_54f870_stdcall2(PV[54], PV[53]);  // @617_42e6f0
  ecx = edx = 0;  // @618_42e6f0
  L42ecf5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @620_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @621_42e6f0
  eax = (eax - ecx);  // @622_42e6f0
  FL[3] = eax;  // @623_42e6f0
  reg.state = (s32)((u32)(9));  // @624_42e6f0
  FL[2] = (ecx & ecx);  // @625_42e6f0
  if (FL[2] == 0) goto L42ed16;  // @626_42e6f0
  FL[2] = (eax & eax);  // @627_42e6f0
  if (FL[2] == 0) goto L42ed16;  // @628_42e6f0
  PV[55] = (u32)(eax);  // @629_42e6f0
  PV[56] = (u32)(ecx);  // @630_42e6f0
  ecx = (u32)(EBP - 52);  // @631_42e6f0
  eax = ext_54f870_stdcall2(PV[56], PV[55]);  // @632_42e6f0
  ecx = edx = 0;  // @633_42e6f0
  L42ed16:;
  SEH_LEAVE();  // @635_42e6f0
  return eax;  // @636_42e6f0
}
PCREG(42e6f0, lifted_42e6f0);

extern "C" u32 THISCALL lifted_4d5150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6694c8);  // @h_4d5150
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4d5150
  eax = ext_41e290_cdecl1((u32)(4));  // @1_4d5150
  ecx = edx = 0;  // @2_4d5150
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4d5150
  edi = eax;  // @4_4d5150
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_4d5150
  eax = ((u32( *)(u32, u32))(*(u32 *)0x6763b0))(PV[1], PV[0]);  // @6_4d5150
  ecx = edx = 0;  // @7_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @8_4d5150
  FL[2] = (eax & eax);  // @9_4d5150
  if (FL[2] != 0) goto L4d51a2;  // @10_4d5150
  PV[2] = (u32)(edi);  // @11_4d5150
  eax = ext_634273_cdecl2(PV[2], (u32)(4));  // @12_4d5150
  ecx = edx = 0;  // @13_4d5150
  edi = 0;  // @14_4d5150
  FL[3] = edi;  // @15_4d5150
  L4d51a2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_4d5150
  FL[2] = (esi & esi);  // @18_4d5150
  if (FL[2] == 0) goto L4d52e4;  // @19_4d5150
  PV[3] = (u32)(esi);  // @20_4d5150
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6763e8))(PV[3], (u32)(0), (u32)(2));  // @21_4d5150
  ecx = edx = 0;  // @22_4d5150
  PV[4] = (u32)(esi);  // @23_4d5150
  reg.state = (s32)((u32)(0));  // @24_4d5150
  eax = ((u32( *)(u32))(*(u32 *)0x6763d8))(PV[4]);  // @25_4d5150
  ecx = edx = 0;  // @26_4d5150
  FL[2] = (eax & eax);  // @27_4d5150
  if (FL[2] == 0) goto L4d51da;  // @28_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @29_4d5150
  FL[2] = (eax & eax);  // @30_4d5150
  if (FL[2] == 0) goto L4d51d9;  // @31_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_4d5150
  ecx = edx = 0;  // @33_4d5150
  goto L4d51da;  // @34_4d5150
  L4d51d9:;
  __builtin_trap();  // @36_4d5150
  L4d51da:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_4d5150
  PV[5] = (u32)(esi);  // @39_4d5150
  eax = ((u32( *)(u32))(*(u32 *)0x6763f4))(PV[5]);  // @40_4d5150
  ecx = edx = 0;  // @41_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @42_4d5150
  PV[6] = (u32)(esi);  // @43_4d5150
  reg.state = (s32)((u32)(1));  // @44_4d5150
  eax = ((u32( *)(u32))(*(u32 *)0x6763d8))(PV[6]);  // @45_4d5150
  ecx = edx = 0;  // @46_4d5150
  FL[2] = (eax & eax);  // @47_4d5150
  if (FL[2] == 0) goto L4d520a;  // @48_4d5150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @49_4d5150
  FL[2] = (ecx & ecx);  // @50_4d5150
  if (FL[2] == 0) goto L4d5209;  // @51_4d5150
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @52_4d5150
  ecx = edx = 0;  // @53_4d5150
  goto L4d520a;  // @54_4d5150
  L4d5209:;
  __builtin_trap();  // @56_4d5150
  L4d520a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_4d5150
  PV[7] = (u32)(esi);  // @59_4d5150
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6763e8))(PV[7], (u32)(0), (u32)(0));  // @60_4d5150
  ecx = edx = 0;  // @61_4d5150
  PV[8] = (u32)(esi);  // @62_4d5150
  reg.state = (s32)((u32)(2));  // @63_4d5150
  eax = ((u32( *)(u32))(*(u32 *)0x6763d8))(PV[8]);  // @64_4d5150
  ecx = edx = 0;  // @65_4d5150
  FL[2] = (eax & eax);  // @66_4d5150
  if (FL[2] == 0) goto L4d523a;  // @67_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @68_4d5150
  FL[2] = (eax & eax);  // @69_4d5150
  if (FL[2] == 0) goto L4d5239;  // @70_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @71_4d5150
  ecx = edx = 0;  // @72_4d5150
  goto L4d523a;  // @73_4d5150
  L4d5239:;
  __builtin_trap();  // @75_4d5150
  L4d523a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @77_4d5150
  reg.state = (s32)((u32)(4294967295));  // @78_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_4d5150
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, (u32)(-1));  // @80_4d5150
  ecx = edx = 0;  // @81_4d5150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @82_4d5150
  PV[9] = (u32)(esi);  // @83_4d5150
  eax = ext_41e290_cdecl1(PV[9]);  // @84_4d5150
  ecx = edx = 0;  // @85_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @86_4d5150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @87_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_4d5150
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, (u32)(0));  // @89_4d5150
  ecx = edx = 0;  // @90_4d5150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @91_4d5150
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @92_4d5150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @93_4d5150
  PV[10] = (u32)(esi);  // @94_4d5150
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @95_4d5150
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @96_4d5150
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[12], (u32)(1), PV[11], PV[10]);  // @97_4d5150
  ecx = edx = 0;  // @98_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @99_4d5150
  PV[13] = (u32)(esi);  // @100_4d5150
  reg.state = (s32)((u32)(3));  // @101_4d5150
  eax = ((u32( *)(u32))(*(u32 *)0x6763d8))(PV[13]);  // @102_4d5150
  ecx = edx = 0;  // @103_4d5150
  FL[2] = (eax & eax);  // @104_4d5150
  if (FL[2] == 0) goto L4d52b2;  // @105_4d5150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @106_4d5150
  FL[2] = (ecx & ecx);  // @107_4d5150
  if (FL[2] == 0) goto L4d52b1;  // @108_4d5150
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @109_4d5150
  ecx = edx = 0;  // @110_4d5150
  goto L4d52b2;  // @111_4d5150
  L4d52b1:;
  __builtin_trap();  // @113_4d5150
  L4d52b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @115_4d5150
  reg.state = (s32)((u32)(4294967295));  // @116_4d5150
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @117_4d5150
  if (FL[0] == FL[1]) goto L4d52cf;  // @118_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @119_4d5150
  FL[2] = (eax & eax);  // @120_4d5150
  if (FL[2] == 0) goto L4d52ce;  // @121_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @122_4d5150
  ecx = edx = 0;  // @123_4d5150
  goto L4d52cf;  // @124_4d5150
  L4d52ce:;
  __builtin_trap();  // @126_4d5150
  L4d52cf:;
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @128_4d5150
  eax = ((u32( *)(u32))(*(u32 *)0x6763ac))(PV[14]);  // @129_4d5150
  ecx = edx = 0;  // @130_4d5150
  PV[15] = (u32)(edi);  // @131_4d5150
  eax = ext_634273_cdecl2(PV[15], (u32)(4));  // @132_4d5150
  ecx = edx = 0;  // @133_4d5150
  goto L4d52f2;  // @134_4d5150
  L4d52e4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @136_4d5150
  FL[2] = (eax & eax);  // @137_4d5150
  if (FL[2] == 0) goto L4d52f1;  // @138_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @139_4d5150
  ecx = edx = 0;  // @140_4d5150
  goto L4d52f2;  // @141_4d5150
  L4d52f1:;
  __builtin_trap();  // @143_4d5150
  L4d52f2:;
  eax = (u32)(ebx + 4);  // @145_4d5150
  SEH_LEAVE();  // @146_4d5150
  return eax;  // @147_4d5150
}
PCREG(4d5150, lifted_4d5150);

extern "C" u32 THISCALL lifted_48c4b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x667a8c);  // @h_48c4b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_48c4b0
  eax = (u32)(ecx + 3021);  // @1_48c4b0
  PV[0] = (u32)(eax);  // @2_48c4b0
  ecx = (u32)(EBP - 144);  // @3_48c4b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @4_48c4b0
  eax = ext_4cbe50_thiscall2(ecx, PV[0]);  // @5_48c4b0
  ecx = edx = 0;  // @6_48c4b0
  ecx = (u32)(EBP - 144);  // @7_48c4b0
  reg.state = (s32)((u32)(0));  // @8_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @9_48c4b0
  ecx = edx = 0;  // @10_48c4b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @11_48c4b0
  PV[1] = (u32)(eax);  // @12_48c4b0
  eax = ((u32( *)(u32, u32))(ebx))(PV[1], (u32)(92));  // @13_48c4b0
  ecx = edx = 0;  // @14_48c4b0
  edi = eax;  // @15_48c4b0
  FL[2] = (edi & edi);  // @16_48c4b0
  if (FL[2] != 0) goto L48c530;  // @17_48c4b0
  ecx = (u32)(EBP - 144);  // @18_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_48c4b0
  ecx = edx = 0;  // @20_48c4b0
  edi = eax;  // @21_48c4b0
  L48c530:;
  ecx = (u32)(EBP - 144);  // @23_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_48c4b0
  ecx = edx = 0;  // @25_48c4b0
  edx = (u32)(eax + 1);  // @26_48c4b0
  L48c540:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @28_48c4b0
  eax = (eax + 1);  // @29_48c4b0
  FL[3] = eax;  // @30_48c4b0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @31_48c4b0
  if (FL[2] != 0) goto L48c540;  // @32_48c4b0
  eax = (eax - edx);  // @33_48c4b0
  FL[3] = eax;  // @34_48c4b0
  if (FL[3] == 0) goto L48c590;  // @35_48c4b0
  PV[2] = (u32)(edi);  // @36_48c4b0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[2], (u32)(46));  // @37_48c4b0
  ecx = edx = 0;  // @38_48c4b0
  FL[2] = (eax & eax);  // @39_48c4b0
  if (FL[2] != 0) goto L48c590;  // @40_48c4b0
  ecx = (u32)(EBP - 272);  // @41_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6871072));  // @42_48c4b0
  ecx = edx = 0;  // @43_48c4b0
  eax = (u32)(EBP - 272);  // @44_48c4b0
  reg.state = (s32)((u32)(1));  // @45_48c4b0
  PV[3] = (u32)(eax);  // @46_48c4b0
  ecx = (u32)(EBP - 144);  // @47_48c4b0
  eax = ext_4cc2c0_thiscall2(ecx, PV[3]);  // @48_48c4b0
  ecx = edx = 0;  // @49_48c4b0
  ecx = (u32)(EBP - 272);  // @50_48c4b0
  reg.state = (s32)((u32)(0));  // @51_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @52_48c4b0
  ecx = edx = 0;  // @53_48c4b0
  L48c590:;
  ecx = (u32)(EBP - 144);  // @55_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @56_48c4b0
  ecx = edx = 0;  // @57_48c4b0
  edx = (u32)(6871072);  // @58_48c4b0
  ecx = eax;  // @59_48c4b0
  eax = ext_4cc780_fastcall2(ecx, edx);  // @60_48c4b0
  ecx = edx = 0;  // @61_48c4b0
  FL[2] = (eax & eax);  // @62_48c4b0
  if (FL[2] == 0) goto L48c660;  // @63_48c4b0
  ecx = (u32)(EBP - 144);  // @64_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_48c4b0
  ecx = edx = 0;  // @66_48c4b0
  edx = (u32)(6871080);  // @67_48c4b0
  ecx = eax;  // @68_48c4b0
  eax = ext_4cc780_fastcall2(ecx, edx);  // @69_48c4b0
  ecx = edx = 0;  // @70_48c4b0
  FL[2] = (eax & eax);  // @71_48c4b0
  if (FL[2] == 0) goto L48c5db;  // @72_48c4b0
  L48c5ca:;
  ecx = esi;  // @74_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @75_48c4b0
  ecx = edx = 0;  // @76_48c4b0
  goto L48c695;  // @77_48c4b0
  L48c5db:;
  ecx = (u32)(EBP - 144);  // @79_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @80_48c4b0
  ecx = edx = 0;  // @81_48c4b0
  PV[4] = (u32)(eax);  // @82_48c4b0
  eax = ((u32( *)(u32, u32))(ebx))(PV[4], (u32)(92));  // @83_48c4b0
  ecx = edx = 0;  // @84_48c4b0
  edi = eax;  // @85_48c4b0
  FL[2] = (edi & edi);  // @86_48c4b0
  if (FL[2] == 0) goto L48c5ca;  // @87_48c4b0
  eax = (u32)(edi + 1);  // @88_48c4b0
  PV[5] = (u32)(eax);  // @89_48c4b0
  ecx = (u32)(EBP - 400);  // @90_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, PV[5]);  // @91_48c4b0
  ecx = edx = 0;  // @92_48c4b0
  ecx = (u32)(EBP - 272);  // @93_48c4b0
  reg.state = (s32)((u32)(2));  // @94_48c4b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @95_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6870184));  // @96_48c4b0
  ecx = edx = 0;  // @97_48c4b0
  eax = (u32)(EBP - 272);  // @98_48c4b0
  reg.state = (s32)((u32)(3));  // @99_48c4b0
  PV[6] = (u32)(eax);  // @100_48c4b0
  ecx = (u32)(EBP - 144);  // @101_48c4b0
  eax = ext_4cc2c0_thiscall2(ecx, PV[6]);  // @102_48c4b0
  ecx = edx = 0;  // @103_48c4b0
  ecx = (u32)(EBP - 272);  // @104_48c4b0
  reg.state = (s32)((u32)(2));  // @105_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @106_48c4b0
  ecx = edx = 0;  // @107_48c4b0
  eax = (u32)(EBP - 400);  // @108_48c4b0
  PV[7] = (u32)(eax);  // @109_48c4b0
  ecx = (u32)(EBP - 144);  // @110_48c4b0
  eax = ext_4cc2c0_thiscall2(ecx, PV[7]);  // @111_48c4b0
  ecx = edx = 0;  // @112_48c4b0
  ecx = (u32)(EBP - 400);  // @113_48c4b0
  reg.state = (s32)((u32)(0));  // @114_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @115_48c4b0
  ecx = edx = 0;  // @116_48c4b0
  L48c660:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @118_48c4b0
  FL[2] = (edi & edi);  // @119_48c4b0
  if (FL[2] == 0) goto L48c687;  // @120_48c4b0
  ecx = (u32)(EBP - 144);  // @121_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @122_48c4b0
  ecx = edx = 0;  // @123_48c4b0
  PV[8] = (u32)(eax);  // @124_48c4b0
  eax = ((u32( *)(u32, u32))(ebx))(PV[8], (u32)(46));  // @125_48c4b0
  ecx = edx = 0;  // @126_48c4b0
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @127_48c4b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @128_48c4b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; })) & 0xff);  // @129_48c4b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 3), &v, sizeof v); }  // @130_48c4b0
  L48c687:;
  eax = (u32)(EBP - 144);  // @132_48c4b0
  ecx = esi;  // @133_48c4b0
  PV[9] = (u32)(eax);  // @134_48c4b0
  eax = ext_4cbe50_thiscall2(ecx, PV[9]);  // @135_48c4b0
  ecx = edx = 0;  // @136_48c4b0
  L48c695:;
  ecx = (u32)(EBP - 144);  // @138_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @139_48c4b0
  ecx = edx = 0;  // @140_48c4b0
  eax = esi;  // @141_48c4b0
  SEH_LEAVE();  // @142_48c4b0
  ext_633654(G(u32, 0x6f5630));  // @143_48c4b0
  return eax;  // @144_48c4b0
}
PCREG(48c4b0, lifted_48c4b0);

extern "C" u32 THISCALL lifted_4acf30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668781);  // @h_4acf30
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4acf30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @1_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4acf30
  PV[0] = (u32)(edx);  // @4_4acf30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @5_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @8_4acf30
  ecx = edx = 0;  // @9_4acf30
  ebx = eax;  // @10_4acf30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @11_4acf30
  FL[2] = (ebx & ebx);  // @12_4acf30
  if (FL[2] != 0) goto L4acfe8;  // @13_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(579));  // @16_4acf30
  ecx = edx = 0;  // @17_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @18_4acf30
  edx = (u32)(EBP - 144);  // @19_4acf30
  edi = eax;  // @20_4acf30
  PV[1] = (u32)(edx);  // @21_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @22_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[1], (u32)(1));  // @24_4acf30
  ecx = edx = 0;  // @25_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_4acf30
  ecx = eax;  // @27_4acf30
  reg.state = (s32)(ebx);  // @28_4acf30
  eax = ext_4cc1d0_thiscall1(ecx);  // @29_4acf30
  ecx = edx = 0;  // @30_4acf30
  PV[2] = (u32)(eax);  // @31_4acf30
  PV[3] = (u32)(edi);  // @32_4acf30
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[3], (u32)(6884216), PV[2]);  // @33_4acf30
  ecx = edx = 0;  // @34_4acf30
  ecx = (u32)(EBP - 144);  // @35_4acf30
  eax = ext_4cbec0_thiscall1(ecx);  // @36_4acf30
  ecx = edx = 0;  // @37_4acf30
  L4acfe1:;
  eax = 0;  // @39_4acf30
  FL[3] = eax;  // @40_4acf30
  goto L4ad375;  // @41_4acf30
  L4acfe8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @43_4acf30
  ecx = ebx;  // @44_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @45_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @46_4acf30
  ecx = edx = 0;  // @47_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @48_4acf30
  if (FL[2] != 0) goto L4ad0b7;  // @49_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_4acf30
  ecx = ebx;  // @51_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @52_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050579));  // @53_4acf30
  ecx = edx = 0;  // @54_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @55_4acf30
  if (FL[2] != 0) goto L4ad0b7;  // @56_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @57_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(584));  // @59_4acf30
  ecx = edx = 0;  // @60_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @61_4acf30
  edx = (u32)(EBP - 272);  // @62_4acf30
  edi = eax;  // @63_4acf30
  PV[4] = (u32)(edx);  // @64_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @65_4acf30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @66_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[4], (u32)(1));  // @68_4acf30
  ecx = edx = 0;  // @69_4acf30
  ebx = eax;  // @70_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @71_4acf30
  edx = (u32)(EBP - 144);  // @72_4acf30
  PV[5] = (u32)(edx);  // @73_4acf30
  reg.state = (s32)((u32)(1));  // @74_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[5], (u32)(1));  // @76_4acf30
  ecx = edx = 0;  // @77_4acf30
  esi = eax;  // @78_4acf30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_4acf30
  ecx = ebx;  // @80_4acf30
  reg.state = (s32)((u32)(2));  // @81_4acf30
  eax = ext_4cc1d0_thiscall1(ecx);  // @82_4acf30
  ecx = edx = 0;  // @83_4acf30
  PV[6] = (u32)(eax);  // @84_4acf30
  ecx = esi;  // @85_4acf30
  eax = ext_4cc1d0_thiscall1(ecx);  // @86_4acf30
  ecx = edx = 0;  // @87_4acf30
  PV[7] = (u32)(eax);  // @88_4acf30
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @89_4acf30
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[8], (u32)(6884272), PV[7], PV[6]);  // @90_4acf30
  ecx = edx = 0;  // @91_4acf30
  ecx = (u32)(EBP - 144);  // @92_4acf30
  eax = ext_4cbec0_thiscall1(ecx);  // @93_4acf30
  ecx = edx = 0;  // @94_4acf30
  ecx = (u32)(EBP - 272);  // @95_4acf30
  eax = ext_4cbec0_thiscall1(ecx);  // @96_4acf30
  ecx = edx = 0;  // @97_4acf30
  eax = 0;  // @98_4acf30
  FL[3] = eax;  // @99_4acf30
  goto L4ad375;  // @100_4acf30
  L4ad0b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_4acf30
  ecx = ebx;  // @103_4acf30
  esi = ebx;  // @104_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @105_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @106_4acf30
  ecx = edx = 0;  // @107_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @108_4acf30
  if (FL[2] == 0) goto L4ad0da;  // @109_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @110_4acf30
  ecx = ebx;  // @111_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @112_4acf30
  ecx = edx = 0;  // @113_4acf30
  esi = eax;  // @114_4acf30
  L4ad0da:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @116_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @118_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2149580820));  // @119_4acf30
  ecx = edx = 0;  // @120_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @121_4acf30
  if (FL[2] == 0) goto L4ad1d7;  // @122_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @123_4acf30
  ecx = (u32)(6801640);  // @124_4acf30
  FL[2] = (eax & eax);  // @125_4acf30
  if (FL[2] != 0) ecx = eax;  // @126_4acf30
  PV[9] = (u32)(ecx);  // @127_4acf30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))((u32)(6884340), PV[9]);  // @128_4acf30
  ecx = edx = 0;  // @129_4acf30
  FL[2] = (eax & eax);  // @130_4acf30
  if (FL[2] != 0) goto L4ad1d7;  // @131_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @132_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @133_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @135_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6884352), (u32)(0), (u32)(6883748), (u32)(594), (u32)(50), (u32)(0));  // @137_4acf30
  ecx = edx = 0;  // @138_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @139_4acf30
  eax = (eax & 0xffff);  // @140_4acf30
  PV[10] = (u32)(eax);  // @141_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[10]);  // @142_4acf30
  ecx = edx = 0;  // @143_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @144_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @145_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @147_4acf30
  ecx = edx = 0;  // @148_4acf30
  ecx = eax;  // @149_4acf30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @150_4acf30
  edx = (u32)(EBP - 288);  // @151_4acf30
  PV[11] = (u32)(edx);  // @152_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(6884372), PV[11]);  // @154_4acf30
  ecx = edx = 0;  // @155_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_4acf30
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @157_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @158_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[12]);  // @160_4acf30
  ecx = edx = 0;  // @161_4acf30
  ecx = eax;  // @162_4acf30
  FL[2] = (ecx & ecx);  // @163_4acf30
  if (FL[2] == 0) goto L4ad1ab;  // @164_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @166_4acf30
  ecx = edx = 0;  // @167_4acf30
  L4ad1ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @169_4acf30
  ecx = ebx;  // @170_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @171_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @172_4acf30
  ecx = edx = 0;  // @173_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @174_4acf30
  if (FL[2] == 0) goto L4acfe1;  // @175_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @176_4acf30
  ecx = ebx;  // @177_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @178_4acf30
  ecx = edx = 0;  // @179_4acf30
  eax = 0;  // @180_4acf30
  FL[3] = eax;  // @181_4acf30
  goto L4ad375;  // @182_4acf30
  L4ad1d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @184_4acf30
  ecx = ebx;  // @185_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @186_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050579));  // @187_4acf30
  ecx = edx = 0;  // @188_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @189_4acf30
  if (FL[2] == 0) goto L4ad2ca;  // @190_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @191_4acf30
  ecx = ebx;  // @192_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @193_4acf30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @194_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @195_4acf30
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @196_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @197_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 708)))(ecx, PV[13], (u32)(1230259533));  // @198_4acf30
  ecx = edx = 0;  // @199_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @200_4acf30
  PV[14] = (u32)(eax);  // @201_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @202_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[14]);  // @203_4acf30
  ecx = edx = 0;  // @204_4acf30
  edx = eax;  // @205_4acf30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @206_4acf30
  FL[2] = (edx & edx);  // @207_4acf30
  if (FL[2] == 0) goto L4acfe1;  // @208_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @209_4acf30
  PV[15] = (u32)(edx);  // @210_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @211_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @212_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[15]);  // @213_4acf30
  ecx = edx = 0;  // @214_4acf30
  ebx = eax;  // @215_4acf30
  ecx = ebx;  // @216_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @217_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @218_4acf30
  ecx = edx = 0;  // @219_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @220_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @221_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @222_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050581));  // @223_4acf30
  ecx = edx = 0;  // @224_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @225_4acf30
  if (FL[2] == 0) goto L4ad28d;  // @226_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @227_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @228_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 796)))(ecx);  // @230_4acf30
  ecx = edx = 0;  // @231_4acf30
  PV[16] = (u32)(eax);  // @232_4acf30
  ecx = ebx;  // @233_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 808)))(ecx, PV[16]);  // @234_4acf30
  ecx = edx = 0;  // @235_4acf30
  goto L4ad2ca;  // @236_4acf30
  L4ad28d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @238_4acf30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @239_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @240_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @241_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @242_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @243_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(0));  // @244_4acf30
  ecx = edx = 0;  // @245_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @246_4acf30
  PV[17] = (u32)(eax);  // @247_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @248_4acf30
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @249_4acf30
  ecx = esi;  // @250_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[18], PV[17]);  // @251_4acf30
  ecx = edx = 0;  // @252_4acf30
  PV[19] = (u32)(eax);  // @253_4acf30
  ecx = ebx;  // @254_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[19]);  // @255_4acf30
  ecx = edx = 0;  // @256_4acf30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @257_4acf30
  L4ad2ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @259_4acf30
  ecx = ebx;  // @260_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @261_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050584));  // @262_4acf30
  ecx = edx = 0;  // @263_4acf30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @264_4acf30
  if (FL[2] == 0) goto L4ad333;  // @265_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @266_4acf30
  ecx = ebx;  // @267_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @268_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 744)))(ecx, (u32)(0));  // @269_4acf30
  ecx = edx = 0;  // @270_4acf30
  PV[20] = (u32)(eax);  // @271_4acf30
  ecx = edi;  // @272_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 152)))(ecx, PV[20]);  // @273_4acf30
  ecx = edx = 0;  // @274_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @275_4acf30
  PV[21] = (u32)(eax);  // @276_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @277_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @278_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[21]);  // @279_4acf30
  ecx = edx = 0;  // @280_4acf30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @281_4acf30
  FL[2] = (eax & eax);  // @282_4acf30
  if (FL[2] == 0) goto L4ad333;  // @283_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @284_4acf30
  ecx = ebx;  // @285_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @286_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 800)))(ecx);  // @287_4acf30
  ecx = edx = 0;  // @288_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @289_4acf30
  PV[22] = (u32)(eax);  // @290_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 808)))(ecx, PV[22]);  // @291_4acf30
  ecx = edx = 0;  // @292_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @293_4acf30
  goto L4ad375;  // @294_4acf30
  L4ad333:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 282), sizeof v); (u32)v; });  // @296_4acf30
  ecx = (u32)(edi + 282);  // @297_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @298_4acf30
  PV[23] = (u32)(esi);  // @299_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[23]);  // @300_4acf30
  ecx = edx = 0;  // @301_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @302_4acf30
  FL[2] = (edx & edx);  // @303_4acf30
  if (FL[2] == 0) goto L4ad373;  // @304_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @305_4acf30
  PV[24] = (u32)(edx);  // @306_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @307_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @308_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[24]);  // @309_4acf30
  ecx = edx = 0;  // @310_4acf30
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @311_4acf30
  PV[25] = (u32)(esi);  // @312_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @313_4acf30
  PV[26] = (u32)(ecx);  // @314_4acf30
  ecx = eax;  // @315_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[26], PV[25], (u32)(0));  // @316_4acf30
  ecx = edx = 0;  // @317_4acf30
  L4ad373:;
  eax = ebx;  // @319_4acf30
  L4ad375:;
  SEH_LEAVE();  // @321_4acf30
  ext_633654(G(u32, 0x6f5630));  // @322_4acf30
  return eax;  // @323_4acf30
}
PCREG(4acf30, lifted_4acf30);

extern "C" u32 THISCALL lifted_434800(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665786);  // @h_434800
  u8 F[0x610] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x510);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x510 + 8, &a0, 4);
  __builtin_memcpy(F + 0x510 + 12, &a1, 4);
  ebx = ecx;  // @0_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_434800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1176), &v, sizeof v); }  // @3_434800
  ecx = (u32)(EBP - 1168);  // @4_434800
  PV[0] = (u32)(eax);  // @5_434800
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @6_434800
  ecx = edx = 0;  // @7_434800
  ecx = (u32)(EBP - 1168);  // @8_434800
  reg.state = (s32)((u32)(0));  // @9_434800
  eax = ext_4cc5f0_thiscall1(ecx);  // @10_434800
  ecx = edx = 0;  // @11_434800
  edi = eax;  // @12_434800
  esi = 0;  // @13_434800
  FL[3] = esi;  // @14_434800
  FL[2] = (edi & edi);  // @15_434800
  if (FL[2] == 0) goto L434887;  // @16_434800
  L434862:;
  ecx = (u32)(EBP - 1168);  // @18_434800
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_434800
  ecx = edx = 0;  // @20_434800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }); FL[1] = (u32)(92);  // @21_434800
  if (FL[0] != FL[1]) goto L434882;  // @22_434800
  ecx = (u32)(EBP - 1168);  // @23_434800
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_434800
  ecx = edx = 0;  // @25_434800
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @26_434800
  L434882:;
  esi = (esi + 1);  // @28_434800
  FL[3] = esi;  // @29_434800
  FL[0] = esi; FL[1] = edi;  // @30_434800
  if (FL[0] != FL[1]) goto L434862;  // @31_434800
  L434887:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @33_434800
  FL[2] = (ecx & ecx);  // @34_434800
  if (FL[2] == 0) goto L434a51;  // @35_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_434800
  edx = (u32)(EBP - 1216);  // @37_434800
  PV[1] = (u32)(edx);  // @38_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @39_434800
  ecx = edx = 0;  // @40_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @41_434800
  edx = (u32)(EBP - 1216);  // @42_434800
  PV[2] = (u32)(edx);  // @43_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[2]);  // @45_434800
  ecx = edx = 0;  // @46_434800
  FL[2] = (eax & eax);  // @47_434800
  if (FL[2] == 0) goto L434a51;  // @48_434800
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @49_434800
  L4348c0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @51_434800
  ecx = (u32)(EBP - 1168);  // @52_434800
  eax = ext_4cc1d0_thiscall1(ecx);  // @53_434800
  ecx = edx = 0;  // @54_434800
  PV[3] = (u32)(eax);  // @55_434800
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @56_434800
  eax = ((u32( *)(u32, u32))(edi))(PV[4], PV[3]);  // @57_434800
  ecx = edx = 0;  // @58_434800
  FL[2] = (eax & eax);  // @59_434800
  if (FL[2] == 0) goto L4348f2;  // @60_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @61_434800
  edx = (u32)(EBP - 1216);  // @62_434800
  PV[5] = (u32)(edx);  // @63_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @65_434800
  ecx = edx = 0;  // @66_434800
  FL[2] = (eax & eax);  // @67_434800
  if (FL[2] != 0) goto L4348c0;  // @68_434800
  goto L434a51;  // @69_434800
  L4348f2:;
  ecx = (u32)(EBP - 1204);  // @71_434800
  eax = ext_4ccd10_thiscall3(ecx, (u32)(256), (u32)(0));  // @72_434800
  ecx = edx = 0;  // @73_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_434800
  ecx = (u32)(EBP - 1204);  // @75_434800
  PV[6] = (u32)(ecx);  // @76_434800
  ecx = esi;  // @77_434800
  reg.state = (s32)((u32)(1));  // @78_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[6]);  // @79_434800
  ecx = edx = 0;  // @80_434800
  eax = (u32)(EBP - 1228);  // @81_434800
  PV[7] = (u32)(eax);  // @82_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1204), sizeof v); (u32)v; });  // @83_434800
  ecx = (u32)(EBP - 1204);  // @84_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @85_434800
  ecx = edx = 0;  // @86_434800
  eax = (u32)(EBP - 1228);  // @87_434800
  PV[8] = (u32)(eax);  // @88_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1204), sizeof v); (u32)v; });  // @89_434800
  ecx = (u32)(EBP - 1204);  // @90_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @91_434800
  ecx = edx = 0;  // @92_434800
  ecx = eax;  // @93_434800
  FL[2] = (ecx & ecx);  // @94_434800
  if (FL[2] == 0) goto L434a46;  // @95_434800
  L434950:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6792424), sizeof v); (u32)v; })) & 0xffff);  // @97_434800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1176), sizeof v); (u32)v; });  // @98_434800
  esi = edx;  // @99_434800
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 1040), &v, sizeof v); }  // @100_434800
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6792426), sizeof v); (u32)v; })) & 0xff);  // @101_434800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1038), &v, sizeof v); }  // @102_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_434800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1172), &v, sizeof v); }  // @104_434800
  FL[2] = (edx & edx);  // @105_434800
  if (FL[2] == 0) goto L4349db;  // @106_434800
  L434980:;
  PV[9] = (u32)(esi);  // @108_434800
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[9], (u32)(44));  // @109_434800
  ecx = edx = 0;  // @110_434800
  ebx = eax;  // @111_434800
  FL[2] = (ebx & ebx);  // @112_434800
  if (FL[2] == 0) goto L4349f5;  // @113_434800
  edi = ebx;  // @114_434800
  eax = (u32)(EBP - 1038);  // @115_434800
  edi = (edi - esi);  // @116_434800
  FL[3] = edi;  // @117_434800
  PV[10] = (u32)(edi);  // @118_434800
  PV[11] = (u32)(esi);  // @119_434800
  PV[12] = (u32)(eax);  // @120_434800
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67642c))(PV[12], PV[11], PV[10]);  // @121_434800
  ecx = edx = 0;  // @122_434800
  edi = (edi + (u32)(2));  // @123_434800
  FL[3] = edi;  // @124_434800
  FL[0] = edi; FL[1] = (u32)(1024);  // @125_434800
  if (FL[0] >= FL[1]) goto L434a7c;  // @126_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1172), sizeof v); (u32)v; });  // @127_434800
  edx = (u32)(EBP - 1040);  // @128_434800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + edi - 1040), &v, sizeof v); }  // @129_434800
  esi = (u32)(ebx + 1);  // @130_434800
  eax = ext_4cc850_fastcall2(ecx, edx);  // @131_434800
  ecx = edx = 0;  // @132_434800
  FL[2] = (eax & eax);  // @133_434800
  if (FL[2] == 0) goto L434a22;  // @134_434800
  FL[2] = (esi & esi);  // @135_434800
  if (FL[2] != 0) goto L434980;  // @136_434800
  L4349db:;
  ecx = (u32)(EBP - 1204);  // @138_434800
  eax = ext_4cd0e0_thiscall1(ecx);  // @139_434800
  ecx = edx = 0;  // @140_434800
  ecx = (u32)(EBP - 1168);  // @141_434800
  eax = ext_4cbec0_thiscall1(ecx);  // @142_434800
  ecx = edx = 0;  // @143_434800
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @144_434800
  goto L434a5e;  // @145_434800
  L4349f5:;
  edi = (u32)(EBP - 1038);  // @147_434800
  edx = esi;  // @148_434800
  edi = (edi - esi);  // @149_434800
  FL[3] = edi;  // @150_434800
  L434a00:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @152_434800
  edx = (u32)(edx + 1);  // @153_434800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + edx - 1), &v, sizeof v); }  // @154_434800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @155_434800
  if (FL[2] != 0) goto L434a00;  // @156_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1172), sizeof v); (u32)v; });  // @157_434800
  edx = (u32)(EBP - 1040);  // @158_434800
  eax = ext_4cc850_fastcall2(ecx, edx);  // @159_434800
  ecx = edx = 0;  // @160_434800
  FL[2] = (eax & eax);  // @161_434800
  if (FL[2] != 0) goto L4349db;  // @162_434800
  L434a22:;
  FL[2] = (esi & esi);  // @164_434800
  if (FL[2] == 0) goto L4349db;  // @165_434800
  eax = (u32)(EBP - 1228);  // @166_434800
  PV[13] = (u32)(eax);  // @167_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1204), sizeof v); (u32)v; });  // @168_434800
  ecx = (u32)(EBP - 1204);  // @169_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[13]);  // @170_434800
  ecx = edx = 0;  // @171_434800
  ecx = eax;  // @172_434800
  FL[2] = (ecx & ecx);  // @173_434800
  if (FL[2] != 0) goto L434950;  // @174_434800
  L434a46:;
  ecx = (u32)(EBP - 1204);  // @176_434800
  eax = ext_4cd0e0_thiscall1(ecx);  // @177_434800
  ecx = edx = 0;  // @178_434800
  L434a51:;
  ecx = (u32)(EBP - 1168);  // @180_434800
  eax = ext_4cbec0_thiscall1(ecx);  // @181_434800
  ecx = edx = 0;  // @182_434800
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @183_434800
  FL[3] = (eax & 0xff);  // @184_434800
  L434a5e:;
  SEH_LEAVE();  // @186_434800
  ext_633654(G(u32, 0x6f5630));  // @187_434800
  return eax;  // @188_434800
  L434a7c:;
  eax = ext_634047_cdecl0();  // @190_434800
  ecx = edx = 0;  // @191_434800
}
PCREG(434800, lifted_434800);

extern "C" u32 THISCALL lifted_434250(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665746);  // @h_434250
  u8 F[0x830] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x730);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x730 + 8, &a0, 4);
  __builtin_memcpy(F + 0x730 + 12, &a1, 4);
  ebx = ecx;  // @0_434250
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 1688), &v, sizeof v); }  // @1_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @2_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1712), &v, sizeof v); }  // @5_434250
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1720), &v, sizeof v); }  // @6_434250
  FL[2] = (ecx & ecx);  // @7_434250
  if (FL[2] == 0) goto L434690;  // @8_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_434250
  edx = (u32)(EBP - 1772);  // @10_434250
  PV[0] = (u32)(edx);  // @11_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @12_434250
  ecx = edx = 0;  // @13_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @14_434250
  edx = (u32)(EBP - 1772);  // @15_434250
  PV[1] = (u32)(edx);  // @16_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @18_434250
  ecx = edx = 0;  // @19_434250
  FL[2] = (eax & eax);  // @20_434250
  if (FL[2] == 0) goto L434690;  // @21_434250
  L4342c6:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @23_434250
  ecx = (u32)(EBP - 1748);  // @24_434250
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1716), &v, sizeof v); }  // @25_434250
  eax = ext_4ccd10_thiscall3(ecx, (u32)(256), (u32)(0));  // @26_434250
  ecx = edx = 0;  // @27_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_434250
  ecx = (u32)(EBP - 1748);  // @29_434250
  PV[2] = (u32)(ecx);  // @30_434250
  ecx = esi;  // @31_434250
  reg.state = (s32)((u32)(0));  // @32_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[2]);  // @33_434250
  ecx = edx = 0;  // @34_434250
  FL[2] = (edi & edi);  // @35_434250
  if (FL[2] != 0) goto L43430f;  // @36_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @37_434250
  FL[2] = (eax & eax);  // @38_434250
  if (FL[2] == 0) goto L434309;  // @39_434250
  eax = ((u32(STDCALL *)(void))(eax))();  // @40_434250
  ecx = edx = 0;  // @41_434250
  goto L434667;  // @42_434250
  L434309:;
  __builtin_trap();  // @44_434250
  L43430f:;
  eax = (u32)(EBP - 1760);  // @46_434250
  PV[3] = (u32)(eax);  // @47_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1748), sizeof v); (u32)v; });  // @48_434250
  ecx = (u32)(EBP - 1748);  // @49_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @50_434250
  ecx = edx = 0;  // @51_434250
  eax = (u32)(EBP - 1760);  // @52_434250
  PV[4] = (u32)(eax);  // @53_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1748), sizeof v); (u32)v; });  // @54_434250
  ecx = (u32)(EBP - 1748);  // @55_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[4]);  // @56_434250
  ecx = edx = 0;  // @57_434250
  FL[2] = (eax & eax);  // @58_434250
  if (FL[2] == 0) goto L434667;  // @59_434250
  L434343:;
  esi = edi;  // @61_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @62_434250
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6792424), sizeof v); (u32)v; })) & 0xffff);  // @63_434250
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 1552), &v, sizeof v); }  // @64_434250
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6792426), sizeof v); (u32)v; })) & 0xff);  // @65_434250
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1704), &v, sizeof v); }  // @66_434250
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1550), &v, sizeof v); }  // @67_434250
  L434365:;
  PV[5] = (u32)(esi);  // @69_434250
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[5], (u32)(44));  // @70_434250
  ecx = edx = 0;  // @71_434250
  ebx = eax;  // @72_434250
  FL[2] = (ebx & ebx);  // @73_434250
  if (FL[2] == 0) goto L4343af;  // @74_434250
  edi = ebx;  // @75_434250
  eax = (u32)(EBP - 1550);  // @76_434250
  edi = (edi - esi);  // @77_434250
  FL[3] = edi;  // @78_434250
  PV[6] = (u32)(edi);  // @79_434250
  PV[7] = (u32)(esi);  // @80_434250
  PV[8] = (u32)(eax);  // @81_434250
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67642c))(PV[8], PV[7], PV[6]);  // @82_434250
  ecx = edx = 0;  // @83_434250
  edi = (edi + (u32)(2));  // @84_434250
  FL[3] = edi;  // @85_434250
  FL[0] = edi; FL[1] = (u32)(1024);  // @86_434250
  if (FL[0] >= FL[1]) goto L4346ae;  // @87_434250
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + edi - 1552), &v, sizeof v); }  // @88_434250
  esi = (u32)(ebx + 1);  // @89_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1704), sizeof v); (u32)v; });  // @90_434250
  goto L4343c6;  // @91_434250
  L4343af:;
  ecx = (u32)(EBP - 1550);  // @93_434250
  ecx = (ecx - esi);  // @94_434250
  FL[3] = ecx;  // @95_434250
  L4343b7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @97_434250
  esi = (u32)(esi + 1);  // @98_434250
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @99_434250
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @100_434250
  if (FL[2] != 0) goto L4343b7;  // @101_434250
  esi = 0;  // @102_434250
  FL[3] = esi;  // @103_434250
  L4343c6:;
  edx = (u32)(EBP - 1552);  // @105_434250
  ecx = edi;  // @106_434250
  eax = ext_4cc850_fastcall2(ecx, edx);  // @107_434250
  ecx = edx = 0;  // @108_434250
  FL[2] = (eax & eax);  // @109_434250
  if (FL[2] == 0) goto L43463d;  // @110_434250
  FL[2] = (esi & esi);  // @111_434250
  if (FL[2] != 0) goto L434365;  // @112_434250
  FL[2] = (edi & edi);  // @113_434250
  if (FL[2] == 0) goto L43463d;  // @114_434250
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @115_434250
  ecx = ebx;  // @116_434250
  PV[9] = (u32)(edi);  // @117_434250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 1681), &v, sizeof v); }  // @118_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @119_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 304)))(ecx, PV[9]);  // @120_434250
  ecx = edx = 0;  // @121_434250
  FL[2] = (eax & eax);  // @122_434250
  if (FL[2] != 0) goto L434570;  // @123_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @124_434250
  ecx = (u32)(EBP - 1680);  // @125_434250
  PV[10] = (u32)(edi);  // @126_434250
  PV[11] = (u32)(ecx);  // @127_434250
  ecx = ebx;  // @128_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 300)))(ecx, PV[11], PV[10]);  // @129_434250
  ecx = edx = 0;  // @130_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @131_434250
  ecx = (u32)(EBP - 1680);  // @132_434250
  reg.state = (s32)((u32)(1));  // @133_434250
  eax = ext_4cc1d0_thiscall1(ecx);  // @134_434250
  ecx = edx = 0;  // @135_434250
  PV[12] = (u32)(eax);  // @136_434250
  ecx = ebx;  // @137_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 48)))(ecx, PV[12], (u32)(1));  // @138_434250
  ecx = edx = 0;  // @139_434250
  ebx = eax;  // @140_434250
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 1696), &v, sizeof v); }  // @141_434250
  FL[0] = ebx; FL[1] = (u32)(-1);  // @142_434250
  if (FL[0] == FL[1]) goto L43453d;  // @143_434250
  PV[13] = (u32)(ebx);  // @144_434250
  eax = ext_41e290_cdecl1(PV[13]);  // @145_434250
  ecx = edx = 0;  // @146_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @147_434250
  ecx = (u32)(EBP - 1680);  // @148_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1708), &v, sizeof v); }  // @149_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @150_434250
  PV[14] = (u32)(ebx);  // @151_434250
  PV[15] = (u32)(eax);  // @152_434250
  eax = ext_4cc1d0_thiscall1(ecx);  // @153_434250
  ecx = edx = 0;  // @154_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @155_434250
  PV[16] = (u32)(eax);  // @156_434250
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, PV[16], PV[15], PV[14], (u32)(0), (u32)(1));  // @157_434250
  ecx = edx = 0;  // @158_434250
  FL[0] = ebx; FL[1] = eax;  // @159_434250
  if (FL[0] != FL[1]) goto L43452a;  // @160_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1712), sizeof v); (u32)v; });  // @161_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(1));  // @163_434250
  ecx = edx = 0;  // @164_434250
  edx = edi;  // @165_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1700), &v, sizeof v); }  // @166_434250
  esi = (u32)(edx + 1);  // @167_434250
  L434495:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @169_434250
  edx = (edx + 1);  // @170_434250
  FL[3] = edx;  // @171_434250
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @172_434250
  if (FL[2] != 0) goto L434495;  // @173_434250
  edx = (edx - esi);  // @174_434250
  FL[3] = edx;  // @175_434250
  esi = 0;  // @176_434250
  FL[3] = esi;  // @177_434250
  eax = (u32)(edx + 1);  // @178_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1692), &v, sizeof v); }  // @179_434250
  FL[2] = (eax & eax);  // @180_434250
  if (FL[2] == 0) goto L4344eb;  // @181_434250
  ebx = edi;  // @182_434250
  eax = (u32)(EBP - 528);  // @183_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1692), sizeof v); (u32)v; });  // @184_434250
  ebx = (ebx - eax);  // @185_434250
  FL[3] = ebx;  // @186_434250
  L4344c0:;
  edx = (u32)(EBP - 528);  // @188_434250
  eax = (u32)(92);  // @189_434250
  edx = (edx + esi);  // @190_434250
  FL[3] = edx;  // @191_434250
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @192_434250
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx), sizeof v); (u32)v; });  // @193_434250
  if (FL[0] == FL[1]) ecx = eax;  // @194_434250
  esi = (esi + 1);  // @195_434250
  FL[3] = esi;  // @196_434250
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @197_434250
  FL[0] = esi; FL[1] = edi;  // @198_434250
  if (FL[0] != FL[1]) goto L4344c0;  // @199_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1704), sizeof v); (u32)v; });  // @200_434250
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1696), sizeof v); (u32)v; });  // @201_434250
  L4344eb:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1700), sizeof v); (u32)v; });  // @203_434250
  ecx = (u32)(EBP - 528);  // @204_434250
  PV[17] = (u32)(ecx);  // @205_434250
  ecx = esi;  // @206_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @207_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[17]);  // @208_434250
  ecx = edx = 0;  // @209_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @210_434250
  ecx = esi;  // @211_434250
  PV[18] = (u32)(ebx);  // @212_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[18]);  // @213_434250
  ecx = edx = 0;  // @214_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1708), sizeof v); (u32)v; });  // @215_434250
  ecx = eax;  // @216_434250
  PV[19] = (u32)(ebx);  // @217_434250
  PV[20] = (u32)(esi);  // @218_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @219_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 28)))(ecx, PV[20], PV[19]);  // @220_434250
  ecx = edx = 0;  // @221_434250
  PV[21] = (u32)(esi);  // @222_434250
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1681), &v, sizeof v); }  // @223_434250
  eax = ext_634273_cdecl2(PV[21], (u32)(1));  // @224_434250
  ecx = edx = 0;  // @225_434250
  goto L434561;  // @226_434250
  L43452a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1708), sizeof v); (u32)v; });  // @228_434250
  PV[22] = (u32)(esi);  // @229_434250
  eax = ext_634273_cdecl2(PV[22], (u32)(1));  // @230_434250
  ecx = edx = 0;  // @231_434250
  goto L434561;  // @232_434250
  L43453d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @234_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6792428), (u32)(273));  // @236_434250
  ecx = edx = 0;  // @237_434250
  PV[23] = (u32)(edi);  // @238_434250
  PV[24] = (u32)(eax);  // @239_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @240_434250
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[24], (u32)(6792472), PV[23]);  // @241_434250
  ecx = edx = 0;  // @242_434250
  L434561:;
  ecx = (u32)(EBP - 1680);  // @244_434250
  reg.state = (s32)((u32)(0));  // @245_434250
  eax = ext_4cbec0_thiscall1(ecx);  // @246_434250
  ecx = edx = 0;  // @247_434250
  L434570:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1681), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @249_434250
  if (FL[0] == FL[1]) goto L43463d;  // @250_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1716), sizeof v); (u32)v; });  // @251_434250
  ecx = esi;  // @252_434250
  PV[25] = (u32)(edi);  // @253_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @254_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[25]);  // @255_434250
  ecx = edx = 0;  // @256_434250
  ebx = eax;  // @257_434250
  PV[26] = (u32)(ebx);  // @258_434250
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 1696), &v, sizeof v); }  // @259_434250
  eax = ext_41e290_cdecl1(PV[26]);  // @260_434250
  ecx = edx = 0;  // @261_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @262_434250
  ecx = esi;  // @263_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1692), &v, sizeof v); }  // @264_434250
  PV[27] = (u32)(ebx);  // @265_434250
  PV[28] = (u32)(eax);  // @266_434250
  PV[29] = (u32)(edi);  // @267_434250
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 28)))(ecx, PV[29], PV[28], PV[27], (u32)(0));  // @268_434250
  ecx = edx = 0;  // @269_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1712), sizeof v); (u32)v; });  // @270_434250
  ecx = eax;  // @271_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @272_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(1));  // @273_434250
  ecx = edx = 0;  // @274_434250
  edx = edi;  // @275_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1700), &v, sizeof v); }  // @276_434250
  eax = (u32)(edx + 1);  // @277_434250
  L4345c8:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @279_434250
  edx = (edx + 1);  // @280_434250
  FL[3] = edx;  // @281_434250
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @282_434250
  if (FL[2] != 0) goto L4345c8;  // @283_434250
  edx = (edx - eax);  // @284_434250
  FL[3] = edx;  // @285_434250
  esi = 0;  // @286_434250
  FL[3] = esi;  // @287_434250
  ebx = (u32)(edx + 1);  // @288_434250
  FL[2] = (ebx & ebx);  // @289_434250
  if (FL[2] == 0) goto L434601;  // @290_434250
  eax = (u32)(EBP - 528);  // @291_434250
  edi = (edi - eax);  // @292_434250
  FL[3] = edi;  // @293_434250
  L4345e2:;
  edx = (u32)(EBP - 528);  // @295_434250
  eax = (u32)(92);  // @296_434250
  edx = (edx + esi);  // @297_434250
  FL[3] = edx;  // @298_434250
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @299_434250
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx), sizeof v); (u32)v; });  // @300_434250
  if (FL[0] == FL[1]) ecx = eax;  // @301_434250
  esi = (esi + 1);  // @302_434250
  FL[3] = esi;  // @303_434250
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @304_434250
  FL[0] = esi; FL[1] = ebx;  // @305_434250
  if (FL[0] != FL[1]) goto L4345e2;  // @306_434250
  L434601:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1700), sizeof v); (u32)v; });  // @308_434250
  ecx = (u32)(EBP - 528);  // @309_434250
  PV[30] = (u32)(ecx);  // @310_434250
  ecx = ebx;  // @311_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @312_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[30]);  // @313_434250
  ecx = edx = 0;  // @314_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @315_434250
  ecx = ebx;  // @316_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1696), sizeof v); (u32)v; });  // @317_434250
  PV[31] = (u32)(esi);  // @318_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[31]);  // @319_434250
  ecx = edx = 0;  // @320_434250
  PV[32] = (u32)(esi);  // @321_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1692), sizeof v); (u32)v; });  // @322_434250
  ecx = eax;  // @323_434250
  PV[33] = (u32)(esi);  // @324_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @325_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 28)))(ecx, PV[33], PV[32]);  // @326_434250
  ecx = edx = 0;  // @327_434250
  PV[34] = (u32)(esi);  // @328_434250
  eax = ext_634273_cdecl2(PV[34], (u32)(1));  // @329_434250
  ecx = edx = 0;  // @330_434250
  L43463d:;
  eax = (u32)(EBP - 1760);  // @332_434250
  PV[35] = (u32)(eax);  // @333_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1748), sizeof v); (u32)v; });  // @334_434250
  ecx = (u32)(EBP - 1748);  // @335_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[35]);  // @336_434250
  ecx = edx = 0;  // @337_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1720), sizeof v); (u32)v; });  // @338_434250
  FL[2] = (eax & eax);  // @339_434250
  if (FL[2] != 0) goto L434343;  // @340_434250
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @341_434250
  L434667:;
  ecx = (u32)(EBP - 1748);  // @343_434250
  reg.state = (s32)((u32)(4294967295));  // @344_434250
  eax = ext_4cd0e0_thiscall1(ecx);  // @345_434250
  ecx = edx = 0;  // @346_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @347_434250
  edx = (u32)(EBP - 1772);  // @348_434250
  PV[36] = (u32)(edx);  // @349_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[36]);  // @351_434250
  ecx = edx = 0;  // @352_434250
  FL[2] = (eax & eax);  // @353_434250
  if (FL[2] != 0) goto L4342c6;  // @354_434250
  L434690:;
  SEH_LEAVE();  // @356_434250
  ext_633654(G(u32, 0x6f5630));  // @357_434250
  return eax;  // @358_434250
  L4346ae:;
  eax = ext_634047_cdecl0();  // @360_434250
  ecx = edx = 0;  // @361_434250
}
PCREG(434250, lifted_434250);

extern "C" u32 THISCALL lifted_5f10c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cda8);  // @h_5f10c0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5f10c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5f10c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5f10c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_5f10c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @4_5f10c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_5f10c0
  reg.state = (s32)((u32)(0));  // @6_5f10c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @7_5f10c0
  ebx = edx;  // @8_5f10c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_5f10c0
  ebx = (ebx - ecx);  // @10_5f10c0
  FL[3] = ebx;  // @11_5f10c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_5f10c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @13_5f10c0
  esi = (u32)(ebx + 1);  // @14_5f10c0
  FL[0] = esi; FL[1] = (u32)(-2);  // @15_5f10c0
  if (FL[0] > FL[1]) goto L5f113f;  // @16_5f10c0
  FL[2] = (esi & esi);  // @17_5f10c0
  if (FL[2] != 0) goto L5f112a;  // @18_5f10c0
  eax = 0;  // @19_5f10c0
  FL[3] = eax;  // @20_5f10c0
  goto L5f1135;  // @21_5f10c0
  L5f112a:;
  PV[0] = (u32)(esi);  // @23_5f10c0
  ecx = edi;  // @24_5f10c0
  eax = ext_6014a0_stdcall1(PV[0]);  // @25_5f10c0
  ecx = edx = 0;  // @26_5f10c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @27_5f10c0
  L5f1135:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @29_5f10c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @30_5f10c0
  eax = (eax + esi);  // @31_5f10c0
  FL[3] = eax;  // @32_5f10c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @33_5f10c0
  L5f113f:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_5f10c0
  PV[1] = (u32)(ebx);  // @36_5f10c0
  PV[2] = (u32)(ecx);  // @37_5f10c0
  PV[3] = (u32)(esi);  // @38_5f10c0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))(PV[3], PV[2], PV[1]);  // @39_5f10c0
  ecx = edx = 0;  // @40_5f10c0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @41_5f10c0
  FL[3] = esi;  // @42_5f10c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @43_5f10c0
  eax = (eax + esi);  // @44_5f10c0
  FL[3] = eax;  // @45_5f10c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @46_5f10c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @47_5f10c0
  if (FL[3] == 0) goto L5f1160;  // @48_5f10c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @49_5f10c0
  L5f1160:;
  eax = edi;  // @51_5f10c0
  SEH_LEAVE();  // @52_5f10c0
  return eax;  // @53_5f10c0
}
PCREG(5f10c0, lifted_5f10c0);

extern "C" u32 THISCALL lifted_42ed30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_42ed30
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_42ed30
  ecx = (ecx + (u32)(291));  // @1_42ed30
  FL[3] = ecx;  // @2_42ed30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3_42ed30
  eax = ext_4cc1d0_thiscall1(ecx);  // @4_42ed30
  ecx = edx = 0;  // @5_42ed30
  PV[0] = (u32)(eax);  // @6_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))(PV[0], (u32)(58));  // @7_42ed30
  ecx = edx = 0;  // @8_42ed30
  FL[2] = (eax & eax);  // @9_42ed30
  if (FL[2] != 0) goto L42ed92;  // @10_42ed30
  L42ed84:;
  ecx = esi;  // @12_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @13_42ed30
  ecx = edx = 0;  // @14_42ed30
  goto L42edf9;  // @15_42ed30
  L42ed92:;
  PV[1] = (u32)(eax);  // @17_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[1], (u32)(92));  // @18_42ed30
  ecx = edx = 0;  // @19_42ed30
  FL[2] = (eax & eax);  // @20_42ed30
  if (FL[2] == 0) goto L42ed84;  // @21_42ed30
  eax = (eax + 1);  // @22_42ed30
  FL[3] = eax;  // @23_42ed30
  ecx = (u32)(EBP - 144);  // @24_42ed30
  PV[2] = (u32)(eax);  // @25_42ed30
  eax = ext_4cbe80_thiscall2(ecx, PV[2]);  // @26_42ed30
  ecx = edx = 0;  // @27_42ed30
  ecx = (u32)(EBP - 144);  // @28_42ed30
  reg.state = (s32)((u32)(0));  // @29_42ed30
  eax = ext_4cc1d0_thiscall1(ecx);  // @30_42ed30
  ecx = edx = 0;  // @31_42ed30
  PV[3] = (u32)(eax);  // @32_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[3], (u32)(92));  // @33_42ed30
  ecx = edx = 0;  // @34_42ed30
  ecx = esi;  // @35_42ed30
  FL[2] = (eax & eax);  // @36_42ed30
  if (FL[2] != 0) goto L42eddf;  // @37_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @38_42ed30
  ecx = edx = 0;  // @39_42ed30
  goto L42edee;  // @40_42ed30
  L42eddf:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @42_42ed30
  eax = (u32)(EBP - 144);  // @43_42ed30
  PV[4] = (u32)(eax);  // @44_42ed30
  eax = ext_4cbe50_thiscall2(ecx, PV[4]);  // @45_42ed30
  ecx = edx = 0;  // @46_42ed30
  L42edee:;
  ecx = (u32)(EBP - 144);  // @48_42ed30
  eax = ext_4cbec0_thiscall1(ecx);  // @49_42ed30
  ecx = edx = 0;  // @50_42ed30
  L42edf9:;
  eax = esi;  // @52_42ed30
  SEH_LEAVE();  // @53_42ed30
  ext_633654(G(u32, 0x6f5630));  // @54_42ed30
  return eax;  // @55_42ed30
}
PCREG(42ed30, lifted_42ed30);

extern "C" u32 THISCALL lifted_4a3280(u32 ecx_in) {
  SEH_ENTER(0x66c588);  // @h_4a3280
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_4a3280
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4a3280
  eax = ext_469870_thiscall1(ecx);  // @2_4a3280
  ecx = edx = 0;  // @3_4a3280
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4a3280
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_4a3280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @6_4a3280
  ecx = 0;  // @7_4a3280
  FL[3] = ecx;  // @8_4a3280
  reg.state = (s32)((u32)(0));  // @9_4a3280
  eax = (u32)(2);  // @10_4a3280
  { u32 v = (u32)((u32)(6879964)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_4a3280
  edx = (u32)(10);  // @12_4a3280
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @13_4a3280
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @14_4a3280
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @15_4a3280
  ecx = (0u - ecx);  // @16_4a3280
  ecx = (ecx | eax);  // @17_4a3280
  FL[3] = ecx;  // @18_4a3280
  PV[0] = (u32)(ecx);  // @19_4a3280
  eax = ext_41e290_cdecl1(PV[0]);  // @20_4a3280
  ecx = edx = 0;  // @21_4a3280
  ebx = 0;  // @22_4a3280
  FL[3] = ebx;  // @23_4a3280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @24_4a3280
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }); FL[1] = ebx;  // @25_4a3280
  if ((s32)FL[0] <= (s32)FL[1]) goto L4a334c;  // @26_4a3280
  edi = 0;  // @27_4a3280
  FL[3] = edi;  // @28_4a3280
  L4a3300:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @30_4a3280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7234360), sizeof v); (u32)v; });  // @31_4a3280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx), &v, sizeof v); }  // @32_4a3280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @33_4a3280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7234366), sizeof v); (u32)v; });  // @34_4a3280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edi + 6), &v, sizeof v); }  // @35_4a3280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_4a3280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @37_4a3280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @38_4a3280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4a3280
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi), sizeof v); (u32)v; });  // @40_4a3280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 276)))(ecx, PV[1], (u32)(0), (u32)(6880104), (u32)(14));  // @41_4a3280
  ecx = edx = 0;  // @42_4a3280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @43_4a3280
  edi = (u32)(edi + 10);  // @44_4a3280
  ebx = (ebx + 1);  // @45_4a3280
  FL[3] = ebx;  // @46_4a3280
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + edi - 6), &v, sizeof v); }  // @47_4a3280
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @48_4a3280
  if ((s32)FL[0] < (s32)FL[1]) goto L4a3300;  // @49_4a3280
  L4a334c:;
  eax = esi;  // @51_4a3280
  SEH_LEAVE();  // @52_4a3280
  return eax;  // @53_4a3280
}
PCREG(4a3280, lifted_4a3280);

extern "C" u32 THISCALL lifted_495b30(u32 ecx_in) {
  SEH_ENTER(0x66dac1);  // @h_495b30
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_495b30
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @2_495b30
  { u8 v = (u8)(((FL[0] != FL[1]) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_495b30
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @4_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_495b30
  eax = ext_4cd9b0_fastcall4(ecx, edx, (u32)(112), PV[0]);  // @6_495b30
  ecx = edx = 0;  // @7_495b30
  ebx = eax;  // @8_495b30
  FL[0] = ebx; FL[1] = (u32)(-1);  // @9_495b30
  if (FL[0] != FL[1]) goto L495b9b;  // @10_495b30
  eax = ext_42ab62_cdecl1((u32)(6874268));  // @11_495b30
  ecx = edx = 0;  // @12_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_495b30
  FL[2] = (ecx & ecx);  // @14_495b30
  if (FL[2] == 0) goto L495b93;  // @15_495b30
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @16_495b30
  ecx = edx = 0;  // @17_495b30
  goto L495b94;  // @18_495b30
  L495b93:;
  __builtin_trap();  // @20_495b30
  L495b94:;
  ecx = edi;  // @22_495b30
  eax = ext_496a40_thiscall1(ecx);  // @23_495b30
  ecx = edx = 0;  // @24_495b30
  L495b9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @26_495b30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @27_495b30
  eax = (u32)(ebx + 112);  // @28_495b30
  esi = (esi + ebx);  // @29_495b30
  FL[3] = esi;  // @30_495b30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_495b30
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = eax;  // @32_495b30
  if (FL[0] >= FL[1]) goto L495bb1;  // @33_495b30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @34_495b30
  L495bb1:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @36_495b30
  reg.state = (s32)((u32)(0));  // @37_495b30
  FL[2] = (esi & esi);  // @38_495b30
  if (FL[2] == 0) goto L495bc6;  // @39_495b30
  ecx = esi;  // @40_495b30
  eax = ext_4d93e0_thiscall1(ecx);  // @41_495b30
  ecx = edx = 0;  // @42_495b30
  L495bc6:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @44_495b30
  reg.state = (s32)((u32)(4294967295));  // @45_495b30
  if (FL[0] == FL[1]) goto L495bdc;  // @46_495b30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) | (u32)(1048576))); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @47_495b30
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @48_495b30
  goto L495bea;  // @49_495b30
  L495bdc:;
  ecx = esi;  // @51_495b30
  eax = ext_4dc630_thiscall3(ecx, (u32)(134217728), (u32)(0));  // @52_495b30
  ecx = edx = 0;  // @53_495b30
  L495bea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @55_495b30
  FL[2] = (ecx & ecx);  // @56_495b30
  if (FL[2] == 0) goto L495c07;  // @57_495b30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_495b30
  PV[1] = (u32)(ebx);  // @59_495b30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(6873924), PV[1], (u32)(112));  // @60_495b30
  ecx = edx = 0;  // @61_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @62_495b30
  L495c07:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_495b30
  PV[2] = (u32)(esi);  // @65_495b30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[2], (u32)(112), (u32)(11468975));  // @66_495b30
  ecx = edx = 0;  // @67_495b30
  eax = esi;  // @68_495b30
  SEH_LEAVE();  // @69_495b30
  return eax;  // @70_495b30
}
PCREG(495b30, lifted_495b30);

extern "C" u32 THISCALL lifted_4711f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666eeb);  // @h_4711f0
  u8 F[0x4220] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x4120);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4120 + 8, &a0, 4);
  __builtin_memcpy(F + 0x4120 + 12, &a1, 4);
  edi = ecx;  // @0_4711f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4711f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @3_4711f0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @4_4711f0
  if (FL[0] == FL[1]) goto L4712d2;  // @5_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @6_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @7_4711f0
  eax = (eax >> (u32)(10));  // @8_4711f0
  FL[3] = eax;  // @9_4711f0
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @10_4711f0
  FL[0] = ebx; FL[1] = (u32)(1);  // @11_4711f0
  if (FL[0] != FL[1]) goto L471254;  // @12_4711f0
  FL[2] = ((ebx & 0xff) & (eax & 0xff));  // @13_4711f0
  if (FL[2] == 0) goto L47125d;  // @14_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @16_4711f0
  ecx = edx = 0;  // @17_4711f0
  goto L47125d;  // @18_4711f0
  L471254:;
  FL[2] = ((eax & 0xff) & (u32)(1));  // @20_4711f0
  if (FL[2] != 0) goto L47125d;  // @21_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @23_4711f0
  ecx = edx = 0;  // @24_4711f0
  L47125d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_4711f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @27_4711f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4711f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @30_4711f0
  ecx = edx = 0;  // @31_4711f0
  ecx = eax;  // @32_4711f0
  FL[2] = (ecx & ecx);  // @33_4711f0
  if (FL[2] == 0) goto L4712d6;  // @34_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4711f0
  PV[1] = (u32)(ebx);  // @36_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 756), sizeof v); (u32)v; });  // @37_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[1], (u32)(0));  // @38_4711f0
  ecx = edx = 0;  // @39_4711f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @40_4711f0
  if (FL[2] == 0) goto L4712d6;  // @41_4711f0
  ecx = (u32)(EBP - 16596);  // @42_4711f0
  eax = ext_4d2280_thiscall1(ecx);  // @43_4711f0
  ecx = edx = 0;  // @44_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @45_4711f0
  esi = (u32)(EBP - 16596);  // @46_4711f0
  FL[2] = (eax & eax);  // @47_4711f0
  reg.state = (s32)((u32)(0));  // @48_4711f0
  PV[2] = (u32)(ebx);  // @49_4711f0
  if (FL[2] != 0) esi = eax;  // @50_4711f0
  ecx = esi;  // @51_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(6850636), PV[2]);  // @53_4711f0
  ecx = edx = 0;  // @54_4711f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @55_4711f0
  ecx = edi;  // @56_4711f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @57_4711f0
  PV[3] = (u32)(esi);  // @58_4711f0
  PV[4] = (u32)(eax);  // @59_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, PV[4], PV[3]);  // @60_4711f0
  ecx = edx = 0;  // @61_4711f0
  ecx = (u32)(EBP - 16596);  // @62_4711f0
  eax = ext_4d2330_thiscall1(ecx);  // @63_4711f0
  ecx = edx = 0;  // @64_4711f0
  L4712d2:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @66_4711f0
  goto L4712d8;  // @67_4711f0
  L4712d6:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @69_4711f0
  FL[3] = (eax & 0xff);  // @70_4711f0
  L4712d8:;
  SEH_LEAVE();  // @72_4711f0
  ext_633654(G(u32, 0x6f5630));  // @73_4711f0
  return eax;  // @74_4711f0
}
PCREG(4711f0, lifted_4711f0);

extern "C" u32 THISCALL lifted_431880(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665451);  // @h_431880
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_431880
  esi = (u32)(ecx + 132);  // @1_431880
  edi = 0;  // @2_431880
  FL[3] = edi;  // @3_431880
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @4_431880
  FL[3] = (eax & 0xff);  // @5_431880
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @6_431880
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @7_431880
  FL[2] = (esi & esi);  // @8_431880
  if (FL[2] == 0) goto L431971;  // @9_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_431880
  ecx = (u32)(EBP - 32);  // @11_431880
  PV[0] = (u32)(ecx);  // @12_431880
  ecx = esi;  // @13_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @14_431880
  ecx = edx = 0;  // @15_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_431880
  ecx = (u32)(EBP - 32);  // @17_431880
  PV[1] = (u32)(ecx);  // @18_431880
  ecx = esi;  // @19_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @20_431880
  ecx = edx = 0;  // @21_431880
  edi = eax;  // @22_431880
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @23_431880
  FL[2] = (edi & edi);  // @24_431880
  if (FL[2] == 0) goto L43196a;  // @25_431880
  L4318e6:;
  ecx = ebx;  // @27_431880
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_431880
  ecx = edx = 0;  // @29_431880
  PV[2] = (u32)(eax);  // @30_431880
  ecx = edi;  // @31_431880
  eax = ext_4cc1d0_thiscall1(ecx);  // @32_431880
  ecx = edx = 0;  // @33_431880
  PV[3] = (u32)(eax);  // @34_431880
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[3], PV[2]);  // @35_431880
  ecx = edx = 0;  // @36_431880
  FL[2] = (eax & eax);  // @37_431880
  if (FL[2] != 0) goto L431938;  // @38_431880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @39_431880
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @40_431880
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 165), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @41_431880
  if (FL[0] == FL[1]) goto L43192d;  // @42_431880
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 167), sizeof v); (u32)v; });  // @43_431880
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 167), sizeof v); (u32)v; });  // @44_431880
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[5], PV[4]);  // @45_431880
  ecx = edx = 0;  // @46_431880
  FL[2] = (eax & eax);  // @47_431880
  if (FL[2] != 0) goto L43192d;  // @48_431880
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @49_431880
  goto L431938;  // @50_431880
  L43192d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_431880
  ecx = (u32)(EBP - 32);  // @53_431880
  PV[6] = (u32)(ecx);  // @54_431880
  ecx = esi;  // @55_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[6]);  // @56_431880
  ecx = edx = 0;  // @57_431880
  L431938:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_431880
  ecx = (u32)(EBP - 32);  // @60_431880
  PV[7] = (u32)(ecx);  // @61_431880
  ecx = esi;  // @62_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[7]);  // @63_431880
  ecx = edx = 0;  // @64_431880
  edi = eax;  // @65_431880
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @66_431880
  FL[2] = (edi & edi);  // @67_431880
  if (FL[2] != 0) goto L4318e6;  // @68_431880
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 13), sizeof v); (u32)v; })) & 0xff);  // @69_431880
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @70_431880
  if (FL[2] == 0) goto L43196e;  // @71_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @72_431880
  SEH_LEAVE();  // @73_431880
  return eax;  // @74_431880
  L43196a:;
  edi = 0;  // @76_431880
  FL[3] = edi;  // @77_431880
  goto L431971;  // @78_431880
  L43196e:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @80_431880
  L431971:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_431880
  ecx = esi;  // @83_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @84_431880
  ecx = edx = 0;  // @85_431880
  esi = eax;  // @86_431880
  esi = (esi - (u32)(4));  // @87_431880
  FL[3] = esi;  // @88_431880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @89_431880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @90_431880
  reg.state = (s32)((u32)(0));  // @91_431880
  if (FL[3] == 0) goto L431997;  // @92_431880
  ecx = esi;  // @93_431880
  eax = ext_4cbeb0_thiscall1(ecx);  // @94_431880
  ecx = edx = 0;  // @95_431880
  goto L431999;  // @96_431880
  L431997:;
  esi = 0;  // @98_431880
  FL[3] = esi;  // @99_431880
  L431999:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 160), sizeof v); (u32)v; })) & 0xff);  // @101_431880
  ecx = esi;  // @102_431880
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @103_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 161), &v, sizeof v); }  // @104_431880
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 165), &v, sizeof v); }  // @105_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @106_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @107_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @108_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @109_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @110_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @111_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @112_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @113_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 167), sizeof v); (u32)v; });  // @114_431880
  PV[8] = (u32)(ebx);  // @115_431880
  reg.state = (s32)((u32)(4294967295));  // @116_431880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 167), &v, sizeof v); }  // @117_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 171), &v, sizeof v); }  // @118_431880
  eax = ext_4cbee0_thiscall2(ecx, PV[8]);  // @119_431880
  ecx = edx = 0;  // @120_431880
  eax = (u32)(edi + 1);  // @121_431880
  SEH_LEAVE();  // @122_431880
  return eax;  // @123_431880
}
PCREG(431880, lifted_431880);

extern "C" u32 THISCALL lifted_45da60(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6667e6);  // @h_45da60
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @1_45da60
  FL[2] = (eax & eax);  // @2_45da60
  if (FL[2] == 0) goto L45dc03;  // @3_45da60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_45da60
  edi = (edi & (u32)(344));  // @5_45da60
  FL[3] = edi;  // @6_45da60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @7_45da60
  if (FL[0] != FL[1]) goto L45db01;  // @8_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_45da60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1417));  // @11_45da60
  ecx = edx = 0;  // @12_45da60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_45da60
  edi = eax;  // @14_45da60
  eax = (u32)(EBP - 144);  // @15_45da60
  ecx = ebx;  // @16_45da60
  PV[0] = (u32)(eax);  // @17_45da60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[0], (u32)(1));  // @18_45da60
  ecx = edx = 0;  // @19_45da60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_45da60
  ecx = eax;  // @21_45da60
  reg.state = (s32)((u32)(0));  // @22_45da60
  eax = ext_4cc1d0_thiscall1(ecx);  // @23_45da60
  ecx = edx = 0;  // @24_45da60
  PV[1] = (u32)(eax);  // @25_45da60
  PV[2] = (u32)(edi);  // @26_45da60
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[2], (u32)(6836440), PV[1]);  // @27_45da60
  ecx = edx = 0;  // @28_45da60
  ecx = (u32)(EBP - 144);  // @29_45da60
  eax = ext_4cbec0_thiscall1(ecx);  // @30_45da60
  ecx = edx = 0;  // @31_45da60
  goto L45dc03;  // @32_45da60
  L45db01:;
  ecx = (u32)(EBP - 316);  // @34_45da60
  eax = ext_4ccba0_thiscall1(ecx);  // @35_45da60
  ecx = edx = 0;  // @36_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @37_45da60
  reg.state = (s32)((u32)(1));  // @38_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @39_45da60
  FL[2] = (ecx & ecx);  // @40_45da60
  if (FL[2] == 0) goto L45db6b;  // @41_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_45da60
  edx = (u32)(EBP - 328);  // @43_45da60
  PV[3] = (u32)(edx);  // @44_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @45_45da60
  ecx = edx = 0;  // @46_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @47_45da60
  edx = (u32)(EBP - 328);  // @48_45da60
  PV[4] = (u32)(edx);  // @49_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @50_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @52_45da60
  ecx = edx = 0;  // @53_45da60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @54_45da60
  if (FL[0] == FL[1]) goto L45db6b;  // @55_45da60
  L45db44:;
  PV[5] = (u32)(eax);  // @57_45da60
  ecx = (u32)(EBP - 316);  // @58_45da60
  eax = ext_4cd540_thiscall2(ecx, PV[5]);  // @59_45da60
  ecx = edx = 0;  // @60_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @61_45da60
  edx = (u32)(EBP - 328);  // @62_45da60
  PV[6] = (u32)(edx);  // @63_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @64_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @66_45da60
  ecx = edx = 0;  // @67_45da60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @68_45da60
  if (FL[0] != FL[1]) goto L45db44;  // @69_45da60
  L45db6b:;
  eax = (u32)(EBP - 328);  // @71_45da60
  PV[7] = (u32)(eax);  // @72_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @73_45da60
  ecx = (u32)(EBP - 316);  // @74_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @75_45da60
  ecx = edx = 0;  // @76_45da60
  eax = (u32)(EBP - 328);  // @77_45da60
  PV[8] = (u32)(eax);  // @78_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @79_45da60
  ecx = (u32)(EBP - 316);  // @80_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @81_45da60
  ecx = edx = 0;  // @82_45da60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @83_45da60
  if (FL[0] == FL[1]) goto L45dbf8;  // @84_45da60
  L45dba0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @86_45da60
  PV[9] = (u32)(eax);  // @87_45da60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[9]);  // @89_45da60
  ecx = edx = 0;  // @90_45da60
  esi = eax;  // @91_45da60
  FL[2] = (esi & esi);  // @92_45da60
  if (FL[2] == 0) goto L45dbd9;  // @93_45da60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @94_45da60
  if (FL[0] == FL[1]) goto L45dbd9;  // @95_45da60
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & edi);  // @96_45da60
  if (FL[2] == 0) goto L45dbd9;  // @97_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_45da60
  ecx = esi;  // @99_45da60
  PV[10] = (u32)(edi);  // @100_45da60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[10], (u32)(0));  // @101_45da60
  ecx = edx = 0;  // @102_45da60
  eax = edi;  // @103_45da60
  ecx = esi;  // @104_45da60
  eax = (~eax);  // @105_45da60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & eax)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @106_45da60
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @107_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_45da60
  PV[11] = (u32)(ebx);  // @109_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[11]);  // @110_45da60
  ecx = edx = 0;  // @111_45da60
  L45dbd9:;
  eax = (u32)(EBP - 328);  // @113_45da60
  PV[12] = (u32)(eax);  // @114_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @115_45da60
  ecx = (u32)(EBP - 316);  // @116_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[12]);  // @117_45da60
  ecx = edx = 0;  // @118_45da60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_45da60
  if (FL[0] != FL[1]) goto L45dba0;  // @120_45da60
  L45dbf8:;
  ecx = (u32)(EBP - 316);  // @122_45da60
  eax = ext_4ccf60_thiscall1(ecx);  // @123_45da60
  ecx = edx = 0;  // @124_45da60
  L45dc03:;
  SEH_LEAVE();  // @126_45da60
  ext_633654(G(u32, 0x6f5630));  // @127_45da60
  return eax;  // @128_45da60
}
PCREG(45da60, lifted_45da60);

extern "C" u32 THISCALL lifted_437210(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665a5d);  // @h_437210
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_437210
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_437210
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_437210
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[0]);  // @4_437210
  ecx = edx = 0;  // @5_437210
  FL[2] = (eax & eax);  // @6_437210
  if (FL[2] == 0) goto L4372a3;  // @7_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @8_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_437210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2627));  // @10_437210
  ecx = edx = 0;  // @11_437210
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @13_437210
  PV[2] = (u32)(eax);  // @14_437210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6794008), PV[1]);  // @15_437210
  ecx = edx = 0;  // @16_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @17_437210
  FL[2] = (eax & eax);  // @18_437210
  if (FL[2] == 0) goto L43728c;  // @19_437210
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_437210
  ecx = edx = 0;  // @21_437210
  eax = 0;  // @22_437210
  FL[3] = eax;  // @23_437210
  SEH_LEAVE();  // @24_437210
  return eax;  // @25_437210
  L43728c:;
  __builtin_trap();  // @27_437210
  L4372a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @29_437210
  FL[2] = ((eax & 0xff) & (u32)(2));  // @30_437210
  if (FL[2] == 0) goto L4372cf;  // @31_437210
  eax = ext_41e290_cdecl1((u32)(18));  // @32_437210
  ecx = edx = 0;  // @33_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @34_437210
  reg.state = (s32)((u32)(0));  // @35_437210
  FL[2] = (eax & eax);  // @36_437210
  if (FL[2] == 0) goto L4372f8;  // @37_437210
  PV[3] = (u32)(esi);  // @38_437210
  PV[4] = (u32)(ebx);  // @39_437210
  ecx = eax;  // @40_437210
  eax = ext_4369a0_thiscall3(ecx, PV[4], PV[3]);  // @41_437210
  ecx = edx = 0;  // @42_437210
  edi = eax;  // @43_437210
  goto L4372fa;  // @44_437210
  L4372cf:;
  FL[2] = ((eax & 0xff) & (u32)(8));  // @46_437210
  if (FL[2] == 0) goto L43731d;  // @47_437210
  eax = ext_41e290_cdecl1((u32)(26));  // @48_437210
  ecx = edx = 0;  // @49_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @50_437210
  reg.state = (s32)((u32)(1));  // @51_437210
  FL[2] = (eax & eax);  // @52_437210
  if (FL[2] == 0) goto L4372f8;  // @53_437210
  PV[5] = (u32)(esi);  // @54_437210
  PV[6] = (u32)(ebx);  // @55_437210
  ecx = eax;  // @56_437210
  eax = ext_436b30_thiscall3(ecx, PV[6], PV[5]);  // @57_437210
  ecx = edx = 0;  // @58_437210
  edi = eax;  // @59_437210
  goto L4372fa;  // @60_437210
  L4372f8:;
  edi = 0;  // @62_437210
  FL[3] = edi;  // @63_437210
  L4372fa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @65_437210
  PV[7] = (u32)(edi);  // @66_437210
  reg.state = (s32)((u32)(4294967295));  // @67_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_437210
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7]);  // @69_437210
  ecx = edx = 0;  // @70_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @71_437210
  PV[8] = (u32)(edi);  // @72_437210
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @74_437210
  eax = ext_4d9350_thiscall3(ecx, PV[9], PV[8]);  // @75_437210
  ecx = edx = 0;  // @76_437210
  goto L437380;  // @77_437210
  L43731d:;
  eax = ext_41e290_cdecl1((u32)(74));  // @79_437210
  ecx = edx = 0;  // @80_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @81_437210
  reg.state = (s32)((u32)(2));  // @82_437210
  FL[2] = (eax & eax);  // @83_437210
  if (FL[2] == 0) goto L437343;  // @84_437210
  PV[10] = (u32)(esi);  // @85_437210
  ecx = (u32)(ebx + 4);  // @86_437210
  PV[11] = (u32)(ecx);  // @87_437210
  ecx = eax;  // @88_437210
  eax = ext_4367b0_thiscall3(ecx, PV[11], PV[10]);  // @89_437210
  ecx = edx = 0;  // @90_437210
  goto L437345;  // @91_437210
  L437343:;
  eax = 0;  // @93_437210
  FL[3] = eax;  // @94_437210
  L437345:;
  ecx = 0;  // @96_437210
  FL[3] = ecx;  // @97_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @98_437210
  edi = (u32)(eax + 4);  // @99_437210
  reg.state = (s32)((u32)(4294967295));  // @100_437210
  FL[2] = (eax & eax);  // @101_437210
  esi = edi;  // @102_437210
  if (FL[2] == 0) esi = ecx;  // @103_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @104_437210
  PV[12] = (u32)(esi);  // @105_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_437210
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[12]);  // @107_437210
  ecx = edx = 0;  // @108_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @109_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @110_437210
  PV[13] = (u32)(esi);  // @111_437210
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @112_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @113_437210
  eax = ext_4d9350_thiscall3(ecx, PV[14], PV[13]);  // @114_437210
  ecx = edx = 0;  // @115_437210
  eax = 0;  // @116_437210
  FL[3] = eax;  // @117_437210
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = eax;  // @118_437210
  if (FL[0] == FL[1]) edi = eax;  // @119_437210
  L437380:;
  eax = edi;  // @121_437210
  SEH_LEAVE();  // @122_437210
  return eax;  // @123_437210
}
PCREG(437210, lifted_437210);

extern "C" u32 THISCALL lifted_636020(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  SEH_ENTER(0x66e74b);  // @h_636020
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  edi = ecx;  // @0_636020
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @1_636020
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @2_636020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_636020
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @5_636020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @6_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @7_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @8_636020
  { u32 v = (u32)((u32)(1380401729)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @9_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @10_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @11_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @12_636020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @13_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 41), &v, sizeof v); }  // @14_636020
  { u32 v = (u32)((u32)(7086356)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @15_636020
  reg.state = (s32)((u32)(0));  // @16_636020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @17_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @18_636020
  eax = ext_639c50_thiscall2(ecx, (u32)(1));  // @19_636020
  ecx = edx = 0;  // @20_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @21_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @22_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @23_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @24_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @25_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @26_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @27_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @28_636020
  eax = (u32)(EBP - 112);  // @29_636020
  PV[0] = (u32)(eax);  // @30_636020
  ecx = eax;  // @31_636020
  eax = ext_4d06a0_stdcall1(PV[0]);  // @32_636020
  ecx = edx = 0;  // @33_636020
  eax = (u32)(EBP - 64);  // @34_636020
  { u32 v = (u32)((u32)(255)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @35_636020
  PV[1] = (u32)(eax);  // @36_636020
  ecx = (u32)(EBP - 112);  // @37_636020
  { u32 v = (u32)((u32)(65280)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @38_636020
  { u32 v = (u32)((u32)(16711680)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @39_636020
  { u32 v = (u32)((u32)(4278190080)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @40_636020
  eax = ext_4d06a0_stdcall1(PV[1]);  // @41_636020
  ecx = edx = 0;  // @42_636020
  esi = ebx;  // @43_636020
  ecx = 0;  // @44_636020
  FL[3] = ecx;  // @45_636020
  esi = (u32)((s32)esi * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; }));  // @46_636020
  FL[3] = esi;  // @47_636020
  edx = (u32)(4);  // @48_636020
  eax = esi;  // @49_636020
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @50_636020
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @51_636020
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @52_636020
  ecx = (0u - ecx);  // @53_636020
  ecx = (ecx | eax);  // @54_636020
  FL[3] = ecx;  // @55_636020
  PV[2] = (u32)(ecx);  // @56_636020
  eax = ext_41e290_cdecl1(PV[2]);  // @57_636020
  ecx = edx = 0;  // @58_636020
  ebx = eax;  // @59_636020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @60_636020
  FL[2] = (esi & esi);  // @61_636020
  if ((s32)FL[2] <= 0) goto L636153;  // @62_636020
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @63_636020
  esi = ebx;  // @64_636020
  edi = (edi - ebx);  // @65_636020
  FL[3] = edi;  // @66_636020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @67_636020
  L636132:;
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @69_636020
  ecx = (u32)(EBP - 112);  // @70_636020
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi), sizeof v); (u32)v; });  // @71_636020
  eax = ext_639df0_thiscall3(ecx, PV[4], PV[3]);  // @72_636020
  ecx = edx = 0;  // @73_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @74_636020
  esi = (u32)(esi + 4);  // @75_636020
  ebx = (ebx - (u32)(1));  // @76_636020
  FL[3] = ebx;  // @77_636020
  if (FL[3] != 0) goto L636132;  // @78_636020
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @79_636020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @80_636020
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @81_636020
  L636153:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @83_636020
  esi = (esi << (u32)(2));  // @84_636020
  FL[3] = esi;  // @85_636020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @86_636020
  if (FL[0] == FL[1]) goto L636173;  // @87_636020
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @88_636020
  eax = ext_634273_cdecl2(PV[5], (u32)(1));  // @89_636020
  ecx = edx = 0;  // @90_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @91_636020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @92_636020
  L636173:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @94_636020
  PV[6] = (u32)(esi);  // @95_636020
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @96_636020
  eax = ext_41e290_cdecl1(PV[6]);  // @97_636020
  ecx = edx = 0;  // @98_636020
  ecx = eax;  // @99_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @100_636020
  PV[7] = (u32)(esi);  // @101_636020
  PV[8] = (u32)(ebx);  // @102_636020
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @103_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @104_636020
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @105_636020
  eax = ext_634d22_cdecl3(PV[9], PV[8], PV[7]);  // @106_636020
  ecx = edx = 0;  // @107_636020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @108_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @109_636020
  PV[10] = (u32)(ebx);  // @110_636020
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @111_636020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @112_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @113_636020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @114_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @115_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @116_636020
  eax = ext_634273_cdecl2(PV[10], (u32)(4));  // @117_636020
  ecx = edx = 0;  // @118_636020
  eax = edi;  // @119_636020
  SEH_LEAVE();  // @120_636020
  ext_633654(G(u32, 0x6f5630));  // @121_636020
  return eax;  // @122_636020
}
PCREG(636020, lifted_636020);

extern "C" u32 THISCALL lifted_602000(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d93f);  // @h_602000
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_602000
  eax = ext_41e290_cdecl1((u32)(4));  // @1_602000
  ecx = edx = 0;  // @2_602000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_602000
  reg.state = (s32)((u32)(0));  // @4_602000
  FL[2] = (eax & eax);  // @5_602000
  if (FL[2] == 0) goto L602058;  // @6_602000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @7_602000
  X0[1] = 0;  // @8_602000
  X0[2] = 0;  // @9_602000
  X0[3] = 0;  // @10_602000
  PV[0] = (u32)(ecx);  // @11_602000
  ecx = eax;  // @12_602000
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @13_602000
  eax = ext_600e40_thiscall3(ecx, PV[1], X0[0]);  // @14_602000
  ecx = edx = 0;  // @15_602000
  edi = eax;  // @16_602000
  goto L60205a;  // @17_602000
  L602058:;
  edi = 0;  // @19_602000
  FL[3] = edi;  // @20_602000
  L60205a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @22_602000
  reg.state = (s32)((u32)(4294967295));  // @23_602000
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @24_602000
  if (FL[0] < FL[1]) goto L602071;  // @25_602000
  ecx = (u32)(esi + 4);  // @26_602000
  eax = ext_5f4630_thiscall1(ecx);  // @27_602000
  ecx = edx = 0;  // @28_602000
  L602071:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @30_602000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @31_602000
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @32_602000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @33_602000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @34_602000
  SEH_LEAVE();  // @35_602000
  return eax;  // @36_602000
}
PCREG(602000, lifted_602000);

extern "C" u32 THISCALL lifted_4614d0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6668cf);  // @h_4614d0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_4614d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4614d0
  if (FL[0] != FL[1]) goto L46152d;  // @2_4614d0
  eax = ext_41e290_cdecl1((u32)(44));  // @3_4614d0
  ecx = edx = 0;  // @4_4614d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_4614d0
  reg.state = (s32)((u32)(0));  // @6_4614d0
  FL[2] = (eax & eax);  // @7_4614d0
  if (FL[2] == 0) goto L461521;  // @8_4614d0
  ecx = eax;  // @9_4614d0
  eax = ext_4ccad0_thiscall3(ecx, (u32)(32), (u32)(3));  // @10_4614d0
  ecx = edx = 0;  // @11_4614d0
  goto L461523;  // @12_4614d0
  L461521:;
  eax = 0;  // @14_4614d0
  FL[3] = eax;  // @15_4614d0
  L461523:;
  reg.state = (s32)((u32)(4294967295));  // @17_4614d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @18_4614d0
  L46152d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @20_4614d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @21_4614d0
  X0[1] = 0;  // @22_4614d0
  X0[2] = 0;  // @23_4614d0
  X0[3] = 0;  // @24_4614d0
  PV[0] = (u32)(ecx);  // @25_4614d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4614d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, (u32)(0), X0[0], (u32)(0));  // @27_4614d0
  ecx = edx = 0;  // @28_4614d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @29_4614d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @30_4614d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_4614d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @32_4614d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @33_4614d0
  SEH_LEAVE();  // @34_4614d0
  return eax;  // @35_4614d0
}
PCREG(4614d0, lifted_4614d0);

extern "C" u32 THISCALL lifted_523cc0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_523cc0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_523cc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_523cc0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @2_523cc0
  FL[2] = (edx & edx);  // @3_523cc0
  if (FL[2] == 0) goto L523deb;  // @4_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_523cc0
  PV[0] = (u32)(edx);  // @6_523cc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_523cc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @9_523cc0
  ecx = edx = 0;  // @10_523cc0
  ecx = eax;  // @11_523cc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @13_523cc0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(67108898));  // @14_523cc0
  ecx = edx = 0;  // @15_523cc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @16_523cc0
  if (FL[2] != 0) goto L523da6;  // @17_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_523cc0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @19_523cc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_523cc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @22_523cc0
  ecx = edx = 0;  // @23_523cc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @24_523cc0
  esi = eax;  // @25_523cc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_523cc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6948728), (u32)(231));  // @27_523cc0
  ecx = edx = 0;  // @28_523cc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_523cc0
  edi = eax;  // @30_523cc0
  eax = (u32)(EBP - 144);  // @31_523cc0
  ecx = esi;  // @32_523cc0
  PV[2] = (u32)(eax);  // @33_523cc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[2], (u32)(1));  // @34_523cc0
  ecx = edx = 0;  // @35_523cc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_523cc0
  ecx = eax;  // @37_523cc0
  reg.state = (s32)((u32)(0));  // @38_523cc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @39_523cc0
  ecx = edx = 0;  // @40_523cc0
  PV[3] = (u32)(eax);  // @41_523cc0
  PV[4] = (u32)(edi);  // @42_523cc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[4], (u32)(6948852), PV[3]);  // @43_523cc0
  ecx = edx = 0;  // @44_523cc0
  reg.state = (s32)((u32)(4294967295));  // @45_523cc0
  ecx = (u32)(EBP - 144);  // @46_523cc0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_523cc0
  ecx = edx = 0;  // @48_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @49_523cc0
  FL[2] = (eax & eax);  // @50_523cc0
  if (FL[2] == 0) goto L523da5;  // @51_523cc0
  eax = ((u32(STDCALL *)(void))(eax))();  // @52_523cc0
  ecx = edx = 0;  // @53_523cc0
  goto L523da6;  // @54_523cc0
  L523da5:;
  __builtin_trap();  // @56_523cc0
  L523da6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_523cc0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @59_523cc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_523cc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[5]);  // @62_523cc0
  ecx = edx = 0;  // @63_523cc0
  FL[2] = (eax & eax);  // @64_523cc0
  if (FL[2] == 0) goto L523de4;  // @65_523cc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @66_523cc0
  X0[1] = 0;  // @67_523cc0
  X0[2] = 0;  // @68_523cc0
  X0[3] = 0;  // @69_523cc0
  PV[6] = (u32)(ecx);  // @70_523cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 75), &v, sizeof v); }  // @71_523cc0
  ecx = ebx;  // @72_523cc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 79), &v, sizeof v); }  // @73_523cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @74_523cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 83), &v, sizeof v); }  // @75_523cc0
  eax = ext_523650_thiscall2(ecx, X0[0]);  // @76_523cc0
  ecx = edx = 0;  // @77_523cc0
  goto L523deb;  // @78_523cc0
  L523de4:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 75), &v, sizeof v); }  // @80_523cc0
  L523deb:;
  SEH_LEAVE();  // @82_523cc0
  ext_633654(G(u32, 0x6f5630));  // @83_523cc0
  return eax;  // @84_523cc0
}
PCREG(523cc0, lifted_523cc0);

extern "C" u32 THISCALL lifted_4634f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6669bf);  // @h_4634f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4634f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4634f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4634f0
  ecx = ebx;  // @3_4634f0
  PV[0] = (u32)(edi);  // @4_4634f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_4634f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[0], (u32)(108));  // @6_4634f0
  ecx = edx = 0;  // @7_4634f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_4634f0
  ecx = ebx;  // @9_4634f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @10_4634f0
  ecx = edx = 0;  // @11_4634f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 112), &v, sizeof v); }  // @12_4634f0
  ecx = ebx;  // @13_4634f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_4634f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @15_4634f0
  ecx = edx = 0;  // @16_4634f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @17_4634f0
  ecx = (u32)(EBP + 8);  // @18_4634f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_4634f0
  PV[1] = (u32)(ecx);  // @20_4634f0
  ecx = ebx;  // @21_4634f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[1]);  // @22_4634f0
  ecx = edx = 0;  // @23_4634f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @24_4634f0
  if (FL[0] == FL[1]) goto L463603;  // @25_4634f0
  eax = ext_41e290_cdecl1((u32)(44));  // @26_4634f0
  ecx = edx = 0;  // @27_4634f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @28_4634f0
  reg.state = (s32)((u32)(0));  // @29_4634f0
  FL[2] = (eax & eax);  // @30_4634f0
  if (FL[2] == 0) goto L463578;  // @31_4634f0
  ecx = eax;  // @32_4634f0
  eax = ext_4ccad0_thiscall3(ecx, (u32)(32), (u32)(3));  // @33_4634f0
  ecx = edx = 0;  // @34_4634f0
  goto L46357a;  // @35_4634f0
  L463578:;
  eax = 0;  // @37_4634f0
  FL[3] = eax;  // @38_4634f0
  L46357a:;
  esi = 0;  // @40_4634f0
  FL[3] = esi;  // @41_4634f0
  reg.state = (s32)((u32)(4294967295));  // @42_4634f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @43_4634f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = esi;  // @44_4634f0
  if (FL[0] == FL[1]) goto L46360a;  // @45_4634f0
  L463590:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_4634f0
  ecx = (u32)(EBP - 20);  // @48_4634f0
  PV[2] = (u32)(ecx);  // @49_4634f0
  ecx = ebx;  // @50_4634f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[2]);  // @51_4634f0
  ecx = edx = 0;  // @52_4634f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; });  // @53_4634f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @54_4634f0
  X0[1] = 0;  // @55_4634f0
  X0[2] = 0;  // @56_4634f0
  X0[3] = 0;  // @57_4634f0
  PV[3] = (u32)(ecx);  // @58_4634f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4634f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, (u32)(0), X0[0], (u32)(0));  // @60_4634f0
  ecx = edx = 0;  // @61_4634f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_4634f0
  ecx = ebx;  // @63_4634f0
  edi = (u32)(eax - 4);  // @64_4634f0
  PV[4] = (u32)(edi);  // @65_4634f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[4]);  // @66_4634f0
  ecx = edx = 0;  // @67_4634f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_4634f0
  ecx = (u32)(edi + 4);  // @69_4634f0
  PV[5] = (u32)(ecx);  // @70_4634f0
  ecx = ebx;  // @71_4634f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[5]);  // @72_4634f0
  ecx = edx = 0;  // @73_4634f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_4634f0
  ecx = (u32)(EBP - 24);  // @75_4634f0
  PV[6] = (u32)(ecx);  // @76_4634f0
  ecx = ebx;  // @77_4634f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[6]);  // @78_4634f0
  ecx = edx = 0;  // @79_4634f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @80_4634f0
  FL[2] = (edx & edx);  // @81_4634f0
  if (FL[2] == 0) goto L4635f1;  // @82_4634f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @83_4634f0
  PV[7] = (u32)(edx);  // @84_4634f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 116), sizeof v); (u32)v; });  // @85_4634f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_4634f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, PV[7]);  // @87_4634f0
  ecx = edx = 0;  // @88_4634f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @89_4634f0
  goto L4635f8;  // @90_4634f0
  L4635f1:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @92_4634f0
  L4635f8:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @94_4634f0
  esi = (esi + 1);  // @95_4634f0
  FL[3] = esi;  // @96_4634f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @97_4634f0
  if (FL[0] != FL[1]) goto L463590;  // @98_4634f0
  goto L46360a;  // @99_4634f0
  L463603:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @101_4634f0
  L46360a:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @103_4634f0
  SEH_LEAVE();  // @104_4634f0
  return eax;  // @105_4634f0
}
PCREG(4634f0, lifted_4634f0);

extern "C" u32 THISCALL lifted_485730(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6675f7);  // @h_485730
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_485730
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_485730
  ecx = (u32)(EBP - 104);  // @2_485730
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @3_485730
  ecx = edx = 0;  // @4_485730
  eax = (u32)(EBP - 104);  // @5_485730
  reg.state = (s32)((u32)(0));  // @6_485730
  PV[0] = (u32)(eax);  // @7_485730
  ecx = esi;  // @8_485730
  eax = ext_4e6330_thiscall2(ecx, PV[0]);  // @9_485730
  ecx = edx = 0;  // @10_485730
  ecx = esi;  // @11_485730
  eax = ext_4e5e60_thiscall1(ecx);  // @12_485730
  ecx = edx = 0;  // @13_485730
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 80), &v, sizeof v); }  // @14_485730
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @15_485730
  eax = ext_41e290_cdecl1((u32)(28));  // @16_485730
  ecx = edx = 0;  // @17_485730
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @18_485730
  reg.state = (s32)((u32)(1));  // @19_485730
  FL[2] = (eax & eax);  // @20_485730
  if (FL[2] == 0) goto L4857b1;  // @21_485730
  ecx = eax;  // @22_485730
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(12));  // @23_485730
  ecx = edx = 0;  // @24_485730
  goto L4857b3;  // @25_485730
  L4857b1:;
  eax = 0;  // @27_485730
  FL[3] = eax;  // @28_485730
  L4857b3:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @30_485730
  ecx = (u32)(EBP - 104);  // @31_485730
  eax = (u32)(EBP - 76);  // @32_485730
  reg.state = (s32)((u32)(0));  // @33_485730
  PV[1] = (u32)(eax);  // @34_485730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @35_485730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @36_485730
  ecx = edx = 0;  // @37_485730
  eax = (u32)(EBP - 76);  // @38_485730
  PV[2] = (u32)(eax);  // @39_485730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @40_485730
  ecx = (u32)(EBP - 104);  // @41_485730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @42_485730
  ecx = edx = 0;  // @43_485730
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @44_485730
  if (FL[0] == FL[1]) goto L48585d;  // @45_485730
  L4857e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_485730
  PV[3] = (u32)(eax);  // @48_485730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @49_485730
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_485730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[3]);  // @51_485730
  ecx = edx = 0;  // @52_485730
  edi = eax;  // @53_485730
  FL[2] = (edi & edi);  // @54_485730
  if (FL[2] == 0) goto L48584a;  // @55_485730
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_485730
  eax = (u32)(EBP - 28);  // @57_485730
  PV[4] = (u32)(eax);  // @58_485730
  eax = (u32)(EBP - 64);  // @59_485730
  ecx = edi;  // @60_485730
  PV[5] = (u32)(eax);  // @61_485730
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[5], PV[4]);  // @62_485730
  ecx = edx = 0;  // @63_485730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @64_485730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_485730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @66_485730
  ecx = edx = 0;  // @67_485730
  esi = eax;  // @68_485730
  edx = (u32)(EBP - 64);  // @69_485730
  ecx = esi;  // @70_485730
  eax = ext_4de420_fastcall2(ecx, edx);  // @71_485730
  ecx = edx = 0;  // @72_485730
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @73_485730
  X0[1] = 0;  // @74_485730
  X0[2] = 0;  // @75_485730
  X0[3] = 0;  // @76_485730
  ecx = edi;  // @77_485730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_485730
  __builtin_memcpy((void *)((u32)(esi + 36) + 0), &X0[0], 4);  // @79_485730
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @80_485730
  X0[1] = 0;  // @81_485730
  X0[2] = 0;  // @82_485730
  X0[3] = 0;  // @83_485730
  __builtin_memcpy((void *)((u32)(esi + 40) + 0), &X0[0], 4);  // @84_485730
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @85_485730
  X0[1] = 0;  // @86_485730
  X0[2] = 0;  // @87_485730
  X0[3] = 0;  // @88_485730
  __builtin_memcpy((void *)((u32)(esi + 44) + 0), &X0[0], 4);  // @89_485730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @90_485730
  ecx = edx = 0;  // @91_485730
  L48584a:;
  eax = (u32)(EBP - 76);  // @93_485730
  PV[6] = (u32)(eax);  // @94_485730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @95_485730
  ecx = (u32)(EBP - 104);  // @96_485730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @97_485730
  ecx = edx = 0;  // @98_485730
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @99_485730
  if (FL[0] != FL[1]) goto L4857e0;  // @100_485730
  L48585d:;
  ecx = (u32)(EBP - 104);  // @102_485730
  eax = ext_4ccfe0_thiscall1(ecx);  // @103_485730
  ecx = edx = 0;  // @104_485730
  SEH_LEAVE();  // @105_485730
  ext_633654(G(u32, 0x6f5630));  // @106_485730
  return eax;  // @107_485730
}
PCREG(485730, lifted_485730);

extern "C" u32 THISCALL lifted_49a300(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66828f);  // @h_49a300
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_49a300
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_49a300
  if (FL[0] != FL[1]) goto L49a35e;  // @2_49a300
  eax = ext_41e290_cdecl1((u32)(44));  // @3_49a300
  ecx = edx = 0;  // @4_49a300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_49a300
  reg.state = (s32)((u32)(0));  // @6_49a300
  FL[2] = (eax & eax);  // @7_49a300
  if (FL[2] == 0) goto L49a352;  // @8_49a300
  ecx = eax;  // @9_49a300
  eax = ext_4ccad0_thiscall3(ecx, (u32)(8), (u32)(4));  // @10_49a300
  ecx = edx = 0;  // @11_49a300
  goto L49a354;  // @12_49a300
  L49a352:;
  eax = 0;  // @14_49a300
  FL[3] = eax;  // @15_49a300
  L49a354:;
  reg.state = (s32)((u32)(4294967295));  // @17_49a300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @18_49a300
  L49a35e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @20_49a300
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_49a300
  PV[0] = (u32)(edi);  // @22_49a300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_49a300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[0]);  // @24_49a300
  ecx = edx = 0;  // @25_49a300
  FL[2] = (eax & eax);  // @26_49a300
  if (FL[2] == 0) goto L49a387;  // @27_49a300
  eax = (eax + (u32)(4));  // @28_49a300
  FL[3] = eax;  // @29_49a300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @30_49a300
  SEH_LEAVE();  // @31_49a300
  return eax;  // @32_49a300
  L49a387:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @34_49a300
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @35_49a300
  X0[0] = F2U((float)(s32)X0[0]);  // @36_49a300
  X0[1] = F2U((float)(s32)X0[1]);  // @37_49a300
  X0[2] = F2U((float)(s32)X0[2]);  // @38_49a300
  X0[3] = F2U((float)(s32)X0[3]);  // @39_49a300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_49a300
  PV[1] = (u32)(ecx);  // @41_49a300
  PV[2] = (u32)(edi);  // @42_49a300
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[2], X0[0], (u32)(0));  // @43_49a300
  ecx = edx = 0;  // @44_49a300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @45_49a300
  FL[2] = (eax & eax);  // @46_49a300
  if (FL[2] == 0) goto L49a3c0;  // @47_49a300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @48_49a300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @49_49a300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @50_49a300
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @51_49a300
  L49a3c0:;
  SEH_LEAVE();  // @53_49a300
  return eax;  // @54_49a300
}
PCREG(49a300, lifted_49a300);

extern "C" u32 THISCALL lifted_4c44f0(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_4c44f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4c44f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 126), sizeof v); (u32)v; });  // @2_4c44f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4c44f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @5_4c44f0
  ecx = edx = 0;  // @6_4c44f0
  esi = eax;  // @7_4c44f0
  FL[2] = (esi & esi);  // @8_4c44f0
  if (FL[2] == 0) goto L4c45a7;  // @9_4c44f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_4c44f0
  ecx = esi;  // @11_4c44f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @12_4c44f0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2097381));  // @13_4c44f0
  ecx = edx = 0;  // @14_4c44f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @15_4c44f0
  if (FL[2] == 0) goto L4c45a7;  // @16_4c44f0
  eax = (u32)(ebx + 134);  // @17_4c44f0
  ecx = esi;  // @18_4c44f0
  PV[1] = (u32)(eax);  // @19_4c44f0
  eax = (u32)(ebx + 130);  // @20_4c44f0
  PV[2] = (u32)(eax);  // @21_4c44f0
  eax = ext_456b70_thiscall3(ecx, PV[2], PV[1]);  // @22_4c44f0
  ecx = edx = 0;  // @23_4c44f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 162), &v, sizeof v); }  // @24_4c44f0
  L4c4570:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 40) + 0), 4); v; });  // @26_4c44f0
  X0[1] = 0;  // @27_4c44f0
  X0[2] = 0;  // @28_4c44f0
  X0[3] = 0;  // @29_4c44f0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 162) + 0), 4); v; })));  // @30_4c44f0
  __builtin_memcpy((void *)((u32)(ebx + 162) + 0), &X0[0], 4);  // @31_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4c44f0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; });  // @33_4c44f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4c44f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @36_4c44f0
  ecx = edx = 0;  // @37_4c44f0
  esi = eax;  // @38_4c44f0
  FL[2] = (esi & esi);  // @39_4c44f0
  if (FL[2] != 0) goto L4c4570;  // @40_4c44f0
  ecx = ebx;  // @41_4c44f0
  eax = ext_4c3e80_thiscall1(ecx);  // @42_4c44f0
  ecx = edx = 0;  // @43_4c44f0
  goto L4c4608;  // @44_4c44f0
  L4c45a7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @46_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4c44f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6897740), (u32)(201));  // @48_4c44f0
  ecx = edx = 0;  // @49_4c44f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @50_4c44f0
  edi = eax;  // @51_4c44f0
  eax = (u32)(EBP - 144);  // @52_4c44f0
  PV[4] = (u32)(eax);  // @53_4c44f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4c44f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[4], (u32)(1));  // @55_4c44f0
  ecx = edx = 0;  // @56_4c44f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @57_4c44f0
  ecx = eax;  // @58_4c44f0
  reg.state = (s32)((u32)(0));  // @59_4c44f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @60_4c44f0
  ecx = edx = 0;  // @61_4c44f0
  PV[5] = (u32)(eax);  // @62_4c44f0
  PV[6] = (u32)(edi);  // @63_4c44f0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[6], (u32)(6897844), PV[5]);  // @64_4c44f0
  ecx = edx = 0;  // @65_4c44f0
  reg.state = (s32)((u32)(4294967295));  // @66_4c44f0
  ecx = (u32)(EBP - 144);  // @67_4c44f0
  eax = ext_4cbec0_thiscall1(ecx);  // @68_4c44f0
  ecx = edx = 0;  // @69_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @70_4c44f0
  ecx = ebx;  // @71_4c44f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @72_4c44f0
  ecx = edx = 0;  // @73_4c44f0
  L4c4608:;
  SEH_LEAVE();  // @75_4c44f0
  ext_633654(G(u32, 0x6f5630));  // @76_4c44f0
  return eax;  // @77_4c44f0
}
PCREG(4c44f0, lifted_4c44f0);

extern "C" u32 THISCALL lifted_45a270(u32 ecx_in) {
  SEH_ENTER(0x6664cb);  // @h_45a270
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_45a270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @1_45a270
  esi = 0;  // @2_45a270
  FL[3] = esi;  // @3_45a270
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @4_45a270
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @5_45a270
  FL[2] = (eax & eax);  // @6_45a270
  if (FL[2] == 0) goto L45a3ce;  // @7_45a270
  L45a2b5:;
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @9_45a270
  if (FL[0] == FL[1]) goto L45a313;  // @10_45a270
  esi = (esi + 1);  // @11_45a270
  FL[3] = esi;  // @12_45a270
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @13_45a270
  if (FL[2] == 0) goto L45a2e3;  // @14_45a270
  ecx = (u32)(EBP - 40);  // @15_45a270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @16_45a270
  PV[0] = (u32)(ecx);  // @17_45a270
  ecx = eax;  // @18_45a270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @19_45a270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @20_45a270
  eax = ext_4db670_thiscall2(ecx, PV[0]);  // @21_45a270
  ecx = edx = 0;  // @22_45a270
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @23_45a270
  FL[3] = (ebx & 0xff);  // @24_45a270
  goto L45a313;  // @25_45a270
  L45a2e3:;
  ecx = (u32)(EBP - 28);  // @27_45a270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @28_45a270
  PV[1] = (u32)(ecx);  // @29_45a270
  ecx = eax;  // @30_45a270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @31_45a270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @32_45a270
  eax = ext_4db670_thiscall2(ecx, PV[1]);  // @33_45a270
  ecx = edx = 0;  // @34_45a270
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @35_45a270
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @36_45a270
  X0[2] = 0;  // @37_45a270
  X0[3] = 0;  // @38_45a270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @39_45a270
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @40_45a270
  __builtin_memcpy((void *)((u32)(EBP - 40) + 4), &X0[1], 4);  // @41_45a270
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @42_45a270
  L45a313:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_45a270
  ecx = (u32)(EBP - 232);  // @45_45a270
  PV[2] = (u32)(ecx);  // @46_45a270
  ecx = edi;  // @47_45a270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[2]);  // @48_45a270
  ecx = edx = 0;  // @49_45a270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; });  // @50_45a270
  FL[2] = (eax & eax);  // @51_45a270
  if (FL[2] != 0) goto L45a2b5;  // @52_45a270
  FL[0] = esi; FL[1] = (u32)(1);  // @53_45a270
  if (FL[0] != FL[1]) goto L45a3ce;  // @54_45a270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @55_45a270
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @56_45a270
  FL[2] = (ecx & ecx);  // @57_45a270
  if (FL[2] == 0) goto L45a3ce;  // @58_45a270
  L45a345:;
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @60_45a270
  if (FL[0] != FL[1]) goto L45a364;  // @61_45a270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_45a270
  ecx = (u32)(EBP - 232);  // @63_45a270
  PV[3] = (u32)(ecx);  // @64_45a270
  ecx = edi;  // @65_45a270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[3]);  // @66_45a270
  ecx = edx = 0;  // @67_45a270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; });  // @68_45a270
  FL[2] = (ecx & ecx);  // @69_45a270
  if (FL[2] != 0) goto L45a345;  // @70_45a270
  goto L45a3ce;  // @71_45a270
  L45a364:;
  eax = (u32)(EBP - 64);  // @73_45a270
  PV[4] = (u32)(eax);  // @74_45a270
  eax = (u32)(EBP - 100);  // @75_45a270
  PV[5] = (u32)(eax);  // @76_45a270
  eax = ext_4db6c0_thiscall3(ecx, PV[5], PV[4]);  // @77_45a270
  ecx = edx = 0;  // @78_45a270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_45a270
  ecx = (u32)(EBP - 228);  // @80_45a270
  PV[6] = (u32)(ecx);  // @81_45a270
  ecx = edi;  // @82_45a270
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @83_45a270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @84_45a270
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @85_45a270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[6], (u32)(0));  // @86_45a270
  ecx = edx = 0;  // @87_45a270
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_45a270
  ecx = eax;  // @89_45a270
  reg.state = (s32)((u32)(0));  // @90_45a270
  eax = ext_4cc1d0_thiscall1(ecx);  // @91_45a270
  ecx = edx = 0;  // @92_45a270
  PV[7] = (u32)(eax);  // @93_45a270
  eax = (u32)(EBP - 52);  // @94_45a270
  ecx = edi;  // @95_45a270
  PV[8] = (u32)(eax);  // @96_45a270
  eax = (u32)(EBP - 64);  // @97_45a270
  PV[9] = (u32)(eax);  // @98_45a270
  eax = (u32)(EBP - 100);  // @99_45a270
  PV[10] = (u32)(eax);  // @100_45a270
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 584)))(ecx, PV[10], PV[9], PV[8], (u32)(12615808), PV[7]);  // @101_45a270
  ecx = edx = 0;  // @102_45a270
  ecx = (u32)(EBP - 228);  // @103_45a270
  eax = ext_4cbec0_thiscall1(ecx);  // @104_45a270
  ecx = edx = 0;  // @105_45a270
  L45a3ce:;
  SEH_LEAVE();  // @107_45a270
  ext_633654(G(u32, 0x6f5630));  // @108_45a270
  return eax;  // @109_45a270
}
PCREG(45a270, lifted_45a270);

extern "C" u32 THISCALL lifted_477de0(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_477de0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_477de0
  eax = ext_472fd0_thiscall1(ecx);  // @1_477de0
  ecx = edx = 0;  // @2_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_477de0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_477de0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @6_477de0
  ecx = edx = 0;  // @7_477de0
  ecx = (u32)(EBP - 152);  // @8_477de0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @9_477de0
  PV[0] = (u32)(ecx);  // @10_477de0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @11_477de0
  ecx = eax;  // @12_477de0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6859232), PV[0]);  // @13_477de0
  ecx = edx = 0;  // @14_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_477de0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @16_477de0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_477de0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_477de0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @20_477de0
  ecx = edx = 0;  // @21_477de0
  PV[2] = (u32)(eax);  // @22_477de0
  ecx = edi;  // @23_477de0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1484)))(ecx, PV[2]);  // @24_477de0
  ecx = edx = 0;  // @25_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_477de0
  ecx = edi;  // @27_477de0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1488)))(ecx);  // @28_477de0
  ecx = edx = 0;  // @29_477de0
  FL[2] = (eax & eax);  // @30_477de0
  if (FL[2] == 0) goto L477e82;  // @31_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_477de0
  ecx = edi;  // @33_477de0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1492)))(ecx, (u32)(1));  // @34_477de0
  ecx = edx = 0;  // @35_477de0
  L477e82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @37_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @38_477de0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @39_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_477de0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @41_477de0
  ecx = edx = 0;  // @42_477de0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_477de0
  PV[3] = (u32)(eax);  // @44_477de0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @45_477de0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_477de0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[3]);  // @47_477de0
  ecx = edx = 0;  // @48_477de0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1850), &v, sizeof v); }  // @49_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_477de0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @51_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_477de0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @53_477de0
  ecx = edx = 0;  // @54_477de0
  ecx = (u32)(EBP - 145);  // @55_477de0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @56_477de0
  PV[4] = (u32)(ecx);  // @57_477de0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @58_477de0
  ecx = eax;  // @59_477de0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6859220), PV[4]);  // @60_477de0
  ecx = edx = 0;  // @61_477de0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 145), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @62_477de0
  if (FL[0] == FL[1]) goto L477ef7;  // @63_477de0
  PV[6] = 0; goto L477f30;  // @64_477de0
  L477ef7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_477de0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_477de0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @69_477de0
  ecx = edx = 0;  // @70_477de0
  ecx = (u32)(EBP - 152);  // @71_477de0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @72_477de0
  PV[5] = (u32)(ecx);  // @73_477de0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @74_477de0
  ecx = eax;  // @75_477de0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), PV[5]);  // @76_477de0
  ecx = edx = 0;  // @77_477de0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @78_477de0
  L477f30:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @80_477de0
  ecx = edi;  // @81_477de0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1408)))(ecx, PV[6]);  // @82_477de0
  ecx = edx = 0;  // @83_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_477de0
  ecx = edi;  // @85_477de0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1620)))(ecx, (u32)(1));  // @86_477de0
  ecx = edx = 0;  // @87_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_477de0
  ecx = edi;  // @89_477de0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @90_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @91_477de0
  X0[0] = F2U((float)(s32)X0[0]);  // @92_477de0
  X0[1] = F2U((float)(s32)X0[1]);  // @93_477de0
  X0[2] = F2U((float)(s32)X0[2]);  // @94_477de0
  X0[3] = F2U((float)(s32)X0[3]);  // @95_477de0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @96_477de0
  __builtin_memcpy((void *)((u32)(edi + 1604) + 0), &X0[0], 4);  // @97_477de0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @98_477de0
  ecx = edx = 0;  // @99_477de0
  ecx = (u32)(6801640);  // @100_477de0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @101_477de0
  FL[2] = (eax & eax);  // @102_477de0
  if (FL[2] != 0) ecx = eax;  // @103_477de0
  PV[7] = (u32)(ecx);  // @104_477de0
  ecx = (u32)(EBP - 144);  // @105_477de0
  eax = ext_4cbe80_thiscall2(ecx, PV[7]);  // @106_477de0
  ecx = edx = 0;  // @107_477de0
  eax = (u32)(EBP - 144);  // @108_477de0
  reg.state = (s32)((u32)(0));  // @109_477de0
  PV[8] = (u32)(eax);  // @110_477de0
  ecx = (u32)(edi + 1042);  // @111_477de0
  eax = ext_4cbee0_thiscall2(ecx, PV[8]);  // @112_477de0
  ecx = edx = 0;  // @113_477de0
  ecx = (u32)(EBP - 144);  // @114_477de0
  eax = ext_4cbec0_thiscall1(ecx);  // @115_477de0
  ecx = edx = 0;  // @116_477de0
  SEH_LEAVE();  // @117_477de0
  ext_633654(G(u32, 0x6f5630));  // @118_477de0
  return eax;  // @119_477de0
}
PCREG(477de0, lifted_477de0);

extern "C" u32 THISCALL lifted_616150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e688);  // @h_616150
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_616150
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_616150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_616150
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @4_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @5_616150
  { u32 v = (u32)((u32)(7069032)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @7_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 47524), sizeof v); (u32)v; });  // @8_616150
  reg.state = (s32)((u32)(0));  // @9_616150
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4758), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @10_616150
  if (FL[0] == FL[1]) goto L6162d1;  // @11_616150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @12_616150
  edx = (u32)(64);  // @13_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_616150
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @15_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @16_616150
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @17_616150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @18_616150
  eax = esi;  // @19_616150
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; }));  // @20_616150
  FL[3] = edi;  // @21_616150
  ecx = 0;  // @22_616150
  FL[3] = ecx;  // @23_616150
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @24_616150
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @25_616150
  ecx = (0u - ecx);  // @26_616150
  ecx = (ecx | eax);  // @27_616150
  FL[3] = ecx;  // @28_616150
  PV[0] = (u32)(ecx);  // @29_616150
  eax = ext_41e290_cdecl1(PV[0]);  // @30_616150
  ecx = edx = 0;  // @31_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @32_616150
  FL[2] = (esi & esi);  // @33_616150
  if (FL[2] == 0) goto L6162d1;  // @34_616150
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @35_616150
  X1[1] = 0;  // @36_616150
  X1[2] = 0;  // @37_616150
  X1[3] = 0;  // @38_616150
  esi = (u32)(eax + 8);  // @39_616150
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @40_616150
  edi = (edi + (u32)(8));  // @41_616150
  FL[3] = edi;  // @42_616150
  L616200:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 8), sizeof v); (u32)v; });  // @44_616150
  X0[0] = X1[0];  // @45_616150
  X0[1] = X1[1];  // @46_616150
  X0[2] = X1[2];  // @47_616150
  X0[3] = X1[3];  // @48_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 8), &v, sizeof v); }  // @49_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @50_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 4), &v, sizeof v); }  // @51_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @53_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @54_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @55_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @56_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @57_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @58_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @59_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @60_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @61_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @62_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @63_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @64_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @65_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @66_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @67_616150
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; })));  // @68_616150
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; })));  // @69_616150
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; })));  // @70_616150
  __builtin_memcpy((void *)((u32)(esi + 36) + 0), &X0[0], 4);  // @71_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @72_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @73_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @74_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @75_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @76_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @77_616150
  eax = (u32)(2863311531);  // @78_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @79_616150
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @80_616150
  eax = (u32)(2863311531);  // @81_616150
  edx = (edx >> (u32)(1));  // @82_616150
  FL[3] = edx;  // @83_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @84_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; });  // @85_616150
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @86_616150
  eax = (u32)(2863311531);  // @87_616150
  edx = (edx >> (u32)(1));  // @88_616150
  FL[3] = edx;  // @89_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @90_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 18), sizeof v); (u32)v; });  // @91_616150
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @92_616150
  eax = (u32)(2863311531);  // @93_616150
  edx = (edx >> (u32)(1));  // @94_616150
  FL[3] = edx;  // @95_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 54), &v, sizeof v); }  // @96_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 19), sizeof v); (u32)v; });  // @97_616150
  edi = (edi + (u32)(52));  // @98_616150
  FL[3] = edi;  // @99_616150
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @100_616150
  edx = (edx >> (u32)(1));  // @101_616150
  FL[3] = edx;  // @102_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 55), &v, sizeof v); }  // @103_616150
  esi = (esi + (u32)(64));  // @104_616150
  FL[3] = esi;  // @105_616150
  ebx = (ebx - (u32)(1));  // @106_616150
  FL[3] = ebx;  // @107_616150
  if (FL[3] != 0) goto L616200;  // @108_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @109_616150
  SEH_LEAVE();  // @110_616150
  return eax;  // @111_616150
  L6162d1:;
  eax = ebx;  // @113_616150
  SEH_LEAVE();  // @114_616150
  return eax;  // @115_616150
}
PCREG(616150, lifted_616150);

extern "C" u32 THISCALL lifted_48b340(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66793e);  // @h_48b340
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_48b340
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_48b340
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @3_48b340
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_48b340
  FL[2] = ((ebx & 0xff) & (u32)(16));  // @5_48b340
  if (FL[2] == 0) goto L48b3cf;  // @6_48b340
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 200), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @7_48b340
  if (FL[0] != FL[1]) goto L48b3c1;  // @8_48b340
  eax = ext_41e290_cdecl1((u32)(41));  // @9_48b340
  ecx = edx = 0;  // @10_48b340
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @11_48b340
  reg.state = (s32)((u32)(0));  // @12_48b340
  FL[2] = (eax & eax);  // @13_48b340
  if (FL[2] == 0) goto L48b3b2;  // @14_48b340
  ecx = eax;  // @15_48b340
  eax = ext_49d220_thiscall4(ecx, (u32)(1200), (u32)(600), (u32)(600));  // @16_48b340
  ecx = edx = 0;  // @17_48b340
  goto L48b3b4;  // @18_48b340
  L48b3b2:;
  eax = 0;  // @20_48b340
  FL[3] = eax;  // @21_48b340
  L48b3b4:;
  reg.state = (s32)((u32)(4294967295));  // @23_48b340
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 200), &v, sizeof v); }  // @24_48b340
  L48b3c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 200), sizeof v); (u32)v; });  // @26_48b340
  PV[0] = (u32)(esi);  // @27_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_48b340
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[0]);  // @29_48b340
  ecx = edx = 0;  // @30_48b340
  ebx = (ebx & (u32)(4294967279));  // @31_48b340
  FL[3] = ebx;  // @32_48b340
  L48b3cf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @34_48b340
  PV[1] = (u32)(esi);  // @35_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_48b340
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[1]);  // @37_48b340
  ecx = edx = 0;  // @38_48b340
  FL[2] = (eax & eax);  // @39_48b340
  if (FL[2] == 0) goto L48b3e3;  // @40_48b340
  edx = 0;  // @41_48b340
  FL[3] = edx;  // @42_48b340
  goto L48b417;  // @43_48b340
  L48b3e3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @45_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @46_48b340
  FL[2] = (eax & eax);  // @47_48b340
  if (FL[2] == 0) goto L48b405;  // @48_48b340
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }); FL[1] = esi;  // @49_48b340
  if (FL[0] > FL[1]) goto L48b405;  // @50_48b340
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @51_48b340
  if (FL[0] >= FL[1]) goto L48b405;  // @52_48b340
  ecx = esi;  // @53_48b340
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @54_48b340
  ecx = edx = 0;  // @55_48b340
  edx = eax;  // @56_48b340
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @57_48b340
  goto L48b41a;  // @58_48b340
  L48b405:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @60_48b340
  if (FL[0] != FL[1]) goto L48b414;  // @61_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_48b340
  PV[2] = (u32)(esi);  // @63_48b340
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[2]);  // @64_48b340
  ecx = edx = 0;  // @65_48b340
  L48b414:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @67_48b340
  L48b417:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @69_48b340
  L48b41a:;
  ebx = (ebx & (u32)(72));  // @71_48b340
  FL[3] = ebx;  // @72_48b340
  esi = 0;  // @73_48b340
  FL[3] = esi;  // @74_48b340
  L48b420:;
  FL[2] = (ebx & ebx);  // @76_48b340
  if (FL[2] == 0) goto L48b4d4;  // @77_48b340
  FL[2] = ((ebx & 0xff) & (u32)(1));  // @78_48b340
  if (FL[2] == 0) goto L48b4c5;  // @79_48b340
  FL[0] = esi; FL[1] = (u32)(3);  // @80_48b340
  if (FL[0] != FL[1]) goto L48b45d;  // @81_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 204), sizeof v); (u32)v; });  // @82_48b340
  ecx = (u32)(edi + 204);  // @83_48b340
  PV[3] = (u32)(edx);  // @84_48b340
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[3]);  // @85_48b340
  ecx = edx = 0;  // @86_48b340
  FL[2] = (eax & eax);  // @87_48b340
  if (FL[2] != 0) goto L48b4c5;  // @88_48b340
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @89_48b340
  ecx = (u32)(edi + 204);  // @90_48b340
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @91_48b340
  eax = ext_48b530_thiscall3(ecx, PV[5], PV[4]);  // @92_48b340
  ecx = edx = 0;  // @93_48b340
  goto L48b4c5;  // @94_48b340
  L48b45d:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_48b340
  if (FL[0] != FL[1]) goto L48b496;  // @97_48b340
  eax = ext_41e290_cdecl1((u32)(44));  // @98_48b340
  ecx = edx = 0;  // @99_48b340
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @100_48b340
  reg.state = (s32)((u32)(1));  // @101_48b340
  FL[2] = (eax & eax);  // @102_48b340
  if (FL[2] == 0) goto L48b489;  // @103_48b340
  ecx = eax;  // @104_48b340
  eax = ext_4ccad0_thiscall3(ecx, (u32)(64), (u32)(0));  // @105_48b340
  ecx = edx = 0;  // @106_48b340
  goto L48b48b;  // @107_48b340
  L48b489:;
  eax = 0;  // @109_48b340
  FL[3] = eax;  // @110_48b340
  L48b48b:;
  reg.state = (s32)((u32)(4294967295));  // @112_48b340
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 72), &v, sizeof v); }  // @113_48b340
  L48b496:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 72), sizeof v); (u32)v; });  // @115_48b340
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @116_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_48b340
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[6]);  // @118_48b340
  ecx = edx = 0;  // @119_48b340
  FL[2] = (eax & eax);  // @120_48b340
  if (FL[2] != 0) goto L48b4c5;  // @121_48b340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @122_48b340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 72), sizeof v); (u32)v; });  // @123_48b340
  X0[0] = F2U((float)(s32)X0[0]);  // @124_48b340
  X0[1] = F2U((float)(s32)X0[1]);  // @125_48b340
  X0[2] = F2U((float)(s32)X0[2]);  // @126_48b340
  X0[3] = F2U((float)(s32)X0[3]);  // @127_48b340
  PV[7] = (u32)(ecx);  // @128_48b340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_48b340
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @130_48b340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[8], X0[0], (u32)(0));  // @131_48b340
  ecx = edx = 0;  // @132_48b340
  L48b4c5:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @134_48b340
  esi = (esi + 1);  // @135_48b340
  FL[3] = esi;  // @136_48b340
  ebx = (ebx >> (u32)(1));  // @137_48b340
  FL[3] = ebx;  // @138_48b340
  FL[0] = esi; FL[1] = (u32)(32);  // @139_48b340
  if (FL[0] != FL[1]) goto L48b420;  // @140_48b340
  L48b4d4:;
  SEH_LEAVE();  // @142_48b340
  return eax;  // @143_48b340
}
PCREG(48b340, lifted_48b340);

extern "C" u32 THISCALL lifted_57cdc0(u32 ecx_in) {
  SEH_ENTER(0x66b272);  // @h_57cdc0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_57cdc0
  edi = 0;  // @1_57cdc0
  FL[3] = edi;  // @2_57cdc0
  { u32 v = (u32)((u32)(19)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @3_57cdc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @4_57cdc0
  esi = 0;  // @5_57cdc0
  FL[3] = esi;  // @6_57cdc0
  edi = (u32)(6990032);  // @7_57cdc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @8_57cdc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @9_57cdc0
  L57ce06:;
  eax = ext_41e290_cdecl1((u32)(225));  // @11_57cdc0
  ecx = edx = 0;  // @12_57cdc0
  ecx = eax;  // @13_57cdc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @14_57cdc0
  reg.state = (s32)((u32)(0));  // @15_57cdc0
  FL[2] = (ecx & ecx);  // @16_57cdc0
  if (FL[2] == 0) goto L57ce45;  // @17_57cdc0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 792), sizeof v); (u32)v; });  // @18_57cdc0
  eax = (u32)(esi + 1);  // @19_57cdc0
  PV[1] = (u32)(eax);  // @20_57cdc0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @21_57cdc0
  PV[3] = (u32)(edi);  // @22_57cdc0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 784), sizeof v); (u32)v; });  // @23_57cdc0
  eax = ext_57c500_thiscall7(ecx, PV[4], PV[3], PV[2], PV[1], PV[0], (u32)(0));  // @24_57cdc0
  ecx = edx = 0;  // @25_57cdc0
  esi = eax;  // @26_57cdc0
  goto L57ce47;  // @27_57cdc0
  L57ce45:;
  esi = 0;  // @29_57cdc0
  FL[3] = esi;  // @30_57cdc0
  L57ce47:;
  reg.state = (s32)((u32)(4294967295));  // @32_57cdc0
  FL[2] = (esi & esi);  // @33_57cdc0
  if (FL[2] != 0) goto L57ce56;  // @34_57cdc0
  ecx = 0;  // @35_57cdc0
  FL[3] = ecx;  // @36_57cdc0
  goto L57ce9b;  // @37_57cdc0
  L57ce56:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @39_57cdc0
  PV[5] = (u32)(esi);  // @40_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[5]);  // @42_57cdc0
  ecx = edx = 0;  // @43_57cdc0
  FL[2] = (eax & eax);  // @44_57cdc0
  if (FL[2] == 0) goto L57ce6a;  // @45_57cdc0
  ecx = 0;  // @46_57cdc0
  FL[3] = ecx;  // @47_57cdc0
  goto L57ce9b;  // @48_57cdc0
  L57ce6a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @50_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @51_57cdc0
  FL[2] = (eax & eax);  // @52_57cdc0
  if (FL[2] == 0) goto L57ce89;  // @53_57cdc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }); FL[1] = esi;  // @54_57cdc0
  if (FL[0] > FL[1]) goto L57ce89;  // @55_57cdc0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @56_57cdc0
  if (FL[0] >= FL[1]) goto L57ce89;  // @57_57cdc0
  ecx = esi;  // @58_57cdc0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @59_57cdc0
  ecx = edx = 0;  // @60_57cdc0
  ecx = eax;  // @61_57cdc0
  goto L57ce9b;  // @62_57cdc0
  L57ce89:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @64_57cdc0
  if (FL[0] != FL[1]) goto L57ce98;  // @65_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_57cdc0
  PV[6] = (u32)(esi);  // @67_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[6]);  // @68_57cdc0
  ecx = edx = 0;  // @69_57cdc0
  L57ce98:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @71_57cdc0
  L57ce9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 572), sizeof v); (u32)v; });  // @73_57cdc0
  PV[7] = (u32)(ecx);  // @74_57cdc0
  ecx = (u32)(ebx + 572);  // @75_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7]);  // @76_57cdc0
  ecx = edx = 0;  // @77_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_57cdc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @79_57cdc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 612), sizeof v); (u32)v; });  // @80_57cdc0
  PV[8] = (u32)(edi);  // @81_57cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @82_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @84_57cdc0
  ecx = edx = 0;  // @85_57cdc0
  PV[9] = (u32)(eax);  // @86_57cdc0
  ecx = (u32)(ebx + 612);  // @87_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, PV[9]);  // @88_57cdc0
  ecx = edx = 0;  // @89_57cdc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @90_57cdc0
  ecx = (u32)(EBP - 28);  // @91_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @92_57cdc0
  X0[0] = F2U((float)(s32)X0[0]);  // @93_57cdc0
  X0[1] = F2U((float)(s32)X0[1]);  // @94_57cdc0
  X0[2] = F2U((float)(s32)X0[2]);  // @95_57cdc0
  X0[3] = F2U((float)(s32)X0[3]);  // @96_57cdc0
  PV[10] = (u32)(ecx);  // @97_57cdc0
  ecx = edi;  // @98_57cdc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @99_57cdc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @100_57cdc0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @101_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[10]);  // @102_57cdc0
  ecx = edx = 0;  // @103_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @104_57cdc0
  ecx = edi;  // @105_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 196)))(ecx, (u32)(0));  // @106_57cdc0
  ecx = edx = 0;  // @107_57cdc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @108_57cdc0
  FL[2] = (esi & esi);  // @109_57cdc0
  if (FL[2] == 0) goto L57cf24;  // @110_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_57cdc0
  ecx = esi;  // @112_57cdc0
  PV[11] = (u32)(edi);  // @113_57cdc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[11], (u32)(4));  // @114_57cdc0
  ecx = edx = 0;  // @115_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @116_57cdc0
  ecx = edi;  // @117_57cdc0
  PV[12] = (u32)(esi);  // @118_57cdc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[12], (u32)(3));  // @119_57cdc0
  ecx = edx = 0;  // @120_57cdc0
  goto L57cf3b;  // @121_57cdc0
  L57cf24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @123_57cdc0
  PV[13] = (u32)(edi);  // @124_57cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @125_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @126_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @127_57cdc0
  ecx = edx = 0;  // @128_57cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 832), &v, sizeof v); }  // @129_57cdc0
  L57cf3b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @131_57cdc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) + (u32)(20))); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @132_57cdc0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @133_57cdc0
  esi = (esi + 1);  // @134_57cdc0
  FL[3] = esi;  // @135_57cdc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @136_57cdc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @137_57cdc0
  edi = (edi + (u32)(8));  // @138_57cdc0
  FL[3] = edi;  // @139_57cdc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @140_57cdc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @141_57cdc0
  FL[0] = esi; FL[1] = (u32)(18);  // @142_57cdc0
  if (FL[0] < FL[1]) goto L57ce06;  // @143_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @144_57cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @145_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @146_57cdc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @147_57cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_57cdc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 736)))(ecx);  // @149_57cdc0
  ecx = edx = 0;  // @150_57cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @151_57cdc0
  PV[14] = (u32)(eax);  // @152_57cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @153_57cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[14]);  // @154_57cdc0
  ecx = edx = 0;  // @155_57cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 836), &v, sizeof v); }  // @156_57cdc0
  SEH_LEAVE();  // @157_57cdc0
  ext_633654(G(u32, 0x6f5630));  // @158_57cdc0
  return eax;  // @159_57cdc0
}
PCREG(57cdc0, lifted_57cdc0);

extern "C" u32 THISCALL lifted_4a25a0(u32 ecx_in) {
  SEH_ENTER(0x6685bb);  // @h_4a25a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @2_4a25a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_4a25a0
  if (FL[0] != FL[1]) goto L4a2633;  // @4_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @6_4a25a0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(4194307));  // @7_4a25a0
  ecx = edx = 0;  // @8_4a25a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @9_4a25a0
  if (FL[2] != 0) goto L4a2633;  // @10_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6879564), (u32)(52));  // @13_4a25a0
  ecx = edx = 0;  // @14_4a25a0
  PV[0] = (u32)(eax);  // @15_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_4a25a0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6879608));  // @17_4a25a0
  ecx = edx = 0;  // @18_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @19_4a25a0
  FL[2] = (eax & eax);  // @20_4a25a0
  if (FL[2] == 0) goto L4a2626;  // @21_4a25a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_4a25a0
  ecx = edx = 0;  // @23_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_4a25a0
  ecx = ebx;  // @25_4a25a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @26_4a25a0
  ecx = edx = 0;  // @27_4a25a0
  goto L4a27ab;  // @28_4a25a0
  L4a2626:;
  __builtin_trap();  // @30_4a25a0
  L4a2633:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @32_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @33_4a25a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @34_4a25a0
  if (FL[0] == FL[1]) goto L4a2644;  // @35_4a25a0
  eax = ext_4da6d0_thiscall1(ecx);  // @36_4a25a0
  ecx = edx = 0;  // @37_4a25a0
  L4a2644:;
  eax = (u32)(ebx + 77);  // @39_4a25a0
  ecx = (u32)(EBP - 148);  // @40_4a25a0
  FL[0] = eax; FL[1] = ecx;  // @41_4a25a0
  if (FL[0] == FL[1]) goto L4a2657;  // @42_4a25a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @43_4a25a0
  L4a2657:;
  eax = (u32)(ebx + 73);  // @45_4a25a0
  ecx = (u32)(EBP - 152);  // @46_4a25a0
  FL[0] = eax; FL[1] = ecx;  // @47_4a25a0
  if (FL[0] == FL[1]) goto L4a266a;  // @48_4a25a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @49_4a25a0
  L4a266a:;
  ecx = ebx;  // @51_4a25a0
  eax = ext_4a2f90_cdecl0();  // @52_4a25a0
  ecx = edx = 0;  // @53_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6851600), (u32)(0), (u32)(6879564), (u32)(62));  // @57_4a25a0
  ecx = edx = 0;  // @58_4a25a0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340784), &v, sizeof v); }  // @59_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6851612), (u32)(0), (u32)(6879564), (u32)(63));  // @63_4a25a0
  ecx = edx = 0;  // @64_4a25a0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340788), &v, sizeof v); }  // @65_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @66_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_4a25a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(524292));  // @68_4a25a0
  ecx = edx = 0;  // @69_4a25a0
  esi = eax;  // @70_4a25a0
  FL[2] = (esi & esi);  // @71_4a25a0
  if (FL[2] == 0) goto L4a272f;  // @72_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 89), sizeof v); (u32)v; });  // @73_4a25a0
  ecx = (u32)(ebx + 89);  // @74_4a25a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 286) + 0), 4); v; });  // @75_4a25a0
  X0[1] = 0;  // @76_4a25a0
  X0[2] = 0;  // @77_4a25a0
  X0[3] = 0;  // @78_4a25a0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 285), sizeof v); (u32)v; });  // @79_4a25a0
  PV[1] = (u32)(ecx);  // @80_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @81_4a25a0
  PV[2] = (u32)(edx);  // @82_4a25a0
  PV[3] = (u32)(esi);  // @83_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[3], PV[2], X0[0]);  // @84_4a25a0
  ecx = edx = 0;  // @85_4a25a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @86_4a25a0
  if (FL[2] != 0) goto L4a278d;  // @87_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @88_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6879564), (u32)(70));  // @90_4a25a0
  ecx = edx = 0;  // @91_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @92_4a25a0
  edx = (u32)(6801640);  // @93_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @94_4a25a0
  FL[2] = (ecx & ecx);  // @95_4a25a0
  if (FL[2] != 0) edx = ecx;  // @96_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @97_4a25a0
  PV[4] = (u32)(edx);  // @98_4a25a0
  PV[5] = (u32)(eax);  // @99_4a25a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6879640), PV[4]);  // @100_4a25a0
  ecx = edx = 0;  // @101_4a25a0
  goto L4a2786;  // @102_4a25a0
  L4a272f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @104_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6879564), (u32)(77));  // @106_4a25a0
  ecx = edx = 0;  // @107_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @108_4a25a0
  edi = eax;  // @109_4a25a0
  eax = (u32)(EBP - 144);  // @110_4a25a0
  PV[6] = (u32)(eax);  // @111_4a25a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[6], (u32)(0));  // @113_4a25a0
  ecx = edx = 0;  // @114_4a25a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @115_4a25a0
  ecx = eax;  // @116_4a25a0
  reg.state = (s32)((u32)(0));  // @117_4a25a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @118_4a25a0
  ecx = edx = 0;  // @119_4a25a0
  PV[7] = (u32)(eax);  // @120_4a25a0
  PV[8] = (u32)(edi);  // @121_4a25a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[8], (u32)(6879680), PV[7]);  // @122_4a25a0
  ecx = edx = 0;  // @123_4a25a0
  reg.state = (s32)((u32)(4294967295));  // @124_4a25a0
  ecx = (u32)(EBP - 144);  // @125_4a25a0
  eax = ext_4cbec0_thiscall1(ecx);  // @126_4a25a0
  ecx = edx = 0;  // @127_4a25a0
  L4a2786:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @129_4a25a0
  ecx = ebx;  // @130_4a25a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @131_4a25a0
  ecx = edx = 0;  // @132_4a25a0
  L4a278d:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 284), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @134_4a25a0
  if (FL[0] != FL[1]) goto L4a27ab;  // @135_4a25a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @136_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_4a25a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(1));  // @138_4a25a0
  ecx = edx = 0;  // @139_4a25a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @140_4a25a0
  ecx = ebx;  // @141_4a25a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @142_4a25a0
  ecx = edx = 0;  // @143_4a25a0
  L4a27ab:;
  SEH_LEAVE();  // @145_4a25a0
  ext_633654(G(u32, 0x6f5630));  // @146_4a25a0
  return eax;  // @147_4a25a0
}
PCREG(4a25a0, lifted_4a25a0);

extern "C" u32 THISCALL lifted_5abce0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c212);  // @h_5abce0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5abce0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5abce0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5abce0
  ebx = (u32)(EBP + 11);  // @3_5abce0
  PV[0] = (u32)(ebx);  // @4_5abce0
  PV[1] = (u32)(ebx);  // @5_5abce0
  PV[2] = (u32)(ebx);  // @6_5abce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_5abce0
  eax = (u32)(edi + 126);  // @8_5abce0
  PV[3] = (u32)(ebx);  // @9_5abce0
  PV[4] = (u32)(ebx);  // @10_5abce0
  PV[5] = (u32)(eax);  // @11_5abce0
  eax = (u32)(edi + 8);  // @12_5abce0
  ecx = (u32)(edi + 25);  // @13_5abce0
  PV[6] = (u32)(eax);  // @14_5abce0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @15_5abce0
  PV[7] = (u32)(ecx);  // @16_5abce0
  ecx = esi;  // @17_5abce0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, PV[7], PV[6], PV[5], PV[4], PV[3], PV[2], PV[1], PV[0]);  // @18_5abce0
  ecx = edx = 0;  // @19_5abce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_5abce0
  eax = (u32)(edi + 4);  // @21_5abce0
  PV[8] = (u32)(eax);  // @22_5abce0
  ecx = esi;  // @23_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[8]);  // @24_5abce0
  ecx = edx = 0;  // @25_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_5abce0
  ecx = (u32)(EBP - 16);  // @27_5abce0
  PV[9] = (u32)(ecx);  // @28_5abce0
  ecx = esi;  // @29_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[9]);  // @30_5abce0
  ecx = edx = 0;  // @31_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @32_5abce0
  ecx = (u32)(EBP - 16);  // @33_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 9), &v, sizeof v); }  // @34_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_5abce0
  PV[10] = (u32)(ecx);  // @36_5abce0
  ecx = esi;  // @37_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[10]);  // @38_5abce0
  ecx = edx = 0;  // @39_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @40_5abce0
  ecx = esi;  // @41_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 13), &v, sizeof v); }  // @42_5abce0
  eax = (u32)(edi + 17);  // @43_5abce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @44_5abce0
  PV[11] = (u32)(eax);  // @45_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[11]);  // @46_5abce0
  ecx = edx = 0;  // @47_5abce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_5abce0
  eax = (u32)(edi + 21);  // @49_5abce0
  PV[12] = (u32)(eax);  // @50_5abce0
  ecx = esi;  // @51_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[12]);  // @52_5abce0
  ecx = edx = 0;  // @53_5abce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_5abce0
  eax = (u32)(edi + 122);  // @55_5abce0
  PV[13] = (u32)(eax);  // @56_5abce0
  ecx = esi;  // @57_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[13]);  // @58_5abce0
  ecx = edx = 0;  // @59_5abce0
  ebx = 0;  // @60_5abce0
  FL[3] = ebx;  // @61_5abce0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 127), sizeof v); (u32)v; }); FL[1] = ebx;  // @62_5abce0
  if (FL[0] <= FL[1]) goto L5abddd;  // @63_5abce0
  edi = (edi + (u32)(66));  // @64_5abce0
  FL[3] = edi;  // @65_5abce0
  L5abd86:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @67_5abce0
  ecx = (u32)(EBP - 24);  // @68_5abce0
  PV[14] = (u32)(ecx);  // @69_5abce0
  ecx = esi;  // @70_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[14]);  // @71_5abce0
  ecx = edx = 0;  // @72_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_5abce0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @74_5abce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @75_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[15]);  // @77_5abce0
  ecx = edx = 0;  // @78_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 40), &v, sizeof v); }  // @79_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @80_5abce0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @81_5abce0
  if (FL[0] == FL[1]) goto L5abdcf;  // @82_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @83_5abce0
  ecx = (u32)(EBP - 36);  // @84_5abce0
  PV[16] = (u32)(ecx);  // @85_5abce0
  ecx = esi;  // @86_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[16]);  // @87_5abce0
  ecx = edx = 0;  // @88_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_5abce0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @90_5abce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @91_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[17]);  // @93_5abce0
  ecx = edx = 0;  // @94_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @95_5abce0
  L5abdcf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @97_5abce0
  ebx = (ebx + 1);  // @98_5abce0
  FL[3] = ebx;  // @99_5abce0
  edi = (edi + (u32)(4));  // @100_5abce0
  FL[3] = edi;  // @101_5abce0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 127), sizeof v); (u32)v; });  // @102_5abce0
  if (FL[0] < FL[1]) goto L5abd86;  // @103_5abce0
  edi = eax;  // @104_5abce0
  L5abddd:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 126), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @106_5abce0
  if (FL[0] == FL[1]) goto L5abe1e;  // @107_5abce0
  eax = ext_41e290_cdecl1((u32)(215));  // @108_5abce0
  ecx = edx = 0;  // @109_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @110_5abce0
  reg.state = (s32)((u32)(0));  // @111_5abce0
  FL[2] = (eax & eax);  // @112_5abce0
  if (FL[2] == 0) goto L5abe0c;  // @113_5abce0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 127), sizeof v); (u32)v; });  // @114_5abce0
  ecx = eax;  // @115_5abce0
  eax = ext_5ec720_thiscall2(ecx, PV[18]);  // @116_5abce0
  ecx = edx = 0;  // @117_5abce0
  ecx = eax;  // @118_5abce0
  goto L5abe0e;  // @119_5abce0
  L5abe0c:;
  ecx = 0;  // @121_5abce0
  FL[3] = ecx;  // @122_5abce0
  L5abe0e:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 106), &v, sizeof v); }  // @124_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_5abce0
  PV[19] = (u32)(esi);  // @126_5abce0
  reg.state = (s32)((u32)(4294967295));  // @127_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[19]);  // @128_5abce0
  ecx = edx = 0;  // @129_5abce0
  L5abe1e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 110), sizeof v); (u32)v; });  // @131_5abce0
  ecx = eax;  // @132_5abce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 114), sizeof v); (u32)v; });  // @133_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @134_5abce0
  eax = edx;  // @135_5abce0
  eax = (eax - edx);  // @136_5abce0
  FL[3] = eax;  // @137_5abce0
  eax = (u32)((s32)eax >> (u32)(4));  // @138_5abce0
  FL[3] = eax;  // @139_5abce0
  FL[2] = (eax & eax);  // @140_5abce0
  if ((s32)FL[2] <= 0) goto L5abe48;  // @141_5abce0
  ebx = edx;  // @142_5abce0
  ebx = (ebx - ecx);  // @143_5abce0
  FL[3] = ebx;  // @144_5abce0
  L5abe38:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx) + 0), 4); v; });  // @146_5abce0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx) + 4), 4); v; });  // @147_5abce0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx) + 8), 4); v; });  // @148_5abce0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx) + 12), 4); v; });  // @149_5abce0
  eax = (eax - 1);  // @150_5abce0
  FL[3] = eax;  // @151_5abce0
  ecx = (u32)(ecx + 16);  // @152_5abce0
  __builtin_memcpy((void *)((u32)(ecx - 16) + 0), &X0[0], 4);  // @153_5abce0
  __builtin_memcpy((void *)((u32)(ecx - 16) + 4), &X0[1], 4);  // @154_5abce0
  __builtin_memcpy((void *)((u32)(ecx - 16) + 8), &X0[2], 4);  // @155_5abce0
  __builtin_memcpy((void *)((u32)(ecx - 16) + 12), &X0[3], 4);  // @156_5abce0
  FL[2] = (eax & eax);  // @157_5abce0
  if ((s32)FL[2] > 0) goto L5abe38;  // @158_5abce0
  L5abe48:;
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @160_5abce0
  FL[3] = edx;  // @161_5abce0
  ecx = (u32)(EBP - 32);  // @162_5abce0
  edx = (u32)((s32)edx >> (u32)(4));  // @163_5abce0
  FL[3] = edx;  // @164_5abce0
  edx = (0u - edx);  // @165_5abce0
  edx = (edx << (u32)(4));  // @166_5abce0
  FL[3] = edx;  // @167_5abce0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 114), sizeof v); (u32)v; }) + edx)); __builtin_memcpy((void *)(u32)(edi + 114), &v, sizeof v); }  // @168_5abce0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 114), sizeof v); (u32)v; });  // @169_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @170_5abce0
  PV[20] = (u32)(ecx);  // @171_5abce0
  ecx = esi;  // @172_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[20]);  // @173_5abce0
  ecx = edx = 0;  // @174_5abce0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @175_5abce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @176_5abce0
  if (FL[0] <= FL[1]) goto L5abee3;  // @177_5abce0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @178_5abce0
  ebx = (ebx + (u32)(66));  // @179_5abce0
  FL[3] = ebx;  // @180_5abce0
  L5abe74:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @182_5abce0
  ecx = (u32)(EBP - 16);  // @183_5abce0
  PV[21] = (u32)(ecx);  // @184_5abce0
  ecx = esi;  // @185_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[21]);  // @186_5abce0
  ecx = edx = 0;  // @187_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @188_5abce0
  ecx = (u32)(EBP - 48);  // @189_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @190_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @191_5abce0
  PV[22] = (u32)(ecx);  // @192_5abce0
  ecx = esi;  // @193_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[22]);  // @194_5abce0
  ecx = edx = 0;  // @195_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @196_5abce0
  ecx = (u32)(EBP - 46);  // @197_5abce0
  PV[23] = (u32)(ecx);  // @198_5abce0
  ecx = esi;  // @199_5abce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[23]);  // @200_5abce0
  ecx = edx = 0;  // @201_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 40), sizeof v); (u32)v; });  // @202_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @203_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @204_5abce0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @205_5abce0
  if (FL[0] == FL[1]) goto L5abeae;  // @206_5abce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @207_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @208_5abce0
  L5abeae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 114), sizeof v); (u32)v; });  // @210_5abce0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 118), sizeof v); (u32)v; });  // @211_5abce0
  if (FL[0] == FL[1]) goto L5abec7;  // @212_5abce0
  FL[2] = (eax & eax);  // @213_5abce0
  if (FL[2] == 0) goto L5abec1;  // @214_5abce0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @215_5abce0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 4), 4); v; });  // @216_5abce0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 8), 4); v; });  // @217_5abce0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 12), 4); v; });  // @218_5abce0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @219_5abce0
  __builtin_memcpy((void *)((u32)(eax) + 4), &X0[1], 4);  // @220_5abce0
  __builtin_memcpy((void *)((u32)(eax) + 8), &X0[2], 4);  // @221_5abce0
  __builtin_memcpy((void *)((u32)(eax) + 12), &X0[3], 4);  // @222_5abce0
  L5abec1:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 114), sizeof v); (u32)v; }) + (u32)(16))); __builtin_memcpy((void *)(u32)(edi + 114), &v, sizeof v); }  // @224_5abce0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 114), sizeof v); (u32)v; });  // @225_5abce0
  goto L5abed4;  // @226_5abce0
  L5abec7:;
  ecx = (u32)(EBP - 52);  // @228_5abce0
  PV[24] = (u32)(ecx);  // @229_5abce0
  PV[25] = (u32)(eax);  // @230_5abce0
  ecx = (u32)(edi + 110);  // @231_5abce0
  eax = ext_5acad0_thiscall3(ecx, PV[25], PV[24]);  // @232_5abce0
  ecx = edx = 0;  // @233_5abce0
  L5abed4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @235_5abce0
  ebx = (ebx + (u32)(4));  // @236_5abce0
  FL[3] = ebx;  // @237_5abce0
  eax = (eax + 1);  // @238_5abce0
  FL[3] = eax;  // @239_5abce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @240_5abce0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @241_5abce0
  if (FL[0] < FL[1]) goto L5abe74;  // @242_5abce0
  L5abee3:;
  SEH_LEAVE();  // @244_5abce0
  return eax;  // @245_5abce0
}
PCREG(5abce0, lifted_5abce0);

extern "C" u32 THISCALL lifted_5f3480(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d0d7);  // @h_5f3480
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_5f3480
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f3480
  ecx = 0;  // @2_5f3480
  FL[3] = ecx;  // @3_5f3480
  { u32 v = (u32)((u32)(7047724)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5f3480
  eax = (u32)(20);  // @5_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @6_5f3480
  edi = (u32)(8);  // @7_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 10), &v, sizeof v); }  // @8_5f3480
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @9_5f3480
  ebx = (u32)(10);  // @10_5f3480
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @11_5f3480
  { u16 v = (u16)((ebx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @12_5f3480
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @13_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @14_5f3480
  ecx = (0u - ecx);  // @15_5f3480
  { u32 v = (u32)((u32)(7048000)); __builtin_memcpy((void *)(u32)(esi + 26), &v, sizeof v); }  // @16_5f3480
  ecx = (ecx | eax);  // @17_5f3480
  FL[3] = ecx;  // @18_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @19_5f3480
  PV[0] = (u32)(ecx);  // @20_5f3480
  { u32 v = (u32)((u32)(20)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @21_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @22_5f3480
  eax = ext_41e290_cdecl1(PV[0]);  // @23_5f3480
  ecx = edx = 0;  // @24_5f3480
  edx = eax;  // @25_5f3480
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @26_5f3480
  FL[2] = (edx & edx);  // @27_5f3480
  if (FL[2] == 0) goto L5f3534;  // @28_5f3480
  ecx = (u32)(20);  // @29_5f3480
  L5f3520:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @31_5f3480
  eax = (u32)(eax + 8);  // @32_5f3480
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @33_5f3480
  ecx = (ecx - (u32)(1));  // @34_5f3480
  FL[3] = ecx;  // @35_5f3480
  if (FL[3] != 0) goto L5f3520;  // @36_5f3480
  goto L5f3536;  // @37_5f3480
  L5f3534:;
  edx = 0;  // @39_5f3480
  FL[3] = edx;  // @40_5f3480
  L5f3536:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @42_5f3480
  ecx = 0;  // @43_5f3480
  FL[3] = ecx;  // @44_5f3480
  reg.state = (s32)((u32)(0));  // @45_5f3480
  eax = (u32)(40);  // @46_5f3480
  { u32 v = (u32)((u32)(40)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @47_5f3480
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @48_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @49_5f3480
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @50_5f3480
  ecx = (0u - ecx);  // @51_5f3480
  ecx = (ecx | eax);  // @52_5f3480
  FL[3] = ecx;  // @53_5f3480
  PV[1] = (u32)(ecx);  // @54_5f3480
  eax = ext_41e290_cdecl1(PV[1]);  // @55_5f3480
  ecx = edx = 0;  // @56_5f3480
  edx = eax;  // @57_5f3480
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @58_5f3480
  FL[2] = (edx & edx);  // @59_5f3480
  if (FL[2] == 0) goto L5f3594;  // @60_5f3480
  ecx = (u32)(40);  // @61_5f3480
  L5f3580:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @63_5f3480
  eax = (u32)(eax + 8);  // @64_5f3480
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @65_5f3480
  ecx = (ecx - (u32)(1));  // @66_5f3480
  FL[3] = ecx;  // @67_5f3480
  if (FL[3] != 0) goto L5f3580;  // @68_5f3480
  goto L5f3596;  // @69_5f3480
  L5f3594:;
  edx = 0;  // @71_5f3480
  FL[3] = edx;  // @72_5f3480
  L5f3596:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @74_5f3480
  ecx = 0;  // @75_5f3480
  FL[3] = ecx;  // @76_5f3480
  reg.state = (s32)((u32)(1));  // @77_5f3480
  eax = (u32)(40);  // @78_5f3480
  { u32 v = (u32)((u32)(40)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @79_5f3480
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @80_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @81_5f3480
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @82_5f3480
  ecx = (0u - ecx);  // @83_5f3480
  ecx = (ecx | eax);  // @84_5f3480
  FL[3] = ecx;  // @85_5f3480
  PV[2] = (u32)(ecx);  // @86_5f3480
  eax = ext_41e290_cdecl1(PV[2]);  // @87_5f3480
  ecx = edx = 0;  // @88_5f3480
  edx = eax;  // @89_5f3480
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @90_5f3480
  FL[2] = (edx & edx);  // @91_5f3480
  if (FL[2] == 0) goto L5f35e6;  // @92_5f3480
  ecx = (u32)(40);  // @93_5f3480
  L5f35d2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @95_5f3480
  eax = (u32)(eax + 8);  // @96_5f3480
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @97_5f3480
  ecx = (ecx - (u32)(1));  // @98_5f3480
  FL[3] = ecx;  // @99_5f3480
  if (FL[3] != 0) goto L5f35d2;  // @100_5f3480
  goto L5f35e8;  // @101_5f3480
  L5f35e6:;
  edx = 0;  // @103_5f3480
  FL[3] = edx;  // @104_5f3480
  L5f35e8:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @106_5f3480
  ecx = 0;  // @107_5f3480
  FL[3] = ecx;  // @108_5f3480
  reg.state = (s32)((u32)(2));  // @109_5f3480
  eax = ebx;  // @110_5f3480
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @111_5f3480
  edi = (u32)(4);  // @112_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @113_5f3480
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @114_5f3480
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @115_5f3480
  ecx = (0u - ecx);  // @116_5f3480
  ecx = (ecx | eax);  // @117_5f3480
  FL[3] = ecx;  // @118_5f3480
  PV[3] = (u32)(ecx);  // @119_5f3480
  eax = ext_41e290_cdecl1(PV[3]);  // @120_5f3480
  ecx = edx = 0;  // @121_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @122_5f3480
  ecx = 0;  // @123_5f3480
  FL[3] = ecx;  // @124_5f3480
  reg.state = (s32)((u32)(3));  // @125_5f3480
  eax = (u32)(2);  // @126_5f3480
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @127_5f3480
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @128_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @129_5f3480
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @130_5f3480
  ecx = (0u - ecx);  // @131_5f3480
  ecx = (ecx | eax);  // @132_5f3480
  FL[3] = ecx;  // @133_5f3480
  PV[4] = (u32)(ecx);  // @134_5f3480
  eax = ext_41e290_cdecl1(PV[4]);  // @135_5f3480
  ecx = edx = 0;  // @136_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @137_5f3480
  eax = 0;  // @138_5f3480
  FL[3] = eax;  // @139_5f3480
  { u32 v = (u32)((u32)(7047672)); __builtin_memcpy((void *)(u32)(esi + 130), &v, sizeof v); }  // @140_5f3480
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 134), &v, sizeof v); }  // @141_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @142_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @143_5f3480
  eax = (u32)(65535);  // @144_5f3480
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @145_5f3480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @146_5f3480
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @147_5f3480
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @148_5f3480
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @149_5f3480
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @150_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 150), &v, sizeof v); }  // @151_5f3480
  eax = 0;  // @152_5f3480
  FL[3] = eax;  // @153_5f3480
  { u32 v = (u32)((u32)(7047664)); __builtin_memcpy((void *)(u32)(esi + 154), &v, sizeof v); }  // @154_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 158), &v, sizeof v); }  // @155_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 162), &v, sizeof v); }  // @156_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 166), &v, sizeof v); }  // @157_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 170), &v, sizeof v); }  // @158_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 174), &v, sizeof v); }  // @159_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 178), &v, sizeof v); }  // @160_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 186), &v, sizeof v); }  // @161_5f3480
  reg.state = (s32)((u32)(4));  // @162_5f3480
  { u32 v = (u32)((u32)(7047696)); __builtin_memcpy((void *)(u32)(esi + 2762), &v, sizeof v); }  // @163_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2766), &v, sizeof v); }  // @164_5f3480
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @165_5f3480
  if (FL[0] != FL[1]) goto L5f3755;  // @166_5f3480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 150), sizeof v); (u32)v; });  // @167_5f3480
  ecx = 0;  // @168_5f3480
  FL[3] = ecx;  // @169_5f3480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 260), sizeof v); (u32)v; });  // @170_5f3480
  FL[2] = (edx & edx);  // @171_5f3480
  if (FL[2] == 0) goto L5f3740;  // @172_5f3480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 264), sizeof v); (u32)v; });  // @173_5f3480
  L5f3710:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(-1);  // @175_5f3480
  if (FL[0] == FL[1]) goto L5f371f;  // @176_5f3480
  ecx = (ecx + 1);  // @177_5f3480
  FL[3] = ecx;  // @178_5f3480
  eax = (eax + (u32)(4));  // @179_5f3480
  FL[3] = eax;  // @180_5f3480
  FL[0] = ecx; FL[1] = edx;  // @181_5f3480
  if (FL[0] < FL[1]) goto L5f3710;  // @182_5f3480
  goto L5f3740;  // @183_5f3480
  L5f371f:;
  eax = ext_5fa630_cdecl0();  // @185_5f3480
  ecx = edx = 0;  // @186_5f3480
  PV[5] = (u32)(eax);  // @187_5f3480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @188_5f3480
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 12)))(PV[5], (u32)(7048024));  // @189_5f3480
  ecx = edx = 0;  // @190_5f3480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @191_5f3480
  FL[2] = (eax & eax);  // @192_5f3480
  if (FL[2] == 0) goto L5f373f;  // @193_5f3480
  eax = ((u32(STDCALL *)(void))(eax))();  // @194_5f3480
  ecx = edx = 0;  // @195_5f3480
  goto L5f3740;  // @196_5f3480
  L5f373f:;
  __builtin_trap();  // @198_5f3480
  L5f3740:;
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @200_5f3480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 150), sizeof v); (u32)v; });  // @201_5f3480
  PV[7] = (u32)(esi);  // @202_5f3480
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(esi + 2766), &v, sizeof v); }  // @203_5f3480
  eax = ext_5fe920_thiscall3(ecx, PV[7], PV[6]);  // @204_5f3480
  ecx = edx = 0;  // @205_5f3480
  L5f3755:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 186), sizeof v); (u32)v; }); FL[1] = (u32)(128);  // @207_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2754), &v, sizeof v); }  // @208_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2758), &v, sizeof v); }  // @209_5f3480
  if (FL[0] >= FL[1]) goto L5f37c6;  // @210_5f3480
  L5f3780:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 186), sizeof v); (u32)v; });  // @212_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @213_5f3480
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @214_5f3480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @215_5f3480
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @216_5f3480
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 4), 4); v; });  // @217_5f3480
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 8), 4); v; });  // @218_5f3480
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 12), 4); v; });  // @219_5f3480
  ecx = (u32)(eax + eax*4);  // @220_5f3480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @221_5f3480
  __builtin_memcpy((void *)((u32)(esi + ecx*4 + 190) + 0), &X0[0], 4);  // @222_5f3480
  __builtin_memcpy((void *)((u32)(esi + ecx*4 + 190) + 4), &X0[1], 4);  // @223_5f3480
  __builtin_memcpy((void *)((u32)(esi + ecx*4 + 190) + 8), &X0[2], 4);  // @224_5f3480
  __builtin_memcpy((void *)((u32)(esi + ecx*4 + 190) + 12), &X0[3], 4);  // @225_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 206), &v, sizeof v); }  // @226_5f3480
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 186), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 186), &v, sizeof v); }  // @227_5f3480
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 186), sizeof v); (u32)v; });  // @228_5f3480
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 186), sizeof v); (u32)v; }); FL[1] = (u32)(128);  // @229_5f3480
  if (FL[0] < FL[1]) goto L5f3780;  // @230_5f3480
  L5f37c6:;
  eax = (u32)(esi + 190);  // @232_5f3480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 182), &v, sizeof v); }  // @233_5f3480
  eax = esi;  // @234_5f3480
  SEH_LEAVE();  // @235_5f3480
  return eax;  // @236_5f3480
}
PCREG(5f3480, lifted_5f3480);

extern "C" u32 THISCALL lifted_455dd0(u32 ecx_in) {
  SEH_ENTER(0x666461);  // @h_455dd0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_455dd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @1_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @2_455dd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_455dd0
  if (FL[0] == FL[1]) goto L456085;  // @4_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_455dd0
  edx = (u32)(EBP - 160);  // @6_455dd0
  PV[0] = (u32)(edx);  // @7_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_455dd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 276)))(ecx, PV[0]);  // @9_455dd0
  ecx = edx = 0;  // @10_455dd0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @11_455dd0
  ecx = (u32)(EBP - 288);  // @12_455dd0
  reg.state = (s32)((u32)(0));  // @13_455dd0
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @14_455dd0
  ecx = edx = 0;  // @15_455dd0
  eax = (u32)(EBP - 288);  // @16_455dd0
  reg.state = (s32)((u32)(1));  // @17_455dd0
  PV[2] = (u32)(eax);  // @18_455dd0
  ecx = (u32)(EBP - 160);  // @19_455dd0
  eax = ext_4cc2c0_thiscall2(ecx, PV[2]);  // @20_455dd0
  ecx = edx = 0;  // @21_455dd0
  ecx = (u32)(EBP - 288);  // @22_455dd0
  reg.state = (s32)((u32)(0));  // @23_455dd0
  eax = ext_4cbec0_thiscall1(ecx);  // @24_455dd0
  ecx = edx = 0;  // @25_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @26_455dd0
  ecx = (u32)(EBP - 160);  // @27_455dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_455dd0
  eax = ext_4cc1d0_thiscall1(ecx);  // @29_455dd0
  ecx = edx = 0;  // @30_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @31_455dd0
  PV[3] = (u32)(eax);  // @32_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 48)))(ecx, PV[3], (u32)(0));  // @33_455dd0
  ecx = edx = 0;  // @34_455dd0
  edi = eax;  // @35_455dd0
  FL[0] = edi; FL[1] = (u32)(-1);  // @36_455dd0
  if (FL[0] == FL[1]) goto L455ffc;  // @37_455dd0
  ecx = (u32)(edi + 1);  // @38_455dd0
  PV[4] = (u32)(ecx);  // @39_455dd0
  eax = ext_41e290_cdecl1(PV[4]);  // @40_455dd0
  ecx = edx = 0;  // @41_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @42_455dd0
  ebx = eax;  // @43_455dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_455dd0
  ecx = (u32)(EBP - 160);  // @45_455dd0
  PV[5] = (u32)(edi);  // @46_455dd0
  PV[6] = (u32)(ebx);  // @47_455dd0
  eax = ext_4cc1d0_thiscall1(ecx);  // @48_455dd0
  ecx = edx = 0;  // @49_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @50_455dd0
  PV[7] = (u32)(eax);  // @51_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, PV[7], PV[6], PV[5], (u32)(0), (u32)(0));  // @52_455dd0
  ecx = edx = 0;  // @53_455dd0
  FL[0] = edi; FL[1] = eax;  // @54_455dd0
  if (FL[0] != FL[1]) goto L455fbd;  // @55_455dd0
  esi = 0;  // @56_455dd0
  FL[3] = esi;  // @57_455dd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + edi), &v, sizeof v); }  // @58_455dd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @59_455dd0
  FL[2] = (edi & edi);  // @60_455dd0
  if ((s32)FL[2] <= 0) goto L455f75;  // @61_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @62_455dd0
  ecx = (ecx + (u32)(101));  // @63_455dd0
  FL[3] = ecx;  // @64_455dd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @65_455dd0
  L455ee6:;
  eax = (u32)(ecx + 4);  // @67_455dd0
  PV[8] = (u32)(eax);  // @68_455dd0
  PV[9] = (u32)(ecx);  // @69_455dd0
  eax = (u32)(ecx - 4);  // @70_455dd0
  PV[10] = (u32)(eax);  // @71_455dd0
  eax = (u32)(ecx - 8);  // @72_455dd0
  PV[11] = (u32)(eax);  // @73_455dd0
  eax = (u32)(esi + ebx);  // @74_455dd0
  PV[12] = (u32)(eax);  // @75_455dd0
  eax = ext_42ab0d_cdecl6(PV[12], (u32)(6827276), PV[11], PV[10], PV[9], PV[8]);  // @76_455dd0
  ecx = edx = 0;  // @77_455dd0
  FL[0] = eax; FL[1] = (u32)(4);  // @78_455dd0
  if (FL[0] == FL[1]) goto L455f3b;  // @79_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @80_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(275));  // @82_455dd0
  ecx = edx = 0;  // @83_455dd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @84_455dd0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @85_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @86_455dd0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 85), sizeof v); (u32)v; });  // @87_455dd0
  PV[15] = (u32)(eax);  // @88_455dd0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[15], (u32)(6827332), PV[14], PV[13]);  // @89_455dd0
  ecx = edx = 0;  // @90_455dd0
  L455f3b:;
  FL[0] = esi; FL[1] = edi;  // @92_455dd0
  if ((s32)FL[0] >= (s32)FL[1]) goto L455f4b;  // @93_455dd0
  L455f40:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @95_455dd0
  if (FL[0] == FL[1]) goto L455f4b;  // @96_455dd0
  esi = (esi + 1);  // @97_455dd0
  FL[3] = esi;  // @98_455dd0
  FL[0] = esi; FL[1] = edi;  // @99_455dd0
  if ((s32)FL[0] < (s32)FL[1]) goto L455f40;  // @100_455dd0
  L455f4b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @102_455dd0
  esi = (esi + 1);  // @103_455dd0
  FL[3] = esi;  // @104_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; });  // @105_455dd0
  eax = (eax + 1);  // @106_455dd0
  FL[3] = eax;  // @107_455dd0
  ecx = (ecx + (u32)(16));  // @108_455dd0
  FL[3] = ecx;  // @109_455dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @110_455dd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @111_455dd0
  FL[0] = eax; FL[1] = (u32)(8);  // @112_455dd0
  if (FL[0] == FL[1]) goto L455fe9;  // @113_455dd0
  FL[0] = esi; FL[1] = edi;  // @114_455dd0
  if ((s32)FL[0] < (s32)FL[1]) goto L455ee6;  // @115_455dd0
  L455f75:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @117_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(283));  // @119_455dd0
  ecx = edx = 0;  // @120_455dd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @121_455dd0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @122_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @123_455dd0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 85), sizeof v); (u32)v; });  // @124_455dd0
  PV[18] = (u32)(eax);  // @125_455dd0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[18], (u32)(6827364), PV[17], PV[16]);  // @126_455dd0
  ecx = edx = 0;  // @127_455dd0
  PV[19] = (u32)(ebx);  // @128_455dd0
  eax = ext_634273_cdecl2(PV[19], (u32)(1));  // @129_455dd0
  ecx = edx = 0;  // @130_455dd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @131_455dd0
  goto L456073;  // @132_455dd0
  L455fbd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @134_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(286));  // @136_455dd0
  ecx = edx = 0;  // @137_455dd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @138_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @139_455dd0
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 85), sizeof v); (u32)v; });  // @140_455dd0
  PV[21] = (u32)(eax);  // @141_455dd0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[21], (u32)(6827396), PV[20]);  // @142_455dd0
  ecx = edx = 0;  // @143_455dd0
  L455fe9:;
  PV[22] = (u32)(ebx);  // @145_455dd0
  eax = ext_634273_cdecl2(PV[22], (u32)(1));  // @146_455dd0
  ecx = edx = 0;  // @147_455dd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @148_455dd0
  goto L456073;  // @149_455dd0
  L455ffc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @151_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @152_455dd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @153_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @154_455dd0
  if (FL[0] == FL[1]) goto L45602c;  // @155_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(291));  // @156_455dd0
  ecx = edx = 0;  // @157_455dd0
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @158_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @159_455dd0
  PV[24] = (u32)(eax);  // @160_455dd0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[24], (u32)(6827428), PV[23]);  // @161_455dd0
  ecx = edx = 0;  // @162_455dd0
  goto L456073;  // @163_455dd0
  L45602c:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(293));  // @165_455dd0
  ecx = edx = 0;  // @166_455dd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @167_455dd0
  edi = eax;  // @168_455dd0
  eax = (u32)(EBP - 288);  // @169_455dd0
  ecx = ebx;  // @170_455dd0
  PV[25] = (u32)(eax);  // @171_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[25], (u32)(1));  // @172_455dd0
  ecx = edx = 0;  // @173_455dd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @174_455dd0
  ecx = eax;  // @175_455dd0
  reg.state = (s32)((u32)(2));  // @176_455dd0
  eax = ext_4cc1d0_thiscall1(ecx);  // @177_455dd0
  ecx = edx = 0;  // @178_455dd0
  PV[26] = (u32)(eax);  // @179_455dd0
  PV[27] = (u32)(edi);  // @180_455dd0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[27], (u32)(6827448), PV[26]);  // @181_455dd0
  ecx = edx = 0;  // @182_455dd0
  ecx = (u32)(EBP - 288);  // @183_455dd0
  eax = ext_4cbec0_thiscall1(ecx);  // @184_455dd0
  ecx = edx = 0;  // @185_455dd0
  L456073:;
  ecx = (u32)(EBP - 160);  // @187_455dd0
  reg.state = (s32)((u32)(4294967295));  // @188_455dd0
  eax = ext_4cbec0_thiscall1(ecx);  // @189_455dd0
  ecx = edx = 0;  // @190_455dd0
  L456085:;
  eax = ext_41e290_cdecl1((u32)(512));  // @192_455dd0
  ecx = edx = 0;  // @193_455dd0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6827704) + 0), 4); v; });  // @194_455dd0
  X3[1] = 0;  // @195_455dd0
  X3[2] = 0;  // @196_455dd0
  X3[3] = 0;  // @197_455dd0
  esi = (u32)(ebx + 93);  // @198_455dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 221), &v, sizeof v); }  // @199_455dd0
  edi = 0;  // @200_455dd0
  FL[3] = edi;  // @201_455dd0
  L4560b0:;
  X2[0] = edi; X2[1] = X2[2] = X2[3] = 0;  // @203_455dd0
  X2[0] = F2U((float)(s32)X2[0]);  // @204_455dd0
  X2[1] = F2U((float)(s32)X2[1]);  // @205_455dd0
  X2[2] = F2U((float)(s32)X2[2]);  // @206_455dd0
  X2[3] = F2U((float)(s32)X2[3]);  // @207_455dd0
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795040) + 0), 4); v; })));  // @208_455dd0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6823368) + 0), 4); v; })));  // @209_455dd0
  { float f_ = U2F(X2[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @210_455dd0
  edx = eax;  // @211_455dd0
  edx = (edx + edx);  // @212_455dd0
  FL[3] = edx;  // @213_455dd0
  FL[0] = eax; FL[1] = (u32)(7);  // @214_455dd0
  ecx = (u32)(eax + 1);  // @215_455dd0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @216_455dd0
  if ((s32)FL[0] >= (s32)FL[1]) ecx = eax;  // @217_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @218_455dd0
  ecx = (ecx << (u32)(4));  // @219_455dd0
  FL[3] = ecx;  // @220_455dd0
  ecx = (ecx + esi);  // @221_455dd0
  FL[3] = ecx;  // @222_455dd0
  X0[0] = F2U((float)(s32)X0[0]);  // @223_455dd0
  X0[1] = F2U((float)(s32)X0[1]);  // @224_455dd0
  X0[2] = F2U((float)(s32)X0[2]);  // @225_455dd0
  X0[3] = F2U((float)(s32)X0[3]);  // @226_455dd0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @227_455dd0
  X1[1] = 0;  // @228_455dd0
  X1[2] = 0;  // @229_455dd0
  X1[3] = 0;  // @230_455dd0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8) + 0), 4); v; })));  // @231_455dd0
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @232_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @233_455dd0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8) + 0), 4); v; })));  // @234_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @235_455dd0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X1[0], 4);  // @236_455dd0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; });  // @237_455dd0
  X1[1] = 0;  // @238_455dd0
  X1[2] = 0;  // @239_455dd0
  X1[3] = 0;  // @240_455dd0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8 + 4) + 0), 4); v; })));  // @241_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @242_455dd0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8 + 4) + 0), 4); v; })));  // @243_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @244_455dd0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X1[0], 4);  // @245_455dd0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; });  // @246_455dd0
  X1[1] = 0;  // @247_455dd0
  X1[2] = 0;  // @248_455dd0
  X1[3] = 0;  // @249_455dd0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8 + 8) + 0), 4); v; })));  // @250_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @251_455dd0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8 + 8) + 0), 4); v; })));  // @252_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @253_455dd0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X1[0], 4);  // @254_455dd0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 12) + 0), 4); v; });  // @255_455dd0
  X1[1] = 0;  // @256_455dd0
  X1[2] = 0;  // @257_455dd0
  X1[3] = 0;  // @258_455dd0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8 + 12) + 0), 4); v; })));  // @259_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @260_455dd0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*8 + 12) + 0), 4); v; })));  // @261_455dd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @262_455dd0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @263_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @264_455dd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @265_455dd0
  eax = (u32)(EBP - 32);  // @266_455dd0
  PV[28] = (u32)(eax);  // @267_455dd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 221), sizeof v); (u32)v; });  // @268_455dd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @269_455dd0
  eax = (u32)(eax + edi*4);  // @270_455dd0
  PV[29] = (u32)(eax);  // @271_455dd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[29], PV[28]);  // @272_455dd0
  ecx = edx = 0;  // @273_455dd0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6827704) + 0), 4); v; });  // @274_455dd0
  X3[1] = 0;  // @275_455dd0
  X3[2] = 0;  // @276_455dd0
  X3[3] = 0;  // @277_455dd0
  edi = (edi + 1);  // @278_455dd0
  FL[3] = edi;  // @279_455dd0
  FL[0] = edi; FL[1] = (u32)(128);  // @280_455dd0
  if ((s32)FL[0] < (s32)FL[1]) goto L4560b0;  // @281_455dd0
  SEH_LEAVE();  // @282_455dd0
  ext_633654(G(u32, 0x6f5630));  // @283_455dd0
  return eax;  // @284_455dd0
}
PCREG(455dd0, lifted_455dd0);

extern "C" u32 THISCALL lifted_57e4f0(u32 ecx_in) {
  SEH_ENTER(0x66b381);  // @h_57e4f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 400), &v, sizeof v); }  // @0_57e4f0
  edx = 0;  // @1_57e4f0
  FL[3] = edx;  // @2_57e4f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 824), sizeof v); (u32)v; }); FL[1] = edx;  // @3_57e4f0
  if (FL[0] <= FL[1]) goto L57e54f;  // @4_57e4f0
  L57e530:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 812), sizeof v); (u32)v; });  // @6_57e4f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @7_57e4f0
  if (FL[0] == FL[1]) goto L57e546;  // @8_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 816), sizeof v); (u32)v; });  // @9_57e4f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + eax), &v, sizeof v); }  // @10_57e4f0
  L57e546:;
  edx = (edx + 1);  // @12_57e4f0
  FL[3] = edx;  // @13_57e4f0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 824), sizeof v); (u32)v; });  // @14_57e4f0
  if (FL[0] < FL[1]) goto L57e530;  // @15_57e4f0
  L57e54f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 816), sizeof v); (u32)v; });  // @17_57e4f0
  ebx = 0;  // @18_57e4f0
  FL[3] = ebx;  // @19_57e4f0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @20_57e4f0
  FL[3] = (eax & 0xff);  // @21_57e4f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @22_57e4f0
  esi = 0;  // @23_57e4f0
  FL[3] = esi;  // @24_57e4f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @25_57e4f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @26_57e4f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @27_57e4f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @28_57e4f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @29_57e4f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 393), &v, sizeof v); }  // @30_57e4f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 824), sizeof v); (u32)v; }); FL[1] = ebx;  // @31_57e4f0
  if (FL[0] <= FL[1]) goto L57e90d;  // @32_57e4f0
  L57e595:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @34_57e4f0
  if (FL[2] != 0) goto L57e636;  // @35_57e4f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @36_57e4f0
  if (FL[0] == FL[1]) goto L57e629;  // @37_57e4f0
  FL[0] = esi; FL[1] = (u32)(144);  // @38_57e4f0
  if (FL[0] == FL[1]) goto L57e629;  // @39_57e4f0
  FL[2] = (esi & (u32)(4294901760));  // @40_57e4f0
  if (FL[2] == 0) goto L57e5ba;  // @41_57e4f0
  eax = esi;  // @42_57e4f0
  goto L57e5f4;  // @43_57e4f0
  L57e5ba:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_57e4f0
  eax = 0;  // @46_57e4f0
  FL[3] = eax;  // @47_57e4f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6411), sizeof v); (u32)v; });  // @48_57e4f0
  FL[2] = (edx & edx);  // @49_57e4f0
  if (FL[2] == 0) goto L57e5eb;  // @50_57e4f0
  edi = edx;  // @51_57e4f0
  L57e5d0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @53_57e4f0
  FL[0] = ebx; FL[1] = esi;  // @54_57e4f0
  if ((s32)FL[0] > (s32)FL[1]) goto L57e5e3;  // @55_57e4f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @56_57e4f0
  ecx = (ecx + ebx);  // @57_57e4f0
  FL[3] = ecx;  // @58_57e4f0
  FL[0] = ecx; FL[1] = esi;  // @59_57e4f0
  if ((s32)FL[0] > (s32)FL[1]) goto L57e86c;  // @60_57e4f0
  L57e5e3:;
  eax = (eax + 1);  // @62_57e4f0
  FL[3] = eax;  // @63_57e4f0
  edi = (edi + (u32)(16));  // @64_57e4f0
  FL[3] = edi;  // @65_57e4f0
  edx = edi;  // @66_57e4f0
  if (FL[3] != 0) goto L57e5d0;  // @67_57e4f0
  L57e5eb:;
  eax = (eax | (u32)(4294967295));  // @69_57e4f0
  FL[3] = eax;  // @70_57e4f0
  L57e5ee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 400), sizeof v); (u32)v; });  // @72_57e4f0
  L57e5f4:;
  edx = eax;  // @74_57e4f0
  edx = (edx >> (u32)(16));  // @75_57e4f0
  FL[3] = edx;  // @76_57e4f0
  FL[0] = edx; FL[1] = (u32)(1);  // @77_57e4f0
  if (FL[0] != FL[1]) goto L57e878;  // @78_57e4f0
  edx = (eax & 0xffff);  // @79_57e4f0
  FL[0] = edx; FL[1] = (u32)(7);  // @80_57e4f0
  if (FL[0] < FL[1]) goto L57e880;  // @81_57e4f0
  FL[0] = edx; FL[1] = (u32)(10);  // @82_57e4f0
  if (FL[0] > FL[1]) goto L57e880;  // @83_57e4f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @84_57e4f0
  L57e61d:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 393), sizeof v); (u32)v; })) & 0xff);  // @86_57e4f0
  L57e623:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 408), sizeof v); (u32)v; });  // @88_57e4f0
  L57e629:;
  esi = (esi + 1);  // @90_57e4f0
  FL[3] = esi;  // @91_57e4f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 824), sizeof v); (u32)v; });  // @92_57e4f0
  if (FL[0] < FL[1]) goto L57e595;  // @93_57e4f0
  L57e636:;
  FL[2] = (ebx & ebx);  // @95_57e4f0
  if (FL[2] == 0) goto L57e90d;  // @96_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 828), sizeof v); (u32)v; });  // @97_57e4f0
  edi = (u32)(ecx + 572);  // @98_57e4f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @99_57e4f0
  eax = (eax - 1);  // @100_57e4f0
  FL[3] = eax;  // @101_57e4f0
  PV[0] = (u32)(eax);  // @102_57e4f0
  ecx = edi;  // @103_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 48)))(ecx, PV[0]);  // @104_57e4f0
  ecx = edx = 0;  // @105_57e4f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @106_57e4f0
  PV[1] = (u32)(eax);  // @107_57e4f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[1]);  // @109_57e4f0
  ecx = edx = 0;  // @110_57e4f0
  ecx = (u32)(EBP - 392);  // @111_57e4f0
  esi = eax;  // @112_57e4f0
  eax = ext_4cbeb0_thiscall1(ecx);  // @113_57e4f0
  ecx = edx = 0;  // @114_57e4f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_57e4f0
  reg.state = (s32)((u32)(0));  // @116_57e4f0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_57e4f0
  ecx = (u32)(EBP - 164);  // @118_57e4f0
  eax = ext_4cbe80_thiscall2(ecx, PV[2]);  // @119_57e4f0
  ecx = edx = 0;  // @120_57e4f0
  eax = (u32)(EBP - 164);  // @121_57e4f0
  reg.state = (s32)((u32)(1));  // @122_57e4f0
  PV[3] = (u32)(eax);  // @123_57e4f0
  ecx = (u32)(EBP - 392);  // @124_57e4f0
  eax = ext_4cbee0_thiscall2(ecx, PV[3]);  // @125_57e4f0
  ecx = edx = 0;  // @126_57e4f0
  ecx = (u32)(EBP - 164);  // @127_57e4f0
  reg.state = (s32)((u32)(0));  // @128_57e4f0
  eax = ext_4cbec0_thiscall1(ecx);  // @129_57e4f0
  ecx = edx = 0;  // @130_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @131_57e4f0
  ecx = (u32)(EBP - 212);  // @132_57e4f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 0), 4); v; });  // @133_57e4f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 4), 4); v; });  // @134_57e4f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 8), 4); v; });  // @135_57e4f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 12), 4); v; });  // @136_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @137_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @138_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @139_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @140_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 256), &v, sizeof v); }  // @141_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @142_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 252), &v, sizeof v); }  // @143_57e4f0
  eax = (u32)(EBP - 392);  // @144_57e4f0
  PV[4] = (u32)(eax);  // @145_57e4f0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @146_57e4f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 231), &v, sizeof v); }  // @147_57e4f0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 227), &v, sizeof v); }  // @148_57e4f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 217), &v, sizeof v); }  // @149_57e4f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 225), &v, sizeof v); }  // @150_57e4f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 221), &v, sizeof v); }  // @151_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 0), &X0[0], 4);  // @152_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 4), &X0[1], 4);  // @153_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 8), &X0[2], 4);  // @154_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 12), &X0[3], 4);  // @155_57e4f0
  eax = ext_4cbe50_thiscall2(ecx, PV[4]);  // @156_57e4f0
  ecx = edx = 0;  // @157_57e4f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; });  // @158_57e4f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 264) + 0), 4); v; });  // @159_57e4f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 264) + 4), 4); v; });  // @160_57e4f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 264) + 8), 4); v; });  // @161_57e4f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 264) + 12), 4); v; });  // @162_57e4f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @163_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 231), sizeof v); (u32)v; });  // @164_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 51), &v, sizeof v); }  // @165_57e4f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 227), sizeof v); (u32)v; });  // @166_57e4f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 47), &v, sizeof v); }  // @167_57e4f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 226), sizeof v); (u32)v; });  // @168_57e4f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 46), &v, sizeof v); }  // @169_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 225), sizeof v); (u32)v; });  // @170_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X0[0], 4);  // @171_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 84) + 4), &X0[1], 4);  // @172_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 84) + 8), &X0[2], 4);  // @173_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 84) + 12), &X0[3], 4);  // @174_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 45), &v, sizeof v); }  // @175_57e4f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 248) + 0), 4); v; });  // @176_57e4f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 248) + 4), 4); v; });  // @177_57e4f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 248) + 8), 4); v; });  // @178_57e4f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 248) + 12), 4); v; });  // @179_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 221), sizeof v); (u32)v; });  // @180_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 41), &v, sizeof v); }  // @181_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 217), sizeof v); (u32)v; });  // @182_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @183_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 68) + 4), &X0[1], 4);  // @184_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 68) + 8), &X0[2], 4);  // @185_57e4f0
  __builtin_memcpy((void *)((u32)(EBP - 68) + 12), &X0[3], 4);  // @186_57e4f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 37), &v, sizeof v); }  // @187_57e4f0
  eax = (u32)(EBP - 212);  // @188_57e4f0
  reg.state = (s32)((u32)(2));  // @189_57e4f0
  PV[5] = (u32)(eax);  // @190_57e4f0
  ecx = (u32)(esi + 44);  // @191_57e4f0
  eax = ext_57c910_thiscall2(ecx, PV[5]);  // @192_57e4f0
  ecx = edx = 0;  // @193_57e4f0
  ecx = esi;  // @194_57e4f0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 223), &v, sizeof v); }  // @195_57e4f0
  eax = ext_57ee90_thiscall1(ecx);  // @196_57e4f0
  ecx = edx = 0;  // @197_57e4f0
  ecx = (u32)(EBP - 212);  // @198_57e4f0
  reg.state = (s32)((u32)(0));  // @199_57e4f0
  eax = ext_4cbec0_thiscall1(ecx);  // @200_57e4f0
  ecx = edx = 0;  // @201_57e4f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 400), sizeof v); (u32)v; });  // @202_57e4f0
  ecx = esi;  // @203_57e4f0
  eax = ext_57d780_thiscall1(ecx);  // @204_57e4f0
  ecx = edx = 0;  // @205_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 400), sizeof v); (u32)v; });  // @206_57e4f0
  ecx = (u32)(esi + 400);  // @207_57e4f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @208_57e4f0
  ecx = edx = 0;  // @209_57e4f0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @210_57e4f0
  FL[3] = (ebx & 0xff);  // @211_57e4f0
  FL[2] = (edi & edi);  // @212_57e4f0
  if (FL[2] == 0) goto L57e837;  // @213_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @214_57e4f0
  ecx = (u32)(EBP - 420);  // @215_57e4f0
  PV[6] = (u32)(ecx);  // @216_57e4f0
  ecx = edi;  // @217_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @218_57e4f0
  ecx = edx = 0;  // @219_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @220_57e4f0
  ecx = (u32)(EBP - 420);  // @221_57e4f0
  PV[7] = (u32)(ecx);  // @222_57e4f0
  ecx = edi;  // @223_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @224_57e4f0
  ecx = edx = 0;  // @225_57e4f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @226_57e4f0
  if (FL[0] == FL[1]) goto L57e837;  // @227_57e4f0
  L57e7f5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @229_57e4f0
  PV[8] = (u32)(eax);  // @230_57e4f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @231_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[8]);  // @232_57e4f0
  ecx = edx = 0;  // @233_57e4f0
  FL[2] = (eax & eax);  // @234_57e4f0
  if (FL[2] == 0) goto L57e820;  // @235_57e4f0
  ecx = 0;  // @236_57e4f0
  FL[3] = ecx;  // @237_57e4f0
  eax = (eax + (u32)(172));  // @238_57e4f0
  FL[3] = eax;  // @239_57e4f0
  L57e810:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(-1);  // @241_57e4f0
  if (FL[0] != FL[1]) goto L57e820;  // @242_57e4f0
  ecx = (ecx + 1);  // @243_57e4f0
  FL[3] = ecx;  // @244_57e4f0
  eax = (eax + (u32)(4));  // @245_57e4f0
  FL[3] = eax;  // @246_57e4f0
  FL[0] = ecx; FL[1] = (u32)(4);  // @247_57e4f0
  if ((s32)FL[0] < (s32)FL[1]) goto L57e810;  // @248_57e4f0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @249_57e4f0
  L57e820:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @251_57e4f0
  ecx = (u32)(EBP - 420);  // @252_57e4f0
  PV[9] = (u32)(ecx);  // @253_57e4f0
  ecx = edi;  // @254_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[9]);  // @255_57e4f0
  ecx = edx = 0;  // @256_57e4f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @257_57e4f0
  if (FL[0] != FL[1]) goto L57e7f5;  // @258_57e4f0
  L57e837:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @260_57e4f0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 392), sizeof v); (u32)v; });  // @261_57e4f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @262_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @263_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[10]);  // @264_57e4f0
  ecx = edx = 0;  // @265_57e4f0
  ecx = eax;  // @266_57e4f0
  FL[2] = (ecx & ecx);  // @267_57e4f0
  if (FL[2] == 0) goto L57e902;  // @268_57e4f0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @269_57e4f0
  if (FL[2] == 0) goto L57e8fa;  // @270_57e4f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @271_57e4f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 732)))(ecx);  // @272_57e4f0
  ecx = edx = 0;  // @273_57e4f0
  goto L57e902;  // @274_57e4f0
  L57e86c:;
  eax = (eax << (u32)(16));  // @276_57e4f0
  FL[3] = eax;  // @277_57e4f0
  eax = (eax - ebx);  // @278_57e4f0
  FL[3] = eax;  // @279_57e4f0
  eax = (eax + esi);  // @280_57e4f0
  FL[3] = eax;  // @281_57e4f0
  goto L57e5ee;  // @282_57e4f0
  L57e878:;
  FL[2] = (edx & edx);  // @284_57e4f0
  if (FL[2] != 0) goto L57e880;  // @285_57e4f0
  FL[2] = (esi & esi);  // @286_57e4f0
  if (FL[2] == 0) goto L57e8b3;  // @287_57e4f0
  L57e880:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @289_57e4f0
  FL[0] = eax; FL[1] = (u32)(-1);  // @290_57e4f0
  if (FL[0] == FL[1]) goto L57e61d;  // @291_57e4f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + ebx*4 - 32), &v, sizeof v); }  // @292_57e4f0
  ebx = (ebx + 1);  // @293_57e4f0
  FL[3] = ebx;  // @294_57e4f0
  PV[11] = (u32)(esi);  // @295_57e4f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @296_57e4f0
  eax = ext_57d950_thiscall2(ecx, PV[11]);  // @297_57e4f0
  ecx = edx = 0;  // @298_57e4f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 400), sizeof v); (u32)v; });  // @299_57e4f0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @300_57e4f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 393), &v, sizeof v); }  // @301_57e4f0
  goto L57e623;  // @302_57e4f0
  L57e8b3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 400), sizeof v); (u32)v; });  // @304_57e4f0
  ecx = (ecx + (u32)(572));  // @305_57e4f0
  FL[3] = ecx;  // @306_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 828), sizeof v); (u32)v; });  // @307_57e4f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @308_57e4f0
  eax = (eax - 1);  // @309_57e4f0
  FL[3] = eax;  // @310_57e4f0
  PV[12] = (u32)(eax);  // @311_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 48)))(ecx, PV[12]);  // @312_57e4f0
  ecx = edx = 0;  // @313_57e4f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @314_57e4f0
  PV[13] = (u32)(eax);  // @315_57e4f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @316_57e4f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[13]);  // @317_57e4f0
  ecx = edx = 0;  // @318_57e4f0
  ecx = eax;  // @319_57e4f0
  eax = ext_57ee90_thiscall1(ecx);  // @320_57e4f0
  ecx = edx = 0;  // @321_57e4f0
  ecx = esi;  // @322_57e4f0
  eax = ext_57d780_thiscall1(ecx);  // @323_57e4f0
  ecx = edx = 0;  // @324_57e4f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 400), sizeof v); (u32)v; });  // @325_57e4f0
  ecx = (u32)(esi + 400);  // @326_57e4f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @327_57e4f0
  ecx = edx = 0;  // @328_57e4f0
  goto L57e90d;  // @329_57e4f0
  L57e8fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @331_57e4f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 728)))(ecx);  // @332_57e4f0
  ecx = edx = 0;  // @333_57e4f0
  L57e902:;
  ecx = (u32)(EBP - 392);  // @335_57e4f0
  eax = ext_4cbec0_thiscall1(ecx);  // @336_57e4f0
  ecx = edx = 0;  // @337_57e4f0
  L57e90d:;
  SEH_LEAVE();  // @339_57e4f0
  ext_633654(G(u32, 0x6f5630));  // @340_57e4f0
  return eax;  // @341_57e4f0
}
PCREG(57e4f0, lifted_57e4f0);

extern "C" u32 THISCALL lifted_5a6980(u32 ecx_in) {
  SEH_ENTER(0x66c176);  // @h_5a6980
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5a6980
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @1_5a6980
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_5a6980
  if (FL[0] != FL[1]) goto L5a6af7;  // @3_5a6980
  eax = ext_41e290_cdecl1((u32)(247));  // @4_5a6980
  ecx = edx = 0;  // @5_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @6_5a6980
  reg.state = (s32)((u32)(0));  // @7_5a6980
  FL[2] = (eax & eax);  // @8_5a6980
  if (FL[2] == 0) goto L5a69ea;  // @9_5a6980
  ecx = eax;  // @10_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @11_5a6980
  ecx = edx = 0;  // @12_5a6980
  goto L5a69ec;  // @13_5a6980
  L5a69ea:;
  eax = 0;  // @15_5a6980
  FL[3] = eax;  // @16_5a6980
  L5a69ec:;
  esi = (u32)(edi + 1625);  // @18_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1080), &v, sizeof v); }  // @19_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @20_5a6980
  reg.state = (s32)((u32)(4294967295));  // @21_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @22_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @23_5a6980
  if (FL[0] == FL[1]) goto L5a6a19;  // @24_5a6980
  FL[2] = (ecx & ecx);  // @25_5a6980
  if (FL[2] == 0) goto L5a6a13;  // @26_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @27_5a6980
  L5a6a13:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @29_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @30_5a6980
  goto L5a6a28;  // @31_5a6980
  L5a6a19:;
  eax = (u32)(EBP - 136);  // @33_5a6980
  PV[0] = (u32)(eax);  // @34_5a6980
  PV[1] = (u32)(ecx);  // @35_5a6980
  ecx = esi;  // @36_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[1], PV[0]);  // @37_5a6980
  ecx = edx = 0;  // @38_5a6980
  L5a6a28:;
  eax = ext_41e290_cdecl1((u32)(215));  // @40_5a6980
  ecx = edx = 0;  // @41_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @42_5a6980
  reg.state = (s32)((u32)(1));  // @43_5a6980
  FL[2] = (eax & eax);  // @44_5a6980
  if (FL[2] == 0) goto L5a6a51;  // @45_5a6980
  ecx = eax;  // @46_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @47_5a6980
  ecx = edx = 0;  // @48_5a6980
  goto L5a6a53;  // @49_5a6980
  L5a6a51:;
  eax = 0;  // @51_5a6980
  FL[3] = eax;  // @52_5a6980
  L5a6a53:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1084), &v, sizeof v); }  // @54_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @55_5a6980
  reg.state = (s32)((u32)(4294967295));  // @56_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @57_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @58_5a6980
  if (FL[0] == FL[1]) goto L5a6a7a;  // @59_5a6980
  FL[2] = (ecx & ecx);  // @60_5a6980
  if (FL[2] == 0) goto L5a6a74;  // @61_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @62_5a6980
  L5a6a74:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @64_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @65_5a6980
  goto L5a6a89;  // @66_5a6980
  L5a6a7a:;
  eax = (u32)(EBP - 136);  // @68_5a6980
  PV[2] = (u32)(eax);  // @69_5a6980
  PV[3] = (u32)(ecx);  // @70_5a6980
  ecx = esi;  // @71_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[3], PV[2]);  // @72_5a6980
  ecx = edx = 0;  // @73_5a6980
  L5a6a89:;
  eax = ext_41e290_cdecl1((u32)(132));  // @75_5a6980
  ecx = edx = 0;  // @76_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @77_5a6980
  reg.state = (s32)((u32)(2));  // @78_5a6980
  FL[2] = (eax & eax);  // @79_5a6980
  if (FL[2] == 0) goto L5a6ab2;  // @80_5a6980
  ecx = eax;  // @81_5a6980
  eax = ext_5edd80_thiscall2(ecx, (u32)(3));  // @82_5a6980
  ecx = edx = 0;  // @83_5a6980
  goto L5a6ab4;  // @84_5a6980
  L5a6ab2:;
  eax = 0;  // @86_5a6980
  FL[3] = eax;  // @87_5a6980
  L5a6ab4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1592), &v, sizeof v); }  // @89_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @90_5a6980
  reg.state = (s32)((u32)(4294967295));  // @91_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @92_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @93_5a6980
  if (FL[0] == FL[1]) goto L5a6adb;  // @94_5a6980
  FL[2] = (ecx & ecx);  // @95_5a6980
  if (FL[2] == 0) goto L5a6ad5;  // @96_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @97_5a6980
  L5a6ad5:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @99_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @100_5a6980
  goto L5a6aea;  // @101_5a6980
  L5a6adb:;
  eax = (u32)(EBP - 136);  // @103_5a6980
  PV[4] = (u32)(eax);  // @104_5a6980
  PV[5] = (u32)(ecx);  // @105_5a6980
  ecx = esi;  // @106_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[5], PV[4]);  // @107_5a6980
  ecx = edx = 0;  // @108_5a6980
  L5a6aea:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @110_5a6980
  if (FL[0] == FL[1]) goto L5a6c1c;  // @111_5a6980
  L5a6af7:;
  eax = ext_41e290_cdecl1((u32)(132));  // @113_5a6980
  ecx = edx = 0;  // @114_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @115_5a6980
  reg.state = (s32)((u32)(3));  // @116_5a6980
  FL[2] = (eax & eax);  // @117_5a6980
  if (FL[2] == 0) goto L5a6b20;  // @118_5a6980
  ecx = eax;  // @119_5a6980
  eax = ext_5edd80_thiscall2(ecx, (u32)(1));  // @120_5a6980
  ecx = edx = 0;  // @121_5a6980
  goto L5a6b22;  // @122_5a6980
  L5a6b20:;
  eax = 0;  // @124_5a6980
  FL[3] = eax;  // @125_5a6980
  L5a6b22:;
  esi = (u32)(edi + 1637);  // @127_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1596), &v, sizeof v); }  // @128_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @129_5a6980
  reg.state = (s32)((u32)(4294967295));  // @130_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @131_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @132_5a6980
  if (FL[0] == FL[1]) goto L5a6b4f;  // @133_5a6980
  FL[2] = (ecx & ecx);  // @134_5a6980
  if (FL[2] == 0) goto L5a6b49;  // @135_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @136_5a6980
  L5a6b49:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @138_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @139_5a6980
  goto L5a6b5e;  // @140_5a6980
  L5a6b4f:;
  eax = (u32)(EBP - 136);  // @142_5a6980
  PV[6] = (u32)(eax);  // @143_5a6980
  PV[7] = (u32)(ecx);  // @144_5a6980
  ecx = esi;  // @145_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[7], PV[6]);  // @146_5a6980
  ecx = edx = 0;  // @147_5a6980
  L5a6b5e:;
  eax = ext_41e290_cdecl1((u32)(219));  // @149_5a6980
  ecx = edx = 0;  // @150_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @151_5a6980
  reg.state = (s32)((u32)(4));  // @152_5a6980
  FL[2] = (eax & eax);  // @153_5a6980
  if (FL[2] == 0) goto L5a6b85;  // @154_5a6980
  ecx = eax;  // @155_5a6980
  eax = ext_5f0020_thiscall1(ecx);  // @156_5a6980
  ecx = edx = 0;  // @157_5a6980
  goto L5a6b87;  // @158_5a6980
  L5a6b85:;
  eax = 0;  // @160_5a6980
  FL[3] = eax;  // @161_5a6980
  L5a6b87:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2215), &v, sizeof v); }  // @163_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @164_5a6980
  reg.state = (s32)((u32)(4294967295));  // @165_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @166_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @167_5a6980
  if (FL[0] == FL[1]) goto L5a6bae;  // @168_5a6980
  FL[2] = (ecx & ecx);  // @169_5a6980
  if (FL[2] == 0) goto L5a6ba8;  // @170_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @171_5a6980
  L5a6ba8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @173_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @174_5a6980
  goto L5a6bbd;  // @175_5a6980
  L5a6bae:;
  eax = (u32)(EBP - 136);  // @177_5a6980
  PV[8] = (u32)(eax);  // @178_5a6980
  PV[9] = (u32)(ecx);  // @179_5a6980
  ecx = esi;  // @180_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[9], PV[8]);  // @181_5a6980
  ecx = edx = 0;  // @182_5a6980
  L5a6bbd:;
  eax = ext_41e290_cdecl1((u32)(219));  // @184_5a6980
  ecx = edx = 0;  // @185_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @186_5a6980
  reg.state = (s32)((u32)(5));  // @187_5a6980
  FL[2] = (eax & eax);  // @188_5a6980
  if (FL[2] == 0) goto L5a6be4;  // @189_5a6980
  ecx = eax;  // @190_5a6980
  eax = ext_5f0020_thiscall1(ecx);  // @191_5a6980
  ecx = edx = 0;  // @192_5a6980
  goto L5a6be6;  // @193_5a6980
  L5a6be4:;
  eax = 0;  // @195_5a6980
  FL[3] = eax;  // @196_5a6980
  L5a6be6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2219), &v, sizeof v); }  // @198_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @199_5a6980
  reg.state = (s32)((u32)(4294967295));  // @200_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @201_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @202_5a6980
  if (FL[0] == FL[1]) goto L5a6c0d;  // @203_5a6980
  FL[2] = (ecx & ecx);  // @204_5a6980
  if (FL[2] == 0) goto L5a6c07;  // @205_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @206_5a6980
  L5a6c07:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @208_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @209_5a6980
  goto L5a6c1c;  // @210_5a6980
  L5a6c0d:;
  eax = (u32)(EBP - 136);  // @212_5a6980
  PV[10] = (u32)(eax);  // @213_5a6980
  PV[11] = (u32)(ecx);  // @214_5a6980
  ecx = esi;  // @215_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[11], PV[10]);  // @216_5a6980
  ecx = edx = 0;  // @217_5a6980
  L5a6c1c:;
  eax = (u32)(edi + 1076);  // @219_5a6980
  ebx = 0;  // @220_5a6980
  FL[3] = ebx;  // @221_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @222_5a6980
  esi = (u32)(edi + 1649);  // @223_5a6980
  eax = (u32)(edi + 1144);  // @224_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @225_5a6980
  eax = (u32)(edi + 1196);  // @226_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @227_5a6980
  eax = (u32)(edi + 1192);  // @228_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @229_5a6980
  eax = (u32)(edi + 1188);  // @230_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @231_5a6980
  eax = (u32)(edi + 1184);  // @232_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @233_5a6980
  eax = (u32)(edi + 1180);  // @234_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @235_5a6980
  eax = (u32)(edi + 1176);  // @236_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @237_5a6980
  eax = (u32)(edi + 1172);  // @238_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @239_5a6980
  eax = (u32)(edi + 1168);  // @240_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @241_5a6980
  eax = (u32)(edi + 1164);  // @242_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @243_5a6980
  eax = (u32)(edi + 1152);  // @244_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @245_5a6980
  eax = (u32)(edi + 1156);  // @246_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @247_5a6980
  eax = (u32)(edi + 1160);  // @248_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @249_5a6980
  eax = (u32)(edi + 1200);  // @250_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @251_5a6980
  eax = (u32)(edi + 1204);  // @252_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @253_5a6980
  eax = (u32)(edi + 1673);  // @254_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @255_5a6980
  eax = (u32)(edi + 1072);  // @256_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @257_5a6980
  eax = (u32)(edi + 1528);  // @258_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @259_5a6980
  eax = (u32)(edi + 1532);  // @260_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @261_5a6980
  eax = (u32)(edi + 1536);  // @262_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @263_5a6980
  eax = (u32)(edi + 1540);  // @264_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @265_5a6980
  eax = (u32)(edi + 1544);  // @266_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @267_5a6980
  eax = (u32)(edi + 1548);  // @268_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @269_5a6980
  eax = (u32)(edi + 1552);  // @270_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @271_5a6980
  eax = (u32)(edi + 1556);  // @272_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @273_5a6980
  eax = (u32)(edi + 1560);  // @274_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @275_5a6980
  eax = (u32)(edi + 1568);  // @276_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @277_5a6980
  eax = (u32)(edi + 1564);  // @278_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @279_5a6980
  L5a6d30:;
  eax = ext_41e290_cdecl1((u32)(215));  // @281_5a6980
  ecx = edx = 0;  // @282_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @283_5a6980
  reg.state = (s32)((u32)(6));  // @284_5a6980
  FL[2] = (eax & eax);  // @285_5a6980
  if (FL[2] == 0) goto L5a6d5b;  // @286_5a6980
  ecx = eax;  // @287_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @288_5a6980
  ecx = edx = 0;  // @289_5a6980
  ecx = eax;  // @290_5a6980
  goto L5a6d5d;  // @291_5a6980
  L5a6d5b:;
  ecx = 0;  // @293_5a6980
  FL[3] = ecx;  // @294_5a6980
  L5a6d5d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 132), sizeof v); (u32)v; });  // @296_5a6980
  reg.state = (s32)((u32)(4294967295));  // @297_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @298_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @299_5a6980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @300_5a6980
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @301_5a6980
  if (FL[0] == FL[1]) goto L5a6d87;  // @302_5a6980
  FL[2] = (eax & eax);  // @303_5a6980
  if (FL[2] == 0) goto L5a6d81;  // @304_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @305_5a6980
  L5a6d81:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @307_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @308_5a6980
  goto L5a6d96;  // @309_5a6980
  L5a6d87:;
  ecx = (u32)(EBP - 136);  // @311_5a6980
  PV[12] = (u32)(ecx);  // @312_5a6980
  PV[13] = (u32)(eax);  // @313_5a6980
  ecx = esi;  // @314_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[13], PV[12]);  // @315_5a6980
  ecx = edx = 0;  // @316_5a6980
  L5a6d96:;
  ebx = (ebx + 1);  // @318_5a6980
  FL[3] = ebx;  // @319_5a6980
  FL[0] = ebx; FL[1] = (u32)(18);  // @320_5a6980
  if (FL[0] < FL[1]) goto L5a6d30;  // @321_5a6980
  ebx = 0;  // @322_5a6980
  FL[3] = ebx;  // @323_5a6980
  L5a6da0:;
  eax = ext_41e290_cdecl1((u32)(167));  // @325_5a6980
  ecx = edx = 0;  // @326_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @327_5a6980
  reg.state = (s32)((u32)(7));  // @328_5a6980
  FL[2] = (eax & eax);  // @329_5a6980
  if (FL[2] == 0) goto L5a6dcb;  // @330_5a6980
  ecx = eax;  // @331_5a6980
  eax = ext_5ebae0_thiscall2(ecx, (u32)(12));  // @332_5a6980
  ecx = edx = 0;  // @333_5a6980
  ecx = eax;  // @334_5a6980
  goto L5a6dcd;  // @335_5a6980
  L5a6dcb:;
  ecx = 0;  // @337_5a6980
  FL[3] = ecx;  // @338_5a6980
  L5a6dcd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 60), sizeof v); (u32)v; });  // @340_5a6980
  reg.state = (s32)((u32)(4294967295));  // @341_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @342_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @343_5a6980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @344_5a6980
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @345_5a6980
  if (FL[0] == FL[1]) goto L5a6df4;  // @346_5a6980
  FL[2] = (eax & eax);  // @347_5a6980
  if (FL[2] == 0) goto L5a6dee;  // @348_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @349_5a6980
  L5a6dee:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @351_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @352_5a6980
  goto L5a6e03;  // @353_5a6980
  L5a6df4:;
  ecx = (u32)(EBP - 136);  // @355_5a6980
  PV[14] = (u32)(ecx);  // @356_5a6980
  PV[15] = (u32)(eax);  // @357_5a6980
  ecx = esi;  // @358_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[15], PV[14]);  // @359_5a6980
  ecx = edx = 0;  // @360_5a6980
  L5a6e03:;
  ebx = (ebx + 1);  // @362_5a6980
  FL[3] = ebx;  // @363_5a6980
  FL[0] = ebx; FL[1] = (u32)(11);  // @364_5a6980
  if (FL[0] < FL[1]) goto L5a6da0;  // @365_5a6980
  eax = ext_41e290_cdecl1((u32)(167));  // @366_5a6980
  ecx = edx = 0;  // @367_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @368_5a6980
  reg.state = (s32)((u32)(8));  // @369_5a6980
  FL[2] = (eax & eax);  // @370_5a6980
  if (FL[2] == 0) goto L5a6e35;  // @371_5a6980
  ecx = eax;  // @372_5a6980
  eax = ext_5ebae0_thiscall2(ecx, (u32)(256));  // @373_5a6980
  ecx = edx = 0;  // @374_5a6980
  goto L5a6e37;  // @375_5a6980
  L5a6e35:;
  eax = 0;  // @377_5a6980
  FL[3] = eax;  // @378_5a6980
  L5a6e37:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1572), &v, sizeof v); }  // @380_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @381_5a6980
  reg.state = (s32)((u32)(4294967295));  // @382_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @383_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @384_5a6980
  if (FL[0] == FL[1]) goto L5a6e5e;  // @385_5a6980
  FL[2] = (ecx & ecx);  // @386_5a6980
  if (FL[2] == 0) goto L5a6e58;  // @387_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @388_5a6980
  L5a6e58:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @390_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @391_5a6980
  goto L5a6e6d;  // @392_5a6980
  L5a6e5e:;
  eax = (u32)(EBP - 136);  // @394_5a6980
  PV[16] = (u32)(eax);  // @395_5a6980
  PV[17] = (u32)(ecx);  // @396_5a6980
  ecx = esi;  // @397_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[17], PV[16]);  // @398_5a6980
  ecx = edx = 0;  // @399_5a6980
  L5a6e6d:;
  ebx = (u32)(edi + 1088);  // @401_5a6980
  edi = (u32)(12);  // @402_5a6980
  L5a6e80:;
  eax = ext_41e290_cdecl1((u32)(215));  // @404_5a6980
  ecx = edx = 0;  // @405_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @406_5a6980
  reg.state = (s32)((u32)(9));  // @407_5a6980
  FL[2] = (eax & eax);  // @408_5a6980
  if (FL[2] == 0) goto L5a6ea9;  // @409_5a6980
  ecx = eax;  // @410_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @411_5a6980
  ecx = edx = 0;  // @412_5a6980
  goto L5a6eab;  // @413_5a6980
  L5a6ea9:;
  eax = 0;  // @415_5a6980
  FL[3] = eax;  // @416_5a6980
  L5a6eab:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @418_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @419_5a6980
  reg.state = (s32)((u32)(4294967295));  // @420_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @421_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @422_5a6980
  if (FL[0] == FL[1]) goto L5a6ece;  // @423_5a6980
  FL[2] = (ecx & ecx);  // @424_5a6980
  if (FL[2] == 0) goto L5a6ec8;  // @425_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @426_5a6980
  L5a6ec8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @428_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @429_5a6980
  goto L5a6edd;  // @430_5a6980
  L5a6ece:;
  eax = (u32)(EBP - 136);  // @432_5a6980
  PV[18] = (u32)(eax);  // @433_5a6980
  PV[19] = (u32)(ecx);  // @434_5a6980
  ecx = esi;  // @435_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[19], PV[18]);  // @436_5a6980
  ecx = edx = 0;  // @437_5a6980
  L5a6edd:;
  ebx = (ebx + (u32)(4));  // @439_5a6980
  FL[3] = ebx;  // @440_5a6980
  edi = (edi - (u32)(1));  // @441_5a6980
  FL[3] = edi;  // @442_5a6980
  if (FL[3] != 0) goto L5a6e80;  // @443_5a6980
  eax = ext_41e290_cdecl1((u32)(247));  // @444_5a6980
  ecx = edx = 0;  // @445_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @446_5a6980
  reg.state = (s32)((u32)(10));  // @447_5a6980
  FL[2] = (eax & eax);  // @448_5a6980
  if (FL[2] == 0) goto L5a6f0c;  // @449_5a6980
  ecx = eax;  // @450_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @451_5a6980
  ecx = edx = 0;  // @452_5a6980
  goto L5a6f0e;  // @453_5a6980
  L5a6f0c:;
  eax = 0;  // @455_5a6980
  FL[3] = eax;  // @456_5a6980
  L5a6f0e:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @458_5a6980
  reg.state = (s32)((u32)(4294967295));  // @459_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @460_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1136), &v, sizeof v); }  // @461_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @462_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @463_5a6980
  if (FL[0] == FL[1]) goto L5a6f3b;  // @464_5a6980
  FL[2] = (ecx & ecx);  // @465_5a6980
  if (FL[2] == 0) goto L5a6f35;  // @466_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @467_5a6980
  L5a6f35:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @469_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @470_5a6980
  goto L5a6f4a;  // @471_5a6980
  L5a6f3b:;
  eax = (u32)(EBP - 136);  // @473_5a6980
  PV[20] = (u32)(eax);  // @474_5a6980
  PV[21] = (u32)(ecx);  // @475_5a6980
  ecx = esi;  // @476_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[21], PV[20]);  // @477_5a6980
  ecx = edx = 0;  // @478_5a6980
  L5a6f4a:;
  eax = ext_41e290_cdecl1((u32)(168));  // @480_5a6980
  ecx = edx = 0;  // @481_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @482_5a6980
  reg.state = (s32)((u32)(11));  // @483_5a6980
  FL[2] = (eax & eax);  // @484_5a6980
  if (FL[2] == 0) goto L5a6f73;  // @485_5a6980
  ecx = eax;  // @486_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(1));  // @487_5a6980
  ecx = edx = 0;  // @488_5a6980
  goto L5a6f75;  // @489_5a6980
  L5a6f73:;
  eax = 0;  // @491_5a6980
  FL[3] = eax;  // @492_5a6980
  L5a6f75:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1600), &v, sizeof v); }  // @494_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @495_5a6980
  reg.state = (s32)((u32)(4294967295));  // @496_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @497_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @498_5a6980
  if (FL[0] == FL[1]) goto L5a6f9c;  // @499_5a6980
  FL[2] = (ecx & ecx);  // @500_5a6980
  if (FL[2] == 0) goto L5a6f96;  // @501_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @502_5a6980
  L5a6f96:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @504_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @505_5a6980
  goto L5a6fab;  // @506_5a6980
  L5a6f9c:;
  eax = (u32)(EBP - 136);  // @508_5a6980
  PV[22] = (u32)(eax);  // @509_5a6980
  PV[23] = (u32)(ecx);  // @510_5a6980
  ecx = esi;  // @511_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[23], PV[22]);  // @512_5a6980
  ecx = edx = 0;  // @513_5a6980
  L5a6fab:;
  eax = ext_41e290_cdecl1((u32)(168));  // @515_5a6980
  ecx = edx = 0;  // @516_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @517_5a6980
  reg.state = (s32)((u32)(12));  // @518_5a6980
  FL[2] = (eax & eax);  // @519_5a6980
  if (FL[2] == 0) goto L5a6fd4;  // @520_5a6980
  ecx = eax;  // @521_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(6));  // @522_5a6980
  ecx = edx = 0;  // @523_5a6980
  goto L5a6fd6;  // @524_5a6980
  L5a6fd4:;
  eax = 0;  // @526_5a6980
  FL[3] = eax;  // @527_5a6980
  L5a6fd6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1604), &v, sizeof v); }  // @529_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @530_5a6980
  reg.state = (s32)((u32)(4294967295));  // @531_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @532_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @533_5a6980
  if (FL[0] == FL[1]) goto L5a6ffd;  // @534_5a6980
  FL[2] = (ecx & ecx);  // @535_5a6980
  if (FL[2] == 0) goto L5a6ff7;  // @536_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @537_5a6980
  L5a6ff7:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @539_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @540_5a6980
  goto L5a700c;  // @541_5a6980
  L5a6ffd:;
  eax = (u32)(EBP - 136);  // @543_5a6980
  PV[24] = (u32)(eax);  // @544_5a6980
  PV[25] = (u32)(ecx);  // @545_5a6980
  ecx = esi;  // @546_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[25], PV[24]);  // @547_5a6980
  ecx = edx = 0;  // @548_5a6980
  L5a700c:;
  eax = ext_41e290_cdecl1((u32)(168));  // @550_5a6980
  ecx = edx = 0;  // @551_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @552_5a6980
  reg.state = (s32)((u32)(13));  // @553_5a6980
  FL[2] = (eax & eax);  // @554_5a6980
  if (FL[2] == 0) goto L5a7035;  // @555_5a6980
  ecx = eax;  // @556_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(1));  // @557_5a6980
  ecx = edx = 0;  // @558_5a6980
  goto L5a7037;  // @559_5a6980
  L5a7035:;
  eax = 0;  // @561_5a6980
  FL[3] = eax;  // @562_5a6980
  L5a7037:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1608), &v, sizeof v); }  // @564_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @565_5a6980
  reg.state = (s32)((u32)(4294967295));  // @566_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @567_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @568_5a6980
  if (FL[0] == FL[1]) goto L5a705e;  // @569_5a6980
  FL[2] = (ecx & ecx);  // @570_5a6980
  if (FL[2] == 0) goto L5a7058;  // @571_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @572_5a6980
  L5a7058:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @574_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @575_5a6980
  goto L5a706d;  // @576_5a6980
  L5a705e:;
  eax = (u32)(EBP - 136);  // @578_5a6980
  PV[26] = (u32)(eax);  // @579_5a6980
  PV[27] = (u32)(ecx);  // @580_5a6980
  ecx = esi;  // @581_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[27], PV[26]);  // @582_5a6980
  ecx = edx = 0;  // @583_5a6980
  L5a706d:;
  eax = ext_41e290_cdecl1((u32)(33));  // @585_5a6980
  ecx = edx = 0;  // @586_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @587_5a6980
  reg.state = (s32)((u32)(14));  // @588_5a6980
  FL[2] = (eax & eax);  // @589_5a6980
  if (FL[2] == 0) goto L5a7091;  // @590_5a6980
  ecx = eax;  // @591_5a6980
  eax = ext_5eec40_thiscall1(ecx);  // @592_5a6980
  ecx = edx = 0;  // @593_5a6980
  goto L5a7093;  // @594_5a6980
  L5a7091:;
  eax = 0;  // @596_5a6980
  FL[3] = eax;  // @597_5a6980
  L5a7093:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1580), &v, sizeof v); }  // @599_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @600_5a6980
  reg.state = (s32)((u32)(4294967295));  // @601_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @602_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @603_5a6980
  if (FL[0] == FL[1]) goto L5a70ba;  // @604_5a6980
  FL[2] = (ecx & ecx);  // @605_5a6980
  if (FL[2] == 0) goto L5a70b4;  // @606_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @607_5a6980
  L5a70b4:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @609_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @610_5a6980
  goto L5a70c9;  // @611_5a6980
  L5a70ba:;
  eax = (u32)(EBP - 136);  // @613_5a6980
  PV[28] = (u32)(eax);  // @614_5a6980
  PV[29] = (u32)(ecx);  // @615_5a6980
  ecx = esi;  // @616_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[29], PV[28]);  // @617_5a6980
  ecx = edx = 0;  // @618_5a6980
  L5a70c9:;
  eax = ext_41e290_cdecl1((u32)(247));  // @620_5a6980
  ecx = edx = 0;  // @621_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @622_5a6980
  reg.state = (s32)((u32)(15));  // @623_5a6980
  FL[2] = (eax & eax);  // @624_5a6980
  if (FL[2] == 0) goto L5a70f0;  // @625_5a6980
  ecx = eax;  // @626_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @627_5a6980
  ecx = edx = 0;  // @628_5a6980
  goto L5a70f2;  // @629_5a6980
  L5a70f0:;
  eax = 0;  // @631_5a6980
  FL[3] = eax;  // @632_5a6980
  L5a70f2:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1576), &v, sizeof v); }  // @634_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @635_5a6980
  reg.state = (s32)((u32)(4294967295));  // @636_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @637_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @638_5a6980
  if (FL[0] == FL[1]) goto L5a7119;  // @639_5a6980
  FL[2] = (ecx & ecx);  // @640_5a6980
  if (FL[2] == 0) goto L5a7113;  // @641_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @642_5a6980
  L5a7113:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @644_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @645_5a6980
  goto L5a7128;  // @646_5a6980
  L5a7119:;
  eax = (u32)(EBP - 136);  // @648_5a6980
  PV[30] = (u32)(eax);  // @649_5a6980
  PV[31] = (u32)(ecx);  // @650_5a6980
  ecx = esi;  // @651_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[31], PV[30]);  // @652_5a6980
  ecx = edx = 0;  // @653_5a6980
  L5a7128:;
  eax = ext_41e290_cdecl1((u32)(247));  // @655_5a6980
  ecx = edx = 0;  // @656_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @657_5a6980
  reg.state = (s32)((u32)(16));  // @658_5a6980
  FL[2] = (eax & eax);  // @659_5a6980
  if (FL[2] == 0) goto L5a714f;  // @660_5a6980
  ecx = eax;  // @661_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @662_5a6980
  ecx = edx = 0;  // @663_5a6980
  goto L5a7151;  // @664_5a6980
  L5a714f:;
  eax = 0;  // @666_5a6980
  FL[3] = eax;  // @667_5a6980
  L5a7151:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1140), &v, sizeof v); }  // @669_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @670_5a6980
  reg.state = (s32)((u32)(4294967295));  // @671_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @672_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @673_5a6980
  if (FL[0] == FL[1]) goto L5a7178;  // @674_5a6980
  FL[2] = (ecx & ecx);  // @675_5a6980
  if (FL[2] == 0) goto L5a7172;  // @676_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @677_5a6980
  L5a7172:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @679_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @680_5a6980
  goto L5a7187;  // @681_5a6980
  L5a7178:;
  eax = (u32)(EBP - 136);  // @683_5a6980
  PV[32] = (u32)(eax);  // @684_5a6980
  PV[33] = (u32)(ecx);  // @685_5a6980
  ecx = esi;  // @686_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[33], PV[32]);  // @687_5a6980
  ecx = edx = 0;  // @688_5a6980
  L5a7187:;
  eax = ext_41e290_cdecl1((u32)(153));  // @690_5a6980
  ecx = edx = 0;  // @691_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @692_5a6980
  reg.state = (s32)((u32)(17));  // @693_5a6980
  FL[2] = (eax & eax);  // @694_5a6980
  if (FL[2] == 0) goto L5a71ae;  // @695_5a6980
  ecx = eax;  // @696_5a6980
  eax = ext_5efd10_thiscall1(ecx);  // @697_5a6980
  ecx = edx = 0;  // @698_5a6980
  goto L5a71b0;  // @699_5a6980
  L5a71ae:;
  eax = 0;  // @701_5a6980
  FL[3] = eax;  // @702_5a6980
  L5a71b0:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1588), &v, sizeof v); }  // @704_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @705_5a6980
  reg.state = (s32)((u32)(4294967295));  // @706_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @707_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @708_5a6980
  if (FL[0] == FL[1]) goto L5a71d7;  // @709_5a6980
  FL[2] = (ecx & ecx);  // @710_5a6980
  if (FL[2] == 0) goto L5a71d1;  // @711_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @712_5a6980
  L5a71d1:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @714_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @715_5a6980
  goto L5a71e6;  // @716_5a6980
  L5a71d7:;
  eax = (u32)(EBP - 136);  // @718_5a6980
  PV[34] = (u32)(eax);  // @719_5a6980
  PV[35] = (u32)(ecx);  // @720_5a6980
  ecx = esi;  // @721_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[35], PV[34]);  // @722_5a6980
  ecx = edx = 0;  // @723_5a6980
  L5a71e6:;
  eax = ext_41e290_cdecl1((u32)(168));  // @725_5a6980
  ecx = edx = 0;  // @726_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @727_5a6980
  reg.state = (s32)((u32)(18));  // @728_5a6980
  FL[2] = (eax & eax);  // @729_5a6980
  if (FL[2] == 0) goto L5a720f;  // @730_5a6980
  ecx = eax;  // @731_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(3));  // @732_5a6980
  ecx = edx = 0;  // @733_5a6980
  goto L5a7211;  // @734_5a6980
  L5a720f:;
  eax = 0;  // @736_5a6980
  FL[3] = eax;  // @737_5a6980
  L5a7211:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1584), &v, sizeof v); }  // @739_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @740_5a6980
  reg.state = (s32)((u32)(4294967295));  // @741_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @742_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @743_5a6980
  if (FL[0] == FL[1]) goto L5a7238;  // @744_5a6980
  FL[2] = (ecx & ecx);  // @745_5a6980
  if (FL[2] == 0) goto L5a7232;  // @746_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @747_5a6980
  L5a7232:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @749_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @750_5a6980
  goto L5a7247;  // @751_5a6980
  L5a7238:;
  eax = (u32)(EBP - 136);  // @753_5a6980
  PV[36] = (u32)(eax);  // @754_5a6980
  PV[37] = (u32)(ecx);  // @755_5a6980
  ecx = esi;  // @756_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[37], PV[36]);  // @757_5a6980
  ecx = edx = 0;  // @758_5a6980
  L5a7247:;
  eax = ext_41e290_cdecl1((u32)(199));  // @760_5a6980
  ecx = edx = 0;  // @761_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @762_5a6980
  reg.state = (s32)((u32)(19));  // @763_5a6980
  FL[2] = (eax & eax);  // @764_5a6980
  if (FL[2] == 0) goto L5a726e;  // @765_5a6980
  ecx = eax;  // @766_5a6980
  eax = ext_5ef080_thiscall1(ecx);  // @767_5a6980
  ecx = edx = 0;  // @768_5a6980
  goto L5a7270;  // @769_5a6980
  L5a726e:;
  eax = 0;  // @771_5a6980
  FL[3] = eax;  // @772_5a6980
  L5a7270:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @774_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @775_5a6980
  reg.state = (s32)((u32)(4294967295));  // @776_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @777_5a6980
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @778_5a6980
  if (FL[0] == FL[1]) goto L5a7297;  // @779_5a6980
  FL[2] = (ecx & ecx);  // @780_5a6980
  if (FL[2] == 0) goto L5a7291;  // @781_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @782_5a6980
  L5a7291:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @784_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @785_5a6980
  goto L5a72a6;  // @786_5a6980
  L5a7297:;
  eax = (u32)(EBP - 136);  // @788_5a6980
  PV[38] = (u32)(eax);  // @789_5a6980
  PV[39] = (u32)(ecx);  // @790_5a6980
  ecx = esi;  // @791_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[39], PV[38]);  // @792_5a6980
  ecx = edx = 0;  // @793_5a6980
  L5a72a6:;
  ebx = (u32)(edi + 1228);  // @795_5a6980
  edi = (u32)(24);  // @796_5a6980
  L5a72b1:;
  eax = ext_41e290_cdecl1((u32)(215));  // @798_5a6980
  ecx = edx = 0;  // @799_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @800_5a6980
  reg.state = (s32)((u32)(20));  // @801_5a6980
  FL[2] = (eax & eax);  // @802_5a6980
  if (FL[2] == 0) goto L5a72dc;  // @803_5a6980
  ecx = eax;  // @804_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @805_5a6980
  ecx = edx = 0;  // @806_5a6980
  ecx = eax;  // @807_5a6980
  goto L5a72de;  // @808_5a6980
  L5a72dc:;
  ecx = 0;  // @810_5a6980
  FL[3] = ecx;  // @811_5a6980
  L5a72de:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @813_5a6980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @814_5a6980
  reg.state = (s32)((u32)(4294967295));  // @815_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @816_5a6980
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @817_5a6980
  if (FL[0] == FL[1]) goto L5a7301;  // @818_5a6980
  FL[2] = (eax & eax);  // @819_5a6980
  if (FL[2] == 0) goto L5a72fb;  // @820_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @821_5a6980
  L5a72fb:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @823_5a6980
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @824_5a6980
  goto L5a7310;  // @825_5a6980
  L5a7301:;
  ecx = (u32)(EBP - 136);  // @827_5a6980
  PV[40] = (u32)(ecx);  // @828_5a6980
  PV[41] = (u32)(eax);  // @829_5a6980
  ecx = esi;  // @830_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, PV[41], PV[40]);  // @831_5a6980
  ecx = edx = 0;  // @832_5a6980
  L5a7310:;
  ebx = (ebx + (u32)(4));  // @834_5a6980
  FL[3] = ebx;  // @835_5a6980
  edi = (edi - (u32)(1));  // @836_5a6980
  FL[3] = edi;  // @837_5a6980
  if (FL[3] != 0) goto L5a72b1;  // @838_5a6980
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @839_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))(PV[42], (u32)(7012036));  // @840_5a6980
  ecx = edx = 0;  // @841_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @842_5a6980
  ebx = eax;  // @843_5a6980
  ebx = (ebx - ecx);  // @844_5a6980
  FL[3] = ebx;  // @845_5a6980
  esi = 0;  // @846_5a6980
  FL[3] = esi;  // @847_5a6980
  edx = 0;  // @848_5a6980
  FL[3] = edx;  // @849_5a6980
  FL[0] = ecx; FL[1] = eax;  // @850_5a6980
  if (FL[0] > FL[1]) ebx = edi;  // @851_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @852_5a6980
  FL[2] = (ebx & ebx);  // @853_5a6980
  if (FL[2] == 0) goto L5a736e;  // @854_5a6980
  edi = ecx;  // @855_5a6980
  L5a7350:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @857_5a6980
  ecx = (u32)(esi + 1);  // @858_5a6980
  edx = (edx + 1);  // @859_5a6980
  FL[3] = edx;  // @860_5a6980
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @861_5a6980
  if (FL[0] != FL[1]) ecx = esi;  // @862_5a6980
  esi = ecx;  // @863_5a6980
  FL[0] = edx; FL[1] = ebx;  // @864_5a6980
  if (FL[0] < FL[1]) goto L5a7350;  // @865_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @866_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @867_5a6980
  L5a736e:;
  esi = (u32)(esi + 2);  // @869_5a6980
  eax = (u32)(esi + esi*2);  // @870_5a6980
  eax = (u32)(edi + eax*4);  // @871_5a6980
  PV[43] = (u32)(ecx);  // @872_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1208), &v, sizeof v); }  // @873_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))(PV[43], (u32)(7012048));  // @874_5a6980
  ecx = edx = 0;  // @875_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @876_5a6980
  edx = 0;  // @877_5a6980
  FL[3] = edx;  // @878_5a6980
  ebx = eax;  // @879_5a6980
  ebx = (ebx - ecx);  // @880_5a6980
  FL[3] = ebx;  // @881_5a6980
  esi = 0;  // @882_5a6980
  FL[3] = esi;  // @883_5a6980
  FL[0] = ecx; FL[1] = eax;  // @884_5a6980
  if (FL[0] > FL[1]) ebx = edx;  // @885_5a6980
  FL[2] = (ebx & ebx);  // @886_5a6980
  if (FL[2] == 0) goto L5a73c3;  // @887_5a6980
  edi = ecx;  // @888_5a6980
  L5a73a5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @890_5a6980
  ecx = (u32)(esi + 1);  // @891_5a6980
  edx = (edx + 1);  // @892_5a6980
  FL[3] = edx;  // @893_5a6980
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @894_5a6980
  if (FL[0] != FL[1]) ecx = esi;  // @895_5a6980
  esi = ecx;  // @896_5a6980
  FL[0] = edx; FL[1] = ebx;  // @897_5a6980
  if (FL[0] < FL[1]) goto L5a73a5;  // @898_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @899_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @900_5a6980
  L5a73c3:;
  esi = (u32)(esi + 2);  // @902_5a6980
  eax = (u32)(esi + esi*2);  // @903_5a6980
  eax = (u32)(edi + eax*4);  // @904_5a6980
  PV[44] = (u32)(ecx);  // @905_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1212), &v, sizeof v); }  // @906_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))(PV[44], (u32)(7012056));  // @907_5a6980
  ecx = edx = 0;  // @908_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @909_5a6980
  edx = 0;  // @910_5a6980
  FL[3] = edx;  // @911_5a6980
  ebx = eax;  // @912_5a6980
  ebx = (ebx - ecx);  // @913_5a6980
  FL[3] = ebx;  // @914_5a6980
  esi = 0;  // @915_5a6980
  FL[3] = esi;  // @916_5a6980
  FL[0] = ecx; FL[1] = eax;  // @917_5a6980
  if (FL[0] > FL[1]) ebx = edx;  // @918_5a6980
  FL[2] = (ebx & ebx);  // @919_5a6980
  if (FL[2] == 0) goto L5a741e;  // @920_5a6980
  edi = ecx;  // @921_5a6980
  L5a7400:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @923_5a6980
  ecx = (u32)(esi + 1);  // @924_5a6980
  edx = (edx + 1);  // @925_5a6980
  FL[3] = edx;  // @926_5a6980
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @927_5a6980
  if (FL[0] != FL[1]) ecx = esi;  // @928_5a6980
  esi = ecx;  // @929_5a6980
  FL[0] = edx; FL[1] = ebx;  // @930_5a6980
  if (FL[0] < FL[1]) goto L5a7400;  // @931_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @932_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @933_5a6980
  L5a741e:;
  esi = (u32)(esi + 2);  // @935_5a6980
  eax = (u32)(esi + esi*2);  // @936_5a6980
  eax = (u32)(edi + eax*4);  // @937_5a6980
  PV[45] = (u32)(ecx);  // @938_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1216), &v, sizeof v); }  // @939_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))(PV[45], (u32)(7012068));  // @940_5a6980
  ecx = edx = 0;  // @941_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @942_5a6980
  edx = 0;  // @943_5a6980
  FL[3] = edx;  // @944_5a6980
  ebx = eax;  // @945_5a6980
  ebx = (ebx - ecx);  // @946_5a6980
  FL[3] = ebx;  // @947_5a6980
  esi = 0;  // @948_5a6980
  FL[3] = esi;  // @949_5a6980
  FL[0] = ecx; FL[1] = eax;  // @950_5a6980
  if (FL[0] > FL[1]) ebx = edx;  // @951_5a6980
  FL[2] = (ebx & ebx);  // @952_5a6980
  if (FL[2] == 0) goto L5a7473;  // @953_5a6980
  edi = ecx;  // @954_5a6980
  L5a7455:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @956_5a6980
  ecx = (u32)(esi + 1);  // @957_5a6980
  edx = (edx + 1);  // @958_5a6980
  FL[3] = edx;  // @959_5a6980
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @960_5a6980
  if (FL[0] != FL[1]) ecx = esi;  // @961_5a6980
  esi = ecx;  // @962_5a6980
  FL[0] = edx; FL[1] = ebx;  // @963_5a6980
  if (FL[0] < FL[1]) goto L5a7455;  // @964_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @965_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @966_5a6980
  L5a7473:;
  esi = (u32)(esi + 2);  // @968_5a6980
  eax = (u32)(esi + esi*2);  // @969_5a6980
  eax = (u32)(edi + eax*4);  // @970_5a6980
  PV[46] = (u32)(ecx);  // @971_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1220), &v, sizeof v); }  // @972_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))(PV[46], (u32)(7012076));  // @973_5a6980
  ecx = edx = 0;  // @974_5a6980
  edx = 0;  // @975_5a6980
  FL[3] = edx;  // @976_5a6980
  ebx = eax;  // @977_5a6980
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @978_5a6980
  FL[3] = ebx;  // @979_5a6980
  esi = 0;  // @980_5a6980
  FL[3] = esi;  // @981_5a6980
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @982_5a6980
  if (FL[0] > FL[1]) ebx = edx;  // @983_5a6980
  FL[2] = (ebx & ebx);  // @984_5a6980
  if (FL[2] == 0) goto L5a74c8;  // @985_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @986_5a6980
  L5a74b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @988_5a6980
  ecx = (u32)(esi + 1);  // @989_5a6980
  edx = (edx + 1);  // @990_5a6980
  FL[3] = edx;  // @991_5a6980
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @992_5a6980
  if (FL[0] != FL[1]) ecx = esi;  // @993_5a6980
  esi = ecx;  // @994_5a6980
  FL[0] = edx; FL[1] = ebx;  // @995_5a6980
  if (FL[0] < FL[1]) goto L5a74b0;  // @996_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @997_5a6980
  L5a74c8:;
  esi = (u32)(esi + 2);  // @999_5a6980
  eax = (u32)(esi + esi*2);  // @1000_5a6980
  eax = (u32)(edi + eax*4);  // @1001_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1224), &v, sizeof v); }  // @1002_5a6980
  SEH_LEAVE();  // @1003_5a6980
  ext_633654(G(u32, 0x6f5630));  // @1004_5a6980
  return eax;  // @1005_5a6980
}
PCREG(5a6980, lifted_5a6980);

