// batch3611.cpp - area 73 batch 11 (residue 12, heavy item 1): ZFFSearchLightGroup::Init() (0x5c6f40, docs/20-unclaimed-73.md).
// SEH frame not reproduced (fs:[0] writes not compared). The float math is x87 in the exe; the port uses float arithmetic and
// the same operation order (one multiply by this+0x71 per item).
#include "ff.h"

// 0x41e290: operator new (cdecl, one argument; original code, hooked in the spec).
extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 n);
// 0x4ccbe0: thiscall, two arguments (1, 0); returns eax (original code, hooked in the spec).
extern "C" u32 THISCALL ext_4ccbe0(u8 *self, u32 a, u32 b);
// 0x5c7570: thiscall, one argument (original code, hooked in the spec).
extern "C" void THISCALL ext_5c7570(u8 *self, u8 *s);

// Allocate a 0x1c buffer and construct it (1, 0); the result is the constructor's eax, or 0 when the allocation is null.
static u32 allocAndCtor() {
  u8 *b = ext_41e290(0x1c);
  return b ? ext_4ccbe0(b, 1u, 0u) : 0u;
}

// 0x5c6f40, ZFFSearchLightGroup::Init() (high), thiscall, plain ret.
static void THISCALL searchLightGroupInit(u8 *self) {
  u8 *obj = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  if (obj) {
    u32 local = 0;
    vcall<void>(obj, 0x4c, (u32)&local);
    u32 item = vcall<u32>(obj, 0x5c, (u32)&local);
    if (local != 0) {
      do {
        u8 *s = ext_41e290(0x2d);
        *(u32 *)s = item;
        u8 *sys = G(u8 *, 0x70039c);
        u8 *ctl = *(u8 **)(sys + 0x9b);
        u8 *a = (u8 *)vcall<u32>(ctl, 0x58, item);
        *(u32 *)(s + 0x1c) = (u32)a;
        float f1 = vcall<float>(a, 0x248);
        *(float *)(s + 0x18) = f1;
        float f2 = vcall<float>(a, 0x240);
        f2 = f2 * *(float *)(self + 0x71);
        *(float *)(s + 0x14) = f2;
        *(u32 *)(s + 4) = allocAndCtor();
        *(u32 *)(s + 0xc) = allocAndCtor();
        *(u32 *)(s + 8) = allocAndCtor();
        *(u32 *)(s + 0x10) = allocAndCtor();
        *(u32 *)(s + 0x20) = 0;
        *(u8 *)(s + 0x2c) = 0;
        *(u32 *)(s + 0x24) = 0;
        *(u32 *)(s + 0x28) = 0;
        ext_5c7570(self, s);
        vcall<void>(*(void **)(self + 0x60), 4, (u32)s);
        obj = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
        item = vcall<u32>(obj, 0x5c, (u32)&local);
      } while (local != 0);
    }
  }
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  *(u32 *)(self + 0x48) = vcall<u32>(*(void **)(ctl + 0xadc), 0x25c, 0x685f44u, 0u);
  u8 *esi = (u8 *)vcall<u32>(ctl, 0x138);
  u32 r = vcall<u32>(ctl, 0x4c, *(u32 *)(self + 0x44));
  vcall<void>(esi, 0x60, 0x6b43a0u, r, 0x10u);
}
PCREG(5c6f40, searchLightGroupInit);
