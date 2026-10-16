// batch200107.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_63418c_stdcall4(u32, u32, u32, u32) __asm__("ext_63418c");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_476540_cdecl2(...) __asm__("ext_476540");
extern "C" u32 ext_48aa80_cdecl2(...) __asm__("ext_48aa80");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_66af40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66af40
  eax = ext_634273_cdecl2((u32)(eax), (u32)(32));  // @1_66af40
  ecx = edx = 0;  // @2_66af40
  return eax;  // @3_66af40
}
PCREG(66af40, lifted_66af40);

extern "C" u32 lifted_66af80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66af80
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66af80
  ecx = edx = 0;  // @2_66af80
  return eax;  // @3_66af80
}
PCREG(66af80, lifted_66af80);

extern "C" u32 lifted_66afc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66afc0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(12));  // @1_66afc0
  ecx = edx = 0;  // @2_66afc0
  return eax;  // @3_66afc0
}
PCREG(66afc0, lifted_66afc0);

extern "C" u32 lifted_66b128(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66b128
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66b128
  ecx = edx = 0;  // @2_66b128
  return eax;  // @3_66b128
}
PCREG(66b128, lifted_66b128);

extern "C" u32 lifted_66b13a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66b13a
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66b13a
  ecx = edx = 0;  // @2_66b13a
  return eax;  // @3_66b13a
}
PCREG(66b13a, lifted_66b13a);

extern "C" u32 lifted_66b14c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66b14c
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66b14c
  ecx = edx = 0;  // @2_66b14c
  return eax;  // @3_66b14c
}
PCREG(66b14c, lifted_66b14c);

extern "C" u32 lifted_66b260(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @0_66b260
  eax = ext_634273_cdecl2((u32)(eax), (u32)(225));  // @1_66b260
  ecx = edx = 0;  // @2_66b260
  return eax;  // @3_66b260
}
PCREG(66b260, lifted_66b260);

extern "C" u32 lifted_66b330(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66b330
  eax = ext_634273_cdecl2((u32)(eax), (u32)(225));  // @1_66b330
  ecx = edx = 0;  // @2_66b330
  return eax;  // @3_66b330
}
PCREG(66b330, lifted_66b330);

extern "C" u32 lifted_66b5b3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66b5b3
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66b5b3
  ecx = edx = 0;  // @2_66b5b3
  return eax;  // @3_66b5b3
}
PCREG(66b5b3, lifted_66b5b3);

extern "C" u32 lifted_66b6f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b6f0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(11406));  // @1_66b6f0
  ecx = edx = 0;  // @2_66b6f0
  return eax;  // @3_66b6f0
}
PCREG(66b6f0, lifted_66b6f0);

extern "C" u32 lifted_66b736(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66b736
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66b736
  ecx = edx = 0;  // @2_66b736
  return eax;  // @3_66b736
}
PCREG(66b736, lifted_66b736);

extern "C" u32 lifted_66b8d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b8d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1356));  // @1_66b8d0
  ecx = edx = 0;  // @2_66b8d0
  return eax;  // @3_66b8d0
}
PCREG(66b8d0, lifted_66b8d0);

extern "C" u32 lifted_66b900(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b900
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1533));  // @1_66b900
  ecx = edx = 0;  // @2_66b900
  return eax;  // @3_66b900
}
PCREG(66b900, lifted_66b900);

extern "C" u32 lifted_66b930(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b930
  eax = ext_634273_cdecl2((u32)(eax), (u32)(393));  // @1_66b930
  ecx = edx = 0;  // @2_66b930
  return eax;  // @3_66b930
}
PCREG(66b930, lifted_66b930);

extern "C" u32 lifted_66b960(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b960
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1425));  // @1_66b960
  ecx = edx = 0;  // @2_66b960
  return eax;  // @3_66b960
}
PCREG(66b960, lifted_66b960);

extern "C" u32 lifted_66b972(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b972
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1485));  // @1_66b972
  ecx = edx = 0;  // @2_66b972
  return eax;  // @3_66b972
}
PCREG(66b972, lifted_66b972);

extern "C" u32 lifted_66b984(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b984
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1471));  // @1_66b984
  ecx = edx = 0;  // @2_66b984
  return eax;  // @3_66b984
}
PCREG(66b984, lifted_66b984);

extern "C" u32 lifted_66b996(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b996
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1467));  // @1_66b996
  ecx = edx = 0;  // @2_66b996
  return eax;  // @3_66b996
}
PCREG(66b996, lifted_66b996);

extern "C" u32 lifted_66b9a8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b9a8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1384));  // @1_66b9a8
  ecx = edx = 0;  // @2_66b9a8
  return eax;  // @3_66b9a8
}
PCREG(66b9a8, lifted_66b9a8);

extern "C" u32 lifted_66b9ba(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b9ba
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1455));  // @1_66b9ba
  ecx = edx = 0;  // @2_66b9ba
  return eax;  // @3_66b9ba
}
PCREG(66b9ba, lifted_66b9ba);

extern "C" u32 lifted_66b9cc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b9cc
  eax = ext_634273_cdecl2((u32)(eax), (u32)(122));  // @1_66b9cc
  ecx = edx = 0;  // @2_66b9cc
  return eax;  // @3_66b9cc
}
PCREG(66b9cc, lifted_66b9cc);

extern "C" u32 lifted_66b9db(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b9db
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1553));  // @1_66b9db
  ecx = edx = 0;  // @2_66b9db
  return eax;  // @3_66b9db
}
PCREG(66b9db, lifted_66b9db);

extern "C" u32 lifted_66b9ed(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b9ed
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1400));  // @1_66b9ed
  ecx = edx = 0;  // @2_66b9ed
  return eax;  // @3_66b9ed
}
PCREG(66b9ed, lifted_66b9ed);

extern "C" u32 lifted_66bac6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bac6
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bac6
  ecx = edx = 0;  // @2_66bac6
  return eax;  // @3_66bac6
}
PCREG(66bac6, lifted_66bac6);

extern "C" u32 lifted_66bad8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bad8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bad8
  ecx = edx = 0;  // @2_66bad8
  return eax;  // @3_66bad8
}
PCREG(66bad8, lifted_66bad8);

extern "C" u32 lifted_66baea(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66baea
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66baea
  ecx = edx = 0;  // @2_66baea
  return eax;  // @3_66baea
}
PCREG(66baea, lifted_66baea);

extern "C" u32 lifted_66bafc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bafc
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bafc
  ecx = edx = 0;  // @2_66bafc
  return eax;  // @3_66bafc
}
PCREG(66bafc, lifted_66bafc);

extern "C" u32 lifted_66bb0e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bb0e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bb0e
  ecx = edx = 0;  // @2_66bb0e
  return eax;  // @3_66bb0e
}
PCREG(66bb0e, lifted_66bb0e);

extern "C" u32 lifted_66bb20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bb20
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bb20
  ecx = edx = 0;  // @2_66bb20
  return eax;  // @3_66bb20
}
PCREG(66bb20, lifted_66bb20);

extern "C" u32 lifted_66bb32(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bb32
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bb32
  ecx = edx = 0;  // @2_66bb32
  return eax;  // @3_66bb32
}
PCREG(66bb32, lifted_66bb32);

