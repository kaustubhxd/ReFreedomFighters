#include "ff.h"

static void FASTCALL __attribute__((naked)) call_vtable_cdecl4_b(u32, u32, u32, u32, u32, u32) {
  __asm__ volatile(
    ".intel_syntax noprefix\n"
    "mov eax, edx\n"
    "push dword ptr [esp+0x10]\n"
    "push dword ptr [esp+0x10]\n"
    "push dword ptr [esp+0x10]\n"
    "push dword ptr [esp+0x10]\n"
    "call eax\n"
    "add esp, 0x10\n"
    "ret 0x10\n"
    ".att_syntax prefix\n");
}

static u32 THISCALL fn578e30(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *context = (u8 *)vcall<u32>(sys, 0x190);
  u32 local44 = 0;
  u8 local45 = 0;
  u32 target = G(u32, G(u32, context) + 0x198);
  call_vtable_cdecl4_b(G(u32, context), target, (u32)context, (u32)&local44,
                       0x6a9ac8u, G(u32, self + 0x194));
  u8 *table = (u8 *)G(u32, sys + 0x9b);
  u8 *resource = (u8 *)vcall<u32>(table, 0x134);
  vcall<void>(resource, 0x90, &local44, &local45);
  return local45;
}
PCREG(578e30, fn578e30);
