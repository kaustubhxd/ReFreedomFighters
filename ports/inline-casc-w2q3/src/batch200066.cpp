// batch200066.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc6e0_fastcall2(u32, u32) __asm__("ext_4cc6e0");
extern "C" u32 STDCALL ext_492200_stdcall1(u32) __asm__("ext_492200");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_41f1e0_thiscall4(u32, u32, u32, u32) __asm__("ext_41f1e0");
extern "C" u32 THISCALL ext_41fad0_thiscall2(u32, u32) __asm__("ext_41fad0");
extern "C" u32 THISCALL ext_424d90_thiscall1(u32) __asm__("ext_424d90");
extern "C" u32 THISCALL ext_426410_thiscall1(u32) __asm__("ext_426410");
extern "C" u32 THISCALL ext_4285f0_thiscall1(u32) __asm__("ext_4285f0");
extern "C" u32 THISCALL ext_456ab0_thiscall1(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_471f60_thiscall1(u32) __asm__("ext_471f60");
extern "C" u32 THISCALL ext_492880_thiscall2(u32, u32) __asm__("ext_492880");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
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
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e5000_thiscall1(u32) __asm__("ext_4e5000");
extern "C" u32 THISCALL ext_4e7160_thiscall1(u32) __asm__("ext_4e7160");
extern "C" u32 THISCALL ext_4ee210_thiscall4(u32, u32, u32, u32) __asm__("ext_4ee210");
extern "C" u32 THISCALL ext_4f9c90_thiscall2(u32, u32) __asm__("ext_4f9c90");
extern "C" u32 THISCALL ext_4febf0_thiscall2(u32, u32) __asm__("ext_4febf0");
extern "C" u32 THISCALL ext_5eaab0_thiscall3(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL ext_5fad90_thiscall1(u32) __asm__("ext_5fad90");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl4(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4f8c50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4f8c50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8c50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4f8c50
  eax = ext_4f9c90_thiscall2(ecx, (u32)(esi));  // @2_4f8c50
  ecx = edx = 0;  // @3_4f8c50
  eax = (u32)(EBP - 148);  // @4_4f8c50
  ecx = esi;  // @5_4f8c50
  eax = ext_4e12e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @6_4f8c50
  ecx = edx = 0;  // @7_4f8c50
  eax = (u32)(ebx + 455);  // @8_4f8c50
  ecx = esi;  // @9_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @10_4f8c50
  ecx = edx = 0;  // @11_4f8c50
  eax = (u32)(ebx + 459);  // @12_4f8c50
  ecx = esi;  // @13_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @14_4f8c50
  ecx = edx = 0;  // @15_4f8c50
  eax = (u32)(ebx + 471);  // @16_4f8c50
  ecx = esi;  // @17_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @18_4f8c50
  ecx = edx = 0;  // @19_4f8c50
  ecx = esi;  // @20_4f8c50
  eax = ext_4e1b30_thiscall1(ecx);  // @21_4f8c50
  ecx = edx = 0;  // @22_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_4f8c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4f8c50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @26_4f8c50
  ecx = edx = 0;  // @27_4f8c50
  ecx = eax;  // @28_4f8c50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 451), &v, sizeof v); }  // @29_4f8c50
  if ((ecx & ecx) == 0) goto L4f8d05;  // @30_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @32_4f8c50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097199));  // @33_4f8c50
  ecx = edx = 0;  // @34_4f8c50
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4f8d5e;  // @35_4f8c50
  L4f8d05:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @37_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4f8c50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6927940), (u32)(37));  // @39_4f8c50
  ecx = edx = 0;  // @40_4f8c50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @41_4f8c50
  edi = eax;  // @42_4f8c50
  eax = (u32)(EBP - 144);  // @43_4f8c50
  ecx = ebx;  // @44_4f8c50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @45_4f8c50
  ecx = edx = 0;  // @46_4f8c50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_4f8c50
  ecx = eax;  // @48_4f8c50
  reg.state = (s32)((u32)(0));  // @49_4f8c50
  eax = ext_4cc1d0_thiscall1(ecx);  // @50_4f8c50
  ecx = edx = 0;  // @51_4f8c50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6927984), (u32)(eax));  // @52_4f8c50
  ecx = edx = 0;  // @53_4f8c50
  ecx = (u32)(EBP - 144);  // @54_4f8c50
  eax = ext_4cbec0_thiscall1(ecx);  // @55_4f8c50
  ecx = edx = 0;  // @56_4f8c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 451), &v, sizeof v); }  // @57_4f8c50
  L4f8d5e:;
  SEH_LEAVE();  // @59_4f8c50
  ext_633654(G(u32, 0x6f5630));  // @60_4f8c50
  return eax;  // @61_4f8c50
}
PCREG(4f8c50, lifted_4f8c50);

extern "C" u32 lifted_456bf0(void) {
  SEH_ENTER(0x6691af);  // @h_456bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_456bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @3_456bf0
  ecx = edx = 0;  // @4_456bf0
  ecx = (u32)(EBP - 16);  // @5_456bf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_456bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_456bf0
  ecx = eax;  // @8_456bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6827256), (u32)(ecx));  // @9_456bf0
  ecx = edx = 0;  // @10_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @11_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_456bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @13_456bf0
  ecx = edx = 0;  // @14_456bf0
  if ((eax & eax) != 0) goto L456cfa;  // @15_456bf0
  eax = ext_41e290_cdecl1((u32)(28));  // @16_456bf0
  ecx = edx = 0;  // @17_456bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @18_456bf0
  reg.state = (s32)((u32)(0));  // @19_456bf0
  if ((eax & eax) == 0) goto L456c84;  // @20_456bf0
  ecx = eax;  // @21_456bf0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(0));  // @22_456bf0
  ecx = edx = 0;  // @23_456bf0
  esi = eax;  // @24_456bf0
  goto L456c86;  // @25_456bf0
  L456c84:;
  esi = 0;  // @27_456bf0
  L456c86:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_456bf0
  reg.state = (s32)((u32)(4294967295));  // @30_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_456bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @33_456bf0
  ecx = edx = 0;  // @34_456bf0
  edi = eax;  // @35_456bf0
  if ((esi & esi) != 0) goto L456caa;  // @36_456bf0
  L456ca6:;
  eax = 0;  // @38_456bf0
  goto L456ce9;  // @39_456bf0
  L456caa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @41_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_456bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(esi));  // @43_456bf0
  ecx = edx = 0;  // @44_456bf0
  if ((eax & eax) != 0) goto L456ca6;  // @45_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @46_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @47_456bf0
  if ((eax & eax) == 0) goto L456cd7;  // @48_456bf0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L456cd7;  // @49_456bf0
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L456cd7;  // @50_456bf0
  ecx = esi;  // @51_456bf0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @52_456bf0
  ecx = edx = 0;  // @53_456bf0
  goto L456ce9;  // @54_456bf0
  L456cd7:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L456ce6;  // @56_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_456bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(esi));  // @58_456bf0
  ecx = edx = 0;  // @59_456bf0
  L456ce6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @61_456bf0
  L456ce9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @63_456bf0
  ecx = edi;  // @64_456bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(6827256), (u32)(eax), (u32)(16));  // @65_456bf0
  ecx = edx = 0;  // @66_456bf0
  eax = esi;  // @67_456bf0
  L456cfa:;
  SEH_LEAVE();  // @69_456bf0
  return eax;  // @70_456bf0
}
PCREG(456bf0, lifted_456bf0);

