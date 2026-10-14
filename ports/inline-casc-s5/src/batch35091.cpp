// batch35091.cpp - cascade s5 batch 35091: 0x573b20 (GUESS find the list entry whose name matches).
#include "ff.h"

typedef void(THISCALL *v1p_t)(void *, void *);

// 0x573b20, stdcall(L, name) ret 8, returns the record [node+0x54] or 0. Iterates the list object L: node = [L+8], then L slot 0x50(&node) for the next one. The name of a node is the C string at [[node+0x54]+4]
// (the default string at 0x67c8e8 when that pointer is null); the first node whose name equals `name` (byte-wise strcmp) returns [node+0x54].
static u32 STDCALL fn573b20(u8 *L, const u8 *name) {
  u32 node = *(u32 *)(L + 8);
  while (node) {
    u8 *rec = *(u8 **)(node + 0x54);
    const u8 *a = *(const u8 **)(rec + 4);
    if (!a) a = (const u8 *)0x67c8e8;
    const u8 *b = name;
    for (;;) {
      u8 d = *a;
      if (d != *b) goto next;
      if (d == 0) return (u32)rec;
      d = a[1];
      if (d != b[1]) goto next;
      a += 2;
      b += 2;
      if (d == 0) return (u32)rec;
    }
  next:
    (*(v1p_t **)L)[0x50 / 4](L, &node);
  }
  return 0;
}
PCREG(573b20, fn573b20);