extern "C" u32 lifted_66bb44(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bb44
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bb44
  ecx = edx = 0;  // @2_66bb44
  return eax;  // @3_66bb44
}
PCREG(66bb44, lifted_66bb44);

extern "C" u32 lifted_66bb56(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bb56
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66bb56
  ecx = edx = 0;  // @2_66bb56
  return eax;  // @3_66bb56
}
PCREG(66bb56, lifted_66bb56);

extern "C" u32 lifted_66bbe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66bbe0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(16));  // @1_66bbe0
  ecx = edx = 0;  // @2_66bbe0
  return eax;  // @3_66bbe0
}
PCREG(66bbe0, lifted_66bbe0);

extern "C" u32 lifted_66bbef(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @0_66bbef
  eax = ext_634273_cdecl2((u32)(eax), (u32)(41));  // @1_66bbef
  ecx = edx = 0;  // @2_66bbef
  return eax;  // @3_66bbef
}
PCREG(66bbef, lifted_66bbef);

extern "C" u32 lifted_66bbfe(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @0_66bbfe
  eax = ext_634273_cdecl2((u32)(eax), (u32)(41));  // @1_66bbfe
  ecx = edx = 0;  // @2_66bbfe
  return eax;  // @3_66bbfe
}
PCREG(66bbfe, lifted_66bbfe);

extern "C" u32 lifted_66bc0d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @0_66bc0d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(41));  // @1_66bc0d
  ecx = edx = 0;  // @2_66bc0d
  return eax;  // @3_66bc0d
}
PCREG(66bc0d, lifted_66bc0d);

extern "C" u32 lifted_66bc56(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bc56
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bc56
  ecx = edx = 0;  // @2_66bc56
  return eax;  // @3_66bc56
}
PCREG(66bc56, lifted_66bc56);

extern "C" u32 lifted_66bc68(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bc68
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bc68
  ecx = edx = 0;  // @2_66bc68
  return eax;  // @3_66bc68
}
PCREG(66bc68, lifted_66bc68);

extern "C" u32 lifted_66bca8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_66bca8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bca8
  ecx = edx = 0;  // @2_66bca8
  return eax;  // @3_66bca8
}
PCREG(66bca8, lifted_66bca8);

extern "C" u32 lifted_66bcba(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_66bcba
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bcba
  ecx = edx = 0;  // @2_66bcba
  return eax;  // @3_66bcba
}
PCREG(66bcba, lifted_66bcba);

extern "C" u32 lifted_66bccc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_66bccc
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bccc
  ecx = edx = 0;  // @2_66bccc
  return eax;  // @3_66bccc
}
PCREG(66bccc, lifted_66bccc);

extern "C" u32 lifted_66bd40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @0_66bd40
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66bd40
  ecx = edx = 0;  // @2_66bd40
  return eax;  // @3_66bd40
}
PCREG(66bd40, lifted_66bd40);

extern "C" u32 lifted_66bed8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66bed8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66bed8
  ecx = edx = 0;  // @2_66bed8
  return eax;  // @3_66bed8
}
PCREG(66bed8, lifted_66bed8);

extern "C" u32 lifted_66bf5e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_66bf5e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66bf5e
  ecx = edx = 0;  // @2_66bf5e
  return eax;  // @3_66bf5e
}
PCREG(66bf5e, lifted_66bf5e);

extern "C" u32 lifted_66bfc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @0_66bfc0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(247));  // @1_66bfc0
  ecx = edx = 0;  // @2_66bfc0
  return eax;  // @3_66bfc0
}
PCREG(66bfc0, lifted_66bfc0);

extern "C" u32 lifted_66bfd5(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @0_66bfd5
  eax = ext_634273_cdecl2((u32)(eax), (u32)(215));  // @1_66bfd5
  ecx = edx = 0;  // @2_66bfd5
  return eax;  // @3_66bfd5
}
PCREG(66bfd5, lifted_66bfd5);

extern "C" u32 lifted_66bfea(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @0_66bfea
  eax = ext_634273_cdecl2((u32)(eax), (u32)(132));  // @1_66bfea
  ecx = edx = 0;  // @2_66bfea
  return eax;  // @3_66bfea
}
PCREG(66bfea, lifted_66bfea);

extern "C" u32 lifted_66bfff(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @0_66bfff
  eax = ext_634273_cdecl2((u32)(eax), (u32)(132));  // @1_66bfff
  ecx = edx = 0;  // @2_66bfff
  return eax;  // @3_66bfff
}
PCREG(66bfff, lifted_66bfff);

extern "C" u32 lifted_66c014(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @0_66c014
  eax = ext_634273_cdecl2((u32)(eax), (u32)(219));  // @1_66c014
  ecx = edx = 0;  // @2_66c014
  return eax;  // @3_66c014
}
PCREG(66c014, lifted_66c014);

extern "C" u32 lifted_66c029(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @0_66c029
  eax = ext_634273_cdecl2((u32)(eax), (u32)(219));  // @1_66c029
  ecx = edx = 0;  // @2_66c029
  return eax;  // @3_66c029
}
PCREG(66c029, lifted_66c029);

extern "C" u32 lifted_66c03e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c03e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(215));  // @1_66c03e
  ecx = edx = 0;  // @2_66c03e
  return eax;  // @3_66c03e
}
PCREG(66c03e, lifted_66c03e);

extern "C" u32 lifted_66c053(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c053
  eax = ext_634273_cdecl2((u32)(eax), (u32)(167));  // @1_66c053
  ecx = edx = 0;  // @2_66c053
  return eax;  // @3_66c053
}
PCREG(66c053, lifted_66c053);

extern "C" u32 lifted_66c068(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c068
  eax = ext_634273_cdecl2((u32)(eax), (u32)(167));  // @1_66c068
  ecx = edx = 0;  // @2_66c068
  return eax;  // @3_66c068
}
PCREG(66c068, lifted_66c068);

extern "C" u32 lifted_66c07d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c07d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(215));  // @1_66c07d
  ecx = edx = 0;  // @2_66c07d
  return eax;  // @3_66c07d
}
PCREG(66c07d, lifted_66c07d);

extern "C" u32 lifted_66c092(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c092
  eax = ext_634273_cdecl2((u32)(eax), (u32)(247));  // @1_66c092
  ecx = edx = 0;  // @2_66c092
  return eax;  // @3_66c092
}
PCREG(66c092, lifted_66c092);

extern "C" u32 lifted_66c0a7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c0a7
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66c0a7
  ecx = edx = 0;  // @2_66c0a7
  return eax;  // @3_66c0a7
}
PCREG(66c0a7, lifted_66c0a7);

extern "C" u32 lifted_66c0bc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c0bc
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66c0bc
  ecx = edx = 0;  // @2_66c0bc
  return eax;  // @3_66c0bc
}
PCREG(66c0bc, lifted_66c0bc);

extern "C" u32 lifted_66c0d1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c0d1
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66c0d1
  ecx = edx = 0;  // @2_66c0d1
  return eax;  // @3_66c0d1
}
PCREG(66c0d1, lifted_66c0d1);

extern "C" u32 lifted_66c0e6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c0e6
  eax = ext_634273_cdecl2((u32)(eax), (u32)(33));  // @1_66c0e6
  ecx = edx = 0;  // @2_66c0e6
  return eax;  // @3_66c0e6
}
PCREG(66c0e6, lifted_66c0e6);

