// batch514.cpp - weapons thread, batch 514: ZItemWeapon::SetState (0x471300), the weapon's state machine.
// Item states: 0 idle, 1 and 2 (1 = hidden/holstered? guess), 3 firing, 4 (not a weapon state: asserts), 5 reloading,
// 6 chambering. Flags: +0xc8 reload running, +0xc9 chamber running, +0xca fire running, +0xcb fire refused (scope not
// ready on a weapon without sniper mode... see below). +0x5c current state.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u8(THISCALL *vB0)(void *self);
typedef u32 (*hookFn)();
extern "C" u8 THISCALL ext_4711f0(void *item, u32 state, void *com);   // ZItem::SetState

static inline u8 bit10(u8 *self) { return (*(u32 *)(*(u8 **)(self + 8) + 0x3c) >> 10) & 1; }

// Entering a state starts the matching action once (FireStart 0x388, ReloadStart 0x378, ChamberStart 0x380) and idle
// ends whichever are running (FireEnd 0x38c, ReloadEnd 0x37c, ChamberEnd 0x384). Firing needs ScopeReady (slot
// 0x36c, true for non-sniper weapons); when it is false a weapon without sniper mode only marks +0xcb (so the next
// idle skips FireEnd). Every state but 1 then makes the weapon geom active when its bit 10 is set and deactivates
// the muzzle flash (handle +0xed). State 1 deactivates the weapon geom instead (when bit 10 is clear). States above 6
// assert (hook 0x7003b0, int3 without one) and fall back to ZItem::SetState. Returns 1.
static u8 THISCALL weaponSetState(u8 *self, u32 s, void *com) {
  if (s == *(u32 *)(self + 0x5c))
    return 1;
  switch (s) {
  case 0:
    if (self[0xcb]) {
      self[0xcb] = 0;
    } else if (self[0xca]) {
      self[0xca] = 0;
      ((vU0)VT(self, 0x38c))(self);
    }
    if (self[0xc8]) {
      self[0xc8] = 0;
      ((vU0)VT(self, 0x37c))(self);
    }
    if (self[0xc9]) {
      self[0xc9] = 0;
      ((vU0)VT(self, 0x384))(self);
    }
    break;
  case 1:
    if (!bit10(self))
      ((vU0)VT(self, 0x28))(self);
    *(u32 *)(self + 0x5c) = s;
    return 1;
  case 2:
    break;
  case 3:
    if (((vB0)VT(self, 0x36c))(self)) {
      if (!self[0xca] && !self[0xcb]) {
        self[0xca] = 1;
        ((vU0)VT(self, 0x388))(self);
      }
    } else {
      u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
      if (!((vB0)VT(t, 0x32c))(t))
        self[0xcb] = 1;
    }
    break;
  case 5:
    if (!self[0xc8]) {
      self[0xc8] = 1;
      ((vU0)VT(self, 0x378))(self);
    }
    break;
  case 6:
    if (!self[0xc9]) {
      self[0xc9] = 1;
      ((vU0)VT(self, 0x380))(self);
    }
    break;
  default: {
    hookFn h = G(hookFn, 0x7003b0);
    if (!h)
      __builtin_debugtrap();
    h();
    return ext_4711f0(self, s, com);
  }
  }
  if (bit10(self)) {
    ((vU0)VT(self, 0x2c))(self);
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *g = (u8 *)((vUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0xed));
    if (g)
      ((vU0)VT(g, 0x28))(g);
  }
  *(u32 *)(self + 0x5c) = s;
  return 1;
}
PCREG(471300, weaponSetState);
