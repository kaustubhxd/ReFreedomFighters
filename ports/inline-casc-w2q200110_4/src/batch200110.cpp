// batch200110.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc6e0_fastcall2(u32, u32) __asm__("ext_4cc6e0");
extern "C" u32 FASTCALL ext_4cd9b0_fastcall4(u32, u32, u32, u32) __asm__("ext_4cd9b0");
extern "C" u32 STDCALL ext_492200_stdcall1(u32) __asm__("ext_492200");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_4d8db0_stdcall2(u32, u32) __asm__("ext_4d8db0");
extern "C" u32 STDCALL ext_4d8ef0_stdcall3(u32, u32, u32) __asm__("ext_4d8ef0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 STDCALL ext_63418c_stdcall4(u32, u32, u32, u32) __asm__("ext_63418c");
extern "C" u32 THISCALL ext_41cfd0_thiscall1(u32) __asm__("ext_41cfd0");
extern "C" u32 THISCALL ext_423ff0_thiscall2(u32, u32) __asm__("ext_423ff0");
extern "C" u32 THISCALL ext_42be20_thiscall2(u32, u32) __asm__("ext_42be20");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_432be0_thiscall1(u32) __asm__("ext_432be0");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_437670_thiscall2(u32, u32) __asm__("ext_437670");
extern "C" u32 THISCALL ext_4376c0_thiscall2(u32, u32) __asm__("ext_4376c0");
extern "C" u32 THISCALL ext_4388a0_thiscall1(u32) __asm__("ext_4388a0");
extern "C" u32 THISCALL ext_438910_thiscall1(u32) __asm__("ext_438910");
extern "C" u32 THISCALL ext_43a900_thiscall1(u32) __asm__("ext_43a900");
extern "C" u32 THISCALL ext_43de40_thiscall4(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_440e10_thiscall2(u32, u32) __asm__("ext_440e10");
extern "C" u32 THISCALL ext_441c00_thiscall1(u32) __asm__("ext_441c00");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_444530_thiscall1(u32) __asm__("ext_444530");
extern "C" u32 THISCALL ext_456ab0_thiscall1(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_45c3e0_thiscall1(u32) __asm__("ext_45c3e0");
extern "C" u32 THISCALL ext_45f420_thiscall1(u32) __asm__("ext_45f420");
extern "C" u32 THISCALL ext_460f90_thiscall1(u32) __asm__("ext_460f90");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_46a4f0_thiscall1(u32) __asm__("ext_46a4f0");
extern "C" u32 THISCALL ext_471f60_thiscall1(u32) __asm__("ext_471f60");
extern "C" u32 THISCALL ext_48cf50_thiscall1(u32) __asm__("ext_48cf50");
extern "C" u32 THISCALL ext_492880_thiscall2(u32, u32) __asm__("ext_492880");
extern "C" u32 THISCALL ext_493820_thiscall4(u32, u32, u32, u32) __asm__("ext_493820");
extern "C" u32 THISCALL ext_496a40_thiscall1(u32) __asm__("ext_496a40");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_4c4740_thiscall4(u32, u32, u32, u32) __asm__("ext_4c4740");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cc690_thiscall1(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccee0_thiscall1(u32) __asm__("ext_4ccee0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4cd160_thiscall1(u32) __asm__("ext_4cd160");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4cd950_thiscall2(u32, u32) __asm__("ext_4cd950");
extern "C" u32 THISCALL ext_4cdcc0_thiscall1(u32) __asm__("ext_4cdcc0");
extern "C" u32 THISCALL ext_4cf850_thiscall1(u32) __asm__("ext_4cf850");
extern "C" u32 THISCALL ext_4d1390_thiscall3(u32, u32, u32) __asm__("ext_4d1390");
extern "C" u32 THISCALL ext_4d2030_thiscall2(u32, u32) __asm__("ext_4d2030");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4d5440_thiscall1(u32) __asm__("ext_4d5440");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4d9230_thiscall2(u32, u32) __asm__("ext_4d9230");
extern "C" u32 THISCALL ext_4d93e0_thiscall1(u32) __asm__("ext_4d93e0");
extern "C" u32 THISCALL ext_4d9430_thiscall1(u32) __asm__("ext_4d9430");
extern "C" u32 THISCALL ext_4d9ce0_thiscall1(u32) __asm__("ext_4d9ce0");
extern "C" u32 THISCALL ext_4da720_thiscall2(u32, u32) __asm__("ext_4da720");
extern "C" u32 THISCALL ext_4db7e0_thiscall1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_4dbb00_thiscall2(u32, u32) __asm__("ext_4dbb00");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e3180_thiscall1(u32) __asm__("ext_4e3180");
extern "C" u32 THISCALL ext_4e3f00_thiscall1(u32) __asm__("ext_4e3f00");
extern "C" u32 THISCALL ext_4e49d0_thiscall2(u32, u32) __asm__("ext_4e49d0");
extern "C" u32 THISCALL ext_4e5000_thiscall1(u32) __asm__("ext_4e5000");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_4e6780_thiscall2(u32, u32) __asm__("ext_4e6780");
extern "C" u32 THISCALL ext_4e7160_thiscall1(u32) __asm__("ext_4e7160");
extern "C" u32 THISCALL ext_4e8450_thiscall2(u32, u32) __asm__("ext_4e8450");
extern "C" u32 THISCALL ext_4ee210_thiscall4(u32, u32, u32, u32) __asm__("ext_4ee210");
extern "C" u32 THISCALL ext_4ef660_thiscall2(u32, u32) __asm__("ext_4ef660");
extern "C" u32 THISCALL ext_4f2be0_thiscall1(u32) __asm__("ext_4f2be0");
extern "C" u32 THISCALL ext_4f9c90_thiscall2(u32, u32) __asm__("ext_4f9c90");
extern "C" u32 THISCALL ext_4ff7b0_thiscall1(u32) __asm__("ext_4ff7b0");
extern "C" u32 THISCALL ext_4ff920_thiscall1(u32) __asm__("ext_4ff920");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_500150_thiscall1(u32) __asm__("ext_500150");
extern "C" u32 THISCALL ext_500190_thiscall2(u32, u32) __asm__("ext_500190");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_500990_thiscall2(u32, u32) __asm__("ext_500990");
extern "C" u32 THISCALL ext_505d50_thiscall1(u32) __asm__("ext_505d50");
extern "C" u32 THISCALL ext_534190_thiscall1(u32) __asm__("ext_534190");
extern "C" u32 THISCALL ext_53a810_thiscall1(u32) __asm__("ext_53a810");
extern "C" u32 THISCALL ext_540ed0_thiscall1(u32) __asm__("ext_540ed0");
extern "C" u32 THISCALL ext_545ee0_thiscall2(u32, u32) __asm__("ext_545ee0");
extern "C" u32 THISCALL ext_54cb50_thiscall1(u32) __asm__("ext_54cb50");
extern "C" u32 THISCALL ext_54e100_thiscall1(u32) __asm__("ext_54e100");
extern "C" u32 THISCALL ext_576a30_thiscall2(u32, u32) __asm__("ext_576a30");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5ab9d0_thiscall1(u32) __asm__("ext_5ab9d0");
extern "C" u32 THISCALL ext_5ac5d0_thiscall2(u32, u32) __asm__("ext_5ac5d0");
extern "C" u32 THISCALL ext_5aca30_thiscall3(u32, u32, u32) __asm__("ext_5aca30");
extern "C" u32 THISCALL ext_5b5420_thiscall1(u32) __asm__("ext_5b5420");
extern "C" u32 THISCALL ext_5eaab0_thiscall3(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL ext_5ee110_thiscall4(u32, u32, u32, u32) __asm__("ext_5ee110");
extern "C" u32 THISCALL ext_5ee920_thiscall1(u32) __asm__("ext_5ee920");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f12d0_thiscall1(u32) __asm__("ext_5f12d0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f37f0_thiscall3(u32, u32, u32) __asm__("ext_5f37f0");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_5f5490_thiscall3(u32, u32, u32) __asm__("ext_5f5490");
extern "C" u32 THISCALL ext_5f55e0_thiscall1(u32) __asm__("ext_5f55e0");
extern "C" u32 THISCALL ext_5fad90_thiscall1(u32) __asm__("ext_5fad90");
extern "C" u32 THISCALL ext_5fae50_thiscall1(u32) __asm__("ext_5fae50");
extern "C" u32 THISCALL ext_5fb370_thiscall2(u32, u32) __asm__("ext_5fb370");
extern "C" u32 THISCALL ext_5fd7c0_thiscall2(u32, u32) __asm__("ext_5fd7c0");
extern "C" u32 THISCALL ext_5fdb70_thiscall1(u32) __asm__("ext_5fdb70");
extern "C" u32 THISCALL ext_5fef70_thiscall2(u32, u32) __asm__("ext_5fef70");
extern "C" u32 THISCALL ext_600260_thiscall3(u32, u32, u32) __asm__("ext_600260");
extern "C" u32 THISCALL ext_601380_thiscall1(u32) __asm__("ext_601380");
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_602260_thiscall2(u32, u32) __asm__("ext_602260");
extern "C" u32 THISCALL ext_603110_thiscall1(u32) __asm__("ext_603110");
extern "C" u32 THISCALL ext_6031e0_thiscall2(u32, u32) __asm__("ext_6031e0");
extern "C" u32 THISCALL ext_6033c0_thiscall2(u32, u32) __asm__("ext_6033c0");
extern "C" u32 THISCALL ext_603430_thiscall3(u32, u32, u32) __asm__("ext_603430");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_603850_thiscall1(u32) __asm__("ext_603850");
extern "C" u32 THISCALL ext_604650_thiscall1(u32) __asm__("ext_604650");
extern "C" u32 THISCALL ext_606ee0_thiscall4(u32, u32, u32, u32) __asm__("ext_606ee0");
extern "C" u32 THISCALL ext_6071c0_thiscall1(u32) __asm__("ext_6071c0");
extern "C" u32 THISCALL ext_607f60_thiscall4(u32, u32, u32, u32) __asm__("ext_607f60");
extern "C" u32 THISCALL ext_608e80_thiscall1(u32) __asm__("ext_608e80");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 THISCALL ext_636020_thiscall9(u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_636020");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_639d00_thiscall2(u32, u32) __asm__("ext_639d00");
extern "C" u32 THISCALL ext_63cc50_thiscall3(u32, u32, u32) __asm__("ext_63cc50");
extern "C" u32 THISCALL ext_63ead0_thiscall2(u32, u32) __asm__("ext_63ead0");
extern "C" u32 THISCALL ext_648280_thiscall1(u32) __asm__("ext_648280");
extern "C" u32 THISCALL ext_64b070_thiscall1(u32) __asm__("ext_64b070");
extern "C" u32 THISCALL ext_64c7e0_thiscall2(u32, u32) __asm__("ext_64c7e0");
extern "C" u32 THISCALL ext_64d5f0_thiscall2(u32, u32) __asm__("ext_64d5f0");
extern "C" u32 THISCALL ext_6500b0_thiscall1(u32) __asm__("ext_6500b0");
extern "C" u32 THISCALL ext_651180_thiscall1(u32) __asm__("ext_651180");
extern "C" u32 THISCALL ext_651880_thiscall1(u32) __asm__("ext_651880");
extern "C" u32 THISCALL ext_659220_thiscall3(u32, u32, u32) __asm__("ext_659220");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 THISCALL ext_65e130_thiscall1(u32) __asm__("ext_65e130");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" u32 ext_42abee_cdecl3(...) __asm__("ext_42abee");
extern "C" u32 ext_42ac56_cdecl3(...) __asm__("ext_42ac56");
extern "C" u32 ext_436ec0_cdecl1(...) __asm__("ext_436ec0");
extern "C" u32 ext_438a60_cdecl1(...) __asm__("ext_438a60");
extern "C" u32 ext_44a1f0_cdecl0(void) __asm__("ext_44a1f0");
extern "C" u32 ext_45c510_cdecl1(...) __asm__("ext_45c510");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl4(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4d9590_cdecl1(...) __asm__("ext_4d9590");
extern "C" u32 ext_632360_cdecl10(...) __asm__("ext_632360");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_632940(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  __builtin_memcpy(F + 0x300 + 40, &a8, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 40), sizeof v); (u32)v; });  // @0_632940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @2_632940
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(288), (u32)(4));  // @3_632940
  ecx = edx = 0;  // @4_632940
  ebx = eax;  // @5_632940
  if ((ebx & ebx) != 0) goto L632971;  // @6_632940
  eax = (u32)(ebx - 4);  // @7_632940
  return eax;  // @8_632940
  L632971:;
  p0_ = ebx;  // @10_632940
  eax = (u32)(EBP - 4);  // @11_632940
  p1_ = eax;  // @12_632940
  eax = ext_632360_cdecl10(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(257), (u32)(7082712), (u32)(7082840), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @13_632940
  ecx = edx = 0;  // @14_632940
  edi = eax;  // @15_632940
  if ((edi & edi) != 0) goto L632a35;  // @16_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @17_632940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == edi) goto L632a48;  // @18_632940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @19_632940
  eax = (u32)(EBP - 4);  // @20_632940
  p2_ = ebx;  // @21_632940
  p3_ = eax;  // @22_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @23_632940
  eax = (u32)(ecx + eax*4);  // @24_632940
  p4_ = edi;  // @25_632940
  p5_ = eax;  // @26_632940
  eax = ext_632360_cdecl10((u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p4_), (u32)(7082968), (u32)(7083088), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; }), (u32)(p3_), (u32)(p2_));  // @27_632940
  ecx = edx = 0;  // @28_632940
  edi = eax;  // @29_632940
  if ((edi & edi) != 0) goto L632a0b;  // @30_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @31_632940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != edi) goto L6329f6;  // @32_632940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) > (u32)(257)) goto L632a2c;  // @33_632940
  L6329f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @35_632940
  p6_ = ebx;  // @36_632940
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(p6_));  // @37_632940
  ecx = edx = 0;  // @38_632940
  eax = 0;  // @39_632940
  return eax;  // @40_632940
  L632a0b:;
  if (edi != (u32)(-3)) goto L632a19;  // @42_632940
  { u32 v = (u32)((u32)(7083352)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @43_632940
  goto L632a54;  // @44_632940
  L632a19:;
  if (edi != (u32)(-5)) goto L632a27;  // @46_632940
  { u32 v = (u32)((u32)(7083384)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @47_632940
  goto L632a4f;  // @48_632940
  L632a27:;
  if (edi == (u32)(-4)) goto L632a54;  // @50_632940
  L632a2c:;
  { u32 v = (u32)((u32)(7083412)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @52_632940
  goto L632a4f;  // @53_632940
  L632a35:;
  if (edi != (u32)(-3)) goto L632a43;  // @55_632940
  { u32 v = (u32)((u32)(7083284)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @56_632940
  goto L632a54;  // @57_632940
  L632a43:;
  if (edi == (u32)(-4)) goto L632a54;  // @59_632940
  L632a48:;
  { u32 v = (u32)((u32)(7083320)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @61_632940
  L632a4f:;
  edi = (u32)(4294967293);  // @63_632940
  L632a54:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @65_632940
  p7_ = ebx;  // @66_632940
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(p7_));  // @67_632940
  ecx = edx = 0;  // @68_632940
  eax = edi;  // @69_632940
  return eax;  // @70_632940
}
PCREG(632940, lifted_632940);

extern "C" u32 THISCALL lifted_5b3c30(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @0_5b3c30
  esi = ecx;  // @1_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11285), sizeof v); (u32)v; });  // @2_5b3c30
  if ((eax & eax) == 0) goto L5b3c7f;  // @3_5b3c30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4156), sizeof v); (u32)v; }) == (u32)(0)) goto L5b3c7f;  // @4_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @6_5b3c30
  if ((ecx & ecx) == 0) goto L5b3c6f;  // @7_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7268848), (u32)(6932112), (u32)(0));  // @9_5b3c30
  ecx = edx = 0;  // @10_5b3c30
  L5b3c6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_5b3c30
  ecx = esi;  // @13_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @14_5b3c30
  ecx = edx = 0;  // @15_5b3c30
  return eax;  // @16_5b3c30
  L5b3c7f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @18_5b3c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 95), &v, sizeof v); }  // @19_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5b3c30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @23_5b3c30
  ecx = edx = 0;  // @24_5b3c30
  ecx = (u32)(EBP - 1);  // @25_5b3c30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @26_5b3c30
  p0_ = ecx;  // @27_5b3c30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_5b3c30
  ecx = eax;  // @29_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6859220), (u32)(p0_));  // @30_5b3c30
  ecx = edx = 0;  // @31_5b3c30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) == (u32)(0)) goto L5b3d80;  // @32_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @33_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1668), sizeof v); (u32)v; });  // @34_5b3c30
  eax = (eax - (u32)(2));  // @35_5b3c30
  if (eax == 0) goto L5b3d54;  // @36_5b3c30
  eax = (eax - (u32)(1));  // @37_5b3c30
  if (eax == 0) goto L5b3d28;  // @38_5b3c30
  eax = (eax - (u32)(1));  // @39_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @41_5b3c30
  if (eax == 0) goto L5b3d04;  // @42_5b3c30
  if ((ecx & ecx) == 0) goto L5b3cfa;  // @43_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7268852), (u32)(7020584), (u32)(0));  // @45_5b3c30
  ecx = edx = 0;  // @46_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_5b3c30
  L5b3cfa:;
  goto L5b3daa;  // @49_5b3c30
  L5b3d04:;
  if ((ecx & ecx) == 0) goto L5b3d1e;  // @51_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7268864), (u32)(7020572), (u32)(0), (u32)(7020584));  // @53_5b3c30
  ecx = edx = 0;  // @54_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_5b3c30
  L5b3d1e:;
  goto L5b3daa;  // @57_5b3c30
  L5b3d28:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @60_5b3c30
  if ((ecx & ecx) == 0) goto L5b3d4d;  // @61_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7268860), (u32)(7020560), (u32)(0), (u32)(7020572));  // @63_5b3c30
  ecx = edx = 0;  // @64_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_5b3c30
  L5b3d4d:;
  goto L5b3daa;  // @67_5b3c30
  L5b3d54:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @70_5b3c30
  if ((ecx & ecx) == 0) goto L5b3d79;  // @71_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7268856), (u32)(7020548), (u32)(0), (u32)(7020560));  // @73_5b3c30
  ecx = edx = 0;  // @74_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_5b3c30
  L5b3d79:;
  goto L5b3daa;  // @77_5b3c30
  L5b3d80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @80_5b3c30
  if ((ecx & ecx) == 0) goto L5b3da5;  // @81_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7268848), (u32)(6932112), (u32)(0), (u32)(7020548));  // @83_5b3c30
  ecx = edx = 0;  // @84_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_5b3c30
  L5b3da5:;
  L5b3daa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @88_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_5b3c30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6932112));  // @90_5b3c30
  ecx = edx = 0;  // @91_5b3c30
  ecx = esi;  // @92_5b3c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 87), &v, sizeof v); }  // @93_5b3c30
  eax = ext_5b5420_thiscall1(ecx);  // @94_5b3c30
  ecx = edx = 0;  // @95_5b3c30
  return eax;  // @96_5b3c30
}
PCREG(5b3c30, lifted_5b3c30);

extern "C" u32 THISCALL lifted_576330(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_576330
  edi = ecx;  // @1_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_576330
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_576330
  ecx = edx = 0;  // @5_576330
  ecx = (u32)(EBP - 4);  // @6_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @7_576330
  p0_ = ecx;  // @8_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_576330
  ecx = eax;  // @10_576330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6983656), (u32)(p0_));  // @11_576330
  ecx = edx = 0;  // @12_576330
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @13_576330
  ecx = (u32)(6975068);  // @14_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @15_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 533), &v, sizeof v); }  // @16_576330
  esi = (u32)(ebx + 72);  // @17_576330
  eax = esi;  // @18_576330
  L576380:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @20_576330
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L5763a0;  // @21_576330
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L57639c;  // @22_576330
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @23_576330
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L5763a0;  // @24_576330
  eax = (eax + (u32)(2));  // @25_576330
  ecx = (ecx + (u32)(2));  // @26_576330
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L576380;  // @27_576330
  L57639c:;
  eax = 0;  // @29_576330
  goto L5763a5;  // @30_576330
  L5763a0:;
  eax = 0;  // @32_576330
  eax = (eax | (u32)(1));  // @33_576330
  L5763a5:;
  if ((eax & eax) != 0) goto L5763bd;  // @35_576330
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4160), sizeof v); (u32)v; }) != (eax & 0xff)) goto L5763bd;  // @36_576330
  ecx = edi;  // @37_576330
  eax = ext_576a30_thiscall2(ecx, (u32)(6977432));  // @38_576330
  ecx = edx = 0;  // @39_576330
  L5763bd:;
  eax = (u32)(6980952);  // @41_576330
  L5763c2:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @43_576330
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L5763e2;  // @44_576330
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L5763de;  // @45_576330
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @46_576330
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L5763e2;  // @47_576330
  esi = (esi + (u32)(2));  // @48_576330
  eax = (eax + (u32)(2));  // @49_576330
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L5763c2;  // @50_576330
  L5763de:;
  eax = 0;  // @52_576330
  goto L5763e7;  // @53_576330
  L5763e2:;
  eax = 0;  // @55_576330
  eax = (eax | (u32)(1));  // @56_576330
  L5763e7:;
  if ((eax & eax) != 0) goto L5763f7;  // @58_576330
  ecx = edi;  // @59_576330
  eax = ext_576a30_thiscall2(ecx, (u32)(6981524));  // @60_576330
  ecx = edx = 0;  // @61_576330
  L5763f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_576330
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @66_576330
  ecx = edx = 0;  // @67_576330
  ecx = (u32)(EBP - 4);  // @68_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @69_576330
  p1_ = ecx;  // @70_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @71_576330
  ecx = eax;  // @72_576330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6985060), (u32)(p1_));  // @73_576330
  ecx = edx = 0;  // @74_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @76_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_576330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @78_576330
  ecx = edx = 0;  // @79_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 553), &v, sizeof v); }  // @80_576330
  ecx = eax;  // @81_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @82_576330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(1));  // @83_576330
  ecx = edx = 0;  // @84_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @86_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_576330
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @88_576330
  ecx = edx = 0;  // @89_576330
  ecx = (u32)(EBP - 4);  // @90_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @91_576330
  p2_ = ecx;  // @92_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @93_576330
  ecx = eax;  // @94_576330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6978112), (u32)(p2_));  // @95_576330
  ecx = edx = 0;  // @96_576330
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @97_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @98_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 537), &v, sizeof v); }  // @99_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 557), &v, sizeof v); }  // @100_576330
  if ((esi & esi) == 0) goto L5764ac;  // @101_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @103_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_576330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }));  // @105_576330
  ecx = edx = 0;  // @106_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 78499), &v, sizeof v); }  // @107_576330
  L5764ac:;
  return eax;  // @109_576330
}
PCREG(576330, lifted_576330);

extern "C" u32 THISCALL lifted_63d2f0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63d2f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @1_63d2f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @2_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @3_63d2f0
  if ((eax & eax) == 0) goto L63d491;  // @4_63d2f0
  esi = eax;  // @5_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 104), sizeof v); (u32)v; });  // @6_63d2f0
  esi = (esi & (u32)(4095));  // @7_63d2f0
  esi = (esi << (u32)(2));  // @8_63d2f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @9_63d2f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; });  // @10_63d2f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @11_63d2f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 61), sizeof v); (u32)v; })) & 0xff);  // @12_63d2f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @13_63d2f0
  if ((eax & 0xff) <= (u32)(1)) goto L63d48f;  // @14_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_63d2f0
  edx = 0;  // @16_63d2f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @17_63d2f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @18_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @19_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @20_63d2f0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @21_63d2f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; });  // @22_63d2f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @23_63d2f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @24_63d2f0
  if ((eax & eax) == 0) goto L63d373;  // @25_63d2f0
  L63d360:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == ecx) goto L63d36d;  // @27_63d2f0
  edx = (edx + 1);  // @28_63d2f0
  ebx = (ebx + (u32)(8));  // @29_63d2f0
  if (edx != eax) goto L63d360;  // @30_63d2f0
  L63d36d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @32_63d2f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @33_63d2f0
  L63d373:;
  if (edx == eax) goto L63d48e;  // @35_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @36_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 236), sizeof v); (u32)v; }) == (u32)(0)) goto L63d427;  // @37_63d2f0
  eax = (eax + (u32)(240));  // @38_63d2f0
  ebx = 0;  // @39_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @40_63d2f0
  L63d395:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @42_63d2f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @43_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 65649), sizeof v); (u32)v; });  // @44_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; }) == (u32)(0)) goto L63d405;  // @45_63d2f0
  eax = ext_64c7e0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @46_63d2f0
  ecx = edx = 0;  // @47_63d2f0
  edi = (u32)(eax + 28);  // @48_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L63d405;  // @49_63d2f0
  L63d3b7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @52_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @53_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @54_63d2f0
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L63d3d2;  // @55_63d2f0
  edi = (u32)(esi + 28);  // @56_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L63d3b7;  // @57_63d2f0
  goto L63d402;  // @58_63d2f0
  L63d3d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @60_63d2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @61_63d2f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @62_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 65625), sizeof v); (u32)v; });  // @63_63d2f0
  eax = (~eax);  // @64_63d2f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & eax)); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @65_63d2f0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L63d3f6;  // @66_63d2f0
  p0_ = esi;  // @67_63d2f0
  eax = ext_64d5f0_thiscall2(ecx, (u32)(p0_));  // @68_63d2f0
  ecx = edx = 0;  // @69_63d2f0
  L63d3f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @71_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @72_63d2f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @73_63d2f0
  L63d402:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @75_63d2f0
  L63d405:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @77_63d2f0
  ebx = (ebx + 1);  // @78_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @79_63d2f0
  eax = (eax + (u32)(4));  // @80_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @81_63d2f0
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 236), sizeof v); (u32)v; })) goto L63d395;  // @82_63d2f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @83_63d2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @84_63d2f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @85_63d2f0
  L63d427:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_63d2f0
  if ((eax & eax) == 0) goto L63d434;  // @88_63d2f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @89_63d2f0
  L63d434:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @91_63d2f0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 61), sizeof v); (u32)v; });  // @92_63d2f0
  ecx = (u32)(eax + ecx*8);  // @93_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 4), sizeof v); (u32)v; });  // @94_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @95_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @96_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @97_63d2f0
  if ((eax & eax) == 0) goto L63d450;  // @98_63d2f0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @99_63d2f0
  L63d450:;
  edi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 61), sizeof v); (u32)v; });  // @101_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @102_63d2f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @103_63d2f0
  ecx = ebx;  // @104_63d2f0
  edi = (edi << (u32)(3));  // @105_63d2f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @106_63d2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @107_63d2f0
  eax = (u32)(edi - 8);  // @108_63d2f0
  p1_ = eax;  // @109_63d2f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(p1_));  // @110_63d2f0
  ecx = edx = 0;  // @111_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @112_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 64), &v, sizeof v); }  // @113_63d2f0
  ecx = (u32)(edi - 8);  // @114_63d2f0
  p2_ = ecx;  // @115_63d2f0
  p3_ = esi;  // @116_63d2f0
  p4_ = eax;  // @117_63d2f0
  eax = ext_634d22_cdecl3((u32)(p4_), (u32)(p3_), (u32)(p2_));  // @118_63d2f0
  ecx = edx = 0;  // @119_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @120_63d2f0
  ecx = ebx;  // @121_63d2f0
  p5_ = edi;  // @122_63d2f0
  p6_ = esi;  // @123_63d2f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(p6_), (u32)(p5_));  // @124_63d2f0
  ecx = edx = 0;  // @125_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @126_63d2f0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 61), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 61), &v, sizeof v); }  // @127_63d2f0
  L63d48e:;
  L63d48f:;
  L63d491:;
  return eax;  // @131_63d2f0
}
PCREG(63d2f0, lifted_63d2f0);

extern "C" u32 THISCALL lifted_5edf70(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5edf70
  esi = ecx;  // @1_5edf70
  ecx = edx;  // @2_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @3_5edf70
  edi = (u32)(ecx + 1);  // @4_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @5_5edf70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @6_5edf70
  L5edf90:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @8_5edf70
  ecx = (ecx + 1);  // @9_5edf70
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5edf90;  // @10_5edf70
  ecx = (ecx - edi);  // @11_5edf70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_5edf70
  edi = ecx;  // @13_5edf70
  if (ecx <= (u32)(1)) goto L5ee0e9;  // @14_5edf70
  ebx = (u32)(ecx - 2);  // @15_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @16_5edf70
  if ((ebx & ebx) == 0) goto L5ee0e9;  // @17_5edf70
  L5edfb5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx), sizeof v); (u32)v; }) != (u32)(92)) goto L5ee0bd;  // @19_5edf70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx + 1), sizeof v); (u32)v; }) != (u32)(110)) goto L5ee0bd;  // @20_5edf70
  edi = (edi - ebx);  // @21_5edf70
  edi = (edi - (u32)(2));  // @22_5edf70
  if (edi == 0) goto L5ee0bb;  // @23_5edf70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }) != (u32)(1)) goto L5ee010;  // @24_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @25_5edf70
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }));  // @26_5edf70
  eax = (u32)((s32)eax >> (u32)(2));  // @27_5edf70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }) != eax) goto L5edff7;  // @28_5edf70
  ecx = esi;  // @29_5edf70
  eax = ext_5ee920_thiscall1(ecx);  // @30_5edf70
  ecx = edx = 0;  // @31_5edf70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @32_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @33_5edf70
  L5edff7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @35_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @36_5edf70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @37_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @38_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_5edf70
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @40_5edf70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @41_5edf70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @42_5edf70
  goto L5ee046;  // @43_5edf70
  L5ee010:;
  ecx = esi;  // @45_5edf70
  eax = ext_5ee920_thiscall1(ecx);  // @46_5edf70
  ecx = edx = 0;  // @47_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @48_5edf70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @49_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @51_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @52_5edf70
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }));  // @53_5edf70
  eax = (u32)((s32)eax >> (u32)(2));  // @54_5edf70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @55_5edf70
  if (edx == eax) goto L5ee03b;  // @56_5edf70
  eax = (u32)(edx + 1);  // @57_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @58_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @59_5edf70
  L5ee03b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @61_5edf70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @62_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_5edf70
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @64_5edf70
  L5ee046:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @66_5edf70
  eax = (eax + (u32)(2));  // @67_5edf70
  p0_ = edi;  // @68_5edf70
  eax = (eax + ebx);  // @69_5edf70
  p1_ = eax;  // @70_5edf70
  eax = ext_5aca30_thiscall3(ecx, (u32)(p1_), (u32)(p0_));  // @71_5edf70
  ecx = edx = 0;  // @72_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @73_5edf70
  eax = ext_5ac5d0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @74_5edf70
  ecx = edx = 0;  // @75_5edf70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65), &v, sizeof v); }  // @76_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @77_5edf70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; }) == (u32)(0)) goto L5ee0b4;  // @78_5edf70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @79_5edf70
  ebx = 0;  // @80_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @81_5edf70
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; })) goto L5ee0a2;  // @82_5edf70
  L5ee080:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_5edf70
  eax = ext_5ab9d0_thiscall1(ecx);  // @86_5edf70
  ecx = edx = 0;  // @87_5edf70
  if (eax > ebx) ebx = eax;  // @88_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @89_5edf70
  eax = (eax + 1);  // @90_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @91_5edf70
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; })) goto L5ee0a2;  // @92_5edf70
  edi = (edi + (u32)(4));  // @93_5edf70
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; })) goto L5ee080;  // @94_5edf70
  L5ee0a2:;
  ebx = (ebx + (u32)(10));  // @96_5edf70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; }) == ebx) goto L5ee0b1;  // @97_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @98_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @99_5edf70
  L5ee0b1:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @101_5edf70
  L5ee0b4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @103_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @104_5edf70
  L5ee0bb:;
  edi = ebx;  // @106_5edf70
  L5ee0bd:;
  ebx = (ebx - (u32)(1));  // @108_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @109_5edf70
  if (ebx != 0) goto L5edfb5;  // @110_5edf70
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; })) goto L5ee0e9;  // @111_5edf70
  ecx = esi;  // @112_5edf70
  p2_ = edi;  // @113_5edf70
  p3_ = edx;  // @114_5edf70
  eax = ext_5ee110_thiscall4(ecx, (u32)(p3_), (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @115_5edf70
  ecx = edx = 0;  // @116_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @117_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @118_5edf70
  return eax;  // @119_5edf70
  L5ee0e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @121_5edf70
  ecx = esi;  // @122_5edf70
  p4_ = edi;  // @123_5edf70
  p5_ = edx;  // @124_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @125_5edf70
  eax = ext_5ee110_thiscall4(ecx, (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @126_5edf70
  ecx = edx = 0;  // @127_5edf70
  return eax;  // @128_5edf70
}
PCREG(5edf70, lifted_5edf70);

extern "C" u32 THISCALL lifted_59a2d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_59a2d0
  eax = (u32)(esi + 137);  // @1_59a2d0
  p0_ = eax;  // @2_59a2d0
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(80));  // @3_59a2d0
  ecx = edx = 0;  // @4_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @6_59a2d0
  if ((ecx & ecx) == 0) goto L59a561;  // @7_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002308));  // @9_59a2d0
  ecx = edx = 0;  // @10_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @11_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @13_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002320));  // @15_59a2d0
  ecx = edx = 0;  // @16_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @17_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @19_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002344));  // @21_59a2d0
  ecx = edx = 0;  // @22_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 149), &v, sizeof v); }  // @23_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @25_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002360));  // @27_59a2d0
  ecx = edx = 0;  // @28_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 153), &v, sizeof v); }  // @29_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @31_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002380));  // @33_59a2d0
  ecx = edx = 0;  // @34_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 157), &v, sizeof v); }  // @35_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @37_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002400));  // @39_59a2d0
  ecx = edx = 0;  // @40_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 161), &v, sizeof v); }  // @41_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @43_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002412));  // @45_59a2d0
  ecx = edx = 0;  // @46_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 165), &v, sizeof v); }  // @47_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @49_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002424));  // @51_59a2d0
  ecx = edx = 0;  // @52_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 169), &v, sizeof v); }  // @53_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @55_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002432));  // @57_59a2d0
  ecx = edx = 0;  // @58_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 173), &v, sizeof v); }  // @59_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @61_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002440));  // @63_59a2d0
  ecx = edx = 0;  // @64_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 177), &v, sizeof v); }  // @65_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @67_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002452));  // @69_59a2d0
  ecx = edx = 0;  // @70_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 181), &v, sizeof v); }  // @71_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @72_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @73_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002472));  // @75_59a2d0
  ecx = edx = 0;  // @76_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 185), &v, sizeof v); }  // @77_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @79_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002488));  // @81_59a2d0
  ecx = edx = 0;  // @82_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 189), &v, sizeof v); }  // @83_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @85_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002504));  // @87_59a2d0
  ecx = edx = 0;  // @88_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 193), &v, sizeof v); }  // @89_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @91_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002520));  // @93_59a2d0
  ecx = edx = 0;  // @94_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 197), &v, sizeof v); }  // @95_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @97_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002536));  // @99_59a2d0
  ecx = edx = 0;  // @100_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 201), &v, sizeof v); }  // @101_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @103_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002552));  // @105_59a2d0
  ecx = edx = 0;  // @106_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 205), &v, sizeof v); }  // @107_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @109_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002568));  // @111_59a2d0
  ecx = edx = 0;  // @112_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 209), &v, sizeof v); }  // @113_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_59a2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @115_59a2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_59a2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; }), (u32)(7002580));  // @117_59a2d0
  ecx = edx = 0;  // @118_59a2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 213), &v, sizeof v); }  // @119_59a2d0
  L59a561:;
  return eax;  // @121_59a2d0
}
PCREG(59a2d0, lifted_59a2d0);

extern "C" u32 lifted_6206e0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6206e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_6206e0
  if ((edx & edx) == 0) goto L620772;  // @2_6206e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @3_6206e0
  if ((ecx & ecx) != 0) goto L62071f;  // @4_6206e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @6_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @7_6206e0
  eax = edx;  // @8_6206e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_6206e0
  ecx = (u32)(eax + 8);  // @11_6206e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @12_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @13_6206e0
  eax = (eax + ecx);  // @14_6206e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @15_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @16_6206e0
  eax = (u32)(1);  // @17_6206e0
  return eax;  // @18_6206e0
  L62071f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @20_6206e0
  eax = (eax - ecx);  // @21_6206e0
  if ((s32)eax >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; })) goto L620772;  // @22_6206e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @23_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @25_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @26_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @27_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @28_6206e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @29_6206e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @30_6206e0
  eax = (eax - ecx);  // @31_6206e0
  p0_ = eax;  // @32_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_6206e0
  p1_ = ecx;  // @34_6206e0
  eax = (eax + (u32)(8));  // @35_6206e0
  p2_ = eax;  // @36_6206e0
  eax = ext_634d22_cdecl3((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @37_6206e0
  ecx = edx = 0;  // @38_6206e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_6206e0
  eax = edx;  // @40_6206e0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @41_6206e0
  eax = (eax + (u32)(8));  // @42_6206e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @43_6206e0
  ecx = (u32)(edx + 8);  // @44_6206e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @45_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @46_6206e0
  eax = (eax + ecx);  // @47_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @48_6206e0
  eax = (u32)(1);  // @49_6206e0
  return eax;  // @50_6206e0
  L620772:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_6206e0
  p3_ = edi;  // @53_6206e0
  if ((edx & edx) == 0) goto L6207c6;  // @54_6206e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @55_6206e0
  eax = (u32)(edx + 8);  // @56_6206e0
  if (ecx != eax) goto L6207c6;  // @57_6206e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @58_6206e0
  edi = (edi - ecx);  // @59_6206e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @60_6206e0
  edi = (edi + edi);  // @61_6206e0
  eax = (u32)(edi + 8);  // @62_6206e0
  p4_ = eax;  // @63_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @64_6206e0
  p5_ = edx;  // @65_6206e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(p5_), (u32)(p4_), (u32)(p3_));  // @66_6206e0
  ecx = edx = 0;  // @67_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @68_6206e0
  if ((eax & eax) == 0) goto L6207ef;  // @69_6206e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @70_6206e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @71_6206e0
  eax = ecx;  // @72_6206e0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @73_6206e0
  eax = (eax + (u32)(8));  // @74_6206e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @75_6206e0
  eax = (u32)(ecx + 8);  // @76_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @77_6206e0
  eax = (eax + edi);  // @78_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @79_6206e0
  eax = (u32)(1);  // @80_6206e0
  return eax;  // @81_6206e0
  L6207c6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @83_6206e0
  ebx = (u32)(1024);  // @84_6206e0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @85_6206e0
  if ((s32)eax < (s32)(u32)(1024)) goto L6207db;  // @86_6206e0
  ebx = (u32)(eax + eax);  // @87_6206e0
  L6207db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @89_6206e0
  eax = (u32)(ebx + 8);  // @90_6206e0
  p6_ = eax;  // @91_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_6206e0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p6_));  // @93_6206e0
  ecx = edx = 0;  // @94_6206e0
  edi = eax;  // @95_6206e0
  if ((edi & edi) != 0) goto L6207f6;  // @96_6206e0
  L6207ef:;
  eax = 0;  // @98_6206e0
  return eax;  // @99_6206e0
  L6207f6:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @101_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @103_6206e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @104_6206e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @105_6206e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @106_6206e0
  if (eax == ecx) goto L620819;  // @107_6206e0
  eax = (eax - ecx);  // @108_6206e0
  p7_ = eax;  // @109_6206e0
  p8_ = ecx;  // @110_6206e0
  eax = (u32)(edi + 8);  // @111_6206e0
  p9_ = eax;  // @112_6206e0
  eax = ext_634d22_cdecl3((u32)(p9_), (u32)(p8_), (u32)(p7_));  // @113_6206e0
  ecx = edx = 0;  // @114_6206e0
  L620819:;
  eax = edi;  // @116_6206e0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @117_6206e0
  eax = (eax + (u32)(8));  // @118_6206e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @119_6206e0
  eax = (u32)(edi + 8);  // @120_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @121_6206e0
  eax = (u32)(ebx + 8);  // @122_6206e0
  eax = (eax + edi);  // @123_6206e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @124_6206e0
  eax = (u32)(1);  // @125_6206e0
  return eax;  // @126_6206e0
}
PCREG(6206e0, lifted_6206e0);

extern "C" u32 THISCALL lifted_602bc0(u32 ecx_in) {
  SEH_ENTER(0x66dbd8);  // @h_602bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_602bc0
  eax = ext_603110_thiscall1(ecx);  // @1_602bc0
  ecx = edx = 0;  // @2_602bc0
  { u32 v = (u32)((u32)(7046408)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @3_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @4_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @5_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_602bc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_602bc0
  p0_ = eax;  // @8_602bc0
  ecx = (u32)(EBP - 36);  // @9_602bc0
  reg.state = (s32)((u32)(0));  // @10_602bc0
  eax = ext_602260_thiscall2(ecx, (u32)(p0_));  // @11_602bc0
  ecx = edx = 0;  // @12_602bc0
  eax = (u32)(EBP - 36);  // @13_602bc0
  ecx = esi;  // @14_602bc0
  p1_ = eax;  // @15_602bc0
  eax = ext_6031e0_thiscall2(ecx, (u32)(p1_));  // @16_602bc0
  ecx = edx = 0;  // @17_602bc0
  ecx = (u32)(EBP - 36);  // @18_602bc0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_602bc0
  eax = ext_602240_thiscall1(ecx);  // @20_602bc0
  ecx = edx = 0;  // @21_602bc0
  SEH_LEAVE();  // @22_602bc0
  return eax;  // @23_602bc0
}
PCREG(602bc0, lifted_602bc0);

extern "C" u32 THISCALL lifted_4ccf60(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4ccf60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ccf60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1_4ccf60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_4ccf60
  { u32 v = (u32)((u32)(6903740)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_4ccf60
  if ((edi & edi) == 0) goto L4ccfaf;  // @4_4ccf60
  L4ccfa0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4ccf60
  ecx = esi;  // @7_4ccf60
  p0_ = edi;  // @8_4ccf60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_4ccf60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(p0_));  // @10_4ccf60
  ecx = edx = 0;  // @11_4ccf60
  if ((edi & edi) != 0) goto L4ccfa0;  // @12_4ccf60
  L4ccfaf:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @14_4ccf60
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @15_4ccf60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @16_4ccf60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @17_4ccf60
  SEH_LEAVE();  // @18_4ccf60
  return eax;  // @19_4ccf60
}
PCREG(4ccf60, lifted_4ccf60);

extern "C" u32 THISCALL lifted_4cd0e0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cd0e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cd0e0
  { u32 v = (u32)((u32)(6904480)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4cd0e0
  eax = ext_4cdcc0_thiscall1(ecx);  // @2_4cd0e0
  ecx = edx = 0;  // @3_4cd0e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @4_4cd0e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_4cd0e0
  reg.state = (s32)((u32)(0));  // @6_4cd0e0
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4cd0e0
  if ((edi & edi) == 0) goto L4cd13f;  // @8_4cd0e0
  L4cd130:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_4cd0e0
  ecx = esi;  // @11_4cd0e0
  p0_ = edi;  // @12_4cd0e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @13_4cd0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(p0_));  // @14_4cd0e0
  ecx = edx = 0;  // @15_4cd0e0
  if ((edi & edi) != 0) goto L4cd130;  // @16_4cd0e0
  L4cd13f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @18_4cd0e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @19_4cd0e0
  SEH_LEAVE();  // @20_4cd0e0
  return eax;  // @21_4cd0e0
}
PCREG(4cd0e0, lifted_4cd0e0);

extern "C" u32 FASTCALL lifted_42b080(u32 ecx_in, u32 edx_in, u32 a0) {
  SEH_ENTER(0x66adf6);  // @h_42b080
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = edx;  // @0_42b080
  esi = ecx;  // @1_42b080
  if (esi == edi) goto L42b0dd;  // @2_42b080
  L42b0b0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_42b080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @5_42b080
  eax = (eax - ecx);  // @6_42b080
  reg.state = (s32)((u32)(0));  // @7_42b080
  if ((ecx & ecx) == 0) goto L42b0cf;  // @8_42b080
  if ((eax & eax) == 0) goto L42b0cf;  // @9_42b080
  p0_ = eax;  // @10_42b080
  p1_ = ecx;  // @11_42b080
  ecx = esi;  // @12_42b080
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @13_42b080
  ecx = edx = 0;  // @14_42b080
  L42b0cf:;
  esi = (esi + (u32)(12));  // @16_42b080
  reg.state = (s32)((u32)(4294967295));  // @17_42b080
  if (esi != edi) goto L42b0b0;  // @18_42b080
  L42b0dd:;
  SEH_LEAVE();  // @20_42b080
  return eax;  // @21_42b080
}
PCREG(42b080, lifted_42b080);

extern "C" u32 STDCALL lifted_5f3050(u32 a0, u32 a1) {
  SEH_ENTER(0x66d04f);  // @h_5f3050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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
  p0_ = ecx;  // @18_5f3050
  ecx = esi;  // @19_5f3050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(p0_));  // @20_5f3050
  ecx = edx = 0;  // @21_5f3050
  L5f30b3:;
  eax = esi;  // @23_5f3050
  SEH_LEAVE();  // @24_5f3050
  return eax;  // @25_5f3050
}
PCREG(5f3050, lifted_5f3050);

extern "C" u32 THISCALL lifted_603500(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66dc73);  // @h_603500
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  p0_ = eax;  // @11_603500
  ecx = (u32)(ebx + 12);  // @12_603500
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @13_603500
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @14_603500
  eax = ext_5f5490_thiscall3(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @15_603500
  ecx = edx = 0;  // @16_603500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489176), sizeof v); (u32)v; }) != (u32)(0)) goto L603580;  // @17_603500
  ecx = ebx;  // @18_603500
  eax = ext_603850_thiscall1(ecx);  // @19_603500
  ecx = edx = 0;  // @20_603500
  L603580:;
  eax = ebx;  // @22_603500
  SEH_LEAVE();  // @23_603500
  return eax;  // @24_603500
}
PCREG(603500, lifted_603500);

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

extern "C" u32 FASTCALL lifted_42b160(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6649b1);  // @h_42b160
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = edx;  // @0_42b160
  esi = ecx;  // @1_42b160
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42b160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @3_42b160
  if (esi == ebx) goto L42b1be;  // @4_42b160
  L42b194:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_42b160
  reg.state = (s32)((u32)(0));  // @7_42b160
  if ((edi & edi) == 0) goto L42b1aa;  // @8_42b160
  p0_ = esi;  // @9_42b160
  ecx = edi;  // @10_42b160
  eax = ext_5f10c0_thiscall2(ecx, (u32)(p0_));  // @11_42b160
  ecx = edx = 0;  // @12_42b160
  L42b1aa:;
  esi = (esi + (u32)(12));  // @14_42b160
  reg.state = (s32)((u32)(4294967295));  // @15_42b160
  edi = (edi + (u32)(12));  // @16_42b160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @17_42b160
  if (esi != ebx) goto L42b194;  // @18_42b160
  L42b1be:;
  eax = edi;  // @20_42b160
  SEH_LEAVE();  // @21_42b160
  return eax;  // @22_42b160
}
PCREG(42b160, lifted_42b160);

extern "C" u32 THISCALL lifted_5a3dc0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5a3dc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  p0_ = ebx;  // @18_5a3dc0
  reg.state = (s32)(edi);  // @19_5a3dc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_5a3dc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_5a3dc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p0_));  // @22_5a3dc0
  ecx = edx = 0;  // @23_5a3dc0
  SEH_LEAVE();  // @24_5a3dc0
  return eax;  // @25_5a3dc0
}
PCREG(5a3dc0, lifted_5a3dc0);

extern "C" u32 THISCALL lifted_606a70(u32 ecx_in) {
  SEH_ENTER(0x66df2b);  // @h_606a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = esi;  // @13_606a70
  eax = ext_59a9b0_thiscall2(ecx, (u32)(p0_));  // @14_606a70
  ecx = edx = 0;  // @15_606a70
  eax = (u32)(EBP - 16);  // @16_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @17_606a70
  p1_ = eax;  // @18_606a70
  p2_ = esi;  // @19_606a70
  ecx = (u32)(ebx + 3);  // @20_606a70
  eax = ext_606ee0_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7), sizeof v); (u32)v; }), (u32)(p2_), (u32)(p1_));  // @21_606a70
  ecx = edx = 0;  // @22_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 15), &v, sizeof v); }  // @23_606a70
  eax = ebx;  // @24_606a70
  SEH_LEAVE();  // @25_606a70
  return eax;  // @26_606a70
}
PCREG(606a70, lifted_606a70);

extern "C" u32 THISCALL lifted_452ed0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666568);  // @h_452ed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_452ed0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_452ed0
  eax = ext_43de40_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_452ed0
  ecx = edx = 0;  // @3_452ed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @4_452ed0
  eax = (u32)(65535);  // @5_452ed0
  reg.state = (s32)((u32)(0));  // @6_452ed0
  { u32 v = (u32)((u32)(6822692)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_452ed0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @8_452ed0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @9_452ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @10_452ed0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @11_452ed0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @12_452ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @13_452ed0
  { u16 v = (u16)((u32)(257)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @14_452ed0
  eax = ext_4dc630_thiscall3(ecx, (u32)(4194304), (u32)(0));  // @15_452ed0
  ecx = edx = 0;  // @16_452ed0
  eax = (u32)(esi + 34);  // @17_452ed0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @18_452ed0
  p0_ = eax;  // @19_452ed0
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(48));  // @20_452ed0
  ecx = edx = 0;  // @21_452ed0
  eax = esi;  // @22_452ed0
  SEH_LEAVE();  // @23_452ed0
  return eax;  // @24_452ed0
}
PCREG(452ed0, lifted_452ed0);

extern "C" u32 STDCALL lifted_601d80(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_4cce40(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cce40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cce40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @1_4cce40
  { u32 v = (u32)((u32)(6904156)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4cce40
  if ((ecx & ecx) == 0) goto L4cce79;  // @3_4cce40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4cce40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4cce40
  ecx = edx = 0;  // @6_4cce40
  L4cce79:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @8_4cce40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @9_4cce40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @10_4cce40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @11_4cce40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @12_4cce40
  reg.state = (s32)((u32)(0));  // @13_4cce40
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_4cce40
  if ((edi & edi) == 0) goto L4ccebf;  // @15_4cce40
  L4cceb0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_4cce40
  ecx = esi;  // @18_4cce40
  p0_ = edi;  // @19_4cce40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @20_4cce40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(p0_));  // @21_4cce40
  ecx = edx = 0;  // @22_4cce40
  if ((edi & edi) != 0) goto L4cceb0;  // @23_4cce40
  L4ccebf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @25_4cce40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @26_4cce40
  SEH_LEAVE();  // @27_4cce40
  return eax;  // @28_4cce40
}
PCREG(4cce40, lifted_4cce40);

extern "C" u32 THISCALL lifted_607b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e0b2);  // @h_607b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_424080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_424080
  if ((ecx & ecx) == 0) goto L4240fa;  // @2_424080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) == (u32)(0)) goto L4240fa;  // @3_424080
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_424080
  p0_ = ecx;  // @5_424080
  ecx = (u32)(EBP - 144);  // @6_424080
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @7_424080
  ecx = edx = 0;  // @8_424080
  eax = (u32)(EBP - 144);  // @9_424080
  reg.state = (s32)((u32)(0));  // @10_424080
  p1_ = eax;  // @11_424080
  ecx = (u32)(esi + 9563);  // @12_424080
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @13_424080
  ecx = edx = 0;  // @14_424080
  ecx = (u32)(EBP - 144);  // @15_424080
  eax = ext_4cbec0_thiscall1(ecx);  // @16_424080
  ecx = edx = 0;  // @17_424080
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6975), &v, sizeof v); }  // @18_424080
  goto L42410f;  // @19_424080
  L4240fa:;
  if ((eax & eax) == 0) goto L42410f;  // @21_424080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L42410f;  // @22_424080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_424080
  p2_ = eax;  // @24_424080
  eax = ext_423ff0_thiscall2(ecx, (u32)(p2_));  // @25_424080
  ecx = edx = 0;  // @26_424080
  L42410f:;
  SEH_LEAVE();  // @28_424080
  ext_633654(G(u32, 0x6f5630));  // @29_424080
  return eax;  // @30_424080
}
PCREG(424080, lifted_424080);

extern "C" u32 THISCALL lifted_473a70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_473a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_473a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_473a70
  ecx = (u32)(EBP - 16596);  // @2_473a70
  eax = ext_4d2280_thiscall1(ecx);  // @3_473a70
  ecx = edx = 0;  // @4_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_473a70
  p0_ = esi;  // @6_473a70
  reg.state = (s32)((u32)(0));  // @7_473a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_473a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_473a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @10_473a70
  ecx = edx = 0;  // @11_473a70
  p1_ = eax;  // @12_473a70
  ecx = (u32)(EBP - 16596);  // @13_473a70
  eax = ext_4d3ab0_stdcall2((u32)(6851120), (u32)(p1_));  // @14_473a70
  ecx = edx = 0;  // @15_473a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_473a70
  eax = (u32)(EBP - 16596);  // @17_473a70
  p2_ = eax;  // @18_473a70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338404), sizeof v); (u32)v; });  // @19_473a70
  ecx = edi;  // @20_473a70
  p3_ = eax;  // @21_473a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(p3_), (u32)(p2_));  // @22_473a70
  ecx = edx = 0;  // @23_473a70
  ecx = (u32)(EBP - 16596);  // @24_473a70
  eax = ext_4d2330_thiscall1(ecx);  // @25_473a70
  ecx = edx = 0;  // @26_473a70
  SEH_LEAVE();  // @27_473a70
  ext_633654(G(u32, 0x6f5630));  // @28_473a70
  return eax;  // @29_473a70
}
PCREG(473a70, lifted_473a70);

extern "C" u32 THISCALL lifted_474e00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_474e00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_474e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_474e00
  ecx = (u32)(EBP - 16596);  // @2_474e00
  eax = ext_4d2280_thiscall1(ecx);  // @3_474e00
  ecx = edx = 0;  // @4_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474e00
  p0_ = esi;  // @6_474e00
  reg.state = (s32)((u32)(0));  // @7_474e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_474e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @10_474e00
  ecx = edx = 0;  // @11_474e00
  p1_ = eax;  // @12_474e00
  ecx = (u32)(EBP - 16596);  // @13_474e00
  eax = ext_4d3ab0_stdcall2((u32)(6851120), (u32)(p1_));  // @14_474e00
  ecx = edx = 0;  // @15_474e00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_474e00
  eax = (u32)(EBP - 16596);  // @17_474e00
  p2_ = eax;  // @18_474e00
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338412), sizeof v); (u32)v; });  // @19_474e00
  ecx = edi;  // @20_474e00
  p3_ = eax;  // @21_474e00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(p3_), (u32)(p2_));  // @22_474e00
  ecx = edx = 0;  // @23_474e00
  ecx = (u32)(EBP - 16596);  // @24_474e00
  eax = ext_4d2330_thiscall1(ecx);  // @25_474e00
  ecx = edx = 0;  // @26_474e00
  SEH_LEAVE();  // @27_474e00
  ext_633654(G(u32, 0x6f5630));  // @28_474e00
  return eax;  // @29_474e00
}
PCREG(474e00, lifted_474e00);

extern "C" u32 THISCALL lifted_474f60(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_474f60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_474f60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_474f60
  ecx = (u32)(EBP - 16596);  // @2_474f60
  eax = ext_4d2280_thiscall1(ecx);  // @3_474f60
  ecx = edx = 0;  // @4_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474f60
  p0_ = esi;  // @6_474f60
  reg.state = (s32)((u32)(0));  // @7_474f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_474f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_474f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @10_474f60
  ecx = edx = 0;  // @11_474f60
  p1_ = eax;  // @12_474f60
  ecx = (u32)(EBP - 16596);  // @13_474f60
  eax = ext_4d3ab0_stdcall2((u32)(6851120), (u32)(p1_));  // @14_474f60
  ecx = edx = 0;  // @15_474f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_474f60
  eax = (u32)(EBP - 16596);  // @17_474f60
  p2_ = eax;  // @18_474f60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338400), sizeof v); (u32)v; });  // @19_474f60
  ecx = edi;  // @20_474f60
  p3_ = eax;  // @21_474f60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(p3_), (u32)(p2_));  // @22_474f60
  ecx = edx = 0;  // @23_474f60
  ecx = (u32)(EBP - 16596);  // @24_474f60
  eax = ext_4d2330_thiscall1(ecx);  // @25_474f60
  ecx = edx = 0;  // @26_474f60
  SEH_LEAVE();  // @27_474f60
  ext_633654(G(u32, 0x6f5630));  // @28_474f60
  return eax;  // @29_474f60
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

extern "C" u32 THISCALL lifted_4e6ce0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_4e6ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = (u32)(ecx + 12);  // @0_4e6ce0
  { u32 v = (u32)((u32)(6877288)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1_4e6ce0
  if ((esi & esi) == 0) goto L4e6d4c;  // @2_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_4e6ce0
  ecx = (u32)(EBP - 24);  // @4_4e6ce0
  p0_ = ecx;  // @5_4e6ce0
  ecx = esi;  // @6_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @7_4e6ce0
  ecx = edx = 0;  // @8_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4e6ce0
  ecx = (u32)(EBP - 24);  // @10_4e6ce0
  p1_ = ecx;  // @11_4e6ce0
  ecx = esi;  // @12_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @13_4e6ce0
  ecx = edx = 0;  // @14_4e6ce0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4e6d4c;  // @15_4e6ce0
  L4e6d30:;
  p2_ = eax;  // @17_4e6ce0
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(24));  // @18_4e6ce0
  ecx = edx = 0;  // @19_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_4e6ce0
  ecx = (u32)(EBP - 24);  // @21_4e6ce0
  p3_ = ecx;  // @22_4e6ce0
  ecx = esi;  // @23_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @24_4e6ce0
  ecx = edx = 0;  // @25_4e6ce0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4e6d30;  // @26_4e6ce0
  L4e6d4c:;
  ecx = esi;  // @28_4e6ce0
  eax = ext_4ccf60_thiscall1(ecx);  // @29_4e6ce0
  ecx = edx = 0;  // @30_4e6ce0
  SEH_LEAVE();  // @31_4e6ce0
  return eax;  // @32_4e6ce0
}
PCREG(4e6ce0, lifted_4e6ce0);

extern "C" u32 THISCALL lifted_4352f0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4352f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = edx;  // @9_4352f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4352f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p0_), (u32)(6792648), (u32)(8));  // @11_4352f0
  ecx = edx = 0;  // @12_4352f0
  eax = (u32)(EBP - 144);  // @13_4352f0
  p1_ = eax;  // @14_4352f0
  ecx = (u32)(EBP - 272);  // @15_4352f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @16_4352f0
  ecx = edx = 0;  // @17_4352f0
  eax = (u32)(EBP - 272);  // @18_4352f0
  reg.state = (s32)((u32)(0));  // @19_4352f0
  p2_ = eax;  // @20_4352f0
  ecx = (u32)(esi + 140);  // @21_4352f0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @22_4352f0
  ecx = edx = 0;  // @23_4352f0
  ecx = (u32)(EBP - 272);  // @24_4352f0
  eax = ext_4cbec0_thiscall1(ecx);  // @25_4352f0
  ecx = edx = 0;  // @26_4352f0
  SEH_LEAVE();  // @27_4352f0
  ext_633654(G(u32, 0x6f5630));  // @28_4352f0
  return eax;  // @29_4352f0
  L4353a0:;
  eax = ext_634047_cdecl0();  // @31_4352f0
  ecx = edx = 0;  // @32_4352f0
}
PCREG(4352f0, lifted_4352f0);

extern "C" u32 THISCALL lifted_4353b0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4353b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = edx;  // @9_4353b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4353b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p0_), (u32)(6792636), (u32)(8));  // @11_4353b0
  ecx = edx = 0;  // @12_4353b0
  eax = (u32)(EBP - 144);  // @13_4353b0
  p1_ = eax;  // @14_4353b0
  ecx = (u32)(EBP - 272);  // @15_4353b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @16_4353b0
  ecx = edx = 0;  // @17_4353b0
  eax = (u32)(EBP - 272);  // @18_4353b0
  reg.state = (s32)((u32)(0));  // @19_4353b0
  p2_ = eax;  // @20_4353b0
  ecx = (u32)(esi + 12);  // @21_4353b0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @22_4353b0
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
  u32 p0_, p1_;
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
  p0_ = eax;  // @19_4cb150
  ecx = edi;  // @20_4cb150
  eax = ext_4e6330_thiscall2(ecx, (u32)(p0_));  // @21_4cb150
  ecx = edx = 0;  // @22_4cb150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4cb150
  ecx = (u32)(EBP - 188);  // @24_4cb150
  p1_ = ecx;  // @25_4cb150
  ecx = esi;  // @26_4cb150
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p1_));  // @27_4cb150
  ecx = edx = 0;  // @28_4cb150
  ecx = (u32)(EBP - 188);  // @29_4cb150
  eax = ext_4ccf60_thiscall1(ecx);  // @30_4cb150
  ecx = edx = 0;  // @31_4cb150
  SEH_LEAVE();  // @32_4cb150
  ext_633654(G(u32, 0x6f5630));  // @33_4cb150
  return eax;  // @34_4cb150
}
PCREG(4cb150, lifted_4cb150);

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
  u32 p0_, p1_;
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
  p0_ = ecx;  // @15_6040d0
  ecx = esi;  // @16_6040d0
  reg.state = (s32)((u32)(1));  // @17_6040d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(p0_));  // @18_6040d0
  ecx = edx = 0;  // @19_6040d0
  ecx = (u32)(EBP - 28);  // @20_6040d0
  eax = ext_500190_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @21_6040d0
  ecx = edx = 0;  // @22_6040d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_6040d0
  ecx = edi;  // @24_6040d0
  p1_ = esi;  // @25_6040d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @26_6040d0
  ecx = edx = 0;  // @27_6040d0
  ecx = (u32)(EBP - 28);  // @28_6040d0
  eax = ext_4ff9d0_thiscall1(ecx);  // @29_6040d0
  ecx = edx = 0;  // @30_6040d0
  SEH_LEAVE();  // @31_6040d0
  return eax;  // @32_6040d0
}
PCREG(6040d0, lifted_6040d0);

extern "C" u32 STDCALL lifted_43a720(u32 a0) {
  SEH_ENTER(0x665c56);  // @h_43a720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_43a720
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @1_43a720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }) != 0) goto L43a7ab;  // @2_43a720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4628), sizeof v); (u32)v; });  // @3_43a720
  p0_ = esi;  // @4_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_43a720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(p0_));  // @6_43a720
  ecx = edx = 0;  // @7_43a720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @8_43a720
  reg.state = (s32)((u32)(0));  // @9_43a720
  { u32 v = (u32)((u32)(6793124)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_43a720
  if ((eax & eax) == 0) goto L43a777;  // @11_43a720
  p1_ = eax;  // @12_43a720
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(1));  // @13_43a720
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
  p2_ = esi;  // @29_43a720
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(35));  // @30_43a720
  ecx = edx = 0;  // @31_43a720
  L43a7ab:;
  SEH_LEAVE();  // @33_43a720
  return eax;  // @34_43a720
}
PCREG(43a720, lifted_43a720);

extern "C" u32 THISCALL lifted_435580(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_435580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435580
  ecx = (u32)(EBP - 144);  // @2_435580
  p0_ = eax;  // @3_435580
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_435580
  ecx = edx = 0;  // @5_435580
  eax = (u32)(EBP - 144);  // @6_435580
  reg.state = (s32)((u32)(0));  // @7_435580
  edi = (edi + (u32)(140));  // @8_435580
  p1_ = eax;  // @9_435580
  ecx = edi;  // @10_435580
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @11_435580
  ecx = edx = 0;  // @12_435580
  ecx = (u32)(EBP - 144);  // @13_435580
  reg.state = (s32)((u32)(4294967295));  // @14_435580
  eax = ext_4cbec0_thiscall1(ecx);  // @15_435580
  ecx = edx = 0;  // @16_435580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @17_435580
  ecx = edi;  // @18_435580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_435580
  eax = ext_4cc5f0_thiscall1(ecx);  // @20_435580
  ecx = edx = 0;  // @21_435580
  p2_ = eax;  // @22_435580
  ecx = edi;  // @23_435580
  eax = ext_4cc1d0_cdecl1((u32)(p2_));  // @24_435580
  ecx = edx = 0;  // @25_435580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @26_435580
  p3_ = eax;  // @27_435580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 20)))(ecx, (u32)(6792648), (u32)(8), (u32)(p3_));  // @28_435580
  ecx = edx = 0;  // @29_435580
  SEH_LEAVE();  // @30_435580
  ext_633654(G(u32, 0x6f5630));  // @31_435580
  return eax;  // @32_435580
}
PCREG(435580, lifted_435580);

extern "C" u32 THISCALL lifted_435630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_435630
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435630
  ecx = (u32)(EBP - 144);  // @2_435630
  p0_ = eax;  // @3_435630
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_435630
  ecx = edx = 0;  // @5_435630
  eax = (u32)(EBP - 144);  // @6_435630
  reg.state = (s32)((u32)(0));  // @7_435630
  edi = (edi + (u32)(12));  // @8_435630
  p1_ = eax;  // @9_435630
  ecx = edi;  // @10_435630
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @11_435630
  ecx = edx = 0;  // @12_435630
  ecx = (u32)(EBP - 144);  // @13_435630
  reg.state = (s32)((u32)(4294967295));  // @14_435630
  eax = ext_4cbec0_thiscall1(ecx);  // @15_435630
  ecx = edx = 0;  // @16_435630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @17_435630
  ecx = edi;  // @18_435630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_435630
  eax = ext_4cc5f0_thiscall1(ecx);  // @20_435630
  ecx = edx = 0;  // @21_435630
  p2_ = eax;  // @22_435630
  ecx = edi;  // @23_435630
  eax = ext_4cc1d0_cdecl1((u32)(p2_));  // @24_435630
  ecx = edx = 0;  // @25_435630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @26_435630
  p3_ = eax;  // @27_435630
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 20)))(ecx, (u32)(6792636), (u32)(8), (u32)(p3_));  // @28_435630
  ecx = edx = 0;  // @29_435630
  SEH_LEAVE();  // @30_435630
  ext_633654(G(u32, 0x6f5630));  // @31_435630
  return eax;  // @32_435630
}
PCREG(435630, lifted_435630);

extern "C" u32 THISCALL lifted_5047c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669bf8);  // @h_5047c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_5047c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5047c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5047c0
  p0_ = esi;  // @3_5047c0
  eax = ext_500990_thiscall2(ecx, (u32)(p0_));  // @4_5047c0
  ecx = edx = 0;  // @5_5047c0
  reg.state = (s32)((u32)(0));  // @6_5047c0
  { u32 v = (u32)((u32)(6933640)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_5047c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @8_5047c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343996), sizeof v); (u32)v; }) != (u32)(0)) goto L504813;  // @9_5047c0
  ecx = edi;  // @10_5047c0
  eax = ext_505d50_thiscall1(ecx);  // @11_5047c0
  ecx = edx = 0;  // @12_5047c0
  L504813:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7245439), sizeof v); (u32)v; }) == (u32)(0)) goto L504854;  // @14_5047c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_5047c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7245439), &v, sizeof v); }  // @16_5047c0
  if ((ecx & ecx) == 0) goto L504854;  // @17_5047c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5047c0
  edx = (u32)(EBP + 8);  // @19_5047c0
  p1_ = edx;  // @20_5047c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @21_5047c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6933760), (u32)(p1_));  // @22_5047c0
  ecx = edx = 0;  // @23_5047c0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7343992), sizeof v); (u32)v; });  // @24_5047c0
  edx = (u32)(1);  // @25_5047c0
  if (((eax & 0xff) & (eax & 0xff)) != 0) ecx = edx;  // @26_5047c0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(7343992), &v, sizeof v); }  // @27_5047c0
  L504854:;
  eax = edi;  // @29_5047c0
  SEH_LEAVE();  // @30_5047c0
  return eax;  // @31_5047c0
}
PCREG(5047c0, lifted_5047c0);

extern "C" u32 THISCALL lifted_54b420(u32 ecx_in) {
  SEH_ENTER(0x66acdf);  // @h_54b420
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_54b420
  eax = ext_41e290_cdecl1((u32)(84));  // @1_54b420
  ecx = edx = 0;  // @2_54b420
  esi = eax;  // @3_54b420
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_54b420
  reg.state = (s32)((u32)(0));  // @5_54b420
  if ((esi & esi) == 0) goto L54b485;  // @6_54b420
  ecx = esi;  // @7_54b420
  eax = ext_54cb50_thiscall1(ecx);  // @8_54b420
  ecx = edx = 0;  // @9_54b420
  { u32 v = (u32)((u32)(6961212)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_54b420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @11_54b420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @12_54b420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @13_54b420
  goto L54b487;  // @14_54b420
  L54b485:;
  esi = 0;  // @16_54b420
  L54b487:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 32841), &v, sizeof v); }  // @18_54b420
  ecx = esi;  // @19_54b420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_54b420
  reg.state = (s32)((u32)(4294967295));  // @21_54b420
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41592), sizeof v); (u32)v; }));  // @22_54b420
  ecx = edx = 0;  // @23_54b420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_54b420
  ecx = esi;  // @25_54b420
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @26_54b420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @27_54b420
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @28_54b420
  ecx = edx = 0;  // @29_54b420
  eax = (eax & 0xffffff00u) | (((u32)(((eax & 0xff) & (eax & 0xff)) != 0)) & 0xff);  // @30_54b420
  SEH_LEAVE();  // @31_54b420
  return eax;  // @32_54b420
}
PCREG(54b420, lifted_54b420);

extern "C" u32 THISCALL lifted_5fb370(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d436);  // @h_5fb370
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5fb370
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5fb370
  if ((esi & esi) == 0) goto L5fb3e4;  // @2_5fb370
  L5fb3a0:;
  ecx = ebx;  // @4_5fb370
  eax = ext_5fb370_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }));  // @5_5fb370
  ecx = edx = 0;  // @6_5fb370
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @7_5fb370
  ecx = (u32)(esi + 13);  // @8_5fb370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_5fb370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @10_5fb370
  eax = (eax - edx);  // @11_5fb370
  reg.state = (s32)((u32)(0));  // @12_5fb370
  if ((edx & edx) == 0) goto L5fb3cd;  // @13_5fb370
  if ((eax & eax) == 0) goto L5fb3cd;  // @14_5fb370
  p0_ = eax;  // @15_5fb370
  p1_ = edx;  // @16_5fb370
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @17_5fb370
  ecx = edx = 0;  // @18_5fb370
  L5fb3cd:;
  p2_ = esi;  // @20_5fb370
  ecx = ebx;  // @21_5fb370
  reg.state = (s32)((u32)(4294967295));  // @22_5fb370
  eax = ext_54f870_stdcall2((u32)(p2_), (u32)(29));  // @23_5fb370
  ecx = edx = 0;  // @24_5fb370
  esi = edi;  // @25_5fb370
  if ((edi & edi) != 0) goto L5fb3a0;  // @26_5fb370
  L5fb3e4:;
  SEH_LEAVE();  // @28_5fb370
  return eax;  // @29_5fb370
}
PCREG(5fb370, lifted_5fb370);

extern "C" u32 THISCALL lifted_45fdf0(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45fdf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = edx;  // @14_45fdf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p0_));  // @15_45fdf0
  ecx = edx = 0;  // @16_45fdf0
  L45fe50:;
  p1_ = ebx;  // @18_45fdf0
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(16));  // @19_45fdf0
  ecx = edx = 0;  // @20_45fdf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @21_45fdf0
  L45fe62:;
  p2_ = edi;  // @23_45fdf0
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(8));  // @24_45fdf0
  ecx = edx = 0;  // @25_45fdf0
  L45fe6d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @27_45fdf0
  SEH_LEAVE();  // @28_45fdf0
  return eax;  // @29_45fdf0
}
PCREG(45fdf0, lifted_45fdf0);

extern "C" u32 THISCALL lifted_63ab30(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_63ab30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_63ab30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_63ab30
  edi = 0;  // @2_63ab30
  { u32 v = (u32)((u32)(7086900)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @3_63ab30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }) == edi) goto L63aba4;  // @4_63ab30
  ebx = (ebx + (u32)(240));  // @5_63ab30
  L63ab71:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_63ab30
  ecx = esi;  // @8_63ab30
  eax = ext_64b070_thiscall1(ecx);  // @9_63ab30
  ecx = edx = 0;  // @10_63ab30
  if ((esi & esi) == 0) goto L63ab93;  // @11_63ab30
  ecx = esi;  // @12_63ab30
  eax = ext_648280_thiscall1(ecx);  // @13_63ab30
  ecx = edx = 0;  // @14_63ab30
  p0_ = esi;  // @15_63ab30
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(98977));  // @16_63ab30
  ecx = edx = 0;  // @17_63ab30
  L63ab93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @19_63ab30
  edi = (edi + 1);  // @20_63ab30
  ebx = (ebx + (u32)(4));  // @21_63ab30
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 236), sizeof v); (u32)v; })) goto L63ab71;  // @22_63ab30
  ebx = eax;  // @23_63ab30
  L63aba4:;
  ecx = (u32)(ebx + 47504);  // @25_63ab30
  eax = ext_4cd160_thiscall1(ecx);  // @26_63ab30
  ecx = edx = 0;  // @27_63ab30
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47433), sizeof v); (u32)v; }) & (u32)(253))); __builtin_memcpy((void *)(u32)(ebx + 47433), &v, sizeof v); }  // @28_63ab30
  ecx = (u32)(ebx + 33392);  // @29_63ab30
  eax = ext_65e130_thiscall1(ecx);  // @30_63ab30
  ecx = edx = 0;  // @31_63ab30
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; }) & (u32)(253))); __builtin_memcpy((void *)(u32)(ebx + 25), &v, sizeof v); }  // @32_63ab30
  SEH_LEAVE();  // @33_63ab30
  return eax;  // @34_63ab30
}
PCREG(63ab30, lifted_63ab30);

extern "C" u32 THISCALL lifted_500220(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66ae60);  // @h_500220
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
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
  p0_ = ecx;  // @15_500220
  ecx = edi;  // @16_500220
  reg.state = (s32)((u32)(1));  // @17_500220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(p0_));  // @18_500220
  ecx = edx = 0;  // @19_500220
  ecx = (u32)(EBP - 28);  // @20_500220
  eax = ext_500150_thiscall1(ecx);  // @21_500220
  ecx = edx = 0;  // @22_500220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @23_500220
  ecx = ebx;  // @24_500220
  p1_ = edi;  // @25_500220
  esi = eax;  // @26_500220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, (u32)(p1_));  // @27_500220
  ecx = edx = 0;  // @28_500220
  ecx = (u32)(EBP - 28);  // @29_500220
  eax = ext_4ff9d0_thiscall1(ecx);  // @30_500220
  ecx = edx = 0;  // @31_500220
  eax = (u32)(esi + 4);  // @32_500220
  SEH_LEAVE();  // @33_500220
  return eax;  // @34_500220
}
PCREG(500220, lifted_500220);

extern "C" u32 THISCALL lifted_4d1640(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66930f);  // @h_4d1640
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_4d1640
  eax = ext_41e290_cdecl1((u32)(20));  // @1_4d1640
  ecx = edx = 0;  // @2_4d1640
  edi = eax;  // @3_4d1640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4d1640
  reg.state = (s32)((u32)(0));  // @5_4d1640
  if ((edi & edi) == 0) goto L4d16bf;  // @6_4d1640
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_4d1640
  p0_ = esi;  // @8_4d1640
  eax = ext_41e290_cdecl1((u32)(p0_));  // @9_4d1640
  ecx = edx = 0;  // @10_4d1640
  p1_ = esi;  // @11_4d1640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @12_4d1640
  p2_ = eax;  // @13_4d1640
  eax = ext_634d22_cdecl3((u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p1_));  // @14_4d1640
  ecx = edx = 0;  // @15_4d1640
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @16_4d1640
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @17_4d1640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @18_4d1640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @19_4d1640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @20_4d1640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @21_4d1640
  if ((eax & eax) == 0) goto L4d16b9;  // @22_4d1640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @23_4d1640
  goto L4d16bc;  // @24_4d1640
  L4d16b9:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @26_4d1640
  L4d16bc:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @28_4d1640
  L4d16bf:;
  SEH_LEAVE();  // @30_4d1640
  return eax;  // @31_4d1640
}
PCREG(4d1640, lifted_4d1640);

extern "C" u32 THISCALL lifted_4b1320(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_4b1320
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4b1320
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b1320
  ecx = esi;  // @2_4b1320
  eax = ext_4e5e60_thiscall1(ecx);  // @3_4b1320
  ecx = edx = 0;  // @4_4b1320
  ecx = esi;  // @5_4b1320
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @6_4b1320
  eax = ext_4e5e60_thiscall1(ecx);  // @7_4b1320
  ecx = edx = 0;  // @8_4b1320
  ecx = esi;  // @9_4b1320
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @10_4b1320
  eax = ext_4e5e60_thiscall1(ecx);  // @11_4b1320
  ecx = edx = 0;  // @12_4b1320
  ecx = esi;  // @13_4b1320
  eax = (eax & 0xffffff00u) | (((u32)((eax & eax) != 0)) & 0xff);  // @14_4b1320
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @15_4b1320
  eax = ext_4e5ea0_thiscall1(ecx);  // @16_4b1320
  ecx = edx = 0;  // @17_4b1320
  if ((eax & eax) == 0) goto L4b13b2;  // @18_4b1320
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L4b13b2;  // @19_4b1320
  p0_ = eax;  // @20_4b1320
  ecx = (u32)(EBP - 144);  // @21_4b1320
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @22_4b1320
  ecx = edx = 0;  // @23_4b1320
  eax = (u32)(EBP - 144);  // @24_4b1320
  reg.state = (s32)((u32)(0));  // @25_4b1320
  p1_ = eax;  // @26_4b1320
  ecx = (u32)(edi + 85);  // @27_4b1320
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @28_4b1320
  ecx = edx = 0;  // @29_4b1320
  ecx = (u32)(EBP - 144);  // @30_4b1320
  eax = ext_4cbec0_thiscall1(ecx);  // @31_4b1320
  ecx = edx = 0;  // @32_4b1320
  L4b13b2:;
  SEH_LEAVE();  // @34_4b1320
  ext_633654(G(u32, 0x6f5630));  // @35_4b1320
  return eax;  // @36_4b1320
}
PCREG(4b1320, lifted_4b1320);

extern "C" u32 THISCALL lifted_4373a0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x665a8f);  // @h_4373a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
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
  p0_ = esi;  // @15_4373a0
  eax = ext_4364e0_thiscall5(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(0));  // @16_4373a0
  ecx = edx = 0;  // @17_4373a0
  edx = eax;  // @18_4373a0
  goto L437415;  // @19_4373a0
  L437413:;
  edx = 0;  // @21_4373a0
  L437415:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4628), sizeof v); (u32)v; });  // @23_4373a0
  p1_ = edx;  // @24_4373a0
  reg.state = (s32)((u32)(4294967295));  // @25_4373a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4373a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @27_4373a0
  ecx = edx = 0;  // @28_4373a0
  SEH_LEAVE();  // @29_4373a0
  return eax;  // @30_4373a0
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

extern "C" u32 THISCALL lifted_444020(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_444020
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_444020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @1_444020
  { u32 v = (u32)((u32)(6803920)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_444020
  if ((ecx & ecx) == 0) goto L444066;  // @3_444020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_444020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_444020
  ecx = edx = 0;  // @6_444020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @7_444020
  L444066:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L44408d;  // @9_444020
  L444070:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @11_444020
  if ((edi & edi) == 0) goto L444087;  // @12_444020
  ecx = edi;  // @13_444020
  eax = ext_4d9430_thiscall1(ecx);  // @14_444020
  ecx = edx = 0;  // @15_444020
  p0_ = edi;  // @16_444020
  eax = ext_4d9590_cdecl1((u32)(p0_));  // @17_444020
  ecx = edx = 0;  // @18_444020
  L444087:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) != (u32)(0)) goto L444070;  // @20_444020
  L44408d:;
  ecx = esi;  // @22_444020
  eax = ext_444530_thiscall1(ecx);  // @23_444020
  ecx = edx = 0;  // @24_444020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 144), sizeof v); (u32)v; });  // @25_444020
  if ((eax & eax) == 0) goto L4440bd;  // @26_444020
  p1_ = eax;  // @27_444020
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(52));  // @28_444020
  ecx = edx = 0;  // @29_444020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @30_444020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @31_444020
  L4440bd:;
  ecx = esi;  // @33_444020
  eax = ext_441c00_thiscall1(ecx);  // @34_444020
  ecx = edx = 0;  // @35_444020
  SEH_LEAVE();  // @36_444020
  return eax;  // @37_444020
}
PCREG(444020, lifted_444020);

extern "C" u32 THISCALL lifted_449ed0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_449ed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = edi;  // @19_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(p0_));  // @21_449ed0
  ecx = edx = 0;  // @22_449ed0
  if ((eax & eax) != 0) goto L449f47;  // @23_449ed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @24_449ed0
  p1_ = edi;  // @25_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @27_449ed0
  ecx = edx = 0;  // @28_449ed0
  L449f47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_449ed0
  ecx = esi;  // @31_449ed0
  p2_ = edi;  // @32_449ed0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 560)))(ecx, (u32)(p2_), (u32)(1));  // @33_449ed0
  ecx = edx = 0;  // @34_449ed0
  SEH_LEAVE();  // @35_449ed0
  return eax;  // @36_449ed0
}
PCREG(449ed0, lifted_449ed0);

extern "C" u32 THISCALL lifted_453b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_453b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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
  p0_ = edi;  // @19_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(p0_));  // @21_453b50
  ecx = edx = 0;  // @22_453b50
  if ((eax & eax) != 0) goto L453bd8;  // @23_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; });  // @24_453b50
  p1_ = edi;  // @25_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @27_453b50
  ecx = edx = 0;  // @28_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_453b50
  p2_ = edi;  // @30_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p2_));  // @33_453b50
  ecx = edx = 0;  // @34_453b50
  L453bd8:;
  SEH_LEAVE();  // @36_453b50
  return eax;  // @37_453b50
}
PCREG(453b50, lifted_453b50);

extern "C" u32 THISCALL lifted_5ebbd0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5ebbd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
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
  p0_ = eax;  // @22_5ebbd0
  p1_ = ecx;  // @23_5ebbd0
  ecx = (u32)(edi + 98);  // @24_5ebbd0
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @25_5ebbd0
  ecx = edx = 0;  // @26_5ebbd0
  L5ebc56:;
  { u32 v = (u32)((u32)(7012828)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @28_5ebbd0
  SEH_LEAVE();  // @29_5ebbd0
  return eax;  // @30_5ebbd0
}
PCREG(5ebbd0, lifted_5ebbd0);

extern "C" u32 THISCALL lifted_45a5a0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_45a5a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @1_45a5a0
  { u32 v = (u32)((u32)(6831020)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_45a5a0
  if ((ecx & ecx) == 0) goto L45a61e;  // @3_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45a5a0
  edx = (u32)(EBP - 24);  // @5_45a5a0
  p0_ = edx;  // @6_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @7_45a5a0
  ecx = edx = 0;  // @8_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @9_45a5a0
  edx = (u32)(EBP - 24);  // @10_45a5a0
  p1_ = edx;  // @11_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @13_45a5a0
  ecx = edx = 0;  // @14_45a5a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L45a611;  // @15_45a5a0
  L45a5f0:;
  if ((eax & eax) == 0) goto L45a5ff;  // @17_45a5a0
  p2_ = eax;  // @18_45a5a0
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(1));  // @19_45a5a0
  ecx = edx = 0;  // @20_45a5a0
  L45a5ff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @22_45a5a0
  edx = (u32)(EBP - 24);  // @23_45a5a0
  p3_ = edx;  // @24_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @26_45a5a0
  ecx = edx = 0;  // @27_45a5a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L45a5f0;  // @28_45a5a0
  L45a611:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @30_45a5a0
  if ((ecx & ecx) == 0) goto L45a61e;  // @31_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @33_45a5a0
  ecx = edx = 0;  // @34_45a5a0
  L45a61e:;
  ecx = esi;  // @36_45a5a0
  eax = ext_43de70_thiscall1(ecx);  // @37_45a5a0
  ecx = edx = 0;  // @38_45a5a0
  SEH_LEAVE();  // @39_45a5a0
  return eax;  // @40_45a5a0
}
PCREG(45a5a0, lifted_45a5a0);

extern "C" u32 THISCALL lifted_6012e0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_6012e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  p0_ = edi;  // @26_6012e0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(4));  // @27_6012e0
  ecx = edx = 0;  // @28_6012e0
  L601352:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L601317;  // @30_6012e0
  L601358:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @32_6012e0
  ecx = edx = 0;  // @33_6012e0
  { u32 v = (u32)((u32)(7046312)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @34_6012e0
  SEH_LEAVE();  // @35_6012e0
  return eax;  // @36_6012e0
}
PCREG(6012e0, lifted_6012e0);

extern "C" u32 THISCALL lifted_435920(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66588e);  // @h_435920
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  p0_ = edx;  // @31_435920
  reg.state = (s32)((u32)(4294967295));  // @32_435920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_435920
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p0_));  // @34_435920
  ecx = edx = 0;  // @35_435920
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @36_435920
  SEH_LEAVE();  // @37_435920
  return eax;  // @38_435920
}
PCREG(435920, lifted_435920);

extern "C" u32 THISCALL lifted_5898c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_5898c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = eax;  // @11_5898c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p0_), (u32)(1));  // @12_5898c0
  ecx = edx = 0;  // @13_5898c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_5898c0
  ecx = eax;  // @15_5898c0
  reg.state = (s32)((u32)(0));  // @16_5898c0
  eax = ext_4cc1d0_thiscall1(ecx);  // @17_5898c0
  ecx = edx = 0;  // @18_5898c0
  p1_ = eax;  // @19_5898c0
  p2_ = edi;  // @20_5898c0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p2_), (u32)(6995992), (u32)(p1_));  // @21_5898c0
  ecx = edx = 0;  // @22_5898c0
  ecx = (u32)(EBP - 144);  // @23_5898c0
  eax = ext_4cbec0_thiscall1(ecx);  // @24_5898c0
  ecx = edx = 0;  // @25_5898c0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @26_5898c0
  goto L589955;  // @27_5898c0
  L58994d:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 4), &v, sizeof v); }  // @29_5898c0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @30_5898c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @31_5898c0
  L589955:;
  SEH_LEAVE();  // @33_5898c0
  ext_633654(G(u32, 0x6f5630));  // @34_5898c0
  return eax;  // @35_5898c0
}
PCREG(5898c0, lifted_5898c0);

extern "C" u32 STDCALL lifted_42da80(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_42da80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_42da80
  ecx = edi;  // @1_42da80
  eax = ext_4cc1d0_thiscall1(ecx);  // @2_42da80
  ecx = edx = 0;  // @3_42da80
  esi = eax;  // @4_42da80
  edx = esi;  // @5_42da80
  eax = (u32)(edx + 1);  // @6_42da80
  L42dac0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @8_42da80
  edx = (edx + 1);  // @9_42da80
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L42dac0;  // @10_42da80
  edx = (edx - eax);  // @11_42da80
  if (edx == 0) goto L42db16;  // @12_42da80
  eax = 0;  // @13_42da80
  L42dad0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(47)) goto L42dada;  // @15_42da80
  { u8 v = (u8)((u32)(92)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @16_42da80
  L42dada:;
  eax = (eax + 1);  // @18_42da80
  if (eax != edx) goto L42dad0;  // @19_42da80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi - 1), sizeof v); (u32)v; }) == (u32)(92)) goto L42db16;  // @20_42da80
  ecx = (u32)(EBP - 144);  // @21_42da80
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @22_42da80
  ecx = edx = 0;  // @23_42da80
  eax = (u32)(EBP - 144);  // @24_42da80
  reg.state = (s32)((u32)(0));  // @25_42da80
  p0_ = eax;  // @26_42da80
  ecx = edi;  // @27_42da80
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p0_));  // @28_42da80
  ecx = edx = 0;  // @29_42da80
  ecx = (u32)(EBP - 144);  // @30_42da80
  eax = ext_4cbec0_thiscall1(ecx);  // @31_42da80
  ecx = edx = 0;  // @32_42da80
  L42db16:;
  SEH_LEAVE();  // @34_42da80
  ext_633654(G(u32, 0x6f5630));  // @35_42da80
  return eax;  // @36_42da80
}
PCREG(42da80, lifted_42da80);

extern "C" u32 THISCALL lifted_42d600(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664e7e);  // @h_42d600
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = eax;  // @11_42d600
  ecx = (u32)(EBP - 24);  // @12_42d600
  eax = ext_5f10c0_thiscall2(ecx, (u32)(p0_));  // @13_42d600
  ecx = edx = 0;  // @14_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_42d600
  reg.state = (s32)((u32)(0));  // @16_42d600
  eax = ext_5f2c60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @17_42d600
  ecx = edx = 0;  // @18_42d600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @19_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_42d600
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d67b;  // @21_42d600
  eax = (u32)(ecx + 12);  // @22_42d600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @23_42d600
  L42d67b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @25_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @26_42d600
  eax = (eax - ecx);  // @27_42d600
  reg.state = (s32)((u32)(1));  // @28_42d600
  if ((ecx & ecx) == 0) goto L42d69c;  // @29_42d600
  if ((eax & eax) == 0) goto L42d69c;  // @30_42d600
  p1_ = eax;  // @31_42d600
  p2_ = ecx;  // @32_42d600
  ecx = (u32)(EBP - 24);  // @33_42d600
  eax = ext_54f870_stdcall2((u32)(p2_), (u32)(p1_));  // @34_42d600
  ecx = edx = 0;  // @35_42d600
  L42d69c:;
  SEH_LEAVE();  // @37_42d600
  return eax;  // @38_42d600
}
PCREG(42d600, lifted_42d600);

extern "C" u32 THISCALL lifted_47f760(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_47f760
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_47f760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @1_47f760
  reg.state = (s32)((u32)(0));  // @2_47f760
  { u32 v = (u32)((u32)(6860620)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_47f760
  if ((edx & edx) == 0) goto L47f7ba;  // @4_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_47f760
  p0_ = edx;  // @6_47f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_47f760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p0_));  // @9_47f760
  ecx = edx = 0;  // @10_47f760
  if ((eax & eax) == 0) goto L47f7ba;  // @11_47f760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_47f760
  ecx = eax;  // @13_47f760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @14_47f760
  ecx = edx = 0;  // @15_47f760
  L47f7ba:;
  ecx = esi;  // @17_47f760
  eax = ext_43de70_thiscall1(ecx);  // @18_47f760
  ecx = edx = 0;  // @19_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @20_47f760
  if (((eax & 0xff) & (u32)(1)) == 0) goto L47f7f4;  // @21_47f760
  if (((eax & 0xff) & (u32)(4)) != 0) goto L47f7e9;  // @22_47f760
  p1_ = esi;  // @23_47f760
  eax = ext_45c510_cdecl1((u32)(p1_));  // @24_47f760
  ecx = edx = 0;  // @25_47f760
  eax = esi;  // @26_47f760
  SEH_LEAVE();  // @27_47f760
  return eax;  // @28_47f760
  L47f7e9:;
  p2_ = esi;  // @30_47f760
  eax = ext_4690b0_cdecl2((u32)(p2_), (u32)(28));  // @31_47f760
  ecx = edx = 0;  // @32_47f760
  L47f7f4:;
  eax = esi;  // @34_47f760
  SEH_LEAVE();  // @35_47f760
  return eax;  // @36_47f760
}
PCREG(47f760, lifted_47f760);

extern "C" u32 THISCALL lifted_465660(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_465660
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = edi;  // @12_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @13_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(p0_));  // @15_465660
  ecx = edx = 0;  // @16_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_465660
  esi = eax;  // @18_465660
  p1_ = esi;  // @19_465660
  ecx = ebx;  // @20_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 556)))(ecx, (u32)(p1_));  // @21_465660
  ecx = edx = 0;  // @22_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @23_465660
  p2_ = esi;  // @24_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p2_));  // @26_465660
  ecx = edx = 0;  // @27_465660
  L4656df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 462), sizeof v); (u32)v; });  // @29_465660
  if ((ecx & ecx) == 0) goto L4656ef;  // @30_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @32_465660
  ecx = edx = 0;  // @33_465660
  L4656ef:;
  ecx = edi;  // @35_465660
  eax = ext_460f90_thiscall1(ecx);  // @36_465660
  ecx = edx = 0;  // @37_465660
  SEH_LEAVE();  // @38_465660
  return eax;  // @39_465660
}
PCREG(465660, lifted_465660);

extern "C" u32 lifted_4216f0(void) {
  SEH_ENTER(0x664311);  // @h_4216f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_4cb410(u32 ecx_in) {
  SEH_ENTER(0x6691af);  // @h_4cb410
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4cb410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4cb410
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4cb410
  ecx = edx = 0;  // @5_4cb410
  ecx = (u32)(EBP - 16);  // @6_4cb410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_4cb410
  p0_ = ecx;  // @8_4cb410
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_4cb410
  ecx = eax;  // @10_4cb410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6903412), (u32)(p0_));  // @11_4cb410
  ecx = edx = 0;  // @12_4cb410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @13_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4cb410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @15_4cb410
  ecx = edx = 0;  // @16_4cb410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @17_4cb410
  edi = eax;  // @18_4cb410
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) != (u32)(0)) goto L4cb4b3;  // @19_4cb410
  eax = ext_41e290_cdecl1((u32)(28));  // @20_4cb410
  ecx = edx = 0;  // @21_4cb410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @22_4cb410
  reg.state = (s32)((u32)(0));  // @23_4cb410
  if ((eax & eax) == 0) goto L4cb4a7;  // @24_4cb410
  ecx = eax;  // @25_4cb410
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(0));  // @26_4cb410
  ecx = edx = 0;  // @27_4cb410
  goto L4cb4a9;  // @28_4cb410
  L4cb4a7:;
  eax = 0;  // @30_4cb410
  L4cb4a9:;
  reg.state = (s32)((u32)(4294967295));  // @32_4cb410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @33_4cb410
  L4cb4b3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @35_4cb410
  p1_ = esi;  // @36_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4cb410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @38_4cb410
  ecx = edx = 0;  // @39_4cb410
  SEH_LEAVE();  // @40_4cb410
  return eax;  // @41_4cb410
}
PCREG(4cb410, lifted_4cb410);

extern "C" u32 THISCALL lifted_4ccc30(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x669258);  // @h_4ccc30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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

extern "C" u32 THISCALL lifted_4d16e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66930f);  // @h_4d16e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_4d16e0
  eax = ext_41e290_cdecl1((u32)(20));  // @1_4d16e0
  ecx = edx = 0;  // @2_4d16e0
  edi = eax;  // @3_4d16e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4d16e0
  reg.state = (s32)((u32)(0));  // @5_4d16e0
  if ((edi & edi) == 0) goto L4d176e;  // @6_4d16e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_4d16e0
  edx = (u32)(ecx + 1);  // @8_4d16e0
  L4d1728:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @10_4d16e0
  ecx = (ecx + 1);  // @11_4d16e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d1728;  // @12_4d16e0
  ecx = (ecx - edx);  // @13_4d16e0
  esi = (u32)(ecx + 1);  // @14_4d16e0
  p0_ = esi;  // @15_4d16e0
  eax = ext_41e290_cdecl1((u32)(p0_));  // @16_4d16e0
  ecx = edx = 0;  // @17_4d16e0
  p1_ = esi;  // @18_4d16e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @19_4d16e0
  p2_ = eax;  // @20_4d16e0
  eax = ext_634d22_cdecl3((u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p1_));  // @21_4d16e0
  ecx = edx = 0;  // @22_4d16e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @23_4d16e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @24_4d16e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @25_4d16e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @26_4d16e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @27_4d16e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @28_4d16e0
  if ((eax & eax) == 0) goto L4d1768;  // @29_4d16e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @30_4d16e0
  goto L4d176b;  // @31_4d16e0
  L4d1768:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @33_4d16e0
  L4d176b:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @35_4d16e0
  L4d176e:;
  SEH_LEAVE();  // @37_4d16e0
  return eax;  // @38_4d16e0
}
PCREG(4d16e0, lifted_4d16e0);

extern "C" u32 THISCALL lifted_444df0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66825f);  // @h_444df0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_444df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @1_444df0
  if ((ecx & ecx) != 0) goto L444e63;  // @2_444df0
  eax = ext_41e290_cdecl1((u32)(28));  // @3_444df0
  ecx = edx = 0;  // @4_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_444df0
  reg.state = (s32)((u32)(0));  // @6_444df0
  if ((eax & eax) == 0) goto L444e52;  // @7_444df0
  ecx = eax;  // @8_444df0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @9_444df0
  ecx = edx = 0;  // @10_444df0
  reg.state = (s32)((u32)(4294967295));  // @11_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @12_444df0
  goto L444e6f;  // @13_444df0
  L444e52:;
  eax = 0;  // @15_444df0
  reg.state = (s32)((u32)(4294967295));  // @16_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @17_444df0
  goto L444e6f;  // @18_444df0
  L444e63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @21_444df0
  ecx = edx = 0;  // @22_444df0
  if ((eax & eax) != 0) goto L444e9c;  // @23_444df0
  L444e6f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @25_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @27_444df0
  ecx = edx = 0;  // @28_444df0
  L444e80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @30_444df0
  eax = ext_4dc630_thiscall3(ecx, (u32)(4194304), (u32)(0));  // @31_444df0
  ecx = edx = 0;  // @32_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_444df0
  ecx = esi;  // @34_444df0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @35_444df0
  ecx = edx = 0;  // @36_444df0
  esi = eax;  // @37_444df0
  if ((esi & esi) != 0) goto L444e80;  // @38_444df0
  L444e9c:;
  SEH_LEAVE();  // @40_444df0
  return eax;  // @41_444df0
}
PCREG(444df0, lifted_444df0);

extern "C" u32 THISCALL lifted_5f2910(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d018);  // @h_5f2910
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
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
  p0_ = eax;  // @11_5f2910
  ecx = edi;  // @12_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 92)))(ecx, (u32)(p0_));  // @13_5f2910
  ecx = edx = 0;  // @14_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @15_5f2910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_5f2910
  ecx = eax;  // @17_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 152), sizeof v); (u32)v; }));  // @18_5f2910
  ecx = edx = 0;  // @19_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @20_5f2910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_5f2910
  ecx = eax;  // @22_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 156), sizeof v); (u32)v; }));  // @23_5f2910
  ecx = edx = 0;  // @24_5f2910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @25_5f2910
  { u32 v = (u32)((u32)(7046532)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @26_5f2910
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 19), &v, sizeof v); }  // @27_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @28_5f2910
  eax = (u32)(EBP - 40);  // @29_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @30_5f2910
  { u32 v = (u32)((u32)(1000000)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @31_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @32_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @33_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @34_5f2910
  p1_ = eax;  // @35_5f2910
  reg.state = (s32)((u32)(0));  // @36_5f2910
  eax = ext_5fd7c0_thiscall2(ecx, (u32)(p1_));  // @37_5f2910
  ecx = edx = 0;  // @38_5f2910
  ecx = (u32)(EBP - 40);  // @39_5f2910
  eax = ext_602240_thiscall1(ecx);  // @40_5f2910
  ecx = edx = 0;  // @41_5f2910
  SEH_LEAVE();  // @42_5f2910
  return eax;  // @43_5f2910
}
PCREG(5f2910, lifted_5f2910);

extern "C" u32 THISCALL lifted_436ec0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_436ec0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_436ec0
  if ((eax & eax) == 0) goto L436efa;  // @2_436ec0
  p0_ = eax;  // @3_436ec0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(1));  // @4_436ec0
  ecx = edx = 0;  // @5_436ec0
  L436efa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @7_436ec0
  if ((ecx & ecx) == 0) goto L436f4e;  // @8_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_436ec0
  edx = (u32)(EBP - 24);  // @10_436ec0
  p1_ = edx;  // @11_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @12_436ec0
  ecx = edx = 0;  // @13_436ec0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @14_436ec0
  edx = (u32)(EBP - 24);  // @15_436ec0
  p2_ = edx;  // @16_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @18_436ec0
  ecx = edx = 0;  // @19_436ec0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L436f41;  // @20_436ec0
  L436f20:;
  if ((eax & eax) == 0) goto L436f2f;  // @22_436ec0
  p3_ = eax;  // @23_436ec0
  eax = ext_634273_cdecl2((u32)(p3_), (u32)(1));  // @24_436ec0
  ecx = edx = 0;  // @25_436ec0
  L436f2f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @27_436ec0
  edx = (u32)(EBP - 24);  // @28_436ec0
  p4_ = edx;  // @29_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p4_));  // @31_436ec0
  ecx = edx = 0;  // @32_436ec0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L436f20;  // @33_436ec0
  L436f41:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @35_436ec0
  if ((ecx & ecx) == 0) goto L436f4e;  // @36_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @38_436ec0
  ecx = edx = 0;  // @39_436ec0
  L436f4e:;
  SEH_LEAVE();  // @41_436ec0
  return eax;  // @42_436ec0
}
PCREG(436ec0, lifted_436ec0);

extern "C" u32 THISCALL lifted_441d90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_441d90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = edi;  // @19_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_441d90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p0_));  // @21_441d90
  ecx = edx = 0;  // @22_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_441d90
  ecx = edi;  // @24_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 776), sizeof v); (u32)v; });  // @25_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @26_441d90
  ecx = edx = 0;  // @27_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e12;  // @28_441d90
  p1_ = edi;  // @29_441d90
  ecx = esi;  // @30_441d90
  eax = ext_442050_thiscall2(ecx, (u32)(p1_));  // @31_441d90
  ecx = edx = 0;  // @32_441d90
  L441e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_441d90
  ecx = edi;  // @35_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @36_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @37_441d90
  ecx = edx = 0;  // @38_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e2a;  // @39_441d90
  p2_ = edi;  // @40_441d90
  ecx = esi;  // @41_441d90
  eax = ext_441e40_thiscall2(ecx, (u32)(p2_));  // @42_441d90
  ecx = edx = 0;  // @43_441d90
  L441e2a:;
  SEH_LEAVE();  // @45_441d90
  return eax;  // @46_441d90
}
PCREG(441d90, lifted_441d90);

extern "C" u32 THISCALL lifted_45cb50(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666666);  // @h_45cb50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = edi;  // @12_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_45cb50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 468)))(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @14_45cb50
  ecx = edx = 0;  // @15_45cb50
  ecx = (u32)(EBP - 144);  // @16_45cb50
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @17_45cb50
  ecx = edx = 0;  // @18_45cb50
  eax = (u32)(EBP - 144);  // @19_45cb50
  reg.state = (s32)((u32)(0));  // @20_45cb50
  p1_ = eax;  // @21_45cb50
  ecx = edi;  // @22_45cb50
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p1_));  // @23_45cb50
  ecx = edx = 0;  // @24_45cb50
  ecx = (u32)(EBP - 144);  // @25_45cb50
  reg.state = (s32)((u32)(4294967295));  // @26_45cb50
  eax = ext_4cbec0_thiscall1(ecx);  // @27_45cb50
  ecx = edx = 0;  // @28_45cb50
  L45cbee:;
  ecx = (u32)(EBP - 272);  // @30_45cb50
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @31_45cb50
  ecx = edx = 0;  // @32_45cb50
  eax = (u32)(EBP - 272);  // @33_45cb50
  reg.state = (s32)((u32)(1));  // @34_45cb50
  p2_ = eax;  // @35_45cb50
  ecx = edi;  // @36_45cb50
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p2_));  // @37_45cb50
  ecx = edx = 0;  // @38_45cb50
  ecx = (u32)(EBP - 272);  // @39_45cb50
  eax = ext_4cbec0_thiscall1(ecx);  // @40_45cb50
  ecx = edx = 0;  // @41_45cb50
  SEH_LEAVE();  // @42_45cb50
  ext_633654(G(u32, 0x6f5630));  // @43_45cb50
  return eax;  // @44_45cb50
}
PCREG(45cb50, lifted_45cb50);

extern "C" u32 THISCALL lifted_644900(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e95f);  // @h_644900
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_644900
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_644900
  eax = (u32)(ebx + 58);  // @2_644900
  p0_ = eax;  // @3_644900
  ecx = edi;  // @4_644900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p0_));  // @6_644900
  ecx = edx = 0;  // @7_644900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_644900
  eax = (u32)(ebx + 8);  // @9_644900
  p1_ = eax;  // @10_644900
  ecx = edi;  // @11_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p1_));  // @12_644900
  ecx = edx = 0;  // @13_644900
  eax = ext_41e290_cdecl1((u32)(101));  // @14_644900
  ecx = edx = 0;  // @15_644900
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @16_644900
  reg.state = (s32)((u32)(0));  // @17_644900
  if ((eax & eax) == 0) goto L644961;  // @18_644900
  ecx = eax;  // @19_644900
  eax = ext_540ed0_thiscall1(ecx);  // @20_644900
  ecx = edx = 0;  // @21_644900
  goto L644963;  // @22_644900
  L644961:;
  eax = 0;  // @24_644900
  L644963:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 383), &v, sizeof v); }  // @26_644900
  esi = (u32)(ebx + 21);  // @27_644900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_644900
  ecx = edi;  // @29_644900
  p2_ = esi;  // @30_644900
  reg.state = (s32)((u32)(4294967295));  // @31_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p2_));  // @32_644900
  ecx = edx = 0;  // @33_644900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_644900
  ecx = (u32)(ebx + 62);  // @35_644900
  p3_ = ecx;  // @36_644900
  ecx = edi;  // @37_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p3_));  // @38_644900
  ecx = edx = 0;  // @39_644900
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(0)) goto L64499d;  // @40_644900
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 62), sizeof v); (u32)v; }) == (u32)(0)) goto L64499d;  // @41_644900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 383), sizeof v); (u32)v; });  // @42_644900
  p4_ = edi;  // @43_644900
  eax = ext_545ee0_thiscall2(ecx, (u32)(p4_));  // @44_644900
  ecx = edx = 0;  // @45_644900
  L64499d:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @47_644900
  SEH_LEAVE();  // @48_644900
  return eax;  // @49_644900
}
PCREG(644900, lifted_644900);

extern "C" u32 THISCALL lifted_430010(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66528c);  // @h_430010
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
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
  p0_ = eax;  // @16_430010
  p1_ = edx;  // @17_430010
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @18_430010
  ecx = edx = 0;  // @19_430010
  L43006f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @21_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @22_430010
  eax = (eax - edx);  // @23_430010
  reg.state = (s32)((u32)(1));  // @24_430010
  if ((edx & edx) == 0) goto L430090;  // @25_430010
  if ((eax & eax) == 0) goto L430090;  // @26_430010
  p2_ = eax;  // @27_430010
  p3_ = edx;  // @28_430010
  ecx = (u32)(esi + 13);  // @29_430010
  eax = ext_54f870_stdcall2((u32)(p3_), (u32)(p2_));  // @30_430010
  ecx = edx = 0;  // @31_430010
  L430090:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @33_430010
  p4_ = esi;  // @34_430010
  reg.state = (s32)((u32)(4294967295));  // @35_430010
  eax = ext_54f870_stdcall2((u32)(p4_), (u32)(37));  // @36_430010
  ecx = edx = 0;  // @37_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @38_430010
  esi = ebx;  // @39_430010
  if ((ebx & ebx) != 0) goto L430042;  // @40_430010
  L4300ab:;
  SEH_LEAVE();  // @42_430010
  return eax;  // @43_430010
}
PCREG(430010, lifted_430010);

extern "C" u32 THISCALL lifted_4317a0(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4317a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4317a0
  { u32 v = (u32)((u32)(6790804)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @1_4317a0
  eax = ext_432be0_thiscall1(ecx);  // @2_4317a0
  ecx = edx = 0;  // @3_4317a0
  edi = (u32)(ebx + 172);  // @4_4317a0
  if ((edi & edi) == 0) goto L43182b;  // @5_4317a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @6_4317a0
  ecx = (u32)(EBP - 24);  // @7_4317a0
  p0_ = ecx;  // @8_4317a0
  ecx = edi;  // @9_4317a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @10_4317a0
  ecx = edx = 0;  // @11_4317a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_4317a0
  ecx = (u32)(EBP - 24);  // @13_4317a0
  p1_ = ecx;  // @14_4317a0
  ecx = edi;  // @15_4317a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @16_4317a0
  ecx = edx = 0;  // @17_4317a0
  if ((eax & eax) == 0) goto L43182b;  // @18_4317a0
  L431800:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @20_4317a0
  if ((esi & esi) == 0) goto L43181c;  // @21_4317a0
  ecx = esi;  // @22_4317a0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_4317a0
  ecx = edx = 0;  // @24_4317a0
  p2_ = esi;  // @25_4317a0
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(128));  // @26_4317a0
  ecx = edx = 0;  // @27_4317a0
  L43181c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_4317a0
  ecx = (u32)(EBP - 24);  // @30_4317a0
  p3_ = ecx;  // @31_4317a0
  ecx = edi;  // @32_4317a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @33_4317a0
  ecx = edx = 0;  // @34_4317a0
  if ((eax & eax) != 0) goto L431800;  // @35_4317a0
  L43182b:;
  ecx = (u32)(ebx + 200);  // @37_4317a0
  eax = ext_4cd0e0_thiscall1(ecx);  // @38_4317a0
  ecx = edx = 0;  // @39_4317a0
  ecx = edi;  // @40_4317a0
  eax = ext_4cd0e0_thiscall1(ecx);  // @41_4317a0
  ecx = edx = 0;  // @42_4317a0
  ecx = (u32)(ebx + 132);  // @43_4317a0
  eax = ext_4cce40_thiscall1(ecx);  // @44_4317a0
  ecx = edx = 0;  // @45_4317a0
  ecx = (u32)(ebx + 4);  // @46_4317a0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_4317a0
  ecx = edx = 0;  // @48_4317a0
  SEH_LEAVE();  // @49_4317a0
  return eax;  // @50_4317a0
}
PCREG(4317a0, lifted_4317a0);

extern "C" u32 THISCALL lifted_447690(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447690
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447690
  { u32 v = (u32)((u32)(6811248)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447690
  if ((ecx & ecx) == 0) goto L447714;  // @3_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447690
  edx = (u32)(EBP - 24);  // @5_447690
  p0_ = edx;  // @6_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @7_447690
  ecx = edx = 0;  // @8_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @9_447690
  edx = (u32)(EBP - 24);  // @10_447690
  p1_ = edx;  // @11_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @13_447690
  ecx = edx = 0;  // @14_447690
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L447714;  // @15_447690
  L4476e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_447690
  p2_ = eax;  // @18_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_447690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p2_));  // @21_447690
  ecx = edx = 0;  // @22_447690
  if ((eax & eax) == 0) goto L447702;  // @23_447690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_447690
  ecx = eax;  // @25_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @26_447690
  ecx = edx = 0;  // @27_447690
  L447702:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @29_447690
  edx = (u32)(EBP - 24);  // @30_447690
  p3_ = edx;  // @31_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @33_447690
  ecx = edx = 0;  // @34_447690
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4476e0;  // @35_447690
  L447714:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @37_447690
  if ((ecx & ecx) == 0) goto L447721;  // @38_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @40_447690
  ecx = edx = 0;  // @41_447690
  L447721:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @43_447690
  reg.state = (s32)((u32)(0));  // @44_447690
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_447690
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @46_447690
  ecx = edx = 0;  // @47_447690
  ecx = esi;  // @48_447690
  eax = ext_45c3e0_thiscall1(ecx);  // @49_447690
  ecx = edx = 0;  // @50_447690
  SEH_LEAVE();  // @51_447690
  return eax;  // @52_447690
}
PCREG(447690, lifted_447690);

extern "C" u32 THISCALL lifted_447750(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447750
  { u32 v = (u32)((u32)(6811840)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447750
  if ((ecx & ecx) == 0) goto L4477d4;  // @3_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447750
  edx = (u32)(EBP - 24);  // @5_447750
  p0_ = edx;  // @6_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @7_447750
  ecx = edx = 0;  // @8_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @9_447750
  edx = (u32)(EBP - 24);  // @10_447750
  p1_ = edx;  // @11_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @13_447750
  ecx = edx = 0;  // @14_447750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4477d4;  // @15_447750
  L4477a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_447750
  p2_ = eax;  // @18_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_447750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p2_));  // @21_447750
  ecx = edx = 0;  // @22_447750
  if ((eax & eax) == 0) goto L4477c2;  // @23_447750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_447750
  ecx = eax;  // @25_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @26_447750
  ecx = edx = 0;  // @27_447750
  L4477c2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @29_447750
  edx = (u32)(EBP - 24);  // @30_447750
  p3_ = edx;  // @31_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @33_447750
  ecx = edx = 0;  // @34_447750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4477a0;  // @35_447750
  L4477d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @37_447750
  if ((ecx & ecx) == 0) goto L4477e1;  // @38_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @40_447750
  ecx = edx = 0;  // @41_447750
  L4477e1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @43_447750
  reg.state = (s32)((u32)(0));  // @44_447750
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_447750
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @46_447750
  ecx = edx = 0;  // @47_447750
  ecx = esi;  // @48_447750
  eax = ext_45c3e0_thiscall1(ecx);  // @49_447750
  ecx = edx = 0;  // @50_447750
  SEH_LEAVE();  // @51_447750
  return eax;  // @52_447750
}
PCREG(447750, lifted_447750);

extern "C" u32 THISCALL lifted_447810(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447810
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447810
  { u32 v = (u32)((u32)(6812432)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447810
  if ((ecx & ecx) == 0) goto L447894;  // @3_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447810
  edx = (u32)(EBP - 24);  // @5_447810
  p0_ = edx;  // @6_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @7_447810
  ecx = edx = 0;  // @8_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @9_447810
  edx = (u32)(EBP - 24);  // @10_447810
  p1_ = edx;  // @11_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @13_447810
  ecx = edx = 0;  // @14_447810
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L447894;  // @15_447810
  L447860:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_447810
  p2_ = eax;  // @18_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_447810
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p2_));  // @21_447810
  ecx = edx = 0;  // @22_447810
  if ((eax & eax) == 0) goto L447882;  // @23_447810
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_447810
  ecx = eax;  // @25_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @26_447810
  ecx = edx = 0;  // @27_447810
  L447882:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @29_447810
  edx = (u32)(EBP - 24);  // @30_447810
  p3_ = edx;  // @31_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @33_447810
  ecx = edx = 0;  // @34_447810
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L447860;  // @35_447810
  L447894:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @37_447810
  if ((ecx & ecx) == 0) goto L4478a1;  // @38_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @40_447810
  ecx = edx = 0;  // @41_447810
  L4478a1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @43_447810
  reg.state = (s32)((u32)(0));  // @44_447810
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_447810
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @46_447810
  ecx = edx = 0;  // @47_447810
  ecx = esi;  // @48_447810
  eax = ext_45c3e0_thiscall1(ecx);  // @49_447810
  ecx = edx = 0;  // @50_447810
  SEH_LEAVE();  // @51_447810
  return eax;  // @52_447810
}
PCREG(447810, lifted_447810);

extern "C" u32 THISCALL lifted_4269e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6685bb);  // @h_4269e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
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
  p0_ = edx;  // @11_4269e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4269e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, (u32)(p0_));  // @13_4269e0
  ecx = edx = 0;  // @14_4269e0
  p1_ = eax;  // @15_4269e0
  ecx = ebx;  // @16_4269e0
  reg.state = (s32)((u32)(0));  // @17_4269e0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @18_4269e0
  ecx = edx = 0;  // @19_4269e0
  ecx = (u32)(EBP - 144);  // @20_4269e0
  reg.state = (s32)((u32)(4294967295));  // @21_4269e0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_4269e0
  ecx = edx = 0;  // @23_4269e0
  L426a63:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4269e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4269e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @27_4269e0
  ecx = edx = 0;  // @28_4269e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @29_4269e0
  esi = eax;  // @30_4269e0
  ecx = (ecx + (u32)(140));  // @31_4269e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_4269e0
  eax = ext_4cc1d0_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @33_4269e0
  ecx = edx = 0;  // @34_4269e0
  p2_ = eax;  // @35_4269e0
  ecx = ebx;  // @36_4269e0
  eax = ext_4cc1d0_cdecl1((u32)(p2_));  // @37_4269e0
  ecx = edx = 0;  // @38_4269e0
  p3_ = eax;  // @39_4269e0
  p4_ = esi;  // @40_4269e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edi + 408)))(ecx, (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }), (u32)(6786332), (u32)(p3_));  // @41_4269e0
  ecx = edx = 0;  // @42_4269e0
  SEH_LEAVE();  // @43_4269e0
  ext_633654(G(u32, 0x6f5630));  // @44_4269e0
  return eax;  // @45_4269e0
}
PCREG(4269e0, lifted_4269e0);

extern "C" u32 THISCALL lifted_5082c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_5082c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = eax;  // @14_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6932144), (u32)(6932912));  // @16_5082c0
  ecx = edx = 0;  // @17_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_5082c0
  if ((eax & eax) == 0) goto L508340;  // @19_5082c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_5082c0
  ecx = edx = 0;  // @21_5082c0
  eax = 0;  // @22_5082c0
  goto L508350;  // @23_5082c0
  L508340:;
  __builtin_trap();  // @25_5082c0
  L508345:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5082c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @29_5082c0
  ecx = edx = 0;  // @30_5082c0
  goto L508350;  // @31_5082c0
  L50834e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5082c0
  L508350:;
  p1_ = eax;  // @35_5082c0
  ecx = (u32)(EBP - 144);  // @36_5082c0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @37_5082c0
  ecx = edx = 0;  // @38_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @39_5082c0
  eax = (u32)(EBP - 144);  // @40_5082c0
  p2_ = eax;  // @41_5082c0
  ecx = (ecx + (u32)(1042));  // @42_5082c0
  reg.state = (s32)((u32)(0));  // @43_5082c0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @44_5082c0
  ecx = edx = 0;  // @45_5082c0
  ecx = (u32)(EBP - 144);  // @46_5082c0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_5082c0
  ecx = edx = 0;  // @48_5082c0
  SEH_LEAVE();  // @49_5082c0
  ext_633654(G(u32, 0x6f5630));  // @50_5082c0
  return eax;  // @51_5082c0
}
PCREG(5082c0, lifted_5082c0);

extern "C" u32 STDCALL lifted_48f5e0(u32 a0) {
  SEH_ENTER(0x667c5b);  // @h_48f5e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_48f5e0
  esi = (u32)(1);  // @1_48f5e0
  L48f620:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_48f5e0
  edx = (u32)(EBP - 1168);  // @4_48f5e0
  p0_ = edx;  // @5_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_48f5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, (u32)(p0_));  // @7_48f5e0
  ecx = edx = 0;  // @8_48f5e0
  p1_ = esi;  // @9_48f5e0
  p2_ = edi;  // @10_48f5e0
  ecx = eax;  // @11_48f5e0
  reg.state = (s32)((u32)(0));  // @12_48f5e0
  eax = ext_4cc1d0_cdecl2((u32)(p2_), (u32)(p1_));  // @13_48f5e0
  ecx = edx = 0;  // @14_48f5e0
  p3_ = eax;  // @15_48f5e0
  eax = (u32)(EBP - 1040);  // @16_48f5e0
  p4_ = eax;  // @17_48f5e0
  eax = ext_42ac56_cdecl3((u32)(p4_), (u32)(6871000), (u32)(p3_));  // @18_48f5e0
  ecx = edx = 0;  // @19_48f5e0
  reg.state = (s32)((u32)(4294967295));  // @20_48f5e0
  ecx = (u32)(EBP - 1168);  // @21_48f5e0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_48f5e0
  ecx = edx = 0;  // @23_48f5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @24_48f5e0
  edx = (u32)(EBP - 1040);  // @25_48f5e0
  p5_ = edx;  // @26_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_48f5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p5_));  // @28_48f5e0
  ecx = edx = 0;  // @29_48f5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @30_48f5e0
  edx = (u32)(EBP - 1040);  // @31_48f5e0
  p6_ = edx;  // @32_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @34_48f5e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p6_), (u32)(0));  // @35_48f5e0
  ecx = edx = 0;  // @36_48f5e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L48f6a2;  // @37_48f5e0
  esi = (esi + 1);  // @38_48f5e0
  if ((s32)esi <= (s32)(u32)(3)) goto L48f620;  // @39_48f5e0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @40_48f5e0
  goto L48f6a4;  // @41_48f5e0
  L48f6a2:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @43_48f5e0
  L48f6a4:;
  SEH_LEAVE();  // @45_48f5e0
  ext_633654(G(u32, 0x6f5630));  // @46_48f5e0
  return eax;  // @47_48f5e0
}
PCREG(48f5e0, lifted_48f5e0);

extern "C" u32 THISCALL lifted_4385e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66606f);  // @h_4385e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4385e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 62), sizeof v); (u32)v; }) != (u32)(0)) goto L43863e;  // @1_4385e0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_4385e0
  ecx = edx = 0;  // @3_4385e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4385e0
  reg.state = (s32)((u32)(0));  // @5_4385e0
  if ((eax & eax) == 0) goto L438632;  // @6_4385e0
  ecx = eax;  // @7_4385e0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(2));  // @8_4385e0
  ecx = edx = 0;  // @9_4385e0
  goto L438634;  // @10_4385e0
  L438632:;
  eax = 0;  // @12_4385e0
  L438634:;
  reg.state = (s32)((u32)(4294967295));  // @14_4385e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 62), &v, sizeof v); }  // @15_4385e0
  L43863e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 62), sizeof v); (u32)v; });  // @17_4385e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4385e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @19_4385e0
  ecx = edx = 0;  // @20_4385e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_4385e0
  edi = eax;  // @22_4385e0
  ecx = esi;  // @23_4385e0
  edx = (u32)(ecx + 1);  // @24_4385e0
  L438652:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @26_4385e0
  ecx = (ecx + 1);  // @27_4385e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L438652;  // @28_4385e0
  ecx = (ecx - edx);  // @29_4385e0
  eax = (u32)(ecx + 1);  // @30_4385e0
  p0_ = eax;  // @31_4385e0
  eax = ext_41e290_cdecl1((u32)(p0_));  // @32_4385e0
  ecx = edx = 0;  // @33_4385e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @34_4385e0
  L438670:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @36_4385e0
  esi = (u32)(esi + 1);  // @37_4385e0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @38_4385e0
  eax = (u32)(eax + 1);  // @39_4385e0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L438670;  // @40_4385e0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; })) & 0xff);  // @41_4385e0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @42_4385e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_4385e0
  SEH_LEAVE();  // @44_4385e0
  return eax;  // @45_4385e0
}
PCREG(4385e0, lifted_4385e0);

extern "C" u32 THISCALL lifted_5f97e0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_5f97e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
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
  p0_ = eax;  // @28_5f97e0
  p1_ = ecx;  // @29_5f97e0
  ecx = esi;  // @30_5f97e0
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @31_5f97e0
  ecx = edx = 0;  // @32_5f97e0
  L5f9859:;
  p2_ = esi;  // @34_5f97e0
  reg.state = (s32)((u32)(4294967295));  // @35_5f97e0
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(12));  // @36_5f97e0
  ecx = edx = 0;  // @37_5f97e0
  L5f986b:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }) != (u32)(0)) goto L5f9811;  // @39_5f97e0
  L5f9871:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }));  // @41_5f97e0
  ecx = edx = 0;  // @42_5f97e0
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @43_5f97e0
  ecx = edx = 0;  // @44_5f97e0
  SEH_LEAVE();  // @45_5f97e0
  return eax;  // @46_5f97e0
}
PCREG(5f97e0, lifted_5f97e0);

extern "C" u32 THISCALL lifted_57c6f0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66b1bb);  // @h_57c6f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
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
  p0_ = ecx;  // @12_57c6f0
  ecx = edi;  // @13_57c6f0
  reg.state = (s32)((u32)(0));  // @14_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p0_));  // @16_57c6f0
  ecx = edx = 0;  // @17_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @21_57c6f0
  ecx = edx = 0;  // @22_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @23_57c6f0
  esi = (u32)(ebx + 12);  // @24_57c6f0
  ebx = (u32)(8);  // @25_57c6f0
  L57c764:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_57c6f0
  ecx = (u32)(EBP + 12);  // @28_57c6f0
  p1_ = ecx;  // @29_57c6f0
  ecx = edi;  // @30_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p1_));  // @31_57c6f0
  ecx = edx = 0;  // @32_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @36_57c6f0
  ecx = edx = 0;  // @37_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @38_57c6f0
  esi = (u32)(esi + 4);  // @39_57c6f0
  ebx = (ebx - (u32)(1));  // @40_57c6f0
  if (ebx != 0) goto L57c764;  // @41_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_57c6f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @44_57c6f0
  ecx = edx = 0;  // @45_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @46_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @47_57c6f0
  eax = ecx;  // @48_57c6f0
  SEH_LEAVE();  // @49_57c6f0
  return eax;  // @50_57c6f0
}
PCREG(57c6f0, lifted_57c6f0);

extern "C" u32 THISCALL lifted_4d8fc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d1b);  // @h_4d8fc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4d8fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d8fc0
  ecx = (u32)(EBP - 144);  // @2_4d8fc0
  p0_ = eax;  // @3_4d8fc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_4d8fc0
  ecx = edx = 0;  // @5_4d8fc0
  ecx = (u32)(EBP - 144);  // @6_4d8fc0
  reg.state = (s32)((u32)(0));  // @7_4d8fc0
  eax = ext_4cc690_thiscall1(ecx);  // @8_4d8fc0
  ecx = edx = 0;  // @9_4d8fc0
  ecx = (u32)(EBP - 144);  // @10_4d8fc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @11_4d8fc0
  ecx = edx = 0;  // @12_4d8fc0
  edi = eax;  // @13_4d8fc0
  esi = edi;  // @14_4d8fc0
  eax = (u32)(esi + 1);  // @15_4d8fc0
  L4d9023:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @17_4d8fc0
  esi = (esi + 1);  // @18_4d8fc0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L4d9023;  // @19_4d8fc0
  esi = (esi - eax);  // @20_4d8fc0
  ecx = ebx;  // @21_4d8fc0
  p1_ = esi;  // @22_4d8fc0
  p2_ = edi;  // @23_4d8fc0
  eax = ext_4d8db0_stdcall2((u32)(p2_), (u32)(p1_));  // @24_4d8fc0
  ecx = edx = 0;  // @25_4d8fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4d8fc0
  p3_ = eax;  // @27_4d8fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4d8fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, (u32)(p3_));  // @29_4d8fc0
  ecx = edx = 0;  // @30_4d8fc0
  if ((eax & eax) == 0) goto L4d9054;  // @31_4d8fc0
  p4_ = esi;  // @32_4d8fc0
  p5_ = edi;  // @33_4d8fc0
  p6_ = eax;  // @34_4d8fc0
  ecx = ebx;  // @35_4d8fc0
  eax = ext_4d8ef0_stdcall3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @36_4d8fc0
  ecx = edx = 0;  // @37_4d8fc0
  if ((eax & eax) == 0) goto L4d9054;  // @38_4d8fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @39_4d8fc0
  goto L4d9056;  // @40_4d8fc0
  L4d9054:;
  esi = 0;  // @42_4d8fc0
  L4d9056:;
  ecx = (u32)(EBP - 144);  // @44_4d8fc0
  eax = ext_4cbec0_thiscall1(ecx);  // @45_4d8fc0
  ecx = edx = 0;  // @46_4d8fc0
  eax = esi;  // @47_4d8fc0
  SEH_LEAVE();  // @48_4d8fc0
  ext_633654(G(u32, 0x6f5630));  // @49_4d8fc0
  return eax;  // @50_4d8fc0
}
PCREG(4d8fc0, lifted_4d8fc0);

extern "C" u32 THISCALL lifted_43aa30(u32 ecx_in) {
  SEH_ENTER(0x6685bb);  // @h_43aa30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_43aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @1_43aa30
  if ((ecx & ecx) == 0) goto L43ab09;  // @2_43aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_43aa30
  edx = (u32)(EBP - 156);  // @4_43aa30
  p0_ = edx;  // @5_43aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_43aa30
  ecx = edx = 0;  // @7_43aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @8_43aa30
  edx = (u32)(EBP - 156);  // @9_43aa30
  p1_ = edx;  // @10_43aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_43aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @12_43aa30
  ecx = edx = 0;  // @13_43aa30
  edi = eax;  // @14_43aa30
  if ((edi & edi) == 0) goto L43aaef;  // @15_43aa30
  L43aaa0:;
  ecx = (u32)(EBP - 144);  // @17_43aa30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @18_43aa30
  ecx = edx = 0;  // @19_43aa30
  eax = (u32)(EBP - 144);  // @20_43aa30
  reg.state = (s32)((u32)(0));  // @21_43aa30
  p2_ = eax;  // @22_43aa30
  ecx = edi;  // @23_43aa30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @24_43aa30
  ecx = edx = 0;  // @25_43aa30
  ecx = (u32)(EBP - 144);  // @26_43aa30
  reg.state = (s32)((u32)(4294967295));  // @27_43aa30
  eax = ext_4cbec0_thiscall1(ecx);  // @28_43aa30
  ecx = edx = 0;  // @29_43aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @30_43aa30
  edx = (u32)(EBP - 156);  // @31_43aa30
  p3_ = edx;  // @32_43aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_43aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @34_43aa30
  ecx = edx = 0;  // @35_43aa30
  edi = eax;  // @36_43aa30
  if ((edi & edi) != 0) goto L43aaa0;  // @37_43aa30
  L43aaef:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @39_43aa30
  if ((ecx & ecx) == 0) goto L43aaff;  // @40_43aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_43aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @42_43aa30
  ecx = edx = 0;  // @43_43aa30
  L43aaff:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4920), &v, sizeof v); }  // @45_43aa30
  L43ab09:;
  SEH_LEAVE();  // @47_43aa30
  ext_633654(G(u32, 0x6f5630));  // @48_43aa30
  return eax;  // @49_43aa30
}
PCREG(43aa30, lifted_43aa30);

extern "C" u32 THISCALL lifted_4afc70(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4afc70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4afc70
  eax = (u32)(EBP - 148);  // @1_4afc70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @2_4afc70
  p0_ = eax;  // @3_4afc70
  eax = ext_6352f0_thiscall2(ecx, (u32)(p0_));  // @4_4afc70
  ecx = edx = 0;  // @5_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_4afc70
  ecx = (u32)(EBP - 148);  // @7_4afc70
  p1_ = ecx;  // @8_4afc70
  ecx = ebx;  // @9_4afc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p1_));  // @10_4afc70
  ecx = edx = 0;  // @11_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @12_4afc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L4afd33;  // @13_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4afc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2305));  // @16_4afc70
  ecx = edx = 0;  // @17_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @18_4afc70
  edi = eax;  // @19_4afc70
  eax = (u32)(EBP - 144);  // @20_4afc70
  p2_ = eax;  // @21_4afc70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4afc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p2_), (u32)(1));  // @23_4afc70
  ecx = edx = 0;  // @24_4afc70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4afc70
  ecx = eax;  // @26_4afc70
  reg.state = (s32)((u32)(0));  // @27_4afc70
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_4afc70
  ecx = edx = 0;  // @29_4afc70
  p3_ = eax;  // @30_4afc70
  p4_ = edi;  // @31_4afc70
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p4_), (u32)(6890728), (u32)(p3_));  // @32_4afc70
  ecx = edx = 0;  // @33_4afc70
  ecx = (u32)(EBP - 144);  // @34_4afc70
  eax = ext_4cbec0_thiscall1(ecx);  // @35_4afc70
  ecx = edx = 0;  // @36_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @37_4afc70
  if ((ecx & ecx) == 0) goto L4afd33;  // @38_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4afc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @40_4afc70
  ecx = edx = 0;  // @41_4afc70
  L4afd33:;
  SEH_LEAVE();  // @43_4afc70
  ext_633654(G(u32, 0x6f5630));  // @44_4afc70
  return eax;  // @45_4afc70
}
PCREG(4afc70, lifted_4afc70);

extern "C" u32 THISCALL lifted_5fbb00(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d4d2);  // @h_5fbb00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_5fbb00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @2_5fbb00
  if ((eax & eax) == 0) goto L5fbb3a;  // @3_5fbb00
  L5fbb31:;
  esi = eax;  // @5_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @6_5fbb00
  if ((eax & eax) != 0) goto L5fbb31;  // @7_5fbb00
  L5fbb3a:;
  eax = ext_41e290_cdecl1((u32)(2770));  // @9_5fbb00
  ecx = edx = 0;  // @10_5fbb00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @11_5fbb00
  reg.state = (s32)((u32)(0));  // @12_5fbb00
  if ((eax & eax) == 0) goto L5fbb64;  // @13_5fbb00
  ecx = eax;  // @14_5fbb00
  p0_ = esi;  // @15_5fbb00
  eax = ext_5f37f0_thiscall3(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @16_5fbb00
  ecx = edx = 0;  // @17_5fbb00
  edi = eax;  // @18_5fbb00
  goto L5fbb66;  // @19_5fbb00
  L5fbb64:;
  edi = 0;  // @21_5fbb00
  L5fbb66:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @23_5fbb00
  reg.state = (s32)((u32)(4294967295));  // @24_5fbb00
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; })) goto L5fbb7d;  // @25_5fbb00
  ecx = (u32)(esi + 88);  // @26_5fbb00
  eax = ext_5f4630_thiscall1(ecx);  // @27_5fbb00
  ecx = edx = 0;  // @28_5fbb00
  L5fbb7d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @30_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @31_5fbb00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @32_5fbb00
  ecx = (u32)(65521);  // @33_5fbb00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @34_5fbb00
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @35_5fbb00
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @36_5fbb00
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(1))) & 0xffff);  // @37_5fbb00
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @38_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @39_5fbb00
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; })) goto L5fbbb3;  // @40_5fbb00
  ecx = (u32)(ebx + 24);  // @41_5fbb00
  eax = ext_5f4630_thiscall1(ecx);  // @42_5fbb00
  ecx = edx = 0;  // @43_5fbb00
  L5fbbb3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @45_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @46_5fbb00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @47_5fbb00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @48_5fbb00
  SEH_LEAVE();  // @49_5fbb00
  return eax;  // @50_5fbb00
}
PCREG(5fbb00, lifted_5fbb00);

extern "C" u32 THISCALL lifted_4d1530(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4d1530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @1_4d1530
  { u32 v = (u32)((u32)(6905720)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4d1530
  if ((eax & eax) == 0) goto L4d1574;  // @3_4d1530
  p0_ = eax;  // @4_4d1530
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(4));  // @5_4d1530
  ecx = edx = 0;  // @6_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @7_4d1530
  L4d1574:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @9_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @10_4d1530
  if ((eax & eax) == 0) goto L4d158d;  // @11_4d1530
  p1_ = eax;  // @12_4d1530
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(4));  // @13_4d1530
  ecx = edx = 0;  // @14_4d1530
  L4d158d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) == (u32)(0)) goto L4d15a7;  // @16_4d1530
  L4d1593:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @18_4d1530
  if ((ecx & ecx) == 0) goto L4d15a1;  // @19_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4d1530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @21_4d1530
  ecx = edx = 0;  // @22_4d1530
  L4d15a1:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L4d1593;  // @24_4d1530
  L4d15a7:;
  ecx = esi;  // @26_4d1530
  eax = ext_4d2030_thiscall2(ecx, (u32)(-1));  // @27_4d1530
  ecx = edx = 0;  // @28_4d1530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @29_4d1530
  if ((ecx & ecx) == 0) goto L4d15ec;  // @30_4d1530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @31_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_4d1530
  if ((edx & edx) == 0) goto L4d15c6;  // @33_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 48), &v, sizeof v); }  // @34_4d1530
  goto L4d15c9;  // @35_4d1530
  L4d15c6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 36), &v, sizeof v); }  // @37_4d1530
  L4d15c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @39_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @40_4d1530
  if ((ecx & ecx) == 0) goto L4d15d8;  // @41_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @42_4d1530
  goto L4d15de;  // @43_4d1530
  L4d15d8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @45_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @46_4d1530
  L4d15de:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @48_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @49_4d1530
  L4d15ec:;
  SEH_LEAVE();  // @51_4d1530
  return eax;  // @52_4d1530
}
PCREG(4d1530, lifted_4d1530);

extern "C" u32 THISCALL lifted_475740(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_475740
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_475740
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_475740
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_475740
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3_475740
  if ((s32)(esi & esi) >= 0) goto L4757e7;  // @4_475740
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_475740
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_475740
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6854172), (u32)(1000));  // @7_475740
  ecx = edx = 0;  // @8_475740
  edi = eax;  // @9_475740
  ecx = (u32)(EBP - 144);  // @10_475740
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @11_475740
  p0_ = ecx;  // @12_475740
  ecx = eax;  // @13_475740
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_475740
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p0_), (u32)(1));  // @15_475740
  ecx = edx = 0;  // @16_475740
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_475740
  ecx = eax;  // @18_475740
  reg.state = (s32)((u32)(0));  // @19_475740
  eax = ext_4cc1d0_thiscall1(ecx);  // @20_475740
  ecx = edx = 0;  // @21_475740
  p1_ = eax;  // @22_475740
  p2_ = edi;  // @23_475740
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p2_), (u32)(6854632), (u32)(p1_));  // @24_475740
  ecx = edx = 0;  // @25_475740
  reg.state = (s32)((u32)(4294967295));  // @26_475740
  ecx = (u32)(EBP - 144);  // @27_475740
  eax = ext_4cbec0_thiscall1(ecx);  // @28_475740
  ecx = edx = 0;  // @29_475740
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @30_475740
  esi = 0;  // @31_475740
  L4757e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @33_475740
  p3_ = ecx;  // @34_475740
  ecx = ebx;  // @35_475740
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1372)))(ecx, (u32)(p3_));  // @36_475740
  ecx = edx = 0;  // @37_475740
  if ((eax & eax) == 0) goto L475801;  // @38_475740
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_475740
  ecx = eax;  // @40_475740
  p4_ = esi;  // @41_475740
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 804)))(ecx, (u32)(p4_));  // @42_475740
  ecx = edx = 0;  // @43_475740
  L475801:;
  SEH_LEAVE();  // @45_475740
  ext_633654(G(u32, 0x6f5630));  // @46_475740
  return eax;  // @47_475740
}
PCREG(475740, lifted_475740);

extern "C" u32 THISCALL lifted_53b2a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66aa2b);  // @h_53b2a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_53b2a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_53b2a0
  ecx = (u32)(EBP - 188);  // @2_53b2a0
  eax = ext_4ccba0_thiscall1(ecx);  // @3_53b2a0
  ecx = edx = 0;  // @4_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_53b2a0
  reg.state = (s32)((u32)(0));  // @6_53b2a0
  if ((ecx & ecx) == 0) goto L53b344;  // @7_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_53b2a0
  edx = (u32)(EBP - 200);  // @9_53b2a0
  p0_ = edx;  // @10_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @11_53b2a0
  ecx = edx = 0;  // @12_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @13_53b2a0
  edx = (u32)(EBP - 200);  // @14_53b2a0
  p1_ = edx;  // @15_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @17_53b2a0
  ecx = edx = 0;  // @18_53b2a0
  edx = eax;  // @19_53b2a0
  if ((edx & edx) == 0) goto L53b344;  // @20_53b2a0
  L53b310:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @25_53b2a0
  ecx = edx = 0;  // @26_53b2a0
  p2_ = eax;  // @27_53b2a0
  ecx = (u32)(EBP - 188);  // @28_53b2a0
  eax = ext_4cd540_thiscall2(ecx, (u32)(p2_));  // @29_53b2a0
  ecx = edx = 0;  // @30_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @31_53b2a0
  edx = (u32)(EBP - 200);  // @32_53b2a0
  p3_ = edx;  // @33_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @35_53b2a0
  ecx = edx = 0;  // @36_53b2a0
  edx = eax;  // @37_53b2a0
  if ((edx & edx) != 0) goto L53b310;  // @38_53b2a0
  L53b344:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_53b2a0
  ecx = (u32)(EBP - 188);  // @41_53b2a0
  p4_ = ecx;  // @42_53b2a0
  ecx = edi;  // @43_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p4_));  // @44_53b2a0
  ecx = edx = 0;  // @45_53b2a0
  ecx = (u32)(EBP - 188);  // @46_53b2a0
  eax = ext_4ccf60_thiscall1(ecx);  // @47_53b2a0
  ecx = edx = 0;  // @48_53b2a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @49_53b2a0
  SEH_LEAVE();  // @50_53b2a0
  ext_633654(G(u32, 0x6f5630));  // @51_53b2a0
  return eax;  // @52_53b2a0
}
PCREG(53b2a0, lifted_53b2a0);

extern "C" u32 THISCALL lifted_4208f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66420d);  // @h_4208f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4208f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4208f0
  ecx = esi;  // @2_4208f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4208f0
  reg.state = (s32)((u32)(0));  // @4_4208f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @5_4208f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @6_4208f0
  eax = ext_4cbeb0_thiscall1(ecx);  // @7_4208f0
  ecx = edx = 0;  // @8_4208f0
  ecx = edi;  // @9_4208f0
  reg.state = (s32)((u32)(0));  // @10_4208f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @11_4208f0
  edx = (u32)(ecx + 1);  // @12_4208f0
  L420960:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @14_4208f0
  ecx = (ecx + 1);  // @15_4208f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L420960;  // @16_4208f0
  ecx = (ecx - edx);  // @17_4208f0
  if (ecx <= (u32)(1)) goto L420997;  // @18_4208f0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(58)) goto L420997;  // @19_4208f0
  eax = (u32)(23644);  // @20_4208f0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) == (eax & 0xffff)) goto L420997;  // @21_4208f0
  ebx = (ebx + (u32)(291));  // @22_4208f0
  ecx = ebx;  // @23_4208f0
  eax = ext_4cc5f0_thiscall1(ecx);  // @24_4208f0
  ecx = edx = 0;  // @25_4208f0
  if ((eax & eax) == 0) goto L420997;  // @26_4208f0
  p0_ = ebx;  // @27_4208f0
  ecx = esi;  // @28_4208f0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p0_));  // @29_4208f0
  ecx = edx = 0;  // @30_4208f0
  L420997:;
  p1_ = edi;  // @32_4208f0
  ecx = (u32)(EBP - 144);  // @33_4208f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @34_4208f0
  ecx = edx = 0;  // @35_4208f0
  eax = (u32)(EBP - 144);  // @36_4208f0
  reg.state = (s32)((u32)(1));  // @37_4208f0
  p2_ = eax;  // @38_4208f0
  ecx = esi;  // @39_4208f0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p2_));  // @40_4208f0
  ecx = edx = 0;  // @41_4208f0
  ecx = (u32)(EBP - 144);  // @42_4208f0
  eax = ext_4cbec0_thiscall1(ecx);  // @43_4208f0
  ecx = edx = 0;  // @44_4208f0
  eax = esi;  // @45_4208f0
  SEH_LEAVE();  // @46_4208f0
  ext_633654(G(u32, 0x6f5630));  // @47_4208f0
  return eax;  // @48_4208f0
}
PCREG(4208f0, lifted_4208f0);

extern "C" u32 THISCALL lifted_462b00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_462b00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_462b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @1_462b00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_462b00
  p0_ = edi;  // @3_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @5_462b00
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(p0_));  // @6_462b00
  ecx = edx = 0;  // @7_462b00
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462b46;  // @8_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @9_462b00
  goto L462bb2;  // @10_462b00
  L462b46:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @12_462b00
  if ((ecx & ecx) == 0) goto L462b5e;  // @13_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_462b00
  p1_ = edi;  // @15_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @16_462b00
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p1_));  // @17_462b00
  ecx = edx = 0;  // @18_462b00
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462b5e;  // @19_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; });  // @20_462b00
  goto L462bb2;  // @21_462b00
  L462b5e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @23_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_462b00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6838324), (u32)(1389));  // @25_462b00
  ecx = edx = 0;  // @26_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_462b00
  edi = eax;  // @28_462b00
  eax = (u32)(EBP - 144);  // @29_462b00
  ecx = esi;  // @30_462b00
  p2_ = eax;  // @31_462b00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p2_), (u32)(1));  // @32_462b00
  ecx = edx = 0;  // @33_462b00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_462b00
  ecx = eax;  // @35_462b00
  reg.state = (s32)((u32)(0));  // @36_462b00
  eax = ext_4cc1d0_thiscall1(ecx);  // @37_462b00
  ecx = edx = 0;  // @38_462b00
  p3_ = eax;  // @39_462b00
  p4_ = edi;  // @40_462b00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p4_), (u32)(6838576), (u32)(p3_));  // @41_462b00
  ecx = edx = 0;  // @42_462b00
  ecx = (u32)(EBP - 144);  // @43_462b00
  eax = ext_4cbec0_thiscall1(ecx);  // @44_462b00
  ecx = edx = 0;  // @45_462b00
  eax = 0;  // @46_462b00
  L462bb2:;
  SEH_LEAVE();  // @48_462b00
  ext_633654(G(u32, 0x6f5630));  // @49_462b00
  return eax;  // @50_462b00
}
PCREG(462b00, lifted_462b00);

extern "C" u32 THISCALL lifted_601380(u32 ecx_in) {
  SEH_ENTER(0x66d8d2);  // @h_601380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_601380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_601380
  eax = (eax - (u32)(2));  // @3_601380
  if (eax == 0) goto L6013c4;  // @4_601380
  eax = (eax - (u32)(1));  // @5_601380
  if (eax != 0) goto L6013fc;  // @6_601380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @7_601380
  if ((esi & esi) == 0) goto L6013fc;  // @8_601380
  reg.state = (s32)((u32)(1));  // @9_601380
  goto L6013d2;  // @10_601380
  L6013c4:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @12_601380
  if ((esi & esi) == 0) goto L6013fc;  // @13_601380
  reg.state = (s32)((u32)(0));  // @14_601380
  L6013d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @17_601380
  eax = (eax - ecx);  // @18_601380
  if ((ecx & ecx) == 0) goto L6013ea;  // @19_601380
  if ((eax & eax) == 0) goto L6013ea;  // @20_601380
  p0_ = eax;  // @21_601380
  p1_ = ecx;  // @22_601380
  ecx = esi;  // @23_601380
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @24_601380
  ecx = edx = 0;  // @25_601380
  L6013ea:;
  p2_ = esi;  // @27_601380
  reg.state = (s32)((u32)(4294967295));  // @28_601380
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(12));  // @29_601380
  ecx = edx = 0;  // @30_601380
  L6013fc:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_601380
  if ((esi & esi) == 0) goto L60142d;  // @33_601380
  ecx = (u32)(esi + 12);  // @34_601380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @36_601380
  eax = (eax - edx);  // @37_601380
  reg.state = (s32)((u32)(2));  // @38_601380
  if ((edx & edx) == 0) goto L601422;  // @39_601380
  if ((eax & eax) == 0) goto L601422;  // @40_601380
  p3_ = eax;  // @41_601380
  p4_ = edx;  // @42_601380
  eax = ext_54f870_stdcall2((u32)(p4_), (u32)(p3_));  // @43_601380
  ecx = edx = 0;  // @44_601380
  L601422:;
  p5_ = esi;  // @46_601380
  eax = ext_634273_cdecl2((u32)(p5_), (u32)(24));  // @47_601380
  ecx = edx = 0;  // @48_601380
  L60142d:;
  SEH_LEAVE();  // @50_601380
  return eax;  // @51_601380
}
PCREG(601380, lifted_601380);

extern "C" u32 THISCALL lifted_537bb0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_537bb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_537bb0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; })) & 0xff);  // @1_537bb0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_537bb0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L537c91;  // @3_537bb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_537bb0
  if (edi != (u32)(-1)) goto L537c00;  // @5_537bb0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @6_537bb0
  goto L537c93;  // @7_537bb0
  L537c00:;
  ecx = (u32)(EBP - 144);  // @9_537bb0
  eax = ext_4cbeb0_thiscall1(ecx);  // @10_537bb0
  ecx = edx = 0;  // @11_537bb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @12_537bb0
  edx = (u32)(EBP - 272);  // @13_537bb0
  p0_ = ebx;  // @14_537bb0
  p1_ = edx;  // @15_537bb0
  reg.state = (s32)((u32)(0));  // @16_537bb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_537bb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(p1_), (u32)(p0_));  // @18_537bb0
  ecx = edx = 0;  // @19_537bb0
  p2_ = eax;  // @20_537bb0
  ecx = (u32)(EBP - 144);  // @21_537bb0
  reg.state = (s32)((u32)(1));  // @22_537bb0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @23_537bb0
  ecx = edx = 0;  // @24_537bb0
  ecx = (u32)(EBP - 272);  // @25_537bb0
  reg.state = (s32)((u32)(0));  // @26_537bb0
  eax = ext_4cbec0_thiscall1(ecx);  // @27_537bb0
  ecx = edx = 0;  // @28_537bb0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @29_537bb0
  ecx = (u32)(EBP - 144);  // @30_537bb0
  { u32 v = (u32)((u32)(257)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @31_537bb0
  { u32 v = (u32)((u32)(140)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @32_537bb0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @33_537bb0
  eax = ext_4cc1d0_thiscall1(ecx);  // @34_537bb0
  ecx = edx = 0;  // @35_537bb0
  edx = (u32)(ebx + 12);  // @36_537bb0
  edx = (edx - eax);  // @37_537bb0
  L537c70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @39_537bb0
  eax = (u32)(eax + 1);  // @40_537bb0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @41_537bb0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L537c70;  // @42_537bb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @43_537bb0
  ecx = (u32)(EBP - 144);  // @44_537bb0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @45_537bb0
  eax = ext_4cbec0_thiscall1(ecx);  // @46_537bb0
  ecx = edx = 0;  // @47_537bb0
  L537c91:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @49_537bb0
  L537c93:;
  SEH_LEAVE();  // @51_537bb0
  ext_633654(G(u32, 0x6f5630));  // @52_537bb0
  return eax;  // @53_537bb0
}
PCREG(537bb0, lifted_537bb0);

extern "C" u32 THISCALL lifted_54d910(u32 ecx_in) {
  SEH_ENTER(0x66adf6);  // @h_54d910
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_54d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_54d910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 84)))(ecx);  // @2_54d910
  ecx = edx = 0;  // @3_54d910
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32865), sizeof v); (u32)v; });  // @4_54d910
  if ((edi & edi) == 0) goto L54d96c;  // @5_54d910
  eax = (u32)(edi + 16);  // @6_54d910
  reg.state = (s32)((u32)(0));  // @7_54d910
  p0_ = eax;  // @8_54d910
  eax = ext_63418c_stdcall4((u32)(p0_), (u32)(107), (u32)(4), (u32)(5562720));  // @9_54d910
  ecx = edx = 0;  // @10_54d910
  p1_ = edi;  // @11_54d910
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(714));  // @12_54d910
  ecx = edx = 0;  // @13_54d910
  L54d96c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32813), sizeof v); (u32)v; });  // @15_54d910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32865), &v, sizeof v); }  // @16_54d910
  if ((eax & eax) == 0) goto L54d98b;  // @17_54d910
  p2_ = eax;  // @18_54d910
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(1));  // @19_54d910
  ecx = edx = 0;  // @20_54d910
  L54d98b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32841), sizeof v); (u32)v; });  // @22_54d910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32813), &v, sizeof v); }  // @23_54d910
  if ((ecx & ecx) == 0) goto L54d9a5;  // @24_54d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_54d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @26_54d910
  ecx = edx = 0;  // @27_54d910
  L54d9a5:;
  edi = 0;  // @29_54d910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32841), &v, sizeof v); }  // @30_54d910
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; }) <= (s32)edi) goto L54d9dd;  // @31_54d910
  L54d9c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @33_54d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @34_54d910
  if ((ecx & ecx) == 0) goto L54d9d4;  // @35_54d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_54d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @37_54d910
  ecx = edx = 0;  // @38_54d910
  L54d9d4:;
  edi = (edi + 1);  // @40_54d910
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; })) goto L54d9c0;  // @41_54d910
  L54d9dd:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; }), (u32)(4));  // @43_54d910
  ecx = edx = 0;  // @44_54d910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32829), &v, sizeof v); }  // @45_54d910
  SEH_LEAVE();  // @46_54d910
  return eax;  // @47_54d910
}
PCREG(54d910, lifted_54d910);

extern "C" u32 THISCALL lifted_4369a0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66592f);  // @h_4369a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4369a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4369a0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4369a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_4369a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @4_4369a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_4369a0
  if ((edx & edx) == 0) goto L436a0e;  // @6_4369a0
  ecx = (u32)(edx + 1);  // @7_4369a0
  L4369e6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @9_4369a0
  edx = (edx + 1);  // @10_4369a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4369e6;  // @11_4369a0
  edx = (edx - ecx);  // @12_4369a0
  eax = (u32)(edx + 1);  // @13_4369a0
  p0_ = eax;  // @14_4369a0
  eax = ext_41e290_cdecl1((u32)(p0_));  // @15_4369a0
  ecx = edx = 0;  // @16_4369a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @17_4369a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_4369a0
  L436a00:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @20_4369a0
  edx = (u32)(edx + 1);  // @21_4369a0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @22_4369a0
  eax = (u32)(eax + 1);  // @23_4369a0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L436a00;  // @24_4369a0
  L436a0e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @26_4369a0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @27_4369a0
  eax = (u32)(ecx + 4);  // @28_4369a0
  ecx = (0u - ecx);  // @29_4369a0
  ecx = 0;  // @30_4369a0
  ecx = (ecx & eax);  // @31_4369a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @32_4369a0
  eax = ext_41e290_cdecl1((u32)(28));  // @33_4369a0
  ecx = edx = 0;  // @34_4369a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @35_4369a0
  reg.state = (s32)((u32)(0));  // @36_4369a0
  if ((eax & eax) == 0) goto L436a46;  // @37_4369a0
  ecx = eax;  // @38_4369a0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @39_4369a0
  ecx = edx = 0;  // @40_4369a0
  goto L436a48;  // @41_4369a0
  L436a46:;
  eax = 0;  // @43_4369a0
  L436a48:;
  p1_ = edi;  // @45_4369a0
  ecx = esi;  // @46_4369a0
  reg.state = (s32)((u32)(4294967295));  // @47_4369a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @48_4369a0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @49_4369a0
  eax = ext_4376c0_thiscall2(ecx, (u32)(p1_));  // @50_4369a0
  ecx = edx = 0;  // @51_4369a0
  eax = esi;  // @52_4369a0
  SEH_LEAVE();  // @53_4369a0
  return eax;  // @54_4369a0
}
PCREG(4369a0, lifted_4369a0);

extern "C" u32 THISCALL lifted_616490(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66e5f8);  // @h_616490
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_616490
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_616490
  ecx = (u32)(edi + 8);  // @5_616490
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @6_616490
  { u32 v = (u32)((u32)(7068916)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_616490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @8_616490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @9_616490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @10_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @11_616490
  reg.state = (s32)((u32)(0));  // @12_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @13_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_616490
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 14), sizeof v); (u32)v; });  // @15_616490
  p0_ = ebx;  // @16_616490
  eax = ext_659330_thiscall3(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47528), sizeof v); (u32)v; }));  // @17_616490
  ecx = edx = 0;  // @18_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47524), sizeof v); (u32)v; });  // @19_616490
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5114), sizeof v); (u32)v; });  // @20_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @22_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @23_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @24_616490
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L616561;  // @25_616490
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L61653b;  // @26_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_616490
  ecx = esi;  // @28_616490
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @29_616490
  ecx = edx = 0;  // @30_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @31_616490
  L61653b:;
  eax = (u32)(ebx + ebx*8);  // @33_616490
  eax = (eax << (u32)(2));  // @34_616490
  p1_ = eax;  // @35_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @37_616490
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @38_616490
  p2_ = eax;  // @39_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @40_616490
  ecx = (u32)(eax + eax*8);  // @41_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @42_616490
  eax = (u32)(eax + ecx*4);  // @43_616490
  p3_ = eax;  // @44_616490
  eax = ext_634d22_cdecl3((u32)(p3_), (u32)(p2_), (u32)(p1_));  // @45_616490
  ecx = edx = 0;  // @46_616490
  L616561:;
  eax = edi;  // @48_616490
  SEH_LEAVE();  // @49_616490
  return eax;  // @50_616490
}
PCREG(616490, lifted_616490);

extern "C" u32 THISCALL lifted_537a90(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_537a90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_537a90
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; })) & 0xff);  // @1_537a90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_537a90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L537b81;  // @3_537a90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_537a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20901), sizeof v); (u32)v; });  // @5_537a90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @6_537a90
  if (edi != (u32)(-1)) goto L537aec;  // @7_537a90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @8_537a90
  goto L537b83;  // @9_537a90
  L537aec:;
  ecx = (u32)(EBP - 144);  // @11_537a90
  eax = ext_4cbeb0_thiscall1(ecx);  // @12_537a90
  ecx = edx = 0;  // @13_537a90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @14_537a90
  edx = (u32)(EBP - 272);  // @15_537a90
  p0_ = ebx;  // @16_537a90
  p1_ = edx;  // @17_537a90
  reg.state = (s32)((u32)(0));  // @18_537a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_537a90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(p1_), (u32)(p0_));  // @20_537a90
  ecx = edx = 0;  // @21_537a90
  p2_ = eax;  // @22_537a90
  ecx = (u32)(EBP - 144);  // @23_537a90
  reg.state = (s32)((u32)(1));  // @24_537a90
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @25_537a90
  ecx = edx = 0;  // @26_537a90
  ecx = (u32)(EBP - 272);  // @27_537a90
  reg.state = (s32)((u32)(0));  // @28_537a90
  eax = ext_4cbec0_thiscall1(ecx);  // @29_537a90
  ecx = edx = 0;  // @30_537a90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @31_537a90
  ecx = (u32)(EBP - 144);  // @32_537a90
  { u32 v = (u32)((u32)(258)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @33_537a90
  { u32 v = (u32)((u32)(140)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @34_537a90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @35_537a90
  eax = ext_4cc1d0_thiscall1(ecx);  // @36_537a90
  ecx = edx = 0;  // @37_537a90
  edx = (u32)(ebx + 12);  // @38_537a90
  edx = (edx - eax);  // @39_537a90
  L537b60:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @41_537a90
  eax = (u32)(eax + 1);  // @42_537a90
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @43_537a90
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L537b60;  // @44_537a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @45_537a90
  ecx = (u32)(EBP - 144);  // @46_537a90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @47_537a90
  eax = ext_4cbec0_thiscall1(ecx);  // @48_537a90
  ecx = edx = 0;  // @49_537a90
  L537b81:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @51_537a90
  L537b83:;
  SEH_LEAVE();  // @53_537a90
  ext_633654(G(u32, 0x6f5630));  // @54_537a90
  return eax;  // @55_537a90
}
PCREG(537a90, lifted_537a90);

extern "C" u32 THISCALL lifted_5f3b00(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_5f3b00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_5f3b00
  ecx = (u32)(esi + 52);  // @1_5f3b00
  { u32 v = (u32)((u32)(7047724)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5f3b00
  eax = ext_5f55e0_thiscall1(ecx);  // @3_5f3b00
  ecx = edx = 0;  // @4_5f3b00
  edi = (u32)(esi + 40);  // @5_5f3b00
  ecx = edi;  // @6_5f3b00
  eax = ext_5f55e0_thiscall1(ecx);  // @7_5f3b00
  ecx = edx = 0;  // @8_5f3b00
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }) == (u32)(0)) goto L5f3b83;  // @9_5f3b00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @10_5f3b00
  L5f3b50:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @12_5f3b00
  if ((ecx & ecx) == 0) goto L5f3b63;  // @13_5f3b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @14_5f3b00
  ecx = (ecx - 1);  // @15_5f3b00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @16_5f3b00
  edi = (u32)(eax + ecx*4);  // @17_5f3b00
  goto L5f3b73;  // @18_5f3b00
  L5f3b63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5f3b00
  if ((eax & eax) == 0) goto L5f3b70;  // @21_5f3b00
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @22_5f3b00
  ecx = edx = 0;  // @23_5f3b00
  goto L5f3b73;  // @24_5f3b00
  L5f3b70:;
  __builtin_trap();  // @26_5f3b00
  L5f3b73:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_5f3b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_5f3b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @30_5f3b00
  ecx = edx = 0;  // @31_5f3b00
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }) != (u32)(0)) goto L5f3b50;  // @32_5f3b00
  edi = (u32)(esi + 40);  // @33_5f3b00
  L5f3b83:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5f3b97;  // @35_5f3b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 150), sizeof v); (u32)v; });  // @36_5f3b00
  p0_ = esi;  // @37_5f3b00
  eax = ext_5fef70_thiscall2(ecx, (u32)(p0_));  // @38_5f3b00
  ecx = edx = 0;  // @39_5f3b00
  goto L5f3ba6;  // @40_5f3b00
  L5f3b97:;
  ecx = (u32)(esi + 154);  // @42_5f3b00
  eax = ext_600260_thiscall3(ecx, (u32)(0), (u32)(0));  // @43_5f3b00
  ecx = edx = 0;  // @44_5f3b00
  L5f3ba6:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; }));  // @46_5f3b00
  ecx = edx = 0;  // @47_5f3b00
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }));  // @48_5f3b00
  ecx = edx = 0;  // @49_5f3b00
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }));  // @50_5f3b00
  ecx = edx = 0;  // @51_5f3b00
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; }));  // @52_5f3b00
  ecx = edx = 0;  // @53_5f3b00
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @54_5f3b00
  ecx = edx = 0;  // @55_5f3b00
  SEH_LEAVE();  // @56_5f3b00
  return eax;  // @57_5f3b00
}
PCREG(5f3b00, lifted_5f3b00);

extern "C" u32 FASTCALL lifted_42ae00(u32 ecx_in, u32 edx_in, u32 a0) {
  SEH_ENTER(0x66cd79);  // @h_42ae00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_42ae00
  edi = ecx;  // @1_42ae00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @2_42ae00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_42ae00
  reg.state = (s32)((u32)(0));  // @4_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_42ae00
  ecx = (u32)(esi + 1);  // @6_42ae00
  L42ae44:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @8_42ae00
  esi = (esi + 1);  // @9_42ae00
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42ae44;  // @10_42ae00
  esi = (esi - ecx);  // @11_42ae00
  ebx = esi;  // @12_42ae00
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @13_42ae00
  ebx = (ebx + 1);  // @14_42ae00
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @15_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @16_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @17_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @18_42ae00
  if (ebx > (u32)(-2)) goto L42ae8b;  // @19_42ae00
  if ((ebx & ebx) != 0) goto L42ae76;  // @20_42ae00
  eax = 0;  // @21_42ae00
  goto L42ae81;  // @22_42ae00
  L42ae76:;
  p0_ = ebx;  // @24_42ae00
  ecx = edi;  // @25_42ae00
  eax = ext_6014a0_stdcall1((u32)(p0_));  // @26_42ae00
  ecx = edx = 0;  // @27_42ae00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @28_42ae00
  L42ae81:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @30_42ae00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @31_42ae00
  eax = (eax + ebx);  // @32_42ae00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @33_42ae00
  L42ae8b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @35_42ae00
  if ((eax & eax) == 0) goto L42ae95;  // @36_42ae00
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_42ae00
  L42ae95:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @39_42ae00
  ecx = edi;  // @40_42ae00
  reg.state = (s32)((u32)(0));  // @41_42ae00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @42_42ae00
  eax = ext_5f2c60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @43_42ae00
  ecx = edx = 0;  // @44_42ae00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @45_42ae00
  eax = (u32)(esi + ecx);  // @46_42ae00
  p1_ = eax;  // @47_42ae00
  p2_ = ecx;  // @48_42ae00
  ecx = edi;  // @49_42ae00
  eax = ext_5f2c60_thiscall3(ecx, (u32)(p2_), (u32)(p1_));  // @50_42ae00
  ecx = edx = 0;  // @51_42ae00
  eax = edi;  // @52_42ae00
  SEH_LEAVE();  // @53_42ae00
  return eax;  // @54_42ae00
}
PCREG(42ae00, lifted_42ae00);

extern "C" u32 THISCALL lifted_4b1f10(u32 ecx_in) {
  SEH_ENTER(0x6689e6);  // @h_4b1f10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4b1f10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4b1f10
  eax = ext_469870_thiscall1(ecx);  // @2_4b1f10
  ecx = edx = 0;  // @3_4b1f10
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4b1f10
  { u32 v = (u32)((u32)(6888848)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4b1f10
  edi = (u32)(esi + 80);  // @7_4b1f10
  ecx = (u32)(esi + 149);  // @8_4b1f10
  reg.state = (s32)((u32)(0));  // @9_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_4b1f10
  eax = ext_4cbeb0_thiscall1(ecx);  // @11_4b1f10
  ecx = edx = 0;  // @12_4b1f10
  eax = (u32)(EBP - 20);  // @13_4b1f10
  reg.state = (s32)((u32)(1));  // @14_4b1f10
  if (edi == eax) goto L4b1f7e;  // @15_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @16_4b1f10
  L4b1f7e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @18_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @19_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @20_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @21_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @22_4b1f10
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @23_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @24_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @25_4b1f10
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @26_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 283), &v, sizeof v); }  // @27_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 287), &v, sizeof v); }  // @28_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4b1f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4b1f10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891112), (u32)(0), (u32)(6889180), (u32)(2749));  // @32_4b1f10
  ecx = edx = 0;  // @33_4b1f10
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 279), &v, sizeof v); }  // @34_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_4b1f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4b1f10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891132), (u32)(0), (u32)(6889180), (u32)(2750));  // @38_4b1f10
  ecx = edx = 0;  // @39_4b1f10
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 281), &v, sizeof v); }  // @40_4b1f10
  eax = (u32)(esi + 291);  // @41_4b1f10
  p0_ = eax;  // @42_4b1f10
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(256));  // @43_4b1f10
  ecx = edx = 0;  // @44_4b1f10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 547), &v, sizeof v); }  // @45_4b1f10
  eax = esi;  // @46_4b1f10
  SEH_LEAVE();  // @47_4b1f10
  return eax;  // @48_4b1f10
}
PCREG(4b1f10, lifted_4b1f10);

extern "C" u32 THISCALL lifted_48b5b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66796b);  // @h_48b5b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 124), sizeof v); (u32)v; });  // @1_48b5b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2_48b5b0
  ecx = edx = 0;  // @3_48b5b0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L48b602;  // @4_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_48b5b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(3598));  // @7_48b5b0
  ecx = edx = 0;  // @8_48b5b0
  p0_ = eax;  // @9_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_48b5b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6872776));  // @11_48b5b0
  ecx = edx = 0;  // @12_48b5b0
  L48b602:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @16_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_48b5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(64));  // @18_48b5b0
  ecx = edx = 0;  // @19_48b5b0
  esi = eax;  // @20_48b5b0
  if ((esi & esi) != 0) goto L48b62b;  // @21_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @22_48b5b0
  if ((eax & eax) == 0) goto L48b62a;  // @23_48b5b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @24_48b5b0
  ecx = edx = 0;  // @25_48b5b0
  goto L48b62b;  // @26_48b5b0
  L48b62a:;
  __builtin_trap();  // @28_48b5b0
  L48b62b:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_48b5b0
  reg.state = (s32)((u32)(0));  // @31_48b5b0
  if ((esi & esi) == 0) goto L48b644;  // @32_48b5b0
  ecx = esi;  // @33_48b5b0
  eax = ext_469870_thiscall1(ecx);  // @34_48b5b0
  ecx = edx = 0;  // @35_48b5b0
  esi = eax;  // @36_48b5b0
  goto L48b646;  // @37_48b5b0
  L48b644:;
  esi = 0;  // @39_48b5b0
  L48b646:;
  reg.state = (s32)((u32)(4294967295));  // @41_48b5b0
  if ((esi & esi) == 0) goto L48b67c;  // @42_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_48b5b0
  edx = (u32)(esi + 16);  // @44_48b5b0
  eax = (u32)(ecx + 64);  // @45_48b5b0
  if (edx == eax) goto L48b66b;  // @46_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_48b5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @48_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_48b5b0
  L48b66b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @51_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_48b5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @53_48b5b0
  ecx = edx = 0;  // @54_48b5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @55_48b5b0
  L48b67c:;
  eax = esi;  // @57_48b5b0
  SEH_LEAVE();  // @58_48b5b0
  return eax;  // @59_48b5b0
}
PCREG(48b5b0, lifted_48b5b0);

extern "C" u32 THISCALL lifted_42d820(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664efc);  // @h_42d820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_42d820
  ecx = (u32)(EBP - 532);  // @2_42d820
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_42d820
  p0_ = ecx;  // @4_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @5_42d820
  ecx = esi;  // @6_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @7_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @8_42d820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789660), (u32)(p0_));  // @9_42d820
  ecx = edx = 0;  // @10_42d820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42d8f5;  // @11_42d820
  ecx = (u32)(EBP - 272);  // @12_42d820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; }));  // @13_42d820
  ecx = edx = 0;  // @14_42d820
  ecx = (u32)(EBP - 144);  // @15_42d820
  reg.state = (s32)((u32)(0));  // @16_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789668));  // @17_42d820
  ecx = edx = 0;  // @18_42d820
  eax = (u32)(EBP - 144);  // @19_42d820
  reg.state = (s32)((u32)(1));  // @20_42d820
  p1_ = eax;  // @21_42d820
  eax = (u32)(EBP - 528);  // @22_42d820
  p2_ = eax;  // @23_42d820
  ecx = (u32)(esi + 291);  // @24_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p2_), (u32)(p1_));  // @25_42d820
  ecx = edx = 0;  // @26_42d820
  ecx = (u32)(EBP - 272);  // @27_42d820
  reg.state = (s32)((u32)(2));  // @28_42d820
  p3_ = ecx;  // @29_42d820
  p4_ = edi;  // @30_42d820
  ecx = eax;  // @31_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p4_), (u32)(p3_));  // @32_42d820
  ecx = edx = 0;  // @33_42d820
  ecx = (u32)(EBP - 528);  // @34_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @35_42d820
  ecx = edx = 0;  // @36_42d820
  ecx = (u32)(EBP - 144);  // @37_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @38_42d820
  ecx = edx = 0;  // @39_42d820
  ecx = (u32)(EBP - 272);  // @40_42d820
  goto L42d925;  // @41_42d820
  L42d8f5:;
  ecx = (u32)(EBP - 400);  // @43_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789660));  // @44_42d820
  ecx = edx = 0;  // @45_42d820
  eax = (u32)(EBP - 400);  // @46_42d820
  reg.state = (s32)((u32)(3));  // @47_42d820
  p5_ = eax;  // @48_42d820
  p6_ = edi;  // @49_42d820
  ecx = (u32)(esi + 291);  // @50_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p6_), (u32)(p5_));  // @51_42d820
  ecx = edx = 0;  // @52_42d820
  ecx = (u32)(EBP - 400);  // @53_42d820
  L42d925:;
  eax = ext_4cbec0_thiscall1(ecx);  // @55_42d820
  ecx = edx = 0;  // @56_42d820
  eax = edi;  // @57_42d820
  SEH_LEAVE();  // @58_42d820
  ext_633654(G(u32, 0x6f5630));  // @59_42d820
  return eax;  // @60_42d820
}
PCREG(42d820, lifted_42d820);

extern "C" u32 THISCALL lifted_4c90a0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_4c90a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1_4c90a0
  ecx = (u32)(EBP - 144);  // @2_4c90a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @4_4c90a0
  ecx = edx = 0;  // @5_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4c90a0
  reg.state = (s32)((u32)(0));  // @7_4c90a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @8_4c90a0
  if ((eax & 0xff) == (u32)(255)) goto L4c9131;  // @9_4c90a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @10_4c90a0
  if ((eax & 0xff) != (u32)(4)) goto L4c9131;  // @11_4c90a0
  ecx = esi;  // @12_4c90a0
  eax = ext_4e5ea0_thiscall1(ecx);  // @13_4c90a0
  ecx = edx = 0;  // @14_4c90a0
  p0_ = eax;  // @15_4c90a0
  ecx = (u32)(EBP - 272);  // @16_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @17_4c90a0
  ecx = edx = 0;  // @18_4c90a0
  eax = (u32)(EBP - 272);  // @19_4c90a0
  reg.state = (s32)((u32)(1));  // @20_4c90a0
  p1_ = eax;  // @21_4c90a0
  ecx = (u32)(EBP - 144);  // @22_4c90a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @23_4c90a0
  ecx = edx = 0;  // @24_4c90a0
  ecx = (u32)(EBP - 272);  // @25_4c90a0
  reg.state = (s32)((u32)(0));  // @26_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @27_4c90a0
  ecx = edx = 0;  // @28_4c90a0
  L4c9131:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @33_4c90a0
  ecx = edx = 0;  // @34_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_4c90a0
  esi = eax;  // @36_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @37_4c90a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_4c90a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4c90a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }), (u32)(2));  // @40_4c90a0
  ecx = edx = 0;  // @41_4c90a0
  p2_ = eax;  // @42_4c90a0
  ecx = (u32)(EBP - 144);  // @43_4c90a0
  eax = ext_4cc1d0_cdecl1((u32)(p2_));  // @44_4c90a0
  ecx = edx = 0;  // @45_4c90a0
  p3_ = eax;  // @46_4c90a0
  ecx = esi;  // @47_4c90a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(p3_));  // @48_4c90a0
  ecx = edx = 0;  // @49_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_4c90a0
  ecx = ebx;  // @51_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @52_4c90a0
  ecx = edx = 0;  // @53_4c90a0
  ecx = (u32)(EBP - 144);  // @54_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @55_4c90a0
  ecx = edx = 0;  // @56_4c90a0
  SEH_LEAVE();  // @57_4c90a0
  ext_633654(G(u32, 0x6f5630));  // @58_4c90a0
  return eax;  // @59_4c90a0
}
PCREG(4c90a0, lifted_4c90a0);

extern "C" u32 THISCALL lifted_4d1390(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6692df);  // @h_4d1390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_4d1390
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d1390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4d1390
  { u32 v = (u32)((u32)(6905720)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @3_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @4_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @5_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @6_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @7_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @8_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @9_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @10_4d1390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @11_4d1390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @12_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @13_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @14_4d1390
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @15_4d1390
  if ((ecx & ecx) == 0) goto L4d1433;  // @16_4d1390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @17_4d1390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @18_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @19_4d1390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @20_4d1390
  if ((eax & eax) == 0) goto L4d142b;  // @21_4d1390
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @22_4d1390
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @23_4d1390
  goto L4d1441;  // @24_4d1390
  L4d142b:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 36), &v, sizeof v); }  // @26_4d1390
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @27_4d1390
  goto L4d1441;  // @28_4d1390
  L4d1433:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @30_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @31_4d1390
  L4d1441:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; });  // @33_4d1390
  if ((esi & esi) == 0) goto L4d1477;  // @34_4d1390
  L4d1448:;
  eax = ext_41e290_cdecl1((u32)(56));  // @36_4d1390
  ecx = edx = 0;  // @37_4d1390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @38_4d1390
  reg.state = (s32)((u32)(0));  // @39_4d1390
  if ((eax & eax) == 0) goto L4d1469;  // @40_4d1390
  p0_ = edi;  // @41_4d1390
  p1_ = esi;  // @42_4d1390
  ecx = eax;  // @43_4d1390
  eax = ext_4d1390_thiscall3(ecx, (u32)(p1_), (u32)(p0_));  // @44_4d1390
  ecx = edx = 0;  // @45_4d1390
  L4d1469:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @47_4d1390
  reg.state = (s32)((u32)(4294967295));  // @48_4d1390
  if ((esi & esi) != 0) goto L4d1448;  // @49_4d1390
  L4d1477:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @51_4d1390
  ecx = ebx;  // @52_4d1390
  p2_ = edi;  // @53_4d1390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p2_));  // @54_4d1390
  ecx = edx = 0;  // @55_4d1390
  eax = edi;  // @56_4d1390
  SEH_LEAVE();  // @57_4d1390
  return eax;  // @58_4d1390
}
PCREG(4d1390, lifted_4d1390);

extern "C" u32 THISCALL lifted_442ad0(u32 ecx_in) {
  SEH_ENTER(0x665e7b);  // @h_442ad0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_442ad0
  eax = ext_44a1f0_cdecl0();  // @1_442ad0
  ecx = edx = 0;  // @2_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_442ad0
  ecx = esi;  // @4_442ad0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 788)))(ecx);  // @5_442ad0
  ecx = edx = 0;  // @6_442ad0
  esi = eax;  // @7_442ad0
  if ((esi & esi) == 0) goto L442be2;  // @8_442ad0
  ecx = (u32)(EBP - 188);  // @9_442ad0
  eax = ext_4ccba0_thiscall1(ecx);  // @10_442ad0
  ecx = edx = 0;  // @11_442ad0
  ecx = (u32)(EBP - 284);  // @12_442ad0
  reg.state = (s32)((u32)(0));  // @13_442ad0
  eax = ext_4e3180_thiscall1(ecx);  // @14_442ad0
  ecx = edx = 0;  // @15_442ad0
  eax = (u32)(EBP - 188);  // @16_442ad0
  { u32 v = (u32)((u32)(5124816)); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @17_442ad0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @18_442ad0
  ecx = esi;  // @19_442ad0
  eax = (u32)(EBP - 284);  // @20_442ad0
  p0_ = eax;  // @21_442ad0
  eax = ext_4e49d0_thiscall2(ecx, (u32)(p0_));  // @22_442ad0
  ecx = edx = 0;  // @23_442ad0
  eax = (u32)(EBP - 296);  // @24_442ad0
  p1_ = eax;  // @25_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @26_442ad0
  ecx = (u32)(EBP - 188);  // @27_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @28_442ad0
  ecx = edx = 0;  // @29_442ad0
  eax = (u32)(EBP - 296);  // @30_442ad0
  p2_ = eax;  // @31_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @32_442ad0
  ecx = (u32)(EBP - 188);  // @33_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @34_442ad0
  ecx = edx = 0;  // @35_442ad0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L442bd7;  // @36_442ad0
  L442b90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_442ad0
  p3_ = eax;  // @39_442ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @40_442ad0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(p3_));  // @42_442ad0
  ecx = edx = 0;  // @43_442ad0
  esi = eax;  // @44_442ad0
  if ((esi & esi) == 0) goto L442bb8;  // @45_442ad0
  ecx = esi;  // @46_442ad0
  eax = ext_4da720_thiscall2(ecx, (u32)(0));  // @47_442ad0
  ecx = edx = 0;  // @48_442ad0
  ecx = esi;  // @49_442ad0
  eax = ext_4d9ce0_thiscall1(ecx);  // @50_442ad0
  ecx = edx = 0;  // @51_442ad0
  L442bb8:;
  eax = (u32)(EBP - 296);  // @53_442ad0
  p4_ = eax;  // @54_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @55_442ad0
  ecx = (u32)(EBP - 188);  // @56_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p4_));  // @57_442ad0
  ecx = edx = 0;  // @58_442ad0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) != (u32)(0)) goto L442b90;  // @59_442ad0
  L442bd7:;
  ecx = (u32)(EBP - 188);  // @61_442ad0
  eax = ext_4ccf60_thiscall1(ecx);  // @62_442ad0
  ecx = edx = 0;  // @63_442ad0
  L442be2:;
  SEH_LEAVE();  // @65_442ad0
  ext_633654(G(u32, 0x6f5630));  // @66_442ad0
  return eax;  // @67_442ad0
}
PCREG(442ad0, lifted_442ad0);

extern "C" u32 THISCALL lifted_4368b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66592f);  // @h_4368b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4368b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4368b0
  ecx = edi;  // @2_4368b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_4368b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4368b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @5_4368b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @6_4368b0
  ecx = edx = 0;  // @7_4368b0
  if ((eax & eax) == 0) goto L436930;  // @8_4368b0
  ecx = edi;  // @9_4368b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @10_4368b0
  ecx = edx = 0;  // @11_4368b0
  edx = (u32)(eax + 1);  // @12_4368b0
  L436902:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @14_4368b0
  eax = (eax + 1);  // @15_4368b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L436902;  // @16_4368b0
  eax = (eax - edx);  // @17_4368b0
  eax = (eax + 1);  // @18_4368b0
  p0_ = eax;  // @19_4368b0
  eax = ext_41e290_cdecl1((u32)(p0_));  // @20_4368b0
  ecx = edx = 0;  // @21_4368b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @22_4368b0
  ecx = edi;  // @23_4368b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_4368b0
  ecx = edx = 0;  // @25_4368b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @26_4368b0
  L436922:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @28_4368b0
  eax = (u32)(eax + 1);  // @29_4368b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @30_4368b0
  edx = (u32)(edx + 1);  // @31_4368b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L436922;  // @32_4368b0
  L436930:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @34_4368b0
  eax = (u32)(ecx + 4);  // @35_4368b0
  ecx = (0u - ecx);  // @36_4368b0
  ecx = 0;  // @37_4368b0
  ecx = (ecx & eax);  // @38_4368b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @39_4368b0
  eax = ext_41e290_cdecl1((u32)(28));  // @40_4368b0
  ecx = edx = 0;  // @41_4368b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @42_4368b0
  reg.state = (s32)((u32)(0));  // @43_4368b0
  if ((eax & eax) == 0) goto L436964;  // @44_4368b0
  ecx = eax;  // @45_4368b0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @46_4368b0
  ecx = edx = 0;  // @47_4368b0
  goto L436966;  // @48_4368b0
  L436964:;
  eax = 0;  // @50_4368b0
  L436966:;
  p1_ = edi;  // @52_4368b0
  ecx = esi;  // @53_4368b0
  reg.state = (s32)((u32)(4294967295));  // @54_4368b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @55_4368b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @56_4368b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @57_4368b0
  eax = ext_437670_thiscall2(ecx, (u32)(p1_));  // @58_4368b0
  ecx = edx = 0;  // @59_4368b0
  eax = esi;  // @60_4368b0
  SEH_LEAVE();  // @61_4368b0
  return eax;  // @62_4368b0
}
PCREG(4368b0, lifted_4368b0);

extern "C" u32 THISCALL lifted_4553d0(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_4553d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 221), sizeof v); (u32)v; });  // @1_4553d0
  { u32 v = (u32)((u32)(6826180)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4553d0
  if ((eax & eax) == 0) goto L455411;  // @3_4553d0
  p0_ = eax;  // @4_4553d0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(4));  // @5_4553d0
  ecx = edx = 0;  // @6_4553d0
  L455411:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; });  // @8_4553d0
  if ((eax & eax) == 0) goto L455423;  // @9_4553d0
  p1_ = eax;  // @10_4553d0
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(1));  // @11_4553d0
  ecx = edx = 0;  // @12_4553d0
  L455423:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; });  // @14_4553d0
  if ((eax & eax) == 0) goto L455435;  // @15_4553d0
  p2_ = eax;  // @16_4553d0
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(1));  // @17_4553d0
  ecx = edx = 0;  // @18_4553d0
  L455435:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4553d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @23_4553d0
  ecx = edx = 0;  // @24_4553d0
  ecx = (u32)(EBP - 16);  // @25_4553d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_4553d0
  p3_ = ecx;  // @27_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_4553d0
  ecx = eax;  // @29_4553d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6827256), (u32)(p3_));  // @30_4553d0
  ecx = edx = 0;  // @31_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @32_4553d0
  if ((edx & edx) == 0) goto L4554a7;  // @33_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @34_4553d0
  p4_ = edx;  // @35_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4553d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(p4_));  // @37_4553d0
  ecx = edx = 0;  // @38_4553d0
  if ((eax & eax) == 0) goto L455484;  // @39_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @40_4553d0
  ecx = eax;  // @41_4553d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(1));  // @42_4553d0
  ecx = edx = 0;  // @43_4553d0
  L455484:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4553d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @48_4553d0
  ecx = edx = 0;  // @49_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_4553d0
  ecx = eax;  // @51_4553d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(6827256), (u32)(0), (u32)(16));  // @52_4553d0
  ecx = edx = 0;  // @53_4553d0
  L4554a7:;
  ecx = esi;  // @55_4553d0
  eax = ext_43de70_thiscall1(ecx);  // @56_4553d0
  ecx = edx = 0;  // @57_4553d0
  SEH_LEAVE();  // @58_4553d0
  return eax;  // @59_4553d0
}
PCREG(4553d0, lifted_4553d0);

extern "C" u32 THISCALL lifted_42c380(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d7c);  // @h_42c380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42c380
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42c380
  ecx = (u32)(EBP - 144);  // @2_42c380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @3_42c380
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_42c380
  ecx = edx = 0;  // @5_42c380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_42c380
  ecx = (u32)(EBP - 400);  // @7_42c380
  p0_ = ecx;  // @8_42c380
  ecx = esi;  // @9_42c380
  reg.state = (s32)((u32)(0));  // @10_42c380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(p0_));  // @11_42c380
  ecx = edx = 0;  // @12_42c380
  p1_ = eax;  // @13_42c380
  ecx = (u32)(EBP - 144);  // @14_42c380
  reg.state = (s32)((u32)(1));  // @15_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @16_42c380
  ecx = edx = 0;  // @17_42c380
  ecx = (u32)(EBP - 400);  // @18_42c380
  reg.state = (s32)((u32)(0));  // @19_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @20_42c380
  ecx = edx = 0;  // @21_42c380
  ecx = (u32)(EBP - 144);  // @22_42c380
  eax = ext_4cc5f0_thiscall1(ecx);  // @23_42c380
  ecx = edx = 0;  // @24_42c380
  if ((eax & eax) != 0) goto L42c41d;  // @25_42c380
  eax = (u32)(EBP - 144);  // @26_42c380
  ecx = edi;  // @27_42c380
  p2_ = eax;  // @28_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p2_));  // @29_42c380
  ecx = edx = 0;  // @30_42c380
  goto L42c48c;  // @31_42c380
  L42c41d:;
  ecx = (u32)(EBP - 272);  // @33_42c380
  eax = ext_4cbeb0_thiscall1(ecx);  // @34_42c380
  ecx = edx = 0;  // @35_42c380
  ecx = (u32)(EBP - 400);  // @36_42c380
  reg.state = (s32)((u32)(2));  // @37_42c380
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789684));  // @38_42c380
  ecx = edx = 0;  // @39_42c380
  eax = (u32)(EBP - 400);  // @40_42c380
  reg.state = (s32)((u32)(3));  // @41_42c380
  p3_ = eax;  // @42_42c380
  ecx = (u32)(EBP - 272);  // @43_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p3_));  // @44_42c380
  ecx = edx = 0;  // @45_42c380
  ecx = (u32)(EBP - 400);  // @46_42c380
  reg.state = (s32)((u32)(2));  // @47_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @48_42c380
  ecx = edx = 0;  // @49_42c380
  eax = (u32)(EBP - 144);  // @50_42c380
  p4_ = eax;  // @51_42c380
  ecx = (u32)(EBP - 272);  // @52_42c380
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p4_));  // @53_42c380
  ecx = edx = 0;  // @54_42c380
  eax = (u32)(EBP - 272);  // @55_42c380
  ecx = edi;  // @56_42c380
  p5_ = eax;  // @57_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p5_));  // @58_42c380
  ecx = edx = 0;  // @59_42c380
  ecx = (u32)(EBP - 272);  // @60_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @61_42c380
  ecx = edx = 0;  // @62_42c380
  L42c48c:;
  ecx = (u32)(EBP - 144);  // @64_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @65_42c380
  ecx = edx = 0;  // @66_42c380
  eax = edi;  // @67_42c380
  SEH_LEAVE();  // @68_42c380
  ext_633654(G(u32, 0x6f5630));  // @69_42c380
  return eax;  // @70_42c380
}
PCREG(42c380, lifted_42c380);

extern "C" u32 THISCALL lifted_42fcc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665213);  // @h_42fcc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_42fcc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42fcc0
  ecx = esi;  // @2_42fcc0
  reg.state = (s32)((u32)(0));  // @3_42fcc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @4_42fcc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @5_42fcc0
  eax = ext_4cbeb0_thiscall1(ecx);  // @6_42fcc0
  ecx = edx = 0;  // @7_42fcc0
  edi = (u32)(ebx + 547);  // @8_42fcc0
  reg.state = (s32)((u32)(0));  // @9_42fcc0
  ecx = edi;  // @10_42fcc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @11_42fcc0
  eax = ext_4cc5f0_thiscall1(ecx);  // @12_42fcc0
  ecx = edx = 0;  // @13_42fcc0
  if ((eax & eax) == 0) goto L42fd3d;  // @14_42fcc0
  p0_ = edi;  // @15_42fcc0
  ecx = esi;  // @16_42fcc0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p0_));  // @17_42fcc0
  ecx = edx = 0;  // @18_42fcc0
  goto L42fda0;  // @19_42fcc0
  L42fd3d:;
  ecx = (u32)(EBP - 144);  // @21_42fcc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789684));  // @22_42fcc0
  ecx = edx = 0;  // @23_42fcc0
  eax = (u32)(EBP - 144);  // @24_42fcc0
  reg.state = (s32)((u32)(1));  // @25_42fcc0
  p1_ = eax;  // @26_42fcc0
  ecx = esi;  // @27_42fcc0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @28_42fcc0
  ecx = edx = 0;  // @29_42fcc0
  ecx = (u32)(EBP - 144);  // @30_42fcc0
  reg.state = (s32)((u32)(0));  // @31_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @32_42fcc0
  ecx = edx = 0;  // @33_42fcc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @34_42fcc0
  ecx = (u32)(EBP - 144);  // @35_42fcc0
  p2_ = ecx;  // @36_42fcc0
  ecx = ebx;  // @37_42fcc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(p2_));  // @38_42fcc0
  ecx = edx = 0;  // @39_42fcc0
  p3_ = eax;  // @40_42fcc0
  ecx = esi;  // @41_42fcc0
  reg.state = (s32)((u32)(2));  // @42_42fcc0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p3_));  // @43_42fcc0
  ecx = edx = 0;  // @44_42fcc0
  ecx = (u32)(EBP - 144);  // @45_42fcc0
  reg.state = (s32)((u32)(0));  // @46_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_42fcc0
  ecx = edx = 0;  // @48_42fcc0
  L42fda0:;
  ecx = (u32)(EBP - 144);  // @50_42fcc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789688));  // @51_42fcc0
  ecx = edx = 0;  // @52_42fcc0
  eax = (u32)(EBP - 144);  // @53_42fcc0
  reg.state = (s32)((u32)(3));  // @54_42fcc0
  p4_ = eax;  // @55_42fcc0
  ecx = esi;  // @56_42fcc0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p4_));  // @57_42fcc0
  ecx = edx = 0;  // @58_42fcc0
  ecx = (u32)(EBP - 144);  // @59_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @60_42fcc0
  ecx = edx = 0;  // @61_42fcc0
  eax = esi;  // @62_42fcc0
  SEH_LEAVE();  // @63_42fcc0
  ext_633654(G(u32, 0x6f5630));  // @64_42fcc0
  return eax;  // @65_42fcc0
}
PCREG(42fcc0, lifted_42fcc0);

extern "C" u32 THISCALL lifted_5afef0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66681b);  // @h_5afef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5afef0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5afef0
  ecx = (u32)(EBP - 188);  // @2_5afef0
  eax = ext_4ccba0_thiscall1(ecx);  // @3_5afef0
  ecx = edx = 0;  // @4_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_5afef0
  ecx = esi;  // @6_5afef0
  reg.state = (s32)((u32)(0));  // @7_5afef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @8_5afef0
  ecx = edx = 0;  // @9_5afef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @10_5afef0
  ebx = eax;  // @11_5afef0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7467), sizeof v); (u32)v; });  // @12_5afef0
  eax = (u32)(EBP - 188);  // @13_5afef0
  p0_ = eax;  // @14_5afef0
  p1_ = edx;  // @15_5afef0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5afef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7435), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @17_5afef0
  ecx = edx = 0;  // @18_5afef0
  eax = (u32)(EBP - 200);  // @19_5afef0
  esi = 0;  // @20_5afef0
  p2_ = eax;  // @21_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @22_5afef0
  ecx = (u32)(EBP - 188);  // @23_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @24_5afef0
  ecx = edx = 0;  // @25_5afef0
  eax = (u32)(EBP - 200);  // @26_5afef0
  p3_ = eax;  // @27_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @28_5afef0
  ecx = (u32)(EBP - 188);  // @29_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @30_5afef0
  ecx = edx = 0;  // @31_5afef0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == esi) goto L5affe0;  // @32_5afef0
  L5affa0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_5afef0
  p4_ = eax;  // @35_5afef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @36_5afef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p4_));  // @38_5afef0
  ecx = edx = 0;  // @39_5afef0
  ecx = eax;  // @40_5afef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_5afef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @42_5afef0
  ecx = edx = 0;  // @43_5afef0
  if (eax != ebx) goto L5affc1;  // @44_5afef0
  esi = (esi + 1);  // @45_5afef0
  L5affc1:;
  eax = (u32)(EBP - 200);  // @47_5afef0
  p5_ = eax;  // @48_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @49_5afef0
  ecx = (u32)(EBP - 188);  // @50_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p5_));  // @51_5afef0
  ecx = edx = 0;  // @52_5afef0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L5affa0;  // @53_5afef0
  L5affe0:;
  ecx = (u32)(EBP - 188);  // @55_5afef0
  eax = ext_4ccf60_thiscall1(ecx);  // @56_5afef0
  ecx = edx = 0;  // @57_5afef0
  eax = esi;  // @58_5afef0
  SEH_LEAVE();  // @59_5afef0
  ext_633654(G(u32, 0x6f5630));  // @60_5afef0
  return eax;  // @61_5afef0
}
PCREG(5afef0, lifted_5afef0);

extern "C" u32 THISCALL lifted_441c00(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_441c00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_441c00
  { u32 v = (u32)((u32)(6802876)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_441c00
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L441c50;  // @2_441c00
  L441c33:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @4_441c00
  if ((edi & edi) == 0) goto L441c4a;  // @5_441c00
  ecx = edi;  // @6_441c00
  eax = ext_4d9430_thiscall1(ecx);  // @7_441c00
  ecx = edx = 0;  // @8_441c00
  p0_ = edi;  // @9_441c00
  eax = ext_4d9590_cdecl1((u32)(p0_));  // @10_441c00
  ecx = edx = 0;  // @11_441c00
  L441c4a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) != (u32)(0)) goto L441c33;  // @13_441c00
  L441c50:;
  ecx = esi;  // @15_441c00
  eax = ext_45f420_thiscall1(ecx);  // @16_441c00
  ecx = edx = 0;  // @17_441c00
  if ((eax & eax) == 0) goto L441c8a;  // @18_441c00
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; }) != (u32)(0)) goto L441c8a;  // @19_441c00
  ecx = esi;  // @20_441c00
  eax = ext_45f420_thiscall1(ecx);  // @21_441c00
  ecx = edx = 0;  // @22_441c00
  if ((eax & eax) == 0) goto L441c8a;  // @23_441c00
  ecx = esi;  // @24_441c00
  eax = ext_45f420_thiscall1(ecx);  // @25_441c00
  ecx = edx = 0;  // @26_441c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @27_441c00
  eax = ext_4db7e0_thiscall1(ecx);  // @28_441c00
  ecx = edx = 0;  // @29_441c00
  if ((eax & eax) == 0) goto L441c8a;  // @30_441c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_441c00
  ecx = eax;  // @32_441c00
  p1_ = esi;  // @33_441c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 716)))(ecx, (u32)(p1_));  // @34_441c00
  ecx = edx = 0;  // @35_441c00
  L441c8a:;
  edi = (u32)(esi + 93);  // @37_441c00
  ebx = (u32)(5);  // @38_441c00
  L441c92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_441c00
  if ((ecx & ecx) == 0) goto L441ca5;  // @41_441c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_441c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(1));  // @43_441c00
  ecx = edx = 0;  // @44_441c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @45_441c00
  L441ca5:;
  edi = (edi + (u32)(4));  // @47_441c00
  ebx = (ebx - (u32)(1));  // @48_441c00
  if (ebx != 0) goto L441c92;  // @49_441c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @50_441c00
  if ((edi & edi) == 0) goto L441cc9;  // @51_441c00
  ecx = edi;  // @52_441c00
  eax = ext_4e3f00_thiscall1(ecx);  // @53_441c00
  ecx = edx = 0;  // @54_441c00
  p2_ = edi;  // @55_441c00
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(45));  // @56_441c00
  ecx = edx = 0;  // @57_441c00
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @58_441c00
  L441cc9:;
  ecx = esi;  // @60_441c00
  eax = ext_43ea20_thiscall1(ecx);  // @61_441c00
  ecx = edx = 0;  // @62_441c00
  SEH_LEAVE();  // @63_441c00
  return eax;  // @64_441c00
}
PCREG(441c00, lifted_441c00);

extern "C" u32 THISCALL lifted_433220(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665580);  // @h_433220
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_433220
  ecx = (u32)(ebx + 200);  // @2_433220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @4_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 200), sizeof v); (u32)v; });  // @5_433220
  p0_ = edi;  // @6_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @7_433220
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p0_));  // @8_433220
  ecx = edx = 0;  // @9_433220
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L433288;  // @10_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 200), sizeof v); (u32)v; });  // @11_433220
  ecx = (u32)(ebx + 200);  // @12_433220
  p1_ = edi;  // @13_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(p1_));  // @14_433220
  ecx = edx = 0;  // @15_433220
  L433288:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 172), sizeof v); (u32)v; });  // @17_433220
  ecx = (u32)(ebx + 172);  // @18_433220
  p2_ = edi;  // @19_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p2_));  // @20_433220
  ecx = edx = 0;  // @21_433220
  esi = eax;  // @22_433220
  if ((esi & esi) != 0) goto L4332f3;  // @23_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 172), sizeof v); (u32)v; });  // @24_433220
  ecx = (u32)(ebx + 172);  // @25_433220
  p3_ = edi;  // @26_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(p3_));  // @27_433220
  ecx = edx = 0;  // @28_433220
  esi = eax;  // @29_433220
  eax = ext_41e290_cdecl1((u32)(128));  // @30_433220
  ecx = edx = 0;  // @31_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @32_433220
  reg.state = (s32)((u32)(0));  // @33_433220
  if ((eax & eax) == 0) goto L4332e6;  // @34_433220
  ecx = eax;  // @35_433220
  eax = ext_4cbeb0_thiscall1(ecx);  // @36_433220
  ecx = edx = 0;  // @37_433220
  reg.state = (s32)((u32)(4294967295));  // @38_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @39_433220
  goto L4332f6;  // @40_433220
  L4332e6:;
  eax = 0;  // @42_433220
  reg.state = (s32)((u32)(4294967295));  // @43_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @44_433220
  goto L4332f6;  // @45_433220
  L4332f3:;
  esi = (esi + (u32)(4));  // @47_433220
  L4332f6:;
  ecx = (u32)(EBP - 144);  // @49_433220
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @50_433220
  ecx = edx = 0;  // @51_433220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_433220
  eax = (u32)(EBP - 144);  // @53_433220
  p4_ = eax;  // @54_433220
  reg.state = (s32)((u32)(1));  // @55_433220
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p4_));  // @56_433220
  ecx = edx = 0;  // @57_433220
  ecx = (u32)(EBP - 144);  // @58_433220
  eax = ext_4cbec0_thiscall1(ecx);  // @59_433220
  ecx = edx = 0;  // @60_433220
  SEH_LEAVE();  // @61_433220
  ext_633654(G(u32, 0x6f5630));  // @62_433220
  return eax;  // @63_433220
}
PCREG(433220, lifted_433220);

extern "C" u32 THISCALL lifted_5384b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66a90d);  // @h_5384b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5384b0
  ecx = (u32)(EBP - 144);  // @2_5384b0
  p0_ = eax;  // @3_5384b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_5384b0
  ecx = edx = 0;  // @5_5384b0
  eax = (u32)(EBP - 144);  // @6_5384b0
  reg.state = (s32)((u32)(0));  // @7_5384b0
  p1_ = eax;  // @8_5384b0
  ecx = (u32)(esi + 20921);  // @9_5384b0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @10_5384b0
  ecx = edx = 0;  // @11_5384b0
  ecx = (u32)(EBP - 144);  // @12_5384b0
  reg.state = (s32)((u32)(4294967295));  // @13_5384b0
  eax = ext_4cbec0_thiscall1(ecx);  // @14_5384b0
  ecx = edx = 0;  // @15_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_5384b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @17_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5384b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6942756), (u32)(0), (u32)(6954540), (u32)(429));  // @19_5384b0
  ecx = edx = 0;  // @20_5384b0
  ecx = (u32)(esi + 139);  // @21_5384b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 20647), &v, sizeof v); }  // @22_5384b0
  eax = ext_534190_thiscall1(ecx);  // @23_5384b0
  ecx = edx = 0;  // @24_5384b0
  eax = ext_41e290_cdecl1((u32)(26));  // @25_5384b0
  ecx = edx = 0;  // @26_5384b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @27_5384b0
  reg.state = (s32)((u32)(1));  // @28_5384b0
  if ((eax & eax) == 0) goto L538572;  // @29_5384b0
  ecx = eax;  // @30_5384b0
  eax = ext_53a810_thiscall1(ecx);  // @31_5384b0
  ecx = edx = 0;  // @32_5384b0
  goto L538574;  // @33_5384b0
  L538572:;
  eax = 0;  // @35_5384b0
  L538574:;
  ecx = eax;  // @37_5384b0
  reg.state = (s32)((u32)(4294967295));  // @38_5384b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21242), &v, sizeof v); }  // @39_5384b0
  eax = ext_4690b0_cdecl0();  // @40_5384b0
  ecx = edx = 0;  // @41_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_5384b0
  ecx = esi;  // @43_5384b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20909), &v, sizeof v); }  // @44_5384b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @45_5384b0
  ecx = edx = 0;  // @46_5384b0
  if ((eax & eax) == 0) goto L5385ad;  // @47_5384b0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @48_5384b0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @49_5384b0
  L5385ad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_5384b0
  ecx = esi;  // @52_5384b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 352)))(ecx, (u32)(128));  // @53_5384b0
  ecx = edx = 0;  // @54_5384b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; }) == (u32)(0)) goto L5385d5;  // @55_5384b0
  L5385c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_5384b0
  ecx = esi;  // @58_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 412), sizeof v); (u32)v; });  // @59_5384b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @60_5384b0
  ecx = edx = 0;  // @61_5384b0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5385c5;  // @62_5384b0
  L5385d5:;
  SEH_LEAVE();  // @64_5384b0
  ext_633654(G(u32, 0x6f5630));  // @65_5384b0
  return eax;  // @66_5384b0
}
PCREG(5384b0, lifted_5384b0);

extern "C" u32 THISCALL lifted_4c4630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4c4630
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4c4630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4c4630
  eax = (u32)(edi + 130);  // @2_4c4630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4c4630
  ecx = esi;  // @4_4c4630
  p0_ = eax;  // @5_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p0_));  // @7_4c4630
  ecx = edx = 0;  // @8_4c4630
  ecx = (u32)(edi + 134);  // @9_4c4630
  p1_ = ecx;  // @10_4c4630
  ecx = eax;  // @11_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p1_));  // @13_4c4630
  ecx = edx = 0;  // @14_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_4c4630
  eax = (u32)(edi + 138);  // @16_4c4630
  p2_ = eax;  // @17_4c4630
  ecx = esi;  // @18_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p2_));  // @19_4c4630
  ecx = edx = 0;  // @20_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_4c4630
  eax = (u32)(edi + 142);  // @22_4c4630
  p3_ = eax;  // @23_4c4630
  ecx = esi;  // @24_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p3_));  // @25_4c4630
  ecx = edx = 0;  // @26_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_4c4630
  eax = (u32)(edi + 146);  // @28_4c4630
  p4_ = eax;  // @29_4c4630
  ecx = esi;  // @30_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p4_));  // @31_4c4630
  ecx = edx = 0;  // @32_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_4c4630
  eax = (u32)(edi + 150);  // @34_4c4630
  p5_ = eax;  // @35_4c4630
  ecx = esi;  // @36_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p5_));  // @37_4c4630
  ecx = edx = 0;  // @38_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_4c4630
  eax = (u32)(edi + 162);  // @40_4c4630
  p6_ = eax;  // @41_4c4630
  ecx = esi;  // @42_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p6_));  // @43_4c4630
  ecx = edx = 0;  // @44_4c4630
  ecx = (u32)(EBP - 144);  // @45_4c4630
  eax = ext_4cbeb0_thiscall1(ecx);  // @46_4c4630
  ecx = edx = 0;  // @47_4c4630
  eax = (u32)(EBP - 148);  // @48_4c4630
  reg.state = (s32)((u32)(0));  // @49_4c4630
  p7_ = eax;  // @50_4c4630
  ecx = edi;  // @51_4c4630
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @52_4c4630
  eax = ext_6352f0_thiscall2(ecx, (u32)(p7_));  // @53_4c4630
  ecx = edx = 0;  // @54_4c4630
  eax = (u32)(EBP - 144);  // @55_4c4630
  ecx = edi;  // @56_4c4630
  p8_ = eax;  // @57_4c4630
  eax = (u32)(EBP - 152);  // @58_4c4630
  p9_ = eax;  // @59_4c4630
  eax = (u32)(EBP - 148);  // @60_4c4630
  p10_ = eax;  // @61_4c4630
  eax = ext_4c4740_thiscall4(ecx, (u32)(p10_), (u32)(p9_), (u32)(p8_));  // @62_4c4630
  ecx = edx = 0;  // @63_4c4630
  ecx = (u32)(EBP - 144);  // @64_4c4630
  eax = ext_4cbec0_thiscall1(ecx);  // @65_4c4630
  ecx = edx = 0;  // @66_4c4630
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @67_4c4630
  SEH_LEAVE();  // @68_4c4630
  ext_633654(G(u32, 0x6f5630));  // @69_4c4630
  return eax;  // @70_4c4630
}
PCREG(4c4630, lifted_4c4630);

extern "C" u32 THISCALL lifted_444eb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_444eb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_444eb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_444eb0
  p0_ = esi;  // @2_444eb0
  eax = ext_440e10_thiscall2(ecx, (u32)(p0_));  // @3_444eb0
  ecx = edx = 0;  // @4_444eb0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L444ef7;  // @5_444eb0
  SEH_LEAVE();  // @6_444eb0
  return eax;  // @7_444eb0
  L444ef7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_444eb0
  eax = (u32)(edi + 148);  // @10_444eb0
  p1_ = eax;  // @11_444eb0
  ecx = esi;  // @12_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p1_));  // @13_444eb0
  ecx = edx = 0;  // @14_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_444eb0
  eax = (u32)(edi + 152);  // @16_444eb0
  p2_ = eax;  // @17_444eb0
  ecx = esi;  // @18_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p2_));  // @19_444eb0
  ecx = edx = 0;  // @20_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_444eb0
  eax = (u32)(edi + 192);  // @22_444eb0
  p3_ = eax;  // @23_444eb0
  ecx = esi;  // @24_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p3_));  // @25_444eb0
  ecx = edx = 0;  // @26_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_444eb0
  ecx = (u32)(EBP + 8);  // @28_444eb0
  p4_ = ecx;  // @29_444eb0
  ecx = esi;  // @30_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p4_));  // @31_444eb0
  ecx = edx = 0;  // @32_444eb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L444f70;  // @33_444eb0
  eax = ext_41e290_cdecl1((u32)(28));  // @34_444eb0
  ecx = edx = 0;  // @35_444eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @36_444eb0
  reg.state = (s32)((u32)(0));  // @37_444eb0
  if ((eax & eax) == 0) goto L444f59;  // @38_444eb0
  ecx = eax;  // @39_444eb0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @40_444eb0
  ecx = edx = 0;  // @41_444eb0
  ecx = eax;  // @42_444eb0
  goto L444f5b;  // @43_444eb0
  L444f59:;
  ecx = 0;  // @45_444eb0
  L444f5b:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 164), &v, sizeof v); }  // @47_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_444eb0
  p5_ = ecx;  // @49_444eb0
  ecx = esi;  // @50_444eb0
  reg.state = (s32)((u32)(4294967295));  // @51_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(p5_));  // @52_444eb0
  ecx = edx = 0;  // @53_444eb0
  L444f70:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_444eb0
  eax = (u32)(edi + 172);  // @56_444eb0
  p6_ = eax;  // @57_444eb0
  ecx = esi;  // @58_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p6_));  // @59_444eb0
  ecx = edx = 0;  // @60_444eb0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @61_444eb0
  SEH_LEAVE();  // @62_444eb0
  return eax;  // @63_444eb0
}
PCREG(444eb0, lifted_444eb0);

extern "C" u32 THISCALL lifted_495b30(u32 ecx_in) {
  SEH_ENTER(0x66dac1);  // @h_495b30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @1_495b30
  { u8 v = (u8)((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }) != (u32)(0))); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_495b30
  eax = ext_4cd9b0_fastcall4(ecx, edx, (u32)(112), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @4_495b30
  ecx = edx = 0;  // @5_495b30
  ebx = eax;  // @6_495b30
  if (ebx != (u32)(-1)) goto L495b9b;  // @7_495b30
  eax = ext_42ab62_cdecl1((u32)(6874268));  // @8_495b30
  ecx = edx = 0;  // @9_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @10_495b30
  if ((ecx & ecx) == 0) goto L495b93;  // @11_495b30
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @12_495b30
  ecx = edx = 0;  // @13_495b30
  goto L495b94;  // @14_495b30
  L495b93:;
  __builtin_trap();  // @16_495b30
  L495b94:;
  ecx = edi;  // @18_495b30
  eax = ext_496a40_thiscall1(ecx);  // @19_495b30
  ecx = edx = 0;  // @20_495b30
  L495b9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @22_495b30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @23_495b30
  eax = (u32)(ebx + 112);  // @24_495b30
  esi = (esi + ebx);  // @25_495b30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_495b30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }) >= eax) goto L495bb1;  // @27_495b30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @28_495b30
  L495bb1:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @30_495b30
  reg.state = (s32)((u32)(0));  // @31_495b30
  if ((esi & esi) == 0) goto L495bc6;  // @32_495b30
  ecx = esi;  // @33_495b30
  eax = ext_4d93e0_thiscall1(ecx);  // @34_495b30
  ecx = edx = 0;  // @35_495b30
  L495bc6:;
  reg.state = (s32)((u32)(4294967295));  // @37_495b30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }) == (u32)(0)) goto L495bdc;  // @38_495b30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) | (u32)(1048576))); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @39_495b30
  goto L495bea;  // @40_495b30
  L495bdc:;
  ecx = esi;  // @42_495b30
  eax = ext_4dc630_thiscall3(ecx, (u32)(134217728), (u32)(0));  // @43_495b30
  ecx = edx = 0;  // @44_495b30
  L495bea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @46_495b30
  if ((ecx & ecx) == 0) goto L495c07;  // @47_495b30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_495b30
  p0_ = ebx;  // @49_495b30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(6873924), (u32)(p0_), (u32)(112));  // @50_495b30
  ecx = edx = 0;  // @51_495b30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @52_495b30
  L495c07:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_495b30
  p1_ = esi;  // @55_495b30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p1_), (u32)(112), (u32)(11468975));  // @56_495b30
  ecx = edx = 0;  // @57_495b30
  eax = esi;  // @58_495b30
  SEH_LEAVE();  // @59_495b30
  return eax;  // @60_495b30
}
PCREG(495b30, lifted_495b30);

extern "C" u32 THISCALL lifted_4ff9d0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_4ff9d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @1_4ff9d0
  edi = 0;  // @2_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_4ff9d0
  eax = (eax - ecx);  // @4_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @5_4ff9d0
  if ((eax & eax) == 0) goto L4ffa30;  // @6_4ff9d0
  L4ffa08:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*4), sizeof v); (u32)v; });  // @8_4ff9d0
  if ((esi & esi) == 0) goto L4ffa21;  // @9_4ff9d0
  ecx = esi;  // @10_4ff9d0
  eax = ext_4ff920_thiscall1(ecx);  // @11_4ff9d0
  ecx = edx = 0;  // @12_4ff9d0
  p0_ = esi;  // @13_4ff9d0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(72));  // @14_4ff9d0
  ecx = edx = 0;  // @15_4ff9d0
  L4ffa21:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @17_4ff9d0
  edi = (edi + 1);  // @18_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_4ff9d0
  eax = (eax - ecx);  // @20_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @21_4ff9d0
  if (edi < eax) goto L4ffa08;  // @22_4ff9d0
  L4ffa30:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @24_4ff9d0
  edx = esi;  // @25_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4ff9d0
  edx = (edx - esi);  // @27_4ff9d0
  edx = (u32)((s32)edx >> (u32)(2));  // @28_4ff9d0
  ecx = eax;  // @29_4ff9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_4ff9d0
  if ((s32)(edx & edx) <= 0) goto L4ffa61;  // @31_4ff9d0
  edi = esi;  // @32_4ff9d0
  edi = (edi - eax);  // @33_4ff9d0
  L4ffa50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx), sizeof v); (u32)v; });  // @35_4ff9d0
  ecx = (u32)(ecx + 4);  // @36_4ff9d0
  edx = (edx - 1);  // @37_4ff9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @38_4ff9d0
  if ((s32)(edx & edx) > 0) goto L4ffa50;  // @39_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @40_4ff9d0
  L4ffa61:;
  esi = (esi - eax);  // @42_4ff9d0
  esi = (u32)((s32)esi >> (u32)(2));  // @43_4ff9d0
  esi = (0u - esi);  // @44_4ff9d0
  esi = (esi << (u32)(2));  // @45_4ff9d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @46_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @47_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @48_4ff9d0
  eax = (eax - ecx);  // @49_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @50_4ff9d0
  reg.state = (s32)((u32)(0));  // @51_4ff9d0
  if ((eax & eax) == 0) goto L4ffa8f;  // @52_4ff9d0
  eax = (eax << (u32)(2));  // @53_4ff9d0
  p1_ = eax;  // @54_4ff9d0
  p2_ = ecx;  // @55_4ff9d0
  ecx = ebx;  // @56_4ff9d0
  eax = ext_54f870_stdcall2((u32)(p2_), (u32)(p1_));  // @57_4ff9d0
  ecx = edx = 0;  // @58_4ff9d0
  L4ffa8f:;
  SEH_LEAVE();  // @60_4ff9d0
  return eax;  // @61_4ff9d0
}
PCREG(4ff9d0, lifted_4ff9d0);

extern "C" u32 THISCALL lifted_5812c0(u32 ecx_in) {
  SEH_ENTER(0x66c588);  // @h_5812c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_5812c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5812c0
  eax = ext_469870_thiscall1(ecx);  // @2_5812c0
  ecx = edx = 0;  // @3_5812c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5812c0
  reg.state = (s32)((u32)(0));  // @6_5812c0
  edi = (u32)(esi + 157);  // @7_5812c0
  { u32 v = (u32)((u32)(6993488)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5812c0
  ebx = (u32)(5);  // @9_5812c0
  L581313:;
  ecx = edi;  // @11_5812c0
  eax = ext_4e7160_thiscall1(ecx);  // @12_5812c0
  ecx = edx = 0;  // @13_5812c0
  edi = (edi + (u32)(44));  // @14_5812c0
  ebx = (ebx - (u32)(1));  // @15_5812c0
  if (ebx != 0) goto L581313;  // @16_5812c0
  eax = (u32)(esi + 522);  // @17_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 862), &v, sizeof v); }  // @18_5812c0
  p0_ = ebx;  // @19_5812c0
  p1_ = eax;  // @20_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 866), &v, sizeof v); }  // @21_5812c0
  { u32 v = (u32)((u32)(1012560910)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @22_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @23_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @24_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @25_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 878), &v, sizeof v); }  // @26_5812c0
  eax = ext_634d10_cdecl3((u32)(p1_), (u32)(p0_), (u32)(340));  // @27_5812c0
  ecx = edx = 0;  // @28_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5812c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; }) == ebx) goto L5813a2;  // @30_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 878), &v, sizeof v); }  // @31_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_5812c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @33_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_5812c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(6993720));  // @35_5812c0
  ecx = edx = 0;  // @36_5812c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 870), &v, sizeof v); }  // @37_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_5812c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @39_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5812c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(6993740));  // @41_5812c0
  ecx = edx = 0;  // @42_5812c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 874), &v, sizeof v); }  // @43_5812c0
  L5813a2:;
  ecx = 0;  // @45_5812c0
  edx = (u32)(esi + 377);  // @46_5812c0
  eax = (u32)(esi + 466);  // @47_5812c0
  L5813b0:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @49_5812c0
  edx = (u32)(edx + 4);  // @50_5812c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + ecx + 457), &v, sizeof v); }  // @51_5812c0
  eax = (u32)(eax + 12);  // @52_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 8), &v, sizeof v); }  // @53_5812c0
  ecx = (ecx + 1);  // @54_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 12), &v, sizeof v); }  // @55_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 16), &v, sizeof v); }  // @56_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 73), &v, sizeof v); }  // @57_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 77), &v, sizeof v); }  // @58_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 81), &v, sizeof v); }  // @59_5812c0
  if (ecx < (u32)(5)) goto L5813b0;  // @60_5812c0
  eax = esi;  // @61_5812c0
  SEH_LEAVE();  // @62_5812c0
  return eax;  // @63_5812c0
}
PCREG(5812c0, lifted_5812c0);

extern "C" u32 THISCALL lifted_6041e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66dd06);  // @h_6041e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_6041e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6041e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6041e0
  p0_ = edi;  // @3_6041e0
  eax = ext_603430_thiscall3(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @4_6041e0
  ecx = edx = 0;  // @5_6041e0
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_6041e0
  eax = (u32)(esi + 12);  // @7_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @8_6041e0
  ecx = (u32)(EBP - 28);  // @9_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @10_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @11_6041e0
  reg.state = (s32)((u32)(0));  // @12_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @13_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @14_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @15_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @16_6041e0
  eax = ext_6014a0_stdcall1((u32)(8));  // @17_6041e0
  ecx = edx = 0;  // @18_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @19_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @20_6041e0
  ecx = (u32)(eax + 8);  // @21_6041e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @22_6041e0
  if ((eax & eax) == 0) goto L604272;  // @23_6041e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @24_6041e0
  L604272:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @26_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_6041e0
  ecx = (u32)(EBP - 28);  // @28_6041e0
  p1_ = ecx;  // @29_6041e0
  ecx = edi;  // @30_6041e0
  reg.state = (s32)((u32)(1));  // @31_6041e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p1_));  // @32_6041e0
  ecx = edx = 0;  // @33_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @34_6041e0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @35_6041e0
  if (eax <= (u32)(32)) goto L60429d;  // @36_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @37_6041e0
  if ((eax & eax) == 0) goto L60429c;  // @38_6041e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @39_6041e0
  ecx = edx = 0;  // @40_6041e0
  goto L60429d;  // @41_6041e0
  L60429c:;
  __builtin_trap();  // @43_6041e0
  L60429d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7488120), sizeof v); (u32)v; });  // @45_6041e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @46_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_6041e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @48_6041e0
  ecx = edx = 0;  // @49_6041e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @50_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @51_6041e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @52_6041e0
  eax = (eax - ecx);  // @53_6041e0
  reg.state = (s32)((u32)(2));  // @54_6041e0
  if ((ecx & ecx) == 0) goto L6042ce;  // @55_6041e0
  if ((eax & eax) == 0) goto L6042ce;  // @56_6041e0
  p2_ = eax;  // @57_6041e0
  p3_ = ecx;  // @58_6041e0
  ecx = (u32)(EBP - 28);  // @59_6041e0
  eax = ext_54f870_stdcall2((u32)(p3_), (u32)(p2_));  // @60_6041e0
  ecx = edx = 0;  // @61_6041e0
  L6042ce:;
  eax = esi;  // @63_6041e0
  SEH_LEAVE();  // @64_6041e0
  return eax;  // @65_6041e0
}
PCREG(6041e0, lifted_6041e0);

extern "C" u32 THISCALL lifted_435470(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6657fd);  // @h_435470
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_435470
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_435470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_435470
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L4354e3;  // @3_435470
  eax = ext_41e290_cdecl1((u32)(28));  // @4_435470
  ecx = edx = 0;  // @5_435470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @6_435470
  reg.state = (s32)((u32)(0));  // @7_435470
  if ((eax & eax) == 0) goto L4354d7;  // @8_435470
  ecx = eax;  // @9_435470
  eax = ext_4ccd10_thiscall3(ecx, (u32)(8), (u32)(0));  // @10_435470
  ecx = edx = 0;  // @11_435470
  goto L4354d9;  // @12_435470
  L4354d7:;
  eax = 0;  // @14_435470
  L4354d9:;
  reg.state = (s32)((u32)(4294967295));  // @16_435470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @17_435470
  L4354e3:;
  p0_ = esi;  // @19_435470
  ecx = (u32)(EBP - 144);  // @20_435470
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @21_435470
  ecx = edx = 0;  // @22_435470
  ecx = (u32)(EBP - 144);  // @23_435470
  reg.state = (s32)((u32)(1));  // @24_435470
  eax = ext_4cc1d0_thiscall1(ecx);  // @25_435470
  ecx = edx = 0;  // @26_435470
  edi = eax;  // @27_435470
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) == (u32)(0)) goto L43554d;  // @28_435470
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775380), sizeof v); (u32)v; });  // @29_435470
  L435510:;
  p1_ = edi;  // @31_435470
  eax = ((u32(STDCALL *)(u32, u32))(ebx))((u32)(p1_), (u32)(59));  // @32_435470
  ecx = edx = 0;  // @33_435470
  esi = eax;  // @34_435470
  if ((esi & esi) != 0) goto L43552f;  // @35_435470
  eax = edi;  // @36_435470
  edx = (u32)(eax + 1);  // @37_435470
  L435523:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @39_435470
  eax = (eax + 1);  // @40_435470
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L435523;  // @41_435470
  eax = (eax - edx);  // @42_435470
  esi = (u32)(eax + edi);  // @43_435470
  L43552f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @45_435470
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @46_435470
  p2_ = edi;  // @47_435470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @48_435470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_435470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(p2_));  // @50_435470
  ecx = edx = 0;  // @51_435470
  edi = (u32)(esi + 1);  // @52_435470
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L435510;  // @53_435470
  L43554d:;
  ecx = (u32)(EBP - 144);  // @55_435470
  eax = ext_4cbec0_thiscall1(ecx);  // @56_435470
  ecx = edx = 0;  // @57_435470
  SEH_LEAVE();  // @58_435470
  ext_633654(G(u32, 0x6f5630));  // @59_435470
  return eax;  // @60_435470
}
PCREG(435470, lifted_435470);

extern "C" u32 THISCALL lifted_4bdf20(u32 ecx_in) {
  SEH_ENTER(0x66c468);  // @h_4bdf20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4bdf20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4bdf20
  eax = ext_469870_thiscall1(ecx);  // @2_4bdf20
  ecx = edx = 0;  // @3_4bdf20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4bdf20
  { u32 v = (u32)((u32)(6895992)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @7_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_4bdf20
  reg.state = (s32)((u32)(0));  // @10_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892948), (u32)(0), (u32)(6896704), (u32)(2657));  // @12_4bdf20
  ecx = edx = 0;  // @13_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @14_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892972), (u32)(0), (u32)(6896704), (u32)(2658));  // @18_4bdf20
  ecx = edx = 0;  // @19_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 78), &v, sizeof v); }  // @20_4bdf20
  { u32 v = (u32)((u32)(257)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @21_4bdf20
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @22_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 85), &v, sizeof v); }  // @23_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @24_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @25_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @26_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @27_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }  // @28_4bdf20
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @29_4bdf20
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @30_4bdf20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @31_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @32_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @33_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891112), (u32)(0), (u32)(6896704), (u32)(2676));  // @37_4bdf20
  ecx = edx = 0;  // @38_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @39_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891132), (u32)(0), (u32)(6896704), (u32)(2677));  // @43_4bdf20
  ecx = edx = 0;  // @44_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @45_4bdf20
  eax = (u32)(esi + 128);  // @46_4bdf20
  p0_ = eax;  // @47_4bdf20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @48_4bdf20
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(256));  // @49_4bdf20
  ecx = edx = 0;  // @50_4bdf20
  eax = esi;  // @51_4bdf20
  SEH_LEAVE();  // @52_4bdf20
  return eax;  // @53_4bdf20
}
PCREG(4bdf20, lifted_4bdf20);

extern "C" u32 THISCALL lifted_607a20(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e06b);  // @h_607a20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @0_607a20
  ecx = esi;  // @1_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 262220), &v, sizeof v); }  // @3_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 262216), &v, sizeof v); }  // @5_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_607a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @7_607a20
  ecx = edx = 0;  // @8_607a20
  edi = eax;  // @9_607a20
  { u32 v = (u32)((u32)(4278255360)); __builtin_memcpy((void *)(u32)(EBP - 262212), &v, sizeof v); }  // @10_607a20
  ebx = 0;  // @11_607a20
  edx = (u32)(EBP - 262160);  // @12_607a20
  L607a82:;
  ecx = 0;  // @14_607a20
  L607a84:;
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @16_607a20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) ^ (ecx & 0xff))) & 0xff);  // @17_607a20
  eax = (u32)(4294901760);  // @18_607a20
  if (((eax & 0xff) & (u32)(1)) != 0) eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262212), sizeof v); (u32)v; });  // @19_607a20
  ecx = (ecx + 1);  // @20_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @21_607a20
  edx = (edx + (u32)(4));  // @22_607a20
  if (ecx < (u32)(256)) goto L607a84;  // @23_607a20
  ebx = (ebx + 1);  // @24_607a20
  if (ebx < (u32)(256)) goto L607a82;  // @25_607a20
  eax = (u32)(EBP - 262160);  // @26_607a20
  ecx = (u32)(EBP - 262208);  // @27_607a20
  p0_ = eax;  // @28_607a20
  eax = ext_636020_thiscall9(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262220), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262216), sizeof v); (u32)v; }), (u32)(16711680), (u32)(65280), (u32)(255), (u32)(4278190080), (u32)(0));  // @29_607a20
  ecx = edx = 0;  // @30_607a20
  ecx = (u32)(EBP - 262208);  // @31_607a20
  reg.state = (s32)((u32)(0));  // @32_607a20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 262180), &v, sizeof v); }  // @33_607a20
  eax = ext_639d00_thiscall2(ecx, (u32)(7053240));  // @34_607a20
  ecx = edx = 0;  // @35_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_607a20
  ecx = esi;  // @37_607a20
  p1_ = edi;  // @38_607a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_), (u32)(0));  // @39_607a20
  ecx = edx = 0;  // @40_607a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_607a20
  ecx = esi;  // @42_607a20
  p2_ = eax;  // @43_607a20
  eax = (u32)(EBP - 262208);  // @44_607a20
  p3_ = eax;  // @45_607a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(p3_), (u32)(p2_));  // @46_607a20
  ecx = edx = 0;  // @47_607a20
  ecx = (u32)(EBP - 262208);  // @48_607a20
  eax = ext_6363a0_thiscall1(ecx);  // @49_607a20
  ecx = edx = 0;  // @50_607a20
  eax = edi;  // @51_607a20
  SEH_LEAVE();  // @52_607a20
  ext_633654(G(u32, 0x6f5630));  // @53_607a20
  return eax;  // @54_607a20
}
PCREG(607a20, lifted_607a20);

extern "C" u32 THISCALL lifted_434ad0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664256);  // @h_434ad0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @1_434ad0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_434ad0
  if ((ecx & ecx) == 0) goto L434bd2;  // @3_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_434ad0
  edx = (u32)(EBP - 284);  // @5_434ad0
  p0_ = edx;  // @6_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @7_434ad0
  ecx = edx = 0;  // @8_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_434ad0
  edx = (u32)(EBP - 284);  // @10_434ad0
  p1_ = edx;  // @11_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @13_434ad0
  ecx = edx = 0;  // @14_434ad0
  esi = eax;  // @15_434ad0
  if ((esi & esi) == 0) goto L434bd2;  // @16_434ad0
  L434b33:;
  ecx = (u32)(EBP - 144);  // @18_434ad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @19_434ad0
  ecx = edx = 0;  // @20_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_434ad0
  ecx = (u32)(EBP - 272);  // @22_434ad0
  reg.state = (s32)((u32)(0));  // @23_434ad0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13), sizeof v); (u32)v; }));  // @24_434ad0
  ecx = edx = 0;  // @25_434ad0
  eax = (u32)(EBP - 272);  // @26_434ad0
  reg.state = (s32)((u32)(1));  // @27_434ad0
  p2_ = eax;  // @28_434ad0
  ecx = (u32)(EBP - 144);  // @29_434ad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @30_434ad0
  ecx = edx = 0;  // @31_434ad0
  ecx = (u32)(EBP - 272);  // @32_434ad0
  reg.state = (s32)((u32)(0));  // @33_434ad0
  eax = ext_4cbec0_thiscall1(ecx);  // @34_434ad0
  ecx = edx = 0;  // @35_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @36_434ad0
  ecx = (u32)(EBP - 144);  // @37_434ad0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_434ad0
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @39_434ad0
  ecx = edx = 0;  // @40_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @41_434ad0
  p3_ = eax;  // @42_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(p3_));  // @43_434ad0
  ecx = edx = 0;  // @44_434ad0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @45_434ad0
  ecx = 0;  // @46_434ad0
  if ((s32)(eax & eax) < 0) eax = ecx;  // @47_434ad0
  ecx = ebx;  // @48_434ad0
  p4_ = eax;  // @49_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, (u32)(p4_));  // @50_434ad0
  ecx = edx = 0;  // @51_434ad0
  ecx = (u32)(EBP - 144);  // @52_434ad0
  reg.state = (s32)((u32)(4294967295));  // @53_434ad0
  eax = ext_4cbec0_thiscall1(ecx);  // @54_434ad0
  ecx = edx = 0;  // @55_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @56_434ad0
  edx = (u32)(EBP - 284);  // @57_434ad0
  p5_ = edx;  // @58_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p5_));  // @60_434ad0
  ecx = edx = 0;  // @61_434ad0
  esi = eax;  // @62_434ad0
  if ((esi & esi) != 0) goto L434b33;  // @63_434ad0
  L434bd2:;
  SEH_LEAVE();  // @65_434ad0
  ext_633654(G(u32, 0x6f5630));  // @66_434ad0
  return eax;  // @67_434ad0
}
PCREG(434ad0, lifted_434ad0);

extern "C" u32 THISCALL lifted_537cc0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_537cc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_537cc0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; })) & 0xff);  // @1_537cc0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_537cc0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L537dd5;  // @3_537cc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_537cc0
  if (edi != (u32)(-1)) goto L537d10;  // @5_537cc0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @6_537cc0
  goto L537dd7;  // @7_537cc0
  L537d10:;
  ecx = (u32)(EBP - 144);  // @9_537cc0
  eax = ext_4cbeb0_thiscall1(ecx);  // @10_537cc0
  ecx = edx = 0;  // @11_537cc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @12_537cc0
  edx = (u32)(EBP - 272);  // @13_537cc0
  p0_ = ebx;  // @14_537cc0
  p1_ = edx;  // @15_537cc0
  reg.state = (s32)((u32)(0));  // @16_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_537cc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(p1_), (u32)(p0_));  // @18_537cc0
  ecx = edx = 0;  // @19_537cc0
  p2_ = eax;  // @20_537cc0
  ecx = (u32)(EBP - 144);  // @21_537cc0
  reg.state = (s32)((u32)(1));  // @22_537cc0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @23_537cc0
  ecx = edx = 0;  // @24_537cc0
  ecx = (u32)(EBP - 272);  // @25_537cc0
  reg.state = (s32)((u32)(0));  // @26_537cc0
  eax = ext_4cbec0_thiscall1(ecx);  // @27_537cc0
  ecx = edx = 0;  // @28_537cc0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @29_537cc0
  ecx = (u32)(EBP - 144);  // @30_537cc0
  { u32 v = (u32)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @31_537cc0
  { u32 v = (u32)((u32)(140)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @32_537cc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @33_537cc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @34_537cc0
  ecx = edx = 0;  // @35_537cc0
  edx = (u32)(ebx + 12);  // @36_537cc0
  edx = (edx - eax);  // @37_537cc0
  L537d80:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @39_537cc0
  eax = (u32)(eax + 1);  // @40_537cc0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @41_537cc0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L537d80;  // @42_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @43_537cc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @44_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @45_537cc0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @46_537cc0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @47_537cc0
  L537db0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_537cc0
  ecx = esi;  // @50_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 412), sizeof v); (u32)v; });  // @51_537cc0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @52_537cc0
  ecx = edx = 0;  // @53_537cc0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L537db0;  // @54_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_537cc0
  ecx = esi;  // @56_537cc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 356)))(ecx);  // @57_537cc0
  ecx = edx = 0;  // @58_537cc0
  ecx = (u32)(EBP - 144);  // @59_537cc0
  eax = ext_4cbec0_thiscall1(ecx);  // @60_537cc0
  ecx = edx = 0;  // @61_537cc0
  L537dd5:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @63_537cc0
  L537dd7:;
  SEH_LEAVE();  // @65_537cc0
  ext_633654(G(u32, 0x6f5630));  // @66_537cc0
  return eax;  // @67_537cc0
}
PCREG(537cc0, lifted_537cc0);

extern "C" u32 THISCALL lifted_4affa0(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4affa0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6886756));  // @3_4affa0
  ecx = edx = 0;  // @4_4affa0
  ecx = eax;  // @5_4affa0
  if ((ecx & ecx) != 0) goto L4b0049;  // @6_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @7_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2434));  // @9_4affa0
  ecx = edx = 0;  // @10_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @11_4affa0
  edi = eax;  // @12_4affa0
  eax = (u32)(EBP - 144);  // @13_4affa0
  p0_ = eax;  // @14_4affa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p0_), (u32)(1));  // @16_4affa0
  ecx = edx = 0;  // @17_4affa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_4affa0
  ecx = eax;  // @19_4affa0
  reg.state = (s32)((u32)(0));  // @20_4affa0
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_4affa0
  ecx = edx = 0;  // @22_4affa0
  p1_ = eax;  // @23_4affa0
  p2_ = edi;  // @24_4affa0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p2_), (u32)(6890800), (u32)(p1_));  // @25_4affa0
  ecx = edx = 0;  // @26_4affa0
  reg.state = (s32)((u32)(4294967295));  // @27_4affa0
  ecx = (u32)(EBP - 144);  // @28_4affa0
  eax = ext_4cbec0_thiscall1(ecx);  // @29_4affa0
  ecx = edx = 0;  // @30_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_4affa0
  ecx = ebx;  // @32_4affa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @33_4affa0
  ecx = edx = 0;  // @34_4affa0
  goto L4b00a4;  // @35_4affa0
  L4b0049:;
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) < (s32)(u32)(0)) goto L4b0058;  // @37_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4affa0
  p3_ = ebx;  // @39_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p3_));  // @40_4affa0
  ecx = edx = 0;  // @41_4affa0
  L4b0058:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @44_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4affa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @46_4affa0
  ecx = edx = 0;  // @47_4affa0
  ecx = (u32)(EBP - 148);  // @48_4affa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @49_4affa0
  p4_ = ecx;  // @50_4affa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @51_4affa0
  ecx = eax;  // @52_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6889580), (u32)(p4_));  // @53_4affa0
  ecx = edx = 0;  // @54_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @56_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @58_4affa0
  ecx = edx = 0;  // @59_4affa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @60_4affa0
  L4b00a4:;
  SEH_LEAVE();  // @62_4affa0
  ext_633654(G(u32, 0x6f5630));  // @63_4affa0
  return eax;  // @64_4affa0
}
PCREG(4affa0, lifted_4affa0);

extern "C" u32 THISCALL lifted_441e40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665e4f);  // @h_441e40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_441e40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; }) != (u32)(0)) goto L441ecd;  // @1_441e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338344), sizeof v); (u32)v; });  // @2_441e40
  if ((ecx & ecx) != 0) goto L441eb0;  // @3_441e40
  eax = ext_41e290_cdecl1((u32)(40));  // @4_441e40
  ecx = edx = 0;  // @5_441e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_441e40
  reg.state = (s32)((u32)(0));  // @7_441e40
  if ((eax & eax) == 0) goto L441ea1;  // @8_441e40
  ecx = eax;  // @9_441e40
  eax = ext_4cca60_thiscall3(ecx, (u32)(1), (u32)(288));  // @10_441e40
  ecx = edx = 0;  // @11_441e40
  ecx = eax;  // @12_441e40
  goto L441ea3;  // @13_441e40
  L441ea1:;
  ecx = 0;  // @15_441e40
  L441ea3:;
  reg.state = (s32)((u32)(4294967295));  // @17_441e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7338344), &v, sizeof v); }  // @18_441e40
  L441eb0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_441e40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @21_441e40
  ecx = edx = 0;  // @22_441e40
  eax = (eax + (u32)(-4));  // @23_441e40
  p0_ = eax;  // @24_441e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @25_441e40
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(1156));  // @26_441e40
  ecx = edx = 0;  // @27_441e40
  L441ecd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @29_441e40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_441e40
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @31_441e40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 1028), &v, sizeof v); }  // @32_441e40
  ecx = esi;  // @33_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @34_441e40
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 2), &v, sizeof v); }  // @35_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 784), sizeof v); (u32)v; });  // @37_441e40
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @38_441e40
  ecx = edx = 0;  // @39_441e40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L441f2b;  // @40_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_441e40
  ecx = esi;  // @42_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @43_441e40
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @44_441e40
  ecx = edx = 0;  // @45_441e40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L441f2b;  // @46_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_441e40
  ecx = esi;  // @48_441e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @49_441e40
  ecx = edx = 0;  // @50_441e40
  if ((eax & eax) == 0) goto L441f2b;  // @51_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_441e40
  ecx = esi;  // @53_441e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @54_441e40
  ecx = edx = 0;  // @55_441e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @56_441e40
  eax = ext_4db7e0_thiscall1(ecx);  // @57_441e40
  ecx = edx = 0;  // @58_441e40
  if ((eax & eax) == 0) goto L441f2b;  // @59_441e40
  p1_ = edi;  // @60_441e40
  ecx = eax;  // @61_441e40
  eax = ext_441e40_thiscall2(ecx, (u32)(p1_));  // @62_441e40
  ecx = edx = 0;  // @63_441e40
  L441f2b:;
  SEH_LEAVE();  // @65_441e40
  return eax;  // @66_441e40
}
PCREG(441e40, lifted_441e40);

extern "C" u32 THISCALL lifted_442050(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665e4f);  // @h_442050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_442050
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; }) != (u32)(0)) goto L4420dd;  // @1_442050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338344), sizeof v); (u32)v; });  // @2_442050
  if ((ecx & ecx) != 0) goto L4420c0;  // @3_442050
  eax = ext_41e290_cdecl1((u32)(40));  // @4_442050
  ecx = edx = 0;  // @5_442050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_442050
  reg.state = (s32)((u32)(0));  // @7_442050
  if ((eax & eax) == 0) goto L4420b1;  // @8_442050
  ecx = eax;  // @9_442050
  eax = ext_4cca60_thiscall3(ecx, (u32)(1), (u32)(288));  // @10_442050
  ecx = edx = 0;  // @11_442050
  ecx = eax;  // @12_442050
  goto L4420b3;  // @13_442050
  L4420b1:;
  ecx = 0;  // @15_442050
  L4420b3:;
  reg.state = (s32)((u32)(4294967295));  // @17_442050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7338344), &v, sizeof v); }  // @18_442050
  L4420c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_442050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @21_442050
  ecx = edx = 0;  // @22_442050
  eax = (eax + (u32)(-4));  // @23_442050
  p0_ = eax;  // @24_442050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @25_442050
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(1156));  // @26_442050
  ecx = edx = 0;  // @27_442050
  L4420dd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @29_442050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_442050
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_442050
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 4), &v, sizeof v); }  // @32_442050
  ecx = esi;  // @33_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @34_442050
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @35_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 784), sizeof v); (u32)v; });  // @37_442050
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @38_442050
  ecx = edx = 0;  // @39_442050
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L442136;  // @40_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_442050
  ecx = esi;  // @42_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 776), sizeof v); (u32)v; });  // @43_442050
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @44_442050
  ecx = edx = 0;  // @45_442050
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L442136;  // @46_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_442050
  ecx = esi;  // @48_442050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @49_442050
  ecx = edx = 0;  // @50_442050
  if ((eax & eax) == 0) goto L442136;  // @51_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_442050
  ecx = esi;  // @53_442050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @54_442050
  ecx = edx = 0;  // @55_442050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @56_442050
  eax = ext_4db7e0_thiscall1(ecx);  // @57_442050
  ecx = edx = 0;  // @58_442050
  if ((eax & eax) == 0) goto L442136;  // @59_442050
  p1_ = edi;  // @60_442050
  ecx = eax;  // @61_442050
  eax = ext_442050_thiscall2(ecx, (u32)(p1_));  // @62_442050
  ecx = edx = 0;  // @63_442050
  L442136:;
  SEH_LEAVE();  // @65_442050
  return eax;  // @66_442050
}
PCREG(442050, lifted_442050);

extern "C" u32 THISCALL lifted_455200(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6663ea);  // @h_455200
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_455200
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_455200
  eax = ext_43de40_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_455200
  ecx = edx = 0;  // @3_455200
  { u32 v = (u32)((u32)(6826716)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_455200
  edi = (u32)(esi + 28);  // @5_455200
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @6_455200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_455200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_455200
  reg.state = (s32)((u32)(0));  // @9_455200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_455200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6827544), (u32)(0), (u32)(6827288), (u32)(362));  // @11_455200
  ecx = edx = 0;  // @12_455200
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2081), &v, sizeof v); }  // @13_455200
  eax = (u32)(esi + 29);  // @14_455200
  p0_ = eax;  // @15_455200
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(2048));  // @16_455200
  ecx = edx = 0;  // @17_455200
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2083), &v, sizeof v); }  // @18_455200
  eax = ext_41e290_cdecl1((u32)(152580));  // @19_455200
  ecx = edx = 0;  // @20_455200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @21_455200
  if ((eax & eax) == 0) goto L4552c7;  // @22_455200
  ecx = 0;  // @23_455200
  edx = (u32)(eax + 152320);  // @24_455200
  L4552b0:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @26_455200
  edx = (u32)(edx + 4);  // @27_455200
  ecx = (ecx + 1);  // @28_455200
  if (ecx < (u32)(64)) goto L4552b0;  // @29_455200
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(eax + 152576), &v, sizeof v); }  // @30_455200
  goto L4552c9;  // @31_455200
  L4552c7:;
  eax = 0;  // @33_455200
  L4552c9:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2077), &v, sizeof v); }  // @35_455200
  eax = ext_41e290_cdecl1((u32)(264));  // @36_455200
  ecx = edx = 0;  // @37_455200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @38_455200
  reg.state = (s32)((u32)(1));  // @39_455200
  if ((eax & eax) == 0) goto L4552fd;  // @40_455200
  p1_ = edi;  // @41_455200
  ecx = eax;  // @42_455200
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6827580), (u32)(6827556), (u32)(p1_));  // @43_455200
  ecx = edx = 0;  // @44_455200
  edx = eax;  // @45_455200
  goto L4552ff;  // @46_455200
  L4552fd:;
  edx = 0;  // @48_455200
  L4552ff:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @50_455200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_455200
  p2_ = edx;  // @52_455200
  reg.state = (s32)((u32)(0));  // @53_455200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_455200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p2_));  // @55_455200
  ecx = edx = 0;  // @56_455200
  eax = esi;  // @57_455200
  SEH_LEAVE();  // @58_455200
  return eax;  // @59_455200
}
PCREG(455200, lifted_455200);

extern "C" u32 THISCALL lifted_641a40(u32 ecx_in) {
  SEH_ENTER(0x66e926);  // @h_641a40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @1_641a40
  ecx = edx = 0;  // @2_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_641a40
  reg.state = (s32)((u32)(0));  // @4_641a40
  if ((eax & eax) == 0) goto L641a97;  // @5_641a40
  ecx = (u32)(esi + 12);  // @6_641a40
  p0_ = ecx;  // @7_641a40
  ecx = eax;  // @8_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088160), (u32)(0), (u32)(p0_));  // @9_641a40
  ecx = edx = 0;  // @10_641a40
  edx = eax;  // @11_641a40
  goto L641a99;  // @12_641a40
  L641a97:;
  edx = 0;  // @14_641a40
  L641a99:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @16_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_641a40
  p1_ = edx;  // @18_641a40
  reg.state = (s32)((u32)(4294967295));  // @19_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p1_));  // @21_641a40
  ecx = edx = 0;  // @22_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @23_641a40
  ecx = edx = 0;  // @24_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @25_641a40
  reg.state = (s32)((u32)(1));  // @26_641a40
  if ((eax & eax) == 0) goto L641ae3;  // @27_641a40
  ecx = (u32)(esi + 4);  // @28_641a40
  p2_ = ecx;  // @29_641a40
  ecx = eax;  // @30_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088168), (u32)(0), (u32)(p2_));  // @31_641a40
  ecx = edx = 0;  // @32_641a40
  edx = eax;  // @33_641a40
  goto L641ae5;  // @34_641a40
  L641ae3:;
  edx = 0;  // @36_641a40
  L641ae5:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @38_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_641a40
  p3_ = edx;  // @40_641a40
  reg.state = (s32)((u32)(4294967295));  // @41_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p3_));  // @43_641a40
  ecx = edx = 0;  // @44_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @45_641a40
  ecx = edx = 0;  // @46_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @47_641a40
  reg.state = (s32)((u32)(2));  // @48_641a40
  if ((eax & eax) == 0) goto L641b2f;  // @49_641a40
  ecx = (u32)(esi + 8);  // @50_641a40
  p4_ = ecx;  // @51_641a40
  ecx = eax;  // @52_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088176), (u32)(0), (u32)(p4_));  // @53_641a40
  ecx = edx = 0;  // @54_641a40
  edx = eax;  // @55_641a40
  goto L641b31;  // @56_641a40
  L641b2f:;
  edx = 0;  // @58_641a40
  L641b31:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @60_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_641a40
  p5_ = edx;  // @62_641a40
  reg.state = (s32)((u32)(4294967295));  // @63_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p5_));  // @65_641a40
  ecx = edx = 0;  // @66_641a40
  SEH_LEAVE();  // @67_641a40
  return eax;  // @68_641a40
}
PCREG(641a40, lifted_641a40);

extern "C" u32 THISCALL lifted_434bf0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6657bf);  // @h_434bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_434bf0
  eax = ext_41e290_cdecl1((u32)(111));  // @1_434bf0
  ecx = edx = 0;  // @2_434bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @3_434bf0
  reg.state = (s32)((u32)(0));  // @4_434bf0
  if ((eax & eax) == 0) goto L434c3e;  // @5_434bf0
  ecx = eax;  // @6_434bf0
  eax = ext_4d5440_thiscall1(ecx);  // @7_434bf0
  ecx = edx = 0;  // @8_434bf0
  ebx = eax;  // @9_434bf0
  goto L434c40;  // @10_434bf0
  L434c3e:;
  ebx = 0;  // @12_434bf0
  L434c40:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_434bf0
  ecx = esi;  // @15_434bf0
  reg.state = (s32)((u32)(4294967295));  // @16_434bf0
  edx = (u32)(ecx + 1);  // @17_434bf0
  L434c50:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @19_434bf0
  ecx = (ecx + 1);  // @20_434bf0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L434c50;  // @21_434bf0
  ecx = (ecx - edx);  // @22_434bf0
  eax = (u32)(ecx + 1);  // @23_434bf0
  p0_ = eax;  // @24_434bf0
  eax = ext_41e290_cdecl1((u32)(p0_));  // @25_434bf0
  ecx = edx = 0;  // @26_434bf0
  edi = eax;  // @27_434bf0
  edx = esi;  // @28_434bf0
  esi = edi;  // @29_434bf0
  esi = (esi - edx);  // @30_434bf0
  L434c70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @32_434bf0
  edx = (u32)(edx + 1);  // @33_434bf0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(esi + edx - 1), &v, sizeof v); }  // @34_434bf0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L434c70;  // @35_434bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @36_434bf0
  p1_ = edi;  // @37_434bf0
  eax = ((u32( *)(u32, u32))(esi))((u32)(p1_), (u32)(92));  // @38_434bf0
  ecx = edx = 0;  // @39_434bf0
  if ((eax & eax) != 0) goto L434c9b;  // @40_434bf0
  p2_ = edi;  // @41_434bf0
  eax = ((u32( *)(u32, u32))(esi))((u32)(p2_), (u32)(47));  // @42_434bf0
  ecx = edx = 0;  // @43_434bf0
  if ((eax & eax) == 0) goto L434ca7;  // @44_434bf0
  L434c9b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @46_434bf0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @47_434bf0
  p3_ = edi;  // @48_434bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_434bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p3_));  // @50_434bf0
  ecx = edx = 0;  // @51_434bf0
  L434ca7:;
  p4_ = edi;  // @53_434bf0
  eax = ext_634273_cdecl2((u32)(p4_), (u32)(1));  // @54_434bf0
  ecx = edx = 0;  // @55_434bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_434bf0
  ecx = ebx;  // @57_434bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 52)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(1));  // @58_434bf0
  ecx = edx = 0;  // @59_434bf0
  eax = ebx;  // @60_434bf0
  SEH_LEAVE();  // @61_434bf0
  return eax;  // @62_434bf0
}
PCREG(434bf0, lifted_434bf0);

extern "C" u32 THISCALL lifted_4b1ca0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_4b1ca0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4b1ca0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4b1ca0
  eax = ext_469870_thiscall1(ecx);  // @2_4b1ca0
  ecx = edx = 0;  // @3_4b1ca0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4b1ca0
  eax = (u32)(esi + 100);  // @6_4b1ca0
  { u32 v = (u32)((u32)(6889016)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_4b1ca0
  ecx = 0;  // @9_4b1ca0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @10_4b1ca0
  ecx = (u32)(EBP - 20);  // @11_4b1ca0
  reg.state = (s32)((u32)(0));  // @12_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @13_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @14_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @15_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @16_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @17_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @18_4b1ca0
  if (eax == ecx) goto L4b1d2e;  // @19_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @20_4b1ca0
  L4b1d2e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @22_4b1ca0
  { u32 v = (u32)((u32)(65792)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @23_4b1ca0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 388), &v, sizeof v); }  // @24_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @25_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @26_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891112), (u32)(0), (u32)(6889180), (u32)(3378));  // @30_4b1ca0
  ecx = edx = 0;  // @31_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @32_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891132), (u32)(0), (u32)(6889180), (u32)(3379));  // @36_4b1ca0
  ecx = edx = 0;  // @37_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @38_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @40_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840116), (u32)(0), (u32)(6889180), (u32)(3380));  // @42_4b1ca0
  ecx = edx = 0;  // @43_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @44_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889320), (u32)(0), (u32)(6889180), (u32)(3381));  // @48_4b1ca0
  ecx = edx = 0;  // @49_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @50_4b1ca0
  eax = (u32)(esi + 128);  // @51_4b1ca0
  p0_ = eax;  // @52_4b1ca0
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(256));  // @53_4b1ca0
  ecx = edx = 0;  // @54_4b1ca0
  eax = esi;  // @55_4b1ca0
  SEH_LEAVE();  // @56_4b1ca0
  return eax;  // @57_4b1ca0
}
PCREG(4b1ca0, lifted_4b1ca0);

extern "C" u32 THISCALL lifted_431ce0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x6654b6);  // @h_431ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  edi = ecx;  // @0_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_431ce0
  ecx = (u32)(EBP - 324);  // @2_431ce0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_431ce0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @4_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 332), &v, sizeof v); }  // @5_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @6_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @7_431ce0
  eax = ext_4cbeb0_thiscall1(ecx);  // @8_431ce0
  ecx = edx = 0;  // @9_431ce0
  p0_ = esi;  // @10_431ce0
  ecx = (u32)(EBP - 144);  // @11_431ce0
  reg.state = (s32)((u32)(0));  // @12_431ce0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @13_431ce0
  ecx = edx = 0;  // @14_431ce0
  eax = (u32)(EBP - 144);  // @15_431ce0
  reg.state = (s32)((u32)(1));  // @16_431ce0
  p1_ = eax;  // @17_431ce0
  ecx = (u32)(EBP - 324);  // @18_431ce0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @19_431ce0
  ecx = edx = 0;  // @20_431ce0
  ecx = (u32)(EBP - 144);  // @21_431ce0
  reg.state = (s32)((u32)(0));  // @22_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_431ce0
  ecx = edx = 0;  // @24_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @25_431ce0
  if ((eax & eax) == 0) goto L431d81;  // @26_431ce0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @27_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @28_431ce0
  goto L431d92;  // @29_431ce0
  L431d81:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @31_431ce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @32_431ce0
  L431d92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @34_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @35_431ce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @36_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 149), &v, sizeof v); }  // @37_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @39_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @40_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @41_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @42_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @43_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @44_431ce0
  ecx = (u32)(EBP - 324);  // @45_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @46_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @47_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @48_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @49_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @50_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @51_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @52_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @53_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @54_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @55_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @56_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @57_431ce0
  p2_ = ecx;  // @58_431ce0
  ecx = edi;  // @59_431ce0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 159), &v, sizeof v); }  // @60_431ce0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 157), &v, sizeof v); }  // @61_431ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p2_));  // @62_431ce0
  ecx = edx = 0;  // @63_431ce0
  ecx = (u32)(EBP - 324);  // @64_431ce0
  esi = eax;  // @65_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @66_431ce0
  ecx = edx = 0;  // @67_431ce0
  eax = esi;  // @68_431ce0
  SEH_LEAVE();  // @69_431ce0
  ext_633654(G(u32, 0x6f5630));  // @70_431ce0
  return eax;  // @71_431ce0
}
PCREG(431ce0, lifted_431ce0);

extern "C" u32 THISCALL lifted_4346e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_4346e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4346e0
  ecx = (u32)(EBP - 144);  // @2_4346e0
  p0_ = eax;  // @3_4346e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_4346e0
  ecx = edx = 0;  // @5_4346e0
  ecx = (u32)(EBP - 144);  // @6_4346e0
  reg.state = (s32)((u32)(0));  // @7_4346e0
  esi = 0;  // @8_4346e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @9_4346e0
  ecx = edx = 0;  // @10_4346e0
  if ((eax & eax) == 0) goto L434770;  // @11_4346e0
  L434740:;
  ecx = (u32)(EBP - 144);  // @13_4346e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @14_4346e0
  ecx = edx = 0;  // @15_4346e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L434760;  // @16_4346e0
  ecx = (u32)(EBP - 144);  // @17_4346e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @18_4346e0
  ecx = edx = 0;  // @19_4346e0
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @20_4346e0
  L434760:;
  ecx = (u32)(EBP - 144);  // @22_4346e0
  esi = (esi + 1);  // @23_4346e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @24_4346e0
  ecx = edx = 0;  // @25_4346e0
  if (esi != eax) goto L434740;  // @26_4346e0
  L434770:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @28_4346e0
  if ((ecx & ecx) == 0) goto L4347cd;  // @29_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4346e0
  edx = (u32)(EBP - 156);  // @31_4346e0
  p1_ = edx;  // @32_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @33_4346e0
  ecx = edx = 0;  // @34_4346e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @35_4346e0
  edx = (u32)(EBP - 156);  // @36_4346e0
  p2_ = edx;  // @37_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @39_4346e0
  ecx = edx = 0;  // @40_4346e0
  if ((eax & eax) == 0) goto L4347cd;  // @41_4346e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @42_4346e0
  L4347a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @44_4346e0
  ecx = (u32)(EBP - 144);  // @45_4346e0
  eax = ext_4cc1d0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13), sizeof v); (u32)v; }));  // @46_4346e0
  ecx = edx = 0;  // @47_4346e0
  p3_ = eax;  // @48_4346e0
  eax = ((u32(STDCALL *)(u32))(esi))((u32)(p3_));  // @49_4346e0
  ecx = edx = 0;  // @50_4346e0
  if ((eax & eax) == 0) goto L4347fa;  // @51_4346e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @52_4346e0
  edx = (u32)(EBP - 156);  // @53_4346e0
  p4_ = edx;  // @54_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @56_4346e0
  ecx = edx = 0;  // @57_4346e0
  if ((eax & eax) != 0) goto L4347a0;  // @58_4346e0
  L4347cd:;
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @60_4346e0
  L4347cf:;
  ecx = (u32)(EBP - 144);  // @62_4346e0
  eax = ext_4cbec0_thiscall1(ecx);  // @63_4346e0
  ecx = edx = 0;  // @64_4346e0
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @65_4346e0
  SEH_LEAVE();  // @66_4346e0
  ext_633654(G(u32, 0x6f5630));  // @67_4346e0
  return eax;  // @68_4346e0
  L4347fa:;
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_4346e0
  goto L4347cf;  // @71_4346e0
}
PCREG(4346e0, lifted_4346e0);

extern "C" u32 THISCALL lifted_4356e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_4356e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4356e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4357df;  // @2_4356e0
  p0_ = eax;  // @3_4356e0
  ecx = (u32)(EBP - 144);  // @4_4356e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @5_4356e0
  ecx = edx = 0;  // @6_4356e0
  ecx = (u32)(EBP - 144);  // @7_4356e0
  reg.state = (s32)((u32)(0));  // @8_4356e0
  esi = 0;  // @9_4356e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @10_4356e0
  ecx = edx = 0;  // @11_4356e0
  if ((eax & eax) == 0) goto L435771;  // @12_4356e0
  L435741:;
  ecx = (u32)(EBP - 144);  // @14_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_4356e0
  ecx = edx = 0;  // @16_4356e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L435761;  // @17_4356e0
  ecx = (u32)(EBP - 144);  // @18_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_4356e0
  ecx = edx = 0;  // @20_4356e0
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @21_4356e0
  L435761:;
  ecx = (u32)(EBP - 144);  // @23_4356e0
  esi = (esi + 1);  // @24_4356e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @25_4356e0
  ecx = edx = 0;  // @26_4356e0
  if (esi != eax) goto L435741;  // @27_4356e0
  L435771:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @29_4356e0
  if ((ecx & ecx) == 0) goto L4357d4;  // @30_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4356e0
  edx = (u32)(EBP - 156);  // @32_4356e0
  p1_ = edx;  // @33_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @34_4356e0
  ecx = edx = 0;  // @35_4356e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @36_4356e0
  edx = (u32)(EBP - 156);  // @37_4356e0
  p2_ = edx;  // @38_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @40_4356e0
  ecx = edx = 0;  // @41_4356e0
  if ((eax & eax) == 0) goto L4357d4;  // @42_4356e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @43_4356e0
  L4357a0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_4356e0
  ecx = (u32)(EBP - 144);  // @46_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @47_4356e0
  ecx = edx = 0;  // @48_4356e0
  p3_ = eax;  // @49_4356e0
  eax = ((u32( *)(u32, u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; }), (u32)(p3_));  // @50_4356e0
  ecx = edx = 0;  // @51_4356e0
  if ((eax & eax) != 0) goto L4357c1;  // @52_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_4356e0
  ecx = esi;  // @54_4356e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @55_4356e0
  ecx = edx = 0;  // @56_4356e0
  L4357c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @58_4356e0
  edx = (u32)(EBP - 156);  // @59_4356e0
  p4_ = edx;  // @60_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @62_4356e0
  ecx = edx = 0;  // @63_4356e0
  if ((eax & eax) != 0) goto L4357a0;  // @64_4356e0
  L4357d4:;
  ecx = (u32)(EBP - 144);  // @66_4356e0
  eax = ext_4cbec0_thiscall1(ecx);  // @67_4356e0
  ecx = edx = 0;  // @68_4356e0
  L4357df:;
  SEH_LEAVE();  // @70_4356e0
  ext_633654(G(u32, 0x6f5630));  // @71_4356e0
  return eax;  // @72_4356e0
}
PCREG(4356e0, lifted_4356e0);

extern "C" u32 THISCALL lifted_435800(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_435800
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435800
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4358ff;  // @2_435800
  p0_ = eax;  // @3_435800
  ecx = (u32)(EBP - 144);  // @4_435800
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @5_435800
  ecx = edx = 0;  // @6_435800
  ecx = (u32)(EBP - 144);  // @7_435800
  reg.state = (s32)((u32)(0));  // @8_435800
  esi = 0;  // @9_435800
  eax = ext_4cc5f0_thiscall1(ecx);  // @10_435800
  ecx = edx = 0;  // @11_435800
  if ((eax & eax) == 0) goto L435891;  // @12_435800
  L435861:;
  ecx = (u32)(EBP - 144);  // @14_435800
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_435800
  ecx = edx = 0;  // @16_435800
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L435881;  // @17_435800
  ecx = (u32)(EBP - 144);  // @18_435800
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_435800
  ecx = edx = 0;  // @20_435800
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @21_435800
  L435881:;
  ecx = (u32)(EBP - 144);  // @23_435800
  esi = (esi + 1);  // @24_435800
  eax = ext_4cc5f0_thiscall1(ecx);  // @25_435800
  ecx = edx = 0;  // @26_435800
  if (esi != eax) goto L435861;  // @27_435800
  L435891:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @29_435800
  if ((ecx & ecx) == 0) goto L4358f4;  // @30_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_435800
  edx = (u32)(EBP - 156);  // @32_435800
  p1_ = edx;  // @33_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @34_435800
  ecx = edx = 0;  // @35_435800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @36_435800
  edx = (u32)(EBP - 156);  // @37_435800
  p2_ = edx;  // @38_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @40_435800
  ecx = edx = 0;  // @41_435800
  if ((eax & eax) == 0) goto L4358f4;  // @42_435800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @43_435800
  L4358c0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_435800
  ecx = (u32)(EBP - 144);  // @46_435800
  eax = ext_4cc1d0_thiscall1(ecx);  // @47_435800
  ecx = edx = 0;  // @48_435800
  p3_ = eax;  // @49_435800
  eax = ((u32( *)(u32, u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; }), (u32)(p3_));  // @50_435800
  ecx = edx = 0;  // @51_435800
  if ((eax & eax) != 0) goto L4358e1;  // @52_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_435800
  ecx = esi;  // @54_435800
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @55_435800
  ecx = edx = 0;  // @56_435800
  L4358e1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @58_435800
  edx = (u32)(EBP - 156);  // @59_435800
  p4_ = edx;  // @60_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @62_435800
  ecx = edx = 0;  // @63_435800
  if ((eax & eax) != 0) goto L4358c0;  // @64_435800
  L4358f4:;
  ecx = (u32)(EBP - 144);  // @66_435800
  eax = ext_4cbec0_thiscall1(ecx);  // @67_435800
  ecx = edx = 0;  // @68_435800
  L4358ff:;
  SEH_LEAVE();  // @70_435800
  ext_633654(G(u32, 0x6f5630));  // @71_435800
  return eax;  // @72_435800
}
PCREG(435800, lifted_435800);

extern "C" u32 STDCALL lifted_4d8af0(u32 a0) {
  SEH_ENTER(0x6696e8);  // @h_4d8af0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 260), sizeof v); (u32)v; });  // @0_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_4d8af0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @2_4d8af0
  ecx = edx = 0;  // @3_4d8af0
  ecx = (u32)(EBP - 52);  // @4_4d8af0
  esi = eax;  // @5_4d8af0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @6_4d8af0
  ecx = edx = 0;  // @7_4d8af0
  reg.state = (s32)((u32)(0));  // @8_4d8af0
  if ((esi & esi) == 0) goto L4d8b70;  // @9_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_4d8af0
  ecx = (u32)(EBP - 24);  // @11_4d8af0
  p0_ = ecx;  // @12_4d8af0
  ecx = esi;  // @13_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @14_4d8af0
  ecx = edx = 0;  // @15_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_4d8af0
  ecx = (u32)(EBP - 24);  // @17_4d8af0
  p1_ = ecx;  // @18_4d8af0
  ecx = esi;  // @19_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @20_4d8af0
  ecx = edx = 0;  // @21_4d8af0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4d8b70;  // @22_4d8af0
  L4d8b56:;
  p2_ = eax;  // @24_4d8af0
  ecx = (u32)(EBP - 52);  // @25_4d8af0
  eax = ext_4cd950_thiscall2(ecx, (u32)(p2_));  // @26_4d8af0
  ecx = edx = 0;  // @27_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_4d8af0
  ecx = (u32)(EBP - 24);  // @29_4d8af0
  p3_ = ecx;  // @30_4d8af0
  ecx = esi;  // @31_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @32_4d8af0
  ecx = edx = 0;  // @33_4d8af0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4d8b56;  // @34_4d8af0
  L4d8b70:;
  ecx = (u32)(EBP - 52);  // @36_4d8af0
  eax = ext_4cf850_thiscall1(ecx);  // @37_4d8af0
  ecx = edx = 0;  // @38_4d8af0
  eax = (u32)(EBP - 24);  // @39_4d8af0
  p4_ = eax;  // @40_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @41_4d8af0
  ecx = (u32)(EBP - 52);  // @42_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p4_));  // @43_4d8af0
  ecx = edx = 0;  // @44_4d8af0
  eax = (u32)(EBP - 24);  // @45_4d8af0
  p5_ = eax;  // @46_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @47_4d8af0
  ecx = (u32)(EBP - 52);  // @48_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p5_));  // @49_4d8af0
  ecx = edx = 0;  // @50_4d8af0
  esi = eax;  // @51_4d8af0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4d8bd6;  // @52_4d8af0
  L4d8ba0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @54_4d8af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4d8af0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6909064), (u32)(35));  // @56_4d8af0
  ecx = edx = 0;  // @57_4d8af0
  p6_ = esi;  // @58_4d8af0
  p7_ = eax;  // @59_4d8af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_4d8af0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p7_), (u32)(6779752), (u32)(p6_));  // @61_4d8af0
  ecx = edx = 0;  // @62_4d8af0
  eax = (u32)(EBP - 24);  // @63_4d8af0
  ecx = (u32)(EBP - 52);  // @64_4d8af0
  p8_ = eax;  // @65_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @66_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p8_));  // @67_4d8af0
  ecx = edx = 0;  // @68_4d8af0
  esi = eax;  // @69_4d8af0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4d8ba0;  // @70_4d8af0
  L4d8bd6:;
  ecx = (u32)(EBP - 52);  // @72_4d8af0
  eax = ext_4cd0e0_thiscall1(ecx);  // @73_4d8af0
  ecx = edx = 0;  // @74_4d8af0
  SEH_LEAVE();  // @75_4d8af0
  return eax;  // @76_4d8af0
}
PCREG(4d8af0, lifted_4d8af0);

extern "C" u32 THISCALL lifted_4e7e80(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_4e7e80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_4e7e80
  { u32 v = (u32)((u32)(6911508)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_4e7e80
  L4e7eb0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @4_4e7e80
  if (ebx == eax) goto L4e7f46;  // @5_4e7e80
  if ((ebx & ebx) == 0) goto L4e7f46;  // @6_4e7e80
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == eax) goto L4e7edc;  // @7_4e7e80
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }) == eax) goto L4e7edc;  // @8_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @9_4e7e80
  ecx = edi;  // @10_4e7e80
  p0_ = ebx;  // @11_4e7e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p0_));  // @12_4e7e80
  ecx = edx = 0;  // @13_4e7e80
  esi = eax;  // @14_4e7e80
  goto L4e7ede;  // @15_4e7e80
  L4e7edc:;
  esi = ebx;  // @17_4e7e80
  L4e7ede:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @19_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @20_4e7e80
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L4e7eef;  // @21_4e7e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @22_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @23_4e7e80
  L4e7eef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_4e7e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @26_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_4e7e80
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L4e7eff;  // @28_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @29_4e7e80
  goto L4e7f0c;  // @30_4e7e80
  L4e7eff:;
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L4e7f09;  // @32_4e7e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @33_4e7e80
  goto L4e7f0c;  // @34_4e7e80
  L4e7f09:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @36_4e7e80
  L4e7f0c:;
  if (esi == ebx) goto L4e7f22;  // @38_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @39_4e7e80
  ecx = edi;  // @40_4e7e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @41_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_4e7e80
  p1_ = esi;  // @43_4e7e80
  p2_ = ebx;  // @44_4e7e80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(p2_), (u32)(p1_));  // @45_4e7e80
  ecx = edx = 0;  // @46_4e7e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @47_4e7e80
  L4e7f22:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) != (u32)(0)) goto L4e7f30;  // @49_4e7e80
  p3_ = ecx;  // @50_4e7e80
  ecx = edi;  // @51_4e7e80
  eax = ext_4e8450_thiscall2(ecx, (u32)(p3_));  // @52_4e7e80
  ecx = edx = 0;  // @53_4e7e80
  L4e7f30:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 29), sizeof v); (u32)v; });  // @55_4e7e80
  eax = 0;  // @56_4e7e80
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) esi = eax;  // @57_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4e7e80
  p4_ = esi;  // @59_4e7e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(p4_));  // @60_4e7e80
  ecx = edx = 0;  // @61_4e7e80
  goto L4e7eb0;  // @62_4e7e80
  L4e7f46:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 29), sizeof v); (u32)v; });  // @64_4e7e80
  if ((ecx & ecx) == 0) goto L4e7f53;  // @65_4e7e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_4e7e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @67_4e7e80
  ecx = edx = 0;  // @68_4e7e80
  L4e7f53:;
  SEH_LEAVE();  // @70_4e7e80
  return eax;  // @71_4e7e80
}
PCREG(4e7e80, lifted_4e7e80);

extern "C" u32 THISCALL lifted_4f6f10(u32 ecx_in) {
  SEH_ENTER(0x6699e7);  // @h_4f6f10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4f6f10
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 147), sizeof v); (u32)v; }) != (u32)(0)) goto L4f704f;  // @1_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_4f6f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @3_4f6f10
  ecx = edx = 0;  // @4_4f6f10
  ecx = (u32)(EBP - 272);  // @5_4f6f10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @6_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6925952));  // @7_4f6f10
  ecx = edx = 0;  // @8_4f6f10
  ecx = (u32)(EBP - 144);  // @9_4f6f10
  reg.state = (s32)((u32)(0));  // @10_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6838840));  // @11_4f6f10
  ecx = edx = 0;  // @12_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @13_4f6f10
  ecx = (u32)(6801640);  // @14_4f6f10
  reg.state = (s32)((u32)(1));  // @15_4f6f10
  if ((eax & eax) != 0) ecx = eax;  // @16_4f6f10
  p0_ = ecx;  // @17_4f6f10
  ecx = (u32)(EBP - 656);  // @18_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @19_4f6f10
  ecx = edx = 0;  // @20_4f6f10
  ecx = (u32)(EBP - 144);  // @21_4f6f10
  reg.state = (s32)((u32)(2));  // @22_4f6f10
  p1_ = ecx;  // @23_4f6f10
  ecx = (u32)(EBP - 528);  // @24_4f6f10
  p2_ = ecx;  // @25_4f6f10
  ecx = eax;  // @26_4f6f10
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p2_), (u32)(p1_));  // @27_4f6f10
  ecx = edx = 0;  // @28_4f6f10
  ecx = (u32)(EBP - 272);  // @29_4f6f10
  reg.state = (s32)((u32)(3));  // @30_4f6f10
  p3_ = ecx;  // @31_4f6f10
  ecx = (u32)(EBP - 400);  // @32_4f6f10
  p4_ = ecx;  // @33_4f6f10
  ecx = eax;  // @34_4f6f10
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p4_), (u32)(p3_));  // @35_4f6f10
  ecx = edx = 0;  // @36_4f6f10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_4f6f10
  ecx = eax;  // @38_4f6f10
  reg.state = (s32)((u32)(4));  // @39_4f6f10
  eax = ext_4cc1d0_cdecl2((u32)(0), (u32)(0));  // @40_4f6f10
  ecx = edx = 0;  // @41_4f6f10
  p5_ = eax;  // @42_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4f6f10
  ecx = edi;  // @44_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_4f6f10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 440)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; }), (u32)(0), (u32)(p5_));  // @46_4f6f10
  ecx = edx = 0;  // @47_4f6f10
  ecx = (u32)(EBP - 400);  // @48_4f6f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 147), &v, sizeof v); }  // @49_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @50_4f6f10
  ecx = edx = 0;  // @51_4f6f10
  ecx = (u32)(EBP - 528);  // @52_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @53_4f6f10
  ecx = edx = 0;  // @54_4f6f10
  ecx = (u32)(EBP - 656);  // @55_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @56_4f6f10
  ecx = edx = 0;  // @57_4f6f10
  ecx = (u32)(EBP - 144);  // @58_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @59_4f6f10
  ecx = edx = 0;  // @60_4f6f10
  ecx = (u32)(EBP - 272);  // @61_4f6f10
  reg.state = (s32)((u32)(4294967295));  // @62_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @63_4f6f10
  ecx = edx = 0;  // @64_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @65_4f6f10
  ecx = ebx;  // @66_4f6f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 876)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 147), sizeof v); (u32)v; }));  // @67_4f6f10
  ecx = edx = 0;  // @68_4f6f10
  L4f704f:;
  SEH_LEAVE();  // @70_4f6f10
  ext_633654(G(u32, 0x6f5630));  // @71_4f6f10
  return eax;  // @72_4f6f10
}
PCREG(4f6f10, lifted_4f6f10);

extern "C" u32 THISCALL lifted_5bfac0(u32 ecx_in) {
  SEH_ENTER(0x66c558);  // @h_5bfac0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5bfac0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5bfac0
  eax = ext_469870_thiscall1(ecx);  // @2_5bfac0
  ecx = edx = 0;  // @3_5bfac0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5bfac0
  { u32 v = (u32)((u32)(7026868)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @7_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @8_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @9_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @10_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_5bfac0
  reg.state = (s32)((u32)(0));  // @13_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968700), (u32)(0), (u32)(7027024), (u32)(63));  // @15_5bfac0
  ecx = edx = 0;  // @16_5bfac0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @17_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968716), (u32)(0), (u32)(7027024), (u32)(64));  // @21_5bfac0
  ecx = edx = 0;  // @22_5bfac0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @23_5bfac0
  edx = (u32)(EBP - 16);  // @24_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @25_5bfac0
  p0_ = edx;  // @26_5bfac0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 11281), &v, sizeof v); }  // @27_5bfac0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @28_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @31_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7027076), (u32)(p0_));  // @32_5bfac0
  ecx = edx = 0;  // @33_5bfac0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5bfbdf;  // @34_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @35_5bfac0
  eax = (u32)(6792920);  // @36_5bfac0
  L5bfba0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @38_5bfac0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L5bfbc0;  // @39_5bfac0
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L5bfbbc;  // @40_5bfac0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @41_5bfac0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L5bfbc0;  // @42_5bfac0
  ecx = (ecx + (u32)(2));  // @43_5bfac0
  eax = (eax + (u32)(2));  // @44_5bfac0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L5bfba0;  // @45_5bfac0
  L5bfbbc:;
  eax = 0;  // @47_5bfac0
  goto L5bfbc5;  // @48_5bfac0
  L5bfbc0:;
  eax = 0;  // @50_5bfac0
  eax = (eax | (u32)(1));  // @51_5bfac0
  L5bfbc5:;
  eax = esi;  // @53_5bfac0
  if ((eax & eax) != 0) goto L5bfbe1;  // @54_5bfac0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @55_5bfac0
  SEH_LEAVE();  // @56_5bfac0
  return eax;  // @57_5bfac0
  L5bfbdf:;
  eax = esi;  // @59_5bfac0
  L5bfbe1:;
  SEH_LEAVE();  // @61_5bfac0
  return eax;  // @62_5bfac0
}
PCREG(5bfac0, lifted_5bfac0);

extern "C" u32 THISCALL lifted_4f8c50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4f8c50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8c50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4f8c50
  p0_ = esi;  // @2_4f8c50
  eax = ext_4f9c90_thiscall2(ecx, (u32)(p0_));  // @3_4f8c50
  ecx = edx = 0;  // @4_4f8c50
  eax = (u32)(EBP - 148);  // @5_4f8c50
  ecx = esi;  // @6_4f8c50
  p1_ = eax;  // @7_4f8c50
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p1_), (u32)(1));  // @8_4f8c50
  ecx = edx = 0;  // @9_4f8c50
  eax = (u32)(ebx + 455);  // @10_4f8c50
  ecx = esi;  // @11_4f8c50
  p2_ = eax;  // @12_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p2_), (u32)(1));  // @13_4f8c50
  ecx = edx = 0;  // @14_4f8c50
  eax = (u32)(ebx + 459);  // @15_4f8c50
  ecx = esi;  // @16_4f8c50
  p3_ = eax;  // @17_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p3_), (u32)(1));  // @18_4f8c50
  ecx = edx = 0;  // @19_4f8c50
  eax = (u32)(ebx + 471);  // @20_4f8c50
  ecx = esi;  // @21_4f8c50
  p4_ = eax;  // @22_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p4_), (u32)(1));  // @23_4f8c50
  ecx = edx = 0;  // @24_4f8c50
  ecx = esi;  // @25_4f8c50
  eax = ext_4e1b30_thiscall1(ecx);  // @26_4f8c50
  ecx = edx = 0;  // @27_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4f8c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4f8c50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @31_4f8c50
  ecx = edx = 0;  // @32_4f8c50
  ecx = eax;  // @33_4f8c50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 451), &v, sizeof v); }  // @34_4f8c50
  if ((ecx & ecx) == 0) goto L4f8d05;  // @35_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @37_4f8c50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097199));  // @38_4f8c50
  ecx = edx = 0;  // @39_4f8c50
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4f8d5e;  // @40_4f8c50
  L4f8d05:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @42_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_4f8c50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6927940), (u32)(37));  // @44_4f8c50
  ecx = edx = 0;  // @45_4f8c50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @46_4f8c50
  edi = eax;  // @47_4f8c50
  eax = (u32)(EBP - 144);  // @48_4f8c50
  ecx = ebx;  // @49_4f8c50
  p5_ = eax;  // @50_4f8c50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p5_), (u32)(1));  // @51_4f8c50
  ecx = edx = 0;  // @52_4f8c50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @53_4f8c50
  ecx = eax;  // @54_4f8c50
  reg.state = (s32)((u32)(0));  // @55_4f8c50
  eax = ext_4cc1d0_thiscall1(ecx);  // @56_4f8c50
  ecx = edx = 0;  // @57_4f8c50
  p6_ = eax;  // @58_4f8c50
  p7_ = edi;  // @59_4f8c50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p7_), (u32)(6927984), (u32)(p6_));  // @60_4f8c50
  ecx = edx = 0;  // @61_4f8c50
  ecx = (u32)(EBP - 144);  // @62_4f8c50
  eax = ext_4cbec0_thiscall1(ecx);  // @63_4f8c50
  ecx = edx = 0;  // @64_4f8c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 451), &v, sizeof v); }  // @65_4f8c50
  L4f8d5e:;
  SEH_LEAVE();  // @67_4f8c50
  ext_633654(G(u32, 0x6f5630));  // @68_4f8c50
  return eax;  // @69_4f8c50
}
PCREG(4f8c50, lifted_4f8c50);

extern "C" u32 THISCALL lifted_4f91f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669acb);  // @h_4f91f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4f91f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @1_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4f91f0
  ecx = (u32)(EBP - 144);  // @3_4f91f0
  p0_ = esi;  // @4_4f91f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @5_4f91f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @6_4f91f0
  ecx = edx = 0;  // @7_4f91f0
  eax = (u32)(edi + 143);  // @8_4f91f0
  reg.state = (s32)((u32)(0));  // @9_4f91f0
  ecx = (u32)(EBP - 144);  // @10_4f91f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @11_4f91f0
  p1_ = ecx;  // @12_4f91f0
  ecx = eax;  // @13_4f91f0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @14_4f91f0
  ecx = edx = 0;  // @15_4f91f0
  ecx = (u32)(EBP - 144);  // @16_4f91f0
  reg.state = (s32)((u32)(4294967295));  // @17_4f91f0
  eax = ext_4cbec0_thiscall1(ecx);  // @18_4f91f0
  ecx = edx = 0;  // @19_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 271), sizeof v); (u32)v; });  // @20_4f91f0
  ecx = (u32)(edi + 271);  // @21_4f91f0
  ebx = 0;  // @22_4f91f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @23_4f91f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @24_4f91f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @25_4f91f0
  ecx = edx = 0;  // @26_4f91f0
  if ((s32)(eax & eax) <= 0) goto L4f92f6;  // @27_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @28_4f91f0
  L4f9295:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_4f91f0
  ecx = esi;  // @31_4f91f0
  p2_ = ebx;  // @32_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_4f91f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(p2_));  // @36_4f91f0
  ecx = edx = 0;  // @37_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_4f91f0
  p3_ = eax;  // @39_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @40_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 88)))(ecx, (u32)(p3_));  // @41_4f91f0
  ecx = edx = 0;  // @42_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @43_4f91f0
  edi = eax;  // @44_4f91f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_4f91f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @46_4f91f0
  ecx = edx = 0;  // @47_4f91f0
  p4_ = eax;  // @48_4f91f0
  ecx = edi;  // @49_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(ebx + 644)))(ecx, (u32)(p4_));  // @50_4f91f0
  ecx = edx = 0;  // @51_4f91f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @52_4f91f0
  ecx = esi;  // @53_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_4f91f0
  ebx = (ebx + 1);  // @55_4f91f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @56_4f91f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @57_4f91f0
  ecx = edx = 0;  // @58_4f91f0
  if ((s32)ebx < (s32)eax) goto L4f9295;  // @59_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @60_4f91f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @61_4f91f0
  L4f92f6:;
  ecx = (u32)(esi + 1);  // @63_4f91f0
  L4f9300:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @65_4f91f0
  esi = (esi + 1);  // @66_4f91f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4f9300;  // @67_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @68_4f91f0
  esi = (esi - ecx);  // @69_4f91f0
  p5_ = esi;  // @70_4f91f0
  ecx = edi;  // @71_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 868)))(ecx, (u32)(p5_));  // @72_4f91f0
  ecx = edx = 0;  // @73_4f91f0
  SEH_LEAVE();  // @74_4f91f0
  ext_633654(G(u32, 0x6f5630));  // @75_4f91f0
  return eax;  // @76_4f91f0
}
PCREG(4f91f0, lifted_4f91f0);

extern "C" u32 THISCALL lifted_4c3d30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668e06);  // @h_4c3d30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4c3d30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @1_4c3d30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4c3d30
  ecx = (u32)(EBP - 144);  // @3_4c3d30
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_4c3d30
  ecx = edx = 0;  // @5_4c3d30
  eax = (u32)(EBP - 144);  // @6_4c3d30
  reg.state = (s32)((u32)(0));  // @7_4c3d30
  p0_ = eax;  // @8_4c3d30
  ebx = (u32)(edi + 126);  // @9_4c3d30
  ecx = edi;  // @10_4c3d30
  p1_ = ebx;  // @11_4c3d30
  p2_ = esi;  // @12_4c3d30
  eax = ext_4c4740_thiscall4(ecx, (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @13_4c3d30
  ecx = edx = 0;  // @14_4c3d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_4c3d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4c3d30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @18_4c3d30
  ecx = edx = 0;  // @19_4c3d30
  if ((eax & eax) != 0) goto L4c3e4b;  // @20_4c3d30
  ecx = (u32)(EBP - 144);  // @21_4c3d30
  eax = ext_4cc5f0_thiscall1(ecx);  // @22_4c3d30
  ecx = edx = 0;  // @23_4c3d30
  if ((eax & eax) == 0) goto L4c3e4b;  // @24_4c3d30
  ecx = (u32)(EBP - 144);  // @25_4c3d30
  eax = ext_456ab0_thiscall1(ecx);  // @26_4c3d30
  ecx = edx = 0;  // @27_4c3d30
  ebx = eax;  // @28_4c3d30
  if ((ebx & ebx) != 0) goto L4c3e37;  // @29_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @30_4c3d30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4c3d30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6897740), (u32)(191));  // @32_4c3d30
  ecx = edx = 0;  // @33_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @34_4c3d30
  edi = eax;  // @35_4c3d30
  eax = (u32)(EBP - 272);  // @36_4c3d30
  p3_ = eax;  // @37_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @38_4c3d30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4c3d30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p3_), (u32)(1));  // @40_4c3d30
  ecx = edx = 0;  // @41_4c3d30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_4c3d30
  ecx = eax;  // @43_4c3d30
  reg.state = (s32)((u32)(1));  // @44_4c3d30
  eax = ext_4cc1d0_thiscall1(ecx);  // @45_4c3d30
  ecx = edx = 0;  // @46_4c3d30
  p4_ = eax;  // @47_4c3d30
  ecx = (u32)(EBP - 144);  // @48_4c3d30
  eax = ext_4cc1d0_cdecl1((u32)(p4_));  // @49_4c3d30
  ecx = edx = 0;  // @50_4c3d30
  p5_ = eax;  // @51_4c3d30
  p6_ = edi;  // @52_4c3d30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(p6_), (u32)(6897792), (u32)(p5_));  // @53_4c3d30
  ecx = edx = 0;  // @54_4c3d30
  reg.state = (s32)((ebx & 0xff));  // @55_4c3d30
  ecx = (u32)(EBP - 272);  // @56_4c3d30
  eax = ext_4cbec0_thiscall1(ecx);  // @57_4c3d30
  ecx = edx = 0;  // @58_4c3d30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @59_4c3d30
  L4c3e37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_4c3d30
  p7_ = ebx;  // @62_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_4c3d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4c3d30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p7_));  // @65_4c3d30
  ecx = edx = 0;  // @66_4c3d30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 126), &v, sizeof v); }  // @67_4c3d30
  L4c3e4b:;
  ecx = (u32)(EBP - 144);  // @69_4c3d30
  eax = ext_4cbec0_thiscall1(ecx);  // @70_4c3d30
  ecx = edx = 0;  // @71_4c3d30
  SEH_LEAVE();  // @72_4c3d30
  ext_633654(G(u32, 0x6f5630));  // @73_4c3d30
  return eax;  // @74_4c3d30
}
PCREG(4c3d30, lifted_4c3d30);

extern "C" u32 THISCALL lifted_44a200(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6660dd);  // @h_44a200
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_44a200
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_44a200
  p0_ = ebx;  // @2_44a200
  eax = ext_610100_stdcall1((u32)(p0_));  // @3_44a200
  ecx = edx = 0;  // @4_44a200
  ecx = (u32)(EBP - 188);  // @5_44a200
  eax = ext_4ccba0_thiscall1(ecx);  // @6_44a200
  ecx = edx = 0;  // @7_44a200
  eax = (u32)(EBP - 188);  // @8_44a200
  reg.state = (s32)((u32)(0));  // @9_44a200
  p1_ = eax;  // @10_44a200
  ecx = ebx;  // @11_44a200
  eax = ext_4e0fd0_thiscall2(ecx, (u32)(p1_));  // @12_44a200
  ecx = edx = 0;  // @13_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L44a28d;  // @14_44a200
  eax = ext_41e290_cdecl1((u32)(28));  // @15_44a200
  ecx = edx = 0;  // @16_44a200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @17_44a200
  reg.state = (s32)((u32)(1));  // @18_44a200
  if ((eax & eax) == 0) goto L44a284;  // @19_44a200
  ecx = eax;  // @20_44a200
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @21_44a200
  ecx = edx = 0;  // @22_44a200
  goto L44a286;  // @23_44a200
  L44a284:;
  eax = 0;  // @25_44a200
  L44a286:;
  reg.state = (s32)((u32)(0));  // @27_44a200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @28_44a200
  L44a28d:;
  eax = (u32)(EBP - 200);  // @30_44a200
  p2_ = eax;  // @31_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @32_44a200
  ecx = (u32)(EBP - 188);  // @33_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @34_44a200
  ecx = edx = 0;  // @35_44a200
  eax = (u32)(EBP - 200);  // @36_44a200
  p3_ = eax;  // @37_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @38_44a200
  ecx = (u32)(EBP - 188);  // @39_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @40_44a200
  ecx = edx = 0;  // @41_44a200
  esi = eax;  // @42_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L44a310;  // @43_44a200
  L44a2d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_44a200
  p4_ = esi;  // @46_44a200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @47_44a200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p4_));  // @49_44a200
  ecx = edx = 0;  // @50_44a200
  if ((eax & eax) == 0) goto L44a2ef;  // @51_44a200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @52_44a200
  p5_ = esi;  // @53_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p5_));  // @55_44a200
  ecx = edx = 0;  // @56_44a200
  L44a2ef:;
  eax = (u32)(EBP - 200);  // @58_44a200
  p6_ = eax;  // @59_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @60_44a200
  ecx = (u32)(EBP - 188);  // @61_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p6_));  // @62_44a200
  ecx = edx = 0;  // @63_44a200
  esi = eax;  // @64_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L44a2d0;  // @65_44a200
  L44a310:;
  ecx = ebx;  // @67_44a200
  eax = ext_4e1b30_thiscall1(ecx);  // @68_44a200
  ecx = edx = 0;  // @69_44a200
  ecx = (u32)(EBP - 188);  // @70_44a200
  eax = ext_4ccf60_thiscall1(ecx);  // @71_44a200
  ecx = edx = 0;  // @72_44a200
  SEH_LEAVE();  // @73_44a200
  ext_633654(G(u32, 0x6f5630));  // @74_44a200
  return eax;  // @75_44a200
}
PCREG(44a200, lifted_44a200);

extern "C" u32 THISCALL lifted_45cc40(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6666bc);  // @h_45cc40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_45cc40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_45cc40
  ecx = (u32)(EBP - 144);  // @2_45cc40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @3_45cc40
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_45cc40
  ecx = edx = 0;  // @5_45cc40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_45cc40
  ecx = (u32)(EBP - 144);  // @7_45cc40
  p0_ = ecx;  // @8_45cc40
  ecx = esi;  // @9_45cc40
  reg.state = (s32)((u32)(0));  // @10_45cc40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 468)))(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @11_45cc40
  ecx = edx = 0;  // @12_45cc40
  ecx = (u32)(EBP - 144);  // @13_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @14_45cc40
  ecx = edx = 0;  // @15_45cc40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @16_45cc40
  p1_ = eax;  // @17_45cc40
  eax = ((u32(STDCALL *)(u32, u32))(ebx))((u32)(p1_), (u32)(47));  // @18_45cc40
  ecx = edx = 0;  // @19_45cc40
  esi = eax;  // @20_45cc40
  if ((esi & esi) == 0) goto L45cd52;  // @21_45cc40
  ecx = (u32)(EBP - 144);  // @22_45cc40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @23_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_45cc40
  ecx = edx = 0;  // @25_45cc40
  p2_ = eax;  // @26_45cc40
  eax = ((u32( *)(u32, u32))(ebx))((u32)(p2_), (u32)(92));  // @27_45cc40
  ecx = edx = 0;  // @28_45cc40
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @29_45cc40
  ecx = (u32)(EBP - 400);  // @30_45cc40
  ebx = eax;  // @31_45cc40
  eax = ext_4cbeb0_thiscall1(ecx);  // @32_45cc40
  ecx = edx = 0;  // @33_45cc40
  reg.state = (s32)((u32)(1));  // @34_45cc40
  ecx = (u32)(EBP - 272);  // @35_45cc40
  if ((ebx & ebx) == 0) goto L45cd09;  // @36_45cc40
  eax = (u32)(ebx + 1);  // @37_45cc40
  p3_ = eax;  // @38_45cc40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p3_));  // @39_45cc40
  ecx = edx = 0;  // @40_45cc40
  reg.state = (s32)((u32)(2));  // @41_45cc40
  goto L45cd16;  // @42_45cc40
  L45cd09:;
  eax = (u32)(esi + 1);  // @44_45cc40
  p4_ = eax;  // @45_45cc40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p4_));  // @46_45cc40
  ecx = edx = 0;  // @47_45cc40
  reg.state = (s32)((u32)(3));  // @48_45cc40
  L45cd16:;
  eax = (u32)(EBP - 272);  // @50_45cc40
  p5_ = eax;  // @51_45cc40
  ecx = (u32)(EBP - 400);  // @52_45cc40
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p5_));  // @53_45cc40
  ecx = edx = 0;  // @54_45cc40
  ecx = (u32)(EBP - 272);  // @55_45cc40
  reg.state = (s32)((u32)(1));  // @56_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @57_45cc40
  ecx = edx = 0;  // @58_45cc40
  eax = (u32)(EBP - 400);  // @59_45cc40
  ecx = edi;  // @60_45cc40
  p6_ = eax;  // @61_45cc40
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p6_));  // @62_45cc40
  ecx = edx = 0;  // @63_45cc40
  ecx = (u32)(EBP - 400);  // @64_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @65_45cc40
  ecx = edx = 0;  // @66_45cc40
  goto L45cd60;  // @67_45cc40
  L45cd52:;
  eax = (u32)(EBP - 144);  // @69_45cc40
  ecx = edi;  // @70_45cc40
  p7_ = eax;  // @71_45cc40
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p7_));  // @72_45cc40
  ecx = edx = 0;  // @73_45cc40
  L45cd60:;
  ecx = (u32)(EBP - 144);  // @75_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @76_45cc40
  ecx = edx = 0;  // @77_45cc40
  eax = edi;  // @78_45cc40
  SEH_LEAVE();  // @79_45cc40
  ext_633654(G(u32, 0x6f5630));  // @80_45cc40
  return eax;  // @81_45cc40
}
PCREG(45cc40, lifted_45cc40);

extern "C" u32 lifted_4260a0(void) {
  SEH_ENTER(0x664592);  // @h_4260a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4260a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L4261a3;  // @1_4260a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; }) != (u32)(0)) goto L426118;  // @2_4260a0
  eax = ext_41e290_cdecl1((u32)(28));  // @3_4260a0
  ecx = edx = 0;  // @4_4260a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4116), &v, sizeof v); }  // @5_4260a0
  reg.state = (s32)((u32)(0));  // @6_4260a0
  if ((eax & eax) == 0) goto L42610c;  // @7_4260a0
  ecx = eax;  // @8_4260a0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @9_4260a0
  ecx = edx = 0;  // @10_4260a0
  goto L42610e;  // @11_4260a0
  L42610c:;
  eax = 0;  // @13_4260a0
  L42610e:;
  reg.state = (s32)((u32)(4294967295));  // @15_4260a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @16_4260a0
  L426118:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_4260a0
  ecx = (u32)(EBP - 4112);  // @19_4260a0
  p0_ = ecx;  // @20_4260a0
  p1_ = edi;  // @21_4260a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(p1_), (u32)(p0_), (u32)(6784796), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }));  // @22_4260a0
  ecx = edx = 0;  // @23_4260a0
  ecx = (u32)(EBP - 4112);  // @24_4260a0
  edx = (u32)(ecx + 1);  // @25_4260a0
  L426140:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @27_4260a0
  ecx = (ecx + 1);  // @28_4260a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426140;  // @29_4260a0
  eax = (u32)(EBP + 16);  // @30_4260a0
  ecx = (ecx - edx);  // @31_4260a0
  p2_ = eax;  // @32_4260a0
  esi = (u32)(EBP - 4112);  // @33_4260a0
  esi = (esi + ecx);  // @34_4260a0
  p3_ = esi;  // @35_4260a0
  eax = ext_42abee_cdecl3((u32)(p3_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p2_));  // @36_4260a0
  ecx = edx = 0;  // @37_4260a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(40)) goto L42617d;  // @38_4260a0
  ecx = (u32)(EBP - 4112);  // @39_4260a0
  ecx = (ecx - esi);  // @40_4260a0
  L426170:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @42_4260a0
  esi = (u32)(esi + 1);  // @43_4260a0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @44_4260a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426170;  // @45_4260a0
  L42617d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @47_4260a0
  edx = (u32)(EBP - 4112);  // @48_4260a0
  p4_ = edx;  // @49_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4260a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(p4_));  // @51_4260a0
  ecx = edx = 0;  // @52_4260a0
  if ((eax & eax) == 0) goto L4261a3;  // @53_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @54_4260a0
  ecx = (u32)(EBP - 4112);  // @55_4260a0
  p5_ = ecx;  // @56_4260a0
  p6_ = edi;  // @57_4260a0
  eax = ((u32( *)(u32, u32))(*(u32 *)(eax + 44)))((u32)(p6_), (u32)(p5_));  // @58_4260a0
  ecx = edx = 0;  // @59_4260a0
  L4261a3:;
  SEH_LEAVE();  // @61_4260a0
  ext_633654(G(u32, 0x6f5630));  // @62_4260a0
  return eax;  // @63_4260a0
}
PCREG(4260a0, lifted_4260a0);

extern "C" u32 THISCALL lifted_497750(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66818f);  // @h_497750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @1_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(2138367));  // @3_497750
  ecx = edx = 0;  // @4_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_497750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L497797;  // @6_497750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; }) == (u32)(0)) goto L4977e0;  // @7_497750
  L497797:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @9_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_497750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @11_497750
  ecx = edx = 0;  // @12_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @13_497750
  if ((eax & eax) == 0) goto L4977be;  // @14_497750
  p0_ = eax;  // @15_497750
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(1));  // @16_497750
  ecx = edx = 0;  // @17_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @18_497750
  L4977be:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @20_497750
  if ((ecx & ecx) == 0) goto L4977d2;  // @21_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_497750
  ecx = edx = 0;  // @24_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @25_497750
  L4977d2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @27_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @28_497750
  L4977e0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_497750
  p1_ = ebx;  // @31_497750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @32_497750
  eax = ext_41e290_cdecl1((u32)(p1_));  // @33_497750
  ecx = edx = 0;  // @34_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @35_497750
  eax = ext_41e290_cdecl1((u32)(16));  // @36_497750
  ecx = edx = 0;  // @37_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @38_497750
  reg.state = (s32)((u32)(0));  // @39_497750
  if ((eax & eax) == 0) goto L49781a;  // @40_497750
  ecx = eax;  // @41_497750
  eax = ext_4ccdd0_thiscall4(ecx, (u32)(0), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; }), (u32)(512));  // @42_497750
  ecx = edx = 0;  // @43_497750
  goto L49781c;  // @44_497750
  L49781a:;
  eax = 0;  // @46_497750
  L49781c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @48_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @49_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @50_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @51_497750
  eax = (eax + edx);  // @52_497750
  reg.state = (s32)((u32)(4294967295));  // @53_497750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_497750
  p2_ = eax;  // @55_497750
  p3_ = edx;  // @56_497750
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 216)))(ecx, (u32)(p3_), (u32)(p2_), (u32)(4809904));  // @57_497750
  ecx = edx = 0;  // @58_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @59_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @61_497750
  ecx = edx = 0;  // @62_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @63_497750
  if ((ecx & ecx) == 0) goto L497866;  // @64_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_497750
  p4_ = ebx;  // @66_497750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6874404), (u32)(p4_));  // @67_497750
  ecx = edx = 0;  // @68_497750
  L497866:;
  SEH_LEAVE();  // @70_497750
  return eax;  // @71_497750
}
PCREG(497750, lifted_497750);

extern "C" u32 THISCALL lifted_5fb660(u32 ecx_in) {
  SEH_ENTER(0x66d496);  // @h_5fb660
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_5fb660
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @2_5fb660
  ebx = (u32)(edi + 1);  // @3_5fb660
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5), sizeof v); (u32)v; });  // @4_5fb660
  if (esi == eax) goto L5fb72e;  // @5_5fb660
  L5fb6a0:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @7_5fb660
  if ((edi & edi) == 0) goto L5fb6ee;  // @8_5fb660
  ecx = (u32)(edi + 370);  // @9_5fb660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @11_5fb660
  eax = (eax - edx);  // @12_5fb660
  reg.state = (s32)((u32)(0));  // @13_5fb660
  if ((edx & edx) == 0) goto L5fb6ca;  // @14_5fb660
  if ((eax & eax) == 0) goto L5fb6ca;  // @15_5fb660
  p0_ = eax;  // @16_5fb660
  p1_ = edx;  // @17_5fb660
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @18_5fb660
  ecx = edx = 0;  // @19_5fb660
  L5fb6ca:;
  ecx = (u32)(edi + 60);  // @21_5fb660
  reg.state = (s32)((u32)(4294967295));  // @22_5fb660
  eax = ext_5fdb70_thiscall1(ecx);  // @23_5fb660
  ecx = edx = 0;  // @24_5fb660
  ecx = edi;  // @25_5fb660
  eax = ext_5fae50_thiscall1(ecx);  // @26_5fb660
  ecx = edx = 0;  // @27_5fb660
  p2_ = edi;  // @28_5fb660
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(382));  // @29_5fb660
  ecx = edx = 0;  // @30_5fb660
  L5fb6ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @32_5fb660
  if ((eax & eax) == 0) goto L5fb70b;  // @33_5fb660
  esi = eax;  // @34_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @35_5fb660
  if ((eax & eax) == 0) goto L5fb723;  // @36_5fb660
  L5fb700:;
  esi = eax;  // @38_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @39_5fb660
  if ((eax & eax) != 0) goto L5fb700;  // @40_5fb660
  goto L5fb723;  // @41_5fb660
  L5fb70b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; });  // @43_5fb660
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L5fb71d;  // @44_5fb660
  L5fb713:;
  esi = eax;  // @46_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @47_5fb660
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L5fb713;  // @48_5fb660
  L5fb71d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }) != eax) esi = eax;  // @50_5fb660
  L5fb723:;
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) goto L5fb6a0;  // @52_5fb660
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @53_5fb660
  L5fb72e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L5fb75a;  // @55_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_5fb660
  ecx = ebx;  // @57_5fb660
  eax = ext_5fb370_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }));  // @58_5fb660
  ecx = edx = 0;  // @59_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @60_5fb660
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @61_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_5fb660
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @63_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_5fb660
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @65_5fb660
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @66_5fb660
  L5fb75a:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @68_5fb660
  SEH_LEAVE();  // @69_5fb660
  return eax;  // @70_5fb660
}
PCREG(5fb660, lifted_5fb660);

extern "C" u32 THISCALL lifted_63d910(u32 ecx_in) {
  SEH_ENTER(0x66e878);  // @h_63d910
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @2_63d910
  eax = (eax - (u32)(8));  // @3_63d910
  p0_ = eax;  // @4_63d910
  eax = ext_63cc50_thiscall3(ecx, (u32)(400000), (u32)(p0_));  // @5_63d910
  ecx = edx = 0;  // @6_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @8_63d910
  eax = ext_651180_thiscall1(ecx);  // @9_63d910
  ecx = edx = 0;  // @10_63d910
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L63da34;  // @11_63d910
  esi = 0;  // @12_63d910
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }) == esi) goto L63d993;  // @13_63d910
  edi = (u32)(ebx + 240);  // @14_63d910
  L63d980:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_63d910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @18_63d910
  ecx = edx = 0;  // @19_63d910
  esi = (esi + 1);  // @20_63d910
  edi = (u32)(edi + 4);  // @21_63d910
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; })) goto L63d980;  // @22_63d910
  L63d993:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @25_63d910
  eax = ext_6500b0_thiscall1(ecx);  // @26_63d910
  ecx = edx = 0;  // @27_63d910
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L63da34;  // @28_63d910
  ecx = (u32)(EBP - 52);  // @29_63d910
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(1));  // @30_63d910
  ecx = edx = 0;  // @31_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; });  // @32_63d910
  eax = (u32)(EBP - 52);  // @33_63d910
  p1_ = eax;  // @34_63d910
  reg.state = (s32)((u32)(0));  // @35_63d910
  eax = ext_63ead0_thiscall2(ecx, (u32)(p1_));  // @36_63d910
  ecx = edx = 0;  // @37_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @38_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 80)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; }), (u32)(12611839));  // @40_63d910
  ecx = edx = 0;  // @41_63d910
  eax = (u32)(EBP - 24);  // @42_63d910
  p2_ = eax;  // @43_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @44_63d910
  ecx = (u32)(EBP - 52);  // @45_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @46_63d910
  ecx = edx = 0;  // @47_63d910
  eax = (u32)(EBP - 24);  // @48_63d910
  p3_ = eax;  // @49_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @50_63d910
  ecx = (u32)(EBP - 52);  // @51_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @52_63d910
  ecx = edx = 0;  // @53_63d910
  if ((eax & eax) == 0) goto L63da2c;  // @54_63d910
  L63da02:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @56_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @57_63d910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_63d910
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }));  // @59_63d910
  p4_ = eax;  // @60_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), (u32)(8405232));  // @61_63d910
  ecx = edx = 0;  // @62_63d910
  eax = (u32)(EBP - 24);  // @63_63d910
  p5_ = eax;  // @64_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @65_63d910
  ecx = (u32)(EBP - 52);  // @66_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p5_));  // @67_63d910
  ecx = edx = 0;  // @68_63d910
  if ((eax & eax) != 0) goto L63da02;  // @69_63d910
  L63da2c:;
  ecx = (u32)(EBP - 52);  // @71_63d910
  eax = ext_4ccfe0_thiscall1(ecx);  // @72_63d910
  ecx = edx = 0;  // @73_63d910
  L63da34:;
  SEH_LEAVE();  // @75_63d910
  return eax;  // @76_63d910
}
PCREG(63d910, lifted_63d910);

extern "C" u32 THISCALL lifted_5fae50(u32 ecx_in) {
  SEH_ENTER(0x66d392);  // @h_5fae50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_5fae50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }) == (u32)(0)) goto L5faec2;  // @1_5fae50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @2_5fae50
  L5fae81:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @4_5fae50
  if ((ecx & ecx) == 0) goto L5fae94;  // @5_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @6_5fae50
  ecx = (ecx - 1);  // @7_5fae50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @8_5fae50
  ebx = (u32)(eax + ecx*4);  // @9_5fae50
  goto L5faea4;  // @10_5fae50
  L5fae94:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @12_5fae50
  if ((eax & eax) == 0) goto L5faea1;  // @13_5fae50
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @14_5fae50
  ecx = edx = 0;  // @15_5fae50
  goto L5faea4;  // @16_5fae50
  L5faea1:;
  __builtin_trap();  // @18_5fae50
  L5faea4:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_5fae50
  if ((edi & edi) == 0) goto L5faebc;  // @21_5fae50
  ecx = edi;  // @22_5fae50
  eax = ext_5fad90_thiscall1(ecx);  // @23_5fae50
  ecx = edx = 0;  // @24_5fae50
  p0_ = edi;  // @25_5fae50
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(72));  // @26_5fae50
  ecx = edx = 0;  // @27_5fae50
  L5faebc:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }) != (u32)(0)) goto L5fae81;  // @29_5fae50
  L5faec2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @31_5fae50
  if ((ecx & ecx) == 0) goto L5faecf;  // @32_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_5fae50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @34_5fae50
  ecx = edx = 0;  // @35_5fae50
  L5faecf:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }));  // @37_5fae50
  ecx = edx = 0;  // @38_5fae50
  ecx = (u32)(esi + 24);  // @39_5fae50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @41_5fae50
  eax = (eax - edx);  // @42_5fae50
  reg.state = (s32)((u32)(0));  // @43_5fae50
  if ((edx & edx) == 0) goto L5faefa;  // @44_5fae50
  if ((eax & eax) == 0) goto L5faefa;  // @45_5fae50
  p1_ = eax;  // @46_5fae50
  p2_ = edx;  // @47_5fae50
  eax = ext_54f870_stdcall2((u32)(p2_), (u32)(p1_));  // @48_5fae50
  ecx = edx = 0;  // @49_5fae50
  L5faefa:;
  ecx = (u32)(esi + 12);  // @51_5fae50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @53_5fae50
  eax = (eax - edx);  // @54_5fae50
  reg.state = (s32)((u32)(1));  // @55_5fae50
  if ((edx & edx) == 0) goto L5faf1a;  // @56_5fae50
  if ((eax & eax) == 0) goto L5faf1a;  // @57_5fae50
  p3_ = eax;  // @58_5fae50
  p4_ = edx;  // @59_5fae50
  eax = ext_54f870_stdcall2((u32)(p4_), (u32)(p3_));  // @60_5fae50
  ecx = edx = 0;  // @61_5fae50
  L5faf1a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @63_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @64_5fae50
  eax = (eax - ecx);  // @65_5fae50
  reg.state = (s32)((u32)(2));  // @66_5fae50
  if ((ecx & ecx) == 0) goto L5faf39;  // @67_5fae50
  if ((eax & eax) == 0) goto L5faf39;  // @68_5fae50
  p5_ = eax;  // @69_5fae50
  p6_ = ecx;  // @70_5fae50
  ecx = esi;  // @71_5fae50
  eax = ext_54f870_stdcall2((u32)(p6_), (u32)(p5_));  // @72_5fae50
  ecx = edx = 0;  // @73_5fae50
  L5faf39:;
  SEH_LEAVE();  // @75_5fae50
  return eax;  // @76_5fae50
}
PCREG(5fae50, lifted_5fae50);

extern "C" u32 THISCALL lifted_492250(u32 ecx_in) {
  SEH_ENTER(0x667d5b);  // @h_492250
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_492250
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }) == (u32)(0)) goto L4923b9;  // @2_492250
  eax = (u32)(EBP - 30016);  // @3_492250
  p0_ = eax;  // @4_492250
  ecx = (u32)(EBP - 30332);  // @5_492250
  eax = ext_499880_thiscall3(ecx, (u32)(p0_), (u32)(30000));  // @6_492250
  ecx = edx = 0;  // @7_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_492250
  ecx = (u32)(EBP - 30332);  // @9_492250
  reg.state = (s32)((u32)(0));  // @10_492250
  eax = ext_49a790_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }), (u32)(2));  // @11_492250
  ecx = edx = 0;  // @12_492250
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4922da;  // @13_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2994), &v, sizeof v); }  // @14_492250
  goto L4923ae;  // @15_492250
  L4922da:;
  ecx = (u32)(EBP - 30332);  // @17_492250
  eax = ext_49b340_thiscall3(ecx, (u32)(1), (u32)(4));  // @18_492250
  ecx = edx = 0;  // @19_492250
  ecx = (u32)(EBP - 30332);  // @20_492250
  eax = ext_49b2e0_thiscall2(ecx, (u32)(1));  // @21_492250
  ecx = edx = 0;  // @22_492250
  eax = (u32)(esi + 2992);  // @23_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3008), &v, sizeof v); }  // @24_492250
  p1_ = eax;  // @25_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @26_492250
  ecx = (u32)(EBP - 30332);  // @27_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p1_));  // @28_492250
  ecx = edx = 0;  // @29_492250
  eax = (u32)(esi + 2993);  // @30_492250
  p2_ = eax;  // @31_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @32_492250
  ecx = (u32)(EBP - 30332);  // @33_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p2_));  // @34_492250
  ecx = edx = 0;  // @35_492250
  eax = (u32)(esi + 2995);  // @36_492250
  p3_ = eax;  // @37_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @38_492250
  ecx = (u32)(EBP - 30332);  // @39_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p3_));  // @40_492250
  ecx = edx = 0;  // @41_492250
  eax = (u32)(esi + 23873);  // @42_492250
  p4_ = eax;  // @43_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @44_492250
  ecx = (u32)(EBP - 30332);  // @45_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p4_));  // @46_492250
  ecx = edx = 0;  // @47_492250
  eax = (u32)(esi + 2988);  // @48_492250
  p5_ = eax;  // @49_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @50_492250
  ecx = (u32)(EBP - 30332);  // @51_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p5_));  // @52_492250
  ecx = edx = 0;  // @53_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_492250
  edx = (u32)(EBP - 30332);  // @55_492250
  p6_ = edx;  // @56_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p6_));  // @58_492250
  ecx = edx = 0;  // @59_492250
  eax = (u32)(EBP - 30332);  // @60_492250
  ecx = esi;  // @61_492250
  p7_ = eax;  // @62_492250
  eax = ext_492200_stdcall1((u32)(p7_));  // @63_492250
  ecx = edx = 0;  // @64_492250
  eax = (u32)(EBP - 30332);  // @65_492250
  ecx = esi;  // @66_492250
  p8_ = eax;  // @67_492250
  eax = ext_492880_thiscall2(ecx, (u32)(p8_));  // @68_492250
  ecx = edx = 0;  // @69_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @72_492250
  ecx = edx = 0;  // @73_492250
  ecx = eax;  // @74_492250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 112)))(ecx);  // @76_492250
  ecx = edx = 0;  // @77_492250
  L4923ae:;
  ecx = (u32)(EBP - 30332);  // @79_492250
  eax = ext_499970_thiscall1(ecx);  // @80_492250
  ecx = edx = 0;  // @81_492250
  L4923b9:;
  SEH_LEAVE();  // @83_492250
  ext_633654(G(u32, 0x6f5630));  // @84_492250
  return eax;  // @85_492250
}
PCREG(492250, lifted_492250);

extern "C" u32 THISCALL lifted_4f5170(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66997b);  // @h_4f5170
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4f5170
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @1_4f5170
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4f5170
  p0_ = esi;  // @3_4f5170
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @4_4f5170
  eax = ext_4ef660_thiscall2(ecx, (u32)(p0_));  // @5_4f5170
  ecx = edx = 0;  // @6_4f5170
  ecx = (u32)(EBP - 188);  // @7_4f5170
  eax = ext_4ccba0_thiscall1(ecx);  // @8_4f5170
  ecx = edx = 0;  // @9_4f5170
  eax = (u32)(EBP - 188);  // @10_4f5170
  reg.state = (s32)((u32)(0));  // @11_4f5170
  p1_ = eax;  // @12_4f5170
  ecx = esi;  // @13_4f5170
  eax = ext_4e0fd0_thiscall2(ecx, (u32)(p1_));  // @14_4f5170
  ecx = edx = 0;  // @15_4f5170
  eax = (u32)(EBP - 208);  // @16_4f5170
  ebx = 0;  // @17_4f5170
  p2_ = eax;  // @18_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @19_4f5170
  ecx = (u32)(EBP - 188);  // @20_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @21_4f5170
  ecx = edx = 0;  // @22_4f5170
  eax = (u32)(EBP - 208);  // @23_4f5170
  p3_ = eax;  // @24_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @25_4f5170
  ecx = (u32)(EBP - 188);  // @26_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @27_4f5170
  ecx = edx = 0;  // @28_4f5170
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }) == ebx) goto L4f523b;  // @29_4f5170
  esi = (u32)(edi + 147);  // @30_4f5170
  L4f5211:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @32_4f5170
  ecx = (u32)(EBP - 188);  // @33_4f5170
  eax = (u32)(EBP - 208);  // @34_4f5170
  ebx = (ebx + 1);  // @35_4f5170
  p4_ = eax;  // @36_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @37_4f5170
  esi = (u32)(esi + 4);  // @38_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p4_));  // @39_4f5170
  ecx = edx = 0;  // @40_4f5170
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }) != (u32)(0)) goto L4f5211;  // @41_4f5170
  if ((s32)ebx >= (s32)(u32)(9)) goto L4f5262;  // @42_4f5170
  L4f523b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @44_4f5170
  edi = (u32)(edi + ebx*4);  // @45_4f5170
  esi = (esi + (u32)(143));  // @46_4f5170
  edi = (edi + (u32)(147));  // @47_4f5170
  ecx = (u32)(9);  // @48_4f5170
  ecx = (ecx - ebx);  // @49_4f5170
  esi = (u32)(esi + ebx*4);  // @50_4f5170
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @51_4f5170
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @52_4f5170
  L4f5262:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @54_4f5170
  ecx = ebx;  // @55_4f5170
  eax = ext_4e1600_thiscall1(ecx);  // @56_4f5170
  ecx = edx = 0;  // @57_4f5170
  if ((eax & 0xff) != (u32)(3)) goto L4f5295;  // @58_4f5170
  eax = (u32)(edi + 187);  // @59_4f5170
  ecx = ebx;  // @60_4f5170
  p5_ = eax;  // @61_4f5170
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p5_), (u32)(1));  // @62_4f5170
  ecx = edx = 0;  // @63_4f5170
  eax = (u32)(edi + 191);  // @64_4f5170
  ecx = ebx;  // @65_4f5170
  p6_ = eax;  // @66_4f5170
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p6_), (u32)(1));  // @67_4f5170
  ecx = edx = 0;  // @68_4f5170
  goto L4f52a9;  // @69_4f5170
  L4f5295:;
  { u32 v = (u32)((u32)(100)); __builtin_memcpy((void *)(u32)(edi + 187), &v, sizeof v); }  // @71_4f5170
  { u32 v = (u32)((u32)(100)); __builtin_memcpy((void *)(u32)(edi + 191), &v, sizeof v); }  // @72_4f5170
  L4f52a9:;
  ecx = ebx;  // @74_4f5170
  eax = ext_4e1b30_thiscall1(ecx);  // @75_4f5170
  ecx = edx = 0;  // @76_4f5170
  ecx = (u32)(EBP - 188);  // @77_4f5170
  eax = ext_4ccf60_thiscall1(ecx);  // @78_4f5170
  ecx = edx = 0;  // @79_4f5170
  SEH_LEAVE();  // @80_4f5170
  ext_633654(G(u32, 0x6f5630));  // @81_4f5170
  return eax;  // @82_4f5170
}
PCREG(4f5170, lifted_4f5170);

extern "C" u32 THISCALL lifted_4f1890(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x669912);  // @h_4f1890
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_4f1890
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4f1890
  eax = ext_4ee210_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_4f1890
  ecx = edx = 0;  // @3_4f1890
  ecx = (u32)(ebx + 159);  // @4_4f1890
  reg.state = (s32)((u32)(0));  // @5_4f1890
  { u32 v = (u32)((u32)(6917104)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_4f1890
  eax = ext_4ccad0_thiscall3(ecx, (u32)(32), (u32)(4));  // @7_4f1890
  ecx = edx = 0;  // @8_4f1890
  ecx = (u32)(ebx + 203);  // @9_4f1890
  reg.state = (s32)((u32)(1));  // @10_4f1890
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(0));  // @11_4f1890
  ecx = edx = 0;  // @12_4f1890
  ecx = (u32)(ebx + 243);  // @13_4f1890
  reg.state = (s32)((u32)(2));  // @14_4f1890
  eax = ext_4ccba0_thiscall1(ecx);  // @15_4f1890
  ecx = edx = 0;  // @16_4f1890
  ecx = (u32)(ebx + 423);  // @17_4f1890
  reg.state = (s32)((u32)(3));  // @18_4f1890
  eax = ext_4ccad0_thiscall3(ecx, (u32)(4), (u32)(0));  // @19_4f1890
  ecx = edx = 0;  // @20_4f1890
  reg.state = (s32)((u32)(4));  // @21_4f1890
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1595), &v, sizeof v); }  // @22_4f1890
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 1529), &v, sizeof v); }  // @23_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 475), &v, sizeof v); }  // @24_4f1890
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 1533), &v, sizeof v); }  // @25_4f1890
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 1535), &v, sizeof v); }  // @26_4f1890
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx + 155), &v, sizeof v); }  // @27_4f1890
  eax = ext_41e290_cdecl1((u32)(264));  // @28_4f1890
  ecx = edx = 0;  // @29_4f1890
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @30_4f1890
  reg.state = (s32)((u32)(5));  // @31_4f1890
  if ((eax & eax) == 0) goto L4f1987;  // @32_4f1890
  ecx = (u32)(ebx + 471);  // @33_4f1890
  p0_ = ecx;  // @34_4f1890
  ecx = eax;  // @35_4f1890
  eax = ext_4d8330_thiscall4(ecx, (u32)(6917996), (u32)(6917956), (u32)(p0_));  // @36_4f1890
  ecx = edx = 0;  // @37_4f1890
  edx = eax;  // @38_4f1890
  goto L4f1989;  // @39_4f1890
  L4f1987:;
  edx = 0;  // @41_4f1890
  L4f1989:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 96), &v, sizeof v); }  // @43_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4f1890
  p1_ = edx;  // @45_4f1890
  reg.state = (s32)((u32)(4));  // @46_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4f1890
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p1_));  // @48_4f1890
  ecx = edx = 0;  // @49_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @51_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4f1890
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @53_4f1890
  ecx = edx = 0;  // @54_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4f1890
  esi = eax;  // @56_4f1890
  p2_ = ebx;  // @57_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @58_4f1890
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_4f1890
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4f1890
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(p2_), (u32)(16));  // @61_4f1890
  ecx = edx = 0;  // @62_4f1890
  p3_ = eax;  // @63_4f1890
  ecx = esi;  // @64_4f1890
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6918004), (u32)(p3_));  // @65_4f1890
  ecx = edx = 0;  // @66_4f1890
  { u8 v = (u8)((u32)(254)); __builtin_memcpy((void *)(u32)(ebx + 104), &v, sizeof v); }  // @67_4f1890
  eax = ebx;  // @68_4f1890
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 106), &v, sizeof v); }  // @69_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1591), &v, sizeof v); }  // @70_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 107), &v, sizeof v); }  // @71_4f1890
  SEH_LEAVE();  // @72_4f1890
  return eax;  // @73_4f1890
}
PCREG(4f1890, lifted_4f1890);

extern "C" u32 THISCALL lifted_4637f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666a2d);  // @h_4637f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4637f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4637f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4637f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @3_4637f0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(0)) goto L463838;  // @4_4637f0
  eax = 0;  // @5_4637f0
  goto L46390f;  // @6_4637f0
  L463838:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4637f0
  esi = 0;  // @9_4637f0
  p0_ = edx;  // @10_4637f0
  edx = (u32)(EBP - 144);  // @11_4637f0
  p1_ = edx;  // @12_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 324)))(ecx, (u32)(p1_), (u32)(p0_));  // @14_4637f0
  ecx = edx = 0;  // @15_4637f0
  ecx = eax;  // @16_4637f0
  reg.state = (s32)(esi);  // @17_4637f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @18_4637f0
  ecx = edx = 0;  // @19_4637f0
  ecx = (u32)(EBP - 144);  // @20_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @21_4637f0
  reg.state = (s32)((u32)(4294967295));  // @22_4637f0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_4637f0
  ecx = edx = 0;  // @24_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @26_4637f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) == esi) goto L46390d;  // @27_4637f0
  eax = ext_41e290_cdecl1((u32)(44));  // @28_4637f0
  ecx = edx = 0;  // @29_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @30_4637f0
  reg.state = (s32)((u32)(1));  // @31_4637f0
  if ((eax & eax) == 0) goto L4638ac;  // @32_4637f0
  ecx = eax;  // @33_4637f0
  eax = ext_4e5000_thiscall1(ecx);  // @34_4637f0
  ecx = edx = 0;  // @35_4637f0
  esi = eax;  // @36_4637f0
  goto L4638ae;  // @37_4637f0
  L4638ac:;
  esi = 0;  // @39_4637f0
  L4638ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @41_4637f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_4637f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @43_4637f0
  reg.state = (s32)((u32)(4294967295));  // @44_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @45_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @47_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @48_4637f0
  p2_ = ecx;  // @49_4637f0
  p3_ = ebx;  // @50_4637f0
  p4_ = edi;  // @51_4637f0
  ecx = esi;  // @52_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(p4_), (u32)(p3_), (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }));  // @53_4637f0
  ecx = edx = 0;  // @54_4637f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L46390d;  // @55_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @56_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6838324), (u32)(453));  // @58_4637f0
  ecx = edx = 0;  // @59_4637f0
  p5_ = ebx;  // @60_4637f0
  p6_ = eax;  // @61_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @62_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p6_), (u32)(6838400), (u32)(p5_));  // @63_4637f0
  ecx = edx = 0;  // @64_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_4637f0
  ecx = esi;  // @66_4637f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @67_4637f0
  ecx = edx = 0;  // @68_4637f0
  esi = 0;  // @69_4637f0
  L46390d:;
  eax = esi;  // @71_4637f0
  L46390f:;
  SEH_LEAVE();  // @73_4637f0
  ext_633654(G(u32, 0x6f5630));  // @74_4637f0
  return eax;  // @75_4637f0
}
PCREG(4637f0, lifted_4637f0);

extern "C" u32 THISCALL lifted_43a900(u32 ecx_in) {
  SEH_ENTER(0x665cbc);  // @h_43a900
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_43a900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25), sizeof v); (u32)v; });  // @1_43a900
  if ((ecx & ecx) == 0) goto L43aa18;  // @2_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_43a900
  edx = (u32)(EBP - 24);  // @4_43a900
  p0_ = edx;  // @5_43a900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_43a900
  ecx = edx = 0;  // @7_43a900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25), sizeof v); (u32)v; });  // @8_43a900
  edx = (u32)(EBP - 24);  // @9_43a900
  p1_ = edx;  // @10_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_43a900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @12_43a900
  ecx = edx = 0;  // @13_43a900
  esi = eax;  // @14_43a900
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L43aa18;  // @15_43a900
  L43a960:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; });  // @17_43a900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @18_43a900
  eax = ext_4d9230_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @19_43a900
  ecx = edx = 0;  // @20_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_43a900
  if ((eax & eax) != 0) goto L43a9b9;  // @22_43a900
  eax = (u32)(esi - 4);  // @23_43a900
  esi = (0u - esi);  // @24_43a900
  esi = 0;  // @25_43a900
  esi = (esi & eax);  // @26_43a900
  if (esi == 0) goto L43aa00;  // @27_43a900
  ecx = esi;  // @28_43a900
  reg.state = (s32)((u32)(0));  // @29_43a900
  { u32 v = (u32)((u32)(6793180)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @30_43a900
  eax = ext_4388a0_thiscall1(ecx);  // @31_43a900
  ecx = edx = 0;  // @32_43a900
  ecx = esi;  // @33_43a900
  eax = ext_438910_thiscall1(ecx);  // @34_43a900
  ecx = edx = 0;  // @35_43a900
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 50), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L43a9b5;  // @36_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @37_43a900
  if ((eax & eax) == 0) goto L43a9b5;  // @38_43a900
  p2_ = eax;  // @39_43a900
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(1));  // @40_43a900
  ecx = edx = 0;  // @41_43a900
  L43a9b5:;
  goto L43a9f0;  // @43_43a900
  L43a9b9:;
  if (eax != (u32)(1)) goto L43a9c9;  // @45_43a900
  ecx = esi;  // @46_43a900
  eax = ext_436ec0_cdecl1((u32)(74));  // @47_43a900
  ecx = edx = 0;  // @48_43a900
  goto L43a9f7;  // @49_43a900
  L43a9c9:;
  if (eax != (u32)(2)) goto L43aa00;  // @51_43a900
  ecx = esi;  // @52_43a900
  reg.state = (s32)((u32)(1));  // @53_43a900
  eax = ext_438a60_cdecl1((u32)(18));  // @54_43a900
  ecx = edx = 0;  // @55_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @56_43a900
  if ((eax & eax) == 0) goto L43a9ee;  // @57_43a900
  p3_ = eax;  // @58_43a900
  eax = ext_634273_cdecl2((u32)(p3_), (u32)(1));  // @59_43a900
  ecx = edx = 0;  // @60_43a900
  L43a9ee:;
  L43a9f0:;
  reg.state = (s32)((u32)(4294967295));  // @63_43a900
  L43a9f7:;
  p4_ = esi;  // @65_43a900
  eax = ext_634273_cdecl2((u32)(p4_), (u32)(26));  // @66_43a900
  ecx = edx = 0;  // @67_43a900
  L43aa00:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25), sizeof v); (u32)v; });  // @69_43a900
  edx = (u32)(EBP - 24);  // @70_43a900
  p5_ = edx;  // @71_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_43a900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p5_));  // @73_43a900
  ecx = edx = 0;  // @74_43a900
  esi = eax;  // @75_43a900
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L43a960;  // @76_43a900
  L43aa18:;
  SEH_LEAVE();  // @78_43a900
  return eax;  // @79_43a900
}
PCREG(43a900, lifted_43a900);

extern "C" u32 THISCALL lifted_492880(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667e27);  // @h_492880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_492880
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_492880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_492880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_492880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(4));  // @4_492880
  ecx = edx = 0;  // @5_492880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_492880
  ecx = ebx;  // @7_492880
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 404)))(ecx);  // @8_492880
  ecx = edx = 0;  // @9_492880
  eax = ext_41e290_cdecl1((u32)(32));  // @10_492880
  ecx = edx = 0;  // @11_492880
  esi = eax;  // @12_492880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @13_492880
  reg.state = (s32)((u32)(0));  // @14_492880
  if ((esi & esi) == 0) goto L49290e;  // @15_492880
  ecx = esi;  // @16_492880
  eax = ext_4e6780_thiscall2(ecx, (u32)(1026));  // @17_492880
  ecx = edx = 0;  // @18_492880
  ecx = esi;  // @19_492880
  reg.state = (s32)((u32)(1));  // @20_492880
  { u32 v = (u32)((u32)(6871484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @21_492880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @22_492880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @23_492880
  eax = ext_48cf50_thiscall1(ecx);  // @24_492880
  ecx = edx = 0;  // @25_492880
  { u32 v = (u32)((u32)(6871512)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_492880
  goto L492910;  // @27_492880
  L49290e:;
  esi = 0;  // @29_492880
  L492910:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 7253), &v, sizeof v); }  // @31_492880
  edi = 0;  // @32_492880
  reg.state = (s32)((u32)(4294967295));  // @33_492880
  ebx = (ebx + (u32)(3149));  // @34_492880
  L492925:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_492880
  edx = (u32)(EBP - 16);  // @37_492880
  p0_ = edx;  // @38_492880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_492880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(p0_));  // @40_492880
  ecx = edx = 0;  // @41_492880
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @42_492880
  if ((esi & esi) == 0) goto L492993;  // @43_492880
  ecx = (u32)(esi + 1);  // @44_492880
  L492940:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @46_492880
  esi = (esi + 1);  // @47_492880
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L492940;  // @48_492880
  esi = (esi - ecx);  // @49_492880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_492880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_492880
  eax = (u32)(esi + 1);  // @52_492880
  p1_ = eax;  // @53_492880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, (u32)(p1_));  // @54_492880
  ecx = edx = 0;  // @55_492880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @56_492880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @57_492880
  L492960:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @59_492880
  edx = (u32)(edx + 1);  // @60_492880
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @61_492880
  eax = (u32)(eax + 1);  // @62_492880
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L492960;  // @63_492880
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @64_492880
  p2_ = edi;  // @65_492880
  p3_ = ebx;  // @66_492880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7253), sizeof v); (u32)v; });  // @67_492880
  eax = ext_493820_thiscall4(ecx, (u32)(p3_), (u32)(p2_), (u32)(1));  // @68_492880
  ecx = edx = 0;  // @69_492880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7257), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 7257), &v, sizeof v); }  // @70_492880
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(1));  // @71_492880
  ecx = edx = 0;  // @72_492880
  L492993:;
  edi = (edi + 1);  // @74_492880
  ebx = (ebx + (u32)(4));  // @75_492880
  if (edi < (u32)(1026)) goto L492925;  // @76_492880
  SEH_LEAVE();  // @77_492880
  return eax;  // @78_492880
}
PCREG(492880, lifted_492880);

extern "C" u32 THISCALL lifted_495c30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6680d1);  // @h_495c30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_495c30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @2_495c30
  { u8 v = (u8)((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; }) != (u32)(0))); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_495c30
  eax = (u32)((s32)edi * (s32)(u32)(112));  // @4_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_495c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @6_495c30
  eax = (eax + (u32)(15));  // @7_495c30
  eax = (eax & (u32)(4294967280));  // @8_495c30
  p0_ = eax;  // @9_495c30
  eax = ext_4cd9b0_fastcall4(ecx, edx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @10_495c30
  ecx = edx = 0;  // @11_495c30
  esi = eax;  // @12_495c30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_495c30
  if (esi != (u32)(-1)) goto L495ca5;  // @14_495c30
  eax = ext_42ab62_cdecl1((u32)(6874268));  // @15_495c30
  ecx = edx = 0;  // @16_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @17_495c30
  if ((ecx & ecx) == 0) goto L495ca4;  // @18_495c30
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @19_495c30
  ecx = edx = 0;  // @20_495c30
  goto L495ca5;  // @21_495c30
  L495ca4:;
  __builtin_trap();  // @23_495c30
  L495ca5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @25_495c30
  if ((ecx & ecx) == 0) goto L495cc4;  // @26_495c30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @27_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_495c30
  p1_ = edx;  // @29_495c30
  p2_ = esi;  // @30_495c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(6873924), (u32)(p2_), (u32)(p1_));  // @31_495c30
  ecx = edx = 0;  // @32_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @33_495c30
  L495cc4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @35_495c30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @37_495c30
  eax = (eax + esi);  // @38_495c30
  p3_ = eax;  // @39_495c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p3_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(11468975));  // @40_495c30
  ecx = edx = 0;  // @41_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @42_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @43_495c30
  eax = (eax + esi);  // @44_495c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @45_495c30
  if ((edi & edi) == 0) goto L495d31;  // @46_495c30
  esi = eax;  // @47_495c30
  L495cf0:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @49_495c30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @50_495c30
  reg.state = (s32)((u32)(0));  // @51_495c30
  if ((esi & esi) == 0) goto L495d08;  // @52_495c30
  ecx = esi;  // @53_495c30
  eax = ext_4d93e0_thiscall1(ecx);  // @54_495c30
  ecx = edx = 0;  // @55_495c30
  L495d08:;
  reg.state = (s32)((u32)(4294967295));  // @57_495c30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L495d23;  // @58_495c30
  ecx = esi;  // @59_495c30
  eax = ext_4dc630_thiscall3(ecx, (u32)(134217728), (u32)(0));  // @60_495c30
  ecx = edx = 0;  // @61_495c30
  L495d23:;
  esi = (esi + (u32)(112));  // @63_495c30
  edi = (edi - (u32)(1));  // @64_495c30
  if (edi != 0) goto L495cf0;  // @65_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @66_495c30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @67_495c30
  L495d31:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @69_495c30
  ecx = (ecx + esi);  // @70_495c30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) >= ecx) goto L495d3e;  // @71_495c30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @72_495c30
  L495d3e:;
  SEH_LEAVE();  // @74_495c30
  return eax;  // @75_495c30
}
PCREG(495c30, lifted_495c30);

extern "C" u32 THISCALL lifted_4f8720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669a96);  // @h_4f8720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 443), sizeof v); (u32)v; }) == (u32)(0)) goto L4f887a;  // @1_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 224)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @4_4f8720
  ecx = edx = 0;  // @5_4f8720
  esi = (eax & 0xffff);  // @6_4f8720
  if (esi < (u32)(32)) goto L4f887a;  // @7_4f8720
  if (esi == (u32)(42)) goto L4f887a;  // @8_4f8720
  if (esi == (u32)(60)) goto L4f887a;  // @9_4f8720
  if (esi == (u32)(62)) goto L4f887a;  // @10_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 451), sizeof v); (u32)v; });  // @11_4f8720
  edi = esi;  // @12_4f8720
  p0_ = edi;  // @13_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 648), sizeof v); (u32)v; });  // @15_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p0_));  // @16_4f8720
  ecx = edx = 0;  // @17_4f8720
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4f887a;  // @18_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 451), sizeof v); (u32)v; });  // @19_4f8720
  p1_ = edi;  // @20_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, (u32)(p1_));  // @22_4f8720
  ecx = edx = 0;  // @23_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 443), sizeof v); (u32)v; });  // @24_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; }));  // @26_4f8720
  ecx = edx = 0;  // @27_4f8720
  if ((eax & eax) != 0) goto L4f87e0;  // @28_4f8720
  if (esi == (u32)(32)) goto L4f887a;  // @29_4f8720
  L4f87e0:;
  if ((s32)eax >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 471), sizeof v); (u32)v; })) goto L4f887a;  // @31_4f8720
  edx = edi;  // @32_4f8720
  ecx = (u32)(EBP - 24);  // @33_4f8720
  eax = ext_4cc6e0_fastcall2(ecx, edx);  // @34_4f8720
  ecx = edx = 0;  // @35_4f8720
  eax = (u32)(EBP - 24);  // @36_4f8720
  p2_ = eax;  // @37_4f8720
  ecx = (u32)(EBP - 152);  // @38_4f8720
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p2_));  // @39_4f8720
  ecx = edx = 0;  // @40_4f8720
  eax = (u32)(EBP - 152);  // @41_4f8720
  reg.state = (s32)((u32)(0));  // @42_4f8720
  p3_ = eax;  // @43_4f8720
  eax = (u32)(EBP - 280);  // @44_4f8720
  p4_ = eax;  // @45_4f8720
  ecx = (u32)(ebx + 143);  // @46_4f8720
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p4_), (u32)(p3_));  // @47_4f8720
  ecx = edx = 0;  // @48_4f8720
  p5_ = eax;  // @49_4f8720
  ecx = (u32)(ebx + 143);  // @50_4f8720
  reg.state = (s32)((u32)(1));  // @51_4f8720
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p5_));  // @52_4f8720
  ecx = edx = 0;  // @53_4f8720
  ecx = (u32)(EBP - 280);  // @54_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @55_4f8720
  ecx = edx = 0;  // @56_4f8720
  ecx = (u32)(EBP - 152);  // @57_4f8720
  reg.state = (s32)((u32)(4294967295));  // @58_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @59_4f8720
  ecx = edx = 0;  // @60_4f8720
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @61_4f8720
  ecx = (u32)(ebx + 143);  // @62_4f8720
  eax = ext_4cc1d0_thiscall1(ecx);  // @63_4f8720
  ecx = edx = 0;  // @64_4f8720
  p6_ = eax;  // @65_4f8720
  ecx = ebx;  // @66_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, (u32)(p6_));  // @67_4f8720
  ecx = edx = 0;  // @68_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; });  // @69_4f8720
  ecx = ebx;  // @70_4f8720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @71_4f8720
  eax = (eax + 1);  // @72_4f8720
  p7_ = eax;  // @73_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 868)))(ecx, (u32)(p7_));  // @74_4f8720
  ecx = edx = 0;  // @75_4f8720
  L4f887a:;
  SEH_LEAVE();  // @77_4f8720
  ext_633654(G(u32, 0x6f5630));  // @78_4f8720
  return eax;  // @79_4f8720
}
PCREG(4f8720, lifted_4f8720);

extern "C" u32 THISCALL lifted_449d80(u32 ecx_in) {
  SEH_ENTER(0x666040);  // @h_449d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @1_449d80
  { u32 v = (u32)((u32)(6813212)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_449d80
  if ((ecx & ecx) == 0) goto L449dbd;  // @3_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_449d80
  ecx = edx = 0;  // @6_449d80
  L449dbd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @8_449d80
  if ((ecx & ecx) == 0) goto L449e6b;  // @9_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_449d80
  edx = (u32)(EBP - 24);  // @11_449d80
  p0_ = edx;  // @12_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @13_449d80
  ecx = edx = 0;  // @14_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @15_449d80
  edx = (u32)(EBP - 24);  // @16_449d80
  p1_ = edx;  // @17_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @19_449d80
  ecx = edx = 0;  // @20_449d80
  ebx = eax;  // @21_449d80
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L449e5e;  // @22_449d80
  L449de5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @24_449d80
  if ((ecx & ecx) == 0) goto L449e4a;  // @25_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_449d80
  edx = (u32)(EBP - 36);  // @27_449d80
  p2_ = edx;  // @28_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @29_449d80
  ecx = edx = 0;  // @30_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @31_449d80
  edx = (u32)(EBP - 36);  // @32_449d80
  p3_ = edx;  // @33_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @35_449d80
  ecx = edx = 0;  // @36_449d80
  esi = eax;  // @37_449d80
  if ((esi & esi) == 0) goto L449e4a;  // @38_449d80
  L449e10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @43_449d80
  ecx = edx = 0;  // @44_449d80
  if ((eax & eax) == 0) goto L449e38;  // @45_449d80
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; });  // @46_449d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_449d80
  p4_ = ebx;  // @48_449d80
  p5_ = ecx;  // @49_449d80
  ecx = eax;  // @50_449d80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(p5_), (u32)(p4_), (u32)(0));  // @51_449d80
  ecx = edx = 0;  // @52_449d80
  L449e38:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @54_449d80
  edx = (u32)(EBP - 36);  // @55_449d80
  p6_ = edx;  // @56_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p6_));  // @58_449d80
  ecx = edx = 0;  // @59_449d80
  esi = eax;  // @60_449d80
  if ((esi & esi) != 0) goto L449e10;  // @61_449d80
  L449e4a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @63_449d80
  edx = (u32)(EBP - 24);  // @64_449d80
  p7_ = edx;  // @65_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p7_));  // @67_449d80
  ecx = edx = 0;  // @68_449d80
  ebx = eax;  // @69_449d80
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L449de5;  // @70_449d80
  L449e5e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @72_449d80
  if ((ecx & ecx) == 0) goto L449e6b;  // @73_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @75_449d80
  ecx = edx = 0;  // @76_449d80
  L449e6b:;
  ecx = edi;  // @78_449d80
  eax = ext_45c3e0_thiscall1(ecx);  // @79_449d80
  ecx = edx = 0;  // @80_449d80
  SEH_LEAVE();  // @81_449d80
  return eax;  // @82_449d80
}
PCREG(449d80, lifted_449d80);

extern "C" u32 THISCALL lifted_6168f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e688);  // @h_6168f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_6168f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6168f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6168f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_6168f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_6168f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @5_6168f0
  { u32 v = (u32)((u32)(7068748)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_6168f0
  ecx = (u32)(esi + 12);  // @7_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @8_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @9_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @10_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @11_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @12_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @13_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_6168f0
  reg.state = (s32)((u32)(0));  // @15_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @16_6168f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @17_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @18_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @19_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @20_6168f0
  eax = (eax + ebx);  // @21_6168f0
  p0_ = eax;  // @22_6168f0
  eax = ext_659220_thiscall3(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 47536), sizeof v); (u32)v; }));  // @23_6168f0
  ecx = edx = 0;  // @24_6168f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L616a1f;  // @25_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 47524), sizeof v); (u32)v; });  // @26_6168f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5130), sizeof v); (u32)v; });  // @27_6168f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L6169b0;  // @28_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_6168f0
  ecx = edi;  // @30_6168f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @31_6168f0
  ecx = edx = 0;  // @32_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @33_6168f0
  L6169b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @35_6168f0
  edi = (u32)(ebx + 2);  // @36_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @37_6168f0
  ebx = 0;  // @38_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @39_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @40_6168f0
  edi = (edi + eax);  // @41_6168f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= ebx) goto L616a1f;  // @42_6168f0
  L6169d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @44_6168f0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_6168f0
  edi = (edi + (u32)(2));  // @46_6168f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @47_6168f0
  edx = (u32)(eax + ebx*8);  // @48_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @49_6168f0
  if ((s32)(eax & eax) >= 0) goto L616a16;  // @50_6168f0
  eax = (eax & (u32)(2147483647));  // @51_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @52_6168f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @53_6168f0
  eax = (u32)(edx + eax*2);  // @54_6168f0
  if ((ecx & ecx) == 0) goto L616a16;  // @55_6168f0
  esi = edi;  // @56_6168f0
  edx = ecx;  // @57_6168f0
  esi = (esi - eax);  // @58_6168f0
  L616a00:;
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; })) & 0xffff);  // @60_6168f0
  eax = (u32)(eax + 2);  // @61_6168f0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax - 2), &v, sizeof v); }  // @62_6168f0
  edx = (edx - (u32)(1));  // @63_6168f0
  if (edx != 0) goto L616a00;  // @64_6168f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @65_6168f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @66_6168f0
  L616a16:;
  ebx = (ebx + 1);  // @68_6168f0
  edi = (u32)(edi + ecx*2);  // @69_6168f0
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L6169d0;  // @70_6168f0
  L616a1f:;
  eax = esi;  // @72_6168f0
  SEH_LEAVE();  // @73_6168f0
  return eax;  // @74_6168f0
}
PCREG(6168f0, lifted_6168f0);

extern "C" u32 STDCALL lifted_601b10(u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_601b10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_601b10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_601b10
  p0_ = eax;  // @3_601b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_601b10
  eax = (u32)(EBP - 144);  // @5_601b10
  p1_ = eax;  // @6_601b10
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @7_601b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 324)))(ecx, (u32)(p1_), (u32)(p0_));  // @8_601b10
  ecx = edx = 0;  // @9_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @10_601b10
  ecx = (u32)(EBP - 144);  // @11_601b10
  reg.state = (s32)((u32)(0));  // @12_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @13_601b10
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @14_601b10
  ecx = edx = 0;  // @15_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @16_601b10
  p2_ = eax;  // @17_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @18_601b10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p2_));  // @19_601b10
  ecx = edx = 0;  // @20_601b10
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L601bf7;  // @21_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @22_601b10
  ecx = (u32)(EBP - 144);  // @23_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_601b10
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @25_601b10
  ecx = edx = 0;  // @26_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @27_601b10
  p3_ = eax;  // @28_601b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(p3_));  // @29_601b10
  ecx = edx = 0;  // @30_601b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @31_601b10
  eax = (eax + 1);  // @32_601b10
  p4_ = eax;  // @33_601b10
  eax = ext_41e290_cdecl1((u32)(p4_));  // @34_601b10
  ecx = edx = 0;  // @35_601b10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_601b10
  ecx = (u32)(EBP - 144);  // @37_601b10
  edi = eax;  // @38_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @39_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @40_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @41_601b10
  p5_ = edi;  // @42_601b10
  eax = ext_4cc1d0_cdecl4((u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), (u32)(0), (u32)(0));  // @43_601b10
  ecx = edx = 0;  // @44_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @45_601b10
  p6_ = eax;  // @46_601b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 96)))(ecx, (u32)(p6_));  // @47_601b10
  ecx = edx = 0;  // @48_601b10
  if (eax == ebx) goto L601bf1;  // @49_601b10
  p7_ = edi;  // @50_601b10
  eax = ext_41e2c0_cdecl1((u32)(p7_));  // @51_601b10
  ecx = edx = 0;  // @52_601b10
  goto L601c25;  // @53_601b10
  L601bf1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + edi), &v, sizeof v); }  // @55_601b10
  goto L601c27;  // @56_601b10
  L601bf7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @58_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_601b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051316), (u32)(121));  // @60_601b10
  ecx = edx = 0;  // @61_601b10
  esi = eax;  // @62_601b10
  ecx = (u32)(EBP - 144);  // @63_601b10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_601b10
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_601b10
  ecx = edx = 0;  // @66_601b10
  p8_ = eax;  // @67_601b10
  p9_ = esi;  // @68_601b10
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p9_), (u32)(7051372), (u32)(p8_));  // @69_601b10
  ecx = edx = 0;  // @70_601b10
  L601c25:;
  edi = 0;  // @72_601b10
  L601c27:;
  ecx = (u32)(EBP - 144);  // @74_601b10
  eax = ext_4cbec0_thiscall1(ecx);  // @75_601b10
  ecx = edx = 0;  // @76_601b10
  eax = edi;  // @77_601b10
  SEH_LEAVE();  // @78_601b10
  ext_633654(G(u32, 0x6f5630));  // @79_601b10
  return eax;  // @80_601b10
}
PCREG(601b10, lifted_601b10);

extern "C" u32 THISCALL lifted_492640(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667ddb);  // @h_492640
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @2_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_492640
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @4_492640
  ecx = edx = 0;  // @5_492640
  eax = (u32)(EBP - 30016);  // @6_492640
  p0_ = eax;  // @7_492640
  ecx = (u32)(EBP - 30332);  // @8_492640
  eax = ext_499880_thiscall3(ecx, (u32)(p0_), (u32)(30000));  // @9_492640
  ecx = edx = 0;  // @10_492640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_492640
  ecx = (u32)(EBP - 30332);  // @12_492640
  p1_ = edi;  // @13_492640
  reg.state = (s32)((u32)(0));  // @14_492640
  eax = ext_49a790_thiscall3(ecx, (u32)(p1_), (u32)(1));  // @15_492640
  ecx = edx = 0;  // @16_492640
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L492746;  // @17_492640
  ecx = (u32)(EBP - 30332);  // @18_492640
  eax = ext_49b340_thiscall3(ecx, (u32)(0), (u32)(0));  // @19_492640
  ecx = edx = 0;  // @20_492640
  ecx = (u32)(EBP - 30332);  // @21_492640
  eax = ext_49b2e0_thiscall2(ecx, (u32)(0));  // @22_492640
  ecx = edx = 0;  // @23_492640
  eax = (u32)(EBP - 30340);  // @24_492640
  p2_ = eax;  // @25_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @26_492640
  ecx = (u32)(EBP - 30332);  // @27_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p2_));  // @28_492640
  ecx = edx = 0;  // @29_492640
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30340), sizeof v); (u32)v; }) == (u32)(64)) goto L49271d;  // @30_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @31_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_492640
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(757));  // @33_492640
  ecx = edx = 0;  // @34_492640
  p3_ = eax;  // @35_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_492640
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6871012));  // @37_492640
  ecx = edx = 0;  // @38_492640
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @39_492640
  goto L49278d;  // @40_492640
  L49271d:;
  eax = (u32)(EBP - 30336);  // @42_492640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 30336), &v, sizeof v); }  // @43_492640
  p4_ = eax;  // @44_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @45_492640
  ecx = (u32)(EBP - 30332);  // @46_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(p4_));  // @47_492640
  ecx = edx = 0;  // @48_492640
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }) != (u32)(0)) goto L492756;  // @49_492640
  L492746:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_492640
  ecx = esi;  // @52_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 392)))(ecx, (u32)(1));  // @53_492640
  ecx = edx = 0;  // @54_492640
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @55_492640
  goto L49278d;  // @56_492640
  L492756:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_492640
  ecx = esi;  // @59_492640
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @60_492640
  ecx = edx = 0;  // @61_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_492640
  ecx = esi;  // @63_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }));  // @64_492640
  ecx = edx = 0;  // @65_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_492640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 6827), &v, sizeof v); }  // @67_492640
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }), (u32)(1));  // @68_492640
  ecx = edx = 0;  // @69_492640
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_492640
  L49278d:;
  ecx = (u32)(EBP - 30332);  // @72_492640
  eax = ext_499970_thiscall1(ecx);  // @73_492640
  ecx = edx = 0;  // @74_492640
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @75_492640
  SEH_LEAVE();  // @76_492640
  ext_633654(G(u32, 0x6f5630));  // @77_492640
  return eax;  // @78_492640
}
PCREG(492640, lifted_492640);

extern "C" u32 THISCALL lifted_6633d0(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_6633d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_6633d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_6633d0
  edx = (u32)(EBP - 144);  // @3_6633d0
  p0_ = edx;  // @4_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_6633d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 412)))(ecx, (u32)(p0_));  // @6_6633d0
  ecx = edx = 0;  // @7_6633d0
  ecx = eax;  // @8_6633d0
  reg.state = (s32)((u32)(0));  // @9_6633d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @10_6633d0
  ecx = edx = 0;  // @11_6633d0
  ebx = (ebx + (u32)(74164));  // @12_6633d0
  edx = ebx;  // @13_6633d0
  edx = (edx - eax);  // @14_6633d0
  L663433:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @16_6633d0
  eax = (u32)(eax + 1);  // @17_6633d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @18_6633d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663433;  // @19_6633d0
  ecx = (u32)(EBP - 144);  // @20_6633d0
  reg.state = (s32)((u32)(4294967295));  // @21_6633d0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_6633d0
  ecx = edx = 0;  // @23_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @26_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_6633d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @28_6633d0
  ecx = edx = 0;  // @29_6633d0
  esi = eax;  // @30_6633d0
  L663473:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @32_6633d0
  eax = (eax + 1);  // @33_6633d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663473;  // @34_6633d0
  eax = (eax - esi);  // @35_6633d0
  edi = (u32)(ebx - 1);  // @36_6633d0
  L663480:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @38_6633d0
  edi = (edi + 1);  // @39_6633d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663480;  // @40_6633d0
  ecx = eax;  // @41_6633d0
  ecx = (ecx >> (u32)(2));  // @42_6633d0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @43_6633d0
  ecx = eax;  // @44_6633d0
  ecx = (ecx & (u32)(3));  // @45_6633d0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 1); esi += 1; edi += 1; ecx--; }  // @46_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @47_6633d0
  p1_ = ebx;  // @48_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @50_6633d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p1_), (u32)(0));  // @51_6633d0
  ecx = edx = 0;  // @52_6633d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6634d1;  // @53_6633d0
  edi = (u32)(ebx - 1);  // @54_6633d0
  L6634b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @56_6633d0
  edi = (u32)(edi + 1);  // @57_6633d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6634b0;  // @58_6633d0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @59_6633d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @60_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @61_6633d0
  p2_ = ebx;  // @62_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_6633d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @64_6633d0
  ecx = edx = 0;  // @65_6633d0
  goto L6634e5;  // @66_6633d0
  L6634d1:;
  ebx = (ebx - 1);  // @68_6633d0
  L6634d2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; })) & 0xff);  // @70_6633d0
  ebx = (ebx + 1);  // @71_6633d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6634d2;  // @72_6633d0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @73_6633d0
  edi = ebx;  // @74_6633d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @75_6633d0
  L6634e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @77_6633d0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 73992), &v, sizeof v); }  // @78_6633d0
  SEH_LEAVE();  // @79_6633d0
  ext_633654(G(u32, 0x6f5630));  // @80_6633d0
  return eax;  // @81_6633d0
}
PCREG(6633d0, lifted_6633d0);

extern "C" u32 THISCALL lifted_480ff0(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_480ff0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_480ff0
  { u32 v = (u32)((u32)(6862416)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_480ff0
  ebx = (u32)(esi + 1117);  // @2_480ff0
  edi = 0;  // @3_480ff0
  L481025:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_480ff0
  if ((ecx & ecx) == 0) goto L481032;  // @6_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @8_480ff0
  ecx = edx = 0;  // @9_480ff0
  L481032:;
  edi = (edi + 1);  // @11_480ff0
  ebx = (ebx + (u32)(4));  // @12_480ff0
  if (edi <= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1113), sizeof v); (u32)v; })) goto L481025;  // @13_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1562), sizeof v); (u32)v; });  // @14_480ff0
  if ((ecx & ecx) == 0) goto L48104e;  // @15_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_480ff0
  ecx = edx = 0;  // @18_480ff0
  L48104e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1582), sizeof v); (u32)v; }));  // @22_480ff0
  ecx = edx = 0;  // @23_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1582), sizeof v); (u32)v; });  // @24_480ff0
  if ((ecx & ecx) == 0) goto L481072;  // @25_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @27_480ff0
  ecx = edx = 0;  // @28_480ff0
  L481072:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1586), sizeof v); (u32)v; }));  // @32_480ff0
  ecx = edx = 0;  // @33_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1586), sizeof v); (u32)v; });  // @34_480ff0
  if ((ecx & ecx) == 0) goto L481096;  // @35_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @37_480ff0
  ecx = edx = 0;  // @38_480ff0
  L481096:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1590), sizeof v); (u32)v; }));  // @42_480ff0
  ecx = edx = 0;  // @43_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1590), sizeof v); (u32)v; });  // @44_480ff0
  if ((ecx & ecx) == 0) goto L4810ba;  // @45_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @47_480ff0
  ecx = edx = 0;  // @48_480ff0
  L4810ba:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1594), sizeof v); (u32)v; }));  // @52_480ff0
  ecx = edx = 0;  // @53_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1594), sizeof v); (u32)v; });  // @54_480ff0
  if ((ecx & ecx) == 0) goto L4810de;  // @55_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @57_480ff0
  ecx = edx = 0;  // @58_480ff0
  L4810de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1578), sizeof v); (u32)v; }));  // @62_480ff0
  ecx = edx = 0;  // @63_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1578), sizeof v); (u32)v; });  // @64_480ff0
  if ((ecx & ecx) == 0) goto L481102;  // @65_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @67_480ff0
  ecx = edx = 0;  // @68_480ff0
  L481102:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1598), sizeof v); (u32)v; }));  // @72_480ff0
  ecx = edx = 0;  // @73_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1598), sizeof v); (u32)v; });  // @74_480ff0
  if ((ecx & ecx) == 0) goto L481126;  // @75_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @77_480ff0
  ecx = edx = 0;  // @78_480ff0
  L481126:;
  ecx = esi;  // @80_480ff0
  eax = ext_471f60_thiscall1(ecx);  // @81_480ff0
  ecx = edx = 0;  // @82_480ff0
  SEH_LEAVE();  // @83_480ff0
  return eax;  // @84_480ff0
}
PCREG(480ff0, lifted_480ff0);

extern "C" u32 THISCALL lifted_598eb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66bbbf);  // @h_598eb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_598eb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_598eb0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 7435), &v, sizeof v); }  // @2_598eb0
  if ((esi & esi) == 0) goto L599021;  // @3_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1654), sizeof v); (u32)v; }));  // @7_598eb0
  ecx = edx = 0;  // @8_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7431), &v, sizeof v); }  // @9_598eb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; }) != (u32)(0)) goto L598f22;  // @10_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_598eb0
  ecx = esi;  // @12_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6975112));  // @13_598eb0
  ecx = edx = 0;  // @14_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2138), &v, sizeof v); }  // @15_598eb0
  L598f22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; });  // @17_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7427), &v, sizeof v); }  // @18_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7435), sizeof v); (u32)v; });  // @19_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1668), sizeof v); (u32)v; });  // @20_598eb0
  eax = (eax - (u32)(2));  // @21_598eb0
  if (eax == 0) goto L598faa;  // @22_598eb0
  eax = (eax - (u32)(1));  // @23_598eb0
  if (eax == 0) goto L598f8c;  // @24_598eb0
  eax = (eax - (u32)(1));  // @25_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @27_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_598eb0
  if (eax == 0) goto L598f7b;  // @29_598eb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @30_598eb0
  ecx = edx = 0;  // @31_598eb0
  ecx = (u32)(EBP + 8);  // @32_598eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @33_598eb0
  p0_ = ecx;  // @34_598eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_598eb0
  ecx = eax;  // @36_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973184), (u32)(p0_));  // @37_598eb0
  ecx = edx = 0;  // @38_598eb0
  goto L598fda;  // @39_598eb0
  L598f7b:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 312)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @41_598eb0
  ecx = edx = 0;  // @42_598eb0
  ecx = (u32)(EBP - 16);  // @43_598eb0
  p1_ = ecx;  // @44_598eb0
  goto L598fc6;  // @45_598eb0
  L598f8c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @48_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, (u32)(6973232), (u32)(p1_));  // @50_598eb0
  ecx = edx = 0;  // @51_598eb0
  ecx = (u32)(EBP - 16);  // @52_598eb0
  p2_ = ecx;  // @53_598eb0
  goto L598fc6;  // @54_598eb0
  L598faa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @57_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, (u32)(6973216), (u32)(p2_));  // @59_598eb0
  ecx = edx = 0;  // @60_598eb0
  ecx = (u32)(EBP - 16);  // @61_598eb0
  p3_ = ecx;  // @62_598eb0
  L598fc6:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @64_598eb0
  ecx = eax;  // @65_598eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @66_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973200), (u32)(p3_));  // @67_598eb0
  ecx = edx = 0;  // @68_598eb0
  L598fda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @73_598eb0
  ecx = edx = 0;  // @74_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7439), &v, sizeof v); }  // @75_598eb0
  eax = ext_41e290_cdecl1((u32)(76));  // @76_598eb0
  ecx = edx = 0;  // @77_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @78_598eb0
  reg.state = (s32)((u32)(0));  // @79_598eb0
  if ((eax & eax) == 0) goto L599019;  // @80_598eb0
  ecx = eax;  // @81_598eb0
  eax = ext_5eaab0_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7439), sizeof v); (u32)v; }), (u32)(16));  // @82_598eb0
  ecx = edx = 0;  // @83_598eb0
  goto L59901b;  // @84_598eb0
  L599019:;
  eax = 0;  // @86_598eb0
  L59901b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8919), &v, sizeof v); }  // @88_598eb0
  L599021:;
  SEH_LEAVE();  // @90_598eb0
  return eax;  // @91_598eb0
}
PCREG(598eb0, lifted_598eb0);

