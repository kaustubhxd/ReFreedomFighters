// u69_35.cpp - area 69, group 35 (slice 8). One thunk and two leaves that call other areas' functions (GUESS stubs in the spec).
#include "ff.h"

extern "C" u32 THISCALL ext_5ac940(void *self, u32 a);
extern "C" void ext_634273(void *p, u32 size);  // operator delete (cdecl, sized), CRT
extern "C" void ext_634d52(void *p);            // CRT helper, cdecl, one arg

// 0x5ef040, thiscall one stack arg (ret 4): ECX = dword [self+0xc], then jumps to 0x5ac940 with the same argument. 0x5ac940 is thiscall with one stack arg (its chain ends in 0x5ac140 and 0x5abf00, both ret 4).
static u32 THISCALL thunk5ef040(u8 *self, u32 a) { return ext_5ac940(*(void **)(self + 0xc), a); }
PCREG(5ef040, thunk5ef040);

// 0x64fe40, thiscall no args (ret): if the dword at self+0x20 is non-null, deletes it with the sized delete (size 1), then clears the slot.
static void THISCALL freeSlot64fe40(u8 *self) {
  void *p = *(void **)(self + 0x20);
  if (p)
    ext_634273(p, 1);
  *(u32 *)(self + 0x20) = 0;
}
PCREG(64fe40, freeSlot64fe40);

// 0x402480, cdecl one stack arg (plain ret). If p is non-null, clears the three dwords at p and calls ext_634d52(p); the caller pops the arg.
static void clear3402480(u32 *p) {
  if (!p)
    return;
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  ext_634d52(p);
}
PCREG(402480, clear3402480);
