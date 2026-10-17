// batch200105.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_42ba10_thiscall1(u32) __asm__("ext_42ba10");
extern "C" u32 THISCALL ext_431870_thiscall1(u32) __asm__("ext_431870");
extern "C" u32 THISCALL ext_480fd0_thiscall1(u32) __asm__("ext_480fd0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccee0_thiscall1(u32) __asm__("ext_4ccee0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d5540_thiscall1(u32) __asm__("ext_4d5540");
extern "C" u32 THISCALL ext_4d8450_thiscall1(u32) __asm__("ext_4d8450");
extern "C" u32 THISCALL ext_4e66a0_thiscall1(u32) __asm__("ext_4e66a0");
extern "C" u32 THISCALL ext_4e6b40_thiscall1(u32) __asm__("ext_4e6b40");
extern "C" u32 THISCALL ext_511a00_thiscall1(u32) __asm__("ext_511a00");
extern "C" u32 THISCALL ext_533d60_thiscall1(u32) __asm__("ext_533d60");
extern "C" u32 THISCALL ext_5421b0_thiscall1(u32) __asm__("ext_5421b0");
extern "C" u32 THISCALL ext_5855c0_thiscall1(u32) __asm__("ext_5855c0");
extern "C" u32 THISCALL ext_589560_thiscall1(u32) __asm__("ext_589560");
extern "C" u32 THISCALL ext_5895b0_thiscall1(u32) __asm__("ext_5895b0");
extern "C" u32 THISCALL ext_59ad30_thiscall1(u32) __asm__("ext_59ad30");
extern "C" u32 THISCALL ext_5a5440_thiscall1(u32) __asm__("ext_5a5440");
extern "C" u32 THISCALL ext_5a5490_thiscall1(u32) __asm__("ext_5a5490");
extern "C" u32 THISCALL ext_5ab460_thiscall1(u32) __asm__("ext_5ab460");
extern "C" u32 THISCALL ext_5f3af0_thiscall1(u32) __asm__("ext_5f3af0");
extern "C" u32 THISCALL ext_5f98d0_thiscall1(u32) __asm__("ext_5f98d0");
extern "C" u32 THISCALL ext_5facc0_thiscall1(u32) __asm__("ext_5facc0");
extern "C" u32 THISCALL ext_5fad10_thiscall1(u32) __asm__("ext_5fad10");
extern "C" u32 THISCALL ext_5fdb70_thiscall1(u32) __asm__("ext_5fdb70");
extern "C" u32 THISCALL ext_6042f0_thiscall1(u32) __asm__("ext_6042f0");
extern "C" u32 THISCALL ext_606c90_thiscall1(u32) __asm__("ext_606c90");
extern "C" u32 THISCALL ext_606ce0_thiscall1(u32) __asm__("ext_606ce0");
extern "C" u32 THISCALL ext_608130_thiscall1(u32) __asm__("ext_608130");
extern "C" u32 THISCALL ext_608140_thiscall1(u32) __asm__("ext_608140");
extern "C" u32 THISCALL ext_612560_thiscall1(u32) __asm__("ext_612560");
extern "C" u32 THISCALL ext_612570_thiscall1(u32) __asm__("ext_612570");
extern "C" u32 THISCALL ext_613940_thiscall1(u32) __asm__("ext_613940");
extern "C" u32 THISCALL ext_615450_thiscall1(u32) __asm__("ext_615450");
extern "C" u32 THISCALL ext_616a40_thiscall1(u32) __asm__("ext_616a40");
extern "C" u32 THISCALL ext_616a50_thiscall1(u32) __asm__("ext_616a50");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_64f380_thiscall1(u32) __asm__("ext_64f380");
extern "C" u32 THISCALL ext_651880_thiscall1(u32) __asm__("ext_651880");
extern "C" u32 THISCALL ext_658020_thiscall1(u32) __asm__("ext_658020");
extern "C" u32 THISCALL ext_65e130_thiscall1(u32) __asm__("ext_65e130");
extern "C" u32 THISCALL ext_660cc0_thiscall1(u32) __asm__("ext_660cc0");
extern "C" u32 ext_45c510_cdecl1(...) __asm__("ext_45c510");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_664cab(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_664cab
  eax = ext_4cbec0_thiscall1(ecx);  // @1_664cab
  ecx = edx = 0;  // @2_664cab
  return eax;  // @3_664cab
}
PCREG(664cab, lifted_664cab);

extern "C" u32 lifted_664d5b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_664d5b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_664d5b
  ecx = edx = 0;  // @2_664d5b
  return eax;  // @3_664d5b
}
PCREG(664d5b, lifted_664d5b);

extern "C" u32 lifted_664d71(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_664d71
  eax = ext_4cbec0_thiscall1(ecx);  // @1_664d71
  ecx = edx = 0;  // @2_664d71
  return eax;  // @3_664d71
}
PCREG(664d71, lifted_664d71);

extern "C" u32 lifted_664ef1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_664ef1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_664ef1
  ecx = edx = 0;  // @2_664ef1
  return eax;  // @3_664ef1
}
PCREG(664ef1, lifted_664ef1);

extern "C" u32 lifted_6655f2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_6655f2
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6655f2
  ecx = edx = 0;  // @2_6655f2
  return eax;  // @3_6655f2
}
PCREG(6655f2, lifted_6655f2);

extern "C" u32 lifted_665dd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_665dd0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_665dd0
  ecx = edx = 0;  // @2_665dd0
  return eax;  // @3_665dd0
}
PCREG(665dd0, lifted_665dd0);

extern "C" u32 lifted_66669b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_66669b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66669b
  ecx = edx = 0;  // @2_66669b
  return eax;  // @3_66669b
}
PCREG(66669b, lifted_66669b);

extern "C" u32 lifted_666850(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_666850
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666850
  ecx = edx = 0;  // @2_666850
  return eax;  // @3_666850
}
PCREG(666850, lifted_666850);

extern "C" u32 lifted_6672fe(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 424);  // @0_6672fe
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672fe
  ecx = edx = 0;  // @2_6672fe
  return eax;  // @3_6672fe
}
PCREG(6672fe, lifted_6672fe);

extern "C" u32 lifted_6679a6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_6679a6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6679a6
  ecx = edx = 0;  // @2_6679a6
  return eax;  // @3_6679a6
}
PCREG(6679a6, lifted_6679a6);

extern "C" u32 lifted_667a76(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_667a76
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667a76
  ecx = edx = 0;  // @2_667a76
  return eax;  // @3_667a76
}
PCREG(667a76, lifted_667a76);

extern "C" u32 lifted_667b36(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_667b36
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b36
  ecx = edx = 0;  // @2_667b36
  return eax;  // @3_667b36
}
PCREG(667b36, lifted_667b36);

extern "C" u32 lifted_667b41(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_667b41
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b41
  ecx = edx = 0;  // @2_667b41
  return eax;  // @3_667b41
}
PCREG(667b41, lifted_667b41);

extern "C" u32 lifted_667b57(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_667b57
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b57
  ecx = edx = 0;  // @2_667b57
  return eax;  // @3_667b57
}
PCREG(667b57, lifted_667b57);

extern "C" u32 lifted_667b78(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_667b78
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b78
  ecx = edx = 0;  // @2_667b78
  return eax;  // @3_667b78
}
PCREG(667b78, lifted_667b78);

extern "C" u32 lifted_66883b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 400);  // @0_66883b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66883b
  ecx = edx = 0;  // @2_66883b
  return eax;  // @3_66883b
}
PCREG(66883b, lifted_66883b);

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

extern "C" u32 lifted_66e0d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e0d0
  eax = ext_651880_thiscall1(ecx);  // @1_66e0d0
  ecx = edx = 0;  // @2_66e0d0
  return eax;  // @3_66e0d0
}
PCREG(66e0d0, lifted_66e0d0);

extern "C" u32 lifted_66e122(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @0_66e122
  eax = ext_608140_thiscall1(ecx);  // @1_66e122
  ecx = edx = 0;  // @2_66e122
  return eax;  // @3_66e122
}
PCREG(66e122, lifted_66e122);

extern "C" u32 lifted_66e175(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e175
  eax = ext_608140_thiscall1(ecx);  // @1_66e175
  ecx = edx = 0;  // @2_66e175
  return eax;  // @3_66e175
}
PCREG(66e175, lifted_66e175);

