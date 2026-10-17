// batch218002.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4d8db0_stdcall2(u32, u32) __asm__("ext_4d8db0");
extern "C" u32 STDCALL ext_4d8ef0_stdcall3(u32, u32, u32) __asm__("ext_4d8ef0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_42be20_thiscall2(u32, u32) __asm__("ext_42be20");
extern "C" u32 THISCALL ext_432be0_thiscall1(u32) __asm__("ext_432be0");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_441c00_thiscall1(u32) __asm__("ext_441c00");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_444530_thiscall1(u32) __asm__("ext_444530");
extern "C" u32 THISCALL ext_45c3e0_thiscall1(u32) __asm__("ext_45c3e0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc690_thiscall1(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4d9430_thiscall1(u32) __asm__("ext_4d9430");
extern "C" u32 THISCALL ext_4dbb00_thiscall2(u32, u32) __asm__("ext_4dbb00");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_57f820_thiscall1(u32) __asm__("ext_57f820");
extern "C" u32 THISCALL ext_57f960_thiscall1(u32) __asm__("ext_57f960");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5fd7c0_thiscall2(u32, u32) __asm__("ext_5fd7c0");
extern "C" u32 THISCALL ext_601380_thiscall1(u32) __asm__("ext_601380");
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_45c510_cdecl1(...) __asm__("ext_45c510");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_4d9590_cdecl1(...) __asm__("ext_4d9590");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_444020(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_444020
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(edi);  // @16_444020
  eax = ext_4d9590_cdecl1(PV[0]);  // @17_444020
  ecx = edx = 0;  // @18_444020
  L444087:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) != (u32)(0)) goto L444070;  // @20_444020
  L44408d:;
  ecx = esi;  // @22_444020
  eax = ext_444530_thiscall1(ecx);  // @23_444020
  ecx = edx = 0;  // @24_444020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 144), sizeof v); (u32)v; });  // @25_444020
  if ((eax & eax) == 0) goto L4440bd;  // @26_444020
  PV[1] = (u32)(eax);  // @27_444020
  eax = ext_634273_cdecl2(PV[1], (u32)(52));  // @28_444020
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

extern "C" u32 THISCALL lifted_453b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_453b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
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
  PV[0] = (u32)(edi);  // @19_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[0]);  // @21_453b50
  ecx = edx = 0;  // @22_453b50
  if ((eax & eax) != 0) goto L453bd8;  // @23_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; });  // @24_453b50
  PV[1] = (u32)(edi);  // @25_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[1]);  // @27_453b50
  ecx = edx = 0;  // @28_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_453b50
  PV[2] = (u32)(edi);  // @30_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[2]);  // @33_453b50
  ecx = edx = 0;  // @34_453b50
  L453bd8:;
  SEH_LEAVE();  // @36_453b50
  return eax;  // @37_453b50
}
PCREG(453b50, lifted_453b50);

extern "C" u32 THISCALL lifted_564460(u32 ecx_in) {
  SEH_ENTER(0x66c588);  // @h_564460
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_564460
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_564460
  eax = ext_561020_thiscall1(ecx);  // @2_564460
  ecx = edx = 0;  // @3_564460
  { u32 v = (u32)((u32)(6973592)); __builtin_memcpy((void *)(u32)(edi + 384), &v, sizeof v); }  // @4_564460
  esi = (u32)(edi + 396);  // @5_564460
  reg.state = (s32)((u32)(0));  // @6_564460
  ebx = (u32)(25);  // @7_564460
  { u32 v = (u32)((u32)(6973600)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @8_564460
  { u32 v = (u32)((u32)(6973868)); __builtin_memcpy((void *)(u32)(edi + 384), &v, sizeof v); }  // @9_564460
  L5644c0:;
  ecx = esi;  // @11_564460
  eax = ext_57f960_thiscall1(ecx);  // @12_564460
  ecx = edx = 0;  // @13_564460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @14_564460
  esi = (esi + (u32)(42));  // @15_564460
  ebx = (ebx - (u32)(1));  // @16_564460
  if (ebx != 0) goto L5644c0;  // @17_564460
  esi = (u32)(edi + 1446);  // @18_564460
  ebx = (u32)(10);  // @19_564460
  L5644e0:;
  ecx = esi;  // @21_564460
  eax = ext_57f820_thiscall1(ecx);  // @22_564460
  ecx = edx = 0;  // @23_564460
  esi = (esi + (u32)(172));  // @24_564460
  ebx = (ebx - (u32)(1));  // @25_564460
  if (ebx != 0) goto L5644e0;  // @26_564460
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(edi + 3202), &v, sizeof v); }  // @27_564460
  eax = edi;  // @28_564460
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(edi + 3226), &v, sizeof v); }  // @29_564460
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(edi + 3214), &v, sizeof v); }  // @30_564460
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(edi + 3230), &v, sizeof v); }  // @31_564460
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 3166), &v, sizeof v); }  // @32_564460
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(edi + 395), &v, sizeof v); }  // @33_564460
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 3242), &v, sizeof v); }  // @34_564460
  SEH_LEAVE();  // @35_564460
  return eax;  // @36_564460
}
PCREG(564460, lifted_564460);

