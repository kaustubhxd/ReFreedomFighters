// batch200067.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
extern "C" u32 STDCALL ext_492200_stdcall1(u32) __asm__("ext_492200");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_41cfd0_thiscall1(u32) __asm__("ext_41cfd0");
extern "C" u32 THISCALL ext_43e0f0_thiscall1(u32) __asm__("ext_43e0f0");
extern "C" u32 THISCALL ext_43e990_thiscall4(u32, u32, u32, u32) __asm__("ext_43e990");
extern "C" u32 THISCALL ext_456ab0_thiscall1(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_492880_thiscall2(u32, u32) __asm__("ext_492880");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_4c4740_thiscall4(u32, u32, u32, u32) __asm__("ext_4c4740");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4e5000_thiscall1(u32) __asm__("ext_4e5000");
extern "C" u32 THISCALL ext_4e66a0_thiscall1(u32) __asm__("ext_4e66a0");
extern "C" u32 THISCALL ext_4febf0_thiscall2(u32, u32) __asm__("ext_4febf0");
extern "C" u32 THISCALL ext_4ff7b0_thiscall1(u32) __asm__("ext_4ff7b0");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_54e9a0_thiscall1(u32) __asm__("ext_54e9a0");
extern "C" u32 THISCALL ext_54f890_thiscall1(u32) __asm__("ext_54f890");
extern "C" u32 THISCALL ext_557930_thiscall1(u32) __asm__("ext_557930");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f12d0_thiscall1(u32) __asm__("ext_5f12d0");
extern "C" u32 THISCALL ext_5f9700_thiscall3(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 THISCALL ext_5fb110_thiscall2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 THISCALL ext_5fb980_thiscall3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_602290_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_604650_thiscall1(u32) __asm__("ext_604650");
extern "C" u32 THISCALL ext_607f60_thiscall4(u32, u32, u32, u32) __asm__("ext_607f60");
extern "C" u32 THISCALL ext_6593c0_thiscall1(u32) __asm__("ext_6593c0");
extern "C" u32 ext_41c750_cdecl0(void) __asm__("ext_41c750");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_557860_cdecl0(void) __asm__("ext_557860");
extern "C" u32 ext_560310_cdecl0(void) __asm__("ext_560310");
extern "C" u32 ext_560580_cdecl0(void) __asm__("ext_560580");
extern "C" u32 ext_580000_cdecl0(void) __asm__("ext_580000");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

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

extern "C" u32 FASTCALL lifted_5579b0(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x66ae9f);  // @h_5579b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  edi = edx;  // @0_5579b0
  ebx = ecx;  // @1_5579b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421700), sizeof v); (u32)v; });  // @2_5579b0
  if ((ecx & ecx) == 0) goto L5579f7;  // @3_5579b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5579b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @5_5579b0
  ecx = edx = 0;  // @6_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7421700), &v, sizeof v); }  // @7_5579b0
  L5579f7:;
  eax = ext_41e290_cdecl1((u32)(40));  // @9_5579b0
  ecx = edx = 0;  // @10_5579b0
  esi = eax;  // @11_5579b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_5579b0
  reg.state = (s32)((u32)(0));  // @13_5579b0
  if ((esi & esi) == 0) goto L557a3e;  // @14_5579b0
  ecx = esi;  // @15_5579b0
  eax = ext_5f9700_thiscall3(ecx, (u32)(ebx), (u32)(edi));  // @16_5579b0
  ecx = edx = 0;  // @17_5579b0
  { u32 v = (u32)((u32)(6969252)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @18_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @19_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @20_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @21_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @22_5579b0
  goto L557a40;  // @23_5579b0
  L557a3e:;
  esi = 0;  // @25_5579b0
  L557a40:;
  reg.state = (s32)((u32)(4294967295));  // @27_5579b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7421700), &v, sizeof v); }  // @28_5579b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421484), sizeof v); (u32)v; }) != (u32)(0)) goto L557ab1;  // @29_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @30_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @31_5579b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @32_5579b0
  ecx = (u32)(EBP - 32);  // @33_5579b0
  reg.state = (s32)((u32)(1));  // @34_5579b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @35_5579b0
  eax = ext_59a9b0_thiscall2(ecx, (u32)(50));  // @36_5579b0
  ecx = edx = 0;  // @37_5579b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_5579b0
  ecx = (u32)(EBP - 32);  // @39_5579b0
  ecx = esi;  // @40_5579b0
  reg.state = (s32)((u32)(2));  // @41_5579b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(ecx));  // @42_5579b0
  ecx = edx = 0;  // @43_5579b0
  ecx = (u32)(EBP - 32);  // @44_5579b0
  eax = ext_4ff9d0_thiscall1(ecx);  // @45_5579b0
  ecx = edx = 0;  // @46_5579b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421700), sizeof v); (u32)v; });  // @47_5579b0
  SEH_LEAVE();  // @48_5579b0
  return eax;  // @49_5579b0
  L557ab1:;
  eax = esi;  // @51_5579b0
  SEH_LEAVE();  // @52_5579b0
  return eax;  // @53_5579b0
}
PCREG(5579b0, lifted_5579b0);

extern "C" u32 THISCALL lifted_4affa0(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4affa0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @15_4affa0
  ecx = edx = 0;  // @16_4affa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_4affa0
  ecx = eax;  // @18_4affa0
  reg.state = (s32)((u32)(0));  // @19_4affa0
  eax = ext_4cc1d0_thiscall1(ecx);  // @20_4affa0
  ecx = edx = 0;  // @21_4affa0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6890800), (u32)(eax));  // @22_4affa0
  ecx = edx = 0;  // @23_4affa0
  reg.state = (s32)((u32)(4294967295));  // @24_4affa0
  ecx = (u32)(EBP - 144);  // @25_4affa0
  eax = ext_4cbec0_thiscall1(ecx);  // @26_4affa0
  ecx = edx = 0;  // @27_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @28_4affa0
  ecx = ebx;  // @29_4affa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @30_4affa0
  ecx = edx = 0;  // @31_4affa0
  goto L4b00a4;  // @32_4affa0
  L4b0049:;
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) < (s32)(u32)(0)) goto L4b0058;  // @34_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(ebx));  // @36_4affa0
  ecx = edx = 0;  // @37_4affa0
  L4b0058:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @40_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_4affa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @42_4affa0
  ecx = edx = 0;  // @43_4affa0
  ecx = (u32)(EBP - 148);  // @44_4affa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @45_4affa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_4affa0
  ecx = eax;  // @47_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6889580), (u32)(ecx));  // @48_4affa0
  ecx = edx = 0;  // @49_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @51_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @53_4affa0
  ecx = edx = 0;  // @54_4affa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @55_4affa0
  L4b00a4:;
  SEH_LEAVE();  // @57_4affa0
  ext_633654(G(u32, 0x6f5630));  // @58_4affa0
  return eax;  // @59_4affa0
}
PCREG(4affa0, lifted_4affa0);

extern "C" u32 FASTCALL lifted_560440(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x66afdf);  // @h_560440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  edi = edx;  // @0_560440
  ebx = ecx;  // @1_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7422364), &v, sizeof v); }  // @2_560440
  eax = ext_41e290_cdecl1((u32)(12));  // @3_560440
  ecx = edx = 0;  // @4_560440
  esi = eax;  // @5_560440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_560440
  reg.state = (s32)((u32)(0));  // @7_560440
  if ((esi & esi) == 0) goto L5604a1;  // @8_560440
  ecx = esi;  // @9_560440
  eax = ext_5f9700_thiscall3(ecx, (u32)(ebx), (u32)(edi));  // @10_560440
  ecx = edx = 0;  // @11_560440
  { u32 v = (u32)((u32)(6971852)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_560440
  goto L5604a3;  // @13_560440
  L5604a1:;
  esi = 0;  // @15_560440
  L5604a3:;
  reg.state = (s32)((u32)(4294967295));  // @17_560440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7422364), &v, sizeof v); }  // @18_560440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422360), sizeof v); (u32)v; }) != (u32)(0)) goto L560514;  // @19_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @20_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @21_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @22_560440
  ecx = (u32)(EBP - 32);  // @23_560440
  reg.state = (s32)((u32)(1));  // @24_560440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @25_560440
  eax = ext_59a9b0_thiscall2(ecx, (u32)(50));  // @26_560440
  ecx = edx = 0;  // @27_560440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_560440
  ecx = (u32)(EBP - 32);  // @29_560440
  ecx = esi;  // @30_560440
  reg.state = (s32)((u32)(2));  // @31_560440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(ecx));  // @32_560440
  ecx = edx = 0;  // @33_560440
  ecx = (u32)(EBP - 32);  // @34_560440
  eax = ext_4ff9d0_thiscall1(ecx);  // @35_560440
  ecx = edx = 0;  // @36_560440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422364), sizeof v); (u32)v; });  // @37_560440
  SEH_LEAVE();  // @38_560440
  return eax;  // @39_560440
  L560514:;
  eax = esi;  // @41_560440
  SEH_LEAVE();  // @42_560440
  return eax;  // @43_560440
}
PCREG(560440, lifted_560440);

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

extern "C" u32 STDCALL lifted_601e20(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  eax = ext_41e290_cdecl1((u32)(42));  // @0_601e20
  ecx = edx = 0;  // @1_601e20
  esi = eax;  // @2_601e20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601e20
  reg.state = (s32)((u32)(0));  // @4_601e20
  if ((esi & esi) == 0) goto L601e90;  // @5_601e20
  ecx = esi;  // @6_601e20
  eax = ext_603500_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_601e20
  ecx = edx = 0;  // @8_601e20
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_601e20
  eax = (u32)(esi + 12);  // @10_601e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @11_601e20
  eax = 0;  // @12_601e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @13_601e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @14_601e20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @15_601e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_601e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @17_601e20
  goto L601e92;  // @18_601e20
  L601e90:;
  esi = 0;  // @20_601e20
  L601e92:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_601e20
  ecx = esi;  // @23_601e20
  reg.state = (s32)((u32)(4294967295));  // @24_601e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @25_601e20
  ecx = edx = 0;  // @26_601e20
  eax = esi;  // @27_601e20
  SEH_LEAVE();  // @28_601e20
  return eax;  // @29_601e20
}
PCREG(601e20, lifted_601e20);

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

extern "C" u32 lifted_41cfd0(void) {
  SEH_ENTER(0x663f7f);  // @h_41cfd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  eax = ext_41e290_cdecl1((u32)(13));  // @0_41cfd0
  ecx = edx = 0;  // @1_41cfd0
  edx = eax;  // @2_41cfd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_41cfd0
  if ((edx & edx) == 0) goto L41d019;  // @4_41cfd0
  { u32 v = (u32)((u32)(6777852)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @5_41cfd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @6_41cfd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @7_41cfd0
  goto L41d01b;  // @8_41cfd0
  L41d019:;
  edx = 0;  // @10_41cfd0
  L41d01b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @12_41cfd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7327044), &v, sizeof v); }  // @13_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_41cfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @15_41cfd0
  ecx = edx = 0;  // @16_41cfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @17_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_41cfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(9));  // @19_41cfd0
  ecx = edx = 0;  // @20_41cfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327048), sizeof v); (u32)v; }) != (u32)(0)) goto L41d07a;  // @21_41cfd0
  eax = ext_41e290_cdecl1((u32)(109));  // @22_41cfd0
  ecx = edx = 0;  // @23_41cfd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @24_41cfd0
  reg.state = (s32)((u32)(0));  // @25_41cfd0
  if ((eax & eax) == 0) goto L41d066;  // @26_41cfd0
  ecx = eax;  // @27_41cfd0
  eax = ext_54f890_thiscall1(ecx);  // @28_41cfd0
  ecx = edx = 0;  // @29_41cfd0
  ecx = eax;  // @30_41cfd0
  goto L41d068;  // @31_41cfd0
  L41d066:;
  ecx = 0;  // @33_41cfd0
  L41d068:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7327048), &v, sizeof v); }  // @35_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_41cfd0
  reg.state = (s32)((u32)(4294967295));  // @37_41cfd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @38_41cfd0
  ecx = edx = 0;  // @39_41cfd0
  L41d07a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @41_41cfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) == (u32)(0)) goto L41d096;  // @42_41cfd0
  eax = ext_580000_cdecl0();  // @43_41cfd0
  ecx = edx = 0;  // @44_41cfd0
  eax = ext_560580_cdecl0();  // @45_41cfd0
  ecx = edx = 0;  // @46_41cfd0
  eax = ext_41c750_cdecl0();  // @47_41cfd0
  ecx = edx = 0;  // @48_41cfd0
  L41d096:;
  SEH_LEAVE();  // @50_41cfd0
  return eax;  // @51_41cfd0
}
PCREG(41cfd0, lifted_41cfd0);

