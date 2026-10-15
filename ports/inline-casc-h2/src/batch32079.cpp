// batch32079.cpp - cascade h2 (Sonnet): 0x63af20 (take a free entry from a pool of 0x4c-byte entries chained through blocks).
#include "ff.h"

extern "C" u8 THISCALL ext_63b440(u8 *self);   // thiscall, plain ret, bool in al

static inline u16 rd16(const u8 *p) { return (u16)(p[0] | (p[1] << 8)); }
static inline void wr16(u8 *p, u16 v) { p[0] = v; p[1] = v >> 8; }

// 0x63af20, thiscall no args: skip exhausted blocks (word [blk+2] == 0xffff) along [blk+8] (stopping on a cycle back to the first or a null link); when
// the head block is exhausted, 0x63b440(this) must succeed (else 0) and the head [this+8] is re-read. Then [this+0xc]++; head word [h+2] == 0xffff -> 0;
// else e = h + 0x10 + idx*0x4c, [h+2] = word [e], clear e (dword [e] = 0, [e+4] = 0xffff1202, [e+0x38] = 0, byte [e+0x43] = 0), byte [h]++, return e.
static u8 *THISCALL fn63af20(u8 *self) {
  u8 *h = *(u8 **)(self + 8);
  if (h) {
    u8 *first = h;
    while (true) {
      u8 *cur = *(u8 **)(self + 8);
      if (rd16(cur + 2) != 0xffff) {
        *(u32 *)(self + 0xc) += 1;
        h = cur;
        goto take;
      }
      u8 *nx = *(u8 **)(cur + 8);
      *(u8 **)(self + 8) = nx;
      if (first == nx) break;
      if (!nx) break;
    }
  }
  if (!ext_63b440(self)) return 0;
  h = *(u8 **)(self + 8);
  *(u32 *)(self + 0xc) += 1;
  if (rd16(h + 2) == 0xffff) return 0;
take:
  {
    u32 idx = rd16(h + 2);
    u8 *e = h + 0x10 + idx * 0x4c;
    wr16(h + 2, rd16(e));
    *(u32 *)e = 0;
    *(u32 *)(e + 4) = 0xffff1202;
    *(u32 *)(e + 0x38) = 0;
    e[0x43] = 0;
    h[0] += 1;
    return e;
  }
}
PCREG(63af20, fn63af20);
