// batch200065.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42feb0_fastcall4(u32, u32, u32, u32) __asm__("ext_42feb0");
extern "C" u32 FASTCALL ext_430480_fastcall2(u32, u32) __asm__("ext_430480");
extern "C" u32 STDCALL ext_42ff40_stdcall1(u32) __asm__("ext_42ff40");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 STDCALL ext_634123_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_634123");
extern "C" u32 THISCALL ext_433f30_thiscall1(u32) __asm__("ext_433f30");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_440e10_thiscall2(u32, u32) __asm__("ext_440e10");
extern "C" u32 THISCALL ext_45f420_thiscall1(u32) __asm__("ext_45f420");
extern "C" u32 THISCALL ext_471f60_thiscall1(u32) __asm__("ext_471f60");
extern "C" u32 THISCALL ext_4c4740_thiscall4(u32, u32, u32, u32) __asm__("ext_4c4740");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d8600_thiscall2(u32, u32) __asm__("ext_4d8600");
extern "C" u32 THISCALL ext_4d9430_thiscall1(u32) __asm__("ext_4d9430");
extern "C" u32 THISCALL ext_4db7e0_thiscall1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_4e3f00_thiscall1(u32) __asm__("ext_4e3f00");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_534190_thiscall1(u32) __asm__("ext_534190");
extern "C" u32 THISCALL ext_534940_thiscall1(u32) __asm__("ext_534940");
extern "C" u32 THISCALL ext_53a810_thiscall1(u32) __asm__("ext_53a810");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f9700_thiscall3(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 THISCALL ext_5fa910_thiscall3(u32, u32, u32) __asm__("ext_5fa910");
extern "C" u32 THISCALL ext_5faf50_thiscall1(u32) __asm__("ext_5faf50");
extern "C" u32 THISCALL ext_5fb370_thiscall2(u32, u32) __asm__("ext_5fb370");
extern "C" u32 THISCALL ext_5fd170_thiscall1(u32) __asm__("ext_5fd170");
extern "C" u32 THISCALL ext_600be0_thiscall1(u32) __asm__("ext_600be0");
extern "C" u32 THISCALL ext_603430_thiscall3(u32, u32, u32) __asm__("ext_603430");
extern "C" u32 THISCALL ext_604170_thiscall2(u32, u32) __asm__("ext_604170");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_4d9590_cdecl1(...) __asm__("ext_4d9590");
extern "C" u32 ext_602ca0_cdecl0(void) __asm__("ext_602ca0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4553d0(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_4553d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 221), sizeof v); (u32)v; });  // @1_4553d0
  { u32 v = (u32)((u32)(6826180)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4553d0
  if ((eax & eax) == 0) goto L455411;  // @3_4553d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @4_4553d0
  ecx = edx = 0;  // @5_4553d0
  L455411:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; });  // @7_4553d0
  if ((eax & eax) == 0) goto L455423;  // @8_4553d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @9_4553d0
  ecx = edx = 0;  // @10_4553d0
  L455423:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; });  // @12_4553d0
  if ((eax & eax) == 0) goto L455435;  // @13_4553d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @14_4553d0
  ecx = edx = 0;  // @15_4553d0
  L455435:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4553d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @20_4553d0
  ecx = edx = 0;  // @21_4553d0
  ecx = (u32)(EBP - 16);  // @22_4553d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @23_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_4553d0
  ecx = eax;  // @25_4553d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6827256), (u32)(ecx));  // @26_4553d0
  ecx = edx = 0;  // @27_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @28_4553d0
  if ((edx & edx) == 0) goto L4554a7;  // @29_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @30_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4553d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(edx));  // @32_4553d0
  ecx = edx = 0;  // @33_4553d0
  if ((eax & eax) == 0) goto L455484;  // @34_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_4553d0
  ecx = eax;  // @36_4553d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(1));  // @37_4553d0
  ecx = edx = 0;  // @38_4553d0
  L455484:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4553d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @43_4553d0
  ecx = edx = 0;  // @44_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_4553d0
  ecx = eax;  // @46_4553d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(6827256), (u32)(0), (u32)(16));  // @47_4553d0
  ecx = edx = 0;  // @48_4553d0
  L4554a7:;
  ecx = esi;  // @50_4553d0
  eax = ext_43de70_thiscall1(ecx);  // @51_4553d0
  ecx = edx = 0;  // @52_4553d0
  SEH_LEAVE();  // @53_4553d0
  return eax;  // @54_4553d0
}
PCREG(4553d0, lifted_4553d0);

extern "C" u32 THISCALL lifted_42c380(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d7c);  // @h_42c380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = esi;  // @8_42c380
  reg.state = (s32)((u32)(0));  // @9_42c380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(ecx));  // @10_42c380
  ecx = edx = 0;  // @11_42c380
  ecx = (u32)(EBP - 144);  // @12_42c380
  reg.state = (s32)((u32)(1));  // @13_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @14_42c380
  ecx = edx = 0;  // @15_42c380
  ecx = (u32)(EBP - 400);  // @16_42c380
  reg.state = (s32)((u32)(0));  // @17_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @18_42c380
  ecx = edx = 0;  // @19_42c380
  ecx = (u32)(EBP - 144);  // @20_42c380
  eax = ext_4cc5f0_thiscall1(ecx);  // @21_42c380
  ecx = edx = 0;  // @22_42c380
  if ((eax & eax) != 0) goto L42c41d;  // @23_42c380
  eax = (u32)(EBP - 144);  // @24_42c380
  ecx = edi;  // @25_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @26_42c380
  ecx = edx = 0;  // @27_42c380
  goto L42c48c;  // @28_42c380
  L42c41d:;
  ecx = (u32)(EBP - 272);  // @30_42c380
  eax = ext_4cbeb0_thiscall1(ecx);  // @31_42c380
  ecx = edx = 0;  // @32_42c380
  ecx = (u32)(EBP - 400);  // @33_42c380
  reg.state = (s32)((u32)(2));  // @34_42c380
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789684));  // @35_42c380
  ecx = edx = 0;  // @36_42c380
  eax = (u32)(EBP - 400);  // @37_42c380
  reg.state = (s32)((u32)(3));  // @38_42c380
  ecx = (u32)(EBP - 272);  // @39_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @40_42c380
  ecx = edx = 0;  // @41_42c380
  ecx = (u32)(EBP - 400);  // @42_42c380
  reg.state = (s32)((u32)(2));  // @43_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @44_42c380
  ecx = edx = 0;  // @45_42c380
  eax = (u32)(EBP - 144);  // @46_42c380
  ecx = (u32)(EBP - 272);  // @47_42c380
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @48_42c380
  ecx = edx = 0;  // @49_42c380
  eax = (u32)(EBP - 272);  // @50_42c380
  ecx = edi;  // @51_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @52_42c380
  ecx = edx = 0;  // @53_42c380
  ecx = (u32)(EBP - 272);  // @54_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @55_42c380
  ecx = edx = 0;  // @56_42c380
  L42c48c:;
  ecx = (u32)(EBP - 144);  // @58_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @59_42c380
  ecx = edx = 0;  // @60_42c380
  eax = edi;  // @61_42c380
  SEH_LEAVE();  // @62_42c380
  ext_633654(G(u32, 0x6f5630));  // @63_42c380
  return eax;  // @64_42c380
}
PCREG(42c380, lifted_42c380);

