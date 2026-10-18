#include "ff.h"

// w3g hand ports of small BLOCKED rows (the lifter only knows framed prologues).
typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
static inline u32 rd32(const u8 *p) { return *(const u32 *)p; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

extern "C" u32 THISCALL ext_5145e0(void *self) __asm__("ext_5145e0");
extern "C" u32 THISCALL ext_4a0d40(u32 one) __asm__("ext_4a0d40");
extern "C" u32 THISCALL ext_49f8a0(u32 self, u32 arg) __asm__("ext_49f8a0");

// 0x515cf0: jmp 0x5145e0 (thiscall thunk)
extern "C" u32 THISCALL fn_515cf0(void *self) { return ext_5145e0(self); }
PCREG(515cf0, fn_515cf0);

// 0x5d89f0: thiscall(this), ret not meaningful (void). H = table slot 0x58 (this+0x28); if present: esi = H slot 0x254(0), eax = H slot 0x274();
// this+0x34 = [[G+0x1aa3]+0x18] slot 0x108(esi, eax, 5).
extern "C" void THISCALL fn_5d89f0(u8 *self) {
  u8 *G = G(u8 *, 0x70039c);
  u8 *T = (u8 *)rd32(G + 0x9b);
  u8 *H = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32(self + 0x28));
  if (H == 0) return;
  u32 esi = (*(V1 *)(vt(H) + 0x254))(H, 0);
  u32 eax = (*(V0 *)(vt(H) + 0x274))(H);
  u8 *Y = (u8 *)rd32((u8 *)rd32(G + 0x1aa3) + 0x18);
  *(u32 *)(self + 0x34) = (*(V3 *)(vt(Y) + 0x108))(Y, esi, eax, 5);
}
PCREG(5d89f0, fn_5d89f0);

// 0x4a1270: thiscall(this) registers this in the list at this+0x102 (default: the inline list at this+0x7e, count word first, max 0x20 entries)
extern "C" void THISCALL fn_4a1270(u8 *self) {
  u32 *pp = (u32 *)(self + 0x102);
  if (*pp == 0) {
    u8 *c = (u8 *)rd32(self + 0x44);
    (*(V3 *)(vt(c) + 0x128))(c, *(u16 *)0x7002ac, (u32)pp, (u32)c);
    if (*pp == 0) {
      self[0x5e] = 1;
      *pp = (u32)(self + 0x7e);
    }
  }
  u32 *q = (u32 *)*pp;
  if (*q + 1 > 0x20) {
    u32 h = G(u32, 0x7003b0);
    if (h) ((void(*)())h)();
    else __builtin_trap();
  }
  q[*q + 1] = (u32)self;
  (*q)++;
  if (self[0x5e]) {
    u32 r = ext_4a0d40(1);
    ext_49f8a0(r, (u32)self);
  }
  if (self[0x63]) {
    u8 *c = (u8 *)rd32(self + 0x44);
    (*(V3 *)(vt(c) + 0x128))(c, *(u16 *)0x7002c8, 1, (u32)c);
  }
}
PCREG(4a1270, fn_4a1270);

extern "C" u32 THISCALL ext_45d5b0(void *self, void *other) __asm__("ext_45d5b0");
extern "C" u32 ext_41e290(u32 size) __asm__("ext_41e290");
typedef u32(THISCALL *V1b)(void *, u32);

static inline u8 *dup_cstr(const u8 *s) {
  const u8 *p = s;
  while (*p++) {}
  u32 n = (u32)(p - s);   // including the terminator
  u8 *d = (u8 *)ext_41e290(n);
  for (u32 i = 0; i < n; i++) d[i] = s[i];
  return d;
}

// 0x4559d0: thiscall(this, src) ret 4: copy constructor / assign. Calls the base copy 0x45d5b0(this, src) (tail jump to this slot 0x48), then asks src slot 0x1e0(0x2000e5);
// when it returns true copies the plain fields, duplicates the two C strings at +0x55 / +0x4d with 0x41e290 and copies the 0x80 byte block at +0x5d.
extern "C" void THISCALL fn_4559d0(u8 *self, u8 *src) {
  ext_45d5b0(self, src);
  u32 ok = (*(V1b *)(vt(src) + 0x1e0))(src, 0x2000e5);
  if ((ok & 0xff) == 0) return;
  *(u32 *)(self + 0x18) = rd32(src + 0x18);
  *(u32 *)(self + 0x1c) = rd32(src + 0x1c);
  *(u32 *)(self + 0x20) = rd32(src + 0x20);
  *(u32 *)(self + 0x24) = rd32(src + 0x24);
  *(u32 *)(self + 0x28) = rd32(src + 0x28);
  *(u32 *)(self + 0x30) = rd32(src + 0x30);
  *(u32 *)(self + 0x34) = rd32(src + 0x34);
  *(u32 *)(self + 0x38) = rd32(src + 0x38);
  *(u32 *)(self + 0x3c) = rd32(src + 0x3c);
  *(u32 *)(self + 0x40) = rd32(src + 0x40);
  *(u32 *)(self + 0x44) = rd32(src + 0x44);
  self[0x48] = src[0x48];
  u8 *s1 = (u8 *)rd32(src + 0x55);
  *(u32 *)(self + 0x55) = s1 ? (u32)dup_cstr(s1) : 0;
  *(u32 *)(self + 0x49) = rd32(src + 0x49);
  u8 *s2 = (u8 *)rd32(src + 0x4d);
  *(u32 *)(self + 0x4d) = s2 ? (u32)dup_cstr(s2) : 0;
  *(u32 *)(self + 0x51) = rd32(src + 0x51);
  *(u32 *)(self + 0x59) = rd32(src + 0x59);
  for (u32 i = 0; i < 0x20; i++) *(u32 *)(self + 0x5d + 4 * i) = rd32(src + 0x5d + 4 * i);
}
PCREG(4559d0, fn_4559d0);
