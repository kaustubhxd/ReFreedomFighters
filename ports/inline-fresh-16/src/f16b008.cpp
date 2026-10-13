// f16b008.cpp - fresh slice 16, batch 8 (2026-10-12).
// 0x64b3c0 (view, e): bucket b = [+0x10071][u16([[[e+8]+0x10]+8]+6) & 0xfff]; unlink e from b's +0x10 chain (next at +0x18;
//           e+0x18 = 0 when found); then ZViewBase::PrimInstanceLeave 0x64d5f0(e). Ret 4.
// 0x4a3040 ZPlaySound::CreateSound: +0x4c -> room = ZBaseGeom::GetOwnerRoom 0x4db3b0([[+0x44]+8]); [+0x44] slot 0x80(mat[9],
//           pos[3]); +0x50 = ZGROUP::AddSound3d 0x43ec00(room; mat, pos, +0x48, 0, 0, 0) (ret 0x18); +0x4f -> this slot 0x64(0x10).
//           Stack cookie not reproduced.
// 0x600780 (this, first, last): for each tree node from first up to last: 0x6006e0(this; &tmp, node+0xd) (ret 8), then the
//           in-order successor (node +1 parent, +5 left, +9 right; SGI header rule: node->right != parent -> parent). Ret 8.
// 0x4b8e40 ZAttachGeomToBone::Save(sg): +4 &= ~0x40; sg slot 0x3c(db slot 0x4c(+0x59)); slot 0x60(byte +0x58); slot 0x3c on
//           +0x4c, +0x50, +0x54; slot 0x40 on u16 +0x48, +0x4a. Returns true. Ret 4.
// 0x4d5680 CFastLookupFileCache_t deleting destructor: vtable 0x696844, flush 0x4d6880, ~REFTAB32 0x4ccf60(+0xa),
//           ~CFastLookup2 0x4d8d50(+4), vtable 0x6967bc, flag bit 0 -> __builtin_delete(this, 0xb6). Returns this. SEH not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_64d5f0[], ext_4db3b0[], ext_43ec00[], ext_6006e0[], ext_4d6880[], ext_4ccf60[], ext_4d8d50[], ext_634273[];

extern "C" void THISCALL f16_64b3c0(u8 *self, u8 *e) {
  u32 k = AT(u16, AT(u8 *, AT(u8 *, AT(u8 *, e, 8), 0x10), 8), 6) & 0xfff;
  u8 *b = AT(u8 **, self, 0x10071)[k];
  u8 *prev = 0;
  for (u8 *cur = AT(u8 *, b, 0x10); cur; cur = AT(u8 *, cur, 0x18)) {
    if (cur == e) {
      if (prev) AT(u32, prev, 0x18) = AT(u32, e, 0x18);
      else AT(u32, b, 0x10) = AT(u32, e, 0x18);
      AT(u32, e, 0x18) = 0;
      break;
    }
    prev = cur;
  }
  ((void(THISCALL *)(void *, void *))(void *)ext_64d5f0)(self, e);
}

extern "C" void THISCALL f16_4a3040(u8 *self) {
  if (!AT(u8, self, 0x4c)) return;
  void *room = ((void *(THISCALL *)(void *))(void *)ext_4db3b0)(AT(void *, AT(u8 *, self, 0x44), 8));
  float mat[9], pos[3];
  vcall<void>(AT(void *, self, 0x44), 0x80, (void *)mat, (void *)pos);
  AT(u32, self, 0x50) = ((u32(THISCALL *)(void *, float *, float *, u32, u32, u32, u32))(void *)ext_43ec00)(
      room, mat, pos, AT(u32, self, 0x48), 0, 0, 0);
  if (AT(u8, self, 0x4f)) vcall<void>(self, 0x64, 0x10u);
}

extern "C" void THISCALL f16_600780(void *self, u8 *n, u8 *last) {
  while (n != last) {
    u8 tmp;
    ((void(THISCALL *)(void *, void *, void *))(void *)ext_6006e0)(self, &tmp, n + 0xd);
    u8 *r = AT(u8 *, n, 9);
    if (r) {
      n = r;
      while (AT(u8 *, n, 5)) n = AT(u8 *, n, 5);
    } else {
      u8 *p = AT(u8 *, n, 1);
      while (n == AT(u8 *, p, 9)) {
        n = p;
        p = AT(u8 *, p, 1);
      }
      if (AT(u8 *, n, 9) != p) n = p;
    }
  }
}

extern "C" bool THISCALL f16_4b8e40(u8 *self, void *sg) {
  AT(u32, self, 4) &= 0xffffffbfu;
  u32 ref = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x4c, AT(u32, self, 0x59));
  vcall<void>(sg, 0x3c, ref);
  vcall<void>(sg, 0x60, (u32)AT(u8, self, 0x58));
  vcall<void>(sg, 0x3c, AT(u32, self, 0x4c));
  vcall<void>(sg, 0x3c, AT(u32, self, 0x50));
  vcall<void>(sg, 0x3c, AT(u32, self, 0x54));
  vcall<void>(sg, 0x40, (u32)AT(u16, self, 0x48));
  vcall<void>(sg, 0x40, (u32)AT(u16, self, 0x4a));
  return true;
}

extern "C" void *THISCALL f16_4d5680(u8 *self, u32 flags) {
  typedef void(THISCALL * V)(void *);
  AT(u32, self, 0) = 0x696844u;
  ((V)(void *)ext_4d6880)(self);
  ((V)(void *)ext_4ccf60)(self + 0xa);
  ((V)(void *)ext_4d8d50)(self + 4);
  AT(u32, self, 0) = 0x6967bcu;
  if (flags & 1) ((void (*)(void *, u32))(void *)ext_634273)(self, 0xb6);
  return self;
}

PCREG(64b3c0, f16_64b3c0);
PCREG(4a3040, f16_4a3040);
PCREG(600780, f16_600780);
PCREG(4b8e40, f16_4b8e40);
PCREG(4d5680, f16_4d5680);