extern "C" u32 lifted_66e192(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e192
  eax = ext_608140_thiscall1(ecx);  // @1_66e192
  ecx = edx = 0;  // @2_66e192
  return eax;  // @3_66e192
}
PCREG(66e192, lifted_66e192);

extern "C" u32 lifted_66e1af(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e1af
  eax = ext_608140_thiscall1(ecx);  // @1_66e1af
  ecx = edx = 0;  // @2_66e1af
  return eax;  // @3_66e1af
}
PCREG(66e1af, lifted_66e1af);

extern "C" u32 lifted_66e1cc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @0_66e1cc
  eax = ext_608130_thiscall1(ecx);  // @1_66e1cc
  ecx = edx = 0;  // @2_66e1cc
  return eax;  // @3_66e1cc
}
PCREG(66e1cc, lifted_66e1cc);

extern "C" u32 lifted_66e2f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 236), sizeof v); (u32)v; });  // @0_66e2f0
  eax = ext_612560_thiscall1(ecx);  // @1_66e2f0
  ecx = edx = 0;  // @2_66e2f0
  return eax;  // @3_66e2f0
}
PCREG(66e2f0, lifted_66e2f0);

extern "C" u32 lifted_66e540(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e540
  eax = ext_615450_thiscall1(ecx);  // @1_66e540
  ecx = edx = 0;  // @2_66e540
  return eax;  // @3_66e540
}
PCREG(66e540, lifted_66e540);

extern "C" u32 lifted_66e5c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e5c0
  eax = ext_616a40_thiscall1(ecx);  // @1_66e5c0
  ecx = edx = 0;  // @2_66e5c0
  return eax;  // @3_66e5c0
}
PCREG(66e5c0, lifted_66e5c0);

extern "C" u32 lifted_66e5f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e5f0
  eax = ext_616a50_thiscall1(ecx);  // @1_66e5f0
  ecx = edx = 0;  // @2_66e5f0
  return eax;  // @3_66e5f0
}
PCREG(66e5f0, lifted_66e5f0);

extern "C" u32 lifted_66e620(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e620
  eax = ext_616a50_thiscall1(ecx);  // @1_66e620
  ecx = edx = 0;  // @2_66e620
  return eax;  // @3_66e620
}
PCREG(66e620, lifted_66e620);

extern "C" u32 lifted_66e650(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66e650
  eax = ext_616a40_thiscall1(ecx);  // @1_66e650
  ecx = edx = 0;  // @2_66e650
  return eax;  // @3_66e650
}
PCREG(66e650, lifted_66e650);

extern "C" u32 lifted_66e680(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e680
  eax = ext_616a40_thiscall1(ecx);  // @1_66e680
  ecx = edx = 0;  // @2_66e680
  return eax;  // @3_66e680
}
PCREG(66e680, lifted_66e680);

extern "C" u32 lifted_66e740(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @0_66e740
  eax = ext_6363a0_thiscall1(ecx);  // @1_66e740
  ecx = edx = 0;  // @2_66e740
  return eax;  // @3_66e740
}
PCREG(66e740, lifted_66e740);

extern "C" u32 lifted_66ec20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ec20
  eax = ext_4e66a0_thiscall1(ecx);  // @1_66ec20
  ecx = edx = 0;  // @2_66ec20
  return eax;  // @3_66ec20
}
PCREG(66ec20, lifted_66ec20);

extern "C" u32 lifted_66ecb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ecb0
  eax = ext_658020_thiscall1(ecx);  // @1_66ecb0
  ecx = edx = 0;  // @2_66ecb0
  return eax;  // @3_66ecb0
}
PCREG(66ecb0, lifted_66ecb0);

extern "C" u32 lifted_66ed40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ed40
  eax = ext_64f380_thiscall1(ecx);  // @1_66ed40
  ecx = edx = 0;  // @2_66ed40
  return eax;  // @3_66ed40
}
PCREG(66ed40, lifted_66ed40);

extern "C" u32 lifted_66407b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_66407b
  ecx = (ecx + (u32)(7825));  // @1_66407b
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66407b
  ecx = edx = 0;  // @3_66407b
  return eax;  // @4_66407b
}
PCREG(66407b, lifted_66407b);

extern "C" u32 lifted_66408c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_66408c
  ecx = (ecx + (u32)(7953));  // @1_66408c
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66408c
  ecx = edx = 0;  // @3_66408c
  return eax;  // @4_66408c
}
PCREG(66408c, lifted_66408c);

extern "C" u32 lifted_66409d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_66409d
  ecx = (ecx + (u32)(8081));  // @1_66409d
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66409d
  ecx = edx = 0;  // @3_66409d
  return eax;  // @4_66409d
}
PCREG(66409d, lifted_66409d);

extern "C" u32 lifted_6640ae(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6640ae
  ecx = (ecx + (u32)(8209));  // @1_6640ae
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6640ae
  ecx = edx = 0;  // @3_6640ae
  return eax;  // @4_6640ae
}
PCREG(6640ae, lifted_6640ae);

extern "C" u32 lifted_6640bf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6640bf
  ecx = (ecx + (u32)(8337));  // @1_6640bf
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6640bf
  ecx = edx = 0;  // @3_6640bf
  return eax;  // @4_6640bf
}
PCREG(6640bf, lifted_6640bf);

extern "C" u32 lifted_6640d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6640d0
  ecx = (ecx + (u32)(8465));  // @1_6640d0
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6640d0
  ecx = edx = 0;  // @3_6640d0
  return eax;  // @4_6640d0
}
PCREG(6640d0, lifted_6640d0);

extern "C" u32 lifted_6640e1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6640e1
  ecx = (ecx + (u32)(8593));  // @1_6640e1
  eax = ext_4ccf60_thiscall1(ecx);  // @2_6640e1
  ecx = edx = 0;  // @3_6640e1
  return eax;  // @4_6640e1
}
PCREG(6640e1, lifted_6640e1);

extern "C" u32 lifted_6640f2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6640f2
  ecx = (ecx + (u32)(8770));  // @1_6640f2
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6640f2
  ecx = edx = 0;  // @3_6640f2
  return eax;  // @4_6640f2
}
PCREG(6640f2, lifted_6640f2);

extern "C" u32 lifted_664103(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_664103
  ecx = (ecx + (u32)(8902));  // @1_664103
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664103
  ecx = edx = 0;  // @3_664103
  return eax;  // @4_664103
}
PCREG(664103, lifted_664103);

extern "C" u32 lifted_664114(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_664114
  ecx = (ecx + (u32)(9030));  // @1_664114
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664114
  ecx = edx = 0;  // @3_664114
  return eax;  // @4_664114
}
PCREG(664114, lifted_664114);

extern "C" u32 lifted_664125(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_664125
  ecx = (ecx + (u32)(9179));  // @1_664125
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664125
  ecx = edx = 0;  // @3_664125
  return eax;  // @4_664125
}
PCREG(664125, lifted_664125);

extern "C" u32 lifted_664136(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_664136
  ecx = (ecx + (u32)(9307));  // @1_664136
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664136
  ecx = edx = 0;  // @3_664136
  return eax;  // @4_664136
}
PCREG(664136, lifted_664136);

extern "C" u32 lifted_664147(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_664147
  ecx = (ecx + (u32)(9435));  // @1_664147
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664147
  ecx = edx = 0;  // @3_664147
  return eax;  // @4_664147
}
PCREG(664147, lifted_664147);

extern "C" u32 lifted_664158(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_664158
  ecx = (ecx + (u32)(9563));  // @1_664158
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664158
  ecx = edx = 0;  // @3_664158
  return eax;  // @4_664158
}
PCREG(664158, lifted_664158);

extern "C" u32 lifted_66487b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_66487b
  ecx = (ecx + (u32)(7025));  // @1_66487b
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66487b
  ecx = edx = 0;  // @3_66487b
  return eax;  // @4_66487b
}
PCREG(66487b, lifted_66487b);

extern "C" u32 lifted_66488c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_66488c
  ecx = (ecx + (u32)(7153));  // @1_66488c
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66488c
  ecx = edx = 0;  // @3_66488c
  return eax;  // @4_66488c
}
PCREG(66488c, lifted_66488c);

extern "C" u32 lifted_66489d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_66489d
  ecx = (ecx + (u32)(7281));  // @1_66489d
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66489d
  ecx = edx = 0;  // @3_66489d
  return eax;  // @4_66489d
}
PCREG(66489d, lifted_66489d);

