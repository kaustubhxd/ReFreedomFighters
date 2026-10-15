// batch66055.cpp - cascade s4 batch 66055: 0x603670 (tier F row).
#include "ff.h"

typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" void THISCALL ext_5f9940(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_5f9b80(void *self, void *a);               // ret 4

// Push a handler on the global handler stack (count [0x724698], array 0x7246a0, capacity 0x32); a full stack goes to the assert hook (int3 when none).
static void push_handler(u32 fn) {
  u32 cnt = G(u32, 0x724698);
  if (cnt < 0x32) {
    *(u32 *)(0x7246a0 + cnt * 4) = fn;
    G(u32, 0x724698) = cnt + 1;
  } else {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
}

// 0x603670, thiscall(a) ret 4 (this = t): three times: 0x5f9940(a, 0x6b9ac0 / 0x6b9acc / 0x6b9ad8, 0x677b5a, 0x677b5a) and, when a[0xc] is still set, push_handler(0x603790 / 0x603ef0 / 0x603a50).
// Finally a[0xc] = 0; 0x5f9b80(t, a).
static void THISCALL fn603670(u8 *t, u8 *a) {
  ext_5f9940(a, 0x6b9ac0u, 0x677b5au, 0x677b5au);
  if (a[0xc]) push_handler(0x603790);
  ext_5f9940(a, 0x6b9accu, 0x677b5au, 0x677b5au);
  if (a[0xc]) push_handler(0x603ef0);
  ext_5f9940(a, 0x6b9ad8u, 0x677b5au, 0x677b5au);
  if (a[0xc]) push_handler(0x603a50);
  a[0xc] = 0;
  ext_5f9b80(t, a);
}
PCREG(603670, fn603670);
