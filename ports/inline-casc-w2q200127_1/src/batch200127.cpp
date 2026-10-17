// batch200127.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double THISCALL ext_4e5e80_thiscall1_f(u32) __asm__("ext_4e5e80");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4cd9b0_fastcall4(u32, u32, u32, u32) __asm__("ext_4cd9b0");
extern "C" u32 FASTCALL ext_4dfd10_fastcall2(u32, u32) __asm__("ext_4dfd10");
extern "C" u32 STDCALL ext_41f190_stdcall1(u32) __asm__("ext_41f190");
extern "C" u32 STDCALL ext_42da80_stdcall1(u32) __asm__("ext_42da80");
extern "C" u32 STDCALL ext_43eb80_stdcall1(u32) __asm__("ext_43eb80");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_62f5d0_stdcall2(u32, u32) __asm__("ext_62f5d0");
extern "C" u32 STDCALL ext_62f980_stdcall1(u32) __asm__("ext_62f980");
extern "C" u32 STDCALL ext_62f9d0_stdcall4(u32, u32, u32, u32) __asm__("ext_62f9d0");
extern "C" u32 STDCALL ext_658c40_stdcall2(u32, u32) __asm__("ext_658c40");
extern "C" u32 STDCALL ext_661b40_stdcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_661b40");
extern "C" u32 THISCALL ext_41e680_thiscall1(u32) __asm__("ext_41e680");
extern "C" u32 THISCALL ext_42de30_thiscall1(u32) __asm__("ext_42de30");
extern "C" u32 THISCALL ext_433f30_thiscall1(u32) __asm__("ext_433f30");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_43de40_thiscall4(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_448a30_thiscall2(u32, u32) __asm__("ext_448a30");
extern "C" u32 THISCALL ext_45c3e0_thiscall1(u32) __asm__("ext_45c3e0");
extern "C" u32 THISCALL ext_460f90_thiscall1(u32) __asm__("ext_460f90");
extern "C" u32 THISCALL ext_48cf50_thiscall1(u32) __asm__("ext_48cf50");
extern "C" u32 THISCALL ext_493820_thiscall4(u32, u32, u32, u32) __asm__("ext_493820");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4cdcc0_thiscall1(u32) __asm__("ext_4cdcc0");
extern "C" u32 THISCALL ext_4cfbe0_thiscall1(u32) __asm__("ext_4cfbe0");
extern "C" u32 THISCALL ext_4d0f30_thiscall4(u32, u32, u32, u32) __asm__("ext_4d0f30");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4dbb00_thiscall2(u32, u32) __asm__("ext_4dbb00");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6780_thiscall2(u32, u32) __asm__("ext_4e6780");
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
extern "C" u32 THISCALL ext_57ee90_thiscall1(u32) __asm__("ext_57ee90");
extern "C" u32 THISCALL ext_582880_thiscall4(u32, u32, u32, u32) __asm__("ext_582880");
extern "C" u32 THISCALL ext_584a20_thiscall3(u32, u32, u32) __asm__("ext_584a20");
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
extern "C" u32 THISCALL ext_5f9db0_thiscall2(u32, u32) __asm__("ext_5f9db0");
extern "C" u32 THISCALL ext_5fa1e0_thiscall2(u32, u32) __asm__("ext_5fa1e0");
extern "C" u32 THISCALL ext_5fa220_thiscall2(u32, u32) __asm__("ext_5fa220");
extern "C" u32 THISCALL ext_5fb210_thiscall3(u32, u32, u32) __asm__("ext_5fb210");
extern "C" u32 THISCALL ext_601380_thiscall1(u32) __asm__("ext_601380");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 THISCALL ext_644900_thiscall2(u32, u32) __asm__("ext_644900");
extern "C" u32 THISCALL ext_647f70_thiscall1(u32) __asm__("ext_647f70");
extern "C" u32 THISCALL ext_648dd0_thiscall1(u32) __asm__("ext_648dd0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_563500_cdecl0(void) __asm__("ext_563500");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl2(...) __asm__("ext_634d22");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4264b0(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4264b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_4b8bf0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66bdd6);  // @h_4b8bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_452bc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666326);  // @h_452bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_5898c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_5898c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_438c60(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_45fd50(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_53b1b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_492880(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667e27);  // @h_492880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_57cb40(u32 ecx_in) {
  SEH_ENTER(0x66b22b);  // @h_57cb40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_4d7610(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_4afc70(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4afc70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_4356e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_4356e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_42a820(u32 ecx_in) {
  SEH_ENTER(0x66496c);  // @h_42a820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 THISCALL lifted_64ea30(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64ea30
  edi = ecx;  // @1_64ea30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_64ea30
  ebx = (u32)(edi + 98845);  // @3_64ea30
  ecx = (u32)(edi + 98809);  // @4_64ea30
  p0_ = ebx;  // @5_64ea30
  p1_ = ecx;  // @6_64ea30
  ecx = esi;  // @7_64ea30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, (u32)(p1_), (u32)(p0_));  // @8_64ea30
  ecx = edx = 0;  // @9_64ea30
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }) & (u32)(65536)) != 0) goto L64ea96;  // @10_64ea30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_64ea30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_64ea30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @13_64ea30
  ecx = edx = 0;  // @14_64ea30
  ecx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(edi + 98853)));  // @15_64ea30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_64ea30
  p2_ = ecx;  // @17_64ea30
  ecx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(edi + 98849)));  // @18_64ea30
  p3_ = ecx;  // @19_64ea30
  ecx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(ebx)));  // @20_64ea30
  p4_ = ecx;  // @21_64ea30
  p5_ = eax;  // @22_64ea30
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 388)))((u32)(p5_), (u32)(93), (u32)(0), (u32)(7089780), (u32)(p4_), (u32)(p3_), (u32)(p2_));  // @23_64ea30
  ecx = edx = 0;  // @24_64ea30
  L64ea96:;
  esi = (u32)(edi + 98857);  // @26_64ea30
  edx = (u32)(edi + 98809);  // @27_64ea30
  ecx = esi;  // @28_64ea30
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @29_64ea30
  ecx = edx = 0;  // @30_64ea30
  p6_ = esi;  // @31_64ea30
  edx = ebx;  // @32_64ea30
  ecx = (u32)(edi + 98893);  // @33_64ea30
  eax = ext_441970_fastcall3(ecx, edx, (u32)(p6_));  // @34_64ea30
  ecx = edx = 0;  // @35_64ea30
  ecx = (u32)(edi + 98893);  // @36_64ea30
  eax = ext_4e09b0_thiscall1(ecx);  // @37_64ea30
  ecx = edx = 0;  // @38_64ea30
  __asm__ volatile("" :: "Yz"(x0));  // @39_64ea30
  return eax;  // @40_64ea30
}
PCREG(64ea30, lifted_64ea30);

extern "C" u32 FASTCALL lifted_633c60(u32 ecx_in, u32 edx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  x1 = _mm_setzero_ps();  // @0_633c60
  x1 = _mm_castpd_ps(_mm_cvtsi32_sd(_mm_castps_pd(x1), (int)edx));  // @1_633c60
  x0 = _mm_setzero_ps();  // @2_633c60
  x0 = _mm_castpd_ps(_mm_cvtsi32_sd(_mm_castps_pd(x0), (int)ecx));  // @3_633c60
  ecx = (ecx >> (u32)(31));  // @4_633c60
  x1 = _mm_castpd_ps(_mm_mul_sd(_mm_castps_pd(x1), _mm_load_sd((const double *)(u32)(7083544))));  // @5_633c60
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(ecx*8 + 7083536))));  // @6_633c60
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_castps_pd(x1)));  // @7_633c60
  __asm__ volatile("" :: "Yz"(x0));  // @8_633c60
  return eax;  // @9_633c60
}
PCREG(633c60, lifted_633c60);

extern "C" u32 THISCALL lifted_495950(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @0_495950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_495950
  eax = (eax + (u32)(7));  // @2_495950
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_495950
  eax = (eax & (u32)(4294967288));  // @4_495950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @5_495950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @6_495950
  edi = edx;  // @7_495950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @8_495950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @9_495950
  ebx = (ebx | eax);  // @10_495950
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }) | eax)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @11_495950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @12_495950
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @13_495950
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @14_495950
  if ((edx & edx) == 0) goto L4959f7;  // @15_495950
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) <= (u32)(1)) goto L4959f7;  // @16_495950
  esi = edx;  // @17_495950
  L495990:;
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @19_495950
  eax = (u32)(esi + 12);  // @20_495950
  ecx = (ecx + (u32)(3));  // @21_495950
  edi = (u32)(esi + ecx*4);  // @22_495950
  ecx = 0;  // @23_495950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @24_495950
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4959b0;  // @25_495950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_495950
  eax = (eax + (u32)(4));  // @27_495950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @28_495950
  L4959b0:;
  if (eax == edi) goto L4959eb;  // @30_495950
  L4959b4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_495950
  ecx = edx;  // @33_495950
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @34_495950
  ecx = (ecx & (u32)(7));  // @35_495950
  eax = (eax + (u32)(8));  // @36_495950
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; })) goto L4959e7;  // @37_495950
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @38_495950
  ecx = edx;  // @39_495950
  ecx = (ecx & (u32)(4294967288));  // @40_495950
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @41_495950
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 80), sizeof v); (u32)v; }) != ebx) goto L4959e7;  // @42_495950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @43_495950
  ecx = (ecx + (u32)(112));  // @44_495950
  if (ecx == edx) goto L495a41;  // @45_495950
  ecx = (u32)(ebx - 112);  // @46_495950
  if (ecx == esi) goto L495a2f;  // @47_495950
  L4959e7:;
  if (eax != edi) goto L4959b4;  // @49_495950
  L4959eb:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @51_495950
  if ((esi & esi) != 0) goto L495990;  // @52_495950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @53_495950
  edi = edx;  // @54_495950
  L4959f7:;
  esi = edx;  // @56_495950
  if ((edx & edx) == 0) goto L495a6b;  // @57_495950
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 9), sizeof v); (u32)v; });  // @58_495950
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @59_495950
  ecx = (ecx - eax);  // @60_495950
  if ((s32)ecx >= (s32)(u32)(2)) goto L495a58;  // @61_495950
  L495a10:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; })) & 0xff);  // @63_495950
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 9), sizeof v); (u32)v; });  // @64_495950
  eax = (ebx & 0xff);  // @65_495950
  ecx = (ecx - eax);  // @66_495950
  if ((s32)ecx >= (s32)(u32)(2)) goto L495a50;  // @67_495950
  if (((ebx & 0xff) & (u32)(1)) == 0) goto L495a55;  // @68_495950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @69_495950
  if ((edx & edx) != 0) goto L495a10;  // @70_495950
  goto L495a55;  // @71_495950
  L495a2f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @73_495950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @74_495950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @75_495950
  return eax;  // @76_495950
  L495a41:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax - 8), &v, sizeof v); }  // @78_495950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @79_495950
  return eax;  // @80_495950
  L495a50:;
  edi = edx;  // @82_495950
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @83_495950
  L495a55:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @85_495950
  L495a58:;
  if ((edi & edi) == 0) goto L495a6b;  // @87_495950
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; });  // @88_495950
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @89_495950
  ecx = (ecx - eax);  // @90_495950
  if ((s32)ecx >= (s32)(u32)(2)) goto L495aca;  // @91_495950
  L495a6b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @93_495950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @94_495950
  esi = (u32)(esi*4 + 24);  // @95_495950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_495950
  esi = (esi & (u32)(4294967280));  // @97_495950
  p0_ = esi;  // @98_495950
  eax = ext_4cd9b0_fastcall4(ecx, edx, (u32)(p0_), (u32)(1));  // @99_495950
  ecx = edx = 0;  // @100_495950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @101_495950
  edi = eax;  // @102_495950
  if ((ecx & ecx) == 0) goto L495a9d;  // @103_495950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_495950
  p1_ = esi;  // @105_495950
  p2_ = edi;  // @106_495950
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(6874312), (u32)(p2_), (u32)(p1_));  // @107_495950
  ecx = edx = 0;  // @108_495950
  L495a9d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @110_495950
  x0 = _mm_setzero_ps();  // @111_495950
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @112_495950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @113_495950
  esi = (esi + edi);  // @114_495950
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @115_495950
  _mm_storel_epi64((__m128i *)(u32)(esi), _mm_castps_si128(x0));  // @116_495950
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }) == (u32)(0)) goto L495ac4;  // @117_495950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @118_495950
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @119_495950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @120_495950
  goto L495ac8;  // @121_495950
  L495ac4:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @123_495950
  L495ac8:;
  edi = esi;  // @125_495950
  L495aca:;
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @127_495950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @128_495950
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + ecx*4 + 12), &v, sizeof v); }  // @129_495950
  ebx = (ebx & (u32)(7));  // @130_495950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx*4 + 16), &v, sizeof v); }  // @131_495950
  eax = esi;  // @132_495950
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @133_495950
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + edi), &v, sizeof v); }  // @134_495950
  __asm__ volatile("" :: "Yz"(x0));  // @135_495950
  return eax;  // @136_495950
}
PCREG(495950, lifted_495950);

