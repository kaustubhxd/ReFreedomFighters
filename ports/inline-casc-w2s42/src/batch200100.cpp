// batch200100.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_65f690_fastcall3(u32, u32, u32) __asm__("ext_65f690");
extern "C" u32 STDCALL ext_661b40_stdcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_661b40");
extern "C" u32 THISCALL ext_42ba10_thiscall1(u32) __asm__("ext_42ba10");
extern "C" u32 THISCALL ext_431870_thiscall1(u32) __asm__("ext_431870");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4ccee0_thiscall1(u32) __asm__("ext_4ccee0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d5580_thiscall1(u32) __asm__("ext_4d5580");
extern "C" u32 THISCALL ext_4f6b20_thiscall1(u32) __asm__("ext_4f6b20");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_5a5440_thiscall1(u32) __asm__("ext_5a5440");
extern "C" u32 THISCALL ext_5adea0_thiscall1(u32) __asm__("ext_5adea0");
extern "C" u32 THISCALL ext_5ae5a0_thiscall3(u32, u32, u32) __asm__("ext_5ae5a0");
extern "C" u32 THISCALL ext_5ae900_thiscall2(u32, u32) __asm__("ext_5ae900");
extern "C" u32 THISCALL ext_5f1360_thiscall1(u32) __asm__("ext_5f1360");
extern "C" u32 THISCALL ext_5f3af0_thiscall1(u32) __asm__("ext_5f3af0");
extern "C" u32 THISCALL ext_5f98a0_thiscall1(u32) __asm__("ext_5f98a0");
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_612550_thiscall1(u32) __asm__("ext_612550");
extern "C" u32 THISCALL ext_612570_thiscall1(u32) __asm__("ext_612570");
extern "C" u32 THISCALL ext_613940_thiscall1(u32) __asm__("ext_613940");
extern "C" u32 THISCALL ext_636400_thiscall1(u32) __asm__("ext_636400");
extern "C" u32 THISCALL ext_636430_thiscall1(u32) __asm__("ext_636430");
extern "C" u32 THISCALL ext_6604c0_thiscall4(u32, u32, u32, u32) __asm__("ext_6604c0");
extern "C" u32 THISCALL ext_663610_thiscall2(u32, u32) __asm__("ext_663610");
extern "C" u32 THISCALL ext_663680_thiscall1(u32) __asm__("ext_663680");
extern "C" u32 THISCALL ext_663770_thiscall2(u32, u32) __asm__("ext_663770");
extern "C" u32 THISCALL ext_6638c0_thiscall2(u32, u32) __asm__("ext_6638c0");
extern "C" u32 THISCALL ext_663b60_thiscall3(u32, u32, u32) __asm__("ext_663b60");
extern "C" u32 ext_633ed4_cdecl1(...) __asm__("ext_633ed4");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_668880(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668880
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668880
  ecx = edx = 0;  // @2_668880
  return eax;  // @3_668880
}
PCREG(668880, lifted_668880);

extern "C" u32 lifted_66888b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_66888b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66888b
  ecx = edx = 0;  // @2_66888b
  return eax;  // @3_66888b
}
PCREG(66888b, lifted_66888b);

extern "C" u32 lifted_668896(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_668896
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668896
  ecx = edx = 0;  // @2_668896
  return eax;  // @3_668896
}
PCREG(668896, lifted_668896);

extern "C" u32 lifted_6688d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6688d0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6688d0
  ecx = edx = 0;  // @2_6688d0
  return eax;  // @3_6688d0
}
PCREG(6688d0, lifted_6688d0);

extern "C" u32 lifted_6688db(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_6688db
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6688db
  ecx = edx = 0;  // @2_6688db
  return eax;  // @3_6688db
}
PCREG(6688db, lifted_6688db);

extern "C" u32 lifted_6688e6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6688e6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6688e6
  ecx = edx = 0;  // @2_6688e6
  return eax;  // @3_6688e6
}
PCREG(6688e6, lifted_6688e6);

extern "C" u32 lifted_668920(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668920
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668920
  ecx = edx = 0;  // @2_668920
  return eax;  // @3_668920
}
PCREG(668920, lifted_668920);

extern "C" u32 lifted_66892b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66892b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66892b
  ecx = edx = 0;  // @2_66892b
  return eax;  // @3_66892b
}
PCREG(66892b, lifted_66892b);

extern "C" u32 lifted_668a32(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668a32
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668a32
  ecx = edx = 0;  // @2_668a32
  return eax;  // @3_668a32
}
PCREG(668a32, lifted_668a32);

extern "C" u32 lifted_668ab0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 192);  // @0_668ab0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668ab0
  ecx = edx = 0;  // @2_668ab0
  return eax;  // @3_668ab0
}
PCREG(668ab0, lifted_668ab0);

extern "C" u32 lifted_668abb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 192);  // @0_668abb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668abb
  ecx = edx = 0;  // @2_668abb
  return eax;  // @3_668abb
}
PCREG(668abb, lifted_668abb);

extern "C" u32 lifted_668af0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668af0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668af0
  ecx = edx = 0;  // @2_668af0
  return eax;  // @3_668af0
}
PCREG(668af0, lifted_668af0);

extern "C" u32 lifted_668b30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 488);  // @0_668b30
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668b30
  ecx = edx = 0;  // @2_668b30
  return eax;  // @3_668b30
}
PCREG(668b30, lifted_668b30);

extern "C" u32 lifted_668b3b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 360);  // @0_668b3b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668b3b
  ecx = edx = 0;  // @2_668b3b
  return eax;  // @3_668b3b
}
PCREG(668b3b, lifted_668b3b);

extern "C" u32 lifted_668b46(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 232);  // @0_668b46
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668b46
  ecx = edx = 0;  // @2_668b46
  return eax;  // @3_668b46
}
PCREG(668b46, lifted_668b46);

extern "C" u32 lifted_668b80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668b80
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668b80
  ecx = edx = 0;  // @2_668b80
  return eax;  // @3_668b80
}
PCREG(668b80, lifted_668b80);

extern "C" u32 lifted_668b8b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668b8b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668b8b
  ecx = edx = 0;  // @2_668b8b
  return eax;  // @3_668b8b
}
PCREG(668b8b, lifted_668b8b);

extern "C" u32 lifted_668c80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 260);  // @0_668c80
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668c80
  ecx = edx = 0;  // @2_668c80
  return eax;  // @3_668c80
}
PCREG(668c80, lifted_668c80);

extern "C" u32 lifted_668df0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668df0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668df0
  ecx = edx = 0;  // @2_668df0
  return eax;  // @3_668df0
}
PCREG(668df0, lifted_668df0);

extern "C" u32 lifted_668dfb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_668dfb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668dfb
  ecx = edx = 0;  // @2_668dfb
  return eax;  // @3_668dfb
}
PCREG(668dfb, lifted_668dfb);

extern "C" u32 lifted_668fe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_668fe0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668fe0
  ecx = edx = 0;  // @2_668fe0
  return eax;  // @3_668fe0
}
PCREG(668fe0, lifted_668fe0);

extern "C" u32 lifted_668feb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_668feb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668feb
  ecx = edx = 0;  // @2_668feb
  return eax;  // @3_668feb
}
PCREG(668feb, lifted_668feb);

extern "C" u32 lifted_668ff6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668ff6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668ff6
  ecx = edx = 0;  // @2_668ff6
  return eax;  // @3_668ff6
}
PCREG(668ff6, lifted_668ff6);

extern "C" u32 lifted_669001(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669001
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669001
  ecx = edx = 0;  // @2_669001
  return eax;  // @3_669001
}
PCREG(669001, lifted_669001);

extern "C" u32 lifted_66900c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66900c
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66900c
  ecx = edx = 0;  // @2_66900c
  return eax;  // @3_66900c
}
PCREG(66900c, lifted_66900c);

