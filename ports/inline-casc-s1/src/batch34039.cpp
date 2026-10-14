// batch34039.cpp - cascade tier E, batch 34039: 0x4f8d80 (create and prime an object, log it), 0x507240 (resolve an entry and hand it to the owner chain),
// 0x509aa0 (hide every object of a list).
#include "ff.h"

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);   // thiscall ret 8
extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);           // thiscall ret 4: entry lookup
extern "C" u32 THISCALL ext_4dafb0(void *self);                  // thiscall, plain ret
extern "C" void THISCALL ext_4dc9c0(void *self, u32 a);          // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4f8d80, thiscall(unused) ret 4, returns the new object: o = this->slot0x294(0x69b6a0, 0x697898, 0, 1); [this+0x1cf] = 0 (unaligned); o->slot0x154(); 0x4dc630([o+8], 0x800000, 0);
// o->slot0x158(); o->slot0xbc(0); log through the object at 0x700390 (slot 0x20(0x69b644, 0xf7), then its slot 0x30 with (r, 0x69b6a8), caller-popped); o->slot0x23c(2, 0xff).
static u32 THISCALL fn4f8d80(u8 *self, u32 unused) {
  (void)unused;
  u8 *o = vcall<u8 *>(self, 0x294, 0x69b6a0u, 0x697898u, 0u, 1u);
  wr32u(self + 0x1cf, 0);
  vcall<void>(o, 0x154);
  ext_4dc630(*(u8 **)(o + 8), 0x800000u, 0u);
  vcall<void>(o, 0x158);
  vcall<void>(o, 0xbc, 0u);
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x69b644u, 0xf7u);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x30 / 4];
  asm volatile("push $0x69b6a8\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  vcall<void>(o, 0x23c, 2u, 0xffu);
  return (u32)o;
}
PCREG(4f8d80, fn4f8d80);

// 0x507240, thiscall(a) ret 4: id = first dword of the entry for [a+4]; o = engine table slot 0x58(id); when o and o->slot0x1e0(0x100021): n = [[this+0x18]+8]; when bit 0x40000000
// of [n+0x3c] is set n = 0x4dafb0(n); 0x4dc9c0(n, o); then the object at [[engine table]+0x5d31] (unaligned) gets slot 0(n).
static void THISCALL fn507240(u8 *self, u8 *a) {
  u32 *e = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x58, *e);
  if (!o) return;
  if (!vcall<bool>(o, 0x1e0, 0x100021u)) return;
  u8 *n = *(u8 **)(*(u8 **)(self + 0x18) + 8);
  if (*(u32 *)(n + 0x3c) & 0x40000000) n = (u8 *)ext_4dafb0(n);
  ext_4dc9c0(n, (u32)o);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *sink = (u8 *)rd32u(tbl + 0x5d31);
  vcall<void>(sink, 0, (u32)n);
}
PCREG(507240, fn507240);

// 0x509aa0, thiscall(unused) ret 4: l = [[this+0xc]+0x18] (return when null): it = {}; l->slot0x4c(&it); id = l->slot0x5c(&it); while it[0]: o = engine table slot 0x58(id);
// o->slot0xbc(1) when found; id = [[this+0xc]+0x18]->slot0x5c(&it).
static void THISCALL fn509aa0(u8 *self, u32 unused) {
  (void)unused;
  u32 it[3];
  u8 *l = *(u8 **)(*(u8 **)(self + 0xc) + 0x18);
  if (!l) return;
  vcall<void>(l, 0x4c, (u32)it);
  u32 id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, id);
    if (o) vcall<void>(o, 0xbc, 1u);
    id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(509aa0, fn509aa0);
