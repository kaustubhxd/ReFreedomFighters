// batch200090.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 STDCALL ext_41f190_stdcall1(u32) __asm__("ext_41f190");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_45fc70_thiscall2(u32, u32) __asm__("ext_45fc70");
extern "C" u32 THISCALL ext_49fa80_thiscall2(u32, u32) __asm__("ext_49fa80");
extern "C" u32 THISCALL ext_4a1850_thiscall2(u32, u32) __asm__("ext_4a1850");
extern "C" u32 THISCALL ext_4cfbe0_thiscall1(u32) __asm__("ext_4cfbe0");
extern "C" u32 THISCALL ext_4db9e0_thiscall1(u32) __asm__("ext_4db9e0");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e14a0_thiscall3(u32, u32, u32) __asm__("ext_4e14a0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4f9680_thiscall2(u32, u32) __asm__("ext_4f9680");
extern "C" u32 THISCALL ext_4f9c90_thiscall2(u32, u32) __asm__("ext_4f9c90");
extern "C" u32 THISCALL ext_512850_thiscall2(u32, u32) __asm__("ext_512850");
extern "C" u32 THISCALL ext_56ad00_thiscall2(u32, u32) __asm__("ext_56ad00");
extern "C" u32 THISCALL ext_5c2cb0_thiscall1(u32) __asm__("ext_5c2cb0");
extern "C" u32 THISCALL ext_5c2e10_thiscall2(u32, u32) __asm__("ext_5c2e10");
extern "C" u32 THISCALL ext_5c2ec0_thiscall1(u32) __asm__("ext_5c2ec0");
extern "C" u32 THISCALL ext_5c2f30_thiscall1(u32) __asm__("ext_5c2f30");
extern "C" u32 THISCALL ext_5c2f90_thiscall1(u32) __asm__("ext_5c2f90");
extern "C" u32 THISCALL ext_658d30_thiscall1(u32) __asm__("ext_658d30");

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
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_449310
  if ((ecx & ecx) == 0) goto L449372;  // @2_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_449310
  edx = (u32)(EBP - 12);  // @4_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @5_449310
  ecx = edx = 0;  // @6_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @7_449310
  edx = (u32)(EBP - 12);  // @8_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @10_449310
  ecx = edx = 0;  // @11_449310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == (u32)(0)) goto L449372;  // @12_449310
  L449340:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @15_449310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @17_449310
  ecx = edx = 0;  // @18_449310
  if ((eax & eax) == 0) goto L449360;  // @19_449310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_449310
  ecx = eax;  // @21_449310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 532)))(ecx);  // @22_449310
  ecx = edx = 0;  // @23_449310
  L449360:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @25_449310
  edx = (u32)(EBP - 12);  // @26_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @28_449310
  ecx = edx = 0;  // @29_449310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) != (u32)(0)) goto L449340;  // @30_449310
  L449372:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_449310
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(8192));  // @33_449310
  ecx = edx = 0;  // @34_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @35_449310
  eax = (eax & (u32)(4294967294));  // @36_449310
  eax = (eax | (u32)(8));  // @37_449310
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @38_449310
  return eax;  // @39_449310
}
PCREG(449310, lifted_449310);

extern "C" u32 THISCALL lifted_562d90(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 216), sizeof v); (u32)v; });  // @2_562d90
  eax = ((u32(STDCALL *)(void))(eax))();  // @3_562d90
  ecx = edx = 0;  // @4_562d90
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L562e18;  // @5_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_562d90
  if (eax != (u32)(261)) goto L562e07;  // @7_562d90
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 135), sizeof v); (u32)v; }) == (u32)(0)) goto L562e18;  // @8_562d90
  ecx = (u32)(7343652);  // @9_562d90
  eax = ext_4f9680_thiscall2(ecx, (u32)(3));  // @10_562d90
  ecx = edx = 0;  // @11_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_562d90
  ecx = esi;  // @13_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 224)))(ecx);  // @14_562d90
  ecx = edx = 0;  // @15_562d90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }) == (u32)(0)) goto L562dec;  // @16_562d90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L562dec;  // @17_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_562d90
  ecx = esi;  // @19_562d90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(0));  // @20_562d90
  ecx = edx = 0;  // @21_562d90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @22_562d90
  return eax;  // @23_562d90
  L562dec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_562d90
  ecx = esi;  // @26_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @27_562d90
  ecx = edx = 0;  // @28_562d90
  ecx = eax;  // @29_562d90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 768)))(ecx);  // @31_562d90
  ecx = edx = 0;  // @32_562d90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @33_562d90
  return eax;  // @34_562d90
  L562e07:;
  if (eax != (u32)(262)) goto L562e18;  // @36_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_562d90
  ecx = esi;  // @38_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @39_562d90
  ecx = edx = 0;  // @40_562d90
  L562e18:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @42_562d90
  return eax;  // @43_562d90
}
PCREG(562d90, lifted_562d90);

