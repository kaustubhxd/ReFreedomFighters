// f15b005.cpp - fresh slice 15, batch 5 (2026-10-12). SEH frames (fs:[0] push/restore) are not reproduced: the
// functions have no code that can throw between the push and the restore that matters to the result (GUESS for EH).
// 0x449670 ZOMNILIGHT::SetDiffuseColor(c) / 0x4497b0 ZOMNILIGHT::SetFarRange(f): this slot 0x238; R = [[0x70039c]+0x1aa3]+0x18;
//          R slot 0x80(id, &d) reads a 0x24-byte light record, d+0x10 = c (or d+0x1c = f), R slot 0x98(id, &d) writes it.
// 0x6482f0 ZDrawArray<ZGateViewEntry>::Add: as 0x648430 but allocates inline: entry = blk + 0x10 + 0x34 * word blk+2,
//          free list next = word entry, byte blk+0 += 1 (grow 0x648cd0).
// 0x4cc7f0 stristr(hay, needle) (fastcall): first p in hay with _memicmp(p, needle, strlen(needle)) == 0, else 0.
// 0x626470 (expat isPublicId)(enc, ptr, end, next): bytes ptr+1 .. end-2 by enc type table enc+0x4c.
// 0x4bf370 ZSoundExtend::CopyData(src): copy +0x48 .. +0x80 from src.
// 0x51a9f0: ctor(a): 0x5193c0(this, a), vtable 0x69f364, +0x18 = a, [0x701730] == 0 -> 0x51ace0(this).
// 0x569c30 CLinkMenu::Command(id, p): RegisterZMsg(0x6a6ffc, 0, 0x6a771c, 0x20e) == (u16)id -> +0x1b4 = *p, return 1
//          (the "< 0 && > 6 -> -1" clamp can never fire); else CFileWindow::Command.
// 0x4970f0 ZGeomBuffer::FreeGeom(g): pool free 0x4ce1c0(off, size), log [0x70038c] slot 0x30, slot 0x50(g, size, 0x7f0000).
// 0x561b70 / 0x49fcf0 / 0x4a3530 / 0x4b8430: factories: o = [[0x70039c]+0x9b]+8 slot 0x44(ecx) (allocator, takes the
//          incoming ECX as its argument); o -> base ctor + vtable (0x6a63bc; 0x68f494 / 0x68fa38 / 0x68f24c with +4 |= 0x20, +0x44 = 0).
// 0x4cfc70(item): s = (this+0x1cc) slot 8(key = item+8, 0) or new 0x4d0630 + insert slot 0; push item at the head of s+0x11.
// 0x5a5730(i, kind): kind 2 -> arrays +0x54e/+0x552, kind 3 -> +0x540/+0x544: entry [i-1] slot 0x28 on both.
// 0x4b86b0: base dtor body: vtable 0x69289c, delete +0x4c (slot 0(1)), +0x44 = +0x30 = 0, vtable 0x686874, db slot 0x34(this).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_648cd0[], ext_5193c0[], ext_51ace0[], ext_561cb0[], ext_4ce1c0[], ext_561020[], ext_469870[],
    ext_4d0630[];

static inline void *light_db() { return AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x1aa3), 0x18); }

extern "C" void THISCALL f15_449670(void *self, u32 c) {
  u8 d[0x24];
  vcall<void>(self, 0x238);
  vcall<void>(light_db(), 0x80, AT(u32, AT(u8 *, self, 8), 0x6c), (void *)d);
  AT(u32, d, 0x10) = c;
  vcall<void>(light_db(), 0x98, AT(u32, AT(u8 *, self, 8), 0x6c), (void *)d);
}

extern "C" void THISCALL f15_4497b0(void *self, float f) {
  u8 d[0x24];
  vcall<void>(self, 0x238);
  vcall<void>(light_db(), 0x80, AT(u32, AT(u8 *, self, 8), 0x6c), (void *)d);
  AT(float, d, 0x1c) = f;
  vcall<void>(light_db(), 0x98, AT(u32, AT(u8 *, self, 8), 0x6c), (void *)d);
}

