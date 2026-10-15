// batch37120.cpp - cascade s6 batch 37120: 0x55c460.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
extern "C" u32 THISCALL ext_506040(u8 *node);            // plain ret
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void typeCheck(u8 *n) {
  if (n[4] != 0 && n[4] != 1) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0x104);
    (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
}

// 0x55c460, thiscall(a) ret 4: script op that broadcasts a pair of ints. With the owner's listener list at [this+0x1c]+0x921 (count, then that many object pointers) it reads three
// arguments of a+4 (a name, resolved to a 16-bit id through the table object slot 0x114, and two ints, type-checked 0 / 1) and calls slot 0x128 (id, &{int1, int2}, 0) on every listener
// other than the owner.
static void THISCALL fn55c460(u8 *self, u8 *a) {
  u8 *lst = *(u8 **)(*(u8 **)(self + 0x1c) + 0x921);
  if (!lst) return;
  u32 args = *(u32 *)(a + 4);
  u32 name = ext_506040(ext_5003d0(args, 0));
  u8 *n1 = ext_5003d0(args, 1);
  typeCheck(n1);
  u32 v1 = D32(n1, 0);
  u8 *n2 = ext_5003d0(args, 2);
  typeCheck(n2);
  u32 v2 = D32(n2, 0);
  u32 id = (u16)vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x114, name, 0u, 0x6a5eb0u, 0x2a9u);
  u32 pair[2] = {v1, v2};
  u8 *esi = lst + 4;
  while (esi != lst + (D32(lst, 0) + 1) * 4) {
    u8 *obj = *(u8 **)esi;
    if (obj != *(u8 **)(self + 0x1c)) vcall<void>(obj, 0x128, id, (u32)pair, 0u);
    esi += 4;
  }
}
PCREG(55c460, fn55c460);
