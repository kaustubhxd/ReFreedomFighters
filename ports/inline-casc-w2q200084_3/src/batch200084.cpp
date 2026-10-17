// batch200084.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 STDCALL ext_65a630_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_65a630");
extern "C" u32 STDCALL ext_65ae70_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_65ae70");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_440220_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_440220");
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_49fa80_thiscall2(u32, u32) __asm__("ext_49fa80");
extern "C" u32 THISCALL ext_4a1850_thiscall2(u32, u32) __asm__("ext_4a1850");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1590_thiscall1(u32) __asm__("ext_4e1590");
extern "C" u32 THISCALL ext_56ad00_thiscall2(u32, u32) __asm__("ext_56ad00");
extern "C" u32 THISCALL ext_5c2cb0_thiscall1(u32) __asm__("ext_5c2cb0");
extern "C" u32 THISCALL ext_5c2e10_thiscall2(u32, u32) __asm__("ext_5c2e10");
extern "C" u32 THISCALL ext_5c2ec0_thiscall1(u32) __asm__("ext_5c2ec0");
extern "C" u32 THISCALL ext_5c2f30_thiscall1(u32) __asm__("ext_5c2f30");
extern "C" u32 THISCALL ext_5c2f90_thiscall1(u32) __asm__("ext_5c2f90");
extern "C" u32 THISCALL ext_638f20_thiscall2(u32, u32) __asm__("ext_638f20");
extern "C" u32 THISCALL ext_658d30_thiscall1(u32) __asm__("ext_658d30");
extern "C" u32 THISCALL ext_65b550_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_65b550");
extern "C" u32 ext_41e290_cdecl2(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_42ab62_cdecl3(...) __asm__("ext_42ab62");
extern "C" u32 ext_45c510_cdecl1(...) __asm__("ext_45c510");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_63a700_cdecl1(...) __asm__("ext_63a700");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_49ff20(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xffff);  // @0_49ff20
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2224), sizeof v); (u32)v; })) goto L49ff3e;  // @1_49ff20
  eax = ext_49fa80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @2_49ff20
  ecx = edx = 0;  // @3_49ff20
  eax = 0;  // @4_49ff20
  return eax;  // @5_49ff20
  L49ff3e:;
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2226), sizeof v); (u32)v; })) goto L49ff4f;  // @7_49ff20
  eax = ext_4a1850_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @8_49ff20
  ecx = edx = 0;  // @9_49ff20
  L49ff4f:;
  eax = 0;  // @11_49ff20
  return eax;  // @12_49ff20
}
PCREG(49ff20, lifted_49ff20);

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

extern "C" u32 THISCALL lifted_4f1520(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = (u32)(32768);  // @0_4f1520
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L4f154c;  // @1_4f1520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4f1520
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4f1520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 136), sizeof v); (u32)v; });  // @4_4f1520
  eax = ((u32(STDCALL *)(u32, u32))(eax))((u32)(esi), (u32)(esi));  // @5_4f1520
  ecx = edx = 0;  // @6_4f1520
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4f1545;  // @7_4f1520
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @8_4f1520
  L4f1545:;
  eax = 0;  // @10_4f1520
  return eax;  // @11_4f1520
  L4f154c:;
  eax = 0;  // @13_4f1520
  return eax;  // @14_4f1520
}
PCREG(4f1520, lifted_4f1520);

extern "C" u32 THISCALL lifted_56a7e0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_56a7e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 453), sizeof v); (u32)v; }) != (u32)(4)) goto L56a838;  // @1_56a7e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_56a7e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_56a7e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_56a7e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(esi));  // @5_56a7e0
  ecx = edx = 0;  // @6_56a7e0
  esi = eax;  // @7_56a7e0
  if ((esi & esi) == 0) goto L56a830;  // @8_56a7e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_56a7e0
  ecx = esi;  // @10_56a7e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @11_56a7e0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(1048627));  // @12_56a7e0
  ecx = edx = 0;  // @13_56a7e0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L56a830;  // @14_56a7e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_56a7e0
  ecx = esi;  // @16_56a7e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 784)))(ecx);  // @17_56a7e0
  ecx = edx = 0;  // @18_56a7e0
  ecx = edi;  // @19_56a7e0
  eax = ext_56ad00_thiscall2(ecx, (u32)(eax));  // @20_56a7e0
  ecx = edx = 0;  // @21_56a7e0
  L56a830:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @23_56a7e0
  return eax;  // @24_56a7e0
  L56a838:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @26_56a7e0
  return eax;  // @27_56a7e0
}
PCREG(56a7e0, lifted_56a7e0);

extern "C" u32 THISCALL lifted_63ea50(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63ea50
  edx = ecx;  // @1_63ea50
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @2_63ea50
  if (((ecx & 0xffff) & (ecx & 0xffff)) != 0) goto L63ea67;  // @3_63ea50
  eax = 0;  // @4_63ea50
  return eax;  // @5_63ea50
  L63ea67:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; });  // @7_63ea50
  ecx = (ecx & (u32)(4095));  // @8_63ea50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @9_63ea50
  eax = ext_658d30_thiscall1(ecx);  // @10_63ea50
  ecx = edx = 0;  // @11_63ea50
  return eax;  // @12_63ea50
}
PCREG(63ea50, lifted_63ea50);

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

extern "C" u32 THISCALL lifted_63b660(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_63b660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_63b660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_63b660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @3_63b660
  ecx = edx = 0;  // @4_63b660
  if ((eax & eax) != 0) goto L63b67a;  // @5_63b660
  return eax;  // @6_63b660
  L63b67a:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @8_63b660
  return eax;  // @9_63b660
}
PCREG(63b660, lifted_63b660);

