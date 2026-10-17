// batch200118.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 STDCALL ext_41f190_stdcall1(u32) __asm__("ext_41f190");
extern "C" u32 STDCALL ext_42da80_stdcall1(u32) __asm__("ext_42da80");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_4d8db0_stdcall2(u32, u32) __asm__("ext_4d8db0");
extern "C" u32 STDCALL ext_4d8ef0_stdcall3(u32, u32, u32) __asm__("ext_4d8ef0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 STDCALL ext_62f5d0_stdcall2(u32, u32) __asm__("ext_62f5d0");
extern "C" u32 STDCALL ext_62f980_stdcall1(u32) __asm__("ext_62f980");
extern "C" u32 STDCALL ext_62f9d0_stdcall4(u32, u32, u32, u32) __asm__("ext_62f9d0");
extern "C" u32 STDCALL ext_63da80_stdcall1(u32) __asm__("ext_63da80");
extern "C" u32 STDCALL ext_658fb0_stdcall1(u32) __asm__("ext_658fb0");
extern "C" u32 STDCALL ext_661b40_stdcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_661b40");
extern "C" u32 THISCALL ext_42de30_thiscall1(u32) __asm__("ext_42de30");
extern "C" u32 THISCALL ext_433f30_thiscall1(u32) __asm__("ext_433f30");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_43e0f0_thiscall1(u32) __asm__("ext_43e0f0");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_448a30_thiscall2(u32, u32) __asm__("ext_448a30");
extern "C" u32 THISCALL ext_45c3e0_thiscall1(u32) __asm__("ext_45c3e0");
extern "C" u32 THISCALL ext_460f90_thiscall1(u32) __asm__("ext_460f90");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_48cf50_thiscall1(u32) __asm__("ext_48cf50");
extern "C" u32 THISCALL ext_493820_thiscall4(u32, u32, u32, u32) __asm__("ext_493820");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cc690_thiscall1(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4cdcc0_thiscall1(u32) __asm__("ext_4cdcc0");
extern "C" u32 THISCALL ext_4ce180_thiscall2(u32, u32) __asm__("ext_4ce180");
extern "C" u32 THISCALL ext_4cfbe0_thiscall1(u32) __asm__("ext_4cfbe0");
extern "C" u32 THISCALL ext_4d0f30_thiscall4(u32, u32, u32, u32) __asm__("ext_4d0f30");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4dbb00_thiscall2(u32, u32) __asm__("ext_4dbb00");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6780_thiscall2(u32, u32) __asm__("ext_4e6780");
extern "C" u32 THISCALL ext_4e7160_thiscall1(u32) __asm__("ext_4e7160");
extern "C" u32 THISCALL ext_4e8450_thiscall2(u32, u32) __asm__("ext_4e8450");
extern "C" u32 THISCALL ext_4f9600_thiscall1(u32) __asm__("ext_4f9600");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_512850_thiscall2(u32, u32) __asm__("ext_512850");
extern "C" u32 THISCALL ext_53b600_thiscall1(u32) __asm__("ext_53b600");
extern "C" u32 THISCALL ext_53c590_thiscall3(u32, u32, u32) __asm__("ext_53c590");
extern "C" u32 THISCALL ext_540ed0_thiscall1(u32) __asm__("ext_540ed0");
extern "C" u32 THISCALL ext_545ee0_thiscall2(u32, u32) __asm__("ext_545ee0");
extern "C" u32 THISCALL ext_562b50_thiscall2(u32, u32) __asm__("ext_562b50");
extern "C" u32 THISCALL ext_562c20_thiscall2(u32, u32) __asm__("ext_562c20");
extern "C" u32 THISCALL ext_57d500_thiscall3(u32, u32, u32) __asm__("ext_57d500");
extern "C" u32 THISCALL ext_5adea0_thiscall1(u32) __asm__("ext_5adea0");
extern "C" u32 THISCALL ext_5ae5a0_thiscall3(u32, u32, u32) __asm__("ext_5ae5a0");
extern "C" u32 THISCALL ext_5c27f0_thiscall2(u32, u32) __asm__("ext_5c27f0");
extern "C" u32 THISCALL ext_5c2cb0_thiscall1(u32) __asm__("ext_5c2cb0");
extern "C" u32 THISCALL ext_5c2e10_thiscall2(u32, u32) __asm__("ext_5c2e10");
extern "C" u32 THISCALL ext_5c2ec0_thiscall1(u32) __asm__("ext_5c2ec0");
extern "C" u32 THISCALL ext_5c2f30_thiscall1(u32) __asm__("ext_5c2f30");
extern "C" u32 THISCALL ext_5c2f90_thiscall1(u32) __asm__("ext_5c2f90");
extern "C" u32 THISCALL ext_5c5620_thiscall1(u32) __asm__("ext_5c5620");
extern "C" u32 THISCALL ext_5c5810_thiscall1(u32) __asm__("ext_5c5810");
extern "C" u32 THISCALL ext_5f0630_thiscall1(u32) __asm__("ext_5f0630");
extern "C" u32 THISCALL ext_5f0700_thiscall2(u32, u32) __asm__("ext_5f0700");
extern "C" u32 THISCALL ext_5f0750_thiscall2(u32, u32) __asm__("ext_5f0750");
extern "C" u32 THISCALL ext_5f0880_thiscall3(u32, u32, u32) __asm__("ext_5f0880");
extern "C" u32 THISCALL ext_5f9db0_thiscall2(u32, u32) __asm__("ext_5f9db0");
extern "C" u32 THISCALL ext_5fa1e0_thiscall2(u32, u32) __asm__("ext_5fa1e0");
extern "C" u32 THISCALL ext_5fa220_thiscall2(u32, u32) __asm__("ext_5fa220");
extern "C" u32 THISCALL ext_5fad90_thiscall1(u32) __asm__("ext_5fad90");
extern "C" u32 THISCALL ext_5fb210_thiscall3(u32, u32, u32) __asm__("ext_5fb210");
extern "C" u32 THISCALL ext_601380_thiscall1(u32) __asm__("ext_601380");
extern "C" u32 THISCALL ext_616150_thiscall3(u32, u32, u32) __asm__("ext_616150");
extern "C" u32 THISCALL ext_6162f0_thiscall3(u32, u32, u32) __asm__("ext_6162f0");
extern "C" u32 THISCALL ext_6166c0_thiscall3(u32, u32, u32) __asm__("ext_6166c0");
extern "C" u32 THISCALL ext_6168c0_thiscall3(u32, u32, u32) __asm__("ext_6168c0");
extern "C" u32 THISCALL ext_6168f0_thiscall3(u32, u32, u32) __asm__("ext_6168f0");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 THISCALL ext_63db40_thiscall2(u32, u32) __asm__("ext_63db40");
extern "C" u32 THISCALL ext_63faa0_thiscall2(u32, u32) __asm__("ext_63faa0");
extern "C" u32 THISCALL ext_644900_thiscall2(u32, u32) __asm__("ext_644900");
extern "C" u32 THISCALL ext_647f70_thiscall1(u32) __asm__("ext_647f70");
extern "C" u32 THISCALL ext_648dd0_thiscall1(u32) __asm__("ext_648dd0");
extern "C" u32 THISCALL ext_64c1e0_thiscall2(u32, u32) __asm__("ext_64c1e0");
extern "C" u32 THISCALL ext_64c7e0_thiscall2(u32, u32) __asm__("ext_64c7e0");
extern "C" u32 THISCALL ext_64d5f0_thiscall2(u32, u32) __asm__("ext_64d5f0");
extern "C" u32 THISCALL ext_658d30_thiscall1(u32) __asm__("ext_658d30");
extern "C" u32 THISCALL ext_658d50_thiscall1(u32) __asm__("ext_658d50");
extern "C" u32 THISCALL ext_658f50_thiscall1(u32) __asm__("ext_658f50");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_563500_cdecl0(void) __asm__("ext_563500");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4264b0(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4264b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @1_4264b0
  { u32 v = (u32)((u32)(6785124)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_4264b0
  if ((ecx & ecx) == 0) goto L426573;  // @3_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4264b0
  edx = (u32)(EBP - 24);  // @5_4264b0
  p0_ = edx;  // @6_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(p0_));  // @7_4264b0
  ecx = edx = 0;  // @8_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @9_4264b0
  edx = (u32)(EBP - 24);  // @10_4264b0
  p1_ = edx;  // @11_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(p1_));  // @13_4264b0
  ecx = edx = 0;  // @14_4264b0
  esi = eax;  // @15_4264b0
  if ((esi & esi) == 0) goto L426573;  // @16_4264b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6774960), sizeof v); (u32)v; });  // @17_4264b0
  L426512:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @19_4264b0
  if ((ecx & ecx) == 0) goto L426520;  // @20_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @22_4264b0
  ecx = edx = 0;  // @23_4264b0
  L426520:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @25_4264b0
  if ((ecx & ecx) == 0) goto L42652e;  // @26_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @28_4264b0
  ecx = edx = 0;  // @29_4264b0
  L42652e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @31_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6785452), (u32)(27));  // @33_4264b0
  ecx = edx = 0;  // @34_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_4264b0
  p2_ = eax;  // @36_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6785504), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @37_4264b0
  ecx = edx = 0;  // @38_4264b0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(1));  // @39_4264b0
  ecx = edx = 0;  // @40_4264b0
  eax = ((u32(STDCALL *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @41_4264b0
  ecx = edx = 0;  // @42_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @43_4264b0
  edx = (u32)(EBP - 24);  // @44_4264b0
  p3_ = edx;  // @45_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(p3_));  // @47_4264b0
  ecx = edx = 0;  // @48_4264b0
  esi = eax;  // @49_4264b0
  if ((esi & esi) != 0) goto L426512;  // @50_4264b0
  L426573:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @52_4264b0
  if ((ecx & ecx) == 0) goto L426583;  // @53_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @55_4264b0
  ecx = edx = 0;  // @56_4264b0
  L426583:;
  ecx = edi;  // @58_4264b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340948), &v, sizeof v); }  // @59_4264b0
  eax = ext_433f30_thiscall1(ecx);  // @60_4264b0
  ecx = edx = 0;  // @61_4264b0
  SEH_LEAVE();  // @62_4264b0
  return eax;  // @63_4264b0
}
PCREG(4264b0, lifted_4264b0);

extern "C" u32 THISCALL lifted_5c5f30(u32 ecx_in) {
  SEH_ENTER(0x66c6b6);  // @h_5c5f30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @1_5c5f30
  { u32 v = (u32)((u32)(7029940)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f6c;  // @3_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_5c5f30
  ecx = edx = 0;  // @6_5c5f30
  L5c5f6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @8_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f79;  // @9_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_5c5f30
  ecx = edx = 0;  // @12_5c5f30
  L5c5f79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @14_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f86;  // @15_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_5c5f30
  ecx = edx = 0;  // @18_5c5f30
  L5c5f86:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @20_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f93;  // @21_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_5c5f30
  ecx = edx = 0;  // @24_5c5f30
  L5c5f93:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @26_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fff;  // @27_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5c5f30
  edx = (u32)(EBP - 24);  // @29_5c5f30
  p0_ = edx;  // @30_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @31_5c5f30
  ecx = edx = 0;  // @32_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @33_5c5f30
  edx = (u32)(EBP - 24);  // @34_5c5f30
  p1_ = edx;  // @35_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @37_5c5f30
  ecx = edx = 0;  // @38_5c5f30
  esi = eax;  // @39_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L5c5fff;  // @40_5c5f30
  L5c5fb7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @42_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fc4;  // @43_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @45_5c5f30
  ecx = edx = 0;  // @46_5c5f30
  L5c5fc4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @48_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fd1;  // @49_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @51_5c5f30
  ecx = edx = 0;  // @52_5c5f30
  L5c5fd1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @54_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fde;  // @55_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @57_5c5f30
  ecx = edx = 0;  // @58_5c5f30
  L5c5fde:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @60_5c5f30
  if ((ecx & ecx) == 0) goto L5c5feb;  // @61_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @63_5c5f30
  ecx = edx = 0;  // @64_5c5f30
  L5c5feb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @66_5c5f30
  edx = (u32)(EBP - 24);  // @67_5c5f30
  p2_ = edx;  // @68_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @70_5c5f30
  ecx = edx = 0;  // @71_5c5f30
  esi = eax;  // @72_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L5c5fb7;  // @73_5c5f30
  L5c5fff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @75_5c5f30
  if ((ecx & ecx) == 0) goto L5c600c;  // @76_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @78_5c5f30
  ecx = edx = 0;  // @79_5c5f30
  L5c600c:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @81_5c5f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @82_5c5f30
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @83_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_5c5f30
  p3_ = edi;  // @85_5c5f30
  reg.state = (s32)((u32)(0));  // @86_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @87_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p3_));  // @89_5c5f30
  ecx = edx = 0;  // @90_5c5f30
  SEH_LEAVE();  // @91_5c5f30
  return eax;  // @92_5c5f30
}
PCREG(5c5f30, lifted_5c5f30);

extern "C" u32 THISCALL lifted_4b8bf0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66bdd6);  // @h_4b8bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4b8bf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4b8bf0
  ecx = edi;  // @2_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @4_4b8bf0
  ecx = edx = 0;  // @5_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @6_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_4b8bf0
  p0_ = eax;  // @8_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @9_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p0_));  // @11_4b8bf0
  ecx = edx = 0;  // @12_4b8bf0
  if ((eax & eax) != 0) goto L4b8c93;  // @13_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(20));  // @16_4b8bf0
  ecx = edx = 0;  // @17_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @18_4b8bf0
  edi = eax;  // @19_4b8bf0
  eax = (u32)(EBP - 144);  // @20_4b8bf0
  p1_ = eax;  // @21_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p1_), (u32)(1));  // @23_4b8bf0
  ecx = edx = 0;  // @24_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4b8bf0
  ecx = eax;  // @26_4b8bf0
  reg.state = (s32)((u32)(0));  // @27_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_4b8bf0
  ecx = edx = 0;  // @29_4b8bf0
  p2_ = eax;  // @30_4b8bf0
  p3_ = edi;  // @31_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(p3_), (u32)(6891904), (u32)(p2_));  // @32_4b8bf0
  ecx = edx = 0;  // @33_4b8bf0
  ecx = (u32)(EBP - 144);  // @34_4b8bf0
  goto L4b8d68;  // @35_4b8bf0
  L4b8c93:;
  ecx = edi;  // @37_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @38_4b8bf0
  ecx = edx = 0;  // @39_4b8bf0
  ecx = edi;  // @40_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 80), &v, sizeof v); }  // @41_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @42_4b8bf0
  ecx = edx = 0;  // @43_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 84), &v, sizeof v); }  // @44_4b8bf0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @45_4b8bf0
  if ((esi & esi) == 0) goto L4b8d7e;  // @46_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_4b8bf0
  ecx = esi;  // @48_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @49_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097158));  // @50_4b8bf0
  ecx = edx = 0;  // @51_4b8bf0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4b8d20;  // @52_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @53_4b8bf0
  ecx = ebx;  // @54_4b8bf0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 89), &v, sizeof v); }  // @55_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(16));  // @56_4b8bf0
  ecx = edx = 0;  // @57_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @59_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892012), (u32)(0), (u32)(6891852), (u32)(36));  // @61_4b8bf0
  ecx = edx = 0;  // @62_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @63_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @64_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @65_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892028), (u32)(0), (u32)(6891852), (u32)(37));  // @67_4b8bf0
  ecx = edx = 0;  // @68_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 74), &v, sizeof v); }  // @69_4b8bf0
  goto L4b8d7e;  // @70_4b8bf0
  L4b8d20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @72_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(32));  // @74_4b8bf0
  ecx = edx = 0;  // @75_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @76_4b8bf0
  edi = eax;  // @77_4b8bf0
  eax = (u32)(EBP - 272);  // @78_4b8bf0
  p4_ = eax;  // @79_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p4_), (u32)(1));  // @81_4b8bf0
  ecx = edx = 0;  // @82_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @83_4b8bf0
  ecx = eax;  // @84_4b8bf0
  reg.state = (s32)((u32)(1));  // @85_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @86_4b8bf0
  ecx = edx = 0;  // @87_4b8bf0
  p5_ = eax;  // @88_4b8bf0
  p6_ = edi;  // @89_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(p6_), (u32)(6891960), (u32)(p5_));  // @90_4b8bf0
  ecx = edx = 0;  // @91_4b8bf0
  ecx = (u32)(EBP - 272);  // @92_4b8bf0
  L4b8d68:;
  reg.state = (s32)((u32)(4294967295));  // @94_4b8bf0
  eax = ext_4cbec0_thiscall1(ecx);  // @95_4b8bf0
  ecx = edx = 0;  // @96_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @97_4b8bf0
  ecx = ebx;  // @98_4b8bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @99_4b8bf0
  ecx = edx = 0;  // @100_4b8bf0
  L4b8d7e:;
  SEH_LEAVE();  // @102_4b8bf0
  ext_633654(G(u32, 0x6f5630));  // @103_4b8bf0
  return eax;  // @104_4b8bf0
}
PCREG(4b8bf0, lifted_4b8bf0);

extern "C" u32 THISCALL lifted_45d5c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66676f);  // @h_45d5c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_45d5c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @2_45d5c0
  ecx = edx = 0;  // @3_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @4_45d5c0
  if ((eax & eax) == 0) goto L45d600;  // @5_45d5c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @6_45d5c0
  L45d600:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @9_45d5c0
  eax = ext_4da3a0_thiscall1(ecx);  // @10_45d5c0
  ecx = edx = 0;  // @11_45d5c0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L45d700;  // @12_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_45d5c0
  ecx = ebx;  // @14_45d5c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @15_45d5c0
  ecx = edx = 0;  // @16_45d5c0
  eax = ext_41e290_cdecl1((u32)(28));  // @17_45d5c0
  ecx = edx = 0;  // @18_45d5c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_45d5c0
  reg.state = (s32)((u32)(0));  // @20_45d5c0
  if ((eax & eax) == 0) goto L45d641;  // @21_45d5c0
  ecx = eax;  // @22_45d5c0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @23_45d5c0
  ecx = edx = 0;  // @24_45d5c0
  ecx = eax;  // @25_45d5c0
  goto L45d643;  // @26_45d5c0
  L45d641:;
  ecx = 0;  // @28_45d5c0
  L45d643:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @30_45d5c0
  reg.state = (s32)((u32)(4294967295));  // @31_45d5c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @32_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @33_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @34_45d5c0
  if ((ecx & ecx) == 0) goto L45d700;  // @35_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_45d5c0
  edx = (u32)(EBP - 28);  // @37_45d5c0
  p0_ = edx;  // @38_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @39_45d5c0
  ecx = edx = 0;  // @40_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @41_45d5c0
  edx = (u32)(EBP - 28);  // @42_45d5c0
  p1_ = edx;  // @43_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @44_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @46_45d5c0
  ecx = edx = 0;  // @47_45d5c0
  edx = eax;  // @48_45d5c0
  if ((edx & edx) == 0) goto L45d700;  // @49_45d5c0
  L45d680:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @51_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @53_45d5c0
  ecx = edx = 0;  // @54_45d5c0
  esi = eax;  // @55_45d5c0
  if ((esi & esi) != 0) goto L45d6a7;  // @56_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @57_45d5c0
  edx = (u32)(EBP - 28);  // @58_45d5c0
  p2_ = edx;  // @59_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @60_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p2_));  // @62_45d5c0
  ecx = edx = 0;  // @63_45d5c0
  goto L45d6eb;  // @64_45d5c0
  L45d6a7:;
  ecx = ebx;  // @66_45d5c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L45d6bf;  // @67_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_45d5c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 272)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @69_45d5c0
  ecx = edx = 0;  // @70_45d5c0
  goto L45d6eb;  // @71_45d5c0
  L45d6bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @73_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 264)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @75_45d5c0
  ecx = edx = 0;  // @76_45d5c0
  edi = eax;  // @77_45d5c0
  p3_ = esi;  // @78_45d5c0
  ecx = edi;  // @79_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @80_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(p3_));  // @81_45d5c0
  ecx = edx = 0;  // @82_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @83_45d5c0
  ecx = (ecx | ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @84_45d5c0
  ecx = (ecx & (u32)(4294967283));  // @85_45d5c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @86_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @87_45d5c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @88_45d5c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @89_45d5c0
  L45d6eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @91_45d5c0
  edx = (u32)(EBP - 28);  // @92_45d5c0
  p4_ = edx;  // @93_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @94_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @96_45d5c0
  ecx = edx = 0;  // @97_45d5c0
  edx = eax;  // @98_45d5c0
  if ((edx & edx) != 0) goto L45d680;  // @99_45d5c0
  L45d700:;
  SEH_LEAVE();  // @101_45d5c0
  return eax;  // @102_45d5c0
}
PCREG(45d5c0, lifted_45d5c0);

extern "C" u32 THISCALL lifted_4ccef0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4ccef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  p0_ = edi;  // @9_4ccef0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @10_4ccef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(p0_));  // @11_4ccef0
  ecx = edx = 0;  // @12_4ccef0
  if ((edi & edi) != 0) goto L4ccf31;  // @13_4ccef0
  L4ccf40:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @15_4ccef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @16_4ccef0
  SEH_LEAVE();  // @17_4ccef0
  return eax;  // @18_4ccef0
}
PCREG(4ccef0, lifted_4ccef0);

extern "C" u32 THISCALL lifted_4cd050(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cd050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  p0_ = edi;  // @16_4cd050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @17_4cd050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(p0_));  // @18_4cd050
  ecx = edx = 0;  // @19_4cd050
  if ((edi & edi) != 0) goto L4cd0a4;  // @20_4cd050
  L4cd0b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @22_4cd050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @23_4cd050
  SEH_LEAVE();  // @24_4cd050
  return eax;  // @25_4cd050
}
PCREG(4cd050, lifted_4cd050);

extern "C" u32 THISCALL lifted_45e710(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45e710
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45e710
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L45e825;  // @1_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @3_45e710
  ecx = edx = 0;  // @4_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_45e710
  ecx = esi;  // @6_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @7_45e710
  ecx = edx = 0;  // @8_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @9_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @10_45e710
  if ((edx & edx) == 0) goto L45e78c;  // @11_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7261), sizeof v); (u32)v; });  // @14_45e710
  if (edx < ecx) goto L45e781;  // @15_45e710
  if ((ecx & ecx) == 0) goto L45e781;  // @16_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @17_45e710
  eax = (eax & (u32)(536870911));  // @18_45e710
  eax = (eax + ecx);  // @19_45e710
  if (edx < eax) goto L45e78c;  // @20_45e710
  L45e781:;
  p0_ = edx;  // @22_45e710
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @23_45e710
  ecx = edx = 0;  // @24_45e710
  L45e78c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @26_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @27_45e710
  if ((eax & eax) == 0) goto L45e7a1;  // @28_45e710
  p1_ = eax;  // @29_45e710
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(8));  // @30_45e710
  ecx = edx = 0;  // @31_45e710
  L45e7a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @33_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @34_45e710
  if ((eax & eax) == 0) goto L45e811;  // @35_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @36_45e710
  if ((eax & eax) == 0) goto L45e7c5;  // @37_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @38_45e710
  if ((edx & edx) == 0) goto L45e7c5;  // @39_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @40_45e710
  p2_ = edx;  // @41_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p2_));  // @43_45e710
  ecx = edx = 0;  // @44_45e710
  L45e7c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @46_45e710
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @47_45e710
  if ((edi & edi) == 0) goto L45e811;  // @48_45e710
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @49_45e710
  if ((ebx & ebx) == 0) goto L45e806;  // @50_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @51_45e710
  reg.state = (s32)((u32)(0));  // @52_45e710
  if ((ecx & ecx) == 0) goto L45e7f4;  // @53_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @54_45e710
  if ((edx & edx) == 0) goto L45e7f4;  // @55_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_45e710
  p3_ = edx;  // @57_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p3_));  // @58_45e710
  ecx = edx = 0;  // @59_45e710
  L45e7f4:;
  p4_ = ebx;  // @61_45e710
  eax = ext_634273_cdecl2((u32)(p4_), (u32)(16));  // @62_45e710
  ecx = edx = 0;  // @63_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @64_45e710
  L45e806:;
  p5_ = edi;  // @66_45e710
  eax = ext_634273_cdecl2((u32)(p5_), (u32)(8));  // @67_45e710
  ecx = edx = 0;  // @68_45e710
  L45e811:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }), (u32)(32));  // @70_45e710
  ecx = edx = 0;  // @71_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @72_45e710
  L45e825:;
  SEH_LEAVE();  // @74_45e710
  return eax;  // @75_45e710
}
PCREG(45e710, lifted_45e710);

