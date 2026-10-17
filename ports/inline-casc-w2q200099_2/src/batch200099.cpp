// batch200099.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_441bf0_thiscall1(u32) __asm__("ext_441bf0");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4ccef0_thiscall1(u32) __asm__("ext_4ccef0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d5640_thiscall1(u32) __asm__("ext_4d5640");
extern "C" u32 THISCALL ext_4f6b20_thiscall1(u32) __asm__("ext_4f6b20");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_663ed0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 796);  // @0_663ed0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_663ed0
  ecx = edx = 0;  // @2_663ed0
  return eax;  // @3_663ed0
}
PCREG(663ed0, lifted_663ed0);

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

extern "C" u32 lifted_664cc1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 784);  // @0_664cc1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_664cc1
  ecx = edx = 0;  // @2_664cc1
  return eax;  // @3_664cc1
}
PCREG(664cc1, lifted_664cc1);

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

extern "C" u32 lifted_665d51(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_665d51
  eax = ext_4cbec0_thiscall1(ecx);  // @1_665d51
  ecx = edx = 0;  // @2_665d51
  return eax;  // @3_665d51
}
PCREG(665d51, lifted_665d51);

extern "C" u32 lifted_665d5c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_665d5c
  eax = ext_4cbec0_thiscall1(ecx);  // @1_665d5c
  ecx = edx = 0;  // @2_665d5c
  return eax;  // @3_665d5c
}
PCREG(665d5c, lifted_665d5c);

extern "C" u32 lifted_665d67(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_665d67
  eax = ext_4cbec0_thiscall1(ecx);  // @1_665d67
  ecx = edx = 0;  // @2_665d67
  return eax;  // @3_665d67
}
PCREG(665d67, lifted_665d67);

extern "C" u32 lifted_665d72(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_665d72
  eax = ext_4cbec0_thiscall1(ecx);  // @1_665d72
  ecx = edx = 0;  // @2_665d72
  return eax;  // @3_665d72
}
PCREG(665d72, lifted_665d72);

extern "C" u32 lifted_665d7d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_665d7d
  eax = ext_4cbec0_thiscall1(ecx);  // @1_665d7d
  ecx = edx = 0;  // @2_665d7d
  return eax;  // @3_665d7d
}
PCREG(665d7d, lifted_665d7d);

extern "C" u32 lifted_665d93(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_665d93
  eax = ext_4cbec0_thiscall1(ecx);  // @1_665d93
  ecx = edx = 0;  // @2_665d93
  return eax;  // @3_665d93
}
PCREG(665d93, lifted_665d93);

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

extern "C" u32 lifted_665e70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_665e70
  eax = ext_4ccf60_thiscall1(ecx);  // @1_665e70
  ecx = edx = 0;  // @2_665e70
  return eax;  // @3_665e70
}
PCREG(665e70, lifted_665e70);

extern "C" u32 lifted_665ef0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 96);  // @0_665ef0
  eax = ext_441bf0_thiscall1(ecx);  // @1_665ef0
  ecx = edx = 0;  // @2_665ef0
  return eax;  // @3_665ef0
}
PCREG(665ef0, lifted_665ef0);

extern "C" u32 lifted_665f50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_665f50
  eax = ext_4ccf60_thiscall1(ecx);  // @1_665f50
  ecx = edx = 0;  // @2_665f50
  return eax;  // @3_665f50
}
PCREG(665f50, lifted_665f50);

extern "C" u32 lifted_6660c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_6660c0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6660c0
  ecx = edx = 0;  // @2_6660c0
  return eax;  // @3_6660c0
}
PCREG(6660c0, lifted_6660c0);

extern "C" u32 lifted_666290(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 532);  // @0_666290
  eax = ext_4ccf60_thiscall1(ecx);  // @1_666290
  ecx = edx = 0;  // @2_666290
  return eax;  // @3_666290
}
PCREG(666290, lifted_666290);

