#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(void *self, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static inline void call_assert() {
  typedef u32 (*Hook)();
  Hook h = G(Hook, 0x7003b0);
  if (!h) __builtin_trap();
  h();
}

// 0x55b120: thiscall(this, a) ret 4: looks up a state record through 0x5003d0([a+4], 0) (byte +4 must be 0 or 1, else log and assert hook),
// refreshes the object of [a+8] through 0x5003d0 / 0x5002f0, then picks a template id at [this+0x1c]+0x78a or +0x78e (by the record's first
// dword), asks the engine table for its object (slot 0x58) and the object's slot 0x2e8 for a node whose kind (slot 0x330) 0..7 starts
// 0x5002f0 with 1, 11 and 12 with 2, 8..10 log through [0x700390]; eax is whatever the path leaves
u32 THISCALL fn_55b120(u8 *self, u8 *a) {
  u8 *rec = ext_5003d0(*(void **)(a + 4), 0);
  u8 dl = rec[4];
  if (dl != 0 && dl != 1) {
    void *L = G(void *, 0x700390);
    u8 *M = (u8 *)(*(V2 *)(*(u8 **)L + 0x20))(L, 0x69c8e0, 0x104);
    u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
    asm volatile(
        "pushl $0x69c938\n\t"
        "pushl $0x69c6b0\n\t"
        "pushl %[m]\n\t"
        "call *%%eax\n\t"
        "addl $12, %%esp"
        : "+a"(ra), "+c"(rc)
        : [m] "r"(M)
        : "edx", "memory", "cc");
    call_assert();
  }
  u32 first = *(u32 *)rec;
  u8 *p = ext_5003d0(*(void **)(a + 8), 0);
  ext_5002f0(p, 0);
  u8 *blk = *(u8 **)(self + 0x1c);
  u32 edx = first ? rd32u(blk + 0x78e) : rd32u(blk + 0x78a);
  if (edx == 0) return (u32)blk;
  u8 *eng = G(u8 *, 0x70039c);
  void *tab = *(void **)(eng + 0x9b);
  u8 *A = (u8 *)(*(V1 *)(*(u8 **)tab + 0x58))(tab, edx);
  u8 *node = (u8 *)(*(V0 *)(*(u8 **)A + 0x2e8))(A);
  if (!node) return 0;
  u32 k = (*(V0 *)(*(u8 **)node + 0x330))(node);
  if (k > 0xc) return k;
  static const u8 map[13] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2};
  switch (map[k]) {
    case 0:
    case 2: {
      u8 *q = ext_5003d0(*(void **)(a + 8), 0);
      return ext_5002f0(q, map[k] == 0 ? 1 : 2);
    }
    default: {
      void *L = G(void *, 0x700390);
      u8 *M = (u8 *)(*(V2 *)(*(u8 **)L + 0x20))(L, 0x6a5eb0, 0x6fd);
      u32 name = *(u32 *)(node + 4);
      if (!name) name = 0x67c8e8;
      u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
      asm volatile(
          "pushl %[n]\n\t"
          "pushl $0x6a6048\n\t"
          "pushl %[m]\n\t"
          "call *%%eax\n\t"
          "addl $12, %%esp"
          : "+a"(ra), "+c"(rc)
          : [n] "r"(name), [m] "r"(M)
          : "edx", "memory", "cc");
      return ra;
    }
  }
}
PCREG(55b120, fn_55b120);
