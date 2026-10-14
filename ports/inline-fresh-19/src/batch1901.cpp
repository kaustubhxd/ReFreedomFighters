// batch1901.cpp - fresh slice 19, batch 1901 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);         // sized operator delete (cdecl; hooked)
extern "C" float THISCALL ext_4e5e80(u8 *db);          // DBREAD::operator float() (hooked)
extern "C" u32 THISCALL ext_4e5e60(u8 *db);            // DBREAD::operator unsigned int() (hooked)
extern "C" bool THISCALL ext_575800(u8 *self);         // ZZoneMap::NextMap() (hooked)
extern "C" bool THISCALL ext_574250(u8 *self, u32 k);  // ZBaseMap::OnKeyPress(unsigned) (hooked)

// 0x5eaaf0 CActorActionMarker::~CActorActionMarker(): deletes each of the [+0x48] pointers at +4 (sized delete, 0x15).
static void THISCALL dtor_5eaaf0(u8 *self) {
  u8 **p = (u8 **)(self + 4);
  for (u32 i = 0; i < *(u32 *)(self + 0x48); i++, p++) ext_634273(*p, 0x15);
}
PCREG(5eaaf0, dtor_5eaaf0);

// 0x4bce30 ZSoundVolume2D::CopyEventDataBlock(DBREAD &d) ret 4: three floats into +0x48, +0x4c, +0x50.
static void THISCALL copyEvent_4bce30(u8 *self, u8 *d) {
  *(float *)(self + 0x48) = ext_4e5e80(d);
  *(float *)(self + 0x4c) = ext_4e5e80(d);
  *(float *)(self + 0x50) = ext_4e5e80(d);
}
PCREG(4bce30, copyEvent_4bce30);

// 0x57a1b0 ZFFWaterMark::CopyEventDataBlock(DBREAD &d) ret 4: three dwords into +0x48, +0x4c, +0x50.
static void THISCALL copyEvent_57a1b0(u8 *self, u8 *d) {
  *(u32 *)(self + 0x48) = ext_4e5e60(d);
  *(u32 *)(self + 0x4c) = ext_4e5e60(d);
  *(u32 *)(self + 0x50) = ext_4e5e60(d);
}
PCREG(57a1b0, copyEvent_57a1b0);

// 0x657970 ZPrimControlGC::SetActiveNrTriangles(unsigned a, unsigned n) ret 8: x = vt[0xc](a); y = vt[0xc](x->+0x3c);
// word *y = n; word x+0xe = 3 * n.
static void THISCALL setActiveNrTriangles_657970(u8 *self, u32 a, u32 n) {
  u8 *x = vcall<u8 *>(self, 0xc, a);
  u16 *y = vcall<u16 *>(self, 0xc, *(u32 *)(x + 0x3c));
  *y = (u16)n;
  *(u16 *)(x + 0xe) = (u16)(n * 3);
}
PCREG(657970, setActiveNrTriangles_657970);

// 0x60ce70 (no GC name): vt[0x2b0](); the object o at +0x1377 gets o->vt[0x8c](o) as a stack argument (ecx is not set
// for that call, so the slot is taken as stdcall: GUESS on the convention, the stub pops one word); clears the global
// 0x724a00 and byte +0x13ec; returns 1.
static bool THISCALL fn_60ce70(u8 *self) {
  vcall<void>(self, 0x2b0);
  u8 *o = *(u8 **)(self + 0x1377);
  (*(void(STDCALL **)(u8 *))(*(u8 **)o + 0x8c))(o);
  G(u32, 0x724a00) = 0;
  self[0x13ec] = 0;
  return true;
}
PCREG(60ce70, fn_60ce70);

// 0x575930 ZZoneMap::OnKeyPress(unsigned key) ret 4: with byte +0x216 set and key 1, NextMap() true returns 1; anything
// else goes to ZBaseMap::OnKeyPress(key).
static bool THISCALL onKeyPress_575930(u8 *self, u32 key) {
  if (self[0x216] && key == 1 && ext_575800(self)) return true;
  return ext_574250(self, key);
}
PCREG(575930, onKeyPress_575930);
