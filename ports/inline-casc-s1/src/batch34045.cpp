// batch34045.cpp - cascade tier E, batch 34045: 0x466640 (transform a point through two helpers and pass it on), 0x46c8a0 (drain a list and optionally make a new object),
// 0x4705a0 (copy seven fields into a chain of setters).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *arg);          // fastcall, 1 stack arg
extern "C" void THISCALL ext_4e09b0(void *self);                                // thiscall, plain ret
extern "C" void FASTCALL ext_4de040(void *ecx, void *edx, u32 arg);            // fastcall, 1 stack arg (ret 4)
extern "C" void FASTCALL ext_633654(u32 cookie);                                // /GS check
extern "C" void THISCALL ext_4d9430(void *node);                                // thiscall, plain ret
extern "C" void ext_4d9590(void *node);                                         // cdecl
extern "C" void THISCALL ext_441790(void *self, void *s);                       // thiscall ret 4

// 0x466640, thiscall(a) ret 4: v = {0, 0, 0}; this->slot0x84(&v); tmp = 0x43e920 (ECX = &tmp, EDX = a, stack &v), tmp[1] = 0, 0x4e09b0(&tmp), 0x4de040 (ECX = &obj, EDX = &tmp, stack 0);
// this->slot0x370(&obj, &v); then the /GS check.
static void THISCALL fn466640(u8 *self, u32 a) {
  u32 v[3] = {0, 0, 0};
  u32 tmp[3];
  u32 obj[9];
  vcall<void>(self, 0x84, (u32)v);
  ext_43e920(tmp, (void *)a, v);
  tmp[1] = 0;
  ext_4e09b0(tmp);
  ext_4de040(obj, tmp, 0);
  vcall<void>(self, 0x370, (u32)obj, (u32)v);
  ext_633654(0);
}
PCREG(466640, fn466640);

// 0x46c8a0, thiscall(a) ret 4: while [this+0x50] is set: 0x4d9430(node), 0x4d9590(node). When a is non-zero: this->slot0x294(0x688a24, a, 0, 1) and returns [this+0x50]; else returns 0.
static u32 THISCALL fn46c8a0(u8 *self, u32 a) {
  u8 *node = *(u8 **)(self + 0x50);
  while (node) {
    ext_4d9430(node);
    ext_4d9590(node);
    node = *(u8 **)(self + 0x50);
  }
  if (!a) return 0;
  vcall<void>(self, 0x294, 0x688a24u, a, 0u, 1u);
  return *(u32 *)(self + 0x50);
}
PCREG(46c8a0, fn46c8a0);

// 0x4705a0, thiscall(s) ret 4, returns true: 0x441790(this, s); then s->slot0x3c([this+0x5c]) and the chain of results' slot 0x3c with [this+0x60], [this+0x64], [this+0x68];
// s->slot0x6c([this+0x6c]) and its result's slot 0x6c([this+0x70]); s->slot0x78([this+0x78]) and its result's slot 0x78([this+0x74]).
static bool THISCALL fn4705a0(u8 *self, u8 *s) {
  ext_441790(self, s);
  u8 *o = vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x5c));
  o = vcall<u8 *>(o, 0x3c, *(u32 *)(self + 0x60));
  o = vcall<u8 *>(o, 0x3c, *(u32 *)(self + 0x64));
  o = vcall<u8 *>(o, 0x3c, *(u32 *)(self + 0x68));
  o = vcall<u8 *>(s, 0x6c, *(u32 *)(self + 0x6c));
  vcall<void>(o, 0x6c, *(u32 *)(self + 0x70));
  o = vcall<u8 *>(s, 0x78, *(u32 *)(self + 0x78));
  vcall<void>(o, 0x78, *(u32 *)(self + 0x74));
  return true;
}
PCREG(4705a0, fn4705a0);