extern "C" u32 lifted_669017(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669017
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669017
  ecx = edx = 0;  // @2_669017
  return eax;  // @3_669017
}
PCREG(669017, lifted_669017);

extern "C" u32 lifted_669022(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669022
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669022
  ecx = edx = 0;  // @2_669022
  return eax;  // @3_669022
}
PCREG(669022, lifted_669022);

extern "C" u32 lifted_669060(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_669060
  eax = ext_4ccf60_thiscall1(ecx);  // @1_669060
  ecx = edx = 0;  // @2_669060
  return eax;  // @3_669060
}
PCREG(669060, lifted_669060);

extern "C" u32 lifted_6690a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_6690a0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6690a0
  ecx = edx = 0;  // @2_6690a0
  return eax;  // @3_6690a0
}
PCREG(6690a0, lifted_6690a0);

extern "C" u32 lifted_6690e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 172);  // @0_6690e0
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_6690e0
  ecx = edx = 0;  // @2_6690e0
  return eax;  // @3_6690e0
}
PCREG(6690e0, lifted_6690e0);

extern "C" u32 lifted_669120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 240);  // @0_669120
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669120
  ecx = edx = 0;  // @2_669120
  return eax;  // @3_669120
}
PCREG(669120, lifted_669120);

extern "C" u32 lifted_66912b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 412);  // @0_66912b
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66912b
  ecx = edx = 0;  // @2_66912b
  return eax;  // @3_66912b
}
PCREG(66912b, lifted_66912b);

extern "C" u32 lifted_669160(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 360);  // @0_669160
  eax = ext_4ccf60_thiscall1(ecx);  // @1_669160
  ecx = edx = 0;  // @2_669160
  return eax;  // @3_669160
}
PCREG(669160, lifted_669160);

extern "C" u32 lifted_66916b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_66916b
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66916b
  ecx = edx = 0;  // @2_66916b
  return eax;  // @3_66916b
}
PCREG(66916b, lifted_66916b);

extern "C" u32 lifted_6691d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6691d0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6691d0
  ecx = edx = 0;  // @2_6691d0
  return eax;  // @3_6691d0
}
PCREG(6691d0, lifted_6691d0);

extern "C" u32 lifted_669210(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 1168);  // @0_669210
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669210
  ecx = edx = 0;  // @2_669210
  return eax;  // @3_669210
}
PCREG(669210, lifted_669210);

extern "C" u32 lifted_6693e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 11176);  // @0_6693e0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6693e0
  ecx = edx = 0;  // @2_6693e0
  return eax;  // @3_6693e0
}
PCREG(6693e0, lifted_6693e0);

extern "C" u32 lifted_669540(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 200);  // @0_669540
  eax = ext_4d5580_thiscall1(ecx);  // @1_669540
  ecx = edx = 0;  // @2_669540
  return eax;  // @3_669540
}
PCREG(669540, lifted_669540);

extern "C" u32 lifted_669690(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 192);  // @0_669690
  eax = ext_4cd0e0_thiscall1(ecx);  // @1_669690
  ecx = edx = 0;  // @2_669690
  return eax;  // @3_669690
}
PCREG(669690, lifted_669690);

extern "C" u32 lifted_66969b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66969b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66969b
  ecx = edx = 0;  // @2_66969b
  return eax;  // @3_66969b
}
PCREG(66969b, lifted_66969b);

extern "C" u32 lifted_6696a6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6696a6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6696a6
  ecx = edx = 0;  // @2_6696a6
  return eax;  // @3_6696a6
}
PCREG(6696a6, lifted_6696a6);

extern "C" u32 lifted_6696e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 52);  // @0_6696e0
  eax = ext_4cd0e0_thiscall1(ecx);  // @1_6696e0
  ecx = edx = 0;  // @2_6696e0
  return eax;  // @3_6696e0
}
PCREG(6696e0, lifted_6696e0);

extern "C" u32 lifted_669760(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669760
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669760
  ecx = edx = 0;  // @2_669760
  return eax;  // @3_669760
}
PCREG(669760, lifted_669760);

extern "C" u32 lifted_669800(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 156);  // @0_669800
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669800
  ecx = edx = 0;  // @2_669800
  return eax;  // @3_669800
}
PCREG(669800, lifted_669800);

extern "C" u32 lifted_669880(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 156);  // @0_669880
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669880
  ecx = edx = 0;  // @2_669880
  return eax;  // @3_669880
}
PCREG(669880, lifted_669880);

extern "C" u32 lifted_669930(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 232);  // @0_669930
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669930
  ecx = edx = 0;  // @2_669930
  return eax;  // @3_669930
}
PCREG(669930, lifted_669930);

extern "C" u32 lifted_669970(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_669970
  eax = ext_4ccf60_thiscall1(ecx);  // @1_669970
  ecx = edx = 0;  // @2_669970
  return eax;  // @3_669970
}
PCREG(669970, lifted_669970);

extern "C" u32 lifted_6699b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6699b0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6699b0
  ecx = edx = 0;  // @2_6699b0
  return eax;  // @3_6699b0
}
PCREG(6699b0, lifted_6699b0);

extern "C" u32 lifted_6699bb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6699bb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6699bb
  ecx = edx = 0;  // @2_6699bb
  return eax;  // @3_6699bb
}
PCREG(6699bb, lifted_6699bb);

extern "C" u32 lifted_6699c6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 656);  // @0_6699c6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6699c6
  ecx = edx = 0;  // @2_6699c6
  return eax;  // @3_6699c6
}
PCREG(6699c6, lifted_6699c6);

extern "C" u32 lifted_6699d1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 528);  // @0_6699d1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6699d1
  ecx = edx = 0;  // @2_6699d1
  return eax;  // @3_6699d1
}
PCREG(6699d1, lifted_6699d1);

extern "C" u32 lifted_6699dc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_6699dc
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6699dc
  ecx = edx = 0;  // @2_6699dc
  return eax;  // @3_6699dc
}
PCREG(6699dc, lifted_6699dc);

extern "C" u32 lifted_669a80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 152);  // @0_669a80
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669a80
  ecx = edx = 0;  // @2_669a80
  return eax;  // @3_669a80
}
PCREG(669a80, lifted_669a80);

extern "C" u32 lifted_669a8b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 280);  // @0_669a8b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669a8b
  ecx = edx = 0;  // @2_669a8b
  return eax;  // @3_669a8b
}
PCREG(669a8b, lifted_669a8b);

extern "C" u32 lifted_669ac0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669ac0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669ac0
  ecx = edx = 0;  // @2_669ac0
  return eax;  // @3_669ac0
}
PCREG(669ac0, lifted_669ac0);

extern "C" u32 lifted_669b40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 332);  // @0_669b40
  eax = ext_499970_thiscall1(ecx);  // @1_669b40
  ecx = edx = 0;  // @2_669b40
  return eax;  // @3_669b40
}
PCREG(669b40, lifted_669b40);

extern "C" u32 lifted_669b80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 332);  // @0_669b80
  eax = ext_499980_thiscall1(ecx);  // @1_669b80
  ecx = edx = 0;  // @2_669b80
  return eax;  // @3_669b80
}
PCREG(669b80, lifted_669b80);

extern "C" u32 lifted_669cd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669cd0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669cd0
  ecx = edx = 0;  // @2_669cd0
  return eax;  // @3_669cd0
}
PCREG(669cd0, lifted_669cd0);

extern "C" u32 lifted_669cdb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_669cdb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669cdb
  ecx = edx = 0;  // @2_669cdb
  return eax;  // @3_669cdb
}
PCREG(669cdb, lifted_669cdb);

extern "C" u32 lifted_669ce6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16852);  // @0_669ce6
  eax = ext_4d2330_thiscall1(ecx);  // @1_669ce6
  ecx = edx = 0;  // @2_669ce6
  return eax;  // @3_669ce6
}
PCREG(669ce6, lifted_669ce6);

