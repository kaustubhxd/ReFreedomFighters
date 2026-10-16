#include "ff.h"

static void FASTCALL __attribute__((naked)) call_vtable_cdecl2(u32, u32, u32, u32) {
  __asm__ volatile(
    ".intel_syntax noprefix\n"
    "mov eax, edx\n"
    "push dword ptr [esp+8]\n"
    "push dword ptr [esp+8]\n"
    "call eax\n"
    "add esp, 8\n"
    "ret 8\n"
    ".att_syntax prefix\n");
}

static u32 THISCALL fn4960e0(u8 *self) {
  u32 index = G(u32, self + 0x59);
  if (index >= 0x1fe) {
    u8 *engine = G(u8 *, 0x700390);
    u8 *message = (u8 *)vcall<u32>(engine, 0x20, 0x68e36cu, 0xc9cu);
    u32 vt = G(u32, message);
    call_vtable_cdecl2(vt, G(u32, vt + 0x2c), (u32)message, 0x68e7e0u);
    return 0;
  }
  u16 *array = (u16 *)G(u32, self + 0x55);
  u8 *base = (u8 *)G(u32, self + 0x51);
  u8 *entry = base + ((u32)array[index] << 5);
  G(u32, self + 0x59) = index + 1;
  G(u8, entry + 0x1c) = 0;
  G(u32, entry + 0x18) = 0;
  u8 *logger = G(u8 *, 0x70038c);
  if (logger) {
    u32 offset = (u32)(entry - base);
    vcall<void>(logger, 0x2c, 0x68e7d4u, offset, 0x20u);
  }
  return (u32)entry;
}
PCREG(4960e0, fn4960e0);
