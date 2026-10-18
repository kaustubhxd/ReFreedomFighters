// batch200091.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_45d3a0_thiscall1(u32) __asm__("ext_45d3a0");
extern "C" u32 THISCALL ext_4cfb30_thiscall3(u32, u32, u32) __asm__("ext_4cfb30");
extern "C" u32 THISCALL ext_4db520_thiscall1(u32) __asm__("ext_4db520");
extern "C" u32 THISCALL ext_4db580_thiscall2(u32, u32) __asm__("ext_4db580");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dc1e0_thiscall2(u32, u32) __asm__("ext_4dc1e0");
extern "C" u32 THISCALL ext_4ef0e0_thiscall1(u32) __asm__("ext_4ef0e0");
extern "C" u32 THISCALL ext_512590_thiscall1(u32) __asm__("ext_512590");
extern "C" u32 THISCALL ext_5aeff0_thiscall2(u32, u32) __asm__("ext_5aeff0");
extern "C" u32 THISCALL ext_5b0b70_thiscall2(u32, u32) __asm__("ext_5b0b70");
extern "C" u32 THISCALL ext_5c2c10_thiscall2(u32, u32) __asm__("ext_5c2c10");
extern "C" u32 THISCALL ext_5c5620_thiscall1(u32) __asm__("ext_5c5620");
extern "C" u32 THISCALL ext_647f70_thiscall1(u32) __asm__("ext_647f70");
extern "C" u32 THISCALL ext_648dd0_thiscall1(u32) __asm__("ext_648dd0");
extern "C" u32 ext_5c5810_cdecl2(...) __asm__("ext_5c5810");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634273_cdecl3(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_4690b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  return eax;  // @0_4690b0
}
PCREG(4690b0, lifted_4690b0);

extern "C" u32 STDCALL lifted_610100(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  return eax;  // @0_610100
}
PCREG(610100, lifted_610100);

extern "C" u32 STDCALL lifted_65f4b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  return eax;  // @0_65f4b0
}
PCREG(65f4b0, lifted_65f4b0);

extern "C" u32 STDCALL lifted_65f4c0(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  return eax;  // @0_65f4c0
}
PCREG(65f4c0, lifted_65f4c0);

extern "C" u32 lifted_51ad80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(6943660);  // @0_51ad80
  return eax;  // @1_51ad80
}
PCREG(51ad80, lifted_51ad80);

extern "C" u32 lifted_549de0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @0_549de0
  return eax;  // @1_549de0
}
PCREG(549de0, lifted_549de0);

extern "C" u32 lifted_55ec20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(6966132);  // @0_55ec20
  return eax;  // @1_55ec20
}
PCREG(55ec20, lifted_55ec20);

extern "C" u32 lifted_5f2120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422896), sizeof v); (u32)v; })) & 0xffff);  // @0_5f2120
  return eax;  // @1_5f2120
}
PCREG(5f2120, lifted_5f2120);

extern "C" u32 THISCALL lifted_616a40(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((u32)(7068736)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @0_616a40
  return eax;  // @1_616a40
}
PCREG(616a40, lifted_616a40);

extern "C" u32 THISCALL lifted_4c3190(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 72), &v, sizeof v); }  // @0_4c3190
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 76), &v, sizeof v); }  // @1_4c3190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @2_4c3190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4c3190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(1));  // @4_4c3190
  ecx = edx = 0;  // @5_4c3190
  return eax;  // @6_4c3190
}
PCREG(4c3190, lifted_4c3190);

extern "C" u32 STDCALL lifted_6387a0(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @0_6387a0
  if ((eax & eax) == 0) goto L6387b0;  // @1_6387a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2_6387a0
  ecx = edx = 0;  // @3_6387a0
  eax = 0;  // @4_6387a0
  return eax;  // @5_6387a0
  L6387b0:;
  __builtin_trap();  // @7_6387a0
}
PCREG(6387a0, lifted_6387a0);

extern "C" u32 THISCALL lifted_460c10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @0_460c10
  if ((eax & eax) == 0) goto L460c22;  // @1_460c10
  eax = ext_634273_cdecl2((u32)(eax), (u32)(56));  // @2_460c10
  ecx = edx = 0;  // @3_460c10
  L460c22:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @5_460c10
  return eax;  // @6_460c10
}
PCREG(460c10, lifted_460c10);

extern "C" u32 THISCALL lifted_4c8dd0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c8dd0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }), (u32)(4));  // @1_4c8dd0
  ecx = edx = 0;  // @2_4c8dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @3_4c8dd0
  return eax;  // @4_4c8dd0
}
PCREG(4c8dd0, lifted_4c8dd0);

extern "C" u32 lifted_5382d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @0_5382d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_5382d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6954540), (u32)(1851));  // @2_5382d0
  ecx = edx = 0;  // @3_5382d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4_5382d0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6955884));  // @5_5382d0
  ecx = edx = 0;  // @6_5382d0
  return eax;  // @7_5382d0
}
PCREG(5382d0, lifted_5382d0);

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

extern "C" u32 THISCALL lifted_658f50(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @0_658f50
  if ((eax & eax) != 0) goto L658f58;  // @1_658f50
  return eax;  // @2_658f50
  L658f58:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @4_658f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @5_658f50
  if ((eax & eax) != 0) goto L658f68;  // @6_658f50
  eax = (u32)(1);  // @7_658f50
  return eax;  // @8_658f50
  L658f68:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_658f50
  return eax;  // @11_658f50
}
PCREG(658f50, lifted_658f50);