extern "C" u32 THISCALL lifted_4c3d30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668e06);  // @h_4c3d30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ebx = (u32)(edi + 126);  // @8_4c3d30
  ecx = edi;  // @9_4c3d30
  eax = ext_4c4740_thiscall4(ecx, (u32)(esi), (u32)(ebx), (u32)(eax));  // @10_4c3d30
  ecx = edx = 0;  // @11_4c3d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_4c3d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4c3d30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @15_4c3d30
  ecx = edx = 0;  // @16_4c3d30
  if ((eax & eax) != 0) goto L4c3e4b;  // @17_4c3d30
  ecx = (u32)(EBP - 144);  // @18_4c3d30
  eax = ext_4cc5f0_thiscall1(ecx);  // @19_4c3d30
  ecx = edx = 0;  // @20_4c3d30
  if ((eax & eax) == 0) goto L4c3e4b;  // @21_4c3d30
  ecx = (u32)(EBP - 144);  // @22_4c3d30
  eax = ext_456ab0_thiscall1(ecx);  // @23_4c3d30
  ecx = edx = 0;  // @24_4c3d30
  ebx = eax;  // @25_4c3d30
  if ((ebx & ebx) != 0) goto L4c3e37;  // @26_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @27_4c3d30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4c3d30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6897740), (u32)(191));  // @29_4c3d30
  ecx = edx = 0;  // @30_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @31_4c3d30
  edi = eax;  // @32_4c3d30
  eax = (u32)(EBP - 272);  // @33_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @34_4c3d30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4c3d30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @36_4c3d30
  ecx = edx = 0;  // @37_4c3d30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_4c3d30
  ecx = eax;  // @39_4c3d30
  reg.state = (s32)((u32)(1));  // @40_4c3d30
  eax = ext_4cc1d0_thiscall1(ecx);  // @41_4c3d30
  ecx = edx = 0;  // @42_4c3d30
  ecx = (u32)(EBP - 144);  // @43_4c3d30
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @44_4c3d30
  ecx = edx = 0;  // @45_4c3d30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(edi), (u32)(6897792), (u32)(eax));  // @46_4c3d30
  ecx = edx = 0;  // @47_4c3d30
  reg.state = (s32)((ebx & 0xff));  // @48_4c3d30
  ecx = (u32)(EBP - 272);  // @49_4c3d30
  eax = ext_4cbec0_thiscall1(ecx);  // @50_4c3d30
  ecx = edx = 0;  // @51_4c3d30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @52_4c3d30
  L4c3e37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_4c3d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_4c3d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4c3d30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(ebx));  // @57_4c3d30
  ecx = edx = 0;  // @58_4c3d30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 126), &v, sizeof v); }  // @59_4c3d30
  L4c3e4b:;
  ecx = (u32)(EBP - 144);  // @61_4c3d30
  eax = ext_4cbec0_thiscall1(ecx);  // @62_4c3d30
  ecx = edx = 0;  // @63_4c3d30
  SEH_LEAVE();  // @64_4c3d30
  ext_633654(G(u32, 0x6f5630));  // @65_4c3d30
  return eax;  // @66_4c3d30
}
PCREG(4c3d30, lifted_4c3d30);

extern "C" u32 THISCALL lifted_45cc40(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6666bc);  // @h_45cc40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = esi;  // @8_45cc40
  reg.state = (s32)((u32)(0));  // @9_45cc40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 468)))(ecx, (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @10_45cc40
  ecx = edx = 0;  // @11_45cc40
  ecx = (u32)(EBP - 144);  // @12_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @13_45cc40
  ecx = edx = 0;  // @14_45cc40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @15_45cc40
  eax = ((u32(STDCALL *)(u32, u32))(ebx))((u32)(eax), (u32)(47));  // @16_45cc40
  ecx = edx = 0;  // @17_45cc40
  esi = eax;  // @18_45cc40
  if ((esi & esi) == 0) goto L45cd52;  // @19_45cc40
  ecx = (u32)(EBP - 144);  // @20_45cc40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @21_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @22_45cc40
  ecx = edx = 0;  // @23_45cc40
  eax = ((u32( *)(u32, u32))(ebx))((u32)(eax), (u32)(92));  // @24_45cc40
  ecx = edx = 0;  // @25_45cc40
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_45cc40
  ecx = (u32)(EBP - 400);  // @27_45cc40
  ebx = eax;  // @28_45cc40
  eax = ext_4cbeb0_thiscall1(ecx);  // @29_45cc40
  ecx = edx = 0;  // @30_45cc40
  reg.state = (s32)((u32)(1));  // @31_45cc40
  ecx = (u32)(EBP - 272);  // @32_45cc40
  if ((ebx & ebx) == 0) goto L45cd09;  // @33_45cc40
  eax = (u32)(ebx + 1);  // @34_45cc40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @35_45cc40
  ecx = edx = 0;  // @36_45cc40
  reg.state = (s32)((u32)(2));  // @37_45cc40
  goto L45cd16;  // @38_45cc40
  L45cd09:;
  eax = (u32)(esi + 1);  // @40_45cc40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @41_45cc40
  ecx = edx = 0;  // @42_45cc40
  reg.state = (s32)((u32)(3));  // @43_45cc40
  L45cd16:;
  eax = (u32)(EBP - 272);  // @45_45cc40
  ecx = (u32)(EBP - 400);  // @46_45cc40
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @47_45cc40
  ecx = edx = 0;  // @48_45cc40
  ecx = (u32)(EBP - 272);  // @49_45cc40
  reg.state = (s32)((u32)(1));  // @50_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @51_45cc40
  ecx = edx = 0;  // @52_45cc40
  eax = (u32)(EBP - 400);  // @53_45cc40
  ecx = edi;  // @54_45cc40
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @55_45cc40
  ecx = edx = 0;  // @56_45cc40
  ecx = (u32)(EBP - 400);  // @57_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @58_45cc40
  ecx = edx = 0;  // @59_45cc40
  goto L45cd60;  // @60_45cc40
  L45cd52:;
  eax = (u32)(EBP - 144);  // @62_45cc40
  ecx = edi;  // @63_45cc40
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @64_45cc40
  ecx = edx = 0;  // @65_45cc40
  L45cd60:;
  ecx = (u32)(EBP - 144);  // @67_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @68_45cc40
  ecx = edx = 0;  // @69_45cc40
  eax = edi;  // @70_45cc40
  SEH_LEAVE();  // @71_45cc40
  ext_633654(G(u32, 0x6f5630));  // @72_45cc40
  return eax;  // @73_45cc40
}
PCREG(45cc40, lifted_45cc40);

extern "C" u32 THISCALL lifted_497750(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66818f);  // @h_497750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @15_497750
  ecx = edx = 0;  // @16_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @17_497750
  L4977be:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @19_497750
  if ((ecx & ecx) == 0) goto L4977d2;  // @20_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @22_497750
  ecx = edx = 0;  // @23_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @24_497750
  L4977d2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @26_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @27_497750
  L4977e0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @29_497750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @30_497750
  eax = ext_41e290_cdecl1((u32)(ebx));  // @31_497750
  ecx = edx = 0;  // @32_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @33_497750
  eax = ext_41e290_cdecl1((u32)(16));  // @34_497750
  ecx = edx = 0;  // @35_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @36_497750
  reg.state = (s32)((u32)(0));  // @37_497750
  if ((eax & eax) == 0) goto L49781a;  // @38_497750
  ecx = eax;  // @39_497750
  eax = ext_4ccdd0_thiscall4(ecx, (u32)(0), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; }), (u32)(512));  // @40_497750
  ecx = edx = 0;  // @41_497750
  goto L49781c;  // @42_497750
  L49781a:;
  eax = 0;  // @44_497750
  L49781c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @46_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @47_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @48_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @49_497750
  eax = (eax + edx);  // @50_497750
  reg.state = (s32)((u32)(4294967295));  // @51_497750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_497750
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 216)))(ecx, (u32)(edx), (u32)(eax), (u32)(4809904));  // @53_497750
  ecx = edx = 0;  // @54_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @55_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @57_497750
  ecx = edx = 0;  // @58_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @59_497750
  if ((ecx & ecx) == 0) goto L497866;  // @60_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_497750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6874404), (u32)(ebx));  // @62_497750
  ecx = edx = 0;  // @63_497750
  L497866:;
  SEH_LEAVE();  // @65_497750
  return eax;  // @66_497750
}
PCREG(497750, lifted_497750);