extern "C" u32 lifted_669e80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16596);  // @0_669e80
  eax = ext_4d2330_thiscall1(ecx);  // @1_669e80
  ecx = edx = 0;  // @2_669e80
  return eax;  // @3_669e80
}
PCREG(669e80, lifted_669e80);

extern "C" u32 lifted_669ec0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_669ec0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669ec0
  ecx = edx = 0;  // @2_669ec0
  return eax;  // @3_669ec0
}
PCREG(669ec0, lifted_669ec0);

extern "C" u32 lifted_669ecb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669ecb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669ecb
  ecx = edx = 0;  // @2_669ecb
  return eax;  // @3_669ecb
}
PCREG(669ecb, lifted_669ecb);

extern "C" u32 lifted_669ed6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669ed6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669ed6
  ecx = edx = 0;  // @2_669ed6
  return eax;  // @3_669ed6
}
PCREG(669ed6, lifted_669ed6);

extern "C" u32 lifted_669ee1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669ee1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669ee1
  ecx = edx = 0;  // @2_669ee1
  return eax;  // @3_669ee1
}
PCREG(669ee1, lifted_669ee1);

extern "C" u32 lifted_669eec(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_669eec
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669eec
  ecx = edx = 0;  // @2_669eec
  return eax;  // @3_669eec
}
PCREG(669eec, lifted_669eec);

extern "C" u32 lifted_669f20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 156);  // @0_669f20
  eax = ext_4cbec0_thiscall1(ecx);  // @1_669f20
  ecx = edx = 0;  // @2_669f20
  return eax;  // @3_669f20
}
PCREG(669f20, lifted_669f20);

extern "C" u32 lifted_669f60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 28);  // @0_669f60
  eax = ext_5a5440_thiscall1(ecx);  // @1_669f60
  ecx = edx = 0;  // @2_669f60
  return eax;  // @3_669f60
}
PCREG(669f60, lifted_669f60);

extern "C" u32 lifted_669f68(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 28);  // @0_669f68
  eax = ext_4ff9d0_thiscall1(ecx);  // @1_669f68
  ecx = edx = 0;  // @2_669f68
  return eax;  // @3_669f68
}
PCREG(669f68, lifted_669f68);

extern "C" u32 lifted_66a000(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 320);  // @0_66a000
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a000
  ecx = edx = 0;  // @2_66a000
  return eax;  // @3_66a000
}
PCREG(66a000, lifted_66a000);

extern "C" u32 lifted_66a00b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 192);  // @0_66a00b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a00b
  ecx = edx = 0;  // @2_66a00b
  return eax;  // @3_66a00b
}
PCREG(66a00b, lifted_66a00b);

extern "C" u32 lifted_66a016(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 448);  // @0_66a016
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a016
  ecx = edx = 0;  // @2_66a016
  return eax;  // @3_66a016
}
PCREG(66a016, lifted_66a016);

extern "C" u32 lifted_66a0c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66a0c0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a0c0
  ecx = edx = 0;  // @2_66a0c0
  return eax;  // @3_66a0c0
}
PCREG(66a0c0, lifted_66a0c0);

extern "C" u32 lifted_66a0cb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66a0cb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a0cb
  ecx = edx = 0;  // @2_66a0cb
  return eax;  // @3_66a0cb
}
PCREG(66a0cb, lifted_66a0cb);

extern "C" u32 lifted_66a605(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_66a605
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66a605
  ecx = edx = 0;  // @2_66a605
  return eax;  // @3_66a605
}
PCREG(66a605, lifted_66a605);

extern "C" u32 lifted_66a625(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 360);  // @0_66a625
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66a625
  ecx = edx = 0;  // @2_66a625
  return eax;  // @3_66a625
}
PCREG(66a625, lifted_66a625);

extern "C" u32 lifted_66a8b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66a8b0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a8b0
  ecx = edx = 0;  // @2_66a8b0
  return eax;  // @3_66a8b0
}
PCREG(66a8b0, lifted_66a8b0);

extern "C" u32 lifted_66a8bb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66a8bb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a8bb
  ecx = edx = 0;  // @2_66a8bb
  return eax;  // @3_66a8bb
}
PCREG(66a8bb, lifted_66a8bb);

extern "C" u32 lifted_66a8f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66a8f0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66a8f0
  ecx = edx = 0;  // @2_66a8f0
  return eax;  // @3_66a8f0
}
PCREG(66a8f0, lifted_66a8f0);

extern "C" u32 lifted_66a940(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 580);  // @0_66a940
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66a940
  ecx = edx = 0;  // @2_66a940
  return eax;  // @3_66a940
}
PCREG(66a940, lifted_66a940);

extern "C" u32 lifted_66a94b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 408);  // @0_66a94b
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66a94b
  ecx = edx = 0;  // @2_66a94b
  return eax;  // @3_66a94b
}
PCREG(66a94b, lifted_66a94b);

extern "C" u32 lifted_66a956(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 236);  // @0_66a956
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66a956
  ecx = edx = 0;  // @2_66a956
  return eax;  // @3_66a956
}
PCREG(66a956, lifted_66a956);

extern "C" u32 lifted_66a961(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 828);  // @0_66a961
  eax = ext_4ccee0_thiscall1(ecx);  // @1_66a961
  ecx = edx = 0;  // @2_66a961
  return eax;  // @3_66a961
}
PCREG(66a961, lifted_66a961);

extern "C" u32 lifted_66a96c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 752);  // @0_66a96c
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66a96c
  ecx = edx = 0;  // @2_66a96c
  return eax;  // @3_66a96c
}
PCREG(66a96c, lifted_66a96c);

extern "C" u32 lifted_66a9e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 236);  // @0_66a9e0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66a9e0
  ecx = edx = 0;  // @2_66a9e0
  return eax;  // @3_66a9e0
}
PCREG(66a9e0, lifted_66a9e0);

extern "C" u32 lifted_66a9eb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 316);  // @0_66a9eb
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_66a9eb
  ecx = edx = 0;  // @2_66a9eb
  return eax;  // @3_66a9eb
}
PCREG(66a9eb, lifted_66a9eb);

extern "C" u32 lifted_66aa20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_66aa20
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66aa20
  ecx = edx = 0;  // @2_66aa20
  return eax;  // @3_66aa20
}
PCREG(66aa20, lifted_66aa20);

extern "C" u32 lifted_66aa60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66aa60
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66aa60
  ecx = edx = 0;  // @2_66aa60
  return eax;  // @3_66aa60
}
PCREG(66aa60, lifted_66aa60);

extern "C" u32 lifted_66aa6b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66aa6b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66aa6b
  ecx = edx = 0;  // @2_66aa6b
  return eax;  // @3_66aa6b
}
PCREG(66aa6b, lifted_66aa6b);

extern "C" u32 lifted_66ae50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 28);  // @0_66ae50
  eax = ext_5a5440_thiscall1(ecx);  // @1_66ae50
  ecx = edx = 0;  // @2_66ae50
  return eax;  // @3_66ae50
}
PCREG(66ae50, lifted_66ae50);

extern "C" u32 lifted_66ae58(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 28);  // @0_66ae58
  eax = ext_4ff9d0_thiscall1(ecx);  // @1_66ae58
  ecx = edx = 0;  // @2_66ae58
  return eax;  // @3_66ae58
}
PCREG(66ae58, lifted_66ae58);

extern "C" u32 lifted_66ae8f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 32);  // @0_66ae8f
  eax = ext_5a5440_thiscall1(ecx);  // @1_66ae8f
  ecx = edx = 0;  // @2_66ae8f
  return eax;  // @3_66ae8f
}
PCREG(66ae8f, lifted_66ae8f);

