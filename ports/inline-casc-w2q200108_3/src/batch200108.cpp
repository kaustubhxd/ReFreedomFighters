// batch200108.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_476540_cdecl2(...) __asm__("ext_476540");
extern "C" u32 ext_48aa80_cdecl2(...) __asm__("ext_48aa80");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_665e10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665e10
  p0_ = eax;  // @1_665e10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_665e10
  p1_ = eax;  // @3_665e10
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_665e10
  ecx = edx = 0;  // @5_665e10
  return eax;  // @6_665e10
}
PCREG(665e10, lifted_665e10);

extern "C" u32 lifted_666150(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_666150
  p0_ = eax;  // @1_666150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_666150
  p1_ = eax;  // @3_666150
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_666150
  ecx = edx = 0;  // @5_666150
  return eax;  // @6_666150
}
PCREG(666150, lifted_666150);

extern "C" u32 lifted_666250(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666250
  p0_ = eax;  // @1_666250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @2_666250
  p1_ = eax;  // @3_666250
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_666250
  ecx = edx = 0;  // @5_666250
  return eax;  // @6_666250
}
PCREG(666250, lifted_666250);

extern "C" u32 lifted_666520(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_666520
  p0_ = eax;  // @1_666520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_666520
  p1_ = eax;  // @3_666520
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_666520
  ecx = edx = 0;  // @5_666520
  return eax;  // @6_666520
}
PCREG(666520, lifted_666520);

extern "C" u32 lifted_666ce0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_666ce0
  p0_ = eax;  // @1_666ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @2_666ce0
  p1_ = eax;  // @3_666ce0
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_666ce0
  ecx = edx = 0;  // @5_666ce0
  return eax;  // @6_666ce0
}
PCREG(666ce0, lifted_666ce0);

extern "C" u32 lifted_6670d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6670d0
  p0_ = eax;  // @1_6670d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_6670d0
  p1_ = eax;  // @3_6670d0
  eax = ext_476540_cdecl2((u32)(p1_), (u32)(p0_));  // @4_6670d0
  ecx = edx = 0;  // @5_6670d0
  return eax;  // @6_6670d0
}
PCREG(6670d0, lifted_6670d0);

extern "C" u32 lifted_667340(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_667340
  p0_ = eax;  // @1_667340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_667340
  p1_ = eax;  // @3_667340
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_667340
  ecx = edx = 0;  // @5_667340
  return eax;  // @6_667340
}
PCREG(667340, lifted_667340);

extern "C" u32 lifted_668570(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668570
  p0_ = eax;  // @1_668570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_668570
  p1_ = eax;  // @3_668570
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_668570
  ecx = edx = 0;  // @5_668570
  return eax;  // @6_668570
}
PCREG(668570, lifted_668570);

extern "C" u32 lifted_668710(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668710
  p0_ = eax;  // @1_668710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_668710
  p1_ = eax;  // @3_668710
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_668710
  ecx = edx = 0;  // @5_668710
  return eax;  // @6_668710
}
PCREG(668710, lifted_668710);

extern "C" u32 lifted_668a70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668a70
  p0_ = eax;  // @1_668a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_668a70
  p1_ = eax;  // @3_668a70
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_668a70
  ecx = edx = 0;  // @5_668a70
  return eax;  // @6_668a70
}
PCREG(668a70, lifted_668a70);

extern "C" u32 lifted_668cc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668cc0
  p0_ = eax;  // @1_668cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_668cc0
  p1_ = eax;  // @3_668cc0
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_668cc0
  ecx = edx = 0;  // @5_668cc0
  return eax;  // @6_668cc0
}
PCREG(668cc0, lifted_668cc0);

extern "C" u32 lifted_668d70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_668d70
  p0_ = eax;  // @1_668d70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_668d70
  p1_ = eax;  // @3_668d70
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_668d70
  ecx = edx = 0;  // @5_668d70
  return eax;  // @6_668d70
}
PCREG(668d70, lifted_668d70);

