// batch67566.cpp - cascade s6 batch 67566: 0x4f12e0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)

// 0x4f12e0, thiscall(name) ret 4, returns al (1, or the result of slot 0x278): sets the object's name string this[0x97]. A name equal to the current one returns 1 untouched. Otherwise the old string is
// freed (sys slot 0xfc) and a non-empty new name is copied into a fresh allocation (sys slot 0xf8, length + 1); the cached second string this[0x9b] is freed and cleared and this slot 0x278 runs and
// supplies the result. An empty or null name runs this slot 0x230 instead, frees / clears this[0x9b] and returns 1.
static u32 THISCALL fn4f12e0(u8 *self, const volatile u8 *name) {
  const volatile u8 *cur = *(const volatile u8 **)(self + 0x97);
  if (cur) {
    const volatile u8 *a = cur, *b = name;
    bool eq = true;
    for (;;) {
      u8 x = *a, y = *b;
      if (x != y) { eq = false; break; }
      if (x == 0) break;
      a++;
      b++;
    }
    if (eq) return 1;
    vcall<void>(SYS, 0xfc, (u32)cur);
    D32(self, 0x97) = 0;
  }
  if (name && *name) {
    u32 len = 0;
    while (name[len]) len++;
    u8 *p = vcall<u8 *>(SYS, 0xf8, len + 1);
    D32(self, 0x97) = (u32)p;
    for (u32 i = 0; i <= len; i++) p[i] = name[i];
    u32 old = D32(self, 0x9b);
    if (old) vcall<void>(SYS, 0xfc, old);
    D32(self, 0x9b) = 0;
    return vcall<u32>(self, 0x278);
  }
  vcall<void>(self, 0x230);
  u32 old = D32(self, 0x9b);
  if (old) vcall<void>(SYS, 0xfc, old);
  D32(self, 0x9b) = 0;
  return 1;
}
PCREG(4f12e0, fn4f12e0);
