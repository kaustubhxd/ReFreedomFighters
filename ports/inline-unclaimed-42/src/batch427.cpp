// batch427.cpp - unclaimed-42 batch 7 (claim 7, residue-01 queue). Names from the GC name map (naming only, never committed).
#include "ff.h"

// Original callee: the element loader (thiscall, one argument: the load object), ret 4.
extern "C" void THISCALL ext_5beeb0(u8 *elem, u8 *ld);

// ZLoadGame virtual slots (thiscall; callee pops its own arguments, as in the original).
typedef void (THISCALL *VLoad48)(u8 *self, u32 *out);            // dword read into out
typedef void (THISCALL *VLoad18)(u8 *self, u8 *buf, u32 len);    // block read
typedef void (THISCALL *VLoad40)(u8 *self, u32 *out);            // pointer-sized read into out
typedef u8 *(THISCALL *VEngine58)(u8 *self, u32 arg);            // engine slot +0x58

// 0x5bedd0, CCivilianPathList::Load(ZLoadGame*) (high): thiscall, ret 4, returns true in AL.
//   clears bit 6 of this+4; reads a count into this+0x90c and a second count into this+0x910; for each of the first
//   count elements (stride 0x3a from this+0x4c) calls the element loader; reads a block of count2*5 bytes into this+0x718;
//   reads three dwords into +0x91e, +0x922, +0x926; reads a pointer-sized value and passes it to the engine (slot +0x58),
//   storing the result at +0x91a; reads a 0x68-byte block into +0x92a.
static u8 THISCALL civilianPathListLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u8 *vt = *(u8 **)ld;
  ((VLoad48)*(u32 *)(vt + 0x48))(ld, (u32 *)(self + 0x90c));
  ((VLoad48)*(u32 *)(vt + 0x48))(ld, (u32 *)(self + 0x910));

  s32 i = 0;
  if (*(s32 *)(self + 0x90c) > 0) {
    u8 *elem = self + 0x4c;
    do {
      ext_5beeb0(elem, ld);
      i++;
      elem += 0x3a;
    } while (i < *(s32 *)(self + 0x90c));
  }

  u32 cnt2 = *(u32 *)(self + 0x910);
  ((VLoad18)*(u32 *)(vt + 0x18))(ld, self + 0x718, cnt2 * 5);
  ((VLoad48)*(u32 *)(vt + 0x48))(ld, (u32 *)(self + 0x91e));
  ((VLoad48)*(u32 *)(vt + 0x48))(ld, (u32 *)(self + 0x922));
  ((VLoad48)*(u32 *)(vt + 0x48))(ld, (u32 *)(self + 0x926));

  u32 slot = (u32)(self + 0x910);
  ((VLoad40)*(u32 *)(vt + 0x40))(ld, &slot);
  u8 *en = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u8 **)(self + 0x91a) = ((VEngine58)*(u32 *)(*(u8 **)en + 0x58))(en, slot);

  ((VLoad18)*(u32 *)(vt + 0x18))(ld, self + 0x92a, 0x68);
  return 1;
}
PCREG(5bedd0, civilianPathListLoad);