extern "C" u32 lifted_66ae97(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 32);  // @0_66ae97
  eax = ext_4ff9d0_thiscall1(ecx);  // @1_66ae97
  ecx = edx = 0;  // @2_66ae97
  return eax;  // @3_66ae97
}
PCREG(66ae97, lifted_66ae97);

extern "C" u32 lifted_66aec0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 264);  // @0_66aec0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66aec0
  ecx = edx = 0;  // @2_66aec0
  return eax;  // @3_66aec0
}
PCREG(66aec0, lifted_66aec0);

extern "C" u32 lifted_66afcf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 32);  // @0_66afcf
  eax = ext_5a5440_thiscall1(ecx);  // @1_66afcf
  ecx = edx = 0;  // @2_66afcf
  return eax;  // @3_66afcf
}
PCREG(66afcf, lifted_66afcf);

extern "C" u32 lifted_66afd7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 32);  // @0_66afd7
  eax = ext_4ff9d0_thiscall1(ecx);  // @1_66afd7
  ecx = edx = 0;  // @2_66afd7
  return eax;  // @3_66afd7
}
PCREG(66afd7, lifted_66afd7);

extern "C" u32 lifted_66b220(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 196);  // @0_66b220
  eax = ext_431870_thiscall1(ecx);  // @1_66b220
  ecx = edx = 0;  // @2_66b220
  return eax;  // @3_66b220
}
PCREG(66b220, lifted_66b220);

extern "C" u32 lifted_66b2a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66b2a0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66b2a0
  ecx = edx = 0;  // @2_66b2a0
  return eax;  // @3_66b2a0
}
PCREG(66b2a0, lifted_66b2a0);

extern "C" u32 lifted_66b2e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 392);  // @0_66b2e0
  eax = ext_431870_thiscall1(ecx);  // @1_66b2e0
  ecx = edx = 0;  // @2_66b2e0
  return eax;  // @3_66b2e0
}
PCREG(66b2e0, lifted_66b2e0);

extern "C" u32 lifted_66b2eb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 164);  // @0_66b2eb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66b2eb
  ecx = edx = 0;  // @2_66b2eb
  return eax;  // @3_66b2eb
}
PCREG(66b2eb, lifted_66b2eb);

extern "C" u32 lifted_66b2f6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 212);  // @0_66b2f6
  eax = ext_431870_thiscall1(ecx);  // @1_66b2f6
  ecx = edx = 0;  // @2_66b2f6
  return eax;  // @3_66b2f6
}
PCREG(66b2f6, lifted_66b2f6);

extern "C" u32 lifted_66b360(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 392);  // @0_66b360
  eax = ext_431870_thiscall1(ecx);  // @1_66b360
  ecx = edx = 0;  // @2_66b360
  return eax;  // @3_66b360
}
PCREG(66b360, lifted_66b360);

extern "C" u32 lifted_66b36b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 164);  // @0_66b36b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66b36b
  ecx = edx = 0;  // @2_66b36b
  return eax;  // @3_66b36b
}
PCREG(66b36b, lifted_66b36b);

extern "C" u32 lifted_66b376(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 212);  // @0_66b376
  eax = ext_431870_thiscall1(ecx);  // @1_66b376
  ecx = edx = 0;  // @2_66b376
  return eax;  // @3_66b376
}
PCREG(66b376, lifted_66b376);

extern "C" u32 lifted_66b3b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66b3b0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66b3b0
  ecx = edx = 0;  // @2_66b3b0
  return eax;  // @3_66b3b0
}
PCREG(66b3b0, lifted_66b3b0);

extern "C" u32 lifted_66b3f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 164);  // @0_66b3f0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66b3f0
  ecx = edx = 0;  // @2_66b3f0
  return eax;  // @3_66b3f0
}
PCREG(66b3f0, lifted_66b3f0);

extern "C" u32 lifted_66b460(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 268);  // @0_66b460
  eax = ext_4f6b20_thiscall1(ecx);  // @1_66b460
  ecx = edx = 0;  // @2_66b460
  return eax;  // @3_66b460
}
PCREG(66b460, lifted_66b460);

extern "C" u32 lifted_66b471(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 268);  // @0_66b471
  eax = ext_4f6b20_thiscall1(ecx);  // @1_66b471
  ecx = edx = 0;  // @2_66b471
  return eax;  // @3_66b471
}
PCREG(66b471, lifted_66b471);

extern "C" u32 lifted_66b488(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 312);  // @0_66b488
  eax = ext_4f6b20_thiscall1(ecx);  // @1_66b488
  ecx = edx = 0;  // @2_66b488
  return eax;  // @3_66b488
}
PCREG(66b488, lifted_66b488);

extern "C" u32 lifted_66b610(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 204);  // @0_66b610
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66b610
  ecx = edx = 0;  // @2_66b610
  return eax;  // @3_66b610
}
PCREG(66b610, lifted_66b610);

extern "C" u32 lifted_66b770(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66b770
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66b770
  ecx = edx = 0;  // @2_66b770
  return eax;  // @3_66b770
}
PCREG(66b770, lifted_66b770);

extern "C" u32 lifted_66ba20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 192);  // @0_66ba20
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66ba20
  ecx = edx = 0;  // @2_66ba20
  return eax;  // @3_66ba20
}
PCREG(66ba20, lifted_66ba20);

extern "C" u32 lifted_66ba60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16724);  // @0_66ba60
  eax = ext_4d2330_thiscall1(ecx);  // @1_66ba60
  ecx = edx = 0;  // @2_66ba60
  return eax;  // @3_66ba60
}
PCREG(66ba60, lifted_66ba60);

extern "C" u32 lifted_66ba6b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66ba6b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66ba6b
  ecx = edx = 0;  // @2_66ba6b
  return eax;  // @3_66ba6b
}
PCREG(66ba6b, lifted_66ba6b);

extern "C" u32 lifted_66ba76(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66ba76
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66ba76
  ecx = edx = 0;  // @2_66ba76
  return eax;  // @3_66ba76
}
PCREG(66ba76, lifted_66ba76);

extern "C" u32 lifted_66bd00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 284);  // @0_66bd00
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66bd00
  ecx = edx = 0;  // @2_66bd00
  return eax;  // @3_66bd00
}
PCREG(66bd00, lifted_66bd00);

extern "C" u32 lifted_66bd0b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 156);  // @0_66bd0b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66bd0b
  ecx = edx = 0;  // @2_66bd0b
  return eax;  // @3_66bd0b
}
PCREG(66bd0b, lifted_66bd0b);

extern "C" u32 lifted_66bdc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66bdc0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66bdc0
  ecx = edx = 0;  // @2_66bdc0
  return eax;  // @3_66bdc0
}
PCREG(66bdc0, lifted_66bdc0);

extern "C" u32 lifted_66bdcb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66bdcb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66bdcb
  ecx = edx = 0;  // @2_66bdcb
  return eax;  // @3_66bdcb
}
PCREG(66bdcb, lifted_66bdcb);

extern "C" u32 lifted_66be00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 240);  // @0_66be00
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66be00
  ecx = edx = 0;  // @2_66be00
  return eax;  // @3_66be00
}
PCREG(66be00, lifted_66be00);

extern "C" u32 lifted_66be40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66be40
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66be40
  ecx = edx = 0;  // @2_66be40
  return eax;  // @3_66be40
}
PCREG(66be40, lifted_66be40);

extern "C" u32 lifted_66be4b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66be4b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66be4b
  ecx = edx = 0;  // @2_66be4b
  return eax;  // @3_66be4b
}
PCREG(66be4b, lifted_66be4b);

extern "C" u32 lifted_66be56(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66be56
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66be56
  ecx = edx = 0;  // @2_66be56
  return eax;  // @3_66be56
}
PCREG(66be56, lifted_66be56);