extern "C" u32 THISCALL lifted_5c2d90(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = esi;  // @8_5c2d90
  eax = ext_5c2e10_thiscall2(ecx, (u32)(eax));  // @9_5c2d90
  ecx = edx = 0;  // @10_5c2d90
  if ((eax & eax) == 0) goto L5c2deb;  // @11_5c2d90
  ecx = eax;  // @12_5c2d90
  eax = ext_5c2cb0_thiscall1(ecx);  // @13_5c2d90
  ecx = edx = 0;  // @14_5c2d90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @15_5c2d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @16_5c2d90
  if (eax == (u32)(-1)) goto L5c2deb;  // @17_5c2d90
  ecx = (u32)(eax*8);  // @18_5c2d90
  ecx = (ecx - eax);  // @19_5c2d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ecx*2 + 8), sizeof v); (u32)v; });  // @20_5c2d90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @21_5c2d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @22_5c2d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_5c2d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @24_5c2d90
  ecx = esi;  // @25_5c2d90
  eax = ext_5c2f30_thiscall1(ecx);  // @26_5c2d90
  ecx = edx = 0;  // @27_5c2d90
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @28_5c2d90
  return eax;  // @29_5c2d90
  L5c2deb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_5c2d90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @32_5c2d90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @33_5c2d90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @34_5c2d90
  return eax;  // @35_5c2d90
}
PCREG(5c2d90, lifted_5c2d90);

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

extern "C" u32 THISCALL lifted_49e260(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_49e260
  eax = 0;  // @1_49e260
  edx = 0;  // @2_49e260
  edi = ecx;  // @3_49e260
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(47)) goto L49e280;  // @4_49e260
  L49e273:;
  eax = (eax + 1);  // @6_49e260
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) == (u32)(47)) goto L49e273;  // @7_49e260
  L49e280:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; })) & 0xff);  // @9_49e260
  if ((ecx & 0xff) != (u32)(47)) goto L49e2aa;  // @10_49e260
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi + edx + 4), &v, sizeof v); }  // @11_49e260
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi + edx + 260), &v, sizeof v); }  // @12_49e260
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax + 1), sizeof v); (u32)v; }) != (ecx & 0xff)) goto L49e2b5;  // @13_49e260
  L49e2a0:;
  eax = (eax + 1);  // @15_49e260
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax + 1), sizeof v); (u32)v; }) == (u32)(47)) goto L49e2a0;  // @16_49e260
  goto L49e2b5;  // @17_49e260
  L49e2aa:;
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi + edx + 260), &v, sizeof v); }  // @19_49e260
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi + edx + 4), &v, sizeof v); }  // @20_49e260
  L49e2b5:;
  eax = (eax + 1);  // @22_49e260
  edx = (edx + 1);  // @23_49e260
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(0)) goto L49e280;  // @24_49e260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6877200), sizeof v); (u32)v; });  // @25_49e260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + edi + 260), &v, sizeof v); }  // @26_49e260
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6877204), sizeof v); (u32)v; })) & 0xff);  // @27_49e260
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + edi + 264), &v, sizeof v); }  // @28_49e260
  return eax;  // @29_49e260
}
PCREG(49e260, lifted_49e260);

extern "C" u32 THISCALL lifted_4f9e90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ecx;  // @0_4f9e90
  eax = ext_440220_thiscall6(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }));  // @1_4f9e90
  ecx = edx = 0;  // @2_4f9e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 143), sizeof v); (u32)v; });  // @3_4f9e90
  edx = eax;  // @4_4f9e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 143), &v, sizeof v); }  // @5_4f9e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 147), sizeof v); (u32)v; });  // @6_4f9e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 147), &v, sizeof v); }  // @7_4f9e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 151), sizeof v); (u32)v; });  // @8_4f9e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 151), &v, sizeof v); }  // @9_4f9e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 155), sizeof v); (u32)v; });  // @10_4f9e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 155), &v, sizeof v); }  // @11_4f9e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 167), sizeof v); (u32)v; });  // @12_4f9e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 167), &v, sizeof v); }  // @13_4f9e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 171), sizeof v); (u32)v; });  // @14_4f9e90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 171), &v, sizeof v); }  // @15_4f9e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 175), sizeof v); (u32)v; });  // @16_4f9e90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 175), &v, sizeof v); }  // @17_4f9e90
  eax = edx;  // @18_4f9e90
  return eax;  // @19_4f9e90
}
PCREG(4f9e90, lifted_4f9e90);

extern "C" u32 STDCALL lifted_54f110(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_54f110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_54f110
  if (edx == esi) goto L54f147;  // @2_54f110
  if ((s32)edx <= (s32)esi) goto L54f133;  // @3_54f110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_54f110
  eax = edx;  // @5_54f110
  eax = (eax - esi);  // @6_54f110
  if ((s32)eax <= (s32)ecx) goto L54f147;  // @7_54f110
  eax = (u32)(esi + ecx);  // @8_54f110
  return eax;  // @9_54f110
  L54f133:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @11_54f110
  ecx = esi;  // @12_54f110
  ecx = (ecx - edx);  // @13_54f110
  if ((s32)ecx <= (s32)eax) goto L54f147;  // @14_54f110
  esi = (esi - eax);  // @15_54f110
  eax = esi;  // @16_54f110
  return eax;  // @17_54f110
  L54f147:;
  eax = edx;  // @19_54f110
  return eax;  // @20_54f110
}
PCREG(54f110, lifted_54f110);