extern "C" u32 THISCALL lifted_452bc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666326);  // @h_452bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_452bc0
  p0_ = esi;  // @2_452bc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @3_452bc0
  eax = ext_448a30_thiscall2(ecx, (u32)(p0_));  // @4_452bc0
  ecx = edx = 0;  // @5_452bc0
  ecx = esi;  // @6_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @7_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @8_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @9_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @10_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @11_452bc0
  ecx = edx = 0;  // @12_452bc0
  if ((eax & 0xff) != (u32)(2)) goto L452d47;  // @13_452bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_452bc0
  ecx = ebx;  // @15_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @16_452bc0
  ecx = edx = 0;  // @17_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @18_452bc0
  esi = eax;  // @19_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(63));  // @21_452bc0
  ecx = edx = 0;  // @22_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_452bc0
  edi = eax;  // @24_452bc0
  eax = (u32)(EBP - 156);  // @25_452bc0
  ecx = esi;  // @26_452bc0
  p1_ = eax;  // @27_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p1_), (u32)(1));  // @28_452bc0
  ecx = edx = 0;  // @29_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_452bc0
  ecx = eax;  // @31_452bc0
  reg.state = (s32)((u32)(0));  // @32_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @33_452bc0
  ecx = edx = 0;  // @34_452bc0
  p2_ = eax;  // @35_452bc0
  p3_ = edi;  // @36_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 48)))((u32)(p3_), (u32)(6813044), (u32)(p2_));  // @37_452bc0
  ecx = edx = 0;  // @38_452bc0
  reg.state = (s32)((u32)(4294967295));  // @39_452bc0
  ecx = (u32)(EBP - 156);  // @40_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @41_452bc0
  ecx = edx = 0;  // @42_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @43_452bc0
  ecx = esi;  // @44_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @45_452bc0
  ecx = edx = 0;  // @46_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452cbb;  // @47_452bc0
  eax = (u32)(EBP - 288);  // @48_452bc0
  ecx = esi;  // @49_452bc0
  p4_ = eax;  // @50_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p4_), (u32)(1));  // @51_452bc0
  ecx = edx = 0;  // @52_452bc0
  goto L452d47;  // @53_452bc0
  L452cbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_452bc0
  ecx = ebx;  // @56_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @57_452bc0
  ecx = edx = 0;  // @58_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @59_452bc0
  esi = eax;  // @60_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(68));  // @62_452bc0
  ecx = edx = 0;  // @63_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_452bc0
  edi = eax;  // @65_452bc0
  eax = (u32)(EBP - 284);  // @66_452bc0
  ecx = esi;  // @67_452bc0
  p5_ = eax;  // @68_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p5_), (u32)(1));  // @69_452bc0
  ecx = edx = 0;  // @70_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @71_452bc0
  ecx = eax;  // @72_452bc0
  reg.state = (s32)((u32)(1));  // @73_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @74_452bc0
  ecx = edx = 0;  // @75_452bc0
  p6_ = eax;  // @76_452bc0
  p7_ = edi;  // @77_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p7_), (u32)(6822612), (u32)(p6_));  // @78_452bc0
  ecx = edx = 0;  // @79_452bc0
  reg.state = (s32)((u32)(4294967295));  // @80_452bc0
  ecx = (u32)(EBP - 284);  // @81_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @82_452bc0
  ecx = edx = 0;  // @83_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @84_452bc0
  eax = (u32)(EBP - 28);  // @85_452bc0
  p8_ = eax;  // @86_452bc0
  ecx = esi;  // @87_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(p8_), (u32)(1));  // @88_452bc0
  ecx = edx = 0;  // @89_452bc0
  eax = (u32)(EBP - 24);  // @90_452bc0
  ecx = esi;  // @91_452bc0
  p9_ = eax;  // @92_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(p9_), (u32)(1));  // @93_452bc0
  ecx = edx = 0;  // @94_452bc0
  eax = (u32)(EBP - 20);  // @95_452bc0
  ecx = esi;  // @96_452bc0
  p10_ = eax;  // @97_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(p10_), (u32)(1));  // @98_452bc0
  ecx = edx = 0;  // @99_452bc0
  L452d47:;
  eax = (u32)(EBP - 292);  // @101_452bc0
  ecx = esi;  // @102_452bc0
  p11_ = eax;  // @103_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p11_), (u32)(1));  // @104_452bc0
  ecx = edx = 0;  // @105_452bc0
  eax = (u32)(EBP - 296);  // @106_452bc0
  ecx = esi;  // @107_452bc0
  p12_ = eax;  // @108_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p12_), (u32)(1));  // @109_452bc0
  ecx = edx = 0;  // @110_452bc0
  ecx = esi;  // @111_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @112_452bc0
  ecx = edx = 0;  // @113_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d82;  // @114_452bc0
  eax = (u32)(EBP - 300);  // @115_452bc0
  ecx = esi;  // @116_452bc0
  p13_ = eax;  // @117_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p13_), (u32)(1));  // @118_452bc0
  ecx = edx = 0;  // @119_452bc0
  L452d82:;
  ecx = esi;  // @121_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @122_452bc0
  ecx = edx = 0;  // @123_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d9d;  // @124_452bc0
  eax = (u32)(EBP - 304);  // @125_452bc0
  ecx = esi;  // @126_452bc0
  p14_ = eax;  // @127_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p14_), (u32)(1));  // @128_452bc0
  ecx = edx = 0;  // @129_452bc0
  L452d9d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) & (u32)(4294955007))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @131_452bc0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; }) == (u32)(0)) goto L452db4;  // @132_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(4096))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @133_452bc0
  L452db4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L452dc4;  // @135_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(8192))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @136_452bc0
  L452dc4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; }) == (u32)(0)) goto L452dd4;  // @138_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(16384))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @139_452bc0
  L452dd4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; }) == (u32)(0)) goto L452de4;  // @141_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(32768))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @142_452bc0
  L452de4:;
  ecx = esi;  // @144_452bc0
  eax = ext_4e1b30_thiscall1(ecx);  // @145_452bc0
  ecx = edx = 0;  // @146_452bc0
  SEH_LEAVE();  // @147_452bc0
  ext_633654(G(u32, 0x6f5630));  // @148_452bc0
  return eax;  // @149_452bc0
}
PCREG(452bc0, lifted_452bc0);

extern "C" u32 THISCALL lifted_4627d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66693b);  // @h_4627d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @2_4627d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16604), &v, sizeof v); }  // @3_4627d0
  ecx = (u32)(edi + edi*2);  // @4_4627d0
  ecx = (u32)(eax + ecx*8);  // @5_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @6_4627d0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4629f7;  // @7_4627d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @8_4627d0
  eax = (eax & (u32)(4294967292));  // @9_4627d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @10_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @11_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @12_4627d0
  ecx = esi;  // @13_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_4627d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16612), &v, sizeof v); }  // @15_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @16_4627d0
  ecx = edx = 0;  // @17_4627d0
  edi = (u32)(edi + edi*2);  // @18_4627d0
  edi = (edi + edi);  // @19_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 47), sizeof v); (u32)v; }) == (u32)(3)) goto L462909;  // @20_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L462909;  // @21_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }) != (u32)(0)) goto L462909;  // @22_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4627d0
  ecx = esi;  // @24_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @25_4627d0
  ecx = edx = 0;  // @26_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 12), sizeof v); (u32)v; });  // @27_4627d0
  if ((s32)(edi & edi) < 0) goto L462909;  // @28_4627d0
  L462880:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @30_4627d0
  ecx = (u32)(edi + edi*2);  // @31_4627d0
  ebx = (u32)(eax + ecx*8);  // @32_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @33_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16608), &v, sizeof v); }  // @34_4627d0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4628a1;  // @35_4627d0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; })) goto L4628ba;  // @36_4627d0
  L4628a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_4627d0
  ecx = esi;  // @39_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @40_4627d0
  ecx = edx = 0;  // @41_4627d0
  ecx = (u32)(edi + edi*2);  // @42_4627d0
  ecx = (ecx + ecx);  // @43_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 12), sizeof v); (u32)v; });  // @44_4627d0
  if ((s32)(edi & edi) >= 0) goto L462880;  // @45_4627d0
  goto L462903;  // @46_4627d0
  L4628ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_4627d0
  ecx = esi;  // @49_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 700)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; }));  // @50_4627d0
  ecx = edx = 0;  // @51_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @52_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16608), sizeof v); (u32)v; });  // @53_4627d0
  p0_ = eax;  // @54_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 48)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(p0_));  // @56_4627d0
  ecx = edx = 0;  // @57_4627d0
  ecx = eax;  // @58_4627d0
  if ((ecx & ecx) == 0) goto L462903;  // @59_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_4627d0
  p1_ = edi;  // @61_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 848), sizeof v); (u32)v; });  // @62_4627d0
  p2_ = ecx;  // @63_4627d0
  ecx = esi;  // @64_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; }), (u32)(p1_));  // @65_4627d0
  ecx = edx = 0;  // @66_4627d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462903;  // @67_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @68_4627d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 68), &v, sizeof v); }  // @69_4627d0
  L462903:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @71_4627d0
  L462909:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @73_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) != 0) goto L4629f7;  // @74_4627d0
  ecx = (u32)(EBP - 16596);  // @75_4627d0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @76_4627d0
  eax = ext_4d2280_thiscall1(ecx);  // @77_4627d0
  ecx = edx = 0;  // @78_4627d0
  edi = (u32)(ebx + 76);  // @79_4627d0
  reg.state = (s32)((u32)(0));  // @80_4627d0
  p3_ = edi;  // @81_4627d0
  ecx = (u32)(EBP - 16596);  // @82_4627d0
  eax = ext_4d39a0_stdcall2((u32)(6838552), (u32)(p3_));  // @83_4627d0
  ecx = edx = 0;  // @84_4627d0
  ecx = (u32)(EBP - 16596);  // @85_4627d0
  eax = ext_4d3ab0_stdcall2((u32)(6838564), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @86_4627d0
  ecx = edx = 0;  // @87_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @88_4627d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) == 0) goto L462979;  // @89_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_4627d0
  eax = (u32)(EBP - 16596);  // @91_4627d0
  p4_ = eax;  // @92_4627d0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 296), sizeof v); (u32)v; });  // @93_4627d0
  ecx = esi;  // @94_4627d0
  p5_ = eax;  // @95_4627d0
  p6_ = esi;  // @96_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(p6_), (u32)(p5_), (u32)(p4_));  // @97_4627d0
  ecx = edx = 0;  // @98_4627d0
  L462979:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_4627d0
  ecx = esi;  // @101_4627d0
  p7_ = edi;  // @102_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 836)))(ecx, (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16612), sizeof v); (u32)v; }));  // @103_4627d0
  ecx = edx = 0;  // @104_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @105_4627d0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @106_4627d0
  if ((ecx & ecx) == 0) goto L4629ec;  // @107_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_4627d0
  edx = (u32)(EBP - 16624);  // @109_4627d0
  p8_ = edx;  // @110_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p8_));  // @111_4627d0
  ecx = edx = 0;  // @112_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @113_4627d0
  edx = (u32)(EBP - 16624);  // @114_4627d0
  p9_ = edx;  // @115_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p9_));  // @117_4627d0
  ecx = edx = 0;  // @118_4627d0
  edx = eax;  // @119_4627d0
  if ((edx & edx) == 0) goto L4629ec;  // @120_4627d0
  L4629b4:;
  ecx = (u32)(edx + 4);  // @122_4627d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L4629d7;  // @123_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; }) != (u32)(-2)) goto L4629d7;  // @124_4627d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 68), &v, sizeof v); }  // @125_4627d0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @126_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @127_4627d0
  p10_ = ecx;  // @128_4627d0
  ecx = esi;  // @129_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 844)))(ecx, (u32)(p10_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @130_4627d0
  ecx = edx = 0;  // @131_4627d0
  L4629d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @133_4627d0
  edx = (u32)(EBP - 16624);  // @134_4627d0
  p11_ = edx;  // @135_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p11_));  // @137_4627d0
  ecx = edx = 0;  // @138_4627d0
  edx = eax;  // @139_4627d0
  if ((edx & edx) != 0) goto L4629b4;  // @140_4627d0
  L4629ec:;
  ecx = (u32)(EBP - 16596);  // @142_4627d0
  eax = ext_4d2330_thiscall1(ecx);  // @143_4627d0
  ecx = edx = 0;  // @144_4627d0
  L4629f7:;
  SEH_LEAVE();  // @146_4627d0
  ext_633654(G(u32, 0x6f5630));  // @147_4627d0
  return eax;  // @148_4627d0
}
PCREG(4627d0, lifted_4627d0);

extern "C" u32 THISCALL lifted_4af780(u32 ecx_in) {
  SEH_ENTER(0x668936);  // @h_4af780
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4af780
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }) != (u32)(0)) goto L4af7f8;  // @1_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; }) != (u32)(0)) goto L4af7f8;  // @2_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @6_4af780
  ecx = edx = 0;  // @7_4af780
  ecx = (u32)(EBP - 276);  // @8_4af780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @9_4af780
  p0_ = ecx;  // @10_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @11_4af780
  ecx = eax;  // @12_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(p0_));  // @13_4af780
  ecx = edx = 0;  // @14_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @15_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @16_4af780
  L4af7f8:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) != (u32)(0)) goto L4af83a;  // @18_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @22_4af780
  ecx = edx = 0;  // @23_4af780
  ecx = (u32)(EBP - 276);  // @24_4af780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @25_4af780
  p1_ = ecx;  // @26_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_4af780
  ecx = eax;  // @28_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(p1_));  // @29_4af780
  ecx = edx = 0;  // @30_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @31_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @32_4af780
  L4af83a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }) != (u32)(0)) goto L4af8ac;  // @34_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @37_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @40_4af780
  ecx = edx = 0;  // @41_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_4af780
  p2_ = eax;  // @43_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @44_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, (u32)(p2_));  // @45_4af780
  ecx = edx = 0;  // @46_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @47_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; }) == (u32)(0)) goto L4af8ac;  // @48_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @49_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(50));  // @51_4af780
  ecx = edx = 0;  // @52_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @53_4af780
  edx = (u32)(6801640);  // @54_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @55_4af780
  if ((ecx & ecx) != 0) edx = ecx;  // @56_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_4af780
  p3_ = edx;  // @58_4af780
  p4_ = eax;  // @59_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p4_), (u32)(6885096), (u32)(p3_));  // @60_4af780
  ecx = edx = 0;  // @61_4af780
  L4af8ac:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; }) == (u32)(0)) goto L4af8bf;  // @63_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @64_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @66_4af780
  ecx = edx = 0;  // @67_4af780
  L4af8bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @70_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @72_4af780
  ecx = edx = 0;  // @73_4af780
  if ((eax & eax) != 0) goto L4af93e;  // @74_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; }) != (eax & 0xff)) goto L4af944;  // @75_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @76_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(58));  // @78_4af780
  ecx = edx = 0;  // @79_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @80_4af780
  edi = eax;  // @81_4af780
  eax = (u32)(EBP - 144);  // @82_4af780
  p5_ = eax;  // @83_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p5_), (u32)(1));  // @85_4af780
  ecx = edx = 0;  // @86_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @87_4af780
  ecx = eax;  // @88_4af780
  reg.state = (s32)((u32)(0));  // @89_4af780
  eax = ext_4cc1d0_thiscall1(ecx);  // @90_4af780
  ecx = edx = 0;  // @91_4af780
  p6_ = eax;  // @92_4af780
  p7_ = edi;  // @93_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p7_), (u32)(6885156), (u32)(p6_));  // @94_4af780
  ecx = edx = 0;  // @95_4af780
  reg.state = (s32)((u32)(4294967295));  // @96_4af780
  ecx = (u32)(EBP - 144);  // @97_4af780
  eax = ext_4cbec0_thiscall1(ecx);  // @98_4af780
  ecx = edx = 0;  // @99_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @100_4af780
  ecx = ebx;  // @101_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @102_4af780
  ecx = edx = 0;  // @103_4af780
  goto L4af9c8;  // @104_4af780
  L4af93e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; }) == (u32)(0)) goto L4af9bb;  // @106_4af780
  L4af944:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @109_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; }));  // @111_4af780
  ecx = edx = 0;  // @112_4af780
  if ((eax & eax) != 0) goto L4af9bb;  // @113_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @114_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(65));  // @116_4af780
  ecx = edx = 0;  // @117_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @118_4af780
  edi = eax;  // @119_4af780
  eax = (u32)(EBP - 272);  // @120_4af780
  p8_ = eax;  // @121_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p8_), (u32)(1));  // @123_4af780
  ecx = edx = 0;  // @124_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @125_4af780
  ecx = eax;  // @126_4af780
  reg.state = (s32)((u32)(1));  // @127_4af780
  eax = ext_4cc1d0_thiscall1(ecx);  // @128_4af780
  ecx = edx = 0;  // @129_4af780
  p9_ = eax;  // @130_4af780
  p10_ = edi;  // @131_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p10_), (u32)(6885216), (u32)(p9_));  // @132_4af780
  ecx = edx = 0;  // @133_4af780
  reg.state = (s32)((u32)(4294967295));  // @134_4af780
  ecx = (u32)(EBP - 272);  // @135_4af780
  eax = ext_4cbec0_thiscall1(ecx);  // @136_4af780
  ecx = edx = 0;  // @137_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @138_4af780
  ecx = ebx;  // @139_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @140_4af780
  ecx = edx = 0;  // @141_4af780
  goto L4af9c8;  // @142_4af780
  L4af9bb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @144_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(1));  // @146_4af780
  ecx = edx = 0;  // @147_4af780
  L4af9c8:;
  SEH_LEAVE();  // @149_4af780
  ext_633654(G(u32, 0x6f5630));  // @150_4af780
  return eax;  // @151_4af780
}
PCREG(4af780, lifted_4af780);

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

extern "C" u32 THISCALL lifted_5379b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a892);  // @h_5379b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  p0_ = eax;  // @6_5379b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_5379b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6955384));  // @8_5379b0
  ecx = edx = 0;  // @9_5379b0
  SEH_LEAVE();  // @10_5379b0
  return eax;  // @11_5379b0
  L537a11:;
  eax = ext_41e290_cdecl1((u32)(4618));  // @13_5379b0
  ecx = edx = 0;  // @14_5379b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @15_5379b0
  reg.state = (s32)((u32)(0));  // @16_5379b0
  if ((eax & eax) == 0) goto L537a35;  // @17_5379b0
  ecx = eax;  // @18_5379b0
  eax = ext_53b600_thiscall1(ecx);  // @19_5379b0
  ecx = edx = 0;  // @20_5379b0
  goto L537a37;  // @21_5379b0
  L537a35:;
  eax = 0;  // @23_5379b0
  L537a37:;
  ecx = eax;  // @25_5379b0
  reg.state = (s32)((u32)(4294967295));  // @26_5379b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 21246), &v, sizeof v); }  // @27_5379b0
  eax = ext_53c590_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @28_5379b0
  ecx = edx = 0;  // @29_5379b0
  SEH_LEAVE();  // @30_5379b0
  return eax;  // @31_5379b0
}
PCREG(5379b0, lifted_5379b0);

extern "C" u32 THISCALL lifted_645100(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_645100
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 63), &v, sizeof v); }  // @1_645100
  return eax;  // @2_645100
}
PCREG(645100, lifted_645100);

extern "C" u32 THISCALL lifted_4b1bd0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4b1bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b1bd0
  eax = ext_4e5ea0_thiscall1(ecx);  // @2_4b1bd0
  ecx = edx = 0;  // @3_4b1bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @4_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4b1bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @6_4b1bd0
  if ((ecx & ecx) == 0) goto L4b1c06;  // @7_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4b1bd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7236676), (u32)(6887628), (u32)(0));  // @9_4b1bd0
  ecx = edx = 0;  // @10_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4b1bd0
  L4b1c06:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @13_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4b1bd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6887828));  // @15_4b1bd0
  ecx = edx = 0;  // @16_4b1bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @17_4b1bd0
  return eax;  // @18_4b1bd0
}
PCREG(4b1bd0, lifted_4b1bd0);

extern "C" u32 THISCALL lifted_438c60(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_438c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4628), sizeof v); (u32)v; });  // @1_438c60
  if ((ecx & ecx) == 0) goto L438caf;  // @2_438c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_438c60
  edx = (u32)(EBP - 12);  // @4_438c60
  p0_ = edx;  // @5_438c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_438c60
  ecx = edx = 0;  // @7_438c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4628), sizeof v); (u32)v; });  // @8_438c60
  edx = (u32)(EBP - 12);  // @9_438c60
  p1_ = edx;  // @10_438c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_438c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @12_438c60
  ecx = edx = 0;  // @13_438c60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == (u32)(0)) goto L438caf;  // @14_438c60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_438c60
  L438c95:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 21), sizeof v); (u32)v; }) == esi) goto L438cb1;  // @17_438c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4628), sizeof v); (u32)v; });  // @18_438c60
  edx = (u32)(EBP - 12);  // @19_438c60
  p2_ = edx;  // @20_438c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_438c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @22_438c60
  ecx = edx = 0;  // @23_438c60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) != (u32)(0)) goto L438c95;  // @24_438c60
  L438caf:;
  eax = 0;  // @26_438c60
  L438cb1:;
  return eax;  // @28_438c60
}
PCREG(438c60, lifted_438c60);