extern "C" u32 lifted_66629b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 360);  // @0_66629b
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66629b
  ecx = edx = 0;  // @2_66629b
  return eax;  // @3_66629b
}
PCREG(66629b, lifted_66629b);

extern "C" u32 lifted_6662a6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_6662a6
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6662a6
  ecx = edx = 0;  // @2_6662a6
  return eax;  // @3_6662a6
}
PCREG(6662a6, lifted_6662a6);

extern "C" u32 lifted_6662e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 96);  // @0_6662e0
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_6662e0
  ecx = edx = 0;  // @2_6662e0
  return eax;  // @3_6662e0
}
PCREG(6662e0, lifted_6662e0);

extern "C" u32 lifted_666310(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 156);  // @0_666310
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666310
  ecx = edx = 0;  // @2_666310
  return eax;  // @3_666310
}
PCREG(666310, lifted_666310);

extern "C" u32 lifted_66631b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 284);  // @0_66631b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66631b
  ecx = edx = 0;  // @2_66631b
  return eax;  // @3_66631b
}
PCREG(66631b, lifted_66631b);

extern "C" u32 lifted_666350(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 536);  // @0_666350
  eax = ext_4ccf60_thiscall1(ecx);  // @1_666350
  ecx = edx = 0;  // @2_666350
  return eax;  // @3_666350
}
PCREG(666350, lifted_666350);

extern "C" u32 lifted_666390(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 536);  // @0_666390
  eax = ext_4ccf60_thiscall1(ecx);  // @1_666390
  ecx = edx = 0;  // @2_666390
  return eax;  // @3_666390
}
PCREG(666390, lifted_666390);

extern "C" u32 lifted_666440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 160);  // @0_666440
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666440
  ecx = edx = 0;  // @2_666440
  return eax;  // @3_666440
}
PCREG(666440, lifted_666440);

extern "C" u32 lifted_66644b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 288);  // @0_66644b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66644b
  ecx = edx = 0;  // @2_66644b
  return eax;  // @3_66644b
}
PCREG(66644b, lifted_66644b);

extern "C" u32 lifted_666456(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 288);  // @0_666456
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666456
  ecx = edx = 0;  // @2_666456
  return eax;  // @3_666456
}
PCREG(666456, lifted_666456);

extern "C" u32 lifted_6664c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 228);  // @0_6664c0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6664c0
  ecx = edx = 0;  // @2_6664c0
  return eax;  // @3_6664c0
}
PCREG(6664c0, lifted_6664c0);

extern "C" u32 lifted_666650(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666650
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666650
  ecx = edx = 0;  // @2_666650
  return eax;  // @3_666650
}
PCREG(666650, lifted_666650);

extern "C" u32 lifted_66665b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66665b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66665b
  ecx = edx = 0;  // @2_66665b
  return eax;  // @3_66665b
}
PCREG(66665b, lifted_66665b);

extern "C" u32 lifted_666690(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666690
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666690
  ecx = edx = 0;  // @2_666690
  return eax;  // @3_666690
}
PCREG(666690, lifted_666690);

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

extern "C" u32 lifted_6666a6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6666a6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6666a6
  ecx = edx = 0;  // @2_6666a6
  return eax;  // @3_6666a6
}
PCREG(6666a6, lifted_6666a6);

extern "C" u32 lifted_6666b1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6666b1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6666b1
  ecx = edx = 0;  // @2_6666b1
  return eax;  // @3_6666b1
}
PCREG(6666b1, lifted_6666b1);

extern "C" u32 lifted_6666f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 444);  // @0_6666f0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6666f0
  ecx = edx = 0;  // @2_6666f0
  return eax;  // @3_6666f0
}
PCREG(6666f0, lifted_6666f0);

extern "C" u32 lifted_66671d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66671d
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66671d
  ecx = edx = 0;  // @2_66671d
  return eax;  // @3_66671d
}
PCREG(66671d, lifted_66671d);