extern "C" u32 lifted_66c820(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66c820
  p0_ = eax;  // @1_66c820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_66c820
  p1_ = eax;  // @3_66c820
  eax = ext_48aa80_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66c820
  ecx = edx = 0;  // @5_66c820
  return eax;  // @6_66c820
}
PCREG(66c820, lifted_66c820);

extern "C" u32 lifted_66507c(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @0_66507c
  p0_ = eax;  // @1_66507c
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @2_66507c
  p1_ = eax;  // @3_66507c
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66507c
  ecx = edx = 0;  // @5_66507c
  return eax;  // @6_66507c
}
PCREG(66507c, lifted_66507c);

extern "C" u32 lifted_66508d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @0_66508d
  p0_ = eax;  // @1_66508d
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @2_66508d
  p1_ = eax;  // @3_66508d
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66508d
  ecx = edx = 0;  // @5_66508d
  return eax;  // @6_66508d
}
PCREG(66508d, lifted_66508d);

extern "C" u32 lifted_6652b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_6652b0
  p0_ = eax;  // @1_6652b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6652b0
  p1_ = eax;  // @3_6652b0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_6652b0
  ecx = edx = 0;  // @5_6652b0
  return eax;  // @6_6652b0
}
PCREG(6652b0, lifted_6652b0);

extern "C" u32 lifted_6652f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_6652f0
  p0_ = eax;  // @1_6652f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_6652f0
  p1_ = eax;  // @3_6652f0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_6652f0
  ecx = edx = 0;  // @5_6652f0
  return eax;  // @6_6652f0
}
PCREG(6652f0, lifted_6652f0);

extern "C" u32 lifted_66530f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66530f
  p0_ = eax;  // @1_66530f
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_66530f
  p1_ = eax;  // @3_66530f
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66530f
  ecx = edx = 0;  // @5_66530f
  return eax;  // @6_66530f
}
PCREG(66530f, lifted_66530f);

extern "C" u32 lifted_665370(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665370
  p0_ = eax;  // @1_665370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_665370
  p1_ = eax;  // @3_665370
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_665370
  ecx = edx = 0;  // @5_665370
  return eax;  // @6_665370
}
PCREG(665370, lifted_665370);

extern "C" u32 lifted_665b6f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_665b6f
  p0_ = eax;  // @1_665b6f
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @2_665b6f
  p1_ = eax;  // @3_665b6f
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_665b6f
  ecx = edx = 0;  // @5_665b6f
  return eax;  // @6_665b6f
}
PCREG(665b6f, lifted_665b6f);

extern "C" u32 lifted_6680c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @0_6680c0
  p0_ = eax;  // @1_6680c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @2_6680c0
  p1_ = eax;  // @3_6680c0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_6680c0
  ecx = edx = 0;  // @5_6680c0
  return eax;  // @6_6680c0
}
PCREG(6680c0, lifted_6680c0);

extern "C" u32 lifted_6681f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @0_6681f0
  p0_ = eax;  // @1_6681f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @2_6681f0
  p1_ = eax;  // @3_6681f0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_6681f0
  ecx = edx = 0;  // @5_6681f0
  return eax;  // @6_6681f0
}
PCREG(6681f0, lifted_6681f0);

extern "C" u32 lifted_66d460(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_66d460
  p0_ = eax;  // @1_66d460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_66d460
  p1_ = eax;  // @3_66d460
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66d460
  ecx = edx = 0;  // @5_66d460
  return eax;  // @6_66d460
}
PCREG(66d460, lifted_66d460);

extern "C" u32 lifted_66d620(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66d620
  p0_ = eax;  // @1_66d620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_66d620
  p1_ = eax;  // @3_66d620
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66d620
  ecx = edx = 0;  // @5_66d620
  return eax;  // @6_66d620
}
PCREG(66d620, lifted_66d620);

extern "C" u32 lifted_66dab0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66dab0
  p0_ = eax;  // @1_66dab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @2_66dab0
  p1_ = eax;  // @3_66dab0
  eax = ext_4690b0_cdecl2((u32)(p1_), (u32)(p0_));  // @4_66dab0
  ecx = edx = 0;  // @5_66dab0
  return eax;  // @6_66dab0
}
PCREG(66dab0, lifted_66dab0);

