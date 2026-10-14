// batch35040.cpp - cascade s5 batch 35040: 0x43e850 (GUESS set an entry's name and value, then dispatch an event built on the stack).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);          // CRT free-style, cdecl
extern "C" u8 *ext_41e290(u32 n);                    // cdecl alloc
extern "C" void THISCALL ext_4de7a0(u8 *self);       // constructor of a 0x24-byte local, plain ret
extern "C" void THISCALL ext_4690b0(u8 *self);       // 1-byte function (plain ret)
typedef void(THISCALL *v2_t)(void *, void *, u32);

// 0x43e850, thiscall(a, name, v) ret 0xc. this[0x40] = v; [this+0x44] (when set) is freed (size 1); a copy of the C string `name` (length + 1 bytes from 0x41e290) becomes [this+0x44];
// 0x4de7a0 builds a 0x24-byte local that is handed to this slot 0x74(local, a); 0x4690b0 runs with ECX = [this+8].
static void THISCALL fn43e850(u8 *self, u32 a, const u8 *name, u32 v) {
  u8 local[0x24];
  *(u32 *)(self + 0x40) = v;
  u8 *old = *(u8 **)(self + 0x44);
  if (old) ext_634273(old, 1);
  const u8 *q = name;
  while (*q++) {}
  u32 len = (u32)(q - name);
  u8 *buf = ext_41e290(len);
  *(u8 **)(self + 0x44) = buf;
  u8 c;
  do {
    c = *name++;
    *buf++ = c;
  } while (c);
  ext_4de7a0(local);
  (*(v2_t **)self)[0x74 / 4](self, local, a);
  ext_4690b0(*(u8 **)(self + 8));
}
PCREG(43e850, fn43e850);