extern "C" u32 THISCALL lifted_42fcc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665213);  // @h_42fcc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = esi;  // @15_42fcc0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(edi));  // @16_42fcc0
  ecx = edx = 0;  // @17_42fcc0
  goto L42fda0;  // @18_42fcc0
  L42fd3d:;
  ecx = (u32)(EBP - 144);  // @20_42fcc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789684));  // @21_42fcc0
  ecx = edx = 0;  // @22_42fcc0
  eax = (u32)(EBP - 144);  // @23_42fcc0
  reg.state = (s32)((u32)(1));  // @24_42fcc0
  ecx = esi;  // @25_42fcc0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @26_42fcc0
  ecx = edx = 0;  // @27_42fcc0
  ecx = (u32)(EBP - 144);  // @28_42fcc0
  reg.state = (s32)((u32)(0));  // @29_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @30_42fcc0
  ecx = edx = 0;  // @31_42fcc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_42fcc0
  ecx = (u32)(EBP - 144);  // @33_42fcc0
  ecx = ebx;  // @34_42fcc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(ecx));  // @35_42fcc0
  ecx = edx = 0;  // @36_42fcc0
  ecx = esi;  // @37_42fcc0
  reg.state = (s32)((u32)(2));  // @38_42fcc0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @39_42fcc0
  ecx = edx = 0;  // @40_42fcc0
  ecx = (u32)(EBP - 144);  // @41_42fcc0
  reg.state = (s32)((u32)(0));  // @42_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @43_42fcc0
  ecx = edx = 0;  // @44_42fcc0
  L42fda0:;
  ecx = (u32)(EBP - 144);  // @46_42fcc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789688));  // @47_42fcc0
  ecx = edx = 0;  // @48_42fcc0
  eax = (u32)(EBP - 144);  // @49_42fcc0
  reg.state = (s32)((u32)(3));  // @50_42fcc0
  ecx = esi;  // @51_42fcc0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @52_42fcc0
  ecx = edx = 0;  // @53_42fcc0
  ecx = (u32)(EBP - 144);  // @54_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @55_42fcc0
  ecx = edx = 0;  // @56_42fcc0
  eax = esi;  // @57_42fcc0
  SEH_LEAVE();  // @58_42fcc0
  ext_633654(G(u32, 0x6f5630));  // @59_42fcc0
  return eax;  // @60_42fcc0
}
PCREG(42fcc0, lifted_42fcc0);

extern "C" u32 THISCALL lifted_5ef080(u32 ecx_in) {
  SEH_ENTER(0x66ccae);  // @h_5ef080
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5ef080
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5ef080
  reg.state = (s32)((u32)(0));  // @2_5ef080
  { u32 v = (u32)((u32)(7045560)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_5ef080
  { u32 v = (u32)((u32)(150)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @4_5ef080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @5_5ef080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @6_5ef080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @7_5ef080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @8_5ef080
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @9_5ef080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @10_5ef080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 173), &v, sizeof v); }  // @11_5ef080
  eax = ext_41e290_cdecl1((u32)(168));  // @12_5ef080
  ecx = edx = 0;  // @13_5ef080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @14_5ef080
  reg.state = (s32)((u32)(1));  // @15_5ef080
  if ((eax & eax) == 0) goto L5ef125;  // @16_5ef080
  ecx = eax;  // @17_5ef080
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(3));  // @18_5ef080
  ecx = edx = 0;  // @19_5ef080
  goto L5ef127;  // @20_5ef080
  L5ef125:;
  eax = 0;  // @22_5ef080
  L5ef127:;
  reg.state = (s32)((u32)(0));  // @24_5ef080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 169), &v, sizeof v); }  // @25_5ef080
  eax = ext_41e290_cdecl1((u32)(168));  // @26_5ef080
  ecx = edx = 0;  // @27_5ef080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @28_5ef080
  reg.state = (s32)((u32)(2));  // @29_5ef080
  if ((eax & eax) == 0) goto L5ef154;  // @30_5ef080
  ecx = eax;  // @31_5ef080
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(3));  // @32_5ef080
  ecx = edx = 0;  // @33_5ef080
  goto L5ef156;  // @34_5ef080
  L5ef154:;
  eax = 0;  // @36_5ef080
  L5ef156:;
  reg.state = (s32)((u32)(0));  // @38_5ef080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 161), &v, sizeof v); }  // @39_5ef080
  eax = ext_41e290_cdecl1((u32)(168));  // @40_5ef080
  ecx = edx = 0;  // @41_5ef080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @42_5ef080
  reg.state = (s32)((u32)(3));  // @43_5ef080
  if ((eax & eax) == 0) goto L5ef183;  // @44_5ef080
  ecx = eax;  // @45_5ef080
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(3));  // @46_5ef080
  ecx = edx = 0;  // @47_5ef080
  goto L5ef185;  // @48_5ef080
  L5ef183:;
  eax = 0;  // @50_5ef080
  L5ef185:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 165), &v, sizeof v); }  // @52_5ef080
  eax = (u32)(70);  // @53_5ef080
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 185), &v, sizeof v); }  // @54_5ef080
  eax = esi;  // @55_5ef080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 177), &v, sizeof v); }  // @56_5ef080
  { u32 v = (u32)((u32)(3145984)); __builtin_memcpy((void *)(u32)(esi + 181), &v, sizeof v); }  // @57_5ef080
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 187), &v, sizeof v); }  // @58_5ef080
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 191), &v, sizeof v); }  // @59_5ef080
  SEH_LEAVE();  // @60_5ef080
  return eax;  // @61_5ef080
}
PCREG(5ef080, lifted_5ef080);

extern "C" u32 THISCALL lifted_441c00(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_441c00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ext_4d9590_cdecl1((u32)(edi));  // @9_441c00
  ecx = edx = 0;  // @10_441c00
  L441c4a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) != (u32)(0)) goto L441c33;  // @12_441c00
  L441c50:;
  ecx = esi;  // @14_441c00
  eax = ext_45f420_thiscall1(ecx);  // @15_441c00
  ecx = edx = 0;  // @16_441c00
  if ((eax & eax) == 0) goto L441c8a;  // @17_441c00
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; }) != (u32)(0)) goto L441c8a;  // @18_441c00
  ecx = esi;  // @19_441c00
  eax = ext_45f420_thiscall1(ecx);  // @20_441c00
  ecx = edx = 0;  // @21_441c00
  if ((eax & eax) == 0) goto L441c8a;  // @22_441c00
  ecx = esi;  // @23_441c00
  eax = ext_45f420_thiscall1(ecx);  // @24_441c00
  ecx = edx = 0;  // @25_441c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @26_441c00
  eax = ext_4db7e0_thiscall1(ecx);  // @27_441c00
  ecx = edx = 0;  // @28_441c00
  if ((eax & eax) == 0) goto L441c8a;  // @29_441c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_441c00
  ecx = eax;  // @31_441c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 716)))(ecx, (u32)(esi));  // @32_441c00
  ecx = edx = 0;  // @33_441c00
  L441c8a:;
  edi = (u32)(esi + 93);  // @35_441c00
  ebx = (u32)(5);  // @36_441c00
  L441c92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_441c00
  if ((ecx & ecx) == 0) goto L441ca5;  // @39_441c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_441c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(1));  // @41_441c00
  ecx = edx = 0;  // @42_441c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_441c00
  L441ca5:;
  edi = (edi + (u32)(4));  // @45_441c00
  ebx = (ebx - (u32)(1));  // @46_441c00
  if (ebx != 0) goto L441c92;  // @47_441c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @48_441c00
  if ((edi & edi) == 0) goto L441cc9;  // @49_441c00
  ecx = edi;  // @50_441c00
  eax = ext_4e3f00_thiscall1(ecx);  // @51_441c00
  ecx = edx = 0;  // @52_441c00
  eax = ext_634273_cdecl2((u32)(edi), (u32)(45));  // @53_441c00
  ecx = edx = 0;  // @54_441c00
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @55_441c00
  L441cc9:;
  ecx = esi;  // @57_441c00
  eax = ext_43ea20_thiscall1(ecx);  // @58_441c00
  ecx = edx = 0;  // @59_441c00
  SEH_LEAVE();  // @60_441c00
  return eax;  // @61_441c00
}
PCREG(441c00, lifted_441c00);

