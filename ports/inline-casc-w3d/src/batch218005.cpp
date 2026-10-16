// batch218005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_45f420_thiscall1(u32) __asm__("ext_45f420");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d1390_thiscall3(u32, u32, u32) __asm__("ext_4d1390");
extern "C" u32 THISCALL ext_4d9430_thiscall1(u32) __asm__("ext_4d9430");
extern "C" u32 THISCALL ext_4db7e0_thiscall1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_4e3f00_thiscall1(u32) __asm__("ext_4e3f00");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f37f0_thiscall3(u32, u32, u32) __asm__("ext_5f37f0");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_5f55e0_thiscall1(u32) __asm__("ext_5f55e0");
extern "C" u32 THISCALL ext_5fef70_thiscall2(u32, u32) __asm__("ext_5fef70");
extern "C" u32 THISCALL ext_600260_thiscall3(u32, u32, u32) __asm__("ext_600260");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4d9590_cdecl1(...) __asm__("ext_4d9590");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5fbb00(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d4d2);  // @h_5fbb00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @14_5fbb00
  ecx = eax;  // @15_5fbb00
  PV[1] = (u32)(esi);  // @16_5fbb00
  eax = ext_5f37f0_thiscall3(ecx, PV[1], PV[0]);  // @17_5fbb00
  ecx = edx = 0;  // @18_5fbb00
  edi = eax;  // @19_5fbb00
  goto L5fbb66;  // @20_5fbb00
  L5fbb64:;
  edi = 0;  // @22_5fbb00
  L5fbb66:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @24_5fbb00
  reg.state = (s32)((u32)(4294967295));  // @25_5fbb00
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; })) goto L5fbb7d;  // @26_5fbb00
  ecx = (u32)(esi + 88);  // @27_5fbb00
  eax = ext_5f4630_thiscall1(ecx);  // @28_5fbb00
  ecx = edx = 0;  // @29_5fbb00
  L5fbb7d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @31_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @32_5fbb00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @33_5fbb00
  ecx = (u32)(65521);  // @34_5fbb00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @35_5fbb00
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @36_5fbb00
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @37_5fbb00
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(1))) & 0xffff);  // @38_5fbb00
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @39_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @40_5fbb00
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; })) goto L5fbbb3;  // @41_5fbb00
  ecx = (u32)(ebx + 24);  // @42_5fbb00
  eax = ext_5f4630_thiscall1(ecx);  // @43_5fbb00
  ecx = edx = 0;  // @44_5fbb00
  L5fbbb3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @46_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @47_5fbb00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @48_5fbb00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @49_5fbb00
  SEH_LEAVE();  // @50_5fbb00
  return eax;  // @51_5fbb00
}
PCREG(5fbb00, lifted_5fbb00);

