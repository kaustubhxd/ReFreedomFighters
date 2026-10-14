// batch35005.cpp - cascade s5 batch 35005: 0x4d8e60 (GUESS drain a list: release each node's sub-object and remove the node).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // CRT free-style, cdecl
typedef void(THISCALL *v1_t)(void *, void *);
typedef u32 *(THISCALL *v1r_t)(void *, void *);

// 0x4d8e60, thiscall, no arguments. While list = [this] has a current node edi = list[1] that is non-null and != list[2]: s = unaligned dword [edi+0x11];
// unless the byte [this+4] is set and s non-null: s slot 0x4c(&it), then free(*p, 0) for every p that slot 0x64(&it) hands out (until null);
// delete s (slot 0 with 1) when non-null; list slot 4(edi) removes the node. At the end the word [this+4] is cleared.
static void THISCALL fn4d8e60(u8 *self) {
  u32 it[3];
  for (;;) {
    u32 *list = *(u32 **)self;
    u8 *edi = (u8 *)list[1];
    if (edi == (u8 *)list[2]) break;
    if (!edi) break;
    u8 flag = self[4];
    u8 *s = (u8 *)(edi[0x11] | edi[0x12] << 8 | edi[0x13] << 16 | (u32)edi[0x14] << 24);
    if (!flag && s) {
      (*(v1_t **)s)[0x4c / 4](s, it);
      u32 *p = (*(v1r_t **)s)[0x64 / 4](s, it);
      while (p) {
        ext_634273((void *)*p, 0);
        p = (*(v1r_t **)s)[0x64 / 4](s, it);
      }
    }
    if (s) (*(v1_t **)s)[0](s, (void *)1);
    u8 *l = *(u8 **)self;
    (*(v1_t **)l)[4 / 4](l, edi);
  }
  self[4] = 0;
  self[5] = 0;
}
PCREG(4d8e60, fn4d8e60);