extern "C" u32 THISCALL lifted_433220(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665580);  // @h_433220
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_433220
  ecx = (u32)(ebx + 200);  // @2_433220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @4_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 200), sizeof v); (u32)v; });  // @5_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @6_433220
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(edi));  // @7_433220
  ecx = edx = 0;  // @8_433220
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L433288;  // @9_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 200), sizeof v); (u32)v; });  // @10_433220
  ecx = (u32)(ebx + 200);  // @11_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(edi));  // @12_433220
  ecx = edx = 0;  // @13_433220
  L433288:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 172), sizeof v); (u32)v; });  // @15_433220
  ecx = (u32)(ebx + 172);  // @16_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(edi));  // @17_433220
  ecx = edx = 0;  // @18_433220
  esi = eax;  // @19_433220
  if ((esi & esi) != 0) goto L4332f3;  // @20_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 172), sizeof v); (u32)v; });  // @21_433220
  ecx = (u32)(ebx + 172);  // @22_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(edi));  // @23_433220
  ecx = edx = 0;  // @24_433220
  esi = eax;  // @25_433220
  eax = ext_41e290_cdecl1((u32)(128));  // @26_433220
  ecx = edx = 0;  // @27_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @28_433220
  reg.state = (s32)((u32)(0));  // @29_433220
  if ((eax & eax) == 0) goto L4332e6;  // @30_433220
  ecx = eax;  // @31_433220
  eax = ext_4cbeb0_thiscall1(ecx);  // @32_433220
  ecx = edx = 0;  // @33_433220
  reg.state = (s32)((u32)(4294967295));  // @34_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @35_433220
  goto L4332f6;  // @36_433220
  L4332e6:;
  eax = 0;  // @38_433220
  reg.state = (s32)((u32)(4294967295));  // @39_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @40_433220
  goto L4332f6;  // @41_433220
  L4332f3:;
  esi = (esi + (u32)(4));  // @43_433220
  L4332f6:;
  ecx = (u32)(EBP - 144);  // @45_433220
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @46_433220
  ecx = edx = 0;  // @47_433220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_433220
  eax = (u32)(EBP - 144);  // @49_433220
  reg.state = (s32)((u32)(1));  // @50_433220
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @51_433220
  ecx = edx = 0;  // @52_433220
  ecx = (u32)(EBP - 144);  // @53_433220
  eax = ext_4cbec0_thiscall1(ecx);  // @54_433220
  ecx = edx = 0;  // @55_433220
  SEH_LEAVE();  // @56_433220
  ext_633654(G(u32, 0x6f5630));  // @57_433220
  return eax;  // @58_433220
}
PCREG(433220, lifted_433220);

extern "C" u32 THISCALL lifted_5328b0(u32 ecx_in) {
  SEH_ENTER(0x66a76c);  // @h_5328b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5328b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5328b0
  eax = ext_534940_thiscall1(ecx);  // @2_5328b0
  ecx = edx = 0;  // @3_5328b0
  edi = (u32)(esi + 21626);  // @4_5328b0
  reg.state = (s32)((u32)(0));  // @5_5328b0
  ebx = (u32)(esi + 21630);  // @6_5328b0
  { u32 v = (u32)((u32)(6952336)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5328b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21642), &v, sizeof v); }  // @8_5328b0
  { u32 v = (u32)((u32)(7347056)); __builtin_memcpy((void *)(u32)(esi + 20901), &v, sizeof v); }  // @9_5328b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21614), &v, sizeof v); }  // @10_5328b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @11_5328b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21618), &v, sizeof v); }  // @12_5328b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @13_5328b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21622), &v, sizeof v); }  // @14_5328b0
  eax = ext_41e290_cdecl1((u32)(264));  // @15_5328b0
  ecx = edx = 0;  // @16_5328b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @17_5328b0
  reg.state = (s32)((u32)(1));  // @18_5328b0
  if ((eax & eax) == 0) goto L532967;  // @19_5328b0
  ecx = eax;  // @20_5328b0
  eax = ext_4d8330_thiscall4(ecx, (u32)(6952972), (u32)(6952940), (u32)(edi));  // @21_5328b0
  ecx = edx = 0;  // @22_5328b0
  edx = eax;  // @23_5328b0
  goto L532969;  // @24_5328b0
  L532967:;
  edx = 0;  // @26_5328b0
  L532969:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 21618), &v, sizeof v); }  // @28_5328b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5328b0
  reg.state = (s32)((u32)(0));  // @30_5328b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_5328b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @32_5328b0
  ecx = edx = 0;  // @33_5328b0
  eax = ext_41e290_cdecl1((u32)(264));  // @34_5328b0
  ecx = edx = 0;  // @35_5328b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @36_5328b0
  reg.state = (s32)((u32)(2));  // @37_5328b0
  if ((eax & eax) == 0) goto L5329b0;  // @38_5328b0
  ecx = eax;  // @39_5328b0
  eax = ext_4d8330_thiscall4(ecx, (u32)(6953012), (u32)(6952988), (u32)(ebx));  // @40_5328b0
  ecx = edx = 0;  // @41_5328b0
  edx = eax;  // @42_5328b0
  goto L5329b2;  // @43_5328b0
  L5329b0:;
  edx = 0;  // @45_5328b0
  L5329b2:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 21622), &v, sizeof v); }  // @47_5328b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_5328b0
  reg.state = (s32)((u32)(0));  // @49_5328b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_5328b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @51_5328b0
  ecx = edx = 0;  // @52_5328b0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @53_5328b0
  eax = esi;  // @54_5328b0
  SEH_LEAVE();  // @55_5328b0
  return eax;  // @56_5328b0
}
PCREG(5328b0, lifted_5328b0);