extern "C" u32 lifted_6309a0(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6309a0
  x0 = _mm_setzero_ps();  // @1_6309a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @3_6309a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4_6309a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @5_6309a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_6309a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @7_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @9_6309a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @10_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @11_6309a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @12_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @13_6309a0
  _mm_storeu_ps((float *)(u32)(edx + 2868), x0);  // @14_6309a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @15_6309a0
  ecx = 0;  // @16_6309a0
  _mm_storeu_ps((float *)(u32)(edx + 2884), x0);  // @17_6309a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5196), sizeof v); (u32)v; });  // @18_6309a0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @19_6309a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @20_6309a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4 + 2900), sizeof v); (u32)v; });  // @21_6309a0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 2), &v, sizeof v); }  // @22_6309a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5196), sizeof v); (u32)v; });  // @23_6309a0
  edi = (edi + 1);  // @24_6309a0
  if ((s32)edi >= (s32)(u32)(573)) goto L630ba4;  // @25_6309a0
  eax = (u32)(573);  // @26_6309a0
  ecx = (u32)(edx + 2900);  // @27_6309a0
  eax = (eax - edi);  // @28_6309a0
  ecx = (u32)(ecx + edi*4);  // @29_6309a0
  edi = (edi + eax);  // @30_6309a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @31_6309a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @32_6309a0
  edi = 0;  // @33_6309a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @34_6309a0
  L630a30:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @37_6309a0
  eax = (u32)(esi*4);  // @38_6309a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @39_6309a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 2), sizeof v); (u32)v; });  // @40_6309a0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4 + 2), sizeof v); (u32)v; });  // @41_6309a0
  ecx = (ecx + 1);  // @42_6309a0
  if ((s32)ecx <= (s32)ebx) goto L630a54;  // @43_6309a0
  edi = (edi + 1);  // @44_6309a0
  ecx = ebx;  // @45_6309a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @46_6309a0
  L630a54:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @48_6309a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @49_6309a0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + ebx + 2), &v, sizeof v); }  // @50_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @51_6309a0
  if ((s32)esi > (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; })) goto L630abf;  // @52_6309a0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*2 + 2868), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + ecx*2 + 2868), &v, sizeof v); }  // @53_6309a0
  if ((s32)esi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; })) goto L630a82;  // @54_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @55_6309a0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @56_6309a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi*4), sizeof v); (u32)v; });  // @57_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @58_6309a0
  goto L630a84;  // @59_6309a0
  L630a82:;
  esi = 0;  // @61_6309a0
  L630a84:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @63_6309a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi), sizeof v); (u32)v; });  // @64_6309a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @65_6309a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @66_6309a0
  eax = (u32)(esi + ecx);  // @67_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @68_6309a0
  eax = (u32)((s32)eax * (s32)ecx);  // @69_6309a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5792), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 5792), &v, sizeof v); }  // @70_6309a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }) == (u32)(0)) goto L630abf;  // @71_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @72_6309a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @73_6309a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 2), sizeof v); (u32)v; });  // @74_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @75_6309a0
  eax = (eax + esi);  // @76_6309a0
  eax = (u32)((s32)eax * (s32)ecx);  // @77_6309a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5796), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 5796), &v, sizeof v); }  // @78_6309a0
  L630abf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @80_6309a0
  ecx = (ecx + (u32)(4));  // @81_6309a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @82_6309a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @83_6309a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }) != 0) goto L630a30;  // @84_6309a0
  if ((edi & edi) == 0) goto L630ba4;  // @85_6309a0
  edi = (u32)(ebx - 1);  // @86_6309a0
  ebx = (ebx + (u32)(1434));  // @87_6309a0
  esi = (u32)(edx + ebx*2);  // @88_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @89_6309a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @90_6309a0
  L630af0:;
  ecx = edi;  // @92_6309a0
  eax = (u32)(edx + 2868);  // @93_6309a0
  eax = (u32)(eax + ecx*2);  // @94_6309a0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*2), sizeof v); (u32)v; }) != (u32)(0)) goto L630b0c;  // @95_6309a0
  L630b02:;
  eax = (u32)(eax - 2);  // @97_6309a0
  ecx = (ecx - 1);  // @98_6309a0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L630b02;  // @99_6309a0
  L630b0c:;
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*2 + 2870), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edx + ecx*2 + 2870), &v, sizeof v); }  // @101_6309a0
  eax = (u32)(65535);  // @102_6309a0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*2 + 2868), sizeof v); (u32)v; }) + (eax & 0xffff))); __builtin_memcpy((void *)(u32)(edx + ecx*2 + 2868), &v, sizeof v); }  // @103_6309a0
  ebx = (ebx - (u32)(2));  // @104_6309a0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + (eax & 0xffff))); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @105_6309a0
  if ((s32)(ebx & ebx) > 0) goto L630af0;  // @106_6309a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @107_6309a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @108_6309a0
  if ((ebx & ebx) == 0) goto L630ba4;  // @109_6309a0
  L630b36:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_6309a0
  if ((eax & eax) == 0) goto L630b99;  // @112_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @113_6309a0
  esi = (u32)(edi + 725);  // @114_6309a0
  esi = (u32)(edx + esi*4);  // @115_6309a0
  L630b50:;
  edi = (edi - 1);  // @117_6309a0
  esi = (u32)(esi - 4);  // @118_6309a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @119_6309a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_6309a0
  if ((s32)edi > (s32)ecx) goto L630b8c;  // @121_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @122_6309a0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*4 + 2), sizeof v); (u32)v; });  // @123_6309a0
  if (ecx == ebx) goto L630b88;  // @124_6309a0
  edx = ebx;  // @125_6309a0
  edx = (edx - ecx);  // @126_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @127_6309a0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*4), sizeof v); (u32)v; });  // @128_6309a0
  edx = (u32)((s32)edx * (s32)ecx);  // @129_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @130_6309a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5792), sizeof v); (u32)v; }) + edx)); __builtin_memcpy((void *)(u32)(ecx + 5792), &v, sizeof v); }  // @131_6309a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @132_6309a0
  { u16 v = (u16)((ebx & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + edi*4 + 2), &v, sizeof v); }  // @133_6309a0
  L630b88:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @135_6309a0
  eax = (eax - 1);  // @136_6309a0
  L630b8c:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @138_6309a0
  if ((eax & eax) != 0) goto L630b50;  // @139_6309a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @140_6309a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @141_6309a0
  L630b99:;
  esi = (esi - (u32)(2));  // @143_6309a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @144_6309a0
  ebx = (ebx - (u32)(1));  // @145_6309a0
  if (ebx != 0) goto L630b36;  // @146_6309a0
  L630ba4:;
  __asm__ volatile("" :: "Yz"(x0));  // @148_6309a0
  return eax;  // @149_6309a0
}
PCREG(6309a0, lifted_6309a0);

extern "C" u32 THISCALL lifted_522250(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_522250
  edi = ecx;  // @1_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @2_522250
  if ((ecx & ecx) == 0) goto L522516;  // @3_522250
  x0 = _mm_load_ss((const float *)(u32)(edi + 881));  // @4_522250
  x1 = _mm_setzero_ps();  // @5_522250
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @6_522250
  if (!(fa_ > fb_)) goto L5222a7;  // @7_522250
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9962), sizeof v); (u32)v; }) != (u32)(0)) goto L5222c9;  // @8_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_522250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_522250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; }), (u32)(6940152));  // @11_522250
  ecx = edx = 0;  // @12_522250
  p0_ = eax;  // @13_522250
  ecx = edi;  // @14_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, (u32)(p0_));  // @15_522250
  ecx = edx = 0;  // @16_522250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 9962), &v, sizeof v); }  // @17_522250
  goto L5222c6;  // @18_522250
  L5222a7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9962), sizeof v); (u32)v; });  // @20_522250
  if ((ecx & ecx) == 0) goto L5222c9;  // @21_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_522250
  p1_ = ecx;  // @23_522250
  ecx = edi;  // @24_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, (u32)(p1_));  // @25_522250
  ecx = edx = 0;  // @26_522250
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9962), &v, sizeof v); }  // @27_522250
  L5222c6:;
  x1 = _mm_setzero_ps();  // @29_522250
  L5222c9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @31_522250
  x0 = _mm_load_ss((const float *)(u32)(eax + 40));  // @32_522250
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @33_522250
  if (!(fa_ >= fb_)) goto L5222dd;  // @34_522250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 9990), &v, sizeof v); }  // @35_522250
  L5222dd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9990), sizeof v); (u32)v; }) == (u32)(0)) goto L522515;  // @37_522250
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6818436)));  // @38_522250
  if (!(fa_ > fb_)) goto L5223f4;  // @39_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_522250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @42_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_522250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; }), (u32)(6942992));  // @44_522250
  ecx = edx = 0;  // @45_522250
  p2_ = eax;  // @46_522250
  ecx = edi;  // @47_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, (u32)(p2_));  // @48_522250
  ecx = edx = 0;  // @49_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_522250
  p3_ = eax;  // @51_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @52_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(p3_));  // @54_522250
  ecx = edx = 0;  // @55_522250
  edx = eax;  // @56_522250
  if ((edx & edx) == 0) goto L52235c;  // @57_522250
  x0 = _mm_load_ss((const float *)(u32)(edi + 481));  // @58_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @59_522250
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6792876)));  // @60_522250
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 36)));  // @61_522250
  ecx = (u32)_mm_cvtss_si32(x0);  // @62_522250
  eax = ecx;  // @63_522250
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 100), sizeof v); (u32)v; }));  // @64_522250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 96), &v, sizeof v); }  // @65_522250
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 100), &v, sizeof v); }  // @66_522250
  L52235c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @70_522250
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6948008), (u32)(887));  // @71_522250
  ecx = edx = 0;  // @72_522250
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @73_522250
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @74_522250
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6792876)));  // @75_522250
  if (!(fa_ > fb_)) goto L52250e;  // @76_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_522250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @79_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_522250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; }), (u32)(6943012));  // @81_522250
  ecx = edx = 0;  // @82_522250
  p4_ = eax;  // @83_522250
  ecx = edi;  // @84_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, (u32)(p4_));  // @85_522250
  ecx = edx = 0;  // @86_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @87_522250
  p5_ = eax;  // @88_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @89_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(p5_));  // @91_522250
  ecx = edx = 0;  // @92_522250
  esi = eax;  // @93_522250
  if ((esi & esi) == 0) goto L52250e;  // @94_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 448), sizeof v); (u32)v; });  // @97_522250
  T[0] = ((double(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6948008), (u32)(892));  // @98_522250
  ecx = edx = 0;  // @99_522250
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @100_522250
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @101_522250
  goto L5224f1;  // @102_522250
  L5223f4:;
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6836848)));  // @104_522250
  if (!(fa_ > fb_)) goto L522515;  // @105_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_522250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @107_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @108_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_522250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; }), (u32)(6943020));  // @110_522250
  ecx = edx = 0;  // @111_522250
  p6_ = eax;  // @112_522250
  ecx = edi;  // @113_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, (u32)(p6_));  // @114_522250
  ecx = edx = 0;  // @115_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_522250
  p7_ = eax;  // @117_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @118_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(p7_));  // @120_522250
  ecx = edx = 0;  // @121_522250
  edx = eax;  // @122_522250
  if ((edx & edx) == 0) goto L522466;  // @123_522250
  x0 = _mm_load_ss((const float *)(u32)(edi + 481));  // @124_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @125_522250
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6792876)));  // @126_522250
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 36)));  // @127_522250
  ecx = (u32)_mm_cvtss_si32(x0);  // @128_522250
  eax = ecx;  // @129_522250
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 100), sizeof v); (u32)v; }));  // @130_522250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 96), &v, sizeof v); }  // @131_522250
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 100), &v, sizeof v); }  // @132_522250
  L522466:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @136_522250
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6948008), (u32)(905));  // @137_522250
  ecx = edx = 0;  // @138_522250
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @139_522250
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @140_522250
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6792876)));  // @141_522250
  if (!(fa_ > fb_)) goto L52250e;  // @142_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_522250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @144_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @145_522250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_522250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; }), (u32)(6943012));  // @147_522250
  ecx = edx = 0;  // @148_522250
  p8_ = eax;  // @149_522250
  ecx = edi;  // @150_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, (u32)(p8_));  // @151_522250
  ecx = edx = 0;  // @152_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @153_522250
  p9_ = eax;  // @154_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @155_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @156_522250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(p9_));  // @157_522250
  ecx = edx = 0;  // @158_522250
  esi = eax;  // @159_522250
  if ((esi & esi) == 0) goto L52250e;  // @160_522250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @161_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_522250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 448), sizeof v); (u32)v; });  // @163_522250
  T[0] = ((double(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6948008), (u32)(910));  // @164_522250
  ecx = edx = 0;  // @165_522250
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @166_522250
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @167_522250
  L5224f1:;
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6803812)));  // @169_522250
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(6818448)));  // @170_522250
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6806012)));  // @171_522250
  _mm_store_ss((float *)(u32)(esi + 120), x0);  // @172_522250
  L52250e:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9990), &v, sizeof v); }  // @174_522250
  L522515:;
  L522516:;
  __asm__ volatile("" :: "Yz"(x0));  // @177_522250
  return eax;  // @178_522250
}
PCREG(522250, lifted_522250);

extern "C" u32 THISCALL lifted_582160(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_582160
  esi = ecx;  // @1_582160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 862), sizeof v); (u32)v; }));  // @4_582160
  ecx = edx = 0;  // @5_582160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_582160
  edi = eax;  // @7_582160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 866), sizeof v); (u32)v; }));  // @10_582160
  ecx = edx = 0;  // @11_582160
  ebx = eax;  // @12_582160
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xffff);  // @13_582160
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; })) goto L582217;  // @14_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_582160
  ecx = esi;  // @16_582160
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @17_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 100)))(ecx, (u32)(16));  // @18_582160
  ecx = edx = 0;  // @19_582160
  edx = (u32)(esi + 141);  // @20_582160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 153), &v, sizeof v); }  // @21_582160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @22_582160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @23_582160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @24_582160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @25_582160
  p0_ = edx;  // @26_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p0_));  // @28_582160
  ecx = edx = 0;  // @29_582160
  if ((edi & edi) == 0) goto L5821f3;  // @30_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @31_582160
  ecx = edi;  // @32_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @33_582160
  ecx = edx = 0;  // @34_582160
  L5821f3:;
  if ((ebx & ebx) == 0) goto L582462;  // @36_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_582160
  ecx = ebx;  // @38_582160
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @39_582160
  p1_ = eax;  // @40_582160
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(p1_), (u32)(0), (u32)(0));  // @41_582160
  ecx = edx = 0;  // @42_582160
  eax = 0;  // @43_582160
  return eax;  // @44_582160
  L582217:;
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 86), sizeof v); (u32)v; })) goto L582462;  // @46_582160
  if ((edi & edi) == 0) goto L582231;  // @47_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_582160
  ecx = edi;  // @49_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @50_582160
  ecx = edx = 0;  // @51_582160
  L582231:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @53_582160
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @54_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_582160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @56_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; }));  // @58_582160
  ecx = edx = 0;  // @59_582160
  ecx = esi;  // @60_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @61_582160
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(2)) != 0) goto L582298;  // @62_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @63_582160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @64_582160
  ecx = edx = 0;  // @65_582160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @66_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_582160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @68_582160
  ecx = edx = 0;  // @69_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_582160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_582160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 866), sizeof v); (u32)v; }));  // @73_582160
  ecx = edx = 0;  // @74_582160
  if ((eax & eax) == 0) goto L582462;  // @75_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @76_582160
  ecx = eax;  // @77_582160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @78_582160
  ecx = edx = 0;  // @79_582160
  eax = 0;  // @80_582160
  return eax;  // @81_582160
  L582298:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @83_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @84_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_582160
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; })));  // @86_582160
  eax = (u32)(edi + 24);  // @87_582160
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @88_582160
  p2_ = eax;  // @89_582160
  eax = (u32)(edi + 12);  // @90_582160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @91_582160
  p3_ = eax;  // @92_582160
  p4_ = edi;  // @93_582160
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784484)));  // @94_582160
  _mm_store_ss((float *)(u32)(esi + 92), x0);  // @95_582160
  eax = ext_582880_thiscall4(ecx, (u32)(p4_), (u32)(p3_), (u32)(p2_));  // @96_582160
  ecx = edx = 0;  // @97_582160
  ecx = esi;  // @98_582160
  eax = ext_584a20_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 870), sizeof v); (u32)v; }), (u32)(100));  // @99_582160
  ecx = edx = 0;  // @100_582160
  ecx = esi;  // @101_582160
  eax = ext_584a20_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 874), sizeof v); (u32)v; }), (u32)(90));  // @102_582160
  ecx = edx = 0;  // @103_582160
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 586), &v, sizeof v); }  // @104_582160
  ecx = (u32)(esi + 522);  // @105_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @106_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 582), &v, sizeof v); }  // @107_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @108_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11345), sizeof v); (u32)v; });  // @109_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @110_582160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + eax*4 + 1876), &v, sizeof v); }  // @111_582160
  ecx = (u32)(esi + 590);  // @112_582160
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 1872), &v, sizeof v); }  // @113_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @114_582160
  eax = (eax + (u32)(469));  // @115_582160
  eax = (u32)(edx + eax*4);  // @116_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 2644), &v, sizeof v); }  // @117_582160
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 654), &v, sizeof v); }  // @118_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @119_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 650), &v, sizeof v); }  // @120_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @121_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11345), sizeof v); (u32)v; });  // @122_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @123_582160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + eax*4 + 1876), &v, sizeof v); }  // @124_582160
  ecx = (u32)(esi + 658);  // @125_582160
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 1872), &v, sizeof v); }  // @126_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @127_582160
  eax = (eax + (u32)(469));  // @128_582160
  eax = (u32)(edx + eax*4);  // @129_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 2644), &v, sizeof v); }  // @130_582160
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 722), &v, sizeof v); }  // @131_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @132_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 718), &v, sizeof v); }  // @133_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @134_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11345), sizeof v); (u32)v; });  // @135_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @136_582160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + eax*4 + 1876), &v, sizeof v); }  // @137_582160
  ecx = (u32)(esi + 726);  // @138_582160
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 1872), &v, sizeof v); }  // @139_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @140_582160
  eax = (eax + (u32)(469));  // @141_582160
  eax = (u32)(edx + eax*4);  // @142_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 2644), &v, sizeof v); }  // @143_582160
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 790), &v, sizeof v); }  // @144_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @145_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 786), &v, sizeof v); }  // @146_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @147_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11345), sizeof v); (u32)v; });  // @148_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @149_582160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + eax*4 + 1876), &v, sizeof v); }  // @150_582160
  ecx = (u32)(esi + 794);  // @151_582160
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 1872), &v, sizeof v); }  // @152_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @153_582160
  eax = (eax + (u32)(469));  // @154_582160
  eax = (u32)(edx + eax*4);  // @155_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 2644), &v, sizeof v); }  // @156_582160
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 858), &v, sizeof v); }  // @157_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @158_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 854), &v, sizeof v); }  // @159_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @160_582160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11345), sizeof v); (u32)v; });  // @161_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @162_582160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + eax*4 + 1876), &v, sizeof v); }  // @163_582160
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 1872), &v, sizeof v); }  // @164_582160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1872), sizeof v); (u32)v; });  // @165_582160
  eax = (eax + (u32)(469));  // @166_582160
  eax = (u32)(edx + eax*4);  // @167_582160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 2644), &v, sizeof v); }  // @168_582160
  L582462:;
  eax = 0;  // @170_582160
  __asm__ volatile("" :: "Yz"(x0));  // @171_582160
  return eax;  // @172_582160
}
PCREG(582160, lifted_582160);