extern "C" u32 THISCALL lifted_63e850(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ecx;  // @0_63e850
  edx = (u32)(65535);  // @1_63e850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_63e850
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @3_63e850
  if ((eax & 0xffff) == (edx & 0xffff)) goto L63e877;  // @4_63e850
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 6), &v, sizeof v); }  // @5_63e850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 624), &v, sizeof v); }  // @6_63e850
  L63e877:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ecx + 5), &v, sizeof v); }  // @8_63e850
  edx = (u32)(EBP + 8);  // @9_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @11_63e850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @12_63e850
  ecx = (u32)(esi + 496);  // @13_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @15_63e850
  ecx = edx = 0;  // @16_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_63e850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @18_63e850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) | (u32)(4096))); __builtin_memcpy((void *)(u32)(ecx + 60), &v, sizeof v); }  // @19_63e850
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(1074003968)) != 0) goto L63e8b3;  // @20_63e850
  eax = ext_4db9e0_thiscall1(ecx);  // @21_63e850
  ecx = edx = 0;  // @22_63e850
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L63e8c8;  // @23_63e850
  L63e8b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_63e850
  ecx = (u32)(esi + 436);  // @26_63e850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @27_63e850
  edx = (u32)(EBP - 4);  // @28_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @30_63e850
  ecx = edx = 0;  // @31_63e850
  L63e8c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_63e850
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L63e8e7;  // @34_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 476), sizeof v); (u32)v; });  // @35_63e850
  ecx = (u32)(esi + 476);  // @36_63e850
  edx = (u32)(EBP + 8);  // @37_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @38_63e850
  ecx = edx = 0;  // @39_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @40_63e850
  L63e8e7:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 63), sizeof v); (u32)v; }) == (u32)(0)) goto L63e900;  // @42_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 456), sizeof v); (u32)v; });  // @43_63e850
  ecx = (u32)(esi + 456);  // @44_63e850
  edx = (u32)(EBP + 8);  // @45_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @46_63e850
  ecx = edx = 0;  // @47_63e850
  L63e900:;
  return eax;  // @49_63e850
}
PCREG(63e850, lifted_63e850);

extern "C" u32 THISCALL lifted_41f400(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_41f400
  ebx = ecx;  // @1_41f400
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @2_41f400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @3_41f400
  eax = (u32)(edi + 32);  // @4_41f400
  eax = ext_41f190_stdcall1((u32)(eax));  // @5_41f400
  ecx = edx = 0;  // @6_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) == esi) goto L41f43e;  // @7_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_41f400
  ecx = ebx;  // @9_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780060), (u32)(edi));  // @10_41f400
  ecx = edx = 0;  // @11_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @12_41f400
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @13_41f400
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @14_41f400
  if ((eax & eax) == 0) goto L41f478;  // @15_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @16_41f400
  ecx = edx = 0;  // @17_41f400
  L41f43e:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @19_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @20_41f400
  eax = (eax & (u32)(536870911));  // @21_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 32), sizeof v); (u32)v; }) == (u32)(2271560481)) goto L41f487;  // @22_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @23_41f400
  ecx = ebx;  // @24_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780084), (u32)(edi));  // @25_41f400
  ecx = edx = 0;  // @26_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @27_41f400
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @28_41f400
  if ((eax & eax) == 0) goto L41f47b;  // @29_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @30_41f400
  ecx = edx = 0;  // @31_41f400
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @32_41f400
  return eax;  // @33_41f400
  L41f478:;
  __builtin_trap();  // @35_41f400
  L41f47b:;
  __builtin_trap();  // @37_41f400
  L41f487:;
  eax = (eax & 0xffffff00u) | (((ecx & 0xff)) & 0xff);  // @39_41f400
  return eax;  // @40_41f400
}
PCREG(41f400, lifted_41f400);

