// batch200078.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 THISCALL ext_41cfd0_thiscall1(u32) __asm__("ext_41cfd0");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_43e0f0_thiscall1(u32) __asm__("ext_43e0f0");
extern "C" u32 THISCALL ext_448a30_thiscall2(u32, u32) __asm__("ext_448a30");
extern "C" u32 THISCALL ext_456ab0_thiscall1(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4c4740_thiscall4(u32, u32, u32, u32) __asm__("ext_4c4740");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e6680_thiscall1(u32) __asm__("ext_4e6680");
extern "C" u32 THISCALL ext_4ff7b0_thiscall1(u32) __asm__("ext_4ff7b0");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_53b600_thiscall1(u32) __asm__("ext_53b600");
extern "C" u32 THISCALL ext_53c590_thiscall3(u32, u32, u32) __asm__("ext_53c590");
extern "C" u32 THISCALL ext_54e9a0_thiscall1(u32) __asm__("ext_54e9a0");
extern "C" u32 THISCALL ext_54fd60_thiscall1(u32) __asm__("ext_54fd60");
extern "C" u32 THISCALL ext_557930_thiscall1(u32) __asm__("ext_557930");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5c9530_thiscall1(u32) __asm__("ext_5c9530");
extern "C" u32 THISCALL ext_5f12d0_thiscall1(u32) __asm__("ext_5f12d0");
extern "C" u32 THISCALL ext_5f9700_thiscall3(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

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

extern "C" u32 THISCALL lifted_4ff7b0(u32 ecx_in) {
  SEH_ENTER(0x66ae28);  // @h_4ff7b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4ff7b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4ff7b0
  eax = ext_4e6680_thiscall1(ecx);  // @2_4ff7b0
  ecx = edx = 0;  // @3_4ff7b0
  reg.state = (s32)((u32)(0));  // @4_4ff7b0
  { u32 v = (u32)((u32)(6932168)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @6_4ff7b0
  ecx = edx = 0;  // @7_4ff7b0
  if ((eax & eax) == 0) goto L4ff801;  // @8_4ff7b0
  { u32 v = (u32)((u32)(6932384)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_4ff7b0
  goto L4ff803;  // @10_4ff7b0
  L4ff801:;
  eax = 0;  // @12_4ff7b0
  L4ff803:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @14_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @15_4ff7b0
  ecx = edx = 0;  // @16_4ff7b0
  if ((eax & eax) == 0) goto L4ff81c;  // @17_4ff7b0
  { u32 v = (u32)((u32)(6932240)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @18_4ff7b0
  goto L4ff81e;  // @19_4ff7b0
  L4ff81c:;
  eax = 0;  // @21_4ff7b0
  L4ff81e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @23_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @24_4ff7b0
  ecx = edx = 0;  // @25_4ff7b0
  if ((eax & eax) == 0) goto L4ff837;  // @26_4ff7b0
  { u32 v = (u32)((u32)(6932248)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @27_4ff7b0
  goto L4ff839;  // @28_4ff7b0
  L4ff837:;
  eax = 0;  // @30_4ff7b0
  L4ff839:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @32_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @33_4ff7b0
  ecx = edx = 0;  // @34_4ff7b0
  if ((eax & eax) == 0) goto L4ff852;  // @35_4ff7b0
  { u32 v = (u32)((u32)(6932256)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @36_4ff7b0
  goto L4ff854;  // @37_4ff7b0
  L4ff852:;
  eax = 0;  // @39_4ff7b0
  L4ff854:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @41_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @42_4ff7b0
  ecx = edx = 0;  // @43_4ff7b0
  if ((eax & eax) == 0) goto L4ff86d;  // @44_4ff7b0
  { u32 v = (u32)((u32)(6932264)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @45_4ff7b0
  goto L4ff86f;  // @46_4ff7b0
  L4ff86d:;
  eax = 0;  // @48_4ff7b0
  L4ff86f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @50_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @51_4ff7b0
  ecx = edx = 0;  // @52_4ff7b0
  if ((eax & eax) == 0) goto L4ff888;  // @53_4ff7b0
  { u32 v = (u32)((u32)(6932272)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @54_4ff7b0
  goto L4ff88a;  // @55_4ff7b0
  L4ff888:;
  eax = 0;  // @57_4ff7b0
  L4ff88a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @59_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @60_4ff7b0
  ecx = edx = 0;  // @61_4ff7b0
  if ((eax & eax) == 0) goto L4ff8a3;  // @62_4ff7b0
  { u32 v = (u32)((u32)(6932280)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @63_4ff7b0
  goto L4ff8a5;  // @64_4ff7b0
  L4ff8a3:;
  eax = 0;  // @66_4ff7b0
  L4ff8a5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @68_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @69_4ff7b0
  ecx = edx = 0;  // @70_4ff7b0
  if ((eax & eax) == 0) goto L4ff8be;  // @71_4ff7b0
  { u32 v = (u32)((u32)(6932288)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @72_4ff7b0
  goto L4ff8c0;  // @73_4ff7b0
  L4ff8be:;
  eax = 0;  // @75_4ff7b0
  L4ff8c0:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @77_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @78_4ff7b0
  ecx = edx = 0;  // @79_4ff7b0
  if ((eax & eax) == 0) goto L4ff8d9;  // @80_4ff7b0
  { u32 v = (u32)((u32)(6932304)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @81_4ff7b0
  goto L4ff8db;  // @82_4ff7b0
  L4ff8d9:;
  eax = 0;  // @84_4ff7b0
  L4ff8db:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @86_4ff7b0
  eax = ext_41e290_cdecl1((u32)(4));  // @87_4ff7b0
  ecx = edx = 0;  // @88_4ff7b0
  if ((eax & eax) == 0) goto L4ff907;  // @89_4ff7b0
  { u32 v = (u32)((u32)(6932296)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @90_4ff7b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @91_4ff7b0
  eax = esi;  // @92_4ff7b0
  SEH_LEAVE();  // @93_4ff7b0
  return eax;  // @94_4ff7b0
  L4ff907:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @96_4ff7b0
  eax = esi;  // @97_4ff7b0
  SEH_LEAVE();  // @98_4ff7b0
  return eax;  // @99_4ff7b0
}
PCREG(4ff7b0, lifted_4ff7b0);

extern "C" u32 THISCALL lifted_5ca720(u32 ecx_in) {
  SEH_ENTER(0x66c7fa);  // @h_5ca720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5ca720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5ca720
  eax = ext_5c9530_thiscall1(ecx);  // @2_5ca720
  ecx = edx = 0;  // @3_5ca720
  { u32 v = (u32)((u32)(7031784)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5ca720
  eax = (u32)(esi + 1206);  // @5_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @6_5ca720
  ecx = (u32)(EBP - 20);  // @7_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1252), &v, sizeof v); }  // @8_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1256), &v, sizeof v); }  // @9_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1260), &v, sizeof v); }  // @10_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1264), &v, sizeof v); }  // @11_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1268), &v, sizeof v); }  // @12_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1269), &v, sizeof v); }  // @13_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1273), &v, sizeof v); }  // @14_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1277), &v, sizeof v); }  // @15_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1281), &v, sizeof v); }  // @16_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1285), &v, sizeof v); }  // @17_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1289), &v, sizeof v); }  // @18_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1293), &v, sizeof v); }  // @19_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1297), &v, sizeof v); }  // @20_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1301), &v, sizeof v); }  // @21_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1305), &v, sizeof v); }  // @22_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1309), &v, sizeof v); }  // @23_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1313), &v, sizeof v); }  // @24_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1314), &v, sizeof v); }  // @25_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1318), &v, sizeof v); }  // @26_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1322), &v, sizeof v); }  // @27_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1326), &v, sizeof v); }  // @28_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1330), &v, sizeof v); }  // @29_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1334), &v, sizeof v); }  // @30_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1338), &v, sizeof v); }  // @31_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1342), &v, sizeof v); }  // @32_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1346), &v, sizeof v); }  // @33_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1350), &v, sizeof v); }  // @34_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1354), &v, sizeof v); }  // @35_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1358), &v, sizeof v); }  // @36_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1359), &v, sizeof v); }  // @37_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1363), &v, sizeof v); }  // @38_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1367), &v, sizeof v); }  // @39_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1371), &v, sizeof v); }  // @40_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1375), &v, sizeof v); }  // @41_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1379), &v, sizeof v); }  // @42_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1383), &v, sizeof v); }  // @43_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1387), &v, sizeof v); }  // @44_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1391), &v, sizeof v); }  // @45_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1395), &v, sizeof v); }  // @46_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1399), &v, sizeof v); }  // @47_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1403), &v, sizeof v); }  // @48_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1404), &v, sizeof v); }  // @49_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1408), &v, sizeof v); }  // @50_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1412), &v, sizeof v); }  // @51_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1416), &v, sizeof v); }  // @52_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1420), &v, sizeof v); }  // @53_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1424), &v, sizeof v); }  // @54_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1428), &v, sizeof v); }  // @55_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1452), &v, sizeof v); }  // @56_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1137), &v, sizeof v); }  // @57_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1226), &v, sizeof v); }  // @58_5ca720
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1432), &v, sizeof v); }  // @59_5ca720
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 762), &v, sizeof v); }  // @60_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 778), &v, sizeof v); }  // @61_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @62_5ca720
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @63_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1214), &v, sizeof v); }  // @64_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1210), &v, sizeof v); }  // @65_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1218), &v, sizeof v); }  // @66_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1222), &v, sizeof v); }  // @67_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1105), &v, sizeof v); }  // @68_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1109), &v, sizeof v); }  // @69_5ca720
  { u32 v = (u32)((u32)(2147483648)); __builtin_memcpy((void *)(u32)(esi + 1113), &v, sizeof v); }  // @70_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1117), &v, sizeof v); }  // @71_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1121), &v, sizeof v); }  // @72_5ca720
  { u32 v = (u32)((u32)(2147483648)); __builtin_memcpy((void *)(u32)(esi + 1125), &v, sizeof v); }  // @73_5ca720
  reg.state = (s32)((u32)(0));  // @74_5ca720
  { u32 v = (u32)((u32)(1048576000)); __builtin_memcpy((void *)(u32)(esi + 1202), &v, sizeof v); }  // @75_5ca720
  if (eax == ecx) goto L5ca9fc;  // @76_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @77_5ca720
  L5ca9fc:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1240), &v, sizeof v); }  // @79_5ca720
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(esi + 1157), &v, sizeof v); }  // @80_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1145), &v, sizeof v); }  // @81_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1149), &v, sizeof v); }  // @82_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1161), &v, sizeof v); }  // @83_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1227), &v, sizeof v); }  // @84_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1231), &v, sizeof v); }  // @85_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1235), &v, sizeof v); }  // @86_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1244), &v, sizeof v); }  // @87_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1248), &v, sizeof v); }  // @88_5ca720
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(esi + 1198), &v, sizeof v); }  // @89_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 216), &v, sizeof v); }  // @90_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 217), &v, sizeof v); }  // @91_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 346), &v, sizeof v); }  // @92_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 347), &v, sizeof v); }  // @93_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 476), &v, sizeof v); }  // @94_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 477), &v, sizeof v); }  // @95_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 606), &v, sizeof v); }  // @96_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 607), &v, sizeof v); }  // @97_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 736), &v, sizeof v); }  // @98_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 737), &v, sizeof v); }  // @99_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_5ca720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @101_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_5ca720
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7032036), (u32)(0), (u32)(7031988), (u32)(165));  // @103_5ca720
  ecx = edx = 0;  // @104_5ca720
  edi = (u32)(esi + 1968);  // @105_5ca720
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 1434), &v, sizeof v); }  // @106_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @107_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1969), &v, sizeof v); }  // @108_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1973), &v, sizeof v); }  // @109_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1977), &v, sizeof v); }  // @110_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1239), &v, sizeof v); }  // @111_5ca720
  { u32 v = (u32)((u32)(1068823723)); __builtin_memcpy((void *)(u32)(esi + 1133), &v, sizeof v); }  // @112_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1293), &v, sizeof v); }  // @113_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1338), &v, sizeof v); }  // @114_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1383), &v, sizeof v); }  // @115_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1428), &v, sizeof v); }  // @116_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1141), &v, sizeof v); }  // @117_5ca720
  eax = ext_41e290_cdecl1((u32)(264));  // @118_5ca720
  ecx = edx = 0;  // @119_5ca720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @120_5ca720
  reg.state = (s32)((u32)(1));  // @121_5ca720
  if ((eax & eax) == 0) goto L5cab7f;  // @122_5ca720
  ecx = eax;  // @123_5ca720
  eax = ext_4d83b0_thiscall4(ecx, (u32)(7032084), (u32)(7032052), (u32)(edi));  // @124_5ca720
  ecx = edx = 0;  // @125_5ca720
  edx = eax;  // @126_5ca720
  goto L5cab81;  // @127_5ca720
  L5cab7f:;
  edx = 0;  // @129_5ca720
  L5cab81:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 1448), &v, sizeof v); }  // @131_5ca720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @132_5ca720
  reg.state = (s32)((u32)(0));  // @133_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_5ca720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @135_5ca720
  ecx = edx = 0;  // @136_5ca720
  eax = esi;  // @137_5ca720
  SEH_LEAVE();  // @138_5ca720
  return eax;  // @139_5ca720
}
PCREG(5ca720, lifted_5ca720);

extern "C" u32 THISCALL lifted_452bc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666326);  // @h_452bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_452bc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @2_452bc0
  eax = ext_448a30_thiscall2(ecx, (u32)(esi));  // @3_452bc0
  ecx = edx = 0;  // @4_452bc0
  ecx = esi;  // @5_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @6_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @7_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @8_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @9_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @10_452bc0
  ecx = edx = 0;  // @11_452bc0
  if ((eax & 0xff) != (u32)(2)) goto L452d47;  // @12_452bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_452bc0
  ecx = ebx;  // @14_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @15_452bc0
  ecx = edx = 0;  // @16_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @17_452bc0
  esi = eax;  // @18_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(63));  // @20_452bc0
  ecx = edx = 0;  // @21_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_452bc0
  edi = eax;  // @23_452bc0
  eax = (u32)(EBP - 156);  // @24_452bc0
  ecx = esi;  // @25_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @26_452bc0
  ecx = edx = 0;  // @27_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_452bc0
  ecx = eax;  // @29_452bc0
  reg.state = (s32)((u32)(0));  // @30_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @31_452bc0
  ecx = edx = 0;  // @32_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 48)))((u32)(edi), (u32)(6813044), (u32)(eax));  // @33_452bc0
  ecx = edx = 0;  // @34_452bc0
  reg.state = (s32)((u32)(4294967295));  // @35_452bc0
  ecx = (u32)(EBP - 156);  // @36_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @37_452bc0
  ecx = edx = 0;  // @38_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @39_452bc0
  ecx = esi;  // @40_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @41_452bc0
  ecx = edx = 0;  // @42_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452cbb;  // @43_452bc0
  eax = (u32)(EBP - 288);  // @44_452bc0
  ecx = esi;  // @45_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @46_452bc0
  ecx = edx = 0;  // @47_452bc0
  goto L452d47;  // @48_452bc0
  L452cbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_452bc0
  ecx = ebx;  // @51_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @52_452bc0
  ecx = edx = 0;  // @53_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @54_452bc0
  esi = eax;  // @55_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(68));  // @57_452bc0
  ecx = edx = 0;  // @58_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_452bc0
  edi = eax;  // @60_452bc0
  eax = (u32)(EBP - 284);  // @61_452bc0
  ecx = esi;  // @62_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @63_452bc0
  ecx = edx = 0;  // @64_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_452bc0
  ecx = eax;  // @66_452bc0
  reg.state = (s32)((u32)(1));  // @67_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @68_452bc0
  ecx = edx = 0;  // @69_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6822612), (u32)(eax));  // @70_452bc0
  ecx = edx = 0;  // @71_452bc0
  reg.state = (s32)((u32)(4294967295));  // @72_452bc0
  ecx = (u32)(EBP - 284);  // @73_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @74_452bc0
  ecx = edx = 0;  // @75_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @76_452bc0
  eax = (u32)(EBP - 28);  // @77_452bc0
  ecx = esi;  // @78_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @79_452bc0
  ecx = edx = 0;  // @80_452bc0
  eax = (u32)(EBP - 24);  // @81_452bc0
  ecx = esi;  // @82_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @83_452bc0
  ecx = edx = 0;  // @84_452bc0
  eax = (u32)(EBP - 20);  // @85_452bc0
  ecx = esi;  // @86_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @87_452bc0
  ecx = edx = 0;  // @88_452bc0
  L452d47:;
  eax = (u32)(EBP - 292);  // @90_452bc0
  ecx = esi;  // @91_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @92_452bc0
  ecx = edx = 0;  // @93_452bc0
  eax = (u32)(EBP - 296);  // @94_452bc0
  ecx = esi;  // @95_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @96_452bc0
  ecx = edx = 0;  // @97_452bc0
  ecx = esi;  // @98_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @99_452bc0
  ecx = edx = 0;  // @100_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d82;  // @101_452bc0
  eax = (u32)(EBP - 300);  // @102_452bc0
  ecx = esi;  // @103_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @104_452bc0
  ecx = edx = 0;  // @105_452bc0
  L452d82:;
  ecx = esi;  // @107_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @108_452bc0
  ecx = edx = 0;  // @109_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d9d;  // @110_452bc0
  eax = (u32)(EBP - 304);  // @111_452bc0
  ecx = esi;  // @112_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @113_452bc0
  ecx = edx = 0;  // @114_452bc0
  L452d9d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) & (u32)(4294955007))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @116_452bc0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; }) == (u32)(0)) goto L452db4;  // @117_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(4096))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @118_452bc0
  L452db4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L452dc4;  // @120_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(8192))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @121_452bc0
  L452dc4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; }) == (u32)(0)) goto L452dd4;  // @123_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(16384))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @124_452bc0
  L452dd4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; }) == (u32)(0)) goto L452de4;  // @126_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(32768))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @127_452bc0
  L452de4:;
  ecx = esi;  // @129_452bc0
  eax = ext_4e1b30_thiscall1(ecx);  // @130_452bc0
  ecx = edx = 0;  // @131_452bc0
  SEH_LEAVE();  // @132_452bc0
  ext_633654(G(u32, 0x6f5630));  // @133_452bc0
  return eax;  // @134_452bc0
}
PCREG(452bc0, lifted_452bc0);