extern "C" u32 THISCALL lifted_612660(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_612660
  x0 = _mm_setzero_ps();  // @1_612660
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_612660
  _mm_storeu_ps((float *)(u32)(esi + 139272), x0);  // @3_612660
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 139288), &v, sizeof v); }  // @4_612660
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 139292), &v, sizeof v); }  // @5_612660
  _mm_storeu_ps((float *)(u32)(esi + 139296), x0);  // @6_612660
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 139312), &v, sizeof v); }  // @7_612660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @8_612660
  p0_ = edi;  // @9_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_612660
  p1_ = eax;  // @11_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p1_), (u32)(0), (u32)(1), (u32)(p0_), (u32)(0), (u32)(3), (u32)(827611204));  // @12_612660
  ecx = edx = 0;  // @13_612660
  if ((s32)(eax & eax) < 0) goto L6126c0;  // @14_612660
  { u32 v = (u32)((u32)(827611204)); __builtin_memcpy((void *)(u32)(esi + 139272), &v, sizeof v); }  // @15_612660
  L6126c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @17_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_612660
  p2_ = edi;  // @19_612660
  p3_ = eax;  // @20_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p3_), (u32)(0), (u32)(1), (u32)(p2_), (u32)(0), (u32)(3), (u32)(844388420));  // @21_612660
  ecx = edx = 0;  // @22_612660
  if ((s32)(eax & eax) < 0) goto L6126e7;  // @23_612660
  { u32 v = (u32)((u32)(844388420)); __builtin_memcpy((void *)(u32)(esi + 139276), &v, sizeof v); }  // @24_612660
  L6126e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @26_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_612660
  p4_ = edi;  // @28_612660
  p5_ = eax;  // @29_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p5_), (u32)(0), (u32)(1), (u32)(p4_), (u32)(0), (u32)(3), (u32)(861165636));  // @30_612660
  ecx = edx = 0;  // @31_612660
  if ((s32)(eax & eax) < 0) goto L61270e;  // @32_612660
  { u32 v = (u32)((u32)(861165636)); __builtin_memcpy((void *)(u32)(esi + 139280), &v, sizeof v); }  // @33_612660
  L61270e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @35_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_612660
  p6_ = edi;  // @37_612660
  p7_ = eax;  // @38_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p7_), (u32)(0), (u32)(1), (u32)(p6_), (u32)(0), (u32)(3), (u32)(877942852));  // @39_612660
  ecx = edx = 0;  // @40_612660
  if ((s32)(eax & eax) < 0) goto L612735;  // @41_612660
  { u32 v = (u32)((u32)(877942852)); __builtin_memcpy((void *)(u32)(esi + 139284), &v, sizeof v); }  // @42_612660
  L612735:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @44_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_612660
  p8_ = edi;  // @46_612660
  p9_ = eax;  // @47_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p9_), (u32)(0), (u32)(1), (u32)(p8_), (u32)(0), (u32)(3), (u32)(894720068));  // @48_612660
  ecx = edx = 0;  // @49_612660
  if ((s32)(eax & eax) < 0) goto L61275c;  // @50_612660
  { u32 v = (u32)((u32)(894720068)); __builtin_memcpy((void *)(u32)(esi + 139288), &v, sizeof v); }  // @51_612660
  L61275c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @53_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_612660
  p10_ = edi;  // @55_612660
  p11_ = eax;  // @56_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p11_), (u32)(0), (u32)(1), (u32)(p10_), (u32)(0), (u32)(3), (u32)(25));  // @57_612660
  ecx = edx = 0;  // @58_612660
  if ((s32)(eax & eax) < 0) goto L612780;  // @59_612660
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(esi + 139304), &v, sizeof v); }  // @60_612660
  L612780:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @62_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_612660
  p12_ = edi;  // @64_612660
  p13_ = eax;  // @65_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p13_), (u32)(0), (u32)(1), (u32)(p12_), (u32)(0), (u32)(3), (u32)(26));  // @66_612660
  ecx = edx = 0;  // @67_612660
  if ((s32)(eax & eax) < 0) goto L6127a4;  // @68_612660
  { u32 v = (u32)((u32)(26)); __builtin_memcpy((void *)(u32)(esi + 139308), &v, sizeof v); }  // @69_612660
  L6127a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @71_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @72_612660
  p14_ = edi;  // @73_612660
  p15_ = eax;  // @74_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p15_), (u32)(0), (u32)(1), (u32)(p14_), (u32)(0), (u32)(3), (u32)(21));  // @75_612660
  ecx = edx = 0;  // @76_612660
  if ((s32)(eax & eax) < 0) goto L6127ca;  // @77_612660
  { u32 v = (u32)((u32)(21)); __builtin_memcpy((void *)(u32)(esi + 139296), &v, sizeof v); }  // @78_612660
  goto L6127d6;  // @79_612660
  L6127ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139304), sizeof v); (u32)v; });  // @81_612660
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 139296), &v, sizeof v); }  // @82_612660
  L6127d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @84_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @85_612660
  p16_ = edi;  // @86_612660
  p17_ = eax;  // @87_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p17_), (u32)(0), (u32)(1), (u32)(p16_), (u32)(0), (u32)(3), (u32)(21));  // @88_612660
  ecx = edx = 0;  // @89_612660
  if ((s32)(eax & eax) < 0) goto L6127fc;  // @90_612660
  { u32 v = (u32)((u32)(21)); __builtin_memcpy((void *)(u32)(esi + 139300), &v, sizeof v); }  // @91_612660
  goto L612808;  // @92_612660
  L6127fc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139308), sizeof v); (u32)v; });  // @94_612660
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 139300), &v, sizeof v); }  // @95_612660
  L612808:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @97_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @98_612660
  p18_ = edi;  // @99_612660
  p19_ = eax;  // @100_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p19_), (u32)(0), (u32)(1), (u32)(p18_), (u32)(0), (u32)(3), (u32)(41));  // @101_612660
  ecx = edx = 0;  // @102_612660
  if ((s32)(eax & eax) < 0) goto L61282c;  // @103_612660
  { u32 v = (u32)((u32)(41)); __builtin_memcpy((void *)(u32)(esi + 139292), &v, sizeof v); }  // @104_612660
  L61282c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @106_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @107_612660
  p20_ = edi;  // @108_612660
  p21_ = eax;  // @109_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p21_), (u32)(0), (u32)(1), (u32)(p20_), (u32)(0), (u32)(3), (u32)(62));  // @110_612660
  ecx = edx = 0;  // @111_612660
  if ((s32)(eax & eax) < 0) goto L612856;  // @112_612660
  { u32 v = (u32)((u32)(62)); __builtin_memcpy((void *)(u32)(esi + 139312), &v, sizeof v); }  // @113_612660
  __asm__ volatile("" :: "Yz"(x0));  // @114_612660
  return eax;  // @115_612660
  L612856:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @117_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @118_612660
  p22_ = edi;  // @119_612660
  p23_ = eax;  // @120_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p23_), (u32)(0), (u32)(1), (u32)(p22_), (u32)(0), (u32)(3), (u32)(61));  // @121_612660
  ecx = edx = 0;  // @122_612660
  if ((s32)(eax & eax) < 0) goto L612880;  // @123_612660
  { u32 v = (u32)((u32)(61)); __builtin_memcpy((void *)(u32)(esi + 139312), &v, sizeof v); }  // @124_612660
  __asm__ volatile("" :: "Yz"(x0));  // @125_612660
  return eax;  // @126_612660
  L612880:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @128_612660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @129_612660
  p24_ = edi;  // @130_612660
  p25_ = eax;  // @131_612660
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, (u32)(p25_), (u32)(0), (u32)(1), (u32)(p24_), (u32)(0), (u32)(3), (u32)(60));  // @132_612660
  ecx = edx = 0;  // @133_612660
  if ((s32)(eax & eax) < 0) goto L6128a4;  // @134_612660
  { u32 v = (u32)((u32)(60)); __builtin_memcpy((void *)(u32)(esi + 139312), &v, sizeof v); }  // @135_612660
  L6128a4:;
  __asm__ volatile("" :: "Yz"(x0));  // @137_612660
  return eax;  // @138_612660
}
PCREG(612660, lifted_612660);

extern "C" u32 THISCALL lifted_43d390(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = (u32)(ecx + 132);  // @0_43d390
  edx = (u32)(EBP - 149);  // @1_43d390
  if (eax == edx) goto L43d3af;  // @2_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @3_43d390
  L43d3af:;
  x0 = _mm_load_ss((const float *)(u32)(6799788));  // @5_43d390
  x6 = _mm_setzero_ps();  // @6_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6799824));  // @7_43d390
  edx = (edx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @8_43d390
  x0 = _mm_unpacklo_ps(x0, x6);  // @9_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 129), _mm_castps_si128(x0));  // @10_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 87));  // @11_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @12_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @13_43d390
  x7 = _mm_load_ss((const float *)(u32)(6785112));  // @14_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 116), x0);  // @15_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 121), &v, sizeof v); }  // @16_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 71)));  // @17_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @18_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 100), _mm_castps_si128(x0));  // @19_43d390
  x2 = _mm_loadu_ps((const float *)(u32)(6799888));  // @20_43d390
  x3 = _mm_loadu_ps((const float *)(u32)(6800064));  // @21_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 203), x1);  // @22_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 117), &v, sizeof v); }  // @23_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 129));  // @24_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @25_43d390
  x1 = _mm_load_ss((const float *)(u32)(6799780));  // @26_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 219), x0);  // @27_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 113));  // @28_43d390
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @29_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @30_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @31_43d390
  ebx = (ebx & 0xffffff00u) | (((edx & 0xff)) & 0xff);  // @32_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 89), sizeof v); (u32)v; });  // @33_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 235), x0);  // @34_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @35_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 97)));  // @36_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 251), _mm_castps_si128(x0));  // @37_43d390
  x0 = x7;  // @38_43d390
  x0 = _mm_unpacklo_ps(x0, x1);  // @39_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @40_43d390
  x0 = x7;  // @41_43d390
  x0 = _mm_unpacklo_ps(x0, x7);  // @42_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6799856));  // @43_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x0));  // @44_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 259), &v, sizeof v); }  // @45_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @46_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @47_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x2);  // @48_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @49_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @50_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @51_43d390
  x2 = _mm_loadu_ps((const float *)(u32)(6800048));  // @52_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 261), x3);  // @53_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @54_43d390
  x3 = _mm_load_ss((const float *)(u32)(6792876));  // @55_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 277), x0);  // @56_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @57_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @58_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @59_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @60_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 293), x0);  // @61_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @62_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @63_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 309), _mm_castps_si128(x0));  // @64_43d390
  x0 = x7;  // @65_43d390
  x0 = _mm_unpacklo_ps(x0, x3);  // @66_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @67_43d390
  x0 = x7;  // @68_43d390
  x0 = _mm_unpacklo_ps(x0, x7);  // @69_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 317), &v, sizeof v); }  // @70_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @71_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x0));  // @72_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @73_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x1);  // @74_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @75_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @76_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @77_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 319), x2);  // @78_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @79_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 335), x0);  // @80_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @81_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @82_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 351), x0);  // @83_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @84_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @85_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6799808));  // @86_43d390
  x2 = _mm_loadu_ps((const float *)(u32)(6799952));  // @87_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 367), _mm_castps_si128(x0));  // @88_43d390
  x0 = x6;  // @89_43d390
  x0 = _mm_unpacklo_ps(x0, x6);  // @90_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @91_43d390
  x0 = x7;  // @92_43d390
  x0 = _mm_unpacklo_ps(x0, x7);  // @93_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x0));  // @94_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 375), &v, sizeof v); }  // @95_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x1);  // @96_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @97_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @98_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6799872));  // @99_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @100_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @101_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @102_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @103_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @104_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 377), x2);  // @105_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @106_43d390
  x2 = _mm_loadu_ps((const float *)(u32)(6799872));  // @107_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 393), x0);  // @108_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @109_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @110_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @111_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x1);  // @112_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @113_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 409), x0);  // @114_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @115_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @116_43d390
  x1 = _mm_load_ss((const float *)(u32)(6795036));  // @117_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 425), _mm_castps_si128(x0));  // @118_43d390
  x0 = x3;  // @119_43d390
  x0 = _mm_unpacklo_ps(x0, x7);  // @120_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @121_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 433), &v, sizeof v); }  // @122_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @123_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @124_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @125_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @126_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @127_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 435), x2);  // @128_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @129_43d390
  x2 = _mm_loadu_ps((const float *)(u32)(6799904));  // @130_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 451), x0);  // @131_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @132_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @133_43d390
  x3 = _mm_unpacklo_ps(x3, x7);  // @134_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x3));  // @135_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @136_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @137_43d390
  x3 = _mm_loadu_ps((const float *)(u32)(6800000));  // @138_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 467), x0);  // @139_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @140_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @141_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 483), _mm_castps_si128(x0));  // @142_43d390
  x0 = x7;  // @143_43d390
  x0 = _mm_unpacklo_ps(x0, x1);  // @144_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @145_43d390
  x0 = x7;  // @146_43d390
  x0 = _mm_unpacklo_ps(x0, x6);  // @147_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 491), &v, sizeof v); }  // @148_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @149_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @150_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x0));  // @151_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x2);  // @152_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @153_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @154_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @155_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 493), x3);  // @156_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @157_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 509), x0);  // @158_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @159_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @160_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @161_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 525), x0);  // @162_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @163_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 541), _mm_castps_si128(x0));  // @164_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 549), &v, sizeof v); }  // @165_43d390
  x5 = _mm_load_ss((const float *)(u32)(6799776));  // @166_43d390
  x3 = _mm_load_ss((const float *)(u32)(6799764));  // @167_43d390
  x0 = x5;  // @168_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6799840));  // @169_43d390
  x2 = _mm_loadu_ps((const float *)(u32)(6799984));  // @170_43d390
  x0 = _mm_unpacklo_ps(x0, x3);  // @171_43d390
  x4 = _mm_load_ss((const float *)(u32)(6799784));  // @172_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @173_43d390
  x0 = x5;  // @174_43d390
  x0 = _mm_unpacklo_ps(x0, x6);  // @175_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x0));  // @176_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x1);  // @177_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @178_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @179_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6799792));  // @180_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @181_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @182_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @183_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @184_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @185_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 551), x2);  // @186_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @187_43d390
  x2 = _mm_loadu_ps((const float *)(u32)(6799936));  // @188_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 567), x0);  // @189_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @190_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @191_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @192_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x1);  // @193_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @194_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 583), x0);  // @195_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @196_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @197_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6799968));  // @198_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 599), _mm_castps_si128(x0));  // @199_43d390
  x0 = x4;  // @200_43d390
  x0 = _mm_unpacklo_ps(x0, x3);  // @201_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 607), &v, sizeof v); }  // @202_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @203_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @204_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @205_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @206_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @207_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @208_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 609), x2);  // @209_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @210_43d390
  x2 = _mm_load_ss((const float *)(u32)(6799772));  // @211_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 625), x0);  // @212_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @213_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @214_43d390
  x5 = _mm_unpacklo_ps(x5, x6);  // @215_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x5));  // @216_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @217_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @218_43d390
  x4 = _mm_unpacklo_ps(x4, x2);  // @219_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 641), x0);  // @220_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @221_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @222_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 657), _mm_castps_si128(x0));  // @223_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(6799920));  // @224_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 665), &v, sizeof v); }  // @225_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @226_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @227_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x0);  // @228_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @229_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @230_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x4));  // @231_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @232_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @233_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 667), x1);  // @234_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @235_43d390
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @236_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @237_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6800016));  // @238_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 683), x0);  // @239_43d390
  x7 = _mm_unpacklo_ps(x7, x7);  // @240_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x7));  // @241_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @242_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 699), x0);  // @243_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @244_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 715), _mm_castps_si128(x0));  // @245_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 723), &v, sizeof v); }  // @246_43d390
  x0 = x2;  // @247_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @248_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @249_43d390
  x0 = _mm_unpacklo_ps(x0, x2);  // @250_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @251_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 87));  // @252_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @253_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @254_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x0);  // @255_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @256_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 71)));  // @257_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x0));  // @258_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @259_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @260_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 725), x1);  // @261_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @262_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @263_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 741), x0);  // @264_43d390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @265_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @266_43d390
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @267_43d390
  x1 = _mm_loadu_ps((const float *)(u32)(6800032));  // @268_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 757), x0);  // @269_43d390
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @270_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @271_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 773), _mm_castps_si128(x0));  // @272_43d390
  x0 = _mm_load_ss((const float *)(u32)(6799768));  // @273_43d390
  x0 = _mm_unpacklo_ps(x0, x2);  // @274_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 42), _mm_castps_si128(x0));  // @275_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 87));  // @276_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 781), &v, sizeof v); }  // @277_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @278_43d390
  _mm_storeu_ps((float *)(u32)(EBP - 29), x0);  // @279_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @280_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 71)));  // @281_43d390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 63), sizeof v); (u32)v; });  // @282_43d390
  _mm_storel_epi64((__m128i *)(u32)(EBP - 13), _mm_castps_si128(x0));  // @283_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 42));  // @284_43d390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @285_43d390
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; });  // @286_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 783), x1);  // @287_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 799), x0);  // @288_43d390
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 26));  // @289_43d390
  _mm_storeu_ps((float *)(u32)(ecx + 815), x0);  // @290_43d390
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 10)));  // @291_43d390
  _mm_storel_epi64((__m128i *)(u32)(ecx + 831), _mm_castps_si128(x0));  // @292_43d390
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 839), &v, sizeof v); }  // @293_43d390
  __asm__ volatile("" :: "Yz"(x0));  // @294_43d390
  return eax;  // @295_43d390
}
PCREG(43d390, lifted_43d390);