extern "C" u32 THISCALL lifted_4cf2d0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4cf2d0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) >= (s32)(u32)(0)) goto L4cf30d;  // @1_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4cf2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6904700), (u32)(392));  // @4_4cf2d0
  ecx = edx = 0;  // @5_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_4cf2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6904776));  // @7_4cf2d0
  ecx = edx = 0;  // @8_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @9_4cf2d0
  if ((eax & eax) == 0) goto L4cf30c;  // @10_4cf2d0
  eax = ((u32(STDCALL *)(void))(eax))();  // @11_4cf2d0
  ecx = edx = 0;  // @12_4cf2d0
  goto L4cf30d;  // @13_4cf2d0
  L4cf30c:;
  __builtin_trap();  // @15_4cf2d0
  L4cf30d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @18_4cf2d0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; })) goto L4cf326;  // @19_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @20_4cf2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @21_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @22_4cf2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @23_4cf2d0
  L4cf326:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @25_4cf2d0
  if ((ecx & ecx) != 0) goto L4cf333;  // @26_4cf2d0
  eax = 0;  // @27_4cf2d0
  return eax;  // @28_4cf2d0
  L4cf333:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @30_4cf2d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @31_4cf2d0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L4cf353;  // @32_4cf2d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cf353;  // @33_4cf2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @34_4cf2d0
  eax = 0;  // @35_4cf2d0
  return eax;  // @36_4cf2d0
  L4cf353:;
  eax = (u32)(ecx + 16);  // @38_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @39_4cf2d0
  ecx = (ecx + edi);  // @40_4cf2d0
  eax = (u32)(eax + edi*4);  // @41_4cf2d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @42_4cf2d0
  return eax;  // @43_4cf2d0
}
PCREG(4cf2d0, lifted_4cf2d0);

extern "C" u32 THISCALL lifted_4d0590(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d0590
  ebx = ecx;  // @1_4d0590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 460), sizeof v); (u32)v; });  // @2_4d0590
  ecx = (u32)(ebx + 460);  // @3_4d0590
  eax = (u32)(edi + 16);  // @4_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 12)))(ecx, (u32)(eax), (u32)(0));  // @5_4d0590
  ecx = edx = 0;  // @6_4d0590
  esi = eax;  // @7_4d0590
  if ((esi & esi) != 0) goto L4d0602;  // @8_4d0590
  ecx = ebx;  // @9_4d0590
  eax = ext_4cfbe0_thiscall1(ecx);  // @10_4d0590
  ecx = edx = 0;  // @11_4d0590
  esi = eax;  // @12_4d0590
  if ((esi & esi) != 0) goto L4d0602;  // @13_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6905280), (u32)(1074));  // @16_4d0590
  ecx = edx = 0;  // @17_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6905496), (u32)(edi));  // @19_4d0590
  ecx = edx = 0;  // @20_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @21_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4d0590
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 120)))(ecx);  // @23_4d0590
  ecx = edx = 0;  // @24_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @25_4d0590
  if ((eax & eax) == 0) goto L4d05ff;  // @26_4d0590
  eax = ((u32(STDCALL *)(void))(eax))();  // @27_4d0590
  ecx = edx = 0;  // @28_4d0590
  goto L4d060a;  // @29_4d0590
  L4d05ff:;
  __builtin_trap();  // @31_4d0590
  L4d0602:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @33_4d0590
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) >= (s32)edi) goto L4d061f;  // @34_4d0590
  L4d060a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_4d0590
  if ((eax & eax) == 0) goto L4d061e;  // @37_4d0590
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_4d0590
  ecx = edx = 0;  // @39_4d0590
  eax = esi;  // @40_4d0590
  return eax;  // @41_4d0590
  L4d061e:;
  __builtin_trap();  // @43_4d0590
  L4d061f:;
  eax = esi;  // @45_4d0590
  return eax;  // @46_4d0590
}
PCREG(4d0590, lifted_4d0590);

