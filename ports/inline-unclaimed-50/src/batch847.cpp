// batch847.cpp - area 50 (residue-10 list): ZFFHERO::CreateMovements() [high, vt 389]. The player's movements first
// (ZPlayer::CreateMovements, 0x482ac0), then nine movement objects: each is a new(size) block, built by its constructor
// (p, this, arg) when the allocation worked (0 otherwise), and registered with the hero's vt +0x624(this, object).
// The exe's exception frame (fs:[0] setup and teardown around the calls) is not reproduced: the port has no throw path.
#include "ff.h"

extern "C" void THISCALL ext_482ac0(void *self);                      // ZPlayer::CreateMovements (not ported here)
extern "C" void *ext_41e290(u32 size);                                 // operator new (cdecl)
extern "C" void *THISCALL ext_5e1110(void *p, void *self, u32 a);      // movement constructors (not ported here)
extern "C" void *THISCALL ext_5e1200(void *p, void *self, u32 a);
extern "C" void *THISCALL ext_5e1160(void *p, void *self, u32 a);
extern "C" void *THISCALL ext_5e1190(void *p, void *self, u32 a);
extern "C" void *THISCALL ext_5e11c0(void *p, void *self, u32 a);
extern "C" void *THISCALL ext_5e10a0(void *p, void *self, u32 a);
extern "C" void *THISCALL ext_5e0ee0(void *p, void *self, u32 a);
extern "C" void *THISCALL ext_5e0f80(void *p, void *self, u32 a);
extern "C" void *THISCALL ext_5e0ff0(void *p, void *self, u32 a);

typedef void *(THISCALL *ctor_t)(void *, void *, u32);   // the constructors are thiscall: p in ECX

static void AddMovement(u8 *self, u32 size, ctor_t ctor, u32 arg) {
  void *p = ext_41e290(size);
  void *c = p ? ctor(p, self, arg) : 0;
  vcall<void>(self, 0x624, c);
}

static void THISCALL CreateMovements(u8 *self) {
  ext_482ac0(self);
  AddMovement(self, 0x591, (ctor_t)ext_5e1110, 7);
  AddMovement(self, 0x5cd, (ctor_t)ext_5e1200, 8);
  AddMovement(self, 0x5bf, (ctor_t)ext_5e1160, 0xf);
  AddMovement(self, 0x5bb, (ctor_t)ext_5e1190, 0x10);
  AddMovement(self, 0x568, (ctor_t)ext_5e11c0, 0x11);
  AddMovement(self, 0x5af, (ctor_t)ext_5e10a0, 9);
  AddMovement(self, 0x7a, (ctor_t)ext_5e0ee0, 0xb);
  AddMovement(self, 0x611, (ctor_t)ext_5e0f80, 0xc);
  AddMovement(self, 0x578, (ctor_t)ext_5e0ff0, 0xe);
}
PCREG(590e20, CreateMovements);
