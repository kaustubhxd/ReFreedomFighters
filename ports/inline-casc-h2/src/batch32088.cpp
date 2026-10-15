// batch32088.cpp - cascade h2 (Sonnet): eight tier C wrappers (eighth batch).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *self);            // thiscall, plain ret
extern "C" u32 THISCALL ext_4e5e40(u8 *self);            // thiscall, plain ret (result in AX)
extern "C" void THISCALL ext_537ed0(u8 *self, u8 *p);    // thiscall ret 4
typedef u32 (*hook_t)();
typedef u32 (*cd3_t)(u32, u32, u32);

static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x486d90, thiscall(o) ret 4: v = o; slot 0x40 of o with &v (out-param, may rewrite v); [this+8] = slot 0x58 of the engine table with v.
static void THISCALL fn486d90(u8 *self, void *o) {
  u32 v = (u32)o;
  vcall<void>(o, 0x40, (u32)&v);
  *(u32 *)(self + 8) = vcall<u32>(engTable(), 0x58, v);
}
PCREG(486d90, fn486d90);

// 0x49eed0, thiscall(a) ret 4: v = 0x4e5e60(a); [this+0x48] = v; slot 0x58 of the engine table with v (result unused); word [this+0x4c] = AX of 0x4e5e40(a).
static void THISCALL fn49eed0(u8 *self, u8 *a) {
  u32 v = ext_4e5e60(a);
  *(u32 *)(self + 0x48) = v;
  vcall<u32>(engTable(), 0x58, v);
  u32 w = ext_4e5e40(a);
  self[0x4c] = w;
  self[0x4d] = w >> 8;
}
PCREG(49eed0, fn49eed0);

// 0x533b50, thiscall(p) ret 4, returns true: slot 0xc of p with 0x14; 0x537ed0(this, p).
static bool THISCALL fn533b50(u8 *self, void *p) {
  vcall<void>(p, 0xc, 0x14u);
  ext_537ed0(self, (u8 *)p);
  return true;
}
PCREG(533b50, fn533b50);

// 0x54dca0, thiscall(on) ret 4: on != 0: byte [this+0x79] == 0 -> set it, slot 0x5c of this; on == 0: byte [this+0x79] != 0 -> clear it, slot 0x58 of this.
static void THISCALL fn54dca0(u8 *self, u32 on) {
  if (on) {
    if (self[0x79]) return;
    self[0x79] = 1;
    vcall<void>(self, 0x5c);
  } else {
    if (!self[0x79]) return;
    self[0x79] = 0;
    vcall<void>(self, 0x58);
  }
}
PCREG(54dca0, fn54dca0);

// 0x5c94f0, thiscall no args: o = slot 0x58 of the engine table with [this+0x70]; r = slot 0x2f4 of o; returns slot 0x4c of the engine table with r.
static u32 THISCALL fn5c94f0(u8 *self) {
  void *o = vcall<void *>(engTable(), 0x58, *(u32 *)(self + 0x70));
  u32 r = vcall<u32>(o, 0x2f4);
  return vcall<u32>(engTable(), 0x4c, r);
}
PCREG(5c94f0, fn5c94f0);

// 0x603eb0, cdecl no args: r = slot 0x20 of [0x700390] with (0x6b9750, 0x26); slot 0x2c of r called cdecl with (r, 0x69c6b0, 0x6b97ac); assert hook (int3 when null); returns 0.
static u32 fn603eb0() {
  void *g = G(void *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x6b9750u, 0x26u);
  (*(cd3_t *)(*(u8 **)r + 0x2c))((u32)r, 0x69c6b0, 0x6b97ac);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(603eb0, fn603eb0);

// 0x65c500, thiscall(a, ignored) ret 8: c = [a+8]; c != 0 and d = [c+0x18] != 0 -> slot 4 of d with (a, [this+0x10051]) (unaligned).
static void THISCALL fn65c500(u8 *self, u8 *a, u32) {
  u8 *c = *(u8 **)(a + 8);
  if (!c) return;
  void *d = *(void **)(c + 0x18);
  if (!d) return;
  u32 f = self[0x10051] | (self[0x10052] << 8) | (self[0x10053] << 16) | ((u32)self[0x10054] << 24);
  vcall<void>(d, 4, (u32)a, f);
}
PCREG(65c500, fn65c500);

// 0x462f50, thiscall(i) ret 4: i < 0 (signed) -> 0; else slot 0x2cc of this + i*0x30 + 0x1c.
static u32 THISCALL fn462f50(void *self, int i) {
  if (i < 0) return 0;
  u32 r = vcall<u32>(self, 0x2cc);
  return r + (u32)i * 0x30 + 0x1c;
}
PCREG(462f50, fn462f50);