extern "C" u32 THISCALL lifted_5384b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66a90d);  // @h_5384b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5384b0
  ecx = (u32)(EBP - 144);  // @2_5384b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @3_5384b0
  ecx = edx = 0;  // @4_5384b0
  eax = (u32)(EBP - 144);  // @5_5384b0
  reg.state = (s32)((u32)(0));  // @6_5384b0
  ecx = (u32)(esi + 20921);  // @7_5384b0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @8_5384b0
  ecx = edx = 0;  // @9_5384b0
  ecx = (u32)(EBP - 144);  // @10_5384b0
  reg.state = (s32)((u32)(4294967295));  // @11_5384b0
  eax = ext_4cbec0_thiscall1(ecx);  // @12_5384b0
  ecx = edx = 0;  // @13_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_5384b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5384b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6942756), (u32)(0), (u32)(6954540), (u32)(429));  // @17_5384b0
  ecx = edx = 0;  // @18_5384b0
  ecx = (u32)(esi + 139);  // @19_5384b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 20647), &v, sizeof v); }  // @20_5384b0
  eax = ext_534190_thiscall1(ecx);  // @21_5384b0
  ecx = edx = 0;  // @22_5384b0
  eax = ext_41e290_cdecl1((u32)(26));  // @23_5384b0
  ecx = edx = 0;  // @24_5384b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @25_5384b0
  reg.state = (s32)((u32)(1));  // @26_5384b0
  if ((eax & eax) == 0) goto L538572;  // @27_5384b0
  ecx = eax;  // @28_5384b0
  eax = ext_53a810_thiscall1(ecx);  // @29_5384b0
  ecx = edx = 0;  // @30_5384b0
  goto L538574;  // @31_5384b0
  L538572:;
  eax = 0;  // @33_5384b0
  L538574:;
  ecx = eax;  // @35_5384b0
  reg.state = (s32)((u32)(4294967295));  // @36_5384b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21242), &v, sizeof v); }  // @37_5384b0
  eax = ext_4690b0_cdecl0();  // @38_5384b0
  ecx = edx = 0;  // @39_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_5384b0
  ecx = esi;  // @41_5384b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20909), &v, sizeof v); }  // @42_5384b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @43_5384b0
  ecx = edx = 0;  // @44_5384b0
  if ((eax & eax) == 0) goto L5385ad;  // @45_5384b0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_5384b0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @47_5384b0
  L5385ad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_5384b0
  ecx = esi;  // @50_5384b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 352)))(ecx, (u32)(128));  // @51_5384b0
  ecx = edx = 0;  // @52_5384b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; }) == (u32)(0)) goto L5385d5;  // @53_5384b0
  L5385c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_5384b0
  ecx = esi;  // @56_5384b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 412), sizeof v); (u32)v; });  // @57_5384b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @58_5384b0
  ecx = edx = 0;  // @59_5384b0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5385c5;  // @60_5384b0
  L5385d5:;
  SEH_LEAVE();  // @62_5384b0
  ext_633654(G(u32, 0x6f5630));  // @63_5384b0
  return eax;  // @64_5384b0
}
PCREG(5384b0, lifted_5384b0);

extern "C" u32 THISCALL lifted_4c4630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4c4630
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4c4630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4c4630
  eax = (u32)(edi + 130);  // @2_4c4630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4c4630
  ecx = esi;  // @4_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @6_4c4630
  ecx = edx = 0;  // @7_4c4630
  ecx = (u32)(edi + 134);  // @8_4c4630
  ecx = eax;  // @9_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(ecx));  // @11_4c4630
  ecx = edx = 0;  // @12_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_4c4630
  eax = (u32)(edi + 138);  // @14_4c4630
  ecx = esi;  // @15_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @16_4c4630
  ecx = edx = 0;  // @17_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_4c4630
  eax = (u32)(edi + 142);  // @19_4c4630
  ecx = esi;  // @20_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @21_4c4630
  ecx = edx = 0;  // @22_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4c4630
  eax = (u32)(edi + 146);  // @24_4c4630
  ecx = esi;  // @25_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @26_4c4630
  ecx = edx = 0;  // @27_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_4c4630
  eax = (u32)(edi + 150);  // @29_4c4630
  ecx = esi;  // @30_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(eax));  // @31_4c4630
  ecx = edx = 0;  // @32_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_4c4630
  eax = (u32)(edi + 162);  // @34_4c4630
  ecx = esi;  // @35_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @36_4c4630
  ecx = edx = 0;  // @37_4c4630
  ecx = (u32)(EBP - 144);  // @38_4c4630
  eax = ext_4cbeb0_thiscall1(ecx);  // @39_4c4630
  ecx = edx = 0;  // @40_4c4630
  eax = (u32)(EBP - 148);  // @41_4c4630
  reg.state = (s32)((u32)(0));  // @42_4c4630
  ecx = edi;  // @43_4c4630
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @44_4c4630
  eax = ext_6352f0_thiscall2(ecx, (u32)(eax));  // @45_4c4630
  ecx = edx = 0;  // @46_4c4630
  eax = (u32)(EBP - 144);  // @47_4c4630
  ecx = edi;  // @48_4c4630
  eax = (u32)(EBP - 152);  // @49_4c4630
  eax = (u32)(EBP - 148);  // @50_4c4630
  eax = ext_4c4740_thiscall4(ecx, (u32)(eax), (u32)(eax), (u32)(eax));  // @51_4c4630
  ecx = edx = 0;  // @52_4c4630
  ecx = (u32)(EBP - 144);  // @53_4c4630
  eax = ext_4cbec0_thiscall1(ecx);  // @54_4c4630
  ecx = edx = 0;  // @55_4c4630
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @56_4c4630
  SEH_LEAVE();  // @57_4c4630
  ext_633654(G(u32, 0x6f5630));  // @58_4c4630
  return eax;  // @59_4c4630
}
PCREG(4c4630, lifted_4c4630);

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

