// batch835.cpp - gap band small functions with hooked callees (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 *THISCALL ext_6397c0(u8 *self, u32 arg);                 // hooked (GUESS): returns a buffer, ret 4
extern "C" u32 *THISCALL ext_638f20(u8 *self, u32 arg);                 // hooked (GUESS): returns counted word array, ret 4
extern "C" void __attribute__((cdecl)) ext_634d22(void *dst, void *src, u32 n);   // hooked (GUESS): memmove
extern "C" void STDCALL ext_63ef00(u8 *a);                              // hooked (GUESS): ret 4
extern "C" u8 THISCALL ext_4dd8d0(u8 *obj);                             // hooked (GUESS): returns al

// 0x639ac0: thiscall(arg) ret 4 - p = 0x6397c0(arg); p[0] = this[0x32]; copies this[0x32] words from this[0x2d] to p + 4;
// returns the end address p + 4 + 4 * this[0x32]
static u32 THISCALL packArray_639ac0(u8 *self, u32 arg) {
  u32 *p = ext_6397c0(self, arg);
  *p = *(u32 *)(self + 0x32);
  u32 *q = p + 1;
  ext_634d22(q, *(void **)(self + 0x2d), *(u32 *)(self + 0x32) << 2);
  return (u32)(q + *(u32 *)(self + 0x32));
}
PCREG(639ac0, packArray_639ac0);

// 0x63f030: stdcall(a) ret 4 - 0x63ef00(a); o = a[0x38]; if o and 0x4dd8d0(o) and o[0x54] (obj): obj->vt[0x130](obj, 0x400, 0)
static void STDCALL notify_63f030(u8 *a) {
  ext_63ef00(a);
  u8 *n = *(u8 **)(a + 0x38);
  if (!n) return;
  if (!ext_4dd8d0(n)) return;
  u8 *o = *(u8 **)(n + 0x54);
  if (!o) return;
  (*(void(THISCALL **)(u8 *, u8 *, u32, u32))(*(u8 **)o + 0x130))(o, o, 0x400, 0);
}
PCREG(63f030, notify_63f030);

// 0x6401b0: thiscall(a) ret 4 - if u16 a[0x40] = n: this->vt[0x24](a[0x48], n * 0x44); a[0x44] = a[0x48] = 0
static void THISCALL freeBlock_6401b0(u8 *self, u8 *a) {
  u32 n = *(u16 *)(a + 0x40);
  if (n) {
    u8 *vt = *(u8 **)self;
    (*(void(THISCALL **)(u8 *, u32, u32))(vt + 0x24))(self, *(u32 *)(a + 0x48), ((n << 4) + n) << 2);
    *(u32 *)(a + 0x44) = 0;
    *(u32 *)(a + 0x48) = 0;
  }
}
PCREG(6401b0, freeBlock_6401b0);

// 0x639270: thiscall(arg) ret 4 - p = 0x638f20(arg); n = p[0]; this[0x2d] = p + 4; this[0x32] = n; this[0x36] = end = p + 4 + 4n;
// returns end + vt[0x1c]() * vt[0x20]()  (vt[0x20] first)
static u32 THISCALL setArrayStride_639270(u8 *self, u32 arg) {
  u32 *p = ext_638f20(self, arg);
  u32 n = p[0];
  p += 1;
  *(u32 *)(self + 0x2d) = (u32)p;
  *(u32 *)(self + 0x32) = n;
  u32 end = (u32)(p + n);
  *(u32 *)(self + 0x36) = end;
  u32 a = (*(u32(THISCALL **)(u8 *))(*(u8 **)self + 0x20))(self);
  u32 b = (*(u32(THISCALL **)(u8 *))(*(u8 **)self + 0x1c))(self);
  return b * a + end;
}
PCREG(639270, setArrayStride_639270);