extern "C" u32 THISCALL lifted_4cbae0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665aff);  // @h_4cbae0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4cbae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4cbae0
  eax = (u32)(edi + 80);  // @2_4cbae0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4cbae0
  ecx = esi;  // @4_4cbae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, (u32)(eax));  // @6_4cbae0
  ecx = edx = 0;  // @7_4cbae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_4cbae0
  eax = (u32)(edi + 82);  // @9_4cbae0
  ecx = esi;  // @10_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, (u32)(eax));  // @11_4cbae0
  ecx = edx = 0;  // @12_4cbae0
  eax = ext_41e290_cdecl1((u32)(28));  // @13_4cbae0
  ecx = edx = 0;  // @14_4cbae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @15_4cbae0
  reg.state = (s32)((u32)(0));  // @16_4cbae0
  if ((eax & eax) == 0) goto L4cbb48;  // @17_4cbae0
  ecx = eax;  // @18_4cbae0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(2));  // @19_4cbae0
  ecx = edx = 0;  // @20_4cbae0
  goto L4cbb4a;  // @21_4cbae0
  L4cbb48:;
  eax = 0;  // @23_4cbae0
  L4cbb4a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @25_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 88), &v, sizeof v); }  // @26_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 92), &v, sizeof v); }  // @27_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @28_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @29_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 104), &v, sizeof v); }  // @30_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @31_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 112), &v, sizeof v); }  // @32_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @33_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_4cbae0
  reg.state = (s32)((u32)(4294967295));  // @35_4cbae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4cbae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @38_4cbae0
  ecx = edx = 0;  // @39_4cbae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @40_4cbae0
  esi = eax;  // @41_4cbae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(edi));  // @43_4cbae0
  ecx = edx = 0;  // @44_4cbae0
  if ((eax & eax) == 0) goto L4cbbb5;  // @45_4cbae0
  ecx = 0;  // @46_4cbae0
  goto L4cbbe6;  // @47_4cbae0
  L4cbbb5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @49_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @50_4cbae0
  if ((eax & eax) == 0) goto L4cbbd4;  // @51_4cbae0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > edi) goto L4cbbd4;  // @52_4cbae0
  if (edi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L4cbbd4;  // @53_4cbae0
  ecx = edi;  // @54_4cbae0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @55_4cbae0
  ecx = edx = 0;  // @56_4cbae0
  ecx = eax;  // @57_4cbae0
  goto L4cbbe6;  // @58_4cbae0
  L4cbbd4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cbbe3;  // @60_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(edi));  // @62_4cbae0
  ecx = edx = 0;  // @63_4cbae0
  L4cbbe3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @65_4cbae0
  L4cbbe6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @67_4cbae0
  ecx = esi;  // @68_4cbae0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6903412), (u32)(ecx), (u32)(4));  // @69_4cbae0
  ecx = edx = 0;  // @70_4cbae0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @71_4cbae0
  SEH_LEAVE();  // @72_4cbae0
  return eax;  // @73_4cbae0
}
PCREG(4cbae0, lifted_4cbae0);

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

extern "C" u32 THISCALL lifted_5fae50(u32 ecx_in) {
  SEH_ENTER(0x66d392);  // @h_5fae50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ext_634273_cdecl2((u32)(edi), (u32)(72));  // @25_5fae50
  ecx = edx = 0;  // @26_5fae50
  L5faebc:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }) != (u32)(0)) goto L5fae81;  // @28_5fae50
  L5faec2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @30_5fae50
  if ((ecx & ecx) == 0) goto L5faecf;  // @31_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_5fae50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @33_5fae50
  ecx = edx = 0;  // @34_5fae50
  L5faecf:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }));  // @36_5fae50
  ecx = edx = 0;  // @37_5fae50
  ecx = (u32)(esi + 24);  // @38_5fae50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @40_5fae50
  eax = (eax - edx);  // @41_5fae50
  reg.state = (s32)((u32)(0));  // @42_5fae50
  if ((edx & edx) == 0) goto L5faefa;  // @43_5fae50
  if ((eax & eax) == 0) goto L5faefa;  // @44_5fae50
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @45_5fae50
  ecx = edx = 0;  // @46_5fae50
  L5faefa:;
  ecx = (u32)(esi + 12);  // @48_5fae50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @50_5fae50
  eax = (eax - edx);  // @51_5fae50
  reg.state = (s32)((u32)(1));  // @52_5fae50
  if ((edx & edx) == 0) goto L5faf1a;  // @53_5fae50
  if ((eax & eax) == 0) goto L5faf1a;  // @54_5fae50
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @55_5fae50
  ecx = edx = 0;  // @56_5fae50
  L5faf1a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @59_5fae50
  eax = (eax - ecx);  // @60_5fae50
  reg.state = (s32)((u32)(2));  // @61_5fae50
  if ((ecx & ecx) == 0) goto L5faf39;  // @62_5fae50
  if ((eax & eax) == 0) goto L5faf39;  // @63_5fae50
  ecx = esi;  // @64_5fae50
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @65_5fae50
  ecx = edx = 0;  // @66_5fae50
  L5faf39:;
  SEH_LEAVE();  // @68_5fae50
  return eax;  // @69_5fae50
}
PCREG(5fae50, lifted_5fae50);

