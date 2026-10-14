// batch35112.cpp - cascade s5 batch 35112: 0x579a60 (GUESS format a label, show it and record the low byte of a in the handler's state).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef u8 *(THISCALL *g0p_t)(void *);
typedef void(THISCALL *v3_t)(void *, void *, u32, u32);
typedef u32(THISCALL *g1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x579a60, thiscall(a) ret 4. s = [0x70039c] slot 0x190(); s slot 0x198 called with ECX = its vtable and four caller-popped stack args (s, buf (0x40 bytes), 0x6a9afc, [this+0x194]); t = [engine+0x9b] slot 0x134(); t slot 0x68(buf, a, 0).
// h = unaligned dword [[0x7003b8] + 4 * [this+0x194] + 0x2c3d]; when non-zero: when the unaligned dword [h+0x85a] is zero it is set to h slot 0x100(0x6a6e88); then byte [[h+0x85a]+0xad4] = (u8)a.
static void THISCALL fn579a60(u8 *self, u32 a) {
  u8 buf[0x40];
  u8 *eng = G(u8 *, 0x70039c);
  u8 *s = (*(g0p_t **)eng)[0x190 / 4](eng);
  u32 vt = *(u32 *)s;
  u32 f = ((u32 *)vt)[0x198 / 4];
  u32 idx = *(u32 *)(self + 0x194);
  asm volatile("push %[idx]\n\tpush $0x6a9afc\n\tpush %[buf]\n\tpush %[s]\n\tcall *%[f]\n\tadd $16, %%esp" : : "c"(vt), [idx] "r"(idx), [buf] "r"(buf), [s] "r"(s), [f] "r"(f) : "eax", "edx", "memory", "cc");
  eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *t = (*(g0p_t **)tab)[0x134 / 4](tab);
  (*(v3_t **)t)[0x68 / 4](t, buf, a, 0);
  u8 *base = G(u8 *, 0x7003b8);
  u8 *h = (u8 *)rd32u(base + *(u32 *)(self + 0x194) * 4 + 0x2c3d);
  if (h) {
    if (rd32u(h + 0x85a) == 0) wr32u(h + 0x85a, (*(g1_t **)h)[0x100 / 4](h, 0x6a6e88));
    u8 *q = (u8 *)rd32u(h + 0x85a);
    q[0xad4] = (u8)a;
  }
}
PCREG(579a60, fn579a60);