extern "C" u32 lifted_6648ae(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6648ae
  ecx = (ecx + (u32)(7409));  // @1_6648ae
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6648ae
  ecx = edx = 0;  // @3_6648ae
  return eax;  // @4_6648ae
}
PCREG(6648ae, lifted_6648ae);

extern "C" u32 lifted_6648bf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6648bf
  ecx = (ecx + (u32)(7537));  // @1_6648bf
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6648bf
  ecx = edx = 0;  // @3_6648bf
  return eax;  // @4_6648bf
}
PCREG(6648bf, lifted_6648bf);

extern "C" u32 lifted_6648d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6648d0
  ecx = (ecx + (u32)(7691));  // @1_6648d0
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6648d0
  ecx = edx = 0;  // @3_6648d0
  return eax;  // @4_6648d0
}
PCREG(6648d0, lifted_6648d0);

extern "C" u32 lifted_664a00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a00
  ecx = (ecx + (u32)(163));  // @1_664a00
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a00
  ecx = edx = 0;  // @3_664a00
  return eax;  // @4_664a00
}
PCREG(664a00, lifted_664a00);

extern "C" u32 lifted_664a11(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a11
  ecx = (ecx + (u32)(291));  // @1_664a11
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a11
  ecx = edx = 0;  // @3_664a11
  return eax;  // @4_664a11
}
PCREG(664a11, lifted_664a11);

extern "C" u32 lifted_664a22(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a22
  ecx = (ecx + (u32)(419));  // @1_664a22
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a22
  ecx = edx = 0;  // @3_664a22
  return eax;  // @4_664a22
}
PCREG(664a22, lifted_664a22);

extern "C" u32 lifted_664a33(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a33
  ecx = (ecx + (u32)(547));  // @1_664a33
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a33
  ecx = edx = 0;  // @3_664a33
  return eax;  // @4_664a33
}
PCREG(664a33, lifted_664a33);

extern "C" u32 lifted_664a44(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a44
  ecx = (ecx + (u32)(675));  // @1_664a44
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a44
  ecx = edx = 0;  // @3_664a44
  return eax;  // @4_664a44
}
PCREG(664a44, lifted_664a44);

extern "C" u32 lifted_664a55(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a55
  ecx = (ecx + (u32)(803));  // @1_664a55
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a55
  ecx = edx = 0;  // @3_664a55
  return eax;  // @4_664a55
}
PCREG(664a55, lifted_664a55);

extern "C" u32 lifted_664a66(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a66
  ecx = (ecx + (u32)(931));  // @1_664a66
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a66
  ecx = edx = 0;  // @3_664a66
  return eax;  // @4_664a66
}
PCREG(664a66, lifted_664a66);

extern "C" u32 lifted_664a77(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a77
  ecx = (ecx + (u32)(1059));  // @1_664a77
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a77
  ecx = edx = 0;  // @3_664a77
  return eax;  // @4_664a77
}
PCREG(664a77, lifted_664a77);

extern "C" u32 lifted_664a88(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a88
  ecx = (ecx + (u32)(1187));  // @1_664a88
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a88
  ecx = edx = 0;  // @3_664a88
  return eax;  // @4_664a88
}
PCREG(664a88, lifted_664a88);

extern "C" u32 lifted_664a99(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664a99
  ecx = (ecx + (u32)(1315));  // @1_664a99
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664a99
  ecx = edx = 0;  // @3_664a99
  return eax;  // @4_664a99
}
PCREG(664a99, lifted_664a99);

extern "C" u32 lifted_664aaa(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664aaa
  ecx = (ecx + (u32)(1443));  // @1_664aaa
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664aaa
  ecx = edx = 0;  // @3_664aaa
  return eax;  // @4_664aaa
}
PCREG(664aaa, lifted_664aaa);

extern "C" u32 lifted_664abb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664abb
  ecx = (ecx + (u32)(1571));  // @1_664abb
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664abb
  ecx = edx = 0;  // @3_664abb
  return eax;  // @4_664abb
}
PCREG(664abb, lifted_664abb);

extern "C" u32 lifted_664acc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664acc
  ecx = (ecx + (u32)(1699));  // @1_664acc
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664acc
  ecx = edx = 0;  // @3_664acc
  return eax;  // @4_664acc
}
PCREG(664acc, lifted_664acc);

extern "C" u32 lifted_664add(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664add
  ecx = (ecx + (u32)(1827));  // @1_664add
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664add
  ecx = edx = 0;  // @3_664add
  return eax;  // @4_664add
}
PCREG(664add, lifted_664add);

extern "C" u32 lifted_664aee(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664aee
  ecx = (ecx + (u32)(1955));  // @1_664aee
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664aee
  ecx = edx = 0;  // @3_664aee
  return eax;  // @4_664aee
}
PCREG(664aee, lifted_664aee);

extern "C" u32 lifted_664aff(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664aff
  ecx = (ecx + (u32)(2083));  // @1_664aff
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664aff
  ecx = edx = 0;  // @3_664aff
  return eax;  // @4_664aff
}
PCREG(664aff, lifted_664aff);

extern "C" u32 lifted_664b10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664b10
  ecx = (ecx + (u32)(2211));  // @1_664b10
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664b10
  ecx = edx = 0;  // @3_664b10
  return eax;  // @4_664b10
}
PCREG(664b10, lifted_664b10);

extern "C" u32 lifted_664b21(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664b21
  ecx = (ecx + (u32)(2339));  // @1_664b21
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664b21
  ecx = edx = 0;  // @3_664b21
  return eax;  // @4_664b21
}
PCREG(664b21, lifted_664b21);

extern "C" u32 lifted_664b32(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664b32
  ecx = (ecx + (u32)(6423));  // @1_664b32
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664b32
  ecx = edx = 0;  // @3_664b32
  return eax;  // @4_664b32
}
PCREG(664b32, lifted_664b32);

extern "C" u32 lifted_664b43(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664b43
  ecx = (ecx + (u32)(6551));  // @1_664b43
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664b43
  ecx = edx = 0;  // @3_664b43
  return eax;  // @4_664b43
}
PCREG(664b43, lifted_664b43);

extern "C" u32 lifted_664b54(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664b54
  ecx = (ecx + (u32)(6679));  // @1_664b54
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664b54
  ecx = edx = 0;  // @3_664b54
  return eax;  // @4_664b54
}
PCREG(664b54, lifted_664b54);

extern "C" u32 lifted_664b65(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_664b65
  ecx = (ecx + (u32)(6839));  // @1_664b65
  eax = ext_4cbec0_thiscall1(ecx);  // @2_664b65
  ecx = edx = 0;  // @3_664b65
  return eax;  // @4_664b65
}
PCREG(664b65, lifted_664b65);

extern "C" u32 lifted_6653a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6653a0
  ecx = (ecx + (u32)(4));  // @1_6653a0
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6653a0
  ecx = edx = 0;  // @3_6653a0
  return eax;  // @4_6653a0
}
PCREG(6653a0, lifted_6653a0);

extern "C" u32 lifted_6653ae(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6653ae
  ecx = (ecx + (u32)(132));  // @1_6653ae
  eax = ext_4cce40_thiscall1(ecx);  // @2_6653ae
  ecx = edx = 0;  // @3_6653ae
  return eax;  // @4_6653ae
}
PCREG(6653ae, lifted_6653ae);

extern "C" u32 lifted_6653bf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6653bf
  ecx = (ecx + (u32)(172));  // @1_6653bf
  eax = ext_4cd0e0_thiscall1(ecx);  // @2_6653bf
  ecx = edx = 0;  // @3_6653bf
  return eax;  // @4_6653bf
}
PCREG(6653bf, lifted_6653bf);

extern "C" u32 lifted_6653d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @0_6653d0
  ecx = (ecx + (u32)(200));  // @1_6653d0
  eax = ext_4cd0e0_thiscall1(ecx);  // @2_6653d0
  ecx = edx = 0;  // @3_6653d0
  return eax;  // @4_6653d0
}
PCREG(6653d0, lifted_6653d0);

extern "C" u32 lifted_665670(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665670
  ecx = (ecx + (u32)(12));  // @1_665670
  eax = ext_4cbec0_thiscall1(ecx);  // @2_665670
  ecx = edx = 0;  // @3_665670
  return eax;  // @4_665670
}
PCREG(665670, lifted_665670);