extern "C" u32 lifted_630120(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_630120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5812), sizeof v); (u32)v; });  // @1_630120
  if (eax != (u32)(16)) goto L63016a;  // @2_630120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @3_630120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @4_630120
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5808), sizeof v); (u32)v; });  // @5_630120
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @6_630120
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @7_630120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @8_630120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @9_630120
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5809), sizeof v); (u32)v; });  // @10_630120
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @11_630120
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @12_630120
  eax = 0;  // @13_630120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 5812), &v, sizeof v); }  // @14_630120
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 5808), &v, sizeof v); }  // @15_630120
  return eax;  // @16_630120
  L63016a:;
  if ((s32)eax < (s32)(u32)(8)) goto L630196;  // @18_630120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @19_630120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @20_630120
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5808), sizeof v); (u32)v; })) & 0xff);  // @21_630120
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @22_630120
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5809), sizeof v); (u32)v; });  // @23_630120
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @24_630120
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5812), sizeof v); (u32)v; }) + (u32)(-8))); __builtin_memcpy((void *)(u32)(esi + 5812), &v, sizeof v); }  // @25_630120
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 5808), &v, sizeof v); }  // @26_630120
  L630196:;
  return eax;  // @28_630120
}
PCREG(630120, lifted_630120);

extern "C" u32 THISCALL lifted_440ce0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_440ce0
  edx = ecx;  // @1_440ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @2_440ce0
  if ((eax & eax) == 0) goto L440d0e;  // @3_440ce0
  L440cf0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @5_440ce0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) & 0xff);  // @6_440ce0
  if ((eax & 0xff) >= (u32)(2)) goto L440d0e;  // @7_440ce0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L440d08;  // @8_440ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @9_440ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @10_440ce0
  if ((eax & eax) != 0) goto L440cf0;  // @11_440ce0
  goto L440d0e;  // @12_440ce0
  L440d08:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @14_440ce0
  L440d0e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @16_440ce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @17_440ce0
  if ((eax & eax) == 0) goto L440d3c;  // @18_440ce0
  ecx = (u32)(eax + 12);  // @19_440ce0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @20_440ce0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L440d2d;  // @21_440ce0
  eax = (u32)(ecx + 4);  // @22_440ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @23_440ce0
  L440d2d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @25_440ce0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @26_440ce0
  eax = (eax + (u32)(3));  // @27_440ce0
  eax = (u32)(ecx + eax*4);  // @28_440ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @29_440ce0
  L440d3c:;
  return eax;  // @31_440ce0
}
PCREG(440ce0, lifted_440ce0);

extern "C" u32 THISCALL lifted_5c2d90(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_5c2d90
  eax = ext_5c2ec0_thiscall1(ecx);  // @1_5c2d90
  ecx = edx = 0;  // @2_5c2d90
  ecx = esi;  // @3_5c2d90
  eax = ext_5c2f90_thiscall1(ecx);  // @4_5c2d90
  ecx = edx = 0;  // @5_5c2d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_5c2d90
  if ((eax & eax) == 0) goto L5c2deb;  // @7_5c2d90
  p0_ = eax;  // @8_5c2d90
  ecx = esi;  // @9_5c2d90
  eax = ext_5c2e10_thiscall2(ecx, (u32)(p0_));  // @10_5c2d90
  ecx = edx = 0;  // @11_5c2d90
  if ((eax & eax) == 0) goto L5c2deb;  // @12_5c2d90
  ecx = eax;  // @13_5c2d90
  eax = ext_5c2cb0_thiscall1(ecx);  // @14_5c2d90
  ecx = edx = 0;  // @15_5c2d90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @16_5c2d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @17_5c2d90
  if (eax == (u32)(-1)) goto L5c2deb;  // @18_5c2d90
  ecx = (u32)(eax*8);  // @19_5c2d90
  ecx = (ecx - eax);  // @20_5c2d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ecx*2 + 8), sizeof v); (u32)v; });  // @21_5c2d90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @22_5c2d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @23_5c2d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_5c2d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @25_5c2d90
  ecx = esi;  // @26_5c2d90
  eax = ext_5c2f30_thiscall1(ecx);  // @27_5c2d90
  ecx = edx = 0;  // @28_5c2d90
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @29_5c2d90
  return eax;  // @30_5c2d90
  L5c2deb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @32_5c2d90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @33_5c2d90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_5c2d90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @35_5c2d90
  return eax;  // @36_5c2d90
}
PCREG(5c2d90, lifted_5c2d90);

extern "C" u32 THISCALL lifted_45e420(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ecx;  // @0_45e420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @1_45e420
  if ((s32)(esi & esi) >= 0) goto L45e473;  // @2_45e420
  if ((esi & (u32)(1073741824)) == 0) goto L45e440;  // @3_45e420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @4_45e420
  ecx = (ecx + (u32)(5));  // @5_45e420
  ecx = (u32)(edx + ecx*4);  // @6_45e420
  goto L45e443;  // @7_45e420
  L45e440:;
  ecx = (u32)(edx + 16);  // @9_45e420
  L45e443:;
  if ((ecx & ecx) == 0) goto L45e473;  // @11_45e420
  if ((s32)(esi & esi) >= 0) goto L45e450;  // @12_45e420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @13_45e420
  goto L45e452;  // @14_45e420
  L45e450:;
  edx = 0;  // @16_45e420
  L45e452:;
  if ((s32)(edx & edx) <= 0) goto L45e473;  // @18_45e420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_45e420
  L45e460:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) == esi) goto L45e47a;  // @21_45e420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @22_45e420
  edx = (edx - 1);  // @23_45e420
  eax = (eax & (u32)(1073741823));  // @24_45e420
  ecx = (ecx + eax);  // @25_45e420
  if ((s32)(edx & edx) > 0) goto L45e460;  // @26_45e420
  L45e473:;
  eax = 0;  // @28_45e420
  return eax;  // @29_45e420
  L45e47a:;
  eax = ecx;  // @31_45e420
  return eax;  // @32_45e420
}
PCREG(45e420, lifted_45e420);

extern "C" u32 THISCALL lifted_4cd540(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4cd540
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4cd557;  // @1_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @2_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @3_4cd540
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; })) goto L4cd597;  // @4_4cd540
  L4cd557:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4cd540
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 128)))(ecx);  // @7_4cd540
  ecx = edx = 0;  // @8_4cd540
  ecx = eax;  // @9_4cd540
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @10_4cd540
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cd57f;  // @11_4cd540
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @12_4cd540
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @13_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @14_4cd540
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @15_4cd540
  goto L4cd58d;  // @16_4cd540
  L4cd57f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @18_4cd540
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @19_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @20_4cd540
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @21_4cd540
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @22_4cd540
  L4cd58d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @24_4cd540
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @25_4cd540
  L4cd597:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @27_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @28_4cd540
  edx = (u32)(ecx + eax*4);  // @29_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_4cd540
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @31_4cd540
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @33_4cd540
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @34_4cd540
  eax = (u32)(edx + 20);  // @35_4cd540
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @36_4cd540
  return eax;  // @37_4cd540
}
PCREG(4cd540, lifted_4cd540);

extern "C" u32 THISCALL lifted_441420(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_441420
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 76), sizeof v); (u32)v; }) != (u32)(0)) goto L44143d;  // @1_441420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @2_441420
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L44143d;  // @3_441420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @4_441420
  return eax;  // @5_441420
  L44143d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @7_441420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @8_441420
  if ((eax & eax) == 0) goto L44144f;  // @9_441420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @10_441420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @11_441420
  goto L441454;  // @12_441420
  L44144f:;
  eax = (u32)(2097154);  // @14_441420
  L441454:;
  if ((eax & (u32)(1048576)) == 0) goto L441465;  // @16_441420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @17_441420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @18_441420
  if ((eax & eax) != 0) goto L44148e;  // @19_441420
  L441465:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @21_441420
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 96), sizeof v); (u32)v; }) != (u32)(0)) goto L44148b;  // @22_441420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @23_441420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @24_441420
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L441480;  // @25_441420
  if ((eax & eax) != 0) goto L441465;  // @26_441420
  return eax;  // @27_441420
  L441480:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @29_441420
  return eax;  // @30_441420
  L44148b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 96), sizeof v); (u32)v; });  // @32_441420
  L44148e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @34_441420
  return eax;  // @35_441420
}
PCREG(441420, lifted_441420);

extern "C" u32 THISCALL lifted_449310(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_449310
  if ((ecx & ecx) == 0) goto L449372;  // @2_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_449310
  edx = (u32)(EBP - 12);  // @4_449310
  p0_ = edx;  // @5_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_449310
  ecx = edx = 0;  // @7_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @8_449310
  edx = (u32)(EBP - 12);  // @9_449310
  p1_ = edx;  // @10_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @12_449310
  ecx = edx = 0;  // @13_449310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == (u32)(0)) goto L449372;  // @14_449310
  L449340:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_449310
  p2_ = eax;  // @17_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @18_449310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p2_));  // @20_449310
  ecx = edx = 0;  // @21_449310
  if ((eax & eax) == 0) goto L449360;  // @22_449310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @23_449310
  ecx = eax;  // @24_449310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 532)))(ecx);  // @25_449310
  ecx = edx = 0;  // @26_449310
  L449360:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @28_449310
  edx = (u32)(EBP - 12);  // @29_449310
  p3_ = edx;  // @30_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @32_449310
  ecx = edx = 0;  // @33_449310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) != (u32)(0)) goto L449340;  // @34_449310
  L449372:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @36_449310
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(8192));  // @37_449310
  ecx = edx = 0;  // @38_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @39_449310
  eax = (eax & (u32)(4294967294));  // @40_449310
  eax = (eax | (u32)(8));  // @41_449310
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @42_449310
  return eax;  // @43_449310
}
PCREG(449310, lifted_449310);

extern "C" u32 THISCALL lifted_41f400(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_41f400
  ebx = ecx;  // @1_41f400
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @2_41f400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @3_41f400
  eax = (u32)(edi + 32);  // @4_41f400
  p0_ = eax;  // @5_41f400
  eax = ext_41f190_stdcall1((u32)(p0_));  // @6_41f400
  ecx = edx = 0;  // @7_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) == esi) goto L41f43e;  // @8_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_41f400
  ecx = ebx;  // @10_41f400
  p1_ = edi;  // @11_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780060), (u32)(p1_));  // @12_41f400
  ecx = edx = 0;  // @13_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @14_41f400
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @15_41f400
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @16_41f400
  if ((eax & eax) == 0) goto L41f478;  // @17_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_41f400
  ecx = edx = 0;  // @19_41f400
  L41f43e:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @21_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @22_41f400
  eax = (eax & (u32)(536870911));  // @23_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 32), sizeof v); (u32)v; }) == (u32)(2271560481)) goto L41f487;  // @24_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_41f400
  ecx = ebx;  // @26_41f400
  p2_ = edi;  // @27_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780084), (u32)(p2_));  // @28_41f400
  ecx = edx = 0;  // @29_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_41f400
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @31_41f400
  if ((eax & eax) == 0) goto L41f47b;  // @32_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @33_41f400
  ecx = edx = 0;  // @34_41f400
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @35_41f400
  return eax;  // @36_41f400
  L41f478:;
  __builtin_trap();  // @38_41f400
  L41f47b:;
  __builtin_trap();  // @40_41f400
  L41f487:;
  eax = (eax & 0xffffff00u) | (((ecx & 0xff)) & 0xff);  // @42_41f400
  return eax;  // @43_41f400
}
PCREG(41f400, lifted_41f400);

extern "C" u32 THISCALL lifted_4cf2d0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4cf2d0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) >= (s32)(u32)(0)) goto L4cf30d;  // @1_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4cf2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6904700), (u32)(392));  // @4_4cf2d0
  ecx = edx = 0;  // @5_4cf2d0
  p0_ = eax;  // @6_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_4cf2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6904776));  // @8_4cf2d0
  ecx = edx = 0;  // @9_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @10_4cf2d0
  if ((eax & eax) == 0) goto L4cf30c;  // @11_4cf2d0
  eax = ((u32(STDCALL *)(void))(eax))();  // @12_4cf2d0
  ecx = edx = 0;  // @13_4cf2d0
  goto L4cf30d;  // @14_4cf2d0
  L4cf30c:;
  __builtin_trap();  // @16_4cf2d0
  L4cf30d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @19_4cf2d0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; })) goto L4cf326;  // @20_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @21_4cf2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @22_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @23_4cf2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @24_4cf2d0
  L4cf326:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @26_4cf2d0
  if ((ecx & ecx) != 0) goto L4cf333;  // @27_4cf2d0
  eax = 0;  // @28_4cf2d0
  return eax;  // @29_4cf2d0
  L4cf333:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @31_4cf2d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @32_4cf2d0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L4cf353;  // @33_4cf2d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cf353;  // @34_4cf2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @35_4cf2d0
  eax = 0;  // @36_4cf2d0
  return eax;  // @37_4cf2d0
  L4cf353:;
  eax = (u32)(ecx + 16);  // @39_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @40_4cf2d0
  ecx = (ecx + edi);  // @41_4cf2d0
  eax = (u32)(eax + edi*4);  // @42_4cf2d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @43_4cf2d0
  return eax;  // @44_4cf2d0
}
PCREG(4cf2d0, lifted_4cf2d0);

extern "C" u32 THISCALL lifted_4d0590(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d0590
  ebx = ecx;  // @1_4d0590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 460), sizeof v); (u32)v; });  // @2_4d0590
  ecx = (u32)(ebx + 460);  // @3_4d0590
  eax = (u32)(edi + 16);  // @4_4d0590
  p0_ = eax;  // @5_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 12)))(ecx, (u32)(p0_), (u32)(0));  // @6_4d0590
  ecx = edx = 0;  // @7_4d0590
  esi = eax;  // @8_4d0590
  if ((esi & esi) != 0) goto L4d0602;  // @9_4d0590
  ecx = ebx;  // @10_4d0590
  eax = ext_4cfbe0_thiscall1(ecx);  // @11_4d0590
  ecx = edx = 0;  // @12_4d0590
  esi = eax;  // @13_4d0590
  if ((esi & esi) != 0) goto L4d0602;  // @14_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @15_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6905280), (u32)(1074));  // @17_4d0590
  ecx = edx = 0;  // @18_4d0590
  p1_ = edi;  // @19_4d0590
  p2_ = eax;  // @20_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6905496), (u32)(p1_));  // @22_4d0590
  ecx = edx = 0;  // @23_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @24_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4d0590
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 120)))(ecx);  // @26_4d0590
  ecx = edx = 0;  // @27_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @28_4d0590
  if ((eax & eax) == 0) goto L4d05ff;  // @29_4d0590
  eax = ((u32(STDCALL *)(void))(eax))();  // @30_4d0590
  ecx = edx = 0;  // @31_4d0590
  goto L4d060a;  // @32_4d0590
  L4d05ff:;
  __builtin_trap();  // @34_4d0590
  L4d0602:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @36_4d0590
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) >= (s32)edi) goto L4d061f;  // @37_4d0590
  L4d060a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @39_4d0590
  if ((eax & eax) == 0) goto L4d061e;  // @40_4d0590
  eax = ((u32(STDCALL *)(void))(eax))();  // @41_4d0590
  ecx = edx = 0;  // @42_4d0590
  eax = esi;  // @43_4d0590
  return eax;  // @44_4d0590
  L4d061e:;
  __builtin_trap();  // @46_4d0590
  L4d061f:;
  eax = esi;  // @48_4d0590
  return eax;  // @49_4d0590
}
PCREG(4d0590, lifted_4d0590);

extern "C" u32 THISCALL lifted_51c210(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_51c210
  ebx = ecx;  // @1_51c210
  p0_ = edi;  // @2_51c210
  eax = ext_512850_thiscall2(ecx, (u32)(p0_));  // @3_51c210
  ecx = edx = 0;  // @4_51c210
  esi = (u32)(ebx + 1101);  // @5_51c210
  ecx = edi;  // @6_51c210
  p1_ = esi;  // @7_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p1_), (u32)(1));  // @8_51c210
  ecx = edx = 0;  // @9_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c267;  // @10_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(258));  // @13_51c210
  ecx = edx = 0;  // @14_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @15_51c210
  edx = (u32)(6801640);  // @16_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @17_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_51c210
  p2_ = edx;  // @19_51c210
  p3_ = eax;  // @20_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6945012), (u32)(p2_));  // @21_51c210
  ecx = edx = 0;  // @22_51c210
  L51c267:;
  ecx = edi;  // @24_51c210
  eax = ext_4e1600_thiscall1(ecx);  // @25_51c210
  ecx = edx = 0;  // @26_51c210
  if ((eax & 0xff) != (u32)(8)) goto L51c2c6;  // @27_51c210
  esi = (u32)(ebx + 1105);  // @28_51c210
  ecx = edi;  // @29_51c210
  p4_ = esi;  // @30_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p4_), (u32)(1));  // @31_51c210
  ecx = edx = 0;  // @32_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c2d0;  // @33_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(261));  // @36_51c210
  ecx = edx = 0;  // @37_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @38_51c210
  edx = (u32)(6801640);  // @39_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @40_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_51c210
  p5_ = edx;  // @42_51c210
  p6_ = eax;  // @43_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p6_), (u32)(6945036), (u32)(p5_));  // @44_51c210
  ecx = edx = 0;  // @45_51c210
  ecx = edi;  // @46_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @47_51c210
  ecx = edx = 0;  // @48_51c210
  return eax;  // @49_51c210
  L51c2c6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1105), &v, sizeof v); }  // @51_51c210
  L51c2d0:;
  ecx = edi;  // @53_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @54_51c210
  ecx = edx = 0;  // @55_51c210
  return eax;  // @56_51c210
}
PCREG(51c210, lifted_51c210);

extern "C" u32 THISCALL lifted_5c2e10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5c2e10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_5c2e10
  if ((edx & edx) != 0) goto L5c2e26;  // @2_5c2e10
  eax = 0;  // @3_5c2e10
  return eax;  // @4_5c2e10
  L5c2e26:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 708), sizeof v); (u32)v; });  // @6_5c2e10
  edi = 0;  // @7_5c2e10
  if ((s32)(ebx & ebx) <= 0) goto L5c2e7b;  // @8_5c2e10
  esi = (u32)(ecx + 248);  // @9_5c2e10
  L5c2e40:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_5c2e10
  ecx = edx;  // @12_5c2e10
  L5c2e44:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @14_5c2e10
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L5c2e64;  // @15_5c2e10
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L5c2e60;  // @16_5c2e10
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @17_5c2e10
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L5c2e64;  // @18_5c2e10
  ecx = (ecx + (u32)(2));  // @19_5c2e10
  eax = (eax + (u32)(2));  // @20_5c2e10
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L5c2e44;  // @21_5c2e10
  L5c2e60:;
  eax = 0;  // @23_5c2e10
  goto L5c2e69;  // @24_5c2e10
  L5c2e64:;
  eax = 0;  // @26_5c2e10
  eax = (eax | (u32)(1));  // @27_5c2e10
  L5c2e69:;
  if ((eax & eax) == 0) goto L5c2ea7;  // @29_5c2e10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_5c2e10
  edi = (edi + 1);  // @31_5c2e10
  esi = (esi + (u32)(76));  // @32_5c2e10
  if ((s32)edi < (s32)ebx) goto L5c2e40;  // @33_5c2e10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @34_5c2e10
  L5c2e7b:;
  if ((s32)ebx >= (s32)(u32)(6)) goto L5c2eb2;  // @36_5c2e10
  eax = (u32)((s32)ebx * (s32)(u32)(76));  // @37_5c2e10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx + 248), &v, sizeof v); }  // @38_5c2e10
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 708), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 708), &v, sizeof v); }  // @39_5c2e10
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 708), sizeof v); (u32)v; }) * (s32)(u32)(76));  // @40_5c2e10
  eax = (eax + (u32)(172));  // @41_5c2e10
  eax = (eax + ecx);  // @42_5c2e10
  return eax;  // @43_5c2e10
  L5c2ea7:;
  eax = esi;  // @45_5c2e10
  return eax;  // @46_5c2e10
  L5c2eb2:;
  eax = 0;  // @48_5c2e10
  return eax;  // @49_5c2e10
}
PCREG(5c2e10, lifted_5c2e10);

extern "C" u32 THISCALL lifted_536750(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 21250), sizeof v); (u32)v; });  // @0_536750
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_536750
  if ((edx & edx) != 0) goto L536769;  // @2_536750
  L536761:;
  eax = 0;  // @4_536750
  return eax;  // @5_536750
  L536769:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_536750
  if ((eax & eax) == 0) goto L536761;  // @8_536750
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_536750
  edx = (edx + eax);  // @10_536750
  esi = 0;  // @11_536750
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @12_536750
  if ((ebx & ebx) == 0) goto L5367a8;  // @13_536750
  L536781:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 21250), sizeof v); (u32)v; });  // @15_536750
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4), sizeof v); (u32)v; });  // @16_536750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @17_536750
  edi = (edi + eax);  // @18_536750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @19_536750
  ecx = (ecx + eax);  // @20_536750
  eax = ext_4cc850_fastcall2(ecx, edx);  // @21_536750
  ecx = edx = 0;  // @22_536750
  if ((eax & eax) == 0) goto L5367b3;  // @23_536750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @24_536750
  esi = (esi + 1);  // @25_536750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @26_536750
  if (esi < ebx) goto L536781;  // @27_536750
  L5367a8:;
  eax = 0;  // @29_536750
  return eax;  // @30_536750
  L5367b3:;
  eax = edi;  // @32_536750
  return eax;  // @33_536750
}
PCREG(536750, lifted_536750);

extern "C" u32 THISCALL lifted_63e910(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63e910
  ebx = ecx;  // @1_63e910
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @3_63e910
  if ((edx & edx) == 0) goto L63e960;  // @4_63e910
  edi = 0;  // @5_63e910
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; }) == (u32)(0)) goto L63e949;  // @6_63e910
  L63e930:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @8_63e910
  if ((eax & eax) == 0) goto L63e93d;  // @9_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_63e910
  L63e93d:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; });  // @12_63e910
  edi = (edi + 1);  // @13_63e910
  edx = (edx + (u32)(8));  // @14_63e910
  if (edi != eax) goto L63e930;  // @15_63e910
  L63e949:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; });  // @17_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_63e910
  eax = (eax << (u32)(3));  // @19_63e910
  p0_ = eax;  // @20_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 36)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }), (u32)(p0_));  // @21_63e910
  ecx = edx = 0;  // @22_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @23_63e910
  L63e960:;
  ecx = esi;  // @25_63e910
  eax = ext_658d30_thiscall1(ecx);  // @26_63e910
  ecx = edx = 0;  // @27_63e910
  if ((eax & eax) == 0) goto L63e9cb;  // @28_63e910
  p1_ = esi;  // @29_63e910
  ecx = ebx;  // @30_63e910
  eax = ext_63faa0_thiscall2(ecx, (u32)(p1_));  // @31_63e910
  ecx = edx = 0;  // @32_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @33_63e910
  if ((eax & eax) == 0) goto L63e9b2;  // @34_63e910
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @35_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @36_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @37_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_63e910
  p2_ = edx;  // @39_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @40_63e910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @41_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_63e910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 196)))(ecx, (u32)(p2_));  // @43_63e910
  ecx = edx = 0;  // @44_63e910
  ecx = esi;  // @45_63e910
  edi = eax;  // @46_63e910
  eax = ext_658d30_thiscall1(ecx);  // @47_63e910
  ecx = edx = 0;  // @48_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_63e910
  ecx = ebx;  // @50_63e910
  p3_ = edi;  // @51_63e910
  p4_ = eax;  // @52_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 644)))(ecx, (u32)(p4_), (u32)(p3_));  // @53_63e910
  ecx = edx = 0;  // @54_63e910
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @55_63e910
  L63e9b2:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_63e910
  ecx = esi;  // @58_63e910
  eax = ext_658d50_thiscall1(ecx);  // @59_63e910
  ecx = edx = 0;  // @60_63e910
  p5_ = eax;  // @61_63e910
  ecx = ebx;  // @62_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 36)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }), (u32)(p5_));  // @63_63e910
  ecx = edx = 0;  // @64_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @65_63e910
  L63e9cb:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(8)) == 0) goto L63e9ea;  // @67_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @68_63e910
  if ((eax & eax) == 0) goto L63e9ea;  // @69_63e910
  ecx = (u32)(65535);  // @70_63e910
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 62), sizeof v); (u32)v; }) + (ecx & 0xffff))); __builtin_memcpy((void *)(u32)(eax + 62), &v, sizeof v); }  // @71_63e910
  ecx = esi;  // @72_63e910
  eax = ext_658fb0_stdcall1((u32)(0));  // @73_63e910
  ecx = edx = 0;  // @74_63e910
  L63e9ea:;
  return eax;  // @76_63e910
}
PCREG(63e910, lifted_63e910);

