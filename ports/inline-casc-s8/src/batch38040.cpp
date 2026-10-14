// batch38040.cpp - cascade s8 batch 38040: 0x4ffc30 (register an entity's script variables with the registry).
#include "ff.h"

extern "C" void THISCALL ext_4690b0(u8 *self);   // a single ret
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v6_t)(void *, u32, u32, u32, u32, u32, u32);
#define REG G(u8 *, 0x7003a4)
#define SLOT(off, T) ((T)(*(u8 **)(*(u8 **)REG + (off))))

// 0x4ffc30, thiscall, no args, plain ret. Runs 0x4690b0 and then talks to the registry object at 0x7003a4 (re-read before every call): slot 0xc4(0, this); eight slot 0xac registrations of
// named fields (the first four as plain values, the next four as 'typed' ones with the type string 0x69c7f4, all with this[0xc] and count 1 / 2) and eighteen slot 0x40 named values taken
// from this[0x10], [0x14], [0x18], [0x20], [0x2c] and [0x30].
static void THISCALL fn4ffc30(u8 *self) {
  ext_4690b0(self);
  SLOT(0xc4, v2_t)(REG, 0, (u32)self);
  static const u32 plain[4] = {0x69c770, 0x69c77c, 0x69c784, 0x69c790};
  for (int i = 0; i < 4; i++) SLOT(0xac, v6_t)(REG, plain[i], 0, 4, 1, *(u32 *)(self + 0xc), 1);
  static const u32 typed[4] = {0x685230, 0x69c754, 0x69c75c, 0x69c768};
  for (int i = 0; i < 4; i++) SLOT(0xac, v6_t)(REG, typed[i], 0x69c7f4, 4, 1, *(u32 *)(self + 0xc), 2);
  static const struct {
    u32 name;
    u32 off;
  } vals[18] = {{0x69c800, 0x10}, {0x685874, 0x18}, {0x690640, 0x20}, {0x690650, 0x20}, {0x69c814, 0x14}, {0x69c828, 0x14}, {0x68a8e0, 0x2c},
                {0x68a8a8, 0x14}, {0x68a8b8, 0x2c}, {0x68a89c, 0x14}, {0x68a904, 0x14}, {0x682e18, 0x14}, {0x69c83c, 0x14}, {0x68a9f4, 0x14},
                {0x68ce84, 0x14}, {0x686794, 0x14}, {0x69c848, 0x30}, {0x69c85c, 0x30}};
  for (int i = 0; i < 18; i++) SLOT(0x40, v2_t)(REG, vals[i].name, *(u32 *)(self + vals[i].off));
}
PCREG(4ffc30, fn4ffc30);