typedef u32(THISCALL *Get0)(void *);
extern "C" u8 *THISCALL f15_6482f0(void *self) {
  u8 *c = AT(u8 *, self, 8), *blk = 0;
  if (c) {
    do {
      u8 *e = AT(u8 *, self, 8);
      if (*(u16 *)(e + 2) != 0xffff) { blk = e; break; }
      e = AT(u8 *, e, 8);
      AT(u8 *, self, 8) = e;
      if (c == e || !e) break;
    } while (1);
  }
  if (!blk) {
    if (!(u8)((Get0)X(648cd0))(self)) return 0;
    blk = AT(u8 *, self, 8);
  }
  AT(u32, self, 0xc)++;
  u16 k = *(u16 *)(blk + 2);
  if (k == 0xffff) return 0;
  u8 *p = blk + 0x10 + k * 0x34;
  blk[0]++;
  *(u16 *)(blk + 2) = *(u16 *)p;
  return p;
}

typedef s32 (*Memicmp)(const void *, const void *, u32);
extern "C" const char *FASTCALL f15_4cc7f0(const char *hay, const char *needle) {
  const char *e = needle;
  while (*e) e++;
  s32 nl = (s32)(e - needle);
  const char *h = hay;
  while (*h) h++;
  s32 hl = (s32)(h - hay);
  if (hl < nl) return 0;
  const char *last = hay + (hl - nl);
  for (const char *p = hay; p <= last; p++)
    if ((*(Memicmp *)0x67640c)(p, needle, (u32)nl) == 0) return p;
  return 0;
}

extern "C" u32 f15_626470(const u8 *enc, const u8 *ptr, const u8 *end, const u8 **next) {
  static const u8 tab[27] = {0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 3, 1, 2, 0, 0, 0, 2, 0, 3, 3, 0, 0, 0, 0, 0, 0};
  ptr++;
  end--;
  for (; ptr != end; ptr++) {
    u8 ch = *ptr;
    u32 t = (u32)enc[0x4c + ch] - 9;
    u32 k = t > 0x1a ? 3 : tab[t];
    if (k == 0) continue;
    if (k == 1) {
      if (ch != 9) continue;
      *next = ptr;
      return 0;
    }
    if (k == 2 && !(ch & 0x80)) continue;
    if (ch == 0x24 || ch == 0x40) continue;
    *next = ptr;
    return 0;
  }
  return 1;
}

extern "C" void THISCALL f15_4bf370(void *self, void *src) {
  for (u32 o = 0x48; o < 0x68; o += 4) AT(u32, self, o) = AT(u32, src, o);
  AT(u8, self, 0x68) = AT(u8, src, 0x68);
  for (u32 o = 0x69; o < 0x81; o += 4) AT(u32, self, o) = AT(u32, src, o);
}

extern "C" void *THISCALL f15_51a9f0(void *self, u32 a) {
  ((void(THISCALL *)(void *, u32))X(5193c0))(self, a);
  AT(u32, self, 0) = 0x69f364u;
  AT(u32, self, 0x18) = a;
  if (G(u32, 0x701730) == 0) ((void(THISCALL *)(void *))X(51ace0))(self);
  return self;
}

extern "C" u32 THISCALL f15_569c30(void *self, u32 id, s32 *p) {
  void *db = AT(void *, G(u8 *, 0x70039c), 0x9b);
  u32 r = vcall<u32>(db, 0x114, 0x6a6ffcu, 0u, 0x6a771cu, 0x20eu);
  if ((u16)id == (u16)r) {
    AT(s32, self, 0x1b4) = *p;
    return 1;
  }
  return ((u32(THISCALL *)(void *, u32, s32 *))X(561cb0))(self, id, p);
}

