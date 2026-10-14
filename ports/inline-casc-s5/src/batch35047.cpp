// batch35047.cpp - cascade s5 batch 35047: 0x579b20 (GUESS format a label and hand a byte value to the registered handler).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v3_t)(void *, void *, u32, u32);
typedef void(THISCALL *v3b_t)(void *, u32, u32, void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x579b20, thiscall(a) ret 4. s = engine slot 0x190(); then s's slot 0x198 called with ECX = its vtable and four caller-popped stack args (s, buf (0x40 bytes), 0x6a9adc, [this+0x194]);
// t = engine table ([engine+0x9b]) slot 0x134(); t slot 0x68(buf, a, 0). Then v = a & 0xff; h = unaligned dword at [[0x7003b8] + 4 * [this+0x194] + 0x2c3d]; when non-zero:
// [this+0x44] slot 0x130(h, word [this+0x19a], &v).
static void THISCALL fn579b20(u8 *self, u32 a) {
  u8 buf[0x40];
  u32 v;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *s = (u8 *)(*(g0_t **)eng)[0x190 / 4](eng);
  u32 vt = *(u32 *)s;
  u32 f = ((u32 *)vt)[0x198 / 4];
  u32 idx = *(u32 *)(self + 0x194);
  asm volatile("push %[idx]\n\tpush $0x6a9adc\n\tpush %[buf]\n\tpush %[s]\n\tcall *%[f]\n\tadd $16, %%esp" : : "c"(vt), [idx] "r"(idx), [buf] "r"(buf), [s] "r"(s), [f] "r"(f) : "eax", "edx", "memory", "cc");
  eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *t = (u8 *)(*(g0_t **)tab)[0x134 / 4](tab);
  (*(v3_t **)t)[0x68 / 4](t, buf, a, 0);
  v = a & 0xff;
  u8 *base = G(u8 *, 0x7003b8);
  u32 h = rd32u(base + *(u32 *)(self + 0x194) * 4 + 0x2c3d);
  if (h) {
    u8 *o = *(u8 **)(self + 0x44);
    (*(v3b_t **)o)[0x130 / 4](o, h, *(u16 *)(self + 0x19a), &v);
  }
}
PCREG(579b20, fn579b20);