extern "C" u32 THISCALL lifted_5082c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_5082c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6932144), (u32)(6932912));  // @15_5082c0
  ecx = edx = 0;  // @16_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @17_5082c0
  if ((eax & eax) == 0) goto L508340;  // @18_5082c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @19_5082c0
  ecx = edx = 0;  // @20_5082c0
  eax = 0;  // @21_5082c0
  goto L508350;  // @22_5082c0
  L508340:;
  __builtin_trap();  // @24_5082c0
  L508345:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_5082c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @28_5082c0
  ecx = edx = 0;  // @29_5082c0
  goto L508350;  // @30_5082c0
  L50834e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_5082c0
  L508350:;
  ecx = (u32)(EBP - 144);  // @34_5082c0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @35_5082c0
  ecx = edx = 0;  // @36_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @37_5082c0
  eax = (u32)(EBP - 144);  // @38_5082c0
  ecx = (ecx + (u32)(1042));  // @39_5082c0
  reg.state = (s32)((u32)(0));  // @40_5082c0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @41_5082c0
  ecx = edx = 0;  // @42_5082c0
  ecx = (u32)(EBP - 144);  // @43_5082c0
  eax = ext_4cbec0_thiscall1(ecx);  // @44_5082c0
  ecx = edx = 0;  // @45_5082c0
  SEH_LEAVE();  // @46_5082c0
  ext_633654(G(u32, 0x6f5630));  // @47_5082c0
  return eax;  // @48_5082c0
}
PCREG(5082c0, lifted_5082c0);

