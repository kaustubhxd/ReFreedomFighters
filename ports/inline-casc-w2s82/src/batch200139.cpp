// batch200139.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_42ba10_thiscall1(u32) __asm__("ext_42ba10");
extern "C" u32 THISCALL ext_4d5570_thiscall1(u32) __asm__("ext_4d5570");
extern "C" u32 THISCALL ext_4d8d50_thiscall1(u32) __asm__("ext_4d8d50");
extern "C" u32 THISCALL ext_5fad10_thiscall1(u32) __asm__("ext_5fad10");
extern "C" u32 THISCALL ext_616a50_thiscall1(u32) __asm__("ext_616a50");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_669592(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_669592
  eax = ext_4d5570_thiscall1(ecx);  // @1_669592
  ecx = edx = 0;  // @2_669592
  return eax;  // @3_669592
}
PCREG(669592, lifted_669592);

extern "C" u32 lifted_66dae0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP + 8);  // @0_66dae0
  eax = ext_42ba10_thiscall1(ecx);  // @1_66dae0
  ecx = edx = 0;  // @2_66dae0
  return eax;  // @3_66dae0
}
PCREG(66dae0, lifted_66dae0);

extern "C" u32 lifted_66db30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP + 8);  // @0_66db30
  eax = ext_42ba10_thiscall1(ecx);  // @1_66db30
  ecx = edx = 0;  // @2_66db30
  return eax;  // @3_66db30
}
PCREG(66db30, lifted_66db30);

extern "C" u32 lifted_66db80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP + 8);  // @0_66db80
  eax = ext_42ba10_thiscall1(ecx);  // @1_66db80
  ecx = edx = 0;  // @2_66db80
  return eax;  // @3_66db80
}
PCREG(66db80, lifted_66db80);

extern "C" u32 lifted_66e6bf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e6bf
  eax = ext_616a50_thiscall1(ecx);  // @1_66e6bf
  ecx = edx = 0;  // @2_66e6bf
  return eax;  // @3_66e6bf
}
PCREG(66e6bf, lifted_66e6bf);

extern "C" u32 lifted_66959a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66959a
  ecx = (ecx + (u32)(4));  // @1_66959a
  eax = ext_4d8d50_thiscall1(ecx);  // @2_66959a
  ecx = edx = 0;  // @3_66959a
  return eax;  // @4_66959a
}
PCREG(66959a, lifted_66959a);

extern "C" u32 lifted_66d300(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66d300
  ecx = (ecx + (u32)(1));  // @1_66d300
  eax = ext_5fad10_thiscall1(ecx);  // @2_66d300
  ecx = edx = 0;  // @3_66d300
  return eax;  // @4_66d300
}
PCREG(66d300, lifted_66d300);

extern "C" u32 lifted_663fd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_663fd0
  p0_ = eax;  // @1_663fd0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_663fd0
  ecx = edx = 0;  // @3_663fd0
  return eax;  // @4_663fd0
}
PCREG(663fd0, lifted_663fd0);

extern "C" u32 lifted_664000(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_664000
  p0_ = eax;  // @1_664000
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(140));  // @2_664000
  ecx = edx = 0;  // @3_664000
  return eax;  // @4_664000
}
PCREG(664000, lifted_664000);

extern "C" u32 lifted_6647f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6647f0
  p0_ = eax;  // @1_6647f0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(178));  // @2_6647f0
  ecx = edx = 0;  // @3_6647f0
  return eax;  // @4_6647f0
}
PCREG(6647f0, lifted_6647f0);

extern "C" u32 lifted_664802(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_664802
  p0_ = eax;  // @1_664802
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(434));  // @2_664802
  ecx = edx = 0;  // @3_664802
  return eax;  // @4_664802
}
PCREG(664802, lifted_664802);

extern "C" u32 lifted_664814(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_664814
  p0_ = eax;  // @1_664814
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(70));  // @2_664814
  ecx = edx = 0;  // @3_664814
  return eax;  // @4_664814
}
PCREG(664814, lifted_664814);