extern "C" u32 THISCALL lifted_492250(u32 ecx_in) {
  SEH_ENTER(0x667d5b);  // @h_492250
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_492250
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }) == (u32)(0)) goto L4923b9;  // @2_492250
  eax = (u32)(EBP - 30016);  // @3_492250
  ecx = (u32)(EBP - 30332);  // @4_492250
  eax = ext_499880_thiscall3(ecx, (u32)(eax), (u32)(30000));  // @5_492250
  ecx = edx = 0;  // @6_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_492250
  ecx = (u32)(EBP - 30332);  // @8_492250
  reg.state = (s32)((u32)(0));  // @9_492250
  eax = ext_49a790_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }), (u32)(2));  // @10_492250
  ecx = edx = 0;  // @11_492250
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4922da;  // @12_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2994), &v, sizeof v); }  // @13_492250
  goto L4923ae;  // @14_492250
  L4922da:;
  ecx = (u32)(EBP - 30332);  // @16_492250
  eax = ext_49b340_thiscall3(ecx, (u32)(1), (u32)(4));  // @17_492250
  ecx = edx = 0;  // @18_492250
  ecx = (u32)(EBP - 30332);  // @19_492250
  eax = ext_49b2e0_thiscall2(ecx, (u32)(1));  // @20_492250
  ecx = edx = 0;  // @21_492250
  eax = (u32)(esi + 2992);  // @22_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3008), &v, sizeof v); }  // @23_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @24_492250
  ecx = (u32)(EBP - 30332);  // @25_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(eax));  // @26_492250
  ecx = edx = 0;  // @27_492250
  eax = (u32)(esi + 2993);  // @28_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @29_492250
  ecx = (u32)(EBP - 30332);  // @30_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(eax));  // @31_492250
  ecx = edx = 0;  // @32_492250
  eax = (u32)(esi + 2995);  // @33_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @34_492250
  ecx = (u32)(EBP - 30332);  // @35_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(eax));  // @36_492250
  ecx = edx = 0;  // @37_492250
  eax = (u32)(esi + 23873);  // @38_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @39_492250
  ecx = (u32)(EBP - 30332);  // @40_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(eax));  // @41_492250
  ecx = edx = 0;  // @42_492250
  eax = (u32)(esi + 2988);  // @43_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @44_492250
  ecx = (u32)(EBP - 30332);  // @45_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(eax));  // @46_492250
  ecx = edx = 0;  // @47_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_492250
  edx = (u32)(EBP - 30332);  // @49_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edx));  // @51_492250
  ecx = edx = 0;  // @52_492250
  eax = (u32)(EBP - 30332);  // @53_492250
  ecx = esi;  // @54_492250
  eax = ext_492200_stdcall1((u32)(eax));  // @55_492250
  ecx = edx = 0;  // @56_492250
  eax = (u32)(EBP - 30332);  // @57_492250
  ecx = esi;  // @58_492250
  eax = ext_492880_thiscall2(ecx, (u32)(eax));  // @59_492250
  ecx = edx = 0;  // @60_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @63_492250
  ecx = edx = 0;  // @64_492250
  ecx = eax;  // @65_492250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @66_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 112)))(ecx);  // @67_492250
  ecx = edx = 0;  // @68_492250
  L4923ae:;
  ecx = (u32)(EBP - 30332);  // @70_492250
  eax = ext_499970_thiscall1(ecx);  // @71_492250
  ecx = edx = 0;  // @72_492250
  L4923b9:;
  SEH_LEAVE();  // @74_492250
  ext_633654(G(u32, 0x6f5630));  // @75_492250
  return eax;  // @76_492250
}
PCREG(492250, lifted_492250);

extern "C" u32 THISCALL lifted_4f1890(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x669912);  // @h_4f1890
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = eax;  // @34_4f1890
  eax = ext_4d8330_thiscall4(ecx, (u32)(6917996), (u32)(6917956), (u32)(ecx));  // @35_4f1890
  ecx = edx = 0;  // @36_4f1890
  edx = eax;  // @37_4f1890
  goto L4f1989;  // @38_4f1890
  L4f1987:;
  edx = 0;  // @40_4f1890
  L4f1989:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 96), &v, sizeof v); }  // @42_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4f1890
  reg.state = (s32)((u32)(4));  // @44_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4f1890
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @46_4f1890
  ecx = edx = 0;  // @47_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4f1890
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @51_4f1890
  ecx = edx = 0;  // @52_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_4f1890
  esi = eax;  // @54_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @55_4f1890
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_4f1890
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4f1890
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(ebx), (u32)(16));  // @58_4f1890
  ecx = edx = 0;  // @59_4f1890
  ecx = esi;  // @60_4f1890
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6918004), (u32)(eax));  // @61_4f1890
  ecx = edx = 0;  // @62_4f1890
  { u8 v = (u8)((u32)(254)); __builtin_memcpy((void *)(u32)(ebx + 104), &v, sizeof v); }  // @63_4f1890
  eax = ebx;  // @64_4f1890
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 106), &v, sizeof v); }  // @65_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1591), &v, sizeof v); }  // @66_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 107), &v, sizeof v); }  // @67_4f1890
  SEH_LEAVE();  // @68_4f1890
  return eax;  // @69_4f1890
}
PCREG(4f1890, lifted_4f1890);

extern "C" u32 THISCALL lifted_4637f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666a2d);  // @h_4637f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  edx = (u32)(EBP - 144);  // @10_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 324)))(ecx, (u32)(edx), (u32)(edx));  // @12_4637f0
  ecx = edx = 0;  // @13_4637f0
  ecx = eax;  // @14_4637f0
  reg.state = (s32)(esi);  // @15_4637f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_4637f0
  ecx = edx = 0;  // @17_4637f0
  ecx = (u32)(EBP - 144);  // @18_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @19_4637f0
  reg.state = (s32)((u32)(4294967295));  // @20_4637f0
  eax = ext_4cbec0_thiscall1(ecx);  // @21_4637f0
  ecx = edx = 0;  // @22_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_4637f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) == esi) goto L46390d;  // @25_4637f0
  eax = ext_41e290_cdecl1((u32)(44));  // @26_4637f0
  ecx = edx = 0;  // @27_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @28_4637f0
  reg.state = (s32)((u32)(1));  // @29_4637f0
  if ((eax & eax) == 0) goto L4638ac;  // @30_4637f0
  ecx = eax;  // @31_4637f0
  eax = ext_4e5000_thiscall1(ecx);  // @32_4637f0
  ecx = edx = 0;  // @33_4637f0
  esi = eax;  // @34_4637f0
  goto L4638ae;  // @35_4637f0
  L4638ac:;
  esi = 0;  // @37_4637f0
  L4638ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @39_4637f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_4637f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @41_4637f0
  reg.state = (s32)((u32)(4294967295));  // @42_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @43_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @46_4637f0
  ecx = esi;  // @47_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(edi), (u32)(ebx), (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }));  // @48_4637f0
  ecx = edx = 0;  // @49_4637f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L46390d;  // @50_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @51_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6838324), (u32)(453));  // @53_4637f0
  ecx = edx = 0;  // @54_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @55_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6838400), (u32)(ebx));  // @56_4637f0
  ecx = edx = 0;  // @57_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_4637f0
  ecx = esi;  // @59_4637f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @60_4637f0
  ecx = edx = 0;  // @61_4637f0
  esi = 0;  // @62_4637f0
  L46390d:;
  eax = esi;  // @64_4637f0
  L46390f:;
  SEH_LEAVE();  // @66_4637f0
  ext_633654(G(u32, 0x6f5630));  // @67_4637f0
  return eax;  // @68_4637f0
}
PCREG(4637f0, lifted_4637f0);