extern "C" u32 THISCALL lifted_5dbe30(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xffff);  // @0_5dbe30
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422852), sizeof v); (u32)v; })) goto L5dbe45;  // @1_5dbe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_5dbe30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @3_5dbe30
  L5dbe45:;
  eax = 0;  // @5_5dbe30
  return eax;  // @6_5dbe30
}
PCREG(5dbe30, lifted_5dbe30);

extern "C" u32 lifted_631840(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ext_63a700_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @0_631840
  ecx = edx = 0;  // @1_631840
  return eax;  // @2_631840
}
PCREG(631840, lifted_631840);

extern "C" u32 THISCALL lifted_639240(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_639240
  eax = ext_638f20_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @1_639240
  ecx = edx = 0;  // @2_639240
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3_639240
  eax = (eax + (u32)(4));  // @4_639240
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @5_639240
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 50), &v, sizeof v); }  // @6_639240
  eax = (u32)(eax + edx*4);  // @7_639240
  return eax;  // @8_639240
}
PCREG(639240, lifted_639240);

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

extern "C" u32 STDCALL lifted_5d92e0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d92e0
  ecx = esi;  // @1_5d92e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_5d92e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(edi));  // @3_5d92e0
  ecx = edx = 0;  // @4_5d92e0
  edi = eax;  // @5_5d92e0
  ecx = edi;  // @6_5d92e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_5d92e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; }) | (u32)(1024))); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @8_5d92e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 604)))(ecx, (u32)(7037720), (u32)(0));  // @9_5d92e0
  ecx = edx = 0;  // @10_5d92e0
  if ((eax & eax) == 0) goto L5d932e;  // @11_5d92e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_5d92e0
  ecx = (u32)(EBP - 8);  // @13_5d92e0
  ecx = eax;  // @14_5d92e0
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @15_5d92e0
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @16_5d92e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 600)))(ecx, (u32)(ecx), (u32)(0));  // @17_5d92e0
  ecx = edx = 0;  // @18_5d92e0
  L5d932e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_5d92e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_5d92e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5d92e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edi));  // @23_5d92e0
  ecx = edx = 0;  // @24_5d92e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_5d92e0
  ecx = esi;  // @26_5d92e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }) | (u32)(2162688))); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @27_5d92e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 636)))(ecx, (u32)(eax));  // @28_5d92e0
  ecx = edx = 0;  // @29_5d92e0
  return eax;  // @30_5d92e0
}
PCREG(5d92e0, lifted_5d92e0);

extern "C" u32 THISCALL lifted_603e40(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @0_603e40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_603e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @2_603e40
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) goto L603e6d;  // @3_603e40
  eax = ext_42ab62_cdecl3((u32)(7047604), (u32)(edi), (u32)(esi));  // @4_603e40
  ecx = edx = 0;  // @5_603e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @6_603e40
  if ((eax & eax) == 0) goto L603e6c;  // @7_603e40
  eax = ((u32(STDCALL *)(void))(eax))();  // @8_603e40
  ecx = edx = 0;  // @9_603e40
  goto L603e6d;  // @10_603e40
  L603e6c:;
  __builtin_trap();  // @12_603e40
  L603e6d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @14_603e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_603e40
  esi = (u32)(eax + ecx*8);  // @16_603e40
  eax = (u32)(ecx + 1);  // @17_603e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @18_603e40
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @19_603e40
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L603e8d;  // @20_603e40
  if ((eax & 0xff) != (u32)(4)) goto L603e9b;  // @21_603e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_603e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_603e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @24_603e40
  ecx = edx = 0;  // @25_603e40
  L603e8d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @27_603e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_603e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @29_603e40
  ecx = edx = 0;  // @30_603e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @31_603e40
  { u8 v = (u8)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @32_603e40
  L603e9b:;
  eax = esi;  // @34_603e40
  return eax;  // @35_603e40
}
PCREG(603e40, lifted_603e40);

extern "C" u32 THISCALL lifted_5d88d0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5d88d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @1_5d88d0
  { u32 v = (u32)((u32)(7036872)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5d88d0
  if ((eax & eax) == 0) goto L5d88ec;  // @3_5d88d0
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @4_5d88d0
  ecx = edx = 0;  // @5_5d88d0
  L5d88ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @7_5d88d0
  if ((eax & eax) == 0) goto L5d88fe;  // @8_5d88d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(8));  // @9_5d88d0
  ecx = edx = 0;  // @10_5d88d0
  L5d88fe:;
  ecx = esi;  // @12_5d88d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @13_5d88d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @14_5d88d0
  eax = ext_43de70_thiscall1(ecx);  // @15_5d88d0
  ecx = edx = 0;  // @16_5d88d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_5d88d0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L5d8939;  // @18_5d88d0
  if (((eax & 0xff) & (u32)(4)) != 0) goto L5d892e;  // @19_5d88d0
  eax = ext_45c510_cdecl1((u32)(esi));  // @20_5d88d0
  ecx = edx = 0;  // @21_5d88d0
  eax = esi;  // @22_5d88d0
  return eax;  // @23_5d88d0
  L5d892e:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(72));  // @25_5d88d0
  ecx = edx = 0;  // @26_5d88d0
  L5d8939:;
  eax = esi;  // @28_5d88d0
  return eax;  // @29_5d88d0
}
PCREG(5d88d0, lifted_5d88d0);