extern "C" u32 lifted_664823(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_664823
  p0_ = eax;  // @1_664823
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(178));  // @2_664823
  ecx = edx = 0;  // @3_664823
  return eax;  // @4_664823
}
PCREG(664823, lifted_664823);

extern "C" u32 lifted_664835(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_664835
  p0_ = eax;  // @1_664835
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(178));  // @2_664835
  ecx = edx = 0;  // @3_664835
  return eax;  // @4_664835
}
PCREG(664835, lifted_664835);

extern "C" u32 lifted_6659e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6659e0
  p0_ = eax;  // @1_6659e0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(18));  // @2_6659e0
  ecx = edx = 0;  // @3_6659e0
  return eax;  // @4_6659e0
}
PCREG(6659e0, lifted_6659e0);

extern "C" u32 lifted_6659ef(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6659ef
  p0_ = eax;  // @1_6659ef
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(26));  // @2_6659ef
  ecx = edx = 0;  // @3_6659ef
  return eax;  // @4_6659ef
}
PCREG(6659ef, lifted_6659ef);

extern "C" u32 lifted_6659fe(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6659fe
  p0_ = eax;  // @1_6659fe
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(74));  // @2_6659fe
  ecx = edx = 0;  // @3_6659fe
  return eax;  // @4_6659fe
}
PCREG(6659fe, lifted_6659fe);

extern "C" u32 lifted_665a30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_665a30
  p0_ = eax;  // @1_665a30
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(18));  // @2_665a30
  ecx = edx = 0;  // @3_665a30
  return eax;  // @4_665a30
}
PCREG(665a30, lifted_665a30);

extern "C" u32 lifted_665a3f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_665a3f
  p0_ = eax;  // @1_665a3f
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(26));  // @2_665a3f
  ecx = edx = 0;  // @3_665a3f
  return eax;  // @4_665a3f
}
PCREG(665a3f, lifted_665a3f);

extern "C" u32 lifted_665af0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_665af0
  p0_ = eax;  // @1_665af0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_665af0
  ecx = edx = 0;  // @3_665af0
  return eax;  // @4_665af0
}
PCREG(665af0, lifted_665af0);

extern "C" u32 lifted_665bf0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_665bf0
  p0_ = eax;  // @1_665bf0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_665bf0
  ecx = edx = 0;  // @3_665bf0
  return eax;  // @4_665bf0
}
PCREG(665bf0, lifted_665bf0);

extern "C" u32 lifted_6665d7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6665d7
  p0_ = eax;  // @1_6665d7
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(40));  // @2_6665d7
  ecx = edx = 0;  // @3_6665d7
  return eax;  // @4_6665d7
}
PCREG(6665d7, lifted_6665d7);

extern "C" u32 lifted_666890(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666890
  p0_ = eax;  // @1_666890
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(40));  // @2_666890
  ecx = edx = 0;  // @3_666890
  return eax;  // @4_666890
}
PCREG(666890, lifted_666890);

extern "C" u32 lifted_666f50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666f50
  p0_ = eax;  // @1_666f50
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_666f50
  ecx = edx = 0;  // @3_666f50
  return eax;  // @4_666f50
}
PCREG(666f50, lifted_666f50);

extern "C" u32 lifted_666f5f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666f5f
  p0_ = eax;  // @1_666f5f
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_666f5f
  ecx = edx = 0;  // @3_666f5f
  return eax;  // @4_666f5f
}
PCREG(666f5f, lifted_666f5f);

extern "C" u32 lifted_666f6e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666f6e
  p0_ = eax;  // @1_666f6e
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_666f6e
  ecx = edx = 0;  // @3_666f6e
  return eax;  // @4_666f6e
}
PCREG(666f6e, lifted_666f6e);

extern "C" u32 lifted_666f7d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666f7d
  p0_ = eax;  // @1_666f7d
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_666f7d
  ecx = edx = 0;  // @3_666f7d
  return eax;  // @4_666f7d
}
PCREG(666f7d, lifted_666f7d);

extern "C" u32 lifted_666f8c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666f8c
  p0_ = eax;  // @1_666f8c
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_666f8c
  ecx = edx = 0;  // @3_666f8c
  return eax;  // @4_666f8c
}
PCREG(666f8c, lifted_666f8c);

