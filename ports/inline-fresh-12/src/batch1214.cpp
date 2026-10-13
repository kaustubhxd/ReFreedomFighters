// batch1214.cpp - fresh slice 12, batch 14. Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);           // allocator, cdecl
extern "C" void THISCALL ext_51a9f0(u8 *self, u8 *owner);              // base constructor, ret 4
extern "C" void THISCALL ext_51b530(u8 *self);                         // ret 0
extern "C" void *__attribute__((cdecl)) ext_634d10(void *p, s32 v, u32 n);   // memset
typedef char *(__attribute__((cdecl)) * strchr_t)(const char *, s32);
#define imp_strchr G(strchr_t, 0x676254)                               // VCRUNTIME140 strchr (IAT)

// 0x51b640: new 0x20-byte child of this (SEH frame, ESI/EDI restored): o = 0x41e290(0x20); null -> 0. Else base ctor
// 0x51a9f0(o, this), vtable 0x69f43c, o+0x1c = this, and when the global at 0x701800 is 0, 0x51b530(o). Returns o.
static u8 *THISCALL newChild51b640(u8 *self) {
  u8 *o = ext_41e290(0x20);
  if (!o) return 0;
  ext_51a9f0(o, self);
  *(u32 *)o = 0x69f43c;
  *(u8 **)(o + 0x1c) = self;
  if (G(u32, 0x701800) == 0) ext_51b530(o);
  return o;
}
PCREG(51b640, newChild51b640);

// 0x4934c0: builds a path record: null or empty name -> 0. Else buf = (this+0x1c) slot 0x84(1), memset(buf, 0,
// 0x115c), word buf = 0x101, the name copied to buf+2 with every '/' turned into '\', byte +0xbbf = 1. Returns buf.
// ret 4.
static u8 *THISCALL pathRec4934c0(u8 *self, const char *name) {
  if (!name || !*name) return 0;
  u8 *buf = vcall<u8 *>(self + 0x1c, 0x84, 1u);
  ext_634d10(buf, 0, 0x115c);
  *(u16 *)buf = 0x101;
  char *d = (char *)buf + 2;
  for (u32 i = 0;; i++) {
    d[i] = name[i];
    if (!name[i]) break;
  }
  for (char *p = imp_strchr(d, '/'); p; p = imp_strchr(d, '/')) *p = '\\';
  self[0xbbf] = 1;
  return buf;
}
PCREG(4934c0, pathRec4934c0);

// 0x64d400: registers item's resource once. Flags: item->+8 ->+0x14 |= this+0x10059. r = item->+8 ->+0x10; id =
// word(r->+8 +6) & 0xfff. If table (this+0x10071)[id] is set -> true. Else n = pool(this+0x10161) slot 8(); null ->
// false. n+8 = r; this slot 0x4c(n) true -> table[id] = n, true; false -> pool slot 0xc(n), false. ret 4.
static bool THISCALL register64d400(u8 *self, u8 *item) {
  u8 *d = *(u8 **)(item + 8);
  *(u32 *)(d + 0x14) |= *(u32 *)(self + 0x10059);
  u8 *r = *(u8 **)(*(u8 **)(item + 8) + 0x10);
  u8 *e = *(u8 **)(r + 8);
  if (*(u32 *)(*(u8 **)(self + 0x10071) + (*(u16 *)(e + 6) & 0xfff) * 4)) return true;
  u8 *n = vcall<u8 *>(*(u8 **)(self + 0x10161), 8);
  if (!n) return false;
  *(u8 **)(n + 8) = r;
  if (!vcall<bool>(self, 0x4c, n)) {
    vcall<void>(*(u8 **)(self + 0x10161), 0xc, n);
    return false;
  }
  *(u8 **)(*(u8 **)(self + 0x10071) + (*(u16 *)(e + 6) & 0xfff) * 4) = n;
  return true;
}
PCREG(64d400, register64d400);

static inline s32 cvtt(float f) {
  s32 r;
  asm("cvttss2si %1, %0" : "=r"(r) : "x"(f));
  return r;
}

// 0x650c40: snaps a 2D point to the pixel grid: x = trunc(v[0] * w), y = trunc(h * v[1]) with w, h = this slots 0xd8 /
// 0xdc (asked again for the divide); v[0] = x / w, v[1] = y / h (SSE single). ret 4.
static void THISCALL snap650c40(u8 *self, float *v) {
  s32 x = cvtt(v[0] * (float)vcall<s32>(self, 0xd8));
  s32 y = cvtt((float)vcall<s32>(self, 0xdc) * v[1]);
  v[0] = (float)x / (float)vcall<s32>(self, 0xd8);
  v[1] = (float)y / (float)vcall<s32>(self, 0xdc);
}
PCREG(650c40, snap650c40);