extern "C" u32 THISCALL lifted_54e3f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edx = 0;  // @0_54e3f0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 453), sizeof v); (u32)v; }) <= (s32)edx) goto L54e425;  // @1_54e3f0
  eax = (u32)(ecx + 91);  // @2_54e3f0
  L54e400:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax - 63), &v, sizeof v); }  // @4_54e3f0
  eax = (u32)(eax + 107);  // @5_54e3f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 94), &v, sizeof v); }  // @6_54e3f0
  edx = (edx + 1);  // @7_54e3f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax - 107), &v, sizeof v); }  // @8_54e3f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 132), &v, sizeof v); }  // @9_54e3f0
  if ((s32)edx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 453), sizeof v); (u32)v; })) goto L54e400;  // @10_54e3f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 457), &v, sizeof v); }  // @11_54e3f0
  return eax;  // @12_54e3f0
  L54e425:;
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 457), &v, sizeof v); }  // @14_54e3f0
  return eax;  // @15_54e3f0
}
PCREG(54e3f0, lifted_54e3f0);

extern "C" u32 STDCALL lifted_5f17d0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @0_5f17d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_5f17d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7046968), (u32)(697));  // @2_5f17d0
  ecx = edx = 0;  // @3_5f17d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4_5f17d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6932144), (u32)(7047368));  // @5_5f17d0
  ecx = edx = 0;  // @6_5f17d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @7_5f17d0
  if ((eax & eax) == 0) goto L5f1806;  // @8_5f17d0
  eax = ((u32(STDCALL *)(void))(eax))();  // @9_5f17d0
  ecx = edx = 0;  // @10_5f17d0
  return eax;  // @11_5f17d0
  L5f1806:;
  __builtin_trap();  // @13_5f17d0
}
PCREG(5f17d0, lifted_5f17d0);

extern "C" u32 THISCALL lifted_4f9bc0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4f9bc0
  eax = ext_4ef0e0_thiscall1(ecx);  // @1_4f9bc0
  ecx = edx = 0;  // @2_4f9bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4f9bc0
  ecx = edi;  // @4_4f9bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_4f9bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_4f9bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_4f9bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @8_4f9bc0
  ecx = edx = 0;  // @9_4f9bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_4f9bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @11_4f9bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, (u32)(eax));  // @12_4f9bc0
  ecx = edx = 0;  // @13_4f9bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @14_4f9bc0
  return eax;  // @15_4f9bc0
}
PCREG(4f9bc0, lifted_4f9bc0);

extern "C" u32 THISCALL lifted_63b940(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_63b940
  esi = 0;  // @1_63b940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }) == esi) goto L63b969;  // @2_63b940
  edi = (u32)(ebx + 240);  // @3_63b940
  L63b955:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_63b940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_63b940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 108)))(ecx);  // @7_63b940
  ecx = edx = 0;  // @8_63b940
  esi = (esi + 1);  // @9_63b940
  edi = (u32)(edi + 4);  // @10_63b940
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; })) goto L63b955;  // @11_63b940
  L63b969:;
  return eax;  // @13_63b940
}
PCREG(63b940, lifted_63b940);

extern "C" u32 THISCALL lifted_54b650(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_54b650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41592), sizeof v); (u32)v; });  // @1_54b650
  if ((ecx & ecx) == 0) goto L54b679;  // @2_54b650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_54b650
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(ecx));  // @4_54b650
  ecx = edx = 0;  // @5_54b650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41592), sizeof v); (u32)v; });  // @6_54b650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_54b650
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(ecx + 8)))(ecx, (u32)(eax));  // @8_54b650
  ecx = edx = 0;  // @9_54b650
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 41592), &v, sizeof v); }  // @10_54b650
  L54b679:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41588), sizeof v); (u32)v; });  // @12_54b650
  if ((ecx & ecx) == 0) goto L54b689;  // @13_54b650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_54b650
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @15_54b650
  ecx = edx = 0;  // @16_54b650
  L54b689:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 41588), &v, sizeof v); }  // @18_54b650
  return eax;  // @19_54b650
}
PCREG(54b650, lifted_54b650);

extern "C" u32 THISCALL lifted_4afed0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4afed0
  ebx = ecx;  // @1_4afed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4afed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4afed0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4afed0
  ecx = edx = 0;  // @5_4afed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4afed0
  esi = eax;  // @7_4afed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_4afed0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4afed0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4afed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }));  // @11_4afed0
  ecx = edx = 0;  // @12_4afed0
  ecx = esi;  // @13_4afed0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 76)))(ecx, (u32)(6889580), (u32)(eax));  // @14_4afed0
  ecx = edx = 0;  // @15_4afed0
  return eax;  // @16_4afed0
}
PCREG(4afed0, lifted_4afed0);