extern "C" u32 lifted_66c0f8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c0f8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(247));  // @1_66c0f8
  ecx = edx = 0;  // @2_66c0f8
  return eax;  // @3_66c0f8
}
PCREG(66c0f8, lifted_66c0f8);

extern "C" u32 lifted_66c10d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c10d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(247));  // @1_66c10d
  ecx = edx = 0;  // @2_66c10d
  return eax;  // @3_66c10d
}
PCREG(66c10d, lifted_66c10d);

extern "C" u32 lifted_66c122(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c122
  eax = ext_634273_cdecl2((u32)(eax), (u32)(153));  // @1_66c122
  ecx = edx = 0;  // @2_66c122
  return eax;  // @3_66c122
}
PCREG(66c122, lifted_66c122);

extern "C" u32 lifted_66c137(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c137
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66c137
  ecx = edx = 0;  // @2_66c137
  return eax;  // @3_66c137
}
PCREG(66c137, lifted_66c137);

extern "C" u32 lifted_66c14c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c14c
  eax = ext_634273_cdecl2((u32)(eax), (u32)(199));  // @1_66c14c
  ecx = edx = 0;  // @2_66c14c
  return eax;  // @3_66c14c
}
PCREG(66c14c, lifted_66c14c);

extern "C" u32 lifted_66c161(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @0_66c161
  eax = ext_634273_cdecl2((u32)(eax), (u32)(215));  // @1_66c161
  ecx = edx = 0;  // @2_66c161
  return eax;  // @3_66c161
}
PCREG(66c161, lifted_66c161);

extern "C" u32 lifted_66c1d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_66c1d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(215));  // @1_66c1d0
  ecx = edx = 0;  // @2_66c1d0
  return eax;  // @3_66c1d0
}
PCREG(66c1d0, lifted_66c1d0);

extern "C" u32 lifted_66c200(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66c200
  eax = ext_634273_cdecl2((u32)(eax), (u32)(215));  // @1_66c200
  ecx = edx = 0;  // @2_66c200
  return eax;  // @3_66c200
}
PCREG(66c200, lifted_66c200);

extern "C" u32 lifted_66c2a8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66c2a8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66c2a8
  ecx = edx = 0;  // @2_66c2a8
  return eax;  // @3_66c2a8
}
PCREG(66c2a8, lifted_66c2a8);

extern "C" u32 lifted_66c2e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c2e0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(16));  // @1_66c2e0
  ecx = edx = 0;  // @2_66c2e0
  return eax;  // @3_66c2e0
}
PCREG(66c2e0, lifted_66c2e0);

extern "C" u32 lifted_66c2ef(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c2ef
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66c2ef
  ecx = edx = 0;  // @2_66c2ef
  return eax;  // @3_66c2ef
}
PCREG(66c2ef, lifted_66c2ef);

extern "C" u32 lifted_66c320(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_66c320
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c320
  ecx = edx = 0;  // @2_66c320
  return eax;  // @3_66c320
}
PCREG(66c320, lifted_66c320);

extern "C" u32 lifted_66c332(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_66c332
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c332
  ecx = edx = 0;  // @2_66c332
  return eax;  // @3_66c332
}
PCREG(66c332, lifted_66c332);

extern "C" u32 lifted_66c380(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @0_66c380
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c380
  ecx = edx = 0;  // @2_66c380
  return eax;  // @3_66c380
}
PCREG(66c380, lifted_66c380);

extern "C" u32 lifted_66c38f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @0_66c38f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c38f
  ecx = edx = 0;  // @2_66c38f
  return eax;  // @3_66c38f
}
PCREG(66c38f, lifted_66c38f);

extern "C" u32 lifted_66c3c8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66c3c8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66c3c8
  ecx = edx = 0;  // @2_66c3c8
  return eax;  // @3_66c3c8
}
PCREG(66c3c8, lifted_66c3c8);

extern "C" u32 lifted_66c490(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @0_66c490
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66c490
  ecx = edx = 0;  // @2_66c490
  return eax;  // @3_66c490
}
PCREG(66c490, lifted_66c490);

extern "C" u32 lifted_66c4d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @0_66c4d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66c4d0
  ecx = edx = 0;  // @2_66c4d0
  return eax;  // @3_66c4d0
}
PCREG(66c4d0, lifted_66c4d0);

extern "C" u32 lifted_66c510(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66c510
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66c510
  ecx = edx = 0;  // @2_66c510
  return eax;  // @3_66c510
}
PCREG(66c510, lifted_66c510);

extern "C" u32 lifted_66c648(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66c648
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c648
  ecx = edx = 0;  // @2_66c648
  return eax;  // @3_66c648
}
PCREG(66c648, lifted_66c648);

extern "C" u32 lifted_66c657(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66c657
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c657
  ecx = edx = 0;  // @2_66c657
  return eax;  // @3_66c657
}
PCREG(66c657, lifted_66c657);

extern "C" u32 lifted_66c666(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66c666
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c666
  ecx = edx = 0;  // @2_66c666
  return eax;  // @3_66c666
}
PCREG(66c666, lifted_66c666);

extern "C" u32 lifted_66c675(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66c675
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c675
  ecx = edx = 0;  // @2_66c675
  return eax;  // @3_66c675
}
PCREG(66c675, lifted_66c675);

extern "C" u32 lifted_66c684(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66c684
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c684
  ecx = edx = 0;  // @2_66c684
  return eax;  // @3_66c684
}
PCREG(66c684, lifted_66c684);

extern "C" u32 lifted_66c720(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c720
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c720
  ecx = edx = 0;  // @2_66c720
  return eax;  // @3_66c720
}
PCREG(66c720, lifted_66c720);

extern "C" u32 lifted_66c72f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66c72f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c72f
  ecx = edx = 0;  // @2_66c72f
  return eax;  // @3_66c72f
}
PCREG(66c72f, lifted_66c72f);

extern "C" u32 lifted_66c73e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66c73e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c73e
  ecx = edx = 0;  // @2_66c73e
  return eax;  // @3_66c73e
}
PCREG(66c73e, lifted_66c73e);

extern "C" u32 lifted_66c74d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @0_66c74d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c74d
  ecx = edx = 0;  // @2_66c74d
  return eax;  // @3_66c74d
}
PCREG(66c74d, lifted_66c74d);

extern "C" u32 lifted_66c780(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66c780
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c780
  ecx = edx = 0;  // @2_66c780
  return eax;  // @3_66c780
}
PCREG(66c780, lifted_66c780);

extern "C" u32 lifted_66c78f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @0_66c78f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c78f
  ecx = edx = 0;  // @2_66c78f
  return eax;  // @3_66c78f
}
PCREG(66c78f, lifted_66c78f);

extern "C" u32 lifted_66c79e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @0_66c79e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c79e
  ecx = edx = 0;  // @2_66c79e
  return eax;  // @3_66c79e
}
PCREG(66c79e, lifted_66c79e);

extern "C" u32 lifted_66c7ad(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66c7ad
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c7ad
  ecx = edx = 0;  // @2_66c7ad
  return eax;  // @3_66c7ad
}
PCREG(66c7ad, lifted_66c7ad);