extern "C" u32 lifted_62ce70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62ce70
  if (esi == (u32)(15)) goto L62cef5;  // @1_62ce70
  if (esi != (u32)(18)) goto L62ced3;  // @2_62ce70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_62ce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @4_62ce70
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078332), (u32)(edi));  // @5_62ce70
  ecx = edx = 0;  // @6_62ce70
  if ((eax & eax) == 0) goto L62ceac;  // @7_62ce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62ce70
  { u32 v = (u32)((u32)(6475520)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_62ce70
  eax = 0;  // @10_62ce70
  return eax;  // @11_62ce70
  L62ceac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @13_62ce70
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078316));  // @14_62ce70
  ecx = edx = 0;  // @15_62ce70
  if ((eax & eax) == 0) goto L62ced3;  // @16_62ce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_62ce70
  { u32 v = (u32)((u32)(6475584)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @18_62ce70
  eax = 0;  // @19_62ce70
  return eax;  // @20_62ce70
  L62ced3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_62ce70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L62cee8;  // @23_62ce70
  if (esi != (u32)(28)) goto L62cee8;  // @24_62ce70
  eax = (u32)(esi + 24);  // @25_62ce70
  return eax;  // @26_62ce70
  L62cee8:;
  { u32 v = (u32)((u32)(5370416)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @28_62ce70
  eax = (eax | (u32)(4294967295));  // @29_62ce70
  return eax;  // @30_62ce70
  L62cef5:;
  eax = 0;  // @32_62ce70
  return eax;  // @33_62ce70
}
PCREG(62ce70, lifted_62ce70);

extern "C" u32 lifted_62d840(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62d840
  if (esi == (u32)(15)) goto L62d8de;  // @1_62d840
  if (esi == (u32)(18)) goto L62d86b;  // @2_62d840
  if (esi != (u32)(27)) goto L62d8bc;  // @3_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_62d840
  { u32 v = (u32)((u32)(6475664)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @5_62d840
  eax = (u32)(esi - 17);  // @6_62d840
  return eax;  // @7_62d840
  L62d86b:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @9_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @10_62d840
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078408), (u32)(edi));  // @11_62d840
  ecx = edx = 0;  // @12_62d840
  if ((eax & eax) == 0) goto L62d895;  // @13_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_62d840
  { u32 v = (u32)((u32)(6478144)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @15_62d840
  eax = 0;  // @16_62d840
  return eax;  // @17_62d840
  L62d895:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @19_62d840
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078388));  // @20_62d840
  ecx = edx = 0;  // @21_62d840
  if ((eax & eax) == 0) goto L62d8bc;  // @22_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @23_62d840
  { u32 v = (u32)((u32)(6478064)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @24_62d840
  eax = 0;  // @25_62d840
  return eax;  // @26_62d840
  L62d8bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @28_62d840
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L62d8d1;  // @29_62d840
  if (esi != (u32)(28)) goto L62d8d1;  // @30_62d840
  eax = (u32)(esi + 24);  // @31_62d840
  return eax;  // @32_62d840
  L62d8d1:;
  { u32 v = (u32)((u32)(5370416)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_62d840
  eax = (eax | (u32)(4294967295));  // @35_62d840
  return eax;  // @36_62d840
  L62d8de:;
  eax = 0;  // @38_62d840
  return eax;  // @39_62d840
}
PCREG(62d840, lifted_62d840);

extern "C" u32 THISCALL lifted_51c210(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_51c210
  ebx = ecx;  // @1_51c210
  eax = ext_512850_thiscall2(ecx, (u32)(edi));  // @2_51c210
  ecx = edx = 0;  // @3_51c210
  esi = (u32)(ebx + 1101);  // @4_51c210
  ecx = edi;  // @5_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(esi), (u32)(1));  // @6_51c210
  ecx = edx = 0;  // @7_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c267;  // @8_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(258));  // @11_51c210
  ecx = edx = 0;  // @12_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @13_51c210
  edx = (u32)(6801640);  // @14_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @15_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6945012), (u32)(edx));  // @17_51c210
  ecx = edx = 0;  // @18_51c210
  L51c267:;
  ecx = edi;  // @20_51c210
  eax = ext_4e1600_thiscall1(ecx);  // @21_51c210
  ecx = edx = 0;  // @22_51c210
  if ((eax & 0xff) != (u32)(8)) goto L51c2c6;  // @23_51c210
  esi = (u32)(ebx + 1105);  // @24_51c210
  ecx = edi;  // @25_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(esi), (u32)(1));  // @26_51c210
  ecx = edx = 0;  // @27_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c2d0;  // @28_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @29_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(261));  // @31_51c210
  ecx = edx = 0;  // @32_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @33_51c210
  edx = (u32)(6801640);  // @34_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @35_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6945036), (u32)(edx));  // @37_51c210
  ecx = edx = 0;  // @38_51c210
  ecx = edi;  // @39_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @40_51c210
  ecx = edx = 0;  // @41_51c210
  return eax;  // @42_51c210
  L51c2c6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1105), &v, sizeof v); }  // @44_51c210
  L51c2d0:;
  ecx = edi;  // @46_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @47_51c210
  ecx = edx = 0;  // @48_51c210
  return eax;  // @49_51c210
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

extern "C" u32 STDCALL lifted_62ee40(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_62ee40
  if ((esi & esi) == 0) goto L62eef8;  // @1_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @2_62ee40
  if ((eax & eax) == 0) goto L62eef8;  // @3_62ee40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_62ee40
  if (edi == (u32)(42)) goto L62ee7b;  // @5_62ee40
  if (edi == (u32)(113)) goto L62ee7b;  // @6_62ee40
  if (edi == (u32)(666)) goto L62ee7b;  // @7_62ee40
  eax = (u32)(4294967294);  // @8_62ee40
  return eax;  // @9_62ee40
  L62ee7b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @11_62ee40
  if ((eax & eax) == 0) goto L62ee8e;  // @12_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @13_62ee40
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax), (u32)(edi));  // @14_62ee40
  ecx = edx = 0;  // @15_62ee40
  L62ee8e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @17_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @18_62ee40
  if ((eax & eax) == 0) goto L62eea4;  // @19_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @20_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax));  // @21_62ee40
  ecx = edx = 0;  // @22_62ee40
  L62eea4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @24_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @25_62ee40
  if ((eax & eax) == 0) goto L62eeba;  // @26_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @27_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax));  // @28_62ee40
  ecx = edx = 0;  // @29_62ee40
  L62eeba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @31_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @32_62ee40
  if ((eax & eax) == 0) goto L62eed0;  // @33_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @34_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax));  // @35_62ee40
  ecx = edx = 0;  // @36_62ee40
  L62eed0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @38_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }));  // @39_62ee40
  ecx = edx = 0;  // @40_62ee40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @41_62ee40
  eax = 0;  // @42_62ee40
  ecx = (u32)(4294967293);  // @43_62ee40
  if (edi == (u32)(113)) eax = ecx;  // @44_62ee40
  return eax;  // @45_62ee40
  L62eef8:;
  eax = (u32)(4294967294);  // @47_62ee40
  return eax;  // @48_62ee40
}
PCREG(62ee40, lifted_62ee40);