extern "C" u32 THISCALL lifted_45a5a0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_45a5a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @1_45a5a0
  { u32 v = (u32)((u32)(6831020)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_45a5a0
  if ((ecx & ecx) == 0) goto L45a61e;  // @3_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45a5a0
  edx = (u32)(EBP - 24);  // @5_45a5a0
  PV[0] = (u32)(edx);  // @6_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @7_45a5a0
  ecx = edx = 0;  // @8_45a5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @9_45a5a0
  edx = (u32)(EBP - 24);  // @10_45a5a0
  PV[1] = (u32)(edx);  // @11_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @13_45a5a0
  ecx = edx = 0;  // @14_45a5a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L45a611;  // @15_45a5a0
  L45a5f0:;
  if ((eax & eax) == 0) goto L45a5ff;  // @17_45a5a0
  PV[2] = (u32)(eax);  // @18_45a5a0
  eax = ext_634273_cdecl2(PV[2], (u32)(1));  // @19_45a5a0
  ecx = edx = 0;  // @20_45a5a0
  L45a5ff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; });  // @22_45a5a0
  edx = (u32)(EBP - 24);  // @23_45a5a0
  PV[3] = (u32)(edx);  // @24_45a5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_45a5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @26_45a5a0
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
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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
  PV[0] = (u32)(edi);  // @26_6012e0
  eax = ext_634273_cdecl2(PV[0], (u32)(4));  // @27_6012e0
  ecx = edx = 0;  // @28_6012e0
  L601352:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L601317;  // @30_6012e0
  L601358:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @32_6012e0
  eax = ext_41e2c0_cdecl1(PV[1]);  // @33_6012e0
  ecx = edx = 0;  // @34_6012e0
  { u32 v = (u32)((u32)(7046312)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @35_6012e0
  SEH_LEAVE();  // @36_6012e0
  return eax;  // @37_6012e0
}
PCREG(6012e0, lifted_6012e0);

extern "C" u32 THISCALL lifted_42d600(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664e7e);  // @h_42d600
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @9_42d600
  eax = ext_42be20_thiscall2(ecx, PV[0]);  // @10_42d600
  ecx = edx = 0;  // @11_42d600
  PV[1] = (u32)(eax);  // @12_42d600
  ecx = (u32)(EBP - 24);  // @13_42d600
  eax = ext_5f10c0_thiscall2(ecx, PV[1]);  // @14_42d600
  ecx = edx = 0;  // @15_42d600
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @16_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_42d600
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @18_42d600
  reg.state = (s32)((u32)(0));  // @19_42d600
  eax = ext_5f2c60_thiscall3(ecx, PV[3], PV[2]);  // @20_42d600
  ecx = edx = 0;  // @21_42d600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @22_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_42d600
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d67b;  // @24_42d600
  eax = (u32)(ecx + 12);  // @25_42d600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_42d600
  L42d67b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @28_42d600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @29_42d600
  eax = (eax - ecx);  // @30_42d600
  reg.state = (s32)((u32)(1));  // @31_42d600
  if ((ecx & ecx) == 0) goto L42d69c;  // @32_42d600
  if ((eax & eax) == 0) goto L42d69c;  // @33_42d600
  PV[4] = (u32)(eax);  // @34_42d600
  PV[5] = (u32)(ecx);  // @35_42d600
  ecx = (u32)(EBP - 24);  // @36_42d600
  eax = ext_54f870_stdcall2(PV[5], PV[4]);  // @37_42d600
  ecx = edx = 0;  // @38_42d600
  L42d69c:;
  SEH_LEAVE();  // @40_42d600
  return eax;  // @41_42d600
}
PCREG(42d600, lifted_42d600);