extern "C" u32 THISCALL lifted_4627d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66693b);  // @h_4627d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 48)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(eax));  // @55_4627d0
  ecx = edx = 0;  // @56_4627d0
  ecx = eax;  // @57_4627d0
  if ((ecx & ecx) == 0) goto L462903;  // @58_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 848), sizeof v); (u32)v; });  // @60_4627d0
  ecx = esi;  // @61_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; }), (u32)(edi));  // @62_4627d0
  ecx = edx = 0;  // @63_4627d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462903;  // @64_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @65_4627d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 68), &v, sizeof v); }  // @66_4627d0
  L462903:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @68_4627d0
  L462909:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @70_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) != 0) goto L4629f7;  // @71_4627d0
  ecx = (u32)(EBP - 16596);  // @72_4627d0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @73_4627d0
  eax = ext_4d2280_thiscall1(ecx);  // @74_4627d0
  ecx = edx = 0;  // @75_4627d0
  edi = (u32)(ebx + 76);  // @76_4627d0
  reg.state = (s32)((u32)(0));  // @77_4627d0
  ecx = (u32)(EBP - 16596);  // @78_4627d0
  eax = ext_4d39a0_stdcall2((u32)(6838552), (u32)(edi));  // @79_4627d0
  ecx = edx = 0;  // @80_4627d0
  ecx = (u32)(EBP - 16596);  // @81_4627d0
  eax = ext_4d3ab0_stdcall2((u32)(6838564), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @82_4627d0
  ecx = edx = 0;  // @83_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @84_4627d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) == 0) goto L462979;  // @85_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_4627d0
  eax = (u32)(EBP - 16596);  // @87_4627d0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 296), sizeof v); (u32)v; });  // @88_4627d0
  ecx = esi;  // @89_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(esi), (u32)(eax), (u32)(eax));  // @90_4627d0
  ecx = edx = 0;  // @91_4627d0
  L462979:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_4627d0
  ecx = esi;  // @94_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 836)))(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16612), sizeof v); (u32)v; }));  // @95_4627d0
  ecx = edx = 0;  // @96_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @97_4627d0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @98_4627d0
  if ((ecx & ecx) == 0) goto L4629ec;  // @99_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_4627d0
  edx = (u32)(EBP - 16624);  // @101_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @102_4627d0
  ecx = edx = 0;  // @103_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @104_4627d0
  edx = (u32)(EBP - 16624);  // @105_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @107_4627d0
  ecx = edx = 0;  // @108_4627d0
  edx = eax;  // @109_4627d0
  if ((edx & edx) == 0) goto L4629ec;  // @110_4627d0
  L4629b4:;
  ecx = (u32)(edx + 4);  // @112_4627d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L4629d7;  // @113_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; }) != (u32)(-2)) goto L4629d7;  // @114_4627d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 68), &v, sizeof v); }  // @115_4627d0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @116_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_4627d0
  ecx = esi;  // @118_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 844)))(ecx, (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @119_4627d0
  ecx = edx = 0;  // @120_4627d0
  L4629d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @122_4627d0
  edx = (u32)(EBP - 16624);  // @123_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @125_4627d0
  ecx = edx = 0;  // @126_4627d0
  edx = eax;  // @127_4627d0
  if ((edx & edx) != 0) goto L4629b4;  // @128_4627d0
  L4629ec:;
  ecx = (u32)(EBP - 16596);  // @130_4627d0
  eax = ext_4d2330_thiscall1(ecx);  // @131_4627d0
  ecx = edx = 0;  // @132_4627d0
  L4629f7:;
  SEH_LEAVE();  // @134_4627d0
  ext_633654(G(u32, 0x6f5630));  // @135_4627d0
  return eax;  // @136_4627d0
}
PCREG(4627d0, lifted_4627d0);

