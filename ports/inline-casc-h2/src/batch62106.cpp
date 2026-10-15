#include "ff.h"
extern "C" u32 ext_41e290(u32 size);
extern "C" void ext_634273(u8 *ptr, u32 flags);
static void THISCALL fn49e0e0(u8 *self, u32 request) {
  u8 *allocator = (u8 *)*(u32 *)0x700394;
  u32 count = vcall<u32>(allocator, 0x30, request, 0);
  if ((s32)count <= 0) return;
  u8 *old = (u8 *)*(u32 *)(self + 4);
  if (old) ext_634273(old, 1);
  u8 *buffer = (u8 *)ext_41e290(count);
  *(u32 *)(self + 4) = (u32)buffer;
  vcall<void>(allocator, 0x60, request, buffer, count, 0, 0);
}
PCREG(49e0e0, fn49e0e0);