extern "C" u32 THISCALL lifted_608da0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_608da0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7490356), sizeof v); (u32)v; }) != (u32)(0)) goto L608df2;  // @1_608da0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @2_608da0
  eax = (u32)(edi + 5142);  // @3_608da0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @4_608da0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 128)))(ecx, (u32)(edx), (u32)(eax));  // @5_608da0
  ecx = edx = 0;  // @6_608da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @7_608da0
  eax = (u32)(edi + 5146);  // @8_608da0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_608da0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(ecx), (u32)(eax));  // @10_608da0
  ecx = edx = 0;  // @11_608da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_608da0
  ecx = edi;  // @13_608da0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @14_608da0
  ecx = edx = 0;  // @15_608da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489604), &v, sizeof v); }  // @16_608da0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 30), &v, sizeof v); }  // @17_608da0
  L608df2:;
  return eax;  // @19_608da0
}
PCREG(608da0, lifted_608da0);

extern "C" u32 THISCALL lifted_54f250(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @0_54f250
  if ((esi & esi) == 0) goto L54f2a0;  // @1_54f250
  eax = (u32)(ecx + 8);  // @2_54f250
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(ecx + 76), &v, sizeof v); }  // @3_54f250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_54f250
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(esi), (u32)(7069552), (u32)(2147483649), (u32)(0), (u32)(0), (u32)(eax), (u32)(72));  // @5_54f250
  ecx = edx = 0;  // @6_54f250
  if ((s32)(eax & eax) >= 0) goto L54f2a0;  // @7_54f250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @8_54f250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_54f250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6963560), (u32)(372));  // @10_54f250
  ecx = edx = 0;  // @11_54f250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_54f250
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6963936));  // @13_54f250
  ecx = edx = 0;  // @14_54f250
  L54f2a0:;
  return eax;  // @16_54f250
}
PCREG(54f250, lifted_54f250);

extern "C" u32 THISCALL lifted_54ba50(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_54ba50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @1_54ba50
  if ((ecx & ecx) == 0) goto L54ba74;  // @2_54ba50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_54ba50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @4_54ba50
  ecx = edx = 0;  // @5_54ba50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @6_54ba50
  if ((ecx & ecx) == 0) goto L54ba6d;  // @7_54ba50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_54ba50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @9_54ba50
  ecx = edx = 0;  // @10_54ba50
  L54ba6d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @12_54ba50
  L54ba74:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @14_54ba50
  if ((ecx & ecx) == 0) goto L54ba81;  // @15_54ba50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_54ba50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_54ba50
  ecx = edx = 0;  // @18_54ba50
  L54ba81:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @20_54ba50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @21_54ba50
  if ((ecx & ecx) == 0) goto L54ba95;  // @22_54ba50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_54ba50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @24_54ba50
  ecx = edx = 0;  // @25_54ba50
  L54ba95:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @27_54ba50
  return eax;  // @28_54ba50
}
PCREG(54ba50, lifted_54ba50);

extern "C" u32 THISCALL lifted_6385c0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_6385c0
  edx = (u32)(7493652);  // @1_6385c0
  if ((esi & esi) == 0) goto L6385fc;  // @2_6385c0
  L6385d0:;
  eax = esi;  // @4_6385c0
  eax = (u32)((s32)eax >> (u32)(24));  // @5_6385c0
  if ((s32)(eax & 0xff) < (s32)(u32)(97)) goto L6385dd;  // @6_6385c0
  if ((s32)(eax & 0xff) <= (s32)(u32)(122)) goto L6385ed;  // @7_6385c0
  L6385dd:;
  if ((s32)(eax & 0xff) < (s32)(u32)(65)) goto L6385e5;  // @9_6385c0
  if ((s32)(eax & 0xff) <= (s32)(u32)(90)) goto L6385ed;  // @10_6385c0
  L6385e5:;
  ecx = (u32)(eax - 48);  // @12_6385c0
  if ((ecx & 0xff) > (u32)(9)) goto L6385f1;  // @13_6385c0
  L6385ed:;
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @15_6385c0
  goto L6385f4;  // @16_6385c0
  L6385f1:;
  { u8 v = (u8)((u32)(46)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @18_6385c0
  L6385f4:;
  esi = (esi << (u32)(8));  // @20_6385c0
  edx = (edx + 1);  // @21_6385c0
  if ((esi & esi) != 0) goto L6385d0;  // @22_6385c0
  L6385fc:;
  eax = (u32)(7493652);  // @24_6385c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @25_6385c0
  return eax;  // @26_6385c0
}
PCREG(6385c0, lifted_6385c0);

extern "C" u32 THISCALL lifted_5d89f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5d89f0
  ebx = ecx;  // @1_5d89f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5d89f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5d89f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 40), sizeof v); (u32)v; }));  // @4_5d89f0
  ecx = edx = 0;  // @5_5d89f0
  edi = eax;  // @6_5d89f0
  if ((edi & edi) == 0) goto L5d8a45;  // @7_5d89f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_5d89f0
  ecx = edi;  // @9_5d89f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 596)))(ecx, (u32)(0));  // @10_5d89f0
  ecx = edx = 0;  // @11_5d89f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_5d89f0
  ecx = edi;  // @13_5d89f0
  esi = eax;  // @14_5d89f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 628)))(ecx);  // @15_5d89f0
  ecx = edx = 0;  // @16_5d89f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_5d89f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @18_5d89f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @19_5d89f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5d89f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 264)))(ecx, (u32)(esi), (u32)(eax), (u32)(5));  // @21_5d89f0
  ecx = edx = 0;  // @22_5d89f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 52), &v, sizeof v); }  // @23_5d89f0
  L5d8a45:;
  return eax;  // @25_5d89f0
}
PCREG(5d89f0, lifted_5d89f0);

