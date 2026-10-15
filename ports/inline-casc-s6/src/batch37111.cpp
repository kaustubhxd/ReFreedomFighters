// batch37111.cpp - cascade s6 batch 37111: 0x569df0.
#include "ff.h"

extern "C" void THISCALL ext_610100(u8 *self, u8 *r);              // ret 4
extern "C" u32 THISCALL ext_4e5e60(u8 *r);                         // reads a dword
extern "C" u8 *THISCALL ext_4e5ea0(u8 *r);                         // reads a string (pointer or null)
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);     // allocate

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static u32 copyStr(const u8 *s) {
  u32 n = 0;
  while (s[n]) n++;
  u8 *p = (u8 *)ext_41e290(n + 1);
  for (u32 i = 0; i <= n; i++) p[i] = s[i];
  return (u32)p;
}

// 0x569df0, thiscall(reader) ret 4: loads this object's state from a reader (0x4e5e60 = next dword, 0x4e5ea0 = next string). After the base load (0x610100) it reads thirteen
// dwords into +0x19c, +0x1a0, +0x1a4, +0x1a8, +0x1ac, +0x1b0, +0x180 .. +0x198 (step 4), then two optional strings (duplicated into allocated copies at +0x1bd and +0x1c1 when non-empty),
// a flag dword (zero clears the byte at +0x87) and two more dwords into +0x1b8 and +0x1c5.
static void THISCALL fn569df0(u8 *self, u8 *r) {
  static const u16 offs[13] = {0x19c, 0x1a0, 0x1a4, 0x1a8, 0x1ac, 0x1b0, 0x180, 0x184, 0x188, 0x18c, 0x190, 0x194, 0x198};
  ext_610100(self, r);
  for (int i = 0; i < 13; i++) D32(self, offs[i]) = ext_4e5e60(r);
  u8 *s = ext_4e5ea0(r);
  if (s && *s) D32(self, 0x1bd) = copyStr(s);
  s = ext_4e5ea0(r);
  if (s && *s) D32(self, 0x1c1) = copyStr(s);
  if (ext_4e5e60(r) == 0) self[0x87] = 0;
  D32(self, 0x1b8) = ext_4e5e60(r);
  D32(self, 0x1c5) = ext_4e5e60(r);
}
PCREG(569df0, fn569df0);