extern "C" u32 lifted_665ce8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665ce8
  ecx = (ecx + (u32)(16));  // @1_665ce8
  eax = ext_431870_thiscall1(ecx);  // @2_665ce8
  ecx = edx = 0;  // @3_665ce8
  return eax;  // @4_665ce8
}
PCREG(665ce8, lifted_665ce8);

extern "C" u32 lifted_665cf3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665cf3
  ecx = (ecx + (u32)(195));  // @1_665cf3
  eax = ext_4cbec0_thiscall1(ecx);  // @2_665cf3
  ecx = edx = 0;  // @3_665cf3
  return eax;  // @4_665cf3
}
PCREG(665cf3, lifted_665cf3);

extern "C" u32 lifted_665d01(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665d01
  ecx = (ecx + (u32)(323));  // @1_665d01
  eax = ext_4cbec0_thiscall1(ecx);  // @2_665d01
  ecx = edx = 0;  // @3_665d01
  return eax;  // @4_665d01
}
PCREG(665d01, lifted_665d01);

extern "C" u32 lifted_666b68(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_666b68
  ecx = (ecx + (u32)(97));  // @1_666b68
  eax = ext_4cbec0_thiscall1(ecx);  // @2_666b68
  ecx = edx = 0;  // @3_666b68
  return eax;  // @4_666b68
}
PCREG(666b68, lifted_666b68);

extern "C" u32 lifted_667178(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_667178
  ecx = (ecx + (u32)(1042));  // @1_667178
  eax = ext_4cbec0_thiscall1(ecx);  // @2_667178
  ecx = edx = 0;  // @3_667178
  return eax;  // @4_667178
}
PCREG(667178, lifted_667178);

extern "C" u32 lifted_667628(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_667628
  ecx = (ecx + (u32)(37));  // @1_667628
  eax = ext_480fd0_thiscall1(ecx);  // @2_667628
  ecx = edx = 0;  // @3_667628
  return eax;  // @4_667628
}
PCREG(667628, lifted_667628);

extern "C" u32 lifted_667633(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_667633
  ecx = (ecx + (u32)(61));  // @1_667633
  eax = ext_480fd0_thiscall1(ecx);  // @2_667633
  ecx = edx = 0;  // @3_667633
  return eax;  // @4_667633
}
PCREG(667633, lifted_667633);

extern "C" u32 lifted_667668(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_667668
  ecx = (ecx + (u32)(221));  // @1_667668
  eax = ext_480fd0_thiscall1(ecx);  // @2_667668
  ecx = edx = 0;  // @3_667668
  return eax;  // @4_667668
}
PCREG(667668, lifted_667668);

extern "C" u32 lifted_667676(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_667676
  ecx = (ecx + (u32)(245));  // @1_667676
  eax = ext_480fd0_thiscall1(ecx);  // @2_667676
  ecx = edx = 0;  // @3_667676
  return eax;  // @4_667676
}
PCREG(667676, lifted_667676);

extern "C" u32 lifted_6676d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_6676d0
  ecx = (ecx + (u32)(28));  // @1_6676d0
  eax = ext_4cce40_thiscall1(ecx);  // @2_6676d0
  ecx = edx = 0;  // @3_6676d0
  return eax;  // @4_6676d0
}
PCREG(6676d0, lifted_6676d0);

extern "C" u32 lifted_6676de(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_6676de
  ecx = (ecx + (u32)(2816));  // @1_6676de
  eax = ext_4ccf60_thiscall1(ecx);  // @2_6676de
  ecx = edx = 0;  // @3_6676de
  return eax;  // @4_6676de
}
PCREG(6676de, lifted_6676de);

extern "C" u32 lifted_6676ef(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_6676ef
  ecx = (ecx + (u32)(3021));  // @1_6676ef
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6676ef
  ecx = edx = 0;  // @3_6676ef
  return eax;  // @4_6676ef
}
PCREG(6676ef, lifted_6676ef);

extern "C" u32 lifted_667700(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @0_667700
  ecx = (ecx + (u32)(7265));  // @1_667700
  eax = ext_4d2330_thiscall1(ecx);  // @2_667700
  ecx = edx = 0;  // @3_667700
  return eax;  // @4_667700
}
PCREG(667700, lifted_667700);

extern "C" u32 lifted_668310(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668310
  ecx = (ecx + (u32)(4));  // @1_668310
  eax = ext_4e6b40_thiscall1(ecx);  // @2_668310
  ecx = edx = 0;  // @3_668310
  return eax;  // @4_668310
}
PCREG(668310, lifted_668310);

extern "C" u32 lifted_668350(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668350
  ecx = (ecx + (u32)(4));  // @1_668350
  eax = ext_4e6b40_thiscall1(ecx);  // @2_668350
  ecx = edx = 0;  // @3_668350
  return eax;  // @4_668350
}
PCREG(668350, lifted_668350);

extern "C" u32 lifted_6685f8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6685f8
  ecx = (ecx + (u32)(92));  // @1_6685f8
  eax = ext_4ccf60_thiscall1(ecx);  // @2_6685f8
  ecx = edx = 0;  // @3_6685f8
  return eax;  // @4_6685f8
}
PCREG(6685f8, lifted_6685f8);

extern "C" u32 lifted_668628(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668628
  ecx = (ecx + (u32)(89692));  // @1_668628
  eax = ext_4ccfe0_thiscall1(ecx);  // @2_668628
  ecx = edx = 0;  // @3_668628
  return eax;  // @4_668628
}
PCREG(668628, lifted_668628);

extern "C" u32 lifted_668729(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_668729
  ecx = (ecx + (u32)(110));  // @1_668729
  eax = ext_4ccf60_thiscall1(ecx);  // @2_668729
  ecx = edx = 0;  // @3_668729
  return eax;  // @4_668729
}
PCREG(668729, lifted_668729);

extern "C" u32 lifted_668734(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_668734
  ecx = (ecx + (u32)(282));  // @1_668734
  eax = ext_4ccf60_thiscall1(ecx);  // @2_668734
  ecx = edx = 0;  // @3_668734
  return eax;  // @4_668734
}
PCREG(668734, lifted_668734);

extern "C" u32 lifted_668998(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668998
  ecx = (ecx + (u32)(170));  // @1_668998
  eax = ext_4ccee0_thiscall1(ecx);  // @2_668998
  ecx = edx = 0;  // @3_668998
  return eax;  // @4_668998
}
PCREG(668998, lifted_668998);

extern "C" u32 lifted_6689a6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6689a6
  ecx = (ecx + (u32)(242));  // @1_6689a6
  eax = ext_4ccfe0_thiscall1(ecx);  // @2_6689a6
  ecx = edx = 0;  // @3_6689a6
  return eax;  // @4_6689a6
}
PCREG(6689a6, lifted_6689a6);

extern "C" u32 lifted_6689d8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6689d8
  ecx = (ecx + (u32)(149));  // @1_6689d8
  eax = ext_4cbec0_thiscall1(ecx);  // @2_6689d8
  ecx = edx = 0;  // @3_6689d8
  return eax;  // @4_6689d8
}
PCREG(6689d8, lifted_6689d8);

extern "C" u32 lifted_668cd9(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_668cd9
  ecx = (ecx + (u32)(72));  // @1_668cd9
  eax = ext_4ccf60_thiscall1(ecx);  // @2_668cd9
  ecx = edx = 0;  // @3_668cd9
  return eax;  // @4_668cd9
}
PCREG(668cd9, lifted_668cd9);

extern "C" u32 lifted_668d48(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668d48
  ecx = (ecx + (u32)(72));  // @1_668d48
  eax = ext_4ccf60_thiscall1(ecx);  // @2_668d48
  ecx = edx = 0;  // @3_668d48
  return eax;  // @4_668d48
}
PCREG(668d48, lifted_668d48);

extern "C" u32 lifted_668d89(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_668d89
  ecx = (ecx + (u32)(84));  // @1_668d89
  eax = ext_4ccf60_thiscall1(ecx);  // @2_668d89
  ecx = edx = 0;  // @3_668d89
  return eax;  // @4_668d89
}
PCREG(668d89, lifted_668d89);

extern "C" u32 lifted_6693a8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6693a8
  ecx = (ecx + (u32)(16392));  // @1_6693a8
  eax = ext_4ccf60_thiscall1(ecx);  // @2_6693a8
  ecx = edx = 0;  // @3_6693a8
  return eax;  // @4_6693a8
}
PCREG(6693a8, lifted_6693a8);