extern "C" u32 THISCALL lifted_4c4930(u32 ecx_in) {
  SEH_ENTER(0x668e74);  // @h_4c4930
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c4930
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c4930
  eax = ext_469870_thiscall1(ecx);  // @2_4c4930
  ecx = edx = 0;  // @3_4c4930
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c4930
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c4930
  { u32 v = (u32)((u32)(6897948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4c4930
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @7_4c4930
  reg.state = (s32)((u32)(0));  // @8_4c4930
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }  // @9_4c4930
  eax = ext_41e290_cdecl1((u32)(28));  // @10_4c4930
  ecx = edx = 0;  // @11_4c4930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @12_4c4930
  reg.state = (s32)((u32)(1));  // @13_4c4930
  if ((eax & eax) == 0) goto L4c49a5;  // @14_4c4930
  ecx = eax;  // @15_4c4930
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(8), (u32)(0));  // @16_4c4930
  ecx = edx = 0;  // @17_4c4930
  goto L4c49a7;  // @18_4c4930
  L4c49a5:;
  eax = 0;  // @20_4c4930
  L4c49a7:;
  reg.state = (s32)((u32)(0));  // @22_4c4930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @23_4c4930
  eax = ext_41e290_cdecl1((u32)(28));  // @24_4c4930
  ecx = edx = 0;  // @25_4c4930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @26_4c4930
  reg.state = (s32)((u32)(2));  // @27_4c4930
  if ((eax & eax) == 0) goto L4c49d0;  // @28_4c4930
  ecx = eax;  // @29_4c4930
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(8), (u32)(0));  // @30_4c4930
  ecx = edx = 0;  // @31_4c4930
  goto L4c49d2;  // @32_4c4930
  L4c49d0:;
  eax = 0;  // @34_4c4930
  L4c49d2:;
  reg.state = (s32)((u32)(0));  // @36_4c4930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @37_4c4930
  eax = ext_41e290_cdecl1((u32)(28));  // @38_4c4930
  ecx = edx = 0;  // @39_4c4930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @40_4c4930
  reg.state = (s32)((u32)(3));  // @41_4c4930
  if ((eax & eax) == 0) goto L4c49fb;  // @42_4c4930
  ecx = eax;  // @43_4c4930
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(8), (u32)(0));  // @44_4c4930
  ecx = edx = 0;  // @45_4c4930
  goto L4c49fd;  // @46_4c4930
  L4c49fb:;
  eax = 0;  // @48_4c4930
  L4c49fd:;
  reg.state = (s32)((u32)(0));  // @50_4c4930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @51_4c4930
  eax = ext_41e290_cdecl1((u32)(28));  // @52_4c4930
  ecx = edx = 0;  // @53_4c4930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @54_4c4930
  reg.state = (s32)((u32)(4));  // @55_4c4930
  if ((eax & eax) == 0) goto L4c4a26;  // @56_4c4930
  ecx = eax;  // @57_4c4930
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(8), (u32)(1));  // @58_4c4930
  ecx = edx = 0;  // @59_4c4930
  goto L4c4a28;  // @60_4c4930
  L4c4a26:;
  eax = 0;  // @62_4c4930
  L4c4a28:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 106), &v, sizeof v); }  // @64_4c4930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_4c4930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @66_4c4930
  reg.state = (s32)((u32)(0));  // @67_4c4930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_4c4930
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6898128), (u32)(0), (u32)(6898080), (u32)(104));  // @69_4c4930
  ecx = edx = 0;  // @70_4c4930
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @71_4c4930
  eax = esi;  // @72_4c4930
  SEH_LEAVE();  // @73_4c4930
  return eax;  // @74_4c4930
}
PCREG(4c4930, lifted_4c4930);

extern "C" u32 THISCALL lifted_5b6d00(u32 ecx_in) {
  SEH_ENTER(0x665c2f);  // @h_5b6d00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5b6d00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_5b6d00
  ecx = edx = 0;  // @5_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_5b6d00
  esi = eax;  // @7_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_5b6d00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5b6d00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5b6d00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }), (u32)(16));  // @11_5b6d00
  ecx = edx = 0;  // @12_5b6d00
  ecx = esi;  // @13_5b6d00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6970372), (u32)(eax));  // @14_5b6d00
  ecx = edx = 0;  // @15_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @17_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5b6d00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @19_5b6d00
  ecx = edx = 0;  // @20_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @21_5b6d00
  esi = eax;  // @22_5b6d00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_5b6d00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(ebx));  // @24_5b6d00
  ecx = edx = 0;  // @25_5b6d00
  if ((eax & eax) == 0) goto L5b6d89;  // @26_5b6d00
  ecx = 0;  // @27_5b6d00
  goto L5b6dba;  // @28_5b6d00
  L5b6d89:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @30_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @31_5b6d00
  if ((eax & eax) == 0) goto L5b6da8;  // @32_5b6d00
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > ebx) goto L5b6da8;  // @33_5b6d00
  if (ebx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L5b6da8;  // @34_5b6d00
  ecx = ebx;  // @35_5b6d00
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @36_5b6d00
  ecx = edx = 0;  // @37_5b6d00
  ecx = eax;  // @38_5b6d00
  goto L5b6dba;  // @39_5b6d00
  L5b6da8:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L5b6db7;  // @41_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_5b6d00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(ebx));  // @43_5b6d00
  ecx = edx = 0;  // @44_5b6d00
  L5b6db7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 4), sizeof v); (u32)v; });  // @46_5b6d00
  L5b6dba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_5b6d00
  ecx = esi;  // @49_5b6d00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6998220), (u32)(ecx), (u32)(4));  // @50_5b6d00
  ecx = edx = 0;  // @51_5b6d00
  eax = ext_41e290_cdecl1((u32)(28));  // @52_5b6d00
  ecx = edx = 0;  // @53_5b6d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @54_5b6d00
  reg.state = (s32)((u32)(0));  // @55_5b6d00
  if ((eax & eax) == 0) goto L5b6e04;  // @56_5b6d00
  ecx = eax;  // @57_5b6d00
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(10), (u32)(141));  // @58_5b6d00
  ecx = edx = 0;  // @59_5b6d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @60_5b6d00
  SEH_LEAVE();  // @61_5b6d00
  return eax;  // @62_5b6d00
  L5b6e04:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @64_5b6d00
  SEH_LEAVE();  // @65_5b6d00
  return eax;  // @66_5b6d00
}
PCREG(5b6d00, lifted_5b6d00);

extern "C" u32 THISCALL lifted_4f8720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669a96);  // @h_4f8720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 648), sizeof v); (u32)v; });  // @14_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(edi));  // @15_4f8720
  ecx = edx = 0;  // @16_4f8720
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4f887a;  // @17_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 451), sizeof v); (u32)v; });  // @18_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, (u32)(edi));  // @20_4f8720
  ecx = edx = 0;  // @21_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 443), sizeof v); (u32)v; });  // @22_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; }));  // @24_4f8720
  ecx = edx = 0;  // @25_4f8720
  if ((eax & eax) != 0) goto L4f87e0;  // @26_4f8720
  if (esi == (u32)(32)) goto L4f887a;  // @27_4f8720
  L4f87e0:;
  if ((s32)eax >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 471), sizeof v); (u32)v; })) goto L4f887a;  // @29_4f8720
  edx = edi;  // @30_4f8720
  ecx = (u32)(EBP - 24);  // @31_4f8720
  eax = ext_4cc6e0_fastcall2(ecx, edx);  // @32_4f8720
  ecx = edx = 0;  // @33_4f8720
  eax = (u32)(EBP - 24);  // @34_4f8720
  ecx = (u32)(EBP - 152);  // @35_4f8720
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @36_4f8720
  ecx = edx = 0;  // @37_4f8720
  eax = (u32)(EBP - 152);  // @38_4f8720
  reg.state = (s32)((u32)(0));  // @39_4f8720
  eax = (u32)(EBP - 280);  // @40_4f8720
  ecx = (u32)(ebx + 143);  // @41_4f8720
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(eax), (u32)(eax));  // @42_4f8720
  ecx = edx = 0;  // @43_4f8720
  ecx = (u32)(ebx + 143);  // @44_4f8720
  reg.state = (s32)((u32)(1));  // @45_4f8720
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @46_4f8720
  ecx = edx = 0;  // @47_4f8720
  ecx = (u32)(EBP - 280);  // @48_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @49_4f8720
  ecx = edx = 0;  // @50_4f8720
  ecx = (u32)(EBP - 152);  // @51_4f8720
  reg.state = (s32)((u32)(4294967295));  // @52_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @53_4f8720
  ecx = edx = 0;  // @54_4f8720
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_4f8720
  ecx = (u32)(ebx + 143);  // @56_4f8720
  eax = ext_4cc1d0_thiscall1(ecx);  // @57_4f8720
  ecx = edx = 0;  // @58_4f8720
  ecx = ebx;  // @59_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, (u32)(eax));  // @60_4f8720
  ecx = edx = 0;  // @61_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; });  // @62_4f8720
  ecx = ebx;  // @63_4f8720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_4f8720
  eax = (eax + 1);  // @65_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 868)))(ecx, (u32)(eax));  // @66_4f8720
  ecx = edx = 0;  // @67_4f8720
  L4f887a:;
  SEH_LEAVE();  // @69_4f8720
  ext_633654(G(u32, 0x6f5630));  // @70_4f8720
  return eax;  // @71_4f8720
}
PCREG(4f8720, lifted_4f8720);

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

