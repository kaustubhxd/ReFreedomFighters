// batch226.cpp - ZIKLNKOBJ Save/Load (with the running action), destructor, and ZActionDispatcher::SetCurrent
// (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_4640f0(void *self, void *sg);              // ZLNKOBJ::Save
extern "C" u32 THISCALL ext_463620(void *self, void *lg);              // ZLNKOBJ::Load
extern "C" void THISCALL ext_467850(void *target, void *sg, void *o);  // ZTARGET::Save
extern "C" void THISCALL ext_466eb0(void *target, void *lg, void *o);  // ZTARGET::Load
extern "C" void THISCALL ext_4946a0(void *disp, void *action);         // ZActionDispatcher::SetCurrent (below)
extern "C" void THISCALL ext_465660(void *self);                       // ZIKLNKOBJ destructor body
extern "C" void ext_45c510(void *p);                                   // ZGEOM::operator delete, cdecl
extern "C" void ext_4690b0(void *p, u32 size);                         // empty (placement delete), cdecl

// 0x4946a0 ZActionDispatcher::SetCurrent(ZLnkAction*) (GC 8 bytes, no PC name; folded with ZSoundBase::SetOwner [high],
// the same code): +4 = the argument. ret 4.
static void THISCALL adSetCurrent(u8 *self, u32 a) { U32(self, 4) = a; }
PCREG(4946a0, adSetCurrent);

// 0x467770 ZIKLNKOBJ::Save(ZSaveGame *s) [high], ret 4, AL. After ZLNKOBJ::Save (false: return it): +0x169 (slot 0x3c,
// dword), byte +0x158 (0x60), +0x159 and +0x136 (0x44), float +0x1ca (0x4c), the ZTARGET +0x16d, the head target
// +0x1ba (0x68, which returns the stream) and float +0x1c6 (0x4c on that). Then the running action: its id (action slot
// 4) or 0 (slot 0x3c), and the action's own data (action slot 0x18(s)). Last +0x14f (0x44). True.
static bool THISCALL ikSave(u8 *self, void *s) {
  u32 r = ext_4640f0(self, s);
  if (!(u8)r)
    return false;
  vcall<void>(s, 0x3c, U32(self, 0x169));
  vcall<void>(s, 0x60, (u32)self[0x158]);
  vcall<void>(s, 0x44, U32(self, 0x159));
  vcall<void>(s, 0x44, U32(self, 0x136));
  vcall<void>(s, 0x4c, F32(self, 0x1ca));
  ext_467850(self + 0x16d, s, self);
  void *s2 = vcall<void *>(s, 0x68, self + 0x1ba);
  vcall<void>(s2, 0x4c, F32(self, 0x1c6));
  void *a = (void *)U32(U32(self, 0x1ce), 4);
  if (a) {
    u8 *svt = *(u8 **)s;
    u32 id = vcall<u32>(a, 4);
    typedef void(THISCALL * fn)(void *, u32);
    (*(fn *)(svt + 0x3c))(s, id);
    vcall<void>(a, 0x18, s);
  } else {
    vcall<void>(s, 0x3c, 0u);
  }
  vcall<void>(s, 0x44, U32(self, 0x14f));
  return true;
}
PCREG(467770, ikSave);

// 0x466dc0 ZIKLNKOBJ::Load(ZLoadGame *l) [high], ret 4, AL. Own slot 0x3d4 first, then ZLNKOBJ::Load (false: return
// it), own slot 0x358, then the fields in Save's order (slots 0x40, 0x68, 0x48, 0x48, 0x50, ZTARGET::Load, 0x6c then
// 0x50 on the returned stream). Then the action id; when non-zero the action is rebuilt with own slot 0x3ec
// (CreateLnkAction), loads its data (action slot 0x1c(l)) and becomes the dispatcher's current action
// (SetCurrent, no Execute). Last +0x14f (0x48). True.
static bool THISCALL ikLoad(u8 *self, void *l) {
  vcall<void>(self, 0x3d4);
  u32 r = ext_463620(self, l);
  if (!(u8)r)
    return false;
  vcall<void>(self, 0x358);
  vcall<void>(l, 0x40, self + 0x169);
  vcall<void>(l, 0x68, self + 0x158);
  vcall<void>(l, 0x48, self + 0x159);
  vcall<void>(l, 0x48, self + 0x136);
  vcall<void>(l, 0x50, self + 0x1ca);
  ext_466eb0(self + 0x16d, l, self);
  void *l2 = vcall<void *>(l, 0x6c, self + 0x1ba);
  vcall<void>(l2, 0x50, self + 0x1c6);
  u32 id;
  vcall<void>(l, 0x40, &id);
  if (id) {
    void *a = vcall<void *>(self, 0x3ec, id);
    vcall<void>(a, 0x1c, l);
    ext_4946a0((void *)U32(self, 0x1ce), a);
  }
  vcall<void>(l, 0x48, self + 0x14f);
  return true;
}
PCREG(466dc0, ikLoad);

// 0x465720 ZIKLNKOBJ scalar deleting destructor [medium], ret 4: destructor body 0x465660; with flags bit 0, either
// ZGEOM::operator delete (bit 2 clear) or the empty placement delete 0x4690b0(this, 0x1d2) (bit 2 set; the object is
// 0x1d2 bytes). Returns this.
static void *THISCALL ikDtor(u8 *self, u32 flags) {
  ext_465660(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x1d2);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(465720, ikDtor);
