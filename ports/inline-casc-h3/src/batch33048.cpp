// batch33048.cpp - h3 () batch 33048: tiny tier C wrappers, two SEH funclets
#include "ff.h"

extern "C" u32 THISCALL ext_54d910(u8 *self);   // ret 0

// 0x640e80: thiscall: vtable 0x6c281c; o=[this+0x17f]; if (o) o->slot 4(1)
static void THISCALL fn640e80(u8 *self) {
  *(u32 *)self = 0x6c281c;
  u8 *o = *(u8 **)(self + 0x17f);
  if (o) vcall<u32>(o, 4, 1u);
}
PCREG(640e80, fn640e80);

// 0x466480: thiscall(a) ret 4: slot 0x2a8(0, a)
static u32 THISCALL fn466480(u8 *self, u32 a) { return vcall<u32>(self, 0x2a8, 0u, a); }
PCREG(466480, fn466480);

// 0x445dc0: thiscall: r = slot 0x100("...") ; r ? r->slot 0x8c() : 0
static u32 THISCALL fn445dc0(u8 *self) {
  u8 *r = vcall<u8 *>(self, 0x100, 0x67d9e8u);
  if (!r) return 0;
  return vcall<u32>(r, 0x8c);
}
PCREG(445dc0, fn445dc0);

// 0x472400: thiscall(a) ret 4: sub-object at this+0x2e7, slot 8(this, a)
static u32 THISCALL fn472400(u8 *self, u32 a) { return vcall<u32>(self + 0x2e7, 8, (u32)self, a); }
PCREG(472400, fn472400);

// 0x54a0c0: thiscall: o=[this+0x8061]; if (o) o->slot 0x18(); tail-call 0x54d910(this)
static u32 THISCALL fn54a0c0(u8 *self) {
  u8 *o = *(u8 **)(self + 0x8061);
  if (o) vcall<u32>(o, 0x18);
  return ext_54d910(self);
}
PCREG(54a0c0, fn54a0c0);

// 0x4634d0: thiscall bool: o=[this+0x18]; return o && o->slot 0x14() != 0
static u32 THISCALL fn4634d0(u8 *self) {
  u8 *o = *(u8 **)(self + 0x18);
  if (!o) return 0;
  return vcall<u32>(o, 0x14) != 0;
}
PCREG(4634d0, fn4634d0);

// SEH funclets: they run in the parent frame; the parent's ebp is the saved ebp of our own frame.
typedef u32 (__attribute__((cdecl)) *log_t)(void *, u32, u32, u32);

// 0x4949a8: funclet: g=[0x700390]; g->slot 0x24(g, fmt, [ebp-0xa0], [ebp-0x9c]) (caller pops); returns 0x4949cd
static u32 fn4949a8() {
  u8 *pebp = *(u8 **)__builtin_frame_address(0);
  u8 *g = G(u8 *, 0x700390);
  u32 a1 = *(u32 *)(pebp - 0x9c);
  u32 a0 = *(u32 *)(pebp - 0xa0);
  (*(log_t *)(*(u8 **)g + 0x24))(g, 0x68dcfc, a0, a1);
  return 0x4949cd;
}
PCREG(4949a8, fn4949a8);

// 0x4233db: funclet: p=[ebp-0x4c0]; g->slot 0x24(g, fmt, p[0], p[1]) (caller pops); returns 0x423400
static u32 fn4233db() {
  u8 *pebp = *(u8 **)__builtin_frame_address(0);
  u32 *p = *(u32 **)(pebp - 0x4c0);
  u8 *g = G(u8 *, 0x700390);
  u32 a1 = p[1];
  u32 a0 = p[0];
  (*(log_t *)(*(u8 **)g + 0x24))(g, 0x6780a0, a0, a1);
  return 0x423400;
}
PCREG(4233db, fn4233db);
