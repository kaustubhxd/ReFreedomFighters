// batch35102.cpp - cascade s5 batch 35102: 0x46eb70 (GUESS look up a second named sub-resource (sibling of 0x46ec20) of the entry [this+0xcb], logging failures).
#include "ff.h"

typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u32(THISCALL *g2_t)(void *, u32, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// log helper: lg = [0x700390]; r = lg slot 0x20(0x6887c4, line); r slot 0x30 called with ECX = r's vtable and the caller-popped args (r, fmt, name).
static inline void log_err(u32 line, u32 fmt, u32 name) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x6887c4, line);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x30 / 4];
  asm volatile("push %[name]\n\tpush %[fmt]\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [name] "r"(name), [fmt] "r"(fmt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}

// 0x46eb70, thiscall, no arguments, returns EAX. e = [engine+0x9b] slot 0x58(unaligned dword [this+0xcb]); null gives 0. name = [e+4] or the default 0x67c8e8. When the unaligned dword at [e+0xc]+0x23 lacks bit 0x100000
// line 0x885 is logged (fmt 0x688b50) and 0 returned; else r = e slot 0x25c(0x688bd0, 0): non-zero is returned, zero logs line 0x88a (fmt 0x688bd8) and returns 0.
static u32 THISCALL fn46eb70(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = (*(e1_t **)tab)[0x58 / 4](tab, rd32u(self + 0xcb));
  if (!e) return 0;
  u32 name = *(u32 *)(e + 4) ? *(u32 *)(e + 4) : 0x67c8e8;
  if (!(rd32u(*(u8 **)(e + 0xc) + 0x23) & 0x100000)) {
    log_err(0x885, 0x688b50, name);
    return 0;
  }
  u32 r = (*(g2_t **)e)[0x25c / 4](e, 0x688bd0, 0);
  if (r) return r;
  log_err(0x88a, 0x688bd8, name);
  return 0;
}
PCREG(46eb70, fn46eb70);
