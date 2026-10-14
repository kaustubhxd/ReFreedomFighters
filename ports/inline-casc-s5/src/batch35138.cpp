// batch35138.cpp - cascade s5 batch 35138: 0x603d10 (GUESS call slot 0 of every listed object with its own table entry and an offset pointer).
#include "ff.h"

typedef u32 (*hook_t)();
typedef void(THISCALL *v2_t)(void *, u32, u32);

static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x603d10, thiscall(list, b) ret 8. n = signed [list+8]; nothing when n <= 0. extra = b + 0xaca. For i = 0, 1, ... while i < n (re-read, signed): the assert hook runs when i >= n or i >= [this+0x14] (unsigned);
// o = [list][i]; o slot 0(this[0xc] + 8 * i, extra) (ECX = o).
static void THISCALL fn603d10(u8 *self, u8 *list, u32 b) {
  s32 n = *(s32 *)(list + 8);
  if (n <= 0) return;
  u32 extra = b + 0xaca;
  u32 i = 0;
  do {
    if (i >= (u32)n) assert_hook();
    u8 *o = *(u8 **)(*(u8 **)list + i * 4);
    if (i >= *(u32 *)(self + 0x14)) assert_hook();
    u32 tbl = *(u32 *)(self + 0xc);
    (*(v2_t **)o)[0](o, tbl + i * 8, extra);
    i++;
    n = *(s32 *)(list + 8);
  } while ((s32)i < n);
}
PCREG(603d10, fn603d10);