extern "C" u32 THISCALL lifted_47f760(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_47f760
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_47f760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @1_47f760
  reg.state = (s32)((u32)(0));  // @2_47f760
  { u32 v = (u32)((u32)(6860620)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_47f760
  if ((edx & edx) == 0) goto L47f7ba;  // @4_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_47f760
  PV[0] = (u32)(edx);  // @6_47f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_47f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_47f760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @9_47f760
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
  PV[1] = (u32)(esi);  // @23_47f760
  eax = ext_45c510_cdecl1(PV[1]);  // @24_47f760
  ecx = edx = 0;  // @25_47f760
  eax = esi;  // @26_47f760
  SEH_LEAVE();  // @27_47f760
  return eax;  // @28_47f760
  L47f7e9:;
  PV[2] = (u32)(esi);  // @30_47f760
  eax = ext_4690b0_cdecl2(PV[2], (u32)(28));  // @31_47f760
  ecx = edx = 0;  // @32_47f760
  L47f7f4:;
  eax = esi;  // @34_47f760
  SEH_LEAVE();  // @35_47f760
  return eax;  // @36_47f760
}
PCREG(47f760, lifted_47f760);

extern "C" u32 THISCALL lifted_5edea0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5edea0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5edea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @1_5edea0
  { u32 v = (u32)((u32)(7045476)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5edea0
  if ((ecx & ecx) == 0) goto L5ededa;  // @3_5edea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5edea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_5edea0
  ecx = edx = 0;  // @6_5edea0
  L5ededa:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; });  // @8_5edea0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; })) goto L5edf04;  // @9_5edea0
  L5edee2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_5edea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_5edea0
  if ((ecx & ecx) == 0) goto L5edef0;  // @13_5edea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5edea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @15_5edea0
  ecx = edx = 0;  // @16_5edea0
  L5edef0:;
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_5edea0
  eax = ext_634273_cdecl2(PV[0], (u32)(8));  // @19_5edea0
  ecx = edx = 0;  // @20_5edea0
  esi = (esi + (u32)(4));  // @21_5edea0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; })) goto L5edee2;  // @22_5edea0
  L5edf04:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 13), sizeof v); (u32)v; });  // @24_5edea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; });  // @25_5edea0
  eax = (eax - ecx);  // @26_5edea0
  eax = (u32)((s32)eax >> (u32)(2));  // @27_5edea0
  reg.state = (s32)((u32)(0));  // @28_5edea0
  if ((eax & eax) == 0) goto L5edf27;  // @29_5edea0
  eax = (eax << (u32)(2));  // @30_5edea0
  PV[1] = (u32)(eax);  // @31_5edea0
  PV[2] = (u32)(ecx);  // @32_5edea0
  ecx = (u32)(edi + 5);  // @33_5edea0
  eax = ext_54f870_stdcall2(PV[2], PV[1]);  // @34_5edea0
  ecx = edx = 0;  // @35_5edea0
  L5edf27:;
  { u32 v = (u32)((u32)(7012828)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @37_5edea0
  SEH_LEAVE();  // @38_5edea0
  return eax;  // @39_5edea0
}
PCREG(5edea0, lifted_5edea0);

extern "C" u32 THISCALL lifted_436ec0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_436ec0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_436ec0
  if ((eax & eax) == 0) goto L436efa;  // @2_436ec0
  PV[0] = (u32)(eax);  // @3_436ec0
  eax = ext_634273_cdecl2(PV[0], (u32)(1));  // @4_436ec0
  ecx = edx = 0;  // @5_436ec0
  L436efa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @7_436ec0
  if ((ecx & ecx) == 0) goto L436f4e;  // @8_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_436ec0
  edx = (u32)(EBP - 24);  // @10_436ec0
  PV[1] = (u32)(edx);  // @11_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @12_436ec0
  ecx = edx = 0;  // @13_436ec0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @14_436ec0
  edx = (u32)(EBP - 24);  // @15_436ec0
  PV[2] = (u32)(edx);  // @16_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @18_436ec0
  ecx = edx = 0;  // @19_436ec0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L436f41;  // @20_436ec0
  L436f20:;
  if ((eax & eax) == 0) goto L436f2f;  // @22_436ec0
  PV[3] = (u32)(eax);  // @23_436ec0
  eax = ext_634273_cdecl2(PV[3], (u32)(1));  // @24_436ec0
  ecx = edx = 0;  // @25_436ec0
  L436f2f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @27_436ec0
  edx = (u32)(EBP - 24);  // @28_436ec0
  PV[4] = (u32)(edx);  // @29_436ec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_436ec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @31_436ec0
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

extern "C" u32 THISCALL lifted_45a0e0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_45a0e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45a0e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @1_45a0e0
  { u32 v = (u32)((u32)(6829984)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_45a0e0
  if ((ecx & ecx) == 0) goto L45a164;  // @3_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45a0e0
  edx = (u32)(EBP - 24);  // @5_45a0e0
  PV[0] = (u32)(edx);  // @6_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @7_45a0e0
  ecx = edx = 0;  // @8_45a0e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @9_45a0e0
  edx = (u32)(EBP - 24);  // @10_45a0e0
  PV[1] = (u32)(edx);  // @11_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @13_45a0e0
  ecx = edx = 0;  // @14_45a0e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L45a164;  // @15_45a0e0
  L45a130:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_45a0e0
  PV[2] = (u32)(eax);  // @18_45a0e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_45a0e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[2]);  // @21_45a0e0
  ecx = edx = 0;  // @22_45a0e0
  if ((eax & eax) == 0) goto L45a152;  // @23_45a0e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_45a0e0
  ecx = eax;  // @25_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @26_45a0e0
  ecx = edx = 0;  // @27_45a0e0
  L45a152:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @29_45a0e0
  edx = (u32)(EBP - 24);  // @30_45a0e0
  PV[3] = (u32)(edx);  // @31_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @33_45a0e0
  ecx = edx = 0;  // @34_45a0e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L45a130;  // @35_45a0e0
  L45a164:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @37_45a0e0
  if ((ecx & ecx) == 0) goto L45a171;  // @38_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @40_45a0e0
  ecx = edx = 0;  // @41_45a0e0
  L45a171:;
  ecx = esi;  // @43_45a0e0
  eax = ext_43ea20_thiscall1(ecx);  // @44_45a0e0
  ecx = edx = 0;  // @45_45a0e0
  SEH_LEAVE();  // @46_45a0e0
  return eax;  // @47_45a0e0
}
PCREG(45a0e0, lifted_45a0e0);

extern "C" u32 THISCALL lifted_5f2910(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d018);  // @h_5f2910
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(eax);  // @11_5f2910
  ecx = edi;  // @12_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 92)))(ecx, PV[0]);  // @13_5f2910
  ecx = edx = 0;  // @14_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @15_5f2910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_5f2910
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 152), sizeof v); (u32)v; });  // @17_5f2910
  ecx = eax;  // @18_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[1]);  // @19_5f2910
  ecx = edx = 0;  // @20_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @21_5f2910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @22_5f2910
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 156), sizeof v); (u32)v; });  // @23_5f2910
  ecx = eax;  // @24_5f2910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[2]);  // @25_5f2910
  ecx = edx = 0;  // @26_5f2910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @27_5f2910
  { u32 v = (u32)((u32)(7046532)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @28_5f2910
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 19), &v, sizeof v); }  // @29_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @30_5f2910
  eax = (u32)(EBP - 40);  // @31_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @32_5f2910
  { u32 v = (u32)((u32)(1000000)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @33_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @34_5f2910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @35_5f2910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @36_5f2910
  PV[3] = (u32)(eax);  // @37_5f2910
  reg.state = (s32)((u32)(0));  // @38_5f2910
  eax = ext_5fd7c0_thiscall2(ecx, PV[3]);  // @39_5f2910
  ecx = edx = 0;  // @40_5f2910
  ecx = (u32)(EBP - 40);  // @41_5f2910
  eax = ext_602240_thiscall1(ecx);  // @42_5f2910
  ecx = edx = 0;  // @43_5f2910
  SEH_LEAVE();  // @44_5f2910
  return eax;  // @45_5f2910
}
PCREG(5f2910, lifted_5f2910);

extern "C" u32 THISCALL lifted_441d90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_441d90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
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
  PV[0] = (u32)(edi);  // @19_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_441d90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[0]);  // @21_441d90
  ecx = edx = 0;  // @22_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_441d90
  ecx = edi;  // @24_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 776), sizeof v); (u32)v; });  // @25_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @26_441d90
  ecx = edx = 0;  // @27_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e12;  // @28_441d90
  PV[1] = (u32)(edi);  // @29_441d90
  ecx = esi;  // @30_441d90
  eax = ext_442050_thiscall2(ecx, PV[1]);  // @31_441d90
  ecx = edx = 0;  // @32_441d90
  L441e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_441d90
  ecx = edi;  // @35_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @36_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @37_441d90
  ecx = edx = 0;  // @38_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e2a;  // @39_441d90
  PV[2] = (u32)(edi);  // @40_441d90
  ecx = esi;  // @41_441d90
  eax = ext_441e40_thiscall2(ecx, PV[2]);  // @42_441d90
  ecx = edx = 0;  // @43_441d90
  L441e2a:;
  SEH_LEAVE();  // @45_441d90
  return eax;  // @46_441d90
}
PCREG(441d90, lifted_441d90);