extern "C" u32 THISCALL lifted_5d8cf0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d8cf0
  esi = ecx;  // @1_5d8cf0
  eax = ext_610100_stdcall1((u32)(edi));  // @2_5d8cf0
  ecx = edx = 0;  // @3_5d8cf0
  eax = (u32)(esi + 40);  // @4_5d8cf0
  ecx = edi;  // @5_5d8cf0
  eax = ext_4e12e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @6_5d8cf0
  ecx = edx = 0;  // @7_5d8cf0
  eax = (u32)(esi + 44);  // @8_5d8cf0
  ecx = edi;  // @9_5d8cf0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @10_5d8cf0
  ecx = edx = 0;  // @11_5d8cf0
  eax = (u32)(esi + 48);  // @12_5d8cf0
  ecx = edi;  // @13_5d8cf0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @14_5d8cf0
  ecx = edx = 0;  // @15_5d8cf0
  eax = (u32)(esi + 60);  // @16_5d8cf0
  ecx = edi;  // @17_5d8cf0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @18_5d8cf0
  ecx = edx = 0;  // @19_5d8cf0
  eax = (u32)(esi + 64);  // @20_5d8cf0
  ecx = edi;  // @21_5d8cf0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @22_5d8cf0
  ecx = edx = 0;  // @23_5d8cf0
  eax = (u32)(esi + 56);  // @24_5d8cf0
  ecx = edi;  // @25_5d8cf0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @26_5d8cf0
  ecx = edx = 0;  // @27_5d8cf0
  return eax;  // @28_5d8cf0
}
PCREG(5d8cf0, lifted_5d8cf0);

extern "C" u32 THISCALL lifted_5c33a0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5c33a0
  edi = ecx;  // @1_5c33a0
  ecx = esi;  // @2_5c33a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_5c33a0
  eax = (u32)(edi + 276);  // @4_5c33a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_5c33a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax), (u32)(edi));  // @6_5c33a0
  ecx = edx = 0;  // @7_5c33a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_5c33a0
  eax = (u32)(edi + 277);  // @9_5c33a0
  ecx = esi;  // @10_5c33a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @11_5c33a0
  ecx = edx = 0;  // @12_5c33a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_5c33a0
  eax = (u32)(edi + 281);  // @14_5c33a0
  ecx = esi;  // @15_5c33a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @16_5c33a0
  ecx = edx = 0;  // @17_5c33a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_5c33a0
  eax = (u32)(edi + 285);  // @19_5c33a0
  ecx = esi;  // @20_5c33a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @21_5c33a0
  ecx = edx = 0;  // @22_5c33a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_5c33a0
  eax = (u32)(edi + 289);  // @24_5c33a0
  ecx = esi;  // @25_5c33a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @26_5c33a0
  ecx = edx = 0;  // @27_5c33a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_5c33a0
  eax = (u32)(edi + 293);  // @29_5c33a0
  ecx = esi;  // @30_5c33a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @31_5c33a0
  ecx = edx = 0;  // @32_5c33a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @33_5c33a0
  return eax;  // @34_5c33a0
}
PCREG(5c33a0, lifted_5c33a0);

extern "C" u32 THISCALL lifted_5d8ee0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d8ee0
  esi = ecx;  // @1_5d8ee0
  eax = ext_45f3c0_thiscall2(ecx, (u32)(edi));  // @2_5d8ee0
  ecx = edx = 0;  // @3_5d8ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_5d8ee0
  eax = (u32)(esi + 40);  // @5_5d8ee0
  ecx = edi;  // @6_5d8ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @7_5d8ee0
  ecx = edx = 0;  // @8_5d8ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @9_5d8ee0
  eax = (u32)(esi + 44);  // @10_5d8ee0
  ecx = edi;  // @11_5d8ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @12_5d8ee0
  ecx = edx = 0;  // @13_5d8ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_5d8ee0
  eax = (u32)(esi + 48);  // @15_5d8ee0
  ecx = edi;  // @16_5d8ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @17_5d8ee0
  ecx = edx = 0;  // @18_5d8ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_5d8ee0
  eax = (u32)(esi + 60);  // @20_5d8ee0
  ecx = edi;  // @21_5d8ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @22_5d8ee0
  ecx = edx = 0;  // @23_5d8ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_5d8ee0
  eax = (u32)(esi + 64);  // @25_5d8ee0
  ecx = edi;  // @26_5d8ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @27_5d8ee0
  ecx = edx = 0;  // @28_5d8ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_5d8ee0
  eax = (u32)(esi + 56);  // @30_5d8ee0
  ecx = edi;  // @31_5d8ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @32_5d8ee0
  ecx = edx = 0;  // @33_5d8ee0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @34_5d8ee0
  return eax;  // @35_5d8ee0
}
PCREG(5d8ee0, lifted_5d8ee0);

extern "C" u32 FASTCALL lifted_4309b0(u32 ecx_in, u32 edx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4309b0
  esi = (esi - (u32)(4));  // @1_4309b0
  if (0 && esi) goto L4309d1;  // @2_4309b0
  L4309c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4309b0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) goto L4309d6;  // @5_4309b0
  ecx = (ecx + (u32)(4));  // @6_4309b0
  edx = (edx + (u32)(4));  // @7_4309b0
  esi = (esi - (u32)(4));  // @8_4309b0
  if (1 || esi) goto L4309c0;  // @9_4309b0
  L4309d1:;
  if (esi == (u32)(-4)) goto L430a0d;  // @11_4309b0
  L4309d6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @13_4309b0
  if ((eax & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) goto L430a03;  // @14_4309b0
  if (esi == (u32)(-3)) goto L430a0d;  // @15_4309b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @16_4309b0
  if ((eax & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) goto L430a03;  // @17_4309b0
  if (esi == (u32)(-2)) goto L430a0d;  // @18_4309b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; })) & 0xff);  // @19_4309b0
  if ((eax & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; })) goto L430a03;  // @20_4309b0
  if (esi == (u32)(-1)) goto L430a0d;  // @21_4309b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 3), sizeof v); (u32)v; })) & 0xff);  // @22_4309b0
  if ((eax & 0xff) == ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 3), sizeof v); (u32)v; })) goto L430a0d;  // @23_4309b0
  L430a03:;
  eax = (0u - (u32)((eax & 0xff) < ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 3), sizeof v); (u32)v; })));  // @25_4309b0
  eax = (eax | (u32)(1));  // @26_4309b0
  return eax;  // @27_4309b0
  L430a0d:;
  eax = 0;  // @29_4309b0
  return eax;  // @30_4309b0
}
PCREG(4309b0, lifted_4309b0);