extern "C" u32 THISCALL lifted_45fd50(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @1_45fd50
  if ((eax & eax) == 0) goto L45fdc4;  // @2_45fd50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @3_45fd50
  if ((ecx & ecx) == 0) goto L45fdc4;  // @4_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_45fd50
  edx = (u32)(EBP - 12);  // @6_45fd50
  p0_ = edx;  // @7_45fd50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @8_45fd50
  ecx = edx = 0;  // @9_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @10_45fd50
  edx = (u32)(EBP - 12);  // @11_45fd50
  p1_ = edx;  // @12_45fd50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @13_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_45fd50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @15_45fd50
  ecx = edx = 0;  // @16_45fd50
  esi = eax;  // @17_45fd50
  if ((esi & esi) == 0) goto L45fdc3;  // @18_45fd50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_45fd50
  L45fd90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @21_45fd50
  edx = ebx;  // @22_45fd50
  eax = ext_4cc850_fastcall2(ecx, edx);  // @23_45fd50
  ecx = edx = 0;  // @24_45fd50
  if ((eax & eax) == 0) goto L45fdbc;  // @25_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @26_45fd50
  edx = (u32)(EBP - 12);  // @27_45fd50
  p2_ = edx;  // @28_45fd50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @29_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_45fd50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @31_45fd50
  ecx = edx = 0;  // @32_45fd50
  esi = eax;  // @33_45fd50
  if ((esi & esi) != 0) goto L45fd90;  // @34_45fd50
  return eax;  // @35_45fd50
  L45fdbc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @37_45fd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @38_45fd50
  L45fdc3:;
  L45fdc4:;
  return eax;  // @41_45fd50
}
PCREG(45fd50, lifted_45fd50);

extern "C" u32 STDCALL lifted_565190(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_565190
  if ((edx & edx) == 0) goto L56522f;  // @1_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_565190
  p0_ = edx;  // @3_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @5_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_565190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973980), (u32)(p0_));  // @7_565190
  ecx = edx = 0;  // @8_565190
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @9_565190
  esi = eax;  // @10_565190
  if ((edi & edi) == 0) goto L5651ea;  // @11_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_565190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @14_565190
  ecx = edx = 0;  // @15_565190
  p1_ = esi;  // @16_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_565190
  p2_ = eax;  // @18_565190
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))((u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p1_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @19_565190
  ecx = edx = 0;  // @20_565190
  return eax;  // @21_565190
  L5651ea:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @23_565190
  if ((edi & edi) == 0) goto L565216;  // @24_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_565190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @27_565190
  ecx = edx = 0;  // @28_565190
  p3_ = edi;  // @29_565190
  p4_ = esi;  // @30_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_565190
  p5_ = eax;  // @32_565190
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))((u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p4_), (u32)(p3_));  // @33_565190
  ecx = edx = 0;  // @34_565190
  return eax;  // @35_565190
  L565216:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @37_565190
  ecx = (ecx - esi);  // @38_565190
  L565220:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @40_565190
  esi = (u32)(esi + 1);  // @41_565190
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @42_565190
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L565220;  // @43_565190
  L56522f:;
  return eax;  // @45_565190
}
PCREG(565190, lifted_565190);

extern "C" u32 THISCALL lifted_4c35e0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4c35e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @1_4c35e0
  if ((ecx & ecx) == 0) goto L4c3678;  // @2_4c35e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4c35e0
  edx = (u32)(EBP - 12);  // @4_4c35e0
  p0_ = edx;  // @5_4c35e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_4c35e0
  ecx = edx = 0;  // @7_4c35e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @8_4c35e0
  edx = (u32)(EBP - 12);  // @9_4c35e0
  p1_ = edx;  // @10_4c35e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4c35e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @12_4c35e0
  ecx = edx = 0;  // @13_4c35e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == (u32)(0)) goto L4c3678;  // @14_4c35e0
  L4c3611:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_4c35e0
  p2_ = eax;  // @17_4c35e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @18_4c35e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4c35e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p2_));  // @20_4c35e0
  ecx = edx = 0;  // @21_4c35e0
  ebx = eax;  // @22_4c35e0
  if ((ebx & ebx) != 0) goto L4c3637;  // @23_4c35e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @24_4c35e0
  edx = (u32)(EBP - 12);  // @25_4c35e0
  p3_ = edx;  // @26_4c35e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4c35e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p3_));  // @28_4c35e0
  ecx = edx = 0;  // @29_4c35e0
  goto L4c3664;  // @30_4c35e0
  L4c3637:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_4c35e0
  ecx = ebx;  // @33_4c35e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 268)))(ecx, (u32)(6897168), (u32)(100));  // @34_4c35e0
  ecx = edx = 0;  // @35_4c35e0
  esi = eax;  // @36_4c35e0
  p4_ = ebx;  // @37_4c35e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_4c35e0
  ecx = esi;  // @39_4c35e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(1), (u32)(p4_), (u32)(0));  // @40_4c35e0
  ecx = edx = 0;  // @41_4c35e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_4c35e0
  ecx = esi;  // @43_4c35e0
  p5_ = edi;  // @44_4c35e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }), (u32)(p5_));  // @45_4c35e0
  ecx = edx = 0;  // @46_4c35e0
  L4c3664:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @48_4c35e0
  edx = (u32)(EBP - 12);  // @49_4c35e0
  p6_ = edx;  // @50_4c35e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_4c35e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p6_));  // @52_4c35e0
  ecx = edx = 0;  // @53_4c35e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) != (u32)(0)) goto L4c3611;  // @54_4c35e0
  L4c3678:;
  return eax;  // @56_4c35e0
}
PCREG(4c35e0, lifted_4c35e0);

extern "C" u32 THISCALL lifted_4a02e0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4a02e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 94), sizeof v); (u32)v; }) == (u32)(0)) goto L4a03a3;  // @1_4a02e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4a02e0
  ecx = edi;  // @3_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @5_4a02e0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097191));  // @6_4a02e0
  ecx = edx = 0;  // @7_4a02e0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4a03a2;  // @8_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_4a02e0
  p0_ = edi;  // @10_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @11_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4a02e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @13_4a02e0
  ecx = edx = 0;  // @14_4a02e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @15_4a02e0
  ecx = 0;  // @16_4a02e0
  if ((esi & esi) == 0) goto L4a0343;  // @17_4a02e0
  edx = (u32)(ebx + 110);  // @18_4a02e0
  L4a0330:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == eax) goto L4a033e;  // @20_4a02e0
  ecx = (ecx + 1);  // @21_4a02e0
  edx = (edx + (u32)(4));  // @22_4a02e0
  if (ecx != esi) goto L4a0330;  // @23_4a02e0
  goto L4a0343;  // @24_4a02e0
  L4a033e:;
  if (ecx != (u32)(-1)) goto L4a03a1;  // @26_4a02e0
  L4a0343:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4a02e0
  p1_ = edi;  // @29_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4a02e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @32_4a02e0
  ecx = edx = 0;  // @33_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @34_4a02e0
  esi = eax;  // @35_4a02e0
  ecx = (ecx + 1);  // @36_4a02e0
  if (ecx <= (u32)(2)) goto L4a036e;  // @37_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @38_4a02e0
  if ((ecx & ecx) == 0) goto L4a036d;  // @39_4a02e0
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @40_4a02e0
  ecx = edx = 0;  // @41_4a02e0
  goto L4a036e;  // @42_4a02e0
  L4a036d:;
  __builtin_trap();  // @44_4a02e0
  L4a036e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @46_4a02e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 110), &v, sizeof v); }  // @47_4a02e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 106), &v, sizeof v); }  // @48_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_4a02e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @50_4a02e0
  p2_ = edx;  // @51_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_4a02e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @53_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4a02e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @55_4a02e0
  ecx = edx = 0;  // @56_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @57_4a02e0
  p3_ = eax;  // @58_4a02e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7340736), sizeof v); (u32)v; });  // @59_4a02e0
  p4_ = eax;  // @60_4a02e0
  p5_ = edi;  // @61_4a02e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, (u32)(p5_), (u32)(p4_), (u32)(p3_));  // @62_4a02e0
  ecx = edx = 0;  // @63_4a02e0
  L4a03a1:;
  L4a03a2:;
  L4a03a3:;
  return eax;  // @67_4a02e0
}
PCREG(4a02e0, lifted_4a02e0);

extern "C" u32 THISCALL lifted_53b1b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_53b1b0
  if ((ecx & ecx) == 0) goto L53b294;  // @2_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_53b1b0
  edx = (u32)(EBP - 12);  // @4_53b1b0
  p0_ = edx;  // @5_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_53b1b0
  ecx = edx = 0;  // @7_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @8_53b1b0
  edx = (u32)(EBP - 12);  // @9_53b1b0
  p1_ = edx;  // @10_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @12_53b1b0
  ecx = edx = 0;  // @13_53b1b0
  if ((eax & eax) == 0) goto L53b294;  // @14_53b1b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_53b1b0
  L53b1e5:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) == edi) goto L53b202;  // @17_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @18_53b1b0
  edx = (u32)(EBP - 12);  // @19_53b1b0
  p2_ = edx;  // @20_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @22_53b1b0
  ecx = edx = 0;  // @23_53b1b0
  if ((eax & eax) != 0) goto L53b1e5;  // @24_53b1b0
  return eax;  // @25_53b1b0
  L53b202:;
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; })) goto L53b21a;  // @27_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @28_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 14), &v, sizeof v); }  // @29_53b1b0
  if ((ecx & ecx) == 0) goto L53b239;  // @30_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @31_53b1b0
  goto L53b239;  // @32_53b1b0
  L53b21a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @34_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @35_53b1b0
  if ((edx & edx) != 0) goto L53b22d;  // @36_53b1b0
  if ((ecx & ecx) == 0) goto L53b239;  // @37_53b1b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @38_53b1b0
  goto L53b239;  // @39_53b1b0
  L53b22d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @41_53b1b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @42_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @43_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @44_53b1b0
  L53b239:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; }) != eax) goto L53b24e;  // @46_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @47_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @48_53b1b0
  if ((ecx & ecx) != 0) goto L53b24e;  // @49_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; });  // @50_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @51_53b1b0
  L53b24e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 22), sizeof v); (u32)v; }) != eax) goto L53b26f;  // @53_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @54_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @55_53b1b0
  if ((ecx & ecx) != 0) goto L53b263;  // @56_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; });  // @57_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @58_53b1b0
  L53b263:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 22), sizeof v); (u32)v; }) != eax) goto L53b26f;  // @60_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @61_53b1b0
  L53b26f:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; }) != eax) goto L53b27b;  // @63_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @64_53b1b0
  L53b27b:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; }) != eax) goto L53b287;  // @66_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 14), &v, sizeof v); }  // @67_53b1b0
  L53b287:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @69_53b1b0
  edx = (u32)(EBP - 12);  // @70_53b1b0
  p3_ = edx;  // @71_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p3_));  // @73_53b1b0
  ecx = edx = 0;  // @74_53b1b0
  L53b294:;
  return eax;  // @76_53b1b0
}
PCREG(53b1b0, lifted_53b1b0);

extern "C" u32 THISCALL lifted_54da90(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edx = ecx;  // @0_54da90
  ecx = 0;  // @1_54da90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32861), sizeof v); (u32)v; });  // @2_54da90
  edi = 0;  // @3_54da90
  ebx = 0;  // @4_54da90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_54da90
  esi = 0;  // @6_54da90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @7_54da90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 32805), &v, sizeof v); }  // @8_54da90
  if ((s32)(eax & eax) <= 0) goto L54db38;  // @9_54da90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32829), sizeof v); (u32)v; });  // @10_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32861), sizeof v); (u32)v; });  // @11_54da90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @12_54da90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @13_54da90
  L54dad0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_54da90
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 125), sizeof v); (u32)v; }) == (u32)(0)) goto L54db1f;  // @16_54da90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32805), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 32805), &v, sizeof v); }  // @17_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 93), sizeof v); (u32)v; });  // @18_54da90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @19_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @20_54da90
  ecx = (ecx + 1);  // @21_54da90
  if ((s32)(edx & edx) >= 0) ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @22_54da90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @23_54da90
  if ((s32)(edx & edx) >= 0) goto L54db09;  // @24_54da90
  if ((edi & edi) == 0) goto L54daff;  // @25_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 53), sizeof v); (u32)v; });  // @26_54da90
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 53), sizeof v); (u32)v; })) goto L54db17;  // @27_54da90
  L54daff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @29_54da90
  edi = eax;  // @30_54da90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @31_54da90
  goto L54db24;  // @32_54da90
  L54db09:;
  if ((ebx & ebx) == 0) goto L54db15;  // @34_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 53), sizeof v); (u32)v; });  // @35_54da90
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 53), sizeof v); (u32)v; })) goto L54db17;  // @36_54da90
  L54db15:;
  ebx = eax;  // @38_54da90
  L54db17:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @40_54da90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @41_54da90
  goto L54db24;  // @42_54da90
  L54db1f:;
  if ((esi & esi) == 0) esi = eax;  // @44_54da90
  L54db24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @46_54da90
  eax = (eax + (u32)(4));  // @47_54da90
  ecx = (ecx - (u32)(1));  // @48_54da90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @49_54da90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @50_54da90
  if (ecx != 0) goto L54dad0;  // @51_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @52_54da90
  L54db38:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @54_54da90
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) >= (s32)(u32)(0)) goto L54db59;  // @55_54da90
  if (ecx != (u32)(4)) goto L54db59;  // @56_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @57_54da90
  if (ecx <= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 53), sizeof v); (u32)v; })) goto L54db71;  // @58_54da90
  eax = edi;  // @59_54da90
  return eax;  // @60_54da90
  L54db59:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32861), sizeof v); (u32)v; });  // @62_54da90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32805), sizeof v); (u32)v; }) != eax) goto L54db71;  // @63_54da90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @64_54da90
  eax = ebx;  // @65_54da90
  if (ecx > ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 53), sizeof v); (u32)v; })) goto L54db73;  // @66_54da90
  L54db71:;
  eax = esi;  // @68_54da90
  L54db73:;
  return eax;  // @70_54da90
}
PCREG(54da90, lifted_54da90);

extern "C" u32 THISCALL lifted_4a01c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ecx;  // @0_4a01c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 94), sizeof v); (u32)v; }) == (u32)(0)) goto L4a02d0;  // @1_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_4a01c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4a01c0
  p0_ = ebx;  // @5_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @7_4a01c0
  ecx = edx = 0;  // @8_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @9_4a01c0
  ecx = 0;  // @10_4a01c0
  if ((esi & esi) == 0) goto L4a02ce;  // @11_4a01c0
  edx = (u32)(edi + 110);  // @12_4a01c0
  L4a01f7:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == eax) goto L4a020c;  // @14_4a01c0
  ecx = (ecx + 1);  // @15_4a01c0
  edx = (edx + (u32)(4));  // @16_4a01c0
  if (ecx != esi) goto L4a01f7;  // @17_4a01c0
  return eax;  // @18_4a01c0
  L4a020c:;
  if (ecx == (u32)(-1)) goto L4a02ce;  // @20_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4a01c0
  p1_ = ebx;  // @22_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @25_4a01c0
  ecx = edx = 0;  // @26_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @27_4a01c0
  ecx = 0;  // @28_4a01c0
  ebx = eax;  // @29_4a01c0
  if ((esi & esi) == 0) goto L4a0255;  // @30_4a01c0
  edx = (u32)(edi + 110);  // @31_4a01c0
  L4a0234:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == ebx) goto L4a0242;  // @33_4a01c0
  ecx = (ecx + 1);  // @34_4a01c0
  edx = (edx + (u32)(4));  // @35_4a01c0
  if (ecx != esi) goto L4a0234;  // @36_4a01c0
  goto L4a0255;  // @37_4a01c0
  L4a0242:;
  if (ecx == (u32)(-1)) goto L4a0255;  // @39_4a01c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 106), &v, sizeof v); }  // @40_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @41_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 110), sizeof v); (u32)v; });  // @42_4a01c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx*4 + 110), &v, sizeof v); }  // @43_4a01c0
  L4a0255:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4a01c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @48_4a01c0
  ecx = edx = 0;  // @49_4a01c0
  ecx = (u32)(EBP - 4);  // @50_4a01c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @51_4a01c0
  p2_ = ecx;  // @52_4a01c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @53_4a01c0
  ecx = eax;  // @54_4a01c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(p2_));  // @55_4a01c0
  ecx = edx = 0;  // @56_4a01c0
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })) goto L4a02a3;  // @57_4a01c0
  ecx = 0;  // @58_4a01c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 126), sizeof v); (u32)v; }) == ecx) goto L4a02a3;  // @59_4a01c0
  edx = (u32)(edi + 130);  // @60_4a01c0
  L4a0294:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @62_4a01c0
  edx = (u32)(edx + 4);  // @63_4a01c0
  ecx = (ecx + 1);  // @64_4a01c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; }) | (u32)(2))); __builtin_memcpy((void *)(u32)(eax + 90), &v, sizeof v); }  // @65_4a01c0
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 126), sizeof v); (u32)v; })) goto L4a0294;  // @66_4a01c0
  L4a02a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_4a01c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @69_4a01c0
  p3_ = edx;  // @70_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @72_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p3_));  // @74_4a01c0
  ecx = edx = 0;  // @75_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @76_4a01c0
  p4_ = eax;  // @77_4a01c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7340740), sizeof v); (u32)v; });  // @78_4a01c0
  p5_ = eax;  // @79_4a01c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p5_), (u32)(p4_));  // @80_4a01c0
  ecx = edx = 0;  // @81_4a01c0
  L4a02ce:;
  L4a02d0:;
  return eax;  // @84_4a01c0
}
PCREG(4a01c0, lifted_4a01c0);

extern "C" u32 THISCALL lifted_648c10(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 98946), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ecx + 98946), &v, sizeof v); }  // @0_648c10
  edx = (u32)(ecx + 98941);  // @1_648c10
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @2_648c10
  eax = (u32)(ecx + 98905);  // @3_648c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 98961), &v, sizeof v); }  // @4_648c10
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; })) & 0xffff);  // @5_648c10
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 98959), &v, sizeof v); }  // @6_648c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @7_648c10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + eax*8 + 44), &v, sizeof v); }  // @8_648c10
  { u32 v = (u32)((u32)(134643721)); __builtin_memcpy((void *)(u32)(ecx + eax*8 + 40), &v, sizeof v); }  // @9_648c10
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @10_648c10
  return eax;  // @11_648c10
}
PCREG(648c10, lifted_648c10);

extern "C" u32 THISCALL lifted_54f250(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @0_54f250
  if ((esi & esi) == 0) goto L54f2a0;  // @1_54f250
  eax = (u32)(ecx + 8);  // @2_54f250
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(ecx + 76), &v, sizeof v); }  // @3_54f250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_54f250
  p0_ = eax;  // @5_54f250
  p1_ = esi;  // @6_54f250
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(p1_), (u32)(7069552), (u32)(2147483649), (u32)(0), (u32)(0), (u32)(p0_), (u32)(72));  // @7_54f250
  ecx = edx = 0;  // @8_54f250
  if ((s32)(eax & eax) >= 0) goto L54f2a0;  // @9_54f250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_54f250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_54f250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6963560), (u32)(372));  // @12_54f250
  ecx = edx = 0;  // @13_54f250
  p2_ = eax;  // @14_54f250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_54f250
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p2_), (u32)(6963936));  // @16_54f250
  ecx = edx = 0;  // @17_54f250
  L54f2a0:;
  return eax;  // @19_54f250
}
PCREG(54f250, lifted_54f250);

extern "C" u32 THISCALL lifted_64ab50(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_64ab50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @1_64ab50
  if ((esi & esi) == 0) goto L64aba1;  // @2_64ab50
  L64ab60:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @4_64ab50
  p0_ = esi;  // @5_64ab50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_64ab50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @7_64ab50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p0_));  // @8_64ab50
  ecx = edx = 0;  // @9_64ab50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_64ab50
  ebx = (ebx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @11_64ab50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_64ab50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(7068248), (u32)(356));  // @13_64ab50
  ecx = edx = 0;  // @14_64ab50
  ecx = (ebx & 0xff);  // @15_64ab50
  p1_ = ecx;  // @16_64ab50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_64ab50
  p2_ = eax;  // @18_64ab50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(p2_), (u32)(7068328), (u32)(p1_));  // @19_64ab50
  ecx = edx = 0;  // @20_64ab50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @21_64ab50
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L64aba0;  // @22_64ab50
  if ((esi & esi) != 0) goto L64ab60;  // @23_64ab50
  L64aba0:;
  L64aba1:;
  return eax;  // @26_64ab50
}
PCREG(64ab50, lifted_64ab50);

extern "C" u32 THISCALL lifted_648350(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_648350
  ebx = (u32)(65535);  // @1_648350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @2_648350
  if ((ecx & ecx) == 0) goto L648378;  // @3_648350
  L648361:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @5_648350
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) != (ebx & 0xffff)) goto L648389;  // @6_648350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_648350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_648350
  if (ecx == eax) goto L648378;  // @9_648350
  if ((eax & eax) != 0) goto L648361;  // @10_648350
  L648378:;
  ecx = esi;  // @12_648350
  eax = ext_648dd0_thiscall1(ecx);  // @13_648350
  ecx = edx = 0;  // @14_648350
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L64839f;  // @15_648350
  eax = 0;  // @16_648350
  return eax;  // @17_648350
  L648389:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @19_648350
  edi = eax;  // @20_648350
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @21_648350
  if ((eax & 0xffff) != (ebx & 0xffff)) goto L6483b6;  // @22_648350
  esi = 0;  // @23_648350
  eax = esi;  // @24_648350
  return eax;  // @25_648350
  L64839f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @27_648350
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @28_648350
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @29_648350
  if ((eax & 0xffff) != (ebx & 0xffff)) goto L6483b6;  // @30_648350
  esi = 0;  // @31_648350
  eax = esi;  // @32_648350
  return eax;  // @33_648350
  L6483b6:;
  eax = (u32)(eax + eax*8);  // @35_648350
  eax = (u32)(eax + 4);  // @36_648350
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; })) & 0xffff);  // @37_648350
  esi = (u32)(edi + eax*4);  // @38_648350
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 2), &v, sizeof v); }  // @39_648350
  ecx = esi;  // @40_648350
  eax = ext_647f70_thiscall1(ecx);  // @41_648350
  ecx = edx = 0;  // @42_648350
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_648350
  eax = esi;  // @44_648350
  return eax;  // @45_648350
}
PCREG(648350, lifted_648350);

