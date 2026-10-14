// batch34140.cpp - cascade tier E, batch 34140: 0x57dd10 (set up a scratch area and two child objects), 0x5d3a10 (property get/set).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);                    // cdecl alloc
extern "C" void THISCALL ext_563510(void *self, u32 a); // ret 4

// 0x57dd10, thiscall plain: [this+0x18c]->slot0xbc(1); n = [[[0x70039c]+0x1907]+0x1210]; [+0x338] = n; p = ext_41e290(3n); [+0x32c] = p; [+0x330] = n + p; [+0x334] = p + 2n;
// [+0x31c] = [0x70039c]->slot0xbc(); ext_563510(this, 0x6a6f98); a = [this+0x54]->slot0x25c(0x6aad6c, 0) -> [+0x314]; b = a->slot0x25c(0x6aad78, 0) -> [+0x310]; b->slot0xbc(1); a->slot0xbc(1).
static void THISCALL fn57dd10(u8 *self) {
  vcall<void>(*(u8 **)(self + 0x18c), 0xbc, 1u);
  u8 *eng = G(u8 *, 0x70039c);
  u32 n = *(u32 *)(*(u8 **)(eng + 0x1907) + 0x1210);
  *(u32 *)(self + 0x338) = n;
  u32 p = ext_41e290(n * 3);
  *(u32 *)(self + 0x32c) = p;
  *(u32 *)(self + 0x330) = *(u32 *)(self + 0x338) + p;
  *(u32 *)(self + 0x334) = p + *(u32 *)(self + 0x338) * 2;
  *(u32 *)(self + 0x31c) = vcall<u32>(G(u8 *, 0x70039c), 0xbc);
  ext_563510(self, 0x6a6f98);
  u8 *a = vcall<u8 *>(*(u8 **)(self + 0x54), 0x25c, 0x6aad6cu, 0u);
  *(u8 **)(self + 0x314) = a;
  u8 *b = vcall<u8 *>(a, 0x25c, 0x6aad78u, 0u);
  *(u8 **)(self + 0x310) = b;
  vcall<void>(b, 0xbc, 1u);
  vcall<void>(*(u8 **)(self + 0x314), 0xbc, 1u);
}
PCREG(57dd10, fn57dd10);

// 0x5d3a10, thiscall(id, out) ret 8, always returns 0. By the low word of id: == word [+0x7a]: [this+0x48] = out; == word [+0x7c]: *out = [this+0x48];
// == word [+0x7e]: t = [this+0x4c] ? [[0x70039c]+0x9b]->slot0x58([this+0x4c]) : id; zero -> [this+0x44]; out[0..2] = 0; t->slot0x84(out).
static u32 THISCALL fn5d3a10(u8 *self, u32 id, u32 *out) {
  u16 w = (u16)id;
  if (w == *(u16 *)(self + 0x7a)) {
    *(u32 *)(self + 0x48) = (u32)out;
    return 0;
  }
  if (w == *(u16 *)(self + 0x7c)) {
    *out = *(u32 *)(self + 0x48);
    return 0;
  }
  if (w == *(u16 *)(self + 0x7e)) {
    u32 e = *(u32 *)(self + 0x4c);
    u8 *t;
    if (e) t = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, e);
    else t = (u8 *)id;
    if (!t) t = *(u8 **)(self + 0x44);
    out[2] = 0;
    out[1] = 0;
    out[0] = 0;
    vcall<void>(t, 0x84, (u32)out);
  }
  return 0;
}
PCREG(5d3a10, fn5d3a10);