extern "C" u32 lifted_66c7e8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66c7e8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66c7e8
  ecx = edx = 0;  // @2_66c7e8
  return eax;  // @3_66c7e8
}
PCREG(66c7e8, lifted_66c7e8);

extern "C" u32 lifted_66c858(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @0_66c858
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66c858
  ecx = edx = 0;  // @2_66c858
  return eax;  // @3_66c858
}
PCREG(66c858, lifted_66c858);

extern "C" u32 lifted_66c890(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c890
  eax = ext_634273_cdecl2((u32)(eax), (u32)(144));  // @1_66c890
  ecx = edx = 0;  // @2_66c890
  return eax;  // @3_66c890
}
PCREG(66c890, lifted_66c890);

extern "C" u32 lifted_66c948(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66c948
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66c948
  ecx = edx = 0;  // @2_66c948
  return eax;  // @3_66c948
}
PCREG(66c948, lifted_66c948);

extern "C" u32 lifted_66ca20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @0_66ca20
  eax = ext_634273_cdecl2((u32)(eax), (u32)(16));  // @1_66ca20
  ecx = edx = 0;  // @2_66ca20
  return eax;  // @3_66ca20
}
PCREG(66ca20, lifted_66ca20);

extern "C" u32 lifted_66ca2f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @0_66ca2f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(41));  // @1_66ca2f
  ecx = edx = 0;  // @2_66ca2f
  return eax;  // @3_66ca2f
}
PCREG(66ca2f, lifted_66ca2f);

extern "C" u32 lifted_66ca3e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66ca3e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(41));  // @1_66ca3e
  ecx = edx = 0;  // @2_66ca3e
  return eax;  // @3_66ca3e
}
PCREG(66ca3e, lifted_66ca3e);

extern "C" u32 lifted_66ca4d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66ca4d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(41));  // @1_66ca4d
  ecx = edx = 0;  // @2_66ca4d
  return eax;  // @3_66ca4d
}
PCREG(66ca4d, lifted_66ca4d);

extern "C" u32 lifted_66cba0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_66cba0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cba0
  ecx = edx = 0;  // @2_66cba0
  return eax;  // @3_66cba0
}
PCREG(66cba0, lifted_66cba0);

extern "C" u32 lifted_66cbb2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_66cbb2
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cbb2
  ecx = edx = 0;  // @2_66cbb2
  return eax;  // @3_66cbb2
}
PCREG(66cbb2, lifted_66cbb2);

extern "C" u32 lifted_66cbe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66cbe0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cbe0
  ecx = edx = 0;  // @2_66cbe0
  return eax;  // @3_66cbe0
}
PCREG(66cbe0, lifted_66cbe0);

extern "C" u32 lifted_66cc10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cc10
  eax = ext_634273_cdecl2((u32)(eax), (u32)(215));  // @1_66cc10
  ecx = edx = 0;  // @2_66cc10
  return eax;  // @3_66cc10
}
PCREG(66cc10, lifted_66cc10);

extern "C" u32 lifted_66cc22(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cc22
  eax = ext_634273_cdecl2((u32)(eax), (u32)(247));  // @1_66cc22
  ecx = edx = 0;  // @2_66cc22
  return eax;  // @3_66cc22
}
PCREG(66cc22, lifted_66cc22);

extern "C" u32 lifted_66cc34(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cc34
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cc34
  ecx = edx = 0;  // @2_66cc34
  return eax;  // @3_66cc34
}
PCREG(66cc34, lifted_66cc34);

extern "C" u32 lifted_66cc78(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66cc78
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cc78
  ecx = edx = 0;  // @2_66cc78
  return eax;  // @3_66cc78
}
PCREG(66cc78, lifted_66cc78);

extern "C" u32 lifted_66cc8a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66cc8a
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cc8a
  ecx = edx = 0;  // @2_66cc8a
  return eax;  // @3_66cc8a
}
PCREG(66cc8a, lifted_66cc8a);

extern "C" u32 lifted_66cc9c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66cc9c
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cc9c
  ecx = edx = 0;  // @2_66cc9c
  return eax;  // @3_66cc9c
}
PCREG(66cc9c, lifted_66cc9c);

extern "C" u32 lifted_66ccd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_66ccd0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(247));  // @1_66ccd0
  ecx = edx = 0;  // @2_66ccd0
  return eax;  // @3_66ccd0
}
PCREG(66ccd0, lifted_66ccd0);

extern "C" u32 lifted_66cd00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66cd00
  eax = ext_634273_cdecl2((u32)(eax), (u32)(247));  // @1_66cd00
  ecx = edx = 0;  // @2_66cd00
  return eax;  // @3_66cd00
}
PCREG(66cd00, lifted_66cd00);

extern "C" u32 lifted_66cd30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cd30
  eax = ext_634273_cdecl2((u32)(eax), (u32)(168));  // @1_66cd30
  ecx = edx = 0;  // @2_66cd30
  return eax;  // @3_66cd30
}
PCREG(66cd30, lifted_66cd30);

extern "C" u32 lifted_66cdd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66cdd0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(25));  // @1_66cdd0
  ecx = edx = 0;  // @2_66cdd0
  return eax;  // @3_66cdd0
}
PCREG(66cdd0, lifted_66cdd0);

extern "C" u32 lifted_66cddf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66cddf
  eax = ext_634273_cdecl2((u32)(eax), (u32)(77));  // @1_66cddf
  ecx = edx = 0;  // @2_66cddf
  return eax;  // @3_66cddf
}
PCREG(66cddf, lifted_66cddf);

extern "C" u32 lifted_66ce38(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66ce38
  eax = ext_634273_cdecl2((u32)(eax), (u32)(184));  // @1_66ce38
  ecx = edx = 0;  // @2_66ce38
  return eax;  // @3_66ce38
}
PCREG(66ce38, lifted_66ce38);

extern "C" u32 lifted_66cf70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cf70
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66cf70
  ecx = edx = 0;  // @2_66cf70
  return eax;  // @3_66cf70
}
PCREG(66cf70, lifted_66cf70);

extern "C" u32 lifted_66cfd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cfd0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(16));  // @1_66cfd0
  ecx = edx = 0;  // @2_66cfd0
  return eax;  // @3_66cfd0
}
PCREG(66cfd0, lifted_66cfd0);

extern "C" u32 lifted_66d040(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d040
  eax = ext_634273_cdecl2((u32)(eax), (u32)(18));  // @1_66d040
  ecx = edx = 0;  // @2_66d040
  return eax;  // @3_66d040
}
PCREG(66d040, lifted_66d040);

extern "C" u32 lifted_66d070(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d070
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66d070
  ecx = edx = 0;  // @2_66d070
  return eax;  // @3_66d070
}
PCREG(66d070, lifted_66d070);

extern "C" u32 lifted_66d1c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66d1c0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(72));  // @1_66d1c0
  ecx = edx = 0;  // @2_66d1c0
  return eax;  // @3_66d1c0
}
PCREG(66d1c0, lifted_66d1c0);

extern "C" u32 lifted_66d200(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @0_66d200
  eax = ext_634273_cdecl2((u32)(eax), (u32)(12));  // @1_66d200
  ecx = edx = 0;  // @2_66d200
  return eax;  // @3_66d200
}
PCREG(66d200, lifted_66d200);

