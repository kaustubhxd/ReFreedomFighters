// batch934.cpp - vehicles thread, batch 934: ZVehicle::Save(ZSaveGame*) and ZVehicle::Load(ZLoadGame*).
// Both start with the base class call (ZMoveOnSpline save/load header, 0x513ff0 / 0x5135c0, stood in by the spec)
// and then go through the save/load object's virtual slots in a fixed order: 0x10 = bytes, 0x68 / 0x6c = byte-sized
// fields, 0x4c / 0x50 = floats, 0x70 / 0x74 = vectors, 0x3c / 0x40 = dwords, 0x64 = object id.
#include "ff.h"

extern "C" u8 THISCALL ext_513ff0(void *self, void *sg);  // ZMoveOnSpline::Save header (stood in)
extern "C" u8 THISCALL ext_5135c0(void *self, void *lg);  // ZMoveOnSpline::Load header (stood in)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x515b70 ZVehicle::Save(ZSaveGame*), callee pops 4, returns bool.
static u8 THISCALL vehSave(u8 *s, void *sg) {
  if (!ext_513ff0(s, sg))
    return 0;
  vcall<void>(sg, 0x10, (u32)(s + 0x216), 4u);
  vcall<void>(sg, 0x68, (u32)(s + 0x21b));
  vcall<void>(sg, 0x68, (u32)(s + 0x227));
  vcall<void>(sg, 0x4c, F(s, 0x233));
  vcall<void>(sg, 0x70, (u32)(s + 0x237));
  vcall<void>(sg, 0x68, (u32)(s + 0x25b));
  vcall<void>(sg, 0x4c, F(s, 0x267));
  vcall<void>(sg, 0x70, (u32)(s + 0x26b));
  vcall<void>(sg, 0x68, (u32)(s + 0x28f));
  vcall<void>(sg, 0x68, (u32)(s + 0x29b));
  vcall<void>(sg, 0x3c, *(u32 *)(s + 0x2ab));
  vcall<void>(sg, 0x64, *(u32 *)(s + 0x2af));
  vcall<void>(sg, 0x68, (u32)(s + 0x2b3));
  vcall<void>(sg, 0x4c, F(s, 0x2bf));
  return 1;
}
PCREG(515b70, vehSave);

// 0x5159b0 ZVehicle::Load(ZLoadGame*), callee pops 4, returns bool. The object id at +0x2af is read as a dword
// into a local and resolved through the render manager (slot 0x58).
static u8 THISCALL vehLoad(u8 *s, void *lg) {
  if (!ext_5135c0(s, lg))
    return 0;
  vcall<void>(lg, 0x18, (u32)(s + 0x216), 4u);
  vcall<void>(lg, 0x6c, (u32)(s + 0x21b));
  vcall<void>(lg, 0x6c, (u32)(s + 0x227));
  vcall<void>(lg, 0x50, (u32)(s + 0x233));
  vcall<void>(lg, 0x74, (u32)(s + 0x237));
  vcall<void>(lg, 0x6c, (u32)(s + 0x25b));
  vcall<void>(lg, 0x50, (u32)(s + 0x267));
  vcall<void>(lg, 0x74, (u32)(s + 0x26b));
  vcall<void>(lg, 0x6c, (u32)(s + 0x28f));
  vcall<void>(lg, 0x6c, (u32)(s + 0x29b));
  vcall<void>(lg, 0x40, (u32)(s + 0x2ab));
  u32 gid = 0;
  vcall<void>(lg, 0x40, (u32)&gid);
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  *(u32 *)(s + 0x2af) = vcall<u32>(rm, 0x58, gid);
  vcall<void>(lg, 0x6c, (u32)(s + 0x2b3));
  vcall<void>(lg, 0x50, (u32)(s + 0x2bf));
  return 1;
}
PCREG(5159b0, vehLoad);