extern "C" u32 lifted_66be90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 300);  // @0_66be90
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66be90
  ecx = edx = 0;  // @2_66be90
  return eax;  // @3_66be90
}
PCREG(66be90, lifted_66be90);

extern "C" u32 lifted_66c230(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 1200);  // @0_66c230
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66c230
  ecx = edx = 0;  // @2_66c230
  return eax;  // @3_66c230
}
PCREG(66c230, lifted_66c230);

extern "C" u32 lifted_66c344(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66c344
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66c344
  ecx = edx = 0;  // @2_66c344
  return eax;  // @3_66c344
}
PCREG(66c344, lifted_66c344);

extern "C" u32 lifted_66c600(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_66c600
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66c600
  ecx = edx = 0;  // @2_66c600
  return eax;  // @3_66c600
}
PCREG(66c600, lifted_66c600);

extern "C" u32 lifted_66c6e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66c6e0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66c6e0
  ecx = edx = 0;  // @2_66c6e0
  return eax;  // @3_66c6e0
}
PCREG(66c6e0, lifted_66c6e0);

extern "C" u32 lifted_66c6eb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66c6eb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66c6eb
  ecx = edx = 0;  // @2_66c6eb
  return eax;  // @3_66c6eb
}
PCREG(66c6eb, lifted_66c6eb);

extern "C" u32 lifted_66c9e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_66c9e0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66c9e0
  ecx = edx = 0;  // @2_66c9e0
  return eax;  // @3_66c9e0
}
PCREG(66c9e0, lifted_66c9e0);

extern "C" u32 lifted_66ce70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 656);  // @0_66ce70
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66ce70
  ecx = edx = 0;  // @2_66ce70
  return eax;  // @3_66ce70
}
PCREG(66ce70, lifted_66ce70);

extern "C" u32 lifted_66ce7b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 696);  // @0_66ce7b
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_66ce7b
  ecx = edx = 0;  // @2_66ce7b
  return eax;  // @3_66ce7b
}
PCREG(66ce7b, lifted_66ce7b);

extern "C" u32 lifted_66ceb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 40);  // @0_66ceb0
  eax = ext_42ba10_thiscall1(ecx);  // @1_66ceb0
  ecx = edx = 0;  // @2_66ceb0
  return eax;  // @3_66ceb0
}
PCREG(66ceb0, lifted_66ceb0);

extern "C" u32 lifted_66ceb8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 64);  // @0_66ceb8
  eax = ext_42ba10_thiscall1(ecx);  // @1_66ceb8
  ecx = edx = 0;  // @2_66ceb8
  return eax;  // @3_66ceb8
}
PCREG(66ceb8, lifted_66ceb8);

extern "C" u32 lifted_66cec0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 52);  // @0_66cec0
  eax = ext_42ba10_thiscall1(ecx);  // @1_66cec0
  ecx = edx = 0;  // @2_66cec0
  return eax;  // @3_66cec0
}
PCREG(66cec0, lifted_66cec0);

extern "C" u32 lifted_66ced4(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 52);  // @0_66ced4
  eax = ext_42ba10_thiscall1(ecx);  // @1_66ced4
  ecx = edx = 0;  // @2_66ced4
  return eax;  // @3_66ced4
}
PCREG(66ced4, lifted_66ced4);

extern "C" u32 lifted_66cedc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 64);  // @0_66cedc
  eax = ext_42ba10_thiscall1(ecx);  // @1_66cedc
  ecx = edx = 0;  // @2_66cedc
  return eax;  // @3_66cedc
}
PCREG(66cedc, lifted_66cedc);

extern "C" u32 lifted_66cf30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 32);  // @0_66cf30
  eax = ext_42ba10_thiscall1(ecx);  // @1_66cf30
  ecx = edx = 0;  // @2_66cf30
  return eax;  // @3_66cf30
}
PCREG(66cf30, lifted_66cf30);

extern "C" u32 lifted_66cf38(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 44);  // @0_66cf38
  eax = ext_42ba10_thiscall1(ecx);  // @1_66cf38
  ecx = edx = 0;  // @2_66cf38
  return eax;  // @3_66cf38
}
PCREG(66cf38, lifted_66cf38);

extern "C" u32 lifted_66cfa0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 44);  // @0_66cfa0
  eax = ext_5f1360_thiscall1(ecx);  // @1_66cfa0
  ecx = edx = 0;  // @2_66cfa0
  return eax;  // @3_66cfa0
}
PCREG(66cfa0, lifted_66cfa0);

extern "C" u32 lifted_66d010(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 40);  // @0_66d010
  eax = ext_5f1360_thiscall1(ecx);  // @1_66d010
  ecx = edx = 0;  // @2_66d010
  return eax;  // @3_66d010
}
PCREG(66d010, lifted_66d010);

extern "C" u32 lifted_66d4f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 64);  // @0_66d4f0
  eax = ext_5f98a0_thiscall1(ecx);  // @1_66d4f0
  ecx = edx = 0;  // @2_66d4f0
  return eax;  // @3_66d4f0
}
PCREG(66d4f0, lifted_66d4f0);

extern "C" u32 lifted_66d540(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 156);  // @0_66d540
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d540
  ecx = edx = 0;  // @2_66d540
  return eax;  // @3_66d540
}
PCREG(66d540, lifted_66d540);

extern "C" u32 lifted_66d54b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 175);  // @0_66d54b
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d54b
  ecx = edx = 0;  // @2_66d54b
  return eax;  // @3_66d54b
}
PCREG(66d54b, lifted_66d54b);

extern "C" u32 lifted_66d55c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 175);  // @0_66d55c
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d55c
  ecx = edx = 0;  // @2_66d55c
  return eax;  // @3_66d55c
}
PCREG(66d55c, lifted_66d55c);

extern "C" u32 lifted_66d56d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 132);  // @0_66d56d
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d56d
  ecx = edx = 0;  // @2_66d56d
  return eax;  // @3_66d56d
}
PCREG(66d56d, lifted_66d56d);

extern "C" u32 lifted_66d578(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 175);  // @0_66d578
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d578
  ecx = edx = 0;  // @2_66d578
  return eax;  // @3_66d578
}
PCREG(66d578, lifted_66d578);

extern "C" u32 lifted_66d59e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 184);  // @0_66d59e
  eax = ext_602240_thiscall1(ecx);  // @1_66d59e
  ecx = edx = 0;  // @2_66d59e
  return eax;  // @3_66d59e
}
PCREG(66d59e, lifted_66d59e);

extern "C" u32 lifted_66d650(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 48);  // @0_66d650
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d650
  ecx = edx = 0;  // @2_66d650
  return eax;  // @3_66d650
}
PCREG(66d650, lifted_66d650);

extern "C" u32 lifted_66d658(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 60);  // @0_66d658
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d658
  ecx = edx = 0;  // @2_66d658
  return eax;  // @3_66d658
}
PCREG(66d658, lifted_66d658);

extern "C" u32 lifted_66d666(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 60);  // @0_66d666
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d666
  ecx = edx = 0;  // @2_66d666
  return eax;  // @3_66d666
}
PCREG(66d666, lifted_66d666);

extern "C" u32 lifted_66d6a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 24);  // @0_66d6a0
  eax = ext_5f98a0_thiscall1(ecx);  // @1_66d6a0
  ecx = edx = 0;  // @2_66d6a0
  return eax;  // @3_66d6a0
}
PCREG(66d6a0, lifted_66d6a0);

extern "C" u32 lifted_66d750(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 156);  // @0_66d750
  eax = ext_42ba10_thiscall1(ecx);  // @1_66d750
  ecx = edx = 0;  // @2_66d750
  return eax;  // @3_66d750
}
PCREG(66d750, lifted_66d750);