extern "C" u32 THISCALL lifted_64ab50(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_64ab50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @1_64ab50
  if ((esi & esi) == 0) goto L64aba1;  // @2_64ab50
  L64ab60:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @4_64ab50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_64ab50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @6_64ab50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(esi));  // @7_64ab50
  ecx = edx = 0;  // @8_64ab50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_64ab50
  ebx = (ebx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @10_64ab50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_64ab50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(7068248), (u32)(356));  // @12_64ab50
  ecx = edx = 0;  // @13_64ab50
  ecx = (ebx & 0xff);  // @14_64ab50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_64ab50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(eax), (u32)(7068328), (u32)(ecx));  // @16_64ab50
  ecx = edx = 0;  // @17_64ab50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @18_64ab50
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L64aba0;  // @19_64ab50
  if ((esi & esi) != 0) goto L64ab60;  // @20_64ab50
  L64aba0:;
  L64aba1:;
  return eax;  // @23_64ab50
}
PCREG(64ab50, lifted_64ab50);

extern "C" u32 THISCALL lifted_5c2f90(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5c2f90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L5c2fef;  // @1_5c2f90
  ebx = 0;  // @2_5c2f90
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 704), sizeof v); (u32)v; }) <= (s32)ebx) goto L5c2fee;  // @3_5c2f90
  esi = (u32)(edi + 20);  // @4_5c2f90
  L5c2fb0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @6_5c2f90
  eax = ext_5b0b70_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 8), sizeof v); (u32)v; }));  // @7_5c2f90
  ecx = edx = 0;  // @8_5c2f90
  eax = (eax & 0xffffff00u) | (((u32)((eax & eax) != 0)) & 0xff);  // @9_5c2f90
  if ((eax & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) goto L5c2fe1;  // @10_5c2f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @11_5c2f90
  eax = ext_5b0b70_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }));  // @12_5c2f90
  ecx = edx = 0;  // @13_5c2f90
  eax = (eax & 0xffffff00u) | (((u32)((eax & eax) != 0)) & 0xff);  // @14_5c2f90
  if ((eax & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) goto L5c2fe1;  // @15_5c2f90
  ecx = edi;  // @16_5c2f90
  eax = ext_5c2c10_thiscall2(ecx, (u32)(ebx));  // @17_5c2f90
  ecx = edx = 0;  // @18_5c2f90
  L5c2fe1:;
  ebx = (ebx + 1);  // @20_5c2f90
  esi = (esi + (u32)(14));  // @21_5c2f90
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 704), sizeof v); (u32)v; })) goto L5c2fb0;  // @22_5c2f90
  L5c2fee:;
  L5c2fef:;
  return eax;  // @25_5c2f90
}
PCREG(5c2f90, lifted_5c2f90);

extern "C" u32 THISCALL lifted_4bb550(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @1_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @2_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 128), sizeof v); (u32)v; });  // @3_4bb550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @4_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4bb550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4bb550
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892948), (u32)(0), (u32)(6892900), (u32)(58));  // @8_4bb550
  ecx = edx = 0;  // @9_4bb550
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @10_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4bb550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4bb550
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892972), (u32)(0), (u32)(6892900), (u32)(59));  // @14_4bb550
  ecx = edx = 0;  // @15_4bb550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @16_4bb550
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @17_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4bb550
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 260)))(ecx, (u32)(6880432));  // @19_4bb550
  ecx = edx = 0;  // @20_4bb550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @21_4bb550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 81), &v, sizeof v); }  // @22_4bb550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_4bb550
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 260)))(ecx, (u32)(6880188));  // @24_4bb550
  ecx = edx = 0;  // @25_4bb550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 85), &v, sizeof v); }  // @26_4bb550
  return eax;  // @27_4bb550
}
PCREG(4bb550, lifted_4bb550);

extern "C" u32 FASTCALL lifted_4dae60(u32 ecx_in, u32 edx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4dae60
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @1_4dae60
  if (((edx & 0xffff) & (edx & 0xffff)) == 0) goto L4daec2;  // @2_4dae60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4dae60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4dae60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @5_4dae60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_4dae60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @7_4dae60
  ecx = edx = 0;  // @8_4dae60
  esi = eax;  // @9_4dae60
  if ((esi & esi) == 0) goto L4daec1;  // @10_4dae60
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L4daea7;  // @11_4dae60
  L4dae90:;
  ecx = esi;  // @13_4dae60
  eax = ext_4db580_thiscall2(ecx, (u32)(0));  // @14_4dae60
  ecx = edx = 0;  // @15_4dae60
  ecx = edi;  // @16_4dae60
  eax = ext_4dc1e0_thiscall2(ecx, (u32)(eax));  // @17_4dae60
  ecx = edx = 0;  // @18_4dae60
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L4dae90;  // @19_4dae60
  L4daea7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4dae60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @22_4dae60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @23_4dae60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4dae60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @25_4dae60
  ecx = edx = 0;  // @26_4dae60
  eax = 0;  // @27_4dae60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 92), &v, sizeof v); }  // @28_4dae60
  L4daec1:;
  L4daec2:;
  return eax;  // @31_4dae60
}
PCREG(4dae60, lifted_4dae60);