extern "C" u32 STDCALL lifted_5f3050(u32 a0, u32 a1) {
  SEH_ENTER(0x66d04f);  // @h_5f3050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = esi;  // @18_5f3050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(ecx));  // @19_5f3050
  ecx = edx = 0;  // @20_5f3050
  L5f30b3:;
  eax = esi;  // @22_5f3050
  SEH_LEAVE();  // @23_5f3050
  return eax;  // @24_5f3050
}
PCREG(5f3050, lifted_5f3050);

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

extern "C" u32 THISCALL lifted_4558a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_4558a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4558a0
  eax = ext_43e0f0_thiscall1(ecx);  // @1_4558a0
  ecx = edx = 0;  // @2_4558a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) != (u32)(0)) goto L455981;  // @3_4558a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; });  // @4_4558a0
  if ((eax & eax) == 0) goto L455981;  // @5_4558a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L455981;  // @6_4558a0
  ecx = (u32)(EBP - 144);  // @7_4558a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @8_4558a0
  ecx = edx = 0;  // @9_4558a0
  ecx = (u32)(EBP - 144);  // @10_4558a0
  reg.state = (s32)((u32)(0));  // @11_4558a0
  eax = ext_456ab0_thiscall1(ecx);  // @12_4558a0
  ecx = edx = 0;  // @13_4558a0
  ecx = (u32)(EBP - 144);  // @14_4558a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 73), &v, sizeof v); }  // @15_4558a0
  reg.state = (s32)((u32)(4294967295));  // @16_4558a0
  eax = ext_4cbec0_thiscall1(ecx);  // @17_4558a0
  ecx = edx = 0;  // @18_4558a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) != (u32)(0)) goto L455981;  // @19_4558a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @20_4558a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4558a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(322));  // @22_4558a0
  ecx = edx = 0;  // @23_4558a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_4558a0
  edi = eax;  // @25_4558a0
  eax = (u32)(EBP - 272);  // @26_4558a0
  ecx = ebx;  // @27_4558a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @28_4558a0
  ecx = edx = 0;  // @29_4558a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_4558a0
  ecx = eax;  // @31_4558a0
  reg.state = (s32)((u32)(1));  // @32_4558a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @33_4558a0
  ecx = edx = 0;  // @34_4558a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6827488), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; }), (u32)(eax));  // @35_4558a0
  ecx = edx = 0;  // @36_4558a0
  ecx = (u32)(EBP - 272);  // @37_4558a0
  eax = ext_4cbec0_thiscall1(ecx);  // @38_4558a0
  ecx = edx = 0;  // @39_4558a0
  L455981:;
  SEH_LEAVE();  // @41_4558a0
  ext_633654(G(u32, 0x6f5630));  // @42_4558a0
  return eax;  // @43_4558a0
}
PCREG(4558a0, lifted_4558a0);

extern "C" u32 THISCALL lifted_614040(u32 ecx_in) {
  SEH_ENTER(0x66e46d);  // @h_614040
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_614040
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; }) != (u32)(0)) goto L6140b2;  // @1_614040
  eax = ext_41e290_cdecl1((u32)(20));  // @2_614040
  ecx = edx = 0;  // @3_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_614040
  if ((eax & eax) == 0) goto L6140a3;  // @5_614040
  ecx = (u32)(esi + 568);  // @6_614040
  { u32 v = (u32)((u32)(7068068)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @7_614040
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @8_614040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @9_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @11_614040
  goto L6140a5;  // @12_614040
  L6140a3:;
  eax = 0;  // @14_614040
  L6140a5:;
  reg.state = (s32)((u32)(4294967295));  // @16_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 544), &v, sizeof v); }  // @17_614040
  L6140b2:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 548), sizeof v); (u32)v; }) != (u32)(0)) goto L6140fe;  // @19_614040
  eax = ext_41e290_cdecl1((u32)(20));  // @20_614040
  ecx = edx = 0;  // @21_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_614040
  if ((eax & eax) == 0) goto L6140ef;  // @23_614040
  ecx = (u32)(esi + 568);  // @24_614040
  { u32 v = (u32)((u32)(7068128)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_614040
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @26_614040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @27_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @28_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @29_614040
  goto L6140f1;  // @30_614040
  L6140ef:;
  eax = 0;  // @32_614040
  L6140f1:;
  reg.state = (s32)((u32)(4294967295));  // @34_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 548), &v, sizeof v); }  // @35_614040
  L6140fe:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 552), sizeof v); (u32)v; }) != (u32)(0)) goto L61414a;  // @37_614040
  eax = ext_41e290_cdecl1((u32)(20));  // @38_614040
  ecx = edx = 0;  // @39_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @40_614040
  if ((eax & eax) == 0) goto L61413b;  // @41_614040
  ecx = (u32)(esi + 568);  // @42_614040
  { u32 v = (u32)((u32)(7068188)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @43_614040
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @44_614040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @45_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @46_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @47_614040
  goto L61413d;  // @48_614040
  L61413b:;
  eax = 0;  // @50_614040
  L61413d:;
  reg.state = (s32)((u32)(4294967295));  // @52_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 552), &v, sizeof v); }  // @53_614040
  L61414a:;
  ecx = esi;  // @55_614040
  eax = ext_6593c0_thiscall1(ecx);  // @56_614040
  ecx = edx = 0;  // @57_614040
  SEH_LEAVE();  // @58_614040
  return eax;  // @59_614040
}
PCREG(614040, lifted_614040);

extern "C" u32 THISCALL lifted_4957f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66809f);  // @h_4957f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4957f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @2_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @5_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @6_4957f0
  if ((eax & eax) == 0) goto L4958c8;  // @7_4957f0
  eax = ext_41e290_cdecl1((u32)(eax));  // @8_4957f0
  ecx = edx = 0;  // @9_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @10_4957f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L4958a8;  // @11_4957f0
  eax = ext_41e290_cdecl1((u32)(16));  // @12_4957f0
  ecx = edx = 0;  // @13_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_4957f0
  reg.state = (s32)((u32)(0));  // @15_4957f0
  if ((eax & eax) == 0) goto L495890;  // @16_4957f0
  ecx = eax;  // @17_4957f0
  eax = ext_4ccdd0_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }), (u32)(1024));  // @18_4957f0
  ecx = edx = 0;  // @19_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @20_4957f0
  eax = esi;  // @21_4957f0
  SEH_LEAVE();  // @22_4957f0
  return eax;  // @23_4957f0
  L495890:;
  eax = 0;  // @25_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_4957f0
  eax = esi;  // @27_4957f0
  SEH_LEAVE();  // @28_4957f0
  return eax;  // @29_4957f0
  L4958a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @31_4957f0
  if ((eax & eax) == 0) goto L4958c7;  // @32_4957f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @33_4957f0
  ecx = edx = 0;  // @34_4957f0
  eax = esi;  // @35_4957f0
  SEH_LEAVE();  // @36_4957f0
  return eax;  // @37_4957f0
  L4958c7:;
  __builtin_trap();  // @39_4957f0
  L4958c8:;
  eax = esi;  // @41_4957f0
  SEH_LEAVE();  // @42_4957f0
  return eax;  // @43_4957f0
}
PCREG(4957f0, lifted_4957f0);

