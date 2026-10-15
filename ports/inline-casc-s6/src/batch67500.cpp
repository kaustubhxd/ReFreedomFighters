// batch67500.cpp - cascade s6 batch 67500: 0x5c4e50.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *r);                         // reads a dword (called with ecx = 0)
extern "C" void THISCALL ext_4e6180(u8 *r, u32 *out);              // ret 4 (called with ecx = 0)
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);     // allocate
typedef u32 (*hook_t)();

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5c4e50, thiscall(stream) ret 4, returns 1: loads a list of up to five 0x19-byte records. Clears bit 6 of +4, calls the assert hook, reads +0x48 and the count +0x50 (clamped to 5)
// with the global reader (0x4e5e60, ecx = 0), two values into +0x64 / +0x70 (0x4e6180) and allocates count * 0x19 bytes (saturating) at +0x4c with the first dword of every record
// cleared. Each record then gets its stream header (slot 0x58 on the record address), a table object from an id (slot 0x40, table slot 0x58) at +4 and three fields read through slots
// 0x48 / 0x6c / 0x68 at +8 / +0xc / +0x18. Finally +0x58 takes slot 0x14 of the object at [+0x44]+0x18.
static u8 THISCALL fn5c4e50(u8 *self, u8 *s) {
  D32(self, 4) &= 0xffffffbfu;
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  D32(self, 0x48) = ext_4e5e60(0);
  D32(self, 0x50) = ext_4e5e60(0);
  ext_4e6180(0, (u32 *)(self + 0x64));
  ext_4e6180(0, (u32 *)(self + 0x70));
  if ((s32)D32(self, 0x50) > 5) D32(self, 0x50) = 5;
  u32 n = D32(self, 0x50);
  u64 b = (u64)n * 0x19;
  u8 *arr = (u8 *)ext_41e290((b >> 32) ? 0xffffffffu : (u32)b);
  if (arr) {
    u8 *p = arr;
    for (u32 i = n; i != 0; i--) {
      D32(p, 0) = 0;
      p += 0x19;
    }
  }
  D32(self, 0x4c) = (u32)arr;
  u32 off = 0;
  for (s32 i = 0; i < (s32)D32(self, 0x50); i++, off += 0x19) {
    u8 *rec = *(u8 **)(self + 0x4c) + off;
    vcall<void>(s, 0x58, (u32)rec);
    u32 id;
    vcall<void>(s, 0x40, (u32)&id);
    D32(rec, 4) = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, id);
    vcall<void>(s, 0x48, (u32)(rec + 8));
    vcall<void>(s, 0x6c, (u32)(rec + 0xc));
    vcall<void>(s, 0x68, (u32)(rec + 0x18));
  }
  D32(self, 0x58) = vcall<u32>(*(void **)(*(u8 **)(self + 0x44) + 0x18), 0x14);
  return 1;
}
PCREG(5c4e50, fn5c4e50);