extern "C" u32 lifted_66d7f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 36);  // @0_66d7f0
  eax = ext_5f3af0_thiscall1(ecx);  // @1_66d7f0
  ecx = edx = 0;  // @2_66d7f0
  return eax;  // @3_66d7f0
}
PCREG(66d7f0, lifted_66d7f0);

extern "C" u32 lifted_66d7f8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 48);  // @0_66d7f8
  eax = ext_5f3af0_thiscall1(ecx);  // @1_66d7f8
  ecx = edx = 0;  // @2_66d7f8
  return eax;  // @3_66d7f8
}
PCREG(66d7f8, lifted_66d7f8);

extern "C" u32 lifted_66da80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 44);  // @0_66da80
  eax = ext_42ba10_thiscall1(ecx);  // @1_66da80
  ecx = edx = 0;  // @2_66da80
  return eax;  // @3_66da80
}
PCREG(66da80, lifted_66da80);

extern "C" u32 lifted_66dbd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 36);  // @0_66dbd0
  eax = ext_602240_thiscall1(ecx);  // @1_66dbd0
  ecx = edx = 0;  // @2_66dbd0
  return eax;  // @3_66dbd0
}
PCREG(66dbd0, lifted_66dbd0);

extern "C" u32 lifted_66dcf8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 28);  // @0_66dcf8
  eax = ext_42ba10_thiscall1(ecx);  // @1_66dcf8
  ecx = edx = 0;  // @2_66dcf8
  return eax;  // @3_66dcf8
}
PCREG(66dcf8, lifted_66dcf8);

extern "C" u32 lifted_66dd60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 36);  // @0_66dd60
  eax = ext_42ba10_thiscall1(ecx);  // @1_66dd60
  ecx = edx = 0;  // @2_66dd60
  return eax;  // @3_66dd60
}
PCREG(66dd60, lifted_66dd60);

extern "C" u32 lifted_66de10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 24);  // @0_66de10
  eax = ext_42ba10_thiscall1(ecx);  // @1_66de10
  ecx = edx = 0;  // @2_66de10
  return eax;  // @3_66de10
}
PCREG(66de10, lifted_66de10);

extern "C" u32 lifted_66de40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 28);  // @0_66de40
  eax = ext_5a5440_thiscall1(ecx);  // @1_66de40
  ecx = edx = 0;  // @2_66de40
  return eax;  // @3_66de40
}
PCREG(66de40, lifted_66de40);

extern "C" u32 lifted_66de48(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 28);  // @0_66de48
  eax = ext_4ff9d0_thiscall1(ecx);  // @1_66de48
  ecx = edx = 0;  // @2_66de48
  return eax;  // @3_66de48
}
PCREG(66de48, lifted_66de48);

extern "C" u32 lifted_66de70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 24);  // @0_66de70
  eax = ext_42ba10_thiscall1(ecx);  // @1_66de70
  ecx = edx = 0;  // @2_66de70
  return eax;  // @3_66de70
}
PCREG(66de70, lifted_66de70);

extern "C" u32 lifted_66de78(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 88);  // @0_66de78
  eax = ext_42ba10_thiscall1(ecx);  // @1_66de78
  ecx = edx = 0;  // @2_66de78
  return eax;  // @3_66de78
}
PCREG(66de78, lifted_66de78);

extern "C" u32 lifted_66de80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 64);  // @0_66de80
  eax = ext_42ba10_thiscall1(ecx);  // @1_66de80
  ecx = edx = 0;  // @2_66de80
  return eax;  // @3_66de80
}
PCREG(66de80, lifted_66de80);

extern "C" u32 lifted_66de88(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 48);  // @0_66de88
  eax = ext_42ba10_thiscall1(ecx);  // @1_66de88
  ecx = edx = 0;  // @2_66de88
  return eax;  // @3_66de88
}
PCREG(66de88, lifted_66de88);

extern "C" u32 lifted_66de90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 36);  // @0_66de90
  eax = ext_42ba10_thiscall1(ecx);  // @1_66de90
  ecx = edx = 0;  // @2_66de90
  return eax;  // @3_66de90
}
PCREG(66de90, lifted_66de90);

extern "C" u32 lifted_66de98(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 100);  // @0_66de98
  eax = ext_42ba10_thiscall1(ecx);  // @1_66de98
  ecx = edx = 0;  // @2_66de98
  return eax;  // @3_66de98
}
PCREG(66de98, lifted_66de98);

extern "C" u32 lifted_66dea6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 112);  // @0_66dea6
  eax = ext_42ba10_thiscall1(ecx);  // @1_66dea6
  ecx = edx = 0;  // @2_66dea6
  return eax;  // @3_66dea6
}
PCREG(66dea6, lifted_66dea6);

extern "C" u32 lifted_66deb4(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 148);  // @0_66deb4
  eax = ext_42ba10_thiscall1(ecx);  // @1_66deb4
  ecx = edx = 0;  // @2_66deb4
  return eax;  // @3_66deb4
}
PCREG(66deb4, lifted_66deb4);

extern "C" u32 lifted_66dec5(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 124);  // @0_66dec5
  eax = ext_42ba10_thiscall1(ecx);  // @1_66dec5
  ecx = edx = 0;  // @2_66dec5
  return eax;  // @3_66dec5
}
PCREG(66dec5, lifted_66dec5);

extern "C" u32 lifted_66ded3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 136);  // @0_66ded3
  eax = ext_42ba10_thiscall1(ecx);  // @1_66ded3
  ecx = edx = 0;  // @2_66ded3
  return eax;  // @3_66ded3
}
PCREG(66ded3, lifted_66ded3);

extern "C" u32 lifted_66e060(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 262208);  // @0_66e060
  eax = ext_612570_thiscall1(ecx);  // @1_66e060
  ecx = edx = 0;  // @2_66e060
  return eax;  // @3_66e060
}
PCREG(66e060, lifted_66e060);

extern "C" u32 lifted_66e1ec(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66e1ec
  eax = ext_612570_thiscall1(ecx);  // @1_66e1ec
  ecx = edx = 0;  // @2_66e1ec
  return eax;  // @3_66e1ec
}
PCREG(66e1ec, lifted_66e1ec);

extern "C" u32 lifted_66e1f7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66e1f7
  eax = ext_612570_thiscall1(ecx);  // @1_66e1f7
  ecx = edx = 0;  // @2_66e1f7
  return eax;  // @3_66e1f7
}
PCREG(66e1f7, lifted_66e1f7);

extern "C" u32 lifted_66e202(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66e202
  eax = ext_612570_thiscall1(ecx);  // @1_66e202
  ecx = edx = 0;  // @2_66e202
  return eax;  // @3_66e202
}
PCREG(66e202, lifted_66e202);

extern "C" u32 lifted_66e285(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 80);  // @0_66e285
  eax = ext_612570_thiscall1(ecx);  // @1_66e285
  ecx = edx = 0;  // @2_66e285
  return eax;  // @3_66e285
}
PCREG(66e285, lifted_66e285);

extern "C" u32 lifted_66e2c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 116);  // @0_66e2c0
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_66e2c0
  ecx = edx = 0;  // @2_66e2c0
  return eax;  // @3_66e2c0
}
PCREG(66e2c0, lifted_66e2c0);

extern "C" u32 lifted_66e330(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 64);  // @0_66e330
  eax = ext_612570_thiscall1(ecx);  // @1_66e330
  ecx = edx = 0;  // @2_66e330
  return eax;  // @3_66e330
}
PCREG(66e330, lifted_66e330);

extern "C" u32 lifted_66e360(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 120);  // @0_66e360
  eax = ext_612550_thiscall1(ecx);  // @1_66e360
  ecx = edx = 0;  // @2_66e360
  return eax;  // @3_66e360
}
PCREG(66e360, lifted_66e360);

extern "C" u32 lifted_66e368(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 64);  // @0_66e368
  eax = ext_612570_thiscall1(ecx);  // @1_66e368
  ecx = edx = 0;  // @2_66e368
  return eax;  // @3_66e368
}
PCREG(66e368, lifted_66e368);