extern "C" u32 THISCALL lifted_4b1930(u32 ecx_in) {
  SEH_ENTER(0x668b96);  // @h_4b1930
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4b1930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4b1930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 218), sizeof v); (u32)v; }));  // @4_4b1930
  ecx = edx = 0;  // @5_4b1930
  ecx = eax;  // @6_4b1930
  if ((ecx & ecx) != 0) goto L4b19e2;  // @7_4b1930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @8_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4b1930
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(3865));  // @10_4b1930
  ecx = edx = 0;  // @11_4b1930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @12_4b1930
  edi = eax;  // @13_4b1930
  eax = (u32)(EBP - 144);  // @14_4b1930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4b1930
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @16_4b1930
  ecx = edx = 0;  // @17_4b1930
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_4b1930
  ecx = eax;  // @19_4b1930
  reg.state = (s32)((u32)(0));  // @20_4b1930
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_4b1930
  ecx = edx = 0;  // @22_4b1930
  L4b19bd:;
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6891256), (u32)(eax));  // @24_4b1930
  ecx = edx = 0;  // @25_4b1930
  reg.state = (s32)((u32)(4294967295));  // @26_4b1930
  ecx = (u32)(EBP - 144);  // @27_4b1930
  eax = ext_4cbec0_thiscall1(ecx);  // @28_4b1930
  ecx = edx = 0;  // @29_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @30_4b1930
  ecx = ebx;  // @31_4b1930
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @32_4b1930
  ecx = edx = 0;  // @33_4b1930
  goto L4b1a93;  // @34_4b1930
  L4b19e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4b1930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6886756));  // @37_4b1930
  ecx = edx = 0;  // @38_4b1930
  ecx = eax;  // @39_4b1930
  if ((ecx & ecx) != 0) goto L4b1a38;  // @40_4b1930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @41_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4b1930
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(3876));  // @43_4b1930
  ecx = edx = 0;  // @44_4b1930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @45_4b1930
  edi = eax;  // @46_4b1930
  eax = (u32)(EBP - 144);  // @47_4b1930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_4b1930
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @49_4b1930
  ecx = edx = 0;  // @50_4b1930
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_4b1930
  ecx = eax;  // @52_4b1930
  reg.state = (s32)((u32)(1));  // @53_4b1930
  eax = ext_4cc1d0_thiscall1(ecx);  // @54_4b1930
  ecx = edx = 0;  // @55_4b1930
  goto L4b19bd;  // @56_4b1930
  L4b1a38:;
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) < (s32)(u32)(0)) goto L4b1a47;  // @58_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4b1930
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(ebx), (u32)(6891328), (u32)(eax));  // @60_4b1930
  ecx = edx = 0;  // @61_4b1930
  L4b1a47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_4b1930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4b1930
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @66_4b1930
  ecx = edx = 0;  // @67_4b1930
  ecx = (u32)(EBP - 148);  // @68_4b1930
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @69_4b1930
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @70_4b1930
  ecx = eax;  // @71_4b1930
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6889580), (u32)(ecx));  // @72_4b1930
  ecx = edx = 0;  // @73_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_4b1930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @75_4b1930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_4b1930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @77_4b1930
  ecx = edx = 0;  // @78_4b1930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @79_4b1930
  L4b1a93:;
  SEH_LEAVE();  // @81_4b1930
  ext_633654(G(u32, 0x6f5630));  // @82_4b1930
  return eax;  // @83_4b1930
}
PCREG(4b1930, lifted_4b1930);

extern "C" u32 THISCALL lifted_578560(u32 ecx_in) {
  SEH_ENTER(0x66b15e);  // @h_578560
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_578560
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_578560
  eax = ext_561020_thiscall1(ecx);  // @2_578560
  ecx = edx = 0;  // @3_578560
  { u32 v = (u32)((u32)(6986028)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_578560
  reg.state = (s32)((u32)(0));  // @7_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_578560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6986320), (u32)(0), (u32)(6986276), (u32)(18));  // @9_578560
  ecx = edx = 0;  // @10_578560
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 408), &v, sizeof v); }  // @11_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_578560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6986340), (u32)(0), (u32)(6986276), (u32)(19));  // @15_578560
  ecx = edx = 0;  // @16_578560
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 410), &v, sizeof v); }  // @17_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @18_578560
  ecx = edx = 0;  // @19_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @20_578560
  reg.state = (s32)((u32)(1));  // @21_578560
  if ((eax & eax) == 0) goto L578621;  // @22_578560
  ecx = (u32)(esi + 424);  // @23_578560
  ecx = eax;  // @24_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986364), (u32)(6975376), (u32)(ecx));  // @25_578560
  ecx = edx = 0;  // @26_578560
  edx = eax;  // @27_578560
  goto L578623;  // @28_578560
  L578621:;
  edx = 0;  // @30_578560
  L578623:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 412), &v, sizeof v); }  // @32_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_578560
  reg.state = (s32)((u32)(0));  // @34_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @36_578560
  ecx = edx = 0;  // @37_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @38_578560
  ecx = edx = 0;  // @39_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @40_578560
  reg.state = (s32)((u32)(2));  // @41_578560
  if ((eax & eax) == 0) goto L578670;  // @42_578560
  ecx = (u32)(esi + 428);  // @43_578560
  ecx = eax;  // @44_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986372), (u32)(6975376), (u32)(ecx));  // @45_578560
  ecx = edx = 0;  // @46_578560
  edx = eax;  // @47_578560
  goto L578672;  // @48_578560
  L578670:;
  edx = 0;  // @50_578560
  L578672:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 416), &v, sizeof v); }  // @52_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_578560
  reg.state = (s32)((u32)(0));  // @54_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @56_578560
  ecx = edx = 0;  // @57_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @58_578560
  ecx = edx = 0;  // @59_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @60_578560
  reg.state = (s32)((u32)(3));  // @61_578560
  if ((eax & eax) == 0) goto L5786bf;  // @62_578560
  ecx = (u32)(esi + 432);  // @63_578560
  ecx = eax;  // @64_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986380), (u32)(6975376), (u32)(ecx));  // @65_578560
  ecx = edx = 0;  // @66_578560
  edx = eax;  // @67_578560
  goto L5786c1;  // @68_578560
  L5786bf:;
  edx = 0;  // @70_578560
  L5786c1:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 420), &v, sizeof v); }  // @72_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_578560
  reg.state = (s32)((u32)(0));  // @74_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @76_578560
  ecx = edx = 0;  // @77_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 424), &v, sizeof v); }  // @78_578560
  eax = esi;  // @79_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 428), &v, sizeof v); }  // @80_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 432), &v, sizeof v); }  // @81_578560
  SEH_LEAVE();  // @82_578560
  return eax;  // @83_578560
}
PCREG(578560, lifted_578560);