extern "C" u32 lifted_666f9b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666f9b
  p0_ = eax;  // @1_666f9b
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_666f9b
  ecx = edx = 0;  // @3_666f9b
  return eax;  // @4_666f9b
}
PCREG(666f9b, lifted_666f9b);

extern "C" u32 lifted_666faa(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666faa
  p0_ = eax;  // @1_666faa
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_666faa
  ecx = edx = 0;  // @3_666faa
  return eax;  // @4_666faa
}
PCREG(666faa, lifted_666faa);

extern "C" u32 lifted_666fb9(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666fb9
  p0_ = eax;  // @1_666fb9
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_666fb9
  ecx = edx = 0;  // @3_666fb9
  return eax;  // @4_666fb9
}
PCREG(666fb9, lifted_666fb9);

extern "C" u32 lifted_666fc8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666fc8
  p0_ = eax;  // @1_666fc8
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_666fc8
  ecx = edx = 0;  // @3_666fc8
  return eax;  // @4_666fc8
}
PCREG(666fc8, lifted_666fc8);

extern "C" u32 lifted_666fd7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666fd7
  p0_ = eax;  // @1_666fd7
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_666fd7
  ecx = edx = 0;  // @3_666fd7
  return eax;  // @4_666fd7
}
PCREG(666fd7, lifted_666fd7);

extern "C" u32 lifted_666fe6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666fe6
  p0_ = eax;  // @1_666fe6
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_666fe6
  ecx = edx = 0;  // @3_666fe6
  return eax;  // @4_666fe6
}
PCREG(666fe6, lifted_666fe6);

extern "C" u32 lifted_666ff5(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_666ff5
  p0_ = eax;  // @1_666ff5
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(64));  // @2_666ff5
  ecx = edx = 0;  // @3_666ff5
  return eax;  // @4_666ff5
}
PCREG(666ff5, lifted_666ff5);

extern "C" u32 lifted_667004(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_667004
  p0_ = eax;  // @1_667004
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(64));  // @2_667004
  ecx = edx = 0;  // @3_667004
  return eax;  // @4_667004
}
PCREG(667004, lifted_667004);

extern "C" u32 lifted_667013(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_667013
  p0_ = eax;  // @1_667013
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(48));  // @2_667013
  ecx = edx = 0;  // @3_667013
  return eax;  // @4_667013
}
PCREG(667013, lifted_667013);

extern "C" u32 lifted_667022(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_667022
  p0_ = eax;  // @1_667022
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(48));  // @2_667022
  ecx = edx = 0;  // @3_667022
  return eax;  // @4_667022
}
PCREG(667022, lifted_667022);

extern "C" u32 lifted_667920(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_667920
  p0_ = eax;  // @1_667920
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(41));  // @2_667920
  ecx = edx = 0;  // @3_667920
  return eax;  // @4_667920
}
PCREG(667920, lifted_667920);

extern "C" u32 lifted_667e50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_667e50
  p0_ = eax;  // @1_667e50
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(44));  // @2_667e50
  ecx = edx = 0;  // @3_667e50
  return eax;  // @4_667e50
}
PCREG(667e50, lifted_667e50);

extern "C" u32 lifted_667e8f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_667e8f
  p0_ = eax;  // @1_667e8f
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(44));  // @2_667e8f
  ecx = edx = 0;  // @3_667e8f
  return eax;  // @4_667e8f
}
PCREG(667e8f, lifted_667e8f);

extern "C" u32 lifted_668090(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_668090
  p0_ = eax;  // @1_668090
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(16));  // @2_668090
  ecx = edx = 0;  // @3_668090
  return eax;  // @4_668090
}
PCREG(668090, lifted_668090);

extern "C" u32 lifted_668180(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_668180
  p0_ = eax;  // @1_668180
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(16));  // @2_668180
  ecx = edx = 0;  // @3_668180
  return eax;  // @4_668180
}
PCREG(668180, lifted_668180);