extern "C" u32 lifted_66d230(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @0_66d230
  eax = ext_634273_cdecl2((u32)(eax), (u32)(12));  // @1_66d230
  ecx = edx = 0;  // @2_66d230
  return eax;  // @3_66d230
}
PCREG(66d230, lifted_66d230);

extern "C" u32 lifted_66d4f8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @0_66d4f8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(2770));  // @1_66d4f8
  ecx = edx = 0;  // @2_66d4f8
  return eax;  // @3_66d4f8
}
PCREG(66d4f8, lifted_66d4f8);

extern "C" u32 lifted_66d50a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @0_66d50a
  eax = ext_634273_cdecl2((u32)(eax), (u32)(2770));  // @1_66d50a
  ecx = edx = 0;  // @2_66d50a
  return eax;  // @3_66d50a
}
PCREG(66d50a, lifted_66d50a);

extern "C" u32 lifted_66d589(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @0_66d589
  eax = ext_634273_cdecl2((u32)(eax), (u32)(382));  // @1_66d589
  ecx = edx = 0;  // @2_66d589
  return eax;  // @3_66d589
}
PCREG(66d589, lifted_66d589);

extern "C" u32 lifted_66d5f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_66d5f0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(2770));  // @1_66d5f0
  ecx = edx = 0;  // @2_66d5f0
  return eax;  // @3_66d5f0
}
PCREG(66d5f0, lifted_66d5f0);

extern "C" u32 lifted_66d720(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @0_66d720
  eax = ext_634273_cdecl2((u32)(eax), (u32)(9));  // @1_66d720
  ecx = edx = 0;  // @2_66d720
  return eax;  // @3_66d720
}
PCREG(66d720, lifted_66d720);

extern "C" u32 lifted_66d850(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d850
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66d850
  ecx = edx = 0;  // @2_66d850
  return eax;  // @3_66d850
}
PCREG(66d850, lifted_66d850);

extern "C" u32 lifted_66d85f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66d85f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(12));  // @1_66d85f
  ecx = edx = 0;  // @2_66d85f
  return eax;  // @3_66d85f
}
PCREG(66d85f, lifted_66d85f);

extern "C" u32 lifted_66d8f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d8f0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(42));  // @1_66d8f0
  ecx = edx = 0;  // @2_66d8f0
  return eax;  // @3_66d8f0
}
PCREG(66d8f0, lifted_66d8f0);

extern "C" u32 lifted_66d930(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d930
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @1_66d930
  ecx = edx = 0;  // @2_66d930
  return eax;  // @3_66d930
}
PCREG(66d930, lifted_66d930);

extern "C" u32 lifted_66dae8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dae8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(48));  // @1_66dae8
  ecx = edx = 0;  // @2_66dae8
  return eax;  // @3_66dae8
}
PCREG(66dae8, lifted_66dae8);

extern "C" u32 lifted_66daf7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @0_66daf7
  eax = ext_634273_cdecl2((u32)(eax), (u32)(40));  // @1_66daf7
  ecx = edx = 0;  // @2_66daf7
  return eax;  // @3_66daf7
}
PCREG(66daf7, lifted_66daf7);

extern "C" u32 lifted_66db38(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @0_66db38
  eax = ext_634273_cdecl2((u32)(eax), (u32)(48));  // @1_66db38
  ecx = edx = 0;  // @2_66db38
  return eax;  // @3_66db38
}
PCREG(66db38, lifted_66db38);

extern "C" u32 lifted_66db47(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @0_66db47
  eax = ext_634273_cdecl2((u32)(eax), (u32)(40));  // @1_66db47
  ecx = edx = 0;  // @2_66db47
  return eax;  // @3_66db47
}
PCREG(66db47, lifted_66db47);

extern "C" u32 lifted_66db88(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_66db88
  eax = ext_634273_cdecl2((u32)(eax), (u32)(48));  // @1_66db88
  ecx = edx = 0;  // @2_66db88
  return eax;  // @3_66db88
}
PCREG(66db88, lifted_66db88);

extern "C" u32 lifted_66db97(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_66db97
  eax = ext_634273_cdecl2((u32)(eax), (u32)(40));  // @1_66db97
  ecx = edx = 0;  // @2_66db97
  return eax;  // @3_66db97
}
PCREG(66db97, lifted_66db97);

extern "C" u32 lifted_66dc00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dc00
  eax = ext_634273_cdecl2((u32)(eax), (u32)(26));  // @1_66dc00
  ecx = edx = 0;  // @2_66dc00
  return eax;  // @3_66dc00
}
PCREG(66dc00, lifted_66dc00);

extern "C" u32 lifted_66dc90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dc90
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66dc90
  ecx = edx = 0;  // @2_66dc90
  return eax;  // @3_66dc90
}
PCREG(66dc90, lifted_66dc90);

extern "C" u32 lifted_66dcc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dcc0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @1_66dcc0
  ecx = edx = 0;  // @2_66dcc0
  return eax;  // @3_66dcc0
}
PCREG(66dcc0, lifted_66dcc0);

extern "C" u32 lifted_66dd30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dd30
  eax = ext_634273_cdecl2((u32)(eax), (u32)(42));  // @1_66dd30
  ecx = edx = 0;  // @2_66dd30
  return eax;  // @3_66dd30
}
PCREG(66dd30, lifted_66dd30);

extern "C" u32 lifted_66dd90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dd90
  eax = ext_634273_cdecl2((u32)(eax), (u32)(18));  // @1_66dd90
  ecx = edx = 0;  // @2_66dd90
  return eax;  // @3_66dd90
}
PCREG(66dd90, lifted_66dd90);

extern "C" u32 lifted_66ddd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ddd0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(18));  // @1_66ddd0
  ecx = edx = 0;  // @2_66ddd0
  return eax;  // @3_66ddd0
}
PCREG(66ddd0, lifted_66ddd0);

extern "C" u32 lifted_66e000(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @0_66e000
  eax = ext_634273_cdecl2((u32)(eax), (u32)(72));  // @1_66e000
  ecx = edx = 0;  // @2_66e000
  return eax;  // @3_66e000
}
PCREG(66e000, lifted_66e000);

extern "C" u32 lifted_66e030(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e030
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @1_66e030
  ecx = edx = 0;  // @2_66e030
  return eax;  // @3_66e030
}
PCREG(66e030, lifted_66e030);

extern "C" u32 lifted_66e0a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e0a0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(5366));  // @1_66e0a0
  ecx = edx = 0;  // @2_66e0a0
  return eax;  // @3_66e0a0
}
PCREG(66e0a0, lifted_66e0a0);

extern "C" u32 lifted_66e0d8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66e0d8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(47540));  // @1_66e0d8
  ecx = edx = 0;  // @2_66e0d8
  return eax;  // @3_66e0d8
}
PCREG(66e0d8, lifted_66e0d8);

extern "C" u32 lifted_66e110(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @0_66e110
  eax = ext_634273_cdecl2((u32)(eax), (u32)(52));  // @1_66e110
  ecx = edx = 0;  // @2_66e110
  return eax;  // @3_66e110
}
PCREG(66e110, lifted_66e110);

extern "C" u32 lifted_66e12d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e12d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(42));  // @1_66e12d
  ecx = edx = 0;  // @2_66e12d
  return eax;  // @3_66e12d
}
PCREG(66e12d, lifted_66e12d);