extern "C" u32 THISCALL lifted_591b20(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_591b20
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @1_591b20
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) & (u32)(33554432)) == 0) goto L591b3e;  // @2_591b20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @3_591b20
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @4_591b20
  L591b3e:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1628), sizeof v); (u32)v; })) & 0xff);  // @6_591b20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 1628), &v, sizeof v); }  // @7_591b20
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L591ba2;  // @8_591b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_591b20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @10_591b20
  ecx = edx = 0;  // @11_591b20
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1624), sizeof v); (u32)v; })) goto L591b62;  // @12_591b20
  if (((ebx & 0xff) & (ebx & 0xff)) == 0) goto L591b88;  // @13_591b20
  L591b62:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1624), &v, sizeof v); }  // @15_591b20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @16_591b20
  if ((eax & eax) == 0) goto L591b88;  // @17_591b20
  ecx = (u32)(esi + 2395);  // @18_591b20
  eax = ext_5aeff0_thiscall2(ecx, (u32)(eax));  // @19_591b20
  ecx = edx = 0;  // @20_591b20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @21_591b20
  L591b88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_591b20
  ecx = esi;  // @24_591b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @25_591b20
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @26_591b20
  ecx = edx = 0;  // @27_591b20
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L591ba2;  // @28_591b20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @29_591b20
  L591ba2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1620), sizeof v); (u32)v; });  // @31_591b20
  return eax;  // @32_591b20
}
PCREG(591b20, lifted_591b20);

extern "C" u32 lifted_4c8fe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4c8fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1_4c8fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4c8fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892260), (u32)(0), (u32)(6901188), (u32)(80));  // @3_4c8fe0
  ecx = edx = 0;  // @4_4c8fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340908), &v, sizeof v); }  // @5_4c8fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4c8fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_4c8fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4c8fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6858876), (u32)(0), (u32)(6901188), (u32)(81));  // @9_4c8fe0
  ecx = edx = 0;  // @10_4c8fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340912), &v, sizeof v); }  // @11_4c8fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_4c8fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_4c8fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4c8fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6901236), (u32)(0), (u32)(6901188), (u32)(82));  // @15_4c8fe0
  ecx = edx = 0;  // @16_4c8fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340916), &v, sizeof v); }  // @17_4c8fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4c8fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_4c8fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4c8fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6901256), (u32)(0), (u32)(6901188), (u32)(83));  // @21_4c8fe0
  ecx = edx = 0;  // @22_4c8fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340920), &v, sizeof v); }  // @23_4c8fe0
  return eax;  // @24_4c8fe0
}
PCREG(4c8fe0, lifted_4c8fe0);

extern "C" u32 THISCALL lifted_6363a0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_6363a0
  edi = 0;  // @1_6363a0
  { u32 v = (u32)((u32)(7085932)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_6363a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) <= edi) goto L6363d6;  // @3_6363a0
  ebx = 0;  // @4_6363a0
  L6363b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @6_6363a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L6363cc;  // @7_6363a0
  eax = ext_634273_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 16), sizeof v); (u32)v; }), (u32)(1), (u32)(ebx));  // @8_6363a0
  ecx = edx = 0;  // @9_6363a0
  L6363cc:;
  edi = (edi + 1);  // @11_6363a0
  ebx = (ebx + (u32)(20));  // @12_6363a0
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; })) goto L6363b4;  // @13_6363a0
  L6363d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @15_6363a0
  if ((eax & eax) == 0) goto L6363e8;  // @16_6363a0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @17_6363a0
  ecx = edx = 0;  // @18_6363a0
  L6363e8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) == (u32)(0)) goto L6363fb;  // @20_6363a0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }), (u32)(1));  // @21_6363a0
  ecx = edx = 0;  // @22_6363a0
  L6363fb:;
  return eax;  // @24_6363a0
}
PCREG(6363a0, lifted_6363a0);

extern "C" u32 THISCALL lifted_64dd20(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65893), sizeof v); (u32)v; }), (u32)(4));  // @1_64dd20
  ecx = edx = 0;  // @2_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65873), sizeof v); (u32)v; }), (u32)(4));  // @3_64dd20
  ecx = edx = 0;  // @4_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65877), sizeof v); (u32)v; }), (u32)(4));  // @5_64dd20
  ecx = edx = 0;  // @6_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65881), sizeof v); (u32)v; }), (u32)(4));  // @7_64dd20
  ecx = edx = 0;  // @8_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65885), sizeof v); (u32)v; }), (u32)(4));  // @9_64dd20
  ecx = edx = 0;  // @10_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65889), sizeof v); (u32)v; }), (u32)(4));  // @11_64dd20
  ecx = edx = 0;  // @12_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65897), sizeof v); (u32)v; }), (u32)(4));  // @13_64dd20
  ecx = edx = 0;  // @14_64dd20
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65901), sizeof v); (u32)v; }), (u32)(4));  // @15_64dd20
  ecx = edx = 0;  // @16_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65893), &v, sizeof v); }  // @17_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65873), &v, sizeof v); }  // @18_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65877), &v, sizeof v); }  // @19_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65881), &v, sizeof v); }  // @20_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65885), &v, sizeof v); }  // @21_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65889), &v, sizeof v); }  // @22_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65897), &v, sizeof v); }  // @23_64dd20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65901), &v, sizeof v); }  // @24_64dd20
  return eax;  // @25_64dd20
}
PCREG(64dd20, lifted_64dd20);