extern "C" u32 THISCALL lifted_5d0600(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_, p37_, p38_, p39_, p40_, p41_, p42_, p43_, p44_, p45_, p46_, p47_, p48_, p49_, p50_, p51_, p52_, p53_, p54_, p55_, p56_, p57_, p58_, p59_, p60_, p61_, p62_, p63_, p64_, p65_, p66_, p67_, p68_, p69_, p70_, p71_, p72_, p73_, p74_, p75_, p76_, p77_, p78_, p79_, p80_, p81_, p82_, p83_, p84_, p85_, p86_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d0600
  edi = ecx;  // @1_5d0600
  ecx = (u32)(EBP - 8);  // @2_5d0600
  p0_ = ecx;  // @3_5d0600
  ecx = esi;  // @4_5d0600
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @5_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p0_));  // @7_5d0600
  ecx = edx = 0;  // @8_5d0600
  x1 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @9_5d0600
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(7000572)));  // @10_5d0600
  x0 = _mm_load_ss((const float *)(u32)(6806040));  // @11_5d0600
  if (fa_ > fb_) goto L5d063f;  // @12_5d0600
  x2 = _mm_load_ss((const float *)(u32)(7000628));  // @13_5d0600
  fa_ = _mm_cvtss_f32(x2); fb_ = _mm_cvtss_f32(x1);  // @14_5d0600
  if (!(fa_ > fb_)) goto L5d0642;  // @15_5d0600
  L5d063f:;
  x1 = x0;  // @17_5d0600
  L5d0642:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_5d0600
  ecx = (u32)(EBP - 8);  // @20_5d0600
  p1_ = ecx;  // @21_5d0600
  ecx = esi;  // @22_5d0600
  _mm_store_ss((float *)(u32)(edi + 2644), x1);  // @23_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p1_));  // @24_5d0600
  ecx = edx = 0;  // @25_5d0600
  x0 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @26_5d0600
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(7000572)));  // @27_5d0600
  if (fa_ > fb_) goto L5d0670;  // @28_5d0600
  x1 = _mm_load_ss((const float *)(u32)(7000628));  // @29_5d0600
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @30_5d0600
  if (!(fa_ > fb_)) goto L5d0678;  // @31_5d0600
  L5d0670:;
  x0 = _mm_load_ss((const float *)(u32)(6806040));  // @33_5d0600
  L5d0678:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_5d0600
  eax = (u32)(edi + 2652);  // @36_5d0600
  p2_ = eax;  // @37_5d0600
  ecx = esi;  // @38_5d0600
  _mm_store_ss((float *)(u32)(edi + 2648), x0);  // @39_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p2_));  // @40_5d0600
  ecx = edx = 0;  // @41_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_5d0600
  eax = (u32)(edi + 2656);  // @43_5d0600
  p3_ = eax;  // @44_5d0600
  ecx = esi;  // @45_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p3_));  // @46_5d0600
  ecx = edx = 0;  // @47_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_5d0600
  eax = (u32)(edi + 2660);  // @49_5d0600
  p4_ = eax;  // @50_5d0600
  ecx = esi;  // @51_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p4_));  // @52_5d0600
  ecx = edx = 0;  // @53_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_5d0600
  eax = (u32)(edi + 2664);  // @55_5d0600
  p5_ = eax;  // @56_5d0600
  ecx = esi;  // @57_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p5_));  // @58_5d0600
  ecx = edx = 0;  // @59_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_5d0600
  eax = (u32)(edi + 2668);  // @61_5d0600
  p6_ = eax;  // @62_5d0600
  ecx = esi;  // @63_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p6_));  // @64_5d0600
  ecx = edx = 0;  // @65_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_5d0600
  eax = (u32)(edi + 2672);  // @67_5d0600
  p7_ = eax;  // @68_5d0600
  ecx = esi;  // @69_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p7_));  // @70_5d0600
  ecx = edx = 0;  // @71_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_5d0600
  eax = (u32)(edi + 2673);  // @73_5d0600
  p8_ = eax;  // @74_5d0600
  ecx = esi;  // @75_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p8_));  // @76_5d0600
  ecx = edx = 0;  // @77_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_5d0600
  eax = (u32)(edi + 2674);  // @79_5d0600
  p9_ = eax;  // @80_5d0600
  ecx = esi;  // @81_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p9_));  // @82_5d0600
  ecx = edx = 0;  // @83_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_5d0600
  eax = (u32)(edi + 2686);  // @85_5d0600
  p10_ = eax;  // @86_5d0600
  ecx = esi;  // @87_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p10_));  // @88_5d0600
  ecx = edx = 0;  // @89_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_5d0600
  eax = (u32)(edi + 2698);  // @91_5d0600
  p11_ = eax;  // @92_5d0600
  ecx = esi;  // @93_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p11_));  // @94_5d0600
  ecx = edx = 0;  // @95_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @96_5d0600
  eax = (u32)(edi + 2710);  // @97_5d0600
  p12_ = eax;  // @98_5d0600
  ecx = esi;  // @99_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p12_));  // @100_5d0600
  ecx = edx = 0;  // @101_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_5d0600
  eax = (u32)(edi + 2714);  // @103_5d0600
  p13_ = eax;  // @104_5d0600
  ecx = esi;  // @105_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p13_));  // @106_5d0600
  ecx = edx = 0;  // @107_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_5d0600
  eax = (u32)(edi + 2718);  // @109_5d0600
  p14_ = eax;  // @110_5d0600
  ecx = esi;  // @111_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p14_));  // @112_5d0600
  ecx = edx = 0;  // @113_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_5d0600
  eax = (u32)(edi + 2722);  // @115_5d0600
  p15_ = eax;  // @116_5d0600
  ecx = esi;  // @117_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p15_));  // @118_5d0600
  ecx = edx = 0;  // @119_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_5d0600
  eax = (u32)(edi + 2734);  // @121_5d0600
  p16_ = eax;  // @122_5d0600
  ecx = esi;  // @123_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p16_));  // @124_5d0600
  ecx = edx = 0;  // @125_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_5d0600
  eax = (u32)(edi + 2742);  // @127_5d0600
  p17_ = eax;  // @128_5d0600
  ecx = esi;  // @129_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p17_));  // @130_5d0600
  ecx = edx = 0;  // @131_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_5d0600
  ecx = (u32)(EBP + 8);  // @133_5d0600
  p18_ = ecx;  // @134_5d0600
  ecx = esi;  // @135_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p18_));  // @136_5d0600
  ecx = edx = 0;  // @137_5d0600
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @138_5d0600
  ecx = esi;  // @139_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2773), &v, sizeof v); }  // @140_5d0600
  eax = (u32)(edi + 2777);  // @141_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_5d0600
  p19_ = eax;  // @143_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p19_));  // @144_5d0600
  ecx = edx = 0;  // @145_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_5d0600
  eax = (u32)(edi + 2781);  // @147_5d0600
  p20_ = eax;  // @148_5d0600
  ecx = esi;  // @149_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p20_));  // @150_5d0600
  ecx = edx = 0;  // @151_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @152_5d0600
  eax = (u32)(edi + 2772);  // @153_5d0600
  p21_ = eax;  // @154_5d0600
  ecx = esi;  // @155_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p21_));  // @156_5d0600
  ecx = edx = 0;  // @157_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_5d0600
  eax = (u32)(edi + 2785);  // @159_5d0600
  p22_ = eax;  // @160_5d0600
  ecx = esi;  // @161_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p22_));  // @162_5d0600
  ecx = edx = 0;  // @163_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_5d0600
  ecx = (u32)(EBP - 12);  // @165_5d0600
  p23_ = ecx;  // @166_5d0600
  ecx = esi;  // @167_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p23_));  // @168_5d0600
  ecx = edx = 0;  // @169_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @170_5d0600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @171_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @172_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @173_5d0600
  ecx = edx = 0;  // @174_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2789), &v, sizeof v); }  // @175_5d0600
  ecx = (u32)(EBP - 8);  // @176_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_5d0600
  p24_ = ecx;  // @178_5d0600
  ecx = esi;  // @179_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p24_));  // @180_5d0600
  ecx = edx = 0;  // @181_5d0600
  x1 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @182_5d0600
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(7000572)));  // @183_5d0600
  if (!(fa_ > fb_)) goto L5d07f4;  // @184_5d0600
  L5d07ea:;
  x0 = _mm_load_ss((const float *)(u32)(6806040));  // @186_5d0600
  goto L5d0804;  // @187_5d0600
  L5d07f4:;
  x0 = _mm_load_ss((const float *)(u32)(7000628));  // @189_5d0600
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @190_5d0600
  if (fa_ > fb_) goto L5d07ea;  // @191_5d0600
  x0 = x1;  // @192_5d0600
  L5d0804:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @194_5d0600
  eax = (u32)(edi + 2797);  // @195_5d0600
  p25_ = eax;  // @196_5d0600
  ecx = esi;  // @197_5d0600
  _mm_store_ss((float *)(u32)(edi + 2793), x0);  // @198_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p25_));  // @199_5d0600
  ecx = edx = 0;  // @200_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @201_5d0600
  eax = (u32)(edi + 2801);  // @202_5d0600
  p26_ = eax;  // @203_5d0600
  ecx = esi;  // @204_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p26_));  // @205_5d0600
  ecx = edx = 0;  // @206_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @207_5d0600
  eax = (u32)(edi + 2805);  // @208_5d0600
  p27_ = eax;  // @209_5d0600
  ecx = esi;  // @210_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p27_));  // @211_5d0600
  ecx = edx = 0;  // @212_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @213_5d0600
  eax = (u32)(edi + 2809);  // @214_5d0600
  p28_ = eax;  // @215_5d0600
  ecx = esi;  // @216_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p28_));  // @217_5d0600
  ecx = edx = 0;  // @218_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @219_5d0600
  eax = (u32)(edi + 2813);  // @220_5d0600
  p29_ = eax;  // @221_5d0600
  ecx = esi;  // @222_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p29_));  // @223_5d0600
  ecx = edx = 0;  // @224_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @225_5d0600
  eax = (u32)(edi + 2817);  // @226_5d0600
  p30_ = eax;  // @227_5d0600
  ecx = esi;  // @228_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p30_));  // @229_5d0600
  ecx = edx = 0;  // @230_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @231_5d0600
  eax = (u32)(edi + 2821);  // @232_5d0600
  p31_ = eax;  // @233_5d0600
  ecx = esi;  // @234_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p31_));  // @235_5d0600
  ecx = edx = 0;  // @236_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @237_5d0600
  eax = (u32)(edi + 2825);  // @238_5d0600
  p32_ = eax;  // @239_5d0600
  ecx = esi;  // @240_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p32_));  // @241_5d0600
  ecx = edx = 0;  // @242_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @243_5d0600
  eax = (u32)(edi + 2829);  // @244_5d0600
  p33_ = eax;  // @245_5d0600
  ecx = esi;  // @246_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p33_));  // @247_5d0600
  ecx = edx = 0;  // @248_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @249_5d0600
  eax = (u32)(edi + 2833);  // @250_5d0600
  p34_ = eax;  // @251_5d0600
  ecx = esi;  // @252_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p34_));  // @253_5d0600
  ecx = edx = 0;  // @254_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @255_5d0600
  eax = (u32)(edi + 2837);  // @256_5d0600
  p35_ = eax;  // @257_5d0600
  ecx = esi;  // @258_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p35_));  // @259_5d0600
  ecx = edx = 0;  // @260_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @261_5d0600
  eax = (u32)(edi + 2841);  // @262_5d0600
  p36_ = eax;  // @263_5d0600
  ecx = esi;  // @264_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p36_));  // @265_5d0600
  ecx = edx = 0;  // @266_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @267_5d0600
  eax = (u32)(edi + 2842);  // @268_5d0600
  p37_ = eax;  // @269_5d0600
  ecx = esi;  // @270_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p37_));  // @271_5d0600
  ecx = edx = 0;  // @272_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @273_5d0600
  eax = (u32)(edi + 2847);  // @274_5d0600
  p38_ = eax;  // @275_5d0600
  ecx = esi;  // @276_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p38_));  // @277_5d0600
  ecx = edx = 0;  // @278_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @279_5d0600
  eax = (u32)(edi + 2851);  // @280_5d0600
  p39_ = eax;  // @281_5d0600
  ecx = esi;  // @282_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p39_));  // @283_5d0600
  ecx = edx = 0;  // @284_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @285_5d0600
  eax = (u32)(edi + 2855);  // @286_5d0600
  p40_ = eax;  // @287_5d0600
  ecx = esi;  // @288_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p40_));  // @289_5d0600
  ecx = edx = 0;  // @290_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @291_5d0600
  eax = (u32)(edi + 2859);  // @292_5d0600
  p41_ = eax;  // @293_5d0600
  ecx = esi;  // @294_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p41_));  // @295_5d0600
  ecx = edx = 0;  // @296_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @297_5d0600
  eax = (u32)(edi + 2863);  // @298_5d0600
  p42_ = eax;  // @299_5d0600
  ecx = esi;  // @300_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p42_));  // @301_5d0600
  ecx = edx = 0;  // @302_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @303_5d0600
  eax = (u32)(edi + 2864);  // @304_5d0600
  p43_ = eax;  // @305_5d0600
  ecx = esi;  // @306_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p43_));  // @307_5d0600
  ecx = edx = 0;  // @308_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @309_5d0600
  eax = (u32)(edi + 2865);  // @310_5d0600
  p44_ = eax;  // @311_5d0600
  ecx = esi;  // @312_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p44_));  // @313_5d0600
  ecx = edx = 0;  // @314_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @315_5d0600
  eax = (u32)(edi + 2866);  // @316_5d0600
  p45_ = eax;  // @317_5d0600
  ecx = esi;  // @318_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p45_));  // @319_5d0600
  ecx = edx = 0;  // @320_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @321_5d0600
  eax = (u32)(edi + 2867);  // @322_5d0600
  p46_ = eax;  // @323_5d0600
  ecx = esi;  // @324_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p46_));  // @325_5d0600
  ecx = edx = 0;  // @326_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @327_5d0600
  eax = (u32)(edi + 2868);  // @328_5d0600
  p47_ = eax;  // @329_5d0600
  ecx = esi;  // @330_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p47_));  // @331_5d0600
  ecx = edx = 0;  // @332_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @333_5d0600
  eax = (u32)(edi + 2869);  // @334_5d0600
  p48_ = eax;  // @335_5d0600
  ecx = esi;  // @336_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p48_));  // @337_5d0600
  ecx = edx = 0;  // @338_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @339_5d0600
  eax = (u32)(edi + 2873);  // @340_5d0600
  p49_ = eax;  // @341_5d0600
  ecx = esi;  // @342_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p49_));  // @343_5d0600
  ecx = edx = 0;  // @344_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @345_5d0600
  eax = (u32)(edi + 2885);  // @346_5d0600
  p50_ = eax;  // @347_5d0600
  ecx = esi;  // @348_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p50_));  // @349_5d0600
  ecx = edx = 0;  // @350_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @351_5d0600
  eax = (u32)(edi + 2887);  // @352_5d0600
  p51_ = eax;  // @353_5d0600
  ecx = esi;  // @354_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p51_));  // @355_5d0600
  ecx = edx = 0;  // @356_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @357_5d0600
  eax = (u32)(edi + 2888);  // @358_5d0600
  p52_ = eax;  // @359_5d0600
  ecx = esi;  // @360_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p52_));  // @361_5d0600
  ecx = edx = 0;  // @362_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @363_5d0600
  eax = (u32)(edi + 2889);  // @364_5d0600
  p53_ = eax;  // @365_5d0600
  ecx = esi;  // @366_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p53_));  // @367_5d0600
  ecx = edx = 0;  // @368_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @369_5d0600
  eax = (u32)(edi + 2893);  // @370_5d0600
  p54_ = eax;  // @371_5d0600
  ecx = esi;  // @372_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p54_));  // @373_5d0600
  ecx = edx = 0;  // @374_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @375_5d0600
  eax = (u32)(edi + 2895);  // @376_5d0600
  p55_ = eax;  // @377_5d0600
  ecx = esi;  // @378_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p55_));  // @379_5d0600
  ecx = edx = 0;  // @380_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @381_5d0600
  ecx = (u32)(EBP - 16);  // @382_5d0600
  p56_ = ecx;  // @383_5d0600
  ecx = esi;  // @384_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p56_));  // @385_5d0600
  ecx = edx = 0;  // @386_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @387_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2896), &v, sizeof v); }  // @388_5d0600
  ecx = esi;  // @389_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @390_5d0600
  eax = (u32)(edi + 3181);  // @391_5d0600
  p57_ = eax;  // @392_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p57_));  // @393_5d0600
  ecx = edx = 0;  // @394_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @395_5d0600
  eax = (u32)(edi + 3185);  // @396_5d0600
  p58_ = eax;  // @397_5d0600
  ecx = esi;  // @398_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p58_));  // @399_5d0600
  ecx = edx = 0;  // @400_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @401_5d0600
  eax = (u32)(edi + 3197);  // @402_5d0600
  p59_ = eax;  // @403_5d0600
  ecx = esi;  // @404_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p59_));  // @405_5d0600
  ecx = edx = 0;  // @406_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @407_5d0600
  eax = (u32)(edi + 3209);  // @408_5d0600
  p60_ = eax;  // @409_5d0600
  ecx = esi;  // @410_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(p60_));  // @411_5d0600
  ecx = edx = 0;  // @412_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @413_5d0600
  eax = (u32)(edi + 3245);  // @414_5d0600
  p61_ = eax;  // @415_5d0600
  ecx = esi;  // @416_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p61_));  // @417_5d0600
  ecx = edx = 0;  // @418_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @419_5d0600
  eax = (u32)(edi + 3257);  // @420_5d0600
  p62_ = eax;  // @421_5d0600
  ecx = esi;  // @422_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(p62_));  // @423_5d0600
  ecx = edx = 0;  // @424_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @425_5d0600
  eax = (u32)(edi + 3293);  // @426_5d0600
  p63_ = eax;  // @427_5d0600
  ecx = esi;  // @428_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(p63_));  // @429_5d0600
  ecx = edx = 0;  // @430_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_5d0600
  eax = (u32)(edi + 3329);  // @432_5d0600
  p64_ = eax;  // @433_5d0600
  ecx = esi;  // @434_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p64_));  // @435_5d0600
  ecx = edx = 0;  // @436_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @437_5d0600
  eax = (u32)(edi + 3341);  // @438_5d0600
  p65_ = eax;  // @439_5d0600
  ecx = esi;  // @440_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p65_));  // @441_5d0600
  ecx = edx = 0;  // @442_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @443_5d0600
  eax = (u32)(edi + 3345);  // @444_5d0600
  p66_ = eax;  // @445_5d0600
  ecx = esi;  // @446_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p66_));  // @447_5d0600
  ecx = edx = 0;  // @448_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @449_5d0600
  eax = (u32)(edi + 3349);  // @450_5d0600
  p67_ = eax;  // @451_5d0600
  ecx = esi;  // @452_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p67_));  // @453_5d0600
  ecx = edx = 0;  // @454_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @455_5d0600
  eax = (u32)(edi + 3361);  // @456_5d0600
  p68_ = eax;  // @457_5d0600
  ecx = esi;  // @458_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p68_));  // @459_5d0600
  ecx = edx = 0;  // @460_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @461_5d0600
  eax = (u32)(edi + 3362);  // @462_5d0600
  p69_ = eax;  // @463_5d0600
  ecx = esi;  // @464_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p69_));  // @465_5d0600
  ecx = edx = 0;  // @466_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @467_5d0600
  eax = (u32)(edi + 3374);  // @468_5d0600
  p70_ = eax;  // @469_5d0600
  ecx = esi;  // @470_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p70_));  // @471_5d0600
  ecx = edx = 0;  // @472_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @473_5d0600
  eax = (u32)(edi + 3378);  // @474_5d0600
  p71_ = eax;  // @475_5d0600
  ecx = esi;  // @476_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p71_));  // @477_5d0600
  ecx = edx = 0;  // @478_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @479_5d0600
  eax = (u32)(edi + 3379);  // @480_5d0600
  p72_ = eax;  // @481_5d0600
  ecx = esi;  // @482_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p72_));  // @483_5d0600
  ecx = edx = 0;  // @484_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @485_5d0600
  eax = (u32)(edi + 3380);  // @486_5d0600
  p73_ = eax;  // @487_5d0600
  ecx = esi;  // @488_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p73_));  // @489_5d0600
  ecx = edx = 0;  // @490_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @491_5d0600
  eax = (u32)(edi + 3381);  // @492_5d0600
  p74_ = eax;  // @493_5d0600
  ecx = esi;  // @494_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p74_));  // @495_5d0600
  ecx = edx = 0;  // @496_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @497_5d0600
  eax = (u32)(edi + 3544);  // @498_5d0600
  p75_ = eax;  // @499_5d0600
  ecx = esi;  // @500_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p75_));  // @501_5d0600
  ecx = edx = 0;  // @502_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @503_5d0600
  eax = (u32)(edi + 3573);  // @504_5d0600
  p76_ = eax;  // @505_5d0600
  ecx = esi;  // @506_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p76_));  // @507_5d0600
  ecx = edx = 0;  // @508_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @509_5d0600
  eax = (u32)(edi + 3577);  // @510_5d0600
  p77_ = eax;  // @511_5d0600
  ecx = esi;  // @512_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p77_));  // @513_5d0600
  ecx = edx = 0;  // @514_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @515_5d0600
  eax = (u32)(edi + 3581);  // @516_5d0600
  p78_ = eax;  // @517_5d0600
  ecx = esi;  // @518_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p78_));  // @519_5d0600
  ecx = edx = 0;  // @520_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @521_5d0600
  eax = (u32)(edi + 3585);  // @522_5d0600
  p79_ = eax;  // @523_5d0600
  ecx = esi;  // @524_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p79_));  // @525_5d0600
  ecx = edx = 0;  // @526_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @527_5d0600
  eax = (u32)(edi + 3589);  // @528_5d0600
  p80_ = eax;  // @529_5d0600
  ecx = esi;  // @530_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p80_));  // @531_5d0600
  ecx = edx = 0;  // @532_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @533_5d0600
  eax = (u32)(edi + 3593);  // @534_5d0600
  p81_ = eax;  // @535_5d0600
  ecx = esi;  // @536_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p81_));  // @537_5d0600
  ecx = edx = 0;  // @538_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @539_5d0600
  eax = (u32)(edi + 3597);  // @540_5d0600
  p82_ = eax;  // @541_5d0600
  ecx = esi;  // @542_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p82_));  // @543_5d0600
  ecx = edx = 0;  // @544_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @545_5d0600
  eax = (u32)(edi + 3598);  // @546_5d0600
  p83_ = eax;  // @547_5d0600
  ecx = esi;  // @548_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p83_));  // @549_5d0600
  ecx = edx = 0;  // @550_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @551_5d0600
  eax = (u32)(edi + 3607);  // @552_5d0600
  p84_ = eax;  // @553_5d0600
  ecx = esi;  // @554_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p84_));  // @555_5d0600
  ecx = edx = 0;  // @556_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_5d0600
  ecx = (u32)(EBP - 12);  // @558_5d0600
  p85_ = ecx;  // @559_5d0600
  ecx = esi;  // @560_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p85_));  // @561_5d0600
  ecx = edx = 0;  // @562_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @563_5d0600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @564_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @565_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @566_5d0600
  ecx = edx = 0;  // @567_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3608), &v, sizeof v); }  // @568_5d0600
  ecx = (u32)(EBP - 4);  // @569_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @570_5d0600
  p86_ = ecx;  // @571_5d0600
  ecx = esi;  // @572_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p86_));  // @573_5d0600
  ecx = edx = 0;  // @574_5d0600
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @575_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3612), &v, sizeof v); }  // @576_5d0600
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @577_5d0600
  __asm__ volatile("" :: "Yz"(x0));  // @578_5d0600
  return eax;  // @579_5d0600
}
PCREG(5d0600, lifted_5d0600);

