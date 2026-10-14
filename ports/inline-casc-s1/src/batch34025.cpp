// batch34025.cpp - cascade tier E, batch 34025: 0x57aff0 / 0x57b060 (save / restore a per-slot value of every matching child) and 0x57bee0
// (fetch three named children and prod them when a mode is 3).
#include "ff.h"

extern "C" bool THISCALL ext_4db9a0(void *node, u32 mask);   // thiscall ret 4, bool in al

// 0x57aff0, thiscall, no args: for each node of the child list ([[this+0x54]+8], next through [this+0x54] slot 0x50(&node)): when 0x4db9a0(node, 0x100034):
// o = [node+0x54]; [this + o->slot0x310()*4 + 0x180] = o->slot0x368().
static void THISCALL fn57aff0(u8 *self) {
  u32 node = *(u32 *)(*(u8 **)(self + 0x54) + 8);
  if (!node) return;
  do {
    if (ext_4db9a0((void *)node, 0x100034)) {
      u8 *o = *(u8 **)(node + 0x54);
      u32 v = vcall<u32>(o, 0x368);
      u32 idx = vcall<u32>(o, 0x310);
      *(u32 *)(self + idx * 4 + 0x180) = v;
    }
    u8 *list = *(u8 **)(self + 0x54);
    vcall<void>(list, 0x50, (u32)&node);
  } while (node);
}
PCREG(57aff0, fn57aff0);

// 0x57b060, thiscall, no args: the restore twin: o->slot0x36c([this + o->slot0x310()*4 + 0x180], 1).
static void THISCALL fn57b060(u8 *self) {
  u32 node = *(u32 *)(*(u8 **)(self + 0x54) + 8);
  if (!node) return;
  do {
    if (ext_4db9a0((void *)node, 0x100034)) {
      u8 *o = *(u8 **)(node + 0x54);
      u32 idx = vcall<u32>(o, 0x310);
      u32 v = *(u32 *)(self + idx * 4 + 0x180);
      vcall<void>(o, 0x36c, v, 1u);
    }
    u8 *list = *(u8 **)(self + 0x54);
    vcall<void>(list, 0x50, (u32)&node);
  } while (node);
}
PCREG(57b060, fn57b060);

// 0x57bee0, thiscall, no args: when [[this+0x94]+0x1044] == 3: p = [this+0x54]; a = p->slot0x25c(0x6a7590, 0); b = a->slot0x25c(0x6aa5f4, 0);
// b->slot0x2dc(); b->slot0x28(); c = a->slot0x25c(0x6aa5fc, 0); c->slot0x31c(0, 1); c->slot0x31c(0, 2).
static void THISCALL fn57bee0(u8 *self) {
  if (*(u32 *)(*(u8 **)(self + 0x94) + 0x1044) != 3) return;
  u8 *p = *(u8 **)(self + 0x54);
  u8 *a = vcall<u8 *>(p, 0x25c, 0x6a7590u, 0u);
  u8 *b = vcall<u8 *>(a, 0x25c, 0x6aa5f4u, 0u);
  vcall<void>(b, 0x2dc);
  vcall<void>(b, 0x28);
  u8 *c = vcall<u8 *>(a, 0x25c, 0x6aa5fcu, 0u);
  vcall<void>(c, 0x31c, 0u, 1u);
  vcall<void>(c, 0x31c, 0u, 2u);
}
PCREG(57bee0, fn57bee0);