extern "C" u32 lifted_66e13f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e13f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(42));  // @1_66e13f
  ecx = edx = 0;  // @2_66e13f
  return eax;  // @3_66e13f
}
PCREG(66e13f, lifted_66e13f);

extern "C" u32 lifted_66e151(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e151
  eax = ext_634273_cdecl2((u32)(eax), (u32)(34));  // @1_66e151
  ecx = edx = 0;  // @2_66e151
  return eax;  // @3_66e151
}
PCREG(66e151, lifted_66e151);

extern "C" u32 lifted_66e163(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e163
  eax = ext_634273_cdecl2((u32)(eax), (u32)(52));  // @1_66e163
  ecx = edx = 0;  // @2_66e163
  return eax;  // @3_66e163
}
PCREG(66e163, lifted_66e163);

extern "C" u32 lifted_66e180(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e180
  eax = ext_634273_cdecl2((u32)(eax), (u32)(52));  // @1_66e180
  ecx = edx = 0;  // @2_66e180
  return eax;  // @3_66e180
}
PCREG(66e180, lifted_66e180);

extern "C" u32 lifted_66e19d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e19d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(52));  // @1_66e19d
  ecx = edx = 0;  // @2_66e19d
  return eax;  // @3_66e19d
}
PCREG(66e19d, lifted_66e19d);

extern "C" u32 lifted_66e1ba(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e1ba
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66e1ba
  ecx = edx = 0;  // @2_66e1ba
  return eax;  // @3_66e1ba
}
PCREG(66e1ba, lifted_66e1ba);

extern "C" u32 lifted_66e1d7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e1d7
  eax = ext_634273_cdecl2((u32)(eax), (u32)(308));  // @1_66e1d7
  ecx = edx = 0;  // @2_66e1d7
  return eax;  // @3_66e1d7
}
PCREG(66e1d7, lifted_66e1d7);

extern "C" u32 lifted_66e270(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1152), sizeof v); (u32)v; });  // @0_66e270
  eax = ext_634273_cdecl2((u32)(eax), (u32)(139628));  // @1_66e270
  ecx = edx = 0;  // @2_66e270
  return eax;  // @3_66e270
}
PCREG(66e270, lifted_66e270);

extern "C" u32 lifted_66e440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e440
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e440
  ecx = edx = 0;  // @2_66e440
  return eax;  // @3_66e440
}
PCREG(66e440, lifted_66e440);

extern "C" u32 lifted_66e44f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e44f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e44f
  ecx = edx = 0;  // @2_66e44f
  return eax;  // @3_66e44f
}
PCREG(66e44f, lifted_66e44f);

extern "C" u32 lifted_66e45e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e45e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e45e
  ecx = edx = 0;  // @2_66e45e
  return eax;  // @3_66e45e
}
PCREG(66e45e, lifted_66e45e);

extern "C" u32 lifted_66e490(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e490
  eax = ext_634273_cdecl2((u32)(eax), (u32)(98990));  // @1_66e490
  ecx = edx = 0;  // @2_66e490
  return eax;  // @3_66e490
}
PCREG(66e490, lifted_66e490);

extern "C" u32 lifted_66e548(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_66e548
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66e548
  ecx = edx = 0;  // @2_66e548
  return eax;  // @3_66e548
}
PCREG(66e548, lifted_66e548);

extern "C" u32 lifted_66e580(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e580
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e580
  ecx = edx = 0;  // @2_66e580
  return eax;  // @3_66e580
}
PCREG(66e580, lifted_66e580);

extern "C" u32 lifted_66e58f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e58f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e58f
  ecx = edx = 0;  // @2_66e58f
  return eax;  // @3_66e58f
}
PCREG(66e58f, lifted_66e58f);

extern "C" u32 lifted_66e7d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e7d0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e7d0
  ecx = edx = 0;  // @2_66e7d0
  return eax;  // @3_66e7d0
}
PCREG(66e7d0, lifted_66e7d0);

extern "C" u32 lifted_66e7df(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e7df
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e7df
  ecx = edx = 0;  // @2_66e7df
  return eax;  // @3_66e7df
}
PCREG(66e7df, lifted_66e7df);

extern "C" u32 lifted_66e7ee(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e7ee
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e7ee
  ecx = edx = 0;  // @2_66e7ee
  return eax;  // @3_66e7ee
}
PCREG(66e7ee, lifted_66e7ee);

extern "C" u32 lifted_66e7fd(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e7fd
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e7fd
  ecx = edx = 0;  // @2_66e7fd
  return eax;  // @3_66e7fd
}
PCREG(66e7fd, lifted_66e7fd);

extern "C" u32 lifted_66e80c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e80c
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e80c
  ecx = edx = 0;  // @2_66e80c
  return eax;  // @3_66e80c
}
PCREG(66e80c, lifted_66e80c);

extern "C" u32 lifted_66e81b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e81b
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e81b
  ecx = edx = 0;  // @2_66e81b
  return eax;  // @3_66e81b
}
PCREG(66e81b, lifted_66e81b);

extern "C" u32 lifted_66e82a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e82a
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e82a
  ecx = edx = 0;  // @2_66e82a
  return eax;  // @3_66e82a
}
PCREG(66e82a, lifted_66e82a);

extern "C" u32 lifted_66e839(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e839
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66e839
  ecx = edx = 0;  // @2_66e839
  return eax;  // @3_66e839
}
PCREG(66e839, lifted_66e839);

extern "C" u32 lifted_66e8f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e8f0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66e8f0
  ecx = edx = 0;  // @2_66e8f0
  return eax;  // @3_66e8f0
}
PCREG(66e8f0, lifted_66e8f0);

extern "C" u32 lifted_66e902(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e902
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66e902
  ecx = edx = 0;  // @2_66e902
  return eax;  // @3_66e902
}
PCREG(66e902, lifted_66e902);

extern "C" u32 lifted_66e914(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e914
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66e914
  ecx = edx = 0;  // @2_66e914
  return eax;  // @3_66e914
}
PCREG(66e914, lifted_66e914);

extern "C" u32 lifted_66e980(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66e980
  eax = ext_634273_cdecl2((u32)(eax), (u32)(101));  // @1_66e980
  ecx = edx = 0;  // @2_66e980
  return eax;  // @3_66e980
}
PCREG(66e980, lifted_66e980);

extern "C" u32 lifted_66eac0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eac0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eac0
  ecx = edx = 0;  // @2_66eac0
  return eax;  // @3_66eac0
}
PCREG(66eac0, lifted_66eac0);

extern "C" u32 lifted_66eacf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eacf
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eacf
  ecx = edx = 0;  // @2_66eacf
  return eax;  // @3_66eacf
}
PCREG(66eacf, lifted_66eacf);

extern "C" u32 lifted_66eade(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eade
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eade
  ecx = edx = 0;  // @2_66eade
  return eax;  // @3_66eade
}
PCREG(66eade, lifted_66eade);

extern "C" u32 lifted_66eaed(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eaed
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eaed
  ecx = edx = 0;  // @2_66eaed
  return eax;  // @3_66eaed
}
PCREG(66eaed, lifted_66eaed);