extern "C" u32 THISCALL lifted_532f30(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_532f30
  edx = ecx;  // @1_532f30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_532f30
  x1 = _mm_load_ss((const float *)(u32)(edi + 136));  // @3_532f30
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edi + 132)));  // @4_532f30
  _mm_store_ss((float *)(u32)(esi + 76), x1);  // @5_532f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @6_532f30
  eax = (u32)(edx + ecx*8);  // @7_532f30
  x0 = _mm_load_ss((const float *)(u32)(ecx + eax + 20825));  // @8_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 20913)));  // @9_532f30
  x0 = _mm_mul_ss(x0, x1);  // @10_532f30
  _mm_store_ss((float *)(u32)(esi + 76), x0);  // @11_532f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @12_532f30
  eax = (u32)(edx + ecx*8);  // @13_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax + 20830), sizeof v); (u32)v; });  // @14_532f30
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; }));  // @15_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @16_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @17_532f30
  eax = (eax - 1);  // @18_532f30
  if (eax > (u32)(9)) goto L5330c8;  // @19_532f30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5452012), sizeof v); (u32)v; });  // @20_532f30
  switch (eax) { case 0: goto L53306d; case 1: goto L532fa0; case 2: goto L532fc0; default: __builtin_trap(); }  // @21_532f30
  L532fa0:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @23_532f30
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @24_532f30
  { u32 v = (u32)((u32)(116)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @25_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; });  // @26_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @27_532f30
  __asm__ volatile("" :: "Yz"(x0));  // @28_532f30
  return eax;  // @29_532f30
  L532fc0:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @31_532f30
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @32_532f30
  { u32 v = (u32)((u32)(192)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @33_532f30
  x0 = _mm_load_ss((const float *)(u32)(edi + 88));  // @34_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 84)));  // @35_532f30
  _mm_store_ss((float *)(u32)(esi + 172), x0);  // @36_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @37_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @38_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @39_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @40_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @41_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @42_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @43_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 188), &v, sizeof v); }  // @44_532f30
  L53300a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 224), sizeof v); (u32)v; });  // @46_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @47_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 228), sizeof v); (u32)v; });  // @48_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @49_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 232), sizeof v); (u32)v; });  // @50_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @51_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 212), sizeof v); (u32)v; });  // @52_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @53_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 216), sizeof v); (u32)v; });  // @54_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @55_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 220), sizeof v); (u32)v; });  // @56_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @57_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @58_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @59_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @60_532f30
  __asm__ volatile("" :: "Yz"(x0));  // @61_532f30
  return eax;  // @62_532f30
  L53306d:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @64_532f30
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @65_532f30
  { u32 v = (u32)((u32)(192)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @66_532f30
  x0 = _mm_load_ss((const float *)(u32)(edi + 88));  // @67_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 84)));  // @68_532f30
  _mm_store_ss((float *)(u32)(esi + 172), x0);  // @69_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @70_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @71_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @72_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @73_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @74_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @75_532f30
  x0 = _mm_load_ss((const float *)(u32)(edi + 76));  // @76_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6802752)));  // @77_532f30
  _mm_store_ss((float *)(u32)(esi + 188), x0);  // @78_532f30
  goto L53300a;  // @79_532f30
  L5330c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @81_532f30
  if ((eax & eax) == 0) goto L5330d9;  // @82_532f30
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @83_532f30
  ecx = edx = 0;  // @84_532f30
  __asm__ volatile("" :: "Yz"(x0));  // @85_532f30
  return eax;  // @86_532f30
  L5330d9:;
  __builtin_trap();  // @88_532f30
}
PCREG(532f30, lifted_532f30);

extern "C" u32 THISCALL lifted_4c0e20(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c0e20
  esi = ecx;  // @1_4c0e20
  ecx = edi;  // @2_4c0e20
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @3_4c0e20
  ecx = edx = 0;  // @4_4c0e20
  ecx = edi;  // @5_4c0e20
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 72), &v, 4); }  // @6_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @7_4c0e20
  ecx = edx = 0;  // @8_4c0e20
  ecx = edi;  // @9_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @10_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @11_4c0e20
  ecx = edx = 0;  // @12_4c0e20
  ecx = edi;  // @13_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @14_4c0e20
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @15_4c0e20
  ecx = edx = 0;  // @16_4c0e20
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 84), &v, 4); }  // @17_4c0e20
  ecx = edi;  // @18_4c0e20
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @19_4c0e20
  ecx = edx = 0;  // @20_4c0e20
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 88), &v, 4); }  // @21_4c0e20
  ecx = edi;  // @22_4c0e20
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @23_4c0e20
  ecx = edx = 0;  // @24_4c0e20
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 92), &v, 4); }  // @25_4c0e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @27_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0e80;  // @28_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @29_4c0e20
  if ((eax & 0xff) != (u32)(2)) goto L4c0e80;  // @30_4c0e20
  ecx = edi;  // @31_4c0e20
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @32_4c0e20
  ecx = edx = 0;  // @33_4c0e20
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 96), &v, 4); }  // @34_4c0e20
  goto L4c0e87;  // @35_4c0e20
  L4c0e80:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @37_4c0e20
  L4c0e87:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @40_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0ea1;  // @41_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @42_4c0e20
  if ((eax & 0xff) != (u32)(3)) goto L4c0ea1;  // @43_4c0e20
  ecx = edi;  // @44_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @45_4c0e20
  ecx = edx = 0;  // @46_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @47_4c0e20
  goto L4c0ea8;  // @48_4c0e20
  L4c0ea1:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @50_4c0e20
  L4c0ea8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @53_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0ec7;  // @54_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @55_4c0e20
  if ((eax & 0xff) != (u32)(3)) goto L4c0ec7;  // @56_4c0e20
  ecx = edi;  // @57_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @58_4c0e20
  ecx = edx = 0;  // @59_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)((eax & eax) != 0)) & 0xff);  // @60_4c0e20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @61_4c0e20
  goto L4c0ecb;  // @62_4c0e20
  L4c0ec7:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @64_4c0e20
  L4c0ecb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @67_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0ee5;  // @68_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @69_4c0e20
  if ((eax & 0xff) != (u32)(2)) goto L4c0ee5;  // @70_4c0e20
  ecx = edi;  // @71_4c0e20
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @72_4c0e20
  ecx = edx = 0;  // @73_4c0e20
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 105), &v, 4); }  // @74_4c0e20
  goto L4c0eec;  // @75_4c0e20
  L4c0ee5:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }  // @77_4c0e20
  L4c0eec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @80_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0f06;  // @81_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @82_4c0e20
  if ((eax & 0xff) != (u32)(3)) goto L4c0f06;  // @83_4c0e20
  ecx = edi;  // @84_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @85_4c0e20
  ecx = edx = 0;  // @86_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @87_4c0e20
  goto L4c0f0d;  // @88_4c0e20
  L4c0f06:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @90_4c0e20
  L4c0f0d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @92_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @93_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0f50;  // @94_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @95_4c0e20
  if ((eax & 0xff) != (u32)(3)) goto L4c0f50;  // @96_4c0e20
  ecx = edi;  // @97_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @98_4c0e20
  ecx = edx = 0;  // @99_4c0e20
  if (eax > (u32)(3)) goto L4c0f50;  // @100_4c0e20
  switch (eax) { case 0: goto L4c0f2e; case 1: goto L4c0f37; case 2: goto L4c0f40; case 3: goto L4c0f49; case 4: goto L4c0fb7; case 5: goto L4c0fd0; case 6: goto L4c0fe9; case 7: goto L4c1002; case 8: goto L4c101b; default: __builtin_trap(); }  // @101_4c0e20
  L4c0f2e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @103_4c0e20
  goto L4c0f50;  // @104_4c0e20
  L4c0f37:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @106_4c0e20
  goto L4c0f50;  // @107_4c0e20
  L4c0f40:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @109_4c0e20
  goto L4c0f50;  // @110_4c0e20
  L4c0f49:;
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @112_4c0e20
  L4c0f50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @114_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @115_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0f6a;  // @116_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @117_4c0e20
  if ((eax & 0xff) != (u32)(3)) goto L4c0f6a;  // @118_4c0e20
  ecx = edi;  // @119_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @120_4c0e20
  ecx = edx = 0;  // @121_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @122_4c0e20
  goto L4c0f71;  // @123_4c0e20
  L4c0f6a:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @125_4c0e20
  L4c0f71:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @127_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @128_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c0f8b;  // @129_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @130_4c0e20
  if ((eax & 0xff) != (u32)(3)) goto L4c0f8b;  // @131_4c0e20
  ecx = edi;  // @132_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @133_4c0e20
  ecx = edx = 0;  // @134_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 125), &v, sizeof v); }  // @135_4c0e20
  goto L4c0f92;  // @136_4c0e20
  L4c0f8b:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 125), &v, sizeof v); }  // @138_4c0e20
  L4c0f92:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @140_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @141_4c0e20
  if ((eax & 0xff) == (u32)(255)) goto L4c1022;  // @142_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @143_4c0e20
  if ((eax & 0xff) != (u32)(3)) goto L4c1022;  // @144_4c0e20
  ecx = edi;  // @145_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @146_4c0e20
  ecx = edx = 0;  // @147_4c0e20
  if (eax > (u32)(4)) goto L4c1022;  // @148_4c0e20
  switch (eax) { case 0: goto L4c0fb7; case 1: goto L4c0fd0; case 2: goto L4c0fe9; case 3: goto L4c1002; case 4: goto L4c101b; default: __builtin_trap(); }  // @149_4c0e20
  L4c0fb7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_4c0e20
  ecx = esi;  // @152_4c0e20
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @153_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @154_4c0e20
  ecx = edx = 0;  // @155_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @156_4c0e20
  return eax;  // @157_4c0e20
  L4c0fd0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @159_4c0e20
  ecx = esi;  // @160_4c0e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @161_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @162_4c0e20
  ecx = edx = 0;  // @163_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @164_4c0e20
  return eax;  // @165_4c0e20
  L4c0fe9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @167_4c0e20
  ecx = esi;  // @168_4c0e20
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @169_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @170_4c0e20
  ecx = edx = 0;  // @171_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @172_4c0e20
  return eax;  // @173_4c0e20
  L4c1002:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @175_4c0e20
  ecx = esi;  // @176_4c0e20
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @177_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @178_4c0e20
  ecx = edx = 0;  // @179_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @180_4c0e20
  return eax;  // @181_4c0e20
  L4c101b:;
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @183_4c0e20
  L4c1022:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @185_4c0e20
  ecx = esi;  // @186_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @187_4c0e20
  ecx = edx = 0;  // @188_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @189_4c0e20
  return eax;  // @190_4c0e20
}
PCREG(4c0e20, lifted_4c0e20);

