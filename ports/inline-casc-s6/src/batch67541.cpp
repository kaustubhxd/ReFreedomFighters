// batch67541.cpp - cascade s6 batch 67541: 0x56cc30.
#include "ff.h"

extern "C" void THISCALL ext_562260(u8 *self);   // plain ret
extern "C" void THISCALL ext_56d950(u8 *self);   // plain ret

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)

// 0x56cc30, thiscall() plain ret (eax unused): updates the four per-slot flags (+0x19c active, +0x1a0 state) from the input system. With sys[0x6c] set and this[0x1c6] non-zero, each slot i
// asks sys[0x1907] slot 0x2c (this[0x1ca + 4i], 0): when pressed it becomes active, its state being "not set" if already active, else (count of active+set slots) <= (count of active+unset slots);
// 0x56d950 is notified; then slot 0x2c (this[0x1da + 4i], 0) releases the slot (flag cleared, 0x56d950). Finally the device mask (slot 0x4c of [0x7003a0]) clears the flags of absent slots and a
// changed mask is stored at +0x1c2 (0x56d950 first).
static void THISCALL fn56cc30(u8 *self) {
  ext_562260(self);
  u8 *sys = SYS;
  if (sys[0x6c] && D32(self, 0x1c6)) {
    for (int i = 0; i < 4; i++) {
      u8 *in = *(u8 **)(SYS + 0x1907);
      if ((u8)vcall<u32>(in, 0x2c, D32(self, 0x1ca + 4 * i), 0u)) {
        u8 v;
        if (self[0x19c + i]) {
          v = self[0x1a0 + i] == 0;
        } else {
          int a = 0, c = 0;
          for (int k = 0; k < 4; k++) {
            if (self[0x19c + k]) {
              if (self[0x1a0 + k]) a++; else c++;
            }
          }
          self[0x19c + i] = 1;
          v = a <= c;
        }
        self[0x1a0 + i] = v;
        ext_56d950(self);
      }
      u8 *in2 = *(u8 **)(SYS + 0x1907);
      if ((u8)vcall<u32>(in2, 0x2c, D32(self, 0x1da + 4 * i), 0u)) {
        self[0x19c + i] = 0;
        ext_56d950(self);
      }
    }
  }
  u32 mask = vcall<u32>(*(u8 **)0x7003a0, 0x4c);
  for (int k = 0; k < 4; k++) {
    if (!(mask & (1u << k))) self[0x19c + k] = 0;
  }
  if (mask != D32(self, 0x1c2)) {
    ext_56d950(self);
    D32(self, 0x1c2) = mask;
  }
}
PCREG(56cc30, fn56cc30);
