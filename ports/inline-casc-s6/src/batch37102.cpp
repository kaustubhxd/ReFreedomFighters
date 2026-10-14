// batch37102.cpp - cascade s6 batch 37102: 0x5fe080.
#include "ff.h"

extern "C" u32 THISCALL ext_5ffb00(u8 *self, u32 id);                       // ret 4
extern "C" u32 THISCALL ext_5ffe20(u8 *self, u32 id);                       // ret 4
extern "C" void THISCALL ext_600540(u8 *map, u32 *out, u8 *hint, u8 *pair);  // ret 0xc (map insert with hint)
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

static void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x5fe080, thiscall(map) ret 4: recursively visits the child object at +0x9c first, then for each of the +0xb8 entries of the {id, id2} array at +0xbc resolves a source value
// (from the table at +0xac / +0xb0 when the id lies in [+0xa0, +0xa0 + count), logging error 0x137 and asserting otherwise; or from the child through 0x5ffb00 when the id is out
// of range), maps it to a 16-bit key through the global object's slot 0 and finds (or inserts through 0x600540) that key in the map `map`; the node's value (+0xf) is then
// set from 0x5ffe20(id2).
static void THISCALL fn5fe080(u8 *self, u8 *map) {
  u8 *child = *(u8 **)(self + 0x9c);
  if (child) fn5fe080(child, map);
  u32 ebx = (u32)map;   // survives across iterations: the error path reuses the last table value
  for (u32 i = 0; i < D32(self, 0xb8); i++) {
    u8 *esi = *(u8 **)(*(u8 **)0x724278 + 0x3c);
    u8 *arr = *(u8 **)(self + 0xbc);
    u32 id = W16(arr, i * 4);
    u32 ebp4;
    if (D32(self, 0xa8) == 0 || D32(self, 0xa0) > id) {
      u8 *ch = *(u8 **)(self + 0x9c);
      if (ch) {
        ebp4 = ext_5ffb00(ch, id);
      } else {
        assertHook();
        ebp4 = 0;   // not reachable in the spec: the original leaves the stack slot as it was
      }
    } else {
      u32 d = (u16)(id - W16(self, 0xa0));
      if (d < D32(self, 0xa8)) {
        ebp4 = D32(*(u8 **)(self + 0xac), d * 4) + D32(self, 0xb0);
        ebx = ebp4;
      } else {
        u8 *lg = *(u8 **)0x700390;
        void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6b9420, 0x137);
        (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x6b9474);
        assertHook();
        ebp4 = ebx;
      }
    }
    u16 key = (u16)vcall<u32>(esi, 0x0, ebp4);
    u8 *hdr = *(u8 **)map;
    u8 *node = hdr;
    u8 *cur = *(u8 **)(hdr + 1);
    while (cur) {
      if (W16(cur, 0xd) < key) {
        cur = *(u8 **)(cur + 9);
      } else {
        node = cur;
        cur = *(u8 **)(cur + 5);
      }
    }
    if (node == hdr || key < W16(node, 0xd)) {
      u8 pair[6];
      *(u16 *)pair = key;
      *(u32 *)(pair + 2) = 0;
      u32 out;
      ext_600540(map, &out, node, pair);
      node = (u8 *)out;
    }
    D32(node, 0xf) = ext_5ffe20(self, W16(*(u8 **)(self + 0xbc), i * 4 + 2));
  }
}
PCREG(5fe080, fn5fe080);