extern "C" u32 lifted_666728(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666728
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666728
  ecx = edx = 0;  // @2_666728
  return eax;  // @3_666728
}
PCREG(666728, lifted_666728);

extern "C" u32 lifted_6667d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6667d0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6667d0
  ecx = edx = 0;  // @2_6667d0
  return eax;  // @3_6667d0
}
PCREG(6667d0, lifted_6667d0);

extern "C" u32 lifted_6667db(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 316);  // @0_6667db
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6667db
  ecx = edx = 0;  // @2_6667db
  return eax;  // @3_6667db
}
PCREG(6667db, lifted_6667db);

extern "C" u32 lifted_666810(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_666810
  eax = ext_4ccf60_thiscall1(ecx);  // @1_666810
  ecx = edx = 0;  // @2_666810
  return eax;  // @3_666810
}
PCREG(666810, lifted_666810);

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

extern "C" u32 lifted_66685b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 528);  // @0_66685b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66685b
  ecx = edx = 0;  // @2_66685b
  return eax;  // @3_66685b
}
PCREG(66685b, lifted_66685b);

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

extern "C" u32 lifted_666970(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666970
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666970
  ecx = edx = 0;  // @2_666970
  return eax;  // @3_666970
}
PCREG(666970, lifted_666970);

extern "C" u32 lifted_666a10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666a10
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666a10
  ecx = edx = 0;  // @2_666a10
  return eax;  // @3_666a10
}
PCREG(666a10, lifted_666a10);

extern "C" u32 lifted_666d20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666d20
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666d20
  ecx = edx = 0;  // @2_666d20
  return eax;  // @3_666d20
}
PCREG(666d20, lifted_666d20);

extern "C" u32 lifted_666d2b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_666d2b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666d2b
  ecx = edx = 0;  // @2_666d2b
  return eax;  // @3_666d2b
}
PCREG(666d2b, lifted_666d2b);

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

extern "C" u32 lifted_666d82(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_666d82
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666d82
  ecx = edx = 0;  // @2_666d82
  return eax;  // @3_666d82
}
PCREG(666d82, lifted_666d82);

extern "C" u32 lifted_666d8d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666d8d
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666d8d
  ecx = edx = 0;  // @2_666d8d
  return eax;  // @3_666d8d
}
PCREG(666d8d, lifted_666d8d);

extern "C" u32 lifted_666dcb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666dcb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666dcb
  ecx = edx = 0;  // @2_666dcb
  return eax;  // @3_666dcb
}
PCREG(666dcb, lifted_666dcb);

extern "C" u32 lifted_666dd6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_666dd6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666dd6
  ecx = edx = 0;  // @2_666dd6
  return eax;  // @3_666dd6
}
PCREG(666dd6, lifted_666dd6);

extern "C" u32 lifted_666e10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666e10
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666e10
  ecx = edx = 0;  // @2_666e10
  return eax;  // @3_666e10
}
PCREG(666e10, lifted_666e10);

extern "C" u32 lifted_666e60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 320);  // @0_666e60
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666e60
  ecx = edx = 0;  // @2_666e60
  return eax;  // @3_666e60
}
PCREG(666e60, lifted_666e60);

extern "C" u32 lifted_666e6b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 192);  // @0_666e6b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666e6b
  ecx = edx = 0;  // @2_666e6b
  return eax;  // @3_666e6b
}
PCREG(666e6b, lifted_666e6b);

extern "C" u32 lifted_666ea0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_666ea0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666ea0
  ecx = edx = 0;  // @2_666ea0
  return eax;  // @3_666ea0
}
PCREG(666ea0, lifted_666ea0);

extern "C" u32 lifted_666eab(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_666eab
  eax = ext_4cbec0_thiscall1(ecx);  // @1_666eab
  ecx = edx = 0;  // @2_666eab
  return eax;  // @3_666eab
}
PCREG(666eab, lifted_666eab);

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

