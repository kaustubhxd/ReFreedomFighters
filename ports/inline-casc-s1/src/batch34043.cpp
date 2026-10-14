// batch34043.cpp - cascade tier E, batch 34043: 0x5efe00 (read five fields from a stream), 0x5fd240 (remove a value from an array), 0x64db30 (pop an item from a chunked list).
#include "ff.h"

extern "C" void THISCALL ext_5ee720(void *self, void *s);   // thiscall ret 4
typedef void *(*memmove_t)(void *, const void *, u32);       // cdecl, through the IAT (VCRUNTIME140!memmove)

// 0x5efe00, thiscall(s) ret 4: 0x5ee720(this, s); s->slot0x50(this+0x84), (+0x88), (+0x8c), (+0x90); s->slot0x40(&v); [this+0x94] = v; s->slot0x68(this+0x98).
static void THISCALL fn5efe00(u8 *self, u8 *s) {
  ext_5ee720(self, s);
  vcall<void>(s, 0x50, (u32)(self + 0x84));
  vcall<void>(s, 0x50, (u32)(self + 0x88));
  vcall<void>(s, 0x50, (u32)(self + 0x8c));
  vcall<void>(s, 0x50, (u32)(self + 0x90));
  u32 v;
  vcall<void>(s, 0x40, (u32)&v);
  *(u32 *)(self + 0x94) = v;
  vcall<void>(s, 0x68, (u32)(self + 0x98));
}
PCREG(5efe00, fn5efe00);

// 0x5fd240, thiscall(k) ret 4, returns bool: array [this] of n = [this+8] dwords; false when k is absent. When found at index i < n-1 the tail is moved down by memmove(base+4i,
// base+4i+4, (n-i)*4) (one dword more than strictly needed, as in the original); [this+8]--; true.
static bool THISCALL fn5fd240(u8 *self, u32 k) {
  u32 n = *(u32 *)(self + 8);
  u32 i = 0;
  if (!n) return false;
  u32 *base = *(u32 **)self;
  u32 *e = base;
  for (;;) {
    if (k == *e) break;
    i++;
    e += 1;
    if (!(i < n)) return false;
  }
  if (i < n - 1) {
    u32 *dst = base + i;
    G(memmove_t, 0x676278)(dst, (u8 *)dst + 4, (n - i) << 2);
  }
  *(u32 *)(self + 8) -= 1;
  return true;
}
PCREG(5fd240, fn5fd240);

// 0x64db30, thiscall(p) ret 4: pops the last item of the chunked list's current chunk ([this+0x10], count at +0, items from +0x10): count--; the iterator p ([p] = pointer to an item) is reset
// ([p] = [p+8] = 0) when it pointed at the removed item, else that item slot receives the removed value; an emptied chunk is unlinked (prev at +0xc becomes current, next cleared, the empty chunk
// freed through [this+4] slot 0xc, [this+0xc] = 0 when there is no previous one); [this+8]-- in every case.
static void THISCALL fn64db30(u8 *self, u32 *p) {
  u8 *blk = *(u8 **)(self + 0x10);
  u32 *edi = (u32 *)p[0];
  *(u32 *)blk -= 1;
  u32 cnt = *(u32 *)blk;
  u8 *cur = *(u8 **)(self + 0x10);
  u32 *end = (u32 *)(cur + cnt * 4 + 0x10);
  if (edi == end) {
    p[2] = 0;
    p[0] = 0;
  } else {
    *edi = *end;
  }
  u8 *c2 = *(u8 **)(self + 0x10);
  if (*(u32 *)c2 == 0) {
    u8 *owner = *(u8 **)(self + 4);
    *(u32 *)(self + 0x10) = *(u32 *)(c2 + 0xc);
    vcall<void>(owner, 0xc, (u32)c2);
    u8 *nc = *(u8 **)(self + 0x10);
    if (nc) {
      *(u32 *)(nc + 8) = 0;
      *(u32 *)(self + 8) -= 1;
      return;
    }
    *(u32 *)(self + 0xc) = 0;
  }
  *(u32 *)(self + 8) -= 1;
}
PCREG(64db30, fn64db30);