extern "C" u32 lifted_669420(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_669420
  ecx = (ecx + (u32)(4315));  // @1_669420
  eax = ext_4d8450_thiscall1(ecx);  // @2_669420
  ecx = edx = 0;  // @3_669420
  return eax;  // @4_669420
}
PCREG(669420, lifted_669420);

extern "C" u32 lifted_6694f8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6694f8
  ecx = (ecx + (u32)(70));  // @1_6694f8
  eax = ext_4d5540_thiscall1(ecx);  // @2_6694f8
  ecx = edx = 0;  // @3_6694f8
  return eax;  // @4_6694f8
}
PCREG(6694f8, lifted_6694f8);

extern "C" u32 lifted_669503(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_669503
  ecx = (ecx + (u32)(82));  // @1_669503
  eax = ext_4d5540_thiscall1(ecx);  // @2_669503
  ecx = edx = 0;  // @3_669503
  return eax;  // @4_669503
}
PCREG(669503, lifted_669503);

extern "C" u32 lifted_66950e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66950e
  ecx = (ecx + (u32)(94));  // @1_66950e
  eax = ext_4d5540_thiscall1(ecx);  // @2_66950e
  ecx = edx = 0;  // @3_66950e
  return eax;  // @4_66950e
}
PCREG(66950e, lifted_66950e);

extern "C" u32 lifted_669611(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_669611
  ecx = (ecx + (u32)(4));  // @1_669611
  eax = ext_4cbec0_thiscall1(ecx);  // @2_669611
  ecx = edx = 0;  // @3_669611
  return eax;  // @4_669611
}
PCREG(669611, lifted_669611);

extern "C" u32 lifted_66962e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66962e
  ecx = (ecx + (u32)(4));  // @1_66962e
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66962e
  ecx = edx = 0;  // @3_66962e
  return eax;  // @4_66962e
}
PCREG(66962e, lifted_66962e);

extern "C" u32 lifted_669660(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_669660
  ecx = (ecx + (u32)(4));  // @1_669660
  eax = ext_4cbec0_thiscall1(ecx);  // @2_669660
  ecx = edx = 0;  // @3_669660
  return eax;  // @4_669660
}
PCREG(669660, lifted_669660);

extern "C" u32 lifted_6697a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6697a0
  ecx = (ecx + (u32)(4));  // @1_6697a0
  eax = ext_4e6b40_thiscall1(ecx);  // @2_6697a0
  ecx = edx = 0;  // @3_6697a0
  return eax;  // @4_6697a0
}
PCREG(6697a0, lifted_6697a0);

extern "C" u32 lifted_6698c8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6698c8
  ecx = (ecx + (u32)(159));  // @1_6698c8
  eax = ext_4ccee0_thiscall1(ecx);  // @2_6698c8
  ecx = edx = 0;  // @3_6698c8
  return eax;  // @4_6698c8
}
PCREG(6698c8, lifted_6698c8);

extern "C" u32 lifted_6698d6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6698d6
  ecx = (ecx + (u32)(203));  // @1_6698d6
  eax = ext_4cce40_thiscall1(ecx);  // @2_6698d6
  ecx = edx = 0;  // @3_6698d6
  return eax;  // @4_6698d6
}
PCREG(6698d6, lifted_6698d6);

extern "C" u32 lifted_6698e4(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6698e4
  ecx = (ecx + (u32)(243));  // @1_6698e4
  eax = ext_4ccf60_thiscall1(ecx);  // @2_6698e4
  ecx = edx = 0;  // @3_6698e4
  return eax;  // @4_6698e4
}
PCREG(6698e4, lifted_6698e4);

extern "C" u32 lifted_6698f2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6698f2
  ecx = (ecx + (u32)(423));  // @1_6698f2
  eax = ext_4ccee0_thiscall1(ecx);  // @2_6698f2
  ecx = edx = 0;  // @3_6698f2
  return eax;  // @4_6698f2
}
PCREG(6698f2, lifted_6698f2);

extern "C" u32 lifted_669a48(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_669a48
  ecx = (ecx + (u32)(143));  // @1_669a48
  eax = ext_4cbec0_thiscall1(ecx);  // @2_669a48
  ecx = edx = 0;  // @3_669a48
  return eax;  // @4_669a48
}
PCREG(669a48, lifted_669a48);

extern "C" u32 lifted_66a2a8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a2a8
  ecx = (ecx + (u32)(1197));  // @1_66a2a8
  eax = ext_4690b0_cdecl0();  // @2_66a2a8
  ecx = edx = 0;  // @3_66a2a8
  return eax;  // @4_66a2a8
}
PCREG(66a2a8, lifted_66a2a8);

extern "C" u32 lifted_66a398(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a398
  ecx = (ecx + (u32)(765));  // @1_66a398
  eax = ext_511a00_thiscall1(ecx);  // @2_66a398
  ecx = edx = 0;  // @3_66a398
  return eax;  // @4_66a398
}
PCREG(66a398, lifted_66a398);

extern "C" u32 lifted_66a530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a530
  ecx = (ecx + (u32)(61));  // @1_66a530
  eax = ext_4690b0_cdecl0();  // @2_66a530
  ecx = edx = 0;  // @3_66a530
  return eax;  // @4_66a530
}
PCREG(66a530, lifted_66a530);

extern "C" u32 lifted_66a560(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a560
  ecx = (ecx + (u32)(61));  // @1_66a560
  eax = ext_4690b0_cdecl0();  // @2_66a560
  ecx = edx = 0;  // @3_66a560
  return eax;  // @4_66a560
}
PCREG(66a560, lifted_66a560);

extern "C" u32 lifted_66a7f8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a7f8
  ecx = (ecx + (u32)(139));  // @1_66a7f8
  eax = ext_533d60_thiscall1(ecx);  // @2_66a7f8
  ecx = edx = 0;  // @3_66a7f8
  return eax;  // @4_66a7f8
}
PCREG(66a7f8, lifted_66a7f8);

extern "C" u32 lifted_66a806(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a806
  ecx = (ecx + (u32)(20921));  // @1_66a806
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66a806
  ecx = edx = 0;  // @3_66a806
  return eax;  // @4_66a806
}
PCREG(66a806, lifted_66a806);

extern "C" u32 lifted_66a814(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a814
  ecx = (ecx + (u32)(21062));  // @1_66a814
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66a814
  ecx = edx = 0;  // @3_66a814
  return eax;  // @4_66a814
}
PCREG(66a814, lifted_66a814);

extern "C" u32 lifted_66a822(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a822
  ecx = (ecx + (u32)(21254));  // @1_66a822
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66a822
  ecx = edx = 0;  // @3_66a822
  return eax;  // @4_66a822
}
PCREG(66a822, lifted_66a822);

extern "C" u32 lifted_66a830(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a830
  ecx = (ecx + (u32)(21426));  // @1_66a830
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66a830
  ecx = edx = 0;  // @3_66a830
  return eax;  // @4_66a830
}
PCREG(66a830, lifted_66a830);

extern "C" u32 lifted_66aaa8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66aaa8
  ecx = (ecx + (u32)(106));  // @1_66aaa8
  eax = ext_5421b0_thiscall1(ecx);  // @2_66aaa8
  ecx = edx = 0;  // @3_66aaa8
  return eax;  // @4_66aaa8
}
PCREG(66aaa8, lifted_66aaa8);

extern "C" u32 lifted_66b180(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b180
  ecx = (ecx + (u32)(44));  // @1_66b180
  eax = ext_431870_thiscall1(ecx);  // @2_66b180
  ecx = edx = 0;  // @3_66b180
  return eax;  // @4_66b180
}
PCREG(66b180, lifted_66b180);

extern "C" u32 lifted_66b1b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b1b0
  ecx = (ecx + (u32)(44));  // @1_66b1b0
  eax = ext_431870_thiscall1(ecx);  // @2_66b1b0
  ecx = edx = 0;  // @3_66b1b0
  return eax;  // @4_66b1b0
}
PCREG(66b1b0, lifted_66b1b0);

extern "C" u32 lifted_66b1e8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b1e8
  ecx = (ecx + (u32)(400));  // @1_66b1e8
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66b1e8
  ecx = edx = 0;  // @3_66b1e8
  return eax;  // @4_66b1e8
}
PCREG(66b1e8, lifted_66b1e8);