extern "C" u32 lifted_66eafc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eafc
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eafc
  ecx = edx = 0;  // @2_66eafc
  return eax;  // @3_66eafc
}
PCREG(66eafc, lifted_66eafc);

extern "C" u32 lifted_66eb0b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eb0b
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eb0b
  ecx = edx = 0;  // @2_66eb0b
  return eax;  // @3_66eb0b
}
PCREG(66eb0b, lifted_66eb0b);

extern "C" u32 lifted_66eb1a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eb1a
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eb1a
  ecx = edx = 0;  // @2_66eb1a
  return eax;  // @3_66eb1a
}
PCREG(66eb1a, lifted_66eb1a);

extern "C" u32 lifted_66eb29(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eb29
  eax = ext_634273_cdecl2((u32)(eax), (u32)(20));  // @1_66eb29
  ecx = edx = 0;  // @2_66eb29
  return eax;  // @3_66eb29
}
PCREG(66eb29, lifted_66eb29);

extern "C" u32 lifted_66eb6e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66eb6e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(44));  // @1_66eb6e
  ecx = edx = 0;  // @2_66eb6e
  return eax;  // @3_66eb6e
}
PCREG(66eb6e, lifted_66eb6e);

extern "C" u32 lifted_66eb7d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66eb7d
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66eb7d
  ecx = edx = 0;  // @2_66eb7d
  return eax;  // @3_66eb7d
}
PCREG(66eb7d, lifted_66eb7d);

extern "C" u32 lifted_66eb8f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66eb8f
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66eb8f
  ecx = edx = 0;  // @2_66eb8f
  return eax;  // @3_66eb8f
}
PCREG(66eb8f, lifted_66eb8f);

extern "C" u32 lifted_66eba1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66eba1
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66eba1
  ecx = edx = 0;  // @2_66eba1
  return eax;  // @3_66eba1
}
PCREG(66eba1, lifted_66eba1);

extern "C" u32 lifted_66ebb3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66ebb3
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ebb3
  ecx = edx = 0;  // @2_66ebb3
  return eax;  // @3_66ebb3
}
PCREG(66ebb3, lifted_66ebb3);

extern "C" u32 lifted_66ebc5(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66ebc5
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ebc5
  ecx = edx = 0;  // @2_66ebc5
  return eax;  // @3_66ebc5
}
PCREG(66ebc5, lifted_66ebc5);

extern "C" u32 lifted_66ebd7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66ebd7
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ebd7
  ecx = edx = 0;  // @2_66ebd7
  return eax;  // @3_66ebd7
}
PCREG(66ebd7, lifted_66ebd7);

extern "C" u32 lifted_66ebe9(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66ebe9
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ebe9
  ecx = edx = 0;  // @2_66ebe9
  return eax;  // @3_66ebe9
}
PCREG(66ebe9, lifted_66ebe9);

extern "C" u32 lifted_66ec50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ec50
  eax = ext_634273_cdecl2((u32)(eax), (u32)(662));  // @1_66ec50
  ecx = edx = 0;  // @2_66ec50
  return eax;  // @3_66ec50
}
PCREG(66ec50, lifted_66ec50);

extern "C" u32 lifted_66ec80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ec80
  eax = ext_634273_cdecl2((u32)(eax), (u32)(49));  // @1_66ec80
  ecx = edx = 0;  // @2_66ec80
  return eax;  // @3_66ec80
}
PCREG(66ec80, lifted_66ec80);

extern "C" u32 lifted_66ecb8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66ecb8
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ecb8
  ecx = edx = 0;  // @2_66ecb8
  return eax;  // @3_66ecb8
}
PCREG(66ecb8, lifted_66ecb8);

extern "C" u32 lifted_66ecca(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66ecca
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ecca
  ecx = edx = 0;  // @2_66ecca
  return eax;  // @3_66ecca
}
PCREG(66ecca, lifted_66ecca);

extern "C" u32 lifted_66ecdc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66ecdc
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ecdc
  ecx = edx = 0;  // @2_66ecdc
  return eax;  // @3_66ecdc
}
PCREG(66ecdc, lifted_66ecdc);

extern "C" u32 lifted_66ed10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ed10
  eax = ext_634273_cdecl2((u32)(eax), (u32)(8625));  // @1_66ed10
  ecx = edx = 0;  // @2_66ed10
  return eax;  // @3_66ed10
}
PCREG(66ed10, lifted_66ed10);

extern "C" u32 lifted_66ed48(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66ed48
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ed48
  ecx = edx = 0;  // @2_66ed48
  return eax;  // @3_66ed48
}
PCREG(66ed48, lifted_66ed48);

extern "C" u32 lifted_66ed5a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66ed5a
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ed5a
  ecx = edx = 0;  // @2_66ed5a
  return eax;  // @3_66ed5a
}
PCREG(66ed5a, lifted_66ed5a);

extern "C" u32 lifted_66ed6c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66ed6c
  eax = ext_634273_cdecl2((u32)(eax), (u32)(264));  // @1_66ed6c
  ecx = edx = 0;  // @2_66ed6c
  return eax;  // @3_66ed6c
}
PCREG(66ed6c, lifted_66ed6c);

extern "C" u32 lifted_66ed7e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66ed7e
  eax = ext_634273_cdecl2((u32)(eax), (u32)(28));  // @1_66ed7e
  ecx = edx = 0;  // @2_66ed7e
  return eax;  // @3_66ed7e
}
PCREG(66ed7e, lifted_66ed7e);

extern "C" u32 lifted_66edb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66edb0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(98981));  // @1_66edb0
  ecx = edx = 0;  // @2_66edb0
  return eax;  // @3_66edb0
}
PCREG(66edb0, lifted_66edb0);

extern "C" u32 lifted_66ee20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ee20
  eax = ext_634273_cdecl2((u32)(eax), (u32)(40));  // @1_66ee20
  ecx = edx = 0;  // @2_66ee20
  return eax;  // @3_66ee20
}
PCREG(66ee20, lifted_66ee20);

extern "C" u32 lifted_66ee50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66ee50
  eax = ext_634273_cdecl2((u32)(eax), (u32)(40));  // @1_66ee50
  ecx = edx = 0;  // @2_66ee50
  return eax;  // @3_66ee50
}
PCREG(66ee50, lifted_66ee50);

extern "C" u32 lifted_665e10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665e10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_665e10
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_665e10
  ecx = edx = 0;  // @3_665e10
  return eax;  // @4_665e10
}
PCREG(665e10, lifted_665e10);

extern "C" u32 lifted_666150(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_666150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_666150
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_666150
  ecx = edx = 0;  // @3_666150
  return eax;  // @4_666150
}
PCREG(666150, lifted_666150);

extern "C" u32 lifted_666250(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @1_666250
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_666250
  ecx = edx = 0;  // @3_666250
  return eax;  // @4_666250
}
PCREG(666250, lifted_666250);

extern "C" u32 lifted_666520(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_666520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_666520
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_666520
  ecx = edx = 0;  // @3_666520
  return eax;  // @4_666520
}
PCREG(666520, lifted_666520);

extern "C" u32 lifted_666ce0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @1_666ce0
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_666ce0
  ecx = edx = 0;  // @3_666ce0
  return eax;  // @4_666ce0
}
PCREG(666ce0, lifted_666ce0);