extern "C" u32 THISCALL lifted_4317a0(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4317a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4317a0
  { u32 v = (u32)((u32)(6790804)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @1_4317a0
  eax = ext_432be0_thiscall1(ecx);  // @2_4317a0
  ecx = edx = 0;  // @3_4317a0
  edi = (u32)(ebx + 172);  // @4_4317a0
  if ((edi & edi) == 0) goto L43182b;  // @5_4317a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @6_4317a0
  ecx = (u32)(EBP - 24);  // @7_4317a0
  PV[0] = (u32)(ecx);  // @8_4317a0
  ecx = edi;  // @9_4317a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @10_4317a0
  ecx = edx = 0;  // @11_4317a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_4317a0
  ecx = (u32)(EBP - 24);  // @13_4317a0
  PV[1] = (u32)(ecx);  // @14_4317a0
  ecx = edi;  // @15_4317a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @16_4317a0
  ecx = edx = 0;  // @17_4317a0
  if ((eax & eax) == 0) goto L43182b;  // @18_4317a0
  L431800:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @20_4317a0
  if ((esi & esi) == 0) goto L43181c;  // @21_4317a0
  ecx = esi;  // @22_4317a0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_4317a0
  ecx = edx = 0;  // @24_4317a0
  PV[2] = (u32)(esi);  // @25_4317a0
  eax = ext_634273_cdecl2(PV[2], (u32)(128));  // @26_4317a0
  ecx = edx = 0;  // @27_4317a0
  L43181c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_4317a0
  ecx = (u32)(EBP - 24);  // @30_4317a0
  PV[3] = (u32)(ecx);  // @31_4317a0
  ecx = edi;  // @32_4317a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[3]);  // @33_4317a0
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

extern "C" u32 THISCALL lifted_447750(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447750
  { u32 v = (u32)((u32)(6811840)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447750
  if ((ecx & ecx) == 0) goto L4477d4;  // @3_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447750
  edx = (u32)(EBP - 24);  // @5_447750
  PV[0] = (u32)(edx);  // @6_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @7_447750
  ecx = edx = 0;  // @8_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @9_447750
  edx = (u32)(EBP - 24);  // @10_447750
  PV[1] = (u32)(edx);  // @11_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @13_447750
  ecx = edx = 0;  // @14_447750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4477d4;  // @15_447750
  L4477a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_447750
  PV[2] = (u32)(eax);  // @18_447750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_447750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[2]);  // @21_447750
  ecx = edx = 0;  // @22_447750
  if ((eax & eax) == 0) goto L4477c2;  // @23_447750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_447750
  ecx = eax;  // @25_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @26_447750
  ecx = edx = 0;  // @27_447750
  L4477c2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @29_447750
  edx = (u32)(EBP - 24);  // @30_447750
  PV[3] = (u32)(edx);  // @31_447750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_447750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @33_447750
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

extern "C" u32 THISCALL lifted_5082c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_5082c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(eax);  // @14_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, PV[0], (u32)(6932144), (u32)(6932912));  // @16_5082c0
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
  PV[1] = (u32)(eax);  // @35_5082c0
  ecx = (u32)(EBP - 144);  // @36_5082c0
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @37_5082c0
  ecx = edx = 0;  // @38_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @39_5082c0
  eax = (u32)(EBP - 144);  // @40_5082c0
  PV[2] = (u32)(eax);  // @41_5082c0
  ecx = (ecx + (u32)(1042));  // @42_5082c0
  reg.state = (s32)((u32)(0));  // @43_5082c0
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @44_5082c0
  ecx = edx = 0;  // @45_5082c0
  ecx = (u32)(EBP - 144);  // @46_5082c0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_5082c0
  ecx = edx = 0;  // @48_5082c0
  SEH_LEAVE();  // @49_5082c0
  ext_633654(G(u32, 0x6f5630));  // @50_5082c0
  return eax;  // @51_5082c0
}
PCREG(5082c0, lifted_5082c0);

extern "C" u32 THISCALL lifted_5f97e0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_5f97e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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
  PV[0] = (u32)(eax);  // @28_5f97e0
  PV[1] = (u32)(ecx);  // @29_5f97e0
  ecx = esi;  // @30_5f97e0
  eax = ext_54f870_stdcall2(PV[1], PV[0]);  // @31_5f97e0
  ecx = edx = 0;  // @32_5f97e0
  L5f9859:;
  PV[2] = (u32)(esi);  // @34_5f97e0
  reg.state = (s32)((u32)(4294967295));  // @35_5f97e0
  eax = ext_634273_cdecl2(PV[2], (u32)(12));  // @36_5f97e0
  ecx = edx = 0;  // @37_5f97e0
  L5f986b:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }) != (u32)(0)) goto L5f9811;  // @39_5f97e0
  L5f9871:;
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @41_5f97e0
  eax = ext_41e2c0_cdecl1(PV[3]);  // @42_5f97e0
  ecx = edx = 0;  // @43_5f97e0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_5f97e0
  eax = ext_41e2c0_cdecl1(PV[4]);  // @45_5f97e0
  ecx = edx = 0;  // @46_5f97e0
  SEH_LEAVE();  // @47_5f97e0
  return eax;  // @48_5f97e0
}
PCREG(5f97e0, lifted_5f97e0);

extern "C" u32 THISCALL lifted_4d8fc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d1b);  // @h_4d8fc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4d8fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d8fc0
  ecx = (u32)(EBP - 144);  // @2_4d8fc0
  PV[0] = (u32)(eax);  // @3_4d8fc0
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @4_4d8fc0
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
  PV[1] = (u32)(esi);  // @22_4d8fc0
  PV[2] = (u32)(edi);  // @23_4d8fc0
  eax = ext_4d8db0_stdcall2(PV[2], PV[1]);  // @24_4d8fc0
  ecx = edx = 0;  // @25_4d8fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4d8fc0
  PV[3] = (u32)(eax);  // @27_4d8fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4d8fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, PV[3]);  // @29_4d8fc0
  ecx = edx = 0;  // @30_4d8fc0
  if ((eax & eax) == 0) goto L4d9054;  // @31_4d8fc0
  PV[4] = (u32)(esi);  // @32_4d8fc0
  PV[5] = (u32)(edi);  // @33_4d8fc0
  PV[6] = (u32)(eax);  // @34_4d8fc0
  ecx = ebx;  // @35_4d8fc0
  eax = ext_4d8ef0_stdcall3(PV[6], PV[5], PV[4]);  // @36_4d8fc0
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
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_43aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @1_43aa30
  if ((ecx & ecx) == 0) goto L43ab09;  // @2_43aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_43aa30
  edx = (u32)(EBP - 156);  // @4_43aa30
  PV[0] = (u32)(edx);  // @5_43aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @6_43aa30
  ecx = edx = 0;  // @7_43aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @8_43aa30
  edx = (u32)(EBP - 156);  // @9_43aa30
  PV[1] = (u32)(edx);  // @10_43aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_43aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @12_43aa30
  ecx = edx = 0;  // @13_43aa30
  edi = eax;  // @14_43aa30
  if ((edi & edi) == 0) goto L43aaef;  // @15_43aa30
  L43aaa0:;
  ecx = (u32)(EBP - 144);  // @17_43aa30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @18_43aa30
  ecx = edx = 0;  // @19_43aa30
  eax = (u32)(EBP - 144);  // @20_43aa30
  reg.state = (s32)((u32)(0));  // @21_43aa30
  PV[2] = (u32)(eax);  // @22_43aa30
  ecx = edi;  // @23_43aa30
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @24_43aa30
  ecx = edx = 0;  // @25_43aa30
  ecx = (u32)(EBP - 144);  // @26_43aa30
  reg.state = (s32)((u32)(4294967295));  // @27_43aa30
  eax = ext_4cbec0_thiscall1(ecx);  // @28_43aa30
  ecx = edx = 0;  // @29_43aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @30_43aa30
  edx = (u32)(EBP - 156);  // @31_43aa30
  PV[3] = (u32)(edx);  // @32_43aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_43aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[3]);  // @34_43aa30
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

