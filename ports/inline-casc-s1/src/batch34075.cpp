// batch34075.cpp - cascade tier E, batch 34075: 0x57e230 (refresh a flag array and ask the member), 0x57e370 (set two values on two engine objects), 0x593f40 (clamped state update).
#include "ff.h"

extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
extern "C" void THISCALL ext_57e4f0(void *self);                  // thiscall, plain ret
extern "C" void THISCALL ext_5630f0(void *self);                  // thiscall, plain ret

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x57e230, thiscall(a) ret 4, bool: when [this+0x33c] is non-zero: copy [this+0x338] bytes from [[sys+0x1907]+0x131c] to [this+0x334] (cdecl 0x634d22), clear every byte of the array [this+0x32c] whose
// partner in [this+0x334] is zero; r = (this+0x190)->slot0x2c(a); when r: ext_57e4f0(this), return true. Otherwise false. When [this+0x33c] is zero: (this+0x190)->slot0x40(a), false. The vtable is read from [this+0x190].
static bool THISCALL fn57e230(u8 *self, u32 a) {
  if (*(u32 *)(self + 0x33c) == 0) {
    vcall<void>(self + 0x190, 0x40, a);
    return false;
  }
  u8 *sys = G(u8 *, 0x70039c);
  ext_634d22(*(void **)(self + 0x334), *(void **)(rd32(sys + 0x1907) + 0x131c), *(u32 *)(self + 0x338));
  for (u32 i = 0; i < *(u32 *)(self + 0x338); i++) {
    u8 *p = *(u8 **)(self + 0x32c);
    if (p[i] != 0 && (*(u8 **)(self + 0x334))[i] == 0) p[i] = 0;
  }
  if (vcall<u32>(self + 0x190, 0x2c, a) == 0) return false;
  ext_57e4f0(self);
  return true;
}
PCREG(57e230, fn57e230);

// 0x57e370, thiscall, plain ret: ext_5630f0(this); for the two engine-table objects given by ids [this+0x180] and [this+0x184] (table slot 0x58): o->slot0x25c(0x6a65b0, 0)->slot0x250(0xc8), then
// o->slot0x25c(0x6aa774, 0)->slot0x250(0x32).
static void THISCALL fn57e370(u8 *self) {
  u8 *o[2];
  ext_5630f0(self);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  o[0] = vcall<u8 *>(tbl, 0x58, *(u32 *)(self + 0x180));
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  o[1] = vcall<u8 *>(tbl, 0x58, *(u32 *)(self + 0x184));
  for (int i = 0; i < 2; i++) {
    u8 *r = vcall<u8 *>(o[i], 0x25c, 0x6a65b0u, 0u);
    vcall<void>(r, 0x250, 0xc8u);
    r = vcall<u8 *>(o[i], 0x25c, 0x6aa774u, 0u);
    vcall<void>(r, 0x250, 0x32u);
  }
}
PCREG(57e370, fn57e370);

// 0x593f40, thiscall(a) ret 4: nothing when [this+0x417] has 0x8000000. v = unaligned dword [this+0x94f]; when [sys+0x40] >= v + 0x200 (signed): when this->slot0x3f0() is zero and a is 0, 1 or 2:
// this->slot0x3d8(this->slot0x3ec(0x1a + a)). Then (in both cases) [this+0x94f] = [sys+0x40] unless the two addresses coincide.
static void THISCALL fn593f40(u8 *self, s32 a) {
  if (rd32(self + 0x417) & 0x8000000) return;
  u8 *sys = G(u8 *, 0x70039c);
  s32 v = (s32)rd32(self + 0x94f);
  if (*(s32 *)(sys + 0x40) < v + 0x200) return;
  if (vcall<u32>(self, 0x3f0) == 0) {
    if (a == 0 || a == 1 || a == 2) {
      u32 t = vcall<u32>(self, 0x3ec, (u32)(0x1a + a));
      vcall<void>(self, 0x3d8, t);
    }
  }
  sys = G(u8 *, 0x70039c);
  if (self + 0x94f != sys + 0x40) wr32(self + 0x94f, *(u32 *)(sys + 0x40));
}
PCREG(593f40, fn593f40);
