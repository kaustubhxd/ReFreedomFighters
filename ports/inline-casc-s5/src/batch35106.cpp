// batch35106.cpp - cascade s5 batch 35106: 0x45bcf0 (GUESS resolve every slot's resource name and cache the handle, logging unknown ones).
#include "ff.h"

typedef u8 *(THISCALL *g2_t)(void *, u32, u32);
typedef u32(THISCALL *h2_t)(void *, u32, u32);
typedef u32(THISCALL *h1_t)(void *, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x45bcf0, thiscall, no arguments. For i < [this+0x20] (the loop ends the function early when a lookup fails): X = unaligned dword [engine+0x1aa3], O = [X+0x18]; b = O slot 0x60([[this+8]+0x6c], i), null returns;
// q = O slot 0xe4(b, 0x678d04); when q != 0: X slot 0x80(q) non-zero stores [[this+0x254] + 4 * i] = b, zero logs line 0x20a (fmt 0x684c24) through the logger at 0x700390 (slot 0x20(0x684bf4, 0x20a), then slot 0x2c of the result
// with ECX = its vtable and caller-popped (r, 0x684c24)).
static void THISCALL fn45bcf0(u8 *self) {
  u32 n = *(u32 *)(self + 0x20);
  if (n == 0) return;
  u32 i = 0;
  do {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *X = (u8 *)rd32u(eng + 0x1aa3);
    u8 *O = *(u8 **)(X + 0x18);
    u32 b = (u32)(*(g2_t **)O)[0x60 / 4](O, *(u32 *)(*(u8 **)(self + 8) + 0x6c), i);
    if (!b) return;
    eng = G(u8 *, 0x70039c);
    X = (u8 *)rd32u(eng + 0x1aa3);
    O = *(u8 **)(X + 0x18);
    u32 q = (*(h2_t **)O)[0xe4 / 4](O, b, 0x678d04);
    if (q) {
      eng = G(u8 *, 0x70039c);
      X = (u8 *)rd32u(eng + 0x1aa3);
      if ((*(h1_t **)X)[0x80 / 4](X, q)) {
        ((u32 *)*(u32 *)(self + 0x254))[i] = b;
      } else {
        u8 *lg = G(u8 *, 0x700390);
        u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x684bf4, 0x20a);
        u32 vt = *(u32 *)r;
        u32 slot = ((u32 *)vt)[0x2c / 4];
        asm volatile("push $0x684c24\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
      }
    }
    i++;
  } while (i != *(u32 *)(self + 0x20));
}
PCREG(45bcf0, fn45bcf0);
