// batch34018.cpp - cascade tier E, batch 34018: 0x5518e0 (stdcall: look up an object and push three values through a setter chain), 0x56b980
// (broadcast a flag to five members), 0x5c90b0 (record an id and a 0/1.0 weight), 0x5d4b80 (resolve a name through two engine tables).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);          // thiscall ret 4, returns a setter object
extern "C" void THISCALL ext_5002f0(void *self, u32 v);         // thiscall ret 4
extern "C" void THISCALL ext_564a40(void *self, u32 flag);      // thiscall ret 4
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5518e0, stdcall(a, b, c) ret 0xc: ebx = a->slot0x18(b); when non-null: e = ebx->slot0x4c(); for i = 0..2: 0x5002f0(0x5003d0(e, i), c[i]); returns ebx.
static u32 STDCALL fn5518e0(u8 *a, u32 b, u32 *c) {
  u32 r = vcall<u32>(a, 0x18, b);
  if (r) {
    u32 e = vcall<u32>((void *)r, 0x4c);
    for (u32 i = 0; i < 3; i++) {
      u32 v = c[i];
      u32 s = ext_5003d0((void *)e, i);
      ext_5002f0((void *)s, v);
    }
  }
  return r;
}
PCREG(5518e0, fn5518e0);

// 0x56b980, thiscall(flag) ret 4: 0x564a40(this, flag); slot 0xbc(flag) of the members at +0xcda, +0xcde, +0xcc2, +0xcd2, +0xcd6 (unaligned pointers);
// when the low byte of flag is 0: o = this->slot0x84(); o->slot0x2ec([this+0xcae]).
static void THISCALL fn56b980(u8 *self, u32 flag) {
  ext_564a40(self, flag);
  vcall<void>((void *)rd32u(self + 0xcda), 0xbc, flag);
  vcall<void>((void *)rd32u(self + 0xcde), 0xbc, flag);
  vcall<void>((void *)rd32u(self + 0xcc2), 0xbc, flag);
  vcall<void>((void *)rd32u(self + 0xcd2), 0xbc, flag);
  vcall<void>((void *)rd32u(self + 0xcd6), 0xbc, flag);
  if ((u8)flag == 0) {
    void *o = vcall<void *>(self, 0x84);
    vcall<void>(o, 0x2ec, rd32u(self + 0xcae));
  }
}
PCREG(56b980, fn56b980);

// 0x5c90b0, thiscall(id) ret 4: obj = engine->table->slot0x58(id); [this+0x80] = id; [this+0x84] = 1.0f when obj && obj->slot0x1e0(0x200006) && [obj+0x54]
// && [[obj+0x54]+4] == 0, else 0.
static void THISCALL fn5c90b0(u8 *self, u32 id) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *obj = vcall<u8 *>(*(u8 **)(eng + 0x9b), 0x58, id);
  u32 w = 0;
  if (obj && vcall<bool>(obj, 0x1e0, 0x200006u)) {
    u8 *p = *(u8 **)(obj + 0x54);
    if (p && *(u32 *)(p + 4) == 0) w = 0x3f800000;
  }
  *(u32 *)(self + 0x80) = id;
  *(u32 *)(self + 0x84) = w;
}
PCREG(5c90b0, fn5c90b0);

// 0x5d4b80, thiscall, no args: id = [this+0x58]; zero -> [this+0x5c] = 0. Else s = table->slot0x58(id), the assert hook (int3 when null),
// x = s->slot0x2c4([table+0xadc], 0x4954454d), x->slot0x2c(), [this+0x5c] = table->slot0x4c(x).
static void THISCALL fn5d4b80(u8 *self) {
  u32 id = *(u32 *)(self + 0x58);
  if (!id) {
    *(u32 *)(self + 0x5c) = 0;
    return;
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tbl = *(u8 **)(eng + 0x9b);
  u8 *s = vcall<u8 *>(tbl, 0x58, id);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  eng = G(u8 *, 0x70039c);
  tbl = *(u8 **)(eng + 0x9b);
  u8 *x = vcall<u8 *>(s, 0x2c4, *(u32 *)(tbl + 0xadc), 0x4954454du);
  vcall<void>(x, 0x2c);
  eng = G(u8 *, 0x70039c);
  tbl = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x5c) = vcall<u32>(tbl, 0x4c, (u32)x);
}
PCREG(5d4b80, fn5d4b80);
