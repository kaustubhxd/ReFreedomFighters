// batch37109.cpp - cascade s6 batch 37109: 0x63f0e0.
#include "ff.h"

extern "C" void THISCALL ext_63e850(u8 *self, u8 *node);          // ret 4
extern "C" u32 THISCALL ext_4dd8d0(u8 *elem);                     // plain ret, bool in al
extern "C" void THISCALL ext_4db6c0(u8 *elem, u8 *a, u8 *b);      // ret 8
extern "C" u32 THISCALL ext_63f090(u8 *self, u8 *node);           // ret 4, id in ax
extern "C" u32 THISCALL ext_658d30(u8 *node);                     // plain ret
extern "C" void THISCALL ext_658fb0(u8 *node, u8 *x);             // ret 4
extern "C" u8 *THISCALL ext_63f220(u8 *self, u32 key);            // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// 0x63f0e0, thiscall(ctx, elem) ret 8, returns a node or 0: finds or creates the node bound to the element. A nonzero 12-bit id in elem+0x5a selects an existing node from the
// table at +0x68 (settled with 0x63e850 unless already marked, bit 0 of +5). Otherwise a node is taken from the pool at +0x220 (slot 8), flagged from the element's state (0x60 when
// the object at elem+0x54 answers slot 0xec, 0x20 from 0x4dd8d0), linked to the element and offered to slots 0x84 / 0x90; when slot 0x90 refuses it is released through slots 0x94 and
// 0xc and 0 is returned. Otherwise the element gets a fresh id (0x63f090), the node is settled and, unless it is already bound, may be attached to the target found through ctx+0x3c
// (slot 0x358) or the engine table object, whose counter at +0x3e is bumped.
static u8 *THISCALL fn63f0e0(u8 *self, u8 *ctx, u8 *elem) {
  u32 id = W16(elem, 0x5a);
  u8 *node;
  if (id) {
    node = ((u8 **)D32(self, 0x68))[id & 0xfff];
    if (!(node[5] & 1)) ext_63e850(self, node);
    return node;
  }
  u8 *pool = *(u8 **)(self + 0x220);
  node = (u8 *)vcall<u32>(pool, 8);
  if (!node) return 0;
  u8 *sub = *(u8 **)(elem + 0x54);
  if (sub && (u8)vcall<u32>(sub, 0xec)) node[5] |= 0x60;
  if ((u8)ext_4dd8d0(elem)) node[5] |= 0x20;
  D32(node, 0x38) = (u32)elem;
  ext_4db6c0(elem, node + 8, node + 0x2c);
  vcall<void>(self, 0x84, (u32)node);
  if (!(u8)vcall<u32>(self, 0x90, (u32)node)) {
    vcall<void>(self, 0x94, (u32)node);
    vcall<void>(*(void **)(self + 0x220), 0xc, (u32)node);
    return 0;
  }
  W16(elem, 0x5a) = (u16)ext_63f090(self, node);
  ext_63e850(self, node);
  if (ext_658d30(node)) return node;
  if (!ctx) return node;
  u8 *c2 = *(u8 **)(ctx + 0x3c);
  if (!c2) return node;
  u32 t = vcall<u32>(c2, 0x358);
  if (!t) {
    if (!(D32(elem, 0x3c) & 0x40000000)) return node;
    void *tab = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc);
    t = vcall<u32>(tab, 0x358);
    if (!t) return node;
  }
  u8 *tg = ext_63f220(self, t);
  if (!tg) return node;
  ext_658fb0(node, tg);
  W16(tg, 0x3e)++;
  return node;
}
PCREG(63f0e0, fn63f0e0);