extern "C" u32 THISCALL lifted_475740(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_475740
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(ecx);  // @12_475740
  ecx = eax;  // @13_475740
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_475740
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[0], (u32)(1));  // @15_475740
  ecx = edx = 0;  // @16_475740
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_475740
  ecx = eax;  // @18_475740
  reg.state = (s32)((u32)(0));  // @19_475740
  eax = ext_4cc1d0_thiscall1(ecx);  // @20_475740
  ecx = edx = 0;  // @21_475740
  PV[1] = (u32)(eax);  // @22_475740
  PV[2] = (u32)(edi);  // @23_475740
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[2], (u32)(6854632), PV[1]);  // @24_475740
  ecx = edx = 0;  // @25_475740
  reg.state = (s32)((u32)(4294967295));  // @26_475740
  ecx = (u32)(EBP - 144);  // @27_475740
  eax = ext_4cbec0_thiscall1(ecx);  // @28_475740
  ecx = edx = 0;  // @29_475740
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @30_475740
  esi = 0;  // @31_475740
  L4757e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @33_475740
  PV[3] = (u32)(ecx);  // @34_475740
  ecx = ebx;  // @35_475740
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1372)))(ecx, PV[3]);  // @36_475740
  ecx = edx = 0;  // @37_475740
  if ((eax & eax) == 0) goto L475801;  // @38_475740
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_475740
  ecx = eax;  // @40_475740
  PV[4] = (u32)(esi);  // @41_475740
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 804)))(ecx, PV[4]);  // @42_475740
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
  u32 PV[64];
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
  PV[0] = (u32)(edx);  // @10_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @11_53b2a0
  ecx = edx = 0;  // @12_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @13_53b2a0
  edx = (u32)(EBP - 200);  // @14_53b2a0
  PV[1] = (u32)(edx);  // @15_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @17_53b2a0
  ecx = edx = 0;  // @18_53b2a0
  edx = eax;  // @19_53b2a0
  if ((edx & edx) == 0) goto L53b344;  // @20_53b2a0
  L53b310:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_53b2a0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @23_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @26_53b2a0
  ecx = edx = 0;  // @27_53b2a0
  PV[3] = (u32)(eax);  // @28_53b2a0
  ecx = (u32)(EBP - 188);  // @29_53b2a0
  eax = ext_4cd540_thiscall2(ecx, PV[3]);  // @30_53b2a0
  ecx = edx = 0;  // @31_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @32_53b2a0
  edx = (u32)(EBP - 200);  // @33_53b2a0
  PV[4] = (u32)(edx);  // @34_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[4]);  // @36_53b2a0
  ecx = edx = 0;  // @37_53b2a0
  edx = eax;  // @38_53b2a0
  if ((edx & edx) != 0) goto L53b310;  // @39_53b2a0
  L53b344:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_53b2a0
  ecx = (u32)(EBP - 188);  // @42_53b2a0
  PV[5] = (u32)(ecx);  // @43_53b2a0
  ecx = edi;  // @44_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[5]);  // @45_53b2a0
  ecx = edx = 0;  // @46_53b2a0
  ecx = (u32)(EBP - 188);  // @47_53b2a0
  eax = ext_4ccf60_thiscall1(ecx);  // @48_53b2a0
  ecx = edx = 0;  // @49_53b2a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @50_53b2a0
  SEH_LEAVE();  // @51_53b2a0
  ext_633654(G(u32, 0x6f5630));  // @52_53b2a0
  return eax;  // @53_53b2a0
}
PCREG(53b2a0, lifted_53b2a0);

extern "C" u32 THISCALL lifted_462b00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_462b00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_462b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @1_462b00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_462b00
  PV[0] = (u32)(edi);  // @3_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @5_462b00
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[0]);  // @6_462b00
  ecx = edx = 0;  // @7_462b00
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462b46;  // @8_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @9_462b00
  goto L462bb2;  // @10_462b00
  L462b46:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @12_462b00
  if ((ecx & ecx) == 0) goto L462b5e;  // @13_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_462b00
  PV[1] = (u32)(edi);  // @15_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @16_462b00
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @17_462b00
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
  PV[2] = (u32)(eax);  // @31_462b00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[2], (u32)(1));  // @32_462b00
  ecx = edx = 0;  // @33_462b00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_462b00
  ecx = eax;  // @35_462b00
  reg.state = (s32)((u32)(0));  // @36_462b00
  eax = ext_4cc1d0_thiscall1(ecx);  // @37_462b00
  ecx = edx = 0;  // @38_462b00
  PV[3] = (u32)(eax);  // @39_462b00
  PV[4] = (u32)(edi);  // @40_462b00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[4], (u32)(6838576), PV[3]);  // @41_462b00
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
  u32 PV[64];
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
  PV[0] = (u32)(eax);  // @21_601380
  PV[1] = (u32)(ecx);  // @22_601380
  ecx = esi;  // @23_601380
  eax = ext_54f870_stdcall2(PV[1], PV[0]);  // @24_601380
  ecx = edx = 0;  // @25_601380
  L6013ea:;
  PV[2] = (u32)(esi);  // @27_601380
  reg.state = (s32)((u32)(4294967295));  // @28_601380
  eax = ext_634273_cdecl2(PV[2], (u32)(12));  // @29_601380
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
  PV[3] = (u32)(eax);  // @41_601380
  PV[4] = (u32)(edx);  // @42_601380
  eax = ext_54f870_stdcall2(PV[4], PV[3]);  // @43_601380
  ecx = edx = 0;  // @44_601380
  L601422:;
  PV[5] = (u32)(esi);  // @46_601380
  eax = ext_634273_cdecl2(PV[5], (u32)(24));  // @47_601380
  ecx = edx = 0;  // @48_601380
  L60142d:;
  SEH_LEAVE();  // @50_601380
  return eax;  // @51_601380
}
PCREG(601380, lifted_601380);