extern "C" u32 THISCALL lifted_610860(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_610860
  eax = (u32)(ecx - 1);  // @2_610860
  if (eax > (u32)(7)) goto L610b6c;  // @3_610860
  switch (eax) { case 0: goto L61087d; case 1: goto L610940; case 2: goto L610b0d; case 3: goto L610b6c; case 4: goto L610b6c; case 5: goto L610b6c; case 6: goto L6109fd; case 7: goto L610a52; default: __builtin_trap(); }  // @4_610860
  L61087d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4879), sizeof v); (u32)v; });  // @6_610860
  if (eax <= (u32)(1)) goto L610917;  // @7_610860
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @8_610860
  if ((edi & edi) == 0) goto L61089f;  // @9_610860
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7273596), &v, sizeof v); }  // @10_610860
  edx = (u32)(3);  // @11_610860
  goto L6108ae;  // @12_610860
  L61089f:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7273596), &v, sizeof v); }  // @14_610860
  edx = (u32)(2);  // @15_610860
  L6108ae:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7273584), &v, sizeof v); }  // @17_610860
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7273588), &v, sizeof v); }  // @18_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @19_610860
  p0_ = edx;  // @20_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_610860
  p1_ = eax;  // @22_610860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, (u32)(p1_), (u32)(0), (u32)(17), (u32)(p0_));  // @23_610860
  ecx = edx = 0;  // @24_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @25_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_610860
  p2_ = eax;  // @27_610860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, (u32)(p2_), (u32)(0), (u32)(16), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273584), sizeof v); (u32)v; }));  // @28_610860
  ecx = edx = 0;  // @29_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @30_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_610860
  p3_ = eax;  // @32_610860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, (u32)(p3_), (u32)(0), (u32)(21), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273596), sizeof v); (u32)v; }));  // @33_610860
  ecx = edx = 0;  // @34_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @36_610860
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 141), &v, sizeof v); }  // @37_610860
  return eax;  // @38_610860
  L610917:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @40_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_610860
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7064448), (u32)(1337));  // @42_610860
  ecx = edx = 0;  // @43_610860
  p4_ = eax;  // @44_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_610860
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p4_), (u32)(7066540));  // @46_610860
  ecx = edx = 0;  // @47_610860
  return eax;  // @48_610860
  L610940:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_610860
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @51_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @52_610860
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 137), sizeof v); (u32)v; }) == edi) goto L610b77;  // @53_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490360), sizeof v); (u32)v; });  // @54_610860
  p5_ = edi;  // @55_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @56_610860
  p6_ = eax;  // @57_610860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p6_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5091), sizeof v); (u32)v; }), (u32)(1), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4995), sizeof v); (u32)v; }), (u32)(0), (u32)(p5_));  // @58_610860
  ecx = edx = 0;  // @59_610860
  if ((s32)(eax & eax) < 0) goto L6109d4;  // @60_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @62_610860
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 137), &v, sizeof v); }  // @63_610860
  x0 = _mm_loadu_ps((const float *)(u32)(esi + 4987));  // @64_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5035), sizeof v); (u32)v; });  // @65_610860
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 5105), &v, sizeof v); }  // @66_610860
  _mm_storeu_ps((float *)(u32)(esi + 5039), x0);  // @67_610860
  x0 = _mm_loadu_ps((const float *)(u32)(esi + 5003));  // @68_610860
  _mm_storeu_ps((float *)(u32)(esi + 5055), x0);  // @69_610860
  x0 = _mm_loadu_ps((const float *)(u32)(esi + 5019));  // @70_610860
  _mm_storeu_ps((float *)(u32)(esi + 5071), x0);  // @71_610860
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 5087), &v, sizeof v); }  // @72_610860
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 5055), &v, sizeof v); }  // @73_610860
  __asm__ volatile("" :: "Yz"(x0));  // @74_610860
  return eax;  // @75_610860
  L6109d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @77_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_610860
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7064448), (u32)(1350));  // @79_610860
  ecx = edx = 0;  // @80_610860
  p7_ = eax;  // @81_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @82_610860
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p7_), (u32)(7066588));  // @83_610860
  ecx = edx = 0;  // @84_610860
  __asm__ volatile("" :: "Yz"(x0));  // @85_610860
  return eax;  // @86_610860
  L6109fd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5095), sizeof v); (u32)v; });  // @88_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @90_610860
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @91_610860
  ecx = edx = 0;  // @92_610860
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L610a29;  // @93_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @94_610860
  ecx = (ecx & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == (u32)(0))) & 0xff);  // @95_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @96_610860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 116), &v, sizeof v); }  // @97_610860
  __asm__ volatile("" :: "Yz"(x0));  // @98_610860
  return eax;  // @99_610860
  L610a29:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @101_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_610860
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7064448), (u32)(1359));  // @103_610860
  ecx = edx = 0;  // @104_610860
  p8_ = eax;  // @105_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @106_610860
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p8_), (u32)(7066624));  // @107_610860
  ecx = edx = 0;  // @108_610860
  __asm__ volatile("" :: "Yz"(x0));  // @109_610860
  return eax;  // @110_610860
  L610a52:;
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4835), sizeof v); (u32)v; }) & (u32)(131072)) == 0) goto L610ae4;  // @112_610860
  edi = 0;  // @113_610860
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == edi) goto L610a9a;  // @114_610860
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490056), sizeof v); (u32)v; }) <= edi) goto L610a8e;  // @115_610860
  L610a71:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @117_610860
  p9_ = edi;  // @118_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @119_610860
  p10_ = eax;  // @120_610860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, (u32)(p10_), (u32)(p9_), (u32)(18), (u32)(2));  // @121_610860
  ecx = edx = 0;  // @122_610860
  edi = (edi + 1);  // @123_610860
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490056), sizeof v); (u32)v; })) goto L610a71;  // @124_610860
  L610a8e:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(7273592), &v, sizeof v); }  // @126_610860
  goto L610ac9;  // @127_610860
  L610a9a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490056), sizeof v); (u32)v; }) <= edi) goto L610abf;  // @129_610860
  L610aa2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @131_610860
  p11_ = edi;  // @132_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @133_610860
  p12_ = eax;  // @134_610860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, (u32)(p12_), (u32)(p11_), (u32)(18), (u32)(1));  // @135_610860
  ecx = edx = 0;  // @136_610860
  edi = (edi + 1);  // @137_610860
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490056), sizeof v); (u32)v; })) goto L610aa2;  // @138_610860
  L610abf:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7273592), &v, sizeof v); }  // @140_610860
  L610ac9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @142_610860
  ecx = (ecx & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @143_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @144_610860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 114), &v, sizeof v); }  // @145_610860
  __asm__ volatile("" :: "Yz"(x0));  // @146_610860
  return eax;  // @147_610860
  L610ae4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @149_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_610860
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7064448), (u32)(1378));  // @151_610860
  ecx = edx = 0;  // @152_610860
  p13_ = eax;  // @153_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @154_610860
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p13_), (u32)(7066652));  // @155_610860
  ecx = edx = 0;  // @156_610860
  __asm__ volatile("" :: "Yz"(x0));  // @157_610860
  return eax;  // @158_610860
  L610b0d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5095), sizeof v); (u32)v; });  // @160_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @162_610860
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @163_610860
  ecx = edx = 0;  // @164_610860
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L610b43;  // @165_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @166_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @167_610860
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L610b39;  // @168_610860
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 109), &v, sizeof v); }  // @169_610860
  __asm__ volatile("" :: "Yz"(x0));  // @170_610860
  return eax;  // @171_610860
  L610b39:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 109), &v, sizeof v); }  // @173_610860
  __asm__ volatile("" :: "Yz"(x0));  // @174_610860
  return eax;  // @175_610860
  L610b43:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @177_610860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_610860
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7064448), (u32)(1390));  // @179_610860
  ecx = edx = 0;  // @180_610860
  p14_ = eax;  // @181_610860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @182_610860
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p14_), (u32)(7066696));  // @183_610860
  ecx = edx = 0;  // @184_610860
  __asm__ volatile("" :: "Yz"(x0));  // @185_610860
  return eax;  // @186_610860
  L610b6c:;
  p15_ = ecx;  // @188_610860
  ecx = esi;  // @189_610860
  eax = ext_658c40_stdcall2((u32)(p15_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @190_610860
  ecx = edx = 0;  // @191_610860
  L610b77:;
  __asm__ volatile("" :: "Yz"(x0));  // @193_610860
  return eax;  // @194_610860
}
PCREG(610860, lifted_610860);

extern "C" u32 STDCALL lifted_4bb830(u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_4bb830
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4bb830
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4bb830
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; }) == (u32)(0)) goto L4bb945;  // @2_4bb830
  ecx = edi;  // @3_4bb830
  ebx = (u32)(1);  // @4_4bb830
  eax = ext_4e5ea0_thiscall1(ecx);  // @5_4bb830
  ecx = edx = 0;  // @6_4bb830
  p0_ = eax;  // @7_4bb830
  ecx = (u32)(EBP - 144);  // @8_4bb830
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @9_4bb830
  ecx = edx = 0;  // @10_4bb830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4bb830
  ecx = (u32)(EBP - 144);  // @12_4bb830
  reg.state = (s32)((u32)(0));  // @13_4bb830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @14_4bb830
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_4bb830
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_4bb830
  ecx = edx = 0;  // @17_4bb830
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4bb830
  p1_ = eax;  // @19_4bb830
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @20_4bb830
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 108)))(ecx, (u32)(p1_));  // @21_4bb830
  ecx = edx = 0;  // @22_4bb830
  ecx = edi;  // @23_4bb830
  esi = eax;  // @24_4bb830
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @25_4bb830
  ecx = edx = 0;  // @26_4bb830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_4bb830
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 148), &v, 4); }  // @28_4bb830
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @29_4bb830
  if ((eax & 0xff) == (u32)(255)) goto L4bb8e0;  // @30_4bb830
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @31_4bb830
  if ((eax & 0xff) != (u32)(3)) goto L4bb8e0;  // @32_4bb830
  ecx = edi;  // @33_4bb830
  eax = ext_4e5e60_thiscall1(ecx);  // @34_4bb830
  ecx = edx = 0;  // @35_4bb830
  ebx = eax;  // @36_4bb830
  L4bb8e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_4bb830
  p2_ = esi;  // @39_4bb830
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @40_4bb830
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @41_4bb830
  eax = ext_43eb80_stdcall1((u32)(p2_));  // @42_4bb830
  ecx = edx = 0;  // @43_4bb830
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4bb830
  p3_ = eax;  // @45_4bb830
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @46_4bb830
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4bb830
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(p3_));  // @48_4bb830
  ecx = edx = 0;  // @49_4bb830
  if ((eax & eax) == 0) goto L4bb93a;  // @50_4bb830
  x0 = _mm_load_ss((const float *)(u32)(EBP - 148));  // @51_4bb830
  _mm_store_ss((float *)(u32)(eax + 136), x0);  // @52_4bb830
  if ((ebx & ebx) == 0) goto L4bb928;  // @53_4bb830
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(eax + 64), &v, sizeof v); }  // @54_4bb830
  goto L4bb92c;  // @55_4bb830
  L4bb928:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) & (u32)(4294967287))); __builtin_memcpy((void *)(u32)(eax + 64), &v, sizeof v); }  // @57_4bb830
  L4bb92c:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) | (u32)(128))); __builtin_memcpy((void *)(u32)(eax + 64), &v, sizeof v); }  // @59_4bb830
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(eax + 44), &v, sizeof v); }  // @60_4bb830
  L4bb93a:;
  ecx = (u32)(EBP - 144);  // @62_4bb830
  eax = ext_4cbec0_thiscall1(ecx);  // @63_4bb830
  ecx = edx = 0;  // @64_4bb830
  L4bb945:;
  SEH_LEAVE();  // @66_4bb830
  ext_633654(G(u32, 0x6f5630));  // @67_4bb830
  __asm__ volatile("" :: "Yz"(x0));  // @68_4bb830
  return eax;  // @69_4bb830
}
PCREG(4bb830, lifted_4bb830);