extern "C" u32 STDCALL lifted_601b10(u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_601b10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_601b10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_601b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_601b10
  eax = (u32)(EBP - 144);  // @4_601b10
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @5_601b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 324)))(ecx, (u32)(eax), (u32)(eax));  // @6_601b10
  ecx = edx = 0;  // @7_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @8_601b10
  ecx = (u32)(EBP - 144);  // @9_601b10
  reg.state = (s32)((u32)(0));  // @10_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @11_601b10
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @12_601b10
  ecx = edx = 0;  // @13_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @14_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @15_601b10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(eax));  // @16_601b10
  ecx = edx = 0;  // @17_601b10
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L601bf7;  // @18_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @19_601b10
  ecx = (u32)(EBP - 144);  // @20_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_601b10
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @22_601b10
  ecx = edx = 0;  // @23_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @24_601b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(eax));  // @25_601b10
  ecx = edx = 0;  // @26_601b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @27_601b10
  eax = (eax + 1);  // @28_601b10
  eax = ext_41e290_cdecl1((u32)(eax));  // @29_601b10
  ecx = edx = 0;  // @30_601b10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_601b10
  ecx = (u32)(EBP - 144);  // @32_601b10
  edi = eax;  // @33_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @34_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @36_601b10
  eax = ext_4cc1d0_cdecl4((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), (u32)(0), (u32)(0));  // @37_601b10
  ecx = edx = 0;  // @38_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @39_601b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 96)))(ecx, (u32)(eax));  // @40_601b10
  ecx = edx = 0;  // @41_601b10
  if (eax == ebx) goto L601bf1;  // @42_601b10
  eax = ext_41e2c0_cdecl1((u32)(edi));  // @43_601b10
  ecx = edx = 0;  // @44_601b10
  goto L601c25;  // @45_601b10
  L601bf1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + edi), &v, sizeof v); }  // @47_601b10
  goto L601c27;  // @48_601b10
  L601bf7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @50_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_601b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051316), (u32)(121));  // @52_601b10
  ecx = edx = 0;  // @53_601b10
  esi = eax;  // @54_601b10
  ecx = (u32)(EBP - 144);  // @55_601b10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_601b10
  eax = ext_4cc1d0_thiscall1(ecx);  // @57_601b10
  ecx = edx = 0;  // @58_601b10
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(esi), (u32)(7051372), (u32)(eax));  // @59_601b10
  ecx = edx = 0;  // @60_601b10
  L601c25:;
  edi = 0;  // @62_601b10
  L601c27:;
  ecx = (u32)(EBP - 144);  // @64_601b10
  eax = ext_4cbec0_thiscall1(ecx);  // @65_601b10
  ecx = edx = 0;  // @66_601b10
  eax = edi;  // @67_601b10
  SEH_LEAVE();  // @68_601b10
  ext_633654(G(u32, 0x6f5630));  // @69_601b10
  return eax;  // @70_601b10
}
PCREG(601b10, lifted_601b10);

extern "C" u32 THISCALL lifted_492640(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667ddb);  // @h_492640
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @2_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_492640
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @4_492640
  ecx = edx = 0;  // @5_492640
  eax = (u32)(EBP - 30016);  // @6_492640
  ecx = (u32)(EBP - 30332);  // @7_492640
  eax = ext_499880_thiscall3(ecx, (u32)(eax), (u32)(30000));  // @8_492640
  ecx = edx = 0;  // @9_492640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_492640
  ecx = (u32)(EBP - 30332);  // @11_492640
  reg.state = (s32)((u32)(0));  // @12_492640
  eax = ext_49a790_thiscall3(ecx, (u32)(edi), (u32)(1));  // @13_492640
  ecx = edx = 0;  // @14_492640
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L492746;  // @15_492640
  ecx = (u32)(EBP - 30332);  // @16_492640
  eax = ext_49b340_thiscall3(ecx, (u32)(0), (u32)(0));  // @17_492640
  ecx = edx = 0;  // @18_492640
  ecx = (u32)(EBP - 30332);  // @19_492640
  eax = ext_49b2e0_thiscall2(ecx, (u32)(0));  // @20_492640
  ecx = edx = 0;  // @21_492640
  eax = (u32)(EBP - 30340);  // @22_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @23_492640
  ecx = (u32)(EBP - 30332);  // @24_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(eax));  // @25_492640
  ecx = edx = 0;  // @26_492640
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30340), sizeof v); (u32)v; }) == (u32)(64)) goto L49271d;  // @27_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @28_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_492640
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(757));  // @30_492640
  ecx = edx = 0;  // @31_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_492640
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6871012));  // @33_492640
  ecx = edx = 0;  // @34_492640
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @35_492640
  goto L49278d;  // @36_492640
  L49271d:;
  eax = (u32)(EBP - 30336);  // @38_492640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 30336), &v, sizeof v); }  // @39_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @40_492640
  ecx = (u32)(EBP - 30332);  // @41_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(eax));  // @42_492640
  ecx = edx = 0;  // @43_492640
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }) != (u32)(0)) goto L492756;  // @44_492640
  L492746:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_492640
  ecx = esi;  // @47_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 392)))(ecx, (u32)(1));  // @48_492640
  ecx = edx = 0;  // @49_492640
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @50_492640
  goto L49278d;  // @51_492640
  L492756:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_492640
  ecx = esi;  // @54_492640
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @55_492640
  ecx = edx = 0;  // @56_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_492640
  ecx = esi;  // @58_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }));  // @59_492640
  ecx = edx = 0;  // @60_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_492640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 6827), &v, sizeof v); }  // @62_492640
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }), (u32)(1));  // @63_492640
  ecx = edx = 0;  // @64_492640
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @65_492640
  L49278d:;
  ecx = (u32)(EBP - 30332);  // @67_492640
  eax = ext_499970_thiscall1(ecx);  // @68_492640
  ecx = edx = 0;  // @69_492640
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @70_492640
  SEH_LEAVE();  // @71_492640
  ext_633654(G(u32, 0x6f5630));  // @72_492640
  return eax;  // @73_492640
}
PCREG(492640, lifted_492640);

extern "C" u32 THISCALL lifted_45c730(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665aff);  // @h_45c730
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_45c730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_45c730
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 324)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(edi), (u32)(0));  // @4_45c730
  ecx = edx = 0;  // @5_45c730
  esi = eax;  // @6_45c730
  if ((esi & esi) != 0) goto L45c788;  // @7_45c730
  SEH_LEAVE();  // @8_45c730
  return eax;  // @9_45c730
  L45c788:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_45c730
  ecx = esi;  // @12_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(edi));  // @13_45c730
  ecx = edx = 0;  // @14_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_45c730
  ecx = edi;  // @16_45c730
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @17_45c730
  ecx = edx = 0;  // @18_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @19_45c730
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L45c7d6;  // @20_45c730
  eax = ext_41e290_cdecl1((u32)(28));  // @21_45c730
  ecx = edx = 0;  // @22_45c730
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @23_45c730
  reg.state = (s32)((u32)(0));  // @24_45c730
  if ((eax & eax) == 0) goto L45c7c7;  // @25_45c730
  ecx = eax;  // @26_45c730
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @27_45c730
  ecx = edx = 0;  // @28_45c730
  ecx = eax;  // @29_45c730
  goto L45c7c9;  // @30_45c730
  L45c7c7:;
  ecx = 0;  // @32_45c730
  L45c7c9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @34_45c730
  reg.state = (s32)((u32)(4294967295));  // @35_45c730
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @36_45c730
  L45c7d6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @38_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(esi));  // @40_45c730
  ecx = edx = 0;  // @41_45c730
  if ((eax & eax) == 0) goto L45c7ea;  // @42_45c730
  edx = 0;  // @43_45c730
  goto L45c81b;  // @44_45c730
  L45c7ea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @46_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @47_45c730
  if ((eax & eax) == 0) goto L45c809;  // @48_45c730
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L45c809;  // @49_45c730
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L45c809;  // @50_45c730
  ecx = esi;  // @51_45c730
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @52_45c730
  ecx = edx = 0;  // @53_45c730
  edx = eax;  // @54_45c730
  goto L45c81b;  // @55_45c730
  L45c809:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L45c818;  // @57_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(esi));  // @59_45c730
  ecx = edx = 0;  // @60_45c730
  L45c818:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @62_45c730
  L45c81b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @64_45c730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @65_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edx));  // @67_45c730
  ecx = edx = 0;  // @68_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_45c730
  ecx = edi;  // @70_45c730
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @71_45c730
  ecx = edx = 0;  // @72_45c730
  eax = esi;  // @73_45c730
  SEH_LEAVE();  // @74_45c730
  return eax;  // @75_45c730
}
PCREG(45c730, lifted_45c730);