extern "C" u32 THISCALL lifted_5dd1b0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5dd1b0
  esi = ecx;  // @1_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7040416), (u32)(0), (u32)(7040368), (u32)(56));  // @4_5dd1b0
  ecx = edx = 0;  // @5_5dd1b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_5dd1b0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L5dd239;  // @7_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; })) goto L5dd1ea;  // @8_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @9_5dd1b0
  L5dd1ea:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; })) goto L5dd1f3;  // @11_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @12_5dd1b0
  L5dd1f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @14_5dd1b0
  if (edi != eax) goto L5dd1fe;  // @15_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @16_5dd1b0
  L5dd1fe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; });  // @18_5dd1b0
  if (edi != ecx) goto L5dd209;  // @19_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @20_5dd1b0
  L5dd209:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; })) goto L5dd212;  // @22_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @23_5dd1b0
  L5dd212:;
  if (edi == eax) goto L5dd21a;  // @25_5dd1b0
  if (edi != ecx) goto L5dd239;  // @26_5dd1b0
  L5dd21a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 93), sizeof v); (u32)v; }));  // @31_5dd1b0
  ecx = edx = 0;  // @32_5dd1b0
  ecx = eax;  // @33_5dd1b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(1));  // @35_5dd1b0
  ecx = edx = 0;  // @36_5dd1b0
  L5dd239:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @39_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7040428), (u32)(0), (u32)(7040368), (u32)(74));  // @41_5dd1b0
  ecx = edx = 0;  // @42_5dd1b0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L5dd295;  // @43_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; })) goto L5dd269;  // @44_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @45_5dd1b0
  L5dd269:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; })) goto L5dd272;  // @47_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @48_5dd1b0
  L5dd272:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; })) goto L5dd27b;  // @50_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @51_5dd1b0
  L5dd27b:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; })) goto L5dd284;  // @53_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @54_5dd1b0
  L5dd284:;
  eax = 0;  // @56_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; })) goto L5dd297;  // @57_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @58_5dd1b0
  return eax;  // @59_5dd1b0
  L5dd295:;
  eax = 0;  // @61_5dd1b0
  L5dd297:;
  return eax;  // @63_5dd1b0
}
PCREG(5dd1b0, lifted_5dd1b0);

extern "C" u32 THISCALL lifted_45fd50(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @7_45fd50
  ecx = edx = 0;  // @8_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @9_45fd50
  edx = (u32)(EBP - 12);  // @10_45fd50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @11_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_45fd50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @13_45fd50
  ecx = edx = 0;  // @14_45fd50
  esi = eax;  // @15_45fd50
  if ((esi & esi) == 0) goto L45fdc3;  // @16_45fd50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_45fd50
  L45fd90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @19_45fd50
  edx = ebx;  // @20_45fd50
  eax = ext_4cc850_fastcall2(ecx, edx);  // @21_45fd50
  ecx = edx = 0;  // @22_45fd50
  if ((eax & eax) == 0) goto L45fdbc;  // @23_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @24_45fd50
  edx = (u32)(EBP - 12);  // @25_45fd50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @26_45fd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_45fd50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @28_45fd50
  ecx = edx = 0;  // @29_45fd50
  esi = eax;  // @30_45fd50
  if ((esi & esi) != 0) goto L45fd90;  // @31_45fd50
  return eax;  // @32_45fd50
  L45fdbc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @34_45fd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @35_45fd50
  L45fdc3:;
  L45fdc4:;
  return eax;  // @38_45fd50
}
PCREG(45fd50, lifted_45fd50);