extern "C" u32 FASTCALL lifted_42ae00(u32 ecx_in, u32 edx_in, u32 a0) {
  SEH_ENTER(0x66cd79);  // @h_42ae00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(ebx);  // @24_42ae00
  ecx = edi;  // @25_42ae00
  eax = ext_6014a0_stdcall1(PV[0]);  // @26_42ae00
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
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @40_42ae00
  ecx = edi;  // @41_42ae00
  reg.state = (s32)((u32)(0));  // @42_42ae00
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @43_42ae00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @44_42ae00
  eax = ext_5f2c60_thiscall3(ecx, PV[2], PV[1]);  // @45_42ae00
  ecx = edx = 0;  // @46_42ae00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_42ae00
  eax = (u32)(esi + ecx);  // @48_42ae00
  PV[3] = (u32)(eax);  // @49_42ae00
  PV[4] = (u32)(ecx);  // @50_42ae00
  ecx = edi;  // @51_42ae00
  eax = ext_5f2c60_thiscall3(ecx, PV[4], PV[3]);  // @52_42ae00
  ecx = edx = 0;  // @53_42ae00
  eax = edi;  // @54_42ae00
  SEH_LEAVE();  // @55_42ae00
  return eax;  // @56_42ae00
}
PCREG(42ae00, lifted_42ae00);


extern "C" u32 THISCALL lifted_48b5b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66796b);  // @h_48b5b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 124), sizeof v); (u32)v; });  // @1_48b5b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2_48b5b0
  ecx = edx = 0;  // @3_48b5b0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L48b602;  // @4_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_48b5b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(3598));  // @7_48b5b0
  ecx = edx = 0;  // @8_48b5b0
  PV[0] = (u32)(eax);  // @9_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_48b5b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6872776));  // @11_48b5b0
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
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @52_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_48b5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @54_48b5b0
  ecx = edx = 0;  // @55_48b5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @56_48b5b0
  L48b67c:;
  eax = esi;  // @58_48b5b0
  SEH_LEAVE();  // @59_48b5b0
  return eax;  // @60_48b5b0
}
PCREG(48b5b0, lifted_48b5b0);

extern "C" u32 THISCALL lifted_42d820(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664efc);  // @h_42d820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_42d820
  ecx = (u32)(EBP - 532);  // @2_42d820
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_42d820
  PV[0] = (u32)(ecx);  // @4_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @5_42d820
  ecx = esi;  // @6_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @7_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @8_42d820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789660), PV[0]);  // @9_42d820
  ecx = edx = 0;  // @10_42d820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42d8f5;  // @11_42d820
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @12_42d820
  ecx = (u32)(EBP - 272);  // @13_42d820
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @14_42d820
  ecx = edx = 0;  // @15_42d820
  ecx = (u32)(EBP - 144);  // @16_42d820
  reg.state = (s32)((u32)(0));  // @17_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789668));  // @18_42d820
  ecx = edx = 0;  // @19_42d820
  eax = (u32)(EBP - 144);  // @20_42d820
  reg.state = (s32)((u32)(1));  // @21_42d820
  PV[2] = (u32)(eax);  // @22_42d820
  eax = (u32)(EBP - 528);  // @23_42d820
  PV[3] = (u32)(eax);  // @24_42d820
  ecx = (u32)(esi + 291);  // @25_42d820
  eax = ext_4cc1e0_thiscall3(ecx, PV[3], PV[2]);  // @26_42d820
  ecx = edx = 0;  // @27_42d820
  ecx = (u32)(EBP - 272);  // @28_42d820
  reg.state = (s32)((u32)(2));  // @29_42d820
  PV[4] = (u32)(ecx);  // @30_42d820
  PV[5] = (u32)(edi);  // @31_42d820
  ecx = eax;  // @32_42d820
  eax = ext_4cc1e0_thiscall3(ecx, PV[5], PV[4]);  // @33_42d820
  ecx = edx = 0;  // @34_42d820
  ecx = (u32)(EBP - 528);  // @35_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @36_42d820
  ecx = edx = 0;  // @37_42d820
  ecx = (u32)(EBP - 144);  // @38_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @39_42d820
  ecx = edx = 0;  // @40_42d820
  ecx = (u32)(EBP - 272);  // @41_42d820
  goto L42d925;  // @42_42d820
  L42d8f5:;
  ecx = (u32)(EBP - 400);  // @44_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789660));  // @45_42d820
  ecx = edx = 0;  // @46_42d820
  eax = (u32)(EBP - 400);  // @47_42d820
  reg.state = (s32)((u32)(3));  // @48_42d820
  PV[6] = (u32)(eax);  // @49_42d820
  PV[7] = (u32)(edi);  // @50_42d820
  ecx = (u32)(esi + 291);  // @51_42d820
  eax = ext_4cc1e0_thiscall3(ecx, PV[7], PV[6]);  // @52_42d820
  ecx = edx = 0;  // @53_42d820
  ecx = (u32)(EBP - 400);  // @54_42d820
  L42d925:;
  eax = ext_4cbec0_thiscall1(ecx);  // @56_42d820
  ecx = edx = 0;  // @57_42d820
  eax = edi;  // @58_42d820
  SEH_LEAVE();  // @59_42d820
  ext_633654(G(u32, 0x6f5630));  // @60_42d820
  return eax;  // @61_42d820
}
PCREG(42d820, lifted_42d820);

