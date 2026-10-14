// batch38061.cpp - cascade s8 batch 38061: 0x5fe610 (recursive: replay a node's two child tables into a sink).
#include "ff.h"

extern "C" u32 THISCALL ext_5ffb00(u8 *child, u32 w);   // ret 4
extern "C" void THISCALL ext_5f9db0(u8 *sink, u8 *obj); // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log3_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

static void error_hook() {
  u8 *lg = G(u8 *, 0x700390);
  void *st = (void *)SLOT(lg, 0x20, v2_t)(lg, 0x6b9420, 0x137);
  (*(log3_t **)st)[0x2c / 4](st, 0x69c6b0, 0x6b9474);
}

// walks one table: base = this[off] + this[0x98]; [base] = entry count, entries of 6 bytes {dword index at +4, word id at +8}. For each entry the replacement value ebx is chosen: the id minus
// this[0xa0] indexes this[0xac] (plus this[0xb0]) when this[0xa8] says the local table is active and the id is inside it; an id below this[0xa0] (or an empty local table) asks the child
// (0x5ffb00(child, id)); an out-of-range id logs error 0x137 and keeps the previous value. B slot 0(value), the entry's object (at A[0x9e] + index) slot 0x3c(B) and 0x5f9db0(B, object) follow.
static void walk(u8 *self, u8 *A, u8 *B, u32 off) {
  u8 *base = (u8 *)(*(u32 *)(self + off) + *(u32 *)(self + 0x98));
  u32 n = *(u32 *)base;
  u32 pos = 0;
  u32 ebx = (u32)B, edi = (u32)B;
  while (n != 0) {
    u32 w = *(u16 *)(base + pos + 8);
    if (*(u32 *)(self + 0xa8) != 0 && !(*(u32 *)(self + 0xa0) > w)) {
      u32 w2 = (u16)(w - *(u16 *)(self + 0xa0));
      if (w2 < *(u32 *)(self + 0xa8)) {
        edi = (*(u32 **)(self + 0xac))[w2] + *(u32 *)(self + 0xb0);
        ebx = edi;
      } else {
        error_hook();
        hook_t h = G(hook_t, 0x7003b0);
        if (!h) __asm__ volatile("int3");
        h();
        ebx = edi;
      }
    } else {
      u8 *child = *(u8 **)(self + 0x9c);
      if (child) {
        ebx = ext_5ffb00(child, w);
      } else {
        hook_t h = G(hook_t, 0x7003b0);
        if (!h) __asm__ volatile("int3");
        h();
      }
    }
    SLOT(B, 0, v1_t)(B, ebx);
    u8 *o = *(u8 **)((u8 *)UN32(A, 0x9e) + *(u32 *)(base + pos + 4));
    SLOT(o, 0x3c, v1_t)(o, (u32)B);
    o = *(u8 **)((u8 *)UN32(A, 0x9e) + *(u32 *)(base + pos + 4));
    ext_5f9db0(B, o);
    pos += 6;
    n--;
  }
}

// 0x5fe610, thiscall(A, B) ret 8. Recurses into the child node this[0x9c] first, then replays the two tables at this[0x84] and this[0x80] (see walk()).
static void THISCALL fn5fe610(u8 *self, u8 *A, u8 *B) {
  u8 *child = *(u8 **)(self + 0x9c);
  if (child) fn5fe610(child, A, B);
  walk(self, A, B, 0x84);
  walk(self, A, B, 0x80);
}
PCREG(5fe610, fn5fe610);