extern "C" u32 THISCALL lifted_45fb40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6685bb);  // @h_45fb40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_45fb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_45fb40
  eax = ext_4da3a0_thiscall1(ecx);  // @2_45fb40
  ecx = edx = 0;  // @3_45fb40
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L45fbee;  // @4_45fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @5_45fb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @6_45fb40
  if ((ecx & ecx) == 0) goto L45fbee;  // @7_45fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_45fb40
  edx = (u32)(EBP - 156);  // @9_45fb40
  p0_ = edx;  // @10_45fb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @11_45fb40
  ecx = edx = 0;  // @12_45fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @13_45fb40
  edx = (u32)(EBP - 156);  // @14_45fb40
  p1_ = edx;  // @15_45fb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @16_45fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_45fb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @18_45fb40
  ecx = edx = 0;  // @19_45fb40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; }) == (u32)(0)) goto L45fbee;  // @20_45fb40
  L45fbb0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @22_45fb40
  p2_ = eax;  // @23_45fb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_45fb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(p2_));  // @25_45fb40
  ecx = edx = 0;  // @26_45fb40
  if ((eax & eax) == 0) goto L45fbd3;  // @27_45fb40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L45fbd3;  // @28_45fb40
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; }) & (u32)(8)) != 0) goto L45fc5d;  // @29_45fb40
  L45fbd3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @31_45fb40
  edx = (u32)(EBP - 156);  // @32_45fb40
  p3_ = edx;  // @33_45fb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @34_45fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_45fb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p3_));  // @36_45fb40
  ecx = edx = 0;  // @37_45fb40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; }) != (u32)(0)) goto L45fbb0;  // @38_45fb40
  L45fbee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @40_45fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_45fb40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1469));  // @42_45fb40
  ecx = edx = 0;  // @43_45fb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @44_45fb40
  edi = eax;  // @45_45fb40
  eax = (u32)(EBP - 144);  // @46_45fb40
  ecx = esi;  // @47_45fb40
  p4_ = eax;  // @48_45fb40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p4_), (u32)(1));  // @49_45fb40
  ecx = edx = 0;  // @50_45fb40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_45fb40
  ecx = eax;  // @52_45fb40
  reg.state = (s32)((u32)(0));  // @53_45fb40
  eax = ext_4cc1d0_thiscall1(ecx);  // @54_45fb40
  ecx = edx = 0;  // @55_45fb40
  p5_ = eax;  // @56_45fb40
  p6_ = edi;  // @57_45fb40
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p6_), (u32)(6836520), (u32)(p5_));  // @58_45fb40
  ecx = edx = 0;  // @59_45fb40
  ecx = (u32)(EBP - 144);  // @60_45fb40
  eax = ext_4cbec0_thiscall1(ecx);  // @61_45fb40
  ecx = edx = 0;  // @62_45fb40
  L45fc40:;
  SEH_LEAVE();  // @64_45fb40
  ext_633654(G(u32, 0x6f5630));  // @65_45fb40
  return eax;  // @66_45fb40
  L45fc5d:;
  x0 = _mm_load_ss((const float *)(u32)(EBP + 8));  // @68_45fb40
  _mm_store_ss((float *)(u32)(eax + 12), x0);  // @69_45fb40
  goto L45fc40;  // @70_45fb40
}
PCREG(45fb40, lifted_45fb40);

extern "C" u32 THISCALL lifted_5a50e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66bf70);  // @h_5a50e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_5a50e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5a50e0
  eax = ext_43de40_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_5a50e0
  ecx = edx = 0;  // @3_5a50e0
  { u32 v = (u32)((u32)(7008876)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5a50e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5a50e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_5a50e0
  reg.state = (s32)((u32)(0));  // @7_5a50e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5a50e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @9_5a50e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(6881100), (u32)(0), (u32)(7009948), (u32)(169));  // @10_5a50e0
  ecx = edx = 0;  // @11_5a50e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 1352), &v, sizeof v); }  // @12_5a50e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_5a50e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @14_5a50e0
  reg.state = (s32)((u32)(1));  // @15_5a50e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5a50e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @17_5a50e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(6881100), (u32)(0), (u32)(7009948), (u32)(169));  // @18_5a50e0
  ecx = edx = 0;  // @19_5a50e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 1366), &v, sizeof v); }  // @20_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1625), &v, sizeof v); }  // @21_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1629), &v, sizeof v); }  // @22_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1633), &v, sizeof v); }  // @23_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1637), &v, sizeof v); }  // @24_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1641), &v, sizeof v); }  // @25_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1645), &v, sizeof v); }  // @26_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1649), &v, sizeof v); }  // @27_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1653), &v, sizeof v); }  // @28_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1657), &v, sizeof v); }  // @29_5a50e0
  x0 = _mm_setzero_ps();  // @30_5a50e0
  reg.state = (s32)((u32)(5));  // @31_5a50e0
  _mm_storeu_ps((float *)(u32)(esi + 2223), x0);  // @32_5a50e0
  _mm_storeu_ps((float *)(u32)(esi + 2239), x0);  // @33_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2260), &v, sizeof v); }  // @34_5a50e0
  { u32 v = (u32)((u32)(268435455)); __builtin_memcpy((void *)(u32)(esi + 772), &v, sizeof v); }  // @35_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7422716), &v, sizeof v); }  // @36_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2202), &v, sizeof v); }  // @37_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2206), &v, sizeof v); }  // @38_5a50e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2201), &v, sizeof v); }  // @39_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1693), &v, sizeof v); }  // @40_5a50e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2210), &v, sizeof v); }  // @41_5a50e0
  { u32 v = (u32)((u32)(60)); __builtin_memcpy((void *)(u32)(esi + 1689), &v, sizeof v); }  // @42_5a50e0
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 1685), &v, sizeof v); }  // @43_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1677), &v, sizeof v); }  // @44_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1669), &v, sizeof v); }  // @45_5a50e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2256), &v, sizeof v); }  // @46_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1204), &v, sizeof v); }  // @47_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1665), &v, sizeof v); }  // @48_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1661), &v, sizeof v); }  // @49_5a50e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1624), &v, sizeof v); }  // @50_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2215), &v, sizeof v); }  // @51_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2219), &v, sizeof v); }  // @52_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1080), &v, sizeof v); }  // @53_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1084), &v, sizeof v); }  // @54_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1072), &v, sizeof v); }  // @55_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1592), &v, sizeof v); }  // @56_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1600), &v, sizeof v); }  // @57_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1608), &v, sizeof v); }  // @58_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1136), &v, sizeof v); }  // @59_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1616), &v, sizeof v); }  // @60_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1148), &v, sizeof v); }  // @61_5a50e0
  { u32 v = (u32)((u32)(268435455)); __builtin_memcpy((void *)(u32)(esi + 768), &v, sizeof v); }  // @62_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 852), &v, sizeof v); }  // @63_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 872), &v, sizeof v); }  // @64_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 876), &v, sizeof v); }  // @65_5a50e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 892), &v, sizeof v); }  // @66_5a50e0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(esi + 962), &v, sizeof v); }  // @67_5a50e0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 966), &v, sizeof v); }  // @68_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 893), &v, sizeof v); }  // @69_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 901), &v, sizeof v); }  // @70_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 897), &v, sizeof v); }  // @71_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 905), &v, sizeof v); }  // @72_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 909), &v, sizeof v); }  // @73_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 922), &v, sizeof v); }  // @74_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 926), &v, sizeof v); }  // @75_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 868), &v, sizeof v); }  // @76_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 976), &v, sizeof v); }  // @77_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 884), &v, sizeof v); }  // @78_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 888), &v, sizeof v); }  // @79_5a50e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1068), &v, sizeof v); }  // @80_5a50e0
  { u32 v = (u32)((u32)(1287568416)); __builtin_memcpy((void *)(u32)(esi + 764), &v, sizeof v); }  // @81_5a50e0
  { u32 v = (u32)((u32)(100000000)); __builtin_memcpy((void *)(u32)(esi + 880), &v, sizeof v); }  // @82_5a50e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2255), &v, sizeof v); }  // @83_5a50e0
  eax = ext_41e290_cdecl1((u32)(264));  // @84_5a50e0
  ecx = edx = 0;  // @85_5a50e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @86_5a50e0
  reg.state = (s32)((u32)(6));  // @87_5a50e0
  if ((eax & eax) == 0) goto L5a5407;  // @88_5a50e0
  ecx = eax;  // @89_5a50e0
  eax = ext_4d83b0_thiscall4(ecx, (u32)(7012016), (u32)(7011988), (u32)(7422712));  // @90_5a50e0
  ecx = edx = 0;  // @91_5a50e0
  edx = eax;  // @92_5a50e0
  goto L5a5409;  // @93_5a50e0
  L5a5407:;
  edx = 0;  // @95_5a50e0
  L5a5409:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @97_5a50e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @98_5a50e0
  p0_ = edx;  // @99_5a50e0
  reg.state = (s32)((u32)(5));  // @100_5a50e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @101_5a50e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p0_));  // @102_5a50e0
  ecx = edx = 0;  // @103_5a50e0
  eax = esi;  // @104_5a50e0
  SEH_LEAVE();  // @105_5a50e0
  __asm__ volatile("" :: "Yz"(x0));  // @106_5a50e0
  return eax;  // @107_5a50e0
}
PCREG(5a50e0, lifted_5a50e0);

extern "C" u32 THISCALL lifted_57e930(u32 ecx_in) {
  SEH_ENTER(0x66b3bb);  // @h_57e930
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 572), sizeof v); (u32)v; });  // @0_57e930
  esi = (u32)(ecx + 572);  // @1_57e930
  edi = 0;  // @2_57e930
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @3_57e930
  ecx = esi;  // @4_57e930
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @5_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @6_57e930
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @7_57e930
  ecx = edx = 0;  // @8_57e930
  if ((s32)(eax & eax) <= 0) goto L57eb89;  // @9_57e930
  L57e986:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_57e930
  ecx = esi;  // @12_57e930
  p0_ = edi;  // @13_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @14_57e930
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p0_));  // @15_57e930
  ecx = edx = 0;  // @16_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @17_57e930
  p1_ = eax;  // @18_57e930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 204), sizeof v); (u32)v; });  // @20_57e930
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p1_));  // @21_57e930
  ecx = edx = 0;  // @22_57e930
  esi = eax;  // @23_57e930
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @24_57e930
  if ((esi & esi) == 0) goto L57eb6b;  // @25_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6407), sizeof v); (u32)v; });  // @27_57e930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_57e930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 96), sizeof v); (u32)v; });  // @29_57e930
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(6932112));  // @30_57e930
  ecx = edx = 0;  // @31_57e930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @32_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 21), sizeof v); (u32)v; });  // @33_57e930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_57e930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @35_57e930
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @36_57e930
  ecx = edx = 0;  // @37_57e930
  x0 = _mm_loadu_ps((const float *)(u32)(6791824));  // @38_57e930
  edx = eax;  // @39_57e930
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 204), &v, sizeof v); }  // @40_57e930
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 205), &v, sizeof v); }  // @41_57e930
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 209), &v, sizeof v); }  // @42_57e930
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 219), &v, sizeof v); }  // @43_57e930
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @44_57e930
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @45_57e930
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @46_57e930
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 211), &v, sizeof v); }  // @47_57e930
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 215), &v, sizeof v); }  // @48_57e930
  _mm_storeu_ps((float *)(u32)(esi + 188), x0);  // @49_57e930
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @50_57e930
  esi = 0;  // @51_57e930
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @52_57e930
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @53_57e930
  if ((edi & edi) == 0) goto L57eb65;  // @54_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @55_57e930
  esi = edx;  // @56_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @58_57e930
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @59_57e930
  L57ea68:;
  eax = edi;  // @61_57e930
  L57ea70:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @63_57e930
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L57ea90;  // @64_57e930
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L57ea8c;  // @65_57e930
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @66_57e930
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L57ea90;  // @67_57e930
  ecx = (ecx + (u32)(2));  // @68_57e930
  eax = (eax + (u32)(2));  // @69_57e930
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L57ea70;  // @70_57e930
  L57ea8c:;
  eax = 0;  // @72_57e930
  goto L57ea95;  // @73_57e930
  L57ea90:;
  eax = 0;  // @75_57e930
  eax = (eax | (u32)(1));  // @76_57e930
  L57ea95:;
  if ((eax & eax) == 0) goto L57eab3;  // @78_57e930
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @79_57e930
  esi = (esi + (u32)(28));  // @80_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @81_57e930
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_57e930
  if ((edi & edi) != 0) goto L57ea68;  // @83_57e930
  goto L57eb65;  // @84_57e930
  L57eab3:;
  p2_ = edi;  // @86_57e930
  ecx = (u32)(EBP - 144);  // @87_57e930
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p2_));  // @88_57e930
  ecx = edx = 0;  // @89_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @90_57e930
  eax = (u32)(EBP - 144);  // @91_57e930
  p3_ = eax;  // @92_57e930
  reg.state = (s32)((u32)(0));  // @93_57e930
  ecx = (u32)(ecx + 44);  // @94_57e930
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p3_));  // @95_57e930
  ecx = edx = 0;  // @96_57e930
  ecx = (u32)(EBP - 144);  // @97_57e930
  reg.state = (s32)((u32)(4294967295));  // @98_57e930
  eax = ext_4cbec0_thiscall1(ecx);  // @99_57e930
  ecx = edx = 0;  // @100_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @101_57e930
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @102_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 17), sizeof v); (u32)v; });  // @103_57e930
  eax = (u32)(esi*8);  // @104_57e930
  eax = (eax - esi);  // @105_57e930
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @106_57e930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 100), sizeof v); (u32)v; });  // @108_57e930
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4 + 8), sizeof v); (u32)v; }));  // @109_57e930
  ecx = edx = 0;  // @110_57e930
  edi = eax;  // @111_57e930
  if ((edi & (u32)(4294901760)) != 0) goto L57eb4b;  // @112_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @113_57e930
  edx = 0;  // @114_57e930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6411), sizeof v); (u32)v; });  // @115_57e930
  if ((ecx & ecx) == 0) goto L57eb48;  // @116_57e930
  esi = ecx;  // @117_57e930
  L57eb33:;
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) > (s32)edi) goto L57eb40;  // @119_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @120_57e930
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }));  // @121_57e930
  if ((s32)eax > (s32)edi) goto L57eba4;  // @122_57e930
  L57eb40:;
  edx = (edx + 1);  // @124_57e930
  esi = (esi + (u32)(16));  // @125_57e930
  ecx = esi;  // @126_57e930
  if (esi != 0) goto L57eb33;  // @127_57e930
  L57eb48:;
  edi = (edi | (u32)(4294967295));  // @129_57e930
  L57eb4b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @131_57e930
  ecx = eax;  // @132_57e930
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 172), &v, sizeof v); }  // @133_57e930
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 223), &v, sizeof v); }  // @134_57e930
  eax = ext_57ee90_thiscall1(ecx);  // @135_57e930
  ecx = edx = 0;  // @136_57e930
  L57eb65:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @138_57e930
  L57eb6b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @140_57e930
  edi = (edi + 1);  // @141_57e930
  ecx = esi;  // @142_57e930
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @143_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_57e930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @145_57e930
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @146_57e930
  ecx = edx = 0;  // @147_57e930
  if ((s32)edi < (s32)eax) goto L57e986;  // @148_57e930
  L57eb89:;
  SEH_LEAVE();  // @150_57e930
  ext_633654(G(u32, 0x6f5630));  // @151_57e930
  __asm__ volatile("" :: "Yz"(x0));  // @152_57e930
  return eax;  // @153_57e930
  L57eba4:;
  edx = (edx << (u32)(16));  // @155_57e930
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }));  // @156_57e930
  edi = (edi + edx);  // @157_57e930
  goto L57eb4b;  // @158_57e930
}
PCREG(57e930, lifted_57e930);