extern "C" u32 THISCALL lifted_4d1390(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6692df);  // @h_4d1390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(edi);  // @41_4d1390
  PV[1] = (u32)(esi);  // @42_4d1390
  ecx = eax;  // @43_4d1390
  eax = ext_4d1390_thiscall3(ecx, PV[1], PV[0]);  // @44_4d1390
  ecx = edx = 0;  // @45_4d1390
  L4d1469:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @47_4d1390
  reg.state = (s32)((u32)(4294967295));  // @48_4d1390
  if ((esi & esi) != 0) goto L4d1448;  // @49_4d1390
  L4d1477:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @51_4d1390
  ecx = ebx;  // @52_4d1390
  PV[2] = (u32)(edi);  // @53_4d1390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[2]);  // @54_4d1390
  ecx = edx = 0;  // @55_4d1390
  eax = edi;  // @56_4d1390
  SEH_LEAVE();  // @57_4d1390
  return eax;  // @58_4d1390
}
PCREG(4d1390, lifted_4d1390);

extern "C" u32 THISCALL lifted_4553d0(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_4553d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 221), sizeof v); (u32)v; });  // @1_4553d0
  { u32 v = (u32)((u32)(6826180)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4553d0
  if ((eax & eax) == 0) goto L455411;  // @3_4553d0
  PV[0] = (u32)(eax);  // @4_4553d0
  eax = ext_634273_cdecl2(PV[0], (u32)(4));  // @5_4553d0
  ecx = edx = 0;  // @6_4553d0
  L455411:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; });  // @8_4553d0
  if ((eax & eax) == 0) goto L455423;  // @9_4553d0
  PV[1] = (u32)(eax);  // @10_4553d0
  eax = ext_634273_cdecl2(PV[1], (u32)(1));  // @11_4553d0
  ecx = edx = 0;  // @12_4553d0
  L455423:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; });  // @14_4553d0
  if ((eax & eax) == 0) goto L455435;  // @15_4553d0
  PV[2] = (u32)(eax);  // @16_4553d0
  eax = ext_634273_cdecl2(PV[2], (u32)(1));  // @17_4553d0
  ecx = edx = 0;  // @18_4553d0
  L455435:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4553d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @23_4553d0
  ecx = edx = 0;  // @24_4553d0
  ecx = (u32)(EBP - 16);  // @25_4553d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_4553d0
  PV[3] = (u32)(ecx);  // @27_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_4553d0
  ecx = eax;  // @29_4553d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6827256), PV[3]);  // @30_4553d0
  ecx = edx = 0;  // @31_4553d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @32_4553d0
  if ((edx & edx) == 0) goto L4554a7;  // @33_4553d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @34_4553d0
  PV[4] = (u32)(edx);  // @35_4553d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4553d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[4]);  // @37_4553d0
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


