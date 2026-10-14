// batch32092.cpp - cascade h2 (): eight tier C wrappers (twelfth batch).
#include "ff.h"

extern "C" u8 *THISCALL ext_4d1cf0(u8 *self, u32 a);   // thiscall ret 4
extern "C" u32 THISCALL ext_514480(u8 *self, u32 a);   // thiscall ret 4
extern "C" void THISCALL ext_4dcbb0(u8 *self, u32 a);  // thiscall ret 4
typedef u32 (*hook_t)();
typedef u32 (*cd2_t)(u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x5f4f70, thiscall no args: n = [this+8]; n == 0 -> tail jump to the assert hook (int3 when null); else n--, [this+8] = n; e = [this] + n*8; byte [e+4] == 4 ->
// slot 0x28 of the object [e]; byte [e+4] = 0.
static u32 THISCALL fn5f4f70(u8 *self) {
  u32 n = *(u32 *)(self + 8);
  if (!n) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    return h();
  }
  n--;
  *(u32 *)(self + 8) = n;
  u8 *e = *(u8 **)self + n * 8;
  if (e[4] == 4) vcall<void>(*(void **)e, 0x28);
  e[4] = 0;
  return 0;
}
PCREG(5f4f70, fn5f4f70);

// 0x63cde0, thiscall no args: for each node p of the list from [this+8] (next = [p+8], read before the call; stop at 0 or when next == [this+8]):
// slot 0x34 of this with p; then [this+0xc] = [this+8] = 0.
static void THISCALL fn63cde0(u8 *self) {
  u8 *p = *(u8 **)(self + 8);
  if (p) {
    while (true) {
      u8 *nx = *(u8 **)(p + 8);
      vcall<void>(self, 0x34, (u32)p);
      if (nx == *(u8 **)(self + 8)) break;
      if (!nx) break;
      p = nx;
    }
  }
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 8) = 0;
}
PCREG(63cde0, fn63cde0);

// 0x45fa30, thiscall(a, b, c) ret 0xc: slot 0x168 of this with (a, b); returns slot 0x124 of this with (0x20, b, word a, c).
static u32 THISCALL fn45fa30(void *self, u32 a, u32 b, u32 c) {
  vcall<void>(self, 0x168, a, b);
  return vcall<u32>(self, 0x124, 0x20u, b, a & 0xffffu, c);
}
PCREG(45fa30, fn45fa30);

// 0x47fba0, thiscall(o) ret 4, bool: [this+4] = o; slot 8 of o returns true (al) -> true; else slot 0x14 of this and false.
static bool THISCALL fn47fba0(u8 *self, void *o) {
  *(void **)(self + 4) = o;
  if (vcall<u8>(o, 8)) return true;
  vcall<void>(self, 0x14);
  return false;
}
PCREG(47fba0, fn47fba0);

// 0x4d1cb0, thiscall(a) ret 4: r = 0x4d1cf0(this, a); r != 0 -> [r+0xc]; else logs through [0x700390] (slot 0x20 with (0x695fec, 0x222), then its slot 0x2c cdecl with (o, 0x6960e8)) and returns 0.
static u32 THISCALL fn4d1cb0(u8 *self, u32 a) {
  u8 *r = ext_4d1cf0(self, a);
  if (r) return *(u32 *)(r + 0xc);
  void *g = G(void *, 0x700390);
  u8 *o = vcall<u8 *>(g, 0x20, 0x695fecu, 0x222u);
  (*(cd2_t *)(*(u8 **)o + 0x2c))((u32)o, 0x6960e8);
  return 0;
}
PCREG(4d1cb0, fn4d1cb0);

// 0x51fa10, thiscall(a) ret 4: slot 0x310 of this with a; [this+0x1654] = (al ? a : 0); returns 0x514480(this+0x16e5, [this+0x1654]).
static u32 THISCALL fn51fa10(u8 *self, u32 a) {
  u8 ok = vcall<u8>(self, 0x310, a);
  *(u32 *)(self + 0x1654) = ok ? a : 0;
  return ext_514480(self + 0x16e5, *(u32 *)(self + 0x1654));
}
PCREG(51fa10, fn51fa10);

// 0x591080, thiscall no args: s = engine table slot 0x58 with unaligned [this+0x842]; 0x4dcbb0([s+8], 0); slot 0x294 of this with ([s+8], 0xc); [this+0x842] = 0; returns s.
static u8 *THISCALL fn591080(u8 *self) {
  u8 *s = vcall<u8 *>(engTable(), 0x58, rd32(self + 0x842));
  ext_4dcbb0(*(u8 **)(s + 8), 0);
  vcall<void>(self, 0x294, *(u32 *)(s + 8), 0xcu);
  self[0x842] = self[0x843] = self[0x844] = self[0x845] = 0;
  return s;
}
PCREG(591080, fn591080);

// 0x5c5cc0, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; slot 0x40 of o with this+0x48; slot 0x48 of o with this+0x4c.
static bool THISCALL fn5c5cc0(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(o, 0x40, (u32)(self + 0x48));
  vcall<void>(o, 0x48, (u32)(self + 0x4c));
  return true;
}
PCREG(5c5cc0, fn5c5cc0);