extern "C" u32 THISCALL lifted_4257b0(u32 ecx_in) {
  SEH_ENTER(0x66454b);  // @h_4257b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4257b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1172), &v, sizeof v); }  // @1_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_4257b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L425a3d;  // @3_4257b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }) == (u32)(0)) goto L425a2c;  // @4_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4257b0
  x1 = _mm_load_ss((const float *)(u32)(6785112));  // @6_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @7_4257b0
  x0 = _mm_load_ss((const float *)(u32)(eax + 88));  // @8_4257b0
  x0 = _mm_div_ss(x0, _mm_load_ss((const float *)(u32)(6785116)));  // @9_4257b0
  x1 = _mm_div_ss(x1, x0);  // @10_4257b0
  _mm_store_ss((float *)(u32)(EBP - 1168), x1);  // @11_4257b0
  if ((ecx & ecx) == 0) goto L425a2c;  // @12_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4257b0
  edx = (u32)(EBP - 1196);  // @14_4257b0
  p0_ = edx;  // @15_4257b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @16_4257b0
  ecx = edx = 0;  // @17_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @18_4257b0
  edx = (u32)(EBP - 1196);  // @19_4257b0
  p1_ = edx;  // @20_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4257b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @22_4257b0
  ecx = edx = 0;  // @23_4257b0
  esi = eax;  // @24_4257b0
  if ((esi & esi) == 0) goto L425a2c;  // @25_4257b0
  L425860:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @28_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4257b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @30_4257b0
  ecx = edx = 0;  // @31_4257b0
  ecx = eax;  // @32_4257b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1164), &v, sizeof v); }  // @33_4257b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(0)) goto L42588a;  // @34_4257b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @35_4257b0
  goto L42588d;  // @36_4257b0
  L42588a:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @38_4257b0
  L42588d:;
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) > (s32)(u32)(100)) goto L42589b;  // @40_4257b0
  if ((ecx & ecx) == 0) goto L42589b;  // @41_4257b0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @42_4257b0
  goto L42589d;  // @43_4257b0
  L42589b:;
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @45_4257b0
  L42589d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @47_4257b0
  if ((edx & edx) == 0) goto L425a66;  // @48_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @49_4257b0
  p2_ = edx;  // @50_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_4257b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(p2_));  // @52_4257b0
  ecx = edx = 0;  // @53_4257b0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L425a59;  // @54_4257b0
  if ((eax & eax) == 0) goto L425a6e;  // @55_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1164), sizeof v); (u32)v; });  // @56_4257b0
  L4258cd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4257b0
  edx = (u32)(EBP - 1160);  // @59_4257b0
  p3_ = edx;  // @60_4257b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, (u32)(p3_), (u32)(1));  // @61_4257b0
  ecx = edx = 0;  // @62_4257b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })));  // @63_4257b0
  ecx = (u32)(EBP - 1160);  // @64_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @65_4257b0
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @66_4257b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1032), &v, sizeof v); }  // @67_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @68_4257b0
  reg.state = (s32)((u32)(0));  // @69_4257b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1028), &v, sizeof v); }  // @70_4257b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 1168)));  // @71_4257b0
  _mm_store_ss((float *)(u32)(EBP - 1024), x0);  // @72_4257b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @73_4257b0
  ecx = edx = 0;  // @74_4257b0
  edx = (u32)(eax + 1);  // @75_4257b0
  L425920:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @77_4257b0
  eax = (eax + 1);  // @78_4257b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L425920;  // @79_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @80_4257b0
  eax = (eax - edx);  // @81_4257b0
  ebx = (u32)(eax + 1);  // @82_4257b0
  edx = (u32)(ecx + 1);  // @83_4257b0
  L425932:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @85_4257b0
  ecx = (ecx + 1);  // @86_4257b0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425932;  // @87_4257b0
  ecx = (ecx - edx);  // @88_4257b0
  edi = (u32)(ecx + 1);  // @89_4257b0
  eax = (u32)(edi + ebx);  // @90_4257b0
  if ((s32)eax <= (s32)(u32)(1000)) goto L425981;  // @91_4257b0
  L425950:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @93_4257b0
  ebx = (u32)((s32)ebx >> (u32)(1));  // @94_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_4257b0
  edi = (u32)((s32)edi >> (u32)(1));  // @96_4257b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6784708), (u32)(576));  // @97_4257b0
  ecx = edx = 0;  // @98_4257b0
  p4_ = eax;  // @99_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @100_4257b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 48)))(ecx, (u32)(p4_), (u32)(6784968));  // @101_4257b0
  ecx = edx = 0;  // @102_4257b0
  eax = (u32)(edi + ebx);  // @103_4257b0
  if ((s32)eax > (s32)(u32)(1000)) goto L425950;  // @104_4257b0
  L425981:;
  p5_ = ebx;  // @106_4257b0
  ecx = (u32)(EBP - 1160);  // @107_4257b0
  eax = ext_4cc1d0_cdecl1((u32)(p5_));  // @108_4257b0
  ecx = edx = 0;  // @109_4257b0
  p6_ = eax;  // @110_4257b0
  eax = (u32)(EBP - 1020);  // @111_4257b0
  p7_ = eax;  // @112_4257b0
  eax = ext_634d22_cdecl2((u32)(p7_), (u32)(p6_));  // @113_4257b0
  ecx = edx = 0;  // @114_4257b0
  p8_ = edi;  // @115_4257b0
  eax = (u32)(EBP - 1020);  // @116_4257b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + ebx - 1020), &v, sizeof v); }  // @117_4257b0
  eax = (eax + ebx);  // @118_4257b0
  p9_ = eax;  // @119_4257b0
  eax = ext_634d22_cdecl3((u32)(p9_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }), (u32)(p8_));  // @120_4257b0
  ecx = edx = 0;  // @121_4257b0
  eax = (u32)(edi + ebx);  // @122_4257b0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 1184), &v, sizeof v); }  // @123_4257b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1172), sizeof v); (u32)v; });  // @124_4257b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + eax - 1020), &v, sizeof v); }  // @125_4257b0
  eax = (eax + (u32)(14));  // @126_4257b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1180), &v, sizeof v); }  // @127_4257b0
  eax = (u32)(EBP - 1032);  // @128_4257b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1176), &v, sizeof v); }  // @129_4257b0
  eax = (u32)(EBP - 1184);  // @130_4257b0
  p10_ = eax;  // @131_4257b0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x67621c))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }), (u32)(74), (u32)(0), (u32)(p10_));  // @132_4257b0
  ecx = edx = 0;  // @133_4257b0
  ecx = (u32)(EBP - 1160);  // @134_4257b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @135_4257b0
  reg.state = (s32)((u32)(4294967295));  // @136_4257b0
  eax = ext_4cbec0_thiscall1(ecx);  // @137_4257b0
  ecx = edx = 0;  // @138_4257b0
  L425a13:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @140_4257b0
  edx = (u32)(EBP - 1196);  // @141_4257b0
  p11_ = edx;  // @142_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_4257b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p11_));  // @144_4257b0
  ecx = edx = 0;  // @145_4257b0
  esi = eax;  // @146_4257b0
  if ((esi & esi) != 0) goto L425860;  // @147_4257b0
  L425a2c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @149_4257b0
  ecx = edi;  // @150_4257b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(22), (u32)(0), (u32)(0));  // @151_4257b0
  ecx = edx = 0;  // @152_4257b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 17), &v, sizeof v); }  // @153_4257b0
  L425a3d:;
  SEH_LEAVE();  // @155_4257b0
  ext_633654(G(u32, 0x6f5630));  // @156_4257b0
  __asm__ volatile("" :: "Yz"(x0));  // @157_4257b0
  return eax;  // @158_4257b0
  L425a59:;
  if ((eax & eax) == 0) goto L425a6e;  // @160_4257b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 52), &v, sizeof v); }  // @161_4257b0
  goto L425a6e;  // @162_4257b0
  L425a66:;
  if (((ebx & 0xff) & (ebx & 0xff)) == 0) goto L4258cd;  // @164_4257b0
  L425a6e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_4257b0
  ecx = edi;  // @167_4257b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(21), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }), (u32)(0));  // @168_4257b0
  ecx = edx = 0;  // @169_4257b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @170_4257b0
  edx = (u32)(EBP - 1196);  // @171_4257b0
  p12_ = edx;  // @172_4257b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @173_4257b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p12_));  // @174_4257b0
  ecx = edx = 0;  // @175_4257b0
  goto L425a13;  // @176_4257b0
}
PCREG(4257b0, lifted_4257b0);

extern "C" u32 THISCALL lifted_634f90(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66a0d6);  // @h_634f90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_634f90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @1_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_634f90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_634f90
  if (eax != (u32)(1)) goto L634fdb;  // @4_634f90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4)) == 0) goto L634fea;  // @5_634f90
  goto L63526f;  // @6_634f90
  L634fdb:;
  if (eax != (u32)(2)) goto L634fea;  // @8_634f90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(8)) != 0) goto L63526f;  // @9_634f90
  L634fea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @11_634f90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @12_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @13_634f90
  ecx = (ecx & (u32)(4));  // @14_634f90
  if (ecx != 0) goto L635093;  // @15_634f90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L635093;  // @16_634f90
  if (((eax & 0xff) & (u32)(1)) != 0) goto L635093;  // @17_634f90
  if (eax == (u32)(4)) goto L63526f;  // @18_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @19_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @21_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7083788), (u32)(91));  // @22_634f90
  ecx = edx = 0;  // @23_634f90
  edi = eax;  // @24_634f90
  ecx = (u32)(EBP - 144);  // @25_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @26_634f90
  p0_ = ecx;  // @27_634f90
  ecx = eax;  // @28_634f90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @29_634f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_634f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 472), sizeof v); (u32)v; });  // @31_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(p0_), (u32)(1));  // @32_634f90
  ecx = edx = 0;  // @33_634f90
  esi = eax;  // @34_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @35_634f90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_634f90
  reg.state = (s32)((u32)(0));  // @37_634f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_634f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @39_634f90
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @40_634f90
  ecx = edx = 0;  // @41_634f90
  p1_ = eax;  // @42_634f90
  ecx = esi;  // @43_634f90
  eax = ext_4cc1d0_cdecl1((u32)(p1_));  // @44_634f90
  ecx = edx = 0;  // @45_634f90
  p2_ = eax;  // @46_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }), (u32)(7083832), (u32)(p2_));  // @47_634f90
  ecx = edx = 0;  // @48_634f90
  ecx = (u32)(EBP - 144);  // @49_634f90
  eax = ext_4cbec0_thiscall1(ecx);  // @50_634f90
  ecx = edx = 0;  // @51_634f90
  goto L63526f;  // @52_634f90
  L635093:;
  if (eax != (u32)(4)) goto L6350ad;  // @54_634f90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(5)) == 0) goto L6350a6;  // @55_634f90
  if ((ecx & ecx) != 0) goto L635128;  // @56_634f90
  L6350a6:;
  eax = 0;  // @58_634f90
  goto L635274;  // @59_634f90
  L6350ad:;
  if ((ecx & ecx) != 0) goto L635128;  // @61_634f90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L635128;  // @62_634f90
  if (eax == (u32)(1)) goto L635128;  // @63_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @64_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @66_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7083788), (u32)(106));  // @67_634f90
  ecx = edx = 0;  // @68_634f90
  edi = eax;  // @69_634f90
  ecx = (u32)(EBP - 272);  // @70_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @71_634f90
  p3_ = ecx;  // @72_634f90
  ecx = eax;  // @73_634f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @74_634f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 472), sizeof v); (u32)v; });  // @75_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(p3_), (u32)(1));  // @76_634f90
  ecx = edx = 0;  // @77_634f90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_634f90
  ecx = eax;  // @79_634f90
  reg.state = (s32)((u32)(1));  // @80_634f90
  eax = ext_4cc1d0_thiscall1(ecx);  // @81_634f90
  ecx = edx = 0;  // @82_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @83_634f90
  p4_ = eax;  // @84_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @86_634f90
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p4_));  // @87_634f90
  ecx = edx = 0;  // @88_634f90
  p5_ = eax;  // @89_634f90
  p6_ = edi;  // @90_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(p6_), (u32)(6836680), (u32)(p5_));  // @91_634f90
  ecx = edx = 0;  // @92_634f90
  ecx = (u32)(EBP - 272);  // @93_634f90
  eax = ext_4cbec0_thiscall1(ecx);  // @94_634f90
  ecx = edx = 0;  // @95_634f90
  goto L63526f;  // @96_634f90
  L635128:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @98_634f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L635147;  // @99_634f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; }) == (u32)(0)) goto L635147;  // @100_634f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @101_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @102_634f90
  L635147:;
  eax = (eax & (u32)(56));  // @104_634f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @105_634f90
  if (eax == 0) goto L635171;  // @106_634f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L635171;  // @107_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @110_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7083788), (u32)(118));  // @111_634f90
  ecx = edx = 0;  // @112_634f90
  goto L635177;  // @113_634f90
  L635171:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @115_634f90
  L635177:;
  p7_ = edi;  // @117_634f90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @118_634f90
  ecx = esi;  // @119_634f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @120_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_634f90
  p8_ = edi;  // @122_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(p8_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), (u32)(p7_));  // @123_634f90
  ecx = edx = 0;  // @124_634f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }) == (u32)(0)) goto L6350a6;  // @125_634f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }) == (u32)(0)) goto L635249;  // @126_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @127_634f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L635249;  // @128_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @129_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @131_634f90
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7083788), (u32)(145));  // @132_634f90
  ecx = edx = 0;  // @133_634f90
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }));  // @134_634f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @135_634f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; }) != (u32)(0)) goto L63523e;  // @136_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @137_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @138_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @140_634f90
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(0));  // @141_634f90
  ecx = edx = 0;  // @142_634f90
  eax = (eax + (u32)(-4));  // @143_634f90
  x0 = _mm_setzero_ps();  // @144_634f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @145_634f90
  _mm_storeu_ps((float *)(u32)(eax), x0);  // @146_634f90
  _mm_storel_epi64((__m128i *)(u32)(eax + 16), _mm_castps_si128(x0));  // @147_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @148_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @149_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @151_634f90
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }));  // @152_634f90
  ecx = edx = 0;  // @153_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @154_634f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @155_634f90
  ecx = esi;  // @156_634f90
  eax = ext_41e680_thiscall1(ecx);  // @157_634f90
  ecx = edx = 0;  // @158_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @159_634f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @160_634f90
  ecx = esi;  // @161_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @162_634f90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @163_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @165_634f90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @166_634f90
  ecx = edx = 0;  // @167_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @168_634f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @169_634f90
  L63523e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @171_634f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @172_634f90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) + ecx)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @173_634f90
  L635249:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @175_634f90
  if (((eax & 0xff) & (u32)(1)) == 0) goto L635254;  // @176_634f90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @177_634f90
  L635254:;
  if (((eax & 0xff) & (u32)(2)) == 0) goto L63525c;  // @179_634f90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @180_634f90
  L63525c:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L63526f;  // @182_634f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @183_634f90
  ecx = esi;  // @184_634f90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; }));  // @185_634f90
  ecx = edx = 0;  // @186_634f90
  L63526f:;
  eax = (u32)(1);  // @188_634f90
  L635274:;
  SEH_LEAVE();  // @190_634f90
  ext_633654(G(u32, 0x6f5630));  // @191_634f90
  __asm__ volatile("" :: "Yz"(x0));  // @192_634f90
  return eax;  // @193_634f90
}
PCREG(634f90, lifted_634f90);