extern "C" u32 lifted_66b1f6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b1f6
  ecx = (ecx + (u32)(572));  // @1_66b1f6
  eax = ext_4cce40_thiscall1(ecx);  // @2_66b1f6
  ecx = edx = 0;  // @3_66b1f6
  return eax;  // @4_66b1f6
}
PCREG(66b1f6, lifted_66b1f6);

extern "C" u32 lifted_66b5a8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b5a8
  ecx = (ecx + (u32)(95));  // @1_66b5a8
  eax = ext_5855c0_thiscall1(ecx);  // @2_66b5a8
  ecx = edx = 0;  // @3_66b5a8
  return eax;  // @4_66b5a8
}
PCREG(66b5a8, lifted_66b5a8);

extern "C" u32 lifted_66b688(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66b688
  ecx = (ecx + (u32)(2901));  // @1_66b688
  eax = ext_589560_thiscall1(ecx);  // @2_66b688
  ecx = edx = 0;  // @3_66b688
  return eax;  // @4_66b688
}
PCREG(66b688, lifted_66b688);

extern "C" u32 lifted_66b696(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66b696
  ecx = (ecx + (u32)(3469));  // @1_66b696
  eax = ext_5895b0_thiscall1(ecx);  // @2_66b696
  ecx = edx = 0;  // @3_66b696
  return eax;  // @4_66b696
}
PCREG(66b696, lifted_66b696);

extern "C" u32 lifted_66b728(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66b728
  ecx = (ecx + (u32)(1688));  // @1_66b728
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66b728
  ecx = edx = 0;  // @3_66b728
  return eax;  // @4_66b728
}
PCREG(66b728, lifted_66b728);

extern "C" u32 lifted_66bab8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66bab8
  ecx = (ecx + (u32)(7586));  // @1_66bab8
  eax = ext_5a5440_thiscall1(ecx);  // @2_66bab8
  ecx = edx = 0;  // @3_66bab8
  return eax;  // @4_66bab8
}
PCREG(66bab8, lifted_66bab8);

extern "C" u32 lifted_66bc48(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66bc48
  ecx = (ecx + (u32)(4196));  // @1_66bc48
  eax = ext_59ad30_thiscall1(ecx);  // @2_66bc48
  ecx = edx = 0;  // @3_66bc48
  return eax;  // @4_66bc48
}
PCREG(66bc48, lifted_66bc48);

extern "C" u32 lifted_66bf18(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66bf18
  ecx = (ecx + (u32)(1340));  // @1_66bf18
  eax = ext_5a5490_thiscall1(ecx);  // @2_66bf18
  ecx = edx = 0;  // @3_66bf18
  return eax;  // @4_66bf18
}
PCREG(66bf18, lifted_66bf18);

extern "C" u32 lifted_66bf26(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66bf26
  ecx = (ecx + (u32)(1354));  // @1_66bf26
  eax = ext_5a5490_thiscall1(ecx);  // @2_66bf26
  ecx = edx = 0;  // @3_66bf26
  return eax;  // @4_66bf26
}
PCREG(66bf26, lifted_66bf26);

extern "C" u32 lifted_66bf34(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66bf34
  ecx = (ecx + (u32)(1625));  // @1_66bf34
  eax = ext_5a5440_thiscall1(ecx);  // @2_66bf34
  ecx = edx = 0;  // @3_66bf34
  return eax;  // @4_66bf34
}
PCREG(66bf34, lifted_66bf34);

extern "C" u32 lifted_66bf42(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66bf42
  ecx = (ecx + (u32)(1637));  // @1_66bf42
  eax = ext_5a5440_thiscall1(ecx);  // @2_66bf42
  ecx = edx = 0;  // @3_66bf42
  return eax;  // @4_66bf42
}
PCREG(66bf42, lifted_66bf42);

extern "C" u32 lifted_66bf50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66bf50
  ecx = (ecx + (u32)(1649));  // @1_66bf50
  eax = ext_5a5440_thiscall1(ecx);  // @2_66bf50
  ecx = edx = 0;  // @3_66bf50
  return eax;  // @4_66bf50
}
PCREG(66bf50, lifted_66bf50);

extern "C" u32 lifted_66c1a8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @0_66c1a8
  ecx = (ecx + (u32)(110));  // @1_66c1a8
  eax = ext_5ab460_thiscall1(ecx);  // @2_66c1a8
  ecx = edx = 0;  // @3_66c1a8
  return eax;  // @4_66c1a8
}
PCREG(66c1a8, lifted_66c1a8);

extern "C" u32 lifted_66c416(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c416
  ecx = (ecx + (u32)(304));  // @1_66c416
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66c416
  ecx = edx = 0;  // @3_66c416
  return eax;  // @4_66c416
}
PCREG(66c416, lifted_66c416);

extern "C" u32 lifted_66c424(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c424
  ecx = (ecx + (u32)(488));  // @1_66c424
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66c424
  ecx = edx = 0;  // @3_66c424
  return eax;  // @4_66c424
}
PCREG(66c424, lifted_66c424);

extern "C" u32 lifted_66c432(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c432
  ecx = (ecx + (u32)(710));  // @1_66c432
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66c432
  ecx = edx = 0;  // @3_66c432
  return eax;  // @4_66c432
}
PCREG(66c432, lifted_66c432);

extern "C" u32 lifted_66c5b8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c5b8
  ecx = (ecx + (u32)(84));  // @1_66c5b8
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66c5b8
  ecx = edx = 0;  // @3_66c5b8
  return eax;  // @4_66c5b8
}
PCREG(66c5b8, lifted_66c5b8);

extern "C" u32 lifted_66c5c3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c5c3
  ecx = (ecx + (u32)(256));  // @1_66c5c3
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66c5c3
  ecx = edx = 0;  // @3_66c5c3
  return eax;  // @4_66c5c3
}
PCREG(66c5c3, lifted_66c5c3);

extern "C" u32 lifted_66c5d1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c5d1
  ecx = (ecx + (u32)(430));  // @1_66c5d1
  eax = ext_4ccf60_thiscall1(ecx);  // @2_66c5d1
  ecx = edx = 0;  // @3_66c5d1
  return eax;  // @4_66c5d1
}
PCREG(66c5d1, lifted_66c5d1);

extern "C" u32 lifted_66c8f8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c8f8
  ecx = (ecx + (u32)(979));  // @1_66c8f8
  eax = ext_480fd0_thiscall1(ecx);  // @2_66c8f8
  ecx = edx = 0;  // @3_66c8f8
  return eax;  // @4_66c8f8
}
PCREG(66c8f8, lifted_66c8f8);

extern "C" u32 lifted_66c914(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c914
  ecx = (ecx + (u32)(1195));  // @1_66c914
  eax = ext_480fd0_thiscall1(ecx);  // @2_66c914
  ecx = edx = 0;  // @3_66c914
  return eax;  // @4_66c914
}
PCREG(66c914, lifted_66c914);

extern "C" u32 lifted_66c988(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c988
  ecx = (ecx + (u32)(269));  // @1_66c988
  eax = ext_480fd0_thiscall1(ecx);  // @2_66c988
  ecx = edx = 0;  // @3_66c988
  return eax;  // @4_66c988
}
PCREG(66c988, lifted_66c988);

extern "C" u32 lifted_66c996(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c996
  ecx = (ecx + (u32)(293));  // @1_66c996
  eax = ext_480fd0_thiscall1(ecx);  // @2_66c996
  ecx = edx = 0;  // @3_66c996
  return eax;  // @4_66c996
}
PCREG(66c996, lifted_66c996);

extern "C" u32 lifted_66c9a4(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c9a4
  ecx = (ecx + (u32)(317));  // @1_66c9a4
  eax = ext_480fd0_thiscall1(ecx);  // @2_66c9a4
  ecx = edx = 0;  // @3_66c9a4
  return eax;  // @4_66c9a4
}
PCREG(66c9a4, lifted_66c9a4);

extern "C" u32 lifted_66c9b2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c9b2
  ecx = (ecx + (u32)(341));  // @1_66c9b2
  eax = ext_480fd0_thiscall1(ecx);  // @2_66c9b2
  ecx = edx = 0;  // @3_66c9b2
  return eax;  // @4_66c9b2
}
PCREG(66c9b2, lifted_66c9b2);