extern "C" u32 THISCALL lifted_5f1180(u32 ecx_in) {
  SEH_ENTER(0x66ce12);  // @h_5f1180
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5f1180
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f1180
  eax = ext_41e290_cdecl1((u32)(25));  // @2_5f1180
  ecx = edx = 0;  // @3_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_5f1180
  reg.state = (s32)((u32)(0));  // @5_5f1180
  if ((eax & eax) == 0) goto L5f11cc;  // @6_5f1180
  ecx = eax;  // @7_5f1180
  eax = ext_600be0_thiscall1(ecx);  // @8_5f1180
  ecx = edx = 0;  // @9_5f1180
  goto L5f11ce;  // @10_5f1180
  L5f11cc:;
  eax = 0;  // @12_5f1180
  L5f11ce:;
  reg.state = (s32)((u32)(4294967295));  // @14_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @15_5f1180
  eax = ext_41e290_cdecl1((u32)(77));  // @16_5f1180
  ecx = edx = 0;  // @17_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @18_5f1180
  reg.state = (s32)((u32)(1));  // @19_5f1180
  if ((eax & eax) == 0) goto L5f11fc;  // @20_5f1180
  ecx = eax;  // @21_5f1180
  eax = ext_5fa910_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(20));  // @22_5f1180
  ecx = edx = 0;  // @23_5f1180
  goto L5f11fe;  // @24_5f1180
  L5f11fc:;
  eax = 0;  // @26_5f1180
  L5f11fe:;
  ecx = (u32)(esi + 8);  // @28_5f1180
  reg.state = (s32)((u32)(4294967295));  // @29_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @30_5f1180
  eax = ext_604170_thiscall2(ecx, (u32)(eax));  // @31_5f1180
  ecx = edx = 0;  // @32_5f1180
  ecx = (u32)(esi + 20);  // @33_5f1180
  reg.state = (s32)((u32)(2));  // @34_5f1180
  eax = ext_4cbeb0_thiscall1(ecx);  // @35_5f1180
  ecx = edx = 0;  // @36_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 172), &v, sizeof v); }  // @37_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @38_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @39_5f1180
  reg.state = (s32)((u32)(4));  // @40_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @41_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @42_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @43_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @44_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @45_5f1180
  eax = ext_41e290_cdecl1((u32)(8));  // @46_5f1180
  ecx = edx = 0;  // @47_5f1180
  if ((eax & eax) == 0) goto L5f12a7;  // @48_5f1180
  { u32 v = (u32)((u32)(7046824)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @49_5f1180
  { u32 v = (u32)((u32)(7046784)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @50_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @51_5f1180
  eax = esi;  // @52_5f1180
  SEH_LEAVE();  // @53_5f1180
  return eax;  // @54_5f1180
  L5f12a7:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @56_5f1180
  eax = esi;  // @57_5f1180
  SEH_LEAVE();  // @58_5f1180
  return eax;  // @59_5f1180
}
PCREG(5f1180, lifted_5f1180);

extern "C" u32 THISCALL lifted_4cb9c0(u32 ecx_in) {
  SEH_ENTER(0x66606f);  // @h_4cb9c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4cb9c0
  eax = ext_41e290_cdecl1((u32)(28));  // @1_4cb9c0
  ecx = edx = 0;  // @2_4cb9c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_4cb9c0
  reg.state = (s32)((u32)(0));  // @4_4cb9c0
  if ((eax & eax) == 0) goto L4cba0c;  // @5_4cb9c0
  ecx = eax;  // @6_4cb9c0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(2));  // @7_4cb9c0
  ecx = edx = 0;  // @8_4cb9c0
  goto L4cba0e;  // @9_4cb9c0
  L4cba0c:;
  eax = 0;  // @11_4cb9c0
  L4cba0e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @13_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @14_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @15_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @16_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @17_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @18_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @19_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @20_4cb9c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @21_4cb9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_4cb9c0
  reg.state = (s32)((u32)(4294967295));  // @23_4cb9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_4cb9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4cb9c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @26_4cb9c0
  ecx = edx = 0;  // @27_4cb9c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @28_4cb9c0
  edi = eax;  // @29_4cb9c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4cb9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(esi));  // @31_4cb9c0
  ecx = edx = 0;  // @32_4cb9c0
  if ((eax & eax) == 0) goto L4cba79;  // @33_4cb9c0
  ecx = 0;  // @34_4cb9c0
  goto L4cbaaa;  // @35_4cb9c0
  L4cba79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @37_4cb9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @38_4cb9c0
  if ((eax & eax) == 0) goto L4cba98;  // @39_4cb9c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L4cba98;  // @40_4cb9c0
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L4cba98;  // @41_4cb9c0
  ecx = esi;  // @42_4cb9c0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @43_4cb9c0
  ecx = edx = 0;  // @44_4cb9c0
  ecx = eax;  // @45_4cb9c0
  goto L4cbaaa;  // @46_4cb9c0
  L4cba98:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cbaa7;  // @48_4cb9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_4cb9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(esi));  // @50_4cb9c0
  ecx = edx = 0;  // @51_4cb9c0
  L4cbaa7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @53_4cb9c0
  L4cbaaa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @55_4cb9c0
  ecx = edi;  // @56_4cb9c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6903412), (u32)(ecx), (u32)(4));  // @57_4cb9c0
  ecx = edx = 0;  // @58_4cb9c0
  SEH_LEAVE();  // @59_4cb9c0
  return eax;  // @60_4cb9c0
}
PCREG(4cb9c0, lifted_4cb9c0);

extern "C" u32 THISCALL lifted_444eb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_444eb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_444eb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_444eb0
  eax = ext_440e10_thiscall2(ecx, (u32)(esi));  // @2_444eb0
  ecx = edx = 0;  // @3_444eb0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L444ef7;  // @4_444eb0
  SEH_LEAVE();  // @5_444eb0
  return eax;  // @6_444eb0
  L444ef7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_444eb0
  eax = (u32)(edi + 148);  // @9_444eb0
  ecx = esi;  // @10_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @11_444eb0
  ecx = edx = 0;  // @12_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_444eb0
  eax = (u32)(edi + 152);  // @14_444eb0
  ecx = esi;  // @15_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @16_444eb0
  ecx = edx = 0;  // @17_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_444eb0
  eax = (u32)(edi + 192);  // @19_444eb0
  ecx = esi;  // @20_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @21_444eb0
  ecx = edx = 0;  // @22_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_444eb0
  ecx = (u32)(EBP + 8);  // @24_444eb0
  ecx = esi;  // @25_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @26_444eb0
  ecx = edx = 0;  // @27_444eb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L444f70;  // @28_444eb0
  eax = ext_41e290_cdecl1((u32)(28));  // @29_444eb0
  ecx = edx = 0;  // @30_444eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_444eb0
  reg.state = (s32)((u32)(0));  // @32_444eb0
  if ((eax & eax) == 0) goto L444f59;  // @33_444eb0
  ecx = eax;  // @34_444eb0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @35_444eb0
  ecx = edx = 0;  // @36_444eb0
  ecx = eax;  // @37_444eb0
  goto L444f5b;  // @38_444eb0
  L444f59:;
  ecx = 0;  // @40_444eb0
  L444f5b:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 164), &v, sizeof v); }  // @42_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_444eb0
  ecx = esi;  // @44_444eb0
  reg.state = (s32)((u32)(4294967295));  // @45_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ecx));  // @46_444eb0
  ecx = edx = 0;  // @47_444eb0
  L444f70:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_444eb0
  eax = (u32)(edi + 172);  // @50_444eb0
  ecx = esi;  // @51_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @52_444eb0
  ecx = edx = 0;  // @53_444eb0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @54_444eb0
  SEH_LEAVE();  // @55_444eb0
  return eax;  // @56_444eb0
}
PCREG(444eb0, lifted_444eb0);

extern "C" u32 THISCALL lifted_6041e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66dd06);  // @h_6041e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_6041e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6041e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6041e0
  eax = ext_603430_thiscall3(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @3_6041e0
  ecx = edx = 0;  // @4_6041e0
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_6041e0
  eax = (u32)(esi + 12);  // @6_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @7_6041e0
  ecx = (u32)(EBP - 28);  // @8_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @9_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @10_6041e0
  reg.state = (s32)((u32)(0));  // @11_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @12_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @13_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @14_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @15_6041e0
  eax = ext_6014a0_stdcall1((u32)(8));  // @16_6041e0
  ecx = edx = 0;  // @17_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @18_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @19_6041e0
  ecx = (u32)(eax + 8);  // @20_6041e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @21_6041e0
  if ((eax & eax) == 0) goto L604272;  // @22_6041e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @23_6041e0
  L604272:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_6041e0
  ecx = (u32)(EBP - 28);  // @27_6041e0
  ecx = edi;  // @28_6041e0
  reg.state = (s32)((u32)(1));  // @29_6041e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(ecx));  // @30_6041e0
  ecx = edx = 0;  // @31_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @32_6041e0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @33_6041e0
  if (eax <= (u32)(32)) goto L60429d;  // @34_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @35_6041e0
  if ((eax & eax) == 0) goto L60429c;  // @36_6041e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @37_6041e0
  ecx = edx = 0;  // @38_6041e0
  goto L60429d;  // @39_6041e0
  L60429c:;
  __builtin_trap();  // @41_6041e0
  L60429d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7488120), sizeof v); (u32)v; });  // @43_6041e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @44_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_6041e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @46_6041e0
  ecx = edx = 0;  // @47_6041e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @48_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @49_6041e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @50_6041e0
  eax = (eax - ecx);  // @51_6041e0
  reg.state = (s32)((u32)(2));  // @52_6041e0
  if ((ecx & ecx) == 0) goto L6042ce;  // @53_6041e0
  if ((eax & eax) == 0) goto L6042ce;  // @54_6041e0
  ecx = (u32)(EBP - 28);  // @55_6041e0
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @56_6041e0
  ecx = edx = 0;  // @57_6041e0
  L6042ce:;
  eax = esi;  // @59_6041e0
  SEH_LEAVE();  // @60_6041e0
  return eax;  // @61_6041e0
}
PCREG(6041e0, lifted_6041e0);