extern "C" u32 THISCALL lifted_5c55a0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5c55a0
  eax = ext_5c5620_thiscall1(ecx);  // @1_5c55a0
  ecx = edx = 0;  // @2_5c55a0
  if ((eax & eax) == 0) goto L5c5605;  // @3_5c55a0
  ecx = ebx;  // @4_5c55a0
  eax = ext_5c5810_cdecl2((u32)(edi), (u32)(esi));  // @5_5c55a0
  ecx = edx = 0;  // @6_5c55a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @7_5c55a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 332), sizeof v); (u32)v; });  // @8_5c55a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(ecx), (u32)(eax), (u32)(0));  // @10_5c55a0
  ecx = edx = 0;  // @11_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @12_5c55a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @13_5c55a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_5c55a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6993692), (u32)(0), (u32)(7029252), (u32)(87), (u32)(0));  // @18_5c55a0
  ecx = edx = 0;  // @19_5c55a0
  eax = (eax & 0xffff);  // @20_5c55a0
  ecx = esi;  // @21_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 304)))(ecx, (u32)(esi), (u32)(eax));  // @22_5c55a0
  ecx = edx = 0;  // @23_5c55a0
  L5c5605:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_5c55a0
  ecx = ebx;  // @26_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @27_5c55a0
  ecx = edx = 0;  // @28_5c55a0
  return eax;  // @29_5c55a0
}
PCREG(5c55a0, lifted_5c55a0);

extern "C" u32 THISCALL lifted_5d3eb0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5d3eb0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @1_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_5d3eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5d3eb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7008588), (u32)(0), (u32)(7033228), (u32)(65));  // @5_5d3eb0
  ecx = edx = 0;  // @6_5d3eb0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @7_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_5d3eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5d3eb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7033288), (u32)(0), (u32)(7033228), (u32)(66));  // @11_5d3eb0
  ecx = edx = 0;  // @12_5d3eb0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 122), &v, sizeof v); }  // @13_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_5d3eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5d3eb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6971824), (u32)(0), (u32)(7033228), (u32)(67));  // @17_5d3eb0
  ecx = edx = 0;  // @18_5d3eb0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @19_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_5d3eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_5d3eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5d3eb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6971804), (u32)(0), (u32)(7033228), (u32)(68));  // @23_5d3eb0
  ecx = edx = 0;  // @24_5d3eb0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 126), &v, sizeof v); }  // @25_5d3eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 133), &v, sizeof v); }  // @26_5d3eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @27_5d3eb0
  return eax;  // @28_5d3eb0
}
PCREG(5d3eb0, lifted_5d3eb0);

extern "C" u32 THISCALL lifted_429b50(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_429b50
  edi = 0;  // @1_429b50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= edi) goto L429b70;  // @2_429b50
  ebx = (u32)(esi + 4);  // @3_429b50
  L429b60:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_429b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_429b50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @7_429b50
  ecx = edx = 0;  // @8_429b50
  edi = (edi + 1);  // @9_429b50
  ebx = (u32)(ebx + 4);  // @10_429b50
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L429b60;  // @11_429b50
  L429b70:;
  edi = 0;  // @13_429b50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) <= edi) goto L429b90;  // @14_429b50
  ebx = (u32)(esi + 16);  // @15_429b50
  L429b80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_429b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_429b50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @19_429b50
  ecx = edx = 0;  // @20_429b50
  edi = (edi + 1);  // @21_429b50
  ebx = (u32)(ebx + 4);  // @22_429b50
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; })) goto L429b80;  // @23_429b50
  L429b90:;
  edi = 0;  // @25_429b50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }) <= edi) goto L429bb0;  // @26_429b50
  ebx = (u32)(esi + 32);  // @27_429b50
  L429ba0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_429b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_429b50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 84)))(ecx);  // @31_429b50
  ecx = edx = 0;  // @32_429b50
  edi = (edi + 1);  // @33_429b50
  ebx = (u32)(ebx + 4);  // @34_429b50
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; })) goto L429ba0;  // @35_429b50
  L429bb0:;
  return eax;  // @37_429b50
}
PCREG(429b50, lifted_429b50);

