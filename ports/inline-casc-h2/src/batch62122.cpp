#include "ff.h"
extern "C" u32 THISCALL ext_63eab0(u8 *handle, u32 id);
static u32 THISCALL fn659000(u8 *self) {
  u32 index = G(u16, self + 0xa);
  u8 *outer = (u8 *)G(u32, self + 0x10);
  if (!index) return G(u32, outer + 0x10);
  u8 *inner = (u8 *)G(u32, outer + 0x10);
  if (!inner) return 0;
  u8 *data = inner + 0xc;
  if (index) {
    u8 *sys = G(u8 *, 0x70039c);
    u8 *manager = G(u8 *, sys + 0x1aa3);
    u8 *items = (u8 *)G(u32, data + 0x3c);
    u32 arg = G(u32, items + index * 4 + 4);
    data = (u8 *)vcall<u32>(manager, 0x80, arg);
  }
  if (!data) return 0;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *service = (u8 *)G(u32, sys + 0x190f);
  u32 id = G(u16, data + 0x40);
  u32 vt = G(u32, service);
  u32 target = G(u32, (u8 *)vt + 0x20);
  u32 handle;
  asm volatile("mov %[service], %%ecx; push %[id]; call *%[target]; add $4, %%esp"
               : "=&a"(handle)
               : [id] "r"(id), [service] "r"(service), [target] "r"(target)
               : "ecx", "edx", "memory", "cc");
  return ext_63eab0((u8 *)handle, id);
}
PCREG(659000, fn659000);