extern "C" u32 THISCALL lifted_62b290(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62b290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_62b290
  if (eax == edx) goto L62b2ce;  // @2_62b290
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3_62b290
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_62b290
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi + 76), sizeof v); (u32)v; })) & 0xff);  // @5_62b290
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) - (u32)(24))) & 0xff);  // @6_62b290
  if ((ecx & 0xff) > (u32)(1)) goto L62b2e4;  // @7_62b290
  eax = (eax + 1);  // @8_62b290
  if (eax == edx) goto L62b2ce;  // @9_62b290
  L62b2b5:;
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @11_62b290
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi + 76), sizeof v); (u32)v; })) & 0xff);  // @12_62b290
  if ((ecx & 0xff) == (u32)(18)) goto L62b2d4;  // @13_62b290
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) - (u32)(24))) & 0xff);  // @14_62b290
  if ((ecx & 0xff) > (u32)(1)) goto L62b2e4;  // @15_62b290
  eax = (eax + 1);  // @16_62b290
  if (eax != edx) goto L62b2b5;  // @17_62b290
  L62b2ce:;
  eax = (eax | (u32)(4294967295));  // @19_62b290
  return eax;  // @20_62b290
  L62b2d4:;
  ecx = (u32)(eax + 1);  // @22_62b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @23_62b290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @24_62b290
  eax = (u32)(10);  // @25_62b290
  return eax;  // @26_62b290
  L62b2e4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @28_62b290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @29_62b290
  eax = 0;  // @30_62b290
  return eax;  // @31_62b290
}
PCREG(62b290, lifted_62b290);

extern "C" u32 THISCALL lifted_65bc00(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_65bc00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bc00
  if ((s32)((ecx & 0xff) & (ecx & 0xff)) < 0) goto L65bc22;  // @3_65bc00
  ecx = ebx;  // @4_65bc00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @5_65bc00
  ecx = edx = 0;  // @6_65bc00
  return eax;  // @7_65bc00
  L65bc22:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_65bc00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @10_65bc00
  ecx = ebx;  // @11_65bc00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(esi), (u32)(edi), (u32)(ecx), (u32)(edi), (u32)(esi));  // @12_65bc00
  ecx = edx = 0;  // @13_65bc00
  ecx = ebx;  // @14_65bc00
  eax = ext_65a630_stdcall5((u32)(esi), (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }));  // @15_65bc00
  ecx = edx = 0;  // @16_65bc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_65bc00
  ecx = ebx;  // @18_65bc00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), (u32)(edi));  // @19_65bc00
  ecx = edx = 0;  // @20_65bc00
  return eax;  // @21_65bc00
}
PCREG(65bc00, lifted_65bc00);

extern "C" u32 THISCALL lifted_65bc60(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_65bc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bc60
  if ((s32)((ecx & 0xff) & (ecx & 0xff)) < 0) goto L65bc82;  // @3_65bc60
  ecx = ebx;  // @4_65bc60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @5_65bc60
  ecx = edx = 0;  // @6_65bc60
  return eax;  // @7_65bc60
  L65bc82:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_65bc60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @10_65bc60
  ecx = ebx;  // @11_65bc60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(esi), (u32)(edi), (u32)(ecx), (u32)(edi), (u32)(esi));  // @12_65bc60
  ecx = edx = 0;  // @13_65bc60
  ecx = ebx;  // @14_65bc60
  eax = ext_65a630_stdcall5((u32)(esi), (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }));  // @15_65bc60
  ecx = edx = 0;  // @16_65bc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_65bc60
  ecx = ebx;  // @18_65bc60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), (u32)(edi));  // @19_65bc60
  ecx = edx = 0;  // @20_65bc60
  return eax;  // @21_65bc60
}
PCREG(65bc60, lifted_65bc60);

extern "C" u32 THISCALL lifted_65bcc0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_65bcc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bcc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bcc0
  if ((s32)((ecx & 0xff) & (ecx & 0xff)) < 0) goto L65bce2;  // @3_65bcc0
  ecx = ebx;  // @4_65bcc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @5_65bcc0
  ecx = edx = 0;  // @6_65bcc0
  return eax;  // @7_65bcc0
  L65bce2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_65bcc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @10_65bcc0
  ecx = ebx;  // @11_65bcc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(esi), (u32)(edi), (u32)(ecx), (u32)(edi), (u32)(esi));  // @12_65bcc0
  ecx = edx = 0;  // @13_65bcc0
  ecx = ebx;  // @14_65bcc0
  eax = ext_65ae70_stdcall5((u32)(esi), (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }));  // @15_65bcc0
  ecx = edx = 0;  // @16_65bcc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_65bcc0
  ecx = ebx;  // @18_65bcc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), (u32)(edi));  // @19_65bcc0
  ecx = edx = 0;  // @20_65bcc0
  return eax;  // @21_65bcc0
}
PCREG(65bcc0, lifted_65bcc0);