extern "C" u32 THISCALL lifted_477480(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_477480
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_477480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1854), sizeof v); (u32)v; });  // @1_477480
  { u32 v = (u32)((u32)(6856996)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_477480
  if ((ecx & ecx) == 0) goto L4774bc;  // @3_477480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_477480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_477480
  ecx = edx = 0;  // @6_477480
  L4774bc:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1685), sizeof v); (u32)v; });  // @8_477480
  if ((edi & edi) == 0) goto L477505;  // @9_477480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @10_477480
  if ((eax & eax) == 0) goto L4774d6;  // @11_477480
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @12_477480
  ecx = edx = 0;  // @13_477480
  L4774d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @15_477480
  if ((eax & eax) == 0) goto L4774e8;  // @16_477480
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @17_477480
  ecx = edx = 0;  // @18_477480
  L4774e8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @20_477480
  if ((eax & eax) == 0) goto L4774fa;  // @21_477480
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @22_477480
  ecx = edx = 0;  // @23_477480
  L4774fa:;
  eax = ext_634273_cdecl2((u32)(edi), (u32)(24));  // @25_477480
  ecx = edx = 0;  // @26_477480
  L477505:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1482), sizeof v); (u32)v; });  // @28_477480
  if ((ecx & ecx) == 0) goto L477515;  // @29_477480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_477480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @31_477480
  ecx = edx = 0;  // @32_477480
  L477515:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_477480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_477480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1462), sizeof v); (u32)v; }));  // @36_477480
  ecx = edx = 0;  // @37_477480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1462), sizeof v); (u32)v; });  // @38_477480
  if ((ecx & ecx) == 0) goto L477539;  // @39_477480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_477480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @41_477480
  ecx = edx = 0;  // @42_477480
  L477539:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_477480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_477480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1466), sizeof v); (u32)v; }));  // @46_477480
  ecx = edx = 0;  // @47_477480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1466), sizeof v); (u32)v; });  // @48_477480
  if ((ecx & ecx) == 0) goto L47755d;  // @49_477480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_477480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @51_477480
  ecx = edx = 0;  // @52_477480
  L47755d:;
  ecx = (u32)(esi + 1042);  // @54_477480
  eax = ext_4cbec0_thiscall1(ecx);  // @55_477480
  ecx = edx = 0;  // @56_477480
  ecx = esi;  // @57_477480
  eax = ext_471f60_thiscall1(ecx);  // @58_477480
  ecx = edx = 0;  // @59_477480
  SEH_LEAVE();  // @60_477480
  return eax;  // @61_477480
}
PCREG(477480, lifted_477480);

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

extern "C" u32 THISCALL lifted_4300c0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x6652c9);  // @h_4300c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edi = ecx;  // @0_4300c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_4300c0
  if (ebx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) goto L430124;  // @2_4300c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L430124;  // @3_4300c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_4300c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_4300c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4300c0
  eax = ext_42feb0_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 13), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; }));  // @7_4300c0
  ecx = edx = 0;  // @8_4300c0
  if ((s32)(eax & eax) < 0) goto L430124;  // @9_4300c0
  ecx = edi;  // @10_4300c0
  eax = ext_42ff40_stdcall1((u32)(esi));  // @11_4300c0
  ecx = edx = 0;  // @12_4300c0
  esi = eax;  // @13_4300c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 9), &v, sizeof v); }  // @14_4300c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_4300c0
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L43017b;  // @16_4300c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @17_4300c0
  goto L43017b;  // @18_4300c0
  L430124:;
  ecx = edi;  // @20_4300c0
  eax = ext_6014a0_stdcall1((u32)(37));  // @21_4300c0
  ecx = edx = 0;  // @22_4300c0
  esi = eax;  // @23_4300c0
  eax = (u32)(esi + 13);  // @24_4300c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @25_4300c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @26_4300c0
  reg.state = (s32)((u32)(0));  // @27_4300c0
  if ((eax & eax) == 0) goto L430160;  // @28_4300c0
  ecx = eax;  // @29_4300c0
  eax = ext_5f10c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @30_4300c0
  ecx = edx = 0;  // @31_4300c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @32_4300c0
  ecx = (u32)(esi + 25);  // @33_4300c0
  eax = (eax + (u32)(12));  // @34_4300c0
  reg.state = (s32)((u32)(1));  // @35_4300c0
  eax = ext_5f10c0_thiscall2(ecx, (u32)(eax));  // @36_4300c0
  ecx = edx = 0;  // @37_4300c0
  L430160:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 5), &v, sizeof v); }  // @39_4300c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_4300c0
  if (ebx != eax) goto L430173;  // @41_4300c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @42_4300c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_4300c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @44_4300c0
  goto L43017b;  // @45_4300c0
  L430173:;
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5), sizeof v); (u32)v; })) goto L43017b;  // @47_4300c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @48_4300c0
  L43017b:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1), &v, sizeof v); }  // @50_4300c0
  ecx = esi;  // @51_4300c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5), &v, sizeof v); }  // @52_4300c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @53_4300c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @54_4300c0
  edx = (edx + 1);  // @55_4300c0
  eax = ext_430480_fastcall2(ecx, edx);  // @56_4300c0
  ecx = edx = 0;  // @57_4300c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @58_4300c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @59_4300c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @60_4300c0
  SEH_LEAVE();  // @61_4300c0
  return eax;  // @62_4300c0
}
PCREG(4300c0, lifted_4300c0);

extern "C" u32 THISCALL lifted_641a40(u32 ecx_in) {
  SEH_ENTER(0x66e926);  // @h_641a40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @1_641a40
  ecx = edx = 0;  // @2_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_641a40
  reg.state = (s32)((u32)(0));  // @4_641a40
  if ((eax & eax) == 0) goto L641a97;  // @5_641a40
  ecx = (u32)(esi + 12);  // @6_641a40
  ecx = eax;  // @7_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088160), (u32)(0), (u32)(ecx));  // @8_641a40
  ecx = edx = 0;  // @9_641a40
  edx = eax;  // @10_641a40
  goto L641a99;  // @11_641a40
  L641a97:;
  edx = 0;  // @13_641a40
  L641a99:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @15_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_641a40
  reg.state = (s32)((u32)(4294967295));  // @17_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @19_641a40
  ecx = edx = 0;  // @20_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @21_641a40
  ecx = edx = 0;  // @22_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @23_641a40
  reg.state = (s32)((u32)(1));  // @24_641a40
  if ((eax & eax) == 0) goto L641ae3;  // @25_641a40
  ecx = (u32)(esi + 4);  // @26_641a40
  ecx = eax;  // @27_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088168), (u32)(0), (u32)(ecx));  // @28_641a40
  ecx = edx = 0;  // @29_641a40
  edx = eax;  // @30_641a40
  goto L641ae5;  // @31_641a40
  L641ae3:;
  edx = 0;  // @33_641a40
  L641ae5:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @35_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_641a40
  reg.state = (s32)((u32)(4294967295));  // @37_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @39_641a40
  ecx = edx = 0;  // @40_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @41_641a40
  ecx = edx = 0;  // @42_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @43_641a40
  reg.state = (s32)((u32)(2));  // @44_641a40
  if ((eax & eax) == 0) goto L641b2f;  // @45_641a40
  ecx = (u32)(esi + 8);  // @46_641a40
  ecx = eax;  // @47_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088176), (u32)(0), (u32)(ecx));  // @48_641a40
  ecx = edx = 0;  // @49_641a40
  edx = eax;  // @50_641a40
  goto L641b31;  // @51_641a40
  L641b2f:;
  edx = 0;  // @53_641a40
  L641b31:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @55_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_641a40
  reg.state = (s32)((u32)(4294967295));  // @57_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @59_641a40
  ecx = edx = 0;  // @60_641a40
  SEH_LEAVE();  // @61_641a40
  return eax;  // @62_641a40
}
PCREG(641a40, lifted_641a40);

