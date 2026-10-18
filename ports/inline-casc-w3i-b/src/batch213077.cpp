#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V5)(void *, u32, float, float, float, float);

extern "C" u8 *THISCALL ext_5003d0(void *tab, u32 k);
extern "C" u32 THISCALL ext_5002f0(void *p, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// type check of a table entry: byte [p+4] must be 0 or 2, else it logs an error line (cdecl-style slot 0x2c of the object returned by the [0x700390] manager's slot 0x20)
// and calls the assert hook [0x7003b0] (int3 when null)
static inline void check_entry(u8 *p) {
  u8 t = p[4];
  if (t == 0 || t == 2) return;
  void *L = G(void *, 0x700390);
  u8 *M = (u8 *)(*(V2 *)(vt(L) + 0x20))(L, 0x69c8e0, 0x104);
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  asm volatile(
      "pushl %[f]\n\t"
      "pushl %[g]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $12, %%esp"
      : "+a"(ra), "+c"(rc)
      : [f] "r"(0x69c938), [g] "r"(0x69c6b0), [m] "r"(M)
      : "edx", "memory", "cc");
  typedef u32 (*Hook)();
  Hook h = G(Hook, 0x7003b0);
  if (!h) __builtin_trap();
  h();
}

// 0x504c90: thiscall(rec) ret 4 -> result of 0x5002f0: reads the five values 4, 3, 2, 1 (floats whose entries must have type 0 / 2, checked) and 0 (a dword offset) of the table rec->[4]
// through 0x5003d0, calls this slot 0x60(offset + [[[0x70039c] + 0x9b] + 0x44], f1, f2, f3, f4) and passes its result to 0x5002f0 on the entry 0 of table rec->[8].
extern "C" u32 THISCALL fn_504c90(u8 *self, u8 *rec) {
  void *tab = (void *)rd32u(rec + 4);
  u8 *p4 = ext_5003d0(tab, 4);
  check_entry(p4);
  u32 f4 = rd32u(p4);
  u8 *p3 = ext_5003d0((void *)rd32u(rec + 4), 3);
  check_entry(p3);
  u32 f3 = rd32u(p3);
  u8 *p2 = ext_5003d0((void *)rd32u(rec + 4), 2);
  check_entry(p2);
  u32 f2 = rd32u(p2);
  u8 *p1 = ext_5003d0((void *)rd32u(rec + 4), 1);
  check_entry(p1);
  u32 f1 = rd32u(p1);
  u8 *p0 = ext_5003d0((void *)rd32u(rec + 4), 0);
  u8 *g = G(u8 *, 0x70039c);
  u32 sum = rd32u((u8 *)rd32u(g + 0x9b) + 0x44) + rd32u(p0);
  u32 r = (*(V5 *)(vt(self) + 0x60))(self, sum, bitsf(f1), bitsf(f2), bitsf(f3), bitsf(f4));
  u8 *pe = ext_5003d0((void *)rd32u(rec + 8), 0);
  return ext_5002f0(pe, r);
}
PCREG(504c90, fn_504c90);