extern "C" u32 lifted_66e3a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 160);  // @0_66e3a0
  eax = ext_612570_thiscall1(ecx);  // @1_66e3a0
  ecx = edx = 0;  // @2_66e3a0
  return eax;  // @3_66e3a0
}
PCREG(66e3a0, lifted_66e3a0);

extern "C" u32 lifted_66e3ab(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 216);  // @0_66e3ab
  eax = ext_636400_thiscall1(ecx);  // @1_66e3ab
  ecx = edx = 0;  // @2_66e3ab
  return eax;  // @3_66e3ab
}
PCREG(66e3ab, lifted_66e3ab);

extern "C" u32 lifted_66e3b6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 276);  // @0_66e3b6
  eax = ext_636430_thiscall1(ecx);  // @1_66e3b6
  ecx = edx = 0;  // @2_66e3b6
  return eax;  // @3_66e3b6
}
PCREG(66e3b6, lifted_66e3b6);

extern "C" u32 lifted_66e3c1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 112);  // @0_66e3c1
  eax = ext_612570_thiscall1(ecx);  // @1_66e3c1
  ecx = edx = 0;  // @2_66e3c1
  return eax;  // @3_66e3c1
}
PCREG(66e3c1, lifted_66e3c1);

extern "C" u32 lifted_66e3c9(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 64);  // @0_66e3c9
  eax = ext_612570_thiscall1(ecx);  // @1_66e3c9
  ecx = edx = 0;  // @2_66e3c9
  return eax;  // @3_66e3c9
}
PCREG(66e3c9, lifted_66e3c9);

extern "C" u32 lifted_66e400(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 932);  // @0_66e400
  eax = ext_613940_thiscall1(ecx);  // @1_66e400
  ecx = edx = 0;  // @2_66e400
  return eax;  // @3_66e400
}
PCREG(66e400, lifted_66e400);

extern "C" u32 lifted_66e40b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 992);  // @0_66e40b
  eax = ext_613940_thiscall1(ecx);  // @1_66e40b
  ecx = edx = 0;  // @2_66e40b
  return eax;  // @3_66e40b
}
PCREG(66e40b, lifted_66e40b);

extern "C" u32 lifted_66e870(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 52);  // @0_66e870
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_66e870
  ecx = edx = 0;  // @2_66e870
  return eax;  // @3_66e870
}
PCREG(66e870, lifted_66e870);

extern "C" u32 lifted_66e9e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 200);  // @0_66e9e0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66e9e0
  ecx = edx = 0;  // @2_66e9e0
  return eax;  // @3_66e9e0
}
PCREG(66e9e0, lifted_66e9e0);

extern "C" u32 lifted_66ede0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 4252);  // @0_66ede0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66ede0
  ecx = edx = 0;  // @2_66ede0
  return eax;  // @3_66ede0
}
PCREG(66ede0, lifted_66ede0);

extern "C" u32 lifted_633170(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_633170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @1_633170
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @2_633170
  ecx = edx = 0;  // @3_633170
  return eax;  // @4_633170
}
PCREG(633170, lifted_633170);

extern "C" u32 lifted_633f0f(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ext_633ed4_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @0_633f0f
  ecx = edx = 0;  // @1_633f0f
  eax = (0u - eax);  // @2_633f0f
  eax = 0;  // @3_633f0f
  eax = (0u - eax);  // @4_633f0f
  eax = (eax - 1);  // @5_633f0f
  return eax;  // @6_633f0f
}
PCREG(633f0f, lifted_633f0f);

extern "C" u32 STDCALL lifted_663200(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_663200
  eax = (eax - (u32)(1));  // @1_663200
  if (eax == 0) goto L66323c;  // @2_663200
  eax = (eax - (u32)(4));  // @3_663200
  if (eax == 0) goto L663230;  // @4_663200
  eax = (eax - (u32)(3));  // @5_663200
  if (eax == 0) goto L663224;  // @6_663200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_663200
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_663200
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @9_663200
  return eax;  // @10_663200
  L663224:;
  eax = ext_663770_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @12_663200
  ecx = edx = 0;  // @13_663200
  return eax;  // @14_663200
  L663230:;
  eax = ext_6638c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @16_663200
  ecx = edx = 0;  // @17_663200
  return eax;  // @18_663200
  L66323c:;
  eax = ext_663610_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @20_663200
  ecx = edx = 0;  // @21_663200
  return eax;  // @22_663200
}
PCREG(663200, lifted_663200);

extern "C" u32 THISCALL lifted_662750(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 13), &v, sizeof v); }  // @0_662750
  edx = (u32)(ecx + 13);  // @1_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 17), &v, sizeof v); }  // @2_662750
  eax = (u32)(ecx + 17);  // @3_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @4_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @5_662750
  esi = (u32)(EBP - 4);  // @6_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @7_662750
  if (edx == esi) goto L66278d;  // @8_662750
  { u32 v = (u32)((u32)(4294966272)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @9_662750
  L66278d:;
  edx = (u32)(EBP - 8);  // @11_662750
  if (eax == edx) goto L66279a;  // @12_662750
  { u32 v = (u32)((u32)(2048)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @13_662750
  L66279a:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ecx + 21), &v, sizeof v); }  // @15_662750
  eax = ecx;  // @16_662750
  { u32 v = (u32)((u32)(981668463)); __builtin_memcpy((void *)(u32)(ecx + 25), &v, sizeof v); }  // @17_662750
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @18_662750
  return eax;  // @19_662750
}
PCREG(662750, lifted_662750);

extern "C" u32 lifted_633cbc(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_633cbc
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @1_633cbc
  ecx = (ecx + eax);  // @2_633cbc
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @3_633cbc
  edx = (u32)(ecx + 24);  // @4_633cbc
  edx = (edx + eax);  // @5_633cbc
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @6_633cbc
  esi = (u32)((s32)eax * (s32)(u32)(40));  // @7_633cbc
  esi = (esi + edx);  // @8_633cbc
  if (edx == esi) goto L633cf7;  // @9_633cbc
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @10_633cbc
  L633ce1:;
  if (ecx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; })) goto L633cf0;  // @12_633cbc
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @13_633cbc
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; }));  // @14_633cbc
  if (ecx < eax) goto L633cfc;  // @15_633cbc
  L633cf0:;
  edx = (edx + (u32)(40));  // @17_633cbc
  if (edx != esi) goto L633ce1;  // @18_633cbc
  L633cf7:;
  eax = 0;  // @20_633cbc
  L633cf9:;
  return eax;  // @22_633cbc
  L633cfc:;
  eax = edx;  // @24_633cbc
  goto L633cf9;  // @25_633cbc
}
PCREG(633cbc, lifted_633cbc);

extern "C" u32 THISCALL lifted_663190(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 74124), sizeof v); (u32)v; });  // @1_663190
  edi = (u32)(ebx + 74124);  // @2_663190
  ecx = edi;  // @3_663190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi));  // @4_663190
  ecx = edx = 0;  // @5_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @6_663190
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_663190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @10_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_663190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @12_663190
  ecx = edx = 0;  // @13_663190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @14_663190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 308)))(ecx, (u32)(edi), (u32)(eax));  // @15_663190
  ecx = edx = 0;  // @16_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_663190
  ecx = edi;  // @18_663190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @19_663190
  ecx = edx = 0;  // @20_663190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 74152), &v, sizeof v); }  // @21_663190
  eax = (eax & 0xffffff00u) | (((u32)((s32)eax < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 74156), sizeof v); (u32)v; }))) & 0xff);  // @22_663190
  return eax;  // @23_663190
}
PCREG(663190, lifted_663190);