extern "C" u32 THISCALL lifted_4c65a0(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_4c65a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c65a0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @1_4c65a0
  { u32 v = (u32)((u32)(6900120)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4c65a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, PV[0]);  // @5_4c65a0
  ecx = edx = 0;  // @6_4c65a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @7_4c65a0
  if ((ecx & ecx) == 0) goto L4c65e9;  // @8_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @10_4c65a0
  ecx = edx = 0;  // @11_4c65a0
  L4c65e9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_4c65a0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @14_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, PV[1]);  // @16_4c65a0
  ecx = edx = 0;  // @17_4c65a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @18_4c65a0
  if ((ecx & ecx) == 0) goto L4c6607;  // @19_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @21_4c65a0
  ecx = edx = 0;  // @22_4c65a0
  L4c6607:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_4c65a0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @25_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, PV[2]);  // @27_4c65a0
  ecx = edx = 0;  // @28_4c65a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @29_4c65a0
  if ((ecx & ecx) == 0) goto L4c6625;  // @30_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @32_4c65a0
  ecx = edx = 0;  // @33_4c65a0
  L4c6625:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_4c65a0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @36_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, PV[3]);  // @38_4c65a0
  ecx = edx = 0;  // @39_4c65a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @40_4c65a0
  if ((ecx & ecx) == 0) goto L4c6643;  // @41_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @43_4c65a0
  ecx = edx = 0;  // @44_4c65a0
  L4c6643:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @46_4c65a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @47_4c65a0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @48_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_4c65a0
  PV[4] = (u32)(esi);  // @50_4c65a0
  reg.state = (s32)((u32)(0));  // @51_4c65a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_4c65a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_4c65a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[4]);  // @54_4c65a0
  ecx = edx = 0;  // @55_4c65a0
  SEH_LEAVE();  // @56_4c65a0
  return eax;  // @57_4c65a0
}
PCREG(4c65a0, lifted_4c65a0);