extern "C" u32 THISCALL lifted_602750(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x66db0c);  // @h_602750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = (u32)(EBP - 16);  // @6_602750
  eax = ext_5fb980_thiscall3(ecx, (u32)(eax), (u32)(eax));  // @7_602750
  ecx = edx = 0;  // @8_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @9_602750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) != eax) goto L60283f;  // @10_602750
  eax = ext_41e290_cdecl1((u32)(48));  // @11_602750
  ecx = edx = 0;  // @12_602750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @13_602750
  reg.state = (s32)((u32)(1));  // @14_602750
  if ((eax & eax) == 0) goto L6027cd;  // @15_602750
  ecx = eax;  // @16_602750
  eax = ext_602290_thiscall5(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; }));  // @17_602750
  ecx = edx = 0;  // @18_602750
  ebx = eax;  // @19_602750
  goto L6027cf;  // @20_602750
  L6027cd:;
  ebx = 0;  // @22_602750
  L6027cf:;
  reg.state = (s32)((u32)(0));  // @24_602750
  eax = ext_41e290_cdecl1((u32)(40));  // @25_602750
  ecx = edx = 0;  // @26_602750
  esi = eax;  // @27_602750
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 32), &v, sizeof v); }  // @28_602750
  reg.state = (s32)((u32)(2));  // @29_602750
  if ((esi & esi) == 0) goto L602824;  // @30_602750
  eax = (u32)(EBP + 8);  // @31_602750
  { u32 v = (u32)((u32)(7051460)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @32_602750
  ecx = (u32)(esi + 4);  // @33_602750
  eax = ext_5f10c0_thiscall2(ecx, (u32)(eax));  // @34_602750
  ecx = edx = 0;  // @35_602750
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @36_602750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @37_602750
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @38_602750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @39_602750
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @40_602750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @41_602750
  goto L602826;  // @42_602750
  L602824:;
  esi = 0;  // @44_602750
  L602826:;
  eax = (u32)(EBP + 8);  // @46_602750
  reg.state = (s32)((u32)(0));  // @47_602750
  ecx = edi;  // @48_602750
  eax = ext_5fb110_thiscall2(ecx, (u32)(eax));  // @49_602750
  ecx = edx = 0;  // @50_602750
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @51_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @52_602750
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @53_602750
  goto L602872;  // @54_602750
  L60283f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @56_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_602750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051464), (u32)(90));  // @58_602750
  ecx = edx = 0;  // @59_602750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_602750
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6932144), (u32)(7051644));  // @61_602750
  ecx = edx = 0;  // @62_602750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @63_602750
  if ((eax & eax) == 0) goto L602871;  // @64_602750
  eax = ((u32(STDCALL *)(void))(eax))();  // @65_602750
  ecx = edx = 0;  // @66_602750
  goto L602872;  // @67_602750
  L602871:;
  __builtin_trap();  // @69_602750
  L602872:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @71_602750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @72_602750
  eax = (eax - ecx);  // @73_602750
  reg.state = (s32)((u32)(3));  // @74_602750
  if ((ecx & ecx) == 0) goto L602893;  // @75_602750
  if ((eax & eax) == 0) goto L602893;  // @76_602750
  ecx = (u32)(EBP + 8);  // @77_602750
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @78_602750
  ecx = edx = 0;  // @79_602750
  L602893:;
  SEH_LEAVE();  // @81_602750
  return eax;  // @82_602750
}
PCREG(602750, lifted_602750);

extern "C" u32 THISCALL lifted_54fb70(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_54fb70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_54fb70
  { u32 v = (u32)((u32)(6965892)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; }), (u32)(4));  // @2_54fb70
  ecx = edx = 0;  // @3_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; }), (u32)(4));  // @4_54fb70
  ecx = edx = 0;  // @5_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65), sizeof v); (u32)v; }), (u32)(4));  // @6_54fb70
  ecx = edx = 0;  // @7_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; }), (u32)(4));  // @8_54fb70
  ecx = edx = 0;  // @9_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; }), (u32)(4));  // @10_54fb70
  ecx = edx = 0;  // @11_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 49), sizeof v); (u32)v; }), (u32)(4));  // @12_54fb70
  ecx = edx = 0;  // @13_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 53), sizeof v); (u32)v; }), (u32)(4));  // @14_54fb70
  ecx = edx = 0;  // @15_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 57), sizeof v); (u32)v; }), (u32)(4));  // @16_54fb70
  ecx = edx = 0;  // @17_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; }), (u32)(4));  // @18_54fb70
  ecx = edx = 0;  // @19_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; }), (u32)(4));  // @20_54fb70
  ecx = edx = 0;  // @21_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 37), sizeof v); (u32)v; }), (u32)(4));  // @22_54fb70
  ecx = edx = 0;  // @23_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 33), sizeof v); (u32)v; }), (u32)(4));  // @24_54fb70
  ecx = edx = 0;  // @25_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }), (u32)(4));  // @26_54fb70
  ecx = edx = 0;  // @27_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }), (u32)(4));  // @28_54fb70
  ecx = edx = 0;  // @29_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; }), (u32)(4));  // @30_54fb70
  ecx = edx = 0;  // @31_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; }), (u32)(4));  // @32_54fb70
  ecx = edx = 0;  // @33_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; }), (u32)(4));  // @34_54fb70
  ecx = edx = 0;  // @35_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 93), sizeof v); (u32)v; }), (u32)(4));  // @36_54fb70
  ecx = edx = 0;  // @37_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 97), sizeof v); (u32)v; }), (u32)(4));  // @38_54fb70
  ecx = edx = 0;  // @39_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 101), sizeof v); (u32)v; }), (u32)(4));  // @40_54fb70
  ecx = edx = 0;  // @41_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 105), sizeof v); (u32)v; }), (u32)(4));  // @42_54fb70
  ecx = edx = 0;  // @43_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; }), (u32)(4));  // @44_54fb70
  ecx = edx = 0;  // @45_54fb70
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }), (u32)(4));  // @46_54fb70
  ecx = edx = 0;  // @47_54fb70
  ecx = 0;  // @48_54fb70
  eax = ext_557930_thiscall1(ecx);  // @49_54fb70
  ecx = edx = 0;  // @50_54fb70
  ecx = eax;  // @51_54fb70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @52_54fb70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @53_54fb70
  ecx = edx = 0;  // @54_54fb70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @55_54fb70
  if ((ecx & ecx) == 0) goto L54fca4;  // @56_54fb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_54fb70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @58_54fb70
  ecx = edx = 0;  // @59_54fb70
  L54fca4:;
  eax = ext_4690b0_cdecl0();  // @61_54fb70
  ecx = edx = 0;  // @62_54fb70
  eax = ext_4690b0_cdecl0();  // @63_54fb70
  ecx = edx = 0;  // @64_54fb70
  eax = ext_560310_cdecl0();  // @65_54fb70
  ecx = edx = 0;  // @66_54fb70
  eax = ext_557860_cdecl0();  // @67_54fb70
  ecx = edx = 0;  // @68_54fb70
  eax = ext_4690b0_cdecl0();  // @69_54fb70
  ecx = edx = 0;  // @70_54fb70
  eax = ext_4690b0_cdecl0();  // @71_54fb70
  ecx = edx = 0;  // @72_54fb70
  eax = ext_4690b0_cdecl0();  // @73_54fb70
  ecx = edx = 0;  // @74_54fb70
  eax = ext_4690b0_cdecl0();  // @75_54fb70
  ecx = edx = 0;  // @76_54fb70
  eax = ext_4690b0_cdecl0();  // @77_54fb70
  ecx = edx = 0;  // @78_54fb70
  eax = ext_4690b0_cdecl0();  // @79_54fb70
  ecx = edx = 0;  // @80_54fb70
  eax = ext_560310_cdecl0();  // @81_54fb70
  ecx = edx = 0;  // @82_54fb70
  ecx = esi;  // @83_54fb70
  eax = ext_4e66a0_thiscall1(ecx);  // @84_54fb70
  ecx = edx = 0;  // @85_54fb70
  SEH_LEAVE();  // @86_54fb70
  return eax;  // @87_54fb70
}
PCREG(54fb70, lifted_54fb70);