extern "C" u32 lifted_66709b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_66709b
  eax = ext_4ccf60_thiscall1(ecx);  // @1_66709b
  ecx = edx = 0;  // @2_66709b
  return eax;  // @3_66709b
}
PCREG(66709b, lifted_66709b);

extern "C" u32 lifted_667130(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_667130
  eax = ext_4ccf60_thiscall1(ecx);  // @1_667130
  ecx = edx = 0;  // @2_667130
  return eax;  // @3_667130
}
PCREG(667130, lifted_667130);

extern "C" u32 lifted_6671e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_6671e0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6671e0
  ecx = edx = 0;  // @2_6671e0
  return eax;  // @3_6671e0
}
PCREG(6671e0, lifted_6671e0);

extern "C" u32 lifted_667290(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 296);  // @0_667290
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667290
  ecx = edx = 0;  // @2_667290
  return eax;  // @3_667290
}
PCREG(667290, lifted_667290);

extern "C" u32 lifted_66729b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_66729b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66729b
  ecx = edx = 0;  // @2_66729b
  return eax;  // @3_66729b
}
PCREG(66729b, lifted_66729b);

extern "C" u32 lifted_6672a6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_6672a6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672a6
  ecx = edx = 0;  // @2_6672a6
  return eax;  // @3_6672a6
}
PCREG(6672a6, lifted_6672a6);

extern "C" u32 lifted_6672b1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_6672b1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672b1
  ecx = edx = 0;  // @2_6672b1
  return eax;  // @3_6672b1
}
PCREG(6672b1, lifted_6672b1);

extern "C" u32 lifted_6672bc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_6672bc
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672bc
  ecx = edx = 0;  // @2_6672bc
  return eax;  // @3_6672bc
}
PCREG(6672bc, lifted_6672bc);

extern "C" u32 lifted_6672d2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_6672d2
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672d2
  ecx = edx = 0;  // @2_6672d2
  return eax;  // @3_6672d2
}
PCREG(6672d2, lifted_6672d2);

extern "C" u32 lifted_6672dd(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_6672dd
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672dd
  ecx = edx = 0;  // @2_6672dd
  return eax;  // @3_6672dd
}
PCREG(6672dd, lifted_6672dd);

extern "C" u32 lifted_6672e8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_6672e8
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672e8
  ecx = edx = 0;  // @2_6672e8
  return eax;  // @3_6672e8
}
PCREG(6672e8, lifted_6672e8);

extern "C" u32 lifted_6672f3(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 168);  // @0_6672f3
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6672f3
  ecx = edx = 0;  // @2_6672f3
  return eax;  // @3_6672f3
}
PCREG(6672f3, lifted_6672f3);

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

extern "C" u32 lifted_6675e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 104);  // @0_6675e0
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_6675e0
  ecx = edx = 0;  // @2_6675e0
  return eax;  // @3_6675e0
}
PCREG(6675e0, lifted_6675e0);

extern "C" u32 lifted_667711(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667711
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667711
  ecx = edx = 0;  // @2_667711
  return eax;  // @3_667711
}
PCREG(667711, lifted_667711);

extern "C" u32 lifted_667990(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 528);  // @0_667990
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667990
  ecx = edx = 0;  // @2_667990
  return eax;  // @3_667990
}
PCREG(667990, lifted_667990);

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

extern "C" u32 lifted_6679b1(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6679b1
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6679b1
  ecx = edx = 0;  // @2_6679b1
  return eax;  // @3_6679b1
}
PCREG(6679b1, lifted_6679b1);

extern "C" u32 lifted_6679bc(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 528);  // @0_6679bc
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6679bc
  ecx = edx = 0;  // @2_6679bc
  return eax;  // @3_6679bc
}
PCREG(6679bc, lifted_6679bc);

extern "C" u32 lifted_6679c7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6679c7
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6679c7
  ecx = edx = 0;  // @2_6679c7
  return eax;  // @3_6679c7
}
PCREG(6679c7, lifted_6679c7);