extern "C" u32 THISCALL lifted_4cfbe0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cfbe0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(2097152))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @1_4cfbe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 456), sizeof v); (u32)v; });  // @2_4cfbe0
  if ((eax & eax) == 0) goto L4cfc0e;  // @3_4cfbe0
  eax = (eax - 1);  // @4_4cfbe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 456), &v, sizeof v); }  // @5_4cfbe0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4 + 8), sizeof v); (u32)v; });  // @6_4cfbe0
  eax = ext_4cfb30_thiscall3(ecx, (u32)(edi), (u32)(2097152));  // @7_4cfbe0
  ecx = edx = 0;  // @8_4cfbe0
  return eax;  // @9_4cfbe0
  L4cfc0e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 519), sizeof v); (u32)v; }) < (u32)(10000)) goto L4cfc1f;  // @11_4cfbe0
  eax = 0;  // @12_4cfbe0
  return eax;  // @13_4cfbe0
  L4cfc1f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775536), sizeof v); (u32)v; });  // @15_4cfbe0
  eax = ((u32( *)(u32))(eax))((u32)(2097184));  // @16_4cfbe0
  ecx = edx = 0;  // @17_4cfbe0
  ecx = (u32)(esi + 490);  // @18_4cfbe0
  edi = (u32)(eax + 19);  // @19_4cfbe0
  edi = (edi & (u32)(4294967280));  // @20_4cfbe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @21_4cfbe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 54824), sizeof v); (u32)v; });  // @22_4cfbe0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4 + 50728), sizeof v); (u32)v; });  // @23_4cfbe0
  eax = (eax + 1);  // @24_4cfbe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 54824), &v, sizeof v); }  // @25_4cfbe0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @26_4cfbe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4cfbe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(edx));  // @28_4cfbe0
  ecx = edx = 0;  // @29_4cfbe0
  ecx = esi;  // @30_4cfbe0
  eax = ext_4cfb30_thiscall3(ecx, (u32)(edi), (u32)(2097152));  // @31_4cfbe0
  ecx = edx = 0;  // @32_4cfbe0
  return eax;  // @33_4cfbe0
}
PCREG(4cfbe0, lifted_4cfbe0);

extern "C" u32 THISCALL lifted_4daff0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @0_4daff0
  if ((esi & esi) == 0) goto L4db000;  // @1_4daff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @2_4daff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @3_4daff0
  goto L4db005;  // @4_4daff0
  L4db000:;
  eax = (u32)(2097154);  // @6_4daff0
  L4db005:;
  if ((eax & (u32)(1048576)) != 0) goto L4db016;  // @8_4daff0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 80), sizeof v); (u32)v; });  // @9_4daff0
  if ((esi & esi) == 0) goto L4db062;  // @10_4daff0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @11_4daff0
  L4db016:;
  if ((esi & esi) == 0) goto L4db062;  // @13_4daff0
  L4db020:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_4daff0
  ecx = esi;  // @16_4daff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @17_4daff0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1048608));  // @18_4daff0
  ecx = edx = 0;  // @19_4daff0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4db055;  // @20_4daff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_4daff0
  ecx = esi;  // @22_4daff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @23_4daff0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @24_4daff0
  ecx = edx = 0;  // @25_4daff0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4db066;  // @26_4daff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_4daff0
  ecx = esi;  // @28_4daff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 784), sizeof v); (u32)v; });  // @29_4daff0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @30_4daff0
  ecx = edx = 0;  // @31_4daff0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4db062;  // @32_4daff0
  L4db055:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_4daff0
  ecx = esi;  // @35_4daff0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @36_4daff0
  ecx = edx = 0;  // @37_4daff0
  esi = eax;  // @38_4daff0
  if ((esi & esi) != 0) goto L4db020;  // @39_4daff0
  L4db062:;
  eax = 0;  // @41_4daff0
  return eax;  // @42_4daff0
  L4db066:;
  eax = esi;  // @44_4daff0
  return eax;  // @45_4daff0
}
PCREG(4daff0, lifted_4daff0);

extern "C" u32 THISCALL lifted_6155d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_6155d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_6155d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @2_6155d0
  ecx = edx = 0;  // @3_6155d0
  esi = eax;  // @4_6155d0
  if ((esi & esi) != 0) goto L6155e4;  // @5_6155d0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @6_6155d0
  return eax;  // @7_6155d0
  L6155e4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; })) & 0xff);  // @9_6155d0
  ecx = edi;  // @10_6155d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 1), &v, sizeof v); }  // @11_6155d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_6155d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ebx));  // @13_6155d0
  ecx = edx = 0;  // @14_6155d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @15_6155d0
  edx = (u32)(esi + 16);  // @16_6155d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @17_6155d0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @18_6155d0
  ebx = (u32)(eax - 1);  // @19_6155d0
  eax = 0;  // @20_6155d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2), &v, sizeof v); }  // @21_6155d0
  if ((ebx & ebx) == 0) goto L615621;  // @22_6155d0
  L615610:;
  ecx = (u32)(eax + 1);  // @24_6155d0
  eax = (eax + 1);  // @25_6155d0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @26_6155d0
  edx = (edx + (u32)(312));  // @27_6155d0
  if (eax != ebx) goto L615610;  // @28_6155d0
  L615621:;
  eax = (u32)(65535);  // @30_6155d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @31_6155d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @32_6155d0
  if ((ecx & ecx) == 0) goto L615640;  // @33_6155d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @34_6155d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @35_6155d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @36_6155d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @37_6155d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @38_6155d0
  L615640:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @40_6155d0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @41_6155d0
  return eax;  // @42_6155d0
}
PCREG(6155d0, lifted_6155d0);