extern "C" u32 THISCALL lifted_45e710(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45e710
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ext_634273_cdecl2((u32)(edx), (u32)(24));  // @22_45e710
  ecx = edx = 0;  // @23_45e710
  L45e78c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @25_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @26_45e710
  if ((eax & eax) == 0) goto L45e7a1;  // @27_45e710
  eax = ext_634273_cdecl2((u32)(eax), (u32)(8));  // @28_45e710
  ecx = edx = 0;  // @29_45e710
  L45e7a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @31_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @32_45e710
  if ((eax & eax) == 0) goto L45e811;  // @33_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @34_45e710
  if ((eax & eax) == 0) goto L45e7c5;  // @35_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @36_45e710
  if ((edx & edx) == 0) goto L45e7c5;  // @37_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @38_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(edx));  // @40_45e710
  ecx = edx = 0;  // @41_45e710
  L45e7c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @43_45e710
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @44_45e710
  if ((edi & edi) == 0) goto L45e811;  // @45_45e710
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @46_45e710
  if ((ebx & ebx) == 0) goto L45e806;  // @47_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @48_45e710
  reg.state = (s32)((u32)(0));  // @49_45e710
  if ((ecx & ecx) == 0) goto L45e7f4;  // @50_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @51_45e710
  if ((edx & edx) == 0) goto L45e7f4;  // @52_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @54_45e710
  ecx = edx = 0;  // @55_45e710
  L45e7f4:;
  eax = ext_634273_cdecl2((u32)(ebx), (u32)(16));  // @57_45e710
  ecx = edx = 0;  // @58_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @59_45e710
  L45e806:;
  eax = ext_634273_cdecl2((u32)(edi), (u32)(8));  // @61_45e710
  ecx = edx = 0;  // @62_45e710
  L45e811:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }), (u32)(32));  // @64_45e710
  ecx = edx = 0;  // @65_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @66_45e710
  L45e825:;
  SEH_LEAVE();  // @68_45e710
  return eax;  // @69_45e710
}
PCREG(45e710, lifted_45e710);

extern "C" u32 FASTCALL lifted_41c820(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x663e9e);  // @h_41c820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  esi = edx;  // @0_41c820
  edi = ecx;  // @1_41c820
  { u32 v = (u32)((u32)(7338296)); __builtin_memcpy((void *)(u32)(7340972), &v, sizeof v); }  // @2_41c820
  eax = ext_41e290_cdecl1((u32)(44));  // @3_41c820
  ecx = edx = 0;  // @4_41c820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @5_41c820
  reg.state = (s32)((u32)(0));  // @6_41c820
  if ((eax & eax) == 0) goto L41c87d;  // @7_41c820
  ecx = eax;  // @8_41c820
  eax = ext_424d90_thiscall1(ecx);  // @9_41c820
  ecx = edx = 0;  // @10_41c820
  L41c87d:;
  reg.state = (s32)((u32)(4294967295));  // @12_41c820
  eax = ext_41e290_cdecl1((u32)(80));  // @13_41c820
  ecx = edx = 0;  // @14_41c820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @15_41c820
  reg.state = (s32)((u32)(1));  // @16_41c820
  if ((eax & eax) == 0) goto L41c8ac;  // @17_41c820
  ecx = eax;  // @18_41c820
  eax = ext_41f1e0_thiscall4(ecx, (u32)(0), (u32)(-1), (u32)(0));  // @19_41c820
  ecx = edx = 0;  // @20_41c820
  L41c8ac:;
  reg.state = (s32)((u32)(4294967295));  // @22_41c820
  eax = ext_41e290_cdecl1((u32)(280));  // @23_41c820
  ecx = edx = 0;  // @24_41c820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @25_41c820
  reg.state = (s32)((u32)(2));  // @26_41c820
  if ((eax & eax) == 0) goto L41c8d8;  // @27_41c820
  ecx = eax;  // @28_41c820
  eax = ext_426410_thiscall1(ecx);  // @29_41c820
  ecx = edx = 0;  // @30_41c820
  L41c8d8:;
  reg.state = (s32)((u32)(4294967295));  // @32_41c820
  eax = ext_41e290_cdecl1((u32)(9859));  // @33_41c820
  ecx = edx = 0;  // @34_41c820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @35_41c820
  reg.state = (s32)((u32)(3));  // @36_41c820
  if ((eax & eax) == 0) goto L41c905;  // @37_41c820
  ecx = eax;  // @38_41c820
  eax = ext_41fad0_thiscall2(ecx, (u32)(edi));  // @39_41c820
  ecx = edx = 0;  // @40_41c820
  L41c905:;
  reg.state = (s32)((u32)(4294967295));  // @42_41c820
  eax = ext_41e290_cdecl1((u32)(143));  // @43_41c820
  ecx = edx = 0;  // @44_41c820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @45_41c820
  reg.state = (s32)((u32)(4));  // @46_41c820
  if ((eax & eax) == 0) goto L41c931;  // @47_41c820
  ecx = eax;  // @48_41c820
  eax = ext_4285f0_thiscall1(ecx);  // @49_41c820
  ecx = edx = 0;  // @50_41c820
  L41c931:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @52_41c820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_41c820
  reg.state = (s32)((u32)(4294967295));  // @54_41c820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_41c820
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2523), sizeof v); (u32)v; }));  // @56_41c820
  ecx = edx = 0;  // @57_41c820
  if ((esi & esi) == 0) goto L41c98f;  // @58_41c820
  ecx = (u32)(EBP - 144);  // @59_41c820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(esi));  // @60_41c820
  ecx = edx = 0;  // @61_41c820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_41c820
  eax = (u32)(EBP - 144);  // @63_41c820
  reg.state = (s32)((u32)(5));  // @64_41c820
  ecx = (u32)(ecx + 2339);  // @65_41c820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @66_41c820
  ecx = edx = 0;  // @67_41c820
  ecx = (u32)(EBP - 144);  // @68_41c820
  reg.state = (s32)((u32)(4294967295));  // @69_41c820
  eax = ext_4cbec0_thiscall1(ecx);  // @70_41c820
  ecx = edx = 0;  // @71_41c820
  L41c98f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_41c820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_41c820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 28)))(ecx);  // @75_41c820
  ecx = edx = 0;  // @76_41c820
  SEH_LEAVE();  // @77_41c820
  ext_633654(G(u32, 0x6f5630));  // @78_41c820
  return eax;  // @79_41c820
}
PCREG(41c820, lifted_41c820);

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
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_598eb0
  ecx = eax;  // @35_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973184), (u32)(ecx));  // @36_598eb0
  ecx = edx = 0;  // @37_598eb0
  goto L598fda;  // @38_598eb0
  L598f7b:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 312)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @40_598eb0
  ecx = edx = 0;  // @41_598eb0
  ecx = (u32)(EBP - 16);  // @42_598eb0
  goto L598fc6;  // @43_598eb0
  L598f8c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, (u32)(6973232), (u32)(ecx));  // @48_598eb0
  ecx = edx = 0;  // @49_598eb0
  ecx = (u32)(EBP - 16);  // @50_598eb0
  goto L598fc6;  // @51_598eb0
  L598faa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @54_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, (u32)(6973216), (u32)(ecx));  // @56_598eb0
  ecx = edx = 0;  // @57_598eb0
  ecx = (u32)(EBP - 16);  // @58_598eb0
  L598fc6:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_598eb0
  ecx = eax;  // @61_598eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @62_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973200), (u32)(ecx));  // @63_598eb0
  ecx = edx = 0;  // @64_598eb0
  L598fda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @69_598eb0
  ecx = edx = 0;  // @70_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7439), &v, sizeof v); }  // @71_598eb0
  eax = ext_41e290_cdecl1((u32)(76));  // @72_598eb0
  ecx = edx = 0;  // @73_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @74_598eb0
  reg.state = (s32)((u32)(0));  // @75_598eb0
  if ((eax & eax) == 0) goto L599019;  // @76_598eb0
  ecx = eax;  // @77_598eb0
  eax = ext_5eaab0_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7439), sizeof v); (u32)v; }), (u32)(16));  // @78_598eb0
  ecx = edx = 0;  // @79_598eb0
  goto L59901b;  // @80_598eb0
  L599019:;
  eax = 0;  // @82_598eb0
  L59901b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8919), &v, sizeof v); }  // @84_598eb0
  L599021:;
  SEH_LEAVE();  // @86_598eb0
  return eax;  // @87_598eb0
}
PCREG(598eb0, lifted_598eb0);