extern "C" u32 THISCALL lifted_44a3d0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66612e);  // @h_44a3d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_44a3d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_44a3d0
  eax = ext_45f3c0_thiscall2(ecx, (u32)(esi));  // @2_44a3d0
  ecx = edx = 0;  // @3_44a3d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L44a419;  // @4_44a3d0
  SEH_LEAVE();  // @5_44a3d0
  return eax;  // @6_44a3d0
  L44a419:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @8_44a3d0
  if ((ecx & ecx) == 0) goto L44a42d;  // @9_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_44a3d0
  ecx = edx = 0;  // @12_44a3d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @13_44a3d0
  L44a42d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @15_44a3d0
  if ((ecx & ecx) == 0) goto L44a441;  // @16_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_44a3d0
  ecx = edx = 0;  // @19_44a3d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @20_44a3d0
  L44a441:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_44a3d0
  ecx = (u32)(EBP + 8);  // @23_44a3d0
  ecx = esi;  // @24_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(ecx));  // @25_44a3d0
  ecx = edx = 0;  // @26_44a3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L44a4ab;  // @27_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_44a3d0
  ecx = (u32)(EBP - 20);  // @29_44a3d0
  ecx = esi;  // @30_44a3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @31_44a3d0
  ecx = edx = 0;  // @32_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_44a3d0
  ecx = (u32)(EBP - 16);  // @34_44a3d0
  ecx = esi;  // @35_44a3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @36_44a3d0
  ecx = edx = 0;  // @37_44a3d0
  eax = ext_41e290_cdecl1((u32)(28));  // @38_44a3d0
  ecx = edx = 0;  // @39_44a3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @40_44a3d0
  reg.state = (s32)((u32)(0));  // @41_44a3d0
  if ((eax & eax) == 0) goto L44a497;  // @42_44a3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @43_44a3d0
  ecx = (ecx - 1);  // @44_44a3d0
  ecx = eax;  // @45_44a3d0
  eax = ext_4ccbe0_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }), (u32)(ecx));  // @46_44a3d0
  ecx = edx = 0;  // @47_44a3d0
  ecx = eax;  // @48_44a3d0
  goto L44a499;  // @49_44a3d0
  L44a497:;
  ecx = 0;  // @51_44a3d0
  L44a499:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @53_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_44a3d0
  ecx = esi;  // @55_44a3d0
  reg.state = (s32)((u32)(4294967295));  // @56_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ecx));  // @57_44a3d0
  ecx = edx = 0;  // @58_44a3d0
  L44a4ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_44a3d0
  ecx = (u32)(EBP + 8);  // @61_44a3d0
  ecx = esi;  // @62_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(ecx));  // @63_44a3d0
  ecx = edx = 0;  // @64_44a3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L44a4f7;  // @65_44a3d0
  eax = ext_41e290_cdecl1((u32)(28));  // @66_44a3d0
  ecx = edx = 0;  // @67_44a3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @68_44a3d0
  reg.state = (s32)((u32)(1));  // @69_44a3d0
  if ((eax & eax) == 0) goto L44a4e3;  // @70_44a3d0
  ecx = eax;  // @71_44a3d0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(1));  // @72_44a3d0
  ecx = edx = 0;  // @73_44a3d0
  ecx = eax;  // @74_44a3d0
  goto L44a4e5;  // @75_44a3d0
  L44a4e3:;
  ecx = 0;  // @77_44a3d0
  L44a4e5:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @79_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_44a3d0
  ecx = esi;  // @81_44a3d0
  reg.state = (s32)((u32)(4294967295));  // @82_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ecx));  // @83_44a3d0
  ecx = edx = 0;  // @84_44a3d0
  L44a4f7:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @86_44a3d0
  SEH_LEAVE();  // @87_44a3d0
  return eax;  // @88_44a3d0
}
PCREG(44a3d0, lifted_44a3d0);

extern "C" u32 THISCALL lifted_45d5c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66676f);  // @h_45d5c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @38_45d5c0
  ecx = edx = 0;  // @39_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @40_45d5c0
  edx = (u32)(EBP - 28);  // @41_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @42_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @44_45d5c0
  ecx = edx = 0;  // @45_45d5c0
  edx = eax;  // @46_45d5c0
  if ((edx & edx) == 0) goto L45d700;  // @47_45d5c0
  L45d680:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @49_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @51_45d5c0
  ecx = edx = 0;  // @52_45d5c0
  esi = eax;  // @53_45d5c0
  if ((esi & esi) != 0) goto L45d6a7;  // @54_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @55_45d5c0
  edx = (u32)(EBP - 28);  // @56_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @57_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(edx));  // @59_45d5c0
  ecx = edx = 0;  // @60_45d5c0
  goto L45d6eb;  // @61_45d5c0
  L45d6a7:;
  ecx = ebx;  // @63_45d5c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L45d6bf;  // @64_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @65_45d5c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 272)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @66_45d5c0
  ecx = edx = 0;  // @67_45d5c0
  goto L45d6eb;  // @68_45d5c0
  L45d6bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @70_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @71_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 264)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @72_45d5c0
  ecx = edx = 0;  // @73_45d5c0
  edi = eax;  // @74_45d5c0
  ecx = edi;  // @75_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @76_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(esi));  // @77_45d5c0
  ecx = edx = 0;  // @78_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @79_45d5c0
  ecx = (ecx | ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @80_45d5c0
  ecx = (ecx & (u32)(4294967283));  // @81_45d5c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @82_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @83_45d5c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @84_45d5c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @85_45d5c0
  L45d6eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @87_45d5c0
  edx = (u32)(EBP - 28);  // @88_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @89_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @91_45d5c0
  ecx = edx = 0;  // @92_45d5c0
  edx = eax;  // @93_45d5c0
  if ((edx & edx) != 0) goto L45d680;  // @94_45d5c0
  L45d700:;
  SEH_LEAVE();  // @96_45d5c0
  return eax;  // @97_45d5c0
}
PCREG(45d5c0, lifted_45d5c0);