extern "C" u32 THISCALL lifted_4af780(u32 ecx_in) {
  SEH_ENTER(0x668936);  // @h_4af780
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_4af780
  ecx = eax;  // @11_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(ecx));  // @12_4af780
  ecx = edx = 0;  // @13_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @14_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @15_4af780
  L4af7f8:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) != (u32)(0)) goto L4af83a;  // @17_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @21_4af780
  ecx = edx = 0;  // @22_4af780
  ecx = (u32)(EBP - 276);  // @23_4af780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @24_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @25_4af780
  ecx = eax;  // @26_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(ecx));  // @27_4af780
  ecx = edx = 0;  // @28_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @29_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @30_4af780
  L4af83a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }) != (u32)(0)) goto L4af8ac;  // @32_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @35_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @38_4af780
  ecx = edx = 0;  // @39_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @41_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, (u32)(eax));  // @42_4af780
  ecx = edx = 0;  // @43_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @44_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; }) == (u32)(0)) goto L4af8ac;  // @45_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @46_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(50));  // @48_4af780
  ecx = edx = 0;  // @49_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @50_4af780
  edx = (u32)(6801640);  // @51_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @52_4af780
  if ((ecx & ecx) != 0) edx = ecx;  // @53_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6885096), (u32)(edx));  // @55_4af780
  ecx = edx = 0;  // @56_4af780
  L4af8ac:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; }) == (u32)(0)) goto L4af8bf;  // @58_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @59_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @61_4af780
  ecx = edx = 0;  // @62_4af780
  L4af8bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @64_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @65_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @67_4af780
  ecx = edx = 0;  // @68_4af780
  if ((eax & eax) != 0) goto L4af93e;  // @69_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; }) != (eax & 0xff)) goto L4af944;  // @70_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @71_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(58));  // @73_4af780
  ecx = edx = 0;  // @74_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @75_4af780
  edi = eax;  // @76_4af780
  eax = (u32)(EBP - 144);  // @77_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @79_4af780
  ecx = edx = 0;  // @80_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @81_4af780
  ecx = eax;  // @82_4af780
  reg.state = (s32)((u32)(0));  // @83_4af780
  eax = ext_4cc1d0_thiscall1(ecx);  // @84_4af780
  ecx = edx = 0;  // @85_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6885156), (u32)(eax));  // @86_4af780
  ecx = edx = 0;  // @87_4af780
  reg.state = (s32)((u32)(4294967295));  // @88_4af780
  ecx = (u32)(EBP - 144);  // @89_4af780
  eax = ext_4cbec0_thiscall1(ecx);  // @90_4af780
  ecx = edx = 0;  // @91_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @92_4af780
  ecx = ebx;  // @93_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @94_4af780
  ecx = edx = 0;  // @95_4af780
  goto L4af9c8;  // @96_4af780
  L4af93e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; }) == (u32)(0)) goto L4af9bb;  // @98_4af780
  L4af944:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @101_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; }));  // @103_4af780
  ecx = edx = 0;  // @104_4af780
  if ((eax & eax) != 0) goto L4af9bb;  // @105_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @106_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(65));  // @108_4af780
  ecx = edx = 0;  // @109_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @110_4af780
  edi = eax;  // @111_4af780
  eax = (u32)(EBP - 272);  // @112_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @114_4af780
  ecx = edx = 0;  // @115_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @116_4af780
  ecx = eax;  // @117_4af780
  reg.state = (s32)((u32)(1));  // @118_4af780
  eax = ext_4cc1d0_thiscall1(ecx);  // @119_4af780
  ecx = edx = 0;  // @120_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6885216), (u32)(eax));  // @121_4af780
  ecx = edx = 0;  // @122_4af780
  reg.state = (s32)((u32)(4294967295));  // @123_4af780
  ecx = (u32)(EBP - 272);  // @124_4af780
  eax = ext_4cbec0_thiscall1(ecx);  // @125_4af780
  ecx = edx = 0;  // @126_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @127_4af780
  ecx = ebx;  // @128_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @129_4af780
  ecx = edx = 0;  // @130_4af780
  goto L4af9c8;  // @131_4af780
  L4af9bb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @133_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(1));  // @135_4af780
  ecx = edx = 0;  // @136_4af780
  L4af9c8:;
  SEH_LEAVE();  // @138_4af780
  ext_633654(G(u32, 0x6f5630));  // @139_4af780
  return eax;  // @140_4af780
}
PCREG(4af780, lifted_4af780);

