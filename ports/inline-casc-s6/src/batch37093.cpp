// batch37093.cpp - cascade s6 batch 37093: 0x603ef0.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x603ef0, thiscall(a) ret 4: copies a value slot of this object's table (8-byte entries at +0xc, count at +0x14) into the result slot of the script stack in a. The entry
// index is the int in a+4's node 0 (asserted below the count), the destination is node 0 of a+8. Kinds 0..2 are plain copies (an object value in the destination is released with
// slot 0x28 first); kind 4 is an object: the destination (empty or object only) is released and receives a clone (slot 0x24) of the entry's object; other kinds log error 0x7e.
static void THISCALL fn603ef0(u8 *self, u8 *a) {
  u32 idx = D32(ext_5003d0(*(u32 *)(a + 4), 0), 0);
  if (idx >= D32(self, 0x14)) assertHook();
  u32 kind = *(u8 *)(D32(self, 0xc) + idx * 8 + 4);
  if (kind <= 2) {
    if (idx >= D32(self, 0x14)) assertHook();
    u8 *src = (u8 *)(D32(self, 0xc) + idx * 8);
    u8 *dst = ext_5003d0(*(u32 *)(a + 8), 0);
    if (src == dst) return;
    if (dst[4] == 4) vcall<void>((void *)D32(dst, 0), 0x28);
    if (src[4] != 4) {
      D32(dst, 0) = D32(src, 0);
      dst[4] = src[4];
      return;
    }
    D32(dst, 0) = vcall<u32>((void *)D32(src, 0), 0x24);
    dst[4] = src[4];
    return;
  }
  if (kind == 4) {
    if (idx >= D32(self, 0x14)) assertHook();
    u8 *obj = (u8 *)D32(D32(self, 0xc) + idx * 8, 0);
    u8 *dst = ext_5003d0(*(u32 *)(a + 8), 0);
    u8 t = dst[4];
    if (t != 0) {
      if (t != 4) return;
      vcall<void>((void *)D32(dst, 0), 0x28);
    }
    D32(dst, 0) = vcall<u32>(obj, 0x24);
    dst[4] = 4;
    return;
  }
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6b9a70, 0x7e);
  (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x6b9aa8);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
PCREG(603ef0, fn603ef0);
