// batch833.cpp - gap band small functions with hooked callees (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634273(u32 a, u32 b);   // hooked (GUESS): delete-like, caller cleans
extern "C" u32 THISCALL ext_638f20(u8 *self, u32 arg);            // hooked (GUESS): returns pointer to counted word array
extern "C" u32 THISCALL ext_63ab30(u8 *self);                     // hooked (GUESS): dtor body
extern "C" u32 THISCALL ext_6363a0(u8 *self);                     // hooked (GUESS): dtor body

// 0x63b660: thiscall(arg) ret 4 - r = this[4]->vt[0x20](arg) (thiscall on this[4]); a nonzero r bumps this[0xc]; returns r
static u32 THISCALL vtCallCount_63b660(u8 *self, u32 arg) {
  u8 *obj = *(u8 **)(self + 4);
  u32 r = (*(u32(THISCALL **)(u8 *, u32))(*(u8 **)obj + 0x20))(obj, arg);
  if (r) *(u32 *)(self + 0xc) += 1;
  return r;
}
PCREG(63b660, vtCallCount_63b660);

// 0x639240: thiscall(arg) ret 4 - p = 0x638f20(arg); this[0x2d] = p + 4; this[0x32] = *p; returns p + 4 + 4 * *p
static u32 THISCALL setArray_639240(u8 *self, u32 arg) {
  u32 *p = (u32 *)ext_638f20(self, arg);
  u32 n = p[0];
  *(u32 *)(self + 0x2d) = (u32)(p + 1);
  *(u32 *)(self + 0x32) = n;
  return (u32)(p + 1) + n * 4;
}
PCREG(639240, setArray_639240);

// 0x63abe0: thiscall(flags) ret 4 - 0x63ab30(this); if flags & 1: 0x634273(this, 0xb9a4); returns this
static u8 *THISCALL dtorDeleting_63abe0(u8 *self, u32 flags) {
  ext_63ab30(self);
  if (flags & 1) ext_634273((u32)self, 0xb9a4);
  return self;
}
PCREG(63abe0, dtorDeleting_63abe0);

// 0x636400: thiscall() - this[0] = 0x6c1fec; if this[0x31]: 0x634273(this[0x2d], 4); then tail-calls 0x6363a0(this)
static u32 THISCALL dtorTail_636400(u8 *self) {
  *(u32 *)self = 0x6c1fec;
  if (self[0x31]) ext_634273(*(u32 *)(self + 0x2d), 4);
  return ext_6363a0(self);
}
PCREG(636400, dtorTail_636400);