extern "C" u32 THISCALL lifted_602a60(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  SEH_ENTER(0x66dbac);  // @h_602a60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  eax = ecx;  // @0_602a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_602a60
  ebx = (u32)(eax + 1);  // @2_602a60
  reg.state = (s32)((u32)(0));  // @3_602a60
  eax = (u32)(EBP + 8);  // @4_602a60
  ecx = ebx;  // @5_602a60
  eax = (u32)(EBP - 16);  // @6_602a60
  eax = ext_5fb980_thiscall3(ecx, (u32)(eax), (u32)(eax));  // @7_602a60
  ecx = edx = 0;  // @8_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_602a60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) != eax) goto L602b4c;  // @10_602a60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @11_602a60
  edi = 0;  // @12_602a60
  if ((esi & esi) == 0) goto L602ae4;  // @13_602a60
  eax = ext_41e290_cdecl1((u32)(48));  // @14_602a60
  ecx = edx = 0;  // @15_602a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @16_602a60
  reg.state = (s32)((u32)(1));  // @17_602a60
  if ((eax & eax) == 0) goto L602ade;  // @18_602a60
  ecx = eax;  // @19_602a60
  eax = ext_602290_thiscall5(ecx, (u32)(edi), (u32)(esi), (u32)(edi), (u32)(edi));  // @20_602a60
  ecx = edx = 0;  // @21_602a60
  edi = eax;  // @22_602a60
  goto L602ae0;  // @23_602a60
  L602ade:;
  edi = 0;  // @25_602a60
  L602ae0:;
  reg.state = (s32)((u32)(0));  // @27_602a60
  L602ae4:;
  eax = ext_41e290_cdecl1((u32)(40));  // @29_602a60
  ecx = edx = 0;  // @30_602a60
  esi = eax;  // @31_602a60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @32_602a60
  reg.state = (s32)((u32)(2));  // @33_602a60
  if ((esi & esi) == 0) goto L602b31;  // @34_602a60
  eax = (u32)(EBP + 8);  // @35_602a60
  { u32 v = (u32)((u32)(7051460)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @36_602a60
  ecx = (u32)(esi + 4);  // @37_602a60
  eax = ext_5f10c0_thiscall2(ecx, (u32)(eax));  // @38_602a60
  ecx = edx = 0;  // @39_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @40_602a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @41_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @42_602a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @43_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @44_602a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @45_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @46_602a60
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @47_602a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @48_602a60
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @49_602a60
  goto L602b33;  // @50_602a60
  L602b31:;
  esi = 0;  // @52_602a60
  L602b33:;
  eax = (u32)(EBP + 8);  // @54_602a60
  reg.state = (s32)((u32)(0));  // @55_602a60
  ecx = ebx;  // @56_602a60
  eax = ext_5fb110_thiscall2(ecx, (u32)(eax));  // @57_602a60
  ecx = edx = 0;  // @58_602a60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @59_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @60_602a60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @61_602a60
  goto L602b7f;  // @62_602a60
  L602b4c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @64_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_602a60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051464), (u32)(76));  // @66_602a60
  ecx = edx = 0;  // @67_602a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @68_602a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6932144), (u32)(7051600));  // @69_602a60
  ecx = edx = 0;  // @70_602a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @71_602a60
  if ((eax & eax) == 0) goto L602b7e;  // @72_602a60
  eax = ((u32(STDCALL *)(void))(eax))();  // @73_602a60
  ecx = edx = 0;  // @74_602a60
  goto L602b7f;  // @75_602a60
  L602b7e:;
  __builtin_trap();  // @77_602a60
  L602b7f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @79_602a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @80_602a60
  eax = (eax - ecx);  // @81_602a60
  reg.state = (s32)((u32)(3));  // @82_602a60
  if ((ecx & ecx) == 0) goto L602ba0;  // @83_602a60
  if ((eax & eax) == 0) goto L602ba0;  // @84_602a60
  ecx = (u32)(EBP + 8);  // @85_602a60
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @86_602a60
  ecx = edx = 0;  // @87_602a60
  L602ba0:;
  SEH_LEAVE();  // @89_602a60
  return eax;  // @90_602a60
}
PCREG(602a60, lifted_602a60);

extern "C" u32 THISCALL lifted_54bc20(u32 ecx_in) {
  SEH_ENTER(0x66ad92);  // @h_54bc20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_54bc20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @1_54bc20
  eax = (u32)(edi + 68);  // @2_54bc20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @3_54bc20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 0)))(ecx, (u32)(edx), (u32)(7070096), (u32)(eax));  // @4_54bc20
  ecx = edx = 0;  // @5_54bc20
  if ((eax & eax) == 0) goto L54bc7d;  // @6_54bc20
  edx = (u32)(6961644);  // @7_54bc20
  ecx = eax;  // @8_54bc20
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @9_54bc20
  ecx = edx = 0;  // @10_54bc20
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @11_54bc20
  SEH_LEAVE();  // @12_54bc20
  return eax;  // @13_54bc20
  L54bc7d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @15_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 204), sizeof v); (u32)v; });  // @17_54bc20
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @18_54bc20
  ecx = edx = 0;  // @19_54bc20
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L54bd84;  // @20_54bc20
  eax = ext_41e290_cdecl1((u32)(244));  // @21_54bc20
  ecx = edx = 0;  // @22_54bc20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @23_54bc20
  reg.state = (s32)((u32)(0));  // @24_54bc20
  if ((eax & eax) == 0) goto L54bcb6;  // @25_54bc20
  ecx = eax;  // @26_54bc20
  eax = ext_54e9a0_thiscall1(ecx);  // @27_54bc20
  ecx = edx = 0;  // @28_54bc20
  goto L54bcb8;  // @29_54bc20
  L54bcb6:;
  eax = 0;  // @31_54bc20
  L54bcb8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @33_54bc20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @34_54bc20
  reg.state = (s32)((u32)(4294967295));  // @35_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_54bc20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @37_54bc20
  ecx = edx = 0;  // @38_54bc20
  ecx = eax;  // @39_54bc20
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @40_54bc20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @41_54bc20
  edx = (u32)(EBP - 64);  // @42_54bc20
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @43_54bc20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @44_54bc20
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @45_54bc20
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @46_54bc20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @47_54bc20
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @48_54bc20
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @49_54bc20
  { u32 v = (u32)((u32)(22050)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @50_54bc20
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @51_54bc20
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @52_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @54_54bc20
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(edx), (u32)(1));  // @55_54bc20
  ecx = edx = 0;  // @56_54bc20
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L54bd84;  // @57_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @58_54bc20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @59_54bc20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @61_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_54bc20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 200)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25580), sizeof v); (u32)v; }), (u32)(1));  // @63_54bc20
  ecx = edx = 0;  // @64_54bc20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @65_54bc20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 20)))(ecx, (u32)(eax));  // @66_54bc20
  ecx = edx = 0;  // @67_54bc20
  if ((eax & eax) != 0) goto L54bd84;  // @68_54bc20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @69_54bc20
  if ((ecx & ecx) == 0) goto L54bd60;  // @70_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_54bc20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @72_54bc20
  ecx = edx = 0;  // @73_54bc20
  L54bd60:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @75_54bc20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @76_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_54bc20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @78_54bc20
  ecx = edx = 0;  // @79_54bc20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @80_54bc20
  if ((ecx & ecx) == 0) goto L54bd7d;  // @81_54bc20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_54bc20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @83_54bc20
  ecx = edx = 0;  // @84_54bc20
  L54bd7d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @86_54bc20
  L54bd84:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_54bc20
  ecx = edi;  // @89_54bc20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(0));  // @90_54bc20
  ecx = edx = 0;  // @91_54bc20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @92_54bc20
  SEH_LEAVE();  // @93_54bc20
  return eax;  // @94_54bc20
}
PCREG(54bc20, lifted_54bc20);

