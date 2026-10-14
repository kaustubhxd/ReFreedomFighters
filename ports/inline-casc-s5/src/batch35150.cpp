// batch35150.cpp - cascade s5 batch 35150: 0x490120 (GUESS find a registered entry by name and kind, logging when missing).
#include "ff.h"

typedef int (*stricmp_t)(const char *, const char *);
typedef u8 *(THISCALL *l2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x490120, stdcall(name, kind) ret 8. Walks the list at [0x7003bc] (next at +0x14); a node counts when [node+4] == kind and _stricmp([node], name) == 0 (IAT 0x676414), or, when kind == 1,
// also _stricmp(unaligned dword [node+0x1f], name) == 0. Returns the node. Not found: the logger at 0x700390 slot 0x20(0x68d798, 0xf1c) returns r; slot 0x30(r, 0x68df7c, name) is
// called with ECX = the vtable and caller-popped; returns 0.
static u8 *STDCALL fn490120(const char *name, u32 kind) {
  u8 *n = G(u8 *, 0x7003bc);
  while (n) {
    if (*(u32 *)(n + 4) == kind) {
      if (G(stricmp_t, 0x676414)(*(const char **)n, name) == 0) return n;
      if (kind == 1 && G(stricmp_t, 0x676414)((const char *)rd32u(n + 0x1f), name) == 0) return n;
    }
    n = *(u8 **)(n + 0x14);
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(l2_t **)lg)[0x20 / 4](lg, 0x68d798, 0xf1c);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x30 / 4];
  asm volatile("push %[nm]\n\tpush $0x68df7c\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [nm] "r"(name), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  return 0;
}
PCREG(490120, fn490120);
