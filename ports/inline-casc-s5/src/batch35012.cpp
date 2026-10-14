// batch35012.cpp - cascade s5 batch 35012: 0x420810 (GUESS shut down the game session: release the two global objects and the object at +0x223d).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static inline u8 *rdp(u8 *p) { return (u8 *)(p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24); }

// 0x420810, thiscall, no arguments. slot 0x1d0(G[0x7003a4]); byte +0x60 = 1; log line through the object at 0x700390 (slot 0x20(0x677fb4, 0x693) -> slot 0x2c(r, 0x6e4098) called with ECX =
// the vtable, caller-popped); slot 0x3c(); the unaligned pointer [+0x9b] (when set) slot 0x128(); [+0x223d] slot 0x10(); then for each of the globals 0x7003a8, 0x7003a4 (when set):
// its slot 0x10(), this slot 0x4c(global), global = 0. Then this slot 0x20(1), this slot 0x4c([+0x223d]), [+0x223d] = 0, byte +0x1a9a = 0, byte +0x25ea = 1.
static void THISCALL fn420810(u8 *self) {
  (*(v1_t **)self)[0x1d0 / 4](self, G(u32, 0x7003a4));
  self[0x60] = 1;
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x677fb4, 0x693);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push $0x6e4098\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  (*(v0_t **)self)[0x3c / 4](self);
  u8 *o = rdp(self + 0x9b);
  if (o) (*(v0_t **)o)[0x128 / 4](o);
  u8 *p = rdp(self + 0x223d);
  (*(v0_t **)p)[0x10 / 4](p);
  u8 *q = G(u8 *, 0x7003a8);
  if (q) {
    (*(v0_t **)q)[0x10 / 4](q);
    (*(v1_t **)self)[0x4c / 4](self, G(u32, 0x7003a8));
    G(u32, 0x7003a8) = 0;
  }
  q = G(u8 *, 0x7003a4);
  if (q) {
    (*(v0_t **)q)[0x10 / 4](q);
    (*(v1_t **)self)[0x4c / 4](self, G(u32, 0x7003a4));
    G(u32, 0x7003a4) = 0;
  }
  (*(v1_t **)self)[0x20 / 4](self, 1);
  (*(v1_t **)self)[0x4c / 4](self, (u32)rdp(self + 0x223d));
  self[0x223d] = 0;
  self[0x223e] = 0;
  self[0x223f] = 0;
  self[0x2240] = 0;
  self[0x1a9a] = 0;
  self[0x25ea] = 1;
}
PCREG(420810, fn420810);