extern "C" u32 THISCALL lifted_65bd20(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_65bd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bd20
  if ((s32)((ecx & 0xff) & (ecx & 0xff)) < 0) goto L65bd42;  // @3_65bd20
  ecx = ebx;  // @4_65bd20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @5_65bd20
  ecx = edx = 0;  // @6_65bd20
  return eax;  // @7_65bd20
  L65bd42:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_65bd20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @10_65bd20
  ecx = ebx;  // @11_65bd20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(esi), (u32)(edi), (u32)(ecx), (u32)(edi), (u32)(esi));  // @12_65bd20
  ecx = edx = 0;  // @13_65bd20
  ecx = ebx;  // @14_65bd20
  eax = ext_65b550_thiscall6(ecx, (u32)(esi), (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }));  // @15_65bd20
  ecx = edx = 0;  // @16_65bd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_65bd20
  ecx = ebx;  // @18_65bd20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), (u32)(edi));  // @19_65bd20
  ecx = edx = 0;  // @20_65bd20
  return eax;  // @21_65bd20
}
PCREG(65bd20, lifted_65bd20);

extern "C" u32 FASTCALL lifted_62c7f0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_62c7f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_62c7f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L62c85b;  // @2_62c7f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_62c7f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_62c7f0
  L62c806:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @6_62c7f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) == eax) goto L62c859;  // @7_62c7f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_62c7f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_62c7f0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + eax*2 + 376), sizeof v); (u32)v; });  // @10_62c7f0
  if (((edx & 0xffff) & (edx & 0xffff)) != 0) goto L62c845;  // @11_62c7f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 368), sizeof v); (u32)v; });  // @12_62c7f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 372), sizeof v); (u32)v; }), (u32)(ecx), (u32)(edi), (u32)(ebx), (u32)(esi));  // @13_62c7f0
  ecx = edx = 0;  // @14_62c7f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_62c7f0
  edx = (eax & 0xffff);  // @16_62c7f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_62c7f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @18_62c7f0
  eax = (eax + (u32)(-3));  // @19_62c7f0
  eax = (eax + ecx);  // @20_62c7f0
  goto L62c848;  // @21_62c7f0
  L62c845:;
  eax = (u32)(ecx + 1);  // @23_62c7f0
  L62c848:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @25_62c7f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_62c7f0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @27_62c7f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @28_62c7f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @29_62c7f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != eax) goto L62c806;  // @30_62c7f0
  L62c859:;
  L62c85b:;
  return eax;  // @33_62c7f0
}
PCREG(62c7f0, lifted_62c7f0);

extern "C" u32 THISCALL lifted_650b90(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_650b90
  edi = ecx;  // @1_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @2_650b90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_650b90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ebx), (u32)(edi), (u32)(esi));  // @7_650b90
  ecx = edx = 0;  // @8_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @9_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 40)))(ecx, (u32)(eax));  // @10_650b90
  ecx = edx = 0;  // @11_650b90
  if ((eax & eax) == 0) goto L650bfd;  // @12_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @13_650b90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ebx));  // @18_650b90
  ecx = edx = 0;  // @19_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @20_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 60)))(ecx, (u32)(eax));  // @21_650b90
  ecx = edx = 0;  // @22_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_650b90
  ecx = edi;  // @24_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 164)))(ecx, (u32)(0));  // @25_650b90
  ecx = edx = 0;  // @26_650b90
  if ((eax & eax) == 0) goto L650bfd;  // @27_650b90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_650b90
  ecx = eax;  // @29_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, (u32)(ebx));  // @30_650b90
  ecx = edx = 0;  // @31_650b90
  L650bfd:;
  return eax;  // @33_650b90
}
PCREG(650b90, lifted_650b90);

extern "C" u32 THISCALL lifted_46aa70(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_46aa70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 160), sizeof v); (u32)v; });  // @1_46aa70
  { u32 v = (u32)((u32)(6844204)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_46aa70
  if ((ecx & ecx) == 0) goto L46aa8c;  // @3_46aa70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_46aa70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_46aa70
  ecx = edx = 0;  // @6_46aa70
  L46aa8c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 199), sizeof v); (u32)v; });  // @8_46aa70
  if ((ecx & ecx) == 0) goto L46aa9c;  // @9_46aa70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_46aa70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_46aa70
  ecx = edx = 0;  // @12_46aa70
  L46aa9c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; });  // @14_46aa70
  { u32 v = (u32)((u32)(6842600)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @15_46aa70
  if ((ecx & ecx) == 0) goto L46aaaf;  // @16_46aa70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_46aa70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_46aa70
  ecx = edx = 0;  // @19_46aa70
  L46aaaf:;
  ecx = esi;  // @21_46aa70
  eax = ext_43ea20_thiscall1(ecx);  // @22_46aa70
  ecx = edx = 0;  // @23_46aa70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @24_46aa70
  if (((eax & 0xff) & (u32)(1)) == 0) goto L46aadf;  // @25_46aa70
  if (((eax & 0xff) & (u32)(4)) != 0) goto L46aad1;  // @26_46aa70
  eax = ext_45c510_cdecl1((u32)(esi));  // @27_46aa70
  ecx = edx = 0;  // @28_46aa70
  eax = esi;  // @29_46aa70
  return eax;  // @30_46aa70
  L46aad1:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(299));  // @32_46aa70
  ecx = edx = 0;  // @33_46aa70
  L46aadf:;
  eax = esi;  // @35_46aa70
  return eax;  // @36_46aa70
}
PCREG(46aa70, lifted_46aa70);

