// batch37103.cpp - cascade s6 batch 37103: 0x5079c0.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
extern "C" void THISCALL ext_4dbe30(u8 *self, u32 v);    // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x5079c0, thiscall(a) ret 4: script op taking three arguments (objects A, B and a flag). The owner's object +0x18 yields a record X (slot 0x20, again slot 0x20 for its
// id Y); with the flag set the owner's byte +0x6fe is cleared. X's inner object is reset (0x4dbe30), A attaches X (slot 0x288), the owner's slot 0x654 is called, B fills a 0x24 and a
// 0xc byte stack record (slot 0x80) which the owner consumes (slot 0x370) and the table handle of Y (slot 0x4c) is stored as the int result of a+8 (error 0xc4 with assert
// hook when the result node holds a non-int value).
static void THISCALL fn5079c0(u8 *self, u8 *a) {
  u8 b34[0x24];
  u8 b10[0xc];
  u32 st = *(u32 *)(a + 4);
  u8 *A = (u8 *)vcall<u32>(tabObj(), 0x58, D32(ext_5003d0(st, 0), 0));
  u8 *B = (u8 *)vcall<u32>(tabObj(), 0x58, D32(ext_5003d0(st, 1), 0));
  u32 flag = D32(ext_5003d0(st, 2), 0);
  u8 *owner = *(u8 **)(self + 0x18);
  u8 *X = (u8 *)vcall<u32>(owner, 0x20);
  u32 Y = vcall<u32>(X, 0x20);
  if (flag) (*(u8 **)(self + 0x18))[0x6fe] = 0;
  ext_4dbe30(*(u8 **)(X + 8), 0);
  vcall<void>(A, 0x288, (u32)X, 0u, 1u);
  vcall<void>(*(void **)(self + 0x18), 0x654, 0u);
  vcall<void>(B, 0x80, (u32)b34, (u32)b10);
  vcall<void>(*(void **)(self + 0x18), 0x370, (u32)b34, (u32)b10);
  u32 h = vcall<u32>(tabObj(), 0x4c, Y);
  u8 *n = ext_5003d0(*(u32 *)(a + 8), 0);
  if (n[4] <= 1) {
    D32(n, 0) = h;
    n[4] = 1;
    return;
  }
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0xc4);
  (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c938);
  hook_t hk = G(hook_t, 0x7003b0);
  if (!hk) __asm__ volatile("int3");
  hk();
}
PCREG(5079c0, fn5079c0);