extern "C" u32 lifted_66831b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66831b
  p0_ = eax;  // @1_66831b
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(21));  // @2_66831b
  ecx = edx = 0;  // @3_66831b
  return eax;  // @4_66831b
}
PCREG(66831b, lifted_66831b);

extern "C" u32 lifted_668c00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_668c00
  p0_ = eax;  // @1_668c00
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(40));  // @2_668c00
  ecx = edx = 0;  // @3_668c00
  return eax;  // @4_668c00
}
PCREG(668c00, lifted_668c00);

extern "C" u32 lifted_668db0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_668db0
  p0_ = eax;  // @1_668db0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_668db0
  ecx = edx = 0;  // @3_668db0
  return eax;  // @4_668db0
}
PCREG(668db0, lifted_668db0);

extern "C" u32 lifted_668dbf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_668dbf
  p0_ = eax;  // @1_668dbf
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_668dbf
  ecx = edx = 0;  // @3_668dbf
  return eax;  // @4_668dbf
}
PCREG(668dbf, lifted_668dbf);

extern "C" u32 lifted_668ed0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_668ed0
  p0_ = eax;  // @1_668ed0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_668ed0
  ecx = edx = 0;  // @3_668ed0
  return eax;  // @4_668ed0
}
PCREG(668ed0, lifted_668ed0);

extern "C" u32 lifted_6692d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6692d0
  p0_ = eax;  // @1_6692d0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(56));  // @2_6692d0
  ecx = edx = 0;  // @3_6692d0
  return eax;  // @4_6692d0
}
PCREG(6692d0, lifted_6692d0);

extern "C" u32 lifted_669370(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_669370
  p0_ = eax;  // @1_669370
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_669370
  ecx = edx = 0;  // @3_669370
  return eax;  // @4_669370
}
PCREG(669370, lifted_669370);

extern "C" u32 lifted_669580(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_669580
  p0_ = eax;  // @1_669580
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(182));  // @2_669580
  ecx = edx = 0;  // @3_669580
  return eax;  // @4_669580
}
PCREG(669580, lifted_669580);

extern "C" u32 lifted_66a710(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66a710
  p0_ = eax;  // @1_66a710
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_66a710
  ecx = edx = 0;  // @3_66a710
  return eax;  // @4_66a710
}
PCREG(66a710, lifted_66a710);

extern "C" u32 lifted_66ad12(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66ad12
  p0_ = eax;  // @1_66ad12
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(80));  // @2_66ad12
  ecx = edx = 0;  // @3_66ad12
  return eax;  // @4_66ad12
}
PCREG(66ad12, lifted_66ad12);

extern "C" u32 lifted_66b7b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b7b0
  p0_ = eax;  // @1_66b7b0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_66b7b0
  ecx = edx = 0;  // @3_66b7b0
  return eax;  // @4_66b7b0
}
PCREG(66b7b0, lifted_66b7b0);

extern "C" u32 lifted_66b7e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b7e0
  p0_ = eax;  // @1_66b7e0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_66b7e0
  ecx = edx = 0;  // @3_66b7e0
  return eax;  // @4_66b7e0
}
PCREG(66b7e0, lifted_66b7e0);

extern "C" u32 lifted_66b7ef(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b7ef
  p0_ = eax;  // @1_66b7ef
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(34));  // @2_66b7ef
  ecx = edx = 0;  // @3_66b7ef
  return eax;  // @4_66b7ef
}
PCREG(66b7ef, lifted_66b7ef);

extern "C" u32 lifted_66b7fe(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b7fe
  p0_ = eax;  // @1_66b7fe
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(16));  // @2_66b7fe
  ecx = edx = 0;  // @3_66b7fe
  return eax;  // @4_66b7fe
}
PCREG(66b7fe, lifted_66b7fe);

extern "C" u32 lifted_66b80d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b80d
  p0_ = eax;  // @1_66b80d
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_66b80d
  ecx = edx = 0;  // @3_66b80d
  return eax;  // @4_66b80d
}
PCREG(66b80d, lifted_66b80d);

extern "C" u32 lifted_66b81c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b81c
  p0_ = eax;  // @1_66b81c
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_66b81c
  ecx = edx = 0;  // @3_66b81c
  return eax;  // @4_66b81c
}
PCREG(66b81c, lifted_66b81c);