extern "C" u32 THISCALL lifted_663b60(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_663b60
  edi = ecx;  // @1_663b60
  if ((s32)esi >= (s32)(u32)(64)) goto L663bbb;  // @2_663b60
  eax = esi;  // @3_663b60
  eax = (eax << (u32)(10));  // @4_663b60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_663b60
  eax = (eax + (u32)(8448));  // @6_663b60
  eax = (eax + edi);  // @7_663b60
  ecx = ebx;  // @8_663b60
  p0_ = eax;  // @9_663b60
  eax = ext_5ae5a0_thiscall3(ecx, (u32)(p0_), (u32)(0));  // @10_663b60
  ecx = edx = 0;  // @11_663b60
  ecx = ebx;  // @12_663b60
  eax = ext_5adea0_thiscall1(ecx);  // @13_663b60
  ecx = edx = 0;  // @14_663b60
  edx = esi;  // @15_663b60
  edx = (edx << (u32)(7));  // @16_663b60
  edx = (edx + edi);  // @17_663b60
  edx = (edx - eax);  // @18_663b60
  L663ba0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @20_663b60
  eax = (u32)(eax + 1);  // @21_663b60
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @22_663b60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663ba0;  // @23_663b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 134), sizeof v); (u32)v; });  // @24_663b60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 8192), &v, sizeof v); }  // @25_663b60
  L663bbb:;
  return eax;  // @27_663b60
}
PCREG(663b60, lifted_663b60);

extern "C" u32 THISCALL lifted_5476e0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5476e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5476e0
  if ((s32)edi <= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; })) goto L547727;  // @2_5476e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @3_5476e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5476e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6958624), (u32)(3329));  // @5_5476e0
  ecx = edx = 0;  // @6_5476e0
  p0_ = eax;  // @7_5476e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_5476e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6959096));  // @9_5476e0
  ecx = edx = 0;  // @10_5476e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @11_5476e0
  if ((eax & eax) == 0) goto L547726;  // @12_5476e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @13_5476e0
  ecx = edx = 0;  // @14_5476e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @15_5476e0
  return eax;  // @16_5476e0
  L547726:;
  __builtin_trap();  // @18_5476e0
  L547727:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @20_5476e0
  return eax;  // @21_5476e0
}
PCREG(5476e0, lifted_5476e0);

extern "C" u32 THISCALL lifted_6074f0(u32 ecx_in) {
  SEH_ENTER(0x66dfe1);  // @h_6074f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_6074f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6074f0
  esi = (u32)(edi + 20);  // @2_6074f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @3_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @4_6074f0
  ecx = esi;  // @5_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @6_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @8_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @9_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @10_6074f0
  ecx = edx = 0;  // @11_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @13_6074f0
  ecx = (u32)(eax + 8);  // @14_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @15_6074f0
  if ((eax & eax) == 0) goto L60755f;  // @16_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @17_6074f0
  L60755f:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @19_6074f0
  esi = (u32)(edi + 32);  // @20_6074f0
  reg.state = (s32)((u32)(0));  // @21_6074f0
  ecx = esi;  // @22_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @23_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @24_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @25_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @26_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @27_6074f0
  ecx = edx = 0;  // @28_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @29_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @30_6074f0
  ecx = (u32)(eax + 8);  // @31_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @32_6074f0
  if ((eax & eax) == 0) goto L60759e;  // @33_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_6074f0
  L60759e:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @36_6074f0
  esi = (u32)(edi + 44);  // @37_6074f0
  reg.state = (s32)((u32)(1));  // @38_6074f0
  ecx = esi;  // @39_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @40_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @41_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @42_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @43_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @44_6074f0
  ecx = edx = 0;  // @45_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @46_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @47_6074f0
  ecx = (u32)(eax + 8);  // @48_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @49_6074f0
  if ((eax & eax) == 0) goto L6075da;  // @50_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @51_6074f0
  L6075da:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @53_6074f0
  esi = (u32)(edi + 56);  // @54_6074f0
  reg.state = (s32)((u32)(2));  // @55_6074f0
  ecx = esi;  // @56_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @57_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @58_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @59_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @60_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @61_6074f0
  ecx = edx = 0;  // @62_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @63_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @64_6074f0
  ecx = (u32)(eax + 8);  // @65_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @66_6074f0
  if ((eax & eax) == 0) goto L607616;  // @67_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @68_6074f0
  L607616:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @70_6074f0
  eax = edi;  // @71_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @72_6074f0
  SEH_LEAVE();  // @73_6074f0
  return eax;  // @74_6074f0
}
PCREG(6074f0, lifted_6074f0);

extern "C" u32 THISCALL lifted_4b8fd0(u32 ecx_in) {
  SEH_ENTER(0x668c56);  // @h_4b8fd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4b8fd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4b8fd0
  eax = ext_469870_thiscall1(ecx);  // @2_4b8fd0
  ecx = edx = 0;  // @3_4b8fd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b8fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4b8fd0
  { u32 v = (u32)((u32)(6892080)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_4b8fd0
  reg.state = (s32)((u32)(0));  // @9_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6827544), (u32)(0), (u32)(6892212), (u32)(36));  // @11_4b8fd0
  ecx = edx = 0;  // @12_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 149), &v, sizeof v); }  // @13_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6858876), (u32)(0), (u32)(6892212), (u32)(37));  // @17_4b8fd0
  ecx = edx = 0;  // @18_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 151), &v, sizeof v); }  // @19_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892260), (u32)(0), (u32)(6892212), (u32)(38));  // @23_4b8fd0
  ecx = edx = 0;  // @24_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 153), &v, sizeof v); }  // @25_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @27_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892276), (u32)(0), (u32)(6892212), (u32)(39));  // @29_4b8fd0
  ecx = edx = 0;  // @30_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @31_4b8fd0
  eax = ext_41e290_cdecl1((u32)(109));  // @32_4b8fd0
  ecx = edx = 0;  // @33_4b8fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @34_4b8fd0
  reg.state = (s32)((u32)(1));  // @35_4b8fd0
  if ((eax & eax) == 0) goto L4b90d6;  // @36_4b8fd0
  ecx = eax;  // @37_4b8fd0
  eax = ext_4e1b60_thiscall1(ecx);  // @38_4b8fd0
  ecx = edx = 0;  // @39_4b8fd0
  goto L4b90d8;  // @40_4b8fd0
  L4b90d6:;
  eax = 0;  // @42_4b8fd0
  L4b90d8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @44_4b8fd0
  reg.state = (s32)((u32)(0));  // @45_4b8fd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 108), &v, sizeof v); }  // @46_4b8fd0
  eax = ext_41e290_cdecl1((u32)(44));  // @47_4b8fd0
  ecx = edx = 0;  // @48_4b8fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @49_4b8fd0
  reg.state = (s32)((u32)(2));  // @50_4b8fd0
  if ((eax & eax) == 0) goto L4b9104;  // @51_4b8fd0
  ecx = eax;  // @52_4b8fd0
  eax = ext_4e7160_thiscall1(ecx);  // @53_4b8fd0
  ecx = edx = 0;  // @54_4b8fd0
  goto L4b9106;  // @55_4b8fd0
  L4b9104:;
  eax = 0;  // @57_4b8fd0
  L4b9106:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @59_4b8fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }  // @60_4b8fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @61_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_4b8fd0
  reg.state = (s32)((u32)(0));  // @64_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892288), (u32)(0), (u32)(6892212), (u32)(49));  // @66_4b8fd0
  ecx = edx = 0;  // @67_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 157), &v, sizeof v); }  // @68_4b8fd0
  eax = esi;  // @69_4b8fd0
  SEH_LEAVE();  // @70_4b8fd0
  return eax;  // @71_4b8fd0
}
PCREG(4b8fd0, lifted_4b8fd0);

extern "C" u32 THISCALL lifted_4f9680(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4f9680
  eax = ext_4f9600_thiscall1(ecx);  // @1_4f9680
  ecx = edx = 0;  // @2_4f9680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4f9680
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }) == (u32)(0)) goto L4f9710;  // @4_4f9680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_4f9680
  edi = (u32)(esi + eax*4);  // @6_4f9680
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4), sizeof v); (u32)v; }) != (u32)(0)) goto L4f96b4;  // @7_4f9680
  ecx = esi;  // @8_4f9680
  eax = ext_4f9600_thiscall1(ecx);  // @9_4f9680
  ecx = edx = 0;  // @10_4f9680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4f9680
  L4f96b4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @13_4f9680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4f9680
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 288)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }), (u32)(4));  // @15_4f9680
  ecx = edx = 0;  // @16_4f9680
  ebx = eax;  // @17_4f9680
  if ((ebx & ebx) == 0) goto L4f96eb;  // @18_4f9680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_4f9680
  p0_ = ebx;  // @20_4f9680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_4f9680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4f9680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(p0_));  // @23_4f9680
  ecx = edx = 0;  // @24_4f9680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(eax + 64), &v, sizeof v); }  // @25_4f9680
  eax = ebx;  // @26_4f9680
  return eax;  // @27_4f9680
  L4f96eb:;
  ecx = esi;  // @29_4f9680
  eax = ext_4f9600_thiscall1(ecx);  // @30_4f9680
  ecx = edx = 0;  // @31_4f9680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4f9680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @33_4f9680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4f9680
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 288)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }), (u32)(4));  // @35_4f9680
  ecx = edx = 0;  // @36_4f9680
  return eax;  // @37_4f9680
  L4f9710:;
  eax = 0;  // @39_4f9680
  return eax;  // @40_4f9680
}
PCREG(4f9680, lifted_4f9680);

extern "C" u32 THISCALL lifted_5c2940(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5c2940
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L5c29eb;  // @1_5c2940
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 603), &v, sizeof v); }  // @2_5c2940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_5c2940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_5c2940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5c2940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968132), (u32)(0), (u32)(7027932), (u32)(94));  // @6_5c2940
  ecx = edx = 0;  // @7_5c2940
  eax = (eax & 0xffff);  // @8_5c2940
  ecx = edi;  // @9_5c2940
  p0_ = eax;  // @10_5c2940
  eax = ext_5c27f0_thiscall2(ecx, (u32)(p0_));  // @11_5c2940
  ecx = edx = 0;  // @12_5c2940
  esi = (u32)(edi + 84);  // @13_5c2940
  if ((esi & esi) == 0) goto L5c29ea;  // @14_5c2940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_5c2940
  ecx = (u32)(EBP - 12);  // @16_5c2940
  p1_ = ecx;  // @17_5c2940
  ecx = esi;  // @18_5c2940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @19_5c2940
  ecx = edx = 0;  // @20_5c2940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_5c2940
  ecx = (u32)(EBP - 12);  // @22_5c2940
  p2_ = ecx;  // @23_5c2940
  ecx = esi;  // @24_5c2940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @25_5c2940
  ecx = edx = 0;  // @26_5c2940
  edx = eax;  // @27_5c2940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5c29ea;  // @28_5c2940
  L5c29b0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_5c2940
  p3_ = edx;  // @31_5c2940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @32_5c2940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_5c2940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p3_));  // @34_5c2940
  ecx = edx = 0;  // @35_5c2940
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 428), sizeof v); (u32)v; });  // @36_5c2940
  p4_ = edi;  // @37_5c2940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_5c2940
  p5_ = ecx;  // @39_5c2940
  ecx = eax;  // @40_5c2940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(p5_), (u32)(p4_), (u32)(0));  // @41_5c2940
  ecx = edx = 0;  // @42_5c2940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_5c2940
  ecx = (u32)(EBP - 12);  // @44_5c2940
  p6_ = ecx;  // @45_5c2940
  ecx = esi;  // @46_5c2940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p6_));  // @47_5c2940
  ecx = edx = 0;  // @48_5c2940
  edx = eax;  // @49_5c2940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) != (u32)(0)) goto L5c29b0;  // @50_5c2940
  L5c29ea:;
  L5c29eb:;
  return eax;  // @53_5c2940
}
PCREG(5c2940, lifted_5c2940);

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

extern "C" u32 THISCALL lifted_6449c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e98f);  // @h_6449c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_6449c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6449c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6449c0
  ebx = (u32)(edi + 33);  // @3_6449c0
  p0_ = ebx;  // @4_6449c0
  ecx = esi;  // @5_6449c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_6449c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(p0_));  // @7_6449c0
  ecx = edx = 0;  // @8_6449c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @9_6449c0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) <= (s32)(u32)(0)) goto L644aab;  // @10_6449c0
  eax = 0;  // @11_6449c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @12_6449c0
  L644a10:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 37), sizeof v); (u32)v; });  // @14_6449c0
  ecx = esi;  // @15_6449c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_6449c0
  ebx = (ebx + eax);  // @17_6449c0
  eax = (u32)(ebx + 58);  // @18_6449c0
  p1_ = eax;  // @19_6449c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p1_));  // @20_6449c0
  ecx = edx = 0;  // @21_6449c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_6449c0
  eax = (u32)(ebx + 8);  // @23_6449c0
  p2_ = eax;  // @24_6449c0
  ecx = esi;  // @25_6449c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p2_));  // @26_6449c0
  ecx = edx = 0;  // @27_6449c0
  eax = ext_41e290_cdecl1((u32)(101));  // @28_6449c0
  ecx = edx = 0;  // @29_6449c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @30_6449c0
  reg.state = (s32)((u32)(0));  // @31_6449c0
  if ((eax & eax) == 0) goto L644a4c;  // @32_6449c0
  ecx = eax;  // @33_6449c0
  eax = ext_540ed0_thiscall1(ecx);  // @34_6449c0
  ecx = edx = 0;  // @35_6449c0
  goto L644a4e;  // @36_6449c0
  L644a4c:;
  eax = 0;  // @38_6449c0
  L644a4e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 383), &v, sizeof v); }  // @40_6449c0
  edi = (u32)(ebx + 21);  // @41_6449c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_6449c0
  ecx = esi;  // @43_6449c0
  p3_ = edi;  // @44_6449c0
  reg.state = (s32)((u32)(4294967295));  // @45_6449c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p3_));  // @46_6449c0
  ecx = edx = 0;  // @47_6449c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_6449c0
  ecx = (u32)(ebx + 62);  // @49_6449c0
  p4_ = ecx;  // @50_6449c0
  ecx = esi;  // @51_6449c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p4_));  // @52_6449c0
  ecx = edx = 0;  // @53_6449c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) == (u32)(0)) goto L644a88;  // @54_6449c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 62), sizeof v); (u32)v; }) == (u32)(0)) goto L644a88;  // @55_6449c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 383), sizeof v); (u32)v; });  // @56_6449c0
  p5_ = esi;  // @57_6449c0
  eax = ext_545ee0_thiscall2(ecx, (u32)(p5_));  // @58_6449c0
  ecx = edx = 0;  // @59_6449c0
  L644a88:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @61_6449c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @62_6449c0
  ebx = (ebx + (u32)(33));  // @63_6449c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @64_6449c0
  edi = (edi + 1);  // @65_6449c0
  eax = (eax + (u32)(479));  // @66_6449c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @67_6449c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @68_6449c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @69_6449c0
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) goto L644a10;  // @70_6449c0
  L644aab:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41), sizeof v); (u32)v; });  // @72_6449c0
  p6_ = esi;  // @73_6449c0
  eax = ext_644900_thiscall2(ecx, (u32)(p6_));  // @74_6449c0
  ecx = edx = 0;  // @75_6449c0
  edi = 0;  // @76_6449c0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) <= (s32)edi) goto L644ad6;  // @77_6449c0
  L644ac0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @79_6449c0
  ecx = esi;  // @80_6449c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @81_6449c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 45), sizeof v); (u32)v; });  // @82_6449c0
  eax = (u32)(eax + edi*4);  // @83_6449c0
  p7_ = eax;  // @84_6449c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(p7_));  // @85_6449c0
  ecx = edx = 0;  // @86_6449c0
  edi = (edi + 1);  // @87_6449c0
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) goto L644ac0;  // @88_6449c0
  L644ad6:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @90_6449c0
  SEH_LEAVE();  // @91_6449c0
  return eax;  // @92_6449c0
}
PCREG(6449c0, lifted_6449c0);

extern "C" u32 THISCALL lifted_5d59a0(u32 ecx_in) {
  SEH_ENTER(0x66c8a2);  // @h_5d59a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_5d59a0
  eax = ext_43e0f0_thiscall1(ecx);  // @1_5d59a0
  ecx = edx = 0;  // @2_5d59a0
  eax = ext_41e290_cdecl1((u32)(144));  // @3_5d59a0
  ecx = edx = 0;  // @4_5d59a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_5d59a0
  reg.state = (s32)((u32)(0));  // @6_5d59a0
  if ((eax & eax) == 0) goto L5d59f1;  // @7_5d59a0
  ecx = eax;  // @8_5d59a0
  eax = ext_5f0630_thiscall1(ecx);  // @9_5d59a0
  ecx = edx = 0;  // @10_5d59a0
  goto L5d59f3;  // @11_5d59a0
  L5d59f1:;
  eax = 0;  // @13_5d59a0
  L5d59f3:;
  ecx = eax;  // @15_5d59a0
  reg.state = (s32)((u32)(4294967295));  // @16_5d59a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @17_5d59a0
  eax = ext_5f0880_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 33), sizeof v); (u32)v; }));  // @18_5d59a0
  ecx = edx = 0;  // @19_5d59a0
  edi = (u32)(32);  // @20_5d59a0
  L5d5a10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @22_5d59a0
  eax = ext_5f0700_thiscall2(ecx, (u32)(6781786));  // @23_5d59a0
  ecx = edx = 0;  // @24_5d59a0
  edi = (edi - (u32)(1));  // @25_5d59a0
  if (edi != 0) goto L5d5a10;  // @26_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @27_5d59a0
  p0_ = edi;  // @28_5d59a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_5d59a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(7034916), (u32)(p0_));  // @30_5d59a0
  ecx = edx = 0;  // @31_5d59a0
  edi = eax;  // @32_5d59a0
  if ((s32)(edi & edi) <= 0) goto L5d5a6d;  // @33_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @34_5d59a0
  if ((ecx & ecx) == 0) goto L5d5a4b;  // @35_5d59a0
  p1_ = ecx;  // @36_5d59a0
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(1));  // @37_5d59a0
  ecx = edx = 0;  // @38_5d59a0
  L5d5a4b:;
  p2_ = edi;  // @40_5d59a0
  eax = ext_41e290_cdecl1((u32)(p2_));  // @41_5d59a0
  ecx = edx = 0;  // @42_5d59a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @43_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @44_5d59a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_5d59a0
  p3_ = edi;  // @46_5d59a0
  p4_ = eax;  // @47_5d59a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(7034916), (u32)(p4_), (u32)(p3_), (u32)(0), (u32)(0));  // @48_5d59a0
  ecx = edx = 0;  // @49_5d59a0
  L5d5a6d:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @51_5d59a0
  edx = 0;  // @52_5d59a0
  ecx = (u32)(ebx + 1);  // @53_5d59a0
  L5d5a75:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) & 0xff);  // @55_5d59a0
  ebx = (ebx + 1);  // @56_5d59a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5d5a75;  // @57_5d59a0
  ebx = (ebx - ecx);  // @58_5d59a0
  edi = edx;  // @59_5d59a0
  if ((s32)ebx < 0) goto L5d5ab9;  // @60_5d59a0
  L5d5a82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @62_5d59a0
  ecx = (u32)(eax + edi);  // @63_5d59a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @64_5d59a0
  if ((eax & 0xff) == (u32)(10)) goto L5d5a92;  // @65_5d59a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5d5ab4;  // @66_5d59a0
  L5d5a92:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @68_5d59a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @69_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @70_5d59a0
  eax = (eax + edx);  // @71_5d59a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(32)) goto L5d5aab;  // @72_5d59a0
  eax = (eax + 1);  // @73_5d59a0
  p5_ = eax;  // @74_5d59a0
  eax = ext_5f0700_thiscall2(ecx, (u32)(p5_));  // @75_5d59a0
  ecx = edx = 0;  // @76_5d59a0
  goto L5d5ab1;  // @77_5d59a0
  L5d5aab:;
  p6_ = eax;  // @79_5d59a0
  eax = ext_5f0750_thiscall2(ecx, (u32)(p6_));  // @80_5d59a0
  ecx = edx = 0;  // @81_5d59a0
  L5d5ab1:;
  edx = (u32)(edi + 1);  // @83_5d59a0
  L5d5ab4:;
  edi = (edi + 1);  // @85_5d59a0
  if ((s32)edi <= (s32)ebx) goto L5d5a82;  // @86_5d59a0
  L5d5ab9:;
  SEH_LEAVE();  // @88_5d59a0
  return eax;  // @89_5d59a0
}
PCREG(5d59a0, lifted_5d59a0);