extern "C" u32 THISCALL lifted_54f890(u32 ecx_in) {
  SEH_ENTER(0x66ae28);  // @h_54f890
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_54f890
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_54f890
  eax = ext_4e6680_thiscall1(ecx);  // @2_54f890
  ecx = edx = 0;  // @3_54f890
  reg.state = (s32)((u32)(0));  // @4_54f890
  { u32 v = (u32)((u32)(6965892)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_54f890
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @6_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @7_54f890
  ecx = edx = 0;  // @8_54f890
  if ((eax & eax) == 0) goto L54f8e5;  // @9_54f890
  { u32 v = (u32)((u32)(6966180)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @10_54f890
  goto L54f8e7;  // @11_54f890
  L54f8e5:;
  eax = 0;  // @13_54f890
  L54f8e7:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @15_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @16_54f890
  ecx = edx = 0;  // @17_54f890
  if ((eax & eax) == 0) goto L54f900;  // @18_54f890
  { u32 v = (u32)((u32)(6965956)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @19_54f890
  goto L54f902;  // @20_54f890
  L54f900:;
  eax = 0;  // @22_54f890
  L54f902:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @24_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @25_54f890
  ecx = edx = 0;  // @26_54f890
  if ((eax & eax) == 0) goto L54f91b;  // @27_54f890
  { u32 v = (u32)((u32)(6965972)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @28_54f890
  goto L54f91d;  // @29_54f890
  L54f91b:;
  eax = 0;  // @31_54f890
  L54f91d:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @33_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @34_54f890
  ecx = edx = 0;  // @35_54f890
  if ((eax & eax) == 0) goto L54f936;  // @36_54f890
  { u32 v = (u32)((u32)(6965964)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_54f890
  goto L54f938;  // @38_54f890
  L54f936:;
  eax = 0;  // @40_54f890
  L54f938:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @42_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @43_54f890
  ecx = edx = 0;  // @44_54f890
  if ((eax & eax) == 0) goto L54f951;  // @45_54f890
  { u32 v = (u32)((u32)(6932296)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_54f890
  goto L54f953;  // @47_54f890
  L54f951:;
  eax = 0;  // @49_54f890
  L54f953:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @51_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @52_54f890
  ecx = edx = 0;  // @53_54f890
  if ((eax & eax) == 0) goto L54f96c;  // @54_54f890
  { u32 v = (u32)((u32)(6965980)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @55_54f890
  goto L54f96e;  // @56_54f890
  L54f96c:;
  eax = 0;  // @58_54f890
  L54f96e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 37), &v, sizeof v); }  // @60_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @61_54f890
  ecx = edx = 0;  // @62_54f890
  if ((eax & eax) == 0) goto L54f987;  // @63_54f890
  { u32 v = (u32)((u32)(6965988)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @64_54f890
  goto L54f989;  // @65_54f890
  L54f987:;
  eax = 0;  // @67_54f890
  L54f989:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @69_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @70_54f890
  ecx = edx = 0;  // @71_54f890
  if ((eax & eax) == 0) goto L54f9a2;  // @72_54f890
  { u32 v = (u32)((u32)(6965996)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @73_54f890
  goto L54f9a4;  // @74_54f890
  L54f9a2:;
  eax = 0;  // @76_54f890
  L54f9a4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @78_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @79_54f890
  ecx = edx = 0;  // @80_54f890
  if ((eax & eax) == 0) goto L54f9bd;  // @81_54f890
  { u32 v = (u32)((u32)(6966028)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @82_54f890
  goto L54f9bf;  // @83_54f890
  L54f9bd:;
  eax = 0;  // @85_54f890
  L54f9bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 61), &v, sizeof v); }  // @87_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @88_54f890
  ecx = edx = 0;  // @89_54f890
  if ((eax & eax) == 0) goto L54f9d8;  // @90_54f890
  { u32 v = (u32)((u32)(6966004)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @91_54f890
  goto L54f9da;  // @92_54f890
  L54f9d8:;
  eax = 0;  // @94_54f890
  L54f9da:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @96_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @97_54f890
  ecx = edx = 0;  // @98_54f890
  if ((eax & eax) == 0) goto L54f9f3;  // @99_54f890
  { u32 v = (u32)((u32)(6966012)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @100_54f890
  goto L54f9f5;  // @101_54f890
  L54f9f3:;
  eax = 0;  // @103_54f890
  L54f9f5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @105_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @106_54f890
  ecx = edx = 0;  // @107_54f890
  if ((eax & eax) == 0) goto L54fa0e;  // @108_54f890
  { u32 v = (u32)((u32)(6966020)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @109_54f890
  goto L54fa10;  // @110_54f890
  L54fa0e:;
  eax = 0;  // @112_54f890
  L54fa10:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 57), &v, sizeof v); }  // @114_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @115_54f890
  ecx = edx = 0;  // @116_54f890
  if ((eax & eax) == 0) goto L54fa29;  // @117_54f890
  { u32 v = (u32)((u32)(6966036)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @118_54f890
  goto L54fa2b;  // @119_54f890
  L54fa29:;
  eax = 0;  // @121_54f890
  L54fa2b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65), &v, sizeof v); }  // @123_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @124_54f890
  ecx = edx = 0;  // @125_54f890
  if ((eax & eax) == 0) goto L54fa44;  // @126_54f890
  { u32 v = (u32)((u32)(6966044)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @127_54f890
  goto L54fa46;  // @128_54f890
  L54fa44:;
  eax = 0;  // @130_54f890
  L54fa46:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @132_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @133_54f890
  ecx = edx = 0;  // @134_54f890
  if ((eax & eax) == 0) goto L54fa5f;  // @135_54f890
  { u32 v = (u32)((u32)(6966052)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @136_54f890
  goto L54fa61;  // @137_54f890
  L54fa5f:;
  eax = 0;  // @139_54f890
  L54fa61:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 73), &v, sizeof v); }  // @141_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @142_54f890
  ecx = edx = 0;  // @143_54f890
  if ((eax & eax) == 0) goto L54fa7a;  // @144_54f890
  { u32 v = (u32)((u32)(6966060)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @145_54f890
  goto L54fa7c;  // @146_54f890
  L54fa7a:;
  eax = 0;  // @148_54f890
  L54fa7c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 77), &v, sizeof v); }  // @150_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @151_54f890
  ecx = edx = 0;  // @152_54f890
  if ((eax & eax) == 0) goto L54fa95;  // @153_54f890
  { u32 v = (u32)((u32)(6966092)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @154_54f890
  goto L54fa97;  // @155_54f890
  L54fa95:;
  eax = 0;  // @157_54f890
  L54fa97:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 81), &v, sizeof v); }  // @159_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @160_54f890
  ecx = edx = 0;  // @161_54f890
  if ((eax & eax) == 0) goto L54fab0;  // @162_54f890
  { u32 v = (u32)((u32)(6966100)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @163_54f890
  goto L54fab2;  // @164_54f890
  L54fab0:;
  eax = 0;  // @166_54f890
  L54fab2:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 85), &v, sizeof v); }  // @168_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @169_54f890
  ecx = edx = 0;  // @170_54f890
  if ((eax & eax) == 0) goto L54facb;  // @171_54f890
  { u32 v = (u32)((u32)(6966108)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @172_54f890
  goto L54facd;  // @173_54f890
  L54facb:;
  eax = 0;  // @175_54f890
  L54facd:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @177_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @178_54f890
  ecx = edx = 0;  // @179_54f890
  if ((eax & eax) == 0) goto L54fae6;  // @180_54f890
  { u32 v = (u32)((u32)(6966116)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @181_54f890
  goto L54fae8;  // @182_54f890
  L54fae6:;
  eax = 0;  // @184_54f890
  L54fae8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @186_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @187_54f890
  ecx = edx = 0;  // @188_54f890
  if ((eax & eax) == 0) goto L54fb01;  // @189_54f890
  { u32 v = (u32)((u32)(6966084)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @190_54f890
  goto L54fb03;  // @191_54f890
  L54fb01:;
  eax = 0;  // @193_54f890
  L54fb03:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @195_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @196_54f890
  ecx = edx = 0;  // @197_54f890
  if ((eax & eax) == 0) goto L54fb1c;  // @198_54f890
  { u32 v = (u32)((u32)(6966076)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @199_54f890
  goto L54fb1e;  // @200_54f890
  L54fb1c:;
  eax = 0;  // @202_54f890
  L54fb1e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @204_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @205_54f890
  ecx = edx = 0;  // @206_54f890
  if ((eax & eax) == 0) goto L54fb37;  // @207_54f890
  { u32 v = (u32)((u32)(6966068)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @208_54f890
  goto L54fb39;  // @209_54f890
  L54fb37:;
  eax = 0;  // @211_54f890
  L54fb39:;
  ecx = 0;  // @213_54f890
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }  // @214_54f890
  eax = ext_557930_thiscall1(ecx);  // @215_54f890
  ecx = edx = 0;  // @216_54f890
  ecx = esi;  // @217_54f890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @218_54f890
  eax = ext_54fd60_thiscall1(ecx);  // @219_54f890
  ecx = edx = 0;  // @220_54f890
  eax = esi;  // @221_54f890
  SEH_LEAVE();  // @222_54f890
  return eax;  // @223_54f890
}
PCREG(54f890, lifted_54f890);

extern "C" u32 THISCALL lifted_5d6040(u32 ecx_in) {
  SEH_ENTER(0x66c8ce);  // @h_5d6040
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5d6040
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5d6040
  eax = ext_469870_thiscall1(ecx);  // @2_5d6040
  ecx = edx = 0;  // @3_5d6040
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5d6040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5d6040
  ecx = (u32)(EBP - 88);  // @6_5d6040
  reg.state = (s32)((u32)(0));  // @7_5d6040
  { u32 v = (u32)((u32)(7035332)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5d6040
  eax = ext_469870_thiscall1(ecx);  // @9_5d6040
  ecx = edx = 0;  // @10_5d6040
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @11_5d6040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @12_5d6040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @13_5d6040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_5d6040
  edx = (u32)(EBP - 88);  // @15_5d6040
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @16_5d6040
  reg.state = (s32)((u32)(1));  // @17_5d6040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_5d6040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5d6040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(edx));  // @20_5d6040
  ecx = edx = 0;  // @21_5d6040
  eax = esi;  // @22_5d6040
  SEH_LEAVE();  // @23_5d6040
  return eax;  // @24_5d6040
}
PCREG(5d6040, lifted_5d6040);

extern "C" u32 THISCALL lifted_4b8bf0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66bdd6);  // @h_4b8bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @10_4b8bf0
  ecx = edx = 0;  // @11_4b8bf0
  if ((eax & eax) != 0) goto L4b8c93;  // @12_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @13_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(20));  // @15_4b8bf0
  ecx = edx = 0;  // @16_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @17_4b8bf0
  edi = eax;  // @18_4b8bf0
  eax = (u32)(EBP - 144);  // @19_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @21_4b8bf0
  ecx = edx = 0;  // @22_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_4b8bf0
  ecx = eax;  // @24_4b8bf0
  reg.state = (s32)((u32)(0));  // @25_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @26_4b8bf0
  ecx = edx = 0;  // @27_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(edi), (u32)(6891904), (u32)(eax));  // @28_4b8bf0
  ecx = edx = 0;  // @29_4b8bf0
  ecx = (u32)(EBP - 144);  // @30_4b8bf0
  goto L4b8d68;  // @31_4b8bf0
  L4b8c93:;
  ecx = edi;  // @33_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @34_4b8bf0
  ecx = edx = 0;  // @35_4b8bf0
  ecx = edi;  // @36_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 80), &v, sizeof v); }  // @37_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @38_4b8bf0
  ecx = edx = 0;  // @39_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 84), &v, sizeof v); }  // @40_4b8bf0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @41_4b8bf0
  if ((esi & esi) == 0) goto L4b8d7e;  // @42_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_4b8bf0
  ecx = esi;  // @44_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @45_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097158));  // @46_4b8bf0
  ecx = edx = 0;  // @47_4b8bf0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4b8d20;  // @48_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_4b8bf0
  ecx = ebx;  // @50_4b8bf0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 89), &v, sizeof v); }  // @51_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(16));  // @52_4b8bf0
  ecx = edx = 0;  // @53_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892012), (u32)(0), (u32)(6891852), (u32)(36));  // @57_4b8bf0
  ecx = edx = 0;  // @58_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @59_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892028), (u32)(0), (u32)(6891852), (u32)(37));  // @63_4b8bf0
  ecx = edx = 0;  // @64_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 74), &v, sizeof v); }  // @65_4b8bf0
  goto L4b8d7e;  // @66_4b8bf0
  L4b8d20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @68_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(32));  // @70_4b8bf0
  ecx = edx = 0;  // @71_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @72_4b8bf0
  edi = eax;  // @73_4b8bf0
  eax = (u32)(EBP - 272);  // @74_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @76_4b8bf0
  ecx = edx = 0;  // @77_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_4b8bf0
  ecx = eax;  // @79_4b8bf0
  reg.state = (s32)((u32)(1));  // @80_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @81_4b8bf0
  ecx = edx = 0;  // @82_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(edi), (u32)(6891960), (u32)(eax));  // @83_4b8bf0
  ecx = edx = 0;  // @84_4b8bf0
  ecx = (u32)(EBP - 272);  // @85_4b8bf0
  L4b8d68:;
  reg.state = (s32)((u32)(4294967295));  // @87_4b8bf0
  eax = ext_4cbec0_thiscall1(ecx);  // @88_4b8bf0
  ecx = edx = 0;  // @89_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_4b8bf0
  ecx = ebx;  // @91_4b8bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @92_4b8bf0
  ecx = edx = 0;  // @93_4b8bf0
  L4b8d7e:;
  SEH_LEAVE();  // @95_4b8bf0
  ext_633654(G(u32, 0x6f5630));  // @96_4b8bf0
  return eax;  // @97_4b8bf0
}
PCREG(4b8bf0, lifted_4b8bf0);

extern "C" u32 THISCALL lifted_4ccef0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4ccef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_4ccef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(edi));  // @10_4ccef0
  ecx = edx = 0;  // @11_4ccef0
  if ((edi & edi) != 0) goto L4ccf31;  // @12_4ccef0
  L4ccf40:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_4ccef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @15_4ccef0
  SEH_LEAVE();  // @16_4ccef0
  return eax;  // @17_4ccef0
}
PCREG(4ccef0, lifted_4ccef0);

extern "C" u32 THISCALL lifted_4cd050(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cd050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @16_4cd050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(edi));  // @17_4cd050
  ecx = edx = 0;  // @18_4cd050
  if ((edi & edi) != 0) goto L4cd0a4;  // @19_4cd050
  L4cd0b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @21_4cd050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @22_4cd050
  SEH_LEAVE();  // @23_4cd050
  return eax;  // @24_4cd050
}
PCREG(4cd050, lifted_4cd050);

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

extern "C" u32 STDCALL lifted_4266a0(u32 a0, u32 a1) {
  SEH_ENTER(0x664638);  // @h_4266a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4266a0
  ecx = edi;  // @1_4266a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4266a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3_4266a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4266a0
  eax = (eax + (u32)(291));  // @5_4266a0
  reg.state = (s32)((u32)(0));  // @6_4266a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @7_4266a0
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @8_4266a0
  ecx = edx = 0;  // @9_4266a0
  ecx = (u32)(EBP - 144);  // @10_4266a0
  reg.state = (s32)((u32)(0));  // @11_4266a0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @12_4266a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @13_4266a0
  ecx = edx = 0;  // @14_4266a0
  eax = (u32)(EBP - 144);  // @15_4266a0
  reg.state = (s32)((u32)(1));  // @16_4266a0
  ecx = edi;  // @17_4266a0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @18_4266a0
  ecx = edx = 0;  // @19_4266a0
  ecx = (u32)(EBP - 144);  // @20_4266a0
  reg.state = (s32)((u32)(0));  // @21_4266a0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_4266a0
  ecx = edx = 0;  // @23_4266a0
  ecx = (u32)(EBP - 144);  // @24_4266a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(esi));  // @25_4266a0
  ecx = edx = 0;  // @26_4266a0
  eax = (u32)(EBP - 144);  // @27_4266a0
  reg.state = (s32)((u32)(2));  // @28_4266a0
  ecx = edi;  // @29_4266a0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @30_4266a0
  ecx = edx = 0;  // @31_4266a0
  ecx = (u32)(EBP - 144);  // @32_4266a0
  eax = ext_4cbec0_thiscall1(ecx);  // @33_4266a0
  ecx = edx = 0;  // @34_4266a0
  eax = edi;  // @35_4266a0
  SEH_LEAVE();  // @36_4266a0
  ext_633654(G(u32, 0x6f5630));  // @37_4266a0
  return eax;  // @38_4266a0
}
PCREG(4266a0, lifted_4266a0);

extern "C" u32 THISCALL lifted_46e800(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_46e800
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_46e800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_46e800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_46e800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_46e800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @4_46e800
  ecx = edx = 0;  // @5_46e800
  ebx = eax;  // @6_46e800
  if ((ebx & ebx) != 0) goto L46e899;  // @7_46e800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @8_46e800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_46e800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6850500), (u32)(1247));  // @10_46e800
  ecx = edx = 0;  // @11_46e800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_46e800
  edi = eax;  // @13_46e800
  eax = (u32)(EBP - 144);  // @14_46e800
  ecx = esi;  // @15_46e800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @16_46e800
  ecx = edx = 0;  // @17_46e800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_46e800
  ecx = eax;  // @19_46e800
  reg.state = (s32)(ebx);  // @20_46e800
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_46e800
  ecx = edx = 0;  // @22_46e800
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6851060), (u32)(eax));  // @23_46e800
  ecx = edx = 0;  // @24_46e800
  ecx = (u32)(EBP - 144);  // @25_46e800
  eax = ext_4cbec0_thiscall1(ecx);  // @26_46e800
  ecx = edx = 0;  // @27_46e800
  eax = ebx;  // @28_46e800
  L46e899:;
  SEH_LEAVE();  // @30_46e800
  ext_633654(G(u32, 0x6f5630));  // @31_46e800
  return eax;  // @32_46e800
}
PCREG(46e800, lifted_46e800);

extern "C" u32 THISCALL lifted_5379b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a892);  // @h_5379b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_5379b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6955384));  // @7_5379b0
  ecx = edx = 0;  // @8_5379b0
  SEH_LEAVE();  // @9_5379b0
  return eax;  // @10_5379b0
  L537a11:;
  eax = ext_41e290_cdecl1((u32)(4618));  // @12_5379b0
  ecx = edx = 0;  // @13_5379b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @14_5379b0
  reg.state = (s32)((u32)(0));  // @15_5379b0
  if ((eax & eax) == 0) goto L537a35;  // @16_5379b0
  ecx = eax;  // @17_5379b0
  eax = ext_53b600_thiscall1(ecx);  // @18_5379b0
  ecx = edx = 0;  // @19_5379b0
  goto L537a37;  // @20_5379b0
  L537a35:;
  eax = 0;  // @22_5379b0
  L537a37:;
  ecx = eax;  // @24_5379b0
  reg.state = (s32)((u32)(4294967295));  // @25_5379b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 21246), &v, sizeof v); }  // @26_5379b0
  eax = ext_53c590_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @27_5379b0
  ecx = edx = 0;  // @28_5379b0
  SEH_LEAVE();  // @29_5379b0
  return eax;  // @30_5379b0
}
PCREG(5379b0, lifted_5379b0);

extern "C" u32 THISCALL lifted_5898c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_5898c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @11_5898c0
  ecx = edx = 0;  // @12_5898c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_5898c0
  ecx = eax;  // @14_5898c0
  reg.state = (s32)((u32)(0));  // @15_5898c0
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_5898c0
  ecx = edx = 0;  // @17_5898c0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6995992), (u32)(eax));  // @18_5898c0
  ecx = edx = 0;  // @19_5898c0
  ecx = (u32)(EBP - 144);  // @20_5898c0
  eax = ext_4cbec0_thiscall1(ecx);  // @21_5898c0
  ecx = edx = 0;  // @22_5898c0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @23_5898c0
  goto L589955;  // @24_5898c0
  L58994d:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 4), &v, sizeof v); }  // @26_5898c0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @27_5898c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @28_5898c0
  L589955:;
  SEH_LEAVE();  // @30_5898c0
  ext_633654(G(u32, 0x6f5630));  // @31_5898c0
  return eax;  // @32_5898c0
}
PCREG(5898c0, lifted_5898c0);

extern "C" u32 THISCALL lifted_4373a0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x665a8f);  // @h_4373a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ext_4364e0_thiscall5(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(0));  // @15_4373a0
  ecx = edx = 0;  // @16_4373a0
  edx = eax;  // @17_4373a0
  goto L437415;  // @18_4373a0
  L437413:;
  edx = 0;  // @20_4373a0
  L437415:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4628), sizeof v); (u32)v; });  // @22_4373a0
  reg.state = (s32)((u32)(4294967295));  // @23_4373a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4373a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edx));  // @25_4373a0
  ecx = edx = 0;  // @26_4373a0
  SEH_LEAVE();  // @27_4373a0
  return eax;  // @28_4373a0
}
PCREG(4373a0, lifted_4373a0);

