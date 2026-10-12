// batch778.cpp - unclaimed-77 claim 8 (docs/20-unclaimed-77.md): ZActionControlMap::FindGameState() (medium). Thiscall, no
// arguments, ret 0. The callee 0x591b20 is stubbed (GUESS): thiscall with the value at this+0x5f as its this, returns the case index.
#include "ff.h"

extern "C" u32 THISCALL ext_591b20(void *thisp);   // stubbed (GUESS): returns the case index

// 0x5b2d00, ZActionControlMap::FindGameState() (medium).
static void THISCALL actionControlMapFindGameState(u8 *self) {
  u32 esi = 0;
  u32 eax = (self[0x22b] != 0) ? 0xfu : 0x10u;
  self[0x22f] = 0x7f;
  *(u32 *)(self + 0x4d) = eax;
  if (self[0x22d] != 0) {
    *(u32 *)(self + 0x4d) = 0xd;
  }
  u8 al = (u8)(self[0x168] | self[0x1a3]);
  u32 ctx = *(u32 *)(self + 0x5f);
  self[0x22e] = al;
  u32 idx = ext_591b20((void *)ctx);
  if (idx <= 0x10) {
    switch (idx) {
      case 0:
      case 1:
      case 2:
        esi = (self[0x1a3] == 0) ? 0 : 0xb;
        break;
      case 3:
      case 4:
        esi = 1;
        break;
      case 5:
        esi = 3;
        break;
      case 6:
      case 7:
        esi = 2;
        break;
      case 8:
        esi = 4;
        *(u32 *)(self + 0x4d) = (self[0x1a3] != 0 ? 1u : 0u) + 2u;
        break;
      case 9:
        self[0x22f] = 0;
        esi = 5;
        *(u32 *)(self + 0x4d) = 0xa;
        break;
      case 10:
        esi = 6;
        break;
      case 11:
        esi = (self[0x1a3] == 0) ? 0 : 7;
        break;
      case 12:
      case 13:
        esi = 8;
        *(u32 *)(self + 0x4d) = 6;
        break;
      case 14:
        esi = 0;
        *(u32 *)(self + 0x4d) = 9;
        esi = (self[0x1a3] != 0) ? 0xbu : 0u;
        break;
      case 15:
        esi = (self[0x1a3] == 0) ? 0 : 0xc;
        break;
      case 16:
        esi = 9;
        *(u32 *)(self + 0x4d) = 8;
        break;
    }
  }
  // common tail (0x5b2e1d): the value stored through this+0x63 is esi, or 0 when byte this+0x168 is nonzero.
  u32 ecxv = (self[0x168] == 0) ? esi : 0;
  u8 *p63 = *(u8 **)(self + 0x63);
  *(u32 *)(p63 + 0xad5) = ecxv;
  u8 *p5f = *(u8 **)(self + 0x5f);
  *(u32 *)(p5f + 0x67b) = *(u32 *)(self + 0x4d);
}
PCREG(5b2d00, actionControlMapFindGameState);
