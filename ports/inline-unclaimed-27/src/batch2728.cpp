#include "ff.h"
// batch2728.cpp - unclaimed-27 batch 28 (gap band; docs/20-unclaimed-27.md). SEH-cookie family, asm-style port (coordinator decision,
// 2026-10-12 06:30 UTC). Names unknown (GUESS). The exe's SEH frame (fs:[0] record, cookie) is not reproduced; the epilogue of the
// exe pops the cookie into esi, so the wrapper sets esi = [0x6f5630] xor (entry esp - 4), the exe's cookie value.
// Callees are original code in the exe; the spec hooks them (stubs, NOT verified).
#include "ff.h"

extern "C" u32 THISCALL ext_581200(u8 *self);   // hooked in the spec
extern "C" u32 THISCALL ext_5812c0(u8 *self);   // hooked in the spec
extern "C" u32 THISCALL ext_581410(u8 *self);   // hooked in the spec
extern "C" void THISCALL ext_581530(u8 *self);   // hooked in the spec
extern "C" void THISCALL ext_5853f0(u8 *self);   // hooked in the spec
extern "C" void THISCALL ext_598440(u8 *self);   // hooked in the spec
extern "C" void THISCALL ext_59aa30(u8 *self);   // hooked in the spec

// 0x5819a0 (GUESS): p = slot +0x44 of the object at ([G 0x70039c]+0x9b)+8; if p, 0x581200(p); returns p.
extern "C" u32 family5819a0Core(u8 *self) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u8 *sub = *(u8 **)(eng + 8);
  u32 p = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)sub + 0x44)))(sub);
  if (p) ext_581200((u8 *)(unsigned long)p);
  return p;
}

// 0x581a10 (GUESS): same chain as 0x5819a0, callee 0x5812c0.
extern "C" u32 family581a10Core(u8 *self) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u8 *sub = *(u8 **)(eng + 8);
  u32 p = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)sub + 0x44)))(sub);
  if (p) ext_5812c0((u8 *)(unsigned long)p);
  return p;
}

// 0x581a80 (GUESS): same chain, callee 0x581410.
extern "C" u32 family581a80Core(u8 *self) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u8 *sub = *(u8 **)(eng + 8);
  u32 p = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)sub + 0x44)))(sub);
  if (p) ext_581410((u8 *)(unsigned long)p);
  return p;
}

// Wrappers: thiscall, no arguments; eax = the core's result; esi = cookie = [0x6f5630] ^ (entry esp - 4).
#define COOKIE_WRAPPER(WRAP, CORE)                                  \
  __asm__(".globl " #WRAP "\n" #WRAP ":\n"                          \
          "  movl %esp, %edx\n"                                     \
          "  pushl %ecx\n"                                          \
          "  call " #CORE "\n"                                      \
          "  addl $4, %esp\n"                                       \
          "  movl 0x6f5630, %ecx\n"                                 \
          "  subl $4, %edx\n"                                       \
          "  xorl %edx, %ecx\n"                                     \
          "  movl %ecx, %esi\n"                                     \
          "  ret\n");                                               \
  extern "C" void WRAP();

// 0x581af0 (GUESS): callee 0x581530 (plain ret, this = p).
extern "C" u32 family581af0Core(u8 *self) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u8 *sub = *(u8 **)(eng + 8);
  u32 p = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)sub + 0x44)))(sub);
  if (p) ext_581530((u8 *)(unsigned long)p);
  return p;
}

// 0x585780 (GUESS): callee 0x5853f0 (plain ret, this = p).
extern "C" u32 family585780Core(u8 *self) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u8 *sub = *(u8 **)(eng + 8);
  u32 p = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)sub + 0x44)))(sub);
  if (p) ext_5853f0((u8 *)(unsigned long)p);
  return p;
}

// 0x598e40 (GUESS): callee 0x598440 (plain ret, this = p).
extern "C" u32 family598e40Core(u8 *self) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u8 *sub = *(u8 **)(eng + 8);
  u32 p = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)sub + 0x44)))(sub);
  if (p) ext_598440((u8 *)(unsigned long)p);
  return p;
}

// 0x59ade0 (GUESS): callee 0x59aa30 (plain ret, this = p).
extern "C" u32 family59ade0Core(u8 *self) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u8 *sub = *(u8 **)(eng + 8);
  u32 p = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)sub + 0x44)))(sub);
  if (p) ext_59aa30((u8 *)(unsigned long)p);
  return p;
}

COOKIE_WRAPPER(familyWrap5819a0, family5819a0Core)
COOKIE_WRAPPER(familyWrap581a10, family581a10Core)
COOKIE_WRAPPER(familyWrap581a80, family581a80Core)
COOKIE_WRAPPER(familyWrap581af0, family581af0Core)
COOKIE_WRAPPER(familyWrap585780, family585780Core)
COOKIE_WRAPPER(familyWrap598e40, family598e40Core)
COOKIE_WRAPPER(familyWrap59ade0, family59ade0Core)
PCREG(5819a0, familyWrap5819a0);
PCREG(581a10, familyWrap581a10);
PCREG(581a80, familyWrap581a80);
PCREG(581af0, familyWrap581af0);
PCREG(585780, familyWrap585780);
PCREG(598e40, familyWrap598e40);
PCREG(59ade0, familyWrap59ade0);