extern "C" u32 lifted_66b82b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b82b
  p0_ = eax;  // @1_66b82b
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_66b82b
  ecx = edx = 0;  // @3_66b82b
  return eax;  // @4_66b82b
}
PCREG(66b82b, lifted_66b82b);

extern "C" u32 lifted_66b83a(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b83a
  p0_ = eax;  // @1_66b83a
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @2_66b83a
  ecx = edx = 0;  // @3_66b83a
  return eax;  // @4_66b83a
}
PCREG(66b83a, lifted_66b83a);

extern "C" u32 lifted_66b849(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b849
  p0_ = eax;  // @1_66b849
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_66b849
  ecx = edx = 0;  // @3_66b849
  return eax;  // @4_66b849
}
PCREG(66b849, lifted_66b849);

extern "C" u32 lifted_66b858(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b858
  p0_ = eax;  // @1_66b858
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_66b858
  ecx = edx = 0;  // @3_66b858
  return eax;  // @4_66b858
}
PCREG(66b858, lifted_66b858);

extern "C" u32 lifted_66b867(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b867
  p0_ = eax;  // @1_66b867
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(16));  // @2_66b867
  ecx = edx = 0;  // @3_66b867
  return eax;  // @4_66b867
}
PCREG(66b867, lifted_66b867);

extern "C" u32 lifted_66b876(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b876
  p0_ = eax;  // @1_66b876
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(21));  // @2_66b876
  ecx = edx = 0;  // @3_66b876
  return eax;  // @4_66b876
}
PCREG(66b876, lifted_66b876);

extern "C" u32 lifted_66b885(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b885
  p0_ = eax;  // @1_66b885
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(21));  // @2_66b885
  ecx = edx = 0;  // @3_66b885
  return eax;  // @4_66b885
}
PCREG(66b885, lifted_66b885);

extern "C" u32 lifted_66b894(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b894
  p0_ = eax;  // @1_66b894
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(21));  // @2_66b894
  ecx = edx = 0;  // @3_66b894
  return eax;  // @4_66b894
}
PCREG(66b894, lifted_66b894);

extern "C" u32 lifted_66b8a3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66b8a3
  p0_ = eax;  // @1_66b8a3
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(16));  // @2_66b8a3
  ecx = edx = 0;  // @3_66b8a3
  return eax;  // @4_66b8a3
}
PCREG(66b8a3, lifted_66b8a3);

extern "C" u32 lifted_66bbb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66bbb0
  p0_ = eax;  // @1_66bbb0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(76));  // @2_66bbb0
  ecx = edx = 0;  // @3_66bbb0
  return eax;  // @4_66bbb0
}
PCREG(66bbb0, lifted_66bbb0);

extern "C" u32 lifted_66bd70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66bd70
  p0_ = eax;  // @1_66bd70
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(33));  // @2_66bd70
  ecx = edx = 0;  // @3_66bd70
  return eax;  // @4_66bd70
}
PCREG(66bd70, lifted_66bd70);

extern "C" u32 lifted_66bd7f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66bd7f
  p0_ = eax;  // @1_66bd7f
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(33));  // @2_66bd7f
  ecx = edx = 0;  // @3_66bd7f
  return eax;  // @4_66bd7f
}
PCREG(66bd7f, lifted_66bd7f);

extern "C" u32 lifted_66bd8e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66bd8e
  p0_ = eax;  // @1_66bd8e
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(81));  // @2_66bd8e
  ecx = edx = 0;  // @3_66bd8e
  return eax;  // @4_66bd8e
}
PCREG(66bd8e, lifted_66bd8e);

extern "C" u32 lifted_66ca5c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66ca5c
  p0_ = eax;  // @1_66ca5c
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(76));  // @2_66ca5c
  ecx = edx = 0;  // @3_66ca5c
  return eax;  // @4_66ca5c
}
PCREG(66ca5c, lifted_66ca5c);