extern "C" u32 THISCALL lifted_5a4610(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5a4610
  edi = ecx;  // @1_5a4610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5a4610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5a4610
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(edi), (u32)(esi));  // @4_5a4610
  ecx = edx = 0;  // @5_5a4610
  esi = eax;  // @6_5a4610
  if ((esi & esi) == 0) goto L5a467f;  // @7_5a4610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_5a4610
  ecx = esi;  // @9_5a4610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @10_5a4610
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2099193));  // @11_5a4610
  ecx = edx = 0;  // @12_5a4610
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5a465a;  // @13_5a4610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_5a4610
  ecx = esi;  // @15_5a4610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @16_5a4610
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2098152));  // @17_5a4610
  ecx = edx = 0;  // @18_5a4610
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5a467f;  // @19_5a4610
  L5a465a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @21_5a4610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @22_5a4610
  eax = (eax - (u32)(3));  // @23_5a4610
  if (eax == (u32)(-1)) goto L5a467f;  // @24_5a4610
  if ((s32)eax > (s32)(u32)(6)) goto L5a467f;  // @25_5a4610
  eax = (u32)(eax + eax*8);  // @26_5a4610
  eax = (u32)(eax*2 + 97);  // @27_5a4610
  eax = (eax + edi);  // @28_5a4610
  return eax;  // @29_5a4610
  L5a467f:;
  eax = 0;  // @31_5a4610
  return eax;  // @32_5a4610
}
PCREG(5a4610, lifted_5a4610);

extern "C" u32 THISCALL lifted_4d4050(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4d4050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4307), sizeof v); (u32)v; });  // @1_4d4050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4023), sizeof v); (u32)v; });  // @2_4d4050
  if ((eax & eax) == 0) goto L4d4072;  // @3_4d4050
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @4_4d4050
  ecx = edx = 0;  // @5_4d4050
  L4d4072:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_4d4050
  ecx = esi;  // @8_4d4050
  edx = (u32)(ecx + 1);  // @9_4d4050
  L4d4080:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @11_4d4050
  ecx = (ecx + 1);  // @12_4d4050
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d4080;  // @13_4d4050
  ecx = (ecx - edx);  // @14_4d4050
  eax = (u32)(ecx + 1);  // @15_4d4050
  eax = ext_41e290_cdecl2((u32)(eax), (u32)(esi));  // @16_4d4050
  ecx = edx = 0;  // @17_4d4050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4307), sizeof v); (u32)v; });  // @18_4d4050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx*4 + 4023), &v, sizeof v); }  // @19_4d4050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4307), sizeof v); (u32)v; });  // @20_4d4050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4023), sizeof v); (u32)v; });  // @21_4d4050
  L4d40b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @23_4d4050
  esi = (u32)(esi + 1);  // @24_4d4050
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @25_4d4050
  ecx = (u32)(ecx + 1);  // @26_4d4050
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d40b0;  // @27_4d4050
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4307), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 4307), &v, sizeof v); }  // @28_4d4050
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4307), sizeof v); (u32)v; }) < (s32)(u32)(20)) goto L4d40d8;  // @29_4d4050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4307), &v, sizeof v); }  // @30_4d4050
  L4d40d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4307), sizeof v); (u32)v; });  // @32_4d4050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4311), &v, sizeof v); }  // @33_4d4050
  return eax;  // @34_4d4050
}
PCREG(4d4050, lifted_4d4050);

extern "C" u32 THISCALL lifted_4e0f60(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4e0f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_4e0f60
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @2_4e0f60
  if ((eax & 0xff) == (u32)(255)) goto L4e0f75;  // @3_4e0f60
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @4_4e0f60
  if ((eax & 0xff) == (u32)(7)) goto L4e0fae;  // @5_4e0f60
  L4e0f75:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @7_4e0f60
  if ((eax & 0xff) == (u32)(255)) goto L4e0f81;  // @8_4e0f60
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @9_4e0f60
  if ((eax & 0xff) == (u32)(12)) goto L4e0fae;  // @10_4e0f60
  L4e0f81:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @12_4e0f60
  if ((eax & 0xff) == (u32)(255)) goto L4e0f8d;  // @13_4e0f60
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @14_4e0f60
  if ((eax & 0xff) == (u32)(9)) goto L4e0fae;  // @15_4e0f60
  L4e0f8d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @17_4e0f60
  if ((eax & eax) == 0) goto L4e0f9a;  // @18_4e0f60
  eax = ((u32(STDCALL *)(void))(eax))();  // @19_4e0f60
  ecx = edx = 0;  // @20_4e0f60
  goto L4e0f9b;  // @21_4e0f60
  L4e0f9a:;
  __builtin_trap();  // @23_4e0f60
  L4e0f9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @25_4e0f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_4e0f60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 36)))((u32)(eax), (u32)(6910200));  // @27_4e0f60
  ecx = edx = 0;  // @28_4e0f60
  L4e0fae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_4e0f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @31_4e0f60
  ecx = (ecx + (u32)(5));  // @32_4e0f60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @33_4e0f60
  ecx = esi;  // @34_4e0f60
  eax = ext_4e1590_thiscall1(ecx);  // @35_4e0f60
  ecx = edx = 0;  // @36_4e0f60
  ecx = (u32)(eax + 1);  // @37_4e0f60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) + ecx)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @38_4e0f60
  eax = (eax + (u32)(-4));  // @39_4e0f60
  return eax;  // @40_4e0f60
}
PCREG(4e0f60, lifted_4e0f60);

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