extern "C" u32 STDCALL lifted_565190(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_565190
  if ((edx & edx) == 0) goto L56522f;  // @1_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @4_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_565190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973980), (u32)(edx));  // @6_565190
  ecx = edx = 0;  // @7_565190
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @8_565190
  esi = eax;  // @9_565190
  if ((edi & edi) == 0) goto L5651ea;  // @10_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_565190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @13_565190
  ecx = edx = 0;  // @14_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_565190
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))((u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @16_565190
  ecx = edx = 0;  // @17_565190
  return eax;  // @18_565190
  L5651ea:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @20_565190
  if ((edi & edi) == 0) goto L565216;  // @21_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_565190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_565190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @24_565190
  ecx = edx = 0;  // @25_565190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_565190
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))((u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), (u32)(edi));  // @27_565190
  ecx = edx = 0;  // @28_565190
  return eax;  // @29_565190
  L565216:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @31_565190
  ecx = (ecx - esi);  // @32_565190
  L565220:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @34_565190
  esi = (u32)(esi + 1);  // @35_565190
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @36_565190
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L565220;  // @37_565190
  L56522f:;
  return eax;  // @39_565190
}
PCREG(565190, lifted_565190);

extern "C" u32 THISCALL lifted_4a02e0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4a02e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edi));  // @12_4a02e0
  ecx = edx = 0;  // @13_4a02e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @14_4a02e0
  ecx = 0;  // @15_4a02e0
  if ((esi & esi) == 0) goto L4a0343;  // @16_4a02e0
  edx = (u32)(ebx + 110);  // @17_4a02e0
  L4a0330:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == eax) goto L4a033e;  // @19_4a02e0
  ecx = (ecx + 1);  // @20_4a02e0
  edx = (edx + (u32)(4));  // @21_4a02e0
  if (ecx != esi) goto L4a0330;  // @22_4a02e0
  goto L4a0343;  // @23_4a02e0
  L4a033e:;
  if (ecx != (u32)(-1)) goto L4a03a1;  // @25_4a02e0
  L4a0343:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4a02e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edi));  // @30_4a02e0
  ecx = edx = 0;  // @31_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @32_4a02e0
  esi = eax;  // @33_4a02e0
  ecx = (ecx + 1);  // @34_4a02e0
  if (ecx <= (u32)(2)) goto L4a036e;  // @35_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_4a02e0
  if ((ecx & ecx) == 0) goto L4a036d;  // @37_4a02e0
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @38_4a02e0
  ecx = edx = 0;  // @39_4a02e0
  goto L4a036e;  // @40_4a02e0
  L4a036d:;
  __builtin_trap();  // @42_4a02e0
  L4a036e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @44_4a02e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 110), &v, sizeof v); }  // @45_4a02e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 106), &v, sizeof v); }  // @46_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_4a02e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @48_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_4a02e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @50_4a02e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_4a02e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @52_4a02e0
  ecx = edx = 0;  // @53_4a02e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @54_4a02e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7340736), sizeof v); (u32)v; });  // @55_4a02e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, (u32)(edi), (u32)(eax), (u32)(eax));  // @56_4a02e0
  ecx = edx = 0;  // @57_4a02e0
  L4a03a1:;
  L4a03a2:;
  L4a03a3:;
  return eax;  // @61_4a02e0
}
PCREG(4a02e0, lifted_4a02e0);