extern "C" u32 lifted_66cb43(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66cb43
  p0_ = eax;  // @1_66cb43
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(247));  // @2_66cb43
  ecx = edx = 0;  // @3_66cb43
  return eax;  // @4_66cb43
}
PCREG(66cb43, lifted_66cb43);

extern "C" u32 lifted_66d2f1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66d2f1
  p0_ = eax;  // @1_66d2f1
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(10));  // @2_66d2f1
  ecx = edx = 0;  // @3_66d2f1
  return eax;  // @4_66d2f1
}
PCREG(66d2f1, lifted_66d2f1);

extern "C" u32 lifted_66d4c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66d4c0
  p0_ = eax;  // @1_66d4c0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(2770));  // @2_66d4c0
  ecx = edx = 0;  // @3_66d4c0
  return eax;  // @4_66d4c0
}
PCREG(66d4c0, lifted_66d4c0);

extern "C" u32 lifted_66e4c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e4c0
  p0_ = eax;  // @1_66e4c0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(52));  // @2_66e4c0
  ecx = edx = 0;  // @3_66e4c0
  return eax;  // @4_66e4c0
}
PCREG(66e4c0, lifted_66e4c0);

extern "C" u32 lifted_66e4cf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e4cf
  p0_ = eax;  // @1_66e4cf
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(48));  // @2_66e4cf
  ecx = edx = 0;  // @3_66e4cf
  return eax;  // @4_66e4cf
}
PCREG(66e4cf, lifted_66e4cf);

extern "C" u32 lifted_66e4de(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e4de
  p0_ = eax;  // @1_66e4de
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(16));  // @2_66e4de
  ecx = edx = 0;  // @3_66e4de
  return eax;  // @4_66e4de
}
PCREG(66e4de, lifted_66e4de);

extern "C" u32 lifted_66e4ed(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e4ed
  p0_ = eax;  // @1_66e4ed
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(12));  // @2_66e4ed
  ecx = edx = 0;  // @3_66e4ed
  return eax;  // @4_66e4ed
}
PCREG(66e4ed, lifted_66e4ed);

extern "C" u32 lifted_66e4fc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e4fc
  p0_ = eax;  // @1_66e4fc
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(48));  // @2_66e4fc
  ecx = edx = 0;  // @3_66e4fc
  return eax;  // @4_66e4fc
}
PCREG(66e4fc, lifted_66e4fc);

extern "C" u32 lifted_66e50b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e50b
  p0_ = eax;  // @1_66e50b
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(48));  // @2_66e50b
  ecx = edx = 0;  // @3_66e50b
  return eax;  // @4_66e50b
}
PCREG(66e50b, lifted_66e50b);

extern "C" u32 lifted_66e6b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e6b0
  p0_ = eax;  // @1_66e6b0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(12));  // @2_66e6b0
  ecx = edx = 0;  // @3_66e6b0
  return eax;  // @4_66e6b0
}
PCREG(66e6b0, lifted_66e6b0);

extern "C" u32 lifted_66e6c7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e6c7
  p0_ = eax;  // @1_66e6c7
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_66e6c7
  ecx = edx = 0;  // @3_66e6c7
  return eax;  // @4_66e6c7
}
PCREG(66e6c7, lifted_66e6c7);

extern "C" u32 lifted_66e6d6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e6d6
  p0_ = eax;  // @1_66e6d6
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_66e6d6
  ecx = edx = 0;  // @3_66e6d6
  return eax;  // @4_66e6d6
}
PCREG(66e6d6, lifted_66e6d6);

extern "C" u32 lifted_66e6e5(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e6e5
  p0_ = eax;  // @1_66e6e5
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(20));  // @2_66e6e5
  ecx = edx = 0;  // @3_66e6e5
  return eax;  // @4_66e6e5
}
PCREG(66e6e5, lifted_66e6e5);

extern "C" u32 lifted_66e710(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e710
  p0_ = eax;  // @1_66e710
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_66e710
  ecx = edx = 0;  // @3_66e710
  return eax;  // @4_66e710
}
PCREG(66e710, lifted_66e710);