extern "C" u32 THISCALL lifted_4264b0(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4264b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @1_4264b0
  { u32 v = (u32)((u32)(6785124)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_4264b0
  if ((ecx & ecx) == 0) goto L426573;  // @3_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4264b0
  edx = (u32)(EBP - 24);  // @5_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(edx));  // @6_4264b0
  ecx = edx = 0;  // @7_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @8_4264b0
  edx = (u32)(EBP - 24);  // @9_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(edx));  // @11_4264b0
  ecx = edx = 0;  // @12_4264b0
  esi = eax;  // @13_4264b0
  if ((esi & esi) == 0) goto L426573;  // @14_4264b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6774960), sizeof v); (u32)v; });  // @15_4264b0
  L426512:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @17_4264b0
  if ((ecx & ecx) == 0) goto L426520;  // @18_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @20_4264b0
  ecx = edx = 0;  // @21_4264b0
  L426520:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @23_4264b0
  if ((ecx & ecx) == 0) goto L42652e;  // @24_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @26_4264b0
  ecx = edx = 0;  // @27_4264b0
  L42652e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @29_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6785452), (u32)(27));  // @31_4264b0
  ecx = edx = 0;  // @32_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6785504), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @34_4264b0
  ecx = edx = 0;  // @35_4264b0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(1));  // @36_4264b0
  ecx = edx = 0;  // @37_4264b0
  eax = ((u32(STDCALL *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @38_4264b0
  ecx = edx = 0;  // @39_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @40_4264b0
  edx = (u32)(EBP - 24);  // @41_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(edx));  // @43_4264b0
  ecx = edx = 0;  // @44_4264b0
  esi = eax;  // @45_4264b0
  if ((esi & esi) != 0) goto L426512;  // @46_4264b0
  L426573:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @48_4264b0
  if ((ecx & ecx) == 0) goto L426583;  // @49_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @51_4264b0
  ecx = edx = 0;  // @52_4264b0
  L426583:;
  ecx = edi;  // @54_4264b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340948), &v, sizeof v); }  // @55_4264b0
  eax = ext_433f30_thiscall1(ecx);  // @56_4264b0
  ecx = edx = 0;  // @57_4264b0
  SEH_LEAVE();  // @58_4264b0
  return eax;  // @59_4264b0
}
PCREG(4264b0, lifted_4264b0);

extern "C" u32 THISCALL lifted_5fb000(u32 ecx_in) {
  SEH_ENTER(0x66d408);  // @h_5fb000
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5fb000
  eax = ext_5fd170_thiscall1(ecx);  // @1_5fb000
  ecx = edx = 0;  // @2_5fb000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7488120), &v, sizeof v); }  // @3_5fb000
  eax = ext_602ca0_cdecl0();  // @4_5fb000
  ecx = edx = 0;  // @5_5fb000
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @6_5fb000
  if ((ebx & ebx) == 0) goto L5fb096;  // @7_5fb000
  reg.state = (s32)((u32)(0));  // @8_5fb000
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 5), sizeof v); (u32)v; }) == (u32)(0)) goto L5fb07a;  // @9_5fb000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; });  // @10_5fb000
  ecx = (u32)(ebx + 1);  // @11_5fb000
  eax = ext_5fb370_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }));  // @12_5fb000
  ecx = edx = 0;  // @13_5fb000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; });  // @14_5fb000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @15_5fb000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; });  // @16_5fb000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @17_5fb000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; });  // @18_5fb000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @19_5fb000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 5), &v, sizeof v); }  // @20_5fb000
  L5fb07a:;
  ecx = (u32)(ebx + 1);  // @22_5fb000
  reg.state = (s32)((u32)(1));  // @23_5fb000
  eax = ext_54f870_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; }), (u32)(29));  // @24_5fb000
  ecx = edx = 0;  // @25_5fb000
  eax = ext_634273_cdecl2((u32)(ebx), (u32)(10));  // @26_5fb000
  ecx = edx = 0;  // @27_5fb000
  L5fb096:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @29_5fb000
  if ((esi & esi) == 0) goto L5fb0af;  // @30_5fb000
  ecx = esi;  // @31_5fb000
  eax = ext_5faf50_thiscall1(ecx);  // @32_5fb000
  ecx = edx = 0;  // @33_5fb000
  eax = ext_634273_cdecl2((u32)(esi), (u32)(51));  // @34_5fb000
  ecx = edx = 0;  // @35_5fb000
  L5fb0af:;
  ecx = (u32)(edi + 65);  // @37_5fb000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_5fb000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @39_5fb000
  eax = (eax - edx);  // @40_5fb000
  reg.state = (s32)((u32)(2));  // @41_5fb000
  if ((edx & edx) == 0) goto L5fb0cf;  // @42_5fb000
  if ((eax & eax) == 0) goto L5fb0cf;  // @43_5fb000
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @44_5fb000
  ecx = edx = 0;  // @45_5fb000
  L5fb0cf:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }));  // @47_5fb000
  ecx = edx = 0;  // @48_5fb000
  ecx = (u32)(edi + 8);  // @49_5fb000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_5fb000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @51_5fb000
  eax = (eax - edx);  // @52_5fb000
  reg.state = (s32)((u32)(3));  // @53_5fb000
  if ((edx & edx) == 0) goto L5fb0fa;  // @54_5fb000
  if ((eax & eax) == 0) goto L5fb0fa;  // @55_5fb000
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @56_5fb000
  ecx = edx = 0;  // @57_5fb000
  L5fb0fa:;
  SEH_LEAVE();  // @59_5fb000
  return eax;  // @60_5fb000
}
PCREG(5fb000, lifted_5fb000);

