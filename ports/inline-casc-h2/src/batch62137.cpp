#include "ff.h"
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);
extern "C" void THISCALL ext_5002f0(u8 *object, u32 enabled);

static void FASTCALL __attribute__((naked)) log_vtable_cdecl2(u32, u32, u32, u32) {
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

static void STDCALL fn50e8a0(u8 *self) {
  u8 *first = ext_5003d0((u8 *)G(u32, self + 4), 0);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *table = (u8 *)G(u32, sys + 0x9b);
  u8 *resource = (u8 *)vcall<u32>(table, 0x58, G(u32, first));
  u32 enabled = 0;
  if (resource) {
    u8 *flags = (u8 *)G(u32, resource + 8);
    enabled = 1u ^ ((G(u32, flags + 0x3c) >> 10) & 1u);
  } else {
    u8 *engine = G(u8 *, 0x700390);
    u8 *message = (u8 *)vcall<u32>(engine, 0x20, 0x69db34u, 0x27eu);
    u32 vt = G(u32, message);
    log_vtable_cdecl2(vt, G(u32, vt + 0x2c), (u32)message, 0x69de58u);
  }
  u8 *second = ext_5003d0((u8 *)G(u32, self + 8), 0);
  ext_5002f0(second, enabled);
}
PCREG(50e8a0, fn50e8a0);
