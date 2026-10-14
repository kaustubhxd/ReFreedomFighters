// batch34036.cpp - cascade tier E, batch 34036: 0x47ad60 (insert a key/value pair into a 10-entry table), 0x492170 (lazily query and allocate a buffer
// around a logger scope), 0x496620 (read ids from a stream and poke the matching nodes).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);   // cdecl alloc
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x47ad60, thiscall(k, v) ret 8, returns bool: table of pairs at +4 (key, then value at +0 of the next row: row i = {value at +i*8, key at +i*8+4}), count at +0x50. A key already present gives
// false. Otherwise (the assert hook is called, int3 when null, when the table already holds 10) key and value are stored at the current count and the count is bumped; true.
static bool THISCALL fn47ad60(u8 *self, u32 k, u32 v) {
  u32 n = *(u32 *)(self + 0x50);
  u32 i = 0;
  if (n) {
    u32 *e = (u32 *)(self + 4);
    for (;;) {
      if (*e == k) return false;
      i++;
      e += 2;
      if (!(i < n)) break;
    }
  }
  if (n == 10) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 idx = *(u32 *)(self + 0x50);
  *(u32 *)(self + idx * 8 + 4) = k;
  u32 idx2 = *(u32 *)(self + 0x50);
  *(u32 *)(self + idx2 * 8) = v;
  *(u32 *)(self + 0x50) += 1;
  return true;
}
PCREG(47ad60, fn47ad60);

// 0x492170, thiscall, no args: h = logger(0x70038c)->slot0x48(0x8080ff); when [this+0xae8] is zero: v = this->slot0x1f0(), [this+0xae8] = v; a result of 0 or -1 clears it,
// closes the scope (logger slot 0x48(h)) and returns. When [this+0xaec] is zero: p = alloc([this+0xae8]), [this+0xaec] = p, this->slot0x1f4(p, [this+0xae8]). Closes the scope.
static void THISCALL fn492170(u8 *self) {
  u8 *lg = G(u8 *, 0x70038c);
  u32 h = vcall<u32>(lg, 0x48, 0x8080ffu);
  if (*(u32 *)(self + 0xae8) == 0) {
    u32 v = vcall<u32>(self, 0x1f0);
    *(u32 *)(self + 0xae8) = v;
    if (v == 0 || v == 0xffffffffu) {
      *(u32 *)(self + 0xae8) = 0;
      vcall<void>(G(u8 *, 0x70038c), 0x48, h);
      return;
    }
  }
  if (*(u32 *)(self + 0xaec) == 0) {
    u32 p = ext_41e290(*(u32 *)(self + 0xae8));
    *(u32 *)(self + 0xaec) = p;
    vcall<void>(self, 0x1f4, p, *(u32 *)(self + 0xae8));
  }
  vcall<void>(G(u8 *, 0x70038c), 0x48, h);
}
PCREG(492170, fn492170);

// 0x496620, thiscall(s) ret 4: s->slot0xc(0xf); repeatedly s->slot0x18(&id, 4) until id == -1; for each id find the node with [node+0x20] == id on the engine table's chain
// ([[engine table]+0x5d29], next at +0x28) and call its slot 0x54(0).
static void THISCALL fn496620(u8 *self, u8 *s) {
  u32 id;
  (void)self;
  vcall<void>(s, 0xc, 0xfu);
  vcall<void>(s, 0x18, (u32)&id, 4u);
  while (id != 0xffffffffu) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *n = (u8 *)rd32u(tbl + 0x5d29);
    while (n) {
      if (*(u32 *)(n + 0x20) == id) {
        vcall<void>(n, 0x54, 0u);
        break;
      }
      n = *(u8 **)(n + 0x28);
    }
    vcall<void>(s, 0x18, (u32)&id, 4u);
  }
}
PCREG(496620, fn496620);