extern "C" u32 lifted_6679d2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6679d2
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6679d2
  ecx = edx = 0;  // @2_6679d2
  return eax;  // @3_6679d2
}
PCREG(6679d2, lifted_6679d2);

extern "C" u32 lifted_6679dd(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 700);  // @0_6679dd
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6679dd
  ecx = edx = 0;  // @2_6679dd
  return eax;  // @3_6679dd
}
PCREG(6679dd, lifted_6679dd);

extern "C" u32 lifted_667a30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 60);  // @0_667a30
  eax = ext_4ccef0_thiscall1(ecx);  // @1_667a30
  ecx = edx = 0;  // @2_667a30
  return eax;  // @3_667a30
}
PCREG(667a30, lifted_667a30);

extern "C" u32 lifted_667a60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667a60
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667a60
  ecx = edx = 0;  // @2_667a60
  return eax;  // @3_667a60
}
PCREG(667a60, lifted_667a60);

extern "C" u32 lifted_667a6b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_667a6b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667a6b
  ecx = edx = 0;  // @2_667a6b
  return eax;  // @3_667a6b
}
PCREG(667a6b, lifted_667a6b);

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

extern "C" u32 lifted_667a81(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_667a81
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667a81
  ecx = edx = 0;  // @2_667a81
  return eax;  // @3_667a81
}
PCREG(667a81, lifted_667a81);

extern "C" u32 lifted_667ae2(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 172);  // @0_667ae2
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667ae2
  ecx = edx = 0;  // @2_667ae2
  return eax;  // @3_667ae2
}
PCREG(667ae2, lifted_667ae2);

extern "C" u32 lifted_667aed(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 172);  // @0_667aed
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667aed
  ecx = edx = 0;  // @2_667aed
  return eax;  // @3_667aed
}
PCREG(667aed, lifted_667aed);

extern "C" u32 lifted_667b20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667b20
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b20
  ecx = edx = 0;  // @2_667b20
  return eax;  // @3_667b20
}
PCREG(667b20, lifted_667b20);

extern "C" u32 lifted_667b2b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_667b2b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b2b
  ecx = edx = 0;  // @2_667b2b
  return eax;  // @3_667b2b
}
PCREG(667b2b, lifted_667b2b);

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

extern "C" u32 lifted_667b4c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 528);  // @0_667b4c
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b4c
  ecx = edx = 0;  // @2_667b4c
  return eax;  // @3_667b4c
}
PCREG(667b4c, lifted_667b4c);

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

extern "C" u32 lifted_667b62(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 528);  // @0_667b62
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b62
  ecx = edx = 0;  // @2_667b62
  return eax;  // @3_667b62
}
PCREG(667b62, lifted_667b62);

extern "C" u32 lifted_667b6d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 784);  // @0_667b6d
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b6d
  ecx = edx = 0;  // @2_667b6d
  return eax;  // @3_667b6d
}
PCREG(667b6d, lifted_667b6d);

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

extern "C" u32 lifted_667b83(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 784);  // @0_667b83
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b83
  ecx = edx = 0;  // @2_667b83
  return eax;  // @3_667b83
}
PCREG(667b83, lifted_667b83);

extern "C" u32 lifted_667b8e(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 528);  // @0_667b8e
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b8e
  ecx = edx = 0;  // @2_667b8e
  return eax;  // @3_667b8e
}
PCREG(667b8e, lifted_667b8e);

extern "C" u32 lifted_667b99(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 912);  // @0_667b99
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667b99
  ecx = edx = 0;  // @2_667b99
  return eax;  // @3_667b99
}
PCREG(667b99, lifted_667b99);

extern "C" u32 lifted_667ba4(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 784);  // @0_667ba4
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667ba4
  ecx = edx = 0;  // @2_667ba4
  return eax;  // @3_667ba4
}
PCREG(667ba4, lifted_667ba4);