extern "C" u32 lifted_66cac8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cac8
  ecx = (ecx + (u32)(98));  // @1_66cac8
  eax = ext_5a5440_thiscall1(ecx);  // @2_66cac8
  ecx = edx = 0;  // @3_66cac8
  return eax;  // @4_66cac8
}
PCREG(66cac8, lifted_66cac8);

extern "C" u32 lifted_66caf8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66caf8
  ecx = (ecx + (u32)(203));  // @1_66caf8
  eax = ext_5a5440_thiscall1(ecx);  // @2_66caf8
  ecx = edx = 0;  // @3_66caf8
  return eax;  // @4_66caf8
}
PCREG(66caf8, lifted_66caf8);

extern "C" u32 lifted_66cb38(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cb38
  ecx = (ecx + (u32)(5));  // @1_66cb38
  eax = ext_5a5440_thiscall1(ecx);  // @2_66cb38
  ecx = edx = 0;  // @3_66cb38
  return eax;  // @4_66cb38
}
PCREG(66cb38, lifted_66cb38);

extern "C" u32 lifted_66cdee(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cdee
  ecx = (ecx + (u32)(8));  // @1_66cdee
  eax = ext_6042f0_thiscall1(ecx);  // @2_66cdee
  ecx = edx = 0;  // @3_66cdee
  return eax;  // @4_66cdee
}
PCREG(66cdee, lifted_66cdee);

extern "C" u32 lifted_66cdf9(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66cdf9
  ecx = (ecx + (u32)(20));  // @1_66cdf9
  eax = ext_4cbec0_thiscall1(ecx);  // @2_66cdf9
  ecx = edx = 0;  // @3_66cdf9
  return eax;  // @4_66cdf9
}
PCREG(66cdf9, lifted_66cdf9);

extern "C" u32 lifted_66d0a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d0a0
  ecx = (ecx + (u32)(40));  // @1_66d0a0
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d0a0
  ecx = edx = 0;  // @3_66d0a0
  return eax;  // @4_66d0a0
}
PCREG(66d0a0, lifted_66d0a0);

extern "C" u32 lifted_66d0ab(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d0ab
  ecx = (ecx + (u32)(52));  // @1_66d0ab
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d0ab
  ecx = edx = 0;  // @3_66d0ab
  return eax;  // @4_66d0ab
}
PCREG(66d0ab, lifted_66d0ab);

extern "C" u32 lifted_66d0b6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d0b6
  ecx = (ecx + (u32)(64));  // @1_66d0b6
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d0b6
  ecx = edx = 0;  // @3_66d0b6
  return eax;  // @4_66d0b6
}
PCREG(66d0b6, lifted_66d0b6);

extern "C" u32 lifted_66d0c1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d0c1
  ecx = (ecx + (u32)(76));  // @1_66d0c1
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d0c1
  ecx = edx = 0;  // @3_66d0c1
  return eax;  // @4_66d0c1
}
PCREG(66d0c1, lifted_66d0c1);

extern "C" u32 lifted_66d0cc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d0cc
  ecx = (ecx + (u32)(88));  // @1_66d0cc
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d0cc
  ecx = edx = 0;  // @3_66d0cc
  return eax;  // @4_66d0cc
}
PCREG(66d0cc, lifted_66d0cc);

extern "C" u32 lifted_66d100(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d100
  ecx = (ecx + (u32)(40));  // @1_66d100
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d100
  ecx = edx = 0;  // @3_66d100
  return eax;  // @4_66d100
}
PCREG(66d100, lifted_66d100);

extern "C" u32 lifted_66d10b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d10b
  ecx = (ecx + (u32)(52));  // @1_66d10b
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d10b
  ecx = edx = 0;  // @3_66d10b
  return eax;  // @4_66d10b
}
PCREG(66d10b, lifted_66d10b);

extern "C" u32 lifted_66d116(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d116
  ecx = (ecx + (u32)(64));  // @1_66d116
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d116
  ecx = edx = 0;  // @3_66d116
  return eax;  // @4_66d116
}
PCREG(66d116, lifted_66d116);

extern "C" u32 lifted_66d121(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d121
  ecx = (ecx + (u32)(76));  // @1_66d121
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d121
  ecx = edx = 0;  // @3_66d121
  return eax;  // @4_66d121
}
PCREG(66d121, lifted_66d121);

extern "C" u32 lifted_66d12c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d12c
  ecx = (ecx + (u32)(88));  // @1_66d12c
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d12c
  ecx = edx = 0;  // @3_66d12c
  return eax;  // @4_66d12c
}
PCREG(66d12c, lifted_66d12c);

extern "C" u32 lifted_66d1cf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66d1cf
  ecx = (ecx + (u32)(4));  // @1_66d1cf
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d1cf
  ecx = edx = 0;  // @3_66d1cf
  return eax;  // @4_66d1cf
}
PCREG(66d1cf, lifted_66d1cf);

extern "C" u32 lifted_66d1da(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_66d1da
  ecx = (ecx + (u32)(16));  // @1_66d1da
  eax = ext_5f98d0_thiscall1(ecx);  // @2_66d1da
  ecx = edx = 0;  // @3_66d1da
  return eax;  // @4_66d1da
}
PCREG(66d1da, lifted_66d1da);

extern "C" u32 lifted_66d268(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d268
  ecx = (ecx + (u32)(60));  // @1_66d268
  eax = ext_5fdb70_thiscall1(ecx);  // @2_66d268
  ecx = edx = 0;  // @3_66d268
  return eax;  // @4_66d268
}
PCREG(66d268, lifted_66d268);

extern "C" u32 lifted_66d298(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d298
  ecx = (ecx + (u32)(12));  // @1_66d298
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d298
  ecx = edx = 0;  // @3_66d298
  return eax;  // @4_66d298
}
PCREG(66d298, lifted_66d298);

extern "C" u32 lifted_66d2a3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d2a3
  ecx = (ecx + (u32)(24));  // @1_66d2a3
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d2a3
  ecx = edx = 0;  // @3_66d2a3
  return eax;  // @4_66d2a3
}
PCREG(66d2a3, lifted_66d2a3);

extern "C" u32 lifted_66d2d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d2d0
  ecx = (ecx + (u32)(8));  // @1_66d2d0
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d2d0
  ecx = edx = 0;  // @3_66d2d0
  return eax;  // @4_66d2d0
}
PCREG(66d2d0, lifted_66d2d0);

extern "C" u32 lifted_66d2db(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d2db
  ecx = (ecx + (u32)(24));  // @1_66d2db
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66d2db
  ecx = edx = 0;  // @3_66d2db
  return eax;  // @4_66d2db
}
PCREG(66d2db, lifted_66d2db);

extern "C" u32 lifted_66d2e6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d2e6
  ecx = (ecx + (u32)(65));  // @1_66d2e6
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d2e6
  ecx = edx = 0;  // @3_66d2e6
  return eax;  // @4_66d2e6
}
PCREG(66d2e6, lifted_66d2e6);

extern "C" u32 lifted_66d340(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d340
  ecx = (ecx + (u32)(268));  // @1_66d340
  eax = ext_5a5440_thiscall1(ecx);  // @2_66d340
  ecx = edx = 0;  // @3_66d340
  return eax;  // @4_66d340
}
PCREG(66d340, lifted_66d340);

extern "C" u32 lifted_66d34e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d34e
  ecx = (ecx + (u32)(280));  // @1_66d34e
  eax = ext_5facc0_thiscall1(ecx);  // @2_66d34e
  ecx = edx = 0;  // @3_66d34e
  return eax;  // @4_66d34e
}
PCREG(66d34e, lifted_66d34e);

extern "C" u32 lifted_66d968(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d968
  ecx = (ecx + (u32)(12));  // @1_66d968
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d968
  ecx = edx = 0;  // @3_66d968
  return eax;  // @4_66d968
}
PCREG(66d968, lifted_66d968);

extern "C" u32 lifted_66d973(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d973
  ecx = (ecx + (u32)(24));  // @1_66d973
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d973
  ecx = edx = 0;  // @3_66d973
  return eax;  // @4_66d973
}
PCREG(66d973, lifted_66d973);

extern "C" u32 lifted_66d97e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d97e
  ecx = (ecx + (u32)(36));  // @1_66d97e
  eax = ext_42ba10_thiscall1(ecx);  // @2_66d97e
  ecx = edx = 0;  // @3_66d97e
  return eax;  // @4_66d97e
}
PCREG(66d97e, lifted_66d97e);