extern "C" u32 THISCALL lifted_53b1b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_53b1b0
  if ((ecx & ecx) == 0) goto L53b294;  // @2_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_53b1b0
  edx = (u32)(EBP - 12);  // @4_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @5_53b1b0
  ecx = edx = 0;  // @6_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @7_53b1b0
  edx = (u32)(EBP - 12);  // @8_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @10_53b1b0
  ecx = edx = 0;  // @11_53b1b0
  if ((eax & eax) == 0) goto L53b294;  // @12_53b1b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @13_53b1b0
  L53b1e5:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) == edi) goto L53b202;  // @15_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @16_53b1b0
  edx = (u32)(EBP - 12);  // @17_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @19_53b1b0
  ecx = edx = 0;  // @20_53b1b0
  if ((eax & eax) != 0) goto L53b1e5;  // @21_53b1b0
  return eax;  // @22_53b1b0
  L53b202:;
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; })) goto L53b21a;  // @24_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @25_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 14), &v, sizeof v); }  // @26_53b1b0
  if ((ecx & ecx) == 0) goto L53b239;  // @27_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @28_53b1b0
  goto L53b239;  // @29_53b1b0
  L53b21a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @31_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @32_53b1b0
  if ((edx & edx) != 0) goto L53b22d;  // @33_53b1b0
  if ((ecx & ecx) == 0) goto L53b239;  // @34_53b1b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @35_53b1b0
  goto L53b239;  // @36_53b1b0
  L53b22d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @38_53b1b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @39_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @40_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @41_53b1b0
  L53b239:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; }) != eax) goto L53b24e;  // @43_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @44_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @45_53b1b0
  if ((ecx & ecx) != 0) goto L53b24e;  // @46_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; });  // @47_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @48_53b1b0
  L53b24e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 22), sizeof v); (u32)v; }) != eax) goto L53b26f;  // @50_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @51_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @52_53b1b0
  if ((ecx & ecx) != 0) goto L53b263;  // @53_53b1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; });  // @54_53b1b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @55_53b1b0
  L53b263:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 22), sizeof v); (u32)v; }) != eax) goto L53b26f;  // @57_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @58_53b1b0
  L53b26f:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; }) != eax) goto L53b27b;  // @60_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @61_53b1b0
  L53b27b:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; }) != eax) goto L53b287;  // @63_53b1b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 14), &v, sizeof v); }  // @64_53b1b0
  L53b287:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @66_53b1b0
  edx = (u32)(EBP - 12);  // @67_53b1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_53b1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(edx));  // @69_53b1b0
  ecx = edx = 0;  // @70_53b1b0
  L53b294:;
  return eax;  // @72_53b1b0
}
PCREG(53b1b0, lifted_53b1b0);

extern "C" u32 THISCALL lifted_4f1100(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f1100
  edi = ecx;  // @1_4f1100
  esi = (u32)(32);  // @2_4f1100
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @3_4f1100
  L4f1112:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @5_4f1100
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4f1129;  // @6_4f1100
  edx = (edx + (u32)(4));  // @7_4f1100
  eax = (eax + (u32)(4));  // @8_4f1100
  esi = (esi - (u32)(4));  // @9_4f1100
  if (1 || esi) goto L4f1112;  // @10_4f1100
  return eax;  // @11_4f1100
  L4f1129:;
  ecx = edi;  // @13_4f1100
  eax = ext_45fc70_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @14_4f1100
  ecx = edx = 0;  // @15_4f1100
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 144), &v, sizeof v); }  // @16_4f1100
  return eax;  // @17_4f1100
}
PCREG(4f1100, lifted_4f1100);

extern "C" u32 THISCALL lifted_4f9d60(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f9d60
  edi = ecx;  // @1_4f9d60
  eax = ext_4f9c90_thiscall2(ecx, (u32)(esi));  // @2_4f9d60
  ecx = edx = 0;  // @3_4f9d60
  eax = (u32)(EBP + 8);  // @4_4f9d60
  ecx = esi;  // @5_4f9d60
  eax = ext_4e12e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @6_4f9d60
  ecx = edx = 0;  // @7_4f9d60
  eax = (u32)(edi + 171);  // @8_4f9d60
  ecx = esi;  // @9_4f9d60
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @10_4f9d60
  ecx = edx = 0;  // @11_4f9d60
  eax = (u32)(edi + 155);  // @12_4f9d60
  ecx = esi;  // @13_4f9d60
  eax = ext_4e12e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @14_4f9d60
  ecx = edx = 0;  // @15_4f9d60
  ecx = esi;  // @16_4f9d60
  eax = ext_4e1b30_thiscall1(ecx);  // @17_4f9d60
  ecx = edx = 0;  // @18_4f9d60
  eax = 0;  // @19_4f9d60
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == eax)) & 0xff);  // @20_4f9d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 143), &v, sizeof v); }  // @21_4f9d60
  return eax;  // @22_4f9d60
}
PCREG(4f9d60, lifted_4f9d60);

