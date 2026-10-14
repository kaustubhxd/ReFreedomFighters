// batch932.cpp - 0x5159b0 ZVehicle::Load(ZLoadGame*) [thiscall (ECX = this), one stack arg (stream), ret 4, returns al]. Body read in full
// (2026-10-12). First the gate 0x5135c0 (thiscall: this, stream; stood in). If false, return 0. Otherwise the stream reads (its slots):
// +0x18 (this+0x216, 4 bytes), +0x6c (+0x21b), +0x6c (+0x227), +0x50 (+0x233), +0x74 (+0x237), +0x6c (+0x25b), +0x50 (+0x267), +0x74 (+0x26b),
// +0x6c (+0x28f), +0x6c (+0x29b), +0x40 (+0x2ab); then a dword read into the argument slot (a), which the manager (g+0x9b) maps through its
// slot +0x58 into this+0x2af; then +0x6c (+0x2b3) and +0x50 (+0x2bf). Returns 1.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_5135c0(void *self, void *stream);   // stood in (its body is not read)

// 0x5159b0 (name in the map: ZVehicle::Load(ZLoadGame*)).
static bool THISCALL Load5159b0(u8 *self, u8 *stream) {
  if (!ext_5135c0(self, stream)) return false;
  vcall<void>(stream, 0x18, (void *)(self + 0x216), 4u);
  vcall<void>(stream, 0x6c, (void *)(self + 0x21b));
  vcall<void>(stream, 0x6c, (void *)(self + 0x227));
  vcall<void>(stream, 0x50, (void *)(self + 0x233));
  vcall<void>(stream, 0x74, (void *)(self + 0x237));
  vcall<void>(stream, 0x6c, (void *)(self + 0x25b));
  vcall<void>(stream, 0x50, (void *)(self + 0x267));
  vcall<void>(stream, 0x74, (void *)(self + 0x26b));
  vcall<void>(stream, 0x6c, (void *)(self + 0x28f));
  vcall<void>(stream, 0x6c, (void *)(self + 0x29b));
  vcall<void>(stream, 0x40, (void *)(self + 0x2ab));
  u32 a = (u32)stream;
  vcall<void>(stream, 0x40, (void *)&a);
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  U32(self, 0x2af) = vcall<u32>(mgr, 0x58, a);
  vcall<void>(stream, 0x6c, (void *)(self + 0x2b3));
  vcall<void>(stream, 0x50, (void *)(self + 0x2bf));
  return true;
}
PCREG(5159b0, Load5159b0);
