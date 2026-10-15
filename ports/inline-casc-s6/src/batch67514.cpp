// batch67514.cpp - cascade s6 batch 67514: 0x59db90.
#include "ff.h"

extern "C" u32 THISCALL ext_4db9a0(u8 *self, u32 key);   // ret 4, bool in al
extern "C" void THISCALL ext_5889c0(u8 *entry, u8 *src); // ret 4: constructs a 0xf4-byte entry from src
extern "C" void THISCALL ext_589710(u8 *dst, u8 *src);   // ret 4: assigns an entry
extern "C" u32 THISCALL ext_5898c0(u8 *entry, u8 *owner);  // ret 4, bool in al
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x59db90, thiscall(), plain ret: when the state block at +0x54 has state 1, finds the registry entry (0xf4 bytes each, count dword then entries at engine-global 0x7003b8 + 0xd8d)
// whose +0x34 is the object reached through two slot-0x20 hops; when none exists and the object's record chain (+8, advanced with slot 0x50) holds more than one record of
// type 0x2007f9, a new entry is built from it (0x5889c0 / 0x589710, error 0x1b2 when the registry is full at 0x20). The entry then binds to this (0x5898c0) and, on success, is
// stored at +0x921.
static void THISCALL fn59db90(u8 *self) {
  if (D32(*(u8 **)(self + 0x54), 4) != 1) return;
  u8 *d1 = (u8 *)vcall<u32>(self, 0x20);
  u8 *edi = (u8 *)vcall<u32>(d1, 0x20);
  u8 *list = *(u8 **)0x7003b8 + 0xd8d;
  u8 *base = list + 4;
  u8 *esi = 0;
  for (u8 *p = base; p != base + D32(list, 0) * 0xf4; p += 0xf4) {
    if (D32(p, 0x34) == (u32)edi) {
      esi = p;
      break;
    }
  }
  if (!esi) {
    u8 *cur = *(u8 **)(edi + 8);
    s32 n = 0;
    while (cur) {
      if ((u8)ext_4db9a0(cur, 0x2007f9)) n++;
      vcall<void>(edi, 0x50, (u32)&cur);
    }
    if (n <= 1) return;
    if (D32(list, 0) == 0x20) {
      u8 *lg = *(u8 **)0x700390;
      void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6ae6a0, 0x1b2);
      (*(cd3_t **)L)[0x30 / 4](L, 0x6ae7d0, 0x20);
      return;
    }
    u8 tmp[0xf4];
    ext_5889c0(tmp, edi);
    ext_589710(base + D32(list, 0) * 0xf4, tmp);
    D32(list, 0)++;
    esi = base + (D32(list, 0) - 1) * 0xf4;
  }
  if ((u8)ext_5898c0(esi, self)) D32(self, 0x921) = (u32)esi;
}
PCREG(59db90, fn59db90);
