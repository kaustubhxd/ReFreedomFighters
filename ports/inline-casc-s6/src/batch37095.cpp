// batch37095.cpp - cascade s6 batch 37095: 0x5c7570.
#include "ff.h"

extern "C" u8 *THISCALL ext_4db2f0(u8 *self, u32 flag);   // ret 4
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5c7570, thiscall(a) ret 4: looks the exe string at 0x6b4718 up through the object 0x4db2f0 returns for a+0x1c's owner (slot 0x25c with a local copy of the string whose
// bytes 3 and 4 are patched from a+0x1c's name, default 0x67c8e8). A hit is registered (table slot 0x4c -> a+0x10 slot 4, then slot 0x130 of this+0x44 with the word at
// 0x714348); a miss logs error 0x25d through the logger. Either way a's id is then passed to a+0x10 slot 4 and to slot 0x12c of this+0x44.
static void THISCALL fn5c7570(u8 *self, u8 *a) {
  char buf[0x80];
  const char *str = (const char *)0x6b4718;
  u8 *w = ext_4db2f0(*(u8 **)(*(u8 **)(a + 0x1c) + 8), 1);
  u8 *nm = *(u8 **)(*(u8 **)(a + 0x1c) + 4);
  if (!nm) nm = (u8 *)0x67c8e8;
  u32 len = 0;
  while (str[len]) len++;
  for (u32 i = 0; i < len; i++) buf[i] = str[i];
  buf[3] = (char)nm[3];
  buf[4] = (char)nm[4];
  if (len >= 0x80) {
    for (;;) {}
  }
  buf[len] = 0;
  u32 r = vcall<u32>(w, 0x25c, (u32)buf, 0u);
  if (r) {
    u8 *obj = *(u8 **)(a + 0x10);
    u32 h = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x4c, r);
    vcall<void>(obj, 4, h);
    vcall<void>(*(void **)(self + 0x44), 0x130, r, (u32)*(u16 *)0x714348, 0u);
  } else {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6b45c0, 0x25d);
    (*(cd3_t **)L)[0x2c / 4](L, 0x6b4728, (u32)str);
  }
  vcall<void>(*(void **)(a + 0x10), 4, D32(a, 0));
  vcall<void>(*(void **)(self + 0x44), 0x12c, D32(a, 0), (u32)*(u16 *)0x714348, 0u);
}
PCREG(5c7570, fn5c7570);
