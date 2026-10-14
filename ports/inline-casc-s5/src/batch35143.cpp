// batch35143.cpp - cascade s5 batch 35143: 0x55fca0 (GUESS add an amount to two counters of a tracked object, logging when it is not tracked).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4: record whose first dword is the value
extern "C" u32 *THISCALL ext_5a45c0(u32 self, u32 a);   // thiscall, ret 4
extern "C" u8 *THISCALL ext_5a4610(u32 self, u32 a);    // thiscall, ret 4
typedef u32(THISCALL *e1_t)(void *, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x55fca0, stdcall(a) ret 4. id = *0x5003d0([a+4], 0), amount = *0x5003d0([a+4], 1); id == 0 does nothing. e = [engine+0x9b] slot 0x58(id); X = unaligned dword [[0x7003b8]+0x2c21]; p = 0x5a45c0(X, e): non-null gets *p += amount;
// q = 0x5a4610(X, id): non-null gets the unaligned dword at q + 2 increased by amount; null logs line 0x137 (fmt 0x6a6268) through the logger at 0x700390 (slot 0x20(0x6a622c, 0x137), then slot 0x30 of the result with ECX = its vtable
// and caller-popped (r, 0x6a6268)).
static void STDCALL fn55fca0(u8 *a) {
  u32 id = *ext_5003d0(*(u32 *)(a + 4), 0);
  u32 amount = *ext_5003d0(*(u32 *)(a + 4), 1);
  if (!id) return;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u32 e = (*(e1_t **)tab)[0x58 / 4](tab, id);
  u8 *H = G(u8 *, 0x7003b8);
  u32 *p = ext_5a45c0(rd32u(H + 0x2c21), e);
  if (p) *p += amount;
  H = G(u8 *, 0x7003b8);
  u8 *q = ext_5a4610(rd32u(H + 0x2c21), id);
  if (q) {
    wr32u(q + 2, rd32u(q + 2) + amount);
    return;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x6a622c, 0x137);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x30 / 4];
  asm volatile("push $0x6a6268\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}
PCREG(55fca0, fn55fca0);
