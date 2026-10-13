// batch1215.cpp - fresh slice 12, batch 15. Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" void THISCALL ext_430b70(u8 *map, u32 *out, u8 *key);   // map find, writes the node to *out; ret 8

// 0x42c900: token reader step. Tokens are 12-byte records {begin, end, ?} in the list at this+0x1b6d (end at +4); *it
// is the cursor. Steps past the current token, skips single-space tokens, looks the token up in the map at this+0x1b65
// (0x430b70) and steps past it. Returns 1 when found (node != map head), else 0. ret 4.
static u32 THISCALL step42c900(u8 *self, u8 **it) {
  if (*it != *(u8 **)(*(u8 **)(self + 0x1b6d) + 4)) *it += 0xc;
  while (*it != *(u8 **)(*(u8 **)(self + 0x1b6d) + 4)) {
    u8 *t = *it;
    u8 *b = *(u8 **)t;
    if (*(u8 **)(t + 4) - b != 1 || *b != ' ') break;
    *it = t + 0xc;
  }
  u8 *map = *(u8 **)(self + 0x1b65);
  u32 node;
  ext_430b70(map, &node, *it);
  u32 r = node != *(u32 *)map;
  if (*it != *(u8 **)(*(u8 **)(self + 0x1b6d) + 4)) *it += 0xc;
  return r;
}
PCREG(42c900, step42c900);

// 0x538600: hands item x between two lists. If list A (this+0x53b2) slot 0x28(x): list B (this+0x5306) slot 4(x),
// A slot 0x3c(x), and the engine record for x (engine(+0x9b) slot 0x60(x)) gets state 3. Else when x's record has
// state 0xc, B slot 4(x). EAX is what the last call left (returned as is). ret 4.
static u32 THISCALL move538600(u8 *self, u32 x) {
  u8 *eng = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (vcall<u32>(self + 0x53b2, 0x28, x)) {
    vcall<u32>(self + 0x5306, 4, x);
    vcall<u32>(self + 0x53b2, 0x3c, x);
    u8 *r = vcall<u8 *>(eng, 0x60, x);
    if (r) *(u32 *)(r + 4) = 3;
    return (u32)r;
  }
  u8 *r = vcall<u8 *>(eng, 0x60, x);
  if (!r || *(u32 *)(r + 4) != 0xc) return (u32)r;
  return vcall<u32>(self + 0x5306, 4, x);
}
PCREG(538600, move538600);

// 0x41c780: engine shutdown. Calls [0x700390] slot 8, then deletes (slot(1), each object's deleting destructor) and
// clears the globals in order: 0x7003a0 (slot 0), 0x70039c (slot 0x18), 0x700394 (slot 0xcc), 0x70038c (slot 0),
// 0x700390 (slot 4). cdecl, no args.
static void shutdown41c780() {
  vcall<void>(G(u8 *, 0x700390), 8);
  if (u8 *o = G(u8 *, 0x7003a0)) vcall<void>(o, 0, 1u);
  G(u32, 0x7003a0) = 0;
  if (u8 *o = G(u8 *, 0x70039c)) vcall<void>(o, 0x18, 1u);
  G(u32, 0x70039c) = 0;
  if (u8 *o = G(u8 *, 0x700394)) vcall<void>(o, 0xcc, 1u);
  G(u32, 0x700394) = 0;
  if (u8 *o = G(u8 *, 0x70038c)) vcall<void>(o, 0, 1u);
  G(u32, 0x70038c) = 0;
  if (u8 *o = G(u8 *, 0x700390)) vcall<void>(o, 4, 1u);
  G(u32, 0x700390) = 0;
}
PCREG(41c780, shutdown41c780);
