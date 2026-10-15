// batch37112.cpp - cascade s6 batch 37112: 0x551e60.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);        // ret 4
extern "C" u8 *THISCALL ext_5002f0(u8 *node, u32 v);          // ret 4
extern "C" u32 THISCALL ext_4db9a0(u8 *self, u32 key);        // ret 4, bool in al
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd2_t)(void *, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x551e60, stdcall(a) ret 4: script op counting records. Resolves the object whose id is the first argument (it must answer slot 0x1e0 with 0x100001, otherwise error 0x33f is
// logged and 0 stored in the result node a+8), walks its record chain (slot 0x50 with an out pointer) and counts the records of type 0x2007f9 whose owner object does not
// answer slot 0x438 and whose linked record has flag bit 10 clear. The count becomes the int result (after a 0 / 1 type check of the result node that logs error 0x104 and
// calls the assert hook).
static void STDCALL fn551e60(u8 *a) {
  u8 *idn = ext_5003d0(*(u32 *)(a + 4), 0);
  u8 *obj = (u8 *)vcall<u32>(tabObj(), 0x58, D32(idn, 0));
  if (!obj || !(u8)vcall<u32>(obj, 0x1e0, 0x100001u)) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6a57fc, 0x33f);
    (*(cd2_t **)L)[0x2c / 4](L, 0x6a5b28);
    ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), 0);
    return;
  }
  u32 count = 0;
  u8 *cur = *(u8 **)(obj + 8);
  while (cur) {
    if ((u8)ext_4db9a0(cur, 0x2007f9)) {
      if (!(u8)vcall<u32>(*(void **)(cur + 0x54), 0x438)) {
        u32 v = D32(*(u8 **)(*(u8 **)(*(u8 **)(cur + 0x50) + 0x54) + 8), 0x3c);
        if ((~(v >> 10)) & 1) count++;
      }
    }
    vcall<void>(obj, 0x50, (u32)&cur);
  }
  u8 *n = ext_5003d0(*(u32 *)(a + 8), 0);
  if (n[4] != 0 && n[4] != 1) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0x104);
    (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  D32(n, 0) = count;
  n[4] = 1;
}
PCREG(551e60, fn551e60);