extern "C" u32 THISCALL lifted_5d5ae0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d5ae0
  edi = ecx;  // @1_5d5ae0
  eax = ext_610100_stdcall1((u32)(esi));  // @2_5d5ae0
  ecx = edx = 0;  // @3_5d5ae0
  eax = (u32)(edi + 29);  // @4_5d5ae0
  ecx = esi;  // @5_5d5ae0
  eax = ext_4e12e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @6_5d5ae0
  ecx = edx = 0;  // @7_5d5ae0
  eax = (u32)(edi + 33);  // @8_5d5ae0
  ecx = esi;  // @9_5d5ae0
  eax = ext_4e12e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @10_5d5ae0
  ecx = edx = 0;  // @11_5d5ae0
  eax = (u32)(EBP + 8);  // @12_5d5ae0
  ecx = esi;  // @13_5d5ae0
  eax = ext_4e12e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @14_5d5ae0
  ecx = edx = 0;  // @15_5d5ae0
  eax = (u32)(edi + 49);  // @16_5d5ae0
  ecx = esi;  // @17_5d5ae0
  eax = ext_4e14a0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @18_5d5ae0
  ecx = edx = 0;  // @19_5d5ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_5d5ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_5d5ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5d5ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @23_5d5ae0
  ecx = edx = 0;  // @24_5d5ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 37), &v, sizeof v); }  // @25_5d5ae0
  return eax;  // @26_5d5ae0
}
PCREG(5d5ae0, lifted_5d5ae0);

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
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ecx;  // @0_4a01c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 94), sizeof v); (u32)v; }) == (u32)(0)) goto L4a02d0;  // @1_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_4a01c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ebx));  // @6_4a01c0
  ecx = edx = 0;  // @7_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @8_4a01c0
  ecx = 0;  // @9_4a01c0
  if ((esi & esi) == 0) goto L4a02ce;  // @10_4a01c0
  edx = (u32)(edi + 110);  // @11_4a01c0
  L4a01f7:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == eax) goto L4a020c;  // @13_4a01c0
  ecx = (ecx + 1);  // @14_4a01c0
  edx = (edx + (u32)(4));  // @15_4a01c0
  if (ecx != esi) goto L4a01f7;  // @16_4a01c0
  return eax;  // @17_4a01c0
  L4a020c:;
  if (ecx == (u32)(-1)) goto L4a02ce;  // @19_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ebx));  // @23_4a01c0
  ecx = edx = 0;  // @24_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @25_4a01c0
  ecx = 0;  // @26_4a01c0
  ebx = eax;  // @27_4a01c0
  if ((esi & esi) == 0) goto L4a0255;  // @28_4a01c0
  edx = (u32)(edi + 110);  // @29_4a01c0
  L4a0234:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == ebx) goto L4a0242;  // @31_4a01c0
  ecx = (ecx + 1);  // @32_4a01c0
  edx = (edx + (u32)(4));  // @33_4a01c0
  if (ecx != esi) goto L4a0234;  // @34_4a01c0
  goto L4a0255;  // @35_4a01c0
  L4a0242:;
  if (ecx == (u32)(-1)) goto L4a0255;  // @37_4a01c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 106), &v, sizeof v); }  // @38_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @39_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 110), sizeof v); (u32)v; });  // @40_4a01c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx*4 + 110), &v, sizeof v); }  // @41_4a01c0
  L4a0255:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @44_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4a01c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @46_4a01c0
  ecx = edx = 0;  // @47_4a01c0
  ecx = (u32)(EBP - 4);  // @48_4a01c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @49_4a01c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_4a01c0
  ecx = eax;  // @51_4a01c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(ecx));  // @52_4a01c0
  ecx = edx = 0;  // @53_4a01c0
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })) goto L4a02a3;  // @54_4a01c0
  ecx = 0;  // @55_4a01c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 126), sizeof v); (u32)v; }) == ecx) goto L4a02a3;  // @56_4a01c0
  edx = (u32)(edi + 130);  // @57_4a01c0
  L4a0294:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @59_4a01c0
  edx = (u32)(edx + 4);  // @60_4a01c0
  ecx = (ecx + 1);  // @61_4a01c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; }) | (u32)(2))); __builtin_memcpy((void *)(u32)(eax + 90), &v, sizeof v); }  // @62_4a01c0
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 126), sizeof v); (u32)v; })) goto L4a0294;  // @63_4a01c0
  L4a02a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_4a01c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @66_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @68_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @70_4a01c0
  ecx = edx = 0;  // @71_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @72_4a01c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7340740), sizeof v); (u32)v; });  // @73_4a01c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(eax), (u32)(eax));  // @74_4a01c0
  ecx = edx = 0;  // @75_4a01c0
  L4a02ce:;
  L4a02d0:;
  return eax;  // @78_4a01c0
}
PCREG(4a01c0, lifted_4a01c0);

