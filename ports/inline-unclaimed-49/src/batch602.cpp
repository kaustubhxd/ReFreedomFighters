// batch602.cpp - area 49, batch 602: the list cleanup 0x5bdfa0 (no GC name; base of CCivilianPathList's destructor)
// and the destructor 0x5be080 (CCivilianPathList::~CCivilianPathList, ret 4, flags).
// List: count at +0x90c, entries of 0x3a bytes from +0x59; an entry's first dword e (a heap object) owns
// e+0xc (freed by 0x41e2c0, cdecl 1 arg), e+0x10 and e+0x14 (freed by 0x634273, cdecl ptr,size = 4) and e itself
// (size 0x18). The object's fields: +0x44 = 0, +0x30 = 0, vtable 0x686874 (set after the loop, GUESS: the object's
// class is the ZFFSimpleTrain2 vtable in the exe, kept as read), then the render manager's slot 0x34 with this.
// The destructor then does the same flag handling as 0x5b8400 with state 0x996 (hook or SetState).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
extern "C" void ext_41e2c0(void *p);                  // free-like (cdecl, one arg)
extern "C" void ext_634273(void *p, u32 size);        // delete-like (cdecl, ptr and size)
extern "C" void ext_4690b0(void *gc, u32 state);      // ZRenderGC::SetState (cdecl, two pushes)
typedef u32 (*hookFn)();

// 0x5bdfa0: thiscall, no args, returns nothing used.
static void THISCALL pathListCleanup(u8 *self) {
  *(u32 *)self = 0x6b3568;
  u32 n = 0;
  for (; n < *(s32 *)(self + 0x90c); n++) {
    u8 *ent = self + 0x59 + n * 0x3a;
    u8 *e = *(u8 **)ent;
    if (e) {
      if (*(u32 *)(e + 0xc))
        ext_41e2c0(*(void **)(e + 0xc));
      if (*(u32 *)(e + 0x10))
        ext_634273(*(void **)(e + 0x10), 4);
      if (*(u32 *)(e + 0x14))
        ext_634273(*(void **)(e + 0x14), 4);
      ext_634273(e, 0x18);
    }
  }
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *rm = *(u8 **)(sys + 0x9b);
  ((vOne)VT(rm, 0x34))(rm, (u32)self);
}
PCREG(5bdfa0, pathListCleanup);

// 0x5be080 ~CCivilianPathList(flags): cleanup, then the 0x5b8400 flag handling with state 0x996.
static u32 THISCALL pathListDtor(u8 *self, u32 flags) {
  pathListCleanup(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x996);
    } else {
      hookFn h = G(hookFn, 0x7003b0);
      if (!h)
        __builtin_debugtrap();
      h();
    }
  }
  return (u32)self;
}
PCREG(5be080, pathListDtor);
