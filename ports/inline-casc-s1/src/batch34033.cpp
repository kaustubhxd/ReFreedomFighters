// batch34033.cpp - cascade tier E, batch 34033: 0x63d7d0 (feed every node of a list to this), 0x6485c0 (append a dword to a chunked list), 0x4288f0
// (tick three object arrays).
#include "ff.h"

typedef u32 (*hook_t)();

// 0x63d7d0, thiscall(a) ret 4: s = [a+0x54]; flags = s ? dword [[s+0xc]+0x23] : 0x200002; when bit 0x100000 is clear call the assert hook (int3 when null);
// then for node = [[a+0x54]+8]; node; node = next (s->slot0x50(&node)): this->slot0x50(node).
static void THISCALL fn63d7d0(u8 *self, u8 *a) {
  u8 *s = *(u8 **)(a + 0x54);
  u32 flags = 0x200002;
  if (s) {
    u8 *q = *(u8 **)(s + 0xc);
    flags = q[0x23] | q[0x24] << 8 | q[0x25] << 16 | (u32)q[0x26] << 24;
  }
  if (!(flags & 0x100000)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  s = *(u8 **)(a + 0x54);
  u32 node = *(u32 *)(s + 8);
  while (node) {
    vcall<void>(self, 0x50, node);
    vcall<void>(s, 0x50, (u32)&node);
  }
}
PCREG(63d7d0, fn63d7d0);

// 0x6485c0, thiscall(p) ret 4, returns bool: chunked list: current chunk [this+0x10] (count at +0, items from +0x10, prev at +0xc, next at +8; capacity 0x3fc). When there is no
// chunk or it is full: nb = [this+4]->slot8(); false when null; link it (old->next = nb or [this+0xc] = nb; nb->prev = old; nb->next = 0; nb->count = 0) and make it current.
// Then store [p] in the current chunk, bump its count and [this+8]; returns true.
static bool THISCALL fn6485c0(u8 *self, u32 *p) {
  u8 *blk = *(u8 **)(self + 0x10);
  if (!blk || *(u32 *)blk == 0x3fc) {
    u8 *nb = vcall<u8 *>(*(u8 **)(self + 4), 8);
    if (!nb) return false;
    u8 *old = *(u8 **)(self + 0x10);
    if (old) *(u8 **)(old + 8) = nb;
    else *(u8 **)(self + 0xc) = nb;
    old = *(u8 **)(self + 0x10);
    *(u8 **)(nb + 0xc) = old;
    *(u32 *)(nb + 8) = 0;
    *(u32 *)nb = 0;
    *(u8 **)(self + 0x10) = nb;
  }
  u8 *cur = *(u8 **)(self + 0x10);
  u32 cnt = *(u32 *)cur;
  *(u32 *)cur = cnt + 1;
  *(u32 *)(cur + cnt * 4 + 0x10) = *p;
  *(u32 *)(self + 8) += 1;
  return true;
}
PCREG(6485c0, fn6485c0);

// 0x4288f0, thiscall, no args: slot 0x28() of the [this+0xc] objects at +4.., of the [this+0x1c] objects at +0x10.., then slot 0x50() of the [this+0x60] objects at +0x20.. (unsigned counts).
static void THISCALL fn4288f0(u8 *self) {
  for (u32 i = 0; i < *(u32 *)(self + 0xc); i++) vcall<void>(*(u8 **)(self + 4 + i * 4), 0x28);
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) vcall<void>(*(u8 **)(self + 0x10 + i * 4), 0x28);
  for (u32 i = 0; i < *(u32 *)(self + 0x60); i++) vcall<void>(*(u8 **)(self + 0x20 + i * 4), 0x50);
}
PCREG(4288f0, fn4288f0);