extern "C" void THISCALL f15_4970f0(void *self, u8 *g) {
  u8 *pool = AT(u8 *, self, 0x18);
  u32 sz = (AT(u32, AT(u8 *, g, 0xc), 0x18) + 0xf) & ~0xfu;
  ((void(THISCALL *)(void *, u32, u32))X(4ce1c0))(AT(void *, pool, 0), (u32)(g - AT(u8 *, pool, 4)), (sz + 0xf) & ~0xfu);
  void *L = G(void *, 0x70038c);
  if (L) {
    vcall<void>(L, 0x30, 0x68e350u, (u32)(g - AT(u8 *, AT(u8 *, self, 0x18), 4)), sz);
    L = G(void *, 0x70038c);
  }
  vcall<void>(L, 0x50, (void *)g, sz, 0x7f0000u);
}

static inline void *alloc_obj(u32 ecx) {
  void *a = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 8);
  return vcall<void *>(a, 0x44, ecx);
}

extern "C" void *THISCALL f15_561b70(u32 ecx) {
  void *o = alloc_obj(ecx);
  if (o) {
    ((void(THISCALL *)(void *))X(561020))(o);
    AT(u32, o, 0) = 0x6a63bcu;
  }
  return o;
}

static inline void *make469(u32 ecx, u32 vt) {
  void *o = alloc_obj(ecx);
  if (o) {
    ((void(THISCALL *)(void *))X(469870))(o);
    AT(u32, o, 4) |= 0x20;
    AT(u32, o, 0x44) = 0;
    AT(u32, o, 0) = vt;
  }
  return o;
}
extern "C" void *THISCALL f15_49fcf0(u32 ecx) { return make469(ecx, 0x68f494u); }
extern "C" void *THISCALL f15_4a3530(u32 ecx) { return make469(ecx, 0x68fa38u); }
extern "C" void *THISCALL f15_4b8430(u32 ecx) { return make469(ecx, 0x68f24cu); }

extern "C" u8 *THISCALL f15_4cfc70(void *self, u8 *item) {
  void *H = (u8 *)self + 0x1cc;
  u32 key = AT(u32, item, 8);
  u8 *s = vcall<u8 *>(H, 8, key, 0u);
  if (!s) {
    s = ((u8 * (THISCALL *)(void *)) X(4d0630))(self);
    AT(u32, s, 0xc) = key;
    AT(u32, s, 0x11) = 0;
    vcall<void>(H, 0, (void *)s);
  }
  AT(u32, item, 0x10) = 0;
  AT(u32, item, 0x14) = AT(u32, s, 0x11);
  AT(u8 *, s, 0x11) = item;
  u8 *nx = AT(u8 *, item, 0x14);
  if (nx) AT(u8 *, nx, 0x10) = item;
  return s;
}

extern "C" void THISCALL f15_5a5730(void *self, u32 i, u32 kind) {
  u32 a, b;
  if (kind == 2) { a = 0x54e; b = 0x552; }
  else if (kind == 3) { a = 0x540; b = 0x544; }
  else return;
  vcall<void>(AT(void *, AT(u8 *, self, a), i * 4 - 4), 0x28);
  vcall<void>(AT(void *, AT(u8 *, self, b), i * 4 - 4), 0x28);
}

extern "C" void THISCALL f15_4b86b0(void *self) {
  AT(u32, self, 0) = 0x69289cu;
  void *o = AT(void *, self, 0x4c);
  if (o) vcall<void>(o, 0, 1u);
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0x30) = 0;
  AT(u32, self, 0) = 0x686874u;
  vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x34, self);
}

PCREG(449670, f15_449670);
PCREG(4497b0, f15_4497b0);
PCREG(6482f0, f15_6482f0);
PCREG(4cc7f0, f15_4cc7f0);
PCREG(626470, f15_626470);
PCREG(4bf370, f15_4bf370);
PCREG(51a9f0, f15_51a9f0);
PCREG(569c30, f15_569c30);
PCREG(4970f0, f15_4970f0);
PCREG(561b70, f15_561b70);
PCREG(49fcf0, f15_49fcf0);
PCREG(4a3530, f15_4a3530);
PCREG(4b8430, f15_4b8430);
PCREG(4cfc70, f15_4cfc70);
PCREG(5a5730, f15_5a5730);
PCREG(4b86b0, f15_4b86b0);