extern "C" u32 THISCALL lifted_512940(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_512940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_512940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_512940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_512940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(edi), (u32)(esi), (u32)(ebx));  // @4_512940
  ecx = edx = 0;  // @5_512940
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_512940
  ecx = eax;  // @7_512940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_512940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 708)))(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @9_512940
  ecx = edx = 0;  // @10_512940
  ebx = eax;  // @11_512940
  ecx = ebx;  // @12_512940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_512940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 44)))(ecx);  // @14_512940
  ecx = edx = 0;  // @15_512940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_512940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @17_512940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_512940
  if ((edi & edi) != 0) edx = edi;  // @19_512940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @20_512940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_512940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(edx), (u32)(1));  // @22_512940
  ecx = edx = 0;  // @23_512940
  ecx = ebx;  // @24_512940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 752)))(ecx, (u32)(eax));  // @25_512940
  ecx = edx = 0;  // @26_512940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_512940
  ecx = ebx;  // @28_512940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @29_512940
  ecx = edx = 0;  // @30_512940
  eax = ebx;  // @31_512940
  return eax;  // @32_512940
}
PCREG(512940, lifted_512940);

extern "C" u32 THISCALL lifted_5b7c00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5b7c00
  edi = ecx;  // @1_5b7c00
  ecx = esi;  // @2_5b7c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_5b7c00
  eax = (u32)(edi + 4);  // @4_5b7c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax), (u32)(edi));  // @5_5b7c00
  ecx = edx = 0;  // @6_5b7c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_5b7c00
  eax = (u32)(edi + 8);  // @8_5b7c00
  ecx = esi;  // @9_5b7c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @10_5b7c00
  ecx = edx = 0;  // @11_5b7c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_5b7c00
  eax = (u32)(edi + 12);  // @13_5b7c00
  ecx = esi;  // @14_5b7c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(eax));  // @15_5b7c00
  ecx = edx = 0;  // @16_5b7c00
  ecx = (u32)(edi + 24);  // @17_5b7c00
  ecx = eax;  // @18_5b7c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_5b7c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(ecx));  // @20_5b7c00
  ecx = edx = 0;  // @21_5b7c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_5b7c00
  eax = (u32)(edi + 40);  // @23_5b7c00
  ecx = esi;  // @24_5b7c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @25_5b7c00
  ecx = edx = 0;  // @26_5b7c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_5b7c00
  eax = (u32)(edi + 36);  // @28_5b7c00
  ecx = esi;  // @29_5b7c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @30_5b7c00
  ecx = edx = 0;  // @31_5b7c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_5b7c00
  ecx = (u32)(EBP + 8);  // @33_5b7c00
  ecx = esi;  // @34_5b7c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @35_5b7c00
  ecx = edx = 0;  // @36_5b7c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @37_5b7c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @38_5b7c00
  return eax;  // @39_5b7c00
}
PCREG(5b7c00, lifted_5b7c00);

extern "C" u32 THISCALL lifted_5d4020(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d4020
  esi = ecx;  // @1_5d4020
  ecx = edi;  // @2_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }));  // @4_5d4020
  ecx = edx = 0;  // @5_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @6_5d4020
  ecx = edi;  // @7_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; }));  // @8_5d4020
  ecx = edx = 0;  // @9_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_5d4020
  ecx = edi;  // @11_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; }));  // @12_5d4020
  ecx = edx = 0;  // @13_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_5d4020
  ecx = edi;  // @15_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @16_5d4020
  ecx = edx = 0;  // @17_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_5d4020
  ecx = edi;  // @19_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; }));  // @20_5d4020
  ecx = edx = 0;  // @21_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_5d4020
  ecx = edi;  // @23_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; }));  // @24_5d4020
  ecx = edx = 0;  // @25_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_5d4020
  ecx = edi;  // @27_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; }));  // @28_5d4020
  ecx = edx = 0;  // @29_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_5d4020
  ecx = edi;  // @31_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }));  // @32_5d4020
  ecx = edx = 0;  // @33_5d4020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_5d4020
  ecx = edi;  // @35_5d4020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 116), sizeof v); (u32)v; }));  // @36_5d4020
  ecx = edx = 0;  // @37_5d4020
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @38_5d4020
  return eax;  // @39_5d4020
}
PCREG(5d4020, lifted_5d4020);

extern "C" u32 THISCALL lifted_63ead0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ecx;  // @0_63ead0
  ebx = 0;  // @1_63ead0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_63ead0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13320), sizeof v); (u32)v; }) == ebx) goto L63eb37;  // @3_63ead0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_63ead0
  L63eaf0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @6_63ead0
  if ((esi & esi) == 0) goto L63eb2c;  // @7_63ead0
  L63eaf7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @9_63ead0
  ecx = edi;  // @10_63ead0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(edi), (u32)(esi), (u32)(ebx));  // @11_63ead0
  ecx = edx = 0;  // @12_63ead0
  ecx = edi;  // @13_63ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_63ead0
  if (eax != (u32)(1)) goto L63eb18;  // @15_63ead0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @16_63ead0
  ecx = edx = 0;  // @17_63ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_63ead0
  ecx = edi;  // @19_63ead0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @20_63ead0
  ecx = edx = 0;  // @21_63ead0
  goto L63eb22;  // @22_63ead0
  L63eb18:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @24_63ead0
  ecx = edx = 0;  // @25_63ead0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_63ead0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @27_63ead0
  L63eb22:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @29_63ead0
  if ((esi & esi) != 0) goto L63eaf7;  // @30_63ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @31_63ead0
  L63eb2c:;
  ebx = (ebx + 1);  // @33_63ead0
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13320), sizeof v); (u32)v; })) goto L63eaf0;  // @34_63ead0
  L63eb37:;
  return eax;  // @36_63ead0
}
PCREG(63ead0, lifted_63ead0);