extern "C" u32 lifted_667baf(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 912);  // @0_667baf
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667baf
  ecx = edx = 0;  // @2_667baf
  return eax;  // @3_667baf
}
PCREG(667baf, lifted_667baf);

extern "C" u32 lifted_667bba(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 1040);  // @0_667bba
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667bba
  ecx = edx = 0;  // @2_667bba
  return eax;  // @3_667bba
}
PCREG(667bba, lifted_667bba);

extern "C" u32 lifted_667bc5(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 656);  // @0_667bc5
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667bc5
  ecx = edx = 0;  // @2_667bc5
  return eax;  // @3_667bc5
}
PCREG(667bc5, lifted_667bc5);

extern "C" u32 lifted_667c50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 1168);  // @0_667c50
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667c50
  ecx = edx = 0;  // @2_667c50
  return eax;  // @3_667c50
}
PCREG(667c50, lifted_667c50);

extern "C" u32 lifted_667c90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_667c90
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667c90
  ecx = edx = 0;  // @2_667c90
  return eax;  // @3_667c90
}
PCREG(667c90, lifted_667c90);

extern "C" u32 lifted_667c9b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667c9b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667c9b
  ecx = edx = 0;  // @2_667c9b
  return eax;  // @3_667c9b
}
PCREG(667c9b, lifted_667c9b);

extern "C" u32 lifted_667ca6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667ca6
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667ca6
  ecx = edx = 0;  // @2_667ca6
  return eax;  // @3_667ca6
}
PCREG(667ca6, lifted_667ca6);

extern "C" u32 lifted_667ce0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 60);  // @0_667ce0
  eax = ext_4cd0e0_thiscall1(ecx);  // @1_667ce0
  ecx = edx = 0;  // @2_667ce0
  return eax;  // @3_667ce0
}
PCREG(667ce0, lifted_667ce0);

extern "C" u32 lifted_667d10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 564);  // @0_667d10
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_667d10
  ecx = edx = 0;  // @2_667d10
  return eax;  // @3_667d10
}
PCREG(667d10, lifted_667d10);

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

extern "C" u32 lifted_667d90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 332);  // @0_667d90
  eax = ext_499970_thiscall1(ecx);  // @1_667d90
  ecx = edx = 0;  // @2_667d90
  return eax;  // @3_667d90
}
PCREG(667d90, lifted_667d90);

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

extern "C" u32 lifted_667edd(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667edd
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667edd
  ecx = edx = 0;  // @2_667edd
  return eax;  // @3_667edd
}
PCREG(667edd, lifted_667edd);

extern "C" u32 lifted_667f10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667f10
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667f10
  ecx = edx = 0;  // @2_667f10
  return eax;  // @3_667f10
}
PCREG(667f10, lifted_667f10);

extern "C" u32 lifted_667f1b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_667f1b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667f1b
  ecx = edx = 0;  // @2_667f1b
  return eax;  // @3_667f1b
}
PCREG(667f1b, lifted_667f1b);

extern "C" u32 lifted_667f26(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 588);  // @0_667f26
  eax = ext_499980_thiscall1(ecx);  // @1_667f26
  ecx = edx = 0;  // @2_667f26
  return eax;  // @3_667f26
}
PCREG(667f26, lifted_667f26);

extern "C" u32 lifted_667f31(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 588);  // @0_667f31
  eax = ext_499980_thiscall1(ecx);  // @1_667f31
  ecx = edx = 0;  // @2_667f31
  return eax;  // @3_667f31
}
PCREG(667f31, lifted_667f31);

extern "C" u32 lifted_667f3c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 588);  // @0_667f3c
  eax = ext_499980_thiscall1(ecx);  // @1_667f3c
  ecx = edx = 0;  // @2_667f3c
  return eax;  // @3_667f3c
}
PCREG(667f3c, lifted_667f3c);

extern "C" u32 lifted_667f70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 148);  // @0_667f70
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667f70
  ecx = edx = 0;  // @2_667f70
  return eax;  // @3_667f70
}
PCREG(667f70, lifted_667f70);

