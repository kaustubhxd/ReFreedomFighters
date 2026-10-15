// batch67537.cpp - cascade s6 batch 67537: 0x651040.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);   // free, cdecl

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x651040, thiscall(target) ret 4, no return value: moves the save-stack depth this[0x3c] to `target` using the stack object at this+0x40 (vtable at this[0x40]). A negative depth or target resets
// it (slot 0xc) and sets the depth. Growing pushes records (slot 0x84(depth): link 0, then the six state fields +0x2c / 0x20 / 0x24 / 0x28 / 0x30 / 0x34 copied to rec +4..+0x18, state cleared, depth++).
// Shrinking pops records (slot 0x34(0)), frees the current +0x2c and +0x20 blocks, restores the six fields from rec +8..+0x1c, then slot 0x3c(depth-1) and depth--.
static void THISCALL fn651040(u8 *self, int target) {
  int depth = (int)D32(self, 0x3c);
  if (depth < 0 || target < 0) {
    vcall<void>(self + 0x40, 0xc);
    D32(self, 0x3c) = (u32)target;
    return;
  }
  if (depth < target) {
    do {
      u8 *rec = vcall<u8 *>(self + 0x40, 0x84, D32(self, 0x3c));
      D32(rec, 0) = 0;
      D32(rec, 4) = D32(self, 0x2c);
      D32(rec, 8) = D32(self, 0x20);
      D32(rec, 0xc) = D32(self, 0x24);
      D32(rec, 0x10) = D32(self, 0x28);
      D32(rec, 0x14) = D32(self, 0x30);
      D32(rec, 0x18) = D32(self, 0x34);
      D32(self, 0x3c)++;
      D32(self, 0x2c) = 0;
      D32(self, 0x20) = 0;
      D32(self, 0x24) = 0;
      D32(self, 0x28) = 0;
      D32(self, 0x30) = 0;
      D32(self, 0x34) = 0;
    } while ((int)D32(self, 0x3c) < target);
    return;
  }
  if (depth == target) return;
  do {
    u8 *rec = vcall<u8 *>(self + 0x40, 0x34, 0u);
    if (D32(self, 0x2c)) ext_634273((u8 *)D32(self, 0x2c), 1);
    if (D32(self, 0x20)) ext_634273((u8 *)D32(self, 0x20), 1);
    D32(self, 0x2c) = D32(rec, 8);
    D32(self, 0x20) = D32(rec, 0xc);
    D32(self, 0x24) = D32(rec, 0x10);
    D32(self, 0x28) = D32(rec, 0x14);
    D32(self, 0x30) = D32(rec, 0x18);
    D32(self, 0x34) = D32(rec, 0x1c);
    vcall<void>(self + 0x40, 0x3c, D32(self, 0x3c) - 1);
    D32(self, 0x3c)--;
  } while ((int)D32(self, 0x3c) > target);
}
PCREG(651040, fn651040);