extern "C" u32 THISCALL lifted_527570(u32 ecx_in) {
  SEH_ENTER(0x66a50c);  // @h_527570
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_527570
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_527570
  eax = (u32)(esi + 149);  // @2_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 133), &v, sizeof v); }  // @3_527570
  edi = (u32)(esi + 133);  // @4_527570
  eax = ext_634123_stdcall5((u32)(eax), (u32)(222), (u32)(8), (u32)(5332384), (u32)(5332736));  // @5_527570
  ecx = edx = 0;  // @6_527570
  eax = (u32)(esi + 1925);  // @7_527570
  reg.state = (s32)((u32)(0));  // @8_527570
  eax = ext_634123_stdcall5((u32)(eax), (u32)(222), (u32)(8), (u32)(5332384), (u32)(5332736));  // @9_527570
  ecx = edx = 0;  // @10_527570
  eax = (u32)(esi + 3701);  // @11_527570
  reg.state = (s32)((u32)(1));  // @12_527570
  eax = ext_634123_stdcall5((u32)(eax), (u32)(307), (u32)(8), (u32)(5413072), (u32)(5315248));  // @13_527570
  ecx = edx = 0;  // @14_527570
  eax = (u32)(esi + 6157);  // @15_527570
  reg.state = (s32)((u32)(2));  // @16_527570
  eax = ext_634123_stdcall5((u32)(eax), (u32)(307), (u32)(8), (u32)(5413072), (u32)(5315248));  // @17_527570
  ecx = edx = 0;  // @18_527570
  eax = (u32)(esi + 8654);  // @19_527570
  reg.state = (s32)((u32)(3));  // @20_527570
  eax = ext_634123_stdcall5((u32)(eax), (u32)(121), (u32)(2), (u32)(5334992), (u32)(4624560));  // @21_527570
  ecx = edx = 0;  // @22_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @23_527570
  eax = (u32)(EBP - 20);  // @24_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @25_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8896), &v, sizeof v); }  // @26_527570
  eax = esi;  // @27_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @28_527570
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @29_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @30_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @31_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8633), &v, sizeof v); }  // @32_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8637), &v, sizeof v); }  // @33_527570
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @34_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @35_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @36_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @37_527570
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @38_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @39_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @40_527570
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @41_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8613), &v, sizeof v); }  // @42_527570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8617), &v, sizeof v); }  // @43_527570
  if (edi == eax) goto L5276f6;  // @44_527570
  { u32 v = (u32)((u32)(5120)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @45_527570
  L5276f6:;
  SEH_LEAVE();  // @47_527570
  return eax;  // @48_527570
}
PCREG(527570, lifted_527570);

extern "C" u32 THISCALL lifted_431ce0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x6654b6);  // @h_431ce0
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
  ecx = (u32)(EBP - 144);  // @10_431ce0
  reg.state = (s32)((u32)(0));  // @11_431ce0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(esi));  // @12_431ce0
  ecx = edx = 0;  // @13_431ce0
  eax = (u32)(EBP - 144);  // @14_431ce0
  reg.state = (s32)((u32)(1));  // @15_431ce0
  ecx = (u32)(EBP - 324);  // @16_431ce0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @17_431ce0
  ecx = edx = 0;  // @18_431ce0
  ecx = (u32)(EBP - 144);  // @19_431ce0
  reg.state = (s32)((u32)(0));  // @20_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @21_431ce0
  ecx = edx = 0;  // @22_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @23_431ce0
  if ((eax & eax) == 0) goto L431d81;  // @24_431ce0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @25_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @26_431ce0
  goto L431d92;  // @27_431ce0
  L431d81:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @29_431ce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @30_431ce0
  L431d92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @32_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @33_431ce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @34_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 149), &v, sizeof v); }  // @35_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @37_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @38_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @39_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @40_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @41_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @42_431ce0
  ecx = (u32)(EBP - 324);  // @43_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @44_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @45_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @46_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @47_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @48_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @49_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @50_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @51_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @52_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @53_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @54_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @55_431ce0
  ecx = edi;  // @56_431ce0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 159), &v, sizeof v); }  // @57_431ce0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 157), &v, sizeof v); }  // @58_431ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(ecx));  // @59_431ce0
  ecx = edx = 0;  // @60_431ce0
  ecx = (u32)(EBP - 324);  // @61_431ce0
  esi = eax;  // @62_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @63_431ce0
  ecx = edx = 0;  // @64_431ce0
  eax = esi;  // @65_431ce0
  SEH_LEAVE();  // @66_431ce0
  ext_633654(G(u32, 0x6f5630));  // @67_431ce0
  return eax;  // @68_431ce0
}
PCREG(431ce0, lifted_431ce0);

extern "C" u32 THISCALL lifted_4d81f0(u32 ecx_in) {
  SEH_ENTER(0x669639);  // @h_4d81f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_4d81f0
  { u32 v = (u32)((u32)(6909020)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_4d81f0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_4d81f0
  ecx = edx = 0;  // @3_4d81f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4d81f0
  reg.state = (s32)((u32)(0));  // @5_4d81f0
  if ((eax & eax) == 0) goto L4d8242;  // @6_4d81f0
  ecx = eax;  // @7_4d81f0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(8), (u32)(1));  // @8_4d81f0
  ecx = edx = 0;  // @9_4d81f0
  goto L4d8244;  // @10_4d81f0
  L4d8242:;
  eax = 0;  // @12_4d81f0
  L4d8244:;
  reg.state = (s32)((u32)(4294967295));  // @14_4d81f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @15_4d81f0
  eax = ext_41e290_cdecl1((u32)(264));  // @16_4d81f0
  ecx = edx = 0;  // @17_4d81f0
  esi = eax;  // @18_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_4d81f0
  reg.state = (s32)((u32)(1));  // @20_4d81f0
  if ((esi & esi) == 0) goto L4d82a0;  // @21_4d81f0
  ecx = (u32)(esi + 4);  // @22_4d81f0
  { u32 v = (u32)((u32)(6908948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @23_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909368));  // @24_4d81f0
  ecx = edx = 0;  // @25_4d81f0
  ecx = (u32)(esi + 132);  // @26_4d81f0
  reg.state = (s32)((u32)(2));  // @27_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909324));  // @28_4d81f0
  ecx = edx = 0;  // @29_4d81f0
  { u32 v = (u32)((u32)(6909044)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @30_4d81f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 260), &v, sizeof v); }  // @31_4d81f0
  goto L4d82a2;  // @32_4d81f0
  L4d82a0:;
  esi = 0;  // @34_4d81f0
  L4d82a2:;
  ecx = edi;  // @36_4d81f0
  reg.state = (s32)((u32)(4294967295));  // @37_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @38_4d81f0
  eax = ext_4d8600_thiscall2(ecx, (u32)(esi));  // @39_4d81f0
  ecx = edx = 0;  // @40_4d81f0
  eax = ext_41e290_cdecl1((u32)(264));  // @41_4d81f0
  ecx = edx = 0;  // @42_4d81f0
  esi = eax;  // @43_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @44_4d81f0
  reg.state = (s32)((u32)(3));  // @45_4d81f0
  if ((esi & esi) == 0) goto L4d8306;  // @46_4d81f0
  ecx = (u32)(esi + 4);  // @47_4d81f0
  { u32 v = (u32)((u32)(6908948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @48_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909412));  // @49_4d81f0
  ecx = edx = 0;  // @50_4d81f0
  ecx = (u32)(esi + 132);  // @51_4d81f0
  reg.state = (s32)((u32)(4));  // @52_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909380));  // @53_4d81f0
  ecx = edx = 0;  // @54_4d81f0
  { u32 v = (u32)((u32)(6909116)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @55_4d81f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 260), &v, sizeof v); }  // @56_4d81f0
  goto L4d8308;  // @57_4d81f0
  L4d8306:;
  esi = 0;  // @59_4d81f0
  L4d8308:;
  ecx = edi;  // @61_4d81f0
  reg.state = (s32)((u32)(4294967295));  // @62_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @63_4d81f0
  eax = ext_4d8600_thiscall2(ecx, (u32)(esi));  // @64_4d81f0
  ecx = edx = 0;  // @65_4d81f0
  eax = edi;  // @66_4d81f0
  SEH_LEAVE();  // @67_4d81f0
  return eax;  // @68_4d81f0
}
PCREG(4d81f0, lifted_4d81f0);