extern "C" u32 lifted_667fb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_667fb0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667fb0
  ecx = edx = 0;  // @2_667fb0
  return eax;  // @3_667fb0
}
PCREG(667fb0, lifted_667fb0);

extern "C" u32 lifted_667fbb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_667fbb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_667fbb
  ecx = edx = 0;  // @2_667fbb
  return eax;  // @3_667fbb
}
PCREG(667fbb, lifted_667fbb);

extern "C" u32 lifted_6680f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 72);  // @0_6680f0
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_6680f0
  ecx = edx = 0;  // @2_6680f0
  return eax;  // @3_6680f0
}
PCREG(6680f0, lifted_6680f0);

extern "C" u32 lifted_668120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 84);  // @0_668120
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_668120
  ecx = edx = 0;  // @2_668120
  return eax;  // @3_668120
}
PCREG(668120, lifted_668120);

extern "C" u32 lifted_668150(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 80);  // @0_668150
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_668150
  ecx = edx = 0;  // @2_668150
  return eax;  // @3_668150
}
PCREG(668150, lifted_668150);

extern "C" u32 lifted_6681b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 188);  // @0_6681b0
  eax = ext_4ccf60_thiscall1(ecx);  // @1_6681b0
  ecx = edx = 0;  // @2_6681b0
  return eax;  // @3_6681b0
}
PCREG(6681b0, lifted_6681b0);

extern "C" u32 lifted_668220(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 72);  // @0_668220
  eax = ext_4ccef0_thiscall1(ecx);  // @1_668220
  ecx = edx = 0;  // @2_668220
  return eax;  // @3_668220
}
PCREG(668220, lifted_668220);

extern "C" u32 lifted_6682b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 36);  // @0_6682b0
  eax = ext_4d5640_thiscall1(ecx);  // @1_6682b0
  ecx = edx = 0;  // @2_6682b0
  return eax;  // @3_6682b0
}
PCREG(6682b0, lifted_6682b0);

extern "C" u32 lifted_6682e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 116);  // @0_6682e0
  eax = ext_4d5640_thiscall1(ecx);  // @1_6682e0
  ecx = edx = 0;  // @2_6682e0
  return eax;  // @3_6682e0
}
PCREG(6682e0, lifted_6682e0);

extern "C" u32 lifted_668380(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 328);  // @0_668380
  eax = ext_4ccfe0_thiscall1(ecx);  // @1_668380
  ecx = edx = 0;  // @2_668380
  return eax;  // @3_668380
}
PCREG(668380, lifted_668380);

extern "C" u32 lifted_66838b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 276);  // @0_66838b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66838b
  ecx = edx = 0;  // @2_66838b
  return eax;  // @3_66838b
}
PCREG(66838b, lifted_66838b);

extern "C" u32 lifted_6683f6(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 308);  // @0_6683f6
  eax = ext_4f6b20_thiscall1(ecx);  // @1_6683f6
  ecx = edx = 0;  // @2_6683f6
  return eax;  // @3_6683f6
}
PCREG(6683f6, lifted_6683f6);

extern "C" u32 lifted_66840d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 644);  // @0_66840d
  eax = ext_4f6b20_thiscall1(ecx);  // @1_66840d
  ecx = edx = 0;  // @2_66840d
  return eax;  // @3_66840d
}
PCREG(66840d, lifted_66840d);

extern "C" u32 lifted_668418(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 534);  // @0_668418
  eax = ext_4ccf60_thiscall1(ecx);  // @1_668418
  ecx = edx = 0;  // @2_668418
  return eax;  // @3_668418
}
PCREG(668418, lifted_668418);

extern "C" u32 lifted_668423(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 362);  // @0_668423
  eax = ext_4ccf60_thiscall1(ecx);  // @1_668423
  ecx = edx = 0;  // @2_668423
  return eax;  // @3_668423
}
PCREG(668423, lifted_668423);

