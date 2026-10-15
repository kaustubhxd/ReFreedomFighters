// batch837.cpp - animation layer thread, batch 837: ZLNKOBJ::DisplayBone and ZIKLNKOBJ::ActivateRagdoll.
// Bone table entries (0x18 bytes): +4 flags (bit 8 = displayed), others as in batch 808/809. Entry 0 is the root.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_466ce0(void *self);   // ZIKLNKOBJ::KillAllSounds (not ported here)

// ZLNKOBJ::DisplayBone(unsigned bone, bool on) [high, GC-mapped]. Returns the previous display state (bit 8 of the
// bone's flags). Turning a bone on also sets the root's bit; turning it off clears the root's bit when no other bone
// is still displayed. Only the low byte of "on" is used.
static u8 THISCALL DisplayBone(u8 *self, u32 bone, u32 on) {
  u8 *tab = (u8 *)FP(self, 0x1c);
  u8 *e = tab + bone * 0x18;
  u32 flags = F32(e, 4);
  u8 was = (u8)((flags >> 3) & 1);
  u8 want = (u8)(on & 0xff);
  if (want != was) {
    if (want) {
      F32(tab, 4) |= 8u;
      F32(e, 4) |= 8u;
    } else {
      F32(e, 4) = flags & ~8u;
      u32 count = F32(self, 0x20);
      u32 i = 1;
      while (i != count && !(F8(tab + i * 0x18, 4) & 8)) i++;
      if (i == count) F32(tab, 4) &= ~8u;
    }
  }
  return was;
}
PCREG(4625c0, DisplayBone);

// ZIKLNKOBJ::ActivateRagdoll(bool a, bool b) [medium]: the flag +0x13a is set when a is false; a true a kills the
// sounds first. The bone modifier's vt +0x30(this, a, b, 0) decides; a non-zero result also calls vt +0x220(0).
// Returns that result as a bool.
static u8 THISCALL ActivateRagdoll(u8 *self, u32 a, u32 b) {
  F8(self, 0x13a) = ((a & 0xff) == 0) ? 1 : 0;
  if (a & 0xff) ext_466ce0(self);
  u32 r = vcall<u32>(FP(self, 0x6c), 0x30, self, a, b, 0u);
  u8 bl = (r != 0) ? 1 : 0;
  if (bl) vcall<void>(self, 0x220, 0u);
  return bl;
}
PCREG(465760, ActivateRagdoll);