extern "C" u32 THISCALL lifted_4fe8a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b8b);  // @h_4fe8a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4fe8a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4fe8a0
  eax = (u32)(edi + 72);  // @2_4fe8a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4fe8a0
  ecx = esi;  // @4_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(1));  // @6_4fe8a0
  ecx = edx = 0;  // @7_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_4fe8a0
  eax = (u32)(edi + 95);  // @9_4fe8a0
  ecx = esi;  // @10_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(4));  // @11_4fe8a0
  ecx = edx = 0;  // @12_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_4fe8a0
  eax = (u32)(edi + 99);  // @14_4fe8a0
  ecx = esi;  // @15_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(4));  // @16_4fe8a0
  ecx = edx = 0;  // @17_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_4fe8a0
  eax = (u32)(edi + 103);  // @19_4fe8a0
  ecx = esi;  // @20_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(1));  // @21_4fe8a0
  ecx = edx = 0;  // @22_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4fe8a0
  eax = (u32)(edi + 104);  // @24_4fe8a0
  ecx = esi;  // @25_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(4));  // @26_4fe8a0
  ecx = edx = 0;  // @27_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_4fe8a0
  eax = (u32)(edi + 108);  // @29_4fe8a0
  ecx = esi;  // @30_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(4));  // @31_4fe8a0
  ecx = edx = 0;  // @32_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_4fe8a0
  eax = (u32)(edi + 112);  // @34_4fe8a0
  ecx = esi;  // @35_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(4));  // @36_4fe8a0
  ecx = edx = 0;  // @37_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_4fe8a0
  eax = (u32)(edi + 228);  // @39_4fe8a0
  ecx = esi;  // @40_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(4));  // @41_4fe8a0
  ecx = edx = 0;  // @42_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_4fe8a0
  eax = (u32)(edi + 232);  // @44_4fe8a0
  ecx = esi;  // @45_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(4));  // @46_4fe8a0
  ecx = edx = 0;  // @47_4fe8a0
  ecx = (u32)(EBP - 332);  // @48_4fe8a0
  eax = ext_4febf0_thiscall2(ecx, (u32)(esi));  // @49_4fe8a0
  ecx = edx = 0;  // @50_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 73), sizeof v); (u32)v; });  // @51_4fe8a0
  ecx = (u32)(EBP - 332);  // @52_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @53_4fe8a0
  reg.state = (s32)((u32)(0));  // @54_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(eax));  // @55_4fe8a0
  ecx = edx = 0;  // @56_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 75), sizeof v); (u32)v; });  // @57_4fe8a0
  ecx = (u32)(EBP - 332);  // @58_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @59_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(eax));  // @60_4fe8a0
  ecx = edx = 0;  // @61_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 77), sizeof v); (u32)v; });  // @62_4fe8a0
  ecx = (u32)(EBP - 332);  // @63_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @64_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(eax));  // @65_4fe8a0
  ecx = edx = 0;  // @66_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 79), sizeof v); (u32)v; });  // @67_4fe8a0
  ecx = (u32)(EBP - 332);  // @68_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @69_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(eax));  // @70_4fe8a0
  ecx = edx = 0;  // @71_4fe8a0
  ecx = (u32)(EBP - 332);  // @72_4fe8a0
  eax = ext_499980_thiscall1(ecx);  // @73_4fe8a0
  ecx = edx = 0;  // @74_4fe8a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @75_4fe8a0
  SEH_LEAVE();  // @76_4fe8a0
  ext_633654(G(u32, 0x6f5630));  // @77_4fe8a0
  return eax;  // @78_4fe8a0
}
PCREG(4fe8a0, lifted_4fe8a0);

extern "C" u32 THISCALL lifted_5c5f30(u32 ecx_in) {
  SEH_ENTER(0x66c6b6);  // @h_5c5f30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @30_5c5f30
  ecx = edx = 0;  // @31_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @32_5c5f30
  edx = (u32)(EBP - 24);  // @33_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @35_5c5f30
  ecx = edx = 0;  // @36_5c5f30
  esi = eax;  // @37_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L5c5fff;  // @38_5c5f30
  L5c5fb7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @40_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fc4;  // @41_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @43_5c5f30
  ecx = edx = 0;  // @44_5c5f30
  L5c5fc4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @46_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fd1;  // @47_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @49_5c5f30
  ecx = edx = 0;  // @50_5c5f30
  L5c5fd1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @52_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fde;  // @53_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @55_5c5f30
  ecx = edx = 0;  // @56_5c5f30
  L5c5fde:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @58_5c5f30
  if ((ecx & ecx) == 0) goto L5c5feb;  // @59_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @61_5c5f30
  ecx = edx = 0;  // @62_5c5f30
  L5c5feb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @64_5c5f30
  edx = (u32)(EBP - 24);  // @65_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @67_5c5f30
  ecx = edx = 0;  // @68_5c5f30
  esi = eax;  // @69_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L5c5fb7;  // @70_5c5f30
  L5c5fff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @72_5c5f30
  if ((ecx & ecx) == 0) goto L5c600c;  // @73_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @75_5c5f30
  ecx = edx = 0;  // @76_5c5f30
  L5c600c:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @78_5c5f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @79_5c5f30
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @80_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_5c5f30
  reg.state = (s32)((u32)(0));  // @82_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @83_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(edi));  // @85_5c5f30
  ecx = edx = 0;  // @86_5c5f30
  SEH_LEAVE();  // @87_5c5f30
  return eax;  // @88_5c5f30
}
PCREG(5c5f30, lifted_5c5f30);