extern "C" u32 THISCALL lifted_433220(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665580);  // @h_433220
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_433220
  ecx = (u32)(ebx + 200);  // @2_433220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_433220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @4_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 200), sizeof v); (u32)v; });  // @5_433220
  PV[0] = (u32)(edi);  // @6_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @7_433220
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @8_433220
  ecx = edx = 0;  // @9_433220
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L433288;  // @10_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 200), sizeof v); (u32)v; });  // @11_433220
  ecx = (u32)(ebx + 200);  // @12_433220
  PV[1] = (u32)(edi);  // @13_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[1]);  // @14_433220
  ecx = edx = 0;  // @15_433220
  L433288:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 172), sizeof v); (u32)v; });  // @17_433220
  ecx = (u32)(ebx + 172);  // @18_433220
  PV[2] = (u32)(edi);  // @19_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[2]);  // @20_433220
  ecx = edx = 0;  // @21_433220
  esi = eax;  // @22_433220
  if ((esi & esi) != 0) goto L4332f3;  // @23_433220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 172), sizeof v); (u32)v; });  // @24_433220
  ecx = (u32)(ebx + 172);  // @25_433220
  PV[3] = (u32)(edi);  // @26_433220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[3]);  // @27_433220
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
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @49_433220
  ecx = (u32)(EBP - 144);  // @50_433220
  eax = ext_4cbe80_thiscall2(ecx, PV[4]);  // @51_433220
  ecx = edx = 0;  // @52_433220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_433220
  eax = (u32)(EBP - 144);  // @54_433220
  PV[5] = (u32)(eax);  // @55_433220
  reg.state = (s32)((u32)(1));  // @56_433220
  eax = ext_4cbee0_thiscall2(ecx, PV[5]);  // @57_433220
  ecx = edx = 0;  // @58_433220
  ecx = (u32)(EBP - 144);  // @59_433220
  eax = ext_4cbec0_thiscall1(ecx);  // @60_433220
  ecx = edx = 0;  // @61_433220
  SEH_LEAVE();  // @62_433220
  ext_633654(G(u32, 0x6f5630));  // @63_433220
  return eax;  // @64_433220
}
PCREG(433220, lifted_433220);

extern "C" u32 THISCALL lifted_4cb9c0(u32 ecx_in) {
  SEH_ENTER(0x66606f);  // @h_4cb9c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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
  PV[0] = (u32)(esi);  // @30_4cb9c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4cb9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, PV[0]);  // @32_4cb9c0
  ecx = edx = 0;  // @33_4cb9c0
  if ((eax & eax) == 0) goto L4cba79;  // @34_4cb9c0
  ecx = 0;  // @35_4cb9c0
  goto L4cbaaa;  // @36_4cb9c0
  L4cba79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @38_4cb9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @39_4cb9c0
  if ((eax & eax) == 0) goto L4cba98;  // @40_4cb9c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L4cba98;  // @41_4cb9c0
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L4cba98;  // @42_4cb9c0
  ecx = esi;  // @43_4cb9c0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @44_4cb9c0
  ecx = edx = 0;  // @45_4cb9c0
  ecx = eax;  // @46_4cb9c0
  goto L4cbaaa;  // @47_4cb9c0
  L4cba98:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cbaa7;  // @49_4cb9c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4cb9c0
  PV[1] = (u32)(esi);  // @51_4cb9c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[1]);  // @52_4cb9c0
  ecx = edx = 0;  // @53_4cb9c0
  L4cbaa7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @55_4cb9c0
  L4cbaaa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @57_4cb9c0
  PV[2] = (u32)(ecx);  // @58_4cb9c0
  ecx = edi;  // @59_4cb9c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6903412), PV[2], (u32)(4));  // @60_4cb9c0
  ecx = edx = 0;  // @61_4cb9c0
  SEH_LEAVE();  // @62_4cb9c0
  return eax;  // @63_4cb9c0
}
PCREG(4cb9c0, lifted_4cb9c0);


