// batch244000.cpp - Sonnet-w4c: tier-4 tiny RENDER/AUDIO/INPUT functions (thunks and getters). GUESS names.
// Tail-jump thunks are naked asm so the argument count is irrelevant (the callee sees exactly the caller's stack).
#include "ff.h"

extern "C" void ext_536640();
extern "C" void ext_462640();
extern "C" void ext_43f8c0();
extern "C" void ext_4ef200();
extern "C" void ext_4efdd0();

#define NAKED __attribute__((naked))

// 0x5332e0: jmp 0x536640
static void NAKED THISCALL fn5332e0() { __asm__ volatile("jmp ext_536640"); }
PCREG(5332e0, fn5332e0);
// 0x4f04d0: mov eax,[ecx]; jmp [eax+0x158]
static void NAKED THISCALL fn4f04d0() { __asm__ volatile("mov (%ecx), %eax\n\tjmp *0x158(%eax)"); }
PCREG(4f04d0, fn4f04d0);
// 0x536640: mov eax,[ecx]; jmp [eax+0x18c]
static void NAKED THISCALL fn536640() { __asm__ volatile("mov (%ecx), %eax\n\tjmp *0x18c(%eax)"); }
PCREG(536640, fn536640);
// 0x54dcd0: mov eax,[ecx]; jmp [eax+0x54]
static void NAKED THISCALL fn54dcd0() { __asm__ volatile("mov (%ecx), %eax\n\tjmp *0x54(%eax)"); }
PCREG(54dcd0, fn54dcd0);

// 0x64c750: mov eax,0x7f; ret
static u32 STDCALL fn64c750() { return 0x7f; }
PCREG(64c750, fn64c750);
// 0x64fb70: mov eax,[ecx+0x8c]; ret
static u32 THISCALL fn64fb70(u8 *self) { return *(u32 *)(self + 0x8c); }
PCREG(64fb70, fn64fb70);
// 0x429b00: byte [ecx+0x75] = 0; al = 1
static u8 THISCALL fn429b00(u8 *self) { self[0x75] = 0; return 1; }
PCREG(429b00, fn429b00);

// 0x473a60 / 0x4ef200 / 0x4f5160 / 0x4f5840: (push ebp; mov ebp,esp; pop ebp;) jmp target
static void NAKED THISCALL fn473a60() { __asm__ volatile("jmp ext_462640"); }
PCREG(473a60, fn473a60);
static void NAKED THISCALL fn4ef200() { __asm__ volatile("jmp ext_43f8c0"); }
PCREG(4ef200, fn4ef200);
static void NAKED THISCALL fn4f5160() { __asm__ volatile("jmp ext_4ef200"); }
PCREG(4f5160, fn4f5160);
static void NAKED THISCALL fn4f5840() { __asm__ volatile("jmp ext_4efdd0"); }
PCREG(4f5840, fn4f5840);

// 0x65f5d0: p = [this+0xc]; return [p+0x10069] - [p+0x10061]
static u32 THISCALL fn65f5d0(u8 *self) {
  u8 *p = *(u8 **)(self + 0xc);
  return *(u32 *)(p + 0x10069) - *(u32 *)(p + 0x10061);
}
PCREG(65f5d0, fn65f5d0);