extern "C" u32 THISCALL lifted_469980(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666b04);  // @h_469980
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_469980
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_469980
  eax = ext_43e990_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_469980
  ecx = edx = 0;  // @3_469980
  reg.state = (s32)((u32)(0));  // @4_469980
  { u32 v = (u32)((u32)(6843400)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_469980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @6_469980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @7_469980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @8_469980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @9_469980
  eax = ext_41e290_cdecl1((u32)(44));  // @10_469980
  ecx = edx = 0;  // @11_469980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @12_469980
  reg.state = (s32)((u32)(1));  // @13_469980
  if ((eax & eax) == 0) goto L469a02;  // @14_469980
  ecx = eax;  // @15_469980
  eax = ext_4ccad0_thiscall3(ecx, (u32)(8), (u32)(0));  // @16_469980
  ecx = edx = 0;  // @17_469980
  goto L469a04;  // @18_469980
  L469a02:;
  eax = 0;  // @20_469980
  L469a04:;
  reg.state = (s32)((u32)(0));  // @22_469980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @23_469980
  eax = ext_41e290_cdecl1((u32)(44));  // @24_469980
  ecx = edx = 0;  // @25_469980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @26_469980
  reg.state = (s32)((u32)(2));  // @27_469980
  if ((eax & eax) == 0) goto L469a2d;  // @28_469980
  ecx = eax;  // @29_469980
  eax = ext_4ccad0_thiscall3(ecx, (u32)(8), (u32)(0));  // @30_469980
  ecx = edx = 0;  // @31_469980
  goto L469a2f;  // @32_469980
  L469a2d:;
  eax = 0;  // @34_469980
  L469a2f:;
  reg.state = (s32)((u32)(0));  // @36_469980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @37_469980
  eax = ext_41e290_cdecl1((u32)(28));  // @38_469980
  ecx = edx = 0;  // @39_469980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @40_469980
  reg.state = (s32)((u32)(3));  // @41_469980
  if ((eax & eax) == 0) goto L469a58;  // @42_469980
  ecx = eax;  // @43_469980
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(8), (u32)(0));  // @44_469980
  ecx = edx = 0;  // @45_469980
  goto L469a5a;  // @46_469980
  L469a58:;
  eax = 0;  // @48_469980
  L469a5a:;
  reg.state = (s32)((u32)(0));  // @50_469980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @51_469980
  eax = ext_41e290_cdecl1((u32)(28));  // @52_469980
  ecx = edx = 0;  // @53_469980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @54_469980
  reg.state = (s32)((u32)(4));  // @55_469980
  if ((eax & eax) == 0) goto L469a83;  // @56_469980
  ecx = eax;  // @57_469980
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(8), (u32)(0));  // @58_469980
  ecx = edx = 0;  // @59_469980
  goto L469a85;  // @60_469980
  L469a83:;
  eax = 0;  // @62_469980
  L469a85:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @64_469980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_469980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @66_469980
  reg.state = (s32)((u32)(0));  // @67_469980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_469980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6850540), (u32)(0), (u32)(6850500), (u32)(697));  // @69_469980
  ecx = edx = 0;  // @70_469980
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @71_469980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @72_469980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @73_469980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_469980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6850700), (u32)(0), (u32)(6850500), (u32)(698));  // @75_469980
  ecx = edx = 0;  // @76_469980
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 126), &v, sizeof v); }  // @77_469980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_469980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_469980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_469980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6850724), (u32)(0), (u32)(6850500), (u32)(699));  // @81_469980
  ecx = edx = 0;  // @82_469980
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @83_469980
  eax = esi;  // @84_469980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 130), &v, sizeof v); }  // @85_469980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 134), &v, sizeof v); }  // @86_469980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 138), &v, sizeof v); }  // @87_469980
  SEH_LEAVE();  // @88_469980
  return eax;  // @89_469980
}
PCREG(469980, lifted_469980);

extern "C" u32 THISCALL lifted_4c6410(u32 ecx_in) {
  SEH_ENTER(0x668f90);  // @h_4c6410
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c6410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c6410
  eax = ext_469870_thiscall1(ecx);  // @2_4c6410
  ecx = edx = 0;  // @3_4c6410
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c6410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c6410
  ebx = (u32)(esi + 88);  // @6_4c6410
  reg.state = (s32)((u32)(0));  // @7_4c6410
  edi = (u32)(esi + 93);  // @8_4c6410
  { u32 v = (u32)((u32)(6900120)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_4c6410
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @10_4c6410
  { u32 v = (u32)((u32)(1148846080)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @11_4c6410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @12_4c6410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @13_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @14_4c6410
  ecx = edx = 0;  // @15_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @16_4c6410
  reg.state = (s32)((u32)(1));  // @17_4c6410
  if ((eax & eax) == 0) goto L4c649f;  // @18_4c6410
  ecx = eax;  // @19_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900288), (u32)(6900252), (u32)(edi));  // @20_4c6410
  ecx = edx = 0;  // @21_4c6410
  edx = eax;  // @22_4c6410
  goto L4c64a1;  // @23_4c6410
  L4c649f:;
  edx = 0;  // @25_4c6410
  L4c64a1:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @27_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4c6410
  reg.state = (s32)((u32)(0));  // @29_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @31_4c6410
  ecx = edx = 0;  // @32_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @33_4c6410
  ecx = edx = 0;  // @34_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @35_4c6410
  reg.state = (s32)((u32)(2));  // @36_4c6410
  if ((eax & eax) == 0) goto L4c64e5;  // @37_4c6410
  ecx = eax;  // @38_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900344), (u32)(6900312), (u32)(edi));  // @39_4c6410
  ecx = edx = 0;  // @40_4c6410
  edx = eax;  // @41_4c6410
  goto L4c64e7;  // @42_4c6410
  L4c64e5:;
  edx = 0;  // @44_4c6410
  L4c64e7:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @46_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_4c6410
  reg.state = (s32)((u32)(0));  // @48_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @50_4c6410
  ecx = edx = 0;  // @51_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @52_4c6410
  ecx = edx = 0;  // @53_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @54_4c6410
  reg.state = (s32)((u32)(3));  // @55_4c6410
  if ((eax & eax) == 0) goto L4c652b;  // @56_4c6410
  ecx = eax;  // @57_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900392), (u32)(6900368), (u32)(ebx));  // @58_4c6410
  ecx = edx = 0;  // @59_4c6410
  edx = eax;  // @60_4c6410
  goto L4c652d;  // @61_4c6410
  L4c652b:;
  edx = 0;  // @63_4c6410
  L4c652d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @65_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_4c6410
  reg.state = (s32)((u32)(0));  // @67_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @69_4c6410
  ecx = edx = 0;  // @70_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @71_4c6410
  ecx = edx = 0;  // @72_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @73_4c6410
  reg.state = (s32)((u32)(4));  // @74_4c6410
  if ((eax & eax) == 0) goto L4c6574;  // @75_4c6410
  ecx = (u32)(esi + 89);  // @76_4c6410
  ecx = eax;  // @77_4c6410
  eax = ext_4d8330_thiscall4(ecx, (u32)(6900424), (u32)(6900408), (u32)(ecx));  // @78_4c6410
  ecx = edx = 0;  // @79_4c6410
  edx = eax;  // @80_4c6410
  goto L4c6576;  // @81_4c6410
  L4c6574:;
  edx = 0;  // @83_4c6410
  L4c6576:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @85_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @86_4c6410
  reg.state = (s32)((u32)(0));  // @87_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @89_4c6410
  ecx = edx = 0;  // @90_4c6410
  eax = esi;  // @91_4c6410
  SEH_LEAVE();  // @92_4c6410
  return eax;  // @93_4c6410
}
PCREG(4c6410, lifted_4c6410);