extern "C" u32 THISCALL lifted_57cb40(u32 ecx_in) {
  SEH_ENTER(0x66b22b);  // @h_57cb40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_57cb40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }) != (u32)(0)) goto L57ccfa;  // @2_57cb40
  edi = (u32)(ebx + 572);  // @3_57cb40
  if ((edi & edi) == 0) goto L57ccd9;  // @4_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_57cb40
  ecx = (u32)(EBP - 208);  // @6_57cb40
  p0_ = ecx;  // @7_57cb40
  ecx = edi;  // @8_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @9_57cb40
  ecx = edx = 0;  // @10_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_57cb40
  ecx = (u32)(EBP - 208);  // @12_57cb40
  p1_ = ecx;  // @13_57cb40
  ecx = edi;  // @14_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @15_57cb40
  ecx = edx = 0;  // @16_57cb40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }) == (u32)(0)) goto L57ccd9;  // @17_57cb40
  L57cbb6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @19_57cb40
  p2_ = eax;  // @20_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(p2_));  // @22_57cb40
  ecx = edx = 0;  // @23_57cb40
  esi = eax;  // @24_57cb40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 223), sizeof v); (u32)v; }) == (u32)(0)) goto L57ccbe;  // @25_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 188)))(ecx);  // @28_57cb40
  ecx = edx = 0;  // @29_57cb40
  ecx = (u32)(esi + 44);  // @30_57cb40
  p3_ = ecx;  // @31_57cb40
  ecx = eax;  // @32_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, (u32)(p3_));  // @34_57cb40
  ecx = edx = 0;  // @35_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_57cb40
  ecx = (u32)(6990352);  // @37_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_57cb40
  L57cbf6:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @40_57cb40
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L57cc16;  // @41_57cb40
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L57cc12;  // @42_57cb40
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @43_57cb40
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L57cc16;  // @44_57cb40
  ecx = (ecx + (u32)(2));  // @45_57cb40
  eax = (eax + (u32)(2));  // @46_57cb40
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L57cbf6;  // @47_57cb40
  L57cc12:;
  eax = 0;  // @49_57cb40
  goto L57cc1b;  // @50_57cb40
  L57cc16:;
  eax = 0;  // @52_57cb40
  eax = (eax | (u32)(1));  // @53_57cb40
  L57cc1b:;
  if ((eax & eax) != 0) goto L57ccbe;  // @55_57cb40
  ecx = (u32)(EBP - 196);  // @56_57cb40
  eax = ext_4cbeb0_thiscall1(ecx);  // @57_57cb40
  ecx = edx = 0;  // @58_57cb40
  eax = (u32)(EBP - 196);  // @59_57cb40
  reg.state = (s32)((u32)(0));  // @60_57cb40
  p4_ = eax;  // @61_57cb40
  ecx = esi;  // @62_57cb40
  eax = ext_57d500_thiscall3(ecx, (u32)(p4_), (u32)(6991200));  // @63_57cb40
  ecx = edx = 0;  // @64_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 172), sizeof v); (u32)v; });  // @65_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @67_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 188), sizeof v); (u32)v; });  // @68_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @69_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 176), sizeof v); (u32)v; });  // @70_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @71_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 192), sizeof v); (u32)v; });  // @72_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @73_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 180), sizeof v); (u32)v; });  // @74_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @75_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 196), sizeof v); (u32)v; });  // @76_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @77_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 184), sizeof v); (u32)v; });  // @78_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @79_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 200), sizeof v); (u32)v; });  // @80_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @81_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @83_57cb40
  ecx = edx = 0;  // @84_57cb40
  ecx = (u32)(EBP - 196);  // @85_57cb40
  p5_ = ecx;  // @86_57cb40
  ecx = eax;  // @87_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, (u32)(p5_));  // @89_57cb40
  ecx = edx = 0;  // @90_57cb40
  ecx = (u32)(EBP - 196);  // @91_57cb40
  reg.state = (s32)((u32)(4294967295));  // @92_57cb40
  eax = ext_4cbec0_thiscall1(ecx);  // @93_57cb40
  ecx = edx = 0;  // @94_57cb40
  L57ccbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @96_57cb40
  ecx = (u32)(EBP - 208);  // @97_57cb40
  p6_ = ecx;  // @98_57cb40
  ecx = edi;  // @99_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p6_));  // @100_57cb40
  ecx = edx = 0;  // @101_57cb40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }) != (u32)(0)) goto L57cbb6;  // @102_57cb40
  L57ccd9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @104_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 116)))(ecx);  // @106_57cb40
  ecx = edx = 0;  // @107_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @108_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 112)))(ecx);  // @110_57cb40
  ecx = edx = 0;  // @111_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @112_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @114_57cb40
  ecx = edx = 0;  // @115_57cb40
  L57ccfa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @117_57cb40
  ecx = ebx;  // @118_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(0));  // @119_57cb40
  ecx = edx = 0;  // @120_57cb40
  SEH_LEAVE();  // @121_57cb40
  ext_633654(G(u32, 0x6f5630));  // @122_57cb40
  return eax;  // @123_57cb40
}
PCREG(57cb40, lifted_57cb40);

extern "C" u32 THISCALL lifted_437440(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665ac2);  // @h_437440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_437440
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @2_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @3_437440
  eax = ext_41e290_cdecl1((u32)(28));  // @4_437440
  ecx = edx = 0;  // @5_437440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @6_437440
  reg.state = (s32)((u32)(0));  // @7_437440
  if ((eax & eax) == 0) goto L4374a3;  // @8_437440
  ecx = eax;  // @9_437440
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @10_437440
  ecx = edx = 0;  // @11_437440
  goto L4374a5;  // @12_437440
  L4374a3:;
  eax = 0;  // @14_437440
  L4374a5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @16_437440
  reg.state = (s32)((u32)(4294967295));  // @17_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L437632;  // @18_437440
  L4374c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @20_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }));  // @22_437440
  ecx = edx = 0;  // @23_437440
  edi = eax;  // @24_437440
  if ((edi & edi) == 0) goto L437538;  // @25_437440
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 160), sizeof v); (u32)v; }) == (u32)(0)) goto L4374e5;  // @26_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @27_437440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 161), &v, sizeof v); }  // @28_437440
  L4374e5:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L43752e;  // @30_437440
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; }) != (u32)(0)) goto L43752e;  // @31_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @32_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2574));  // @34_437440
  ecx = edx = 0;  // @35_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_437440
  p0_ = eax;  // @37_437440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6793848), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @38_437440
  ecx = edx = 0;  // @39_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @40_437440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @41_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @43_437440
  ecx = edx = 0;  // @44_437440
  L43752e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @46_437440
  ecx = ebx;  // @47_437440
  p1_ = edi;  // @48_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @49_437440
  ecx = edx = 0;  // @50_437440
  goto L437540;  // @51_437440
  L437538:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @53_437440
  ecx = ebx;  // @54_437440
  p2_ = esi;  // @55_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(p2_));  // @56_437440
  ecx = edx = 0;  // @57_437440
  L437540:;
  esi = (esi + (u32)(28));  // @59_437440
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @60_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != 0) goto L4374c0;  // @61_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 145), sizeof v); (u32)v; })) & 0xff);  // @62_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @63_437440
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L437638;  // @64_437440
  if ((esi & esi) == 0) goto L437644;  // @65_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_437440
  ecx = (u32)(EBP - 164);  // @67_437440
  p3_ = ecx;  // @68_437440
  ecx = esi;  // @69_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p3_));  // @70_437440
  ecx = edx = 0;  // @71_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_437440
  ecx = (u32)(EBP - 164);  // @73_437440
  p4_ = ecx;  // @74_437440
  ecx = esi;  // @75_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p4_));  // @76_437440
  ecx = edx = 0;  // @77_437440
  ecx = eax;  // @78_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) == (u32)(0)) goto L437638;  // @79_437440
  L437594:;
  edx = (u32)(EBP - 144);  // @81_437440
  edx = (edx - ecx);  // @82_437440
  L4375a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @84_437440
  ecx = (u32)(ecx + 1);  // @85_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @86_437440
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4375a0;  // @87_437440
  esi = (u32)(EBP - 144);  // @88_437440
  L4375b3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @90_437440
  edi = esi;  // @91_437440
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L43760d;  // @92_437440
  if ((eax & 0xff) == (u32)(48)) goto L43760d;  // @93_437440
  L4375c0:;
  if ((eax & 0xff) == (u32)(43)) goto L4375d0;  // @95_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @96_437440
  esi = (esi + 1);  // @97_437440
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4375c0;  // @98_437440
  if ((eax & 0xff) != (u32)(43)) goto L4375d4;  // @99_437440
  L4375d0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @101_437440
  esi = (esi + 1);  // @102_437440
  L4375d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @104_437440
  p5_ = edi;  // @105_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p5_));  // @107_437440
  ecx = edx = 0;  // @108_437440
  if ((eax & eax) == 0) goto L4375e7;  // @109_437440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @110_437440
  goto L4375b3;  // @111_437440
  L4375e7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @113_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2603));  // @115_437440
  ecx = edx = 0;  // @116_437440
  p6_ = edi;  // @117_437440
  p7_ = eax;  // @118_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @119_437440
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p7_), (u32)(6793964), (u32)(p6_));  // @120_437440
  ecx = edx = 0;  // @121_437440
  goto L4375b3;  // @122_437440
  L43760d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @124_437440
  ecx = (u32)(EBP - 164);  // @125_437440
  p8_ = ecx;  // @126_437440
  ecx = esi;  // @127_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @128_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p8_));  // @129_437440
  ecx = edx = 0;  // @130_437440
  ecx = eax;  // @131_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) != (u32)(0)) goto L437594;  // @132_437440
  goto L437638;  // @133_437440
  L437632:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @135_437440
  L437638:;
  if ((esi & esi) == 0) goto L437644;  // @137_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_437440
  ecx = esi;  // @139_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @140_437440
  ecx = edx = 0;  // @141_437440
  L437644:;
  SEH_LEAVE();  // @143_437440
  ext_633654(G(u32, 0x6f5630));  // @144_437440
  return eax;  // @145_437440
}
PCREG(437440, lifted_437440);

extern "C" u32 THISCALL lifted_661940(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @2_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @3_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_661940
  edi = edx;  // @5_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @6_661940
  eax = edx;  // @7_661940
  ebx = (edx & 0xffff);  // @8_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @9_661940
  eax = (eax >> (u32)(31));  // @10_661940
  edx = (edx + ecx);  // @11_661940
  edi = (edi >> (u32)(16));  // @12_661940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @13_661940
  edi = (edi & (u32)(32767));  // @14_661940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @15_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @16_661940
  ebx = (ebx + edi);  // @17_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @18_661940
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; }) & eax) != 0) goto L661994;  // @19_661940
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @20_661940
  return eax;  // @21_661940
  L661994:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @23_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @24_661940
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @25_661940
  eax = (u32)(eax + edi*2);  // @26_661940
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @27_661940
  p0_ = ebx;  // @28_661940
  p1_ = edi;  // @29_661940
  p2_ = eax;  // @30_661940
  p3_ = ecx;  // @31_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @32_661940
  eax = ext_661b40_stdcall8((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @33_661940
  ecx = edx = 0;  // @34_661940
  return eax;  // @35_661940
}
PCREG(661940, lifted_661940);

extern "C" u32 THISCALL lifted_656fe0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_656fe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @1_656fe0
  ecx = edx = 0;  // @2_656fe0
  edx = eax;  // @3_656fe0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; }) != (u32)(0)) goto L65702c;  // @4_656fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_656fe0
  ecx = (ecx - 1);  // @6_656fe0
  if (ecx > (u32)(15)) goto L65701e;  // @7_656fe0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6647884), sizeof v); (u32)v; });  // @8_656fe0
  switch (ecx) { case 0: goto L657012; case 1: goto L65700b; case 2: goto L65701e; default: __builtin_trap(); }  // @9_656fe0
  L65700b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @11_656fe0
  return eax;  // @12_656fe0
  L657012:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 14), sizeof v); (u32)v; });  // @14_656fe0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 80), sizeof v); (u32)v; }));  // @15_656fe0
  return eax;  // @16_656fe0
  L65701e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_656fe0
  if ((eax & eax) == 0) goto L65702b;  // @19_656fe0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @20_656fe0
  ecx = edx = 0;  // @21_656fe0
  goto L65702c;  // @22_656fe0
  L65702b:;
  __builtin_trap();  // @24_656fe0
  L65702c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @26_656fe0
  if ((eax & eax) == 0) goto L65703b;  // @27_656fe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @28_656fe0
  ecx = edx = 0;  // @29_656fe0
  return eax;  // @30_656fe0
  L65703b:;
  __builtin_trap();  // @32_656fe0
}
PCREG(656fe0, lifted_656fe0);

extern "C" u32 STDCALL lifted_657360(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_657360
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @1_657360
  if (eax > (u32)(6)) goto L6573db;  // @2_657360
  switch (eax) { case 0: goto L657377; case 1: goto L657381; case 2: goto L6573db; case 3: goto L6573db; case 4: goto L65738b; case 5: goto L6573db; case 6: goto L657395; case 7: goto L6573af; case 8: goto L6573a5; case 9: goto L6573c3; case 10: goto L6573b9; default: __builtin_trap(); }  // @3_657360
  L657377:;
  eax = (u32)(124);  // @5_657360
  return eax;  // @6_657360
  L657381:;
  eax = (u32)(160);  // @8_657360
  return eax;  // @9_657360
  L65738b:;
  eax = (u32)(132);  // @11_657360
  return eax;  // @12_657360
  L657395:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @14_657360
  if (eax > (u32)(3)) goto L6573cd;  // @15_657360
  switch (eax) { case 0: goto L6573af; case 1: goto L6573a5; case 2: goto L6573c3; case 3: goto L6573b9; default: __builtin_trap(); }  // @16_657360
  L6573a5:;
  eax = (u32)(36);  // @18_657360
  return eax;  // @19_657360
  L6573af:;
  eax = (u32)(56);  // @21_657360
  return eax;  // @22_657360
  L6573b9:;
  eax = (u32)(28);  // @24_657360
  return eax;  // @25_657360
  L6573c3:;
  eax = (u32)(60);  // @27_657360
  return eax;  // @28_657360
  L6573cd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_657360
  if ((eax & eax) == 0) goto L6573da;  // @31_657360
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_657360
  ecx = edx = 0;  // @33_657360
  goto L6573db;  // @34_657360
  L6573da:;
  __builtin_trap();  // @36_657360
  L6573db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @38_657360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_657360
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7094156), (u32)(47));  // @40_657360
  ecx = edx = 0;  // @41_657360
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @42_657360
  p0_ = ecx;  // @43_657360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @44_657360
  p1_ = eax;  // @45_657360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(p1_), (u32)(7094216), (u32)(p0_));  // @46_657360
  ecx = edx = 0;  // @47_657360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @48_657360
  if ((eax & eax) == 0) goto L657410;  // @49_657360
  eax = ((u32(STDCALL *)(void))(eax))();  // @50_657360
  ecx = edx = 0;  // @51_657360
  return eax;  // @52_657360
  L657410:;
  __builtin_trap();  // @54_657360
}
PCREG(657360, lifted_657360);

extern "C" u32 THISCALL lifted_64ba70(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64ba70
  esi = 0;  // @1_64ba70
  ebx = ecx;  // @2_64ba70
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3_64ba70
  eax = (eax - 1);  // @4_64ba70
  if (eax > (u32)(6)) goto L64bb58;  // @5_64ba70
  switch (eax) { case 0: goto L64bb18; case 1: goto L64ba92; case 2: goto L64baad; case 3: goto L64bb03; case 4: goto L64bae1; case 5: goto L64bac8; case 6: goto L64baf2; default: __builtin_trap(); }  // @6_64ba70
  L64ba92:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @8_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @9_64ba70
  if ((eax & eax) == 0) goto L64baa2;  // @10_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @11_64ba70
  esi = (esi + (u32)(90));  // @12_64ba70
  L64baa2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65877), sizeof v); (u32)v; });  // @14_64ba70
  goto L64bb31;  // @15_64ba70
  L64baad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @17_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @18_64ba70
  if ((eax & eax) == 0) goto L64baba;  // @19_64ba70
  esi = (u32)(eax + 90);  // @20_64ba70
  L64baba:;
  p0_ = edi;  // @22_64ba70
  eax = ext_64c1e0_thiscall2(ecx, (u32)(p0_));  // @23_64ba70
  ecx = edx = 0;  // @24_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65881), sizeof v); (u32)v; });  // @25_64ba70
  goto L64bb31;  // @26_64ba70
  L64bac8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @28_64ba70
  p1_ = edi;  // @29_64ba70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p1_));  // @30_64ba70
  ecx = edx = 0;  // @31_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65885), sizeof v); (u32)v; });  // @32_64ba70
  p2_ = edi;  // @33_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_64ba70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p2_));  // @35_64ba70
  ecx = edx = 0;  // @36_64ba70
  return eax;  // @37_64ba70
  L64bae1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @39_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65889), sizeof v); (u32)v; });  // @40_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @41_64ba70
  esi = (esi + (u32)(6));  // @42_64ba70
  goto L64bb31;  // @43_64ba70
  L64baf2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @45_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65897), sizeof v); (u32)v; });  // @46_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @47_64ba70
  esi = (esi + (u32)(64));  // @48_64ba70
  goto L64bb31;  // @49_64ba70
  L64bb03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @51_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @52_64ba70
  if ((eax & eax) == 0) goto L64bb10;  // @53_64ba70
  esi = (u32)(eax + 90);  // @54_64ba70
  L64bb10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65901), sizeof v); (u32)v; });  // @56_64ba70
  goto L64bb31;  // @57_64ba70
  L64bb18:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @59_64ba70
  edi = (edi + (u32)(-4));  // @60_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @61_64ba70
  if ((eax & eax) == 0) goto L64bb2b;  // @62_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @63_64ba70
  esi = (esi + (u32)(90));  // @64_64ba70
  L64bb2b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65873), sizeof v); (u32)v; });  // @66_64ba70
  L64bb31:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_64ba70
  p3_ = edi;  // @69_64ba70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p3_));  // @70_64ba70
  ecx = edx = 0;  // @71_64ba70
  if ((esi & esi) == 0) goto L64bb6b;  // @72_64ba70
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65649), sizeof v); (u32)v; });  // @74_64ba70
  ecx = (ecx & (u32)(4095));  // @75_64ba70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @76_64ba70
  return eax;  // @77_64ba70
  L64bb58:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @79_64ba70
  if ((eax & eax) == 0) goto L64bb6a;  // @80_64ba70
  eax = ((u32(STDCALL *)(void))(eax))();  // @81_64ba70
  ecx = edx = 0;  // @82_64ba70
  return eax;  // @83_64ba70
  L64bb6a:;
  __builtin_trap();  // @85_64ba70
  L64bb6b:;
  return eax;  // @87_64ba70
}
PCREG(64ba70, lifted_64ba70);

extern "C" u32 THISCALL lifted_63e480(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63e480
  ebx = ecx;  // @1_63e480
  edi = 0;  // @2_63e480
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @3_63e480
  eax = (eax - 1);  // @4_63e480
  if (eax > (u32)(6)) goto L63e5b4;  // @5_63e480
  switch (eax) { case 0: goto L63e567; case 1: goto L63e4a2; case 2: goto L63e4c3; case 3: goto L63e555; case 4: goto L63e4fd; case 5: goto L63e4e1; case 6: goto L63e514; default: __builtin_trap(); }  // @6_63e480
  L63e4a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_63e480
  p0_ = esi;  // @9_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(p0_));  // @10_63e480
  ecx = edx = 0;  // @11_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @12_63e480
  if ((eax & eax) == 0) goto L63e4b8;  // @13_63e480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @14_63e480
  edi = (edi + (u32)(90));  // @15_63e480
  L63e4b8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 540), sizeof v); (u32)v; });  // @17_63e480
  goto L63e57a;  // @18_63e480
  L63e4c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_63e480
  p1_ = esi;  // @21_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 148)))(ecx, (u32)(p1_));  // @22_63e480
  ecx = edx = 0;  // @23_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @24_63e480
  if ((eax & eax) == 0) goto L63e4d6;  // @25_63e480
  edi = (u32)(eax + 90);  // @26_63e480
  L63e4d6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 544), sizeof v); (u32)v; });  // @28_63e480
  goto L63e57a;  // @29_63e480
  L63e4e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_63e480
  p2_ = esi;  // @32_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(p2_));  // @33_63e480
  ecx = edx = 0;  // @34_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 548), sizeof v); (u32)v; });  // @35_63e480
  p3_ = esi;  // @36_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p3_));  // @38_63e480
  ecx = edx = 0;  // @39_63e480
  return eax;  // @40_63e480
  L63e4fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_63e480
  p4_ = esi;  // @43_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 152)))(ecx, (u32)(p4_));  // @44_63e480
  ecx = edx = 0;  // @45_63e480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @46_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 552), sizeof v); (u32)v; });  // @47_63e480
  edi = (edi + (u32)(6));  // @48_63e480
  goto L63e57a;  // @49_63e480
  L63e514:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @51_63e480
  eax = (u32)(EBP + 8);  // @52_63e480
  ecx = (u32)(ebx + 368);  // @53_63e480
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @54_63e480
  p5_ = eax;  // @55_63e480
  edi = (edi + (u32)(64));  // @56_63e480
  eax = ext_63db40_thiscall2(ecx, (u32)(p5_));  // @57_63e480
  ecx = edx = 0;  // @58_63e480
  edx = eax;  // @59_63e480
  if (edx == (u32)(-1)) goto L63e54d;  // @60_63e480
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 368), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(ebx + 368), &v, sizeof v); }  // @61_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 368), sizeof v); (u32)v; });  // @62_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx*4 + 372), sizeof v); (u32)v; });  // @63_63e480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + edx*4 + 372), &v, sizeof v); }  // @64_63e480
  L63e54d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 556), sizeof v); (u32)v; });  // @66_63e480
  goto L63e57a;  // @67_63e480
  L63e555:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @69_63e480
  if ((eax & eax) == 0) goto L63e55f;  // @70_63e480
  edi = (u32)(eax + 90);  // @71_63e480
  L63e55f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 560), sizeof v); (u32)v; });  // @73_63e480
  goto L63e57a;  // @74_63e480
  L63e567:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @76_63e480
  if ((eax & eax) == 0) goto L63e574;  // @77_63e480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @78_63e480
  edi = (edi + (u32)(90));  // @79_63e480
  L63e574:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 536), sizeof v); (u32)v; });  // @81_63e480
  L63e57a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_63e480
  p6_ = esi;  // @84_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p6_));  // @85_63e480
  ecx = edx = 0;  // @86_63e480
  if ((edi & edi) == 0) goto L63e5c7;  // @87_63e480
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @89_63e480
  ecx = edx;  // @90_63e480
  ecx = (ecx & (u32)(4095));  // @91_63e480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @92_63e480
  eax = (u32)(edx - 1);  // @93_63e480
  p7_ = eax;  // @94_63e480
  ecx = (u32)(ebx + 47504);  // @95_63e480
  eax = ext_4ce180_thiscall2(ecx, (u32)(p7_));  // @96_63e480
  ecx = edx = 0;  // @97_63e480
  eax = 0;  // @98_63e480
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @99_63e480
  return eax;  // @100_63e480
  L63e5b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @102_63e480
  if ((eax & eax) == 0) goto L63e5c6;  // @103_63e480
  eax = ((u32(STDCALL *)(void))(eax))();  // @104_63e480
  ecx = edx = 0;  // @105_63e480
  return eax;  // @106_63e480
  L63e5c6:;
  __builtin_trap();  // @108_63e480
  L63e5c7:;
  return eax;  // @110_63e480
}
PCREG(63e480, lifted_63e480);

extern "C" u32 FASTCALL lifted_6403a0(u32 ecx_in, u32 edx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6403a0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @1_6403a0
  if (((edx & 0xffff) & (edx & 0xffff)) == 0) goto L6403e4;  // @2_6403a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 104), sizeof v); (u32)v; });  // @3_6403a0
  edx = (edx & (u32)(4095));  // @4_6403a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @5_6403a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @6_6403a0
  eax = (eax - 1);  // @7_6403a0
  if (eax > (u32)(3)) goto L6403d4;  // @8_6403a0
  switch (eax) { case 0: goto L6403e4; case 1: goto L6403cc; case 2: goto L6403e4; case 3: goto L6403e4; default: __builtin_trap(); }  // @9_6403a0
  L6403cc:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 66), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ecx + 66), &v, sizeof v); }  // @11_6403a0
  return eax;  // @12_6403a0
  L6403d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @14_6403a0
  if ((eax & eax) == 0) goto L6403e3;  // @15_6403a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @16_6403a0
  ecx = edx = 0;  // @17_6403a0
  return eax;  // @18_6403a0
  L6403e3:;
  __builtin_trap();  // @20_6403a0
  L6403e4:;
  return eax;  // @22_6403a0
}
PCREG(6403a0, lifted_6403a0);

extern "C" u32 THISCALL lifted_41f0d0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x664012);  // @h_41f0d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @1_41f0d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_41f0d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 61), &v, sizeof v); }  // @3_41f0d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @4_41f0d0
  if ((ecx & ecx) == 0) goto L41f116;  // @5_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_41f0d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(140));  // @7_41f0d0
  ecx = edx = 0;  // @8_41f0d0
  goto L41f11f;  // @9_41f0d0
  L41f116:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x6762f0))();  // @11_41f0d0
  ecx = edx = 0;  // @12_41f0d0
  L41f11f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_41f0d0
  reg.state = (s32)((u32)(0));  // @15_41f0d0
  if ((eax & eax) == 0) goto L41f13f;  // @16_41f0d0
  ecx = eax;  // @17_41f0d0
  p0_ = edi;  // @18_41f0d0
  eax = ext_4d0f30_thiscall4(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @19_41f0d0
  ecx = edx = 0;  // @20_41f0d0
  ecx = eax;  // @21_41f0d0
  goto L41f141;  // @22_41f0d0
  L41f13f:;
  ecx = 0;  // @24_41f0d0
  L41f141:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @26_41f0d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + eax*4 + 53), &v, sizeof v); }  // @27_41f0d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @28_41f0d0
  SEH_LEAVE();  // @29_41f0d0
  return eax;  // @30_41f0d0
}
PCREG(41f0d0, lifted_41f0d0);

