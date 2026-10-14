// batch34022.cpp - cascade tier E, batch 34022: 0x4c8760 (set or clear flag 0x10 on every object of a list), 0x4d2120 (replace an entry's buffer),
// 0x4db930 (visit a node list).
#include "ff.h"

extern "C" u32 THISCALL ext_4d1cf0(void *self, u32 a);          // thiscall ret 4: finds the entry
extern "C" u32 ext_41e290(u32 size);                            // cdecl alloc
extern "C" void ext_634d22(void *dst, const void *src, u32 n);  // cdecl memcpy
extern "C" void ext_634273(void *p, u32 n);                     // cdecl free(ptr, size)
extern "C" void THISCALL ext_4db860(void *self, u32 a);         // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4c8760, no arguments: walk the engine list (+0x190f, slot 0xb4(i) gives the i-th id, 0 ends); for each id fetch the object from the engine table
// (slot 0x58). The first object decides the mode: set when its flag 0x10 (dword +0x48) is clear, clear when it is set; every object gets the same.
static void fn4c8760() {
  u32 i = 0;
  u8 mode = 1;
  u8 *eng = G(u8 *, 0x70039c);
  u32 id = vcall<u32>((void *)rd32u(eng + 0x190f), 0xb4, i);
  while (id) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *obj = vcall<u8 *>(tbl, 0x58, id);
    if (i == 0) mode = (*(u8 *)(obj + 0x48) & 0x10) ? 0 : 1;
    if (obj) {
      if (mode) *(u32 *)(obj + 0x48) |= 0x10;
      else *(u32 *)(obj + 0x48) &= ~0x10u;
    }
    i++;
    id = vcall<u32>((void *)rd32u(G(u8 *, 0x70039c) + 0x190f), 0xb4, i);
  }
}
PCREG(4c8760, fn4c8760);

// 0x4d2120, thiscall(a, b, c) ret 0xc: e = 0x4d1cf0(this, a); when found: old = [e+0xc]; [e+0xc] = copy of the c bytes at b (alloc 0x41e290, memcpy 0x634d22);
// [e+0x10] = c; free(old, 0). Otherwise log through the object at 0x700390 (slot 0x20(0x695fec, 0x205) -> slot 0x2c(.., 0x6960a8), caller-popped).
static void THISCALL fn4d2120(u8 *self, u32 a, u8 *b, u32 c) {
  u8 *e = (u8 *)ext_4d1cf0(self, a);
  if (e) {
    u8 *old = *(u8 **)(e + 0xc);
    u8 *p = (u8 *)ext_41e290(c);
    *(u8 **)(e + 0xc) = p;
    ext_634d22(p, b, c);
    *(u32 *)(e + 0x10) = c;
    ext_634273(old, 0);
    return;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x695fecu, 0x205u);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push $0x6960a8\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}
PCREG(4d2120, fn4d2120);

// 0x4db930, thiscall(a) ret 4: s = [this+0x54]; flags = s ? dword [[s+0xc]+0x23] : 0x200002. When bit 0x100000 is set: for node = [s+8]; node;
// node = next (s->slot0x50(&node)): 0x4db860(node, a). Otherwise just 0x4db860(this, a).
static void THISCALL fn4db930(u8 *self, u32 a) {
  u8 *s = *(u8 **)(self + 0x54);
  u32 flags = s ? rd32u(*(u8 **)(s + 0xc) + 0x23) : 0x200002;
  if (flags & 0x100000) {
    u32 node = *(u32 *)(s + 8);
    if (!node) return;
    do {
      ext_4db860((void *)node, a);
      vcall<void>(s, 0x50, (u32)&node);
    } while (node);
  } else {
    ext_4db860(self, a);
  }
}
PCREG(4db930, fn4db930);