extern "C" u32 lifted_6670d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6670d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_6670d0
  eax = ext_476540_cdecl2((u32)(eax), (u32)(eax));  // @2_6670d0
  ecx = edx = 0;  // @3_6670d0
  return eax;  // @4_6670d0
}
PCREG(6670d0, lifted_6670d0);

extern "C" u32 lifted_667340(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_667340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_667340
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_667340
  ecx = edx = 0;  // @3_667340
  return eax;  // @4_667340
}
PCREG(667340, lifted_667340);

extern "C" u32 lifted_668570(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_668570
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_668570
  ecx = edx = 0;  // @3_668570
  return eax;  // @4_668570
}
PCREG(668570, lifted_668570);

extern "C" u32 lifted_668710(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_668710
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_668710
  ecx = edx = 0;  // @3_668710
  return eax;  // @4_668710
}
PCREG(668710, lifted_668710);

extern "C" u32 lifted_668a70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_668a70
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_668a70
  ecx = edx = 0;  // @3_668a70
  return eax;  // @4_668a70
}
PCREG(668a70, lifted_668a70);

extern "C" u32 lifted_668cc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_668cc0
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_668cc0
  ecx = edx = 0;  // @3_668cc0
  return eax;  // @4_668cc0
}
PCREG(668cc0, lifted_668cc0);

extern "C" u32 lifted_668d70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668d70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_668d70
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_668d70
  ecx = edx = 0;  // @3_668d70
  return eax;  // @4_668d70
}
PCREG(668d70, lifted_668d70);

extern "C" u32 lifted_66c820(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_66c820
  eax = ext_48aa80_cdecl2((u32)(eax), (u32)(eax));  // @2_66c820
  ecx = edx = 0;  // @3_66c820
  return eax;  // @4_66c820
}
PCREG(66c820, lifted_66c820);

extern "C" u32 lifted_66507c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66507c
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @1_66507c
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_66507c
  ecx = edx = 0;  // @3_66507c
  return eax;  // @4_66507c
}
PCREG(66507c, lifted_66507c);

extern "C" u32 lifted_66508d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @0_66508d
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @1_66508d
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_66508d
  ecx = edx = 0;  // @3_66508d
  return eax;  // @4_66508d
}
PCREG(66508d, lifted_66508d);

extern "C" u32 lifted_6652b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_6652b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_6652b0
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_6652b0
  ecx = edx = 0;  // @3_6652b0
  return eax;  // @4_6652b0
}
PCREG(6652b0, lifted_6652b0);

extern "C" u32 lifted_6652f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6652f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_6652f0
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_6652f0
  ecx = edx = 0;  // @3_6652f0
  return eax;  // @4_6652f0
}
PCREG(6652f0, lifted_6652f0);

extern "C" u32 lifted_66530f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66530f
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_66530f
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_66530f
  ecx = edx = 0;  // @3_66530f
  return eax;  // @4_66530f
}
PCREG(66530f, lifted_66530f);

extern "C" u32 lifted_665370(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_665370
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_665370
  ecx = edx = 0;  // @3_665370
  return eax;  // @4_665370
}
PCREG(665370, lifted_665370);

extern "C" u32 lifted_665b6f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665b6f
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @1_665b6f
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_665b6f
  ecx = edx = 0;  // @3_665b6f
  return eax;  // @4_665b6f
}
PCREG(665b6f, lifted_665b6f);

extern "C" u32 lifted_6680c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_6680c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @1_6680c0
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_6680c0
  ecx = edx = 0;  // @3_6680c0
  return eax;  // @4_6680c0
}
PCREG(6680c0, lifted_6680c0);

extern "C" u32 lifted_6681f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @0_6681f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @1_6681f0
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_6681f0
  ecx = edx = 0;  // @3_6681f0
  return eax;  // @4_6681f0
}
PCREG(6681f0, lifted_6681f0);

extern "C" u32 lifted_66d460(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_66d460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_66d460
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_66d460
  ecx = edx = 0;  // @3_66d460
  return eax;  // @4_66d460
}
PCREG(66d460, lifted_66d460);

extern "C" u32 lifted_66d620(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_66d620
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_66d620
  ecx = edx = 0;  // @3_66d620
  return eax;  // @4_66d620
}
PCREG(66d620, lifted_66d620);

extern "C" u32 lifted_66dab0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_66dab0
  eax = ext_4690b0_cdecl2((u32)(eax), (u32)(eax));  // @2_66dab0
  ecx = edx = 0;  // @3_66dab0
  return eax;  // @4_66dab0
}
PCREG(66dab0, lifted_66dab0);

extern "C" u32 lifted_66a410(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a410
  eax = (eax + (u32)(189));  // @1_66a410
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(222), (u32)(4), (u32)(5332736));  // @2_66a410
  ecx = edx = 0;  // @3_66a410
  return eax;  // @4_66a410
}
PCREG(66a410, lifted_66a410);

extern "C" u32 lifted_66a42b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a42b
  eax = (eax + (u32)(1077));  // @1_66a42b
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(222), (u32)(4), (u32)(5332736));  // @2_66a42b
  ecx = edx = 0;  // @3_66a42b
  return eax;  // @4_66a42b
}
PCREG(66a42b, lifted_66a42b);

extern "C" u32 lifted_66a446(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a446
  eax = (eax + (u32)(1965));  // @1_66a446
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(355), (u32)(4), (u32)(5314864));  // @2_66a446
  ecx = edx = 0;  // @3_66a446
  return eax;  // @4_66a446
}
PCREG(66a446, lifted_66a446);

extern "C" u32 lifted_66a461(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a461
  eax = (eax + (u32)(3385));  // @1_66a461
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(307), (u32)(4), (u32)(5315248));  // @2_66a461
  ecx = edx = 0;  // @3_66a461
  return eax;  // @4_66a461
}
PCREG(66a461, lifted_66a461);

extern "C" u32 lifted_66a4a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a4a0
  eax = (eax + (u32)(149));  // @1_66a4a0
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(222), (u32)(8), (u32)(5332736));  // @2_66a4a0
  ecx = edx = 0;  // @3_66a4a0
  return eax;  // @4_66a4a0
}
PCREG(66a4a0, lifted_66a4a0);

extern "C" u32 lifted_66a4bb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a4bb
  eax = (eax + (u32)(1925));  // @1_66a4bb
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(222), (u32)(8), (u32)(5332736));  // @2_66a4bb
  ecx = edx = 0;  // @3_66a4bb
  return eax;  // @4_66a4bb
}
PCREG(66a4bb, lifted_66a4bb);

extern "C" u32 lifted_66a4d6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a4d6
  eax = (eax + (u32)(3701));  // @1_66a4d6
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(307), (u32)(8), (u32)(5315248));  // @2_66a4d6
  ecx = edx = 0;  // @3_66a4d6
  return eax;  // @4_66a4d6
}
PCREG(66a4d6, lifted_66a4d6);

extern "C" u32 lifted_66a4f1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a4f1
  eax = (eax + (u32)(6157));  // @1_66a4f1
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(307), (u32)(8), (u32)(5315248));  // @2_66a4f1
  ecx = edx = 0;  // @3_66a4f1
  return eax;  // @4_66a4f1
}
PCREG(66a4f1, lifted_66a4f1);