extern "C" u32 THISCALL lifted_6150c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e51a);  // @h_6150c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_6150c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6150c0
  edx = 0;  // @2_6150c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @3_6150c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; });  // @4_6150c0
  if (eax > (u32)(4)) goto L6151f1;  // @5_6150c0
  switch (eax) { case 0: goto L615102; case 1: goto L61512e; case 2: goto L61518f; case 3: goto L6151b4; case 4: goto L6151ca; default: __builtin_trap(); }  // @6_6150c0
  L615102:;
  eax = ext_41e290_cdecl1((u32)(52));  // @8_6150c0
  ecx = edx = 0;  // @9_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @10_6150c0
  reg.state = (s32)((u32)(0));  // @11_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @12_6150c0
  p0_ = esi;  // @13_6150c0
  p1_ = edi;  // @14_6150c0
  ecx = eax;  // @15_6150c0
  eax = ext_6168f0_thiscall3(ecx, (u32)(p1_), (u32)(p0_));  // @16_6150c0
  ecx = edx = 0;  // @17_6150c0
  edx = eax;  // @18_6150c0
  goto L6151f1;  // @19_6150c0
  L61512e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47524), sizeof v); (u32)v; });  // @21_6150c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5101), sizeof v); (u32)v; })) & 0xff);  // @22_6150c0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L61516a;  // @23_6150c0
  eax = ext_41e290_cdecl1((u32)(48));  // @24_6150c0
  ecx = edx = 0;  // @25_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @26_6150c0
  reg.state = (s32)((u32)(1));  // @27_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @28_6150c0
  p2_ = esi;  // @29_6150c0
  p3_ = edi;  // @30_6150c0
  ecx = eax;  // @31_6150c0
  eax = ext_6162f0_thiscall3(ecx, (u32)(p3_), (u32)(p2_));  // @32_6150c0
  ecx = edx = 0;  // @33_6150c0
  edx = eax;  // @34_6150c0
  goto L6151f1;  // @35_6150c0
  L61516a:;
  eax = ext_41e290_cdecl1((u32)(16));  // @37_6150c0
  ecx = edx = 0;  // @38_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @39_6150c0
  reg.state = (s32)((u32)(2));  // @40_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @41_6150c0
  p4_ = esi;  // @42_6150c0
  p5_ = edi;  // @43_6150c0
  ecx = eax;  // @44_6150c0
  eax = ext_616150_thiscall3(ecx, (u32)(p5_), (u32)(p4_));  // @45_6150c0
  ecx = edx = 0;  // @46_6150c0
  edx = eax;  // @47_6150c0
  goto L6151f1;  // @48_6150c0
  L61518f:;
  eax = ext_41e290_cdecl1((u32)(12));  // @50_6150c0
  ecx = edx = 0;  // @51_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @52_6150c0
  reg.state = (s32)((u32)(3));  // @53_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @54_6150c0
  p6_ = esi;  // @55_6150c0
  p7_ = edi;  // @56_6150c0
  ecx = eax;  // @57_6150c0
  eax = ext_6168c0_thiscall3(ecx, (u32)(p7_), (u32)(p6_));  // @58_6150c0
  ecx = edx = 0;  // @59_6150c0
  edx = eax;  // @60_6150c0
  goto L6151f1;  // @61_6150c0
  L6151b4:;
  eax = ext_41e290_cdecl1((u32)(48));  // @63_6150c0
  ecx = edx = 0;  // @64_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @65_6150c0
  reg.state = (s32)((u32)(4));  // @66_6150c0
  goto L6151de;  // @67_6150c0
  L6151ca:;
  eax = ext_41e290_cdecl1((u32)(48));  // @69_6150c0
  ecx = edx = 0;  // @70_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @71_6150c0
  reg.state = (s32)((u32)(5));  // @72_6150c0
  L6151de:;
  if ((eax & eax) == 0) goto L6151ef;  // @74_6150c0
  p8_ = esi;  // @75_6150c0
  p9_ = edi;  // @76_6150c0
  ecx = eax;  // @77_6150c0
  eax = ext_6166c0_thiscall3(ecx, (u32)(p9_), (u32)(p8_));  // @78_6150c0
  ecx = edx = 0;  // @79_6150c0
  edx = eax;  // @80_6150c0
  goto L6151f1;  // @81_6150c0
  L6151ef:;
  edx = 0;  // @83_6150c0
  L6151f1:;
  eax = edx;  // @85_6150c0
  SEH_LEAVE();  // @86_6150c0
  return eax;  // @87_6150c0
}
PCREG(6150c0, lifted_6150c0);

extern "C" u32 lifted_6349c7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676060))((u32)(0));  // @0_6349c7
  ecx = edx = 0;  // @1_6349c7
  ecx = eax;  // @2_6349c7
  if ((ecx & ecx) != 0) goto L6349d8;  // @3_6349c7
  L6349d5:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @5_6349c7
  return eax;  // @6_6349c7
  L6349d8:;
  eax = (u32)(23117);  // @8_6349c7
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L6349d5;  // @9_6349c7
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @10_6349c7
  eax = (eax + ecx);  // @11_6349c7
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(17744)) goto L6349d5;  // @12_6349c7
  ecx = (u32)(267);  // @13_6349c7
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }) != (ecx & 0xffff)) goto L6349d5;  // @14_6349c7
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; }) <= (u32)(14)) goto L6349d5;  // @15_6349c7
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 232), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @16_6349c7
  return eax;  // @17_6349c7
}
PCREG(6349c7, lifted_6349c7);

extern "C" u32 THISCALL lifted_4cdd50(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4cdd50
  edi = ecx;  // @1_4cdd50
  eax = (eax + (u32)(-8));  // @2_4cdd50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @3_4cdd50
  esi = (u32)(eax + esi*4);  // @4_4cdd50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L4cddb1;  // @5_4cdd50
  eax = ext_41e290_cdecl1((u32)(28));  // @6_4cdd50
  ecx = edx = 0;  // @7_4cdd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @8_4cdd50
  if ((eax & eax) == 0) goto L4cddac;  // @9_4cdd50
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @10_4cdd50
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @12_4cdd50
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @13_4cdd50
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @14_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @15_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @16_4cdd50
  goto L4cddae;  // @17_4cdd50
  L4cddac:;
  eax = 0;  // @19_4cdd50
  L4cddae:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @21_4cdd50
  L4cddb1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @23_4cdd50
  p0_ = esi;  // @24_4cdd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4cdd50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p0_));  // @26_4cdd50
  ecx = edx = 0;  // @27_4cdd50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_4cdd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @29_4cdd50
  if ((ecx & ecx) == 0) goto L4cddc8;  // @30_4cdd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @31_4cdd50
  goto L4cddcb;  // @32_4cdd50
  L4cddc8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @34_4cdd50
  L4cddcb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @36_4cdd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_4cdd50
  if ((ecx & ecx) == 0) goto L4cddd8;  // @38_4cdd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @39_4cdd50
  goto L4cdddb;  // @40_4cdd50
  L4cddd8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @42_4cdd50
  L4cdddb:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @44_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_4cdd50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @46_4cdd50
  return eax;  // @47_4cdd50
}
PCREG(4cdd50, lifted_4cdd50);

extern "C" u32 THISCALL lifted_64d490(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64d490
  esi = ecx;  // @1_64d490
  p0_ = ebx;  // @2_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @3_64d490
  eax = ext_63da80_stdcall1((u32)(p0_));  // @4_64d490
  ecx = edx = 0;  // @5_64d490
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @6_64d490
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; })) & 0xff);  // @7_64d490
  eax = (u32)(edx + 1);  // @8_64d490
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 9), &v, sizeof v); }  // @9_64d490
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L64d4c6;  // @10_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @11_64d490
  p1_ = edi;  // @12_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_64d490
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, (u32)(p1_));  // @14_64d490
  ecx = edx = 0;  // @15_64d490
  L64d4c6:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @17_64d490
  if ((edi & edi) == 0) goto L64d552;  // @18_64d490
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @19_64d490
  eax = (u32)(ecx + 1);  // @20_64d490
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @21_64d490
  if (((ecx & 0xffff) & (ecx & 0xffff)) != 0) goto L64d4ed;  // @22_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @23_64d490
  p2_ = edi;  // @24_64d490
  eax = ext_63da80_stdcall1((u32)(p2_));  // @25_64d490
  ecx = edx = 0;  // @26_64d490
  L64d4ed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @28_64d490
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6), sizeof v); (u32)v; });  // @29_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65649), sizeof v); (u32)v; });  // @30_64d490
  ecx = (ecx & (u32)(4095));  // @31_64d490
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @32_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @33_64d490
  eax = (u32)(ecx + 1);  // @34_64d490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @35_64d490
  if ((ecx & ecx) != 0) goto L64d518;  // @36_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_64d490
  ecx = esi;  // @38_64d490
  p3_ = edx;  // @39_64d490
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(p3_));  // @40_64d490
  ecx = edx = 0;  // @41_64d490
  L64d518:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 98757), sizeof v); (u32)v; });  // @43_64d490
  if ((esi & esi) == 0) goto L64d542;  // @44_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @45_64d490
  eax = (eax + 1);  // @46_64d490
  if (eax <= (u32)(8192)) goto L64d53a;  // @47_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @48_64d490
  if ((eax & eax) == 0) goto L64d539;  // @49_64d490
  eax = ((u32(STDCALL *)(void))(eax))();  // @50_64d490
  ecx = edx = 0;  // @51_64d490
  goto L64d53a;  // @52_64d490
  L64d539:;
  __builtin_trap();  // @54_64d490
  L64d53a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_64d490
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + eax*4 + 4), &v, sizeof v); }  // @57_64d490
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @58_64d490
  L64d542:;
  ecx = edi;  // @60_64d490
  eax = ext_658f50_thiscall1(ecx);  // @61_64d490
  ecx = edx = 0;  // @62_64d490
  if (eax <= (u32)(1)) goto L64d552;  // @63_64d490
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 5), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(ebx + 5), &v, sizeof v); }  // @64_64d490
  L64d552:;
  return eax;  // @66_64d490
}
PCREG(64d490, lifted_64d490);

extern "C" u32 THISCALL lifted_4d7610(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @0_4d7610
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 17), sizeof v); (u32)v; }) != (u32)(1)) goto L4d7641;  // @1_4d7610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4d7610
  if ((s32)edx > (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; })) edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; });  // @3_4d7610
  eax = (eax + (u32)(9));  // @4_4d7610
  p0_ = edx;  // @5_4d7610
  p1_ = eax;  // @6_4d7610
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @7_4d7610
  ecx = edx = 0;  // @8_4d7610
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @9_4d7610
  return eax;  // @10_4d7610
  L4d7641:;
  eax = (eax + (u32)(9));  // @12_4d7610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @13_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @14_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; });  // @15_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @16_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @18_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @19_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @20_4d7610
  eax = (u32)(EBP - 56);  // @21_4d7610
  p2_ = eax;  // @22_4d7610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @23_4d7610
  eax = ext_62f9d0_stdcall4((u32)(p2_), (u32)(-15), (u32)(6908044), (u32)(56));  // @24_4d7610
  ecx = edx = 0;  // @25_4d7610
  if ((eax & eax) == 0) goto L4d76a8;  // @26_4d7610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @27_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4d7610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6908196), (u32)(1574));  // @29_4d7610
  ecx = edx = 0;  // @30_4d7610
  p3_ = eax;  // @31_4d7610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_4d7610
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6908824));  // @33_4d7610
  ecx = edx = 0;  // @34_4d7610
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @35_4d7610
  return eax;  // @36_4d7610
  L4d76a8:;
  eax = (u32)(EBP - 56);  // @38_4d7610
  p4_ = eax;  // @39_4d7610
  eax = ext_62f5d0_stdcall2((u32)(p4_), (u32)(4));  // @40_4d7610
  ecx = edx = 0;  // @41_4d7610
  esi = eax;  // @42_4d7610
  eax = (u32)(EBP - 56);  // @43_4d7610
  p5_ = eax;  // @44_4d7610
  eax = ext_62f980_stdcall1((u32)(p5_));  // @45_4d7610
  ecx = edx = 0;  // @46_4d7610
  if (esi == (u32)(1)) goto L4d76d8;  // @47_4d7610
  if (esi != (u32)(-5)) goto L4d76cf;  // @48_4d7610
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }) == (u32)(0)) goto L4d76d8;  // @49_4d7610
  L4d76cf:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @51_4d7610
  return eax;  // @52_4d7610
  L4d76d8:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @54_4d7610
  return eax;  // @55_4d7610
}
PCREG(4d7610, lifted_4d7610);

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

extern "C" u32 THISCALL lifted_42a820(u32 ecx_in) {
  SEH_ENTER(0x66496c);  // @h_42a820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_42a820
  eax = ext_42de30_thiscall1(ecx);  // @1_42a820
  ecx = edx = 0;  // @2_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_42a820
  edx = (u32)(EBP - 276);  // @4_42a820
  p0_ = edx;  // @5_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @7_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783396), (u32)(p0_));  // @8_42a820
  ecx = edx = 0;  // @9_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a875;  // @10_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @11_42a820
  L42a875:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_42a820
  edx = (u32)(EBP - 276);  // @14_42a820
  p1_ = edx;  // @15_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @17_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783568), (u32)(p1_));  // @18_42a820
  ecx = edx = 0;  // @19_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a8da;  // @20_42a820
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7003), sizeof v); (u32)v; }) == (u32)(0)) goto L42a8c9;  // @21_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @22_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6788896), (u32)(80));  // @24_42a820
  ecx = edx = 0;  // @25_42a820
  p2_ = eax;  // @26_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6783580));  // @28_42a820
  ecx = edx = 0;  // @29_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_42a820
  if ((eax & eax) == 0) goto L42a8c8;  // @31_42a820
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_42a820
  ecx = edx = 0;  // @33_42a820
  goto L42a8c9;  // @34_42a820
  L42a8c8:;
  __builtin_trap();  // @36_42a820
  L42a8c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @38_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_42a820
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 120)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @40_42a820
  ecx = edx = 0;  // @41_42a820
  L42a8da:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_42a820
  edx = (u32)(EBP - 276);  // @44_42a820
  p3_ = edx;  // @45_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @47_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783656), (u32)(p3_));  // @48_42a820
  ecx = edx = 0;  // @49_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a933;  // @50_42a820
  ecx = (u32)(EBP - 144);  // @51_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @52_42a820
  ecx = edx = 0;  // @53_42a820
  eax = (u32)(EBP - 144);  // @54_42a820
  reg.state = (s32)((u32)(0));  // @55_42a820
  p4_ = eax;  // @56_42a820
  ecx = (u32)(edi + 7153);  // @57_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p4_));  // @58_42a820
  ecx = edx = 0;  // @59_42a820
  ecx = (u32)(EBP - 144);  // @60_42a820
  reg.state = (s32)((u32)(4294967295));  // @61_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @62_42a820
  ecx = edx = 0;  // @63_42a820
  L42a933:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_42a820
  edx = (u32)(EBP - 276);  // @66_42a820
  p5_ = edx;  // @67_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @69_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783668), (u32)(p5_));  // @70_42a820
  ecx = edx = 0;  // @71_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a99a;  // @72_42a820
  ecx = (u32)(EBP - 144);  // @73_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @74_42a820
  ecx = edx = 0;  // @75_42a820
  eax = (u32)(EBP - 144);  // @76_42a820
  reg.state = (s32)((u32)(1));  // @77_42a820
  esi = (u32)(edi + 7025);  // @78_42a820
  p6_ = eax;  // @79_42a820
  ecx = esi;  // @80_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p6_));  // @81_42a820
  ecx = edx = 0;  // @82_42a820
  ecx = (u32)(EBP - 144);  // @83_42a820
  reg.state = (s32)((u32)(4294967295));  // @84_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @85_42a820
  ecx = edx = 0;  // @86_42a820
  p7_ = esi;  // @87_42a820
  ecx = edi;  // @88_42a820
  eax = ext_42da80_stdcall1((u32)(p7_));  // @89_42a820
  ecx = edx = 0;  // @90_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @91_42a820
  L42a99a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_42a820
  edx = (u32)(EBP - 276);  // @94_42a820
  p8_ = edx;  // @95_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @97_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783676), (u32)(p8_));  // @98_42a820
  ecx = edx = 0;  // @99_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @100_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_42a820
  edx = (u32)(EBP - 276);  // @102_42a820
  p9_ = edx;  // @103_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @105_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783684), (u32)(p9_));  // @106_42a820
  ecx = edx = 0;  // @107_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @108_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_42a820
  edx = (u32)(EBP - 276);  // @110_42a820
  p10_ = edx;  // @111_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @113_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783696), (u32)(p10_));  // @114_42a820
  ecx = edx = 0;  // @115_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aa3b;  // @116_42a820
  L42a9f1:;
  ecx = (u32)(EBP - 144);  // @118_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @119_42a820
  ecx = edx = 0;  // @120_42a820
  eax = (u32)(EBP - 144);  // @121_42a820
  reg.state = (s32)((u32)(2));  // @122_42a820
  esi = (u32)(edi + 7025);  // @123_42a820
  p11_ = eax;  // @124_42a820
  ecx = esi;  // @125_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p11_));  // @126_42a820
  ecx = edx = 0;  // @127_42a820
  ecx = (u32)(EBP - 144);  // @128_42a820
  reg.state = (s32)((u32)(4294967295));  // @129_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @130_42a820
  ecx = edx = 0;  // @131_42a820
  p12_ = esi;  // @132_42a820
  ecx = edi;  // @133_42a820
  eax = ext_42da80_stdcall1((u32)(p12_));  // @134_42a820
  ecx = edx = 0;  // @135_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @136_42a820
  L42aa3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @138_42a820
  edx = (u32)(EBP - 276);  // @139_42a820
  p13_ = edx;  // @140_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @142_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783708), (u32)(p13_));  // @143_42a820
  ecx = edx = 0;  // @144_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aaa2;  // @145_42a820
  ecx = (u32)(EBP - 272);  // @146_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @147_42a820
  ecx = edx = 0;  // @148_42a820
  eax = (u32)(EBP - 272);  // @149_42a820
  reg.state = (s32)((u32)(3));  // @150_42a820
  esi = (u32)(edi + 7025);  // @151_42a820
  p14_ = eax;  // @152_42a820
  ecx = esi;  // @153_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p14_));  // @154_42a820
  ecx = edx = 0;  // @155_42a820
  ecx = (u32)(EBP - 272);  // @156_42a820
  reg.state = (s32)((u32)(4294967295));  // @157_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @158_42a820
  ecx = edx = 0;  // @159_42a820
  p15_ = esi;  // @160_42a820
  ecx = edi;  // @161_42a820
  eax = ext_42da80_stdcall1((u32)(p15_));  // @162_42a820
  ecx = edx = 0;  // @163_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @164_42a820
  L42aaa2:;
  SEH_LEAVE();  // @166_42a820
  ext_633654(G(u32, 0x6f5630));  // @167_42a820
  return eax;  // @168_42a820
}
PCREG(42a820, lifted_42a820);

extern "C" u32 THISCALL lifted_5fbe50(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5fbe50
  if ((ebx & ebx) == 0) goto L5fbf64;  // @1_5fbe50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5fbf64;  // @2_5fbe50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @3_5fbe50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 150), sizeof v); (u32)v; });  // @4_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @5_5fbe50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @6_5fbe50
  if (eax == esi) goto L5fbea0;  // @7_5fbe50
  L5fbe81:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @9_5fbe50
  ecx = (ecx + (u32)(60));  // @10_5fbe50
  if (edi == ecx) goto L5fbeb8;  // @11_5fbe50
  eax = (u32)(EBP - 8);  // @12_5fbe50
  p0_ = eax;  // @13_5fbe50
  ecx = (u32)(EBP + 8);  // @14_5fbe50
  eax = ext_5fb210_thiscall3(ecx, (u32)(p0_), (u32)(0));  // @15_5fbe50
  ecx = edx = 0;  // @16_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_5fbe50
  if (eax != esi) goto L5fbe81;  // @18_5fbe50
  L5fbea0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5fbe50
  if ((eax & eax) == 0) goto L5fbf61;  // @21_5fbe50
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5fbe50
  ecx = edx = 0;  // @23_5fbe50
  return eax;  // @24_5fbe50
  L5fbeb8:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @26_5fbe50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @27_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @28_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @29_5fbe50
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fbf62;  // @30_5fbe50
  ecx = eax;  // @31_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5fbe50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @34_5fbe50
  if ((edi & edi) == 0) goto L5fbf62;  // @35_5fbe50
  L5fbee3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_5fbe50
  eax = (eax + (u32)(-20));  // @38_5fbe50
  if (eax > (u32)(16)) goto L5fbf20;  // @39_5fbe50
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6274936), sizeof v); (u32)v; });  // @40_5fbe50
  switch (eax) { case 0: goto L5fbf2e; case 1: goto L5fbefb; case 2: goto L5fbf20; default: __builtin_trap(); }  // @41_5fbe50
  L5fbefb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @43_5fbe50
  edx = (u32)(EBP - 4);  // @44_5fbe50
  p1_ = edx;  // @45_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_5fbe50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @47_5fbe50
  ecx = edx = 0;  // @48_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @49_5fbe50
  eax = ext_5fa1e0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @50_5fbe50
  ecx = edx = 0;  // @51_5fbe50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @52_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @53_5fbe50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @54_5fbe50
  goto L5fbf2e;  // @55_5fbe50
  L5fbf20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_5fbe50
  if ((eax & eax) == 0) goto L5fbf2d;  // @58_5fbe50
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @59_5fbe50
  ecx = edx = 0;  // @60_5fbe50
  goto L5fbf2e;  // @61_5fbe50
  L5fbf2d:;
  __builtin_trap();  // @63_5fbe50
  L5fbf2e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @65_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @66_5fbe50
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L5fbf3f;  // @67_5fbe50
  eax = (u32)(ecx + 1);  // @68_5fbe50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @69_5fbe50
  L5fbf3f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @71_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @72_5fbe50
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fbf62;  // @73_5fbe50
  ecx = eax;  // @74_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @75_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @76_5fbe50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @77_5fbe50
  if ((edi & edi) != 0) goto L5fbee3;  // @78_5fbe50
  return eax;  // @79_5fbe50
  L5fbf61:;
  __builtin_trap();  // @81_5fbe50
  L5fbf62:;
  L5fbf64:;
  return eax;  // @84_5fbe50
}
PCREG(5fbe50, lifted_5fbe50);