extern "C" u32 lifted_66d9b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d9b0
  ecx = (ecx + (u32)(1));  // @1_66d9b0
  eax = ext_5fad10_thiscall1(ecx);  // @2_66d9b0
  ecx = edx = 0;  // @3_66d9b0
  return eax;  // @4_66d9b0
}
PCREG(66d9b0, lifted_66d9b0);

extern "C" u32 lifted_66dc38(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dc38
  ecx = (ecx + (u32)(12));  // @1_66dc38
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66dc38
  ecx = edx = 0;  // @3_66dc38
  return eax;  // @4_66dc38
}
PCREG(66dc38, lifted_66dc38);

extern "C" u32 lifted_66dc68(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dc68
  ecx = (ecx + (u32)(12));  // @1_66dc68
  eax = ext_5f3af0_thiscall1(ecx);  // @2_66dc68
  ecx = edx = 0;  // @3_66dc68
  return eax;  // @4_66dc68
}
PCREG(66dc68, lifted_66dc68);

extern "C" u32 lifted_66df20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @0_66df20
  ecx = (ecx + (u32)(3));  // @1_66df20
  eax = ext_5a5440_thiscall1(ecx);  // @2_66df20
  ecx = edx = 0;  // @3_66df20
  return eax;  // @4_66df20
}
PCREG(66df20, lifted_66df20);

extern "C" u32 lifted_66df50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @0_66df50
  ecx = (ecx + (u32)(4));  // @1_66df50
  eax = ext_606ce0_thiscall1(ecx);  // @2_66df50
  ecx = edx = 0;  // @3_66df50
  return eax;  // @4_66df50
}
PCREG(66df50, lifted_66df50);

extern "C" u32 lifted_66df5b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @0_66df5b
  ecx = (ecx + (u32)(23));  // @1_66df5b
  eax = ext_5a5440_thiscall1(ecx);  // @2_66df5b
  ecx = edx = 0;  // @3_66df5b
  return eax;  // @4_66df5b
}
PCREG(66df5b, lifted_66df5b);

extern "C" u32 lifted_66df66(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @0_66df66
  ecx = (ecx + (u32)(35));  // @1_66df66
  eax = ext_606c90_thiscall1(ecx);  // @2_66df66
  ecx = edx = 0;  // @3_66df66
  return eax;  // @4_66df66
}
PCREG(66df66, lifted_66df66);

extern "C" u32 lifted_66dfc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dfc0
  ecx = (ecx + (u32)(20));  // @1_66dfc0
  eax = ext_42ba10_thiscall1(ecx);  // @2_66dfc0
  ecx = edx = 0;  // @3_66dfc0
  return eax;  // @4_66dfc0
}
PCREG(66dfc0, lifted_66dfc0);

extern "C" u32 lifted_66dfcb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dfcb
  ecx = (ecx + (u32)(32));  // @1_66dfcb
  eax = ext_42ba10_thiscall1(ecx);  // @2_66dfcb
  ecx = edx = 0;  // @3_66dfcb
  return eax;  // @4_66dfcb
}
PCREG(66dfcb, lifted_66dfcb);

extern "C" u32 lifted_66dfd6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dfd6
  ecx = (ecx + (u32)(44));  // @1_66dfd6
  eax = ext_42ba10_thiscall1(ecx);  // @2_66dfd6
  ecx = edx = 0;  // @3_66dfd6
  return eax;  // @4_66dfd6
}
PCREG(66dfd6, lifted_66dfd6);

extern "C" u32 lifted_66e780(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e780
  ecx = (ecx + (u32)(20));  // @1_66e780
  eax = ext_613940_thiscall1(ecx);  // @2_66e780
  ecx = edx = 0;  // @3_66e780
  return eax;  // @4_66e780
}
PCREG(66e780, lifted_66e780);

extern "C" u32 lifted_66e78b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e78b
  ecx = (ecx + (u32)(33392));  // @1_66e78b
  eax = ext_65e130_thiscall1(ecx);  // @2_66e78b
  ecx = edx = 0;  // @3_66e78b
  return eax;  // @4_66e78b
}
PCREG(66e78b, lifted_66e78b);

extern "C" u32 lifted_66e799(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66e799
  ecx = (ecx + (u32)(47428));  // @1_66e799
  eax = ext_613940_thiscall1(ecx);  // @2_66e799
  ecx = edx = 0;  // @3_66e799
  return eax;  // @4_66e799
}
PCREG(66e799, lifted_66e799);

extern "C" u32 lifted_66ea70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ea70
  ecx = (ecx + (u32)(4));  // @1_66ea70
  eax = ext_613940_thiscall1(ecx);  // @2_66ea70
  ecx = edx = 0;  // @3_66ea70
  return eax;  // @4_66ea70
}
PCREG(66ea70, lifted_66ea70);

extern "C" u32 lifted_66ea7b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ea7b
  ecx = (ecx + (u32)(65581));  // @1_66ea7b
  eax = ext_613940_thiscall1(ecx);  // @2_66ea7b
  ecx = edx = 0;  // @3_66ea7b
  return eax;  // @4_66ea7b
}
PCREG(66ea7b, lifted_66ea7b);

extern "C" u32 lifted_66ea89(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ea89
  ecx = (ecx + (u32)(98905));  // @1_66ea89
  eax = ext_613940_thiscall1(ecx);  // @2_66ea89
  ecx = edx = 0;  // @3_66ea89
  return eax;  // @4_66ea89
}
PCREG(66ea89, lifted_66ea89);

extern "C" u32 lifted_66ea97(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ea97
  ecx = (ecx + (u32)(98941));  // @1_66ea97
  eax = ext_613940_thiscall1(ecx);  // @2_66ea97
  ecx = edx = 0;  // @3_66ea97
  return eax;  // @4_66ea97
}
PCREG(66ea97, lifted_66ea97);

extern "C" u32 lifted_66eb60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66eb60
  ecx = (ecx + (u32)(148));  // @1_66eb60
  eax = ext_660cc0_thiscall1(ecx);  // @2_66eb60
  ecx = edx = 0;  // @3_66eb60
  return eax;  // @4_66eb60
}
PCREG(66eb60, lifted_66eb60);

extern "C" u32 lifted_66ec28(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66ec28
  ecx = (ecx + (u32)(64));  // @1_66ec28
  eax = ext_4cce40_thiscall1(ecx);  // @2_66ec28
  ecx = edx = 0;  // @3_66ec28
  return eax;  // @4_66ec28
}
PCREG(66ec28, lifted_66ec28);

extern "C" u32 lifted_666090(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666090
  eax = ext_45c510_cdecl1((u32)(eax));  // @1_666090
  ecx = edx = 0;  // @2_666090
  return eax;  // @3_666090
}
PCREG(666090, lifted_666090);

extern "C" u32 lifted_6661c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6661c0
  eax = ext_45c510_cdecl1((u32)(eax));  // @1_6661c0
  ecx = edx = 0;  // @2_6661c0
  return eax;  // @3_6661c0
}
PCREG(6661c0, lifted_6661c0);

extern "C" u32 lifted_666220(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666220
  eax = ext_45c510_cdecl1((u32)(eax));  // @1_666220
  ecx = edx = 0;  // @2_666220
  return eax;  // @3_666220
}
PCREG(666220, lifted_666220);

extern "C" u32 lifted_666261(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666261
  eax = ext_45c510_cdecl1((u32)(eax));  // @1_666261
  ecx = edx = 0;  // @2_666261
  return eax;  // @3_666261
}
PCREG(666261, lifted_666261);

extern "C" u32 lifted_666590(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666590
  eax = ext_45c510_cdecl1((u32)(eax));  // @1_666590
  ecx = edx = 0;  // @2_666590
  return eax;  // @3_666590
}
PCREG(666590, lifted_666590);

extern "C" u32 lifted_666cf1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666cf1
  eax = ext_45c510_cdecl1((u32)(eax));  // @1_666cf1
  ecx = edx = 0;  // @2_666cf1
  return eax;  // @3_666cf1
}
PCREG(666cf1, lifted_666cf1);

extern "C" u32 lifted_667440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_667440
  eax = ext_45c510_cdecl1((u32)(eax));  // @1_667440
  ecx = edx = 0;  // @2_667440
  return eax;  // @3_667440
}
PCREG(667440, lifted_667440);

