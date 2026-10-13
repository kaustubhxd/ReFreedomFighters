// batch1202.cpp - fresh slice 12, batch 2: small destructors, a constructor, deletes and wrappers.
// Names are FUN_ in the exe list (no map entry). Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);   // sized operator delete
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);           // operator new
extern "C" void THISCALL ext_5ec7e0(u8 *self);                          // base destructor, ret 0
extern "C" void THISCALL ext_469870(u8 *self);                          // base constructor, ret 0
extern "C" u32 THISCALL ext_642050(u8 *self);                           // ret 0
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 i);                    // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 v);                   // ret 4
extern "C" void THISCALL ext_5626c0(u8 *self);                          // jmp thunk to 0x562750, ret 0
extern "C" void THISCALL ext_56a140(u8 *self);                          // ret 0
typedef void *(__attribute__((cdecl)) * fopen_t)(const char *, const char *);
#define imp_fopen G(fopen_t, 0x6763b0)                                   // api-ms-win-crt-stdio fopen (IAT)

// 0x5ec880: scalar deleting destructor: base 0x5ec7e0, sized delete 0xd7 when bit 0 of flags is set.
static u8 *THISCALL sdd5ec880(u8 *self, u32 flags) {
  ext_5ec7e0(self);
  if (flags & 1) ext_634273(self, 0xd7);
  return self;
}
PCREG(5ec880, sdd5ec880);

// 0x63db40: index of *key in the dword array that follows the count at this+0, or -1. ret 4.
static s32 THISCALL indexOf(u32 *self, u32 *key) {
  u32 n = self[0];
  if (n) {
    u32 k = *key;
    u32 i = 0;
    do {
      if (self[1 + i] == k) return (s32)i;
    } while (++i != n);
  }
  return -1;
}
PCREG(63db40, indexOf);

// 0x54a6c0: calls vslot 0x8c(list[i]) for i in [0, n) (signed count). ret 8.
static void THISCALL forEach8c(u8 *self, u32 *list, s32 n) {
  for (s32 i = 0; i < n; i++) vcall<u32>(self, 0x8c, list[i]);
}
PCREG(54a6c0, forEach8c);

// 0x652680: frees the block at this+0x11e9 (its +8 buffer first, size 4; then the 0x10-byte block) and clears it.
static void THISCALL free11e9(u8 *self) {
  u8 *p = *(u8 **)(self + 0x11e9);
  ext_634273(*(void **)(p + 8), 4);
  ext_634273(*(void **)(self + 0x11e9), 0x10);
  *(u32 *)(self + 0x11e9) = 0;
}
PCREG(652680, free11e9);

// 0x56ad80: constructor: base 0x469870, flags |= 0x20 at +4, vtable 0x6a7858, +0x44 = +0x48 = 0, byte +0x50 = 1.
static u8 *THISCALL ctor56ad80(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6a7858;
  *(u32 *)(self + 0x48) = 0;
  self[0x50] = 1;
  return self;
}
PCREG(56ad80, ctor56ad80);

// 0x64fe80: replaces the buffer at +0x20 (old one deleted, size 1); +0x28 = buf + buf->+4; +0x24 = buf + off.
// EAX = the +0x24 value. ret 8.
static u32 THISCALL setBuf(u8 *self, u8 *buf, u32 off) {
  void *old = *(void **)(self + 0x20);
  if (old) ext_634273(old, 1);
  *(u8 **)(self + 0x20) = buf;
  *(u32 *)(self + 0x28) = *(u32 *)(buf + 4) + (u32)buf;
  u32 r = off + (u32)buf;
  *(u32 *)(self + 0x24) = r;
  return r;
}
PCREG(64fe80, setBuf);

// 0x54e180: scalar deleting destructor: vtable 0x6a3ea8, delete the +0x53 buffer (size 1) if set, then sized delete
// 0x6b when bit 0 of flags is set.
static u8 *THISCALL sdd54e180(u8 *self, u32 flags) {
  void *b = *(void **)(self + 0x53);
  *(u32 *)self = 0x6a3ea8;
  if (b) ext_634273(b, 1);
  if (flags & 1) ext_634273(self, 0x6b);
  return self;
}
PCREG(54e180, sdd54e180);

// 0x4d5640: if the buffer at +1 is set: delete it (size 1) unless byte +0 (borrowed flag) is set; then clear +1, +5,
// +9 and +0x11.
static void THISCALL clearBuf(u8 *self) {
  void *p = *(void **)(self + 1);
  if (!p) return;
  if (self[0] == 0) ext_634273(p, 1);
  *(u32 *)(self + 1) = 0;
  *(u32 *)(self + 5) = 0;
  *(u32 *)(self + 9) = 0;
  *(u32 *)(self + 0x11) = 0;
}
PCREG(4d5640, clearBuf);

// 0x4d49c0: stdcall (path, mode): new 4-byte holder, holder->f = fopen(path, mode); returns the holder, or deletes it
// (size 4) and returns 0 when fopen fails. ret 8.
static u32 *STDCALL openFile(const char *path, const char *mode) {
  u32 *h = (u32 *)ext_41e290(4);
  void *f = imp_fopen(path, mode);
  *h = (u32)f;
  if (f) return h;
  ext_634273(h, 4);
  return 0;
}
PCREG(4d49c0, openFile);

// 0x554d00: o = engine(+0x1aa3)->vslot 0x94(); v = o->+0x21 - 0x642050(o); 0x5002f0(0x5003d0(arg->+8, 0), v). ret 4.
static void THISCALL f554d00(u8 *, u8 *arg) {
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *o = vcall<u8 *>(mgr, 0x94);
  u32 r = ext_642050(o);
  u32 v = *(u32 *)(o + 0x21) - r;
  ext_5002f0(ext_5003d0(*(u8 **)(arg + 8), 0), v);
}
PCREG(554d00, f554d00);

// 0x56a100: runs 0x5626c0 and 0x56a140; when +0x1c5 == 2 and +0x94 is set, stores engine(+0x9b)->vslot 0x4c(+0x44)
// at (+0x94)->+0x1329f.
static void THISCALL f56a100(u8 *self) {
  ext_5626c0(self);
  ext_56a140(self);
  if (*(u32 *)(self + 0x1c5) != 2) return;
  u8 *t = *(u8 **)(self + 0x94);
  if (!t) return;
  u8 *eng = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(t + 0x1329f) = vcall<u32>(eng, 0x4c, *(u32 *)(self + 0x44));
}
PCREG(56a100, f56a100);
