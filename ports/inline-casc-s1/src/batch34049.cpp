// batch34049.cpp - cascade escalation batch 34049 (queue items 0x4c5680 and 0x4dc030): a byte-forwarding wrapper and a recursive tree update.
#include "ff.h"

extern "C" u32 THISCALL ext_4c5770(void *self, u32 b);   // thiscall ret 4
extern "C" void THISCALL ext_4da770(void *self, u32 a);  // thiscall ret 4
extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);   // thiscall ret 8
extern "C" u32 THISCALL ext_4daff0(void *p);             // thiscall, plain ret
extern "C" void THISCALL ext_4dae60(void *self);         // thiscall, plain ret

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4c5680, thiscall, no args: returns 0x4c5770(this, byte [this+0x52]).
static u32 THISCALL fn4c5680(u8 *self) { return ext_4c5770(self, self[0x52]); }
PCREG(4c5680, fn4c5680);

// 0x4dc030, thiscall, no args: nothing when bit 0x400 of [this+0x3c] is set. Otherwise: when [this+0x68] and the object at the unaligned [[engine table]+0x5d35] exist: it->slot0x10(this);
// 0x4da770(this, 0); 0x4dc630(this, 0x400, 0); [this+0x54]->slot0x24(0) when set. When bit 0x40000 of the flags: if [this+0x64] and the low flag byte are non-zero: y = 0x4daff0([[this+0x50]+0x54]+8)
// (ECX = that dword), and when y: y->slot0x320(this) and [this+0x64] = 0; then 0x4dae60(this). Then the flag dword at +0x23 of the record [[this+0x54]+0xc] (0x200002 when [this+0x54] is null): with bit
// 0x100000 set recurse on every child from [[this+0x54]+0x50] along [child+0x60].
static void THISCALL fn4dc030(u8 *self) {
  u32 flags = *(u32 *)(self + 0x3c);
  if (((flags >> 10) & 1) != 0) return;
  if (*(u32 *)(self + 0x68)) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *p = (u8 *)rd32u(tbl + 0x5d35);
    if (p) vcall<void>(p, 0x10, (u32)self);
  }
  ext_4da770(self, 0);
  ext_4dc630(self, 0x400, 0);
  u8 *c = *(u8 **)(self + 0x54);
  if (c) vcall<void>(c, 0x24, 0u);
  flags = *(u32 *)(self + 0x3c);
  if (flags & 0x40000) {
    if (*(u32 *)(self + 0x64) && (u8)flags) {
      u8 *x = *(u8 **)(self + 0x50);
      u32 ecx = x ? *(u32 *)(*(u8 **)(x + 0x54) + 8) : *(u32 *)(0 + 8);
      u8 *y = (u8 *)ext_4daff0((void *)ecx);
      if (y) {
        vcall<void>(y, 0x320, (u32)self);
        *(u32 *)(self + 0x64) = 0;
      }
    }
    ext_4dae60(self);
  }
  u8 *oc = *(u8 **)(self + 0x54);
  u32 f2 = oc ? rd32u(*(u8 **)(oc + 0xc) + 0x23) : 0x200002;
  if (f2 & 0x100000) {
    u8 *ch = *(u8 **)(oc + 0x50);
    while (ch) {
      fn4dc030(ch);
      ch = *(u8 **)(ch + 0x60);
    }
  }
}
PCREG(4dc030, fn4dc030);
