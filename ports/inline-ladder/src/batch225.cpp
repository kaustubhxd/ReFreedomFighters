// batch225.cpp - ZIKLNKOBJ members, part 4 (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_466ce0(void *self);   // ZIKLNKOBJ::KillAllSounds (damage thread, batch 609)
extern "C" void THISCALL ext_45d3a0(void *self);   // ZGEOM::ClassInit2

static inline void *db225() { return (void *)U32(G(u32, 0x70039c), 0x9b); }

// 0x465760 ZIKLNKOBJ::ActivateRagdoll(bool on, bool b) [high], ret 8, AL. Byte +0x13a = !on (low byte); turning the
// ragdoll on kills all the actor's sounds first. The IK object (+0x6c) slot 0x30(owner, on (whole dword), b, 0) does
// it; when that returns non-zero, own slot 0x220(0). Returns whether it worked.
static bool THISCALL ikActivateRagdoll(u8 *self, u32 on, u32 b) {
  bool off = (u8)on == 0;
  self[0x13a] = off;
  if (!off)
    ext_466ce0(self);
  bool ok = vcall<u32>((void *)U32(self, 0x6c), 0x30, self, on, b, 0u) != 0;
  if (ok)
    vcall<void>(self, 0x220, 0u);
  return ok;
}
PCREG(465760, ikActivateRagdoll);

// 0x465fd0 ZIKLNKOBJ::ClassInit2() [medium]: ZGEOM::ClassInit2, then adds itself to the engine list
// "TrackLinkObjects" (database +0xadc slot 0x25c; asserts it exists: hook 0x7003b0 or int3): list slot
// 0x228(ref(this), word +0x161, word +0x163). So every IK actor is in the list the bat/knife hit test walks.
static void THISCALL ikClassInit2(u8 *self) {
  ext_45d3a0(self);
  u8 *list = vcall<u8 *>((void *)U32(db225(), 0xadc), 0x25c, (const char *)0x685f44, 0u);
  if (!list) {
    typedef void (*hook_t)();
    hook_t h = G(hook_t, 0x7003b0);
    if (h)
      h();
    else
      __asm__ volatile("int3");
  }
  u8 *lvt = *(u8 **)list;
  u32 w163 = U16(self, 0x163), w161 = U16(self, 0x161);
  u32 ref = vcall<u32>(db225(), 0x4c, self);
  typedef void(THISCALL * fn)(void *, u32, u32, u32);
  (*(fn *)(lvt + 0x228))(list, ref, w161, w163);
}
PCREG(465fd0, ikClassInit2);

// 0x467f60 ZIKLNKOBJ::UpdateTargets() [medium]: own slots 0x408, 0x404, then 0x40c (tail call).
static u32 THISCALL ikUpdateTargets(void *self) {
  vcall<void>(self, 0x408);
  vcall<void>(self, 0x404);
  return vcall<u32>(self, 0x40c);
}
PCREG(467f60, ikUpdateTargets);

// 0x467f20 ZIKLNKOBJ::UpdateSpeech() [high]: the speech sound handle +0x153 is cleared once its sound object
// (database slot 0x60) has +0x70 below 0.1 (ordered; probably the remaining time or volume).
static void THISCALL ikUpdateSpeech(u8 *self) {
  u32 h = U32(self, 0x153);
  if (!h)
    return;
  u8 *o = vcall<u8 *>(db225(), 0x60, h);
  if (o && 0.1f > F32(o, 0x70))
    U32(self, 0x153) = 0;
}
PCREG(467f20, ikUpdateSpeech);

// 0x466f30 ZIKLNKOBJ::MoveToMatPos(const float*, const float*) [low]: own slot 0x20 gives an object, whose slot 0x7c
// gets the same two arguments (tail call; callee pops 8).
static u32 THISCALL ikMoveToMatPos(void *self, u32 m, u32 p) {
  void *o = vcall<void *>(self, 0x20);
  return vcall<u32>(o, 0x7c, m, p);
}
PCREG(466f30, ikMoveToMatPos);