extern "C" u32 lifted_66844c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 436);  // @0_66844c
  eax = ext_4f6b20_thiscall1(ecx);  // @1_66844c
  ecx = edx = 0;  // @2_66844c
  return eax;  // @3_66844c
}
PCREG(66844c, lifted_66844c);

extern "C" u32 lifted_668457(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 364);  // @0_668457
  eax = ext_4ccf60_thiscall1(ecx);  // @1_668457
  ecx = edx = 0;  // @2_668457
  return eax;  // @3_668457
}
PCREG(668457, lifted_668457);

extern "C" u32 lifted_668468(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 320);  // @0_668468
  eax = ext_4f6b20_thiscall1(ecx);  // @1_668468
  ecx = edx = 0;  // @2_668468
  return eax;  // @3_668468
}
PCREG(668468, lifted_668468);

extern "C" u32 lifted_6685b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6685b0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6685b0
  ecx = edx = 0;  // @2_6685b0
  return eax;  // @3_6685b0
}
PCREG(6685b0, lifted_6685b0);

extern "C" u32 lifted_668690(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_668690
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668690
  ecx = edx = 0;  // @2_668690
  return eax;  // @3_668690
}
PCREG(668690, lifted_668690);

extern "C" u32 lifted_66869b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_66869b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66869b
  ecx = edx = 0;  // @2_66869b
  return eax;  // @3_66869b
}
PCREG(66869b, lifted_66869b);

extern "C" u32 lifted_6686d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6686d0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6686d0
  ecx = edx = 0;  // @2_6686d0
  return eax;  // @3_6686d0
}
PCREG(6686d0, lifted_6686d0);

extern "C" u32 lifted_6686db(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6686db
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6686db
  ecx = edx = 0;  // @2_6686db
  return eax;  // @3_6686db
}
PCREG(6686db, lifted_6686db);

extern "C" u32 lifted_668760(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668760
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668760
  ecx = edx = 0;  // @2_668760
  return eax;  // @3_668760
}
PCREG(668760, lifted_668760);

extern "C" u32 lifted_66876b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_66876b
  eax = ext_4cbec0_thiscall1(ecx);  // @1_66876b
  ecx = edx = 0;  // @2_66876b
  return eax;  // @3_66876b
}
PCREG(66876b, lifted_66876b);

extern "C" u32 lifted_668776(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668776
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668776
  ecx = edx = 0;  // @2_668776
  return eax;  // @3_668776
}
PCREG(668776, lifted_668776);

extern "C" u32 lifted_6687b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6687b0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6687b0
  ecx = edx = 0;  // @2_6687b0
  return eax;  // @3_6687b0
}
PCREG(6687b0, lifted_6687b0);

extern "C" u32 lifted_6687bb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6687bb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6687bb
  ecx = edx = 0;  // @2_6687bb
  return eax;  // @3_6687bb
}
PCREG(6687bb, lifted_6687bb);

extern "C" u32 lifted_6687f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_6687f0
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6687f0
  ecx = edx = 0;  // @2_6687f0
  return eax;  // @3_6687f0
}
PCREG(6687f0, lifted_6687f0);

extern "C" u32 lifted_6687fb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_6687fb
  eax = ext_4cbec0_thiscall1(ecx);  // @1_6687fb
  ecx = edx = 0;  // @2_6687fb
  return eax;  // @3_6687fb
}
PCREG(6687fb, lifted_6687fb);

extern "C" u32 lifted_668830(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 144);  // @0_668830
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668830
  ecx = edx = 0;  // @2_668830
  return eax;  // @3_668830
}
PCREG(668830, lifted_668830);

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

extern "C" u32 lifted_668846(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 272);  // @0_668846
  eax = ext_4cbec0_thiscall1(ecx);  // @1_668846
  ecx = edx = 0;  // @2_668846
  return eax;  // @3_668846
}
PCREG(668846, lifted_668846);

