// batch34061 - cascade tier E, batch 34061: 0x5f4040 (build an object from a record found by a lookup), 0x5f4f00 (swap-remove from a vector of 8-byte refs), 0x5f51e0 (push-copy onto such a vector).
#include "ff.h"

extern "C" u32 THISCALL ext_5ffb70(void *self, u32 id);   // thiscall ret 4
extern "C" u8 *ext_5fa630();                              // returns the global at 0x724270
typedef u32 (*hook_t)();

// 0x5f4040, thiscall(a) ret 4, returns the new object or 0: r = [[0x724278]+0x3c]->slot0(a); rec = 0x5ffb70([this+0x96], (u16)r); 0 when rec is null. Otherwise h = the global at 0x724270 (0x5fa630),
// p = h->slot0x4c(this, a, [rec+8]) and, when p, p->slot0x48(rec, this); returns p.
static u32 THISCALL fn5f4040(u8 *self, u32 a) {
  u8 *g = G(u8 *, 0x724278);
  u8 *o = *(u8 **)(g + 0x3c);
  u32 r = vcall<u32>(o, 0, a);
  u8 *rec = (u8 *)ext_5ffb70((void *)(*(u32 *)(self + 0x96)), r & 0xffff);
  if (!rec) return 0;
  u8 *h = ext_5fa630();
  u8 *p = vcall<u8 *>(h, 0x4c, (u32)self, a, *(u32 *)(rec + 8));
  if (p) vcall<void>(p, 0x48, (u32)rec, (u32)self);
  return (u32)p;
}
PCREG(5f4040, fn5f4040);

// 0x5f4f00, thiscall(p) ret 4: vector of 8-byte refs {object or value at +0, kind byte at +4; kind 4 = ref-counted object (slot 0x24 clones, slot 0x28 releases)}: base [this], count [this+8], capacity
// [this+4]. With a zero count: the assert hook (int3 when null) and return. Otherwise the count drops by one, last = base + count*8; when last != p: p's old object is released (kind 4), then p takes last's value
// (cloned through slot 0x24 for kind 4) and kind. The last element's object is then released (kind 4) and its kind byte cleared.
static void THISCALL fn5f4f00(u8 *self, u8 *p) {
  u32 n = *(u32 *)(self + 8);
  if (n == 0) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    return;
  }
  n -= 1;
  u8 *last = *(u8 **)self + n * 8;
  *(u32 *)(self + 8) = n;
  if (last != p) {
    if (p[4] == 4) vcall<void>(*(u8 **)p, 0x28);
    u32 v;
    if (last[4] == 4) v = vcall<u32>(*(u8 **)last, 0x24);
    else v = *(u32 *)last;
    *(u32 *)p = v;
    p[4] = last[4];
  }
  if (last[4] == 4) vcall<void>(*(u8 **)last, 0x28);
  last[4] = 0;
}
PCREG(5f4f00, fn5f4f00);

// 0x5f51e0, thiscall(p) ret 4, returns the new last element's address: when count [this+8] >= capacity [this+4] (unsigned) the assert hook (int3 when null) runs and the push goes on; dst = base +
// count*8; when dst != p the old object of dst is released (kind 4) and dst takes p's value (cloned through slot 0x24 for kind 4) and kind; then count++ and returns base + count*8 - 8.
static u32 THISCALL fn5f51e0(u8 *self, u8 *p) {
  if (*(u32 *)(self + 8) >= *(u32 *)(self + 4)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *dst = *(u8 **)self + *(u32 *)(self + 8) * 8;
  if (p != dst) {
    if (dst[4] == 4) vcall<void>(*(u8 **)dst, 0x28);
    u32 v;
    if (p[4] == 4) v = vcall<u32>(*(u8 **)p, 0x24);
    else v = *(u32 *)p;
    *(u32 *)dst = v;
    dst[4] = p[4];
  }
  *(u32 *)(self + 8) += 1;
  return (u32)(*(u8 **)self + *(u32 *)(self + 8) * 8 - 8);
}
PCREG(5f51e0, fn5f51e0);
