#include "ff.h"
// batch1383.cpp - unclaimed-13 claim 2 (docs/20-unclaimed-13.md). Names: none in the GC name map, so these are GUESS
// labels for the forwarders; the owner class is unknown. Each one forwards to a virtual slot of an object that a
// virtual slot returns:  p = this->vt[+0x60](arg); return p ? p->vt[+off]() : 0;   (thiscall, ret 4, eax result).

// 0x437080 (GUESS): forwards to slot +0x18 of the object from slot +0x60.
static u32 THISCALL forwardSlot18(u8 *self, u32 a1) {
  typedef u8 *(THISCALL * slot60_fn)(u8 *, u32);
  typedef u32(THISCALL * slot18_fn)(u8 *);
  u8 *p = ((slot60_fn)*(u32 *)(*(u32 *)self + 0x60))(self, a1);
  if (p == 0) return 0;
  return ((slot18_fn)*(u32 *)(*(u32 *)p + 0x18))(p);
}
PCREG(437080, forwardSlot18);

// 0x438340 (GUESS): same shape, forwards to slot +0x1c.
static u32 THISCALL forwardSlot1c(u8 *self, u32 a1) {
  typedef u8 *(THISCALL * slot60_fn)(u8 *, u32);
  typedef u32(THISCALL * slot1c_fn)(u8 *);
  u8 *p = ((slot60_fn)*(u32 *)(*(u32 *)self + 0x60))(self, a1);
  if (p == 0) return 0;
  return ((slot1c_fn)*(u32 *)(*(u32 *)p + 0x1c))(p);
}
PCREG(438340, forwardSlot1c);

// 0x43ac10 (GUESS): same shape, forwards to slot +0x2c.
static u32 THISCALL forwardSlot2c(u8 *self, u32 a1) {
  typedef u8 *(THISCALL * slot60_fn)(u8 *, u32);
  typedef u32(THISCALL * slot2c_fn)(u8 *);
  u8 *p = ((slot60_fn)*(u32 *)(*(u32 *)self + 0x60))(self, a1);
  if (p == 0) return 0;
  return ((slot2c_fn)*(u32 *)(*(u32 *)p + 0x2c))(p);
}
PCREG(43ac10, forwardSlot2c);
