// batch35059.cpp - cascade s5 batch 35059: 0x442e20 (GUESS walk a node's children for a flagged node, then clear a pending state).
#include "ff.h"

extern "C" u8 THISCALL ext_4db9a0(u8 *self, u32 a);   // thiscall, ret 4, bool in AL
extern "C" void THISCALL ext_4da720(u8 *self, u32 a);  // thiscall, ret 4
typedef u8(THISCALL *b0_t)(void *);
typedef void(THISCALL *v1_t)(void *, void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x442e20, thiscall(n) ret 4. r = [n+0x54]; flags = r ? unaligned dword [[r+0xc]+0x23] : 0x200002. When flags has 0x100000: when 0x4db9a0(n, 0x100020) is true: r slot 0x310() true returns at once;
// r slot 0x30c() true with n != [this+8] returns at once. Then for each child c from [r+0x50] following [c+0x60]: this slot 0x2f4(c). Finally, when n != [this+8] and dword [n+0x3c] has 0x40000:
// 0x4da720(n, 0).
static void THISCALL fn442e20(u8 *self, u8 *n) {
  u8 *r = *(u8 **)(n + 0x54);
  u32 flags = r ? rd32u(*(u8 **)(r + 0xc) + 0x23) : 0x200002;
  if (flags & 0x100000) {
    if (ext_4db9a0(n, 0x100020)) {
      if ((*(b0_t **)r)[0x310 / 4](r)) return;
      if ((*(b0_t **)r)[0x30c / 4](r) && n != *(u8 **)(self + 8)) return;
    }
    for (u8 *c = *(u8 **)(r + 0x50); c; c = *(u8 **)(c + 0x60)) (*(v1_t **)self)[0x2f4 / 4](self, c);
  }
  if (n != *(u8 **)(self + 8) && (*(u32 *)(n + 0x3c) & 0x40000)) ext_4da720(n, 0);
}
PCREG(442e20, fn442e20);
