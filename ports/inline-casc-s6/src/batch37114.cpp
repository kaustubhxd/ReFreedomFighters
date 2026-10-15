// batch37114.cpp - cascade s6 batch 37114: 0x476c00.
#include "ff.h"

extern "C" u32 THISCALL ext_440e10(u8 *self, u8 *stream);          // ret 4, bool in al
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);     // allocate

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static u32 sat4(u32 n) {
  u64 b = (u64)n * 4;
  return (b >> 32) ? 0xffffffffu : (u32)b;
}

// 0x476c00, thiscall(stream) ret 4, returns bool: loads a list of table objects from the stream (after the 0x440e10 header check, which fails the load). Slot 0x68 reads the
// flag byte at +0x72 and slot 0x44 the field at +0x70. With the flag set a single id (slot 0x40) is resolved through the table object (slot 0x58) into +0x6c and the list fields
// +0x5c .. +0x68 are cleared. Otherwise slot 0x48 reads the count (+0x5c) and a second value (+0x60), two arrays of count dwords are allocated (+0x64 / +0x68), +0x64 is
// filled with the table objects of the ids read one by one, and +0x68 is read as a raw block (count * 4 bytes, slot 0x18); +0x6c is cleared.
static u8 THISCALL fn476c00(u8 *self, u8 *s) {
  if (!(u8)ext_440e10(self, s)) return 0;
  vcall<void>(s, 0x68, (u32)(self + 0x72));
  vcall<void>(s, 0x44, (u32)(self + 0x70));
  if (self[0x72]) {
    u32 tmp;
    vcall<void>(s, 0x40, (u32)&tmp);
    D32(self, 0x6c) = vcall<u32>(tabObj(), 0x58, tmp);
    D32(self, 0x5c) = 0;
    D32(self, 0x60) = 0;
    D32(self, 0x64) = 0;
    D32(self, 0x68) = 0;
    return 1;
  }
  vcall<void>(s, 0x48, (u32)(self + 0x5c));
  vcall<void>(s, 0x48, (u32)(self + 0x60));
  D32(self, 0x64) = (u32)ext_41e290(sat4(D32(self, 0x5c)));
  D32(self, 0x68) = (u32)ext_41e290(sat4(D32(self, 0x5c)));
  for (s32 i = 0; i < (s32)D32(self, 0x5c); i++) {
    u32 id;
    vcall<void>(s, 0x40, (u32)&id);
    ((u32 *)D32(self, 0x64))[i] = vcall<u32>(tabObj(), 0x58, id);
  }
  vcall<void>(s, 0x18, D32(self, 0x68), D32(self, 0x5c) << 2);
  D32(self, 0x6c) = 0;
  return 1;
}
PCREG(476c00, fn476c00);