extern "C" u32 THISCALL lifted_5fb770(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5fb770
  if ((ebx & ebx) == 0) goto L5fb888;  // @1_5fb770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5fb888;  // @2_5fb770
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @3_5fb770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 150), sizeof v); (u32)v; });  // @4_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @5_5fb770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @6_5fb770
  if (eax == esi) goto L5fb7bf;  // @7_5fb770
  L5fb7a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @9_5fb770
  ecx = (ecx + (u32)(60));  // @10_5fb770
  if (edi == ecx) goto L5fb7d7;  // @11_5fb770
  eax = (u32)(EBP - 4);  // @12_5fb770
  p0_ = eax;  // @13_5fb770
  ecx = (u32)(EBP + 8);  // @14_5fb770
  eax = ext_5fb210_thiscall3(ecx, (u32)(p0_), (u32)(0));  // @15_5fb770
  ecx = edx = 0;  // @16_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_5fb770
  if (eax != esi) goto L5fb7a0;  // @18_5fb770
  L5fb7bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5fb770
  if ((eax & eax) == 0) goto L5fb885;  // @21_5fb770
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5fb770
  ecx = edx = 0;  // @23_5fb770
  return eax;  // @24_5fb770
  L5fb7d7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @26_5fb770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @27_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @28_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @29_5fb770
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fb886;  // @30_5fb770
  ecx = eax;  // @31_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5fb770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @34_5fb770
  if ((edi & edi) == 0) goto L5fb886;  // @35_5fb770
  L5fb802:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_5fb770
  eax = (eax + (u32)(-20));  // @38_5fb770
  if (eax > (u32)(16)) goto L5fb844;  // @39_5fb770
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6273180), sizeof v); (u32)v; });  // @40_5fb770
  switch (eax) { case 0: goto L5fb852; case 1: goto L5fb81a; case 2: goto L5fb844; default: __builtin_trap(); }  // @41_5fb770
  L5fb81a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @43_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @44_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @45_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_5fb770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @47_5fb770
  ecx = edx = 0;  // @48_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @49_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @50_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @51_5fb770
  eax = ext_5f9db0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }));  // @52_5fb770
  ecx = edx = 0;  // @53_5fb770
  goto L5fb852;  // @54_5fb770
  L5fb844:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @56_5fb770
  if ((eax & eax) == 0) goto L5fb851;  // @57_5fb770
  eax = ((u32(STDCALL *)(void))(eax))();  // @58_5fb770
  ecx = edx = 0;  // @59_5fb770
  goto L5fb852;  // @60_5fb770
  L5fb851:;
  __builtin_trap();  // @62_5fb770
  L5fb852:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @64_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @65_5fb770
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L5fb863;  // @66_5fb770
  eax = (u32)(ecx + 1);  // @67_5fb770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @68_5fb770
  L5fb863:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @70_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @71_5fb770
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fb886;  // @72_5fb770
  ecx = eax;  // @73_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @74_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_5fb770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @76_5fb770
  if ((edi & edi) != 0) goto L5fb802;  // @77_5fb770
  return eax;  // @78_5fb770
  L5fb885:;
  __builtin_trap();  // @80_5fb770
  L5fb886:;
  L5fb888:;
  return eax;  // @83_5fb770
}
PCREG(5fb770, lifted_5fb770);

extern "C" u32 THISCALL lifted_5fda30(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5fda30
  if ((ebx & ebx) == 0) goto L5fdb3e;  // @1_5fda30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5fdb3e;  // @2_5fda30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @3_5fda30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 150), sizeof v); (u32)v; });  // @4_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @5_5fda30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @6_5fda30
  if (eax == esi) goto L5fda7f;  // @7_5fda30
  L5fda60:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @9_5fda30
  ecx = (ecx + (u32)(60));  // @10_5fda30
  if (edi == ecx) goto L5fda97;  // @11_5fda30
  eax = (u32)(EBP - 4);  // @12_5fda30
  p0_ = eax;  // @13_5fda30
  ecx = (u32)(EBP + 8);  // @14_5fda30
  eax = ext_5fb210_thiscall3(ecx, (u32)(p0_), (u32)(0));  // @15_5fda30
  ecx = edx = 0;  // @16_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_5fda30
  if (eax != esi) goto L5fda60;  // @18_5fda30
  L5fda7f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5fda30
  if ((eax & eax) == 0) goto L5fdb3b;  // @21_5fda30
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5fda30
  ecx = edx = 0;  // @23_5fda30
  return eax;  // @24_5fda30
  L5fda97:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @26_5fda30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @27_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @28_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @29_5fda30
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fdb3c;  // @30_5fda30
  ecx = eax;  // @31_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5fda30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @34_5fda30
  if ((edx & edx) == 0) goto L5fdb3c;  // @35_5fda30
  L5fdac0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @37_5fda30
  eax = (eax + (u32)(-20));  // @38_5fda30
  if (eax > (u32)(16)) goto L5fdafa;  // @39_5fda30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6282068), sizeof v); (u32)v; });  // @40_5fda30
  switch (eax) { case 0: goto L5fdb08; case 1: goto L5fdad8; case 2: goto L5fdafa; default: __builtin_trap(); }  // @41_5fda30
  L5fdad8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @43_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @44_5fda30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @45_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @46_5fda30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_5fda30
  eax = ext_5fa220_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }));  // @48_5fda30
  ecx = edx = 0;  // @49_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @50_5fda30
  p1_ = eax;  // @51_5fda30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 44)))(ecx, (u32)(p1_));  // @52_5fda30
  ecx = edx = 0;  // @53_5fda30
  goto L5fdb08;  // @54_5fda30
  L5fdafa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @56_5fda30
  if ((eax & eax) == 0) goto L5fdb07;  // @57_5fda30
  eax = ((u32(STDCALL *)(void))(eax))();  // @58_5fda30
  ecx = edx = 0;  // @59_5fda30
  goto L5fdb08;  // @60_5fda30
  L5fdb07:;
  __builtin_trap();  // @62_5fda30
  L5fdb08:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @64_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @65_5fda30
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L5fdb19;  // @66_5fda30
  eax = (u32)(ecx + 1);  // @67_5fda30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @68_5fda30
  L5fdb19:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @70_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @71_5fda30
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fdb3c;  // @72_5fda30
  ecx = eax;  // @73_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @74_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_5fda30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @76_5fda30
  if ((edx & edx) != 0) goto L5fdac0;  // @77_5fda30
  return eax;  // @78_5fda30
  L5fdb3b:;
  __builtin_trap();  // @80_5fda30
  L5fdb3c:;
  L5fdb3e:;
  return eax;  // @83_5fda30
}
PCREG(5fda30, lifted_5fda30);

extern "C" u32 THISCALL lifted_5c55a0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5c55a0
  eax = ext_5c5620_thiscall1(ecx);  // @1_5c55a0
  ecx = edx = 0;  // @2_5c55a0
  if ((eax & eax) == 0) goto L5c5605;  // @3_5c55a0
  ecx = ebx;  // @4_5c55a0
  eax = ext_5c5810_thiscall1(ecx);  // @5_5c55a0
  ecx = edx = 0;  // @6_5c55a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @7_5c55a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 332), sizeof v); (u32)v; });  // @8_5c55a0
  p0_ = eax;  // @9_5c55a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5c55a0
  p1_ = ecx;  // @11_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(p1_), (u32)(p0_), (u32)(0));  // @12_5c55a0
  ecx = edx = 0;  // @13_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @14_5c55a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @15_5c55a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_5c55a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6993692), (u32)(0), (u32)(7029252), (u32)(87), (u32)(0));  // @20_5c55a0
  ecx = edx = 0;  // @21_5c55a0
  eax = (eax & 0xffff);  // @22_5c55a0
  ecx = esi;  // @23_5c55a0
  p2_ = eax;  // @24_5c55a0
  p3_ = esi;  // @25_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 304)))(ecx, (u32)(p3_), (u32)(p2_));  // @26_5c55a0
  ecx = edx = 0;  // @27_5c55a0
  L5c5605:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_5c55a0
  ecx = ebx;  // @30_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @31_5c55a0
  ecx = edx = 0;  // @32_5c55a0
  return eax;  // @33_5c55a0
}
PCREG(5c55a0, lifted_5c55a0);

extern "C" u32 THISCALL lifted_41ed40(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_41ed40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @1_41ed40
  if ((ecx & ecx) == 0) goto L41edc7;  // @2_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_41ed40
  edx = (u32)(EBP - 12);  // @4_41ed40
  p0_ = edx;  // @5_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_41ed40
  ecx = edx = 0;  // @7_41ed40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @8_41ed40
  edx = (u32)(EBP - 12);  // @9_41ed40
  p1_ = edx;  // @10_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @12_41ed40
  ecx = edx = 0;  // @13_41ed40
  esi = eax;  // @14_41ed40
  if ((esi & esi) == 0) goto L41edb2;  // @15_41ed40
  L41ed70:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_41ed40
  if ((eax & eax) == 0) goto L41ed87;  // @18_41ed40
  p2_ = eax;  // @19_41ed40
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(1));  // @20_41ed40
  ecx = edx = 0;  // @21_41ed40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @22_41ed40
  L41ed87:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @24_41ed40
  if ((eax & eax) == 0) goto L41eda0;  // @25_41ed40
  p3_ = eax;  // @26_41ed40
  eax = ext_634273_cdecl2((u32)(p3_), (u32)(4));  // @27_41ed40
  ecx = edx = 0;  // @28_41ed40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @29_41ed40
  L41eda0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @31_41ed40
  edx = (u32)(EBP - 12);  // @32_41ed40
  p4_ = edx;  // @33_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @35_41ed40
  ecx = edx = 0;  // @36_41ed40
  esi = eax;  // @37_41ed40
  if ((esi & esi) != 0) goto L41ed70;  // @38_41ed40
  L41edb2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @40_41ed40
  if ((ecx & ecx) == 0) goto L41edc0;  // @41_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @43_41ed40
  ecx = edx = 0;  // @44_41ed40
  L41edc0:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @46_41ed40
  L41edc7:;
  return eax;  // @48_41ed40
}
PCREG(41ed40, lifted_41ed40);

extern "C" u32 THISCALL lifted_425310(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @1_425310
  if ((ecx & ecx) == 0) goto L42539e;  // @2_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_425310
  edx = (u32)(EBP - 12);  // @4_425310
  p0_ = edx;  // @5_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_425310
  ecx = edx = 0;  // @7_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @8_425310
  edx = (u32)(EBP - 12);  // @9_425310
  p1_ = edx;  // @10_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @12_425310
  ecx = edx = 0;  // @13_425310
  edi = eax;  // @14_425310
  if ((edi & edi) == 0) goto L425381;  // @15_425310
  L425340:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @17_425310
  if ((edx & edx) == 0) goto L42536f;  // @18_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @19_425310
  p2_ = edx;  // @20_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(p2_));  // @22_425310
  ecx = edx = 0;  // @23_425310
  if ((eax & eax) == 0) goto L425361;  // @24_425310
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 52), &v, sizeof v); }  // @25_425310
  L425361:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_425310
  ecx = esi;  // @28_425310
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(21), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }), (u32)(0));  // @29_425310
  ecx = edx = 0;  // @30_425310
  L42536f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @32_425310
  edx = (u32)(EBP - 12);  // @33_425310
  p3_ = edx;  // @34_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @36_425310
  ecx = edx = 0;  // @37_425310
  edi = eax;  // @38_425310
  if ((edi & edi) != 0) goto L425340;  // @39_425310
  L425381:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @41_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_425310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @43_425310
  ecx = edx = 0;  // @44_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @45_425310
  if ((ecx & ecx) == 0) goto L425397;  // @46_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @48_425310
  ecx = edx = 0;  // @49_425310
  L425397:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @51_425310
  L42539e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }) == (u32)(0)) goto L4253b5;  // @53_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_425310
  ecx = esi;  // @55_425310
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(22), (u32)(0), (u32)(0));  // @56_425310
  ecx = edx = 0;  // @57_425310
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @58_425310
  L4253b5:;
  return eax;  // @60_425310
}
PCREG(425310, lifted_425310);

extern "C" u32 THISCALL lifted_4a1710(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4a1710
  edi = ecx;  // @1_4a1710
  ecx = 0;  // @2_4a1710
  eax = (u32)(edi + 2052);  // @3_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_4a1710
  if ((s32)esi <= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4a1760;  // @5_4a1710
  L4a1730:;
  eax = (u32)(eax + 4);  // @7_4a1710
  ecx = (ecx + 1);  // @8_4a1710
  if ((s32)esi > (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4a1730;  // @9_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @10_4a1710
  if (ecx != (u32)(7)) goto L4a1753;  // @11_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2080), sizeof v); (u32)v; });  // @12_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @13_4a1710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @14_4a1710
  goto L4a180b;  // @15_4a1710
  L4a1753:;
  if ((s32)ecx >= (s32)(u32)(7)) goto L4a180b;  // @17_4a1710
  L4a1760:;
  if ((s32)esi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2080), sizeof v); (u32)v; })) goto L4a180b;  // @19_4a1710
  eax = 0;  // @20_4a1710
  L4a1770:;
  if ((eax & eax) == 0) goto L4a177e;  // @22_4a1710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 2048), sizeof v); (u32)v; });  // @23_4a1710
  ecx = (ecx + 1);  // @24_4a1710
  goto L4a1780;  // @25_4a1710
  L4a177e:;
  ecx = 0;  // @27_4a1710
  L4a1780:;
  if ((s32)esi < (s32)ecx) goto L4a178d;  // @29_4a1710
  if ((s32)esi <= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 2052), sizeof v); (u32)v; })) goto L4a17a3;  // @30_4a1710
  L4a178d:;
  eax = (eax + 1);  // @32_4a1710
  if ((s32)eax < (s32)(u32)(8)) goto L4a1770;  // @33_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @34_4a1710
  if ((eax & eax) == 0) goto L4a17a0;  // @35_4a1710
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @36_4a1710
  ecx = edx = 0;  // @37_4a1710
  goto L4a17a1;  // @38_4a1710
  L4a17a0:;
  __builtin_trap();  // @40_4a1710
  L4a17a1:;
  eax = 0;  // @42_4a1710
  L4a17a3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 2052), sizeof v); (u32)v; });  // @44_4a1710
  ebx = (u32)(edi + eax*4);  // @45_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @46_4a1710
  if (ecx == esi) goto L4a17c9;  // @47_4a1710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 4), sizeof v); (u32)v; });  // @48_4a1710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx*4 + 4), sizeof v); (u32)v; });  // @49_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @50_4a1710
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @51_4a1710
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @52_4a1710
  goto L4a17cc;  // @53_4a1710
  L4a17c9:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @55_4a1710
  L4a17cc:;
  edx = (u32)(eax - 1);  // @57_4a1710
  if ((s32)(edx & edx) <= 0) goto L4a17f5;  // @58_4a1710
  ecx = (u32)(edi + 2052);  // @59_4a1710
  ecx = (u32)(ecx + edx*4);  // @60_4a1710
  L4a17e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4a1710
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2052), sizeof v); (u32)v; })) goto L4a17f5;  // @63_4a1710
  eax = (eax - 1);  // @64_4a1710
  edx = (edx - 1);  // @65_4a1710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @66_4a1710
  ecx = (ecx - (u32)(4));  // @67_4a1710
  if ((s32)(edx & edx) > 0) goto L4a17e0;  // @68_4a1710
  L4a17f5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @70_4a1710
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2052), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(ebx + 2052), &v, sizeof v); }  // @71_4a1710
  ecx = (ecx + 1);  // @72_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @73_4a1710
  if ((s32)ecx < (s32)(u32)(7)) goto L4a1760;  // @74_4a1710
  L4a180b:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2080), sizeof v); (u32)v; });  // @76_4a1710
  edx = (u32)(edi + 2080);  // @77_4a1710
  if ((s32)esi >= (s32)ebx) goto L4a182b;  // @78_4a1710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 4), sizeof v); (u32)v; });  // @79_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*4 + 4), sizeof v); (u32)v; });  // @80_4a1710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @81_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + ebx*4 + 4), &v, sizeof v); }  // @82_4a1710
  L4a182b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @84_4a1710
  eax = edx;  // @85_4a1710
  L4a1832:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @87_4a1710
  eax = (eax - (u32)(4));  // @88_4a1710
  edx = eax;  // @89_4a1710
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == ecx) goto L4a1832;  // @90_4a1710
  return eax;  // @91_4a1710
}
PCREG(4a1710, lifted_4a1710);

extern "C" u32 THISCALL lifted_577550(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_577550
  esi = ecx;  // @1_577550
  p0_ = edi;  // @2_577550
  eax = ext_562c20_thiscall2(ecx, (u32)(p0_));  // @3_577550
  ecx = edx = 0;  // @4_577550
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L57756c;  // @5_577550
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @6_577550
  return eax;  // @7_577550
  L57756c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_577550
  edx = (u32)(EBP + 8);  // @10_577550
  p1_ = edx;  // @11_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_577550
  ebx = 0;  // @13_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @14_577550
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6976900), (u32)(p1_));  // @15_577550
  ecx = edx = 0;  // @16_577550
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L577597;  // @17_577550
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @18_577550
  ecx = edx = 0;  // @19_577550
  ebx = eax;  // @20_577550
  L577597:;
  eax = (u32)(ebx + ebx*4);  // @22_577550
  eax = (eax + eax);  // @23_577550
  if (edi < eax) goto L57778f;  // @24_577550
  edi = (edi + (u32)(-11));  // @25_577550
  if (edi > (u32)(71)) goto L57776f;  // @26_577550
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5732316), sizeof v); (u32)v; });  // @27_577550
  switch (eax) { case 0: goto L5775bf; case 1: goto L577754; case 2: goto L5775da; case 3: goto L577697; case 4: goto L5775f5; case 5: goto L5776b2; case 6: goto L577610; case 7: goto L5776cd; case 8: goto L57762b; case 9: goto L5776e8; case 10: goto L577646; case 11: goto L577703; case 12: goto L577661; case 13: goto L57771e; case 14: goto L57767c; case 15: goto L577739; case 16: goto L57776f; default: __builtin_trap(); }  // @28_577550
  L5775bf:;
  ecx = esi;  // @30_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981620));  // @31_577550
  ecx = edx = 0;  // @32_577550
  ecx = esi;  // @33_577550
  eax = ext_563500_cdecl0();  // @34_577550
  ecx = edx = 0;  // @35_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @36_577550
  return eax;  // @37_577550
  L5775da:;
  ecx = esi;  // @39_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981564));  // @40_577550
  ecx = edx = 0;  // @41_577550
  ecx = esi;  // @42_577550
  eax = ext_563500_cdecl0();  // @43_577550
  ecx = edx = 0;  // @44_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @45_577550
  return eax;  // @46_577550
  L5775f5:;
  ecx = esi;  // @48_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981572));  // @49_577550
  ecx = edx = 0;  // @50_577550
  ecx = esi;  // @51_577550
  eax = ext_563500_cdecl0();  // @52_577550
  ecx = edx = 0;  // @53_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @54_577550
  return eax;  // @55_577550
  L577610:;
  ecx = esi;  // @57_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981580));  // @58_577550
  ecx = edx = 0;  // @59_577550
  ecx = esi;  // @60_577550
  eax = ext_563500_cdecl0();  // @61_577550
  ecx = edx = 0;  // @62_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @63_577550
  return eax;  // @64_577550
  L57762b:;
  ecx = esi;  // @66_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981588));  // @67_577550
  ecx = edx = 0;  // @68_577550
  ecx = esi;  // @69_577550
  eax = ext_563500_cdecl0();  // @70_577550
  ecx = edx = 0;  // @71_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @72_577550
  return eax;  // @73_577550
  L577646:;
  ecx = esi;  // @75_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981604));  // @76_577550
  ecx = edx = 0;  // @77_577550
  ecx = esi;  // @78_577550
  eax = ext_563500_cdecl0();  // @79_577550
  ecx = edx = 0;  // @80_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @81_577550
  return eax;  // @82_577550
  L577661:;
  ecx = esi;  // @84_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981612));  // @85_577550
  ecx = edx = 0;  // @86_577550
  ecx = esi;  // @87_577550
  eax = ext_563500_cdecl0();  // @88_577550
  ecx = edx = 0;  // @89_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @90_577550
  return eax;  // @91_577550
  L57767c:;
  ecx = esi;  // @93_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6984788));  // @94_577550
  ecx = edx = 0;  // @95_577550
  ecx = esi;  // @96_577550
  eax = ext_563500_cdecl0();  // @97_577550
  ecx = edx = 0;  // @98_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @99_577550
  return eax;  // @100_577550
  L577697:;
  ecx = esi;  // @102_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985408));  // @103_577550
  ecx = edx = 0;  // @104_577550
  ecx = esi;  // @105_577550
  eax = ext_563500_cdecl0();  // @106_577550
  ecx = edx = 0;  // @107_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @108_577550
  return eax;  // @109_577550
  L5776b2:;
  ecx = esi;  // @111_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985416));  // @112_577550
  ecx = edx = 0;  // @113_577550
  ecx = esi;  // @114_577550
  eax = ext_563500_cdecl0();  // @115_577550
  ecx = edx = 0;  // @116_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @117_577550
  return eax;  // @118_577550
  L5776cd:;
  ecx = esi;  // @120_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985424));  // @121_577550
  ecx = edx = 0;  // @122_577550
  ecx = esi;  // @123_577550
  eax = ext_563500_cdecl0();  // @124_577550
  ecx = edx = 0;  // @125_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @126_577550
  return eax;  // @127_577550
  L5776e8:;
  ecx = esi;  // @129_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985432));  // @130_577550
  ecx = edx = 0;  // @131_577550
  ecx = esi;  // @132_577550
  eax = ext_563500_cdecl0();  // @133_577550
  ecx = edx = 0;  // @134_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @135_577550
  return eax;  // @136_577550
  L577703:;
  ecx = esi;  // @138_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981596));  // @139_577550
  ecx = edx = 0;  // @140_577550
  ecx = esi;  // @141_577550
  eax = ext_563500_cdecl0();  // @142_577550
  ecx = edx = 0;  // @143_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @144_577550
  return eax;  // @145_577550
  L57771e:;
  ecx = esi;  // @147_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985440));  // @148_577550
  ecx = edx = 0;  // @149_577550
  ecx = esi;  // @150_577550
  eax = ext_563500_cdecl0();  // @151_577550
  ecx = edx = 0;  // @152_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @153_577550
  return eax;  // @154_577550
  L577739:;
  ecx = esi;  // @156_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985448));  // @157_577550
  ecx = edx = 0;  // @158_577550
  ecx = esi;  // @159_577550
  eax = ext_563500_cdecl0();  // @160_577550
  ecx = edx = 0;  // @161_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @162_577550
  return eax;  // @163_577550
  L577754:;
  ecx = esi;  // @165_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6980864));  // @166_577550
  ecx = edx = 0;  // @167_577550
  ecx = esi;  // @168_577550
  eax = ext_563500_cdecl0();  // @169_577550
  ecx = edx = 0;  // @170_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @171_577550
  return eax;  // @172_577550
  L57776f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @174_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_577550
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6985456), (u32)(97));  // @176_577550
  ecx = edx = 0;  // @177_577550
  p2_ = eax;  // @178_577550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @179_577550
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p2_), (u32)(6985504));  // @180_577550
  ecx = edx = 0;  // @181_577550
  L57778f:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @183_577550
  return eax;  // @184_577550
}
PCREG(577550, lifted_577550);

