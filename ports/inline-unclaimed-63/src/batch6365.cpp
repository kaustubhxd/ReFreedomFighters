// batch6365.cpp - unclaimed-63 batch 65: 0x478e20 ZActor::GetMoveTypeId(const char *) const (core list name), stdcall-like, one stack
//   argument s, ret 4 (ECX unused). For i = 0 .. 17: if cmp(s, table[i].name) == 0 (the cdecl compare through [0x676414], arguments
//   (s, name)) return table[i].id. Not found: the logger 0x700390 slot +0x20 (0x68a7c4, 0xd81) gives a log; its slot +0x2c
//   (cdecl, 0x68add0, s) prints; return 0. The table is at 0x68ac68 (8-byte entries: name pointer, id).
#include "ff.h"

typedef int (*cmp_fn)(u32, u32);
typedef u32(THISCALL * log20_fn)(void *, u32, u32);
typedef void (*printf3_fn)(u32, u32, u32);

// 0x478e20.
static u32 STDCALL unnamed478e20(u32 s) {
  for (u32 i = 0; i < 0x12; i++) {
    u32 name = G(u32, 0x68ac68 + 8 * i);
    if (((cmp_fn)G(u32, 0x676414))(s, name) == 0)
      return G(u32, 0x68ac6c + 8 * i);
  }
  u32 lg = G(u32, 0x700390);
  u32 l = ((log20_fn)(*(u32 *)(*(u32 *)lg + 0x20)))((void *)lg, 0x68a7c4u, 0xd81u);
  ((printf3_fn)(*(u32 *)(*(u32 *)l + 0x2c)))(l, 0x68add0u, s);
  return 0;
}
PCREG(478e20, unnamed478e20);