extern "C" u32 THISCALL lifted_648d50(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_648d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_648d50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @2_648d50
  ecx = edx = 0;  // @3_648d50
  esi = eax;  // @4_648d50
  if ((esi & esi) != 0) goto L648d64;  // @5_648d50
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @6_648d50
  return eax;  // @7_648d50
  L648d64:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; })) & 0xff);  // @9_648d50
  ecx = edi;  // @10_648d50
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 1), &v, sizeof v); }  // @11_648d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_648d50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ebx));  // @13_648d50
  ecx = edx = 0;  // @14_648d50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @15_648d50
  edx = (u32)(esi + 16);  // @16_648d50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @17_648d50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @18_648d50
  ebx = (u32)(eax - 1);  // @19_648d50
  eax = 0;  // @20_648d50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2), &v, sizeof v); }  // @21_648d50
  if ((ebx & ebx) == 0) goto L648d9e;  // @22_648d50
  L648d90:;
  ecx = (u32)(eax + 1);  // @24_648d50
  eax = (eax + 1);  // @25_648d50
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @26_648d50
  edx = (edx + (u32)(32));  // @27_648d50
  if (eax != ebx) goto L648d90;  // @28_648d50
  L648d9e:;
  eax = (u32)(65535);  // @30_648d50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @31_648d50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @32_648d50
  if ((ecx & ecx) == 0) goto L648dbd;  // @33_648d50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @34_648d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @35_648d50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @36_648d50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @37_648d50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @38_648d50
  L648dbd:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @40_648d50
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @41_648d50
  return eax;  // @42_648d50
}
PCREG(648d50, lifted_648d50);

extern "C" u32 THISCALL lifted_4f9af0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4f9af0
  eax = ext_45d3a0_thiscall1(ecx);  // @1_4f9af0
  ecx = edx = 0;  // @2_4f9af0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @3_4f9af0
  L4f9b00:;
  if ((esi & esi) == 0) goto L4f9b44;  // @5_4f9af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @6_4f9af0
  if ((eax & eax) == 0) goto L4f9b13;  // @7_4f9af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @8_4f9af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @9_4f9af0
  goto L4f9b18;  // @10_4f9af0
  L4f9b13:;
  eax = (u32)(2097154);  // @12_4f9af0
  L4f9b18:;
  if ((eax & (u32)(1048576)) != 0) goto L4f9b44;  // @14_4f9af0
  ecx = esi;  // @15_4f9af0
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097196));  // @16_4f9af0
  ecx = edx = 0;  // @17_4f9af0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4f9b39;  // @18_4f9af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @19_4f9af0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 33), sizeof v); (u32)v; });  // @20_4f9af0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; }) | eax)); __builtin_memcpy((void *)(u32)(edi + 116), &v, sizeof v); }  // @21_4f9af0
  L4f9b39:;
  ecx = esi;  // @23_4f9af0
  eax = ext_4db520_thiscall1(ecx);  // @24_4f9af0
  ecx = edx = 0;  // @25_4f9af0
  esi = eax;  // @26_4f9af0
  goto L4f9b00;  // @27_4f9af0
  L4f9b44:;
  ecx = edi;  // @29_4f9af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_4f9af0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; }) & (u32)(1)) != 0) goto L4f9b52;  // @31_4f9af0
  goto L4f9b54;  // @32_4f9af0
  L4f9b52:;
  L4f9b54:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0), (u32)(1));  // @35_4f9af0
  ecx = edx = 0;  // @36_4f9af0
  ecx = edi;  // @37_4f9af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_4f9af0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4f9b6c;  // @39_4f9af0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 732)))(ecx);  // @40_4f9af0
  ecx = edx = 0;  // @41_4f9af0
  goto L4f9b72;  // @42_4f9af0
  L4f9b6c:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 728)))(ecx);  // @44_4f9af0
  ecx = edx = 0;  // @45_4f9af0
  L4f9b72:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; });  // @47_4f9af0
  ecx = edi;  // @48_4f9af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @49_4f9af0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 112), &v, sizeof v); }  // @50_4f9af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, (u32)(eax));  // @51_4f9af0
  ecx = edx = 0;  // @52_4f9af0
  return eax;  // @53_4f9af0
}
PCREG(4f9af0, lifted_4f9af0);

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

extern "C" u32 THISCALL lifted_51c140(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_51c140
  eax = ext_512590_thiscall1(ecx);  // @1_51c140
  ecx = edx = 0;  // @2_51c140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_51c140
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }) == (u32)(0)) goto L51c19b;  // @4_51c140
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 303), sizeof v); (u32)v; });  // @5_51c140
  if ((edx & edx) == 0) goto L51c19b;  // @6_51c140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @7_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_51c140
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(edx), (u32)(6945060));  // @9_51c140
  ecx = edx = 0;  // @10_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1169), &v, sizeof v); }  // @11_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_51c140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @13_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_51c140
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 303), sizeof v); (u32)v; }), (u32)(6945068));  // @15_51c140
  ecx = edx = 0;  // @16_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1173), &v, sizeof v); }  // @17_51c140
  L51c19b:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_51c140
  eax = (u32)(ebx + 96);  // @20_51c140
  esi = (u32)(ebx + 108);  // @21_51c140
  ecx = ebx;  // @22_51c140
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, (u32)(esi), (u32)(eax));  // @23_51c140
  ecx = edx = 0;  // @24_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_51c140
  edi = (u32)(ebx + 534);  // @26_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @27_51c140
  edx = (u32)(ebx + 546);  // @28_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @29_51c140
  ecx = (u32)(ebx + 846);  // @30_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @31_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @33_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @35_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @36_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @37_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @38_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @39_51c140
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 538), &v, sizeof v); }  // @40_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @42_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @43_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @44_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @45_51c140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @46_51c140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_51c140
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edi), (u32)(edx));  // @48_51c140
  ecx = edx = 0;  // @49_51c140
  return eax;  // @50_51c140
}
PCREG(51c140, lifted_51c140);