extern "C" u32 THISCALL lifted_663610(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 74124), sizeof v); (u32)v; });  // @0_663610
  edi = (u32)(ecx + 74124);  // @1_663610
  ecx = edi;  // @2_663610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi), (u32)(esi));  // @3_663610
  ecx = edx = 0;  // @4_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @5_663610
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_663610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @9_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_663610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @11_663610
  ecx = edx = 0;  // @12_663610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @13_663610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 308)))(ecx, (u32)(edi), (u32)(eax));  // @14_663610
  ecx = edx = 0;  // @15_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_663610
  ecx = edi;  // @17_663610
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @18_663610
  ecx = edx = 0;  // @19_663610
  if ((eax & eax) != 0) goto L663676;  // @20_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_663610
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @22_663610
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @23_663610
  return eax;  // @24_663610
  L663676:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @26_663610
  return eax;  // @27_663610
}
PCREG(663610, lifted_663610);

extern "C" u32 THISCALL lifted_663b60(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_663b60
  edi = ecx;  // @1_663b60
  if ((s32)esi >= (s32)(u32)(64)) goto L663bbb;  // @2_663b60
  eax = esi;  // @3_663b60
  eax = (eax << (u32)(10));  // @4_663b60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_663b60
  eax = (eax + (u32)(8448));  // @6_663b60
  eax = (eax + edi);  // @7_663b60
  ecx = ebx;  // @8_663b60
  eax = ext_5ae5a0_thiscall3(ecx, (u32)(eax), (u32)(0));  // @9_663b60
  ecx = edx = 0;  // @10_663b60
  ecx = ebx;  // @11_663b60
  eax = ext_5adea0_thiscall1(ecx);  // @12_663b60
  ecx = edx = 0;  // @13_663b60
  edx = esi;  // @14_663b60
  edx = (edx << (u32)(7));  // @15_663b60
  edx = (edx + edi);  // @16_663b60
  edx = (edx - eax);  // @17_663b60
  L663ba0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @19_663b60
  eax = (u32)(eax + 1);  // @20_663b60
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @21_663b60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663ba0;  // @22_663b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 134), sizeof v); (u32)v; });  // @23_663b60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 8192), &v, sizeof v); }  // @24_663b60
  L663bbb:;
  return eax;  // @26_663b60
}
PCREG(663b60, lifted_663b60);

extern "C" u32 FASTCALL lifted_660c00(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_660c00
  ebx = ecx;  // @1_660c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_660c00
  edi = edx;  // @3_660c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_660c00
  eax = ext_6604c0_thiscall4(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }));  // @5_660c00
  ecx = edx = 0;  // @6_660c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @7_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @9_660c00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(8471088), &v, sizeof v); }  // @10_660c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(8471092), &v, sizeof v); }  // @11_660c00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(8471096), &v, sizeof v); }  // @12_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(8471100), &v, sizeof v); }  // @13_660c00
  if ((s32)(edi & edi) <= 0) goto L660c79;  // @14_660c00
  ecx = (u32)(83);  // @15_660c00
  L660c57:;
  esi = edi;  // @17_660c00
  edx = ebx;  // @18_660c00
  if ((s32)edi > (s32)(u32)(83)) esi = ecx;  // @19_660c00
  ecx = eax;  // @20_660c00
  eax = ext_65f690_fastcall3(ecx, edx, (u32)(esi));  // @21_660c00
  ecx = edx = 0;  // @22_660c00
  edi = (edi - esi);  // @23_660c00
  ecx = (u32)(83);  // @24_660c00
  esi = (esi << (u32)(6));  // @25_660c00
  ebx = (ebx + esi);  // @26_660c00
  if ((s32)(edi & edi) > 0) goto L660c57;  // @27_660c00
  L660c79:;
  return eax;  // @29_660c00
}
PCREG(660c00, lifted_660c00);

extern "C" u32 STDCALL lifted_6639a0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @0_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 228)))(ecx, (u32)(1));  // @2_6639a0
  ecx = edx = 0;  // @3_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @7_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1));  // @8_6639a0
  ecx = edx = 0;  // @9_6639a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6639f4;  // @10_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_6639a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @14_6639a0
  ecx = edx = 0;  // @15_6639a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_6639a0
  ecx = eax;  // @17_6639a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6973164), (u32)(1), (u32)(2));  // @18_6639a0
  ecx = edx = 0;  // @19_6639a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @20_6639a0
  return eax;  // @21_6639a0
  L6639f4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @23_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 228)))(ecx, (u32)(1));  // @25_6639a0
  ecx = edx = 0;  // @26_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_6639a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @30_6639a0
  ecx = edx = 0;  // @31_6639a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_6639a0
  ecx = eax;  // @33_6639a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6973164), (u32)(0), (u32)(2));  // @34_6639a0
  ecx = edx = 0;  // @35_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_6639a0
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_6639a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @38_6639a0
  return eax;  // @39_6639a0
}
PCREG(6639a0, lifted_6639a0);

extern "C" u32 THISCALL lifted_661940(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @2_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @3_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_661940
  edi = edx;  // @5_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @6_661940
  eax = edx;  // @7_661940
  ebx = (edx & 0xffff);  // @8_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @9_661940
  eax = (eax >> (u32)(31));  // @10_661940
  edx = (edx + ecx);  // @11_661940
  edi = (edi >> (u32)(16));  // @12_661940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @13_661940
  edi = (edi & (u32)(32767));  // @14_661940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @15_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @16_661940
  ebx = (ebx + edi);  // @17_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @18_661940
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; }) & eax) != 0) goto L661994;  // @19_661940
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @20_661940
  return eax;  // @21_661940
  L661994:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @23_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @24_661940
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @25_661940
  eax = (u32)(eax + edi*2);  // @26_661940
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @27_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @28_661940
  eax = ext_661b40_stdcall8((u32)(ecx), (u32)(eax), (u32)(edi), (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @29_661940
  ecx = edx = 0;  // @30_661940
  return eax;  // @31_661940
}
PCREG(661940, lifted_661940);

extern "C" u32 THISCALL lifted_663520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_663520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L663573;  // @1_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @2_663520
  ebx = (u32)(esi + 74124);  // @3_663520
  ecx = ebx;  // @4_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi), (u32)(esi));  // @5_663520
  ecx = edx = 0;  // @6_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @7_663520
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @11_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @13_663520
  ecx = edx = 0;  // @14_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @15_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 308)))(ecx, (u32)(ebx), (u32)(eax));  // @16_663520
  ecx = edx = 0;  // @17_663520
  L663573:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @19_663520
  ecx = (u32)(esi + 74124);  // @20_663520
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @21_663520
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @22_663520
  ecx = edx = 0;  // @23_663520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @24_663520
  if ((s32)(eax & eax) <= 0) goto L6635e7;  // @25_663520
  edi = 0;  // @26_663520
  if ((s32)(eax & eax) <= 0) goto L6635e7;  // @27_663520
  L6635a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @29_663520
  ecx = (u32)(esi + 74124);  // @30_663520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(edi));  // @31_663520
  ecx = edx = 0;  // @32_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; });  // @33_663520
  eax = ext_5ae900_thiscall2(ecx, (u32)(eax));  // @34_663520
  ecx = edx = 0;  // @35_663520
  ecx = esi;  // @36_663520
  eax = ext_663680_thiscall1(ecx);  // @37_663520
  ecx = edx = 0;  // @38_663520
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L6635f8;  // @39_663520
  ecx = (u32)(esi + 4);  // @40_663520
  eax = ext_663b60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }));  // @41_663520
  ecx = edx = 0;  // @42_663520
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @43_663520
  edi = (edi + 1);  // @44_663520
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L6635a0;  // @45_663520
  L6635e7:;
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @47_663520
  return eax;  // @48_663520
  L6635f8:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @50_663520
  return eax;  // @51_663520
}
PCREG(663520, lifted_663520);

