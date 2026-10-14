// batch37024.cpp - cascade s6 batch 37024: 0x4cb7f0.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);   // alloc, cdecl
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *dt_t)(void *, u32);
typedef u32(THISCALL *hook0_t)();
typedef u32 (*hook_t)();

static inline u8 *lookup(u32 id) {
  void *t = *(void **)(*(u8 **)0x70039c + 0x9b);
  return (u8 *)(*(v1_t **)t)[0x58 / 4](t, id);
}
static inline u32 allocN(u32 n) {
  u64 p = (u64)n * 4;
  return (u32)ext_41e290((p >> 32) ? 0xffffffffu : (u32)p);
}

static void THISCALL fn4cb7f0(u8 *self, u32 id);
// 0x4cb7f0, thiscall(id) ret 4 (recursive): walks the list of the table object `id` (slot 0x4c starts, 0x5c iterates) and for each item whose object does not answer
// slot 0x1e0(0x80200014): a group object (tag 0x800001a at [[obj+0xc]+0x23]) is expanded recursively, anything else is registered through slot 4 of this+0x54 (called with the item; its
// block gets the item id at -4 and zero at +0 / +1). Then the list held in this+0x48 (if any) is copied into a fresh array at this+0x68 (this+0x6c gets a second
// array of the same size), the count is checked against slot 0x14 (assert hook when it differs) and the list object is destroyed through its slot 0.
static void THISCALL fn4cb7f0(u8 *self, u32 id) {
  u8 *o = lookup(id);
  if (o && *(u8 **)(o + 0x18)) {
    u32 var_c;
    void *l = *(void **)(o + 0x18);
    (*(v1_t **)l)[0x4c / 4](l, (u32)&var_c);
    l = *(void **)(o + 0x18);
    u32 item = (*(v1_t **)l)[0x5c / 4](l, (u32)&var_c);
    while (var_c != 0) {
      u8 *p = lookup(item);
      if (p) {
        if (!(u8)(*(v1_t **)p)[0x1e0 / 4](p, 0x80200014)) {
          u8 *tag = *(u8 **)(p + 0xc);
          if (*(u32 *)(tag + 0x23) == 0x800001a) {
            fn4cb7f0(self, item);
          } else {
            void *q = *(void **)(self + 0x54);
            u8 *blk = (u8 *)(*(v1_t **)q)[1](q, item);
            *(u32 *)(blk - 4) = item;
            *blk = 0;
            *(u32 *)(blk + 1) = 0;
          }
        }
      }
      l = *(void **)(o + 0x18);
      item = (*(v1_t **)l)[0x5c / 4](l, (u32)&var_c);
    }
  }
  void *lst = *(void **)(self + 0x48);
  if (!lst) return;
  u32 n = (*(v0_t **)lst)[0x14 / 4](lst);
  *(u32 *)(self + 0x64) = n;
  if (n) {
    *(u32 *)(self + 0x68) = allocN(n);
    *(u32 *)(self + 0x6c) = allocN(*(u32 *)(self + 0x64));
  }
  lst = *(void **)(self + 0x48);
  u32 i = 0;
  if (lst) {
    u32 var_c;
    (*(v1_t **)lst)[0x4c / 4](lst, (u32)&var_c);
    lst = *(void **)(self + 0x48);
    u32 item = (*(v1_t **)lst)[0x5c / 4](lst, (u32)&var_c);
    if (var_c != 0) {
      do {
        (*(u32 **)(self + 0x68))[i] = item;
        i++;
        lst = *(void **)(self + 0x48);
        item = (*(v1_t **)lst)[0x5c / 4](lst, (u32)&var_c);
      } while (var_c != 0);
    }
  }
  if (i != *(u32 *)(self + 0x64)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  lst = *(void **)(self + 0x48);
  if (lst) (*(dt_t **)lst)[0](lst, 1);
  *(u32 *)(self + 0x48) = 0;
}
PCREG(4cb7f0, fn4cb7f0);
