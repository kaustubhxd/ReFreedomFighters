// batch210025.cpp - Sonnet-w3a: small BLOCKED rows (byte compare, state-dependent slots, array remove, engine lookups, serializer)
#include "ff.h"

extern "C" u32 THISCALL ext_45f3c0(u8 *self, u8 *a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static int FASTCALL fn4309b0(const u8 *a, const u8 *b, u32 n) {
  for (u32 i = 0; i < n; i++) {
    if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;  // @4309b0_a
  }
  return 0;
}
PCREG(4309b0, fn4309b0);

static u32 THISCALL fn4a5fe0(u8 *self) {
  if (self[0x8f] == 0) {  // @4a5fe0_a
    if (self[0x90]) return vcall<u32>(*(u8 **)(self + 0x44), 0x28);  // @4a5fe0_b
    u32 r = vcall<u32, u32, u32>(self, 0x68, 0x10, 0);  // @4a5fe0_c
    self[0xbf] = 0;  // @4a5fe0_d
    return r;
  }
  if (self[0x91]) {
    u8 *m = *(u8 **)(self + 0x44);
    u8 *o = (u8 *)vcall<u32>(m, 0x20);  // @4a5fe0_e
    if (*(u32 *)(o + 0x4c) == 1) {  // @4a5fe0_f
      u8 *o2 = (u8 *)vcall<u32>(*(u8 **)(self + 0x44), 0x20);
      if (!o2) return 0;
      return vcall<u32, u32>(o2, 0x210, 1);  // @4a5fe0_g
    }
  }
  u8 *m = *(u8 **)(self + 0x44);
  if (!m) return 0;
  return vcall<u32, u32>(m, 0x210, 1);  // @4a5fe0_h
}
PCREG(4a5fe0, fn4a5fe0);

static u32 THISCALL fn4dc140(u8 *self, u32 a) {
  u32 *arr = (u32 *)self;
  u32 i = 0;
  u8 bl = self[0x1c];
  if (!bl) return 0;
  for (;;) {
    if (arr[i] == a) break;  // @4dc140_a
    i++;
    if (i == bl) return i;
  }
  bl--;
  self[0x1c] = bl;  // @4dc140_b
  if (i >= bl) return i;  // @4dc140_c
  do {
    arr[i] = arr[i + 1];  // @4dc140_d
    if (i < 3) {
      if (i == 2) self[0x1f] = 0;  // @4dc140_e
      else self[i + 0x1d] = self[i + 0x1e];  // @4dc140_f
    }
    i++;
  } while (i < self[0x1c]);
  return i;
}
PCREG(4dc140, fn4dc140);

static u32 THISCALL fn5d3eb0(u8 *self) {
  *(u32 *)(self + 0x80) = 0xffffffffu;  // @5d3eb0_a
  u32 r;
  r = vcall<u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6af14c, 0, 0x6b518c, 0x41);  // @5d3eb0_b
  *(u16 *)(self + 0x78) = (u16)r;
  r = vcall<u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6b51c8, 0, 0x6b518c, 0x42);  // @5d3eb0_c
  *(u16 *)(self + 0x7a) = (u16)r;
  r = vcall<u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6a61b0, 0, 0x6b518c, 0x43);  // @5d3eb0_d
  *(u16 *)(self + 0x7c) = (u16)r;
  r = vcall<u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6a619c, 0, 0x6b518c, 0x44);  // @5d3eb0_e
  *(u16 *)(self + 0x7e) = (u16)r;
  __builtin_memset(self + 0x85, 0, 4);  // @5d3eb0_f
  *(u32 *)(self + 0x48) = 0;  // @5d3eb0_g
  return r;
}
PCREG(5d3eb0, fn5d3eb0);

static u32 THISCALL fn5d8ee0(u8 *self, u8 *a) {
  ext_45f3c0(self, a);  // @5d8ee0_a
  vcall<u32, u8 *>(a, 0x40, self + 0x28);  // @5d8ee0_b
  vcall<u32, u8 *>(a, 0x48, self + 0x2c);  // @5d8ee0_c
  vcall<u32, u8 *>(a, 0x48, self + 0x30);
  vcall<u32, u8 *>(a, 0x48, self + 0x3c);  // @5d8ee0_d
  vcall<u32, u8 *>(a, 0x48, self + 0x40);
  u32 r = vcall<u32, u8 *>(a, 0x50, self + 0x38);  // @5d8ee0_e
  return (r & ~0xffu) | 1;
}
PCREG(5d8ee0, fn5d8ee0);