extern "C" u32 lifted_66e950(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e950
  p0_ = eax;  // @1_66e950
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(101));  // @2_66e950
  ecx = edx = 0;  // @3_66e950
  return eax;  // @4_66e950
}
PCREG(66e950, lifted_66e950);

extern "C" u32 lifted_66e9b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_66e9b0
  p0_ = eax;  // @1_66e9b0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(101));  // @2_66e9b0
  ecx = edx = 0;  // @3_66e9b0
  return eax;  // @4_66e9b0
}
PCREG(66e9b0, lifted_66e9b0);

extern "C" u32 lifted_6649a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6649a0
  p0_ = eax;  // @1_6649a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @2_6649a0
  p1_ = eax;  // @3_6649a0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_6649a0
  ecx = edx = 0;  // @5_6649a0
  return eax;  // @6_6649a0
}
PCREG(6649a0, lifted_6649a0);

extern "C" u32 lifted_665440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_665440
  p0_ = eax;  // @1_665440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_665440
  p1_ = eax;  // @3_665440
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_665440
  ecx = edx = 0;  // @5_665440
  return eax;  // @6_665440
}
PCREG(665440, lifted_665440);

extern "C" u32 lifted_665470(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_665470
  p0_ = eax;  // @1_665470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @2_665470
  p1_ = eax;  // @3_665470
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_665470
  ecx = edx = 0;  // @5_665470
  return eax;  // @6_665470
}
PCREG(665470, lifted_665470);

extern "C" u32 lifted_66cef0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_66cef0
  p0_ = eax;  // @1_66cef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_66cef0
  p1_ = eax;  // @3_66cef0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66cef0
  ecx = edx = 0;  // @5_66cef0
  return eax;  // @6_66cef0
}
PCREG(66cef0, lifted_66cef0);

extern "C" u32 lifted_6665c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6665c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @1_6665c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @2_6665c0
  p0_ = eax;  // @3_6665c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_6665c0
  p1_ = eax;  // @5_6665c0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @6_6665c0
  ecx = edx = 0;  // @7_6665c0
  return eax;  // @8_6665c0
}
PCREG(6665c0, lifted_6665c0);

extern "C" u32 lifted_666790(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_666790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @1_666790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @2_666790
  p0_ = eax;  // @3_666790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_666790
  p1_ = eax;  // @5_666790
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @6_666790
  ecx = edx = 0;  // @7_666790
  return eax;  // @8_666790
}
PCREG(666790, lifted_666790);

extern "C" { u32 w2ret_66e8a0; u32 w2regs_66e8a0[3]; u32 w2in_66e8a0[3]; }
extern "C" u32 lifted_66e8a0_in(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = w2in_66e8a0[0], esi = 0, edi = 0;
  ebx = 0;  // @0_66e8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_66e8a0
  ecx = (u32)(479);  // @2_66e8a0
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_66e8a0
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_66e8a0
  ebx = (0u - ebx);  // @5_66e8a0
  ebx = (ebx | eax);  // @6_66e8a0
  eax = 0;  // @7_66e8a0
  ebx = (ebx + (u32)(4));  // @8_66e8a0
  eax = (eax & 0xffffff00u) | (((u32)(0 && ebx)) & 0xff);  // @9_66e8a0
  eax = (0u - eax);  // @10_66e8a0
  eax = (eax | ebx);  // @11_66e8a0
  p0_ = eax;  // @12_66e8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @13_66e8a0
  p1_ = eax;  // @14_66e8a0
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @15_66e8a0
  ecx = edx = 0;  // @16_66e8a0
  { w2regs_66e8a0[0] = ebx; return eax; }  // @17_66e8a0
}
__asm__(".text\n.globl lifted_66e8a0\nlifted_66e8a0:\n pop %eax\n mov %eax, w2ret_66e8a0\n mov %ebx, w2in_66e8a0\n mov %esi, w2in_66e8a0+4\n mov %edi, w2in_66e8a0+8\n call lifted_66e8a0_in\n mov w2regs_66e8a0+0, %ebx\n jmp *w2ret_66e8a0\n");
extern "C" u32 lifted_66e8a0(void);
PCREG(66e8a0, lifted_66e8a0);

