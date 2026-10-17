// batch200104.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_42ba10_thiscall1(u32) __asm__("ext_42ba10");
extern "C" u32 THISCALL ext_431870_thiscall1(u32) __asm__("ext_431870");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d5640_thiscall1(u32) __asm__("ext_4d5640");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_6646a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 102804);  // @0_6646a0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6646a0
  ecx = edx = 0;  // @2_6646a0
  return eax;  // @3_6646a0
}
PCREG(6646a0, lifted_6646a0);

extern "C" u32 lifted_6646ab(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 102932);  // @0_6646ab
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6646ab
  ecx = edx = 0;  // @2_6646ab
  return eax;  // @3_6646ab
}
PCREG(6646ab, lifted_6646ab);

extern "C" u32 lifted_6646b6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 103060);  // @0_6646b6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6646b6
  ecx = edx = 0;  // @2_6646b6
  return eax;  // @3_6646b6
}
PCREG(6646b6, lifted_6646b6);

extern "C" u32 lifted_6646c1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 102932);  // @0_6646c1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6646c1
  ecx = edx = 0;  // @2_6646c1
  return eax;  // @3_6646c1
}
PCREG(6646c1, lifted_6646c1);

extern "C" u32 lifted_6646cc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 103316);  // @0_6646cc
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6646cc
  ecx = edx = 0;  // @2_6646cc
  return eax;  // @3_6646cc
}
PCREG(6646cc, lifted_6646cc);

extern "C" u32 lifted_6646d7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 103188);  // @0_6646d7
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6646d7
  ecx = edx = 0;  // @2_6646d7
  return eax;  // @3_6646d7
}
PCREG(6646d7, lifted_6646d7);

extern "C" u32 lifted_6646e2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 103060);  // @0_6646e2
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6646e2
  ecx = edx = 0;  // @2_6646e2
  return eax;  // @3_6646e2
}
PCREG(6646e2, lifted_6646e2);

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

extern "C" u32 lifted_6650e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16272);  // @0_6650e0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6650e0
  ecx = edx = 0;  // @2_6650e0
  return eax;  // @3_6650e0
}
PCREG(6650e0, lifted_6650e0);

extern "C" u32 lifted_6650eb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16144);  // @0_6650eb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6650eb
  ecx = edx = 0;  // @2_6650eb
  return eax;  // @3_6650eb
}
PCREG(6650eb, lifted_6650eb);

extern "C" u32 lifted_6650f6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16304);  // @0_6650f6
  eax = ext_42ba10_thiscall1(ecx);  // @1_6650f6
  ecx = edx = 0;  // @2_6650f6
  return eax;  // @3_6650f6
}
PCREG(6650f6, lifted_6650f6);

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

extern "C" u32 lifted_6668f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16596);  // @0_6668f0
  eax = ext_4d2330_thiscall1(ecx);  // @1_6668f0
  ecx = edx = 0;  // @2_6668f0
  return eax;  // @3_6668f0
}
PCREG(6668f0, lifted_6668f0);

extern "C" u32 lifted_666930(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16596);  // @0_666930
  eax = ext_4d2330_thiscall1(ecx);  // @1_666930
  ecx = edx = 0;  // @2_666930
  return eax;  // @3_666930
}
PCREG(666930, lifted_666930);

extern "C" u32 lifted_666d36(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16852);  // @0_666d36
  eax = ext_4d2330_thiscall1(ecx);  // @1_666d36
  ecx = edx = 0;  // @2_666d36
  return eax;  // @3_666d36
}
PCREG(666d36, lifted_666d36);

extern "C" u32 lifted_666ee0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16596);  // @0_666ee0
  eax = ext_4d2330_thiscall1(ecx);  // @1_666ee0
  ecx = edx = 0;  // @2_666ee0
  return eax;  // @3_666ee0
}
PCREG(666ee0, lifted_666ee0);

extern "C" u32 lifted_667050(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16596);  // @0_667050
  eax = ext_4d2330_thiscall1(ecx);  // @1_667050
  ecx = edx = 0;  // @2_667050
  return eax;  // @3_667050
}
PCREG(667050, lifted_667050);

extern "C" u32 lifted_667090(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 16768);  // @0_667090
  eax = ext_4d2330_thiscall1(ecx);  // @1_667090
  ecx = edx = 0;  // @2_667090
  return eax;  // @3_667090
}
PCREG(667090, lifted_667090);

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

extern "C" u32 lifted_667560(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 51592);  // @0_667560
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667560
  ecx = edx = 0;  // @2_667560
  return eax;  // @3_667560
}
PCREG(667560, lifted_667560);

extern "C" u32 lifted_6675a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 8476);  // @0_6675a0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6675a0
  ecx = edx = 0;  // @2_6675a0
  return eax;  // @3_6675a0
}
PCREG(6675a0, lifted_6675a0);

extern "C" u32 lifted_66799b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 8760);  // @0_66799b
  eax = ext_4d5640_thiscall1(ecx);  // @1_66799b
  ecx = edx = 0;  // @2_66799b
  return eax;  // @3_66799b
}
PCREG(66799b, lifted_66799b);

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

extern "C" u32 lifted_667d50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 30332);  // @0_667d50
  eax = ext_499970_thiscall1(ecx);  // @1_667d50
  ecx = edx = 0;  // @2_667d50
  return eax;  // @3_667d50
}
PCREG(667d50, lifted_667d50);

extern "C" u32 lifted_667dd0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 30332);  // @0_667dd0
  eax = ext_499970_thiscall1(ecx);  // @1_667dd0
  ecx = edx = 0;  // @2_667dd0
  return eax;  // @3_667dd0
}
PCREG(667dd0, lifted_667dd0);

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

