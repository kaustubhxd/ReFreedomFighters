// batch66017.cpp - cascade s4 batch 66017: 0x51fd70 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void (*hook_t)();

extern "C" void THISCALL ext_51b270(void *self, void *a);   // ret 4

// Push a handler address on the global handler stack (count [0x7019a8], array at 0x7019b0, capacity 0x32); a full stack reports through this->slot 0x11 (0x44)(0x6a0044) and the assert hook.
static void push_handler(u8 *t, u32 fn) {
  u32 cnt = G(u32, 0x7019a8);
  if (cnt < 0x32) {
    *(u32 *)(0x7019b0 + cnt * 4) = fn;
    G(u32, 0x7019a8) = cnt + 1;
  } else {
    (*(v1_t **)t)[0x44 / 4](t, 0x6a0044u);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
}

// 0x51fd70, thiscall(a) ret 4 (this = t): a[0xc] set -> push_handler 0x51fd10, then (while a[0xc] is still set) 0x51fd40, then 0x51fcc0. Finally a[0xc] = 0; 0x51b270(t, a).
static void THISCALL fn51fd70(u8 *t, u8 *a) {
  if (a[0xc]) {
    push_handler(t, 0x51fd10);
    if (a[0xc]) {
      push_handler(t, 0x51fd40);
      if (a[0xc]) push_handler(t, 0x51fcc0);
    }
  }
  a[0xc] = 0;
  ext_51b270(t, a);
}
PCREG(51fd70, fn51fd70);
